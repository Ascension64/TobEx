#include "EffectOpcode.h"

#include <math.h>

#include "stdafx.h"
#include "effopcode.h"
#include "effcore.h"
#include "engworld.h"
#include "infcursor.h"
#include "infgame.h"
#include "msgcore.h"
#include "options.h"
#include "console.h"
#include "log.h"
#include "chitin.h"
#include "objcre.h"
#include "MessageExt.h"
#include "ObjectStats.h"
#include "InfGameCommon.h"

BOOL (CEffectAttacksPerRoundMod::*Tramp_CEffectAttacksPerRoundMod_ApplyEffect)(CCreatureObject&) =
	SetFP(static_cast<BOOL (CEffectAttacksPerRoundMod::*)(CCreatureObject&)>(&CEffectAttacksPerRoundMod::ApplyEffect),	0x5030F6);
BOOL (CEffectDamage::*Tramp_CEffectDamage_ApplyEffect)(CCreatureObject&) =
	SetFP(static_cast<BOOL (CEffectDamage::*)(CCreatureObject&)>			(&CEffectDamage::ApplyEffect),				0x505570);
BOOL (CEffectDexterityMod::*Tramp_CEffectDexterityMod_ApplyEffect)(CCreatureObject&) =
	SetFP(static_cast<BOOL (CEffectDexterityMod::*)(CCreatureObject&)>		(&CEffectDexterityMod::ApplyEffect),		0x510DCF);
BOOL (CEffectPoison::*Tramp_CEffectPoison_ApplyEffect)(CCreatureObject&) =
	SetFP(static_cast<BOOL (CEffectPoison::*)(CCreatureObject&)>			(&CEffectPoison::ApplyEffect),				0x516024);
BOOL (CEffectMageMemSpellMod::*Tramp_CEffectMageMemSpellMod_ApplyEffect)(CCreatureObject&) =
	SetFP(static_cast<BOOL (CEffectMageMemSpellMod::*)(CCreatureObject&)>	(&CEffectMageMemSpellMod::ApplyEffect),		0x5161AB);
BOOL (CEffectStrengthMod::*Tramp_CEffectStrengthMod_ApplyEffect)(CCreatureObject&) =
	SetFP(static_cast<BOOL (CEffectStrengthMod::*)(CCreatureObject&)>		(&CEffectStrengthMod::ApplyEffect),			0x516673);
BOOL (CEffectDispel::*Tramp_CEffectDispel_ApplyEffect)(CCreatureObject&) =
	SetFP(static_cast<BOOL (CEffectDispel::*)(CCreatureObject&)>			(&CEffectDispel::ApplyEffect),				0x5184DA);
BOOL (CEffectPriestMemSpellMod::*Tramp_CEffectPriestMemSpellMod_ApplyEffect)(CCreatureObject&) =
	SetFP(static_cast<BOOL (CEffectPriestMemSpellMod::*)(CCreatureObject&)>	(&CEffectPriestMemSpellMod::ApplyEffect),	0x518AA3);
BOOL (CEffectBlindness::*Tramp_CEffectBlindness_ApplyEffect)(CCreatureObject&) =
	SetFP(static_cast<BOOL (CEffectBlindness::*)(CCreatureObject&)>			(&CEffectBlindness::ApplyEffect),			0x51ADF9);
BOOL (CEffectDisease::*Tramp_CEffectDisease_ApplyEffect)(CCreatureObject&) =
	SetFP(static_cast<BOOL (CEffectDisease::*)(CCreatureObject&)>			(&CEffectDisease::ApplyEffect),				0x51B1FB);
BOOL (CEffectRegeneration::*Tramp_CEffectRegeneration_ApplyEffect)(CCreatureObject&) =
	SetFP(static_cast<BOOL (CEffectRegeneration::*)(CCreatureObject&)>		(&CEffectRegeneration::ApplyEffect),		0x51C615);
BOOL (CEffectLearnSpell::*Tramp_CEffectLearnSpell_ApplyEffect)(CCreatureObject&) =
	SetFP(static_cast<BOOL (CEffectLearnSpell::*)(CCreatureObject&)>		(&CEffectLearnSpell::ApplyEffect),			0x52C250);
BOOL (CEffectMagicResistMod::*Tramp_CEffectMagicResistMod_ApplyEffect)(CCreatureObject&) =
	SetFP(static_cast<BOOL (CEffectMagicResistMod::*)(CCreatureObject&)>	(&CEffectMagicResistMod::ApplyEffect),		0x52EB97);
BOOL (CEffectCastSpellOnCondition::*Tramp_CEffectCastSpellOnCondition_ApplyEffect)(CCreatureObject&) =
	SetFP(static_cast<BOOL (CEffectCastSpellOnCondition::*)(CCreatureObject&)>	(&CEffectCastSpellOnCondition::ApplyEffect),	0x53AFB7);
CEffectRepeatingEff& (CEffectRepeatingEff::*Tramp_CEffectRepeatingEff_Construct_5)(ITEM_EFFECT&, POINT&, Enum, int, int) =
	SetFP(static_cast<CEffectRepeatingEff& (CEffectRepeatingEff::*)(ITEM_EFFECT&, POINT&, Enum, int, int)>
																			(&CEffectRepeatingEff::Construct),			0x561AA0);
BOOL (CEffectRepeatingEff::*Tramp_CEffectRepeatingEff_ApplyEffect)(CCreatureObject&) =
	SetFP(static_cast<BOOL (CEffectRepeatingEff::*)(CCreatureObject&)>		(&CEffectRepeatingEff::ApplyEffect),		0x541C3B);
BOOL (CEffectDisintegrate::*Tramp_CEffectDisintegrate_ApplyEffect)(CCreatureObject&) =
	SetFP(static_cast<BOOL (CEffectDisintegrate::*)(CCreatureObject&)>		(&CEffectDisintegrate::ApplyEffect),		0x53F01D);
BOOL (CEffectRemoveProjectile::*Tramp_CEffectRemoveProjectile_ApplyEffect)(CCreatureObject&) =
	SetFP(static_cast<BOOL (CEffectRemoveProjectile::*)(CCreatureObject&)>	(&CEffectRemoveProjectile::ApplyEffect),	0x53F5D8);
BOOL (CEffectCutScene2::*Tramp_CEffectCutScene2_ApplyEffect)(CCreatureObject&) =
	SetFP(static_cast<BOOL (CEffectCutScene2::*)(CCreatureObject&)>			(&CEffectCutScene2::ApplyEffect),			0x542815);
BOOL (CEffectAnimationRemoval::*Tramp_CEffectAnimationRemoval_ApplyEffect)(CCreatureObject&) =
	SetFP(static_cast<BOOL (CEffectAnimationRemoval::*)(CCreatureObject&)>	(&CEffectAnimationRemoval::ApplyEffect),	0x549C0C);

BOOL DETOUR_CEffectAttacksPerRoundMod::DETOUR_ApplyEffect(CCreatureObject& creTarget) {
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
		bPurge = TRUE;
		break;
	}

	return TRUE;
}

