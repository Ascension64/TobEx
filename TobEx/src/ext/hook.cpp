#include "hook.h"

#include "utils.h"
#include "detoursext.h"

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
#include "SoundCore.h"
#include "UserCore.h"
#include "UserButton.h"
#include "VideoCore.h"


void InitHooks() {

    DetourMemberFunction(Tramp_CBaldurChitin_Construct0, DETOUR_CBaldurChitin::DETOUR_Construct);
	DetourMemberFunction(Tramp_CRuleTables_Construct, DETOUR_CRuleTables::DETOUR_Construct);
	DetourMemberFunction(Tramp_CRuleTables_Deconstruct, DETOUR_CRuleTables::DETOUR_Deconstruct);
	DetourFunction(Tramp_CloseLogAndErr, DETOUR_CloseLogAndErr);

	if (GetIniValue("Sound", "Externalise Animation Walking Sounds")) {
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

	if (GetIniValue("Debug", "External Logging"))
		DetourFunction(Tramp_WriteToFile, DETOUR_WriteToFile);
	if (GetIniValue("Debug", "Log Assertion Failures"))
		DetourFunction(Tramp_AssertFailedQuit, DETOUR_AssertFailedQuit);
	if (GetIniValue("Debug", "Log Assertion Warnings"))
		DetourFunction(Tramp_AssertFailedContinue, DETOUR_AssertFailedContinue);

	if (GetIniValue("Effect Opcodes", "Awaken On Damage"))
		DetourMemberFunction(Tramp_CEffectDamage_ApplyEffect, DETOUR_CEffectDamage::DETOUR_ApplyEffect);
	if (GetIniValue("Effect Opcodes", "Blindness Fix"))
		DetourMemberFunction(Tramp_CEffectBlindness_ApplyEffect, DETOUR_CEffectBlindness::DETOUR_ApplyEffect);
	if (GetIniValue("Effect Opcodes", "Extend Cut Scene 2"))
		DetourMemberFunction(Tramp_CEffectCutScene2_ApplyEffect, DETOUR_CEffectCutScene2::DETOUR_ApplyEffect);
	if (GetIniValue("Effect Opcodes", "Magic Resistance Mod Fix"))
		DetourMemberFunction(Tramp_CEffectMagicResistMod_ApplyEffect, DETOUR_CEffectMagicResistMod::DETOUR_ApplyEffect);
	if (GetIniValue("Effect Opcodes", "Opcode 0x13E"))
		DetourMemberFunction(Tramp_CEffect_CreateEffect, DETOUR_CEffect::DETOUR_CreateEffect);

	if (GetIniValue("Engine", "Externalise Class-Race Restrictions")) {
		DetourFunction(Tramp_CAnimation_IsPlayableAnimation, DETOUR_CAnimation::DETOUR_IsPlayableAnimation);
		DetourMemberFunction(Tramp_CAnimation5000_Construct, DETOUR_CAnimation5000::DETOUR_Construct);
		DetourMemberFunction(Tramp_CRuleTables_IsMageSchoolAllowed, DETOUR_CRuleTables::DETOUR_IsMageSchoolAllowed);
		DetourMemberFunction(Tramp_CCharGen_ClassPanelOnUpdate, DETOUR_CCharGen::DETOUR_ClassPanelOnUpdate);
		DetourMemberFunction(Tramp_CCharGen_MulticlassPanelOnUpdate, DETOUR_CCharGen::DETOUR_MulticlassPanelOnUpdate);
		DetourMemberFunction(Tramp_CCharGen_MageSchoolPanelOnUpdate, DETOUR_CCharGen::DETOUR_MageSchoolPanelOnUpdate);
	}
	if (GetIniValue("Engine", "Level One Proficiency Restrictions")) {
		DetourMemberFunction(Tramp_CRuleTables_GetWeapProfMax, DETOUR_CRuleTables::DETOUR_GetWeapProfMax);
	}

	if (GetIniValue("Music", "Extended Songlist")) {
		DetourMemberFunction(Tramp_CSoundMixer_InitSonglist, DETOUR_CSoundMixer::DETOUR_InitSonglist);
		DetourMemberFunction(Tramp_CArea_GetSong, DETOUR_CArea::DETOUR_GetSong);
	}

	if (GetIniValue("Sound", "Enable Animation Attack Sounds"))
		DetourMemberFunction(Tramp_CAnimation_PlayCurrentSequenceSound, DETOUR_CAnimation::DETOUR_PlayCurrentSequenceSound);
	if (GetIniValue("Sound", "Soundset Subtitles")) {
		DetourMemberFunction(Tramp_CRecord_UpdateCharacter, DETOUR_CRecord::DETOUR_UpdateCharacter);
		DetourMemberFunction(Tramp_CCharGen_InitSoundset, DETOUR_CCharGen::DETOUR_InitSoundset);
	}

	DetourFunction(Tramp_CreateUIControl, DETOUR_CreateUIControl);
	if (GetIniValue("UI", "Externalise Mage Spell Hiding")) {
		DetourMemberFunction(Tramp_CRuleTables_GetMageSpellRefAutoPick, DETOUR_CRuleTables::DETOUR_GetMageSpellRefAutoPick);
		DetourMemberFunction(Tramp_CRuleTables_GetMageSpellRef, DETOUR_CRuleTables::DETOUR_GetMageSpellRef);
	}
	if (GetIniValue("UI", "Scrollable Chargen Mage Spell Selection")) {
		DetourMemberFunction(Tramp_CCharGen_MageBookPanelOnUpdate, DETOUR_CCharGen::DETOUR_MageBookPanelOnUpdate);
		DetourMemberFunction(Tramp_CCharGen_MageBookPanelOnLoad, DETOUR_CCharGen::DETOUR_MageBookPanelOnLoad);
	}
	if (GetIniValue("UI", "Scrollable Kit Selection")) {
		DetourMemberFunction(Tramp_CCharGen_KitPanelOnUpdate, DETOUR_CCharGen::DETOUR_KitPanelOnUpdate);
		DetourMemberFunction(Tramp_CCharGen_KitPanelOnLoad, DETOUR_CCharGen::DETOUR_KitPanelOnLoad);
		DetourMemberFunction(Tramp_CUICheckButtonChargenKit_GetKitId, DETOUR_CUICheckButtonChargenKit::DETOUR_GetKitId);
		DetourMemberFunction(Tramp_CUICheckButtonChargenKit_GetKitHelpText, DETOUR_CUICheckButtonChargenKit::DETOUR_GetKitHelpText);
	}
	if (GetIniValue("UI", "Scrollable Level Up Mage Spell Selection")) {
		DetourMemberFunction(Tramp_CRecord_MageBookPanelOnUpdate, DETOUR_CRecord::DETOUR_MageBookPanelOnUpdate);
		DetourMemberFunction(Tramp_CRecord_MageBookPanelOnLoad, DETOUR_CRecord::DETOUR_MageBookPanelOnLoad);
	}
	if (GetIniValue("UI", "Scrollable Mage Spellbook")) {
		DetourMemberFunction(Tramp_CMageBook_SetLevel, DETOUR_CMageBook::DETOUR_SetLevel);
		DetourMemberFunction(Tramp_CCreatureObject_GetKnownSpellMage, DETOUR_CCreatureObject::DETOUR_GetKnownSpellMage);
		DetourMemberFunction(Tramp_CCreatureObject_AddMemSpellMage, DETOUR_CCreatureObject::DETOUR_AddMemSpellMage);
	}
	if (GetIniValue("UI", "Scrollable Priest Spellbook")) {
		DetourMemberFunction(Tramp_CPriestBook_SetLevel, DETOUR_CPriestBook::DETOUR_SetLevel);
		DetourMemberFunction(Tramp_CCreatureObject_GetKnownSpellPriest, DETOUR_CCreatureObject::DETOUR_GetKnownSpellPriest);
		DetourMemberFunction(Tramp_CCreatureObject_AddMemSpellPriest, DETOUR_CCreatureObject::DETOUR_AddMemSpellPriest);
	}

	if (GetIniValue("Video", "Brighten On Disable Brightest No3d Fix")) {
		DetourMemberFunction(Tramp_VidPal_SetFxPaletteNo3d, DETOUR_VidPal::DETOUR_SetFxPaletteNo3d);
	}

	return;
}