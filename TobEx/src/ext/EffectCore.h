#ifndef EFFECTCORE_H
#define EFFECTCORE_H

#include "utils.h"
#include "effcore.h"
#include "objcre.h"

class DETOUR_CEffect : public CEffect {
public:
	static CEffect& CreateEffect(ITEM_EFFECT&, POINT&, Enum, POINT&, Enum);
};

#endif //EFFECTCOMMON_H