BOOL DETOUR_CEffectDamage::DETOUR_ApplyEffect(CCreatureObject& creTarget) {
	if (!pGameOptionsEx->bEffApplyConcCheckDamage &&
		!pGameOptionsEx->bEffDamageFix &&
		!pGameOptionsEx->bEffNoDamageNoSpellInterrupt) {

		(this->*Tramp_CEffectDamage_ApplyEffect)(creTarget);
		
		if (pGameOptionsEx->bEffDamageAwaken) {
			creTarget.m_BaseStats.stateFlags &= ~STATE_SLEEPING;
			creTarget.cdsCurrent.stateFlags &= ~STATE_SLEEPING;
			creTarget.m_EffectsEquipped.RemoveEffect(creTarget, CEFFECT_OPCODE_SLEEP, creTarget.m_EffectsEquipped.posItrPrev, -1, ResRef(), FALSE);
			creTarget.m_EffectsMain.RemoveEffect(creTarget, CEFFECT_OPCODE_SLEEP, creTarget.m_EffectsMain.posItrPrev, -1, ResRef(), FALSE);
		}

		return TRUE;
	}

	if (creTarget.m_bUnmarshalling) return TRUE;

	creTarget.m_bResetAnimationColors = TRUE;
	int nPrevHP = creTarget.m_BaseStats.currentHP;
	
	CAnimation* pAnimation = creTarget.m_animation.pAnimation;
	if (pAnimation == NULL) {
		LPCTSTR lpsz = "DETOUR_CEffectDamage::DETOUR_ApplyEffect(): pAnimation == NULL\r\n";
		L.timestamp();
		L.append(lpsz);
		console.write(lpsz);
		bPurge = TRUE;
		return TRUE;
	}

	if (pAnimation->IsImmuneToDamage()) {
		bPurge = TRUE;
		return TRUE;
	}

	BOOL bCheckSlayerChange;
	if (g_pChitin->pGame->u44c0 <= 0) {
		if (g_pChitin->pWorld->u1230 &&
			g_pChitin->pWorld->u1234 <= 0) {
			bCheckSlayerChange = TRUE;
		} else {
			bCheckSlayerChange = FALSE;
		}
		bCheckSlayerChange = TRUE;
	}

	if (bCheckSlayerChange) {
		if (effect.rParentResource == "SPIN823") {
			bPurge = TRUE;
			return TRUE;
		}
	}

	short wOrient;
	if (eSource == ENUM_INVALID_INDEX) {
		wOrient = creTarget.GetOrientationTo(effect.ptSource);
	} else {
		CCreatureObject* pCre;
		char nReturnVal;
		do {
			nReturnVal = g_pChitin->pGame->m_GameObjectArrayHandler.GetGameObjectShare(eSource, THREAD_ASYNCH, &pCre, INFINITE);
		} while (nReturnVal == OBJECT_SHARING || nReturnVal == OBJECT_DENYING);

		if (nReturnVal == OBJECT_SUCCESS) {
			wOrient = creTarget.GetOrientationTo(pCre->m_currentLoc);
			nReturnVal = g_pChitin->pGame->m_GameObjectArrayHandler.FreeGameObjectShare(eSource, THREAD_ASYNCH, INFINITE);
		} else {
			wOrient = 0;
		}
	}

	if (creTarget.m_BaseStats.stateFlags & STATE_STONE_DEATH) {
		CEffectInstantDeath* pEff = new CEffectInstantDeath();
		pEff->effect.ptSource = effect.ptSource;
		pEff->eSource = eSource;
		pEff->enum2 = enum2;
		pEff->effect.nParam2 = EFFECTINSTANTDEATH_TYPE_STONE_EXPLODE;
		creTarget.ApplyEffect(*pEff, 1, TRUE, TRUE);
		bPurge = TRUE;
		return TRUE;
	}

	if (creTarget.m_BaseStats.stateFlags & STATE_FROZEN_DEATH) {
		CEffectInstantDeath* pEff = new CEffectInstantDeath();
		pEff->effect.ptSource = effect.ptSource;
		pEff->eSource = eSource;
		pEff->enum2 = enum2;
		pEff->effect.nParam2 = EFFECTINSTANTDEATH_TYPE_FROZEN_EXPLODE;
		creTarget.ApplyEffect(*pEff, 1, TRUE, TRUE);
		bPurge = TRUE;
		return TRUE;
	}

	if (creTarget.m_BaseStats.currentHP <= -10 ||
		creTarget.m_BaseStats.stateFlags & STATE_DEAD) {
		bPurge = TRUE;
		return TRUE;
	}

	int nDamageAmount = 0;
	for (int i = 0; i < effect.nDice; i++) {
		nDamageAmount += DieRoll(effect.nDieSides, -creTarget.cdsPrevious.luck) + 1;
	}
	effect.nParam1 += nDamageAmount;
	
	BOOL bBaseDamageDone = (BOOL)effect.nParam1;
	short wAnimSeq = creTarget.wCurrentSequenceSimplified;

	int nDamageType = effect.nParam2 & 0xFFFF0000;
	int nDamageBehavior = effect.nParam2 & 0xFFFF;

	if (nDamageBehavior == EFFECTDAMAGE_BEHAVIOR_NORMAL) {
		switch (nDamageType) {
		case DAMAGETYPE_ACID:
			effect.nParam1 -= effect.nParam1 * creTarget.cdsPrevious.resistAcid / 100;
			break;
		case DAMAGETYPE_COLD:
			effect.nParam1 -= effect.nParam1 * creTarget.cdsPrevious.resistCold / 100;
			break;
		case DAMAGETYPE_CRUSHING:
		case DAMAGETYPE_FIST:
			effect.nParam1 -= effect.nParam1 * creTarget.cdsPrevious.resistCrushing / 100;
			break;
		case DAMAGETYPE_PIERCING:
			effect.nParam1 -= effect.nParam1 * creTarget.cdsPrevious.resistPiercing / 100;
			break;
		case DAMAGETYPE_SLASHING:
			effect.nParam1 -= effect.nParam1 * creTarget.cdsPrevious.resistSlashing / 100;
			break;
		case DAMAGETYPE_ELECTRICITY:
			effect.nParam1 -= effect.nParam1 * creTarget.cdsPrevious.resistElectricity / 100;
			break;
		case DAMAGETYPE_FIRE:
			effect.nParam1 -= effect.nParam1 * creTarget.cdsPrevious.resistFire / 100;
			break;
		case DAMAGETYPE_POISON:
			effect.nParam1 -= effect.nParam1 * creTarget.cdsPrevious.resistPoison / 100;
			break;
		case DAMAGETYPE_MAGIC:
			effect.nParam1 -= effect.nParam1 * creTarget.cdsPrevious.resistMagic / 100;
			break;
		case DAMAGETYPE_MISSILE:
			effect.nParam1 -= effect.nParam1 * creTarget.cdsPrevious.resistMissile / 100;
			break;
		case DAMAGETYPE_MAGICFIRE:
			effect.nParam1 -= effect.nParam1 * creTarget.cdsPrevious.resistMagicFire / 100;
			break;
		case DAMAGETYPE_MAGICCOLD:
			effect.nParam1 -= effect.nParam1 * creTarget.cdsPrevious.resistMagicCold / 100;
			break;
		default:
			break;
		}

		if (g_pChitin->pGame->GetPartyMemberSlot(creTarget.e) != -1) {
			if (g_pChitin->cNetwork.bSessionOpen) {
				effect.nParam1 += effect.nParam1 * g_pChitin->pGame->m_GameOptions.m_nMPDifficultyMultiplier / 100;
			} else {
				effect.nParam1 += effect.nParam1 * g_pChitin->pGame->m_GameOptions.m_nDifficultyMultiplier / 100;
			}
			
			if (effect.nParam1 > creTarget.cdsPrevious.maxHP &&
				creTarget.cdsPrevious.maxHP < 14) {
				effect.nParam1 = creTarget.cdsPrevious.maxHP - 1;
			}
		}

	}

	BOOL bPreviousSpellInterruptState = creTarget.m_bInterruptSpellcasting;
	creTarget.m_bInterruptSpellcasting = TRUE;

	if (pGameOptionsEx->bEffApplyConcCheckDamage) {
		int nBaseDifficulty = 0;
		int nLevelMod = 0;

		if (creTarget.m_bCastingSpell &&
			(creTarget.aCurrent.opcode == ACTION_SPELL || creTarget.aCurrent.opcode == ACTION_SPELL_NO_DEC)) {
			IECString sSpell;
			if (creTarget.aCurrent.GetSName1().IsEmpty()) {
				creTarget.GetSpellIdsName(creTarget.aCurrent.i, &sSpell);
			} else {
				sSpell = creTarget.aCurrent.GetSName1();
			}
	
			ResSplContainer resSpell;
			resSpell.LoadResource(ResRef(sSpell), TRUE, TRUE);
			if (resSpell.bLoaded &&
				resSpell.name.IsNotEmpty()) {
				nLevelMod = resSpell.GetSpellLevel();
			}
			resSpell.Unload();
		}

		int nDifficulty = nBaseDifficulty + nLevelMod + effect.nParam1;
		int nRoll = DieRoll(20, creTarget.cdsPrevious.luck);
		if (nRoll >= nDifficulty) { //if pass
			creTarget.m_bInterruptSpellcasting = bPreviousSpellInterruptState;
		}
	}

	if (pGameOptionsEx->bEffNoDamageNoSpellInterrupt) {
		if (nDamageBehavior == EFFECTDAMAGE_BEHAVIOR_NORMAL &&
			effect.nParam1 <= 0) {
			creTarget.m_bInterruptSpellcasting = bPreviousSpellInterruptState;
		}
	}

	if (creTarget.ePuppet != ENUM_INVALID_INDEX) {
		Enum ePuppet = creTarget.ePuppet;
		CCreatureObject* pCrePuppet;
		char nReturnVal = g_pChitin->pGame->m_GameObjectArrayHandler.GetGameObjectDeny(ePuppet, THREAD_ASYNCH, &pCrePuppet, INFINITE);
		if (nReturnVal == OBJECT_SUCCESS) {
			creTarget.ePuppet = ENUM_INVALID_INDEX;
			pCrePuppet->m_bRemoveFromArea = TRUE;
			nReturnVal = g_pChitin->pGame->m_GameObjectArrayHandler.FreeGameObjectDeny(ePuppet, THREAD_ASYNCH, INFINITE);
		}
		creTarget.u36d0 = TRUE;
	}

	if (nDamageType == DAMAGETYPE_POISON) {
		if (creTarget.m_wPoisonTimer <= 0) {
			creTarget.m_wPoisonTimer = 100;
			CMessagePlaySoundset* pMsg = IENew CMessagePlaySoundset();
			pMsg->eTarget = creTarget.e;
			pMsg->eSource = creTarget.e;
			pMsg->nSoundIdx = SOUNDSET_DAMAGE;
			pMsg->bPrintToConsole = TRUE;
			pMsg->bLimitLength = TRUE;
			g_pChitin->messages.Send(*pMsg, FALSE);
		}
	} else {
		if (bBaseDamageDone) {
			CMessagePlaySoundset* pMsg = IENew CMessagePlaySoundset();
			pMsg->eTarget = creTarget.e;
			pMsg->eSource = creTarget.e;
			pMsg->nSoundIdx = SOUNDSET_DAMAGE;
			pMsg->bPrintToConsole = TRUE;
			pMsg->bLimitLength = TRUE;
			g_pChitin->messages.Send(*pMsg, FALSE);
		}
	}

	switch (nDamageBehavior) {
	case EFFECTDAMAGE_BEHAVIOR_NORMAL:
		if (bBaseDamageDone) PrintEffectTextOnApply(creTarget);
		if (effect.nParam1 > 0) {
			Trigger tTookDamage(TRIGGER_TOOK_DAMAGE, effect.nParam1);
			CMessageSetTrigger* pMsg = IENew CMessageSetTrigger();
			pMsg->eTarget = creTarget.e;
			pMsg->eSource = creTarget.e;
			pMsg->t = tTookDamage;
			g_pChitin->messages.Send(*pMsg, FALSE);
		}
		creTarget.m_BaseStats.currentHP -= effect.nParam1;
		break;
	case EFFECTDAMAGE_BEHAVIOR_SETVALUE:
		creTarget.m_BaseStats.currentHP = creTarget.cdsPrevious.maxHP < effect.nParam1 ? effect.nParam1 : creTarget.cdsPrevious.maxHP;
		break;
	case EFFECTDAMAGE_BEHAVIOR_SETPERCENT:
		creTarget.m_BaseStats.currentHP = creTarget.m_BaseStats.currentHP * effect.nParam1 / 100;
		break;
	case EFFECTDAMAGE_BEHAVIOR_LOSEPERCENT:
		creTarget.m_BaseStats.currentHP -= creTarget.cdsPrevious.maxHP * effect.nParam1 / 100;
		break;
	default:
		break;
	}

	creTarget.m_bShowDamageArrow = TRUE;
	creTarget.m_wDamagePortraitFlashTimer = 128;
	creTarget.m_wDamageArrowTimer = 128;

	if (g_pChitin->pCursor->nCurrentCursorIdx == CURSOR_TOOLTIP_SCROLL &&
		creTarget.pArea != NULL &&
		creTarget.pArea->eDamageLocatorTarget == creTarget.e &&
		g_pChitin->pGame->GetPartyMemberSlot(creTarget.e) != -1) {
		creTarget.UpdateHPStatusTooltip(*g_pChitin->pCursor->pCtrlTarget);
	}

	PlayHitSound(nDamageType, creTarget);

	switch (nDamageType) {
	case DAMAGETYPE_PIERCING:
	case DAMAGETYPE_CRUSHING:
	case DAMAGETYPE_SLASHING:
	case DAMAGETYPE_MISSILE:
		if (nPrevHP - creTarget.m_BaseStats.currentHP < 6) {
			creTarget.CreateGore(0, wOrient, PARTICLETYPE_BLOOD_SMALL);
		} else {
			creTarget.CreateGore(0, wOrient, PARTICLETYPE_BLOOD_MEDIUM);
		}
		break;
	case DAMAGETYPE_COLD:
		PlaySound(ResRef("HIT_06"), creTarget);
		creTarget.StartSpriteEffect(GORETYPE_COLD, 0, (nPrevHP - creTarget.m_BaseStats.currentHP) * 3);
		break;
	case DAMAGETYPE_MAGICCOLD: //omitted in original code
		if (pGameOptionsEx->bEffDamageFix) {
			PlaySound(ResRef("HIT_06"), creTarget);
			creTarget.StartSpriteEffect(GORETYPE_COLD, 0, (nPrevHP - creTarget.m_BaseStats.currentHP) * 3);
		}
		break;
	case DAMAGETYPE_FIRE:
	case DAMAGETYPE_MAGICFIRE:
		PlaySound(ResRef("FIRE"), creTarget);
		creTarget.StartSpriteEffect(GORETYPE_FIRE, 0, (nPrevHP - creTarget.m_BaseStats.currentHP) * 3);
		break;
	case DAMAGETYPE_ELECTRICITY:
		PlaySound(ResRef("HIT_05"), creTarget);
		creTarget.StartSpriteEffect(GORETYPE_SHOCK, 0, (nPrevHP - creTarget.m_BaseStats.currentHP) * 3);
		break;
	case DAMAGETYPE_MAGIC:
		PlaySound(ResRef("HIT_07"), creTarget);
		break;
	default:
		break;
	}

	if (wAnimSeq != SEQ_DAMAGE &&
		wAnimSeq != SEQ_DIE &&
		wAnimSeq != SEQ_TWITCH &&
		wAnimSeq != SEQ_SLEEP) {
		if (pGameOptionsEx->bEffNoDamageNoSpellInterrupt &&
			nDamageBehavior == EFFECTDAMAGE_BEHAVIOR_NORMAL &&
			effect.nParam1 <= 0 &&
			(wAnimSeq == SEQ_CONJURE || wAnimSeq == SEQ_CAST)) {
		} else {
			creTarget.SetAnimationSequence(SEQ_DAMAGE);
		}
	}

	if (creTarget.cdsPrevious.minHitPoints > 0 &&
		creTarget.m_BaseStats.currentHP <= 0) {
		creTarget.m_BaseStats.currentHP = creTarget.cdsPrevious.minHitPoints;
	}

	if (creTarget.m_BaseStats.currentHP <= 0) {
		if (g_pChitin->pGame->GetPartyMemberSlot(creTarget.e) != -1 &&
			creTarget.m_BaseStats.currentHP > -20) {
			creTarget.m_BaseStats.currentHP = 0;
		}
		CEffectInstantDeath* pEff = new CEffectInstantDeath();
		pEff->eSource = eSource;
		pEff->enum2 = enum2;

		switch (nDamageType) {
		case DAMAGETYPE_FIST:
			{
			delete pEff;
			pEff = NULL;
			ITEM_EFFECT* pIF = IENew ITEM_EFFECT();
			CreateItemEffect(*pIF, CEFFECT_OPCODE_UNCONSCIOUSNESS);
			pIF->timing = 0;
			pIF->duration = (1 - creTarget.m_BaseStats.currentHP) * 15;
			POINT ptSrc;
			ptSrc.x = -1;
			ptSrc.y = -1;
			POINT ptDest;
			ptDest.x = -1;
			ptDest.y = -1;

			pEff = (CEffectInstantDeath*)&CreateEffect(*pIF, ptSrc, ENUM_INVALID_INDEX, ptDest, ENUM_INVALID_INDEX);
			pEff->effect.ptSource = creTarget.m_currentLoc;
			pEff->eSource = creTarget.e;
			pEff->enum2 = ENUM_INVALID_INDEX;
			pEff->effect.ptDest = effect.ptDest;
			}
			
			creTarget.m_BaseStats.currentHP = 1;

			break;
		case DAMAGETYPE_ACID:
			pEff->effect.nParam2 = creTarget.m_BaseStats.currentHP < -5 ? EFFECTINSTANTDEATH_TYPE_ACID : EFFECTINSTANTDEATH_TYPE_NORMAL;
			break;
		case DAMAGETYPE_COLD:
		case DAMAGETYPE_MAGICCOLD:
			pEff->effect.nParam2 = creTarget.m_BaseStats.currentHP < -5 ? EFFECTINSTANTDEATH_TYPE_FROZEN : EFFECTINSTANTDEATH_TYPE_NORMAL;
			break;
		case DAMAGETYPE_CRUSHING:
		case DAMAGETYPE_PIERCING:
		case DAMAGETYPE_SLASHING:
			pEff->effect.nParam2 = creTarget.m_BaseStats.currentHP < -8 ? EFFECTINSTANTDEATH_TYPE_CHUNKED : EFFECTINSTANTDEATH_TYPE_NORMAL;
			break;
		case DAMAGETYPE_ELECTRICITY:
			pEff->effect.nParam2 = creTarget.m_BaseStats.currentHP < -5 ? EFFECTINSTANTDEATH_TYPE_ELECTRIC : EFFECTINSTANTDEATH_TYPE_NORMAL;
			break;
		case DAMAGETYPE_FIRE:
			pEff->effect.nParam2 = creTarget.m_BaseStats.currentHP < -5 ? EFFECTINSTANTDEATH_TYPE_BURNING : EFFECTINSTANTDEATH_TYPE_NORMAL;
			break;
		case DAMAGETYPE_MAGICFIRE: //omitted in original code
			if (pGameOptionsEx->bEffDamageFix) {
				pEff->effect.nParam2 = creTarget.m_BaseStats.currentHP < -5 ? EFFECTINSTANTDEATH_TYPE_BURNING : EFFECTINSTANTDEATH_TYPE_NORMAL;
				break;
			}
		case DAMAGETYPE_POISON:
		case DAMAGETYPE_MAGIC:
		case DAMAGETYPE_MISSILE:
			pEff->effect.nParam2 = EFFECTINSTANTDEATH_TYPE_NORMAL;
			break;
		default:
			LPCTSTR lpsz = "DETOUR_CEffectDamage::DETOUR_ApplyEffect(): WEIRD damage\r\n";
			L.timestamp();
			L.append(lpsz);
			console.write(lpsz);
			pEff->effect.nParam2 = EFFECTINSTANTDEATH_TYPE_NORMAL;
			break;
		}

		creTarget.ApplyEffect(*pEff, 1, TRUE, TRUE);
	}

	if (pGameOptionsEx->bEffDamageAwaken) {
		creTarget.m_BaseStats.stateFlags &= ~STATE_SLEEPING;
		creTarget.cdsCurrent.stateFlags &= ~STATE_SLEEPING;
		creTarget.m_EffectsEquipped.RemoveEffect(creTarget, CEFFECT_OPCODE_SLEEP, creTarget.m_EffectsEquipped.posItrPrev, -1, ResRef(), FALSE);
		creTarget.m_EffectsMain.RemoveEffect(creTarget, CEFFECT_OPCODE_SLEEP, creTarget.m_EffectsMain.posItrPrev, -1, ResRef(), FALSE);
	}

	int n = creTarget.cdsPrevious.maxHP < 1 ? 1 : creTarget.cdsPrevious.maxHP;
	if (nPrevHP * 100 / n > *g_pHPHurtThresholdPercent &&
		creTarget.m_BaseStats.currentHP * 100 / n < *g_pHPHurtThresholdPercent &&
		creTarget.m_BaseStats.currentHP * 100 / n > 0) { //went from above threshold to below threshold
		CMessagePlaySoundset* pMsg = IENew CMessagePlaySoundset();
		pMsg->eTarget = creTarget.e;
		pMsg->eSource = creTarget.e;
		pMsg->nSoundIdx = SOUNDSET_HURT;
		pMsg->bPrintToConsole = TRUE;
		pMsg->bLimitLength = FALSE;
		g_pChitin->messages.Send(*pMsg, FALSE);

		creTarget.SetAutoPauseInfo(8);
	} else if (creTarget.m_BaseStats.currentHP * 100 / n < *g_pHPHurtThresholdPercent &&
		creTarget.m_BaseStats.currentHP * 100 / n > 0 &&
		IERand() * 10 >> 15 == 0) { //was below threshold and still below threshold, with 1/16 chance
		CMessagePlaySoundset* pMsg = IENew CMessagePlaySoundset();
		pMsg->eTarget = creTarget.e;
		pMsg->eSource = creTarget.e;
		pMsg->nSoundIdx = SOUNDSET_HURT;
		pMsg->bPrintToConsole = TRUE;
		pMsg->bLimitLength = FALSE;
		g_pChitin->messages.Send(*pMsg, FALSE);

		creTarget.SetAutoPauseInfo(8);
	}

	bPurge = TRUE;
	return TRUE;
};

