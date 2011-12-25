#include "options.h"

#include "utils.h"

static LPCTSTR szDefault = "0";
static const DWORD nBufSize = 8;
static char szBuf[nBufSize] = { 0 };
static LPCTSTR szFile = "./TobEx.ini";

CGameOptionsEx* pGameOptionsEx = NULL;

CGameOptionsEx::CGameOptionsEx() {
	bDebugCriticalMsgBoxFix = FALSE;
	bDebugExternalLogging = FALSE;
	bDebugLogFailures = FALSE;
	bDebugLogWarnings = FALSE;
	bDebugLogMore = FALSE;
	bDebugRestoreCombatInfoText = FALSE;

	bEffAttacksPerRoundFix = FALSE;
	bEffAwakenFix = FALSE;
	bEffDamageAwaken = FALSE;
	nEffBlindnessFix = 0;
	bEffBackstabEveryHitConfig = FALSE;
	bEffDamageBypassMirrorImageConfig = FALSE;
	bEffDispelMagicalItemConfig = FALSE;
	bEffCureDrunkFix = FALSE;
	bEffStoneskinDisableColour = FALSE;
	bEffDiseaseFix = FALSE;
	bEffDispelFix = FALSE;
	bEffCutScene2Extend = FALSE;
	bEffForbidItemTypeFix = FALSE;
	bEffInvisibleFix = FALSE;
	bEffMagicResistFix = FALSE;
	bEffOpcode13E = FALSE;
	bEffPoisonFix = FALSE;
	bEffRegenerationFix = FALSE;
	bEffRepeatingEffFix = FALSE;
	bEffMirrorImageUseCastLevel = FALSE;

	bEnginePriestKnownSpellsExtend = FALSE;
	bEngineCastingLevelBonus = FALSE;
	bEngineExperienceFix = FALSE;
	nEngineContingencyTriggerDelay = 0;
	bEngineCharmSilenceRemoval = FALSE;
	bEngineExternClassRaceRestrictions = FALSE;
	bEngineProficiencyRestrictions = FALSE;
	bEnginePickpocketRemainHidden = FALSE;

	bItemsBackstabRestrictionsConfig = FALSE;
	bItemsCriticalHitAversionConfig = FALSE;
	bItemsRandomTreasureExtend = FALSE;

	bMusicSonglistExtend = FALSE;

	bSoundAnimSoundFix = FALSE;
	bSoundAnimAttackSounds = FALSE;
	bSoundExistenceFix = FALSE;
	bSoundExternWalkSounds = FALSE;
	bSoundSoundsetSubtitles = FALSE;

	bTriggerPickpocketFailed = FALSE;

	bUserKitsExtend = FALSE;
	bUserLargerTooltipScroll = FALSE;
	bUserExternMageSpellHiding = FALSE;
	bUserExternRaceSelectionText = FALSE;
	bUserChargenMageSpellScroll = FALSE;
	bUserChargenKitSelectScroll = FALSE;
	bUserRecordMageSpellScroll = FALSE;
	bUserMageBookScroll = FALSE;
	bUserPriestBookScroll = FALSE;
	bUserFourInventorySlots = FALSE;

	bVideoDisableBrightestFix = FALSE;
	bUserVvcAlphaCrashFix = FALSE;

	Init();
}

