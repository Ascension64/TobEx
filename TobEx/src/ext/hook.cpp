#include "hook.h"

#include "utils.h"
#include "detoursext.h"
#include "UserCore.h"
#include "uicore.h"
#include "SoundMusic.h"
#include "sndcore.h"
#include "AreaCommon.h"
#include "areacore.h"
#include "AnimationSound.h"
#include "animcore.h"
#include "LogCore.h"
#include "dbgcore.h"
#include "VideoCore.h"
#include "vidcore.h"
#include "EffectOpcode.h"
#include "effopcode.h"
#include "EffectCore.h"
#include "effcore.h"
#include "infgame.h"
#include "InfGameCore.h"
#include "chitin.h"
#include "ChitinCore.h"
#include "engchargen.h"
#include "EngineChargen.h"
#include "engrecord.h"
#include "EngineRecord.h"
#include "engmagebk.h"
#include "EngineMageBook.h"
#include "engpriestbk.h"
#include "EnginePriestBook.h"
#include "objcre.h"
#include "ObjectCreature.h"
#include "uibutton.h"
#include "UserButton.h"

void InitHooks() {

	//Common
	DetourFunction(CloseLogAndErr, DETOUR_CloseLogAndErr);
	if (GetIniValue("Debug", "External Logging"))
		DetourFunction(WriteToFile, DETOUR_WriteToFile);
	if (GetIniValue("Debug", "Log Assertion Failures"))
		DetourFunction(AssertFailedQuit, DETOUR_AssertFailedQuit);
	if (GetIniValue("Debug", "Log Assertion Warnings"))
		DetourFunction(AssertFailedContinue, DETOUR_AssertFailedContinue);

	//Effect
	if (GetIniValue("Effect Opcodes", "Magic Resistance Mod Fix"))
		DetourMemberFunction(CEffectMagicResistMod_ApplyEffect, DETOUR_CEffectMagicResistMod::DETOUR_ApplyEffect);
	if (GetIniValue("Effect Opcodes", "Extend Cut Scene 2"))
		DetourMemberFunction(CEffectCutScene2_ApplyEffect, DETOUR_CEffectCutScene2::DETOUR_ApplyEffect);
	if (GetIniValue("Effect Opcodes", "Awaken On Damage"))
		DetourMemberFunction(CEffectDamage_ApplyEffect, DETOUR_CEffectDamage::DETOUR_ApplyEffect);
	if (GetIniValue("Effect Opcodes", "Blindness Fix"))
		DetourMemberFunction(CEffectBlindness_ApplyEffect, DETOUR_CEffectBlindness::DETOUR_ApplyEffect);
	if (GetIniValue("Effect Opcodes", "Opcode 0x13E"))
		DetourMemberFunction(CEffect_CreateEffect, DETOUR_CEffect::CreateEffect);

	//InfGame
    DetourMemberFunction(CBaldurChitin_Construct0, DETOUR_CBaldurChitin::DETOUR_Construct);

	//InfScreenCharacter
	if (GetIniValue("Sound", "Soundset Subtitles")) {
		DetourMemberFunction(CRecord_UpdateCharacter, DETOUR_CRecord::DETOUR_UpdateCharacter);
		DetourMemberFunction(CCharGen_InitSoundset, DETOUR_CCharGen::DETOUR_InitSoundset);
	}

	//Sound
	if (GetIniValue("Music", "Extended Songlist")) {
		DetourMemberFunction(CSoundMixer_InitSonglist, DETOUR_CSoundMixer::DETOUR_InitSonglist);
		DetourMemberFunction(CArea_GetSong, DETOUR_CArea::DETOUR_GetSong);
	}

	if (GetIniValue("Sound", "Enable Animation Attack Sounds"))
		DetourMemberFunction(CAnimation_PlayCurrentAnimationSequenceSound, DETOUR_CAnimation::DETOUR_PlayCurrentAnimationSequenceSound);

	//UI
	DetourFunction(CreateUIControl, DETOUR_CreateUIControl);

	if (GetIniValue("UI", "Scrollable Kit Selection")) {
		DetourMemberFunction(CCharGen_KitPanelOnUpdate, DETOUR_CCharGen::DETOUR_KitPanelOnUpdate);
		DetourMemberFunction(CCharGen_KitPanelOnLoad, DETOUR_CCharGen::DETOUR_KitPanelOnLoad);
		DetourMemberFunction(CUICheckButtonChargenKit_GetKitId, DETOUR_CUICheckButtonChargenKit::DETOUR_GetKitId);
		DetourMemberFunction(CUICheckButtonChargenKit_GetKitHelpText, DETOUR_CUICheckButtonChargenKit::DETOUR_GetKitHelpText);
	}

	if (GetIniValue("UI", "Externalise Mage Spell Hiding")) {
		DetourMemberFunction(CRuleTables_GetMageSpellRefAutoPick, DETOUR_CRuleTables::DETOUR_GetMageSpellRefAutoPick);
		DetourMemberFunction(CRuleTables_GetMageSpellRef, DETOUR_CRuleTables::DETOUR_GetMageSpellRef);
	}

	if (GetIniValue("UI", "Scrollable Level Up Mage Spell Selection")) {
		DetourMemberFunction(CRecord_MageBookPanelOnUpdate, DETOUR_CRecord::DETOUR_MageBookPanelOnUpdate);
		DetourMemberFunction(CRecord_MageBookPanelOnLoad, DETOUR_CRecord::DETOUR_MageBookPanelOnLoad);
	}

	if (GetIniValue("UI", "Scrollable Chargen Mage Spell Selection")) {
		DetourMemberFunction(CCharGen_MageBookPanelOnUpdate, DETOUR_CCharGen::DETOUR_MageBookPanelOnUpdate);
		DetourMemberFunction(CCharGen_MageBookPanelOnLoad, DETOUR_CCharGen::DETOUR_MageBookPanelOnLoad);
	}

	if (GetIniValue("UI", "Scrollable Mage Spellbook")) {
		DetourMemberFunction(CMageBook_SetLevel, DETOUR_CMageBook::DETOUR_SetLevel);
		DetourMemberFunction(CCreatureObject_GetKnownSpellMage, DETOUR_CCreatureObject::DETOUR_GetKnownSpellMage);
		DetourMemberFunction(CCreatureObject_AddMemSpellMage, DETOUR_CCreatureObject::DETOUR_AddMemSpellMage);
	}

	if (GetIniValue("UI", "Scrollable Priest Spellbook")) {
		DetourMemberFunction(CPriestBook_SetLevel, DETOUR_CPriestBook::DETOUR_SetLevel);
		DetourMemberFunction(CCreatureObject_GetKnownSpellPriest, DETOUR_CCreatureObject::DETOUR_GetKnownSpellPriest);
		DetourMemberFunction(CCreatureObject_AddMemSpellPriest, DETOUR_CCreatureObject::DETOUR_AddMemSpellPriest);
	}

	if (GetIniValue("Engine", "Level One Proficiency Restrictions")) {
		DetourMemberFunction(CRuleTables_GetWeapProfMax, DETOUR_CRuleTables::DETOUR_GetWeapProfMax);
	}

	//Video
	if (GetIniValue("Video", "Brighten On Disable Brightest No3d Fix")) {
		DetourMemberFunction(VidPal_SetFxPaletteNo3d, DETOUR_VidPal::DETOUR_SetFxPaletteNo3d);
	}

	return;
}