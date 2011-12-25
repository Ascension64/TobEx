#ifndef OBJECTCORE_H
#define OBJECTCORE_H

#include "stdafx.h"
#include "objcore.h"

extern BOOL (CGameSprite::*Tramp_CGameSprite_EvaluateTrigger)(Trigger&);
extern ACTIONRESULT (CGameSprite::*Tramp_CGameSprite_ExecuteAction)();

class DETOUR_CGameSprite : public CGameSprite {
public:
	BOOL DETOUR_EvaluateTrigger(Trigger& t);
	ACTIONRESULT DETOUR_ExecuteAction();
};

#endif //OBJECTCORE_H