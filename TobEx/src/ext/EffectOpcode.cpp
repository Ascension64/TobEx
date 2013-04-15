#include "EffectOpcode.h"

#include <math.h>

#include "stdafx.h"
#include "effopcode.h"
#include "effcore.h"
#include "engworld.h"
#include "infcursor.h"
#include "infgame.h"
#include "msgcore.h"
#include "optionsext.h"
#include "console.h"
#include "log.h"
#include "chitin.h"
#include "objcre.h"
#include "MessageExt.h"
#include "ObjectStats.h"
#include "InfGameCommon.h"

//CEffectAttacksPerRoundMod
DefineTrampMemberFunc(BOOL, CEffectAttacksPerRoundMod, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect, ApplyEffect, 0x5030F6);

BOOL DETOUR_CEffectAttacksPerRoundMod::DETOUR_ApplyEffect(CCreatureObject& creTarget) {
	if (0) IECString("DETOUR_CEffectAttacksPerRoundMod::DETOUR_ApplyEffect");

	switch (effect.nParam2) {
	case 0: //add
		if (effect.nTiming == 1) {
			float fNumAttacks = CDerivedStats_NumAttacksShortToFloat(creTarget.m_header.m_cNumberOfAttacksBase) + CDerivedStats_NumAttacksShortToFloat((short)(effect.nParam1));
			creTarget.m_header.m_cNumberOfAttacksBase = CDerivedStats_NumAttacksFloatToShort(fNumAttacks);

			bRefreshStats = TRUE;
			bPurge = TRUE;
		} else {
			float fNumAttacks = CDerivedStats_NumAttacksShortToFloat(creTarget.m_cdsDiff.numAttacks) + CDerivedStats_NumAttacksShortToFloat((short)(effect.nParam1));
			creTarget.m_cdsDiff.numAttacks = CDerivedStats_NumAttacksFloatToShort(fNumAttacks);

			bPurge = FALSE;
		}
		break;
	case 1: //set
		if (effect.nTiming == 1) {
			creTarget.m_header.m_cNumberOfAttacksBase = effect.nParam1;
			if (creTarget.m_header.m_cNumberOfAttacksBase > 10) creTarget.m_header.m_cNumberOfAttacksBase = 10;
			if (creTarget.m_header.m_cNumberOfAttacksBase < 0) creTarget.m_header.m_cNumberOfAttacksBase = 0;

			bRefreshStats = TRUE;
			bPurge = TRUE;
		} else {
			creTarget.m_cdsCurrent.numAttacks = effect.nParam1;
			if (creTarget.m_cdsCurrent.numAttacks > 10) creTarget.m_cdsCurrent.numAttacks = 10;
			if (creTarget.m_cdsCurrent.numAttacks < 0) creTarget.m_cdsCurrent.numAttacks = 0;

			bPurge = FALSE;
		}
		break;
	case 2: //percent
		if (effect.nTiming == 1) {
			float fNumAttacks = CDerivedStats_NumAttacksShortToFloat(creTarget.m_header.m_cNumberOfAttacksBase) * (float)effect.nParam1 / 100.0;
			fNumAttacks = floor(fNumAttacks * 2.0 + 0.5) / 2.0; //round to nearest 0.5
			creTarget.m_header.m_cNumberOfAttacksBase = CDerivedStats_NumAttacksFloatToShort(fNumAttacks);
			if (creTarget.m_header.m_cNumberOfAttacksBase < 1) creTarget.m_header.m_cNumberOfAttacksBase = 1;

			bRefreshStats = TRUE;
			bPurge = TRUE;
		} else {
			float fNumAttacks = CDerivedStats_NumAttacksShortToFloat(creTarget.m_header.m_cNumberOfAttacksBase) * (float)effect.nParam1 / 100.0;
			fNumAttacks = floor(fNumAttacks * 2.0 + 0.5) / 2.0; //round to nearest 0.5
			creTarget.m_cdsCurrent.numAttacks = CDerivedStats_NumAttacksFloatToShort(fNumAttacks);
			if (creTarget.m_cdsCurrent.numAttacks < 1) creTarget.m_cdsCurrent.numAttacks = 1;

			bPurge = FALSE;
		}
		break;
	default:
		LPCTSTR lpsz = "DETOUR_CEffectAttacksPerRoundMod::DETOUR_ApplyEffect(): invalid effect.nParam2 (%d)\r\n";
		console.writef(lpsz, effect.nParam2);
		L.timestamp();
		L.appendf(lpsz, effect.nParam2);
		bPurge = TRUE;
		break;
	}

	return TRUE;
}

//CEffectCharismaMod
DefineTrampMemberFunc(BOOL, CEffectCharismaMod, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect, ApplyEffect, 0x5046EC);

BOOL DETOUR_CEffectCharismaMod::DETOUR_ApplyEffect(CCreatureObject& creTarget) {
	if (0) IECString("DETOUR_CEffectCharismaMod::DETOUR_ApplyEffect");

	switch (effect.nParam2) {
	case 0: //sum
		if (effect.nTiming == 1) {
			creTarget.m_header.m_cCHRBase += effect.nParam1;
			creTarget.m_header.m_cCHRBase = min(creTarget.m_header.m_cCHRBase, 25);
			creTarget.m_header.m_cCHRBase = max(creTarget.m_header.m_cCHRBase, 0);
			bRefreshStats = TRUE;
			bPurge = TRUE;
		} else {
			creTarget.m_cdsDiff.charisma += effect.nParam1;
			bPurge = FALSE;
		}
		break;
	case 1: //set
		if (effect.nTiming == 1) {
			creTarget.m_header.m_cCHRBase = effect.nParam1;
			creTarget.m_header.m_cCHRBase = min(creTarget.m_header.m_cCHRBase, 25);
			creTarget.m_header.m_cCHRBase = max(creTarget.m_header.m_cCHRBase, 0);
			bRefreshStats = TRUE;
			bPurge = TRUE;
		} else {
			creTarget.m_cdsCurrent.charisma = effect.nParam1;
			creTarget.m_cdsCurrent.charisma = min(creTarget.m_cdsCurrent.charisma, 25);
			creTarget.m_cdsCurrent.charisma = max(creTarget.m_cdsCurrent.charisma, 0);
			bPurge = FALSE;
		}
		break;
	case 2:	//percentage
		if (effect.nTiming == 1) {
			creTarget.m_header.m_cCHRBase = creTarget.m_header.m_cCHRBase * effect.nParam1 / 100;
			creTarget.m_header.m_cCHRBase = min(creTarget.m_header.m_cCHRBase, 25);
			creTarget.m_header.m_cCHRBase = max(creTarget.m_header.m_cCHRBase, 0);
			bRefreshStats = TRUE;
			bPurge = TRUE;
		} else {
			creTarget.m_cdsCurrent.charisma = creTarget.m_cdsCurrent.charisma * effect.nParam1 / 100;
			creTarget.m_cdsCurrent.charisma = min(creTarget.m_cdsCurrent.charisma, 25);
			creTarget.m_cdsCurrent.charisma = max(creTarget.m_cdsCurrent.charisma, 0);
			bPurge = FALSE;
		}
		break;
	default:
		LPCTSTR lpsz = "DETOUR_CEffectCharisma::DETOUR_ApplyEffect(): invalid effect.nParam2 (%d)\r\n";
		console.writef(lpsz, effect.nParam2);
		L.timestamp();
		L.appendf(lpsz, effect.nParam2);
		bPurge = TRUE;
		break;
	}
	
	return TRUE;
}

//CEffectConstitutionMod
DefineTrampMemberFunc(BOOL, CEffectConstitutionMod, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect, ApplyEffect, 0x50515F);

BOOL DETOUR_CEffectConstitutionMod::DETOUR_ApplyEffect(CCreatureObject& creTarget) {
	if (0) IECString("DETOUR_CEffectConstitutionMod::DETOUR_ApplyEffect");

	switch (effect.nParam2) {
	case 0: //sum
		if (effect.nTiming == 1) {
			creTarget.m_header.m_cCONBase += effect.nParam1;
			creTarget.m_header.m_cCONBase = min(creTarget.m_header.m_cCONBase, 25);
			creTarget.m_header.m_cCONBase = max(creTarget.m_header.m_cCONBase, 0);
			bRefreshStats = TRUE;
			bPurge = TRUE;
		} else {
			creTarget.m_cdsDiff.constitution += effect.nParam1;
			bPurge = FALSE;
		}
		break;
	case 1: //set
		if (effect.nTiming == 1) {
			creTarget.m_header.m_cCONBase = effect.nParam1;
			creTarget.m_header.m_cCONBase = min(creTarget.m_header.m_cCONBase, 25);
			creTarget.m_header.m_cCONBase = max(creTarget.m_header.m_cCONBase, 0);
			bRefreshStats = TRUE;
			bPurge = TRUE;
		} else {
			creTarget.m_cdsCurrent.constitution = effect.nParam1;
			creTarget.m_cdsCurrent.constitution = min(creTarget.m_cdsCurrent.constitution, 25);
			creTarget.m_cdsCurrent.constitution = max(creTarget.m_cdsCurrent.constitution, 0);
			bPurge = FALSE;
		}
		break;
	case 2:	//percentage
		if (effect.nTiming == 1) {
			creTarget.m_header.m_cCONBase = creTarget.m_header.m_cCONBase * effect.nParam1 / 100;
			creTarget.m_header.m_cCONBase = min(creTarget.m_header.m_cCONBase, 25);
			creTarget.m_header.m_cCONBase = max(creTarget.m_header.m_cCONBase, 0);
			bRefreshStats = TRUE;
			bPurge = TRUE;
		} else {
			creTarget.m_cdsCurrent.constitution = creTarget.m_cdsCurrent.constitution * effect.nParam1 / 100;
			creTarget.m_cdsCurrent.constitution = min(creTarget.m_cdsCurrent.constitution, 25);
			creTarget.m_cdsCurrent.constitution = max(creTarget.m_cdsCurrent.constitution, 0);
			bPurge = FALSE;
		}
		break;
	default:
		LPCTSTR lpsz = "DETOUR_CEffectConstitution::DETOUR_ApplyEffect(): invalid effect.nParam2 (%d)\r\n";
		console.writef(lpsz, effect.nParam2);
		L.timestamp();
		L.appendf(lpsz, effect.nParam2);
		bPurge = TRUE;
		break;
	}
	
	return TRUE;
}

//CEffectDamage
DefineTrampMemberFunc(BOOL, CEffectDamage, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect, ApplyEffect, 0x505570);

