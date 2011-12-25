#include "hook.h"

#include "stdafx.h"
#include "detoursext.h"
#include "options.h"

#include "AnimationCore.h"
#include "Animation1000.h"
#include "Animation1200.h"
#include "Animation1300.h"
#include "Animation2000.h"
#include "Animation5000.h"
#include "Animation6400.h"
#include "Animation7000.h"
#include "Animation7300.h"
#include "Animation8000.h"
#include "Animation9000.h"
#include "AnimationA000.h"
#include "AnimationC000.h"
#include "AreaCore.h"
#include "ChitinCore.h"
#include "EffectCore.h"
#include "EffectOpcode.h"
#include "EngineChargen.h"
#include "EngineRecord.h"
#include "EngineMageBook.h"
#include "EnginePriestBook.h"
#include "InfGameCore.h"
#include "LogCore.h"
#include "ObjectCreature.h"
#include "ObjectStats.h"
#include "SoundCore.h"
#include "UserCore.h"
#include "UserButton.h"
#include "VideoCore.h"


void InitHooks() {

    DetourMemberFunction(Tramp_CBaldurChitin_Construct, DETOUR_CBaldurChitin::DETOUR_Construct);
	DetourMemberFunction(Tramp_CRuleTables_Construct, DETOUR_CRuleTables::DETOUR_Construct);
	DetourMemberFunction(Tramp_CRuleTables_Deconstruct, DETOUR_CRuleTables::DETOUR_Deconstruct);
	DetourFunction(Tramp_CloseLogAndErr, DETOUR_CloseLogAndErr);

	if (pGameOptionsEx->bDebugExternalLogging)
		DetourFunction(Tramp_WriteToFile, DETOUR_WriteToFile);
	if (pGameOptionsEx->bDebugLogFailures)
		DetourFunction(Tramp_AssertFailedQuit, DETOUR_AssertFailedQuit);
	if (pGameOptionsEx->bDebugLogWarnings)
		DetourFunction(Tramp_AssertFailedContinue, DETOUR_AssertFailedContinue);

	DetourMemberFunction(Tramp_CEffect_CreateEffect, DETOUR_CEffect::DETOUR_CreateEffect);
	if (pGameOptionsEx->bEffAttacksPerRoundFix) {
		DetourMemberFunction(Tramp_CDerivedStats_OpAdd, DETOUR_CDerivedStats::DETOUR_OpAdd);
		DetourMemberFunction(Tramp_CEffectAttacksPerRoundMod_ApplyEffect, DETOUR_CEffectAttacksPerRoundMod::DETOUR_ApplyEffect);
	}
	if (pGameOptionsEx->bEffDamageAwaken)
		DetourMemberFunction(Tramp_CEffectDamage_ApplyEffect, DETOUR_CEffectDamage::DETOUR_ApplyEffect);
	if (pGameOptionsEx->nEffBlindnessFix)
		DetourMemberFunction(Tramp_CEffectBlindness_ApplyEffect, DETOUR_CEffectBlindness::DETOUR_ApplyEffect);
	if (pGameOptionsEx->bEffDispelMagicalItemConfig)
		DetourMemberFunction(Tramp_CEffectDispel_ApplyEffect, DETOUR_CEffectDispel::DETOUR_ApplyEffect);
	if (pGameOptionsEx->bEffDiseaseFix)
		DetourMemberFunction(Tramp_CEffectDisease_ApplyEffect, DETOUR_CEffectDisease::DETOUR_ApplyEffect);
	if (pGameOptionsEx->bEffCutScene2Extend)
		DetourMemberFunction(Tramp_CEffectCutScene2_ApplyEffect, DETOUR_CEffectCutScene2::DETOUR_ApplyEffect);
	if (pGameOptionsEx->bEffMagicResistFix)
		DetourMemberFunction(Tramp_CEffectMagicResistMod_ApplyEffect, DETOUR_CEffectMagicResistMod::DETOUR_ApplyEffect);
	if (pGameOptionsEx->bEffPoisonFix)
		DetourMemberFunction(Tramp_CEffectPoison_ApplyEffect, DETOUR_CEffectPoison::DETOUR_ApplyEffect);
	if (pGameOptionsEx->bEffRegenerationFix)
		DetourMemberFunction(Tramp_CEffectRegeneration_ApplyEffect, DETOUR_CEffectRegeneration::DETOUR_ApplyEffect);
	if (pGameOptionsEx->bEffRepeatingEffFix) {
		DetourMemberFunction(Tramp_CEffectRepeatingEff_Construct_5, DETOUR_CEffectRepeatingEff::DETOUR_Construct);
		DetourMemberFunction(Tramp_CEffectRepeatingEff_ApplyEffect, DETOUR_CEffectRepeatingEff::DETOUR_ApplyEffect);
	}

	if (pGameOptionsEx->bEngineExternClassRaceRestrictions) {
		DetourFunction(Tramp_CAnimation_IsPlayableAnimation, DETOUR_CAnimation::DETOUR_IsPlayableAnimation);
		DetourMemberFunction(Tramp_CAnimation5000_Construct, DETOUR_CAnimation5000::DETOUR_Construct);
		DetourMemberFunction(Tramp_CRuleTables_IsMageSchoolAllowed, DETOUR_CRuleTables::DETOUR_IsMageSchoolAllowed);
		DetourMemberFunction(Tramp_CCharGen_ClassPanelOnUpdate, DETOUR_CCharGen::DETOUR_ClassPanelOnUpdate);
		DetourMemberFunction(Tramp_CCharGen_MulticlassPanelOnUpdate, DETOUR_CCharGen::DETOUR_MulticlassPanelOnUpdate);
		DetourMemberFunction(Tramp_CCharGen_MageSchoolPanelOnUpdate, DETOUR_CCharGen::DETOUR_MageSchoolPanelOnUpdate);
	}
	if (pGameOptionsEx->bEngineProficiencyRestrictions) {
		DetourMemberFunction(Tramp_CRuleTables_GetWeapProfMax, DETOUR_CRuleTables::DETOUR_GetWeapProfMax);
	}

	if (pGameOptionsEx->bMusicSonglistExtend) {
		DetourMemberFunction(Tramp_CSoundMixer_InitSonglist, DETOUR_CSoundMixer::DETOUR_InitSonglist);
		DetourMemberFunction(Tramp_CArea_GetSong, DETOUR_CArea::DETOUR_GetSong);
	}

	if (pGameOptionsEx->bSoundAnimAttackSounds)
		DetourMemberFunction(Tramp_CAnimation_PlayCurrentSequenceSound, DETOUR_CAnimation::DETOUR_PlayCurrentSequenceSound);

	if (pGameOptionsEx->bSoundExternWalkSounds) {
		DetourMemberFunction(Tramp_CAnimation_GetWalkingSound, DETOUR_CAnimation::DETOUR_GetWalkingSound);
		DetourMemberFunction(Tramp_CAnimation1000_GetWalkingSound, DETOUR_CAnimation1000::DETOUR_GetWalkingSound);
		DetourMemberFunction(Tramp_CAnimation1200_GetWalkingSound, DETOUR_CAnimation1200::DETOUR_GetWalkingSound);
		DetourMemberFunction(Tramp_CAnimation1300_GetWalkingSound, DETOUR_CAnimation1300::DETOUR_GetWalkingSound);
		DetourMemberFunction(Tramp_CAnimation2000_GetWalkingSound, DETOUR_CAnimation2000::DETOUR_GetWalkingSound);
		DetourMemberFunction(Tramp_CAnimation5000_GetWalkingSound, DETOUR_CAnimation5000::DETOUR_GetWalkingSound);
		DetourMemberFunction(Tramp_CAnimation6400_GetWalkingSound, DETOUR_CAnimation6400::DETOUR_GetWalkingSound);
		DetourMemberFunction(Tramp_CAnimation7000_GetWalkingSound, DETOUR_CAnimation7000::DETOUR_GetWalkingSound);
		DetourMemberFunction(Tramp_CAnimation7300_GetWalkingSound, DETOUR_CAnimation7300::DETOUR_GetWalkingSound);
		DetourMemberFunction(Tramp_CAnimation8000_GetWalkingSound, DETOUR_CAnimation8000::DETOUR_GetWalkingSound);
		DetourMemberFunction(Tramp_CAnimation9000_GetWalkingSound, DETOUR_CAnimation9000::DETOUR_GetWalkingSound);
		DetourMemberFunction(Tramp_CAnimationA000_GetWalkingSound, DETOUR_CAnimationA000::DETOUR_GetWalkingSound);
		DetourMemberFunction(Tramp_CAnimationC000_GetWalkingSound, DETOUR_CAnimationC000::DETOUR_GetWalkingSound);
	}

	if (pGameOptionsEx->bSoundSoundsetSubtitles) {
		DetourMemberFunction(Tramp_CRecord_UpdateCharacter, DETOUR_CRecord::DETOUR_UpdateCharacter);
		DetourMemberFunction(Tramp_CCharGen_InitSoundset, DETOUR_CCharGen::DETOUR_InitSoundset);
	}

	DetourFunction(Tramp_CreateUIControl, DETOUR_CreateUIControl);
	if (pGameOptionsEx->bUserExternMageSpellHiding) {
		DetourMemberFunction(Tramp_CRuleTables_GetMageSpellRefAutoPick, DETOUR_CRuleTables::DETOUR_GetMageSpellRefAutoPick);
		DetourMemberFunction(Tramp_CRuleTables_GetMageSpellRef, DETOUR_CRuleTables::DETOUR_GetMageSpellRef);
	}
	if (pGameOptionsEx->bUserChargenMageSpellScroll) {
		DetourMemberFunction(Tramp_CCharGen_MageBookPanelOnUpdate, DETOUR_CCharGen::DETOUR_MageBookPanelOnUpdate);
		DetourMemberFunction(Tramp_CCharGen_MageBookPanelOnLoad, DETOUR_CCharGen::DETOUR_MageBookPanelOnLoad);
	}
	if (pGameOptionsEx->bUserChargenKitSelectScroll) {
		DetourMemberFunction(Tramp_CCharGen_KitPanelOnUpdate, DETOUR_CCharGen::DETOUR_KitPanelOnUpdate);
		DetourMemberFunction(Tramp_CCharGen_KitPanelOnLoad, DETOUR_CCharGen::DETOUR_KitPanelOnLoad);
		DetourMemberFunction(Tramp_CUICheckButtonChargenKit_GetKitId, DETOUR_CUICheckButtonChargenKit::DETOUR_GetKitId);
		DetourMemberFunction(Tramp_CUICheckButtonChargenKit_GetKitHelpText, DETOUR_CUICheckButtonChargenKit::DETOUR_GetKitHelpText);
	}
	if (pGameOptionsEx->bUserRecordMageSpellScroll) {
		DetourMemberFunction(Tramp_CRecord_MageBookPanelOnUpdate, DETOUR_CRecord::DETOUR_MageBookPanelOnUpdate);
		DetourMemberFunction(Tramp_CRecord_MageBookPanelOnLoad, DETOUR_CRecord::DETOUR_MageBookPanelOnLoad);
	}
	if (pGameOptionsEx->bUserMageBookScroll) {
		DetourMemberFunction(Tramp_CMageBook_SetLevel, DETOUR_CMageBook::DETOUR_SetLevel);
		DetourMemberFunction(Tramp_CCreatureObject_GetKnownSpellMage, DETOUR_CCreatureObject::DETOUR_GetKnownSpellMage);
		DetourMemberFunction(Tramp_CCreatureObject_AddMemSpellMage, DETOUR_CCreatureObject::DETOUR_AddMemSpellMage);
	}
	if (pGameOptionsEx->bUserPriestBookScroll) {
		DetourMemberFunction(Tramp_CPriestBook_SetLevel, DETOUR_CPriestBook::DETOUR_SetLevel);
		DetourMemberFunction(Tramp_CCreatureObject_GetKnownSpellPriest, DETOUR_CCreatureObject::DETOUR_GetKnownSpellPriest);
		DetourMemberFunction(Tramp_CCreatureObject_AddMemSpellPriest, DETOUR_CCreatureObject::DETOUR_AddMemSpellPriest);
	}

	if (pGameOptionsEx->bVideoDisableBrightestFix) {
		DetourMemberFunction(Tramp_VidPal_SetFxPaletteNo3d, DETOUR_VidPal::DETOUR_SetFxPaletteNo3d);
	}

	return;
}