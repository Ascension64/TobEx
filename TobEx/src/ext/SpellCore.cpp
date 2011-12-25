#include "SpellCore.h"

#include "objcre.h"
#include "effopcode.h"
#include "ObjectStats.h"

CEffect& (ResSplContainer::*Tramp_ResSplContainer_GetAbilityEffect)(int, int, CCreatureObject&) =
	SetFP(static_cast<CEffect& (ResSplContainer::*)(int, int, CCreatureObject&)>
																			(&ResSplContainer::GetAbilityEffect),		0x6432B6);

CEffect& DETOUR_ResSplContainer::DETOUR_GetAbilityEffect(int nAbilityIdx, int nEffectIdx, CCreatureObject& creSource) {
	CEffect& eff = (this->*Tramp_ResSplContainer_GetAbilityEffect)(nAbilityIdx, nEffectIdx, creSource);

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
