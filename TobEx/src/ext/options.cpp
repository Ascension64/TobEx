#include "options.h"

#include "utils.h"

static LPCTSTR s_szDefault = "0";
static const DWORD s_nBufSize = 8;
static char s_szBuf[s_nBufSize] = { 0 };
static LPCTSTR s_szFileCore = "./TobEx_ini/TobExCore.ini";
static LPCTSTR s_szFileTweak = "./TobEx_ini/TobExTweak.ini";

CGameOptionsEx* pGameOptionsEx = NULL;

CGameOptionsEx::CGameOptionsEx() {
	bActionAddKitFix = FALSE;
	bSpellsTargetInvisConfig = FALSE;
	bActionEquipRangedFix = FALSE;

	bDebugCriticalMsgBoxFix = FALSE;
	bDebugExternalLogging = FALSE;
	bDebugLogDialogueBar = FALSE;
	bDebugLogFailures = FALSE;
	bDebugLogWarnings = FALSE;
	bDebugLogMissingRes = FALSE;
	bDebugLogMore = FALSE;
	bDebugRestoreCombatInfoText = FALSE;
	bDebugVerbose = FALSE;

	bEffApplyConcCheckDamage = FALSE;
	bEffApplyEffItemFix = FALSE;
	bEffApplyEffItemtypeFix = FALSE;
	bEffAttacksPerRoundFix = FALSE;
	bEffAwakenFix = FALSE;
	bEffDamageAwaken = FALSE;
	bEffBlindnessAsSpellDesc = FALSE;
	bEffBlindnessFix = FALSE;
	bEffCastSpellConditionMod = FALSE;
	bEffCastingLevelModFix = FALSE;
	bEffBackstabEveryHitConfig = FALSE;
	bEffDamageBypassMirrorImageConfig = FALSE;
	bEffDispelMagicalItemConfig = FALSE;
	bEffCureDrunkFix = FALSE;
	bEffDamageFix = FALSE;
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
	bEffLearnSpellMod = FALSE;
	bEffMagicResistFix = FALSE;
	bEffNoDamageNoSpellInterrupt = FALSE;
	bEffPoisonFix = FALSE;
	bEffRegenerationFix = FALSE;
	bEffRemoveProjectileMod = FALSE;
	bEffRepeatingEffFix = FALSE;
	bEffMirrorImageUseCastLevel = FALSE;

	bEnginePriestKnownSpellsExtend = FALSE;
	bEngineAllowDualClassAll = FALSE;
	bEngineAllowEquipArmorCombat = FALSE;
	bEngineAllowZeroStartXP = FALSE;
	bEngineAssBHPenaltyKit = FALSE;
	bEngineClericRangerHLAFix = FALSE;
	bEngineXPReportFix = FALSE;
	nEngineCustomSoAStartXP = -1;
	nEngineCustomToBStartXP = -1;
	bEngineModifyEffectStacking = FALSE;
	bEngineDisableInvPauseSP = FALSE;
	bEngineDisableXPBoost = FALSE;
	bEngineCharmSilenceRemoval = FALSE;
	bEngineExpandedStats = FALSE;
	bEngineExternHPTables = FALSE;
	bEngineExternClassRaceRestrictions = FALSE;
	bEngineExternEncumbrance = FALSE;
	bEngineProficiencyRestrictions = FALSE;
	bEnginePickpocketRemainHidden = FALSE;
	bEngineRestSpawnsAdvanceTime = FALSE;
	bEngineTargetDeadFix = FALSE;
	bEngineWeapSpecNumAttacksMod = FALSE;

	bItemsBackstabRestrictionsConfig = FALSE;
	bItemsCriticalHitAversionConfig = FALSE;
	bItemsRandomTreasureExtend = FALSE;
	bItemsNonAmmoLauncherDamageFix = FALSE;
	bItemsUseAnimPercentThrowingWeapons = FALSE;

	bMusicSonglistExtend = FALSE;

	bSoundAnimSoundFix = FALSE;
	bSoundAnimAttackSounds = FALSE;
	bSoundDlgGreetingSubtitles = FALSE;
	bSoundExistenceFix = FALSE;
	bSoundExternWalkSounds = FALSE;
	bSoundSoundsetSubtitles = FALSE;

	bTriggerPickpocketFailed = FALSE;
	bTriggerExpandedTriggers = FALSE;
	bTriggerKitFix = FALSE;

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
	bVideoEnableMorePaperdolls = FALSE;
	bVideoIWDAnimAttack3Fix = FALSE;
	bVideoVvcAlphaCrashFix = FALSE;

	Init();
}

