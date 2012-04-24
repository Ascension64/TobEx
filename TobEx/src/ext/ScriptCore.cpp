#include "ScriptCore.h"

#include "chitin.h"
#include "objcore.h"

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

	POSITION pos = m_triggers.GetHeadPosition();
	if (pos == NULL) return TRUE;

	while (pos != NULL) {
		if (nOr <= 0) bResult = FALSE;
		Trigger* pt = (Trigger*)m_triggers.GetNext(pos);
		
		if (pt->opcode == TRIGGER_OR) {
			nOr = pt->i;
		} else {
			if (pt->opcode != TRIGGER_NEXT_TRIGGER_OBJECT) {
				nOr--;
			}
		}

		if (bOverrideObject) {
			if (pOverrideSprite) {
				bResult |= EvaluateTrigger(*pt, triggers, *pOverrideSprite);
				g_pChitin->pGame->m_GameObjectArrayHandler.FreeGameObjectShare(pOverrideSprite->GetEnum(), THREAD_ASYNCH, INFINITE);
			} else {
				bResult |= FALSE;
			}
			bOverrideObject = FALSE;
			pOverrideSprite = NULL;
		} else {
			bResult |= EvaluateTrigger(*pt, triggers, sprite);
		}

		if (pt->opcode == TRIGGER_NEXT_TRIGGER_OBJECT) {
			oOverride = pt->o;
			oOverride.DecodeIdentifiers(sprite);
			pOverrideSprite = (CGameSprite*)&oOverride.FindTargetOfType((CGameObject&)sprite, CGAMEOBJECT_TYPE_SPRITE, FALSE);
			bOverrideObject = TRUE;
		}

		if (bResult == FALSE && nOr <= 0 &&
			pt->opcode != TRIGGER_NEXT_TRIGGER_OBJECT)
			return FALSE;
	}

	return bResult;
}