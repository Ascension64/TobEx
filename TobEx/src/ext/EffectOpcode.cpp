#include "EffectOpcode.h"

#include <math.h>

#include "stdafx.h"
#include "effopcode.h"
#include "effcore.h"
#include "engworld.h"
#include "infgame.h"
#include "msgcore.h"
#include "options.h"
#include "console.h"
#include "log.h"
#include "chitin.h"
#include "objcre.h"
#include "ObjectStats.h"

BOOL (CEffectAttacksPerRoundMod::*Tramp_CEffectAttacksPerRoundMod_ApplyEffect)(CCreatureObject&) =
	SetFP(static_cast<BOOL (CEffectAttacksPerRoundMod::*)(CCreatureObject&)>(&CEffectAttacksPerRoundMod::ApplyEffect),	0x5030F6);
BOOL (CEffectDamage::*Tramp_CEffectDamage_ApplyEffect)(CCreatureObject&) =
	SetFP(static_cast<BOOL (CEffectDamage::*)(CCreatureObject&)>			(&CEffectDamage::ApplyEffect),				0x505570);
BOOL (CEffectPoison::*Tramp_CEffectPoison_ApplyEffect)(CCreatureObject&) =
	SetFP(static_cast<BOOL (CEffectPoison::*)(CCreatureObject&)>			(&CEffectPoison::ApplyEffect),				0x516024);
BOOL (CEffectDispel::*Tramp_CEffectDispel_ApplyEffect)(CCreatureObject&) =
	SetFP(static_cast<BOOL (CEffectDispel::*)(CCreatureObject&)>			(&CEffectDispel::ApplyEffect),				0x5184DA);
BOOL (CEffectBlindness::*Tramp_CEffectBlindness_ApplyEffect)(CCreatureObject&) =
	SetFP(static_cast<BOOL (CEffectBlindness::*)(CCreatureObject&)>			(&CEffectBlindness::ApplyEffect),			0x51ADF9);
BOOL (CEffectDisease::*Tramp_CEffectDisease_ApplyEffect)(CCreatureObject&) =
	SetFP(static_cast<BOOL (CEffectDisease::*)(CCreatureObject&)>			(&CEffectDisease::ApplyEffect),				0x51B1FB);
BOOL (CEffectRegeneration::*Tramp_CEffectRegeneration_ApplyEffect)(CCreatureObject&) =
	SetFP(static_cast<BOOL (CEffectRegeneration::*)(CCreatureObject&)>		(&CEffectRegeneration::ApplyEffect),		0x51C615);
BOOL (CEffectMagicResistMod::*Tramp_CEffectMagicResistMod_ApplyEffect)(CCreatureObject&) =
	SetFP(static_cast<BOOL (CEffectMagicResistMod::*)(CCreatureObject&)>	(&CEffectMagicResistMod::ApplyEffect),		0x52EB97);
CEffectRepeatingEff& (CEffectRepeatingEff::*Tramp_CEffectRepeatingEff_Construct_5)(ITEM_EFFECT&, POINT&, Enum, int, int) =
	SetFP(static_cast<CEffectRepeatingEff& (CEffectRepeatingEff::*)(ITEM_EFFECT&, POINT&, Enum, int, int)>
																			(&CEffectRepeatingEff::Construct),			0x561AA0);
BOOL (CEffectRepeatingEff::*Tramp_CEffectRepeatingEff_ApplyEffect)(CCreatureObject&) =
	SetFP(static_cast<BOOL (CEffectRepeatingEff::*)(CCreatureObject&)>		(&CEffectRepeatingEff::ApplyEffect),		0x541C3B);
BOOL (CEffectCutScene2::*Tramp_CEffectCutScene2_ApplyEffect)(CCreatureObject&) =
	SetFP(static_cast<BOOL (CEffectCutScene2::*)(CCreatureObject&)>			(&CEffectCutScene2::ApplyEffect),			0x542815);