void CGameOptionsEx::Init() {
	bActionAddKitFix = GetCoreIniValue("Action", "AddKit Actions Fix");
	bActionEquipRangedFix = GetCoreIniValue("Action", "EquipRanged Action Fix");

	bDebugCriticalMsgBoxFix = GetCoreIniValue("Debug", "Critical Error Message Box Fix");
	bDebugExternalLogging = GetCoreIniValue("Debug", "Externalise Logging");
	bDebugLogDialogueBar = GetCoreIniValue("Debug", "Log Dialogue Bar");
	bDebugLogFailures = GetCoreIniValue("Debug", "Log Assertion Failures");
	bDebugLogWarnings = GetCoreIniValue("Debug", "Log Assertion Warnings");
	bDebugLogMissingRes = GetCoreIniValue("Debug", "Log Missing Resources");
	bDebugLogMore = GetCoreIniValue("Debug", "Log More Messages");
	bDebugRestoreCombatInfoText = GetCoreIniValue("Debug", "Restore Extra Combat Info Text");
	bDebugVerbose = GetCoreIniValue("Debug", "Verbose Logging");

	bEffApplyConcCheckDamage = GetTweakIniValue("Tweak", "Effect Opcodes:Apply Concentration Check On Damage");
	bEffApplyEffItemFix = GetCoreIniValue("Effect Opcodes", "Apply Effect Item Fix");
	bEffApplyEffItemtypeFix = GetCoreIniValue("Effect Opcodes", "Apply Effect Itemtype Fix");
	bEffAttacksPerRoundFix = GetCoreIniValue("Effect Opcodes", "Attacks Per Round Mod Fix");
	bEffAwakenFix = GetCoreIniValue("Effect Opcodes", "Awaken Fix");
	bEffDamageAwaken = GetTweakIniValue("Tweak", "Effect Opcodes:Awaken On Damage");
	bEffBlindnessAsSpellDesc = GetTweakIniValue("Tweak", "Blindness As Spell Description");
	bEffBlindnessFix = GetCoreIniValue("Effect Opcodes", "Blindness Fix");
	bEffCastSpellConditionMod = GetCoreIniValue("Effect Opcodes", "Cast Spell On Condition Mod");
	bEffCastingLevelModFix = GetCoreIniValue("Effect Opcodes", "Casting Level Mod Fix");
	bEffBackstabEveryHitConfig = GetCoreIniValue("Effect Opcodes", "Configurable Backstab Every Hit");
	bEffDamageBypassMirrorImageConfig = GetCoreIniValue("Effect Opcodes", "Configurable Damage Effect Bypasses Mirror Images");
	bEffDispelMagicalItemConfig = GetCoreIniValue("Effect Opcodes", "Configurable Magical Item Dispel Behaviour");
	bEffCureDrunkFix = GetCoreIniValue("Effect Opcodes", "Cure Drunk Fix");
	bEffDamageFix = GetCoreIniValue("Effect Opcodes", "Damage Fix");
	bEffStoneskinDisableColour = GetTweakIniValue("Tweak", "Effect Opcodes:Disable Stoneskin Grey Colour");
	bEffDiseaseFix = GetCoreIniValue("Effect Opcodes", "Disease Fix");
	bEffDisintegrateFix = GetCoreIniValue("Effect Opcodes", "Disintegrate Fix");
	bEffDispelFix = GetCoreIniValue("Effect Opcodes", "Dispel Formula Fix");
	bEffCutScene2Extend = GetCoreIniValue("Effect Opcodes", "Extend Cut Scene 2");
	bEffForbidItemTypeFix = GetCoreIniValue("Effect Opcodes", "Forbid Item Type Fix");
	bEffInvisibleFix = GetCoreIniValue("Effect Opcodes", "Invisible Fix");
	bEffIWDDexterityMod =  GetCoreIniValue("Effect Opcodes", "IWD Style Cats Grace Dexterity Mod");
	bEffIWDMageMemSpellMod = GetCoreIniValue("Effect Opcodes", "IWD Style Mage Spell Slots Mod");
	bEffIWDPriestMemSpellMod = GetCoreIniValue("Effect Opcodes", "IWD Style Priest Spell Slots Mod");
	bEffIWDStrengthMod = GetCoreIniValue("Effect Opcodes", "IWD Style Strength Mod");
	bEffLearnSpellMod = GetCoreIniValue("Effect Opcodes", "Learn Spell Mod");
	bEffMagicResistFix = GetCoreIniValue("Effect Opcodes", "Magic Resistance Mod Fix");
	bEffNoDamageNoSpellInterrupt = GetTweakIniValue("Tweak", "Effect Opcodes:No Spell Interruption On Zero Damage");
	bEffPoisonFix = GetCoreIniValue("Effect Opcodes", "Poison Fix");
	bEffRegenerationFix = GetCoreIniValue("Effect Opcodes", "Regeneration Fix");
	bEffRemoveProjectileMod = GetCoreIniValue("Effect Opcodes", "Remove Projectile Mod");
	bEffRepeatingEffFix = GetCoreIniValue("Effect Opcodes", "Repeating Effect Fix");
	bEffMirrorImageUseCastLevel = GetTweakIniValue("Tweak:", "Effect Opcodes:Use Caster Level On Mirror Image");

	bEnginePriestKnownSpellsExtend = GetCoreIniValue("Engine", "Allow 99 Priest Known Spells Per Level");
	bEngineAllowDualClassAll = GetTweakIniValue("Tweak", "Engine:Allow All Races to Dual Class");
	bEngineAllowEquipArmorCombat = GetTweakIniValue("Tweak", "Engine:Allow Equipping Armor in Combat");
	bEngineAllowZeroStartXP = GetCoreIniValue("Engine", "Allow Zero Starting Experience");
	bEngineAssBHPenaltyKit = GetCoreIniValue("Engine", "Assassin and Bounty Hunter Penalty to Similar Kits");
	bEngineClericRangerHLAFix = GetCoreIniValue("Engine", "Cleric-Ranger HLA Fix");
	bEngineXPReportFix = GetCoreIniValue("Engine", "Correct Experience Reporting");
	nEngineCustomSoAStartXP = GetTweakIniValue("Tweak", "Engine:Custom Shadows of Amn Starting Experience", "-1");
	nEngineCustomToBStartXP = GetTweakIniValue("Tweak", "Engine:Custom Throne of Bhaal Starting Experience", "-1");
	bEngineModifyEffectStacking = GetCoreIniValue("Engine", "Disable Duplicate Effect Stacking");
	bEngineDisableInvPauseSP = GetTweakIniValue("Tweak", "Engine:Disable Force Inventory Pause");
	bEngineDisableXPBoost = GetTweakIniValue("Tweak", "Engine:Disable Experience Boost");
	bEngineCharmSilenceRemoval = GetTweakIniValue("Tweak", "Engine:Disable Silence On Charm");
	bEngineExpandedStats = GetCoreIniValue("Engine", "Expanded Stats");
	bEngineExternHPTables = GetCoreIniValue("Engine", "Externalise HP Tables");
	bEngineExternClassRaceRestrictions = GetCoreIniValue("Engine", "Externalise Class-Race Restrictions");
	bEngineExternEncumbrance = GetCoreIniValue("Engine", "Externalise Encumbrance Restrictions");
	bEngineProficiencyRestrictions = GetTweakIniValue("Tweak", "Engine:Level One Proficiency Restrictions");
	bEnginePickpocketRemainHidden = GetTweakIniValue("Tweak", "Engine:Remain Hidden On Pickpocket Success");
	bEngineRestSpawnsAdvanceTime = GetTweakIniValue("Tweak", "Engine:Rest Spawns Advance Time");
	bEngineTargetDeadFix = GetCoreIniValue("Engine", "Targetting Dead Animations Fix");
	bEngineWeapSpecNumAttacksMod = GetTweakIniValue("Tweak", "Engine:Weapon Specialisation Number of Attacks Mod");

	bItemsBackstabRestrictionsConfig = GetCoreIniValue("Items", "Configurable Backstab Restrictions");
	bItemsCriticalHitAversionConfig = GetCoreIniValue("Items", "Configurable Critical Hit Aversion");
	bItemsRandomTreasureExtend = GetCoreIniValue("Items", "Enable 99 Random Treasure Rows");
	bItemsExternCreExcl = GetCoreIniValue("Items", "Externalise Item-Creature Exclusions");
	bItemsNonAmmoLauncherDamageFix = GetCoreIniValue("Items", "Non-Ammo Launcher Damage Fix");
	bItemsUseAnimPercentThrowingWeapons = GetTweakIniValue("Tweak", "Items:Use Animation Percentages for Throwing Weapons");

	bMusicSonglistExtend = GetCoreIniValue("Music", "Extended Songlist");

	bSoundAnimSoundFix = GetCoreIniValue("Sound", "Animation Sound Fix");
	bSoundDlgGreetingSubtitles = GetTweakIniValue("Tweak", "Sound:Dialogue Greeting Subtitles");
	bSoundAnimAttackSounds = GetTweakIniValue("Tweak", "Sound:Enable Animation Attack Sounds");
	bSoundExistenceFix = GetCoreIniValue("Sound", "Existence Sound Fix");
	bSoundExternWalkSounds = GetCoreIniValue("Sound", "Externalise Animation Walking Sounds");
	bSoundSoundsetSubtitles = GetCoreIniValue("Sound", "Soundset Subtitles");

	bSpellsTargetInvisConfig = GetCoreIniValue("Spells", "Configurable Spells Can Target Invisible");

	bTriggerPickpocketFailed = GetTweakIniValue("Tweak", "Trigger:Enable PickpocketFailed Trigger");
	bTriggerExpandedTriggers = GetCoreIniValue("Trigger", "Expanded Triggers");
	bTriggerKitFix = GetCoreIniValue("Trigger", "Kit Trigger Fix");

	bUserKitsExtend = GetCoreIniValue("UI", "Allow 1280 Total Kits");
	nUserCustomDlgBarSize = GetCoreIniValue("UI", "Custom Dialogue Bar Buffer Size");
	nUserCustomDlgBarSize = max(nUserCustomDlgBarSize, 0);
	bUserLargerTooltipScroll = GetCoreIniValue("UI", "Enlarge Tooltip Scroll");
	bUserExternMageSpellHiding = GetCoreIniValue("UI", "Externalise Mage Spell Hiding");
	bUserExternRaceSelectionText = GetCoreIniValue("UI", "Externalise Race Selection StrRef");
	bUserChargenMageSpellScroll = GetCoreIniValue("UI", "Scrollable Chargen Mage Spell Selection");
	bUserChargenKitSelectScroll = GetCoreIniValue("UI", "Scrollable Kit Selection");
	bUserRecordMageSpellScroll = GetCoreIniValue("UI", "Scrollable Level Up Mage Spell Selection");
	bUserMageBookScroll = GetCoreIniValue("UI", "Scrollable Mage Spellbook");
	bUserPriestBookScroll = GetCoreIniValue("UI", "Scrollable Priest Spellbook");
	bUserFourInventorySlots = GetTweakIniValue("Tweak", "UI:Universal Four Inventory Weapon Slots");

	bVideoDisableBrightestFix = GetCoreIniValue("Video", "Brighten On Disable Brightest No3d Fix");
	bVideoEnableMorePaperdolls = GetCoreIniValue("Video", "Enable More Paperdolls");
	bVideoIWDAnimAttack3Fix = GetCoreIniValue("Video", "IWD Animation Attack 3 Fix");
	bVideoVvcAlphaCrashFix = GetCoreIniValue("Video", "VVC Alpha Rendering Crash Fix");

	return;
}

