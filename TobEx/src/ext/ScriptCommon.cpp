#include "ScriptCommon.h"

#include "chitin.h"
#include "InfGameCommon.h"

inline bool isdigit(char c) {
	return (c >= '0') && (c <= '9');
}

IECString ParseBlockVariables(IECString s, int nType, CBlockVariables& vars) {
	IECString sTemp = s;
	IECString sVarIdx;
	IECString sValue;
	char c;

	int nHashIdx = -1;
	unsigned int nArrayIdx = 0;
	int nValue = 0;

	//int variables
	while ((nHashIdx = sTemp.Find('#')) != -1) {
		int nStrIdx = nHashIdx + 1;
		while (
			isdigit(sTemp.GetAt(nStrIdx)) &&
			nStrIdx < sTemp.GetLength()
		) {
			sVarIdx += sTemp.GetAt(nStrIdx);
			nStrIdx++;
		}

		sscanf_s((LPCTSTR)sVarIdx, "%d", &nArrayIdx);

		if (nArrayIdx >= 0 && nArrayIdx < BLOCK_VAR_ARRAY_SIZE)
			nValue = vars.GetInt(nArrayIdx);
		sValue.Format("%d", nValue);

		if (nType != ARGTYPE_INT) {
			LPCTSTR lpsz = "ParseBlockVariables(): \"%s\" (INT) references a non-integer variable\r\n";
			L.timestamp();
			L.appendf(lpsz, (LPCTSTR)s);
			console.writef(lpsz, (LPCTSTR)s);
		}

		sTemp.Delete(nHashIdx, max(1, nStrIdx - nHashIdx));
		sTemp.Insert(nHashIdx, (LPCTSTR)sValue);
	}

	//string variables
	while ((nHashIdx = sTemp.Find('@')) != -1) {
		int nStrIdx = nHashIdx + 1;
		while (
			isdigit(sTemp.GetAt(nStrIdx)) &&
			nStrIdx < sTemp.GetLength()
		) {
			sVarIdx += sTemp.GetAt(nStrIdx);
			nStrIdx++;
		}

		sscanf_s((LPCTSTR)sVarIdx, "%d", &nArrayIdx);

		if (nArrayIdx >= 0 && nArrayIdx < BLOCK_VAR_ARRAY_SIZE)
			sValue = vars.GetStr(nArrayIdx);
		
		if (nType != ARGTYPE_STR) {
			LPCTSTR lpsz = "ParseBlockVariables(): \"%s\" (STR) references a non-string variable\r\n";
			L.timestamp();
			L.appendf(lpsz, (LPCTSTR)s);
			console.writef(lpsz, (LPCTSTR)s);
		}

		sTemp.Delete(nHashIdx, max(1, nStrIdx - nHashIdx));
		sTemp.Insert(nHashIdx, (LPCTSTR)sValue);
	}
	

	return sTemp;
}