BOOL DETOUR_CEffectAttacksPerRoundMod::DETOUR_ApplyEffect(CCreatureObject& creTarget) {

	/*original function
	switch (effect.nParam2) {
	case 0: //add
		if (effect.nTiming == 1) {
			if (creTarget.m_BaseStats.numAttacks <= 5) {
				creTarget.m_BaseStats.numAttacks += creTarget.m_BaseStats.numAttacks + effect.nParam1;
				if (creTarget.m_BaseStats.numAttacks > 5) creTarget.m_BaseStats.numAttacks = 5;
				if (creTarget.m_BaseStats.numAttacks < 0) creTarget.m_BaseStats.numAttacks = 0;
			} else {
				creTarget.m_BaseStats.numAttacks += creTarget.m_BaseStats.numAttacks + effect.nParam1;
				if (creTarget.m_BaseStats.numAttacks > 10) creTarget.m_BaseStats.numAttacks = 10;
				if (creTarget.m_BaseStats.numAttacks < 6) creTarget.m_BaseStats.numAttacks = 6;
			}

			bRefreshStats = TRUE;
			bPurge = TRUE;
		} else {
			creTarget.cdsDiff.numAttacks += effect.nParam1;
			bPurge = FALSE;
		}
		break;
	case 1: //set
		if (effect.nTiming == 1) {
			creTarget.m_BaseStats.numAttacks = effect.nParam1;
			if (creTarget.m_BaseStats.numAttacks > 10) creTarget.m_BaseStats.numAttacks = 10;
			if (creTarget.m_BaseStats.numAttacks < 0) creTarget.m_BaseStats.numAttacks = 0;

			bRefreshStats = TRUE;
			bPurge = TRUE;
		} else {
			if (creTarget.cdsCurrent.numAttacks) {
				creTarget.cdsCurrent.numAttacks = effect.nParam1;
				if (creTarget.cdsCurrent.numAttacks > 10) creTarget.cdsCurrent.numAttacks = 10;
				if (creTarget.cdsCurrent.numAttacks < 0) creTarget.cdsCurrent.numAttacks = 0;
			}
			bPurge = FALSE;
		}
		break;
	case 2: //percent
		if (effect.nTiming == 1) {
			if (creTarget.m_BaseStats.numAttacks <= 5) {
				creTarget.m_BaseStats.numAttacks = creTarget.m_BaseStats.numAttacks * effect.nParam1 / 100;
				if (creTarget.m_BaseStats.numAttacks > 5) creTarget.m_BaseStats.numAttacks = 5;
				if (creTarget.m_BaseStats.numAttacks < 0) creTarget.m_BaseStats.numAttacks = 0;
				if (creTarget.m_BaseStats.numAttacks <= 1) creTarget.m_BaseStats.numAttacks = 1;
			} else {
				creTarget.m_BaseStats.numAttacks = (creTarget.m_BaseStats.numAttacks - 5) * effect.nParam1 / 100 + 5;
				if (creTarget.m_BaseStats.numAttacks > 10) creTarget.m_BaseStats.numAttacks = 10;
				if (creTarget.m_BaseStats.numAttacks < 6) creTarget.m_BaseStats.numAttacks = 6;
				if (creTarget.m_BaseStats.numAttacks <= 1) creTarget.m_BaseStats.numAttacks = 1;
			}
			bRefreshStats = TRUE;
			bPurge = TRUE;
		} else {
			if (creTarget.cdsCurrent.numAttacks <= 5) {
				creTarget.cdsCurrent.numAttacks = creTarget.m_BaseStats.numAttacks * effect.nParam1 / 100;
				if (creTarget.cdsCurrent.numAttacks > 5) creTarget.cdsCurrent.numAttacks = 5;
				if (creTarget.cdsCurrent.numAttacks < 0) creTarget.cdsCurrent.numAttacks = 0;
				if (creTarget.cdsCurrent.numAttacks <= 1) creTarget.cdsCurrent.numAttacks = 1;
			} else {
				creTarget.cdsCurrent.numAttacks = (creTarget.m_BaseStats.numAttacks - 5) * effect.nParam1 / 100 + 5;
				if (creTarget.cdsCurrent.numAttacks > 10) creTarget.cdsCurrent.numAttacks = 10;
				if (creTarget.cdsCurrent.numAttacks < 6) creTarget.cdsCurrent.numAttacks = 6;
				if (creTarget.cdsCurrent.numAttacks <= 1) creTarget.cdsCurrent.numAttacks = 1;
			}
			bPurge = FALSE;
		}
		break;
	default:
		assert(FALSE);
		break;
	}

	return TRUE;*/

	switch (effect.nParam2) {
	case 0: //add
		if (effect.nTiming == 1) {
			float fNumAttacks = CDerivedStats_NumAttacksShortToFloat(creTarget.m_BaseStats.numAttacks) + CDerivedStats_NumAttacksShortToFloat((short)(effect.nParam1));
			creTarget.m_BaseStats.numAttacks = CDerivedStats_NumAttacksFloatToShort(fNumAttacks);

			bRefreshStats = TRUE;
			bPurge = TRUE;
		} else {
			float fNumAttacks = CDerivedStats_NumAttacksShortToFloat(creTarget.cdsDiff.numAttacks) + CDerivedStats_NumAttacksShortToFloat((short)(effect.nParam1));
			creTarget.cdsDiff.numAttacks = CDerivedStats_NumAttacksFloatToShort(fNumAttacks);

			bPurge = FALSE;
		}
		break;
	case 1: //set
		if (effect.nTiming == 1) {
			creTarget.m_BaseStats.numAttacks = effect.nParam1;
			if (creTarget.m_BaseStats.numAttacks > 10) creTarget.m_BaseStats.numAttacks = 10;
			if (creTarget.m_BaseStats.numAttacks < 0) creTarget.m_BaseStats.numAttacks = 0;

			bRefreshStats = TRUE;
			bPurge = TRUE;
		} else {
			creTarget.cdsCurrent.numAttacks = effect.nParam1;
			if (creTarget.cdsCurrent.numAttacks > 10) creTarget.cdsCurrent.numAttacks = 10;
			if (creTarget.cdsCurrent.numAttacks < 0) creTarget.cdsCurrent.numAttacks = 0;

			bPurge = FALSE;
		}
		break;
	case 2: //percent
		if (effect.nTiming == 1) {
			float fNumAttacks = CDerivedStats_NumAttacksShortToFloat(creTarget.m_BaseStats.numAttacks) * (float)effect.nParam1 / 100.0;
			fNumAttacks = floor(fNumAttacks * 2.0 + 0.5) / 2.0; //round to nearest 0.5
			creTarget.m_BaseStats.numAttacks = CDerivedStats_NumAttacksFloatToShort(fNumAttacks);
			if (creTarget.m_BaseStats.numAttacks < 1) creTarget.m_BaseStats.numAttacks = 1;

			bRefreshStats = TRUE;
			bPurge = TRUE;
		} else {
			float fNumAttacks = CDerivedStats_NumAttacksShortToFloat(creTarget.cdsCurrent.numAttacks) * (float)effect.nParam1 / 100.0;
			fNumAttacks = floor(fNumAttacks * 2.0 + 0.5) / 2.0; //round to nearest 0.5
			creTarget.cdsCurrent.numAttacks = CDerivedStats_NumAttacksFloatToShort(fNumAttacks);
			if (creTarget.cdsCurrent.numAttacks < 1) creTarget.m_BaseStats.numAttacks = 1;

			bPurge = FALSE;
		}
		break;
	default:
		LPCTSTR lpsz = "DETOUR_CEffectAttacksPerRoundMod::DETOUR_ApplyEffect(): invalid effect.nParam2 (%d)\r\n";
		console.write(lpsz, 1, effect.nParam2);
		L.timestamp();
		L.append(lpsz, 1, effect.nParam2);
		break;
	}

	return TRUE;
}

