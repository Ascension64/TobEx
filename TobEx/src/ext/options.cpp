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
	bDebugLogDialogueBar = FALSE;
	bDebugLogFailures = FALSE;
	bDebugLogWarnings = FALSE;
	bDebugLogMore = FALSE;
	bDebugRestoreCombatInfoText = FALSE;
	BOOL bDebugVerbose = FALSE;

	bEffApplyEffItemFix = FALSE;
	bEffApplyEffItemtypeFix = FALSE;
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
	bEffDisintegrateFix = FALSE;
	bEffDispelFix = FALSE;
	bEffCutScene2Extend = FALSE;
	bEffForbidItemTypeFix = FALSE;
	bEffInvisibleFix = FALSE;
	bEffIWDDexterityMod = FALSE;
	bEffIWDMageMemSpellMod = FALSE;
	bEffIWDPriestMemSpellMod = FALSE;
	bEffIWDStrengthMod = FALSE;
	bEffMagicResistFix = FALSE;
	bEffOpcode13E = FALSE;
	bEffPoisonFix = FALSE;
	bEffRegenerationFix = FALSE;
	bEffRemoveProjectileMod = FALSE;
	bEffRepeatingEffFix = FALSE;
	bEffMirrorImageUseCastLevel = FALSE;

	bEnginePriestKnownSpellsExtend = FALSE;
	bEngineAllowDualClassAll = FALSE;
	bEngineCastingLevelBonus = FALSE;
	bEngineExperienceFix = FALSE;
	nEngineContingencyTriggerDelay = 0;
	bEngineModifyEffectStacking = FALSE;
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
	bSoundDlgGreetingSubtitles = FALSE;
	bSoundExistenceFix = FALSE;
	bSoundExternWalkSounds = FALSE;
	bSoundSoundsetSubtitles = FALSE;

	bTriggerPickpocketFailed = FALSE;

	bUserKitsExtend = FALSE;
	nUserCustomDlgBarSize = 0;
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
	bVideoIWDAnimAttack3Fix = FALSE;
	bVideoVvcAlphaCrashFix = FALSE;

	Init();
}

void CGameOptionsEx::Init() {
	bDebugCriticalMsgBoxFix = GetIniValue("Debug", "Critical Error Message Box Fix");
	bDebugExternalLogging = GetIniValue("Debug", "Externalise Logging");
	bDebugLogDialogueBar = GetIniValue("Debug", "Log Dialogue Bar");
	bDebugLogFailures = GetIniValue("Debug", "Log Assertion Failures");
	bDebugLogWarnings = GetIniValue("Debug", "Log Assertion Warnings");
	bDebugLogMore = GetIniValue("Debug", "Log More Messages");
	bDebugRestoreCombatInfoText = GetIniValue("Debug", "Restore Extra Combat Info Text");
	bDebugVerbose = GetIniValue("Debug", "Verbose Logging");

	bEffApplyEffItemFix = GetIniValue("Effect Opcodes", "Apply Effect Item Fix");
	bEffApplyEffItemtypeFix = GetIniValue("Effect Opcodes", "Apply Effect Itemtype Fix");
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
	bEffDisintegrateFix = GetIniValue("Effect Opcodes", "Disintegrate Fix");
	bEffDispelFix = GetIniValue("Effect Opcodes", "Dispel Formula Fix");
	bEffCutScene2Extend = GetIniValue("Effect Opcodes", "Extend Cut Scene 2");
	bEffForbidItemTypeFix = GetIniValue("Effect Opcodes", "Forbid Item Type Fix");
	bEffInvisibleFix = GetIniValue("Effect Opcodes", "Invisible Fix");
	bEffIWDDexterityMod =  GetIniValue("Effect Opcodes", "IWD Style Cats Grace Dexterity Mod");
	bEffIWDMageMemSpellMod = GetIniValue("Effect Opcodes", "IWD Style Mage Spell Slots Mod");
	bEffIWDPriestMemSpellMod = GetIniValue("Effect Opcodes", "IWD Style Priest Spell Slots Mod");
	bEffIWDStrengthMod = GetIniValue("Effect Opcodes", "IWD Style Strength Mod");
	bEffMagicResistFix = GetIniValue("Effect Opcodes", "Magic Resistance Mod Fix");
	bEffOpcode13E = GetIniValue("Effect Opcodes", "Opcode 0x13E");
	bEffPoisonFix = GetIniValue("Effect Opcodes", "Poison Fix");
	bEffRegenerationFix = GetIniValue("Effect Opcodes", "Regeneration Fix");
	bEffRemoveProjectileMod = GetIniValue("Effect Opcodes", "Remove Projectile Mod");
	bEffRepeatingEffFix = GetIniValue("Effect Opcodes", "Repeating Effect Fix");
	bEffMirrorImageUseCastLevel = GetIniValue("Effect Opcodes", "Use Caster Level On Mirror Image");

	bEnginePriestKnownSpellsExtend = GetIniValue("Engine", "Allow 99 Priest Known Spells Per Level");
	bEngineAllowDualClassAll = GetIniValue("Engine", "Allow All Races to Dual Class");
	bEngineCastingLevelBonus = GetIniValue("Engine", "Apply Casting Level Bonus");
	bEngineExperienceFix = GetIniValue("Engine", "Correct Experience Gain");
	nEngineContingencyTriggerDelay = GetIniValue("Engine", "Custom Contingency Trigger Check Delay");
	bEngineModifyEffectStacking = GetIniValue("Engine", "Disable Duplicate Effect Stacking");
	bEngineCharmSilenceRemoval = GetIniValue("Engine", "Disable Silence On Charm");
	bEngineExternClassRaceRestrictions = GetIniValue("Engine", "Externalise Class-Race Restrictions");
	bEngineProficiencyRestrictions = GetIniValue("Engine", "Level One Proficiency Restrictions");
	bEnginePickpocketRemainHidden = GetIniValue("Engine", "Remain Hidden On Pickpocket Success");

	bItemsBackstabRestrictionsConfig = GetIniValue("Items", "Configurable Backstab Restrictions");
	bItemsCriticalHitAversionConfig = GetIniValue("Items", "Configurable Critial Hit Aversion");
	bItemsRandomTreasureExtend = GetIniValue("Items", "Enable 99 Random Treasure Rows");

	bMusicSonglistExtend = GetIniValue("Music", "Extended Songlist");

	bSoundAnimSoundFix = GetIniValue("Sound", "Animation Sound Fix");
	bSoundDlgGreetingSubtitles = GetIniValue("Sound", "Dialogue Greeting Subtitles");
	bSoundAnimAttackSounds = GetIniValue("Sound", "Enable Animation Attack Sounds");
	bSoundExistenceFix = GetIniValue("Sound", "Existence Sound Fix");
	bSoundExternWalkSounds = GetIniValue("Sound", "Externalise Animation Walking Sounds");
	bSoundSoundsetSubtitles = GetIniValue("Sound", "Soundset Subtitles");

	bTriggerPickpocketFailed = GetIniValue("Trigger", "Enable PickpocketFailed Trigger");

	bUserKitsExtend = GetIniValue("UI", "Allow 1280 Total Kits");
	nUserCustomDlgBarSize = GetIniValue("UI", "Custom Dialogue Bar Buffer Size");
	nUserCustomDlgBarSize = max(nUserCustomDlgBarSize, 0);
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
	bVideoIWDAnimAttack3Fix = GetIniValue("Video", "IWD Animation Attack 3 Fix");
	bVideoVvcAlphaCrashFix = GetIniValue("Video", "VVC Alpha Rendering Crash Fix");

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