BOOL DETOUR_CEffectDamage::DETOUR_ApplyEffect(CCreatureObject& creTarget) {
	if (0) IECString("DETOUR_CEffectDamage::DETOUR_ApplyEffect");

	if (!pGameOptionsEx->GetOption("Eff_ApplyConcCheckDamage") &&
		!pGameOptionsEx->GetOption("Eff_DamageFix") &&
		!pGameOptionsEx->GetOption("Eff_NoDamageNoSpellInterrupt") &&
		!pGameOptionsEx->GetOption("Eff_DamageAwaken")) {
		return (this->*Tramp_CEffectDamage_ApplyEffect)(creTarget);
	}

	if (creTarget.m_bUnmarshalling) return TRUE;

	creTarget.m_bForceReinitAnimColors = TRUE;
	int nPrevHP = creTarget.m_header.m_wHitPoints;
	
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
			nReturnVal = g_pChitin->pGame->m_GameObjectArray.GetShare(eSource, THREAD_ASYNCH, &pCre, INFINITE);
		} while (nReturnVal == OBJECT_SHARING || nReturnVal == OBJECT_DENYING);

		if (nReturnVal == OBJECT_SUCCESS) {
			wOrient = creTarget.GetOrientationTo(pCre->m_currentLoc);
			nReturnVal = g_pChitin->pGame->m_GameObjectArray.FreeShare(eSource, THREAD_ASYNCH, INFINITE);
		} else {
			wOrient = 0;
		}
	}

	if (creTarget.m_header.m_dwGeneralState & STATE_STONE_DEATH) {
		CEffectInstantDeath* pEff = new CEffectInstantDeath();
		pEff->effect.ptSource = effect.ptSource;
		pEff->eSource = eSource;
		pEff->enum2 = enum2;
		pEff->effect.nParam2 = EFFECTINSTANTDEATH_TYPE_STONE_EXPLODE;
		creTarget.ApplyEffect(*pEff, 1, TRUE, TRUE);
		bPurge = TRUE;
		return TRUE;
	}

	if (creTarget.m_header.m_dwGeneralState & STATE_FROZEN_DEATH) {
		CEffectInstantDeath* pEff = new CEffectInstantDeath();
		pEff->effect.ptSource = effect.ptSource;
		pEff->eSource = eSource;
		pEff->enum2 = enum2;
		pEff->effect.nParam2 = EFFECTINSTANTDEATH_TYPE_FROZEN_EXPLODE;
		creTarget.ApplyEffect(*pEff, 1, TRUE, TRUE);
		bPurge = TRUE;
		return TRUE;
	}

	if (creTarget.m_header.m_wHitPoints <= -10 ||
		creTarget.m_header.m_dwGeneralState & STATE_DEAD) {
		bPurge = TRUE;
		return TRUE;
	}

	int nDamageAmount = 0;
	for (int i = 0; i < effect.nDice; i++) {
		nDamageAmount += _DieRoll(effect.nDieSides, -creTarget.m_cdsPrevious.luck) + 1;
	}
	effect.nParam1 += nDamageAmount;
	
	BOOL bBaseDamageDone = (BOOL)effect.nParam1;
	short wAnimSeq = creTarget.wCurrentSequenceSimplified;

	unsigned int nDamageType = effect.nParam2 & 0xFFFF0000;
	int nDamageBehavior = effect.nParam2 & 0xFFFF;

	if (nDamageBehavior == EFFECTDAMAGE_BEHAVIOR_NORMAL) {
		if (pGameOptionsEx->GetOption("Engine_ExpandedStats")) {
			switch (nDamageType) {
			case DAMAGETYPE_ACID:
			case DAMAGETYPE_COLD:
			case DAMAGETYPE_CRUSHING:
			case DAMAGETYPE_STUNNING:
			case DAMAGETYPE_PIERCING:
			case DAMAGETYPE_SLASHING:
			case DAMAGETYPE_ELECTRICITY:
			case DAMAGETYPE_FIRE:
			case DAMAGETYPE_POISON:
			case DAMAGETYPE_MAGIC:
			case DAMAGETYPE_MISSILE:
			case DAMAGETYPE_MAGICFIRE:
			case DAMAGETYPE_MAGICCOLD:
				effect.nParam1 += effect.nParam1 * effect.nParam3 / 100;
				break;
			default:
				break;
			}
		}

		switch (nDamageType) {
		case DAMAGETYPE_ACID:
			effect.nParam1 -= effect.nParam1 * creTarget.m_cdsPrevious.resistAcid / 100;
			break;
		case DAMAGETYPE_COLD:
			effect.nParam1 -= effect.nParam1 * creTarget.m_cdsPrevious.resistCold / 100;
			break;
		case DAMAGETYPE_CRUSHING:
		case DAMAGETYPE_STUNNING:
			effect.nParam1 -= effect.nParam1 * creTarget.m_cdsPrevious.resistCrushing / 100;
			break;
		case DAMAGETYPE_PIERCING:
			effect.nParam1 -= effect.nParam1 * creTarget.m_cdsPrevious.resistPiercing / 100;
			break;
		case DAMAGETYPE_SLASHING:
			effect.nParam1 -= effect.nParam1 * creTarget.m_cdsPrevious.resistSlashing / 100;
			break;
		case DAMAGETYPE_ELECTRICITY:
			effect.nParam1 -= effect.nParam1 * creTarget.m_cdsPrevious.resistElectricity / 100;
			break;
		case DAMAGETYPE_FIRE:
			effect.nParam1 -= effect.nParam1 * creTarget.m_cdsPrevious.resistFire / 100;
			break;
		case DAMAGETYPE_POISON:
			effect.nParam1 -= effect.nParam1 * creTarget.m_cdsPrevious.resistPoison / 100;
			break;
		case DAMAGETYPE_MAGIC:
			effect.nParam1 -= effect.nParam1 * creTarget.m_cdsPrevious.resistMagicDamage / 100;
			break;
		case DAMAGETYPE_MISSILE:
			effect.nParam1 -= effect.nParam1 * creTarget.m_cdsPrevious.resistMissile / 100;
			break;
		case DAMAGETYPE_MAGICFIRE:
			effect.nParam1 -= effect.nParam1 * creTarget.m_cdsPrevious.resistMagicFire / 100;
			break;
		case DAMAGETYPE_MAGICCOLD:
			effect.nParam1 -= effect.nParam1 * creTarget.m_cdsPrevious.resistMagicCold / 100;
			break;
		default:
			break;
		}

		if (g_pChitin->pGame->GetCharacterPortraitNum(creTarget.e) != -1) {
			if (g_pChitin->cNetwork.bSessionOpen) {
				effect.nParam1 += effect.nParam1 * g_pChitin->pGame->m_GameOptions.m_nMPDifficultyMultiplier / 100;
			} else {
				effect.nParam1 += effect.nParam1 * g_pChitin->pGame->m_GameOptions.m_nDifficultyMultiplier / 100;
			}
			
			if (effect.nParam1 > creTarget.m_cdsPrevious.maxHP &&
				creTarget.m_cdsPrevious.maxHP < 14) {
				effect.nParam1 = creTarget.m_cdsPrevious.maxHP - 1;
			}
		}

	}

	BOOL bPreviousSpellInterruptState = creTarget.m_bInterruptSpellcasting;
	creTarget.m_bInterruptSpellcasting = TRUE;

	if (pGameOptionsEx->GetOption("Eff_ApplyConcCheckDamage")) {
		int nBaseDifficulty = 0;
		int nLevelMod = 0;

		if (creTarget.m_bCastingSpell && //set in ACTION_SPELL and ACTION_SPELL_POINT
			(creTarget.aCurrent.opcode == ACTION_SPELL ||
			creTarget.aCurrent.opcode == ACTION_SPELL_NO_DEC ||
			creTarget.aCurrent.opcode == ACTION_SPELL_POINT ||
			creTarget.aCurrent.opcode == ACTION_SPELL_NO_DEC)) {
			IECString sSpell;
			if (creTarget.aCurrent.GetSName1().IsEmpty()) {
				creTarget.GetSpellIdsName(creTarget.aCurrent.i, &sSpell);
			} else {
				sSpell = creTarget.aCurrent.GetSName1();
			}
	
			ResSplFile resSpell;
			resSpell.LoadResource(ResRef(sSpell), TRUE, TRUE);
			if (resSpell.bLoaded &&
				resSpell.name.IsNotEmpty()) {
				nLevelMod = resSpell.GetSpellLevel();
			}
		}

		int nDifficulty = nBaseDifficulty + nLevelMod + effect.nParam1;
		int nRoll = _DieRoll(20, creTarget.m_cdsPrevious.luck);
		if (nRoll >= nDifficulty) { //if pass
			creTarget.m_bInterruptSpellcasting = bPreviousSpellInterruptState;
		}
	}

	if (pGameOptionsEx->GetOption("Eff_NoDamageNoSpellInterrupt")) {
		if (nDamageBehavior == EFFECTDAMAGE_BEHAVIOR_NORMAL &&
			effect.nParam1 <= 0) {
			creTarget.m_bInterruptSpellcasting = bPreviousSpellInterruptState;
		}
	}

	if (creTarget.ePuppet != ENUM_INVALID_INDEX) {
		ENUM ePuppet = creTarget.ePuppet;
		CCreatureObject* pCrePuppet;
		char nReturnVal = g_pChitin->pGame->m_GameObjectArray.GetDeny(ePuppet, THREAD_ASYNCH, &pCrePuppet, INFINITE);
		if (nReturnVal == OBJECT_SUCCESS) {
			creTarget.ePuppet = ENUM_INVALID_INDEX;
			pCrePuppet->m_bRemoveFromArea = TRUE;
			nReturnVal = g_pChitin->pGame->m_GameObjectArray.FreeDeny(ePuppet, THREAD_ASYNCH, INFINITE);
		}
		creTarget.m_bForceRefresh = TRUE;
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
			g_pChitin->m_MessageHandler.AddMessage(*pMsg, FALSE);
		}
	} else {
		if (bBaseDamageDone) {
			CMessagePlaySoundset* pMsg = IENew CMessagePlaySoundset();
			pMsg->eTarget = creTarget.e;
			pMsg->eSource = creTarget.e;
			pMsg->nSoundIdx = SOUNDSET_DAMAGE;
			pMsg->bPrintToConsole = TRUE;
			pMsg->bLimitLength = TRUE;
			g_pChitin->m_MessageHandler.AddMessage(*pMsg, FALSE);
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
			g_pChitin->m_MessageHandler.AddMessage(*pMsg, FALSE);
		}
		creTarget.m_header.m_wHitPoints -= effect.nParam1;
		break;
	case EFFECTDAMAGE_BEHAVIOR_SETVALUE:
		creTarget.m_header.m_wHitPoints = effect.nParam1 < creTarget.m_cdsPrevious.maxHP ? effect.nParam1 : creTarget.m_cdsPrevious.maxHP;
		break;
	case EFFECTDAMAGE_BEHAVIOR_SETPERCENT:
		creTarget.m_header.m_wHitPoints = creTarget.m_header.m_wHitPoints * effect.nParam1 / 100;
		break;
	case EFFECTDAMAGE_BEHAVIOR_LOSEPERCENT:
		creTarget.m_header.m_wHitPoints -= creTarget.m_cdsPrevious.maxHP * effect.nParam1 / 100;
		break;
	default:
		break;
	}

	creTarget.m_bShowDamageArrow = TRUE;
	creTarget.m_wDamagePortraitFlashTimer = 128;
	creTarget.m_wDamageArrowTimer = 128;

	if (g_pChitin->pCursor->nCurrentCursorIdx == CURSOR_TOOLTIP_SCROLL &&
		creTarget.pArea != NULL &&
		creTarget.pArea->eCursorTarget == creTarget.e &&
		g_pChitin->pGame->GetCharacterPortraitNum(creTarget.e) != -1) {
		creTarget.UpdateHPStatusTooltip(*g_pChitin->pCursor->pCtrlTarget);
	}

	PlayHitSound(nDamageType, creTarget);

	switch (nDamageType) {
	case DAMAGETYPE_PIERCING:
	case DAMAGETYPE_CRUSHING:
	case DAMAGETYPE_SLASHING:
	case DAMAGETYPE_MISSILE:
		if (nPrevHP - creTarget.m_header.m_wHitPoints < 6) {
			creTarget.CreateGore(0, wOrient, PARTICLETYPE_BLOOD_SMALL);
		} else {
			creTarget.CreateGore(0, wOrient, PARTICLETYPE_BLOOD_MEDIUM);
		}
		break;
	case DAMAGETYPE_COLD:
		PlaySound(ResRef("HIT_06"), creTarget);
		creTarget.StartSpriteEffect(GORETYPE_COLD, 0, (nPrevHP - creTarget.m_header.m_wHitPoints) * 3);
		break;
	case DAMAGETYPE_MAGICCOLD: //omitted in original code
		if (pGameOptionsEx->GetOption("Eff_DamageFix")) {
			PlaySound(ResRef("HIT_06"), creTarget);
			creTarget.StartSpriteEffect(GORETYPE_COLD, 0, (nPrevHP - creTarget.m_header.m_wHitPoints) * 3);
		}
		break;
	case DAMAGETYPE_FIRE:
	case DAMAGETYPE_MAGICFIRE:
		PlaySound(ResRef("FIRE"), creTarget);
		creTarget.StartSpriteEffect(GORETYPE_FIRE, 0, (nPrevHP - creTarget.m_header.m_wHitPoints) * 3);
		break;
	case DAMAGETYPE_ELECTRICITY:
		PlaySound(ResRef("HIT_05"), creTarget);
		creTarget.StartSpriteEffect(GORETYPE_SHOCK, 0, (nPrevHP - creTarget.m_header.m_wHitPoints) * 3);
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
		if (pGameOptionsEx->GetOption("Eff_NoDamageNoSpellInterrupt") &&
			nDamageBehavior == EFFECTDAMAGE_BEHAVIOR_NORMAL &&
			effect.nParam1 <= 0 &&
			(wAnimSeq == SEQ_CONJURE || wAnimSeq == SEQ_CAST)) {
		} else {
			creTarget.SetAnimationSequence(SEQ_DAMAGE);
		}
	}

	if (creTarget.m_cdsPrevious.minHitPoints > 0 &&
		creTarget.m_header.m_wHitPoints <= 0) {
		creTarget.m_header.m_wHitPoints = creTarget.m_cdsPrevious.minHitPoints;
	}

	bool bStunned = false; //added to prevent Awaken on Damage to reverse the unconsciousness effect of fist below

	if (creTarget.m_header.m_wHitPoints <= 0) {
		if (g_pChitin->pGame->GetCharacterPortraitNum(creTarget.e) != -1 &&
			creTarget.m_header.m_wHitPoints > -20) {
			creTarget.m_header.m_wHitPoints = 0;
		}
		CEffectInstantDeath* pEff = new CEffectInstantDeath();
		pEff->eSource = eSource;
		pEff->enum2 = enum2;

		switch (nDamageType) {
		case DAMAGETYPE_STUNNING:
			{
			bStunned = true;

			delete pEff;
			pEff = NULL;
			ItmFileEffect* pIF = new ItmFileEffect;
			ClearItemEffect(*pIF, CEFFECT_OPCODE_UNCONSCIOUSNESS);
			pIF->m_cTiming = 0;
			pIF->m_dwDuration = (1 - creTarget.m_header.m_wHitPoints) * 15;
			CPoint ptSrc;
			ptSrc.x = -1;
			ptSrc.y = -1;
			CPoint ptDest;
			ptDest.x = -1;
			ptDest.y = -1;

			pEff = (CEffectInstantDeath*)&DecodeEffect(*pIF, ptSrc, ENUM_INVALID_INDEX, ptDest, ENUM_INVALID_INDEX);
			pEff->effect.ptSource = creTarget.m_currentLoc;
			pEff->eSource = creTarget.e;
			pEff->enum2 = ENUM_INVALID_INDEX;
			pEff->effect.ptDest = effect.ptDest;

			if (pGameOptionsEx->GetOption("Eff_DamageFix")) {
				delete pIF;
			}

			}
			
			creTarget.m_header.m_wHitPoints = 1;

			break;
		case DAMAGETYPE_ACID:
			pEff->effect.nParam2 = creTarget.m_header.m_wHitPoints < -5 ? EFFECTINSTANTDEATH_TYPE_ACID : EFFECTINSTANTDEATH_TYPE_NORMAL;
			break;
		case DAMAGETYPE_COLD:
		case DAMAGETYPE_MAGICCOLD:
			pEff->effect.nParam2 = creTarget.m_header.m_wHitPoints < -5 ? EFFECTINSTANTDEATH_TYPE_FROZEN : EFFECTINSTANTDEATH_TYPE_NORMAL;
			break;
		case DAMAGETYPE_CRUSHING:
		case DAMAGETYPE_PIERCING:
		case DAMAGETYPE_SLASHING:
			pEff->effect.nParam2 = creTarget.m_header.m_wHitPoints < -8 ? EFFECTINSTANTDEATH_TYPE_CHUNKED : EFFECTINSTANTDEATH_TYPE_NORMAL;
			break;
		case DAMAGETYPE_ELECTRICITY:
			pEff->effect.nParam2 = creTarget.m_header.m_wHitPoints < -5 ? EFFECTINSTANTDEATH_TYPE_ELECTRIC : EFFECTINSTANTDEATH_TYPE_NORMAL;
			break;
		case DAMAGETYPE_FIRE:
			pEff->effect.nParam2 = creTarget.m_header.m_wHitPoints < -5 ? EFFECTINSTANTDEATH_TYPE_BURNING : EFFECTINSTANTDEATH_TYPE_NORMAL;
			break;
		case DAMAGETYPE_MAGICFIRE: //omitted in original code
			if (pGameOptionsEx->GetOption("Eff_DamageFix")) {
				pEff->effect.nParam2 = creTarget.m_header.m_wHitPoints < -5 ? EFFECTINSTANTDEATH_TYPE_BURNING : EFFECTINSTANTDEATH_TYPE_NORMAL;
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

	if (pGameOptionsEx->GetOption("Eff_DamageAwaken") && !bStunned) {
		creTarget.m_header.m_dwGeneralState &= ~STATE_SLEEPING;
		creTarget.m_cdsCurrent.stateFlags &= ~STATE_SLEEPING;
		creTarget.m_EffectsEquipped.RemoveEffect(creTarget, CEFFECT_OPCODE_UNCONSCIOUSNESS, creTarget.m_EffectsEquipped.posItrPrev, -1, ResRef(), FALSE);
		creTarget.m_TimedEffectList.RemoveEffect(creTarget, CEFFECT_OPCODE_UNCONSCIOUSNESS, creTarget.m_TimedEffectList.posItrPrev, -1, ResRef(), FALSE);
	}

	int n = creTarget.m_cdsPrevious.maxHP < 1 ? 1 : creTarget.m_cdsPrevious.maxHP;
	if (nPrevHP * 100 / n > *g_pHPHurtThresholdPercent &&
		creTarget.m_header.m_wHitPoints * 100 / n < *g_pHPHurtThresholdPercent &&
		creTarget.m_header.m_wHitPoints * 100 / n > 0) { //went from above threshold to below threshold
		CMessagePlaySoundset* pMsg = IENew CMessagePlaySoundset();
		pMsg->eTarget = creTarget.e;
		pMsg->eSource = creTarget.e;
		pMsg->nSoundIdx = SOUNDSET_HURT;
		pMsg->bPrintToConsole = TRUE;
		pMsg->bLimitLength = FALSE;
		g_pChitin->m_MessageHandler.AddMessage(*pMsg, FALSE);

		creTarget.SetAutoPauseInfo(8);
	} else if (creTarget.m_header.m_wHitPoints * 100 / n < *g_pHPHurtThresholdPercent &&
		creTarget.m_header.m_wHitPoints * 100 / n > 0 &&
		IERand() * 10 >> 15 == 0) { //was below threshold and still below threshold, with 1/16 chance
		CMessagePlaySoundset* pMsg = IENew CMessagePlaySoundset();
		pMsg->eTarget = creTarget.e;
		pMsg->eSource = creTarget.e;
		pMsg->nSoundIdx = SOUNDSET_HURT;
		pMsg->bPrintToConsole = TRUE;
		pMsg->bLimitLength = FALSE;
		g_pChitin->m_MessageHandler.AddMessage(*pMsg, FALSE);

		creTarget.SetAutoPauseInfo(8);
	}

	bPurge = TRUE;
	return TRUE;
};

//CEffectDexterityMod
DefineTrampMemberFunc(BOOL, CEffectDexterityMod, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect, ApplyEffect, 0x510DCF);

BOOL DETOUR_CEffectDexterityMod::DETOUR_ApplyEffect(CCreatureObject& creTarget) {
	if (0) IECString("DETOUR_CEffectDexterityMod::DETOUR_ApplyEffect");

	//case 0, 1, 2, default as original
	switch (effect.nParam2) {
	case 0: //sum
		if (effect.nTiming == 1) {
			creTarget.m_header.m_cDEXBase += effect.nParam1;
			creTarget.m_header.m_cDEXBase = min(creTarget.m_header.m_cDEXBase, 25);
			creTarget.m_header.m_cDEXBase = max(creTarget.m_header.m_cDEXBase, 0);
			bRefreshStats = TRUE;
			bPurge = TRUE;
		} else {
			creTarget.m_cdsDiff.dexterity += effect.nParam1;
			bPurge = FALSE;
		}
		break;
	case 1: //set
		if (effect.nTiming == 1) {
			creTarget.m_header.m_cDEXBase = effect.nParam1;
			creTarget.m_header.m_cDEXBase = min(creTarget.m_header.m_cDEXBase, 25);
			creTarget.m_header.m_cDEXBase = max(creTarget.m_header.m_cDEXBase, 0);
			bRefreshStats = TRUE;
			bPurge = TRUE;
		} else {
			creTarget.m_cdsCurrent.dexterity = effect.nParam1;
			creTarget.m_cdsCurrent.dexterity = min(creTarget.m_cdsCurrent.dexterity, 25);
			creTarget.m_cdsCurrent.dexterity = max(creTarget.m_cdsCurrent.dexterity, 0);
			bPurge = FALSE;
		}
		break;
	case 2:	//percentage
		if (effect.nTiming == 1) {
			creTarget.m_header.m_cDEXBase = creTarget.m_header.m_cDEXBase * effect.nParam1 / 100;
			creTarget.m_header.m_cDEXBase = min(creTarget.m_header.m_cDEXBase, 25);
			creTarget.m_header.m_cDEXBase = max(creTarget.m_header.m_cDEXBase, 0);
			bRefreshStats = TRUE;
			bPurge = TRUE;
		} else {
			creTarget.m_cdsCurrent.dexterity = creTarget.m_header.m_cDEXBase * effect.nParam1 / 100;
			creTarget.m_cdsCurrent.dexterity = min(creTarget.m_cdsCurrent.dexterity, 25);
			creTarget.m_cdsCurrent.dexterity = max(creTarget.m_cdsCurrent.dexterity, 0);
			bPurge = FALSE;
		}
		break;
	case 3: //IWD1/P&P Cat's Grace spell
		if (!pRuleEx->m_ClassSpellAbility.m_2da.bLoaded) {
			LPCTSTR lpsz = "DETOUR_CEffectDexterityMod::DETOUR_ApplyEffect(): CLSSPLAB.2DA not found\r\n";
			console.write(lpsz);
			L.timestamp();
			L.append(lpsz);
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

				wParam1High = _DieRoll(nDieSides, 0) + 1;
				effect.nParam1 = wParam1Low | (wParam1High << 16);
			}

			if (effect.nTiming == 1) {
				creTarget.m_header.m_cDEXBase += wParam1High;
				creTarget.m_header.m_cDEXBase = min(creTarget.m_header.m_cDEXBase, 20);
				creTarget.m_header.m_cDEXBase = max(creTarget.m_header.m_cDEXBase, 0);
				bRefreshStats = TRUE;
				bPurge = TRUE;
			} else {
				creTarget.m_cdsCurrent.dexterity += wParam1High;
				creTarget.m_cdsCurrent.dexterity = min(creTarget.m_cdsCurrent.dexterity, 20);
				creTarget.m_cdsCurrent.dexterity = max(creTarget.m_cdsCurrent.dexterity, 0);
				bPurge = FALSE;
			}
		}
		break;
	default:
		LPCTSTR lpsz = "DETOUR_CEffectDexterityMod::DETOUR_ApplyEffect(): invalid effect.nParam2 (%d)\r\n";
		console.writef(lpsz, effect.nParam2);
		L.timestamp();
		L.appendf(lpsz, effect.nParam2);
		bPurge = TRUE;
		break;
	}

	return TRUE;
}

//CEffectIntelligenceMod
DefineTrampMemberFunc(BOOL, CEffectIntelligenceMod, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect, ApplyEffect, 0x5121DB);

BOOL DETOUR_CEffectIntelligenceMod::DETOUR_ApplyEffect(CCreatureObject& creTarget) {
	if (0) IECString("DETOUR_CEffectIntelligenceMod::DETOUR_ApplyEffect");

	switch (effect.nParam2) {
	case 0: //sum
		if (effect.nTiming == 1) {
			creTarget.m_header.m_cINTBase += effect.nParam1;
			creTarget.m_header.m_cINTBase = min(creTarget.m_header.m_cINTBase, 25);
			creTarget.m_header.m_cINTBase = max(creTarget.m_header.m_cINTBase, 0);
			bRefreshStats = TRUE;
			bPurge = TRUE;
		} else {
			creTarget.m_cdsDiff.intelligence += effect.nParam1;
			bPurge = FALSE;
		}
		break;
	case 1: //set
		if (effect.nTiming == 1) {
			creTarget.m_header.m_cINTBase = effect.nParam1;
			creTarget.m_header.m_cINTBase = min(creTarget.m_header.m_cINTBase, 25);
			creTarget.m_header.m_cINTBase = max(creTarget.m_header.m_cINTBase, 0);
			bRefreshStats = TRUE;
			bPurge = TRUE;
		} else {
			creTarget.m_cdsCurrent.intelligence = effect.nParam1;
			creTarget.m_cdsCurrent.intelligence = min(creTarget.m_cdsCurrent.intelligence, 25);
			creTarget.m_cdsCurrent.intelligence = max(creTarget.m_cdsCurrent.intelligence, 0);
			bPurge = FALSE;
		}
		break;
	case 2:	//percentage
		if (effect.nTiming == 1) {
			creTarget.m_header.m_cINTBase = creTarget.m_header.m_cINTBase * effect.nParam1 / 100;
			creTarget.m_header.m_cINTBase = min(creTarget.m_header.m_cINTBase, 25);
			creTarget.m_header.m_cINTBase = max(creTarget.m_header.m_cINTBase, 0);
			bRefreshStats = TRUE;
			bPurge = TRUE;
		} else {
			creTarget.m_cdsCurrent.intelligence = creTarget.m_cdsCurrent.intelligence * effect.nParam1 / 100;
			creTarget.m_cdsCurrent.intelligence = min(creTarget.m_cdsCurrent.intelligence, 25);
			creTarget.m_cdsCurrent.intelligence = max(creTarget.m_cdsCurrent.intelligence, 0);
			bPurge = FALSE;
		}
		break;
	default:
		LPCTSTR lpsz = "DETOUR_CEffectIntelligence::DETOUR_ApplyEffect(): invalid effect.nParam2 (%d)\r\n";
		console.writef(lpsz, effect.nParam2);
		L.timestamp();
		L.appendf(lpsz, effect.nParam2);
		bPurge = TRUE;
		break;
	}
	
	return TRUE;
}

//CEffectLoreMod
DefineTrampMemberFunc(BOOL, CEffectLoreMod, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect, ApplyEffect, 0x512733);

BOOL DETOUR_CEffectLoreMod::DETOUR_ApplyEffect(CCreatureObject& creTarget) {
	if (0) IECString("DETOUR_CEffectLoreMod::DETOUR_ApplyEffect");

	switch (effect.nParam2) {
	case 0: //sum
		if (effect.nTiming == 1) {
			creTarget.m_header.m_cLoreBase += effect.nParam1;
			creTarget.m_header.m_cLoreBase = min(creTarget.m_header.m_cLoreBase, 100);
			creTarget.m_header.m_cLoreBase = max(creTarget.m_header.m_cLoreBase, 0);
			bRefreshStats = TRUE;
			bPurge = TRUE;
		} else {
			creTarget.m_cdsDiff.lore += effect.nParam1;
			bPurge = FALSE;
		}
		break;
	case 1: //set
		if (effect.nTiming == 1) {
			creTarget.m_header.m_cLoreBase = effect.nParam1;
			creTarget.m_header.m_cLoreBase = min(creTarget.m_header.m_cLoreBase, 100);
			creTarget.m_header.m_cLoreBase = max(creTarget.m_header.m_cLoreBase, 0);
			bRefreshStats = TRUE;
			bPurge = TRUE;
		} else {
			creTarget.m_cdsCurrent.lore = effect.nParam1;
			creTarget.m_cdsCurrent.lore = min(creTarget.m_cdsCurrent.lore, 100);
			creTarget.m_cdsCurrent.lore = max(creTarget.m_cdsCurrent.lore, 0);
			bPurge = FALSE;
		}
		break;
	case 2:	//percentage
		if (effect.nTiming == 1) {
			creTarget.m_header.m_cLoreBase = creTarget.m_header.m_cLoreBase * effect.nParam1 / 100;
			creTarget.m_header.m_cLoreBase = min(creTarget.m_header.m_cLoreBase, 100);
			creTarget.m_header.m_cLoreBase = max(creTarget.m_header.m_cLoreBase, 0);
			bRefreshStats = TRUE;
			bPurge = TRUE;
		} else {
			creTarget.m_cdsCurrent.lore = creTarget.m_cdsCurrent.lore * effect.nParam1 / 100;
			creTarget.m_cdsCurrent.lore = min(creTarget.m_cdsCurrent.lore, 100);
			creTarget.m_cdsCurrent.lore = max(creTarget.m_cdsCurrent.lore, 0);
			bPurge = FALSE;
		}
		break;
	default:
		LPCTSTR lpsz = "DETOUR_CEffectLore::DETOUR_ApplyEffect(): invalid effect.nParam2 (%d)\r\n";
		console.writef(lpsz, effect.nParam2);
		L.timestamp();
		L.appendf(lpsz, effect.nParam2);
		bPurge = TRUE;
		break;
	}
	
	return TRUE;
}

//CEffectLuckMod
DefineTrampMemberFunc(BOOL, CEffectLuckMod, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect, ApplyEffect, 0x5129F3);

BOOL DETOUR_CEffectLuckMod::DETOUR_ApplyEffect(CCreatureObject& creTarget) {
	if (0) IECString("DETOUR_CEffectLuckMod::DETOUR_ApplyEffect");

	switch (effect.nParam2) {
	case 0:
		if (effect.nTiming == 1) { //permanent
			creTarget.m_header.m_cLuckBase += effect.nParam1;
			creTarget.m_header.m_cLuckBase = min(20, creTarget.m_header.m_cLuckBase);
			creTarget.m_header.m_cLuckBase = max(-20, creTarget.m_header.m_cLuckBase);
			bRefreshStats = TRUE;
			bPurge = TRUE;
		} else {
			creTarget.m_cdsDiff.luck += effect.nParam1;
			bPurge = FALSE;
		}
		break;
	case 1:
		if (effect.nTiming == 1) { //permanent
			creTarget.m_header.m_cLuckBase = effect.nParam1;
			creTarget.m_header.m_cLuckBase = min(20, creTarget.m_header.m_cLuckBase);
			creTarget.m_header.m_cLuckBase = max(-20, creTarget.m_header.m_cLuckBase);
			bRefreshStats = TRUE;
			bPurge = TRUE;
		} else {
			creTarget.m_cdsCurrent.luck = effect.nParam1;
			creTarget.m_cdsCurrent.luck = min(20, creTarget.m_cdsCurrent.luck);
			creTarget.m_cdsCurrent.luck = max(-20, creTarget.m_cdsCurrent.luck);
			bPurge = FALSE;
		}
		break;
	case 2:
		if (effect.nTiming == 1) { //permanent
			creTarget.m_header.m_cLuckBase = creTarget.m_header.m_cLuckBase * effect.nParam1 / 100;
			creTarget.m_header.m_cLuckBase = min(20, creTarget.m_header.m_cLuckBase);
			creTarget.m_header.m_cLuckBase = max(-20, creTarget.m_header.m_cLuckBase);
			bRefreshStats = TRUE;
			bPurge = TRUE;
		} else {
			creTarget.m_cdsCurrent.luck = creTarget.m_header.m_cLuckBase * effect.nParam1 / 100;
			creTarget.m_cdsCurrent.luck = min(20, creTarget.m_cdsCurrent.luck);
			creTarget.m_cdsCurrent.luck = max(-20, creTarget.m_cdsCurrent.luck);
			bPurge = FALSE;
		}
		break;
	case 3: //instantaneous sum
		if (effect.nTiming == 1) { //permanent
			creTarget.m_header.m_cLuckBase += effect.nParam1;
			creTarget.m_header.m_cLuckBase = min(20, creTarget.m_header.m_cLuckBase);
			creTarget.m_header.m_cLuckBase = max(-20, creTarget.m_header.m_cLuckBase);
			bRefreshStats = TRUE;
			bPurge = TRUE;
		} else {
			creTarget.m_cdsCurrent.luck += effect.nParam1;
			creTarget.m_cdsCurrent.luck = min(20, creTarget.m_cdsCurrent.luck);
			creTarget.m_cdsCurrent.luck = max(-20, creTarget.m_cdsCurrent.luck);
			bPurge = FALSE;
		}
		break;
	default:
		LPCTSTR lpsz = "DETOUR_CEffectLuckMod::DETOUR_ApplyEffect(): invalid effect.nParam2 (%d)\r\n";
		L.timestamp();
		L.append(lpsz);
		console.write(lpsz);
		break;
	}

	return TRUE;
}

//CEffectPoison
DefineTrampMemberFunc(BOOL, CEffectPoison, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect, ApplyEffect, 0x513024);

BOOL DETOUR_CEffectPoison::DETOUR_ApplyEffect(CCreatureObject& creTarget) {
	if (0) IECString("DETOUR_CEffectPoison::DETOUR_ApplyEffect");

	CRepeatingPoison* pRepeat = IENew CRepeatingPoison();
	pRepeat->eSource = eSource;

	short wParam2Low = effect.nParam2 & 0xFFFF;
	short wParam2High = effect.nParam2 >> 16;
	creTarget.m_cdsCurrent.stateFlags |= STATE_POISONED;

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
		pRepeat->wPostDelayDuration = creTarget.m_header.m_wHitPoints * effect.nParam1 / 100;
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
		console.writef(lpsz, wParam2Low);
		L.timestamp();
		L.appendf(lpsz, wParam2Low);
		bPurge = TRUE;
		break;
	}

	creTarget.m_cdsCurrent.m_RepeatingEffs.AddTail(pRepeat);

	return TRUE;
}