BOOL DETOUR_CEffectDexterityMod::DETOUR_ApplyEffect(CCreatureObject& creTarget) {
	//case 0, 1, 2, default as original
	switch (effect.nParam2) {
	case 0: //sum
		if (effect.nTiming == 1) {
			creTarget.m_BaseStats.dexterity += effect.nParam1;
			creTarget.m_BaseStats.dexterity = min(creTarget.m_BaseStats.dexterity, 25);
			creTarget.m_BaseStats.dexterity = max(creTarget.m_BaseStats.dexterity, 0);
			bRefreshStats = TRUE;
			bPurge = TRUE;
		} else {
			creTarget.cdsDiff.dexterity += effect.nParam1;
			bPurge = FALSE;
		}
		break;
	case 1: //set
		if (effect.nTiming == 1) {
			creTarget.m_BaseStats.dexterity = effect.nParam1;
			creTarget.m_BaseStats.dexterity = min(creTarget.m_BaseStats.dexterity, 25);
			creTarget.m_BaseStats.dexterity = max(creTarget.m_BaseStats.dexterity, 0);
			bRefreshStats = TRUE;
			bPurge = TRUE;
		} else {
			creTarget.cdsCurrent.dexterity = effect.nParam1;
			creTarget.cdsCurrent.dexterity = min(creTarget.cdsCurrent.dexterity, 25);
			creTarget.cdsCurrent.dexterity = max(creTarget.cdsCurrent.dexterity, 0);
			bPurge = FALSE;
		}
		break;
	case 2:	//percentage
		if (effect.nTiming == 1) {
			creTarget.m_BaseStats.dexterity = creTarget.m_BaseStats.dexterity * effect.nParam1 / 100;
			creTarget.m_BaseStats.dexterity = min(creTarget.m_BaseStats.dexterity, 25);
			creTarget.m_BaseStats.dexterity = max(creTarget.m_BaseStats.dexterity, 0);
			bRefreshStats = TRUE;
			bPurge = TRUE;
		} else {
			creTarget.cdsCurrent.dexterity = creTarget.cdsCurrent.dexterity * effect.nParam1 / 100;
			creTarget.cdsCurrent.dexterity = min(creTarget.cdsCurrent.dexterity, 25);
			creTarget.cdsCurrent.dexterity = max(creTarget.cdsCurrent.dexterity, 0);
			bPurge = FALSE;
		}
		break;
	case 3: //IWD1/P&P Cat's Grace spell
		if (!pRuleEx->m_ClassSpellAbility.m_2da.bLoaded) {
			LPCTSTR lpsz = "DETOUR_CEffectDexterityMod::DETOUR_ApplyEffect(): invalid effect.nParam2 (%d)\r\n";
			console.write(lpsz, 1, effect.nParam2);
			L.timestamp();
			L.append(lpsz, 1, effect.nParam2);
			bPurge = TRUE;
			break;
		}
		{
			short wParam1Low = effect.nParam1 & 0xFFFF;
			short wParam1High = effect.nParam1 >> 16;

			if (wParam1High == 0) {
				int nDieSides;

				if (wParam1Low > 0) {
					nDieSides = wParam1Low;
				} else {
					IECString sClass = g_pChitin->pGame->GetClassString(creTarget.oBase.GetClass(), KIT_TRUECLASS);
					IECString& sDieSides = pRuleEx->m_ClassSpellAbility.GetValue(IECString("DEX"), sClass);
					sscanf_s((LPCTSTR)sDieSides, "%d", &nDieSides);
					if (nDieSides == 0) nDieSides = 6;
				}

				wParam1High = DieRoll(nDieSides, 0) + 1;
				effect.nParam1 = wParam1Low | (wParam1High << 16);
			}

			if (effect.nTiming == 1) {
				creTarget.m_BaseStats.dexterity += wParam1High;
				creTarget.m_BaseStats.dexterity = min(creTarget.m_BaseStats.dexterity, 20);
				creTarget.m_BaseStats.dexterity = max(creTarget.m_BaseStats.dexterity, 0);
				bRefreshStats = TRUE;
				bPurge = TRUE;
			} else {
				creTarget.cdsCurrent.dexterity += wParam1High;
				creTarget.cdsCurrent.dexterity = min(creTarget.cdsCurrent.dexterity, 20);
				creTarget.cdsCurrent.dexterity = max(creTarget.cdsCurrent.dexterity, 0);
				bPurge = FALSE;
			}
		}
		break;
	default:
		LPCTSTR lpsz = "DETOUR_CEffectDexterityMod::DETOUR_ApplyEffect(): invalid effect.nParam2 (%d)\r\n";
		console.write(lpsz, 1, effect.nParam2);
		L.timestamp();
		L.append(lpsz, 1, effect.nParam2);
		bPurge = TRUE;
		break;
	}

	return TRUE;
}

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
		bPurge = TRUE;
		break;
	}

	creTarget.cdsCurrent.m_RepeatingEffs.AddTail(pRepeat);

	return TRUE;
}