void CGameOptionsEx::Init() {
	bDebugCriticalMsgBoxFix = GetIniValue("Debug", "Critical Error Message Box Fix");
	bDebugExternalLogging = GetIniValue("Debug", "Externalise Logging");
	bDebugLogFailures = GetIniValue("Debug", "Log Assertion Failures");
	bDebugLogWarnings = GetIniValue("Debug", "Log Assertion Warnings");
	bDebugLogMore = GetIniValue("Debug", "Log More Messages");
	bDebugRestoreCombatInfoText = GetIniValue("Debug", "Restore Extra Combat Info Text");

	bEffAttacksPerRoundFix = GetIniValue("Effect Opcodes", "Attacks Per Round Mod Fix");
	bEffAwakenFix = GetIniValue("Effect Opcodes", "Awaken Fix");
	bEffDamageAwaken = GetIniValue("Effect Opcodes", "Awaken On Damage");
	nEffBlindnessFix = GetIniValue("Effect Opcodes", "Blindness Fix");
	bEffBackstabEveryHitConfig = GetIniValue("Effect Opcodes", "Configurable Backstab Every Hit");
	bEffDamageBypassMirrorImageConfig = GetIniValue("Effect Opcodes", "Configurable Damage Effect Bypasses Mirror Images");
	bEffDispelMagicalItemConfig = GetIniValue("Effect Opcodes", "Configurable Magical Item Dispel Behaviour");
	bEffCureDrunkFix = GetIniValue("Effect Opcodes", "Cure Drunk Fix");
	bEffStoneskinDisableColour = GetIniValue("Effect Opcodes", "Disable Stoneskin Grey Colour");
	bEffDiseaseFix = GetIniValue("Effect Opcodes", "Disease Fix");
	bEffDispelFix = GetIniValue("Effect Opcodes", "Dispel Formula Fix");
	bEffCutScene2Extend = GetIniValue("Effect Opcodes", "Extend Cut Scene 2");
	bEffForbidItemTypeFix = GetIniValue("Effect Opcodes", "Forbid Item Type Fix");
	bEffInvisibleFix = GetIniValue("Effect Opcodes", "Invisible Fix");
	bEffMagicResistFix = GetIniValue("Effect Opcodes", "Magic Resistance Mod Fix");
	bEffOpcode13E = GetIniValue("Effect Opcodes", "Opcode 0x13E");
	bEffPoisonFix = GetIniValue("Effect Opcodes", "Poison Fix");
	bEffRegenerationFix = GetIniValue("Effect Opcodes", "Regeneration Fix");
	bEffRepeatingEffFix = GetIniValue("Effect Opcodes", "Repeating Effect Fix");
	bEffMirrorImageUseCastLevel = GetIniValue("Effect Opcodes", "Use Caster Level On Mirror Image");

	bEnginePriestKnownSpellsExtend = GetIniValue("Engine", "Allow 99 Priest Known Spells Per Level");
	bEngineCastingLevelBonus = GetIniValue("Engine", "Apply Casting Level Bonus");
	bEngineExperienceFix = GetIniValue("Engine", "Correct Experience Gain");
	nEngineContingencyTriggerDelay = GetIniValue("Engine", "Custom Contingency Trigger Check Delay");
	bEngineCharmSilenceRemoval = GetIniValue("Engine", "Disable Silence On Charm");
	bEngineExternClassRaceRestrictions = GetIniValue("Engine", "Externalise Class-Race Restrictions");
	bEngineProficiencyRestrictions = GetIniValue("Engine", "Level One Proficiency Restrictions");
	bEnginePickpocketRemainHidden = GetIniValue("Engine", "Remain Hidden On Pickpocket Success");

	bItemsBackstabRestrictionsConfig = GetIniValue("Items", "Configurable Backstab Restrictions");
	bItemsCriticalHitAversionConfig = GetIniValue("Items", "Configurable Critial Hit Aversion");
	bItemsRandomTreasureExtend = GetIniValue("Items", "Enable 99 Random Treasure Rows");

	bMusicSonglistExtend = GetIniValue("Music", "Extended Songlist");

	bSoundAnimSoundFix = GetIniValue("Sound", "Animation Sound Fix");
	bSoundAnimAttackSounds = GetIniValue("Sound", "Enable Animation Attack Sounds");
	bSoundExistenceFix = GetIniValue("Sound", "Existence Sound Fix");
	bSoundExternWalkSounds = GetIniValue("Sound", "Externalise Animation Walking Sounds");
	bSoundSoundsetSubtitles = GetIniValue("Sound", "Soundset Subtitles");

	bTriggerPickpocketFailed = GetIniValue("Trigger", "Enable PickpocketFailed Trigger");

	bUserKitsExtend = GetIniValue("UI", "Allow 1280 Total Kits");
	bUserLargerTooltipScroll = GetIniValue("UI", "Enlarge Tooltip Scroll");
	bUserExternMageSpellHiding = GetIniValue("UI", "Externalise Mage Spell Hiding");
	bUserExternRaceSelectionText = GetIniValue("UI", "Externalise Race Selection StrRef");
	bUserChargenMageSpellScroll = GetIniValue("UI", "Scrollable Chargen Mage Spell Selection");
	bUserChargenKitSelectScroll = GetIniValue("UI", "Scrollable Kit Selection");
	bUserRecordMageSpellScroll = GetIniValue("UI", "Scrollable Level Up Mage Spell Selection");
	bUserMageBookScroll = GetIniValue("UI", "Scrollable Mage Spellbook");
	bUserPriestBookScroll = GetIniValue("UI", "Scrollable Priest Spellbook");
	bUserFourInventorySlots = GetIniValue("UI", "Universal Four Inventory Weapon Slots");

	bVideoDisableBrightestFix = GetIniValue("Video", "Brighten On Disable Brightest No3d Fix");
	bUserVvcAlphaCrashFix = GetIniValue("Video", "VVC Alpha Rendering Crash Fix");

	return;
}

int GetIniValue(LPCTSTR szSection, LPCTSTR szKey) {
	int n = 0;
	GetPrivateProfileString(szSection, szKey, szDefault, szBuf, nBufSize, szFile);
	sscanf_s(szBuf, "%d", &n);
	return n;
}

void InitOptions() {
	pGameOptionsEx = new CGameOptionsEx();
	return;
}