//CEffectSaveVsDeathMod
DefineTrampMemberFunc(BOOL, CEffectSaveVsDeathMod, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect, ApplyEffect, 0x514B87);

BOOL DETOUR_CEffectSaveVsDeathMod::DETOUR_ApplyEffect(CCreatureObject& creTarget) {
	if (0) IECString("DETOUR_CEffectSaveVsDeathMod::DETOUR_ApplyEffect");

	switch (effect.nParam2) {
	case 0: //sum
		if (effect.nTiming == 1) { //permanent
			creTarget.m_header.m_cSaveVsDeathBase -= effect.nParam1;
			creTarget.m_header.m_cSaveVsDeathBase = min(20, creTarget.m_header.m_cSaveVsDeathBase);
			creTarget.m_header.m_cSaveVsDeathBase = max(-20, creTarget.m_header.m_cSaveVsDeathBase);
			bRefreshStats = TRUE;
			bPurge = TRUE;
		} else {
			creTarget.m_cdsDiff.saveDeath -= effect.nParam1;
			bPurge = FALSE;
		}
		break;
	case 1: //set
		if (effect.nTiming == 1) { //permanent
			creTarget.m_header.m_cSaveVsDeathBase = effect.nParam1;
			creTarget.m_header.m_cSaveVsDeathBase = min(20, creTarget.m_header.m_cSaveVsDeathBase);
			creTarget.m_header.m_cSaveVsDeathBase = max(-20, creTarget.m_header.m_cSaveVsDeathBase);
			bRefreshStats = TRUE;
			bPurge = TRUE;
		} else {
			creTarget.m_cdsCurrent.saveDeath = effect.nParam1;
			creTarget.m_cdsCurrent.saveDeath = min(20, creTarget.m_cdsCurrent.saveDeath);
			creTarget.m_cdsCurrent.saveDeath = max(-20, creTarget.m_cdsCurrent.saveDeath);
			bPurge = FALSE;
		}
		break;
	case 2: //percentage
		if (effect.nTiming == 1) { //permanent
			creTarget.m_header.m_cSaveVsDeathBase = creTarget.m_header.m_cSaveVsDeathBase * effect.nParam1 / 100;
			creTarget.m_header.m_cSaveVsDeathBase = min(20, creTarget.m_header.m_cSaveVsDeathBase);
			creTarget.m_header.m_cSaveVsDeathBase = max(-20, creTarget.m_header.m_cSaveVsDeathBase);
			bRefreshStats = TRUE;
			bPurge = TRUE;
		} else {
			creTarget.m_cdsCurrent.saveDeath = creTarget.m_header.m_cSaveVsDeathBase * effect.nParam1 / 100;
			creTarget.m_cdsCurrent.saveDeath = min(20, creTarget.m_cdsCurrent.saveDeath);
			creTarget.m_cdsCurrent.saveDeath = max(-20, creTarget.m_cdsCurrent.saveDeath);
			bPurge = FALSE;
		}
		break;
	case 3: //instantaneous sum
		if (effect.nTiming == 1) { //permanent
			creTarget.m_header.m_cSaveVsDeathBase -= effect.nParam1;
			creTarget.m_header.m_cSaveVsDeathBase = min(20, creTarget.m_header.m_cSaveVsDeathBase);
			creTarget.m_header.m_cSaveVsDeathBase = max(-20, creTarget.m_header.m_cSaveVsDeathBase);
			bRefreshStats = TRUE;
			bPurge = TRUE;
		} else {
			creTarget.m_cdsCurrent.saveDeath -= effect.nParam1;
			creTarget.m_cdsCurrent.saveDeath = min(20, creTarget.m_cdsCurrent.saveDeath);
			creTarget.m_cdsCurrent.saveDeath = max(-20, creTarget.m_cdsCurrent.saveDeath);
			bPurge = FALSE;
		}
		break;
	default:
		LPCTSTR lpsz = "DETOUR_CEffectSaveVsDeathMod::DETOUR_ApplyEffect(): invalid effect.nParam2 (%d)\r\n";
		L.timestamp();
		L.append(lpsz);
		console.write(lpsz);
		break;
	}

	return TRUE;
}

//CEffectSaveVsWandsMod
DefineTrampMemberFunc(BOOL, CEffectSaveVsWandsMod, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect, ApplyEffect, 0x514E4C);

BOOL DETOUR_CEffectSaveVsWandsMod::DETOUR_ApplyEffect(CCreatureObject& creTarget) {
	if (0) IECString("DETOUR_CEffectSaveVsWandsMod::DETOUR_ApplyEffect");

	switch (effect.nParam2) {
	case 0:
		if (effect.nTiming == 1) { //permanent
			creTarget.m_header.m_cSaveVsWandsBase -= effect.nParam1;
			creTarget.m_header.m_cSaveVsWandsBase = min(20, creTarget.m_header.m_cSaveVsWandsBase);
			creTarget.m_header.m_cSaveVsWandsBase = max(-20, creTarget.m_header.m_cSaveVsWandsBase);
			bRefreshStats = TRUE;
			bPurge = TRUE;
		} else {
			creTarget.m_cdsDiff.saveWands -= effect.nParam1;
			bPurge = FALSE;
		}
		break;
	case 1:
		if (effect.nTiming == 1) { //permanent
			creTarget.m_header.m_cSaveVsWandsBase = effect.nParam1;
			creTarget.m_header.m_cSaveVsWandsBase = min(20, creTarget.m_header.m_cSaveVsWandsBase);
			creTarget.m_header.m_cSaveVsWandsBase = max(-20, creTarget.m_header.m_cSaveVsWandsBase);
			bRefreshStats = TRUE;
			bPurge = TRUE;
		} else {
			creTarget.m_cdsCurrent.saveWands = effect.nParam1;
			creTarget.m_cdsCurrent.saveWands = min(20, creTarget.m_cdsCurrent.saveWands);
			creTarget.m_cdsCurrent.saveWands = max(-20, creTarget.m_cdsCurrent.saveWands);
			bPurge = FALSE;
		}
		break;
	case 2:
		if (effect.nTiming == 1) { //permanent
			creTarget.m_header.m_cSaveVsWandsBase = creTarget.m_header.m_cSaveVsWandsBase * effect.nParam1 / 100;
			creTarget.m_header.m_cSaveVsWandsBase = min(20, creTarget.m_header.m_cSaveVsWandsBase);
			creTarget.m_header.m_cSaveVsWandsBase = max(-20, creTarget.m_header.m_cSaveVsWandsBase);
			bRefreshStats = TRUE;
			bPurge = TRUE;
		} else {
			creTarget.m_cdsCurrent.saveWands = creTarget.m_header.m_cSaveVsWandsBase * effect.nParam1 / 100;
			creTarget.m_cdsCurrent.saveWands = min(20, creTarget.m_cdsCurrent.saveWands);
			creTarget.m_cdsCurrent.saveWands = max(-20, creTarget.m_cdsCurrent.saveWands);
			bPurge = FALSE;
		}
		break;
	case 3: //instantaneous sum
		if (effect.nTiming == 1) { //permanent
			creTarget.m_header.m_cSaveVsWandsBase -= effect.nParam1;
			creTarget.m_header.m_cSaveVsWandsBase = min(20, creTarget.m_header.m_cSaveVsWandsBase);
			creTarget.m_header.m_cSaveVsWandsBase = max(-20, creTarget.m_header.m_cSaveVsWandsBase);
			bRefreshStats = TRUE;
			bPurge = TRUE;
		} else {
			creTarget.m_cdsCurrent.saveWands -= effect.nParam1;
			creTarget.m_cdsCurrent.saveWands = min(20, creTarget.m_cdsCurrent.saveWands);
			creTarget.m_cdsCurrent.saveWands = max(-20, creTarget.m_cdsCurrent.saveWands);
			bPurge = FALSE;
		}
		break;
	default:
		LPCTSTR lpsz = "DETOUR_CEffectSaveVsWandsMod::DETOUR_ApplyEffect(): invalid effect.nParam2 (%d)\r\n";
		L.timestamp();
		L.append(lpsz);
		console.write(lpsz);
		break;
	}

	return TRUE;
}

//CEffectSaveVsPolyMod
DefineTrampMemberFunc(BOOL, CEffectSaveVsPolyMod, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect, ApplyEffect, 0x515111);

BOOL DETOUR_CEffectSaveVsPolyMod::DETOUR_ApplyEffect(CCreatureObject& creTarget) {
	if (0) IECString("DETOUR_CEffectSaveVsPolyMod::DETOUR_ApplyEffect");

	switch (effect.nParam2) {
	case 0:
		if (effect.nTiming == 1) { //permanent
			creTarget.m_header.m_cSaveVsPolyBase -= effect.nParam1;
			creTarget.m_header.m_cSaveVsPolyBase = min(20, creTarget.m_header.m_cSaveVsPolyBase);
			creTarget.m_header.m_cSaveVsPolyBase = max(-20, creTarget.m_header.m_cSaveVsPolyBase);
			bRefreshStats = TRUE;
			bPurge = TRUE;
		} else {
			creTarget.m_cdsDiff.savePoly -= effect.nParam1;
			bPurge = FALSE;
		}
		break;
	case 1:
		if (effect.nTiming == 1) { //permanent
			creTarget.m_header.m_cSaveVsPolyBase = effect.nParam1;
			creTarget.m_header.m_cSaveVsPolyBase = min(20, creTarget.m_header.m_cSaveVsPolyBase);
			creTarget.m_header.m_cSaveVsPolyBase = max(-20, creTarget.m_header.m_cSaveVsPolyBase);
			bRefreshStats = TRUE;
			bPurge = TRUE;
		} else {
			creTarget.m_cdsCurrent.savePoly = effect.nParam1;
			creTarget.m_cdsCurrent.savePoly = min(20, creTarget.m_cdsCurrent.savePoly);
			creTarget.m_cdsCurrent.savePoly = max(-20, creTarget.m_cdsCurrent.savePoly);
			bPurge = FALSE;
		}
		break;
	case 2:
		if (effect.nTiming == 1) { //permanent
			creTarget.m_header.m_cSaveVsPolyBase = creTarget.m_header.m_cSaveVsPolyBase * effect.nParam1 / 100;
			creTarget.m_header.m_cSaveVsPolyBase = min(20, creTarget.m_header.m_cSaveVsPolyBase);
			creTarget.m_header.m_cSaveVsPolyBase = max(-20, creTarget.m_header.m_cSaveVsPolyBase);
			bRefreshStats = TRUE;
			bPurge = TRUE;
		} else {
			creTarget.m_cdsCurrent.savePoly = creTarget.m_header.m_cSaveVsPolyBase * effect.nParam1 / 100;
			creTarget.m_cdsCurrent.savePoly = min(20, creTarget.m_cdsCurrent.savePoly);
			creTarget.m_cdsCurrent.savePoly = max(-20, creTarget.m_cdsCurrent.savePoly);
			bPurge = FALSE;
		}
		break;
	case 3: //instantaneous sum
		if (effect.nTiming == 1) { //permanent
			creTarget.m_header.m_cSaveVsPolyBase -= effect.nParam1;
			creTarget.m_header.m_cSaveVsPolyBase = min(20, creTarget.m_header.m_cSaveVsPolyBase);
			creTarget.m_header.m_cSaveVsPolyBase = max(-20, creTarget.m_header.m_cSaveVsPolyBase);
			bRefreshStats = TRUE;
			bPurge = TRUE;
		} else {
			creTarget.m_cdsCurrent.savePoly -= effect.nParam1;
			creTarget.m_cdsCurrent.savePoly = min(20, creTarget.m_cdsCurrent.savePoly);
			creTarget.m_cdsCurrent.savePoly = max(-20, creTarget.m_cdsCurrent.savePoly);
			bPurge = FALSE;
		}
		break;
	default:
		LPCTSTR lpsz = "DETOUR_CEffectSaveVsPolyMod::DETOUR_ApplyEffect(): invalid effect.nParam2 (%d)\r\n";
		L.timestamp();
		L.append(lpsz);
		console.write(lpsz);
		break;
	}

	return TRUE;
}

//CEffectSaveVsBreathMod
DefineTrampMemberFunc(BOOL, CEffectSaveVsBreathMod, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect, ApplyEffect, 0x5153C7);

BOOL DETOUR_CEffectSaveVsBreathMod::DETOUR_ApplyEffect(CCreatureObject& creTarget) {
	if (0) IECString("DETOUR_CEffectSaveVsBreathMod::DETOUR_ApplyEffect");

	switch (effect.nParam2) {
	case 0:
		if (effect.nTiming == 1) { //permanent
			creTarget.m_header.m_cSaveVsBreathBase -= effect.nParam1;
			creTarget.m_header.m_cSaveVsBreathBase = min(20, creTarget.m_header.m_cSaveVsBreathBase);
			creTarget.m_header.m_cSaveVsBreathBase = max(-20, creTarget.m_header.m_cSaveVsBreathBase);
			bRefreshStats = TRUE;
			bPurge = TRUE;
		} else {
			creTarget.m_cdsDiff.saveBreath -= effect.nParam1;
			bPurge = FALSE;
		}
		break;
	case 1:
		if (effect.nTiming == 1) { //permanent
			creTarget.m_header.m_cSaveVsBreathBase = effect.nParam1;
			creTarget.m_header.m_cSaveVsBreathBase = min(20, creTarget.m_header.m_cSaveVsBreathBase);
			creTarget.m_header.m_cSaveVsBreathBase = max(-20, creTarget.m_header.m_cSaveVsBreathBase);
			bRefreshStats = TRUE;
			bPurge = TRUE;
		} else {
			creTarget.m_cdsCurrent.saveBreath = effect.nParam1;
			creTarget.m_cdsCurrent.saveBreath = min(20, creTarget.m_cdsCurrent.saveBreath);
			creTarget.m_cdsCurrent.saveBreath = max(-20, creTarget.m_cdsCurrent.saveBreath);
			bPurge = FALSE;
		}
		break;
	case 2:
		if (effect.nTiming == 1) { //permanent
			creTarget.m_header.m_cSaveVsBreathBase = creTarget.m_header.m_cSaveVsBreathBase * effect.nParam1 / 100;
			creTarget.m_header.m_cSaveVsBreathBase = min(20, creTarget.m_header.m_cSaveVsBreathBase);
			creTarget.m_header.m_cSaveVsBreathBase = max(-20, creTarget.m_header.m_cSaveVsBreathBase);
			bRefreshStats = TRUE;
			bPurge = TRUE;
		} else {
			creTarget.m_cdsCurrent.saveBreath = creTarget.m_header.m_cSaveVsBreathBase * effect.nParam1 / 100;
			creTarget.m_cdsCurrent.saveBreath = min(20, creTarget.m_cdsCurrent.saveBreath);
			creTarget.m_cdsCurrent.saveBreath = max(-20, creTarget.m_cdsCurrent.saveBreath);
			bPurge = FALSE;
		}
		break;
	case 3: //instantaneous sum
		if (effect.nTiming == 1) { //permanent
			creTarget.m_header.m_cSaveVsBreathBase -= effect.nParam1;
			creTarget.m_header.m_cSaveVsBreathBase = min(20, creTarget.m_header.m_cSaveVsBreathBase);
			creTarget.m_header.m_cSaveVsBreathBase = max(-20, creTarget.m_header.m_cSaveVsBreathBase);
			bRefreshStats = TRUE;
			bPurge = TRUE;
		} else {
			creTarget.m_cdsCurrent.saveBreath -= effect.nParam1;
			creTarget.m_cdsCurrent.saveBreath = min(20, creTarget.m_cdsCurrent.saveBreath);
			creTarget.m_cdsCurrent.saveBreath = max(-20, creTarget.m_cdsCurrent.saveBreath);
			bPurge = FALSE;
		}
		break;
	default:
		LPCTSTR lpsz = "DETOUR_CEffectSaveVsBreathMod::DETOUR_ApplyEffect(): invalid effect.nParam2 (%d)\r\n";
		L.timestamp();
		L.append(lpsz);
		console.write(lpsz);
		break;
	}

	return TRUE;
}

//CEffectSaveVsSpellMod
DefineTrampMemberFunc(BOOL, CEffectSaveVsSpellMod, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect, ApplyEffect, 0x51568C);

BOOL DETOUR_CEffectSaveVsSpellMod::DETOUR_ApplyEffect(CCreatureObject& creTarget) {
	if (0) IECString("DETOUR_CEffectSaveVsSpellMod::DETOUR_ApplyEffect");

	switch (effect.nParam2) {
	case 0:
		if (effect.nTiming == 1) { //permanent
			creTarget.m_header.m_cSaveVsSpellBase -= effect.nParam1;
			creTarget.m_header.m_cSaveVsSpellBase = min(20, creTarget.m_header.m_cSaveVsSpellBase);
			creTarget.m_header.m_cSaveVsSpellBase = max(-20, creTarget.m_header.m_cSaveVsSpellBase);
			bRefreshStats = TRUE;
			bPurge = TRUE;
		} else {
			creTarget.m_cdsDiff.saveSpell -= effect.nParam1;
			bPurge = FALSE;
		}
		break;
	case 1:
		if (effect.nTiming == 1) { //permanent
			creTarget.m_header.m_cSaveVsSpellBase = effect.nParam1;
			creTarget.m_header.m_cSaveVsSpellBase = min(20, creTarget.m_header.m_cSaveVsSpellBase);
			creTarget.m_header.m_cSaveVsSpellBase = max(-20, creTarget.m_header.m_cSaveVsSpellBase);
			bRefreshStats = TRUE;
			bPurge = TRUE;
		} else {
			creTarget.m_cdsCurrent.saveSpell = effect.nParam1;
			creTarget.m_cdsCurrent.saveSpell = min(20, creTarget.m_cdsCurrent.saveSpell);
			creTarget.m_cdsCurrent.saveSpell = max(-20, creTarget.m_cdsCurrent.saveSpell);
			bPurge = FALSE;
		}
		break;
	case 2:
		if (effect.nTiming == 1) { //permanent
			creTarget.m_header.m_cSaveVsSpellBase = creTarget.m_header.m_cSaveVsSpellBase * effect.nParam1 / 100;
			creTarget.m_header.m_cSaveVsSpellBase = min(20, creTarget.m_header.m_cSaveVsSpellBase);
			creTarget.m_header.m_cSaveVsSpellBase = max(-20, creTarget.m_header.m_cSaveVsSpellBase);
			bRefreshStats = TRUE;
			bPurge = TRUE;
		} else {
			creTarget.m_cdsCurrent.saveSpell = creTarget.m_header.m_cSaveVsSpellBase * effect.nParam1 / 100;
			creTarget.m_cdsCurrent.saveSpell = min(20, creTarget.m_cdsCurrent.saveSpell);
			creTarget.m_cdsCurrent.saveSpell = max(-20, creTarget.m_cdsCurrent.saveSpell);
			bPurge = FALSE;
		}
		break;
	case 3: //instantaneous sum
		if (effect.nTiming == 1) { //permanent
			creTarget.m_header.m_cSaveVsSpellBase -= effect.nParam1;
			creTarget.m_header.m_cSaveVsSpellBase = min(20, creTarget.m_header.m_cSaveVsSpellBase);
			creTarget.m_header.m_cSaveVsSpellBase = max(-20, creTarget.m_header.m_cSaveVsSpellBase);
			bRefreshStats = TRUE;
			bPurge = TRUE;
		} else {
			creTarget.m_cdsCurrent.saveSpell -= effect.nParam1;
			creTarget.m_cdsCurrent.saveSpell = min(20, creTarget.m_cdsCurrent.saveSpell);
			creTarget.m_cdsCurrent.saveSpell = max(-20, creTarget.m_cdsCurrent.saveSpell);
			bPurge = FALSE;
		}
		break;
	default:
		LPCTSTR lpsz = "DETOUR_CEffectSaveVsSpellMod::DETOUR_ApplyEffect(): invalid effect.nParam2 (%d)\r\n";
		L.timestamp();
		L.append(lpsz);
		console.write(lpsz);
		break;
	}

	return TRUE;
}

//CEffectMageMemSpellMod
DefineTrampMemberFunc(BOOL, CEffectMageMemSpellMod, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect, ApplyEffect, 0x5161AB);

BOOL DETOUR_CEffectMageMemSpellMod::DETOUR_ApplyEffect(CCreatureObject& creTarget) {
	if (0) IECString("DETOUR_CEffectMageMemSpellMod::DETOUR_ApplyEffect");

	int bit = 1;

	if (effect.nParam2 & 0x200 &&
		effect.nParam1 >= 0 &&
		effect.nParam1 < 9) {
		CreFileMemorizedSpellLevel& splLvl = creTarget.m_cdsCurrent.MemInfoMage[effect.nParam1];
		splLvl.m_wMemSpellsMax *= 2;
		splLvl.m_wMemSpellsCount *= 2;
	} else if (effect.nParam2 == 0) { //remainder is the original function
		for (int i = 0; i < effect.nParam1 && i < 9; i++) {
			CreFileMemorizedSpellLevel& splLvl = creTarget.m_cdsCurrent.MemInfoMage[i];
			splLvl.m_wMemSpellsMax *= 2;
			splLvl.m_wMemSpellsCount *= 2;
		}
	} else {
		for (int i = 0; i < 9; i++) {
			CreFileMemorizedSpellLevel& splLvl = creTarget.m_cdsCurrent.MemInfoMage[i];
			if (effect.nParam2 & bit &&
				splLvl.m_wMemSpellsMax > 0) {
				splLvl.m_wMemSpellsMax += (short)effect.nParam1;
				splLvl.m_wMemSpellsCount += (short)effect.nParam1;
			}
			bit = bit << 1;
		}
	}

	return TRUE;
};

//CEffectStrengthMod
DefineTrampMemberFunc(BOOL, CEffectStrengthMod, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect, ApplyEffect, 0x516673);

