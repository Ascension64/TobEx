//TobExEE
#include "ObjectCore.h"
#include "p_objcore.h"

#include "chitin.h"
#include "objcre.h"

#include "InfGameCommon.h"
#include "ScriptCommon.h"

DefineTrampMemberFunc(BOOL, CGameSprite, EvaluateTrigger, (Trigger& t), EvaluateTrigger, EvaluateTrigger, CGAMESPRITE_EVALUATETRIGGER);
DefineTrampMemberFunc(void, CGameSprite, ClearAllActions, (BOOL bSkipFlagged), ClearAllActions, ClearAllActions, CGAMESPRITE_CLEARALLACTIONS);
DefineTrampMemberFunc(ACTIONRESULT, CGameSprite, ExecuteAction, (), ExecuteAction, ExecuteAction, CGAMESPRITE_EXECUTEACTION);
DefineTrampMemberFunc(void, CGameSprite, QueueActions, (Response& r, BOOL bSkipIfAlreadyQueued, BOOL bClearActionQueue), QueueActions, QueueActions, CGAMESPRITE_QUEUEACTIONS);

BOOL DETOUR_CGameSprite::DETOUR_EvaluateTrigger(Trigger& t) {
	if (0) IECString("DETOUR_CGameSprite::DETOUR_EvaluateTrigger");

	Trigger tTemp = t;
	CCreatureObject* pCre = NULL;
	CGameSprite* pSprite = NULL;
	Object oCriteria;
	int nFindTargetResult = 0;
	BOOL bResult = FALSE;

	switch (tTemp.m_wOpcode) {
	case TRIGGER_MOVEMENT_RATE:
		{
		nFindTargetResult = FindTargetCreature(tTemp, &pCre);
		if (pCre == NULL) break;
		CAnimation* pAnim = pCre->m_animation.m_pAnimation;
		if (pAnim == NULL) break;
		unsigned char nMvt = pAnim->GetCurrentMovementRate();
		bResult = (signed int)nMvt == tTemp.m_i;
		}
		break;
	case TRIGGER_MOVEMENT_RATE_GT:
		{
		nFindTargetResult = FindTargetCreature(tTemp, &pCre);
		if (pCre == NULL) break;
		CAnimation* pAnim = pCre->m_animation.m_pAnimation;
		if (pAnim == NULL) break;
		unsigned char nMvt = pAnim->GetCurrentMovementRate();
		bResult = (signed int)nMvt > tTemp.m_i;
		}
		break;
	case TRIGGER_MOVEMENT_RATE_LT:
		{
		nFindTargetResult = FindTargetCreature(tTemp, &pCre);
		if (pCre == NULL) break;
		CAnimation* pAnim = pCre->m_animation.m_pAnimation;
		if (pAnim == NULL) break;
		unsigned char nMvt = pAnim->GetCurrentMovementRate();
		bResult = (signed int)nMvt < tTemp.m_i;
		}
		break;
	case TRIGGER_NUM_MIRRORIMAGES:
		{
		nFindTargetResult = FindTargetCreature(tTemp, &pCre);
		if (pCre == NULL) break;
		unsigned char nImages = pCre->m_nMirrorImages;
		bResult = (signed int)nImages == tTemp.m_i;
		}
		break;
	case TRIGGER_NUM_MIRRORIMAGES_GT:
		{
		nFindTargetResult = FindTargetCreature(tTemp, &pCre);
		if (pCre == NULL) break;
		unsigned char nImages = pCre->m_nMirrorImages;
		bResult = (signed int)nImages > tTemp.m_i;
		}
		break;
	case TRIGGER_NUM_MIRRORIMAGES_LT:
		{
		nFindTargetResult = FindTargetCreature(tTemp, &pCre);
		if (pCre == NULL) break;
		unsigned char nImages = pCre->m_nMirrorImages;
		bResult = (signed int)nImages < tTemp.m_i;
		}
		break;
	case TRIGGER_BOUNCING_SPELL_LEVEL:
		{
		nFindTargetResult = FindTargetCreature(tTemp, &pCre);
		if (pCre == NULL) break;
		if (tTemp.m_i < 0) break;
		if (tTemp.m_i > 9) break;
		bResult = pCre->GetDerivedStats().m_bBounceSplLvl[tTemp.m_i] || pCre->GetDerivedStats().m_BounceSplLvlDec[tTemp.m_i].m_bOn;
		}
		break;
	case TRIGGER_NUM_BOUNCING_SPELL_LEVEL:
		{
		nFindTargetResult = FindTargetCreature(tTemp, &pCre);
		if (pCre == NULL) break;
		if (tTemp.m_i < 0) break;
		if (tTemp.m_i > 9) break;
		unsigned int nNumBounce = 0;
		if (pCre->GetDerivedStats().m_bBounceSplLvl[tTemp.m_i]) {
			nNumBounce = UINT_MAX;
		} else {
			if (pCre->GetDerivedStats().m_BounceSplLvlDec[tTemp.m_i].m_bOn)
				nNumBounce = pCre->GetDerivedStats().m_BounceSplLvlDec[tTemp.m_i].m_nCount;
		}
		bResult = nNumBounce == tTemp.m_i2;
		}
		break;
	case TRIGGER_NUM_BOUNCING_SPELL_LEVEL_GT:
		{
		nFindTargetResult = FindTargetCreature(tTemp, &pCre);
		if (pCre == NULL) break;
		if (tTemp.m_i < 0) break;
		if (tTemp.m_i > 9) break;
		unsigned int nNumBounce = 0;
		if (pCre->GetDerivedStats().m_bBounceSplLvl[tTemp.m_i]) {
			nNumBounce = UINT_MAX;
		} else {
			if (pCre->GetDerivedStats().m_BounceSplLvlDec[tTemp.m_i].m_bOn)
				nNumBounce = pCre->GetDerivedStats().m_BounceSplLvlDec[tTemp.m_i].m_nCount;
		}
		bResult = nNumBounce > (unsigned int)tTemp.m_i2;
		}
		break;
	case TRIGGER_NUM_BOUNCING_SPELL_LEVEL_LT:
		{
		nFindTargetResult = FindTargetCreature(tTemp, &pCre);
		if (pCre == NULL) break;
		if (tTemp.m_i < 0) break;
		if (tTemp.m_i > 9) break;
		unsigned int nNumBounce = 0;
		if (pCre->GetDerivedStats().m_bBounceSplLvl[tTemp.m_i]) {
			nNumBounce = UINT_MAX;
		} else {
			if (pCre->GetDerivedStats().m_BounceSplLvlDec[tTemp.m_i].m_bOn)
				nNumBounce = pCre->GetDerivedStats().m_BounceSplLvlDec[tTemp.m_i].m_nCount;
		}
		bResult = nNumBounce < (unsigned int)tTemp.m_i2;
		}
		break;
	case TRIGGER_IMMUNE_SPELL_LEVEL:
		{
		nFindTargetResult = FindTargetCreature(tTemp, &pCre);
		if (pCre == NULL) break;
		if (tTemp.m_i < 0) break;
		if (tTemp.m_i > 9) break;
		bResult = pCre->GetDerivedStats().m_bProtSplLvl[tTemp.m_i] || pCre->GetDerivedStats().m_ProtSplLvlDec[tTemp.m_i].m_bOn;
		}
		break;
	case TRIGGER_NUM_IMMUNE_SPELL_LEVEL:
		{
		nFindTargetResult = FindTargetCreature(tTemp, &pCre);
		if (pCre == NULL) break;
		if (tTemp.m_i < 0) break;
		if (tTemp.m_i > 9) break;
		unsigned int nNumProt = 0;
		if (pCre->GetDerivedStats().m_bProtSplLvl[tTemp.m_i]) {
			nNumProt = UINT_MAX;
		} else {
			if (pCre->GetDerivedStats().m_ProtSplLvlDec[tTemp.m_i].m_bOn)
				nNumProt = pCre->GetDerivedStats().m_ProtSplLvlDec[tTemp.m_i].m_nCount;
		}
		bResult = nNumProt == tTemp.m_i2;
		}
		break;
	case TRIGGER_NUM_IMMUNE_SPELL_LEVEL_GT:
		{
		nFindTargetResult = FindTargetCreature(tTemp, &pCre);
		if (pCre == NULL) break;
		if (tTemp.m_i < 0) break;
		if (tTemp.m_i > 9) break;
		unsigned int nNumProt = 0;
		if (pCre->GetDerivedStats().m_bProtSplLvl[tTemp.m_i]) {
			nNumProt = UINT_MAX;
		} else {
			if (pCre->GetDerivedStats().m_ProtSplLvlDec[tTemp.m_i].m_bOn)
				nNumProt = pCre->GetDerivedStats().m_ProtSplLvlDec[tTemp.m_i].m_nCount;
		}
		bResult = nNumProt > (unsigned int)tTemp.m_i2;
		}
		break;
	case TRIGGER_NUM_IMMUNE_SPELL_LEVEL_LT:
		{
		nFindTargetResult = FindTargetCreature(tTemp, &pCre);
		if (pCre == NULL) break;
		if (tTemp.m_i < 0) break;
		if (tTemp.m_i > 9) break;
		unsigned int nNumProt = 0;
		if (pCre->GetDerivedStats().m_bProtSplLvl[tTemp.m_i]) {
			nNumProt = UINT_MAX;
		} else {
			if (pCre->GetDerivedStats().m_ProtSplLvlDec[tTemp.m_i].m_bOn)
				nNumProt = pCre->GetDerivedStats().m_ProtSplLvlDec[tTemp.m_i].m_nCount;
		}
		bResult = nNumProt < (unsigned int)tTemp.m_i2;
		}
		break;
	case TRIGGER_TIME_STOP_COUNTER:
		bResult = g_pChitin->GetInfGame().m_nTimeStopObjectsTicksLeft == tTemp.m_i;
		break;
	case TRIGGER_TIME_STOP_COUNTER_GT:
		bResult = g_pChitin->GetInfGame().m_nTimeStopObjectsTicksLeft > tTemp.m_i;
		break;
	case TRIGGER_TIME_STOP_COUNTER_LT:
		bResult = g_pChitin->GetInfGame().m_nTimeStopObjectsTicksLeft < tTemp.m_i;
		break;
	case TRIGGER_TIME_STOP_OBJECT:
		tTemp.DecodeIdentifiers(*this);
		pSprite = (CGameSprite*)&tTemp.m_o.FindTargetOfType(*this, CGAMEOBJECT_TYPE_SPRITE, FALSE);
		if (pSprite == NULL) break;
		bResult = pSprite->m_e == g_pChitin->GetInfGame().m_eTimeStopExempt;
		break;
	case TRIGGER_NUM_TRAPPING_SPELL_LEVEL:
		{
		nFindTargetResult = FindTargetCreature(tTemp, &pCre);
		if (pCre == NULL) break;
		if (tTemp.m_i < 0) break;
		if (tTemp.m_i > 9) break;
		unsigned int nNumTrap = 0;
		if (pCre->GetDerivedStats().m_SplTrapLvl[tTemp.m_i].m_bOn)
			nNumTrap = pCre->GetDerivedStats().m_SplTrapLvl[tTemp.m_i].m_nCount;
		bResult = nNumTrap == tTemp.m_i2;
		}
		break;
	case TRIGGER_NUM_TRAPPING_SPELL_LEVEL_GT:
		{
		nFindTargetResult = FindTargetCreature(tTemp, &pCre);
		if (pCre == NULL) break;
		if (tTemp.m_i < 0) break;
		if (tTemp.m_i > 9) break;
		unsigned int nNumTrap = 0;
		if (pCre->GetDerivedStats().m_SplTrapLvl[tTemp.m_i].m_bOn)
			nNumTrap = pCre->GetDerivedStats().m_SplTrapLvl[tTemp.m_i].m_nCount;
		bResult = nNumTrap > (unsigned int)tTemp.m_i2;
		}
		break;
	case TRIGGER_NUM_TRAPPING_SPELL_LEVEL_LT:
		{
		nFindTargetResult = FindTargetCreature(tTemp, &pCre);
		if (pCre == NULL) break;
		if (tTemp.m_i < 0) break;
		if (tTemp.m_i > 9) break;
		unsigned int nNumTrap = 0;
		if (pCre->GetDerivedStats().m_SplTrapLvl[tTemp.m_i].m_bOn)
			nNumTrap = pCre->GetDerivedStats().m_SplTrapLvl[tTemp.m_i].m_nCount;
		bResult = nNumTrap < (unsigned int)tTemp.m_i2;
		}
		break;
	case TRIGGER_ORIGINAL_CLASS:
		{
		tTemp.DecodeIdentifiers(*this);
		unsigned char nClassOld;
		unsigned char nClassNew;
		tTemp.m_o.GetDualClasses(&nClassNew, &nClassOld);
		if (nClassNew == nClassOld) break; //not dual-class
		oCriteria.m_cClass = tTemp.m_i;
		Object oTemp;
		oTemp.m_cClass = nClassOld;
		bResult = oTemp.MatchCriteria(oCriteria, FALSE, FALSE, FALSE);
		}
		break;
	case TRIGGER_HP_LOST:
		{
		nFindTargetResult = FindTargetCreature(tTemp, &pCre);
		if (pCre == NULL) break;
		int nHurtAmount = pCre->m_cdsCurrent.m_wMaxHP - pCre->m_header.m_wHitPoints;
		bResult = nHurtAmount == tTemp.m_i;
		}
		break;
	case TRIGGER_HP_LOST_GT:
		{
		nFindTargetResult = FindTargetCreature(tTemp, &pCre);
		if (pCre == NULL) break;
		int nHurtAmount = pCre->m_cdsCurrent.m_wMaxHP - pCre->m_header.m_wHitPoints;
		bResult = nHurtAmount > tTemp.m_i;
		}
		break;
	case TRIGGER_HP_LOST_LT:
		{
		nFindTargetResult = FindTargetCreature(tTemp, &pCre);
		if (pCre == NULL) break;
		int nHurtAmount = pCre->m_cdsCurrent.m_wMaxHP - pCre->m_header.m_wHitPoints;
		bResult = nHurtAmount < tTemp.m_i;
		}
		break;
	case TRIGGER_EQUALS:
		bResult = tTemp.m_i == tTemp.m_i2;
		break;
	case TRIGGER_GT:
		bResult = tTemp.m_i > tTemp.m_i2;
		break;
	case TRIGGER_LT:
		bResult = tTemp.m_i < tTemp.m_i2;
		break;
	case TRIGGER_CHECK_STAT_BAND:
		{
		nFindTargetResult = FindTargetCreature(tTemp, &pCre);
		if (pCre == NULL) break;
		bResult = (BOOL)(pCre->GetDerivedStats().GetStat(tTemp.m_i2) & tTemp.m_i);
		break;
		}
	default:
		bResult = (this->*Tramp_CGameSprite_EvaluateTrigger)(t);
		break;
	}

	return bResult;

}

