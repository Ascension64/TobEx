#include "ObjectCore.h"

#include "chitin.h"
#include "objcre.h"
#include "ScriptAction.h"

DefineTrampMemberFunc(BOOL, CGameSprite, EvaluateTrigger, (Trigger& t), EvaluateTrigger, EvaluateTrigger, 0x47F4F2);
DefineTrampMemberFunc(void, CGameSprite, ClearAllActions, (BOOL bSkipFlagged), ClearAllActions, ClearAllActions, 0x47838F);
DefineTrampMemberFunc(ACTIONRESULT, CGameSprite, ExecuteAction, (), ExecuteAction, ExecuteAction, 0x47891B);
DefineTrampMemberFunc(void, CGameSprite, QueueActions, (Response& r, BOOL bSkipIfAlreadyQueued, BOOL bClearActionQueue), QueueActions, QueueActions, 0x48DA78);

BOOL DETOUR_CGameSprite::DETOUR_EvaluateTrigger(Trigger& t) {
	if (0) IECString("DETOUR_CGameSprite::DETOUR_EvaluateTrigger");

	Trigger tTemp = t;
	CCreatureObject* pCre = NULL;
	CGameSprite* pSprite = NULL;
	Object oCriteria;
	int nFindTargetResult = 0;
	BOOL bResult = FALSE;

	switch (tTemp.opcode) {
	case TRIGGER_MOVEMENT_RATE:
		{
		nFindTargetResult = FindTargetCreature(tTemp, &pCre);
		if (pCre == NULL) break;
		CAnimation* pAnim = pCre->m_animation.pAnimation;
		if (pAnim == NULL) break;
		unsigned char nMvt = pAnim->GetCurrentMovementRate();
		bResult = (signed int)nMvt == tTemp.i;
		}
		break;
	case TRIGGER_MOVEMENT_RATE_GT:
		{
		nFindTargetResult = FindTargetCreature(tTemp, &pCre);
		if (pCre == NULL) break;
		CAnimation* pAnim = pCre->m_animation.pAnimation;
		if (pAnim == NULL) break;
		unsigned char nMvt = pAnim->GetCurrentMovementRate();
		bResult = (signed int)nMvt > tTemp.i;
		}
		break;
	case TRIGGER_MOVEMENT_RATE_LT:
		{
		nFindTargetResult = FindTargetCreature(tTemp, &pCre);
		if (pCre == NULL) break;
		CAnimation* pAnim = pCre->m_animation.pAnimation;
		if (pAnim == NULL) break;
		unsigned char nMvt = pAnim->GetCurrentMovementRate();
		bResult = (signed int)nMvt < tTemp.i;
		}
		break;
	case TRIGGER_NUM_MIRRORIMAGES:
		{
		nFindTargetResult = FindTargetCreature(tTemp, &pCre);
		if (pCre == NULL) break;
		unsigned char nImages = pCre->m_nMirrorImages;
		bResult = (signed int)nImages == tTemp.i;
		}
		break;
	case TRIGGER_NUM_MIRRORIMAGES_GT:
		{
		nFindTargetResult = FindTargetCreature(tTemp, &pCre);
		if (pCre == NULL) break;
		unsigned char nImages = pCre->m_nMirrorImages;
		bResult = (signed int)nImages > tTemp.i;
		}
		break;
	case TRIGGER_NUM_MIRRORIMAGES_LT:
		{
		nFindTargetResult = FindTargetCreature(tTemp, &pCre);
		if (pCre == NULL) break;
		unsigned char nImages = pCre->m_nMirrorImages;
		bResult = (signed int)nImages < tTemp.i;
		}
		break;
	case TRIGGER_BOUNCING_SPELL_LEVEL:
		{
		nFindTargetResult = FindTargetCreature(tTemp, &pCre);
		if (pCre == NULL) break;
		if (tTemp.i < 0) break;
		if (tTemp.i > 9) break;
		bResult = pCre->GetActiveStats().BounceSplLvl[tTemp.i] || pCre->GetActiveStats().BounceSplLvlDec[tTemp.i].bOn;
		}
		break;
	case TRIGGER_NUM_BOUNCING_SPELL_LEVEL:
		{
		nFindTargetResult = FindTargetCreature(tTemp, &pCre);
		if (pCre == NULL) break;
		if (tTemp.i < 0) break;
		if (tTemp.i > 9) break;
		unsigned int nNumBounce = 0;
		if (pCre->GetActiveStats().BounceSplLvl[tTemp.i]) {
			nNumBounce = UINT_MAX;
		} else {
			if (pCre->GetActiveStats().BounceSplLvlDec[tTemp.i].bOn)
				nNumBounce = pCre->GetActiveStats().BounceSplLvlDec[tTemp.i].nCount;
		}
		bResult = nNumBounce == tTemp.i2;
		}
		break;
	case TRIGGER_NUM_BOUNCING_SPELL_LEVEL_GT:
		{
		nFindTargetResult = FindTargetCreature(tTemp, &pCre);
		if (pCre == NULL) break;
		if (tTemp.i < 0) break;
		if (tTemp.i > 9) break;
		unsigned int nNumBounce = 0;
		if (pCre->GetActiveStats().BounceSplLvl[tTemp.i]) {
			nNumBounce = UINT_MAX;
		} else {
			if (pCre->GetActiveStats().BounceSplLvlDec[tTemp.i].bOn)
				nNumBounce = pCre->GetActiveStats().BounceSplLvlDec[tTemp.i].nCount;
		}
		bResult = nNumBounce > (unsigned int)tTemp.i2;
		}
		break;
	case TRIGGER_NUM_BOUNCING_SPELL_LEVEL_LT:
		{
		nFindTargetResult = FindTargetCreature(tTemp, &pCre);
		if (pCre == NULL) break;
		if (tTemp.i < 0) break;
		if (tTemp.i > 9) break;
		unsigned int nNumBounce = 0;
		if (pCre->GetActiveStats().BounceSplLvl[tTemp.i]) {
			nNumBounce = UINT_MAX;
		} else {
			if (pCre->GetActiveStats().BounceSplLvlDec[tTemp.i].bOn)
				nNumBounce = pCre->GetActiveStats().BounceSplLvlDec[tTemp.i].nCount;
		}
		bResult = nNumBounce < (unsigned int)tTemp.i2;
		}
		break;
	case TRIGGER_IMMUNE_SPELL_LEVEL:
		{
		nFindTargetResult = FindTargetCreature(tTemp, &pCre);
		if (pCre == NULL) break;
		if (tTemp.i < 0) break;
		if (tTemp.i > 9) break;
		bResult = pCre->GetActiveStats().ProtSplLvl[tTemp.i] || pCre->GetActiveStats().ProtSplLvlDec[tTemp.i].bOn;
		}
		break;
	case TRIGGER_NUM_IMMUNE_SPELL_LEVEL:
		{
		nFindTargetResult = FindTargetCreature(tTemp, &pCre);
		if (pCre == NULL) break;
		if (tTemp.i < 0) break;
		if (tTemp.i > 9) break;
		unsigned int nNumProt = 0;
		if (pCre->GetActiveStats().ProtSplLvl[tTemp.i]) {
			nNumProt = UINT_MAX;
		} else {
			if (pCre->GetActiveStats().ProtSplLvlDec[tTemp.i].bOn)
				nNumProt = pCre->GetActiveStats().ProtSplLvlDec[tTemp.i].nCount;
		}
		bResult = nNumProt == tTemp.i2;
		}
		break;
	case TRIGGER_NUM_IMMUNE_SPELL_LEVEL_GT:
		{
		nFindTargetResult = FindTargetCreature(tTemp, &pCre);
		if (pCre == NULL) break;
		if (tTemp.i < 0) break;
		if (tTemp.i > 9) break;
		unsigned int nNumProt = 0;
		if (pCre->GetActiveStats().ProtSplLvl[tTemp.i]) {
			nNumProt = UINT_MAX;
		} else {
			if (pCre->GetActiveStats().ProtSplLvlDec[tTemp.i].bOn)
				nNumProt = pCre->GetActiveStats().ProtSplLvlDec[tTemp.i].nCount;
		}
		bResult = nNumProt > (unsigned int)tTemp.i2;
		}
		break;
	case TRIGGER_NUM_IMMUNE_SPELL_LEVEL_LT:
		{
		nFindTargetResult = FindTargetCreature(tTemp, &pCre);
		if (pCre == NULL) break;
		if (tTemp.i < 0) break;
		if (tTemp.i > 9) break;
		unsigned int nNumProt = 0;
		if (pCre->GetActiveStats().ProtSplLvl[tTemp.i]) {
			nNumProt = UINT_MAX;
		} else {
			if (pCre->GetActiveStats().ProtSplLvlDec[tTemp.i].bOn)
				nNumProt = pCre->GetActiveStats().ProtSplLvlDec[tTemp.i].nCount;
		}
		bResult = nNumProt < (unsigned int)tTemp.i2;
		}
		break;
	case TRIGGER_TIME_STOP_COUNTER:
		bResult = g_pChitin->pGame->m_nTimeStopObjectsTicksLeft == tTemp.i;
		break;
	case TRIGGER_TIME_STOP_COUNTER_GT:
		bResult = g_pChitin->pGame->m_nTimeStopObjectsTicksLeft > tTemp.i;
		break;
	case TRIGGER_TIME_STOP_COUNTER_LT:
		bResult = g_pChitin->pGame->m_nTimeStopObjectsTicksLeft < tTemp.i;
		break;
	case TRIGGER_TIME_STOP_OBJECT:
		tTemp.DecodeIdentifiers(*this);
		pSprite = (CGameSprite*)&tTemp.o.FindTargetOfType(*this, CGAMEOBJECT_TYPE_SPRITE, FALSE);
		if (pSprite == NULL) break;
		bResult = pSprite->e == g_pChitin->pGame->m_eTimeStopExempt;
		break;
	case TRIGGER_NUM_TRAPPING_SPELL_LEVEL:
		{
		nFindTargetResult = FindTargetCreature(tTemp, &pCre);
		if (pCre == NULL) break;
		if (tTemp.i < 0) break;
		if (tTemp.i > 9) break;
		unsigned int nNumTrap = 0;
		if (pCre->GetActiveStats().SplTrapLvl[tTemp.i].bOn)
			nNumTrap = pCre->GetActiveStats().SplTrapLvl[tTemp.i].nCount;
		bResult = nNumTrap == tTemp.i2;
		}
		break;
	case TRIGGER_NUM_TRAPPING_SPELL_LEVEL_GT:
		{
		nFindTargetResult = FindTargetCreature(tTemp, &pCre);
		if (pCre == NULL) break;
		if (tTemp.i < 0) break;
		if (tTemp.i > 9) break;
		unsigned int nNumTrap = 0;
		if (pCre->GetActiveStats().SplTrapLvl[tTemp.i].bOn)
			nNumTrap = pCre->GetActiveStats().SplTrapLvl[tTemp.i].nCount;
		bResult = nNumTrap > (unsigned int)tTemp.i2;
		}
		break;
	case TRIGGER_NUM_TRAPPING_SPELL_LEVEL_LT:
		{
		nFindTargetResult = FindTargetCreature(tTemp, &pCre);
		if (pCre == NULL) break;
		if (tTemp.i < 0) break;
		if (tTemp.i > 9) break;
		unsigned int nNumTrap = 0;
		if (pCre->GetActiveStats().SplTrapLvl[tTemp.i].bOn)
			nNumTrap = pCre->GetActiveStats().SplTrapLvl[tTemp.i].nCount;
		bResult = nNumTrap < (unsigned int)tTemp.i2;
		}
		break;
	case TRIGGER_ORIGINAL_CLASS:
		{
		tTemp.DecodeIdentifiers(*this);
		unsigned char nClassOld;
		unsigned char nClassNew;
		tTemp.o.GetDualClasses(&nClassNew, &nClassOld);
		if (nClassNew == nClassOld) break; //not dual-class
		oCriteria.m_cClass = tTemp.i;
		Object oTemp;
		oTemp.m_cClass = nClassOld;
		bResult = oTemp.MatchCriteria(oCriteria, FALSE, FALSE, FALSE);
		}
		break;
	case TRIGGER_HP_LOST:
		{
		nFindTargetResult = FindTargetCreature(tTemp, &pCre);
		if (pCre == NULL) break;
		int nHurtAmount = pCre->m_cdsCurrent.maxHP - pCre->m_header.m_wHitPoints;
		bResult = nHurtAmount == tTemp.i;
		}
		break;
	case TRIGGER_HP_LOST_GT:
		{
		nFindTargetResult = FindTargetCreature(tTemp, &pCre);
		if (pCre == NULL) break;
		int nHurtAmount = pCre->m_cdsCurrent.maxHP - pCre->m_header.m_wHitPoints;
		bResult = nHurtAmount > tTemp.i;
		}
		break;
	case TRIGGER_HP_LOST_LT:
		{
		nFindTargetResult = FindTargetCreature(tTemp, &pCre);
		if (pCre == NULL) break;
		int nHurtAmount = pCre->m_cdsCurrent.maxHP - pCre->m_header.m_wHitPoints;
		bResult = nHurtAmount < tTemp.i;
		}
		break;
	case TRIGGER_EQUALS:
		bResult = tTemp.i == tTemp.i2;
		break;
	case TRIGGER_GT:
		bResult = tTemp.i > tTemp.i2;
		break;
	case TRIGGER_LT:
		bResult = tTemp.i < tTemp.i2;
		break;
	case TRIGGER_CHECK_STAT_BAND:
		{
		nFindTargetResult = FindTargetCreature(tTemp, &pCre);
		if (pCre == NULL) break;
		bResult = (BOOL)(pCre->GetActiveStats().GetStat(tTemp.i2) & tTemp.i);
		break;
		}
	default:
		bResult = (this->*Tramp_CGameSprite_EvaluateTrigger)(t);
		break;
	}

	if (pCre != NULL &&
		nFindTargetResult == 0) {
		g_pChitin->pGame->m_GameObjectArray.FreeShare(pCre->e, THREAD_ASYNCH, INFINITE);
	}

	if (pSprite != NULL)
		g_pChitin->pGame->m_GameObjectArray.FreeShare(pSprite->e, THREAD_ASYNCH, INFINITE);

	return bResult;

}