BOOL DETOUR_CEffectStrengthMod::DETOUR_ApplyEffect(CCreatureObject& creTarget) {
	if (0) IECString("DETOUR_CEffectStrengthMod::DETOUR_ApplyEffect");

	switch (effect.nParam2) {
	case 0: //sum
		if (effect.nTiming == 1) {
			creTarget.m_header.m_cSTRBase += effect.nParam1;
			creTarget.m_header.m_cSTRBase = min(creTarget.m_header.m_cSTRBase, 25);
			creTarget.m_header.m_cSTRBase = max(creTarget.m_header.m_cSTRBase, 0);
			bRefreshStats = TRUE;
			bPurge = TRUE;
		} else {
			creTarget.m_cdsDiff.strength += effect.nParam1;
			bPurge = FALSE;
		}
		break;
	case 1: //set
		if (effect.nTiming == 1) {
			creTarget.m_header.m_cSTRBase = effect.nParam1;
			creTarget.m_header.m_cSTRBase = min(creTarget.m_header.m_cSTRBase, 25);
			creTarget.m_header.m_cSTRBase = max(creTarget.m_header.m_cSTRBase, 0);
			bRefreshStats = TRUE;
			bPurge = TRUE;
		} else {
			creTarget.m_cdsCurrent.strength = effect.nParam1;
			creTarget.m_cdsCurrent.strength = min(creTarget.m_cdsCurrent.strength, 25);
			creTarget.m_cdsCurrent.strength = max(creTarget.m_cdsCurrent.strength, 0);
			bPurge = FALSE;
		}
		break;
	case 2: //percentage
		if (effect.nTiming == 1) {
			creTarget.m_header.m_cSTRBase = (creTarget.m_header.m_cSTRBase * effect.nParam1) / 100;
			creTarget.m_header.m_cSTRBase = min(creTarget.m_header.m_cSTRBase, 25);
			creTarget.m_header.m_cSTRBase = max(creTarget.m_header.m_cSTRBase, 0);
			bRefreshStats = TRUE;
			bPurge = TRUE;
		} else {
			creTarget.m_cdsCurrent.strength = (creTarget.m_header.m_cSTRBase * effect.nParam1) / 100;
			creTarget.m_cdsCurrent.strength = min(creTarget.m_cdsCurrent.strength, 25);
			creTarget.m_cdsCurrent.strength = max(creTarget.m_cdsCurrent.strength, 0);
			bPurge = FALSE;
		}
		break;
	case 3: //IWD1/P&P Strength Spell
		if (!pRuleEx->m_ClassSpellAbility.m_2da.bLoaded) {
			LPCTSTR lpsz = "DETOUR_CEffectStrengthMod::DETOUR_ApplyEffect(): CLSSPLAB.2DA not found\r\n";
			console.write(lpsz);
			L.timestamp();
			L.append(lpsz);
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

				wParam1High = _DieRoll(nDieSides, 0) + 1;
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
				char strengthEffective = CDerivedStats_GetEffectiveStrengthSpell(creTarget.m_header.m_cSTRBase, creTarget.m_header.m_cSTRExtraBase) + wParam1High;
				char strength = 0;
				char strengthEx = 0;
				CDerivedStats_GetRealStrengthSpell(strengthEffective, strength, strengthEx);
				creTarget.m_header.m_cSTRBase = strength;
				creTarget.m_header.m_cSTRBase = min(creTarget.m_header.m_cSTRBase, 18);
				creTarget.m_header.m_cSTRBase = max(creTarget.m_header.m_cSTRBase, 0);
				creTarget.m_header.m_cSTRExtraBase = strengthEx;
				creTarget.m_header.m_cSTRExtraBase = min(creTarget.m_header.m_cSTRExtraBase, nMaxStrengthEx ? 100 : 0);
				creTarget.m_header.m_cSTRExtraBase = max(creTarget.m_header.m_cSTRExtraBase, 0);
				bRefreshStats = TRUE;
				bPurge = TRUE;
			} else {
				char strengthEffective = CDerivedStats_GetEffectiveStrengthSpell((char&)creTarget.m_cdsCurrent.strength, (char&)creTarget.m_cdsCurrent.strengthEx) + wParam1High;
				char strength = 0;
				char strengthEx = 0;
				CDerivedStats_GetRealStrengthSpell(strengthEffective, strength, strengthEx);
				creTarget.m_cdsCurrent.strength = strength;
				creTarget.m_cdsCurrent.strength = min(creTarget.m_cdsCurrent.strength, 18);
				creTarget.m_cdsCurrent.strength = max(creTarget.m_cdsCurrent.strength, 0);
				creTarget.m_cdsCurrent.strengthEx = strengthEx;
				creTarget.m_cdsCurrent.strengthEx = min(creTarget.m_cdsCurrent.strengthEx, nMaxStrengthEx ? 100 : 0);
				creTarget.m_cdsCurrent.strengthEx = max(creTarget.m_cdsCurrent.strengthEx, 0);
				bPurge = FALSE;
			}
		}
		break;
	default:
		LPCTSTR lpsz = "DETOUR_CEffectStrengthMod::DETOUR_ApplyEffect(): invalid effect.nParam2 (%d)\r\n";
		console.writef(lpsz, effect.nParam2);
		L.timestamp();
		L.appendf(lpsz, effect.nParam2);
		bPurge = TRUE;
		break;
	}

	return TRUE;
}

//CEffectWisdomMod
DefineTrampMemberFunc(BOOL, CEffectWisdomMod, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect, ApplyEffect, 0x516DF1);

BOOL DETOUR_CEffectWisdomMod::DETOUR_ApplyEffect(CCreatureObject& creTarget) {
	if (0) IECString("DETOUR_CEffectWisdomMod::DETOUR_ApplyEffect");

	switch (effect.nParam2) {
	case 0: //sum
		if (effect.nTiming == 1) {
			creTarget.m_header.m_cWISBase += effect.nParam1;
			creTarget.m_header.m_cWISBase = min(creTarget.m_header.m_cWISBase, 25);
			creTarget.m_header.m_cWISBase = max(creTarget.m_header.m_cWISBase, 0);
			bRefreshStats = TRUE;
			bPurge = TRUE;
		} else {
			creTarget.m_cdsDiff.wisdom += effect.nParam1;
			bPurge = FALSE;
		}
		break;
	case 1: //set
		if (effect.nTiming == 1) {
			creTarget.m_header.m_cWISBase = effect.nParam1;
			creTarget.m_header.m_cWISBase = min(creTarget.m_header.m_cWISBase, 25);
			creTarget.m_header.m_cWISBase = max(creTarget.m_header.m_cWISBase, 0);
			bRefreshStats = TRUE;
			bPurge = TRUE;
		} else {
			creTarget.m_cdsCurrent.wisdom = effect.nParam1;
			creTarget.m_cdsCurrent.wisdom = min(creTarget.m_cdsCurrent.wisdom, 25);
			creTarget.m_cdsCurrent.wisdom = max(creTarget.m_cdsCurrent.wisdom, 0);
			bPurge = FALSE;
		}
		break;
	case 2:	//percentage
		if (effect.nTiming == 1) {
			creTarget.m_header.m_cWISBase = creTarget.m_header.m_cWISBase * effect.nParam1 / 100;
			creTarget.m_header.m_cWISBase = min(creTarget.m_header.m_cWISBase, 25);
			creTarget.m_header.m_cWISBase = max(creTarget.m_header.m_cWISBase, 0);
			bRefreshStats = TRUE;
			bPurge = TRUE;
		} else {
			creTarget.m_cdsCurrent.wisdom = creTarget.m_cdsCurrent.wisdom * effect.nParam1 / 100;
			creTarget.m_cdsCurrent.wisdom = min(creTarget.m_cdsCurrent.wisdom, 25);
			creTarget.m_cdsCurrent.wisdom = max(creTarget.m_cdsCurrent.wisdom, 0);
			bPurge = FALSE;
		}
		break;
	default:
		LPCTSTR lpsz = "DETOUR_CEffectWisdom::DETOUR_ApplyEffect(): invalid effect.nParam2 (%d)\r\n";
		console.writef(lpsz, effect.nParam2);
		L.timestamp();
		L.appendf(lpsz, effect.nParam2);
		bPurge = TRUE;
		break;
	}
	
	return TRUE;
}

//CEffectDispel
DefineTrampMemberFunc(BOOL, CEffectDispel, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect, ApplyEffect, 0x5184DA);

