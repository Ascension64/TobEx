#include "optionsext.h"

#include "utils.h"

CGameOptionsEx* pGameOptionsEx = NULL;

void InitOptions() {
	pGameOptionsEx = new CGameOptionsEx();

	pGameOptionsEx->SetOption("Action_AddKitFix", "Action", "AddKit Actions Fix");
	pGameOptionsEx->SetOption("Action_AttackOnceFix", "Action", "AttackOnce Action Fix");
	pGameOptionsEx->SetOption("Action_AttacksGenuine", "Tweak", "Action:Attacks Are All Genuine");
	pGameOptionsEx->SetOption("Action_ChangeAnimFix", "Action", "ChangeAnimation Action Fix");
	pGameOptionsEx->SetOption("Action_EquipRangedFix", "Action", "EquipRanged Action Fix");
	pGameOptionsEx->SetOption("Action_ExpandedActions", "Action", "Expanded Actions");
	pGameOptionsEx->SetOption("Action_JoinPartyFix", "Action", "JoinParty Action Class Ability Refresh Fix");
	pGameOptionsEx->SetOption("Action_PickpocketRemainHidden", "Tweak", "Action:Remain Hidden On Pickpocket Success");
	pGameOptionsEx->SetOption("Action_TakePartyItemFix", "Action", "TakePartyItem Fix");

	pGameOptionsEx->SetOption("Arenas_Enable", "Arenas", "Enable Arenas Game Type");

	pGameOptionsEx->SetOption("Debug_CriticalMsgBoxFix", "Debug", "Critical Error Message Box Fix");
	pGameOptionsEx->SetOption("Debug_ExpandedLUAConsole", "Debug", "Expanded LUA Console");
	pGameOptionsEx->SetOption("Debug_ExternalLogging", "Debug", "Externalise Logging");
	pGameOptionsEx->SetOption("Debug_LogDialogueBar", "Debug", "Log Dialogue Bar");
	pGameOptionsEx->SetOption("Debug_LogFailures", "Debug", "Log Assertion Failures");
	pGameOptionsEx->SetOption("Debug_LogWarnings", "Debug", "Log Assertion Warnings");
	pGameOptionsEx->SetOption("Debug_LogMissingRes", "Debug", "Log Missing Resources");
	pGameOptionsEx->SetOption("Debug_LogMore", "Debug", "Log More Messages");
	pGameOptionsEx->SetOption("Debug_LogNetworkErrors", "Debug", "Log Network Errors");
	pGameOptionsEx->SetOption("Debug_RestoreCombatInfoText", "Debug", "Restore Extra Combat Info Text");
	pGameOptionsEx->SetOption("Debug_Verbose", "Debug", "Verbose Logging");

	pGameOptionsEx->SetOption("Eff_ApplyConcCheckDamage", "Tweak", "Effect Opcodes:Apply Concentration Check On Damage");
	pGameOptionsEx->SetOption("Eff_ApplyEffItemFix", "Effect Opcodes", "Apply Effect Item Fix");
	pGameOptionsEx->SetOption("Eff_ApplyEffItemtypeFix", "Effect Opcodes", "Apply Effect Itemtype Fix");
	pGameOptionsEx->SetOption("Eff_AttacksPerRoundFix", "Effect Opcodes", "Attacks Per Round Mod Fix");
	pGameOptionsEx->SetOption("Eff_AwakenFix", "Effect Opcodes", "Awaken Fix");
	pGameOptionsEx->SetOption("Eff_DamageAwaken", "Tweak", "Effect Opcodes:Awaken On Damage");
	pGameOptionsEx->SetOption("Eff_BlindnessAsSpellDesc", "Tweak", "Effect Opcodes:Blindness As Spell Description");
	pGameOptionsEx->SetOption("Eff_BlindnessFix", "Effect Opcodes", "Blindness Fix");
	pGameOptionsEx->SetOption("Eff_ButtonFXMod", "Effect Opcodes", "Button Effects Mod");
	pGameOptionsEx->SetOption("Eff_CastSpellConditionMod", "Effect Opcodes", "Cast Spell On Condition Mod");
	pGameOptionsEx->SetOption("Eff_CastingLevelModFix", "Effect Opcodes", "Casting Level Mod Fix");
	pGameOptionsEx->SetOption("Eff_CharismaModFix", "Effect Opcodes", "Charisma Mod Fix");
	pGameOptionsEx->SetOption("Eff_BackstabEveryHitConfig", "Effect Opcodes", "Configurable Backstab Every Hit");
	pGameOptionsEx->SetOption("Eff_DamageBypassMirrorImageConfig", "Effect Opcodes", "Configurable Damage Effect Bypasses Mirror Images");
	pGameOptionsEx->SetOption("Eff_StackingConfig", "Effect Opcodes", "Configurable Effect Stacking");
	pGameOptionsEx->SetOption("Eff_DispelMagicalItemConfig", "Effect Opcodes", "Configurable Magical Item Dispel Behaviour");
	pGameOptionsEx->SetOption("Eff_ConstitutionModFix", "Effect Opcodes", "Constitution Mod Fix");
	pGameOptionsEx->SetOption("Eff_ContainerUseEffFileFix", "Effect Opcodes", "Container Use EFF File Fix");
	pGameOptionsEx->SetOption("Eff_CureDrunkFix", "Effect Opcodes", "Cure Drunk Fix");
	pGameOptionsEx->SetOption("Eff_CutScene2Mod", "Effect Opcodes", "Cut Scene 2 Mod");
	pGameOptionsEx->SetOption("Eff_DamageFix", "Effect Opcodes", "Damage Fix");
	pGameOptionsEx->SetOption("Eff_DexterityMod", "Effect Opcodes", "Dexterity Mod");
	pGameOptionsEx->SetOption("Eff_StoneskinDisableColour", "Tweak", "Effect Opcodes:Disable Stoneskin Grey Colour");
	pGameOptionsEx->SetOption("Eff_DiseaseFix", "Effect Opcodes", "Disease Fix");
	pGameOptionsEx->SetOption("Eff_DisintegrateFix", "Effect Opcodes", "Disintegrate Fix");
	pGameOptionsEx->SetOption("Eff_DispelFix", "Effect Opcodes", "Dispel Formula Fix");
	pGameOptionsEx->SetOption("Eff_DropInvDisintegrate", "Tweak", "Effect Opcodes:Drop Inventory on Disintegrate");
	pGameOptionsEx->SetOption("Eff_DropInvFrozenDeath", "Tweak", "Effect Opcodes:Drop Inventory on Frozen Death");
	pGameOptionsEx->SetOption("Eff_DropInvStoneDeath", "Tweak", "Effect Opcodes:Drop Inventory on Stone Death");
	pGameOptionsEx->SetOption("Eff_FatigueModFix", "Effect Opcodes", "Fatigue Mod Fix");
	pGameOptionsEx->SetOption("Eff_FindTrapsModFix", "Effect Opcodes", "Find Traps Mod Fix");
	pGameOptionsEx->SetOption("Eff_ForbidItemTypeFix", "Effect Opcodes", "Forbid Item Type Fix");
	pGameOptionsEx->SetOption("Eff_IntelligenceModFix", "Effect Opcodes", "Intelligence Mod Fix");
	pGameOptionsEx->SetOption("Eff_IntoxicationModFix", "Effect Opcodes", "Intoxication Mod Fix");
	pGameOptionsEx->SetOption("Eff_InvisibleFix", "Effect Opcodes", "Invisible Fix");
	pGameOptionsEx->SetOption("Eff_LearnSpellMod", "Effect Opcodes", "Learn Spell Mod");
	pGameOptionsEx->SetOption("Eff_LevelModFix", "Effect Opcodes", "Level Mod Fix");
	pGameOptionsEx->SetOption("Eff_LoreModFix", "Effect Opcodes", "Lore Mod Fix");
	pGameOptionsEx->SetOption("Eff_LuckMod", "Effect Opcodes", "Luck Mod");
	pGameOptionsEx->SetOption("Eff_MageMemSpellMod", "Effect Opcodes", "Mage Spell Slots Mod");
	pGameOptionsEx->SetOption("Eff_MagicResistModFix", "Effect Opcodes", "Magic Resistance Mod Fix");
	pGameOptionsEx->SetOption("Eff_MoraleBreakModFix", "Effect Opcodes", "Morale Break Mod Fix");
	pGameOptionsEx->SetOption("Eff_NoDamageNoSpellInterrupt", "Tweak", "Effect Opcodes:No Spell Interruption On Zero Damage");
	pGameOptionsEx->SetOption("Eff_OpenLocksModFix", "Effect Opcodes", "Open Locks Mod Fix");
	pGameOptionsEx->SetOption("Eff_PickPocketsModFix", "Effect Opcodes", "Pick Pockets Mod Fix");
	pGameOptionsEx->SetOption("Eff_PoisonFix", "Effect Opcodes", "Poison Fix");
	pGameOptionsEx->SetOption("Eff_PoisonResistMod", "Effect Opcodes", "Poison Resistance Mod");
	pGameOptionsEx->SetOption("Eff_PolymorphFix", "Effect Opcodes", "Polymorph Fix");
	pGameOptionsEx->SetOption("Eff_PriestMemSpellMod", "Effect Opcodes", "Priest Spell Slots Mod");
	pGameOptionsEx->SetOption("Eff_ProficiencyModMod", "Effect Opcodes", "Proficiency Modifier Mod");
	pGameOptionsEx->SetOption("Eff_RegenerationFix", "Effect Opcodes", "Regeneration Fix");
	pGameOptionsEx->SetOption("Eff_RemoveProjectileMod", "Effect Opcodes", "Remove Projectile Mod");
	pGameOptionsEx->SetOption("Eff_RepeatingEffFix", "Effect Opcodes", "Repeating Effect Fix");
	pGameOptionsEx->SetOption("Eff_ReputationModFix", "Effect Opcodes", "Reputation Mod Fix");
	pGameOptionsEx->SetOption("Eff_SaveVsBreathMod", "Effect Opcodes", "Save Vs Breath Mod");
	pGameOptionsEx->SetOption("Eff_SaveVsDeathMod", "Effect Opcodes", "Save Vs Death Mod");
	pGameOptionsEx->SetOption("Eff_SaveVsPolyMod", "Effect Opcodes", "Save Vs Poly Mod");
	pGameOptionsEx->SetOption("Eff_SaveVsSpellMod", "Effect Opcodes", "Save Vs Spell Mod");
	pGameOptionsEx->SetOption("Eff_SaveVsWandsMod", "Effect Opcodes", "Save Vs Wands Mod");
	pGameOptionsEx->SetOption("Eff_SavingThrowFix", "Effect Opcodes", "Saving Throw Fix");
	pGameOptionsEx->SetOption("Eff_StealthModFix", "Effect Opcodes", "Stealth Mod Fix");
	pGameOptionsEx->SetOption("Eff_StrengthExModFix", "Effect Opcodes", "Strength Extra Mod Fix");
	pGameOptionsEx->SetOption("Eff_StrengthMod", "Effect Opcodes", "Strength Mod");
	pGameOptionsEx->SetOption("Eff_TrackingModFix", "Effect Opcodes", "Tracking Mod Fix");
	pGameOptionsEx->SetOption("Eff_MirrorImageUseCastLevel", "Tweak", "Effect Opcodes:Use Caster Level On Mirror Image");
	pGameOptionsEx->SetOption("Eff_UseEFFFileFix", "Effect Opcodes", "Use EFF File Fix");
	pGameOptionsEx->SetOption("Eff_WisdomModFix", "Effect Opcodes", "Wisdom Mod Fix");

	pGameOptionsEx->SetOption("Engine_PriestKnownSpellsExtend", "Engine", "Allow 99 Priest Known Spells Per Level");
	pGameOptionsEx->SetOption("Engine_AllowDualClassAll", "Tweak", "Engine:Allow All Races to Dual Class");
	pGameOptionsEx->SetOption("Engine_AllowEquipArmorCombat", "Tweak", "Engine:Allow Equipping Armor in Combat");
	pGameOptionsEx->SetOption("Engine_AllowZeroStartXP", "Engine", "Allow Zero Starting Experience");
	pGameOptionsEx->SetOption("Engine_AssBHPenaltyKit", "Engine", "Assassin and Bounty Hunter Penalty to Similar Kits");
	pGameOptionsEx->SetOption("Engine_ClericRangerHLAFix", "Engine", "Cleric-Ranger HLA Fix");
	pGameOptionsEx->SetOption("Engine_CloneCreatureFix", "Engine", "Clone Creature Fix");
	pGameOptionsEx->SetOption("Engine_CustomSoAStartXP", "Tweak", "Engine:Custom Shadows of Amn Starting Experience", "-1");
	pGameOptionsEx->SetOption("Engine_CustomToBStartXP", "Tweak", "Engine:Custom Throne of Bhaal Starting Experience", "-1");
	pGameOptionsEx->SetOption("Engine_DisableEndPlayer1Dead", "Tweak", "Engine:Disable End On Player1 Dead");
	pGameOptionsEx->SetOption("Engine_DisableInvPauseSP", "Tweak", "Engine:Disable Force Inventory Pause");
	pGameOptionsEx->SetOption("Engine_DisableXPBoost", "Tweak", "Engine:Disable Experience Boost");
	pGameOptionsEx->SetOption("Engine_CharmSilenceRemoval", "Tweak", "Engine:Disable Silence On Charm");
	pGameOptionsEx->SetOption("Engine_AutoPauseAllSP", "Tweak","Engine:Enable Auto-Pause On All Screens");
	pGameOptionsEx->SetOption("Engine_ExpandedStats", "Engine", "Expanded Stats");
	pGameOptionsEx->SetOption("Engine_ExternHPTables", "Engine", "Externalise HP Tables");
	pGameOptionsEx->SetOption("Engine_ExternClassRaceRestrictions", "Engine", "Externalise Class-Race Restrictions");
	pGameOptionsEx->SetOption("Engine_ExternDifficulty", "Engine", "Externalise Difficulty Settings");
	pGameOptionsEx->SetOption("Engine_ExternEncumbrance", "Engine", "Externalise Encumbrance Restrictions");
	pGameOptionsEx->SetOption("Engine_ExternMageSpellsCap", "Engine", "Externalise Mage Spells Cap");
	pGameOptionsEx->SetOption("Engine_ExternStealSlots", "Engine", "Externalise Stealable Item Slots");
	pGameOptionsEx->SetOption("Engine_FakeTalkFix", "Engine", "Fake Talk Exploit Fix");
	pGameOptionsEx->SetOption("Engine_LauncherProficiencyFix", "Engine", "Launcher Proficiency Fix");
	pGameOptionsEx->SetOption("Engine_ProficiencyRestrictions", "Tweak", "Engine:Level One Proficiency Restrictions");
	pGameOptionsEx->SetOption("Engine_MoveAreasFix", "Engine", "Move Areas Fix");
	pGameOptionsEx->SetOption("Engine_OptimiseVarCode", "Engine", "Optimise Variables Code");
	pGameOptionsEx->SetOption("Engine_RestSpawnsAdvanceTime", "Tweak", "Engine:Rest Spawns Advance Time");
	pGameOptionsEx->SetOption("Engine_SpellTurningFix", "Engine", "Spell Turning Fix");
	pGameOptionsEx->SetOption("Engine_SummonLimitFix", "Engine", "Summon Limit Fix");
	pGameOptionsEx->SetOption("Engine_TargetDeadFix", "Engine", "Targetting Dead Animations Fix");
	pGameOptionsEx->SetOption("Engine_WeapSpecNumAttacksMod", "Tweak", "Engine:Weapon Specialisation Number of Attacks Mod");

	pGameOptionsEx->SetOption("Items_AbilityItemAnim", "Items", "Ability-specific Use Item Animations");
	pGameOptionsEx->SetOption("Items_BackstabRestrictionsConfig", "Items", "Configurable Backstab Restrictions");
	pGameOptionsEx->SetOption("Items_CriticalHitAversionConfig", "Items", "Configurable Critical Hit Aversion");
	pGameOptionsEx->SetOption("Items_TargetInvisConfig", "Items", "Configurable Items Cannot Target Invisible");
	pGameOptionsEx->SetOption("Items_RandomTreasureExtend", "Items", "Enable 99 Random Treasure Rows");
	pGameOptionsEx->SetOption("Items_ExternCreExcl", "Items", "Externalise Item-Creature Exclusions");
	pGameOptionsEx->SetOption("Items_NonAmmoLauncherDamageFix", "Items", "Non-Ammo Launcher Damage Fix");
	pGameOptionsEx->SetOption("Items_UseAnimPercentThrowingWeapons", "Tweak", "Items:Use Animation Percentages for Throwing Weapons");

	pGameOptionsEx->SetOption("Music_SonglistExtend", "Music", "Extended Songlist");

	pGameOptionsEx->SetOption("Sound_AnimSoundFix", "Sound", "Animation Sound Fix");
	pGameOptionsEx->SetOption("Sound_DlgGreetingSubtitles", "Tweak", "Sound:Dialogue Greeting Subtitles");
	pGameOptionsEx->SetOption("Sound_AnimAttackSounds", "Tweak", "Sound:Enable Animation Attack Sounds");
	pGameOptionsEx->SetOption("Sound_ExistenceFix", "Sound", "Existence Sound Fix");
	pGameOptionsEx->SetOption("Sound_ExternWalkSounds", "Sound", "Externalise Animation Walking Sounds");
	pGameOptionsEx->SetOption("Sound_SoundsetSubtitles", "Sound", "Soundset Subtitles");

	pGameOptionsEx->SetOption("Spells_CastingFix", "Spells", "Casting Fixes");
	pGameOptionsEx->SetOption("Spells_UnvoicedConfig", "Spells", "Configurable Spells Can Be Unvoiced");
	pGameOptionsEx->SetOption("Spells_TargetInvisConfig", "Spells", "Configurable Spells Can Target Invisible");
	pGameOptionsEx->SetOption("Spells_ExternBardSong", "Spells", "Externalise Bard Song Effects");

	pGameOptionsEx->SetOption("Store_ItemRechargeMod", "Store", "Item Recharge Mod");

	pGameOptionsEx->SetOption("Trigger_PickpocketFailed", "Trigger", "Enable PickpocketFailed Trigger");
	pGameOptionsEx->SetOption("Trigger_ExpandedTriggers", "Trigger", "Expanded Triggers");
	pGameOptionsEx->SetOption("Trigger_KitFix", "Trigger", "Kit Trigger Fix");
	pGameOptionsEx->SetOption("Trigger_OptimiseBagSearch", "Trigger", "Optimise Bag Search Code");
	pGameOptionsEx->SetOption("Trigger_PickpocketFailedOnly", "Tweak", "Trigger:PickpocketFailed Trigger Only");

	pGameOptionsEx->SetOption("User_KitsExtend", "UI", "Allow 1280 Total Kits");
	pGameOptionsEx->SetOption("User_ContingencySelectSpell", "UI", "Contingency Detects Select Spell");
	pGameOptionsEx->SetOption("User_CustomDlgBarSize", "UI", "Custom Dialogue Bar Buffer Size");
	pGameOptionsEx->GetMap()["User_CustomDlgBarSize"] = max(pGameOptionsEx->GetMap()["User_CustomDlgBarSize"], 0);
	pGameOptionsEx->SetOption("User_LargerTooltipScroll", "UI", "Enlarge Tooltip Scroll");
	pGameOptionsEx->SetOption("User_ExternMageSpellHiding", "UI", "Externalise Mage Spell Hiding");
	pGameOptionsEx->SetOption("User_ExternRaceSelectionText", "UI", "Externalise Race Selection StrRef");
	pGameOptionsEx->SetOption("User_ChargenMageSpellScroll", "UI", "Scrollable Chargen Mage Spell Selection");
	pGameOptionsEx->SetOption("User_ChargenKitSelectScroll", "UI", "Scrollable Kit Selection");
	pGameOptionsEx->SetOption("User_RecordMageSpellScroll", "UI", "Scrollable Level Up Mage Spell Selection");
	pGameOptionsEx->SetOption("User_MageBookScroll", "UI", "Scrollable Mage Spellbook");
	pGameOptionsEx->SetOption("User_PriestBookScroll", "UI", "Scrollable Priest Spellbook");
	pGameOptionsEx->SetOption("User_FourInventorySlots", "Tweak", "UI:Universal Four Inventory Weapon Slots");

	pGameOptionsEx->SetOption("Video_EnableMorePaperdolls", "Video", "Enable More Paperdolls");
	pGameOptionsEx->SetOption("Video_IWDAnimAttack3Fix", "Video", "IWD Animation Attack 3 Fix");
	pGameOptionsEx->SetOption("Video_SpellTurningAnimFix", "Video", "Spell Turning Animation Fix");
	pGameOptionsEx->SetOption("Video_VvcAlphaCrashFix", "Video", "VVC Alpha Rendering Crash Fix");
	pGameOptionsEx->SetOption("Video_VvcShadowAnimFix", "Video", "VVC Shadow Animation Fix");

	return;
}