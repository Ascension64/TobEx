#ifndef OBJCRE_H
#define OBJCRE_H

#include "stdafx.h"
#include "datatypes.h"
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

//Event message ids
#define EVENTMESSAGE_BACKSTAB_SUCCESS			0x01
#define EVENTMESSAGE_BACKSTAB_WEAPON_UNSUITABLE	0x1C
#define EVENTMESSAGE_PICKPOCKET_DISABLED_ARMOR	0x1E
#define EVENTMESSAGE_PICKPOCKET_FAILED_HOSTILE	0x1F
#define EVENTMESSAGE_PICKPOCKET_FAILED			0x20
#define EVENTMESSAGE_PICKPOCKET_NO_ITEMS		0x21
#define EVENTMESSAGE_PICKPOCKET_INV_FULL		0x22
#define EVENTMESSAGE_PICKPOCKET_SUCCESS			0x23
#define EVENTMESSAGE_BACKSTAB_FAIL				0x40
#define EVENTMESSAGE_SPELLFAILED_INVISIBLE		0x42

struct CQuickObject { //Size 30h
//Constructor: see 0x532F23
	ResRef rUsageIcon; //0h
	STRREF strrefName; //8h
	ResRef uc;
	STRREF strrefLauncherName; //14h
	short wAmount; //18h
	struct ObjectInfo { //Size 14h
		short wType; //0h, 1 = SPL, 2 = ITM, 3 = cast spell from list
		short wItemSlotIdx; //2h
		short wItemAbilityIdx; //4h
		ResRef rSpellName; //6h
		char nTargetType; //eh
		char nTargets; //fh
		STRREF strrefAbilityTooltip; //10h
	} m_ObjectInfo; //1ah
	bool bDisableButton; //2eh
	bool bConstructed; //2fh
};

class CQuickObjectList : public IECPtrList { //Size 20h
//Constructor: 0x55ECC0
public:
	//AA99DC
	int nIndexMageStart; //1ch, index at which wizard spells start (since order is priest, mage, innate)
};

struct CQuickSlot { //Size 30h
//Constructor: 0x549D30
	ResRef name; //0h
	int u8; //-1
	ResRef uc; //second name?
	int u14;
	short u18;
	//struct copy constructor at 568340
		short u1a;
		short nSlotIdx; //1ch
		short nAbilityIdx; //1eh
		ResRef rSpellName; //20h
		char u28;
		char u29;
		int u2a; //-1
	//end struct
	char u2e;
	char u2f;
};

struct CFavorite { //Size Eh
//Constructor: 0x579E70
	unsigned int* vtable; //0h
	ResRef name; //4h
	short nTimesUsed; //ch
};

struct CProtectedSpl { //Size 1Ch
	int nLevel; //0h, spl level subtracted from amount of immunity/bounces left
	int nOpcode; //4h, opcode of the protection effect
	CProjectile* pProj; //8h
	BOOL bNoProjectile; //ch, do not make a bounce projectile
	STRREF strref; //10h
	BOOL bStrRefOnly; //14h, ignores everything except printing a string to console
	BOOL bSpellTrap; //18h, applies Restore Lost Spells eff on nPower
};

class CProtectedSplList : public IECPtrList {
public:
	void AddTail(CEffect& effect, int nPower, int nOpcode, CCreatureObject& cre, BOOL bCreateProj, STRREF strref, BOOL bDoNotUpdateEff, BOOL bRestoreLostSpls);
	void Update(CCreatureObject& cre);
};

extern void (CProtectedSplList::*CProtectedSplList_AddTail)(CEffect&, int, int, CCreatureObject&, BOOL, STRREF, BOOL, BOOL);
extern void (CProtectedSplList::*CProtectedSplList_Update)(CCreatureObject&);

class CCreatureObject : public CGameSprite { //Size 6774h
//Constructor: 0x87FB08
public:
	CGameObject& SetTarget(Object& o, char type);
	void GetSpellIdsName(int nSpellIdx, IECString* ptr);
	CDerivedStats& GetDerivedStats();
	ACTIONRESULT CastSpell(ResRef& rResource, CGameObject& cgoTarget, BOOL bPrintStrref, STRREF strref, void* pMod, BOOL bPrintEventMsg, BOOL bDoNotApplySplAbil);
	static void RemoveItem(CCreatureObject& cre, int nSlot);
	CEffectList& GetEquippedEffectsList();
	CEffectList& GetMainEffectsList();