BOOL DETOUR_CEffectDamage::DETOUR_ApplyEffect(CCreatureObject& creTarget) {
	(this->*Tramp_CEffectDamage_ApplyEffect)(creTarget);

	//CEffectAwaken::ApplyEffect(creTarget)
	creTarget.m_BaseStats.stateFlags &= ~STATE_SLEEPING;
	creTarget.cdsCurrent.stateFlags &= ~STATE_SLEEPING;
	creTarget.m_EffectsEquipped.RemoveEffect(creTarget, CEFFECT_OPCODE_SLEEP, creTarget.m_EffectsEquipped.posItrPrev, -1, ResRef(), FALSE);
	creTarget.m_EffectsMain.RemoveEffect(creTarget, CEFFECT_OPCODE_SLEEP, creTarget.m_EffectsMain.posItrPrev, -1, ResRef(), FALSE);

	return TRUE;
};

BOOL DETOUR_CEffectPoison::DETOUR_ApplyEffect(CCreatureObject& creTarget) {
	CRepeatingPoison* pRepeat = IENew CRepeatingPoison();
	pRepeat->eSource = eSource;

	short wParam2Low = effect.nParam2 & 0xFFFF;
	short wParam2High = effect.nParam2 >> 16;
	creTarget.cdsCurrent.stateFlags &= STATE_POISONED;

	int nTicksBegan = effect.nParam4;

	switch (wParam2Low) {
	case 0:
		pRepeat->wMode = 0;
		pRepeat->wPostDelayDuration = effect.nParam1;
		pRepeat->wAmount = 1;
		pRepeat->wPeriod = 1;
		pRepeat->nTicksLeft = effect.nDuration - g_pChitin->pGame->m_WorldTimer.nGameTime;
		pRepeat->wSecondsElapsed = 0;
		break;
	case 1:
		pRepeat->wMode = 0;
		pRepeat->wPostDelayDuration = creTarget.m_BaseStats.currentHP * effect.nParam1 / 100;;
		pRepeat->wAmount = 1;
		pRepeat->wPeriod = 1;
		pRepeat->nTicksLeft = effect.nDuration - g_pChitin->pGame->m_WorldTimer.nGameTime;
		pRepeat->wSecondsElapsed = 0;
		break;
	case 2:
		pRepeat->wMode = 2;
		pRepeat->wPostDelayDuration = 1;
		pRepeat->wAmount = effect.nParam1;
		pRepeat->wPeriod = 1;
		pRepeat->nTicksLeft = effect.nDuration - g_pChitin->pGame->m_WorldTimer.nGameTime;
		pRepeat->wSecondsElapsed = 0;
		break;
	case 3:
		pRepeat->wMode = 3;
		pRepeat->wPostDelayDuration = 1;
		pRepeat->wAmount = 1;
		pRepeat->wPeriod = effect.nParam1;
		pRepeat->nTicksLeft = effect.nDuration - g_pChitin->pGame->m_WorldTimer.nGameTime;
		pRepeat->wSecondsElapsed = (g_pChitin->pGame->m_WorldTimer.nGameTime - nTicksBegan) / 15 % pRepeat->wPeriod;
		break;
	case 4:
		pRepeat->wMode = 3;
		pRepeat->wPostDelayDuration = 1;
		pRepeat->wAmount = effect.nParam3;
		pRepeat->wPeriod = effect.nParam1;
		pRepeat->nTicksLeft = effect.nDuration - g_pChitin->pGame->m_WorldTimer.nGameTime;
		pRepeat->wSecondsElapsed = (g_pChitin->pGame->m_WorldTimer.nGameTime - nTicksBegan) / 15 % pRepeat->wPeriod;
		break;
	default:
		LPCTSTR lpsz = "DETOUR_CEffectPoison::DETOUR_ApplyEffect(): invalid effect.nParam2 low word (%d)\r\n";
		console.write(lpsz, 1, wParam2Low);
		L.timestamp();
		L.append(lpsz, 1, wParam2Low);
		break;
	}

	creTarget.cdsCurrent.m_RepeatingEffs.AddTail(pRepeat);

	return TRUE;
}