void DETOUR_CGameSprite::DETOUR_ClearAllActions(BOOL bSkipFlagged) {
	POSITION pos = m_lActions.GetHeadPosition();
	if (bSkipFlagged) {
		POSITION posTarget = pos;
		while (posTarget = pos) {
			Action* pA = (Action*)m_lActions.GetNext(pos);
			if (pA->m_dwFlags & 1 == 0) {
				//BioWare forgets to delete the action here
				delete pA;
				pA = NULL;

				m_lActions.RemoveAt(posTarget);
			}
		}
	} else {
		while (pos) {
			Action* pA = (Action*)m_lActions.GetNext(pos);
			delete pA;
			pA = NULL;
		}
		m_lActions.RemoveAll();
	}

	//new - forcibly clear all action block variables
	ActionClearBlockVars();

	m_nCurrResponseIdx = -1;
	m_nCurrScriptBlockIdx = -1;
	m_nCurrScriptIdx = -1;
	return;
}

ACTIONRESULT DETOUR_CGameSprite::DETOUR_ExecuteAction() {
	if (0) IECString("DETOUR_CGameSprite::DETOUR_ExecuteAction");

	m_bExecutingAction = TRUE;
	ACTIONRESULT ar = ACTIONRESULT_ERROR;

	if (m_aCurrent.m_wOpcode == ACTION_BREAK_INSTANTS) SetCurrentAction(GetTopAction(g_pActionTemp));

	switch (m_aCurrent.m_wOpcode) {
	case ACTION_BREAK_INSTANTS:
		ar = ACTIONRESULT_DONE; //re-implement here to prevent weird behaviour for double BreakInstants()
		break;
	case ACTION_LOSE_GAME:
		g_pChitin->GetInfGame().SetLoseCutscene();
		ar = ACTIONRESULT_DONE;
		break;
	case ACTION_DIALOG_SET_GLOBAL:
		m_aCurrent.m_wOpcode = ACTION_SET_GLOBAL;
		return (this->*Tramp_CGameSprite_ExecuteAction)();
		break;
	case ACTION_DIALOG_INCREMENT_GLOBAL:
		m_aCurrent.m_wOpcode = ACTION_INCREMENT_GLOBAL;
		return (this->*Tramp_CGameSprite_ExecuteAction)();
		break;
	case ACTION_DIALOG_SG:
		m_aCurrent.m_wOpcode = ACTION_SG;
		return (this->*Tramp_CGameSprite_ExecuteAction)();
		break;
	case ACTION_ASSIGN:
		ar = ActionAssign(m_aCurrent);
		break;
	case ACTION_EVAL:
		ar = ActionEval(m_aCurrent);
		break;
	case ACTION_CLEAR_BLOCK_VARIABLES:
		ar = ActionClearBlockVars();
		break;
	default:
		return (this->*Tramp_CGameSprite_ExecuteAction)();
		break;
	}

	arCurrent = ar;
	m_bExecutingAction = FALSE;

	return ar;

	return (this->*Tramp_CGameSprite_ExecuteAction)();
}