	CCreatureObject(void* pFile, unsigned int dwSize, BOOL bHasSpawned, int nTicksTillRemove, int nMaxMvtDistance, int nMaxMvtDistanceToObject, unsigned int nSchedule, int nDestX, int nDestY, int nFacing);
	CCreatureObject& Construct(void* pFile, unsigned int dwSize, BOOL bHasSpawned, int nTicksTillRemove, int nMaxMvtDistance, int nMaxMvtDistanceToObject, unsigned int nSchedule, int nDestX, int nDestY, int nFacing) { return *this; } //dummy

	void CreateGore(int dwUnused, short wOrient, short wType);
	void UpdateHPStatusTooltip(CUIControl& control);
	short GetOrientationTo(POINT& pt);
	static short CalculateOrientation(POINT& pt1, POINT& pt2);
	void SetAnimationSequence(short wSeq);
	void StartSpriteEffect(char nEffectType, char nParticleType, int nParticles);
	CItem& GetFirstEquippedLauncherOfAbility(ItmFileAbility& ability, int* pnSlot);
	int GetSlotOfEquippedLauncherOfAmmo(short wAmmoSlot, short wAbilityIdx);
	void UnequipAll(BOOL bKeepEffects);
	void EquipAll(BOOL bDoNotApplyEffects);
	void AddKnownSpell(ResRef& name, BOOL bPrintEventMessage);
	CreFileKnownSpell& GetKnownSpellPriest(int nLevel, int nIndex);
	CreFileKnownSpell& GetKnownSpellMage(int nLevel, int nIndex);
	CreFileKnownSpell& GetKnownSpellInnate(int nLevel, int nIndex);
	CreFileMemSpell& GetMemSpellPriest(int nLevel, int nIndex);
	CreFileMemSpell& GetMemSpellMage(int nLevel, int nIndex);
	CreFileMemSpell& GetMemSpellInnate(int nLevel, int nIndex);
	BOOL AddMemSpellPriest(int nLevel, int nIndex, int* pIndex);
	BOOL AddMemSpellMage(int nLevel, int nIndex, int* pIndex);
	BOOL AddMemSpellInnate(int nLevel, int nIndex, int* pIndex);
	BOOL AddKnownSpellPriest(ResRef& name, int nLevel);
	BOOL AddKnownSpellMage(ResRef& name, int nLevel);
	BOOL AddKnownSpellInnate(ResRef& name, int nLevel);
	IECString& GetLongName();
	STRREF GetLongNameStrRef();
	void SetSpellMemorizedState(ResSplContainer& resSpell, BOOL bState);
	void ValidateAttackSequence(char* pSeq);
	char GetNumUniqueMemSpellMage(int nLevel, ResRef rTemp);
	BOOL InDialogAction();
	unsigned int GetKitUnusableFlag();
	void PrintEventMessage(short wEventId, int nParam1, int nParam2, int nParam3, STRREF strrefParam4, BOOL bParam5, IECString& sParam6);
	ACTIONRESULT ActionMoveToObject(CGameObject& cgoTarget);
	ACTIONRESULT ActionPickPockets(CCreatureObject& creTarget);
	short GetSpellCastingLevel(ResSplContainer& resSpell, BOOL bUseWildMagicMod);
	void UpdateFaceTalkerTimer();

	//AA98A8
	virtual ~CCreatureObject() {} //v0
	virtual bool NeedsAIUpdate(bool bRun, int nChitinUpdates); //v4c
	virtual BOOL EvaluateTrigger(Trigger& t); //v60
	virtual ACTIONRESULT ExecuteAction(); //v7c
	virtual void SetCurrentAction(Action& a); //v88, calls vb0

	virtual void SetAutoPauseInfo(int nType) {} //va8
	virtual BOOL CanSeeInvisible() { return FALSE; } //vac
	
	//vb8, void CCreatureObject::SetObjects(o, bSetDerived, bSetBase)
	//vc0, void RefreshObjects(), 1c = 3698 (identical), 3684 = 3698 (except general)
	//vc4, void ProcessScriptsOnce(BOOL bOverrideOnly)
	//...
	//etc. to v114