BOOL DETOUR_CEffectMageMemSpellMod::DETOUR_ApplyEffect(CCreatureObject& creTarget) {
	int bit = 1;

	if (effect.nParam2 & 0x200 &&
		effect.nParam1 >= 0 &&
		effect.nParam1 < 9) {
		CreFileMemSpellLevel& splLvl = creTarget.cdsCurrent.MemInfoMage[effect.nParam1];
		splLvl.wMaxMemSpells *= 2;
		splLvl.wCurrMemSpells *= 2;
	} else if (effect.nParam2 == 0) { //remainder is the original function
		for (int i = 0; i < effect.nParam1 && i < 9; i++) {
			CreFileMemSpellLevel& splLvl = creTarget.cdsCurrent.MemInfoMage[i];
			splLvl.wMaxMemSpells *= 2;
			splLvl.wCurrMemSpells *= 2;
		}
	} else {
		for (int i = 0; i < 9; i++) {
			CreFileMemSpellLevel& splLvl = creTarget.cdsCurrent.MemInfoMage[i];
			if (effect.nParam2 & bit &&
				splLvl.wMaxMemSpells > 0) {
				splLvl.wMaxMemSpells += (short)effect.nParam1;
				splLvl.wCurrMemSpells += (short)effect.nParam1;
			}
			bit = bit << 1;
		}
	}

	return TRUE;
};