BOOL DETOUR_CEffectDispel::DETOUR_ApplyEffect(CCreatureObject& creTarget) {

	/*original function
	char nRand;

	switch (effect.nParam2) {
	case 0:
		creTarget.m_EffectsMain.TryDispel(creTarget, creTarget.m_EffectsMain.posItrPrev, TRUE, FALSE, 0, 0);
		creTarget.m_EffectsEquipped.TryDispel(creTarget, creTarget.m_EffectsEquipped.posItrPrev, TRUE, FALSE, 0, 0);
		creTarget.UnequipAll(TRUE);
		CCreatureObject::RemoveItem(creTarget, SLOT_MISC19);
		creTarget.EquipAll(TRUE);
		creTarget.u36dc = TRUE;
		creTarget.u36e0 = TRUE;
		creTarget.u36e4 = TRUE;

		bRefreshStats = TRUE;
		break;

	case 1:
		nRand = IERand() * 100 >> 15;
		creTarget.m_EffectsMain.TryDispel(creTarget, creTarget.m_EffectsMain.posItrPrev, TRUE, TRUE, nRand, effect.nSourceCreLevel);
		creTarget.m_EffectsEquipped.TryDispel(creTarget, creTarget.m_EffectsEquipped.posItrPrev, TRUE, TRUE, nRand, effect.nSourceCreLevel);

		creTarget.UnequipAll(TRUE);
		CCreatureObject::RemoveItem(creTarget, SLOT_MISC19);
		creTarget.EquipAll(TRUE);
		creTarget.u36dc = TRUE;
		creTarget.u36e0 = TRUE;
		creTarget.u36e4 = TRUE;

		bRefreshStats = TRUE;
		break;

	default:
		nRand = IERand() * 100 >> 15;
		creTarget.m_EffectsMain.TryDispel(creTarget, creTarget.m_EffectsMain.posItrPrev, TRUE, TRUE, nRand, effect.nParam1);
		creTarget.m_EffectsEquipped.TryDispel(creTarget, creTarget.m_EffectsEquipped.posItrPrev, TRUE, TRUE, nRand, effect.nParam1);

		creTarget.UnequipAll(TRUE);
		CCreatureObject::RemoveItem(creTarget, SLOT_MISC19);
		creTarget.EquipAll(TRUE);
		creTarget.u36dc = TRUE;
		creTarget.u36e0 = TRUE;
		creTarget.u36e4 = TRUE;

		bRefreshStats = TRUE;
		break;
	}

	bPurge = TRUE;
	*/

	int nParam2Low = effect.nParam2 & 0xFFFF;
	int nParam2High = effect.nParam2 >> 16;
	char nRand = IERand() * 100 >> 15;

	switch (nParam2Low) {
	case 0:
		creTarget.m_EffectsMain.TryDispel(creTarget, creTarget.m_EffectsMain.posItrPrev, TRUE, FALSE, 0, 0);
		creTarget.m_EffectsEquipped.TryDispel(creTarget, creTarget.m_EffectsEquipped.posItrPrev, TRUE, FALSE, 0, 0);
		break;
	case 1:
		creTarget.m_EffectsMain.TryDispel(creTarget, creTarget.m_EffectsMain.posItrPrev, TRUE, TRUE, nRand, effect.nSourceCreLevel);
		creTarget.m_EffectsEquipped.TryDispel(creTarget, creTarget.m_EffectsEquipped.posItrPrev, TRUE, TRUE, nRand, effect.nSourceCreLevel);
		break;
	default:
		creTarget.m_EffectsMain.TryDispel(creTarget, creTarget.m_EffectsMain.posItrPrev, TRUE, TRUE, nRand, effect.nParam1);
		creTarget.m_EffectsEquipped.TryDispel(creTarget, creTarget.m_EffectsEquipped.posItrPrev, TRUE, TRUE, nRand, effect.nParam1);
		break;
	}

	bool bDispelMagicalItem = false;

	if (creTarget.m_Inventory.items[SLOT_MISC19]) {
		if (!(creTarget.m_Inventory.items[SLOT_MISC19]->GetFlags() & ITEMFLAG_NOT_DISPELLABLE)) {
			switch (nParam2High) {
			case 0:
				bDispelMagicalItem = true;
				break;
			case 1:
				bDispelMagicalItem = false;
				break;
			case 2:
			default:
				CDerivedStats& cds = creTarget.GetDerivedStats();
				int nItemLevel = max(
					cds.GetEffectiveMageLevel(creTarget.o.GetClass()),
					cds.GetEffectiveClericLevel(creTarget.o.GetClass())
				);
				
				int nDispelLevel;
				switch (nParam2Low) {
				case 0:
				case 1:
				default:
					nDispelLevel = effect.nSourceCreLevel;
					break;
				case 2:
					nDispelLevel = effect.nParam1;
					break;
				}

				int nDifficulty = 50 + (nItemLevel - nDispelLevel) * (nItemLevel > nDispelLevel ? 10 : 5);
				if (nRand == 99 ||
					nRand > nDifficulty) {
					bDispelMagicalItem = true;
				} else {
					bDispelMagicalItem = false;
				}
				break;
			}
		}
	}
	
	if (bDispelMagicalItem) {
		creTarget.UnequipAll(TRUE);
		CCreatureObject::RemoveItem(creTarget, SLOT_MISC19);
		creTarget.EquipAll(TRUE);
	}

	creTarget.u36dc = TRUE;
	creTarget.u36e0 = TRUE;
	creTarget.u36e4 = TRUE;

	bRefreshStats = TRUE;
	bPurge = TRUE;

	return TRUE;
};

