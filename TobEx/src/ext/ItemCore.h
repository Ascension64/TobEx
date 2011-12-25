#ifndef ITEMCORE_H
#define ITEMCORE_H

#include "itmcore.h"

class DETOUR_CItem : public CItem {
public:
	void DETOUR_Equip(CCreatureObject& cre, int nSlot, BOOL bDoNotApplyEffects);
	CEffect& DETOUR_GetAbilityEffect(int nAbilityIdx, int nEffectIdx, CCreatureObject& creSource);
};

extern void (CItem::*Tramp_CItem_Equip)(CCreatureObject&, int, BOOL);
extern CEffect& (CItem::*Tramp_CItem_GetAbilityEffect)(int, int, CCreatureObject&);

#endif //ITEMCORE_H