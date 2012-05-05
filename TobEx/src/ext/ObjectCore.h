#ifndef OBJECTCORE_H
#define OBJECTCORE_H

#include "stdafx.h"
#include "objcore.h"

extern BOOL (CGameSprite::*Tramp_CGameSprite_EvaluateTrigger)(Trigger&);
extern void (CGameSprite::*Tramp_CGameSprite_ClearAllActions)(BOOL);
extern ACTIONRESULT (CGameSprite::*Tramp_CGameSprite_ExecuteAction)();
extern void (CGameSprite::*Tramp_CGameSprite_QueueActions)(Response&, BOOL, BOOL);

class DETOUR_CGameSprite : public CGameSprite {
public:
	BOOL DETOUR_EvaluateTrigger(Trigger& t);
	void DETOUR_ClearAllActions(BOOL bSkipFlagged);
	ACTIONRESULT DETOUR_ExecuteAction();
	void DETOUR_QueueActions(Response& r, BOOL bSkipIfAlreadyQueued, BOOL bClearActionQueue);
};

#endif //OBJECTCORE_H