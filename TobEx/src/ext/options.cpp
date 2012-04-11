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
	bActionEquipRangedFix = FALSE;
	bActionExpandedActions = FALSE;
	bActionJoinPartyFix = FALSE;
	bActionPickpocketRemainHidden = FALSE;

	bArenasEnable = FALSE;

	bDebugCriticalMsgBoxFix = FALSE;
	bDebugExternalLogging = FALSE;
	bDebugLogDialogueBar = FALSE;
	bDebugLogFailures = FALSE;
	bDebugLogWarnings = FALSE;
	bDebugLogMissingRes = FALSE;
	bDebugLogMore = FALSE;
	bDebugLogNetworkErrors = FALSE;
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
	bEffButtonFXMod = FALSE;
	bEffCastSpellConditionMod = FALSE;
	bEffCastingLevelModFix = FALSE;
	bEffCharismaModFix = FALSE;
	bEffBackstabEveryHitConfig = FALSE;
	bEffDamageBypassMirrorImageConfig = FALSE;
	bEffDispelMagicalItemConfig = FALSE;
	bEffConstitutionModFix = FALSE;
	bEffContainerUseEffFileFix = FALSE;
	bEffCureDrunkFix = FALSE;
	bEffCutScene2Mod = FALSE;
	bEffDamageFix = FALSE;
	bEffDexterityMod = FALSE;
	bEffStoneskinDisableColour = FALSE;
	bEffDiseaseFix = FALSE;
	bEffDisintegrateFix = FALSE;
	bEffDispelFix = FALSE;
	bEffDropInvDisintegrate = FALSE;
	bEffDropInvFrozenDeath = FALSE;
	bEffDropInvStoneDeath = FALSE;
	bEffFatigueModFix = FALSE;
	bEffFindTrapsModFix = FALSE;
	bEffForbidItemTypeFix = FALSE;
	bEffIntelligenceModFix = FALSE;
	bEffIntoxicationModFix = FALSE;
	bEffInvisibleFix = FALSE;
	bEffLearnSpellMod = FALSE;
	bEffLevelModFix = FALSE;
	bEffLoreModFix = FALSE;
	bEffLuckMod = FALSE;
	bEffMageMemSpellMod = FALSE;
	bEffMagicResistModFix = FALSE;
	bEffMoraleBreakModFix = FALSE;
	bEffNoDamageNoSpellInterrupt = FALSE;
	bEffOpenLocksModFix = FALSE;
	bEffPickPocketsModFix = FALSE;
	bEffPoisonFix = FALSE;
	bEffPolymorphFix = FALSE;
	bEffPriestMemSpellMod = FALSE;
	bEffProficiencyModMod = FALSE;
	bEffRegenerationFix = FALSE;
	bEffRemoveProjectileMod = FALSE;
	bEffRepeatingEffFix = FALSE;
	bEffReputationModFix = FALSE;
	bEffSaveVsBreathMod = FALSE;
	bEffSaveVsDeathMod = FALSE;
	bEffSaveVsPolyMod = FALSE;
	bEffSaveVsSpellMod = FALSE;
	bEffSaveVsWandsMod = FALSE;
	bEffStealthModFix = FALSE;
	bEffStrengthExModFix = FALSE;
	bEffStrengthMod = FALSE;
	bEffTrackingModFix = FALSE;
	bEffMirrorImageUseCastLevel = FALSE;
	bEffUseEFFFileFix = FALSE;
	bEffWisdomModFix = FALSE;

	bEnginePriestKnownSpellsExtend = FALSE;
	bEngineAllowDualClassAll = FALSE;
	bEngineAllowEquipArmorCombat = FALSE;
	bEngineAllowZeroStartXP = FALSE;
	bEngineAssBHPenaltyKit = FALSE;
	bEngineClericRangerHLAFix = FALSE;
	nEngineCustomSoAStartXP = -1;
	nEngineCustomToBStartXP = -1;
	bEngineModifyEffectStacking = FALSE;
	bEngineDisableEndPlayer1Dead = FALSE;
	bEngineDisableInvPauseSP = FALSE;
	bEngineDisableXPBoost = FALSE;
	bEngineCharmSilenceRemoval = FALSE;
	bEngineAutoPauseAllSP = FALSE;
	bEngineExpandedStats = FALSE;
	bEngineExternHPTables = FALSE;
	bEngineExternClassRaceRestrictions = FALSE;
	bEngineExternEncumbrance = FALSE;
	bEngineExternMageSpellsCap = FALSE;
	bEngineExternStealSlots = FALSE;
	bEngineFakeTalkFix = FALSE;
	bEngineProficiencyRestrictions = FALSE;
	bEngineMoveAreasFix = FALSE;
	bEngineRestSpawnsAdvanceTime = FALSE;
	bEngineSpellTurningFix = FALSE;
	bEngineSummonLimitFix = FALSE;
	bEngineTargetDeadFix = FALSE;
	bEngineWeapSpecNumAttacksMod = FALSE;

	bItemsAbilityItemAnim = FALSE;
	bItemsBackstabRestrictionsConfig = FALSE;
	bItemsCriticalHitAversionConfig = FALSE;
	bItemsTargetInvisConfig = FALSE;
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

	bSpellsCastingFix = FALSE;
	bSpellsUnvoicedConfig = FALSE;
	bSpellsTargetInvisConfig = FALSE;

	bStoreItemRechargeFix = FALSE;
		
	bTriggerPickpocketFailed = FALSE;
	bTriggerExpandedTriggers = FALSE;
	bTriggerKitFix = FALSE;
	bTriggerOptimiseBagSearch = FALSE;
	bTriggerPickpocketFailedOnly = FALSE;

	bUserKitsExtend = FALSE;
	bUserContingencySelectSpell = FALSE;
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

	bVideoEnableMorePaperdolls = FALSE;
	bVideoIWDAnimAttack3Fix = FALSE;
	bVideoSpellTurningAnimFix = FALSE;
	bVideoVvcAlphaCrashFix = FALSE;
	bVideoVvcShadowAnimFix = FALSE;

	Init();
}

