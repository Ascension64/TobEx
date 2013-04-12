#include "ScriptCore.h"

#include "chitin.h"
#include "optionsext.h"
#include "objcore.h"
#include "InfGameCommon.h"
#include "ScriptCommon.h"

//CVariableMap
DefineTrampMemberFunc(BOOL, CVariableMap, Add, (CVariable& var), Add, Add, 0x64A2E8);
DefineTrampMemberFunc(CVariable&, CVariableMap, Find, (IECString sVar), Find, Find, 0x64A709);
DefineTrampMemberFunc(unsigned int, CVariableMap, GetHash, (IECString sVar), GetHash, GetHash, 0x64A96E);

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
				if (pGameOptionsEx->GetOption("Debug_Verbose")) {
					LPCTSTR lpsz = "DETOUR_CVariableMap::DETOUR_Add(): Map[0x%X]->%s(id=%d)=%d\r\n";
					L.appendf(lpsz, (DWORD)this, (LPCTSTR)sName, nHash, var.m_nValue);
					console.writef(lpsz, (DWORD)this, (LPCTSTR)sName, nHash, var.m_nValue);
				}
			} else { //collision
				if (nHash == nHashEnd) {
					bFail = TRUE;
					if (pGameOptionsEx->GetOption("Debug_Verbose")) {
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
DefineTrampMemberFunc(BOOL, CScriptBlock, Evaluate, (CTriggerList& triggers, CGameSprite& sprite), Evaluate, Evaluate, 0x405D19);

BOOL DETOUR_CScriptBlock::DETOUR_Evaluate(CTriggerList& triggers, CGameSprite& sprite) {
	if (0) IECString("DETOUR_CScriptBlock::DETOUR_Evaluate");

	//normal trigger variables
	BOOL bResult = FALSE;
	int nOr = 0;
	bool bBreak = false;
	
	//NextTriggerObject() variables
	BOOL bOverrideObject = FALSE;
	Object oOverride;
	CGameSprite* pOverrideSprite = NULL;

	//Eval() variables
	BOOL bOverrideInt[] = { FALSE, FALSE };
	int nOverride[] = { 0, 0 };
	BOOL bOverrideStr[] = { FALSE, FALSE };
	IECString sOverride[2];

	POSITION pos = m_triggers.GetHeadPosition();
	if (pos == NULL) return TRUE;

	while (pos != NULL && !bBreak) {
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

		case TRIGGER_ASSIGN:
		{
			IECString sStatement = tCopy.sName1;
			CGameSprite* pSpriteTarget = (bOverrideObject && pOverrideSprite) ? pOverrideSprite : &sprite;
					
			if (tCopy.i2 >= 0 && tCopy.i2 < BLOCK_VAR_ARRAY_SIZE) {
				if (tCopy.i == ARGTYPE_INT) {
					ParseStatement(tCopy.i2, tCopy.i, sStatement, *pSpriteTarget, pRuleEx->m_TriggerVars);
				} else if (tCopy.i == ARGTYPE_STR) {
					ParseStatement(tCopy.i2, tCopy.i, sStatement, *pSpriteTarget, pRuleEx->m_TriggerVars);
				}
			}

			//clean up
			bOverrideObject = FALSE;
			pOverrideSprite = NULL;
			break;
		} //TRIGGER_ASSIGN

		case TRIGGER_EVAL:
		{
			IECString sExpression = ParseBlockVariables(tCopy.sName1, tCopy.i, pRuleEx->m_TriggerVars);
			int nLoc = (tCopy.i2 - 1) & 1;

			if (tCopy.i == ARGTYPE_INT) {
				int nValue = 0;
				MathPresso::Expression mpExp;
				MathPresso::mresult_t mpResult = mpExp.create(pRuleEx->m_mpContext, (LPCTSTR)sExpression);
				if (mpResult == MathPresso::MRESULT_OK) {
					nValue = mpExp.evaluate(NULL);
				} else {
					LPCTSTR lpsz = "Trigger Eval(): bad expression \"%s\" (error %d)\r\n";
					L.timestamp();
					L.appendf(lpsz, (LPCTSTR)sExpression, (int)mpResult);
					console.writef(lpsz, (LPCTSTR)sExpression, (int)mpResult);
				}

				bOverrideInt[nLoc] = TRUE;
				nOverride[nLoc] = nValue;
			} else if (tCopy.i == ARGTYPE_STR) {
				bOverrideStr[nLoc] = TRUE;
				sOverride[nLoc] = sExpression;
			}

			break;
		} //TRIGGER_EVAL

		default:
			//set OR value
			if (tCopy.opcode == TRIGGER_OR) {
				nOr = tCopy.i;
			} else nOr--;

			//substitute trigger parameters
			if (bOverrideInt[0]) {
				tCopy.i = nOverride[0];
				nOverride[0] = 0;
				bOverrideInt[0] = FALSE;
			}
			if (bOverrideInt[1]) {
				tCopy.i2 = nOverride[1];
				nOverride[1] = 0;
				bOverrideInt[1] = FALSE;
			}
			if (bOverrideStr[0]) {
				tCopy.sName1 = sOverride[0];
				sOverride[0].Empty();
				bOverrideStr[0] = FALSE;
			}
			if (bOverrideStr[1]) {
				tCopy.sName2 = sOverride[1];
				sOverride[1].Empty();
				bOverrideStr[1] = FALSE;
			}

			//evaluate trigger depending on override object
			if (bOverrideObject) {
				if (pOverrideSprite) {
					if ((tCopy.opcode & 0x4000) == 0) pt->DecodeIdentifiers(*pOverrideSprite); //workaround for 0x0XXX triggers that need the original trigger decoded to work properly
					bResult |= EvaluateTrigger(tCopy, triggers, *pOverrideSprite);
					g_pChitin->pGame->m_GameObjectArray.FreeShare(pOverrideSprite->GetEnum(), THREAD_ASYNCH, INFINITE);
				} else bResult |= FALSE;
				bOverrideObject = FALSE;
				pOverrideSprite = NULL;
			} else {
				if ((tCopy.opcode & 0x4000) == 0) pt->DecodeIdentifiers(sprite); //workaround for 0x0XXX triggers that need the original trigger decoded to work properly
				bResult |= EvaluateTrigger(tCopy, triggers, sprite);
			}

			//terminate if not in OR
			if (bResult == FALSE &&	nOr <= 0) {
				//return FALSE;
				bResult = FALSE;
				bBreak = true;
			}

			break;
		} // switch(tCopy.opcode)
	} //while (pos != NULL)

	//clean up variables
	pRuleEx->m_TriggerVars.Empty();
	return bResult;
}