void ParseStatement(unsigned int nIndex, int nType, IECString s, CGameSprite& sprite, CBlockVariables& vars) {
	IECString sTemp = s;
	IECString sType;
	int nIdx = -1;
	if ((nIdx = sTemp.Find('[')) != -1) {
		sType = sTemp.Left(nIdx);
		sTemp = sTemp.Right(sTemp.GetLength() - nIdx - 1);
		if ((nIdx = sTemp.Find(']')) != -1) sTemp = sTemp.Left(nIdx);

		if (sType.CompareNoCase("v") == 0 && nType == ARGTYPE_INT) {
			//variable "v[NAME.SCOPE]"
			IECString sVariable;
			IECString sScope;

			if ((nIdx = sTemp.Find('.')) != -1) {
				sVariable = ParseBlockVariables(sTemp.Left(nIdx), ARGTYPE_STR, vars);
				sTemp = sTemp.Right(sTemp.GetLength() - nIdx - 1);
			} else sVariable = ParseBlockVariables(sTemp, ARGTYPE_STR, vars);
			sVariable.TrimLeft();
			sVariable.TrimRight();

			sScope = ParseBlockVariables(sTemp, ARGTYPE_INT, vars);
			sScope.TrimLeft();
			sScope.TrimRight();
			sScope.MakeUpper();

			CVariable* pVar = NULL;

			if (!sScope.Compare("GLOBAL")) {
				pVar = &g_pChitin->pGame->m_GlobalVariables.Find(sVariable);
			} else if (!sScope.Compare("LOCALS") && sprite.GetType() == CGAMEOBJECT_TYPE_CREATURE) {
				pVar = &((CCreatureObject&)sprite).m_pLocalVariables->Find(sVariable);
			} else {
				if (!sScope.Compare("MYAREA")) sScope = sprite.pArea->rAreaName.FormatToString();
				CArea& area = g_pChitin->pGame->GetLoadedArea(sScope);
				if (&area != NULL) pVar = &area.m_AreaVariables.Find(sVariable);
			}
			vars.SetInt(nIndex, pVar ? pVar->nValue : 0);
		
		} else if (sType.CompareNoCase("ts") == 0) {
			//table by string "t[NAME.COL.ROW]"
			IECString sTable;
			IECString sCol;
			IECString sRow;

			if ((nIdx = sTemp.Find('.')) != -1) {
				sTable = ParseBlockVariables(sTemp.Left(nIdx), ARGTYPE_STR, vars);
				sTemp = sTemp.Right(sTemp.GetLength() - nIdx - 1);
			} else sTable = ParseBlockVariables(sTemp, ARGTYPE_STR, vars);
			sTable.TrimLeft();
			sTable.TrimRight();

			if ((nIdx = sTemp.Find('.')) != -1) {
				sCol = ParseBlockVariables(sTemp.Left(nIdx), ARGTYPE_STR, vars);
				sTemp = sTemp.Right(sTemp.GetLength() - nIdx - 1);
			} else sCol = ParseBlockVariables(sTemp, ARGTYPE_STR, vars);
			sCol.TrimLeft();
			sCol.TrimRight();

			sRow = ParseBlockVariables(sTemp, ARGTYPE_STR, vars);
			sRow.TrimLeft();
			sRow.TrimRight();

			sTable.MakeUpper();

			CRuleTable rule;
			IECString sValue;
			int nValue = 0;

			rule.LoadTable(ResRef((LPCTSTR)sTable));
			if (rule.m_2da.bLoaded) {
				sValue = rule.GetValue(sCol, sRow);
				sscanf_s((LPCTSTR)sValue, "%d", &nValue);
			}

			if (nType == ARGTYPE_INT) {
				vars.SetInt(nIndex, nValue);
			} else if (nType == ARGTYPE_STR) {
				vars.SetStr(nIndex, sValue);
			}

		} else if (sType.CompareNoCase("tn") == 0) {
			//table by int "t[NAME.X.Y]"
			IECString sTable;
			POINT pt = {0, 0};

			if ((nIdx = sTemp.Find('.')) != -1) {
				sTable = ParseBlockVariables(sTemp.Left(nIdx), ARGTYPE_STR, vars);
				sTemp = sTemp.Right(sTemp.GetLength() - nIdx - 1);
			} else sTable = ParseBlockVariables(sTemp, ARGTYPE_INT, vars);
			sTable.TrimLeft();
			sTable.TrimRight();

			if ((nIdx = sTemp.Find('.')) != -1) {
				sscanf_s((LPCTSTR)(ParseBlockVariables(sTemp.Left(nIdx), ARGTYPE_INT, vars)), "%d", &pt.x);
				sTemp = sTemp.Right(sTemp.GetLength() - nIdx - 1);
			}

			sscanf_s((LPCTSTR)(ParseBlockVariables(sTemp, ARGTYPE_INT, vars)), "%d", &pt.y);

			sTable.MakeUpper();

			CRuleTable rule;
			IECString sValue;
			int nValue = 0;

			rule.LoadTable(ResRef((LPCTSTR)sTable));
			if (rule.m_2da.bLoaded) {
				sValue = rule.GetValue(pt);
				sscanf_s((LPCTSTR)sValue, "%d", &nValue);
			}
			if (nType == ARGTYPE_INT) {
				vars.SetInt(nIndex, nValue);
			} else if (nType == ARGTYPE_STR) {
				vars.SetStr(nIndex, sValue);
			}

		} else if (sType.CompareNoCase("e") == 0 && nType == ARGTYPE_INT) {
			//expression "e[expression]"
			IECString sExpression = ParseBlockVariables(sTemp, ARGTYPE_INT, vars);
			int nValue = 0;
			MathPresso::Expression mpExp;
			MathPresso::mresult_t mpResult = mpExp.create(pRuleEx->m_mpContext, (LPCTSTR)sExpression);
			if (mpResult == MathPresso::MRESULT_OK) {
				nValue = mpExp.evaluate(NULL);
			} else {
				//error
				LPCTSTR lpsz = "Trigger Assign(): bad expression \"%s\" (error %d)\r\n";
				L.timestamp();
				L.appendf(lpsz, (LPCTSTR)sExpression, (int)mpResult);
				console.writef(lpsz, (LPCTSTR)sExpression, (int)mpResult);
			}
			vars.SetInt(nIndex, nValue);

		} else if (sType.CompareNoCase("id") == 0 && nType == ARGTYPE_INT) {
			//identifier "id[NAME.VALUE]"
			IECString sIdsName;
			IECString sValue;

			if ((nIdx = sTemp.Find('.')) != -1) {
				sIdsName = ParseBlockVariables(sTemp.Left(nIdx), ARGTYPE_STR, vars);
				sTemp = sTemp.Right(sTemp.GetLength() - nIdx - 1);
			} else sIdsName = ParseBlockVariables(sTemp, ARGTYPE_STR, vars);
			sIdsName.TrimLeft();
			sIdsName.TrimRight();

			sValue = ParseBlockVariables(sTemp, ARGTYPE_STR, vars);
			sValue.TrimLeft();
			sValue.TrimRight();

			sIdsName.MakeUpper();
			sValue.MakeUpper();

			Identifiers ids(ResRef((LPCTSTR)sIdsName));
			IdsEntry* pIE = ids.FindByHead(sValue, FALSE);
			int nValue = pIE ? pIE->nOpcode : 0;
			vars.SetInt(nIndex, nValue);

		} else if (sType.CompareNoCase("c") == 0) {
			//constant "c[value]"
			if (nType == ARGTYPE_INT) {
				int nValue;
				sTemp.TrimLeft();
				sTemp.TrimRight();
				sscanf_s((LPCTSTR)(ParseBlockVariables(sTemp, ARGTYPE_INT, vars)), "%d", &nValue);
				vars.SetInt(nIndex, nValue);
			} else if (nType == ARGTYPE_STR) {
				vars.SetStr(nIndex, ParseBlockVariables(sTemp, ARGTYPE_STR, vars));
			}

		} else if (sType.CompareNoCase("s") == 0 &&
			nType == ARGTYPE_INT &&
			sprite.GetType() == CGAMEOBJECT_TYPE_CREATURE) {
			//stat "s[VALUE]"
			IECString sValue;
			sValue = ParseBlockVariables(sTemp, ARGTYPE_STR, vars);
			sValue.TrimLeft();
			sValue.TrimRight();
			sValue.MakeUpper();

			Identifiers ids(ResRef("STATS"));
			IdsEntry* pIE = ids.FindByHead(sValue, FALSE);
			int nStat = pIE ? pIE->nOpcode : 0;
			int nValue = 0;
			if (nStat) nValue = ((CCreatureObject&)sprite).GetDerivedStats().GetStat(nStat);
			vars.SetInt(nIndex, nValue);
		}
	}

	return;
}