void DETOUR_CGameSprite::DETOUR_QueueActions(Response& r, BOOL bSkipIfAlreadyQueued, BOOL bClearActionQueue) {
	if (bSkipIfAlreadyQueued &&
		this->m_nCurrScriptBlockIdx >= 0 &&
		this->m_nCurrScriptIdx >= 0 &&
		this->m_nCurrScriptBlockIdx == r.m_wScriptBlockIdx &&
		this->m_nCurrScriptIdx == r.m_wScriptIdx) {
		return;
	}

	if (bClearActionQueue) ClearAllActions(FALSE);

	this->m_nCurrResponseIdx = r.m_wResponseIdx;
	this->m_nCurrScriptBlockIdx = r.m_wScriptBlockIdx;
	this->m_nCurrScriptIdx = r.m_wScriptIdx;
	this->m_bUseCurrScriptIdx = TRUE;

	if (this->GetType() != CGAMEOBJECT_TYPE_CREATURE) {
		Action* pAInterruptFalse = new Action();
		pAInterruptFalse->m_wOpcode = ACTION_SET_INTERRUPT;
		pAInterruptFalse->m_i = 0;
		this->m_lActions.AddTail(pAInterruptFalse);
	}

	//new - add ClearVariables
	Action* pAClearBlockVars = new Action();
	pAClearBlockVars->m_wOpcode = ACTION_CLEAR_BLOCK_VARIABLES;
	this->m_lActions.AddTail(pAClearBlockVars);

	POSITION pos = r.m_lActions.GetHeadPosition();
	while (pos) {
		Action* aTemp = (Action*)r.m_lActions.GetNext(pos);
		Action* pANew = new Action();
		*pANew = *aTemp;
		this->m_lActions.AddTail(pANew);
	}

	if (this->GetType() != CGAMEOBJECT_TYPE_CREATURE) {
		Action* pAInterruptTrue = new Action();
		pAInterruptTrue->m_wOpcode = ACTION_SET_INTERRUPT;
		pAInterruptTrue->m_i = 1;
		this->m_lActions.AddTail(pAInterruptTrue);
	}
}