BOOL DETOUR_CEffectDispel::DETOUR_ApplyEffect(CCreatureObject& creTarget) {
	if (0) IECString("DETOUR_CEffectDispel::DETOUR_ApplyEffect");

	int nParam2Low = effect.nParam2 & 0xFFFF;
	int nParam2High = effect.nParam2 >> 16;
	char nRand = IERand() * 100 >> 15;

	switch (nParam2Low) {
	case 0:
		creTarget.m_TimedEffectList.TryDispel(creTarget, creTarget.m_TimedEffectList.posItrPrev, TRUE, FALSE, 0, 0);
		creTarget.m_EffectsEquipped.TryDispel(creTarget, creTarget.m_EffectsEquipped.posItrPrev, TRUE, FALSE, 0, 0);
		break;
	case 1:
		creTarget.m_TimedEffectList.TryDispel(creTarget, creTarget.m_TimedEffectList.posItrPrev, TRUE, TRUE, nRand, effect.nSourceCreLevel);
		creTarget.m_EffectsEquipped.TryDispel(creTarget, creTarget.m_EffectsEquipped.posItrPrev, TRUE, TRUE, nRand, effect.nSourceCreLevel);
		break;
	default:
		creTarget.m_TimedEffectList.TryDispel(creTarget, creTarget.m_TimedEffectList.posItrPrev, TRUE, TRUE, nRand, effect.nParam1);
		creTarget.m_EffectsEquipped.TryDispel(creTarget, creTarget.m_EffectsEquipped.posItrPrev, TRUE, TRUE, nRand, effect.nParam1);
		break;
	}

	bool bDispelMagicalItem = false;

	if (creTarget.m_Inventory.items[SLOT_MISC19]) {
		if (!(creTarget.m_Inventory.items[SLOT_MISC19]->GetFlags() & ITEM_FLAGS_NOT_DISPELLABLE)) {
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

	creTarget.m_bForceReinitAnimColors = TRUE;
	creTarget.m_bForceResetAnimColors = TRUE;
	creTarget.m_bForceMsgResetAnimColors = TRUE;

	bRefreshStats = TRUE;
	bPurge = TRUE;

	return TRUE;
};

//CEffectStealthMod
DefineTrampMemberFunc(BOOL, CEffectStealthMod, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect, ApplyEffect, 0x51877E);

BOOL DETOUR_CEffectStealthMod::DETOUR_ApplyEffect(CCreatureObject& creTarget) {
	if (0) IECString("DETOUR_CEffectStealthMod::DETOUR_ApplyEffect");

	switch (effect.nParam2) {
	case 0: //sum
		if (effect.nTiming == 1) {
			if (creTarget.m_header.m_cMoveSilentlyBase + effect.nParam1 < 0) {
				creTarget.m_header.m_cMoveSilentlyBase = 0;
			} else if (creTarget.m_header.m_cMoveSilentlyBase + effect.nParam1 > 255) {
				creTarget.m_header.m_cMoveSilentlyBase = 255;
			} else {
				creTarget.m_header.m_cMoveSilentlyBase += effect.nParam1;
			}
			bRefreshStats = TRUE;
			bPurge = TRUE;
		} else if (effect.nTiming == 9) {
			creTarget.m_cdsDiff.moveSilently9 += effect.nParam1;
			bPurge = FALSE;
		} else {
			creTarget.m_cdsDiff.stealth += effect.nParam1;
			bPurge = FALSE;
		}
		break;
	case 1: //set
		if (effect.nTiming == 1) {
			effect.nParam1 = min(effect.nParam1, 255);
			effect.nParam1 = max(effect.nParam1, 0);
			creTarget.m_header.m_cMoveSilentlyBase = effect.nParam1;
			bRefreshStats = TRUE;
			bPurge = TRUE;
		} else {
			creTarget.m_cdsCurrent.stealth = effect.nParam1;
			creTarget.m_cdsCurrent.stealth = min(creTarget.m_cdsCurrent.stealth, 255);
			creTarget.m_cdsCurrent.stealth = max(creTarget.m_cdsCurrent.stealth, 0);
			bPurge = FALSE;
		}
		break;
	case 2:	//percentage
		if (effect.nTiming == 1) {
			if (creTarget.m_header.m_cMoveSilentlyBase * effect.nParam1 / 100 < 0) {
				creTarget.m_header.m_cMoveSilentlyBase = 0;
			} else if (creTarget.m_header.m_cMoveSilentlyBase * effect.nParam1 / 100 > 255) {
				creTarget.m_header.m_cMoveSilentlyBase = 255;
			} else {
				creTarget.m_header.m_cMoveSilentlyBase = creTarget.m_header.m_cMoveSilentlyBase * effect.nParam1 / 100;
			}
			bRefreshStats = TRUE;
			bPurge = TRUE;
		} else {
			creTarget.m_cdsCurrent.stealth = creTarget.m_cdsCurrent.stealth * effect.nParam1 / 100;
			creTarget.m_cdsCurrent.stealth = min(creTarget.m_cdsCurrent.stealth, 255);
			creTarget.m_cdsCurrent.stealth = max(creTarget.m_cdsCurrent.stealth, 0);
			bPurge = FALSE;
		}
		break;
	default:
		LPCTSTR lpsz = "DETOUR_CEffectStealthMod::DETOUR_ApplyEffect(): invalid effect.nParam2 (%d)\r\n";
		console.writef(lpsz, effect.nParam2);
		L.timestamp();
		L.appendf(lpsz, effect.nParam2);
		bPurge = TRUE;
		break;
	}
	
	return TRUE;
}

//CEffectPriestMemSpellMod
DefineTrampMemberFunc(BOOL, CEffectPriestMemSpellMod, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect, ApplyEffect, 0x518AA3);

BOOL DETOUR_CEffectPriestMemSpellMod::DETOUR_ApplyEffect(CCreatureObject& creTarget) {
	if (0) IECString("DETOUR_CEffectPriestMemSpellMod::DETOUR_ApplyEffect");

	int bit = 1;

	if (effect.nParam2 & 0x200 &&
		effect.nParam1 >= 0 &&
		effect.nParam1 < 7) {
		CreFileMemorizedSpellLevel& splLvl = creTarget.m_cdsCurrent.MemInfoPriest[effect.nParam1];
		splLvl.m_wMemSpellsMax *= 2;
		splLvl.m_wMemSpellsCount *= 2;
	} else if (effect.nParam2 == 0) { //remainder is the original function
		for (int i = 0; i < effect.nParam1 && i < 7; i++) {
			CreFileMemorizedSpellLevel& splLvl = creTarget.m_cdsCurrent.MemInfoPriest[i];
			splLvl.m_wMemSpellsMax *= 2;
			splLvl.m_wMemSpellsCount *= 2;
		}
	} else {
		for (int i = 0; i < 7; i++) {
			CreFileMemorizedSpellLevel& splLvl = creTarget.m_cdsCurrent.MemInfoPriest[i];
			if (effect.nParam2 & bit &&
				splLvl.m_wMemSpellsMax > 0) {
				splLvl.m_wMemSpellsMax += (short)effect.nParam1;
				splLvl.m_wMemSpellsCount += (short)effect.nParam1;
			}
			bit = bit << 1;
		}
	}

	return TRUE;
};

//CEffectBlindness
DefineTrampMemberFunc(BOOL, CEffectBlindness, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect, ApplyEffect, 0x51ADF9);

BOOL DETOUR_CEffectBlindness::DETOUR_ApplyEffect(CCreatureObject& creTarget) {
	if (0) IECString("DETOUR_CEffectBlindness::DETOUR_ApplyEffect");

	//Change to spell description - overwrites Blindness Fix
	if (pGameOptionsEx->GetOption("Eff_BlindnessAsSpellDesc")) {
		if (effect.nTiming == 1) {
			//permanent
			if (!(creTarget.m_header.m_dwGeneralState & STATE_BLIND)) {
				creTarget.m_header.m_cTHAC0Base -= (-4);
				creTarget.m_header.m_wArmorClassBase = min(20, creTarget.m_header.m_wArmorClassBase - (-4));
			}
			creTarget.m_header.m_dwGeneralState |= STATE_BLIND;
			if (!(creTarget.m_cdsCurrent.stateFlags & STATE_BLIND)) {
				creTarget.m_cdsCurrent.THAC0 -= (-4);
			}
			creTarget.m_cdsCurrent.stateFlags |= STATE_BLIND;
		
			bRefreshStats = TRUE;
			bPurge = TRUE;
		} else {
			//limited
			if (!(creTarget.m_cdsCurrent.stateFlags & STATE_BLIND)) {
				creTarget.m_cdsCurrent.THAC0 -= (-4);
				creTarget.m_cdsDiff.ACEffective -= (-4);
			}
			creTarget.m_cdsCurrent.stateFlags |= STATE_BLIND;

			bPurge = FALSE;
		}

		return TRUE;
	}

	//Remove cumulative penalty
	if (pGameOptionsEx->GetOption("Eff_BlindnessFix")) {
		if (effect.nTiming == 1) {
			//permanent
			if (!(creTarget.m_header.m_dwGeneralState & STATE_BLIND)) creTarget.m_header.m_cTHAC0Base -= (-10);
			creTarget.m_header.m_dwGeneralState |= STATE_BLIND;
			if (!(creTarget.m_cdsCurrent.stateFlags & STATE_BLIND)) creTarget.m_cdsCurrent.THAC0 -= (-10);
			creTarget.m_cdsCurrent.stateFlags |= STATE_BLIND;
		
			bPurge = TRUE;
		} else {
			//limited
			if (!(creTarget.m_cdsCurrent.stateFlags & STATE_BLIND)) creTarget.m_cdsCurrent.THAC0 -= (-10);
			creTarget.m_cdsCurrent.stateFlags |= STATE_BLIND;
		}

		return TRUE;
	}

	return TRUE;
}

DefineTrampMemberFunc(BOOL, CEffectDisease, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect, ApplyEffect, 0x51B1FB);

//CEffectDisease
BOOL DETOUR_CEffectDisease::DETOUR_ApplyEffect(CCreatureObject& creTarget) {
	if (0) IECString("DETOUR_CEffectDisease::DETOUR_ApplyEffect");

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
		creTarget.m_cdsCurrent.m_RepeatingEffs.AddTail(pRepeat);
		break;
	case 1:
		pRepeat = IENew CRepeatingDisease();
		pRepeat->eSource = eSource;
		pRepeat->wMode = 0;
		pRepeat->wPostDelayDuration = creTarget.m_header.m_wHitPoints * effect.nParam1 / 100;
		pRepeat->wAmount = 1;
		pRepeat->wPeriod = 1;
		pRepeat->nTicksLeft = effect.nDuration - g_pChitin->pGame->m_WorldTimer.nGameTime;
		pRepeat->wSecondsElapsed = 0;
		creTarget.m_cdsCurrent.m_RepeatingEffs.AddTail(pRepeat);
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
		creTarget.m_cdsCurrent.m_RepeatingEffs.AddTail(pRepeat);
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
		creTarget.m_cdsCurrent.m_RepeatingEffs.AddTail(pRepeat);
		break;
	case 4:
		creTarget.m_cdsDiff.strength -= effect.nParam1;
		break;
	case 5:
		creTarget.m_cdsDiff.dexterity -= effect.nParam1;
		break;
	case 6:
		creTarget.m_cdsDiff.constitution -= effect.nParam1;
		break;
	case 7:
		creTarget.m_cdsDiff.intelligence -= effect.nParam1;
		break;
	case 8:
		creTarget.m_cdsDiff.wisdom -= effect.nParam1;
		break;
	case 9:
		creTarget.m_cdsDiff.charisma -= effect.nParam1;
		break;
	case 10:
		creTarget.m_cdsCurrent.stateFlags |= STATE_SLOWED;
		break;
	default:
		LPCTSTR lpsz = "DETOUR_CEffectDisease::DETOUR_ApplyEffect(): invalid effect.nParam2 low word (%d)\r\n";
		console.writef(lpsz, wParam2Low);
		L.timestamp();
		L.appendf(lpsz, wParam2Low);
		bPurge = TRUE;
		break;
	}
	return TRUE;
}

//CEffectOpenLocksMod
DefineTrampMemberFunc(BOOL, CEffectOpenLocksMod, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect, ApplyEffect, 0x51D1B8);

BOOL DETOUR_CEffectOpenLocksMod::DETOUR_ApplyEffect(CCreatureObject& creTarget) {
	if (0) IECString("DETOUR_CEffectOpenLocksMod::DETOUR_ApplyEffect");

	switch (effect.nParam2) {
	case 0: //sum
		if (effect.nTiming == 1) {
			if (creTarget.m_header.m_cLockPickingBase + effect.nParam1 < 0) {
				creTarget.m_header.m_cLockPickingBase = 0;
			} else if (creTarget.m_header.m_cLockPickingBase + effect.nParam1 > 255) {
				creTarget.m_header.m_cLockPickingBase = 255;
			} else {
				creTarget.m_header.m_cLockPickingBase += effect.nParam1;
			}
			bRefreshStats = TRUE;
			bPurge = TRUE;
		} else if (effect.nTiming == 9) {
			creTarget.m_cdsDiff.openLocks9 += effect.nParam1;
			bPurge = FALSE;
		} else {
			creTarget.m_cdsDiff.lockpicking += effect.nParam1;
			bPurge = FALSE;
		}
		break;
	case 1: //set
		if (effect.nTiming == 1) {
			effect.nParam1 = min(effect.nParam1, 255);
			effect.nParam1 = max(effect.nParam1, 0);
			creTarget.m_header.m_cLockPickingBase = effect.nParam1;
			bRefreshStats = TRUE;
			bPurge = TRUE;
		} else {
			creTarget.m_cdsCurrent.lockpicking = effect.nParam1;
			creTarget.m_cdsCurrent.lockpicking = min(creTarget.m_cdsCurrent.lockpicking, 255);
			creTarget.m_cdsCurrent.lockpicking = max(creTarget.m_cdsCurrent.lockpicking, 0);
			bPurge = FALSE;
		}
		break;
	case 2:	//percentage
		if (effect.nTiming == 1) {
			if (creTarget.m_header.m_cLockPickingBase * effect.nParam1 / 100 < 0) {
				creTarget.m_header.m_cLockPickingBase = 0;
			} else if (creTarget.m_header.m_cLockPickingBase * effect.nParam1 / 100 > 255) {
				creTarget.m_header.m_cLockPickingBase = 255;
			} else {
				creTarget.m_header.m_cLockPickingBase = creTarget.m_header.m_cLockPickingBase * effect.nParam1 / 100;
			}
			bRefreshStats = TRUE;
			bPurge = TRUE;
		} else {
			creTarget.m_cdsCurrent.lockpicking = creTarget.m_cdsCurrent.lockpicking * effect.nParam1 / 100;
			creTarget.m_cdsCurrent.lockpicking = min(creTarget.m_cdsCurrent.lockpicking, 255);
			creTarget.m_cdsCurrent.lockpicking = max(creTarget.m_cdsCurrent.lockpicking, 0);
			bPurge = FALSE;
		}
		break;
	default:
		LPCTSTR lpsz = "DETOUR_CEffectOpenLocksMod::DETOUR_ApplyEffect(): invalid effect.nParam2 (%d)\r\n";
		console.writef(lpsz, effect.nParam2);
		L.timestamp();
		L.appendf(lpsz, effect.nParam2);
		bPurge = TRUE;
		break;
	}
	
	return TRUE;
}

//CEffectFindTrapsMod
DefineTrampMemberFunc(BOOL, CEffectFindTrapsMod, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect, ApplyEffect, 0x51D420);

BOOL DETOUR_CEffectFindTrapsMod::DETOUR_ApplyEffect(CCreatureObject& creTarget) {
	if (0) IECString("DETOUR_CEffectFindTrapsMod::DETOUR_ApplyEffect");

	switch (effect.nParam2) {
	case 0: //sum
		if (effect.nTiming == 1) {
			if (creTarget.m_header.m_cTrapsBase + effect.nParam1 < 0) {
				creTarget.m_header.m_cTrapsBase = 0;
			} else if (creTarget.m_header.m_cTrapsBase + effect.nParam1 > 255) {
				creTarget.m_header.m_cTrapsBase = 255;
			} else {
				creTarget.m_header.m_cTrapsBase += effect.nParam1;
			}
			bRefreshStats = TRUE;
			bPurge = TRUE;
		} else if (effect.nTiming == 9) {
			creTarget.m_cdsDiff.findTraps9 += effect.nParam1;
			bPurge = FALSE;
		} else {
			creTarget.m_cdsDiff.findTraps += effect.nParam1;
			bPurge = FALSE;
		}
		break;
	case 1: //set
		if (effect.nTiming == 1) {
			effect.nParam1 = min(effect.nParam1, 255);
			effect.nParam1 = max(effect.nParam1, 0);
			creTarget.m_header.m_cTrapsBase = effect.nParam1;
			bRefreshStats = TRUE;
			bPurge = TRUE;
		} else {
			creTarget.m_cdsCurrent.findTraps = effect.nParam1;
			creTarget.m_cdsCurrent.findTraps = min(creTarget.m_cdsCurrent.findTraps, 255);
			creTarget.m_cdsCurrent.findTraps = max(creTarget.m_cdsCurrent.findTraps, 0);
			bPurge = FALSE;
		}
		break;
	case 2:	//percentage
		if (effect.nTiming == 1) {
			if (creTarget.m_header.m_cTrapsBase * effect.nParam1 / 100 < 0) {
				creTarget.m_header.m_cTrapsBase = 0;
			} else if (creTarget.m_header.m_cTrapsBase * effect.nParam1 / 100 > 255) {
				creTarget.m_header.m_cTrapsBase = 255;
			} else {
				creTarget.m_header.m_cTrapsBase = creTarget.m_header.m_cTrapsBase * effect.nParam1 / 100;
			}
			bRefreshStats = TRUE;
			bPurge = TRUE;
		} else {
			creTarget.m_cdsCurrent.findTraps = creTarget.m_cdsCurrent.findTraps * effect.nParam1 / 100;
			creTarget.m_cdsCurrent.findTraps = min(creTarget.m_cdsCurrent.findTraps, 255);
			creTarget.m_cdsCurrent.findTraps = max(creTarget.m_cdsCurrent.findTraps, 0);
			bPurge = FALSE;
		}
		break;
	default:
		LPCTSTR lpsz = "DETOUR_CEffectFindTrapsMod::DETOUR_ApplyEffect(): invalid effect.nParam2 (%d)\r\n";
		console.writef(lpsz, effect.nParam2);
		L.timestamp();
		L.appendf(lpsz, effect.nParam2);
		bPurge = TRUE;
		break;
	}
	
	return TRUE;
}

//CEffectPickPocketsMod
DefineTrampMemberFunc(BOOL, CEffectPickPocketsMod, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect, ApplyEffect, 0x51D688);

BOOL DETOUR_CEffectPickPocketsMod::DETOUR_ApplyEffect(CCreatureObject& creTarget) {
	if (0) IECString("DETOUR_CEffectPickPocketsMod::DETOUR_ApplyEffect");

	switch (effect.nParam2) {
	case 0: //sum
		if (effect.nTiming == 1) {
			if (creTarget.m_header.m_cPickPocketBase + effect.nParam1 < 0) {
				creTarget.m_header.m_cPickPocketBase = 0;
			} else if (creTarget.m_header.m_cPickPocketBase + effect.nParam1 > 255) {
				creTarget.m_header.m_cPickPocketBase = 255;
			} else {
				creTarget.m_header.m_cPickPocketBase += effect.nParam1;
			}
			bRefreshStats = TRUE;
			bPurge = TRUE;
		} else if (effect.nTiming == 9) {
			creTarget.m_cdsDiff.pickPockets9 += effect.nParam1;
			bPurge = FALSE;
		} else {
			creTarget.m_cdsDiff.pickPockets += effect.nParam1;
			bPurge = FALSE;
		}
		break;
	case 1: //set
		if (effect.nTiming == 1) {
			effect.nParam1 = min(effect.nParam1, 255);
			effect.nParam1 = max(effect.nParam1, 0);
			creTarget.m_header.m_cPickPocketBase = effect.nParam1;
			bRefreshStats = TRUE;
			bPurge = TRUE;
		} else {
			creTarget.m_cdsCurrent.pickPockets = effect.nParam1;
			creTarget.m_cdsCurrent.pickPockets = min(creTarget.m_cdsCurrent.pickPockets, 255);
			creTarget.m_cdsCurrent.pickPockets = max(creTarget.m_cdsCurrent.pickPockets, 0);
			bPurge = FALSE;
		}
		break;
	case 2:	//percentage
		if (effect.nTiming == 1) {
			if (creTarget.m_header.m_cPickPocketBase * effect.nParam1 / 100 < 0) {
				creTarget.m_header.m_cPickPocketBase = 0;
			} else if (creTarget.m_header.m_cPickPocketBase * effect.nParam1 / 100 > 255) {
				creTarget.m_header.m_cPickPocketBase = 255;
			} else {
				creTarget.m_header.m_cPickPocketBase = creTarget.m_header.m_cPickPocketBase * effect.nParam1 / 100;
			}
			bRefreshStats = TRUE;
			bPurge = TRUE;
		} else {
			creTarget.m_cdsCurrent.pickPockets = creTarget.m_cdsCurrent.pickPockets * effect.nParam1 / 100;
			creTarget.m_cdsCurrent.pickPockets = min(creTarget.m_cdsCurrent.pickPockets, 255);
			creTarget.m_cdsCurrent.pickPockets = max(creTarget.m_cdsCurrent.pickPockets, 0);
			bPurge = FALSE;
		}
		break;
	default:
		LPCTSTR lpsz = "DETOUR_CEffectPickPocketsMod::DETOUR_ApplyEffect(): invalid effect.nParam2 (%d)\r\n";
		console.writef(lpsz, effect.nParam2);
		L.timestamp();
		L.appendf(lpsz, effect.nParam2);
		bPurge = TRUE;
		break;
	}
	
	return TRUE;
}

//CEffectFatigueMod
DefineTrampMemberFunc(BOOL, CEffectFatigueMod, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect, ApplyEffect, 0x51D8F0);

BOOL DETOUR_CEffectFatigueMod::DETOUR_ApplyEffect(CCreatureObject& creTarget) {
	if (0) IECString("DETOUR_CEffectFatigueMod::DETOUR_ApplyEffect");

	switch (effect.nParam2) {
	case 0: //sum
		if (effect.nTiming == 1) {
			creTarget.m_header.m_cFatigueLimit += effect.nParam1;
			creTarget.m_header.m_cFatigueLimit = min(creTarget.m_header.m_cFatigueLimit, 100);
			creTarget.m_header.m_cFatigueLimit = max(creTarget.m_header.m_cFatigueLimit, 0);
			bRefreshStats = TRUE;
			bPurge = TRUE;
		} else {
			creTarget.m_cdsDiff.fatigue += effect.nParam1;
			bPurge = FALSE;
		}
		break;
	case 1: //set
		if (effect.nTiming == 1) {
			creTarget.m_header.m_cFatigueLimit = effect.nParam1;
			creTarget.m_header.m_cFatigueLimit = min(creTarget.m_header.m_cFatigueLimit, 100);
			creTarget.m_header.m_cFatigueLimit = max(creTarget.m_header.m_cFatigueLimit, 0);
			bRefreshStats = TRUE;
			bPurge = TRUE;
		} else {
			creTarget.m_cdsCurrent.fatigue = effect.nParam1;
			creTarget.m_cdsCurrent.fatigue = min(creTarget.m_cdsCurrent.fatigue, 100);
			creTarget.m_cdsCurrent.fatigue = max(creTarget.m_cdsCurrent.fatigue, 0);
			bPurge = FALSE;
		}
		break;
	case 2:	//percentage
		if (effect.nTiming == 1) {
			creTarget.m_header.m_cFatigueLimit = creTarget.m_header.m_cFatigueLimit * effect.nParam1 / 100;
			creTarget.m_header.m_cFatigueLimit = min(creTarget.m_header.m_cFatigueLimit, 100);
			creTarget.m_header.m_cFatigueLimit = max(creTarget.m_header.m_cFatigueLimit, 0);
			bRefreshStats = TRUE;
			bPurge = TRUE;
		} else {
			creTarget.m_cdsCurrent.fatigue = creTarget.m_cdsCurrent.fatigue * effect.nParam1 / 100;
			creTarget.m_cdsCurrent.fatigue = min(creTarget.m_cdsCurrent.fatigue, 100);
			creTarget.m_cdsCurrent.fatigue = max(creTarget.m_cdsCurrent.fatigue, 0);
			bPurge = FALSE;
		}
		break;
	default:
		LPCTSTR lpsz = "DETOUR_CEffectFatigue::DETOUR_ApplyEffect(): invalid effect.nParam2 (%d)\r\n";
		console.writef(lpsz, effect.nParam2);
		L.timestamp();
		L.appendf(lpsz, effect.nParam2);
		bPurge = TRUE;
		break;
	}
	
	return TRUE;
}

//CEffectIntoxicationMod
DefineTrampMemberFunc(BOOL, CEffectIntoxicationMod, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect, ApplyEffect, 0x51DBB0);

BOOL DETOUR_CEffectIntoxicationMod::DETOUR_ApplyEffect(CCreatureObject& creTarget) {
	if (0) IECString("DETOUR_CEffectIntoxicationMod::DETOUR_ApplyEffect");

	switch (effect.nParam2) {
	case 0: //sum
		if (effect.nTiming == 1) {
			creTarget.m_header.m_cIntoxication += effect.nParam1;
			creTarget.m_header.m_cIntoxication = min(creTarget.m_header.m_cIntoxication, 100);
			creTarget.m_header.m_cIntoxication = max(creTarget.m_header.m_cIntoxication, 0);
			bRefreshStats = TRUE;
			bPurge = TRUE;
		} else {
			creTarget.m_cdsDiff.intoxication += effect.nParam1;
			bPurge = FALSE;
		}
		break;
	case 1: //set
		if (effect.nTiming == 1) {
			creTarget.m_header.m_cIntoxication = effect.nParam1;
			creTarget.m_header.m_cIntoxication = min(creTarget.m_header.m_cIntoxication, 100);
			creTarget.m_header.m_cIntoxication = max(creTarget.m_header.m_cIntoxication, 0);
			bRefreshStats = TRUE;
			bPurge = TRUE;
		} else {
			creTarget.m_cdsCurrent.intoxication = effect.nParam1;
			creTarget.m_cdsCurrent.intoxication = min(creTarget.m_cdsCurrent.intoxication, 100);
			creTarget.m_cdsCurrent.intoxication = max(creTarget.m_cdsCurrent.intoxication, 0);
			bPurge = FALSE;
		}
		break;
	case 2:	//percentage
		if (effect.nTiming == 1) {
			creTarget.m_header.m_cIntoxication = creTarget.m_header.m_cIntoxication * effect.nParam1 / 100;
			creTarget.m_header.m_cIntoxication = min(creTarget.m_header.m_cIntoxication, 100);
			creTarget.m_header.m_cIntoxication = max(creTarget.m_header.m_cIntoxication, 0);
			bRefreshStats = TRUE;
			bPurge = TRUE;
		} else {
			creTarget.m_cdsCurrent.intoxication = creTarget.m_cdsCurrent.intoxication * effect.nParam1 / 100;
			creTarget.m_cdsCurrent.intoxication = min(creTarget.m_cdsCurrent.intoxication, 100);
			creTarget.m_cdsCurrent.intoxication = max(creTarget.m_cdsCurrent.intoxication, 0);
			bPurge = FALSE;
		}
		break;
	default:
		LPCTSTR lpsz = "DETOUR_CEffectIntoxication::DETOUR_ApplyEffect(): invalid effect.nParam2 (%d)\r\n";
		console.writef(lpsz, effect.nParam2);
		L.timestamp();
		L.appendf(lpsz, effect.nParam2);
		bPurge = TRUE;
		break;
	}
	
	return TRUE;
}

//CEffectTrackingMod
DefineTrampMemberFunc(BOOL, CEffectTrackingMod, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect, ApplyEffect, 0x51DE70);

BOOL DETOUR_CEffectTrackingMod::DETOUR_ApplyEffect(CCreatureObject& creTarget) {
	if (0) IECString("DETOUR_CEffectTrackingMod::DETOUR_ApplyEffect");

	switch (effect.nParam2) {
	case 0: //sum
		if (effect.nTiming == 1) {
			if (creTarget.m_header.m_cTrackingBase + effect.nParam1 < 0) {
				creTarget.m_header.m_cTrackingBase = 0;
			} else if (creTarget.m_header.m_cTrackingBase + effect.nParam1 > 255) {
				creTarget.m_header.m_cTrackingBase = 255;
			} else {
				creTarget.m_header.m_cTrackingBase += effect.nParam1;
			}
			bRefreshStats = TRUE;
			bPurge = TRUE;
		} else {
			creTarget.m_cdsDiff.tracking += effect.nParam1;
			bPurge = FALSE;
		}
		break;
	case 1: //set
		if (effect.nTiming == 1) {
			effect.nParam1 = min(effect.nParam1, 255);
			effect.nParam1 = max(effect.nParam1, 0);
			creTarget.m_header.m_cTrackingBase = effect.nParam1;
			bRefreshStats = TRUE;
			bPurge = TRUE;
		} else {
			creTarget.m_cdsCurrent.tracking = effect.nParam1;
			creTarget.m_cdsCurrent.tracking = min(creTarget.m_cdsCurrent.tracking, 255);
			creTarget.m_cdsCurrent.tracking = max(creTarget.m_cdsCurrent.tracking, 0);
			bPurge = FALSE;
		}
		break;
	case 2:	//percentage
		if (effect.nTiming == 1) {
			if (creTarget.m_header.m_cTrackingBase * effect.nParam1 / 100 < 0) {
				creTarget.m_header.m_cTrackingBase = 0;
			} else if (creTarget.m_header.m_cTrackingBase * effect.nParam1 / 100 > 255) {
				creTarget.m_header.m_cTrackingBase = 255;
			} else {
				creTarget.m_header.m_cTrackingBase = creTarget.m_header.m_cTrackingBase * effect.nParam1 / 100;
			}
			bRefreshStats = TRUE;
			bPurge = TRUE;
		} else {
			creTarget.m_cdsCurrent.tracking = creTarget.m_cdsCurrent.tracking * effect.nParam1 / 100;
			creTarget.m_cdsCurrent.tracking = min(creTarget.m_cdsCurrent.tracking, 255);
			creTarget.m_cdsCurrent.tracking = max(creTarget.m_cdsCurrent.tracking, 0);
			bPurge = FALSE;
		}
		break;
	default:
		LPCTSTR lpsz = "DETOUR_CEffectTrackingMod::DETOUR_ApplyEffect(): invalid effect.nParam2 (%d)\r\n";
		console.writef(lpsz, effect.nParam2);
		L.timestamp();
		L.appendf(lpsz, effect.nParam2);
		bPurge = TRUE;
		break;
	}
	
	return TRUE;
}

//CEffectLevelMod
DefineTrampMemberFunc(BOOL, CEffectLevelMod, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect, ApplyEffect, 0x51E36C);

BOOL DETOUR_CEffectLevelMod::DETOUR_ApplyEffect(CCreatureObject& creTarget) {
	if (0) IECString("DETOUR_CEffectLevelMod::DETOUR_ApplyEffect");

	switch (effect.nParam2) {
	case 0: //sum
		if (effect.nTiming == 1) {
			creTarget.m_header.m_cLevel1 += effect.nParam1;
			creTarget.m_header.m_cLevel1 = min(creTarget.m_header.m_cLevel1, 100);
			creTarget.m_header.m_cLevel1 = max(creTarget.m_header.m_cLevel1, 0);
			bRefreshStats = TRUE;
			bPurge = TRUE;
		} else {
			creTarget.m_cdsDiff.levelPrimary += effect.nParam1;
			bPurge = FALSE;
		}
		break;
	case 1: //set
		if (effect.nTiming == 1) {
			creTarget.m_header.m_cLevel1 = effect.nParam1;
			creTarget.m_header.m_cLevel1 = min(creTarget.m_header.m_cLevel1, 100);
			creTarget.m_header.m_cLevel1 = max(creTarget.m_header.m_cLevel1, 0);
			bRefreshStats = TRUE;
			bPurge = TRUE;
		} else {
			creTarget.m_cdsCurrent.levelPrimary = effect.nParam1;
			creTarget.m_cdsCurrent.levelPrimary = min(creTarget.m_cdsCurrent.levelPrimary, 100);
			creTarget.m_cdsCurrent.levelPrimary = max(creTarget.m_cdsCurrent.levelPrimary, 0);
			bPurge = FALSE;
		}
		break;
	case 2:	//percentage
		if (effect.nTiming == 1) {
			creTarget.m_header.m_cLevel1 = creTarget.m_header.m_cLevel1 * effect.nParam1 / 100;
			creTarget.m_header.m_cLevel1 = min(creTarget.m_header.m_cLevel1, 100);
			creTarget.m_header.m_cLevel1 = max(creTarget.m_header.m_cLevel1, 0);
			bRefreshStats = TRUE;
			bPurge = TRUE;
		} else {
			creTarget.m_cdsCurrent.levelPrimary = creTarget.m_cdsCurrent.levelPrimary * effect.nParam1 / 100;
			creTarget.m_cdsCurrent.levelPrimary = min(creTarget.m_cdsCurrent.levelPrimary, 100);
			creTarget.m_cdsCurrent.levelPrimary = max(creTarget.m_cdsCurrent.levelPrimary, 0);
			bPurge = FALSE;
		}
		break;
	default:
		LPCTSTR lpsz = "DETOUR_CEffectLevel::DETOUR_ApplyEffect(): invalid effect.nParam2 (%d)\r\n";
		console.writef(lpsz, effect.nParam2);
		L.timestamp();
		L.appendf(lpsz, effect.nParam2);
		bPurge = TRUE;
		break;
	}
	
	return TRUE;
}

//CEffectStrengthExMod
DefineTrampMemberFunc(BOOL, CEffectStrengthExMod, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect, ApplyEffect, 0x51E0AC);

BOOL DETOUR_CEffectStrengthExMod::DETOUR_ApplyEffect(CCreatureObject& creTarget) {
	if (0) IECString("DETOUR_CEffectStrengthExMod::DETOUR_ApplyEffect");

	switch (effect.nParam2) {
	case 0: //sum
		if (effect.nTiming == 1) {
			creTarget.m_header.m_cSTRExtraBase += effect.nParam1;
			creTarget.m_header.m_cSTRExtraBase = min(creTarget.m_header.m_cSTRExtraBase, 100);
			creTarget.m_header.m_cSTRExtraBase = max(creTarget.m_header.m_cSTRExtraBase, 0);
			bRefreshStats = TRUE;
			bPurge = TRUE;
		} else {
			creTarget.m_cdsDiff.strengthEx += effect.nParam1;
			bPurge = FALSE;
		}
		break;
	case 1: //set
		if (effect.nTiming == 1) {
			creTarget.m_header.m_cSTRExtraBase = effect.nParam1;
			creTarget.m_header.m_cSTRExtraBase = min(creTarget.m_header.m_cSTRExtraBase, 100);
			creTarget.m_header.m_cSTRExtraBase = max(creTarget.m_header.m_cSTRExtraBase, 0);
			bRefreshStats = TRUE;
			bPurge = TRUE;
		} else {
			creTarget.m_cdsCurrent.strengthEx = effect.nParam1;
			creTarget.m_cdsCurrent.strengthEx = min(creTarget.m_cdsCurrent.strengthEx, 100);
			creTarget.m_cdsCurrent.strengthEx = max(creTarget.m_cdsCurrent.strengthEx, 0);
			bPurge = FALSE;
		}
		break;
	case 2:	//percentage
		if (effect.nTiming == 1) {
			creTarget.m_header.m_cSTRExtraBase = creTarget.m_header.m_cSTRExtraBase * effect.nParam1 / 100;
			creTarget.m_header.m_cSTRExtraBase = min(creTarget.m_header.m_cSTRExtraBase, 100);
			creTarget.m_header.m_cSTRExtraBase = max(creTarget.m_header.m_cSTRExtraBase, 0);
			bRefreshStats = TRUE;
			bPurge = TRUE;
		} else {
			creTarget.m_cdsCurrent.strengthEx = creTarget.m_cdsCurrent.strengthEx * effect.nParam1 / 100;
			creTarget.m_cdsCurrent.strengthEx = min(creTarget.m_cdsCurrent.strengthEx, 100);
			creTarget.m_cdsCurrent.strengthEx = max(creTarget.m_cdsCurrent.strengthEx, 0);
			bPurge = FALSE;
		}
		break;
	default:
		LPCTSTR lpsz = "DETOUR_CEffectStrengthEx::DETOUR_ApplyEffect(): invalid effect.nParam2 (%d)\r\n";
		console.writef(lpsz, effect.nParam2);
		L.timestamp();
		L.appendf(lpsz, effect.nParam2);
		bPurge = TRUE;
		break;
	}
	
	return TRUE;
}

//CEffectRegeneration
DefineTrampMemberFunc(BOOL, CEffectRegeneration, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect, ApplyEffect, 0x51C615);

BOOL DETOUR_CEffectRegeneration::DETOUR_ApplyEffect(CCreatureObject& creTarget) {
	if (0) IECString("DETOUR_CEffectRegeneration::DETOUR_ApplyEffect");

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
		pRepeat->wPostDelayDuration = creTarget.m_header.m_wHitPoints * effect.nParam1 / 100;
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
		console.writef(lpsz, wParam2Low);
		L.timestamp();
		L.appendf(lpsz, wParam2Low);
		bPurge = TRUE;
		break;
	}

	creTarget.m_cdsCurrent.m_RepeatingEffs.AddTail(pRepeat);

	return TRUE;
}

