//TobExEE
#include "ObjectCreature.h"
#include "p_objcre.h"

#include "chitin.h"
#include "optionsext.h"

#include "InfGameCommon.h"

DefineTrampMemberFunc(BOOL, CCreatureObject, EvaluateTrigger, (Trigger& t), EvaluateTrigger, EvaluateTrigger, CCREATUREOBJECT_EVALUATETRIGGER);
DefineTrampMemberFunc(ACTIONRESULT, CCreatureObject, ExecuteAction, (), ExecuteAction, ExecuteAction, CCREATUREOBJECT_EXECUTEACTION);

BOOL DETOUR_CCreatureObject::DETOUR_EvaluateTrigger(Trigger& t) {
	if (0) IECString("DETOUR_CCreatureObject::DETOUR_EvaluateTrigger");

	Trigger tTemp = t;
	switch (tTemp.m_wOpcode) {
	default:
		return (this->*Tramp_CCreatureObject_EvaluateTrigger)(t);
		break;
	}

	return FALSE;
}

ACTIONRESULT DETOUR_CCreatureObject::DETOUR_ExecuteAction() {
	m_bExecutingAction = TRUE;
	ACTIONRESULT ar = ACTIONRESULT_DONE;

	if (m_aCurrent.m_wOpcode == ACTION_BREAK_INSTANTS) SetCurrentAction(GetTopAction(g_pActionTemp));

	switch (m_aCurrent.m_wOpcode) {
	case ACTION_BREAK_INSTANTS:
		ar = ACTIONRESULT_DONE; //re-implement here to prevent weird behaviour for double BreakInstants()
		break;
	default:
		return (this->*Tramp_CCreatureObject_ExecuteAction)();
		break;
	}

	arCurrent = ar;
	m_bExecutingAction = FALSE;

	return ar;
}
