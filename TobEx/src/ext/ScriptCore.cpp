#include "ScriptCore.h"

#include "chitin.h"
#include "objcore.h"
#include "ScriptCommon.h"

//CVariableMap
BOOL (CVariableMap::*Tramp_CVariableMap_Add)(CVariable&) =
	SetFP(static_cast<BOOL (CVariableMap::*)(CVariable&)>		(&CVariableMap::Add),			0x64A2E8);
CVariable& (CVariableMap::*Tramp_CVariableMap_Find)(IECString) =
	SetFP(static_cast<CVariable& (CVariableMap::*)(IECString)>	(&CVariableMap::Find),			0x64A709);
unsigned int (CVariableMap::*Tramp_CVariableMap_GetHash)(IECString) =
	SetFP(static_cast<unsigned int (CVariableMap::*)(IECString)>(&CVariableMap::GetHash),		0x64A96E);

BOOL DETOUR_CVariableMap::DETOUR_Add(CVariable& var) {
	if (0) IECString("DETOUR_CVariableMap::DETOUR_Add");

	BOOL bSuccess = FALSE;
	BOOL bFail = FALSE;
	IECString sName = var.GetName();

	//trim spaces and upper-case
	sName.Remove(' ');
	sName.MakeUpper();
	var.SetName(sName);

	unsigned int nHash = GetHash(sName);
	unsigned int nHashEnd = (nHash + nArraySize / 10 - 1) % nArraySize;

	if (!var.GetName().IsEmpty()) {
		while (!bSuccess && !bFail) {
			IECString sBucket = pArray[nHash].GetName();
			if (sBucket.IsEmpty() || !sBucket.Compare(sName)) {
				bSuccess = TRUE;
				pArray[nHash] = var;
				if (pGameOptionsEx->bDebugVerbose) {
					LPCTSTR lpsz = "DETOUR_CVariableMap::DETOUR_Add(): Map[0x%X]->%s(id=%d)=%d\r\n";
					L.appendf(lpsz, (DWORD)this, (LPCTSTR)sName, nHash, var.nValue);
					console.writef(lpsz, (DWORD)this, (LPCTSTR)sName, nHash, var.nValue);
				}
			} else { //collision
				if (nHash == nHashEnd) {
					bFail = TRUE;
					if (pGameOptionsEx->bDebugVerbose) {
						LPCTSTR lpsz = "DETOUR_CVariableMap::DETOUR_Add(): Map[0x%X]->SetSize(%d)\r\n";
						L.appendf(lpsz, (DWORD)this, nArraySize * 2);
						console.writef(lpsz, (DWORD)this, nArraySize * 2);
					}
					SetSize(nArraySize * 2);
					Add(var);
				}
				nHash = ++nHash % nArraySize;
			}
		}
	}

	return bSuccess;
}

CVariable& DETOUR_CVariableMap::DETOUR_Find(IECString sVar) {
	if (0) IECString("DETOUR_CVariableMap::DETOUR_Find");

	CVariable* pVar = NULL;
	BOOL bSuccess = FALSE;
	BOOL bFail = FALSE;
	IECString sName = sVar;

	//trim spaces and upper-case
	sName.Remove(' ');
	sName.MakeUpper();

	unsigned int nHash = GetHash(sName);
	unsigned int nHashEnd = (nHash + nArraySize / 10 - 1) % nArraySize;

	while (!bSuccess && !bFail) {
		IECString sBucket = pArray[nHash].GetName();
		if (!sBucket.Compare(sName)) { //equal
			bSuccess = TRUE;
			pVar = &pArray[nHash];
		} else if (!sBucket.IsEmpty()) { //collision
			if (nHash == nHashEnd) bFail = TRUE;
			nHash = ++nHash % nArraySize;
		} else bSuccess = TRUE; //bucket empty
	}

	return *pVar;
}

unsigned int DETOUR_CVariableMap::DETOUR_GetHash(IECString sVar) {
	if (0) IECString("DETOUR_CVariableMap::DETOUR_GetHash");

	unsigned int hash = 5381;
	for (int i = 0; i < sVar.GetLength() && i < 32; i++)
		hash = ((hash << 5) + hash) + sVar[i]; //hash * 33 + c

	return hash % nArraySize;
}

//CScriptBlock
BOOL (CScriptBlock::*Tramp_CScriptBlock_Evaluate)(CTriggerList&, CGameSprite&) =
	SetFP(static_cast<BOOL (CScriptBlock::*)(CTriggerList&, CGameSprite&)>	(&CScriptBlock::Evaluate),	0x405D19);

