//TobExEE
#ifndef OBJECTCORE_H
#define OBJECTCORE_H

#include "stdafx.h"
#include "objcore.h"

DeclareTrampMemberFunc(BOOL, CGameSprite, EvaluateTrigger, (Trigger& t), EvaluateTrigger);
DeclareTrampMemberFunc(void, CGameSprite, ClearAllActions, (BOOL bSkipFlagged), ClearAllActions);
DeclareTrampMemberFunc(ACTIONRESULT, CGameSprite, ExecuteAction, (), ExecuteAction);
DeclareTrampMemberFunc(void, CGameSprite, QueueActions, (Response& r, BOOL bSkipIfAlreadyQueued, BOOL bClearActionQueue), QueueActions);

class DETOUR_CGameSprite : public CGameSprite {
public:
	BOOL DETOUR_EvaluateTrigger(Trigger& t);
	void DETOUR_ClearAllActions(BOOL bSkipFlagged);
	ACTIONRESULT DETOUR_ExecuteAction();
	void DETOUR_QueueActions(Response& r, BOOL bSkipIfAlreadyQueued, BOOL bClearActionQueue);

	//new
	BOOL AtomicSetGlobal(Action& a);
	ACTIONRESULT ActionAssign(Action& a);
	ACTIONRESULT ActionEval(Action& a);
	ACTIONRESULT ActionClearBlockVars();
};

#endif //OBJECTCORE_H