void DETOUR_CGameSprite::DETOUR_ClearAllActions(BOOL bSkipFlagged) {
	POSITION pos = actions.GetHeadPosition();
	if (bSkipFlagged) {
		POSITION posTarget = pos;
		while (posTarget = pos) {
			Action* pA = (Action*)actions.GetNext(pos);
			if (pA->dwFlags & 1 == 0) {
				//BioWare forgets to delete the action here
				delete pA;
				pA = NULL;

				actions.RemoveAt(posTarget);
			}
		}
	} else {
		while (pos) {
			Action* pA = (Action*)actions.GetNext(pos);
			delete pA;
			pA = NULL;
		}
		actions.RemoveAll();
	}

	//new - forcibly clear all action block variables
	CGameSprite_ActionClearBlockVars(*this);

	nCurrResponseIdx = -1;
	nCurrScriptBlockIdx = -1;
	nCurrScriptIdx = -1;
	return;
}

ACTIONRESULT DETOUR_CGameSprite::DETOUR_ExecuteAction() {
	if (0) IECString("DETOUR_CGameSprite::DETOUR_ExecuteAction");

	bExecutingAction = TRUE;
	ACTIONRESULT ar = ACTIONRESULT_ERROR;

	if (aCurrent.opcode == ACTION_BREAK_INSTANTS) SetCurrentAction(GetTopAction(g_pActionTemp));

	switch (aCurrent.opcode) {
	case ACTION_BREAK_INSTANTS:
		ar = ACTIONRESULT_DONE; //re-implement here to prevent weird behaviour for double BreakInstants()
		break;
	case ACTION_LOSE_GAME:
		g_pChitin->pGame->SetLoseCutscene();
		ar = ACTIONRESULT_DONE;
		break;
	case ACTION_DIALOG_SET_GLOBAL:
		aCurrent.opcode = ACTION_SET_GLOBAL;
		return (this->*Tramp_CGameSprite_ExecuteAction)();
		break;
	case ACTION_DIALOG_INCREMENT_GLOBAL:
		aCurrent.opcode = ACTION_INCREMENT_GLOBAL;
		return (this->*Tramp_CGameSprite_ExecuteAction)();
		break;
	case ACTION_DIALOG_SG:
		aCurrent.opcode = ACTION_SG;
		return (this->*Tramp_CGameSprite_ExecuteAction)();
		break;
	case ACTION_ASSIGN:
		ar = CGameSprite_ActionAssign(*this, this->aCurrent);
		break;
	case ACTION_EVAL:
		ar = CGameSprite_ActionEval(*this, this->aCurrent);
		break;
	case ACTION_CLEAR_BLOCK_VARIABLES:
		ar = CGameSprite_ActionClearBlockVars(*this);
		break;
	default:
		return (this->*Tramp_CGameSprite_ExecuteAction)();
		break;
	}

	arCurrent = ar;
	bExecutingAction = FALSE;

	return ar;

	return (this->*Tramp_CGameSprite_ExecuteAction)();
}