BOOL DETOUR_CScriptBlock::DETOUR_Evaluate(CTriggerList& triggers, CGameSprite& sprite) {
	if (0) IECString("DETOUR_CScriptBlock::DETOUR_Evaluate");

	BOOL bResult = FALSE;
	int nOr = 0;
	
	BOOL bOverrideObject = FALSE;
	Object oOverride;
	CGameSprite* pOverrideSprite = NULL;

	IECPtrList cplOp1;
	IECPtrList cplOp2;
	IECString sEval1;
	IECString sEval2;

	POSITION pos = m_triggers.GetHeadPosition();
	if (pos == NULL) return TRUE;

	while (pos != NULL) {
		if (nOr <= 0) bResult = FALSE; //AND
		Trigger* pt = (Trigger*)m_triggers.GetNext(pos);
		Trigger tCopy = *pt;
		
		switch (tCopy.opcode) {
		case TRIGGER_NEXT_TRIGGER_OBJECT:
			oOverride = tCopy.o;
			oOverride.DecodeIdentifiers(sprite);
			pOverrideSprite = (CGameSprite*)&oOverride.FindTargetOfType((CGameObject&)sprite, CGAMEOBJECT_TYPE_SPRITE, FALSE);
			bOverrideObject = TRUE;
			break;

		case TRIGGER_EVAL1:
		case TRIGGER_EVAL2:
		{
			unsigned int nType = (unsigned int)tCopy.i3 & 0xFFFF;
			unsigned int nMode = (unsigned int)tCopy.i3 >> 16;

			switch (nType) {
			case EVALUATE_TYPE_INT:
				if (tCopy.opcode == TRIGGER_EVAL1) {
					cplOp1.AddHead(new EvalOp(tCopy.i, nMode));
				} else if (tCopy.opcode == TRIGGER_EVAL2) {
					cplOp2.AddHead(new EvalOp(tCopy.i, nMode));
				}
				break;
			case EVALUATE_TYPE_VAR:
			{
				IECString sArg = tCopy.GetSName1();
				sArg.MakeUpper();
				IECString sScope = sArg.Left(6);
				IECString sVariable = sArg.Right(sArg.GetLength() - 6);
				CVariable* pVar = NULL;

				if (!sScope.Compare("GLOBAL")) {
					pVar = &g_pChitin->pGame->m_GlobalVariables.Find(sVariable);
				} else if (!sScope.Compare("LOCALS")) {
					if (bOverrideObject) {
						if (pOverrideSprite &&
							pOverrideSprite->GetType() == CGAMEOBJECT_TYPE_CREATURE)
							pVar = &((CCreatureObject*)pOverrideSprite)->m_pLocalVariables->Find(sVariable);
					} else if (sprite.GetType() == CGAMEOBJECT_TYPE_CREATURE)
						pVar = &((CCreatureObject*)&sprite)->m_pLocalVariables->Find(sVariable);
				} else {
					if (!sScope.Compare("MYAREA")) sScope = sprite.pArea->rAreaName.FormatToString();
					CArea& area = g_pChitin->pGame->GetLoadedArea(sScope);
					if (&area != NULL)
						pVar = &area.m_AreaVariables.Find(sVariable);
				}

				if (tCopy.opcode == TRIGGER_EVAL1) {
					cplOp1.AddHead(new EvalOp(pVar ? pVar->nValue : 0, nMode));
				} else if (tCopy.opcode == TRIGGER_EVAL2) {
					cplOp2.AddHead(new EvalOp(pVar ? pVar->nValue : 0, nMode));
				}
				break;
			}
			case EVALUATE_TYPE_STAT:
			{
				IECString sStat = tCopy.GetSName1();
				sStat.MakeUpper();
				Identifiers ids(ResRef("STATS"));
				IdsEntry* pIE = ids.FindByValue(sStat, FALSE);
				int nStat = pIE ? pIE->nOpcode : 0;
				if (nStat) {
					int nValue = 0;
					bool bFound = false;
					if (bOverrideObject) {
						if (pOverrideSprite &&
							pOverrideSprite->GetType() == CGAMEOBJECT_TYPE_CREATURE) {
							nValue = ((CCreatureObject*)pOverrideSprite)->GetDerivedStats().GetStat(nStat);
							bFound = true;
						}
					} else if (sprite.GetType() == CGAMEOBJECT_TYPE_CREATURE) {
						nValue = ((CCreatureObject*)&sprite)->GetDerivedStats().GetStat(nStat);
						bFound = true;
					}

					if (tCopy.opcode == TRIGGER_EVAL1) {
						cplOp1.AddHead(new EvalOp(bFound ? nValue : 0, nMode));
					} else if (tCopy.opcode == TRIGGER_EVAL2) {
						cplOp2.AddHead(new EvalOp(bFound ? nValue : 0, nMode));
					}
				}
				break;
			}

			/*case EVALUATE_TYPE_2DA_INT:
			{
				IECString sTemp = tCopy.GetSName1();
				sTemp.Delete(' ');
				sTemp.MakeUpper();
				IECString sTable = sTemp.SpanExcluding(".");
				sTemp = sTemp.Right(sTemp.GetLength() - sTable.GetLength() - 1);
				IECString sCol = sTemp.SpanExcluding(".");
				sTemp = sTemp.Right(sTemp.GetLength() - sCol.GetLength() - 1);
				IECString sRow = sTemp;

				CRuleTable rule;
				rule.LoadTable(ResRef((LPCTSTR)sTable));
				if (rule.m_2da.bLoaded) {
					IECString sValue = rule.GetValue(sCol, sRow);
					int nValue = atoi((LPCTSTR)sValue);
					if (tCopy.opcode == TRIGGER_EVAL1) {
						cplOp1.AddHead(new EvalOp(nValue, nMode));
					} else if (tCopy.opcode == TRIGGER_EVAL2) {
						cplOp2.AddHead(new EvalOp(nValue, nMode));
					}
				} else {
					if (tCopy.opcode == TRIGGER_EVAL1) {
						cplOp1.AddHead(new EvalOp(0, nMode));
					} else if (tCopy.opcode == TRIGGER_EVAL2) {
						cplOp2.AddHead(new EvalOp(0, nMode));
					}
				}
				break;
			}*/

			case EVALUATE_TYPE_2DA_INT:
			{
				//unwind the operator ptr lists
				while (!cplOp1.IsEmpty()) {
					EvalOp* pOp = (EvalOp*)cplOp1.RemoveHead();
					tCopy.i = EvalOp::Operate(tCopy.i, *pOp);
					delete pOp;
					pOp = NULL;
				}
				while (!cplOp2.IsEmpty()) {
					EvalOp* pOp = (EvalOp*)cplOp2.RemoveHead();
					tCopy.i2 = EvalOp::Operate(tCopy.i2, *pOp);
					delete pOp;
					pOp = NULL;
				}
				POINT pt = {tCopy.i, tCopy.i2};
				//replace the strings if present
				if (!sEval1.IsEmpty() && sEval1.Compare("*")) tCopy.sName1 = sEval1;
				if (!sEval2.IsEmpty() && sEval2.Compare("*")) tCopy.sName2 = sEval2;
				sEval1.Empty();
				sEval2.Empty();

				IECString sTable = tCopy.GetSName1();
				sTable.Delete(' ');
				sTable.MakeUpper();

				CRuleTable rule;
				rule.LoadTable(ResRef((LPCTSTR)sTable));
				if (rule.m_2da.bLoaded) {
					IECString sValue = rule.GetValue(pt);
					int nValue = atoi((LPCTSTR)sValue);
					if (tCopy.opcode == TRIGGER_EVAL1) {
						cplOp1.AddHead(new EvalOp(nValue, nMode));
					} else if (tCopy.opcode == TRIGGER_EVAL2) {
						cplOp2.AddHead(new EvalOp(nValue, nMode));
					}
				} else {
					if (tCopy.opcode == TRIGGER_EVAL1) {
						cplOp1.AddHead(new EvalOp(0, nMode));
					} else if (tCopy.opcode == TRIGGER_EVAL2) {
						cplOp2.AddHead(new EvalOp(0, nMode));
					}
				}
				break;
			}

			case EVALUATE_TYPE_STR:
				if (tCopy.opcode == TRIGGER_EVAL1) {
					sEval1 = tCopy.sName1;
				} else if (tCopy.opcode == TRIGGER_EVAL2) {
					sEval2 = tCopy.sName1;
				}
				break;

			/*case EVALUATE_TYPE_2DA_STR:
			{
				IECString sTemp = tCopy.GetSName1();
				sTemp.Delete(' ');
				sTemp.MakeUpper();
				IECString sTable = sTemp.SpanExcluding(".");
				sTemp = sTemp.Right(sTemp.GetLength() - sTable.GetLength() - 1);
				IECString sCol = sTemp.SpanExcluding(".");
				sTemp = sTemp.Right(sTemp.GetLength() - sCol.GetLength() - 1);
				IECString sRow = sTemp;

				CRuleTable rule;
				rule.LoadTable(ResRef((LPCTSTR)sTable));
				if (rule.m_2da.bLoaded) {
					IECString sValue = rule.GetValue(sCol, sRow);
					if (tCopy.opcode == TRIGGER_EVAL1) {
						sEval1 = sValue;
					} else if (tCopy.opcode == TRIGGER_EVAL2) {
						sEval2 = sValue;
					}
				} else {
					if (tCopy.opcode == TRIGGER_EVAL1) {
						sEval1.Empty();
					} else if (tCopy.opcode == TRIGGER_EVAL2) {
						sEval2.Empty();
					}
				}
				break;
			}*/

			case EVALUATE_TYPE_2DA_STR:
			{
				IECString sTable = tCopy.GetSName1();
				sTable.Delete(' ');
				sTable.MakeUpper();

				//unwind the operator ptr lists
				while (!cplOp1.IsEmpty()) {
					EvalOp* pOp = (EvalOp*)cplOp1.RemoveHead();
					tCopy.i = EvalOp::Operate(tCopy.i, *pOp);
					delete pOp;
					pOp = NULL;
				}
				while (!cplOp2.IsEmpty()) {
					EvalOp* pOp = (EvalOp*)cplOp2.RemoveHead();
					tCopy.i2 = EvalOp::Operate(tCopy.i2, *pOp);
					delete pOp;
					pOp = NULL;
				}
				POINT pt = {tCopy.i, tCopy.i2};
				//replace the strings if present
				if (!sEval1.IsEmpty() && sEval1.Compare("*")) tCopy.sName1 = sEval1;
				if (!sEval2.IsEmpty() && sEval2.Compare("*")) tCopy.sName2 = sEval2;
				sEval1.Empty();
				sEval2.Empty();

				CRuleTable rule;
				rule.LoadTable(ResRef((LPCTSTR)sTable));
				if (rule.m_2da.bLoaded) {
					IECString sValue = rule.GetValue(pt);
					if (tCopy.opcode == TRIGGER_EVAL1) {
						sEval1 = sValue;
					} else if (tCopy.opcode == TRIGGER_EVAL2) {
						sEval2 = sValue;
					}
				} else {
					if (tCopy.opcode == TRIGGER_EVAL1) {
						sEval1.Empty();
					} else if (tCopy.opcode == TRIGGER_EVAL2) {
						sEval2.Empty();
					}
				}
				break;
			}

			default:
				break;
			} // switch(i)

			//clean up
			bOverrideObject = FALSE;
			pOverrideSprite = NULL;
			break;

		} //TRIGGER_EVAL

		default:
			//set OR value
			if (tCopy.opcode == TRIGGER_OR) {
				nOr = tCopy.i;
			} else nOr--;

			//unwind the operator ptr lists
			while (!cplOp1.IsEmpty()) {
				EvalOp* pOp = (EvalOp*)cplOp1.RemoveHead();
				tCopy.i = EvalOp::Operate(tCopy.i, *pOp);
				delete pOp;
				pOp = NULL;
			}
			while (!cplOp2.IsEmpty()) {
				EvalOp* pOp = (EvalOp*)cplOp2.RemoveHead();
				tCopy.i2 = EvalOp::Operate(tCopy.i2, *pOp);
				delete pOp;
				pOp = NULL;
			}

			//replace the strings if present
			if (!sEval1.IsEmpty() && sEval1.Compare("*")) tCopy.sName1 = sEval1;
			if (!sEval2.IsEmpty() && sEval2.Compare("*")) tCopy.sName2 = sEval2;
			sEval1.Empty();
			sEval2.Empty();

			//evaluate trigger depending on override object
			if (bOverrideObject) {
				if (pOverrideSprite) {
					bResult |= EvaluateTrigger(tCopy, triggers, *pOverrideSprite);
					g_pChitin->pGame->m_GameObjectArrayHandler.FreeGameObjectShare(pOverrideSprite->GetEnum(), THREAD_ASYNCH, INFINITE);
				} else bResult |= FALSE;
			} else bResult |= EvaluateTrigger(tCopy, triggers, sprite);

			//terminate if not in OR
			if (bResult == FALSE &&	nOr <= 0)
				return FALSE;

			//clean up
			bOverrideObject = FALSE;
			pOverrideSprite = NULL;
			break;
		} // switch(tCopy.opcode)
	} //while (pos != NULL)

	return bResult;
}