//CEffectMoraleBreakMod
DefineTrampMemberFunc(BOOL, CEffectMoraleBreakMod, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect, ApplyEffect, 0x51F080);

BOOL DETOUR_CEffectMoraleBreakMod::DETOUR_ApplyEffect(CCreatureObject& creTarget) {
	if (0) IECString("DETOUR_CEffectMoraleBreakMod::DETOUR_ApplyEffect");

	switch (effect.nParam2) {
	case 0: //sum
		if (effect.nTiming == 1) {
			if (creTarget.m_header.m_cMoraleBreak + effect.nParam1 < 0) {
				creTarget.m_header.m_cMoraleBreak = 0;
			} else if (creTarget.m_header.m_cMoraleBreak + effect.nParam1 > 255) {
				creTarget.m_header.m_cMoraleBreak = 255;
			} else {
				creTarget.m_header.m_cMoraleBreak += effect.nParam1;
			}
			bRefreshStats = TRUE;
			bPurge = TRUE;
		} else {
			creTarget.m_cdsDiff.moraleBreak += effect.nParam1;
			bPurge = FALSE;
		}
		break;
	case 1: //set
		if (effect.nTiming == 1) {
			effect.nParam1 = min(effect.nParam1, 255);
			effect.nParam1 = max(effect.nParam1, 0);
			creTarget.m_header.m_cMoraleBreak = effect.nParam1;
			bRefreshStats = TRUE;
			bPurge = TRUE;
		} else {
			creTarget.m_cdsCurrent.moraleBreak = effect.nParam1;
			creTarget.m_cdsCurrent.moraleBreak = min(creTarget.m_cdsCurrent.moraleBreak, 255);
			creTarget.m_cdsCurrent.moraleBreak = max(creTarget.m_cdsCurrent.moraleBreak, 0);
			bPurge = FALSE;
		}
		break;
	case 2:	//percentage
		if (effect.nTiming == 1) {
			if (creTarget.m_header.m_cMoraleBreak * effect.nParam1 / 100 < 0) {
				creTarget.m_header.m_cMoraleBreak = 0;
			} else if (creTarget.m_header.m_cMoraleBreak * effect.nParam1 / 100 > 255) {
				creTarget.m_header.m_cMoraleBreak = 255;
			} else {
				creTarget.m_header.m_cMoraleBreak = creTarget.m_header.m_cMoraleBreak * effect.nParam1 / 100;
			}
			bRefreshStats = TRUE;
			bPurge = TRUE;
		} else {
			creTarget.m_cdsCurrent.moraleBreak = creTarget.m_cdsCurrent.moraleBreak * effect.nParam1 / 100;
			creTarget.m_cdsCurrent.moraleBreak = min(creTarget.m_cdsCurrent.moraleBreak, 255);
			creTarget.m_cdsCurrent.moraleBreak = max(creTarget.m_cdsCurrent.moraleBreak, 0);
			bPurge = FALSE;
		}
		break;
	default:
		LPCTSTR lpsz = "DETOUR_CEffectMoraleBreakMod::DETOUR_ApplyEffect(): invalid effect.nParam2 (%d)\r\n";
		console.writef(lpsz, effect.nParam2);
		L.timestamp();
		L.appendf(lpsz, effect.nParam2);
		bPurge = TRUE;
		break;
	}
	
	return TRUE;
}

//CEffectReputationMod
DefineTrampMemberFunc(BOOL, CEffectReputationMod, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect, ApplyEffect, 0x51F4C1);

BOOL DETOUR_CEffectReputationMod::DETOUR_ApplyEffect(CCreatureObject& creTarget) {
	if (0) IECString("DETOUR_CEffectReputationMod::DETOUR_ApplyEffect");

	switch (effect.nParam2) {
	case 0: //sum
		if (effect.nTiming == 1) {
			if (creTarget.m_header.m_cReputation + effect.nParam1 < 0) {
				creTarget.m_header.m_cReputation = 0;
			} else if (creTarget.m_header.m_cReputation + effect.nParam1 > 255) {
				creTarget.m_header.m_cReputation = 255;
			} else {
				creTarget.m_header.m_cReputation += effect.nParam1;
			}
			bRefreshStats = TRUE;
			bPurge = TRUE;
		} else {
			creTarget.m_cdsDiff.reputation += effect.nParam1;
			bPurge = FALSE;
		}
		break;
	case 1: //set
		if (effect.nTiming == 1) {
			effect.nParam1 = min(effect.nParam1, 255);
			effect.nParam1 = max(effect.nParam1, 0);
			creTarget.m_header.m_cReputation = effect.nParam1;
			bRefreshStats = TRUE;
			bPurge = TRUE;
		} else {
			creTarget.m_cdsCurrent.reputation = effect.nParam1;
			creTarget.m_cdsCurrent.reputation = min(creTarget.m_cdsCurrent.reputation, 255);
			creTarget.m_cdsCurrent.reputation = max(creTarget.m_cdsCurrent.reputation, 0);
			bPurge = FALSE;
		}
		break;
	case 2:	//percentage
		if (effect.nTiming == 1) {
			if (creTarget.m_header.m_cReputation * effect.nParam1 / 100 < 0) {
				creTarget.m_header.m_cReputation = 0;
			} else if (creTarget.m_header.m_cReputation * effect.nParam1 / 100 > 255) {
				creTarget.m_header.m_cReputation = 255;
			} else {
				creTarget.m_header.m_cReputation = creTarget.m_header.m_cReputation * effect.nParam1 / 100;
			}
			bRefreshStats = TRUE;
			bPurge = TRUE;
		} else {
			creTarget.m_cdsCurrent.reputation = creTarget.m_cdsCurrent.reputation * effect.nParam1 / 100;
			creTarget.m_cdsCurrent.reputation = min(creTarget.m_cdsCurrent.reputation, 255);
			creTarget.m_cdsCurrent.reputation = max(creTarget.m_cdsCurrent.reputation, 0);
			bPurge = FALSE;
		}
		break;
	default:
		LPCTSTR lpsz = "DETOUR_CEffectReputationMod::DETOUR_ApplyEffect(): invalid effect.nParam2 (%d)\r\n";
		console.writef(lpsz, effect.nParam2);
		L.timestamp();
		L.appendf(lpsz, effect.nParam2);
		bPurge = TRUE;
		break;
	}
	
	return TRUE;
}

//CEffectAid
DefineTrampMemberFunc(BOOL, CEffectAid, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect, ApplyEffect, 0x52720A);

BOOL DETOUR_CEffectAid::DETOUR_ApplyEffect(CCreatureObject& creTarget) {
	if (0) IECString("DETOUR_CEffectAid::DETOUR_ApplyEffect");
	if (creTarget.m_header.m_wHitPoints <= 0) return TRUE;
	if (!(creTarget.m_cdsCurrent.stateFlags & STATE_AID))
		CDerivedStats_SetStat(creTarget.m_cdsCurrent, CDERIVEDSTATSEX_BASE + CDERIVEDSTATSEX_AID, effect.nParam1);
	return (this->*Tramp_CEffectAid_ApplyEffect)(creTarget);
}

//CEffectBless
DefineTrampMemberFunc(BOOL, CEffectBless, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect, ApplyEffect, 0x5273F7);

BOOL DETOUR_CEffectBless::DETOUR_ApplyEffect(CCreatureObject& creTarget) {
	if (0) IECString("DETOUR_CEffectBless::DETOUR_ApplyEffect");
	if (!(creTarget.m_cdsCurrent.stateFlags & STATE_BLESS))
		CDerivedStats_SetStat(creTarget.m_cdsCurrent, CDERIVEDSTATSEX_BASE + CDERIVEDSTATSEX_BLESS, effect.nParam1);
	return (this->*Tramp_CEffectBless_ApplyEffect)(creTarget);
}

//CEffectChant
DefineTrampMemberFunc(BOOL, CEffectChant, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect, ApplyEffect, 0x527499);

BOOL DETOUR_CEffectChant::DETOUR_ApplyEffect(CCreatureObject& creTarget) {
	if (0) IECString("DETOUR_CEffectChant::DETOUR_ApplyEffect");
	if (!(creTarget.m_cdsCurrent.stateFlags & STATE_CHANT))
		CDerivedStats_SetStat(creTarget.m_cdsCurrent, CDERIVEDSTATSEX_BASE + CDERIVEDSTATSEX_CHANT, effect.nParam1);
	return (this->*Tramp_CEffectChant_ApplyEffect)(creTarget);
}

//CEffectHolyMight
DefineTrampMemberFunc(BOOL, CEffectHolyMight, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect, ApplyEffect, 0x527563);

BOOL DETOUR_CEffectHolyMight::DETOUR_ApplyEffect(CCreatureObject& creTarget) {
	if (0) IECString("DETOUR_CEffectHolyMight::DETOUR_ApplyEffect");
	if (!(creTarget.m_cdsCurrent.stateFlags & STATE_DRAWUPONHOLYMIGHT))
		CDerivedStats_SetStat(creTarget.m_cdsCurrent, CDERIVEDSTATSEX_BASE + CDERIVEDSTATSEX_DRAWUPONHOLYMIGHT, effect.nParam1);
	return (this->*Tramp_CEffectHolyMight_ApplyEffect)(creTarget);
}

//CEffectChantBad
DefineTrampMemberFunc(BOOL, CEffectChantBad, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect, ApplyEffect, 0x5274FE);

BOOL DETOUR_CEffectChantBad::DETOUR_ApplyEffect(CCreatureObject& creTarget) {
	if (0) IECString("DETOUR_CEffectChantBad::DETOUR_ApplyEffect");
	if (!(creTarget.m_cdsCurrent.stateFlags & STATE_CHANTBAD))
		CDerivedStats_SetStat(creTarget.m_cdsCurrent, CDERIVEDSTATSEX_BASE + CDERIVEDSTATSEX_CHANTBAD, effect.nParam1);
	return (this->*Tramp_CEffectChantBad_ApplyEffect)(creTarget);
}

//CEffectDisableSpelltype
DefineTrampMemberFunc(BOOL, CEffectDisableSpelltype, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect, ApplyEffect, 0x52BA62);

BOOL DETOUR_CEffectDisableSpelltype::DETOUR_ApplyEffect(CCreatureObject& creTarget) {
	if (0) IECString("DETOUR_CEffectDisableSpelltype::DETOUR_ApplyEffect");
	if ((unsigned int)effect.nParam2 < 3)
		CDerivedStats_SetStat(creTarget.m_cdsCurrent, CDERIVEDSTATSEX_BASE + CDERIVEDSTATSEX_DISABLESPELLTYPEWIZARD + effect.nParam2, 1);
	return (this->*Tramp_CEffectDisableSpelltype_ApplyEffect)(creTarget);
}

//CEffectDisableButton
DefineTrampMemberFunc(BOOL, CEffectDisableButton, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect, ApplyEffect, 0x52B97B);

BOOL DETOUR_CEffectDisableButton::DETOUR_ApplyEffect(CCreatureObject& creTarget) {
	if (0) IECString("DETOUR_CEffectDisableButton::DETOUR_ApplyEffect");

	if ((unsigned int)effect.nParam2 < 14)
		creTarget.m_cdsCurrent.ButtonDisable[effect.nParam2] = 1;
	if ((unsigned int)effect.nParam2 < 15)
		CDerivedStats_SetStat(creTarget.m_cdsCurrent, CDERIVEDSTATSEX_BASE + CDERIVEDSTATSEX_BUTTONDISABLESTEALTH + effect.nParam2, 1);

	return TRUE;
}

//CEffectLearnSpell
DefineTrampMemberFunc(BOOL, CEffectLearnSpell, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect, ApplyEffect, 0x52C250);