void DETOUR_CGameSprite::DETOUR_QueueActions(Response& r, BOOL bSkipIfAlreadyQueued, BOOL bClearActionQueue) {
	if (bSkipIfAlreadyQueued &&
		this->nCurrScriptBlockIdx >= 0 &&
		this->nCurrScriptIdx >= 0 &&
		this->nCurrScriptBlockIdx == r.nScriptBlockIdx &&
		this->nCurrScriptIdx == r.nScriptIdx) {
		return;
	}

	if (bClearActionQueue) ClearAllActions(FALSE);

	this->nCurrResponseIdx = r.nResponseIdx;
	this->nCurrScriptBlockIdx = r.nScriptBlockIdx;
	this->nCurrScriptIdx = r.nScriptIdx;
	this->bUseCurrScriptIdx = TRUE;

	if (this->GetType() != CGAMEOBJECT_TYPE_CREATURE) {
		Action* pAInterruptFalse = new Action();
		pAInterruptFalse->opcode = ACTION_SET_INTERRUPT;
		pAInterruptFalse->i = 0;
		this->actions.AddTail(pAInterruptFalse);
	}

	//new - add ClearVariables
	Action* pAClearBlockVars = new Action();
	pAClearBlockVars->opcode = ACTION_CLEAR_BLOCK_VARIABLES;
	this->actions.AddTail(pAClearBlockVars);

	POSITION pos = r.m_actions.GetHeadPosition();
	while (pos) {
		Action* aTemp = (Action*)r.m_actions.GetNext(pos);
		Action* pANew = new Action();
		*pANew = *aTemp;
		this->actions.AddTail(pANew);
	}

	if (this->GetType() != CGAMEOBJECT_TYPE_CREATURE) {
		Action* pAInterruptTrue = new Action();
		pAInterruptTrue->opcode = ACTION_SET_INTERRUPT;
		pAInterruptTrue->i = 1;
		this->actions.AddTail(pAInterruptTrue);
	}
}