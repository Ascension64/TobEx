#ifndef ITEMCORE_H
#define ITEMCORE_H

#include "itmcore.h"

class DETOUR_CItem : public CItem {
public:
	void DETOUR_Equip(CCreatureObject& cre, int nSlot, BOOL bDoNotApplyEffects);
};

extern void (CItem::*Tramp_CItem_Equip)(CCreatureObject&, int, BOOL);

#endif //ITEMCORE_H