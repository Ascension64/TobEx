#ifndef SPELLCORE_H
#define SPELLCORE_H

#include "splcore.h"

struct DETOUR_ResSplContainer : public ResSplContainer {
	CEffect& DETOUR_GetAbilityEffect(int nAbilityIdx, int nEffectIdx, CCreatureObject& creSource);
};

extern CEffect& (ResSplContainer::*Tramp_ResSplContainer_GetAbilityEffect)(int, int, CCreatureObject&);

#endif //SPELLCORE_H