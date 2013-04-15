//TobExEE
#ifndef OBJCRE_H
#define OBJCRE_H

#include "stdafx.h"
#include "effcore.h"
#include "splcore.h"
#include "objcore.h"
#include "scrcore.h"
#include "itmcore.h"
#include "sndcore.h"
#include "vidcore.h"
#include "pathfind.h"
#include "objproj.h"
#include "splcore.h"
#include "dlgcore.h"
#include "animcore.h"
#include "tlkcore.h"
#include "uicore.h"
#include "particle.h"

//Feedback IDs
#define FEEDBACK_BACKSTAB_SUCCESS			0x01
#define FEEDBACK_BACKSTAB_WEAPON_UNSUITABLE	0x1C
#define FEEDBACK_PICKPOCKET_DISABLED_ARMOR	0x1E
#define FEEDBACK_PICKPOCKET_FAILED_HOSTILE	0x1F
#define FEEDBACK_PICKPOCKET_FAILED			0x20
#define FEEDBACK_PICKPOCKET_NO_ITEMS		0x21
#define FEEDBACK_PICKPOCKET_INV_FULL		0x22
#define FEEDBACK_PICKPOCKET_SUCCESS			0x23
#define FEEDBACK_BACKSTAB_FAIL				0x40
#define FEEDBACK_SPELLFAILED_INVISIBLE		0x42
#define FEEDBACK_CANNOT_TALK_BUSY			0x43

struct CQuickObject { //Size 30h, FIX_ME
//Constructor: see 0x532F23
	ResRef m_rUsageIcon; //0h
	STRREF m_strrefName; //8h
	ResRef uc;
	STRREF m_strrefLauncherName; //14h
	short m_wAmount; //18h
	struct ObjectInfo { //Size 14h
		short m_wType; //0h, 1 = SPL, 2 = ITM, 3 = cast spell from list
		short m_wItemSlotIdx; //2h
		short m_wItemAbilityIdx; //4h
		ResRef m_rSpellName; //6h
		char m_nTargetType; //eh
		char m_nTargets; //fh
		STRREF m_strrefAbilityTooltip; //10h
	} m_ObjectInfo; //1ah
	bool m_bDisableButton; //2eh
	bool m_bConstructed; //2fh
};

class CQuickObjectList : public IECPtrList { //Size 20h, FIX_ME
//Constructor: 0x55ECC0
public:
	//AA99DC
	int m_nIndexMageStart; //1ch, index at which wizard spells start (since order is priest, mage, innate)
};

struct CQuickSlot { //Size 34h
	ResRef m_rName; //0h
	int u8; //-1
	ResRef uc; //second name?
	int u14;
	short u18;
	char p1a[2];
	//struct copy constructor at 568340
		short u1c;
		short m_nSlotIdx; //1eh
		short m_nAbilityIdx; //20h
		ResRef m_rSpellName; //22h
		char u2a;
		char u2b;
		int u2c; //-1
	//end struct
	char u30;
	char u31;
	char p32[2];
};

struct CFavorite : CObject { //Size 10h
	ResRef m_rName; //4h
	short m_nTimesUsed; //ch
	char pe[2];
};

struct CProtectedSpl { //Size 1Ch, FIX_ME
	int m_nLevel; //0h, spl level subtracted from amount of immunity/bounces left
	int m_nOpcode; //4h, opcode of the protection effect
	CProjectile* m_pProj; //8h
	BOOL m_bNoProjectile; //ch, do not make a bounce projectile
	STRREF m_strref; //10h
	BOOL m_bStrRefOnly; //14h, ignores everything except printing a string to console
	BOOL m_bSpellTrap; //18h, applies Restore Lost Spells eff on nPower
};

class CProtectedSplList : public IECPtrList { //1Ch
public:
};

class CCreatureObject : public CGameSprite { //Size 3968h
public:
	virtual BOOL EvaluateTrigger(Trigger& t); //v60
	virtual ACTIONRESULT ExecuteAction(); //v80

	//vbc, void CCreatureObject::SetObjects(o, bSetDerived, bSetBase)
	//vc8, void RefreshObjects(), 1c = 3698 (identical), 3684 = 3698 (except general)
	//vcc, void ProcessScriptsOnce(BOOL bOverrideOnly)
	//...
	//etc. to v??