	short u3d4;
	short u3d6;
	ResRef rSaveName; //3d8h, CRE name with * prefix
	short bHasSpawned; //3e0h
	int nTicksTillRemove; //3e2h, Arg4
	short nMaxMvtDistance; //3e6h, Arg5, Actor3C
	short nMaxMvtDistanceToObject; //3e8h, Arg6, Actor3E
	int destX; //3eah
	int destY; //3eeh
	int timesOfDay; //3f2h, creature schedule
	CreFileData m_BaseStats; //3f6h
	CKnownSpellList m_KnownSpellsPriest[7]; //65eh
	CKnownSpellList m_KnownSpellsWizard[9]; //722h
	CKnownSpellList m_KnownSpellsInnate; //81eh
	CreFileMemSpellLevel* m_MemInfoPriest[7]; //83ah
	CreFileMemSpellLevel* m_MemInfoWizard[9]; //856h
	CreFileMemSpellLevel* m_MemInfoInnate; //87ah
	CMemSpellList m_MemSpellsPriest[7]; //87eh
	CMemSpellList m_MemSpellsWizard[9]; //942h
	CMemSpellList m_MemSpellsInnate; //a3eh

	CCreInventory m_Inventory; //a5ah
	/*CItem* m_pItemAmulet; //a5ah
	CItem* m_pItemArmor; //a5eh
	CItem* m_pItemBelt; //a62h
	CItem* m_pItemBoots; //a66h
	CItem* m_pItemCloak; //a6ah
	CItem* m_pItemGauntlets; //a6eh
	CItem* m_pItemHelmet; //a72h
	CItem* m_pItemRingLeft; //a76h
	CItem* m_pItemRingRight; //a7ah
	CItem* m_pItemShield; //a7eh
	CItem* m_pItemFist; //a82h
	CItem* m_pItemAmmo0; //a86h
	CItem* m_pItemAmmo1; //a8ah
	CItem* m_pItemAmmo2; //a8eh
	CItem* m_pItemAmmo3; //a92h
	CItem* m_pItemMisc0; //a96h
	CItem* m_pItemMisc1; //a9ah
	CItem* m_pItemMisc2; //a9eh
	CItem* m_pItemMisc3; //aa2h
	CItem* m_pItemMisc4; //aa6h
	CItem* m_pItemMisc5; //aaah
	CItem* m_pItemMisc6; //aaeh
	CItem* m_pItemMisc7; //ab2h
	CItem* m_pItemMisc8; //ab6h
	CItem* m_pItemMisc9; //abah
	CItem* m_pItemMisc10; //abeh
	CItem* m_pItemMisc11; //ac2h
	CItem* m_pItemMisc12; //ac6h
	CItem* m_pItemMisc13; //acah
	CItem* m_pItemMisc14; //aceh
	CItem* m_pItemMisc15; //ad2h
	CItem* m_pItemMisc16; //ad6h
	CItem* m_pItemMisc17; //adah
	CItem* m_pItemMisc18; //adeh
	CItem* m_pItemMisc19; //ae2h, magical weapon slot
	CItem* m_pItemWeapon0; //ae6h
	CItem* m_pItemWeapon1; //aeah
	CItem* m_pItemWeapon2; //aeeh
	CItem* m_pItemWeapon3; //af2h
	char nSlotSelected; //af6h
	short nAbilitySelected; //af8h*/