BOOL DETOUR_CEffectBlindness::DETOUR_ApplyEffect(CCreatureObject& creTarget) {

	/*original function
	if (timing == 1) {
		//permanent
		creTarget.m_BaseStats.stateFlags |= STATE_BLIND;
		creTarget.cdsCurrent.stateFlags |= STATE_BLIND;
		creTarget.m_BaseStats.THAC0 -= (-10);
		creTarget.cdsCurrent.THAC0 -= (-10);
		bPurge = TRUE;
	} else {
		//limited
		creTarget.cdsCurrent.stateFlags |= STATE_BLIND;
		creTarget.cdsCurrent.THAC0 -= (-10);
	}*/

	//Remove cumulative penalty
	if (pGameOptionsEx->nEffBlindnessFix == 1) {
		if (effect.nTiming == 1) {
			//permanent
			if (!(creTarget.m_BaseStats.stateFlags & STATE_BLIND)) creTarget.m_BaseStats.THAC0 -= (-10);
			creTarget.m_BaseStats.stateFlags |= STATE_BLIND;
			if (!(creTarget.cdsCurrent.stateFlags & STATE_BLIND)) creTarget.cdsCurrent.THAC0 -= (-10);
			creTarget.cdsCurrent.stateFlags |= STATE_BLIND;
		
			bPurge = TRUE;
		} else {
			//limited
			if (!(creTarget.cdsCurrent.stateFlags & STATE_BLIND)) creTarget.cdsCurrent.THAC0 -= (-10);
			creTarget.cdsCurrent.stateFlags |= STATE_BLIND;
		}

		return TRUE;
	}

	//Change to game description
	if (pGameOptionsEx->nEffBlindnessFix == 2) {
		if (effect.nTiming == 1) {
			//permanent
			if (!(creTarget.m_BaseStats.stateFlags & STATE_BLIND)) {
				creTarget.m_BaseStats.THAC0 -= (-4);
				creTarget.m_BaseStats.ACEffective = min(20, creTarget.m_BaseStats.ACEffective - (-4));
			}
			creTarget.m_BaseStats.stateFlags |= STATE_BLIND;
			if (!(creTarget.cdsCurrent.stateFlags & STATE_BLIND)) {
				creTarget.cdsCurrent.THAC0 -= (-4);
			}
			creTarget.cdsCurrent.stateFlags |= STATE_BLIND;
		
			bRefreshStats = TRUE;
			bPurge = TRUE;
		} else {
			//limited
			if (!(creTarget.cdsCurrent.stateFlags & STATE_BLIND)) {
				creTarget.cdsCurrent.THAC0 -= (-4);
				creTarget.cdsDiff.ACEffective -= (-4);
			}
			creTarget.cdsCurrent.stateFlags |= STATE_BLIND;

			bPurge = FALSE;
		}

		return TRUE;
	}

	return true;
}