BOOL DETOUR_CGameSprite::AtomicSetGlobal(Action& a) {
	IECString sArg = a.m_s1;
	sArg.MakeUpper();
	IECString sScope = sArg.Left(6);
	IECString sVariable = sArg.Right(sArg.GetLength() - 6);
	CVariable varNew;

	BOOL bIncrement = a.m_wOpcode == ACTION_INCREMENT_GLOBAL;
	int nNewValue;

	CGameSprite* pTarget = NULL;
	Object oOverride = a.m_oOverride;
	if (!oOverride.MatchCriteria(*g_poAny, FALSE, FALSE, FALSE) ||
		!oOverride.m_sName.IsEmpty() ||
		oOverride.m_oids.m_id1 != OBJECT_NOTHING) {
		oOverride.DecodeIdentifiers(*this);
		pTarget = (CGameSprite*)&oOverride.FindTargetOfType(*this, CGAMEOBJECT_TYPE_SPRITE, FALSE);
		if (pTarget) {
			a.m_oOverride = *g_poAny;
		} else {
			return TRUE;
		}
	} else {
		pTarget = this;
	}

	if (a.m_wOpcode == ACTION_SG) {
		sScope = "GLOBAL";
		sVariable = sArg;
	}

	if (!sScope.Compare("GLOBAL")) {
		CVariable& var = g_pChitin->GetInfGame().m_GlobalVariables.Find(sVariable);
		if (&var != NULL) {
			var.m_nValue = bIncrement ? var.m_nValue + a.m_i : a.m_i;
			nNewValue = var.m_nValue;
		} else {
			varNew.SetName(sVariable);
			varNew.m_nValue = a.m_i;
			nNewValue = varNew.m_nValue;
			g_pChitin->GetInfGame().m_GlobalVariables.Add(varNew);
		}

		CMessageModifyVariable* pMsg = new CMessageModifyVariable(
			sVariable,
			sScope,
			nNewValue,
			0,
			pTarget->m_e,
			pTarget->m_e);
		g_pChitin->m_MessageHandler.AddMessage(*pMsg, FALSE);

		return TRUE;
	}

	if (!sScope.Compare("LOCALS")) {
		if (pTarget->GetType() == CGAMEOBJECT_TYPE_CREATURE) {
			CVariable& var = ((CCreatureObject*)pTarget)->m_pLocalVariables->Find(sVariable);
			if (&var != NULL) {
				var.m_nValue = bIncrement ? var.m_nValue + a.m_i : a.m_i;
				nNewValue = var.m_nValue;
			} else {
				varNew.SetName(sVariable);
				varNew.m_nValue = a.m_i;
				nNewValue = varNew.m_nValue;
				((CCreatureObject*)pTarget)->m_pLocalVariables->Add(varNew); //64A2E8
			}

			CMessageModifyVariable* pMsg = new CMessageModifyVariable(
				sVariable,
				sScope,
				nNewValue,
				0,
				pTarget->m_e,
				pTarget->m_e);
			g_pChitin->m_MessageHandler.AddMessage(*pMsg, FALSE);

			return TRUE;
		} else {
			LPCTSTR lpsz = "CGameSprite_AtomicSetGlobal(): pTarget not CGAMEOBJECT_TYPE_CREATURE for setting LOCALS\r\n";
			L.timestamp();
			L.append(lpsz);
			console.write(lpsz);
			return TRUE;
		}
	}

	if (!sScope.Compare("MYAREA")) {
		sScope = pTarget->m_pArea->m_rAreaName.FormatToString();
	}
	CArea& area = g_pChitin->GetInfGame().GetLoadedArea(sScope);
	if (&area != NULL) {
		CVariable& var = area.m_mapAreaVariables.Find(sVariable);
		if (&var != NULL) {
			var.m_nValue = bIncrement ? var.m_nValue + a.m_i : a.m_i;
			nNewValue = var.m_nValue;
		} else {
			varNew.SetName(sVariable);
			varNew.m_nValue = a.m_i;
			nNewValue = varNew.m_nValue;
			area.m_mapAreaVariables.Add(varNew);
		}

		CMessageModifyVariable* pMsg = new CMessageModifyVariable(
			sVariable,
			sScope,
			nNewValue,
			0,
			pTarget->m_e,
			pTarget->m_e);
		g_pChitin->m_MessageHandler.AddMessage(*pMsg, FALSE);

		return TRUE;
	}

	return TRUE;
}

