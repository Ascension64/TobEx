#ifndef OPTIONS_H
#define OPTIONS_H

#include "win32def.h"

struct CGameOptionsEx {
	CGameOptionsEx();

	BOOL bActionAddKitFix;
	BOOL bActionEquipRangedFix;
	
	BOOL bDebugCriticalMsgBoxFix;
	BOOL bDebugExternalLogging;
	BOOL bDebugLogDialogueBar;
	BOOL bDebugLogFailures;
	BOOL bDebugLogWarnings;
	BOOL bDebugLogMissingRes;
	BOOL bDebugLogMore;
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
	BOOL bEffCastSpellConditionMod;
	BOOL bEffCastingLevelModFix;
	BOOL bEffBackstabEveryHitConfig;
	BOOL bEffDamageBypassMirrorImageConfig;
	BOOL bEffDispelMagicalItemConfig;
	BOOL bEffCureDrunkFix;
	BOOL bEffDamageFix;
	BOOL bEffStoneskinDisableColour;
	BOOL bEffDiseaseFix;
	BOOL bEffDisintegrateFix;
	BOOL bEffDispelFix;
	BOOL bEffCutScene2Extend;
	BOOL bEffForbidItemTypeFix;
	BOOL bEffInvisibleFix;
	BOOL bEffIWDDexterityMod;
	BOOL bEffIWDMageMemSpellMod;
	BOOL bEffIWDPriestMemSpellMod;
	BOOL bEffIWDStrengthMod;
	BOOL bEffLearnSpellMod;
	BOOL bEffMagicResistFix;
	BOOL bEffNoDamageNoSpellInterrupt;
	BOOL bEffPoisonFix;
	BOOL bEffRegenerationFix;
	BOOL bEffRemoveProjectileMod;
	BOOL bEffRepeatingEffFix;
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
	BOOL bEngineDisableInvPauseSP;
	BOOL bEngineDisableXPBoost;
	BOOL bEngineCharmSilenceRemoval;
	BOOL bEngineExpandedStats;
	BOOL bEngineExternHPTables;
	BOOL bEngineExternClassRaceRestrictions;
	BOOL bEngineExternEncumbrance;
	BOOL bEngineProficiencyRestrictions;
	BOOL bEnginePickpocketRemainHidden;
	BOOL bEngineRestSpawnsAdvanceTime;
	BOOL bEngineTargetDeadFix;
	BOOL bEngineWeapSpecNumAttacksMod;

	BOOL bItemsBackstabRestrictionsConfig;
	BOOL bItemsCriticalHitAversionConfig;
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

	BOOL bSpellsTargetInvisConfig;

	BOOL bTriggerPickpocketFailed;
	BOOL bTriggerExpandedTriggers;
	BOOL bTriggerKitFix;

	BOOL bUserKitsExtend;
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

	BOOL bVideoDisableBrightestFix;
	BOOL bVideoEnableMorePaperdolls;
	BOOL bVideoIWDAnimAttack3Fix;
	BOOL bVideoVvcAlphaCrashFix;

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