BOOL DETOUR_CEffectStrengthMod::DETOUR_ApplyEffect(CCreatureObject& creTarget) {
	switch (effect.nParam2) {
	case 0: //sum
		{
			if (effect.nTiming == 1) {
				char strengthEffective = CDerivedStats_GetEffectiveStrength(creTarget.m_BaseStats.strength, creTarget.m_BaseStats.strengthEx) + effect.nParam1;
				char strength = 0;
				char strengthEx = 0;
				CDerivedStats_GetRealStrength(strengthEffective, strength, strengthEx);
				creTarget.m_BaseStats.strength = strength;
				creTarget.m_BaseStats.strength = min(creTarget.m_BaseStats.strength, 25);
				creTarget.m_BaseStats.strength = max(creTarget.m_BaseStats.strength, 0);
				creTarget.m_BaseStats.strengthEx = strengthEx;
				creTarget.m_BaseStats.strengthEx = min(creTarget.m_BaseStats.strengthEx, 100);
				creTarget.m_BaseStats.strengthEx = max(creTarget.m_BaseStats.strengthEx, 0);
				bRefreshStats = TRUE;
				bPurge = TRUE;
			} else {
				char strengthEffective = CDerivedStats_GetEffectiveStrength((char&)creTarget.cdsCurrent.strength, (char&)creTarget.cdsCurrent.strengthEx) + effect.nParam1;
				char strength = 0;
				char strengthEx = 0;
				CDerivedStats_GetRealStrength(strengthEffective, strength, strengthEx);
				creTarget.cdsCurrent.strength = strength;
				creTarget.cdsCurrent.strengthEx = strengthEx;
				bPurge = FALSE;
			}
		}
		break;
	case 1: //set
		if (effect.nTiming == 1) {
			creTarget.m_BaseStats.strength = effect.nParam1;
			creTarget.m_BaseStats.strength = min(creTarget.m_BaseStats.strength, 25);
			creTarget.m_BaseStats.strength = max(creTarget.m_BaseStats.strength, 0);
			bRefreshStats = TRUE;
			bPurge = TRUE;
		} else {
			creTarget.cdsCurrent.strength = effect.nParam1;
			creTarget.cdsCurrent.strength = min(creTarget.cdsCurrent.strength, 25);
			creTarget.cdsCurrent.strength = max(creTarget.cdsCurrent.strength, 0);
			bPurge = FALSE;
		}
		break;
	case 2: //percentage
		if (effect.nTiming == 1) {
			creTarget.m_BaseStats.strength = (creTarget.m_BaseStats.strength * effect.nParam1) / 100;
			creTarget.m_BaseStats.strength = min(creTarget.m_BaseStats.strength, 25);
			creTarget.m_BaseStats.strength = max(creTarget.m_BaseStats.strength, 0);
			bRefreshStats = TRUE;
			bPurge = TRUE;
		} else {
			creTarget.cdsCurrent.strength = (creTarget.m_BaseStats.strength * effect.nParam1) / 100;
			creTarget.cdsCurrent.strength = min(creTarget.m_BaseStats.strength, 25);
			creTarget.cdsCurrent.strength = max(creTarget.m_BaseStats.strength, 0);
			bPurge = FALSE;
		}
		break;
	case 3: //IWD1/P&P Strength Spell
		if (!pRuleEx->m_ClassSpellAbility.m_2da.bLoaded) {
			LPCTSTR lpsz = "DETOUR_CEffectStrengthMod::DETOUR_ApplyEffect(): invalid effect.nParam2 (%d)\r\n";
			console.write(lpsz, 1, effect.nParam2);
			L.timestamp();
			L.append(lpsz, 1, effect.nParam2);
			bPurge = TRUE;
			break;
		}
		{
			short wParam1Low = effect.nParam1 & 0xFFFF;
			short wParam1High = effect.nParam1 >> 16;
			int nMaxStrengthEx;

			if (wParam1High == 0) {
				int nDieSides;

				if (wParam1Low > 0) {
					nDieSides = effect.nParam1;
				} else {
					IECString sClass = g_pChitin->pGame->GetClassString(creTarget.oBase.GetClass(), KIT_TRUECLASS);
					IECString& sDieSides = pRuleEx->m_ClassSpellAbility.GetValue(IECString("STR"), sClass);
					sscanf_s((LPCTSTR)sDieSides, "%d", &nDieSides);
					if (nDieSides == 0) nDieSides = 6;
				}

				wParam1High = DieRoll(nDieSides, 0) + 1;
				effect.nParam1 = wParam1Low | (wParam1High << 16);
			}

			if (wParam1Low > 0) {
				nMaxStrengthEx = 100;
			} else {
				IECString sClass = g_pChitin->pGame->GetClassString(creTarget.oBase.GetClass(), KIT_TRUECLASS);
				IECString& sMaxStrEx = pRuleEx->m_ClassSpellAbility.GetValue(IECString("STREX"), sClass);
				sscanf_s((LPCTSTR)sMaxStrEx, "%d", &nMaxStrengthEx);
			}

			if (effect.nTiming == 1) {
				char strengthEffective = CDerivedStats_GetEffectiveStrengthSpell(creTarget.m_BaseStats.strength, creTarget.m_BaseStats.strengthEx) + wParam1High;
				char strength = 0;
				char strengthEx = 0;
				CDerivedStats_GetRealStrengthSpell(strengthEffective, strength, strengthEx);
				creTarget.m_BaseStats.strength = strength;
				creTarget.m_BaseStats.strength = min(creTarget.m_BaseStats.strength, 18);
				creTarget.m_BaseStats.strength = max(creTarget.m_BaseStats.strength, 0);
				creTarget.m_BaseStats.strengthEx = strengthEx;
				creTarget.m_BaseStats.strengthEx = min(creTarget.m_BaseStats.strengthEx, nMaxStrengthEx ? 100 : 0);
				creTarget.m_BaseStats.strengthEx = max(creTarget.m_BaseStats.strengthEx, 0);
				bRefreshStats = TRUE;
				bPurge = TRUE;
			} else {
				char strengthEffective = CDerivedStats_GetEffectiveStrengthSpell((char&)creTarget.cdsCurrent.strength, (char&)creTarget.cdsCurrent.strengthEx) + wParam1High;
				char strength = 0;
				char strengthEx = 0;
				CDerivedStats_GetRealStrengthSpell(strengthEffective, strength, strengthEx);
				creTarget.cdsCurrent.strength = strength;
				creTarget.cdsCurrent.strength = min(creTarget.cdsCurrent.strength, 18);
				creTarget.cdsCurrent.strength = max(creTarget.cdsCurrent.strength, 0);
				creTarget.cdsCurrent.strengthEx = strengthEx;
				creTarget.cdsCurrent.strengthEx = min(creTarget.cdsCurrent.strengthEx, nMaxStrengthEx ? 100 : 0);
				creTarget.cdsCurrent.strengthEx = max(creTarget.cdsCurrent.strengthEx, 0);
				bPurge = FALSE;
			}
		}
		break;
	default:
		LPCTSTR lpsz = "DETOUR_CEffectStrengthMod::DETOUR_ApplyEffect(): invalid effect.nParam2 (%d)\r\n";
		console.write(lpsz, 1, effect.nParam2);
		L.timestamp();
		L.append(lpsz, 1, effect.nParam2);
		bPurge = TRUE;
		break;
	}

	return TRUE;
}