int GetCoreIniValue(LPCTSTR szSection, LPCTSTR szKey) {
	int n = 0;
	GetPrivateProfileString(szSection, szKey, s_szDefault, s_szBuf, s_nBufSize, s_szFileCore);
	sscanf_s(s_szBuf, "%d", &n);
	return n;
}

int GetCoreIniValue(LPCTSTR szSection, LPCTSTR szKey, LPCTSTR szDefault) {
	int n = 0;
	GetPrivateProfileString(szSection, szKey, szDefault, s_szBuf, s_nBufSize, s_szFileCore);
	sscanf_s(s_szBuf, "%d", &n);
	return n;
}

int GetTweakIniValue(LPCTSTR szSection, LPCTSTR szKey) {
	int n = 0;
	GetPrivateProfileString(szSection, szKey, s_szDefault, s_szBuf, s_nBufSize, s_szFileTweak);
	sscanf_s(s_szBuf, "%d", &n);
	return n;
}

int GetTweakIniValue(LPCTSTR szSection, LPCTSTR szKey, LPCTSTR szDefault) {
	int n = 0;
	GetPrivateProfileString(szSection, szKey, szDefault, s_szBuf, s_nBufSize, s_szFileTweak);
	sscanf_s(s_szBuf, "%d", &n);
	return n;
}

void InitOptions() {
	pGameOptionsEx = new CGameOptionsEx();
	return;
}