ACTIONRESULT DETOUR_CGameSprite::ActionAssign(Action& a) {
	IECString sStatement = a.m_s1;
	CGameSprite* pSpriteRef = NULL;
	if (!a.m_oObject.IsEqualIncludeEnum(*g_poAny)) {
		a.m_oObject.DecodeIdentifiers(*this);
		pSpriteRef = (CGameSprite*)&a.m_oObject.FindTargetOfType(*this, CGAMEOBJECT_TYPE_SPRITE, FALSE);
	} else {
		pSpriteRef = this;
	}
	if (pSpriteRef &&
		a.m_i2 >= 0 && a.m_i2 < BLOCK_VAR_ARRAY_SIZE) {
		std::map<ENUM, CBlockVariables*>::iterator it = pRuleEx->m_MapActionVars.find(m_e);
		if (it == pRuleEx->m_MapActionVars.end()) pRuleEx->m_MapActionVars[m_e] = new CBlockVariables();

		if (a.m_i == ARGTYPE_INT) {
			ParseStatement(a.m_i2, a.m_i, sStatement, *pSpriteRef, *pRuleEx->m_MapActionVars[m_e]);
		} else if (a.m_i == ARGTYPE_STR) {
			ParseStatement(a.m_i2, a.m_i, sStatement, *pSpriteRef, *pRuleEx->m_MapActionVars[m_e]);
		}
	}

	return ACTIONRESULT_DONE;
}