void CGameOptionsEx::Init() {
	bActionAddKitFix = GetCoreIniValue("Action", "AddKit Actions Fix");
	bActionEquipRangedFix = GetCoreIniValue("Action", "EquipRanged Action Fix");
	bActionExpandedActions = GetCoreIniValue("Action", "Expanded Actions");
	bActionJoinPartyFix = GetCoreIniValue("Action", "JoinParty Action Class Ability Refresh Fix");
	bActionPickpocketRemainHidden = GetTweakIniValue("Tweak", "Action:Remain Hidden On Pickpocket Success");

	bArenasEnable = GetCoreIniValue("Arenas", "Enable Arenas Game Type");

	bDebugCriticalMsgBoxFix = GetCoreIniValue("Debug", "Critical Error Message Box Fix");
	bDebugExternalLogging = GetCoreIniValue("Debug", "Externalise Logging");
	bDebugLogDialogueBar = GetCoreIniValue("Debug", "Log Dialogue Bar");
	bDebugLogFailures = GetCoreIniValue("Debug", "Log Assertion Failures");
	bDebugLogWarnings = GetCoreIniValue("Debug", "Log Assertion Warnings");
	bDebugLogMissingRes = GetCoreIniValue("Debug", "Log Missing Resources");
	bDebugLogMore = GetCoreIniValue("Debug", "Log More Messages");
	bDebugLogNetworkErrors = GetCoreIniValue("Debug", "Log Network Errors");
	bDebugRestoreCombatInfoText = GetCoreIniValue("Debug", "Restore Extra Combat Info Text");
	bDebugVerbose = GetCoreIniValue("Debug", "Verbose Logging");

	bEffApplyConcCheckDamage = GetTweakIniValue("Tweak", "Effect Opcodes:Apply Concentration Check On Damage");
	bEffApplyEffItemFix = GetCoreIniValue("Effect Opcodes", "Apply Effect Item Fix");
	bEffApplyEffItemtypeFix = GetCoreIniValue("Effect Opcodes", "Apply Effect Itemtype Fix");
	bEffAttacksPerRoundFix = GetCoreIniValue("Effect Opcodes", "Attacks Per Round Mod Fix");
	bEffAwakenFix = GetCoreIniValue("Effect Opcodes", "Awaken Fix");
	bEffDamageAwaken = GetTweakIniValue("Tweak", "Effect Opcodes:Awaken On Damage");
	bEffBlindnessAsSpellDesc = GetTweakIniValue("Tweak", "Effect Opcodes:Blindness As Spell Description");
	bEffBlindnessFix = GetCoreIniValue("Effect Opcodes", "Blindness Fix");
	bEffButtonFXMod = GetCoreIniValue("Effect Opcodes", "Button Effects Mod");
	bEffCastSpellConditionMod = GetCoreIniValue("Effect Opcodes", "Cast Spell On Condition Mod");
	bEffCastingLevelModFix = GetCoreIniValue("Effect Opcodes", "Casting Level Mod Fix");
	bEffCharismaModFix = GetCoreIniValue("Effect Opcodes", "Charisma Mod Fix");
	bEffBackstabEveryHitConfig = GetCoreIniValue("Effect Opcodes", "Configurable Backstab Every Hit");
	bEffDamageBypassMirrorImageConfig = GetCoreIniValue("Effect Opcodes", "Configurable Damage Effect Bypasses Mirror Images");
	bEffDispelMagicalItemConfig = GetCoreIniValue("Effect Opcodes", "Configurable Magical Item Dispel Behaviour");
	bEffConstitutionModFix = GetCoreIniValue("Effect Opcodes", "Constitution Mod Fix");
	bEffContainerUseEffFileFix = GetCoreIniValue("Effect Opcodes", "Container Use EFF File Fix");
	bEffCureDrunkFix = GetCoreIniValue("Effect Opcodes", "Cure Drunk Fix");
	bEffCutScene2Mod = GetCoreIniValue("Effect Opcodes", "Cut Scene 2 Mod");
	bEffDamageFix = GetCoreIniValue("Effect Opcodes", "Damage Fix");
	bEffDexterityMod =  GetCoreIniValue("Effect Opcodes", "Dexterity Mod");
	bEffStoneskinDisableColour = GetTweakIniValue("Tweak", "Effect Opcodes:Disable Stoneskin Grey Colour");
	bEffDiseaseFix = GetCoreIniValue("Effect Opcodes", "Disease Fix");
	bEffDisintegrateFix = GetCoreIniValue("Effect Opcodes", "Disintegrate Fix");
	bEffDispelFix = GetCoreIniValue("Effect Opcodes", "Dispel Formula Fix");
	bEffDropInvDisintegrate = GetTweakIniValue("Tweak", "Effect Opcodes:Drop Inventory on Disintegrate");
	bEffDropInvFrozenDeath = GetTweakIniValue("Tweak", "Effect Opcodes:Drop Inventory on Frozen Death");
	bEffDropInvStoneDeath = GetTweakIniValue("Tweak", "Effect Opcodes:Drop Inventory on Stone Death");
	bEffFatigueModFix =  GetCoreIniValue("Effect Opcodes", "Fatigue Mod Fix");
	bEffFindTrapsModFix =  GetCoreIniValue("Effect Opcodes", "Find Traps Mod Fix");
	bEffForbidItemTypeFix = GetCoreIniValue("Effect Opcodes", "Forbid Item Type Fix");
	bEffIntelligenceModFix = GetCoreIniValue("Effect Opcodes", "Intelligence Mod Fix");
	bEffIntoxicationModFix = GetCoreIniValue("Effect Opcodes", "Intoxication Mod Fix");
	bEffInvisibleFix = GetCoreIniValue("Effect Opcodes", "Invisible Fix");
	bEffLearnSpellMod = GetCoreIniValue("Effect Opcodes", "Learn Spell Mod");
	bEffLevelModFix = GetCoreIniValue("Effect Opcodes", "Level Mod Fix");
	bEffLoreModFix = GetCoreIniValue("Effect Opcodes", "Lore Mod Fix");
	bEffLuckMod = GetCoreIniValue("Effect Opcodes", "Luck Mod");
	bEffMageMemSpellMod = GetCoreIniValue("Effect Opcodes", "Mage Spell Slots Mod");
	bEffMagicResistModFix = GetCoreIniValue("Effect Opcodes", "Magic Resistance Mod Fix");
	bEffMoraleBreakModFix = GetCoreIniValue("Effect Opcodes", "Morale Break Mod Fix");
	bEffNoDamageNoSpellInterrupt = GetTweakIniValue("Tweak", "Effect Opcodes:No Spell Interruption On Zero Damage");
	bEffOpenLocksModFix = GetCoreIniValue("Effect Opcodes", "Open Locks Mod Fix");
	bEffPickPocketsModFix = GetCoreIniValue("Effect Opcodes", "Pick Pockets Mod Fix");
	bEffPoisonFix = GetCoreIniValue("Effect Opcodes", "Poison Fix");
	bEffPolymorphFix = GetCoreIniValue("Effect Opcodes", "Polymorph Fix");
	bEffPriestMemSpellMod = GetCoreIniValue("Effect Opcodes", "Priest Spell Slots Mod");
	bEffProficiencyModMod = GetCoreIniValue("Effect Opcodes", "Proficiency Modifier Mod");
	bEffRegenerationFix = GetCoreIniValue("Effect Opcodes", "Regeneration Fix");
	bEffRemoveProjectileMod = GetCoreIniValue("Effect Opcodes", "Remove Projectile Mod");
	bEffRepeatingEffFix = GetCoreIniValue("Effect Opcodes", "Repeating Effect Fix");
	bEffReputationModFix = GetCoreIniValue("Effect Opcodes", "Reputation Mod Fix");
	bEffSaveVsBreathMod = GetCoreIniValue("Effect Opcodes", "Save Vs Breath Mod");
	bEffSaveVsDeathMod = GetCoreIniValue("Effect Opcodes", "Save Vs Death Mod");
	bEffSaveVsPolyMod = GetCoreIniValue("Effect Opcodes", "Save Vs Poly Mod");
	bEffSaveVsSpellMod = GetCoreIniValue("Effect Opcodes", "Save Vs Spell Mod");
	bEffSaveVsWandsMod = GetCoreIniValue("Effect Opcodes", "Save Vs Wands Mod");
	bEffStealthModFix = GetCoreIniValue("Effect Opcodes", "Stealth Mod Fix");
	bEffStrengthExModFix = GetCoreIniValue("Effect Opcodes", "Strength Extra Mod Fix");
	bEffStrengthMod = GetCoreIniValue("Effect Opcodes", "Strength Mod");
	bEffTrackingModFix = GetCoreIniValue("Effect Opcodes", "Tracking Mod Fix");
	bEffMirrorImageUseCastLevel = GetTweakIniValue("Tweak", "Effect Opcodes:Use Caster Level On Mirror Image");
	bEffUseEFFFileFix = GetCoreIniValue("Effect Opcodes", "Use EFF File Fix");
	bEffWisdomModFix = GetCoreIniValue("Effect Opcodes", "Wisdom Mod Fix");

	bEnginePriestKnownSpellsExtend = GetCoreIniValue("Engine", "Allow 99 Priest Known Spells Per Level");
	bEngineAllowDualClassAll = GetTweakIniValue("Tweak", "Engine:Allow All Races to Dual Class");
	bEngineAllowEquipArmorCombat = GetTweakIniValue("Tweak", "Engine:Allow Equipping Armor in Combat");
	bEngineAllowZeroStartXP = GetCoreIniValue("Engine", "Allow Zero Starting Experience");
	bEngineAssBHPenaltyKit = GetCoreIniValue("Engine", "Assassin and Bounty Hunter Penalty to Similar Kits");
	bEngineClericRangerHLAFix = GetCoreIniValue("Engine", "Cleric-Ranger HLA Fix");
	nEngineCustomSoAStartXP = GetTweakIniValue("Tweak", "Engine:Custom Shadows of Amn Starting Experience", "-1");
	nEngineCustomToBStartXP = GetTweakIniValue("Tweak", "Engine:Custom Throne of Bhaal Starting Experience", "-1");
	bEngineModifyEffectStacking = GetCoreIniValue("Engine", "Disable Duplicate Effect Stacking");
	bEngineDisableEndPlayer1Dead = GetTweakIniValue("Tweak", "Engine:Disable End On Player1 Dead");
	bEngineDisableInvPauseSP = GetTweakIniValue("Tweak", "Engine:Disable Force Inventory Pause");
	bEngineDisableXPBoost = GetTweakIniValue("Tweak", "Engine:Disable Experience Boost");
	bEngineCharmSilenceRemoval = GetTweakIniValue("Tweak", "Engine:Disable Silence On Charm");
	bEngineAutoPauseAllSP = GetTweakIniValue("Tweak","Engine:Enable Auto-Pause On All Screens");
	bEngineExpandedStats = GetCoreIniValue("Engine", "Expanded Stats");
	bEngineExternHPTables = GetCoreIniValue("Engine", "Externalise HP Tables");
	bEngineExternClassRaceRestrictions = GetCoreIniValue("Engine", "Externalise Class-Race Restrictions");
	bEngineExternEncumbrance = GetCoreIniValue("Engine", "Externalise Encumbrance Restrictions");
	bEngineExternMageSpellsCap = GetCoreIniValue("Engine", "Externalise Mage Spells Cap");
	bEngineExternStealSlots = GetCoreIniValue("Engine", "Externalise Stealable Item Slots");
	bEngineFakeTalkFix = GetCoreIniValue("Engine", "Fake Talk Exploit Fix");
	bEngineProficiencyRestrictions = GetTweakIniValue("Tweak", "Engine:Level One Proficiency Restrictions");
	bEngineMoveAreasFix = GetCoreIniValue("Engine", "Move Areas Fix");
	bEngineRestSpawnsAdvanceTime = GetTweakIniValue("Tweak", "Engine:Rest Spawns Advance Time");
	bEngineSpellTurningFix = GetCoreIniValue("Engine", "Spell Turning Fix");
	bEngineSummonLimitFix = GetCoreIniValue("Engine", "Summon Limit Fix");
	bEngineTargetDeadFix = GetCoreIniValue("Engine", "Targetting Dead Animations Fix");
	bEngineWeapSpecNumAttacksMod = GetTweakIniValue("Tweak", "Engine:Weapon Specialisation Number of Attacks Mod");

	bItemsAbilityItemAnim = GetCoreIniValue("Items", "Ability-specific Use Item Animations");
	bItemsBackstabRestrictionsConfig = GetCoreIniValue("Items", "Configurable Backstab Restrictions");
	bItemsCriticalHitAversionConfig = GetCoreIniValue("Items", "Configurable Critical Hit Aversion");
	bItemsTargetInvisConfig = GetCoreIniValue("Items", "Configurable Items Cannot Target Invisible");
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

	bSpellsCastingFix = GetCoreIniValue("Spells", "Casting Fixes");
	bSpellsUnvoicedConfig = GetCoreIniValue("Spells", "Configurable Spells Can Be Unvoiced");
	bSpellsTargetInvisConfig = GetCoreIniValue("Spells", "Configurable Spells Can Target Invisible");

	bStoreItemRechargeFix = GetCoreIniValue("Store", "Item Recharge in Bag Fix");

	bTriggerPickpocketFailed = GetCoreIniValue("Trigger", "Enable PickpocketFailed Trigger");
	bTriggerExpandedTriggers = GetCoreIniValue("Trigger", "Expanded Triggers");
	bTriggerKitFix = GetCoreIniValue("Trigger", "Kit Trigger Fix");
	bTriggerOptimiseBagSearch = GetCoreIniValue("Trigger", "Optimise Bag Search Code");
	bTriggerPickpocketFailedOnly = GetTweakIniValue("Tweak", "Trigger:PickpocketFailed Trigger Only");

	bUserKitsExtend = GetCoreIniValue("UI", "Allow 1280 Total Kits");
	bUserContingencySelectSpell = GetCoreIniValue("UI", "Contingency Detects Select Spell");
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

	bVideoEnableMorePaperdolls = GetCoreIniValue("Video", "Enable More Paperdolls");
	bVideoIWDAnimAttack3Fix = GetCoreIniValue("Video", "IWD Animation Attack 3 Fix");
	bVideoSpellTurningAnimFix = GetCoreIniValue("Video", "Spell Turning Animation Fix");
	bVideoVvcAlphaCrashFix = GetCoreIniValue("Video", "VVC Alpha Rendering Crash Fix");
	bVideoVvcShadowAnimFix = GetCoreIniValue("Video", "VVC Shadow Animation Fix");

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