BOOL DETOUR_CEffectDispel::DETOUR_ApplyEffect(CCreatureObject& creTarget) {
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

	creTarget.m_bResetAnimationColors = TRUE;
	creTarget.u36e0 = TRUE;
	creTarget.u36e4 = TRUE;

	bRefreshStats = TRUE;
	bPurge = TRUE;

	return TRUE;
};

BOOL DETOUR_CEffectPriestMemSpellMod::DETOUR_ApplyEffect(CCreatureObject& creTarget) {
	int bit = 1;

	if (effect.nParam2 & 0x200 &&
		effect.nParam1 >= 0 &&
		effect.nParam1 < 7) {
		CreFileMemSpellLevel& splLvl = creTarget.cdsCurrent.MemInfoPriest[effect.nParam1];
		splLvl.wMaxMemSpells *= 2;
		splLvl.wCurrMemSpells *= 2;
	} else if (effect.nParam2 == 0) { //remainder is the original function
		for (int i = 0; i < effect.nParam1 && i < 7; i++) {
			CreFileMemSpellLevel& splLvl = creTarget.cdsCurrent.MemInfoPriest[i];
			splLvl.wMaxMemSpells *= 2;
			splLvl.wCurrMemSpells *= 2;
		}
	} else {
		for (int i = 0; i < 7; i++) {
			CreFileMemSpellLevel& splLvl = creTarget.cdsCurrent.MemInfoPriest[i];
			if (effect.nParam2 & bit &&
				splLvl.wMaxMemSpells > 0) {
				splLvl.wMaxMemSpells += (short)effect.nParam1;
				splLvl.wCurrMemSpells += (short)effect.nParam1;
			}
			bit = bit << 1;
		}
	}

	return TRUE;
};

BOOL DETOUR_CEffectBlindness::DETOUR_ApplyEffect(CCreatureObject& creTarget) {
	//Remove cumulative penalty
	if (pGameOptionsEx->bEffBlindnessFix) {
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

	//Change to spell description
	if (pGameOptionsEx->bEffBlindnessAsSpellDesc) {
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

	return TRUE;
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
		bPurge = TRUE;
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
		bPurge = TRUE;
		break;
	}

	creTarget.cdsCurrent.m_RepeatingEffs.AddTail(pRepeat);

	return TRUE;
}

BOOL DETOUR_CEffectLearnSpell::DETOUR_ApplyEffect(CCreatureObject& creTarget) {
	int wParam1High = effect.nParam1 >> 16;

	IECString sLearnSpellMod;
	int nLearnSpellMod;
	int nRow = creTarget.cdsPrevious.intelligence;
	int nCol = 0; //LEARN_SPELL
	if (nCol < g_pChitin->pGame->INTMOD.nCols &&
		nRow < g_pChitin->pGame->INTMOD.nRows &&
		nCol >= 0 &&
		nRow >= 0) {
		sLearnSpellMod = *((g_pChitin->pGame->INTMOD.pDataArray) + (g_pChitin->pGame->INTMOD.nCols * nRow + nCol));
	} else {
		sLearnSpellMod = g_pChitin->pGame->INTMOD.defaultVal;
	}
	sscanf_s((LPCTSTR)sLearnSpellMod, "%d", &nLearnSpellMod);

	int nRand = IERand() * 100 >> 15;

	if (g_pChitin->cNetwork.bSessionOpen &&
		g_pChitin->pGame->m_GameOptions.m_nMPDifficultyMultiplier < 0) {
		nRand = 1;
	} else
	if (g_pChitin->pGame->m_GameOptions.m_nDifficultyMultiplier < 0) {
		nRand = 1;
	}

	ResSplContainer resSpell;
	resSpell.LoadResource(effect.rResource, TRUE, TRUE);
	if (!resSpell.bLoaded) {
		bPurge = TRUE;
		return TRUE;
	}

	short wLevel = resSpell.GetSpellLevel();
	short wType = resSpell.GetSpellType();
	int nSchoolExclusionFlags = resSpell.GetExclusionFlags() & 0x3FC0; //keep only spell school bits

	if (wParam1High & EFFECTLEARNSPELL_RESTRICT_SCHOOL &&
		wType == SPELLTYPE_MAGE &&
		creTarget.GetKitUnusableFlag() & nSchoolExclusionFlags) {
		resSpell.Unload();
		bPurge = TRUE;
		return TRUE;
	}

	if (wParam1High & EFFECTLEARNSPELL_NO_SORCERER &&
		creTarget.GetCurrentObject().GetClass() == CLASS_SORCERER) {
		resSpell.Unload();
		bPurge = TRUE;
		return TRUE;
	}

	BOOL bAlreadyKnown = FALSE;
	POSITION pos;
	if (wParam1High & EFFECTLEARNSPELL_NO_XP_DUPLICATE) {
		switch (wType) {
		case SPELLTYPE_MAGE:
			pos = creTarget.m_KnownSpellsWizard[wLevel - 1].GetHeadPosition();
			while (pos != NULL && bAlreadyKnown == FALSE) {
				CreFileKnownSpell* pKSpell = (CreFileKnownSpell*)creTarget.m_KnownSpellsWizard[wLevel - 1].GetNext(pos);
				if (pKSpell->name == resSpell.name) {
					bAlreadyKnown = TRUE;
				}
			}
			break;
		case SPELLTYPE_PRIEST:
			pos = creTarget.m_KnownSpellsPriest[wLevel - 1].GetHeadPosition();
			while (pos != NULL && bAlreadyKnown == FALSE) {
				CreFileKnownSpell* pKSpell = (CreFileKnownSpell*)creTarget.m_KnownSpellsPriest[wLevel - 1].GetNext(pos);
				if (pKSpell->name == resSpell.name) {
					bAlreadyKnown = TRUE;
				}
			}
			break;
		default:
			break;
		}
	}

	if (creTarget.m_BaseStats.kit[1] != KIT_TRUECLASS) {
		if (g_pChitin->pGame->GetMageSchool(creTarget.m_BaseStats.kit[1]) == resSpell.GetSpellSchoolPrimary()) {
			nLearnSpellMod += 15;
		} else {
			nLearnSpellMod -= 15;
		}
	}

	if ((nRand <= nLearnSpellMod) ||
		wParam1High & EFFECTLEARNSPELL_SUCCESS_ALWAYS) { //success
		switch (wType) {
		case SPELLTYPE_MAGE:
			creTarget.AddKnownSpellMage(effect.rResource, wLevel - 1);
			break;
		case SPELLTYPE_PRIEST:
			creTarget.AddKnownSpellPriest(effect.rResource, wLevel - 1);
			break;
		default:
			creTarget.AddKnownSpell(effect.rResource, FALSE);
			break;
		}

		if (!bAlreadyKnown &&
			!(wParam1High & EFFECTLEARNSPELL_NO_XP_ALWAYS) &&
			creTarget.GetCurrentObject().EnemyAlly <= EA_CONTROLLEDCUTOFF) {
			IECString sXPBonus;
			int nXPBonus;
			nRow = 2; //LEARN_SPELL
			nCol = wLevel - 1;

			if (nCol < g_pChitin->pGame->XPBONUS.nCols &&
				nRow < g_pChitin->pGame->XPBONUS.nRows &&
				nCol >= 0 &&
				nRow >= 0) {
				sXPBonus = *((g_pChitin->pGame->XPBONUS.pDataArray) + (g_pChitin->pGame->XPBONUS.nCols * nRow + nCol));
			} else {
				sXPBonus = g_pChitin->pGame->XPBONUS.defaultVal;
			}
			sscanf_s((LPCTSTR)sXPBonus, "%d", &nXPBonus);

			g_pChitin->pGame->AddExperienceParty(nXPBonus);
		}
	}

	resSpell.Unload();
	bPurge = TRUE;
	return TRUE;
}

BOOL DETOUR_CEffectMagicResistMod::DETOUR_ApplyEffect(CCreatureObject& creTarget) {
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
				bPurge = FALSE;
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
			bPurge = TRUE;
			break;
	}
	return TRUE;
}