	CDerivedStats& GetDerivedStats();

	short u390;
	short u392;
	ResRef m_rSaveName; //394h, CRE name with * prefix
	short m_wCreType; //39ch, NORMAL or RANDOM
	char p39e[2];
	int m_nExpirationTime; //3a0h, nTicksTillRemove
	short m_wHuntingRange; //3a4h, nMaxMvtDistance
	short m_wFollowRange; //3a6h, nMaxMvtDistanceToObject
	CPoint m_posStart; //3a8h
	int m_nTimeOfDayVisible; //3b0h, creature schedule
	CreFileHeader m_header; //3b4h
	CKnownSpellList m_KnownSpellsPriest[7]; //61ch
	CKnownSpellList m_KnownSpellsWizard[9]; //6e0h
	CKnownSpellList m_KnownSpellsInnate; //7dch
	CreFileMemorizedSpellLevel* m_MemInfoPriest[7]; //7f8h
	CreFileMemorizedSpellLevel* m_MemInfoWizard[9]; //814h
	CreFileMemorizedSpellLevel* m_MemInfoInnate; //838h
	CMemSpellList m_MemSpellsPriest[7]; //83ch
	CMemSpellList m_MemSpellsWizard[9]; //900h
	CMemSpellList m_MemSpellsInnate; //9fch
	CCreInventory m_Inventory; //a18h

	CGameObject* m_pThis; //abch
	int uac0;
	int uac4;
	CDerivedStats m_cdsCurrent; //ac8h
	CDerivedStats m_cdsPrevious; //1384hh, previous state to restore after effect finishes
	CDerivedStats m_cdsDiff; //1c40, difference to add to currentState

	struct CQuickSlots {
		int u0;
		CQuickSlot m_qsWeapons[4]; //4h
		CQuickSlot m_qsSpells[3]; //d4h
		CQuickSlot m_qsItems[3]; //170h
	} u24fc;