ACTIONRESULT DETOUR_CGameSprite::ActionEval(Action& a) {
	IECString sExpression;
	Action* aTarget = NULL;

	std::map<ENUM, CBlockVariables*>::iterator it = pRuleEx->m_MapActionVars.find(m_e);
	if (it == pRuleEx->m_MapActionVars.end()) {
		sExpression = a.m_s1;
	} else {
		sExpression = ParseBlockVariables(a.m_s1, a.m_i, *pRuleEx->m_MapActionVars[m_e]);
	}

	POSITION pos = m_lActions.GetHeadPosition();
	POSITION posTarget = NULL;
	while (posTarget = pos) {
		Action* aTemp = (Action*)m_lActions.GetNext(pos);
		if (aTemp->m_wOpcode == ACTION_CLEAR_BLOCK_VARIABLES) {
			posTarget = NULL;
			break;
		}
		if (aTemp->m_wOpcode != ACTION_EVAL &&
			aTemp->m_wOpcode != ACTION_ASSIGN)
			break;
	}
	if (posTarget) {
		aTarget = (Action*)m_lActions.GetAt(posTarget);
	}

	if (aTarget) {
		if (a.m_i == ARGTYPE_INT) {
			int nValue = 0;
			MathPresso::Expression mpExp;
			MathPresso::mresult_t mpResult = mpExp.create(pRuleEx->m_mpContext, (LPCTSTR)sExpression);
			if (mpResult == MathPresso::MRESULT_OK) {
				nValue = mpExp.evaluate(NULL);
			} else {
				LPCTSTR lpsz = "Action Eval(): bad expression \"%s\" (error %d)\r\n";
				L.timestamp();
				L.appendf(lpsz, (LPCTSTR)sExpression, (int)mpResult);
				console.writef(lpsz, (LPCTSTR)sExpression, (int)mpResult);
			}

			switch (a.m_i2) {
			case 1: //int1
				aTarget->m_i = nValue;
				break;
			case 2: //int2
				aTarget->m_i2 = nValue;
				break;
			case 3: //int3
				aTarget->m_i3 = nValue;
				break;
			case 4: //pt.x
				aTarget->m_pt.x = nValue;
				break;
			case 5: //pt.y
				aTarget->m_pt.y = nValue;
				break;
			default:
				break;
			}

		} else if (a.m_i == ARGTYPE_STR) {
			switch (a.m_i2) {
			case 1: //int1
				aTarget->m_s1 = sExpression;
				break;
			case 2: //int2
				aTarget->m_s2 = sExpression;
				break;
			default:
				break;
			}
		}
	}

	return ACTIONRESULT_DONE;
}

ACTIONRESULT DETOUR_CGameSprite::ActionClearBlockVars() {
	std::map<ENUM, CBlockVariables*>::iterator it = pRuleEx->m_MapActionVars.find(m_e);
	if (it != pRuleEx->m_MapActionVars.end()) {
		it->second->Empty();
		/*delete pRuleEx->m_MapActionVars[sprite.e];
		pRuleEx->m_MapActionVars[sprite.e] = NULL;
		pRuleEx->m_MapActionVars.erase(it);*/
	}

	return ACTIONRESULT_DONE;
}