BOOL DETOUR_CEffectLearnSpell::DETOUR_ApplyEffect(CCreatureObject& creTarget) {
	if (0) IECString("DETOUR_CEffectLearnSpell::DETOUR_ApplyEffect");

	int wParam1High = effect.nParam1 >> 16;

	IECString sLearnSpellMod;
	int nLearnSpellMod;
	int nRow = creTarget.m_cdsPrevious.intelligence;
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

	ResSplFile resSpell;
	resSpell.LoadResource(effect.rResource, TRUE, TRUE);
	if (!resSpell.bLoaded) {
		bPurge = TRUE;
		return TRUE;
	}

	short wLevel = resSpell.GetSpellLevel();
	short wType = resSpell.GetSpellType();
	int nSchoolExclusionFlags = resSpell.GetExclusionFlags() & 0x3FC0; //keep only spell school bits
	int nKnownSpellsOfLevel = 0;

	while (&creTarget.GetKnownSpellMage(wLevel - 1, nKnownSpellsOfLevel) != NULL) {
		nKnownSpellsOfLevel++;
	}

	if (wParam1High & EFFECTLEARNSPELL_RESTRICT_MAX_SPELLS &&
		nKnownSpellsOfLevel > g_pChitin->pGame->GetIntModMaxSpellsPerLevel(creTarget.m_cdsCurrent)) {
		bPurge = TRUE;
		return TRUE;
	}

	if (wParam1High & EFFECTLEARNSPELL_RESTRICT_SCHOOL &&
		wType == SPELL_TYPE_WIZARD &&
		creTarget.GetKitUnusableFlag() & nSchoolExclusionFlags) {
		bPurge = TRUE;
		return TRUE;
	}

	if (wParam1High & EFFECTLEARNSPELL_NO_SORCERER &&
		creTarget.GetCurrentObject().GetClass() == CLASS_SORCERER) {
		bPurge = TRUE;
		return TRUE;
	}
	
	BOOL bAlreadyKnown = FALSE;
	POSITION pos;
	if (wParam1High & EFFECTLEARNSPELL_NO_XP_DUPLICATE) {
		switch (wType) {
		case SPELL_TYPE_WIZARD:
			pos = creTarget.m_KnownSpellsWizard[wLevel - 1].GetHeadPosition();
			while (pos != NULL && bAlreadyKnown == FALSE) {
				CreFileKnownSpell* pKSpell = (CreFileKnownSpell*)creTarget.m_KnownSpellsWizard[wLevel - 1].GetNext(pos);
				if (pKSpell->m_rKnownSpellName == resSpell.name) {
					bAlreadyKnown = TRUE;
				}
			}
			break;
		case SPELL_TYPE_CLERIC:
			pos = creTarget.m_KnownSpellsPriest[wLevel - 1].GetHeadPosition();
			while (pos != NULL && bAlreadyKnown == FALSE) {
				CreFileKnownSpell* pKSpell = (CreFileKnownSpell*)creTarget.m_KnownSpellsPriest[wLevel - 1].GetNext(pos);
				if (pKSpell->m_rKnownSpellName == resSpell.name) {
					bAlreadyKnown = TRUE;
				}
			}
			break;
		default:
			break;
		}
	}

	if (creTarget.m_header.m_wKit[1] != KIT_TRUECLASS) {
		if (g_pChitin->pGame->GetMageSchool(creTarget.m_header.m_wKit[1]) == resSpell.GetSpellSchoolPrimary()) {
			nLearnSpellMod += 15;
		} else {
			nLearnSpellMod -= 15;
		}
	}

	if ((nRand <= nLearnSpellMod) ||
		wParam1High & EFFECTLEARNSPELL_SUCCESS_ALWAYS) { //success
		switch (wType) {
		case SPELL_TYPE_WIZARD:
			creTarget.AddKnownSpellMage(effect.rResource, wLevel - 1);
			break;
		case SPELL_TYPE_CLERIC:
			creTarget.AddKnownSpellPriest(effect.rResource, wLevel - 1);
			break;
		default:
			creTarget.AddKnownSpell(effect.rResource, FALSE);
			break;
		}

		if (!bAlreadyKnown &&
			!(wParam1High & EFFECTLEARNSPELL_NO_XP_ALWAYS) &&
			creTarget.GetCurrentObject().m_cEnemyAlly <= EA_CONTROLLEDCUTOFF) {
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

	bPurge = TRUE;
	return TRUE;
}

//CEffectMagicResistMod
DefineTrampMemberFunc(BOOL, CEffectMagicResistMod, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect, ApplyEffect, 0x52EB97);

BOOL DETOUR_CEffectMagicResistMod::DETOUR_ApplyEffect(CCreatureObject& creTarget) {
	if (0) IECString("DETOUR_CEffectMagicResistMod::DETOUR_ApplyEffect");

	switch (effect.nParam2) {
		case 0:
			//instantaneous sum
			if (effect.nTiming == 1) {
				creTarget.m_header.m_cResistMagicBase += effect.nParam1;
				creTarget.m_header.m_cResistMagicBase = min(creTarget.m_header.m_cResistMagicBase, 100);
				creTarget.m_header.m_cResistMagicBase = max(creTarget.m_header.m_cResistMagicBase, 0);
				bRefreshStats = TRUE;
				bPurge = TRUE;
			} else {
				creTarget.m_cdsCurrent.resistMagic += effect.nParam1;
				creTarget.m_cdsCurrent.resistMagic = min(creTarget.m_cdsCurrent.resistMagic, 100);
				creTarget.m_cdsCurrent.resistMagic = max(creTarget.m_cdsCurrent.resistMagic, 0);
				bPurge = FALSE;
			}
			break;
		case 1:
			//set
			if (effect.nTiming == 1) {
				creTarget.m_header.m_cResistMagicBase = effect.nParam1;
				creTarget.m_header.m_cResistMagicBase = min(creTarget.m_header.m_cResistMagicBase, 100);
				creTarget.m_header.m_cResistMagicBase = max(creTarget.m_header.m_cResistMagicBase, 0);
				bRefreshStats = TRUE;
				bPurge = TRUE;
			} else {
				creTarget.m_cdsCurrent.resistMagic = effect.nParam1;
				creTarget.m_cdsCurrent.resistMagic = min(creTarget.m_cdsCurrent.resistMagic, 100);
				creTarget.m_cdsCurrent.resistMagic = max(creTarget.m_cdsCurrent.resistMagic, 0);
				bPurge = FALSE;
			}
			break;
		case 2:
			//percentage
			if (effect.nTiming == 1) {
				creTarget.m_header.m_cResistMagicBase = (creTarget.m_header.m_cResistMagicBase * effect.nParam1) / 100;
				creTarget.m_header.m_cResistMagicBase = min(creTarget.m_header.m_cResistMagicBase, 100);
				creTarget.m_header.m_cResistMagicBase = max(creTarget.m_header.m_cResistMagicBase, 0);
				bRefreshStats = TRUE;
				bPurge = TRUE;
			} else {
				creTarget.m_cdsCurrent.resistMagic = (creTarget.m_header.m_cResistMagicBase * effect.nParam1) / 100;
				creTarget.m_cdsCurrent.resistMagic = min(creTarget.m_cdsCurrent.resistMagic, 100);
				creTarget.m_cdsCurrent.resistMagic = max(creTarget.m_cdsCurrent.resistMagic, 0);
				bPurge = FALSE;
			}
			break;
		case 3:
			//sum
			if (effect.nTiming == 1) {
				creTarget.m_header.m_cResistMagicBase += effect.nParam1;
				creTarget.m_header.m_cResistMagicBase = min(creTarget.m_header.m_cResistMagicBase, 100);
				creTarget.m_header.m_cResistMagicBase = max(creTarget.m_header.m_cResistMagicBase, 0);
				bRefreshStats = TRUE;
				bPurge = TRUE;
			} else {
				creTarget.m_cdsDiff.resistMagic += effect.nParam1;
				bPurge = FALSE;
			}
			break;
		default:
			LPCTSTR lpsz = "DETOUR_CEffectMagicResistMod::DETOUR_ApplyEffect(): invalid effect.nParam2 (%d)\r\n";
			console.writef(lpsz, effect.nParam2);
			L.timestamp();
			L.appendf(lpsz, effect.nParam2);
			bPurge = TRUE;
			break;
	}
	return TRUE;
}

//CEffectPoisonResistMod
DefineTrampMemberFunc(BOOL, CEffectPoisonResistMod, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect, ApplyEffect, 0x52F0A5);

BOOL DETOUR_CEffectPoisonResistMod::DETOUR_ApplyEffect(CCreatureObject& creTarget) {
	if (0) IECString("DETOUR_CEffectPoisonResistMod::DETOUR_ApplyEffect");

	switch (effect.nParam2) {
		case 0:
		case 78: //TEMPORARY ONLY workaround for BG2Fixpack immunity batch for disease
			//set
			creTarget.m_cdsCurrent.resistPoison = effect.nParam1;
			break;
		case 1:
			//sum
			creTarget.m_cdsDiff.resistPoison += effect.nParam1;
			break;
		case 2:
			//percentage
			creTarget.m_cdsCurrent.resistPoison = (creTarget.m_cdsCurrent.resistPoison * effect.nParam1) / 100;
			break;
		case 3:
			//instantaneous sum
			creTarget.m_cdsCurrent.resistPoison += effect.nParam1;
			break;
		default:
			LPCTSTR lpsz = "DETOUR_CEffectPoisonResistMod::DETOUR_ApplyEffect(): invalid effect.nParam2 (%d)\r\n";
			console.writef(lpsz, effect.nParam2);
			L.timestamp();
			L.appendf(lpsz, effect.nParam2);
			bPurge = TRUE;
			break;
	}
	return TRUE;
}

//CEffectUseEFFFile
DefineTrampMemberFunc(BOOL, CEffectUseEFFFile, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect, ApplyEffect, 0x52FBAE);

BOOL DETOUR_CEffectUseEFFFile::DETOUR_ApplyEffect(CCreatureObject& creTarget) {
	if (0) IECString("DETOUR_CEffectUseEFFFile::DETOUR_ApplyEffect");

	BOOL bValidTarget = FALSE;
	Object oTarget = creTarget.GetCurrentObject();
	Object oCriteria;
	unsigned char cValue = effect.nParam1 & 0xFF;
	int nIdsType = effect.nParam2;

	switch (nIdsType) {
	case 2: //EA
		oCriteria.m_cEnemyAlly = cValue;
		if (oTarget.MatchCriteria(oCriteria, FALSE, FALSE, FALSE)) bValidTarget = TRUE;
		break;
	case 3: //GENERAL
		if (oTarget.m_cGeneral == cValue || cValue == 0) bValidTarget = TRUE;
		break;
	case 4: //RACE
		if (oTarget.m_cRace == cValue || cValue == 0) bValidTarget = TRUE;
		break;
	case 5: //CLASS
		{
			unsigned char cClassOrg;
			unsigned char cClassNew;
			unsigned char cClass = oTarget.GetClass();
			
			oTarget.GetDualClasses(&cClassNew, &cClassOrg);
			
			if (cClassNew != cClassOrg &&
				!oTarget.HasActiveSubclass(cClassOrg, TRUE)
			) { //dual-class
				cClass = cClassNew;
			}

			if (cClass == cValue || cValue == 0) bValidTarget = TRUE;
		}
		break;
	case 6: //SPECIFIC
		if (oTarget.m_cSpecific == cValue || cValue == 0) bValidTarget = TRUE;
		break;
	case 7: //GENDER
		if (oTarget.m_cGender == cValue || cValue == 0) bValidTarget = TRUE;
		break;
	case 8: //ALIGN
		if (oTarget.m_cAlignment == cValue || cValue == ALIGN_ANY) bValidTarget = TRUE;
		if (cValue == ALIGN_MASK_GOOD && (oTarget.m_cAlignment & 0xF) == ALIGN_MASK_GOOD) bValidTarget = TRUE;
		if (cValue == ALIGN_MASK_NEUTRAL && (oTarget.m_cAlignment & 0xF) == ALIGN_MASK_NEUTRAL) bValidTarget = TRUE;
		if (cValue == ALIGN_MASK_EVIL && (oTarget.m_cAlignment & 0xF) == ALIGN_MASK_EVIL) bValidTarget = TRUE;
		if (cValue == ALIGN_LAWFUL_MASK && (oTarget.m_cAlignment & 0xF0) == ALIGN_LAWFUL_MASK) bValidTarget = TRUE;
		if (cValue == ALIGN_NEUTRAL_MASK && (oTarget.m_cAlignment & 0xF0) == ALIGN_NEUTRAL_MASK) bValidTarget = TRUE;
		if (cValue == ALIGN_CHAOTIC_MASK && (oTarget.m_cAlignment & 0xF0) == ALIGN_CHAOTIC_MASK) bValidTarget = TRUE;
		break;
	default:
		break;
	}

	if (bValidTarget) {
		ResEffFile rec(effect.rResource);
		CEffect* pEff = &rec.CreateCEffect();
		if (pEff) {
			pEff->effect.ptSource = effect.ptSource;
			pEff->enum2 = enum2;
			pEff->eSource = eSource;
			pEff->effect.ptDest = effect.ptDest;
			pEff->effect.nDuration = effect.nDuration;
			pEff->effect.nTiming = effect.nTiming & 0xFFFF;
			pEff->effect.bDoSingleUse = effect.bDoSingleUse;

			//new - restore child effect's parameters and resources from previous application
			if (effect.nParam3) { //bSuccess
				if (pEff->effect.nOpcode == CEFFECT_OPCODE_USE_EFF_FILE) {
					pEff->effect.ud0[0] = effect.ud0[0];
					pEff->effect.ud0[1] = effect.ud0[1];
					pEff->effect.ud0[2] = effect.ud0[2];
					pEff->effect.ud0[3] = effect.ud0[3];
				} else {
					pEff->effect.nParam1 = effect.ud0[0];
					pEff->effect.nParam2 = effect.ud0[1];
					pEff->effect.nParam3 = effect.ud0[2];
					pEff->effect.nParam4 = effect.ud0[3];
				}
			}

			if (effect.nParam3 || //bSuccess
				pEff->TryApplyEffect(
					creTarget,
					&creTarget.m_cRandSaveDeath,
					&creTarget.m_cRandSaveWand,
					&creTarget.m_cRandSavePolymorph,
					&creTarget.m_cRandSaveBreath,
					&creTarget.m_cRandSaveSpell,
					&creTarget.m_cRandResistMagic,
					&creTarget.m_cRandEffProb
				)
			) {
				effect.nParam3 = TRUE;
				pEff->ApplyEffect(creTarget);
				if (pEff->bPurge) bPurge = TRUE;
				effect.bDoSingleUse = pEff->effect.bDoSingleUse;

				//new - store child effect's parameters and resources
				if (pEff->effect.nOpcode == CEFFECT_OPCODE_USE_EFF_FILE) {
					effect.ud0[0] = pEff->effect.ud0[0];
					effect.ud0[1] = pEff->effect.ud0[1];
					effect.ud0[2] = pEff->effect.ud0[2];
					effect.ud0[3] = pEff->effect.ud0[3];
				} else {
					effect.ud0[0] = pEff->effect.nParam1;
					effect.ud0[1] = pEff->effect.nParam2;
					effect.ud0[2] = pEff->effect.nParam3;
					effect.ud0[3] = pEff->effect.nParam4;
				}
			} else bPurge = TRUE;

			delete pEff;
			pEff = NULL;
		}
	} else bPurge = TRUE;

	return TRUE;
}

//CEffectCastSpellOnCondition
DefineTrampMemberFunc(BOOL, CEffectCastSpellOnCondition, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect, ApplyEffect, 0x53AFB7);

BOOL DETOUR_CEffectCastSpellOnCondition::DETOUR_ApplyEffect(CCreatureObject& creTarget) {
	if (0) IECString("DETOUR_CEffectCastSpellOnCondition::DETOUR_ApplyEffect");

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
		t.o.m_oids.id1 = OBJECT_NEARESTENEMYOF;
		break;
	case 2:
		t.opcode = TRIGGER_HP_PERCENT_LT;
		t.i = 50;
		t.o.m_oids.id1 = OBJECT_MYSELF;
		break;
	case 3:
		t.opcode = TRIGGER_HP_PERCENT_LT;
		t.i = 25;
		t.o.m_oids.id1 = OBJECT_MYSELF;
		break;
	case 4:
		t.opcode = TRIGGER_HP_PERCENT_LT;
		t.i = 10;
		t.o.m_oids.id1 = OBJECT_MYSELF;
		break;
	case 5:
		t.opcode = TRIGGER_STATE_CHECK;
		t.i = STATE_HELPLESS;
		t.o.m_oids.id1 = OBJECT_MYSELF;
		break;
	case 6:
		t.opcode = TRIGGER_STATE_CHECK;
		t.i = STATE_POISONED;
		t.o.m_oids.id1 = OBJECT_MYSELF;
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
		o.m_oids.id1 = OBJECT_MYSELF;
		break;
	case 1:
		o.m_oids.id1 = OBJECT_LASTHITTER;
		break;
	case 2:
		o.m_oids.id1 = OBJECT_NEARESTENEMYOF;
		break;
	case 3:
		o.m_oids.id1 = OBJECT_NOTHING;
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
	g_pChitin->pGame->GetContingencyConditionTexts(&strrefName, &strrefDescription, wParam2Low);
	pConditionalSpell->strrefCondition = strrefName;

	g_pChitin->pGame->GetContingencyTargetTexts(&strrefName, &strrefDescription, (short)effect.nParam1);
	pConditionalSpell->strrefTarget = strrefName;

	creTarget.m_cdsCurrent.m_ConditionalSpells.AddTail(pConditionalSpell);

	if (effect.nParentResourceType == 1 && //spell
		effect.rParentResource.IsNotEmpty()) {
		CSpellProtection* pSpellProt = IENew CSpellProtection();
		pSpellProt->rSpell = effect.rParentResource;
		pSpellProt->strrefMsg = creTarget.GetCurrentObject().m_cEnemyAlly <= EA_CONTROLLEDCUTOFF ? 0x806C : -1;
		creTarget.m_cdsCurrent.m_SpellProtections.AddTail(pSpellProt);
	}

	return TRUE;
}

//CEffectProficiencyMod
DefineTrampMemberFunc(BOOL, CEffectProficiencyMod, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect, ApplyEffect, 0x53B776);

BOOL DETOUR_CEffectProficiencyMod::DETOUR_ApplyEffect(CCreatureObject& creTarget) {
	if (0) IECString("DETOUR_CEffectProficiencyMod::DETOUR_ApplyEffect");

	int wParam2Low = effect.nParam2 & 0xFFFF;  //proficiency
	int wParam2High = effect.nParam2 >> 16; //behaviour

	/*
	unsigned char nClassId = creTarget.o.GetClass();
	unsigned char nClassNew;
	unsigned char nClassOrg;
	creTarget.o.GetDualClasses(&nClassNew, &nClassOrg);
	BOOL bTwoClasses = creTarget.o.HasActiveSubclass(nClassOrg, TRUE);
	unsigned int dwKit = creTarget.m_header.m_wKit[1] | (creTarget.m_header.m_wKit[0] << 16);
	int dwProfsMax = 5;
	if (nClassId < 21) g_pChitin->pGame->GetWeapProfMax(nClassId, nClassNew, nClassOrg, bTwoClasses, wParam2Low, dwKit);
	*/

	switch (wParam2Low) {
	case STATS_PROFICIENCYBASTARDSWORD:
		switch (wParam2High) {
		case 1: //increment
			creTarget.m_cdsDiff.proficiencyBastardSword += effect.nParam1;
			bPurge = FALSE;
		default: //set higher only
			creTarget.m_cdsCurrent.proficiencyBastardSword = max(creTarget.m_cdsCurrent.proficiencyBastardSword, effect.nParam1);
			break;
		}
		break;
	case STATS_PROFICIENCYLONGSWORD:
		switch (wParam2High) {
		case 1: //increment
			creTarget.m_cdsDiff.proficiencyLongSword += effect.nParam1;
			bPurge = FALSE;
		default: //set higher only
			creTarget.m_cdsCurrent.proficiencyLongSword = max(creTarget.m_cdsCurrent.proficiencyLongSword, effect.nParam1);
			break;
		}
		break;
	case STATS_PROFICIENCYSHORTSWORD:
		switch (wParam2High) {
		case 1: //increment
			creTarget.m_cdsDiff.proficiencyShortSword += effect.nParam1;
			bPurge = FALSE;
		default: //set higher only
			creTarget.m_cdsCurrent.proficiencyShortSword = max(creTarget.m_cdsCurrent.proficiencyShortSword, effect.nParam1);
			break;
		}
		break;
	case STATS_PROFICIENCYAXE:
		switch (wParam2High) {
		case 1: //increment
			creTarget.m_cdsDiff.proficiencyAxe += effect.nParam1;
			bPurge = FALSE;
		default: //set higher only
			creTarget.m_cdsCurrent.proficiencyAxe = max(creTarget.m_cdsCurrent.proficiencyAxe, effect.nParam1);
			break;
		}
		break;
	case STATS_PROFICIENCYTWOHANDEDSWORD:
		switch (wParam2High) {
		case 1: //increment
			creTarget.m_cdsDiff.proficiencyTwoHandedSword += effect.nParam1;
			bPurge = FALSE;
		default: //set higher only
			creTarget.m_cdsCurrent.proficiencyTwoHandedSword = max(creTarget.m_cdsCurrent.proficiencyTwoHandedSword, effect.nParam1);
			break;
		}
		break;
	case STATS_PROFICIENCYKATANA:
		switch (wParam2High) {
		case 1: //increment
			creTarget.m_cdsDiff.proficiencyKatana += effect.nParam1;
			bPurge = FALSE;
		default: //set higher only
			creTarget.m_cdsCurrent.proficiencyKatana = max(creTarget.m_cdsCurrent.proficiencyKatana, effect.nParam1);
			break;
		}
		break;
	case STATS_PROFICIENCYSCIMITARWAKISASHININJATO:
		switch (wParam2High) {
		case 1: //increment
			creTarget.m_cdsDiff.proficiencyScimitarWakizashiNinjato += effect.nParam1;
			bPurge = FALSE;
		default: //set higher only
			creTarget.m_cdsCurrent.proficiencyScimitarWakizashiNinjato = max(creTarget.m_cdsCurrent.proficiencyScimitarWakizashiNinjato, effect.nParam1);
			break;
		}
		break;
	case STATS_PROFICIENCYDAGGER:
		switch (wParam2High) {
		case 1: //increment
			creTarget.m_cdsDiff.proficiencyDagger += effect.nParam1;
			bPurge = FALSE;
		default: //set higher only
			creTarget.m_cdsCurrent.proficiencyDagger = max(creTarget.m_cdsCurrent.proficiencyDagger, effect.nParam1);
			break;
		}
		break;
	case STATS_PROFICIENCYWARHAMMER:
		switch (wParam2High) {
		case 1: //increment
			creTarget.m_cdsDiff.proficiencyWarhammer += effect.nParam1;
			bPurge = FALSE;
		default: //set higher only
			creTarget.m_cdsCurrent.proficiencyWarhammer = max(creTarget.m_cdsCurrent.proficiencyWarhammer, effect.nParam1);
			break;
		}
		break;
	case STATS_PROFICIENCYSPEAR:
		switch (wParam2High) {
		case 1: //increment
			creTarget.m_cdsDiff.proficiencySpear += effect.nParam1;
			bPurge = FALSE;
		default: //set higher only
			creTarget.m_cdsCurrent.proficiencySpear = max(creTarget.m_cdsCurrent.proficiencySpear, effect.nParam1);
			break;
		}
		break;
	case STATS_PROFICIENCYHALBERD:
		switch (wParam2High) {
		case 1: //increment
			creTarget.m_cdsDiff.proficiencyHalberd += effect.nParam1;
			bPurge = FALSE;
		default: //set higher only
			creTarget.m_cdsCurrent.proficiencyHalberd = max(creTarget.m_cdsCurrent.proficiencyHalberd, effect.nParam1);
			break;
		}
		break;
	case STATS_PROFICIENCYFLAILMORNINGSTAR:
		switch (wParam2High) {
		case 1: //increment
			creTarget.m_cdsDiff.proficiencyFlailMorningstar += effect.nParam1;
			bPurge = FALSE;
		default: //set higher only
			creTarget.m_cdsCurrent.proficiencyFlailMorningstar = max(creTarget.m_cdsCurrent.proficiencyFlailMorningstar, effect.nParam1);
			break;
		}
		break;
	case STATS_PROFICIENCYMACE:
		switch (wParam2High) {
		case 1: //increment
			creTarget.m_cdsDiff.proficiencyMace += effect.nParam1;
			bPurge = FALSE;
		default: //set higher only
			creTarget.m_cdsCurrent.proficiencyMace = max(creTarget.m_cdsCurrent.proficiencyMace, effect.nParam1);
			break;
		}
		break;
	case STATS_PROFICIENCYQUARTERSTAFF:
		switch (wParam2High) {
		case 1: //increment
			creTarget.m_cdsDiff.proficiencyQuarterstaff += effect.nParam1;
			bPurge = FALSE;
		default: //set higher only
			creTarget.m_cdsCurrent.proficiencyQuarterstaff = max(creTarget.m_cdsCurrent.proficiencyQuarterstaff, effect.nParam1);
			break;
		}
		break;
	case STATS_PROFICIENCYCROSSBOW:
		switch (wParam2High) {
		case 1: //increment
			creTarget.m_cdsDiff.proficiencyCrossbow += effect.nParam1;
			bPurge = FALSE;
		default: //set higher only
			creTarget.m_cdsCurrent.proficiencyCrossbow = max(creTarget.m_cdsCurrent.proficiencyCrossbow, effect.nParam1);
			break;
		}
		break;
	case STATS_PROFICIENCYLONGBOW:
		switch (wParam2High) {
		case 1: //increment
			creTarget.m_cdsDiff.proficiencyLongbow += effect.nParam1;
			bPurge = FALSE;
		default: //set higher only
			creTarget.m_cdsCurrent.proficiencyLongbow = max(creTarget.m_cdsCurrent.proficiencyLongbow, effect.nParam1);
			break;
		}
		break;
	case STATS_PROFICIENCYSHORTBOW:
		switch (wParam2High) {
		case 1: //increment
			creTarget.m_cdsDiff.proficiencyShortbow += effect.nParam1;
			bPurge = FALSE;
		default: //set higher only
			creTarget.m_cdsCurrent.proficiencyShortbow = max(creTarget.m_cdsCurrent.proficiencyShortbow, effect.nParam1);
			break;
		}
		break;
	case STATS_PROFICIENCYDART:
		switch (wParam2High) {
		case 1: //increment
			creTarget.m_cdsDiff.proficiencyDart += effect.nParam1;
			bPurge = FALSE;
		default: //set higher only
			creTarget.m_cdsCurrent.proficiencyDart = max(creTarget.m_cdsCurrent.proficiencyDart, effect.nParam1);
			break;
		}
		break;
	case STATS_PROFICIENCYSLING:
		switch (wParam2High) {
		case 1: //increment
			creTarget.m_cdsDiff.proficiencySling += effect.nParam1;
			bPurge = FALSE;
		default: //set higher only
			creTarget.m_cdsCurrent.proficiencySling = max(creTarget.m_cdsCurrent.proficiencySling, effect.nParam1);
			break;
		}
		break;
	case STATS_PROFICIENCYBLACKJACK:
		switch (wParam2High) {
		case 1: //increment
			creTarget.m_cdsDiff.proficiencyBlackjack += effect.nParam1;
			bPurge = FALSE;
		default: //set higher only
			creTarget.m_cdsCurrent.proficiencyBlackjack = max(creTarget.m_cdsCurrent.proficiencyBlackjack, effect.nParam1);
			break;
		}
		break;
	case STATS_PROFICIENCYGUN:
		switch (wParam2High) {
		case 1: //increment
			creTarget.m_cdsDiff.proficiencyGun += effect.nParam1;
			bPurge = FALSE;
		default: //set higher only
			creTarget.m_cdsCurrent.proficiencyGun = max(creTarget.m_cdsCurrent.proficiencyGun, effect.nParam1);
			break;
		}
		break;
	case STATS_PROFICIENCYMARTIALARTS:
		switch (wParam2High) {
		case 1: //increment
			creTarget.m_cdsDiff.proficiencyMartialArts += effect.nParam1;
			bPurge = FALSE;
		default: //set higher only
			creTarget.m_cdsCurrent.proficiencyMartialArts = max(creTarget.m_cdsCurrent.proficiencyMartialArts, effect.nParam1);
			break;
		}
		break;
	case STATS_PROFICIENCY2HANDED:
		switch (wParam2High) {
		case 1: //increment
			creTarget.m_cdsDiff.proficiencyTwoHanded += effect.nParam1;
			bPurge = FALSE;
		default: //set higher only
			creTarget.m_cdsCurrent.proficiencyTwoHanded = max(creTarget.m_cdsCurrent.proficiencyTwoHanded, effect.nParam1);
			break;
		}
		break;
	case STATS_PROFICIENCYSWORDANDSHIELD:
		switch (wParam2High) {
		case 1: //increment
			creTarget.m_cdsDiff.proficiencySwordAndShield += effect.nParam1;
			bPurge = FALSE;
		default: //set higher only
			creTarget.m_cdsCurrent.proficiencySwordAndShield = max(creTarget.m_cdsCurrent.proficiencySwordAndShield, effect.nParam1);
			break;
		}
		break;
	case STATS_PROFICIENCYSINGLEWEAPON:
		switch (wParam2High) {
		case 1: //increment
			creTarget.m_cdsDiff.proficiencySingleWeapon += effect.nParam1;
			bPurge = FALSE;
		default: //set higher only
			creTarget.m_cdsCurrent.proficiencySingleWeapon = max(creTarget.m_cdsCurrent.proficiencySingleWeapon, effect.nParam1);
			break;
		}
		break;
	case STATS_PROFICIENCY2WEAPON:
		switch (wParam2High) {
		case 1: //increment
			creTarget.m_cdsDiff.proficiencyTwoWeapon += effect.nParam1;
			bPurge = FALSE;
		default: //set higher only
			creTarget.m_cdsCurrent.proficiencyTwoWeapon = max(creTarget.m_cdsCurrent.proficiencyTwoWeapon, effect.nParam1);
			break;
		}
		break;
	case STATS_EXTRAPROFICIENCY1:
		switch (wParam2High) {
		case 1: //increment
			creTarget.m_cdsDiff.proficiencyExtra1 += effect.nParam1;
			bPurge = FALSE;
		default: //set higher only
			creTarget.m_cdsCurrent.proficiencyExtra1 = max(creTarget.m_cdsCurrent.proficiencyExtra1, effect.nParam1);
			break;
		}
		break;
	case STATS_EXTRAPROFICIENCY2:
		switch (wParam2High) {
		case 1: //increment
			creTarget.m_cdsDiff.proficiencyExtra2 += effect.nParam1;
			bPurge = FALSE;
		default: //set higher only
			creTarget.m_cdsCurrent.proficiencyExtra2 = max(creTarget.m_cdsCurrent.proficiencyExtra2, effect.nParam1);
			break;
		}
		break;
	case STATS_EXTRAPROFICIENCY3:
		switch (wParam2High) {
		case 1: //increment
			creTarget.m_cdsDiff.proficiencyExtra3 += effect.nParam1;
			bPurge = FALSE;
		default: //set higher only
			creTarget.m_cdsCurrent.proficiencyExtra3 = max(creTarget.m_cdsCurrent.proficiencyExtra3, effect.nParam1);
			break;
		}
		break;
	case STATS_EXTRAPROFICIENCY4:
		switch (wParam2High) {
		case 1: //increment
			creTarget.m_cdsDiff.proficiencyExtra4 += effect.nParam1;
			bPurge = FALSE;
		default: //set higher only
			creTarget.m_cdsCurrent.proficiencyExtra4 = max(creTarget.m_cdsCurrent.proficiencyExtra4, effect.nParam1);
			break;
		}
		break;
	case STATS_EXTRAPROFICIENCY5:
		switch (wParam2High) {
		case 1: //increment
			creTarget.m_cdsDiff.proficiencyExtra5 += effect.nParam1;
			bPurge = FALSE;
		default: //set higher only
			creTarget.m_cdsCurrent.proficiencyExtra5 = max(creTarget.m_cdsCurrent.proficiencyExtra5, effect.nParam1);
			break;
		}
		break;
	case STATS_EXTRAPROFICIENCY6:
		switch (wParam2High) {
		case 1: //increment
			creTarget.m_cdsDiff.proficiencyExtra6 += effect.nParam1;
			bPurge = FALSE;
		default: //set higher only
			creTarget.m_cdsCurrent.proficiencyExtra6 = max(creTarget.m_cdsCurrent.proficiencyExtra6, effect.nParam1);
			break;
		}
		break;
	case STATS_EXTRAPROFICIENCY7:
		switch (wParam2High) {
		case 1: //increment
			creTarget.m_cdsDiff.proficiencyExtra7 += effect.nParam1;
			bPurge = FALSE;
		default: //set higher only
			creTarget.m_cdsCurrent.proficiencyExtra7 = max(creTarget.m_cdsCurrent.proficiencyExtra7, effect.nParam1);
			break;
		}
		break;
	case STATS_EXTRAPROFICIENCY8:
		switch (wParam2High) {
		case 1: //increment
			creTarget.m_cdsDiff.proficiencyExtra8 += effect.nParam1;
			bPurge = FALSE;
		default: //set higher only
			creTarget.m_cdsCurrent.proficiencyExtra8 = max(creTarget.m_cdsCurrent.proficiencyExtra8, effect.nParam1);
			break;
		}
		break;
	case STATS_EXTRAPROFICIENCY9:
		switch (wParam2High) {
		case 1: //increment
			creTarget.m_cdsDiff.proficiencyExtra9 += effect.nParam1;
			bPurge = FALSE;
		default: //set higher only
			creTarget.m_cdsCurrent.proficiencyExtra9 = max(creTarget.m_cdsCurrent.proficiencyExtra9, effect.nParam1);
			break;
		}
		break;
	case STATS_EXTRAPROFICIENCY10:
		switch (wParam2High) {
		case 1: //increment
			creTarget.m_cdsDiff.proficiencyExtra10 += effect.nParam1;
			bPurge = FALSE;
		default: //set higher only
			creTarget.m_cdsCurrent.proficiencyExtra10 = max(creTarget.m_cdsCurrent.proficiencyExtra10, effect.nParam1);
			break;
		}
		break;
	case STATS_EXTRAPROFICIENCY11:
		switch (wParam2High) {
		case 1: //increment
			creTarget.m_cdsDiff.proficiencyExtra11 += effect.nParam1;
			bPurge = FALSE;
		default: //set higher only
			creTarget.m_cdsCurrent.proficiencyExtra11 = max(creTarget.m_cdsCurrent.proficiencyExtra11, effect.nParam1);
			break;
		}
		break;
	case STATS_EXTRAPROFICIENCY12:
		switch (wParam2High) {
		case 1: //increment
			creTarget.m_cdsDiff.proficiencyExtra12 += effect.nParam1;
			bPurge = FALSE;
		default: //set higher only
			creTarget.m_cdsCurrent.proficiencyExtra12 = max(creTarget.m_cdsCurrent.proficiencyExtra12, effect.nParam1);
			break;
		}
		break;
	case STATS_EXTRAPROFICIENCY13:
		switch (wParam2High) {
		case 1: //increment
			creTarget.m_cdsDiff.proficiencyExtra13 += effect.nParam1;
			bPurge = FALSE;
		default: //set higher only
			creTarget.m_cdsCurrent.proficiencyExtra13 = max(creTarget.m_cdsCurrent.proficiencyExtra13, effect.nParam1);
			break;
		}
		break;
	case STATS_EXTRAPROFICIENCY14:
		switch (wParam2High) {
		case 1: //increment
			creTarget.m_cdsDiff.proficiencyExtra14 += effect.nParam1;
			bPurge = FALSE;
		default: //set higher only
			creTarget.m_cdsCurrent.proficiencyExtra14 = max(creTarget.m_cdsCurrent.proficiencyExtra14, effect.nParam1);
			break;
		}
		break;
	case STATS_EXTRAPROFICIENCY15:
		switch (wParam2High) {
		case 1: //increment
			creTarget.m_cdsDiff.proficiencyExtra15 += effect.nParam1;
			bPurge = FALSE;
		default: //set higher only
			creTarget.m_cdsCurrent.proficiencyExtra15 = max(creTarget.m_cdsCurrent.proficiencyExtra15, effect.nParam1);
			break;
		}
		break;
	case STATS_EXTRAPROFICIENCY16:
		switch (wParam2High) {
		case 1: //increment
			creTarget.m_cdsDiff.proficiencyExtra16 += effect.nParam1;
			bPurge = FALSE;
		default: //set higher only
			creTarget.m_cdsCurrent.proficiencyExtra16 = max(creTarget.m_cdsCurrent.proficiencyExtra16, effect.nParam1);
			break;
		}
		break;
	case STATS_EXTRAPROFICIENCY17:
		switch (wParam2High) {
		case 1: //increment
			creTarget.m_cdsDiff.proficiencyExtra17 += effect.nParam1;
			bPurge = FALSE;
		default: //set higher only
			creTarget.m_cdsCurrent.proficiencyExtra17 = max(creTarget.m_cdsCurrent.proficiencyExtra17, effect.nParam1);
			break;
		}
		break;
	case STATS_EXTRAPROFICIENCY18:
		switch (wParam2High) {
		case 1: //increment
			creTarget.m_cdsDiff.proficiencyExtra18 += effect.nParam1;
			bPurge = FALSE;
		default: //set higher only
			creTarget.m_cdsCurrent.proficiencyExtra18 = max(creTarget.m_cdsCurrent.proficiencyExtra18, effect.nParam1);
			break;
		}
		break;
	case STATS_EXTRAPROFICIENCY19:
		switch (wParam2High) {
		case 1: //increment
			creTarget.m_cdsDiff.proficiencyExtra19 += effect.nParam1;
			bPurge = FALSE;
		default: //set higher only
			creTarget.m_cdsCurrent.proficiencyExtra19 = max(creTarget.m_cdsCurrent.proficiencyExtra19, effect.nParam1);
			break;
		}
		break;
	case STATS_EXTRAPROFICIENCY20:
		switch (wParam2High) {
		case 1: //increment
			creTarget.m_cdsDiff.proficiencyExtra20 += effect.nParam1;
			bPurge = FALSE;
		default: //set higher only
			creTarget.m_cdsCurrent.proficiencyExtra20 = max(creTarget.m_cdsCurrent.proficiencyExtra20, effect.nParam1);
			break;
		}
		break;
	default:
		LPCTSTR lpsz = "DETOUR_CEffectProficiencyMod::DETOUR_ApplyEffect(): Invalid wParam2Low\r\n";
		L.timestamp();
		L.append(lpsz);
		console.write(lpsz);
		break;
	}
	return TRUE;
}

//CEffectRepeatingEff
DefineTrampMemberFunc(CEffectRepeatingEff&, CEffectRepeatingEff, Construct, (ItmFileEffect& eff, CPoint& ptSource, ENUM eSource, int ptDestX, int ptDestY), Construct, Construct5, 0x561AA0);
DefineTrampMemberFunc(BOOL, CEffectRepeatingEff, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect, ApplyEffect, 0x541C3B);

CEffectRepeatingEff& DETOUR_CEffectRepeatingEff::DETOUR_Construct(ItmFileEffect& eff, CPoint& ptSource, ENUM eSource, int ptDestX, int ptDestY) {
	if (0) IECString("DETOUR_CEffectRepeatingEff::DETOUR_Construct");

	CEffectRepeatingEff& e = (this->*Tramp_CEffectRepeatingEff_Construct5)(eff, ptSource, eSource, ptDestX, ptDestY);
	e.effect.nParam4 = g_pChitin->pGame->m_WorldTimer.nGameTime;
	return e;
}

BOOL DETOUR_CEffectRepeatingEff::DETOUR_ApplyEffect(CCreatureObject& creTarget) {
	if (0) IECString("DETOUR_CEffectRepeatingEff::DETOUR_ApplyEffect");

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
		pRepeat->nTicksLeft = nDuration - g_pChitin->pGame->m_WorldTimer.nGameTime;
		pRepeat->wSecondsElapsed = 0;
		break;
	case 2:
		pRepeat->wMode = 2;
		pRepeat->wPostDelayDuration = 1;
		pRepeat->wAmount = effect.nParam1;
		pRepeat->wPeriod = 1;
		pRepeat->nTicksLeft = nDuration - g_pChitin->pGame->m_WorldTimer.nGameTime;
		pRepeat->wSecondsElapsed = 0;
		break;
	case 3:
		pRepeat->wMode = 3;
		pRepeat->wPostDelayDuration = 1;
		pRepeat->wAmount = 1;
		pRepeat->wPeriod = effect.nParam1;
		pRepeat->nTicksLeft = nDuration - g_pChitin->pGame->m_WorldTimer.nGameTime;
		pRepeat->wSecondsElapsed = (g_pChitin->pGame->m_WorldTimer.nGameTime - nTicksBegan) / 15 % pRepeat->wPeriod;
		break;
	case 4:
		pRepeat->wMode = 3;
		pRepeat->wPostDelayDuration = 1;
		pRepeat->wAmount = effect.nParam3;
		pRepeat->wPeriod = effect.nParam1;
		pRepeat->nTicksLeft = nDuration - g_pChitin->pGame->m_WorldTimer.nGameTime;
		pRepeat->wSecondsElapsed = (g_pChitin->pGame->m_WorldTimer.nGameTime - nTicksBegan) / 15 % pRepeat->wPeriod;
		break;
	case 1:
	default:
		LPCTSTR lpsz = "DETOUR_CEffectRepeatingEff::DETOUR_ApplyEffect(): invalid effect.nParam2 low word (%d)\r\n";
		console.writef(lpsz, wParam2Low);
		L.timestamp();
		L.appendf(lpsz, wParam2Low);
		bPurge = TRUE;
		break;
	}

	creTarget.m_cdsCurrent.m_RepeatingEffs.AddTail(pRepeat);

	return TRUE;
}

//CEffectWingBuffet
DefineTrampMemberFunc(BOOL, CEffectWingBuffet, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect, ApplyEffect, 0x53C791);

BOOL DETOUR_CEffectWingBuffet::DETOUR_ApplyEffect(CCreatureObject& creTarget) {
	if (0) IECString("DETOUR_CEffectWingBuffet::DETOUR_ApplyEffect");

	if ((unsigned int)effect.nParam2 < 5)
		CDerivedStats_SetStat(creTarget.m_cdsCurrent, CDERIVEDSTATSEX_BASE + CDERIVEDSTATSEX_WINGBUFFET, effect.nParam2);
	return (this->*Tramp_CEffectWingBuffet_ApplyEffect)(creTarget);
}

//CEffectDisintegrate
DefineTrampMemberFunc(BOOL, CEffectDisintegrate, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect, ApplyEffect, 0x53F01D);

BOOL DETOUR_CEffectDisintegrate::DETOUR_ApplyEffect(CCreatureObject& creTarget) {
	if (0) IECString("DETOUR_CEffectDisintegrate::DETOUR_ApplyEffect");

	Object& o = creTarget.GetCurrentObject();
	BOOL bMatch = FALSE;
	switch (effect.nParam2) {
	case 2:
		if (o.m_cEnemyAlly == effect.nParam1 || effect.nParam1 == 0) bMatch = TRUE;
		break;
	case 3:
		if (o.m_cGeneral == effect.nParam1 || effect.nParam1 == 0) bMatch = TRUE;
		break;
	case 4:
		if (o.m_cRace == effect.nParam1 || effect.nParam1 == 0) bMatch = TRUE;
		break;
	case 5:
		{
			unsigned char nClass = o.GetClass();
			unsigned char nClassNew;
			unsigned char nClassOrg;
			o.GetDualClasses(&nClassNew, &nClassOrg);
			if (nClassNew != nClassOrg && //dual-classed
				!o.HasActiveSubclass(nClassOrg, TRUE)) {
				nClass = nClassNew;
			}
			if (nClass == effect.nParam1 || effect.nParam1 == 0) bMatch = TRUE;
			break;
		}
	case 6:
		if (o.m_cSpecific == effect.nParam1 || effect.nParam1 == 0) bMatch = TRUE;
		break;
	case 7:
		if (o.m_cGender == effect.nParam1 || effect.nParam1 == 0) bMatch = TRUE;
		break;
	case 8:
		if (
			(o.m_cAlignment == effect.nParam1 || effect.nParam1 == 0) ||
			(effect.nParam1 == ALIGN_MASK_GOOD && (o.m_cAlignment & 0xF) == ALIGN_MASK_GOOD) ||
			(effect.nParam2 == ALIGN_MASK_NEUTRAL && (o.m_cAlignment & 0xF) == ALIGN_MASK_NEUTRAL) ||
			(effect.nParam2 == ALIGN_MASK_EVIL && (o.m_cAlignment & 0xF) == ALIGN_MASK_EVIL) ||
			(effect.nParam2 == ALIGN_LAWFUL_MASK && (o.m_cAlignment & 0xF0) == ALIGN_LAWFUL_MASK) ||
			(effect.nParam2 == ALIGN_NEUTRAL_MASK && (o.m_cAlignment & 0xF0) == ALIGN_NEUTRAL_MASK) ||
			(effect.nParam2 == ALIGN_CHAOTIC_MASK && (o.m_cAlignment & 0xF0) == ALIGN_CHAOTIC_MASK)
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

//CEffectRemoveProjectile
DefineTrampMemberFunc(BOOL, CEffectRemoveProjectile, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect, ApplyEffect, 0x53F5D8);

BOOL DETOUR_CEffectRemoveProjectile::DETOUR_ApplyEffect(CCreatureObject& creTarget) {
	if (0) IECString("DETOUR_CEffectRemoveProjectile::DETOUR_ApplyEffect");

	CArea* pArea = creTarget.pArea;
	if (pArea == NULL) return TRUE;
	
	switch (effect.nParam1) {
	case 1:
		{
			CMessageRemoveAreaAirEffectSpecific* pMsg = new CMessageRemoveAreaAirEffectSpecific();
			pMsg->rAreaName = pArea->rAreaName;
			pMsg->rResource = effect.rResource;
			g_pChitin->m_MessageHandler.AddMessage(*pMsg, FALSE);
		}
		break;
	default:
		{
			CMessageRemoveAreaAirEffects* pMsg = IENew CMessageRemoveAreaAirEffects();
			pMsg->rAreaName = pArea->rAreaName;
			g_pChitin->m_MessageHandler.AddMessage(*pMsg, FALSE);
		}
		break;
	}
	bPurge = 1;
	return TRUE;
	
}

//CEffectEnableButton
DefineTrampMemberFunc(BOOL, CEffectEnableButton, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect, ApplyEffect, 0x52B9AA);

BOOL DETOUR_CEffectEnableButton::DETOUR_ApplyEffect(CCreatureObject& creTarget) {
	if (0) IECString("DETOUR_CEffectEnableButton::DETOUR_ApplyEffect");

	if ((unsigned int)effect.nParam2 < 14)
		creTarget.m_cdsCurrent.ButtonDisable[effect.nParam2] = 0;
	if ((unsigned int)effect.nParam2 < 15)
		CDerivedStats_SetStat(creTarget.m_cdsCurrent, CDERIVEDSTATSEX_BASE + CDERIVEDSTATSEX_BUTTONDISABLESTEALTH + effect.nParam2, 0);
	if ((unsigned int)effect.nParam2 < 15) {
		creTarget.m_EffectsEquipped.RemoveEffect(creTarget, CEFFECT_OPCODE_DISABLE_BUTTON, creTarget.m_EffectsEquipped.posItrPrev, effect.nParam2, effect.rResource, FALSE);
		creTarget.m_TimedEffectList.RemoveEffect(creTarget, CEFFECT_OPCODE_DISABLE_BUTTON, creTarget.m_TimedEffectList.posItrPrev, effect.nParam2, effect.rResource, FALSE);
	}

	bPurge = TRUE;
	return TRUE;
}

//CEffectCutScene2
DefineTrampMemberFunc(BOOL, CEffectCutScene2, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect, ApplyEffect, 0x542815);

BOOL DETOUR_CEffectCutScene2::DETOUR_ApplyEffect(CCreatureObject& creTarget) {
	if (0) IECString("DETOUR_CEffectCutScene2::DETOUR_ApplyEffect");

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
	g_pChitin->m_MessageHandler.AddMessage(*pcmCSM, FALSE);

	CMessageAddActionHead* pcmA = IENew CMessageAddActionHead();
	pcmA->eTarget = pGame->ePlayersPartyOrder[0];
	pcmA->eSource = pGame->ePlayersPartyOrder[0];
	pcmA->a.opcode = 120; //StartCutScene
	pcmA->a.sName1 = effect.nParam2 ? IECString(effect.rResource.GetBuffer()) : "cut250a";
	pcmA->a.dwFlags |= 1;
	g_pChitin->m_MessageHandler.AddMessage(*pcmA, FALSE);

	bPurge = TRUE;
	return TRUE;
}

//CEffectAnimationRemoval
DefineTrampMemberFunc(BOOL, CEffectAnimationRemoval, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect, ApplyEffect, 0x549C0C);

BOOL DETOUR_CEffectAnimationRemoval::DETOUR_ApplyEffect(CCreatureObject& creTarget) {
	if (0) IECString("DETOUR_CEffectAnimationRemoval::DETOUR_ApplyEffect");

	DWORD nSize = pRuleEx->m_nStats - 200;

	if (creTarget.m_cdsCurrent.animationRemoval) {
		int* pStatsEx = (int*)creTarget.m_cdsCurrent.animationRemoval;
		pStatsEx[0] = effect.nParam2;
	} else {
		LPCTSTR lpsz = "DETOUR_CEffectAnimationRemoval::DETOUR_ApplyEffect(): pStatsEx == NULL\r\n";
		L.timestamp();
		L.append(lpsz);
		console.write(lpsz);
	}

	return TRUE;
}

//CEffectSetStat
CEffectSetStat::CEffectSetStat(ItmFileEffect& data, CPoint& ptSource, ENUM eSource, int destX, int destY, BOOL bUseDice, ENUM e2) \
	: CEffect(data, ptSource, eSource, destX, destY, bUseDice, e2) {}

CEffect& CEffectSetStat::Copy() {
	CEffectSetStat* pceff = new CEffectSetStat(ToItemEffect(), effect.ptSource, eSource, effect.ptDest.x, effect.ptDest.y, FALSE, ENUM_INVALID_INDEX);
	pceff->Unmarshal(effect);
	return *pceff;
}

BOOL CEffectSetStat::ApplyEffect(CCreatureObject& creTarget) {
	short nOpcode = effect.nParam2 & 0xFFFF;
	short nModType = effect.nParam2 >> 16;

	DWORD nSize = pRuleEx->m_nStats;

	if (nOpcode < 387) {
		LPCTSTR lpsz = "CEffectSetStat::ApplyEffect(): Tried to set a stat with index < 387 (expected 387-%d)\r\n";
		L.timestamp();
		L.appendf(lpsz, nSize);
		console.writef(lpsz, nSize);
		return TRUE;
	}

	if (nOpcode > nSize) {
		LPCTSTR lpsz = "CEffectSetStat::ApplyEffect(): nOpcode out of bounds (expected maximum %d)\r\n";
		L.timestamp();
		L.appendf(lpsz, nSize);
		console.writef(lpsz, nSize);
		return TRUE;
	}

	if (!creTarget.m_cdsCurrent.animationRemoval) {
		LPCTSTR lpsz = "CEffectSetStat::ApplyEffect(): creTarget.m_cdsCurrent.pStatsEx == NULL\r\n";
		L.timestamp();
		L.append(lpsz);
		console.write(lpsz);
		return TRUE;
	}

	int* pStatsEx = (int*)creTarget.m_cdsCurrent.animationRemoval;

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
			L.appendf(lpsz, nSize);
			console.writef(lpsz, nSize);
			return TRUE;
		}
		break;
	case 5: //modulus
		if (effect.nParam1 != 0) {
			pStatsEx[nOpcode - 200 - 1] %= effect.nParam1;
		} else {
			LPCTSTR lpsz = "CEffectSetStat::ApplyEffect(): Tried to divide by zero\r\n";
			L.timestamp();
			L.appendf(lpsz, nSize);
			console.writef(lpsz, nSize);
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
		pStatsEx[nOpcode - 200 - 1] = pStatsEx[nOpcode - 200 - 1] & effect.nParam1;
		break;
	case 9: //bitwise or
		pStatsEx[nOpcode - 200 - 1] = pStatsEx[nOpcode - 200 - 1] | effect.nParam1;
		break;
	case 10: //not
		pStatsEx[nOpcode - 200 - 1] = !pStatsEx[nOpcode - 200 - 1];
		break;
	default:
		LPCTSTR lpsz = "CEffectSetStat::ApplyEffect(): nModType %d invalid (expected 0-10)\r\n";
		L.timestamp();
		L.appendf(lpsz, nModType);
		console.writef(lpsz, nModType);
		break;
	}

	return TRUE;
}

void __stdcall CEffectPolymorph_ApplyEffect_ReinitAnimation(CEffect& eff, CCreatureObject& creTarget, CCreatureObject& creNew) {
	short wOrient = creTarget.m_wDirection;
	short wAnimId = eff.effect.nParam1;
	AnimData* pAD = &creTarget.m_animation;
	bool bAnimMatch = wAnimId == pAD->pAnimation->wAnimId;

	if (!bAnimMatch) {
		delete pAD->pAnimation;
		pAD->pAnimation = NULL;
		pAD->pAnimation = CAnimation::CreateAnimation(wAnimId, creNew.m_header.m_colors, wOrient);
	}

	for (int i = 0; i < 7; i++) {
		ColorPal* pColor = IENew ColorPal();
		pColor->m_cColorGroup = i;
		pColor->m_cGroupRangeId = *((char*)&creNew.m_header.m_colors + i);
		creTarget.m_cdsCurrent.ColorListPal.AddTail(pColor);
		if (bAnimMatch) pAD->pAnimation->SetColorRange(pColor->m_cColorGroup, pColor->m_cGroupRangeId);
	}

	return;
}

