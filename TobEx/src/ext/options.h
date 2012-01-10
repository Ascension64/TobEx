#ifndef OPTIONS_H
#define OPTIONS_H

#include "win32def.h"

struct CGameOptionsEx {
	CGameOptionsEx();

	BOOL bActionAddKitFix;
	BOOL bActionEquipRangedFix;
	BOOL bActionExpandedActions;

	BOOL bArenasEnable;
	
	BOOL bDebugCriticalMsgBoxFix;
	BOOL bDebugExternalLogging;
	BOOL bDebugLogDialogueBar;
	BOOL bDebugLogFailures;
	BOOL bDebugLogWarnings;
	BOOL bDebugLogMissingRes;
	BOOL bDebugLogMore;
	BOOL bDebugLogNetworkErrors;
	BOOL bDebugRestoreCombatInfoText;
	BOOL bDebugVerbose;

	BOOL bEffApplyConcCheckDamage;
	BOOL bEffApplyEffItemFix;
	BOOL bEffApplyEffItemtypeFix;
	BOOL bEffAttacksPerRoundFix;
	BOOL bEffAwakenFix;
	BOOL bEffDamageAwaken;
	BOOL bEffBlindnessAsSpellDesc;
	BOOL bEffBlindnessFix;
	BOOL bEffButtonFXMod;
	BOOL bEffCastSpellConditionMod;
	BOOL bEffCastingLevelModFix;
	BOOL bEffBackstabEveryHitConfig;
	BOOL bEffDamageBypassMirrorImageConfig;
	BOOL bEffDispelMagicalItemConfig;
	BOOL bEffContainerUseEffFileFix;
	BOOL bEffCureDrunkFix;
	BOOL bEffCutScene2Mod;
	BOOL bEffDamageFix;
	BOOL bEffDexterityMod;
	BOOL bEffStoneskinDisableColour;
	BOOL bEffDiseaseFix;
	BOOL bEffDisintegrateFix;
	BOOL bEffDispelFix;
	BOOL bEffDropInvDisintegrate;
	BOOL bEffDropInvFrozenDeath;
	BOOL bEffDropInvStoneDeath;
	BOOL bEffForbidItemTypeFix;
	BOOL bEffInvisibleFix;
	BOOL bEffLearnSpellMod;
	BOOL bEffLuckMod;
	BOOL bEffMageMemSpellMod;
	BOOL bEffMagicResistFix;
	BOOL bEffNoDamageNoSpellInterrupt;
	BOOL bEffPoisonFix;
	BOOL bEffPriestMemSpellMod;
	BOOL bEffProficiencyModMod;
	BOOL bEffRegenerationFix;
	BOOL bEffRemoveProjectileMod;
	BOOL bEffRepeatingEffFix;
	BOOL bEffSaveVsBreathMod;
	BOOL bEffSaveVsDeathMod;
	BOOL bEffSaveVsPolyMod;
	BOOL bEffSaveVsSpellMod;
	BOOL bEffSaveVsWandsMod;
	BOOL bEffStrengthMod;
	BOOL bEffMirrorImageUseCastLevel;

	BOOL bEnginePriestKnownSpellsExtend;
	BOOL bEngineAllowDualClassAll;
	BOOL bEngineAllowEquipArmorCombat;
	BOOL bEngineAllowZeroStartXP;
	BOOL bEngineAssBHPenaltyKit;
	BOOL bEngineClericRangerHLAFix;
	BOOL bEngineXPReportFix;
	int nEngineCustomSoAStartXP;
	int nEngineCustomToBStartXP;
	BOOL bEngineModifyEffectStacking;
	BOOL bEngineDisableEndPlayer1Dead;
	BOOL bEngineDisableInvPauseSP;
	BOOL bEngineDisableXPBoost;
	BOOL bEngineCharmSilenceRemoval;
	BOOL bEngineExpandedStats;
	BOOL bEngineExternHPTables;
	BOOL bEngineExternClassRaceRestrictions;
	BOOL bEngineExternEncumbrance;
	BOOL bEngineExternMageSpellsCap;
	BOOL bEngineProficiencyRestrictions;
	BOOL bEngineMoveAreasFix;
	BOOL bEnginePickpocketRemainHidden;
	BOOL bEngineRestSpawnsAdvanceTime;
	BOOL bEngineSummonLimitFix;
	BOOL bEngineTargetDeadFix;
	BOOL bEngineWeapSpecNumAttacksMod;

	BOOL bItemsAbilityItemAnim;
	BOOL bItemsBackstabRestrictionsConfig;
	BOOL bItemsCriticalHitAversionConfig;
	BOOL bItemsTargetInvisConfig;
	BOOL bItemsRandomTreasureExtend;
	BOOL bItemsExternCreExcl;
	BOOL bItemsNonAmmoLauncherDamageFix;
	BOOL bItemsUseAnimPercentThrowingWeapons;

	BOOL bMusicSonglistExtend;

	BOOL bSoundAnimSoundFix;
	BOOL bSoundAnimAttackSounds;
	BOOL bSoundDlgGreetingSubtitles;
	BOOL bSoundExistenceFix;
	BOOL bSoundExternWalkSounds;
	BOOL bSoundSoundsetSubtitles;

	BOOL bSpellsCastingFix;
	BOOL bSpellsUnvoicedConfig;
	BOOL bSpellsTargetInvisConfig;

	BOOL bTriggerPickpocketFailed;
	BOOL bTriggerExpandedTriggers;
	BOOL bTriggerKitFix;
	BOOL bTriggerOptimiseBagSearch;

	BOOL bUserKitsExtend;
	BOOL bUserContingencySelectSpell;
	int nUserCustomDlgBarSize;
	BOOL bUserLargerTooltipScroll;
	BOOL bUserExternMageSpellHiding;
	BOOL bUserExternRaceSelectionText;
	BOOL bUserChargenMageSpellScroll;
	BOOL bUserChargenKitSelectScroll;
	BOOL bUserRecordMageSpellScroll;
	BOOL bUserMageBookScroll;
	BOOL bUserPriestBookScroll;
	BOOL bUserFourInventorySlots;

	BOOL bVideoEnableMorePaperdolls;
	BOOL bVideoIWDAnimAttack3Fix;
	BOOL bVideoVvcAlphaCrashFix;
	BOOL bVideoVvcShadowAnimFix;

protected:
	void Init();
};

extern CGameOptionsEx* pGameOptionsEx;

int GetCoreIniValue(LPCTSTR szSection, LPCTSTR szKey);
int GetCoreIniValue(LPCTSTR szSection, LPCTSTR szKey, LPCTSTR szDefault);
int GetTweakIniValue(LPCTSTR szSection, LPCTSTR szKey);
int GetTweakIniValue(LPCTSTR szSection, LPCTSTR szKey, LPCTSTR szDefault);
void InitOptions();

#endif //OPTIONS_H