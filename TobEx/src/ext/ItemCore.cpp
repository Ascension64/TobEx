#include "ItemCore.h"

#include "objcre.h"
#include "effopcode.h"
#include "ObjectStats.h"

void (CItem::*Tramp_CItem_Equip)(CCreatureObject&, int, BOOL) =
	SetFP(static_cast<void (CItem::*)(CCreatureObject&, int, BOOL)>	(&CItem::Equip),			0x5AA430);
CEffect& (CItem::*Tramp_CItem_GetAbilityEffect)(int, int, CCreatureObject&) =
	SetFP(static_cast<CEffect& (CItem::*)(int, int, CCreatureObject&)>
																	(&CItem::GetAbilityEffect),	0x5AB168);

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

CEffect& DETOUR_CItem::DETOUR_GetAbilityEffect(int nAbilityIdx, int nEffectIdx, CCreatureObject& creSource) {
	CEffect& eff = (this->*Tramp_CItem_GetAbilityEffect)(nAbilityIdx, nEffectIdx, creSource);

	if (pGameOptionsEx->bEngineExpandedStats) {
		if (&eff != NULL &&
			eff.effect.nOpcode == CEFFECT_OPCODE_DAMAGE &&
			&creSource != NULL &&
			creSource.GetType() == CGAMEOBJECT_TYPE_CREATURE) {

			short wDamageType = eff.effect.nParam2 >> 16;
			int nDamageBehavior = eff.effect.nParam2 & 0xFFFF;

			if (nDamageBehavior == EFFECTDAMAGE_BEHAVIOR_NORMAL) {
				switch (wDamageType) {
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
