#ifndef OPTIONS_H
#define OPTIONS_H

#include "win32def.h"

struct CGameOptionsEx {
	CGameOptionsEx();

	BOOL bActionAddKitFix;
	BOOL bActionSpellTargetInvisConfig;
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
	int nEffBlindnessFix;
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
	BOOL bEngineCastingLevelBonus;
	BOOL bEngineAssBHPenaltyKit;
	BOOL bEngineClericRangerHLAFix;
	BOOL bEngineExperienceFix;
	int nEngineContingencyTriggerDelay;
	BOOL bEngineModifyEffectStacking;
	BOOL bEngineDisableInvPauseSP;
	BOOL bEngineCharmSilenceRemoval;
	BOOL bEngineExpandedStats;
	BOOL bEngineExternHPTables;
	BOOL bEngineExternClassRaceRestrictions;
	BOOL bEngineExternEncumbrance;
	BOOL bEngineProficiencyRestrictions;
	BOOL bEnginePickpocketRemainHidden;
	BOOL bEngineRestSpawnsAdvanceTime;
	BOOL bEngineTargetDeadFix;

	BOOL bItemsBackstabRestrictionsConfig;
	BOOL bItemsCriticalHitAversionConfig;
	BOOL bItemsRandomTreasureExtend;
	BOOL bItemsExternCreExcl;
	BOOL bItemsUseAnimPercentThrowingWeapons;

	BOOL bMusicSonglistExtend;

	BOOL bSoundAnimSoundFix;
	BOOL bSoundAnimAttackSounds;
	BOOL bSoundDlgGreetingSubtitles;
	BOOL bSoundExistenceFix;
	BOOL bSoundExternWalkSounds;
	BOOL bSoundSoundsetSubtitles;

	BOOL bTriggerPickpocketFailed;
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
	BOOL bVideoIWDAnimAttack3Fix;
	BOOL bVideoVvcAlphaCrashFix;

protected:
	void Init();
};

extern CGameOptionsEx* pGameOptionsEx;

int GetIniValue(LPCTSTR, LPCTSTR);
void InitOptions();

#endif //OPTIONS_H