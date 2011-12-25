#include "ScriptCore.h"

#include "chitin.h"
#include "objcore.h"

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