	CGameObject* pThis; //afeh
	int ub02;
	int ub06;
	CDerivedStats cdsCurrent; //b0ah
	CDerivedStats cdsPrevious; //13c2h, previous state to restore after effect finishes
	CDerivedStats cdsDiff; //1c7ah, difference to add to currentState
	int u2532;
	CQuickSlot m_qsWeapons[4]; //2536h
	CQuickSlot m_qsSpells[3]; //25f6h
	CQuickSlot m_qsItems[3]; //2686h
	IECString sLongName; //2716h
	char u271a;
	char u271b; //padding?
	struct CStatistics {
		STRREF mostPowerfulFoe; //0h
		int mostPowerfulXP; //4h
		int inPartyTime; //8h
		int joinedTime; //ch
		BOOL inParty; //10h
		int chapterKillXP; //14h
		int chapterNumKills; //18h
		int gameKillXP; //1ch
		int gameNumKills; //20h
		CFavorite favSpell[4]; //24h
		CFavorite favWeapon[4]; //5ch
	} statistics; //271ch
	ResRef currentArea;
	char m_bGlobal; //27b8h, is this Cre Global
	char m_nModalState; //27b9h, 0: None, 1: Battle Song, 2: Detecting Traps, 3: Hide in Shadows, 4: Turn Undead
	CSound m_sndWalking[2]; //27bah
	int u288e;
	CSound m_sndArmor[2]; //2892h
	char bCurrentWalkingSoundIdx; //2966h
	char bCurrentArmorSoundIdx; //2967h
	CSound u2968; //uses walking sound channel
	CSound m_sndMissile; //29d2h
	CSound m_sndCasting; //2a3ch
	CSound u2aa6;
	CSound u2b10; //associated with overlays
	int nTimesTalkedTo; //2b7ah, for NumTimesTalkedTo() trigger
	int u2b7e;
	ResRef areaSpecificScriptName; //2b82h
	int nTimesInteractedWith[24]; //2b8ah, each element associated with NPC.IDS //copied from saved game unknown area under happiness
	short wHappiness; //2beah
	Object oInteractee; //2bech, for InteractingWith() trigger
	Enum u2c00;
	BOOL bScheduled; //2c04h, not outside 24-hour schedule
	BOOL bActive; //2c08h, not diseased/deactivated
	BOOL bFree; //2c0ch, not mazed/imprisoned
	int nSelectionState; //2c10h, as per GAM NPC
	int u2c14;
	char u2c18;
	TerrainTable tt; //2c19h
	TerrainTable tt2; //2c29h
	TerrainTable tt3; //2c39h
	char u2c49;
	AnimData m_animation; //2c4ah
	short* m_GoreParticleArray; //2c50h, elements = (2c5c + 2c5d - 1) * m_nGoreParticleFrames
	long long* m_GoreParticleArray2; //2c54h, elements as above
	char u2c58;
	char m_nGoreParticleSequences; //2c59h
	char u2c5a; //m_nNumGoreParticls?
	char m_nGoreParticleFrames; //2c5bh
	char u2c5c; //assoc gore
	char u2c5d; //assoc gore
	CVidCell m_cvcGoreParticle; //2c5eh, e.g. flames/sparks
	VidPal m_vpGoreParticle; //2d34h
	int u2d58;
	CVidCell m_cvcGoreMain; //2d5ch, e.g. blood
	VidPal m_vpGoreMain; //2e32h
	int u2e56;
	RECT rGoreBounds; //2e5ah
	POINT ptGoreCentre; //2e6a
	bool u2e72; //assoc gore particle
	char u2e73;
	BOOL m_bIsAnimationMovable; //2e74h, 0 = static (ANIMATE.IDS values < 0x1000) or HELD, set to 1 on dying
	int u2e78;
	char u2e7c; //3
	unsigned char m_nMirrorImages; //2e7dh, immune to poison and display special effect icon?
	bool m_bBlur; //2e7eh
	bool m_bInvisible; //2e7fh, invisibility and improved invisibility
	bool m_bSanctuary;
	char u2e81;
	CVidCell SANCTRY; //2e82h
	bool m_bEntangle; //2f58h
	char u2f59; //padding
	CVidCell SPEntaCl;
	bool m_bInvGlobe;
	char u3031; //padding
	CVidCell MinorGlb;
	bool m_bSpellShield;
	char u3109; //padding
	CVidCell SpShield;
	bool m_bGrease;
	char u31e1; //padding
	CVidCell GreaseD;
	bool m_bWeb;
	char u32b9; //padding
	CVidCell WebEntD;