BOOL DETOUR_CEffectCastSpellOnCondition::DETOUR_ApplyEffect(CCreatureObject& creTarget) {
	Trigger t(TRIGGER_NONE, 0);
	Object o;

	CConditionalSpell* pConditionalSpell = new CConditionalSpell();
	pConditionalSpell->dwFlags = 0;
	pConditionalSpell->rResource1 = effect.rResource;
	pConditionalSpell->rResource2 = effect.rResource2;
	pConditionalSpell->rResource3 = effect.rResource3;

	short wParam3High = effect.nParam3 >> 16; //bool game ticks set
	short wParam3Low = effect.nParam3 & 0xFFFF; //set flags, portrait icon, purge after trigger
	unsigned short wParam2High = effect.nParam2 >> 16; //condition check period
	short wParam2Low = effect.nParam2 & 0xFFFF; //condition

	if (wParam3High == 0) {
		effect.nParam4 = g_pChitin->pGame->m_WorldTimer.nGameTime; //time effect first applied
		wParam3High = 1;
		effect.nParam3 = wParam3High << 16 | wParam3Low;
	}

	switch (wParam2Low) {
	case 0:
		t.opcode = TRIGGER_HIT_BY;
		break;
	case 1:
		t.opcode = TRIGGER_SEE;
		t.o.oids.id1 = OBJECT_NEARESTENEMYOF;
		break;
	case 2:
		t.opcode = TRIGGER_HP_PERCENT_LT;
		t.i = 50;
		t.o.oids.id1 = OBJECT_MYSELF;
		break;
	case 3:
		t.opcode = TRIGGER_HP_PERCENT_LT;
		t.i = 25;
		t.o.oids.id1 = OBJECT_MYSELF;
		break;
	case 4:
		t.opcode = TRIGGER_HP_PERCENT_LT;
		t.i = 10;
		t.o.oids.id1 = OBJECT_MYSELF;
		break;
	case 5:
		t.opcode = TRIGGER_STATE_CHECK;
		t.i = STATE_HELPLESS;
		t.o.oids.id1 = OBJECT_MYSELF;
		break;
	case 6:
		t.opcode = TRIGGER_STATE_CHECK;
		t.i = STATE_POISONED;
		t.o.oids.id1 = OBJECT_MYSELF;
		break;
	case 7:
		t.opcode = TRIGGER_ATTACKED_BY;
		break;
	case 8:
		t.opcode = TRIGGER_PERSONAL_SPACE_DISTANCE;
		t.i = 4;
		break;
	case 9:
		t.opcode = TRIGGER_PERSONAL_SPACE_DISTANCE;
		t.i = 10;
		break;
	case 11:
		t.opcode = TRIGGER_TOOK_DAMAGE;
		break;
	default:
		break;
	}
	pConditionalSpell->t = t;

	switch (effect.nParam1) {
	case 0:
		o.oids.id1 = OBJECT_MYSELF;
		break;
	case 1:
		o.oids.id1 = OBJECT_LASTHITTER;
		break;
	case 2:
		o.oids.id1 = OBJECT_NEARESTENEMYOF;
		break;
	case 3:
		o.oids.id1 = OBJECT_NOTHING;
		break;
	default:
		break;
	}
	pConditionalSpell->oTarget = o;

	if (wParam3Low) {
		pConditionalSpell->dwFlags |= 0x1;
		if (!creTarget.m_PortraitIcons.Find((void*)0x4B, NULL)) {
			creTarget.m_PortraitIcons.AddTail((void*)0x4B);
		}
	}

	pConditionalSpell->eff = *this;
	
	STRREF strrefName;
	STRREF strrefDescription;
	g_pChitin->pGame->GetContingencyConditionTexts(&strrefName, &strrefDescription, (short)effect.nParam2);
	pConditionalSpell->strrefName = strrefName;

	g_pChitin->pGame->GetContingencyTargetTexts(&strrefName, &strrefDescription, (short)effect.nParam2);
	pConditionalSpell->strrefTarget = strrefName;

	creTarget.cdsCurrent.m_ConditionalSpells.AddTail(pConditionalSpell);

	if (effect.nParentResourceType == 1 && //spell
		effect.rParentResource.IsNotEmpty()) {
		CSpellProtection* pSpellProt = IENew CSpellProtection();
		pSpellProt->rSpell = effect.rParentResource;
		pSpellProt->strrefMsg = creTarget.GetCurrentObject().EnemyAlly <= EA_CONTROLLEDCUTOFF ? 0x806C : -1;
		creTarget.cdsCurrent.m_SpellProtections.AddTail(pSpellProt);
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
		bPurge = TRUE;
		break;
	}

	creTarget.cdsCurrent.m_RepeatingEffs.AddTail(pRepeat);

	return TRUE;
}

