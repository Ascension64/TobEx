#include "ItemCore.h"

#include "objcre.h"
#include "optionsext.h"
#include "effopcode.h"
#include "ObjectStats.h"

DefineTrampMemberFunc(void, CItem, Equip, (CCreatureObject& cre, int nSlot, BOOL bDoNotApplyEffects), Equip, Equip, 0x5AA430);
DefineTrampMemberFunc(CEffect&, CItem, GetAbilityEffect, (int nAbilityIdx, int nEffectIdx, CCreatureObject& creSource), GetAbilityEffect, GetAbilityEffect, 0x5AB168);

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
		if (pGameOptionsEx->GetOption("Eff_ApplyEffItemFix")) {
			POSITION pos = cre.m_cdsCurrent.ApplyEffOnEquipItem.GetHeadPosition();
			while (pos != NULL) {
				COnEquipItem* pOnEquipItem = (COnEquipItem*)cre.m_cdsCurrent.ApplyEffOnEquipItem.GetNext(pos);
				if (pOnEquipItem->rItem == m_itm.name) {
					if (pOnEquipItem->pEffect != NULL) {
						cre.ApplyEffect(pOnEquipItem->pEffect->Copy(), true, FALSE, TRUE);
					}
				}
			}
		}

		//effect 183
		if (pGameOptionsEx->GetOption("Eff_ApplyEffItemtypeFix")) {
			short nItemType = GetType();
			POSITION pos = cre.m_cdsCurrent.ApplyEffOnEquipItemType.GetHeadPosition();
			while (pos != NULL) {
				COnEquipItemType* pOnEquipItemType = (COnEquipItemType*)cre.m_cdsCurrent.ApplyEffOnEquipItemType.GetNext(pos);
				if (pOnEquipItemType->nItemType == (int)nItemType) {
					if (pOnEquipItemType->pEffect != NULL) {
						cre.ApplyEffect(pOnEquipItemType->pEffect->Copy(), true, FALSE, TRUE);
					}
				}
			}
		}

	cre.m_bEquippingItem = FALSE;
	}

	return;
}

CEffect& DETOUR_CItem::DETOUR_GetAbilityEffect(int nAbilityIdx, int nEffectIdx, CCreatureObject& creSource) {
	CEffect& eff = (this->*Tramp_CItem_GetAbilityEffect)(nAbilityIdx, nEffectIdx, creSource);

	if (pGameOptionsEx->GetOption("Engine_ExpandedStats")) {
		if (&eff != NULL &&
			eff.effect.nOpcode == CEFFECT_OPCODE_DAMAGE &&
			&creSource != NULL &&
			creSource.GetType() == CGAMEOBJECT_TYPE_CREATURE) {

			unsigned int nDamageType = eff.effect.nParam2 & 0xFFFF0000;
			int nDamageBehavior = eff.effect.nParam2 & 0xFFFF;

			if (nDamageBehavior == EFFECTDAMAGE_BEHAVIOR_NORMAL) {
				switch (nDamageType) {
				case DAMAGETYPE_ACID:
					eff.effect.nParam3 = creSource.GetDerivedStats().GetStat(CDERIVEDSTATSEX_BASE + CDERIVEDSTATSEX_ACIDDAMAGEBONUS);
					break;
				case DAMAGETYPE_COLD:
					eff.effect.nParam3 = creSource.GetDerivedStats().GetStat(CDERIVEDSTATSEX_BASE + CDERIVEDSTATSEX_COLDDAMAGEBONUS);
					break;
				case DAMAGETYPE_CRUSHING:
					eff.effect.nParam3 = creSource.GetDerivedStats().GetStat(CDERIVEDSTATSEX_BASE + CDERIVEDSTATSEX_CRUSHINGDAMAGEBONUS);
					break;
				case DAMAGETYPE_STUNNING:
					eff.effect.nParam3 = creSource.GetDerivedStats().GetStat(CDERIVEDSTATSEX_BASE + CDERIVEDSTATSEX_STUNNINGDAMAGEBONUS);
					break;
				case DAMAGETYPE_PIERCING:
					eff.effect.nParam3 = creSource.GetDerivedStats().GetStat(CDERIVEDSTATSEX_BASE + CDERIVEDSTATSEX_PIERCINGDAMAGEBONUS);
					break;
				case DAMAGETYPE_SLASHING:
					eff.effect.nParam3 = creSource.GetDerivedStats().GetStat(CDERIVEDSTATSEX_BASE + CDERIVEDSTATSEX_SLASHINGDAMAGEBONUS);
					break;
				case DAMAGETYPE_ELECTRICITY:
					eff.effect.nParam3 = creSource.GetDerivedStats().GetStat(CDERIVEDSTATSEX_BASE + CDERIVEDSTATSEX_ELECTRICITYDAMAGEBONUS);
					break;
				case DAMAGETYPE_FIRE:
					eff.effect.nParam3 = creSource.GetDerivedStats().GetStat(CDERIVEDSTATSEX_BASE + CDERIVEDSTATSEX_FIREDAMAGEBONUS);
					break;
				case DAMAGETYPE_POISON:
					eff.effect.nParam3 = creSource.GetDerivedStats().GetStat(CDERIVEDSTATSEX_BASE + CDERIVEDSTATSEX_POISONDAMAGEBONUS);
					break;
				case DAMAGETYPE_MAGIC:
					eff.effect.nParam3 = creSource.GetDerivedStats().GetStat(CDERIVEDSTATSEX_BASE + CDERIVEDSTATSEX_MAGICDAMAGEBONUS);
					break;
				case DAMAGETYPE_MISSILE:
					eff.effect.nParam3 = creSource.GetDerivedStats().GetStat(CDERIVEDSTATSEX_BASE + CDERIVEDSTATSEX_MISSILEDAMAGEBONUS);
					break;
				case DAMAGETYPE_MAGICFIRE:
					eff.effect.nParam3 = creSource.GetDerivedStats().GetStat(CDERIVEDSTATSEX_BASE + CDERIVEDSTATSEX_MAGICFIREDAMAGEBONUS);
					break;
				case DAMAGETYPE_MAGICCOLD:
					eff.effect.nParam3 = creSource.GetDerivedStats().GetStat(CDERIVEDSTATSEX_BASE + CDERIVEDSTATSEX_MAGICCOLDDAMAGEBONUS);
					break;
				default:
					break;
				}
			}
		}
	}

	return eff;
}