BOOL DETOUR_CEffectDisease::DETOUR_ApplyEffect(CCreatureObject& creTarget) {
	CRepeatingDisease* pRepeat = NULL;

	short wParam2Low = effect.nParam2 & 0xFFFF;
	short wParam2High = effect.nParam2 >> 16;
	int nTicksLeft = effect.nDuration - g_pChitin->pGame->m_WorldTimer.nGameTime;
	int nTicksBegan = effect.nParam4;

	switch (wParam2Low) {
	case 0:
		pRepeat = IENew CRepeatingDisease();
		pRepeat->eSource = eSource;
		pRepeat->wMode = 0;
		pRepeat->wPostDelayDuration = effect.nParam1;
		pRepeat->wAmount = 1;
		pRepeat->wPeriod = 1;
		pRepeat->nTicksLeft = effect.nDuration - g_pChitin->pGame->m_WorldTimer.nGameTime;
		pRepeat->wSecondsElapsed = 0;
		creTarget.cdsCurrent.m_RepeatingEffs.AddTail(pRepeat);
		break;
	case 1:
		pRepeat = IENew CRepeatingDisease();
		pRepeat->eSource = eSource;
		pRepeat->wMode = 0;
		pRepeat->wPostDelayDuration = creTarget.m_BaseStats.currentHP * effect.nParam1 / 100;;
		pRepeat->wAmount = 1;
		pRepeat->wPeriod = 1;
		pRepeat->nTicksLeft = effect.nDuration - g_pChitin->pGame->m_WorldTimer.nGameTime;
		pRepeat->wSecondsElapsed = 0;
		creTarget.cdsCurrent.m_RepeatingEffs.AddTail(pRepeat);
		break;
	case 2:
		pRepeat = IENew CRepeatingDisease();
		pRepeat->eSource = eSource;
		pRepeat->wMode = 2;
		pRepeat->wPostDelayDuration = 1;
		pRepeat->wAmount = effect.nParam1;
		pRepeat->wPeriod = 1;
		pRepeat->nTicksLeft = effect.nDuration - g_pChitin->pGame->m_WorldTimer.nGameTime;
		pRepeat->wSecondsElapsed = 0;
		creTarget.cdsCurrent.m_RepeatingEffs.AddTail(pRepeat);
		break;
	case 3:
		pRepeat = IENew CRepeatingDisease();
		pRepeat->eSource = eSource;
		pRepeat->wMode = 3;
		pRepeat->wPostDelayDuration = 1;
		pRepeat->wAmount = 1;
		pRepeat->wPeriod = effect.nParam1;
		pRepeat->nTicksLeft = effect.nDuration - g_pChitin->pGame->m_WorldTimer.nGameTime;
		pRepeat->wSecondsElapsed = (g_pChitin->pGame->m_WorldTimer.nGameTime - nTicksBegan) / 15 % pRepeat->wPeriod;
		creTarget.cdsCurrent.m_RepeatingEffs.AddTail(pRepeat);
		break;
	case 4:
		creTarget.cdsDiff.strength -= effect.nParam1;
		break;
	case 5:
		creTarget.cdsDiff.dexterity -= effect.nParam1;
		break;
	case 6:
		creTarget.cdsDiff.constitution -= effect.nParam1;
		break;
	case 7:
		creTarget.cdsDiff.intelligence -= effect.nParam1;
		break;
	case 8:
		creTarget.cdsDiff.wisdom -= effect.nParam1;
		break;
	case 9:
		creTarget.cdsDiff.charisma -= effect.nParam1;
		break;
	case 10:
		creTarget.cdsCurrent.stateFlags &= STATE_SLOWED;
		break;
	default:
		LPCTSTR lpsz = "DETOUR_CEffectDisease::DETOUR_ApplyEffect(): invalid effect.nParam2 low word (%d)\r\n";
		console.write(lpsz, 1, wParam2Low);
		L.timestamp();
		L.append(lpsz, 1, wParam2Low);
		break;
	}
	return TRUE;
}

BOOL DETOUR_CEffectRegeneration::DETOUR_ApplyEffect(CCreatureObject& creTarget) {
	CRepeatingRegen* pRepeat = IENew CRepeatingRegen();

	short wParam2Low = effect.nParam2 & 0xFFFF;
	short wParam2High = effect.nParam2 >> 16;

	int nTicksBegan = effect.nParam4;

	switch (wParam2Low) {
	case 0:
		pRepeat->wMode = 0;
		pRepeat->wPostDelayDuration = effect.nParam1;
		pRepeat->wAmount = 1;
		pRepeat->wPeriod = 1;
		pRepeat->nTicksLeft = effect.nDuration - g_pChitin->pGame->m_WorldTimer.nGameTime;
		pRepeat->wSecondsElapsed = 0;
		break;
	case 1:
		pRepeat->wMode = 0;
		pRepeat->wPostDelayDuration = creTarget.m_BaseStats.currentHP * effect.nParam1 / 100;
		pRepeat->wAmount = 1;
		pRepeat->wPeriod = 1;
		pRepeat->nTicksLeft = effect.nDuration - g_pChitin->pGame->m_WorldTimer.nGameTime;
		pRepeat->wSecondsElapsed = 0;
		break;
	case 2:
		pRepeat->wMode = 2;
		pRepeat->wPostDelayDuration = 1;
		pRepeat->wAmount = effect.nParam1;
		pRepeat->wPeriod = 1;
		pRepeat->nTicksLeft = effect.nDuration - g_pChitin->pGame->m_WorldTimer.nGameTime;
		pRepeat->wSecondsElapsed = 0;
		break;
	case 3:
		pRepeat->wMode = 3;
		pRepeat->wPostDelayDuration = 1;
		pRepeat->wAmount = 1;
		pRepeat->wPeriod = effect.nParam1;
		pRepeat->nTicksLeft = effect.nDuration - g_pChitin->pGame->m_WorldTimer.nGameTime;
		pRepeat->wSecondsElapsed = (g_pChitin->pGame->m_WorldTimer.nGameTime - nTicksBegan) / 15 % pRepeat->wPeriod;
		break;
	case 4:
		pRepeat->wMode = 3;
		pRepeat->wPostDelayDuration = 1;
		pRepeat->wAmount = effect.nParam3;
		pRepeat->wPeriod = effect.nParam1;
		pRepeat->nTicksLeft = effect.nDuration - g_pChitin->pGame->m_WorldTimer.nGameTime;
		pRepeat->wSecondsElapsed = (g_pChitin->pGame->m_WorldTimer.nGameTime - nTicksBegan) / 15 % pRepeat->wPeriod;
		break;
	default:
		LPCTSTR lpsz = "DETOUR_CEffectRegeneration::DETOUR_ApplyEffect(): invalid effect.nParam2 low word (%d)\r\n";
		console.write(lpsz, 1, wParam2Low);
		L.timestamp();
		L.append(lpsz, 1, wParam2Low);
		break;
	}

	creTarget.cdsCurrent.m_RepeatingEffs.AddTail(pRepeat);

	return TRUE;
}