BOOL DETOUR_CEffectDisintegrate::DETOUR_ApplyEffect(CCreatureObject& creTarget) {
	Object& o = creTarget.GetCurrentObject();
	BOOL bMatch;
	switch (effect.nParam2) {
	case 2:
		if (o.EnemyAlly == effect.nParam1 || effect.nParam1 == 0) bMatch = TRUE;
		break;
	case 3:
		if (o.General == effect.nParam1 || effect.nParam1 == 0) bMatch = TRUE;
		break;
	case 4:
		if (o.Race == effect.nParam1 || effect.nParam1 == 0) bMatch = TRUE;
		break;
	case 5:
		{
			unsigned char nClass = o.GetClass();
			unsigned char nClass1;
			unsigned char nClass2;
			o.GetClasses(&nClass1, &nClass2);
			if (nClass1 != nClass2 &&
				!o.HasSubclass(nClass2, TRUE)) {
				nClass = nClass1;
			}
			if (nClass == effect.nParam1 || effect.nParam1 == 0) bMatch = TRUE;
			break;
		}
	case 6:
		if (o.Specific == effect.nParam1 || effect.nParam1 == 0) bMatch = TRUE;
		break;
	case 7:
		if (o.Gender == effect.nParam1 || effect.nParam1 == 0) bMatch = TRUE;
		break;
	case 8:
		if (
			(o.Alignment == effect.nParam1 || effect.nParam1 == 0) ||
			(effect.nParam1 == ALIGN_MASK_GOOD && (o.Alignment & 0xF) == ALIGN_MASK_GOOD) ||
			(effect.nParam2 == ALIGN_MASK_NEUTRAL && (o.Alignment & 0xF) == ALIGN_MASK_NEUTRAL) ||
			(effect.nParam2 == ALIGN_MASK_EVIL && (o.Alignment & 0xF) == ALIGN_MASK_EVIL) ||
			(effect.nParam2 == ALIGN_LAWFUL_MASK && (o.Alignment & 0xF0) == ALIGN_LAWFUL_MASK) ||
			(effect.nParam2 == ALIGN_NEUTRAL_MASK && (o.Alignment & 0xF0) == ALIGN_NEUTRAL_MASK) ||
			(effect.nParam2 == ALIGN_CHAOTIC_MASK && (o.Alignment & 0xF0) == ALIGN_CHAOTIC_MASK)
		) bMatch = TRUE;
		break;
	default:
		break;
	}

	if (bMatch) {
		CEffectInstantDeath* pEffect = new CEffectInstantDeath();
		pEffect->effect.nParam2 = EFFECTINSTANTDEATH_TYPE_DISINTEGRATE;
		pEffect->effect.ptSource = effect.ptSource;
		pEffect->eSource = eSource;
		pEffect->enum2 = enum2;
		creTarget.ApplyEffect(*pEffect, 1, TRUE, TRUE);
	}

	bPurge = TRUE;
	return TRUE;
}

BOOL DETOUR_CEffectRemoveProjectile::DETOUR_ApplyEffect(CCreatureObject& creTarget) {
	CArea* pArea = creTarget.pArea;
	if (pArea == NULL) return TRUE;
	
	switch (effect.nParam1) {
	case 1:
		{
			CMessageRemoveAreaAirEffectSpecific* pMsg = new CMessageRemoveAreaAirEffectSpecific();
			pMsg->rAreaName = pArea->rAreaName;
			pMsg->rResource = effect.rResource;
			g_pChitin->messages.Send(*pMsg, FALSE);
		}
		break;
	default:
		{
			CMessageRemoveAreaAirEffects* pMsg = IENew CMessageRemoveAreaAirEffects();
			pMsg->rAreaName = pArea->rAreaName;
			g_pChitin->messages.Send(*pMsg, FALSE);
		}
		break;
	}
	bPurge = 1;
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

BOOL DETOUR_CEffectAnimationRemoval::DETOUR_ApplyEffect(CCreatureObject& creTarget) {
	DWORD nSize = pRuleEx->m_nStats - 200;

	if (creTarget.cdsCurrent.animationRemoval) {
		int* pStatsEx = (int*)creTarget.cdsCurrent.animationRemoval;
		pStatsEx[0] = effect.nParam2;
	} else {
		LPCTSTR lpsz = "DETOUR_CEffectAnimationRemoval::DETOUR_ApplyEffect(): pStatsEx == NULL\r\n";
		L.timestamp();
		L.append(lpsz);
		console.write(lpsz);
	}

	return TRUE;
}

CEffectSetStat::CEffectSetStat(ITEM_EFFECT& data, POINT& ptSource, Enum eSource, int destX, int destY, BOOL bUseDice, Enum e2) \
	: CEffect(data, ptSource, eSource, destX, destY, bUseDice, e2) {}

CEffect& CEffectSetStat::Duplicate() {
	CEffectSetStat* pceff = new CEffectSetStat(ToItemEffect(), effect.ptSource, eSource, effect.ptDest.x, effect.ptDest.y, FALSE, ENUM_INVALID_INDEX);
	pceff->Unmarshal(effect);
	return *pceff;
}

BOOL CEffectSetStat::ApplyEffect(CCreatureObject& creTarget) {
	short nOpcode = effect.nParam2 & 0xFFFF;
	short nModType = effect.nParam2 >> 16;

	DWORD nSize = pRuleEx->m_nStats;

	if (nOpcode < 400) {
		LPCTSTR lpsz = "CEffectSetStat::ApplyEffect(): Tried to set a stat with index < 400 (expected 400-%d)\r\n";
		L.timestamp();
		L.append(lpsz, 1, nSize);
		console.write(lpsz, 1, nSize);
		return TRUE;
	}

	if (nOpcode > nSize) {
		LPCTSTR lpsz = "CEffectSetStat::ApplyEffect(): nOpcode out of bounds (expected maximum %d)\r\n";
		L.timestamp();
		L.append(lpsz, 1, nSize);
		console.write(lpsz, 1, nSize);
		return TRUE;
	}

	if (!creTarget.cdsCurrent.animationRemoval) {
		LPCTSTR lpsz = "CEffectSetStat::ApplyEffect(): creTarget.cdsCurrent.pStatsEx == NULL\r\n";
		L.timestamp();
		L.append(lpsz);
		console.write(lpsz);
		return TRUE;
	}

	int* pStatsEx = (int*)creTarget.cdsCurrent.animationRemoval;

	switch (nModType) {
	case 0: //sum
		pStatsEx[nOpcode - 200 - 1] += effect.nParam1;
		break;
	case 1: //set
		pStatsEx[nOpcode - 200 - 1] = effect.nParam1;
		break;
	case 2: //percent
		pStatsEx[nOpcode - 200 - 1] = pStatsEx[nOpcode - 200 - 1] * effect.nParam1 / 100;
		break;
	case 3: //multiply
		pStatsEx[nOpcode - 200 - 1] *= effect.nParam1;
		break;
	case 4: //divide
		if (effect.nParam1 != 0) {
			pStatsEx[nOpcode - 200 - 1] /= effect.nParam1;
		} else {
			LPCTSTR lpsz = "CEffectSetStat::ApplyEffect(): Tried to divide by zero\r\n";
			L.timestamp();
			L.append(lpsz, 1, nSize);
			console.write(lpsz, 1, nSize);
			return TRUE;
		}
		break;
	case 5: //modulus
		if (effect.nParam1 != 0) {
			pStatsEx[nOpcode - 200 - 1] %= effect.nParam1;
		} else {
			LPCTSTR lpsz = "CEffectSetStat::ApplyEffect(): Tried to divide by zero\r\n";
			L.timestamp();
			L.append(lpsz, 1, nSize);
			console.write(lpsz, 1, nSize);
			return TRUE;
		}
		break;
	case 6: //logical and
		pStatsEx[nOpcode - 200 - 1] = pStatsEx[nOpcode - 200 - 1] && effect.nParam1;
		break;
	case 7: //logical or
		pStatsEx[nOpcode - 200 - 1] = pStatsEx[nOpcode - 200 - 1] || effect.nParam1;
		break;
	case 8: //bitwise and
		pStatsEx[nOpcode - 200 - 1] = pStatsEx[nOpcode - 200 - 1] && effect.nParam1;
		break;
	case 9: //bitwise or
		pStatsEx[nOpcode - 200 - 1] = pStatsEx[nOpcode - 200 - 1] || effect.nParam1;
		break;
	case 10: //not
		pStatsEx[nOpcode - 200 - 1] = !pStatsEx[nOpcode - 200 - 1];
		break;
	default:
		LPCTSTR lpsz = "CEffectSetStat::ApplyEffect(): nModType %d invalid (expected 0-10)\r\n";
		L.timestamp();
		L.append(lpsz, 1, nModType);
		console.write(lpsz, 1, nModType);
		break;
	}

	return TRUE;
}
