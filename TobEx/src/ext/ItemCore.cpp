#include "ItemCore.h"

#include "objcre.h"

void (CItem::*Tramp_CItem_Equip)(CCreatureObject&, int, BOOL) =
	SetFP(static_cast<void (CItem::*)(CCreatureObject&, int, BOOL)>	(&CItem::Equip),			0x5AA430);

void DETOUR_CItem::DETOUR_Equip(CCreatureObject& cre, int nSlot, BOOL bDoNotApplyEffects) {
	DWORD Eip;
	GetEip(Eip);

	(this->*Tramp_CItem_Equip)(cre, nSlot, bDoNotApplyEffects);

	if (Eip != 0x8BFEA5 &&
		Eip != 0x8C002D &&
		Eip != 0x8C01B6 &&
		Eip != 0x8C033F &&
		Eip != 0x8C04C8 &&
		Eip != 0x8C0651 &&
		Eip != 0x8C07D4 &&
		Eip != 0x8C095D &&
		Eip != 0x8C0AE6 &&
		Eip != 0x8C0C6F &&
		Eip != 0x8C1B9E &&
		Eip != 0x8C1BE0) { //CCreInventory::Unmarshal calls should not apply these effects

		if (m_itm.name.IsEmpty()) return;
		if (m_itm.pRes == NULL) return;
		if (bDoNotApplyEffects == TRUE) return;
		cre.m_bEquippingItem = TRUE;
		
		//effect 182
		if (pGameOptionsEx->bEffApplyEffItemFix) {
			POSITION pos = cre.cdsCurrent.ApplyEffOnEquipItem.GetHeadPosition();
			while (pos != NULL) {
				COnEquipItem* pOnEquipItem = (COnEquipItem*)cre.cdsCurrent.ApplyEffOnEquipItem.GetNext(pos);
				if (pOnEquipItem->rItem == m_itm.name) {
					if (pOnEquipItem->pEffect != NULL) {
						cre.ApplyEffect(pOnEquipItem->pEffect->Duplicate(), true, FALSE, TRUE);
					}
				}
			}
		}

		//effect 183
		if (pGameOptionsEx->bEffApplyEffItemtypeFix) {
			short nItemType = GetType();
			POSITION pos = cre.cdsCurrent.ApplyEffOnEquipItemType.GetHeadPosition();
			while (pos != NULL) {
				COnEquipItemType* pOnEquipItemType = (COnEquipItemType*)cre.cdsCurrent.ApplyEffOnEquipItemType.GetNext(pos);
				if (pOnEquipItemType->nItemType == (int)nItemType) {
					if (pOnEquipItemType->pEffect != NULL) {
						cre.ApplyEffect(pOnEquipItemType->pEffect->Duplicate(), true, FALSE, TRUE);
					}
				}
			}
		}

	cre.m_bEquippingItem = FALSE;
	}

	return;
}
