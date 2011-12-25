#ifndef OPTIONS_H
#define OPTIONS_H

#include "stdafx.h"

struct CGameOptionsEx {
	CGameOptionsEx();

	BOOL bDebugCriticalMsgBoxFix;
	BOOL bDebugExternalLogging;
	BOOL bDebugLogFailures;
	BOOL bDebugLogWarnings;
	BOOL bDebugLogMore;
	BOOL bDebugRestoreCombatInfoText;

	BOOL bEffAttacksPerRoundFix;
	BOOL bEffAwakenFix;
	BOOL bEffDamageAwaken;
	int nEffBlindnessFix;
	BOOL bEffBackstabEveryHitConfig;
	BOOL bEffDamageBypassMirrorImageConfig;
	BOOL bEffDispelMagicalItemConfig;
	BOOL bEffCureDrunkFix;
	BOOL bEffStoneskinDisableColour;
	BOOL bEffDiseaseFix;
	BOOL bEffDispelFix;
	BOOL bEffCutScene2Extend;
	BOOL bEffForbidItemTypeFix;
	BOOL bEffInvisibleFix;
	BOOL bEffMagicResistFix;
	BOOL bEffOpcode13E;
	BOOL bEffPoisonFix;
	BOOL bEffRegenerationFix;
	BOOL bEffRepeatingEffFix;
	BOOL bEffMirrorImageUseCastLevel;

	BOOL bEnginePriestKnownSpellsExtend;
	BOOL bEngineCastingLevelBonus;
	BOOL bEngineExperienceFix;
	int nEngineContingencyTriggerDelay;
	BOOL bEngineCharmSilenceRemoval;
	BOOL bEngineExternClassRaceRestrictions;
	BOOL bEngineProficiencyRestrictions;
	BOOL bEnginePickpocketRemainHidden;

	BOOL bItemsBackstabRestrictionsConfig;
	BOOL bItemsCriticalHitAversionConfig;
	BOOL bItemsRandomTreasureExtend;

	BOOL bMusicSonglistExtend;

	BOOL bSoundAnimSoundFix;
	BOOL bSoundAnimAttackSounds;
	BOOL bSoundExistenceFix;
	BOOL bSoundExternWalkSounds;
	BOOL bSoundSoundsetSubtitles;

	BOOL bTriggerPickpocketFailed;

	BOOL bUserKitsExtend;
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
	BOOL bUserVvcAlphaCrashFix;

protected:
	void Init();
};

extern CGameOptionsEx* pGameOptionsEx;

int GetIniValue(LPCTSTR, LPCTSTR);
void InitOptions();

#endif //OPTIONS_H