BOOL DETOUR_CEffectMagicResistMod::DETOUR_ApplyEffect(CCreatureObject& creTarget) {

	/*original function
	switch (effect.nParam2) {
		case 0:
			//sum
			creTarget.cdsCurrent.resistMagic += effect.nParam1;
			break;
		case 1:
			//set
			creTarget.cdsCurrent.resistMagic = effect.nParam1;
			break;
		default:
			break;
	}*/

	switch (effect.nParam2) {
		case 0:
			//sum
			if (effect.nTiming == 1) {
				creTarget.m_BaseStats.resistMagic += effect.nParam1;
				creTarget.m_BaseStats.resistMagic = min(creTarget.m_BaseStats.resistMagic, 100);
				creTarget.m_BaseStats.resistMagic = max(creTarget.m_BaseStats.resistMagic, 0);
				bRefreshStats = TRUE;
				bPurge = TRUE;
			} else {
				creTarget.cdsDiff.resistMagic += effect.nParam1;
				bPurge = TRUE;
			}
			break;
		case 1:
			//set
			if (effect.nTiming == 1) {
				creTarget.m_BaseStats.resistMagic = effect.nParam1;
				creTarget.m_BaseStats.resistMagic = min(creTarget.m_BaseStats.resistMagic, 100);
				creTarget.m_BaseStats.resistMagic = max(creTarget.m_BaseStats.resistMagic, 0);
				bRefreshStats = TRUE;
				bPurge = TRUE;
			} else {
				creTarget.cdsCurrent.resistMagic = effect.nParam1;
				creTarget.cdsCurrent.resistMagic = min(creTarget.cdsCurrent.resistMagic, 100);
				creTarget.cdsCurrent.resistMagic = max(creTarget.cdsCurrent.resistMagic, 0);
				bPurge = FALSE;
			}
			break;
		case 2:
			//percentage
			if (effect.nTiming == 1) {
				creTarget.m_BaseStats.resistMagic = (creTarget.m_BaseStats.resistMagic * effect.nParam1) / 100;
				creTarget.m_BaseStats.resistMagic = min(creTarget.m_BaseStats.resistMagic, 100);
				creTarget.m_BaseStats.resistMagic = max(creTarget.m_BaseStats.resistMagic, 0);
				bRefreshStats = TRUE;
				bPurge = TRUE;
			} else {
				creTarget.cdsCurrent.resistMagic = (creTarget.m_BaseStats.resistMagic * effect.nParam1) / 100;
				creTarget.cdsCurrent.resistMagic = min(creTarget.m_BaseStats.resistMagic, 100);
				creTarget.cdsCurrent.resistMagic = max(creTarget.m_BaseStats.resistMagic, 0);
				bPurge = FALSE;
			}
			break;
		default:
			LPCTSTR lpsz = "DETOUR_CEffectMagicResistMod::DETOUR_ApplyEffect(): invalid effect.nParam2 (%d)\r\n";
			console.write(lpsz, 1, effect.nParam2);
			L.timestamp();
			L.append(lpsz, 1, effect.nParam2);
			break;
	}
	return TRUE;
}

CEffectRepeatingEff& DETOUR_CEffectRepeatingEff::DETOUR_Construct(ITEM_EFFECT& eff, POINT& ptSource, Enum eSource, int ptDestX, int ptDestY) {
	CEffectRepeatingEff& e = (this->*Tramp_CEffectRepeatingEff_Construct_5)(eff, ptSource, eSource, ptDestX, ptDestY);
	e.effect.nParam4 = g_pChitin->pGame->m_WorldTimer.nGameTime;
	return e;
}

