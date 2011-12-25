#ifndef EFFECTCORE_H
#define EFFECTCORE_H

#include "stdafx.h"
#include "effcore.h"
#include "objcre.h"

//CEffect
extern CEffect& (*Tramp_CEffect_CreateEffect)(ITEM_EFFECT&, POINT&, Enum, POINT&, Enum);
extern BOOL (CEffect::*Tramp_CEffect_ApplyTiming)(CCreatureObject&);

class DETOUR_CEffect : public CEffect {
public:
	static CEffect& DETOUR_CreateEffect(ITEM_EFFECT& eff, POINT& ptSource, Enum eSource, POINT& ptDest, Enum e2);
	BOOL DETOUR_ApplyTiming(CCreatureObject& creTarget);
};

#endif //EFFECTCOMMON_H