	float u3390;
	float u3394;
	float u3398;
	float u339c; //1.875f
	short u33a0; //range?
	char u33a2; //mirror 33a4 through X axis
	char u33a3;
	float u33a4; //radians CCW to North
	int u33a8;
	short wCurrentSequenceSimplified; //33ach, used in animation sound selection (see animation sound 2DA files for values)
	POINT u33ae; //linked to coordinates
	POINT ptDistanceToMove; //33b6h, towards target at 0x33beh, set on refresh
	POINT ptTargetToMove; //33beh, next pathfinding node?
	POINT ptBlur1; //33c6h, copied from 0x6 and 0xa
	POINT ptBlur2; //33ceh, copied from above
	int u33d6;
	int u33da;
	int u33de;
	short u33e2; //assoc with orientations
	short u33e4; //assoc with orientations
	short wOrientGoal; //33e6h, orientation to get to
	short wOrientInstant; //33e8h, instantaneous orientation
	int* u33ea; //has to do with pathfinding and search requests
	short u33ee;
	CDwordList u33f0;
	CDwordList u340c;
	short u3428;
	int u342a;
	int u342e;
	int u3432; //0x8000
	int u3436;
	int u343a;
	CSearchRequest* m_currentSearchRequest; //343eh
	short m_wDamagePortraitFlashTimer; //3442h, countdown by 5, this+78h also gives red intensity
	short m_wDamageArrowTimer; //3444h, countdown by 1
	ABGR m_rgbDamageArrow; //3446h, different colour every 5 ticks
	BOOL m_bShowDamageArrow; //344ah
	int u344e;
	CVidBitmap smallPortrait; //3452h
	int u3508;
	BOOL u350c; //if set, will set search bitmap bits 1, 2, 3 in foot circle area, else 4, 5, 6
	char u3510;
	char u3511; //padding?
	POINT u3512;
	int u351a;
	int u351e;
	int u3522;
	int u3526;
	int u352a; //assoc with action 0x30
	CParticleList m_particles; //352eh
	short m_wCastingTimer; //354ah, how many ticks has creature been casting a spell, counts upwards (-1 is none)
	BOOL m_bCastingAction; //354ch, assoc ForceSpell[Point], Spell, UseItem, UseItemPoint
	BOOL m_bCastingSpell; //3550h
	short u3554;
	short u3556; //assoc actions
	short m_wMoveToFrontDelay; //3558h, countdown to move to front vertical list on resurrect?
	short m_wMoveToMiddleDelay; //355ah, countdown to move to middle vertical list on death?
	BOOL m_bDead; //355ch, set by CEffectInstandDeath
	BOOL m_bResurrect; //3560h, set by CEffectResurrect
	CEffectList m_EffectsEquipped; //3564h, for while equipped effects
	CEffectList m_EffectsMain; //3590h, for all other effects
	IECPtrList u35bc; //AAA8FC, CPermRepeatingEffList
	CPtrArray u35d8;
	POINT u35ec; //assoc actions, target for pathfinding
	int u35f4;
	int u35f8; //assoc actions
	short u35fc; //confusion timer?
	short m_wTriggerRemovalTimer; //35feh, ticks until remove all 0x0 triggers
	int u3600;
	int u3604;
	BOOL m_bInterruptSpellcasting; //3608h
	POSITION* posSelected; //360ch, of CPartySelection list
	int u3610;
	int u3614;
	CProjectile* m_currentProjectile; //3618h, once projectile placed in area list, set to NULL
	ResSplContainer* m_currentSpell; //361ch
	CItem* m_currentItem; //3620h, quick item currently being used
	short m_currentItemSlot; //3624h, slot of m_currentItem
	short m_currentItemAbility; //3626h, ability of m_currentItem
	short u3628[0x28];
	char u3678[8];
	char m_AttackSpeed; //3680h, (weaponSpeed - physicalSpeed - 1D6 - luck) / 0.5 * dieSize, range 0-10, determines the y-coordinate of the pixel to select in RNDBASE*.BMP
	char u3681;
	short m_wPreviousTickActionOpcode; //3682h, action opcode in the last tick, sometimes set to 3 Attack or 22 MoveToObject, never checked
	Object oDerived; //3684h, keeps General, scriptName is of thisCre
	Object oBase; //3698h, base for o and oDerived, used for gender for sounds, scriptName is of thisCre
	int u36ac;
	short u36b0;
	int u36b2;
	short u36b6;
	short u36b8;
	short u36ba; //incremental timer, assoc actions, and luck, and when a new pathfinding search request gets sent
	int u36bc; //assoc actions, ? has search request?
	short u36c0;
	short u36c2[2];
	short wRoundTimer; //36c6h, range 0-100, determines the x-coordinate of the pixel to select in RNDBASE*.BMP
	int u36c8; //assoc actions (idle time?), ++ with NoAction()
	int u36cc;
	BOOL m_bForceRefresh; //36d0h, Refresh() despite nTimeFree % 15 == e % 15
	char u36d4; //assoc actions
	char u36d5;
	BOOL m_bUsingLeftWeapon; //36d6h, assoc actions
	short u36da;
	BOOL m_bResetAnimationColors; //36dch
	BOOL m_bForceSetAnimColors; //36e0h, set to 1 when Set Item Color effect used or when applying petrify colouring but only if animation uses color ranges
	BOOL u36e4; //assoc with items
	BOOL m_bRemoveFromArea; //36e8h
	BOOL m_bForceResetAnimation; //36ech
	CSelectionCircle cscSelf; //36f0h
	CSelectionCircle cscTarget; //3714h
	Enum eTarget; //3738h, the target of actions?
	POINT ptTarget; //373ch, set by ProtectPoint(), MoveToPoint(), Leader(), cscTarget places here
	short u3744;
	char nQuickSlotSelected; //3746h, copied from af6h
	char nQuickAbilitySelected; //3747h, copied from af8h
	CQuickSlot m_qsSpellCurrent; //u3748h
	ResRef rDialog; //3778h
	ResRef rDialog2; //3780h
	bool u3788;
	char u3789; //padding?
	CStrRef soundset[100]; //378ah
	char rndEffSaveDeath; //6282h, 1D20
	char rndEffSaveWand; //6283h, 1D20
	char rndEffSavePolymorph; //6284h, 1D20
	char rndEffSaveBreath; //6285h, 1D20
	char rndEffSaveSpell; //6286h, 1D20
	char rndEffResistMagic; //6287h, 1D100
	char rndDoEff; //6288h, 1D100, test against effect prob1 and prob2
	char rndWildMagicLevel; //6289h, 1D20, column of LVLMODWM.2DA
	char rndDoWildMagic; //628Ah, 1D20, if 0, do wild magic
	char u628b; //padding?
	long u628c[2];
	int m_nLargestCurrentHP; //6294h, set to largest current HP value obtained
	BOOL m_bMoraleBroken; //6298h, contains char data
	BOOL m_bInAttack; //629ch, in the middle of attack phase of a round
	short u62a0; //assoc actions
	int u62a2;
	int m_nFaceTalkerTimer; //62a6h, countdown timer
	Enum m_eTalker; //62aah, orients cre to person who is about to talk to them
	int nSoundLength; //62aeh, in sec
	char u62b2[3];
	char u62b5; //padding?
	CDwordList m_PortraitIcons; //62b6h
	CVidCell u62d2;
	int u63a8;
	int nTicksLastRested; //63ach, base time to calculate fatigue = (nGameTime - 63ach) / (4 hours in ticks) - FATIGUE_BONUS
	int m_bAllowBerserkStage2; //63b0h, updated every AIUpdateActions(), no actual berserk action unless STATE_BERSERK
	short u63b4;
	int m_nHPBonusPrev; //63b6h, on previous Refresh()
	BOOL m_bConstructing; //63bah, TRUE only when object is still being constructed
	int m_nWeight; //63beh, compared to total item weight
	int u63c2;
	int u63c6;
	int m_nTicksLastRefresh; //63cah, gets nGameTime during refresh
	BOOL m_bLevelUpAvailable; //63ceh
	char u63d2[2];
	int nUnselectableVariable; //63d4h
	ResRef voiceset; //63d8h, from CRE entry in GAM file
	int u63e0; //m_bStoneSkin?
	int u63e4;
	int u63e8;
	int u63ec;
	int u63f0;
	int u63f4;
	BOOL m_bSendOverlayMessages; //63f8h, associated with sending CMessageCreatureOverlay messages
	short u63fc; //contains an actionOpcode (a dialog or escape area action?)
	int u63fe; //assoc actions
	int u6402; //assoc actions
	int m_nHighEncumberanceMessageDelay; //6406h, decrementing timer to show Encumbered: Can Not Move
	int m_nLowEncumbranceMessageDelay; //640ah, decrementing timer to show Encumbered: Slowed
	short m_wPoisonTimer; //640eh, set to 100 on poison damage
	short m_wDelayedRefreshCounter; //6410h, if using previous state, Refresh() will delay and increment this counter, next Refresh() will Refresh() the counter number of times (max 5)
	BOOL bUseCurrentState; //6412h, 0 = uses prevState, 1 = uses currentState, set to 0 when refreshing repeating effects
	short u6416;
	int u6418;
	int u641c;
	CVariableArray* m_pLocalVariables; //6420h
	int m_bUnmarshalling; //6424h, 1 during Unmarshal, 0 when done
	CProtectedSplList m_ProtectedSpls; //6428h, of CProtectedSpl objects
	int u6444;
	int m_nBounceDelay; //6448h, counts down from 25 frames
	int m_nMoraleAI; //644ch
	Enum eVisualEffect; //6450h, contains enum of CVisualEffect
	int u6454;
	CQuickObjectList* pSelectSpellSpells; //6458h
	CScript* pDreamScript; //645ch
	CGameDialog dlgCurrent; //6460h
	CGameDialog dlgCurrent2; //64c4h
	short u6528;
	int u652a;
	int m_nContingencyDelay; //652eh, a countdown timer set to 100, delay processing contingency triggers until 0
	IECString m_sWeaponLeftToHitBonuses; //6532h
	IECString m_sWeaponRightToHitBonuses; //6536h
	IECString m_sWeaponLeftDamageBonuses; //653ah
	IECString m_sWeaponRightDamageBonuses; //653eh

