#ifndef EFFECTCOMMON_H
#define EFFECTCOMMON_H

#include "effcore.h"
#include "objcre.h"

//Effect stacking behaviours
#define EFFECT_STACKING_SUSPEND	0x00010000

bool CEffect_IsSimilar(CEffect& eff1, CEffect& eff2);
CEffect* CEffectList_Find(CEffectList& list, CEffect& eff, POSITION posCurrent, CCreatureObject& cre);

#endif //EFFECTCOMMON_H