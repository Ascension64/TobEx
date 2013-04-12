#ifndef ITEMCORE_H
#define ITEMCORE_H

#include "itmcore.h"

DeclareTrampMemberFunc(void, CItem, Equip, (CCreatureObject& cre, int nSlot, BOOL bDoNotApplyEffects), Equip);
DeclareTrampMemberFunc(CEffect&, CItem, GetAbilityEffect, (int nAbilityIdx, int nEffectIdx, CCreatureObject& creSource), GetAbilityEffect);

class DETOUR_CItem : public CItem {
public:
	void DETOUR_Equip(CCreatureObject& cre, int nSlot, BOOL bDoNotApplyEffects);
	CEffect& DETOUR_GetAbilityEffect(int nAbilityIdx, int nEffectIdx, CCreatureObject& creSource);
};

#endif //ITEMCORE_H