BOOL DETOUR_CEffectRepeatingEff::DETOUR_ApplyEffect(CCreatureObject& creTarget) {
	CRepeatingEff* pRepeat = IENew CRepeatingEff();
	pRepeat->eSource = eSource;

	short wParam2Low = effect.nParam2 & 0xFFFF;
	short wParam2High = effect.nParam2 >> 16;
	pRepeat->rResource = effect.rResource;
	pRepeat->pEffect = this;

	int nDuration = effect.nDuration;
	if (!(effect.nTiming == 0 ||
		effect.nTiming == 3 ||
		effect.nTiming == 6 ||
		effect.nTiming == 1000)) {
		nDuration = INT_MAX;
	}

	int nTicksBegan = effect.nParam4;

	switch (wParam2Low) {
	case 0:
		pRepeat->wMode = 0;
		pRepeat->wPostDelayDuration = effect.nParam1;
		pRepeat->wAmount = 1;
		pRepeat->wPeriod = 1;
		pRepeat->nTicksLeft = effect.nDuration - g_pChitin->pGame->m_WorldTimer.nGameTime;
		pRepeat->wSecondsElapsed = 0;
		break;
	case 2:
		pRepeat->wMode = 2;
		pRepeat->wPostDelayDuration = 1;
		pRepeat->wAmount = effect.nParam1;
		pRepeat->wPeriod = 1;
		pRepeat->nTicksLeft = effect.nDuration - g_pChitin->pGame->m_WorldTimer.nGameTime;
		pRepeat->wSecondsElapsed = 0;
		break;
	case 3:
		pRepeat->wMode = 3;
		pRepeat->wPostDelayDuration = 1;
		pRepeat->wAmount = 1;
		pRepeat->wPeriod = effect.nParam1;
		pRepeat->nTicksLeft = effect.nDuration - g_pChitin->pGame->m_WorldTimer.nGameTime;
		pRepeat->wSecondsElapsed = (g_pChitin->pGame->m_WorldTimer.nGameTime - nTicksBegan) / 15 % pRepeat->wPeriod;
		break;
	case 4:
		pRepeat->wMode = 3;
		pRepeat->wPostDelayDuration = 1;
		pRepeat->wAmount = effect.nParam3;
		pRepeat->wPeriod = effect.nParam1;
		pRepeat->nTicksLeft = effect.nDuration - g_pChitin->pGame->m_WorldTimer.nGameTime;
		pRepeat->wSecondsElapsed = (g_pChitin->pGame->m_WorldTimer.nGameTime - nTicksBegan) / 15 % pRepeat->wPeriod;
		break;
	case 1:
	default:
		LPCTSTR lpsz = "DETOUR_CEffectRepeatingEff::DETOUR_ApplyEffect(): invalid effect.nParam2 low word (%d)\r\n";
		console.write(lpsz, 1, wParam2Low);
		L.timestamp();
		L.append(lpsz, 1, wParam2Low);
		break;
	}

	creTarget.cdsCurrent.m_RepeatingEffs.AddTail(pRepeat);

	return TRUE;
}

BOOL DETOUR_CEffectCutScene2::DETOUR_ApplyEffect(CCreatureObject& creTarget) {
	CInfGame* pGame = g_pChitin->pGame;
	CInfGame::CGameSave* pGameSave = &pGame->m_GameSave;

	if (pGameSave->mode == 0x1016E || pGameSave->mode == 0x3016E) {
		bPurge = TRUE;
		return TRUE;
	}

	switch (effect.nParam1) {
		case 1:
			//Use StorePartyLocations() list
			pGame->StorePartyLocations(FALSE);
			break;
		case 2:
			//Do not store party member locations
			break;
		case 0:
		default:
			//Use pocket plane list
			pGame->StorePartyLocations(TRUE);
			break;
	}

	CMessageCutSceneMode* pcmCSM = IENew CMessageCutSceneMode();
	pcmCSM->eTarget = creTarget.e;
	pcmCSM->eSource = creTarget.e;
	pcmCSM->bEnable = true;
	g_pChitin->messages.Send(*pcmCSM, FALSE);

	CMessageAddAction* pcmA = IENew CMessageAddAction();
	pcmA->eTarget = pGame->ePlayersPartyOrder[0];
	pcmA->eSource = pGame->ePlayersPartyOrder[0];
	pcmA->a.opcode = 120; //StartCutScene
	pcmA->a.sName1 = effect.nParam2 ? IECString(effect.rResource.GetBuffer()) : "cut250a";
	pcmA->a.dwFlags |= 1;
	g_pChitin->messages.Send(*pcmA, FALSE);

	bPurge = TRUE;
	return TRUE;
}

CEffect13E::CEffect13E(ITEM_EFFECT& data, POINT& ptSource, Enum eSource, int destX, int destY, BOOL bUseDice, Enum e2) \
	: CEffect(data, ptSource, eSource, destX, destY, bUseDice, e2) {}

CEffect& CEffect13E::Duplicate() {
	CEffect13E* pceff = new CEffect13E(ToItemEffect(), effect.ptSource, eSource, effect.nDestX, effect.nDestY, FALSE, ENUM_INVALID_INDEX);
	pceff->Unmarshal(effect);
	return *pceff;
}

BOOL CEffect13E::ApplyEffect(CCreatureObject& creTarget) {
	CMessageDisplayText* pcmDT = IENew CMessageDisplayText();
	pcmDT->eTarget = creTarget.e;
	pcmDT->eSource = creTarget.e;
	pcmDT->sLeft = "TobEx";
	pcmDT->sRight = "Applied effect 0x13E via AddMessage()";
	pcmDT->rgbLeft = 0x239526;
	pcmDT->rgbRight = 0x728460;
	pcmDT->bFloatText = TRUE;

	g_pChitin->messages.Send(*pcmDT, FALSE);

	g_pChitin->pWorld->PrintToConsole(IECString("TobEx"), IECString("Applied effect 0x13E directly through GUIW"), 0x239526, 0xAB3FEC, -1, 0);

	return TRUE;
}