	short m_wMvtRatePrev; //6542h, on last Refresh()
	int m_nStateFlagsPrev; //6544h, on last Refresh()
	CreFileMemSpellLevel m_MemInfoWizPrev[9]; //0x6548, on last Refresh()
	CreFileMemSpellLevel m_MemInfoPrsPrev[7]; //0x65d8, on last Refresh()
	BOOL m_bSavedStateOnce; //6648h, set to TRUE when the above is saved for the first time during Refresh()

	bool m_bLevellingUp; //664ch, true when loading LevelUpPanel
	char u664d; //padding?
	int u664e;
	CEnumList u6652;
	IECPtrList u666e;
	BOOL m_bInStore; //668ah, prevents party required area transitions
	BOOL m_bInDialogue; //668eh
	int m_nDialoguePosition; //6692h, -1 = none, 1 = listener, 2 = speaker
	int u6696; //assoc actions
	BOOL m_bLeavingArea; //669ah
	Enum ePuppet; //669eh
	BOOL m_bAffectedByTimeStop; //66a2h, temporary use during Refresh() to set bForceRefresh
	int u66a6;
	int u66aa;
	CEventMessageList m_EventMessages; //66aeh
	BOOL u66ca; //set when search bitmap has set 3 bits
	BOOL u66ce; //set when search bitmap has set 2 bits
	_8DF1F2 u66d2;
	int u6722;
	int nLastDamageTaken; //6726h
	int u672a; //timer
	int u672e;
	char m_SightRadius; //6732h, default = 14 (AACF46), one unit = 32 pixels
	char u6733; //padding?
	BOOL u6734; //play animSound battle cry?, set to 0 after use
	BOOL u6738; //play animSound selection?, set to 0 after use
	char u673c[9];
	char u6745; //padding?
	int u6746; //assoc actions
	BOOL m_bReequipItem; //674ah
	BOOL m_bEquippingItem; //674eh
	char u6752; //default = 2a; if CRE name does not start with *, will put first character in here; inherits value from GAM (unknown above killXP(chapter), inherits from Actor2E (char)
	char u6753;
	int u6754; //m_nColorsPrev1, compared to cdsCurrent.ColorListRgb count
	int u6758; //m_nColorsPrev2, compared to cdsCurrent.ColorListRgb count
	int u675c; //m_nWeaponProtectionsPrev
	int u6760;
	BOOL m_bInitTOB; //6764h, initialises innates, once per construction
	BOOL u6768; //to do with grabbed item
	int m_nSpriteUpdateTimer; //676ch, increments up to 15, then set to 0 on before CMessageSpriteUpdate
	int u6770; //assoc sprite update timer, 0 = always sprite update when ready, other = sprite update, reset to 0 if timer > 2
};

