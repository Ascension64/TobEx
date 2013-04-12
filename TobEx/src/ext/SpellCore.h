#ifndef SPELLCORE_H
#define SPELLCORE_H

#include "splcore.h"

DeclareTrampMemberFunc(CEffect&, ResSplFile, GetAbilityEffect, (int nAbilityIdx, int nEffectIdx, CCreatureObject& creSource), GetAbilityEffect);

struct DETOUR_ResSplFile : public ResSplFile {
	CEffect& DETOUR_GetAbilityEffect(int nAbilityIdx, int nEffectIdx, CCreatureObject& creSource);
};

#endif //SPELLCORE_H