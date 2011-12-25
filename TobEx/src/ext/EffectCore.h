#ifndef EFFECTCORE_H
#define EFFECTCORE_H

#include "utils.h"
#include "effcore.h"
#include "objcre.h"

extern CEffect& (*Tramp_CEffect_CreateEffect)(ITEM_EFFECT&, POINT&, Enum, POINT&, Enum);

class DETOUR_CEffect : public CEffect {
public:
	static CEffect& DETOUR_CreateEffect(ITEM_EFFECT&, POINT&, Enum, POINT&, Enum);
};

#endif //EFFECTCOMMON_H