extern void (CCreatureObject::*CCreatureObject_GetSpellIdsName)(int, IECString*);
extern CDerivedStats& (CCreatureObject::*CCreatureObject_GetDerivedStats)();
extern ACTIONRESULT (CCreatureObject::*CCreatureObject_CastSpell)(ResRef&, CGameObject&, BOOL, STRREF, void*, BOOL, BOOL);
extern void (*CCreatureObject_RemoveItem)(CCreatureObject&, int);
extern CEffectList& (CCreatureObject::*CCreatureObject_GetEquippedEffectsList)();
extern CEffectList& (CCreatureObject::*CCreatureObject_GetMainEffectsList)();
extern CCreatureObject& (CCreatureObject::*CCreatureObject_Construct_10)(void*, unsigned int, BOOL, int, int, int, unsigned int, int, int, int);
extern void (CCreatureObject::*CCreatureObject_CreateGore)(int, short, short);
extern void (CCreatureObject::*CCreatureObject_UpdateHPStatusTooltip)(CUIControl&);
extern short (CCreatureObject::*CCreatureObject_GetOrientationTo)(POINT&);
extern short (*CCreatureObject_CalculateOrientation)(POINT&, POINT&);
extern void (CCreatureObject::*CCreatureObject_SetAnimationSequence)(short);
extern void (CCreatureObject::*CCreatureObject_StartSpriteEffect)(char, char, int);
extern CItem& (CCreatureObject::*CCreatureObject_GetFirstEquippedLauncherOfAbility)(ItmFileAbility& ability, int* pnSlot);
extern int (CCreatureObject::*CCreatureObject_GetSlotOfEquippedLauncherOfAmmo)(short, short);
extern void (CCreatureObject::*CCreatureObject_UnequipAll)(BOOL);
extern void (CCreatureObject::*CCreatureObject_EquipAll)(BOOL);
extern void (CCreatureObject::*CCreatureObject_AddKnownSpell)(ResRef&, BOOL);
extern CreFileKnownSpell& (CCreatureObject::*CCreatureObject_GetKnownSpellPriest)(int, int);
extern CreFileKnownSpell& (CCreatureObject::*CCreatureObject_GetKnownSpellMage)(int, int);
extern CreFileKnownSpell& (CCreatureObject::*CCreatureObject_GetKnownSpellInnate)(int, int);
extern CreFileMemSpell& (CCreatureObject::*CCreatureObject_GetMemSpellPriest)(int, int);
extern CreFileMemSpell& (CCreatureObject::*CCreatureObject_GetMemSpellMage)(int, int);
extern CreFileMemSpell& (CCreatureObject::*CCreatureObject_GetMemSpellInnate)(int, int);
extern BOOL (CCreatureObject::*CCreatureObject_AddMemSpellPriest)(int, int, int*);
extern BOOL (CCreatureObject::*CCreatureObject_AddMemSpellMage)(int, int, int*);
extern BOOL (CCreatureObject::*CCreatureObject_AddMemSpellInnate)(int, int, int*);
extern BOOL (CCreatureObject::*CCreatureObject_AddKnownSpellPriest)(ResRef&, int);
extern BOOL (CCreatureObject::*CCreatureObject_AddKnownSpellMage)(ResRef&, int);
extern BOOL (CCreatureObject::*CCreatureObject_AddKnownSpellInnate)(ResRef&, int);
extern IECString& (CCreatureObject::*CCreatureObject_GetLongName)();
extern STRREF (CCreatureObject::*CCreatureObject_GetLongNameStrRef)();
extern void (CCreatureObject::*CCreatureObject_SetSpellMemorizedState)(ResSplContainer&, BOOL);
extern void (CCreatureObject::*CCreatureObject_ValidateAttackSequence)(char*);
extern char (CCreatureObject::*CCreatureObject_GetNumUniqueMemSpellMage)(int, ResRef);
extern BOOL (CCreatureObject::*CCreatureObject_InDialogAction)();
extern unsigned int (CCreatureObject::*CCreatureObject_GetKitUnusableFlag)();
extern void (CCreatureObject::*CCreatureObject_PrintEventMessage)(short, int, int, int, STRREF, BOOL, IECString&);
extern ACTIONRESULT (CCreatureObject::*CCreatureObject_ActionMoveToObject)(CGameObject&);
extern ACTIONRESULT (CCreatureObject::*CCreatureObject_ActionPickPockets)(CCreatureObject&);
extern short (CCreatureObject::*CCreatureObject_GetSpellCastingLevel)(ResSplContainer&, BOOL);
extern void (CCreatureObject::*CCreatureObject_UpdateFaceTalkerTimer)();

extern bool (CCreatureObject::*CCreatureObject_NeedsAIUpdate)(bool, int);
extern BOOL (CCreatureObject::*CCreatureObject_EvaluateTrigger)(Trigger&);
extern ACTIONRESULT (CCreatureObject::*CCreatureObject_ExecuteAction)();
extern void (CCreatureObject::*CCreatureObject_SetCurrentAction)(Action&);

#endif //OBJCRE_H