	IECString m_sLongName; //2708h
	char u270c;
	char p270d[3];
	struct CStatistics { //Size A4h
		STRREF m_mostPowerfulFoe; //0h
		int m_mostPowerfulXP; //4h
		int m_inPartyTime; //8h
		int m_joinedTime; //ch
		BOOL m_inParty; //10h
		int m_chapterKillXP; //14h
		int m_chapterNumKills; //18h
		int m_gameKillXP; //1ch
		int m_gameNumKills; //20h
		CFavorite m_favSpell[4]; //24h
		CFavorite m_favWeapon[4]; //64h
	} m_statistics; //2710h
	ResRef m_rCurrentArea; //27b4
	char m_bGlobal; //27bch, is this Cre Global
	char m_nModalState; //27bdh, 0: None, 1: Battle Song, 2: Detecting Traps, 3: Hide in Shadows, 4: Turn Undead
	char p27be[2];
	CSoundWrapper m_sndWalking[2]; //27c0h
	int u27f0;
	CSoundWrapper m_sndArmor[2]; //27f4h
	char m_bCurrentWalkingSoundIdx; //2824h
	char m_bCurrentArmorSoundIdx; //2825h
	char p2826[2];
	CSoundWrapper u2828; //uses walking sound channel
	CSoundWrapper m_sndMissile; //2840h
	CSoundWrapper m_sndCasting; //2858h
	CSoundWrapper u2870;
	CSoundWrapper u2888; //associated with overlays
	int m_nTimesTalkedTo; //28a0, for NumTimesTalkedTo() trigger
	int u28a4;
	ResRef m_areaSpecificScriptName; //28a8h
	int m_nTimesInteractedWith[24]; //28b0h, each element associated with NPC.IDS //copied from saved game unknown area under happiness
	short m_wHappiness; //2910h
	char p2912[2];
	Object m_oInteractee; //2914h, for InteractingWith() trigger
	ENUM u2928;
	BOOL m_bActive; //292ch, GetActive(), not outside 24-hour schedule
	BOOL m_bActiveAI; //2930h, GetActiveAI(), not diseased/deactivated
	BOOL m_bActiveImprisonment; //2934h, GetActiveImprisonment(), not mazed/imprisoned
	int m_nSelectionState; //2938, as per GAM NPC
	int u293c;
	char u2940;
	TerrainTable m_tt; //2941h
	TerrainTable m_tt2; //2951h
	TerrainTable m_tt3; //2961h
	char u2971;
	char p2972[2];
	AnimData m_animation; //2974h
	short* m_GoreParticleArray; //297ch, elements = (2c5c + 2c5d - 1) * m_nGoreParticleFrames
	long long* m_GoreParticleArray2; //2980h, elements as above
	char u2984;
	char m_nGoreParticleSequences; //2985h
	char u2986; //m_nNumGoreParticls?
	char m_nGoreParticleFrames; //2987h
	char u2988; //assoc gore
	char u2989; //assoc gore
	char p298a[2];
	CVidCell m_cvcGoreParticle; //298ch, e.g. flames/sparks
	VidPal m_vpGoreParticle; //2a50h
	int u2a74;
	CVidCell m_cvcGoreMain; //2a78h, e.g. blood
	VidPal m_vpGoreMain; //2b3ch
	int u2b60;
	RECT m_rGoreBounds; //2b64h
	CPoint m_ptGoreCentre; //2b74
	bool u2b7c; //assoc gore particle
	char u2b7d;
	char p2b7e[2];
	BOOL m_bIsAnimationMovable; //2b80h, 0 = static (ANIMATE.IDS values < 0x1000) or HELD, set to 1 on dying
	int u2b84;
	char u2b88; //3
	unsigned char m_nMirrorImages; //2b89h, immune to poison and display special effect icon?
	bool m_bBlur; //2b8ah
	bool m_bInvisible; //2b8bh, invisibility and improved invisibility
	bool m_bSanctuary; //2b8ch
	char u2b8d;
	char p2b8e[2];
	CVidCell m_vidSANCTRY; //2b90h
	bool m_bEntangle; //2c54h
	char p2c55[3];
	CVidCell m_vidSPEntaCl; //2c58h
	bool m_bInvGlobe; //2d1ch
	char p2d1d[3];
	CVidCell m_vidMinorGlb; //2d20h
	bool m_bSpellShield; //2de4h
	char p2de5[3];
	CVidCell m_vidSpShield; //2de8h
	bool m_bGrease; //2each
	char p2ead[3];
	CVidCell m_vidGreaseD; //2eb0h
	bool m_bWeb; //2f74h
	char p2f75[3];
	CVidCell m_vidWebEntD; //2f78h
	float u303c;
	float u3040;
	float u3044;
	float u3048; //1.875f
	short u304c; //range?
	char u304e; //mirror 33a4 through X axis
	char u304f;
	float u3050; //radians CCW to North
	int u3054;
	short m_wCurrentSequenceSimplified; //3058h, used in animation sound selection (see animation sound 2DA files for values)
	char p305a[2];
	int u305c;
	int u3060;
	CPoint u3064; //linked to coordinates
	CPoint m_ptDistanceToMove; //306ch, towards target at 0x33beh, set on refresh
	CPoint m_ptTargetToMove; //3074h, next pathfinding node?
	CPoint m_ptBlur1; //307ch, copied from 0x6 and 0xa
	CPoint m_ptBlur2; //3084h, copied from above
	CPoint u308c;
	int u3094;
	short u3098; //assoc with orientations
	short u309a; //assoc with orientations
	short m_wOrientGoal; //309ch, orientation to get to
	short m_wDirection; //309eh, instantaneous orientation
	int* u30a0; //has to do with pathfinding and search requests
	short u30a4;
	char p30a6[2];
	CDwordList u30a8;
	CDwordList u30c4;
	short u30e0;
	char p30e2[2];
	int u30e4;
	int u30e8;
	int u30ec; //0x8000
	int u30f0;
	int u30f4;
	CSearchRequest* m_currentSearchRequest; //30f8h
	short m_wDamagePortraitFlashTimer; //30fch, countdown by 5, this+78h also gives red intensity
	short m_wDamageArrowTimer; //30feh, countdown by 1
	ABGR m_rgbDamageArrow; //3100h, different colour every 5 ticks
	BOOL m_bShowDamageArrow; //3104h
	int u3108;
	CVidBitmap m_vidSmallPortrait; //310ch
	int u31c0;
	BOOL u31c4; //if set, will set search bitmap bits 1, 2, 3 in foot circle area, else 4, 5, 6
	char u31c8;
	char p31c9[3];
	CPoint u31cc;
	int u31d4;
	int u31d8;
	int u31dc;
	int u31e0;
	int u31e4; //assoc with action 0x30
	CParticleList m_particles; //31e8h
	short m_wCastingTimer; //3204h, how many ticks has creature been casting a spell, counts upwards (-1 is none)
	char p3206[2];
	BOOL m_bCastingAction; //3208h, assoc ForceSpell[Point], Spell, UseItem, UseItemPoint
	BOOL m_bCastingSpell; //320ch
	short u3210;
	short u3212; //assoc actions
	short m_wMoveToFrontDelay; //3214h, countdown to move to front vertical list on resurrect?
	short m_wMoveToMiddleDelay; //3216h, countdown to move to middle vertical list on death?
	BOOL m_bDead; //3218h, set by CEffectInstantDeath
	BOOL m_bResurrect; //321ch, set by CEffectResurrect
	CEffectList m_EffectsEquipped; //3220h, for while equipped effects
	CEffectList m_TimedEffectList; //324ch, for all other effects
	IECPtrList u3278; //AAA8FC, CPermRepeatingEffList
	CPtrArray u3294;
	CPoint u32a8; //assoc actions, target for pathfinding
	int u32b0;
	int u32b4; //assoc actions
	short u32b8; //confusion timer?
	short m_wTriggerRemovalTimer; //32bah, ticks until remove all 0x0 triggers
	int u32bc;
	int u32c0;
	BOOL m_bInterruptSpellcasting; //32c4h
	POSITION* m_posSelected; //32c8h, of CPartySelection list
	int u32cc;
	int u32d0;
	CProjectile* m_currentProjectile; //32d4h, once projectile placed in area list, set to NULL
	ResSplFile* m_currentSpell; //32d8h
	CItem* m_currentItem; //32dch, quick item currently being used
	short m_currentItemSlot; //32e0h, slot of m_currentItem
	short m_currentItemAbility; //32e2h, ability of m_currentItem
	short u32e4[0x28];
	char u3334[8];
	char m_AttackSpeed; //333ch, (weaponSpeed - physicalSpeed - 1D6 - luck) / 0.5 * dieSize, range 0-10, determines the y-coordinate of the pixel to select in RNDBASE*.BMP
	char u333d;
	short m_wPreviousTickActionOpcode; //333e, action opcode in the last tick, sometimes set to 3 Attack or 22 MoveToObject, never checked
	Object m_oDerived; //3340h, keeps General, scriptName is of thisCre
	Object m_oBase; //3354h, base for o and oDerived, used for gender for sounds, scriptName is of thisCre
	int u3368;
	short u336c;
	char p336e[2];
	int u3370;
	short u3374;
	short u3376;
	short u3378; //incremental timer, assoc actions, and luck, and when a new pathfinding search request gets sent
	int u337a; //assoc actions, ? has search request?
	short u337e;
	short u3380[2];
	short m_wRoundTimer; //3384h, range 0-100, determines the x-coordinate of the pixel to select in RNDBASE*.BMP
	char p3386[2];
	int u3388; //assoc actions (idle time?), ++ with NoAction()
	int u338c;
	BOOL m_bForceRefresh; //3390h, Refresh() despite nTimeFree % 15 == e % 15
	bool m_bStatisticalAttack; //3394h, i.e. rolling die to hit, applying damage/effects, depleting charges, etc.
	char u3395;
	BOOL m_bUsingLeftWeapon; //3396h
	short m_wDoHalfAttack; //339ah, replaced by TobEx, originally m_wHalveToHitRolls that was not really used, really a BOOL
	BOOL m_bForceReinitAnimColors; //339ch, DeInitAllColors() then sends CMessageResetAnimColors during Refresh() 
	BOOL m_bForceResetAnimColors; //33a0h, resets animation colours directly during Refresh() (e.g. Set Item Color opcode, petrify colouring)
	BOOL m_bForceMsgResetAnimColors; //33a4h, sends CMessageResetAnimColors during Refresh() (e.g. Polymorph, Animation Change opcodes)
	BOOL m_bRemoveFromArea; //33a8h
	BOOL m_bForceResetAnimation; //33ach
	CSelectionCircle m_cscSelf; //33b0h
	CSelectionCircle m_cscTarget; //33dch
	ENUM m_eTarget; //3408h, the target of actions?
	CPoint m_ptTarget; //340ch, set by ProtectPoint(), MoveToPoint(), Leader(), cscTarget places here
	short u3414;
	char m_nQuickSlotSelected; //3416h, copied from af6h
	char m_nQuickAbilitySelected; //3417h, copied from af8h
	CQuickSlot m_qsSpellCurrent; //u3418h
	ResRef m_rDialog; //344ch, main dialog
	ResRef m_rDialogInteract; //3454h, interact dialog
	bool u345c;
	char p345d[3];
	CStrRef* m_soundsetArray; //3460h, size 0xAF4
	char m_cRandSaveDeath; //3464h, 1D20
	char m_cRandSaveWand; //3465h, 1D20
	char m_cRandSavePolymorph; //3466h, 1D20
	char m_cRandSaveBreath; //3467h, 1D20
	char m_cRandSaveSpell; //3468h, 1D20
	char m_cRandResistMagic; //3469h, 1D100
	char m_cRandEffProb; //346ah, 1D100, test against effect prob1 and prob2
	char m_cRandWildMagicLevel; //346bh, 1D20, column of LVLMODWM.2DA
	char m_cRandWildMagicProb; //346ch, 1D20, if 0, do wild magic
	char p346d[3];
	int u3470[2];
	int m_nLargestCurrentHP; //3478h, set to largest current HP value obtained
	BOOL m_bMoraleFailure; //347ch, contains char data
	BOOL m_bIsAttacking; //3480h, in the middle of attack phase of a round
	short u3484; //assoc actions
	char p3486[2];
	int u3488;
	int m_nFaceTalkerTimer; //348ch, countdown timer
	ENUM m_eTalker; //3490h, orients cre to person who is about to talk to them
	int m_nSoundLength; //3494h, in sec
	char u3498;
	char p3499[3];
	CDwordList m_PortraitIcons; //349ch
	CVidCell u34b8;
	int u357c;
	int m_nTicksLastRested; //3580h, base time to calculate fatigue = (nGameTime - 63ach) / (4 hours in ticks) - FATIGUE_BONUS
	BOOL m_bBerserkActive; //3584h, updated every AIUpdateActions(), no actual berserk action unless STATE_BERSERK
	short u3588;
	char p358a[2];
	int m_nHPBonusPrev; //358ch, on previous Refresh()
	BOOL m_bConstructing; //3590h, TRUE only when object is still being constructed
	int m_nWeight; //3594h, compared to total item weight
	int u3598;
	int u359c;
	int m_nTicksLastRefresh; //35a0h, gets nGameTime during refresh
	BOOL m_bLevelUpAvailable; //35a4h
	char m_bAllowDialogInterrupt; //35a8h
	char u35a9;
	char p35aa[2];
	int m_nUnselectableVariable; //35ach
	ResRef m_rVoiceset; //35b0h, from CRE entry in GAM file
	int u35b8; //m_bStoneSkin?
	int u35bc;
	int u35c0;
	int u35c4;
	int u35c8;
	int u35cc;
	BOOL m_bSendOverlayMessages; //35d0h, associated with sending CMessageCreatureOverlay messages
	short u35d4; //contains an actionOpcode (a dialog or escape area action?)
	char p35d6[2];
	int u35d8; //assoc actions
	int u35dc; //assoc actions
	int m_nHighEncumberanceMessageDelay; //35e0h, decrementing timer to show Encumbered: Can Not Move
	int m_nLowEncumbranceMessageDelay; //35e4h, decrementing timer to show Encumbered: Slowed
	short m_wPoisonTimer; //35e8h, set to 100 on poison damage
	short m_wDelayedRefreshCounter; //35eah, if using previous state, Refresh() will delay and increment this counter, next Refresh() will Refresh() the counter number of times (max 5)
	BOOL m_bUseCurrentState; //35ech, 0 = uses prevState, 1 = uses currentState, set to 0 when refreshing repeating effects
	short u35f0;
	char p35f2[2];
	int u35f4;
	int u35f8;
	CVariableMap* m_pLocalVariables; //35fch
	int m_bUnmarshalling; //3600h, 1 during Unmarshal, 0 when done
	CProtectedSplList m_ProtectedSpls; //3604h, of CProtectedSpl objects
	ENUM m_eEntrancePoint; //3620h, which entrance point to use when moving between areas
	int m_nBounceDelay; //3624h, counts down from 25 frames
	int m_nMoraleAI; //3628h
	ENUM m_eVisualEffect; //362ch, contains enum of CVisualEffect
	int u3630;
	CQuickObjectList* m_pSelectSpellSpells; //3634h
	CScript* m_pDreamScript; //3638h
	CGameDialog m_dlgCurrent; //363ch
	CGameDialog m_dlgCurrent2; //36a0h
	short u3704;
	char p3706[2];
	int u3708;
	int m_nContingencyDelay; //370ch, a countdown timer set to 100, delay processing contingency triggers until 0
	IECString m_sWeaponLeftToHitBonuses; //3710h
	IECString m_sWeaponRightToHitBonuses; //3714h
	IECString m_sWeaponLeftDamageBonuses; //3718h
	IECString m_sWeaponRightDamageBonuses; //371ch
	short m_wMvtRatePrev; //3720h, on last Refresh()
	char p3722[2];
	int m_nStateFlagsPrev; //3724h, on last Refresh()
	CreFileMemorizedSpellLevel m_MemInfoWizPrev[9]; //3728h, on last Refresh()
	CreFileMemorizedSpellLevel m_MemInfoPrsPrev[7]; //37b8h, on last Refresh()
	BOOL m_bSavedStateOnce; //3828h, set to TRUE when the above is saved for the first time during Refresh()
	bool m_bLevellingUp; //382ch, true when loading LevelUpPanel
	char p382d[3];
	int u3830;
	CEnumList u3834;
	IECPtrList u3850;
	BOOL m_bInStore; //386ch, prevents party required area transitions
	BOOL m_bInDialogue; //3870h
	int m_nDialoguePosition; //3874h, -1 = none, 1 = listener, 2 = speaker
	int u3878; //assoc actions
	BOOL m_bLeavingArea; //387ch
	ENUM m_ePuppet; //3880h
	BOOL m_bAffectedByTimeStop; //3884h, temporary use during Refresh() to set bForceRefresh
	int u3888;
	int u388c;
	CFeedbackList m_lFeedbacks; //3890h
	BOOL u38ac; //set when search bitmap has set 3 bits
	BOOL u38b0; //set when search bitmap has set 2 bits
	
	struct unk1 { //Size 58h
		void* u0;
		short u4;
		short u6;
		CPoint u8;
		char u10;
		char p11;
		short u12;
		CPoint u14; //current position?
		short u1c;
		char p1e[2];
		int u20;
		short u24[8];
		void* u34;
		char u38[5];
		char p3d[3];
		IECString u40; //current area name?
		char u44;
		char p45[3];
		int u48;
		char u4c[4];
		short u50;
		char p52[2];
		int u54;
	} u38b4;

	int u390c;
	int m_nLastDamageTaken; //3910h
	int u3914; //timer
	int u3918;
	char m_SightRadius; //391ch, default = 14 (AACF46), one unit = 32 pixels
	char p391d[3];
	BOOL u3920; //play animSound battle cry?, set to 0 after use
	BOOL u3924; //play animSound selection?, set to 0 after use
	char u3928[9];
	char p3931[3];
	int m_nAbandonActionTimer; //3934h, used by AttackReeavluate, TryAttack, MoveToObject; when hits 150, ACTION_FAILED is returned
	BOOL m_bReequipItem; //3938h
	BOOL m_bEquippingItem; //393ch
	char u3940; //default = 2a; if CRE name does not start with *, will put first character in here; inherits value from GAM (unknown above killXP(chapter), inherits from Actor2E (char)
	char u3941;
	char p3942[2];
	int u3944; //m_nColorsPrev1, compared to cdsCurrent.ColorListRgb count
	int u3948; //m_nColorsPrev2, compared to cdsCurrent.ColorListRgb count
	int u394c; //m_nWeaponProtectionsPrev
	int u3950;
	BOOL m_bInitTOB; //3954h, initialises innates, once per construction
	BOOL u3958; //to do with grabbed item
	int m_nSpriteUpdateTimer; //395ch, increments up to 15, then set to 0 on before CMessageSpriteUpdate
	int u3960; //assoc sprite update timer, 0 = always sprite update when ready, other = sprite update, reset to 0 if timer > 2
	int u3964;
};

#endif //OBJCRE_H
