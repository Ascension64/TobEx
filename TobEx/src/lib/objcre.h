#ifndef OBJCRE_H
#define OBJCRE_H

#include "stdafx.h"
#include "datatypes.h"
#include "effcore.h"
#include "splcore.h"
#include "objcore.h"
#include "scrcore.h"
#include "itmcore.h"
#include "icon.h"
#include "sndcore.h"
#include "vidcore.h"
#include "pathfind.h"
#include "objproj.h"
#include "splcore.h"
#include "dlgcore.h"
#include "animcore.h"
#include "tlkcore.h"

//Event message ids
#define EVENTMESSAGE_BACKSTAB_SUCCESS			0x01
#define EVENTMESSAGE_BACKSTAB_WEAPON_UNSUITABLE	0x1C
#define EVENTMESSAGE_BACKSTAB_FAIL				0x40

struct CQuickObject { //Size 30h
//Constructor: see 0x532F23
	ResRef rUsageIcon; //0h
	STRREF strrefName; //8h
	ResRef uc;
	STRREF strrefLauncherName; //14h
	short wAmount; //18h
	struct ObjectInfo { //Size 14h
		short wType; //0h, 1 = SPL, 2 = ITM
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

struct CFavorite { //Size Eh
//Constructor: 0x579E70
	unsigned int* vtable; //0h
	ResRef name; //4h
	short nTimesUsed; //ch
};

class CCreatureObject : public CGameSprite { //Size 6774h
//Constructor: 0x87FB08
public:
	CGameObject& SetTarget(Object& o, char type);
	CDerivedStats& GetDerivedStats();
	ACTIONRESULT CCreatureObject::CastSpell(ResRef& rResource, CGameObject& cgoTarget, BOOL bPrintStrref, STRREF strref, void* pMod, BOOL bPrintEventMsg, BOOL bDoNotApplySplAbil);
	static void RemoveItem(CCreatureObject& cre, int nSlot);
	CEffectList& GetEquippedEffectsList();
	CEffectList& GetMainEffectsList();
	void UnequipAll(BOOL bKeepEffects);
	void EquipAll(BOOL bDoNotApplyEffects);
	CreFileKnownSpell& GetKnownSpellPriest(int nLevel, int nIndex);
	CreFileKnownSpell& GetKnownSpellMage(int nLevel, int nIndex);
	CreFileKnownSpell& GetKnownSpellInnate(int nLevel, int nIndex);
	CreFileMemSpell& GetMemSpellPriest(int nLevel, int nIndex);
	CreFileMemSpell& GetMemSpellMage(int nLevel, int nIndex);
	CreFileMemSpell& GetMemSpellInnate(int nLevel, int nIndex);
	BOOL AddMemSpellPriest(int nLevel, int nIndex, int* pIndex);
	BOOL AddMemSpellMage(int nLevel, int nIndex, int* pIndex);
	BOOL AddMemSpellInnate(int nLevel, int nIndex, int* pIndex);
	IECString& GetLongName();
	STRREF GetLongNameStrRef();
	unsigned int GetKitUnusableFlag();
	void PrintEventMessage(short wEventId, int nParam1, int nParam2, int nParam3, STRREF strrefParam4, BOOL bParam5, IECString& sParam6);

	//AA98A8
	virtual ~CCreatureObject() {} //v0

	short u3d4;
	short u3d6;
	ResRef saveName; //3d8h, CRE name with * prefix
	short isSpawned; //3e0h, bHasSpawned
	int Arg4; //3e2h, TicksTillRemove
	short Arg5; //3e6h, Actor3C
	short Arg6; //3e8h, Actor3E
	int destY; //3eah
	int destX; //3eeh
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

	CInventory m_Inventory; //a5ah
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

	CGameObject* pThis;
	int ub02;
	int ub06;
	CDerivedStats cdsCurrent; //0xub0a
	CDerivedStats cdsPrevious; //0x13c2, previous state to restore after effect finishes
	CDerivedStats cdsDiff; //0x1c7a, difference to add to currentState
	int u2532;
	CIcon weapon0; //2536h
	CIcon weapon1; //2566h
	CIcon weapon2; //2596h
	CIcon weapon3; //25c6h
	CIcon spell0; //25f6h
	CIcon spell1; //2626h
	CIcon spell2; //2656h
	CIcon item0; //2686h
	CIcon item1; //26b6h
	CIcon item2; //26e6h
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
	CSound WalkingSounds[2]; //27bah
	int u288e;
	CSound u2892[2];
	char bCurrentWalkingSoundIdx; //2966h
	char u2967; //which CSound of u2892 to use
	CSound u2968;
	CSound u29d2;
	CSound u2a3c; //casting sound
	CSound u2aa6;
	CSound u2b10; //associated with overlays
	int nTimesTalkedTo; //2b7ah, for NumTimesTalkedTo() trigger
	int u2b7e;
	ResRef areaSpecificScriptName;
	int nTimesInteractedWith[24]; //2b8ah, each element associated with NPC.IDS //copied from saved game unknown area under happiness
	short u2bea;
	Object oInteractee; //2bech, for InteractingWith() trigger
	Enum u2c00;
	BOOL bScheduled; //2c04h, not outside 24-hour schedule
	BOOL bActive; //2c08h, not diseased/deactivated
	BOOL bFree; //2c0ch, not mazed/imprisoned
	int u2c10;
	int u2c14;
	char u2c18;
	TerrainTable tt; //2c19h
	TerrainTable tt2; //2c29h
	TerrainTable tt3; //2c39h
	char u2c49;
	AnimData m_animation; //2c4ah
	int u2c50;
	int u2c54;
	char u2c58;
	char u2c59; //padding?
	char u2c5a;
	char u2c5b; //padding?
	short u2c5c;
	CVidCell u2c5e;
	VidPal u2d34;
	int u2d58;
	CVidCell u2d5c;
	VidPal u2e32;
	int u2e56;
	char u2e5a[24]; //don't know the type here
	char u2e72; //don't know the type here
	char u2e73;
	int isAnimationMovable; //0 = static animation (ANIMATE.IDS values < 0x1000)
	int u2e78;
	char u2e7c; //3
	char m_nMirrorImages; //2e7dh, immune to poison and display special effect icon?
	bool m_bBlur; //2e7eh
	bool m_bInvisible; //invisibility and improved invisibility
	bool m_bSanctuary;
	char u2e81;
	CVidCell SANCTRY; //0x2e82
	bool m_bEntangle; //0x2f58
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
	int u3394;
	float u3398;
	float u339c; //1.875f
	short u33a0; //range?
	char u33a2; //mirror 33a4 through X axis
	char u33a3;
	float u33a4; //radians CCW to North
	int u33a8;
	short wCurrentSequenceSimplified; //33ach, used in animation sound selection (see animation sound 2DA files for values)
	POINT u33ae; //linked to coordinates
	POINT u33b6;
	POINT u33be;
	POINT ptBlur1; //33c6h, copied from 0x6 and 0xa
	POINT ptBlur2; //33ceh, copied from above
	int u33d6;
	int u33da;
	int u33de;
	short u33e2; //assoc with orientations
	short u33e4; //assoc with orientations
	short wOrientGoal; //33e6h, orientation to get to
	short wOrientInstant; //33e8h, instantaneous orientation
	int* u33ea;
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
	short u3442;
	short u3444;
	int u3446; //0x001e1eff
	int u344a;
	int u344e;
	CVidBitmap smallPortrait; //3452h
	int u3508;
	int u350c;
	char u3510;
	char u3511; //padding?
	long u3512[2];
	int u351a;
	int u351e;
	int u3522;
	int u3526;
	int u352a; //assoc with action 0x30
	IECPtrList u352e;
	short u354a;
	short u354c; //assoc actions
	short u354e;
	int u3550; //assoc actions
	short u3554;
	short u3556; //assoc actions
	short u3558;
	short u355a;
	int u355c;
	int u3560;
	CEffectList m_EffectsEquipped; //3564h, for while equipped effects
	CEffectList m_EffectsMain; //3590h, for all other effects
	IECPtrList u35bc; //AAA8FC, CPermRepeatingEffList
	CPtrArray u35d8;
	POINT u35ec; //assoc actions
	int u35f4;
	int u35f8;
	int u35fc;
	int u3600;
	int u3604;
	int u3608;
	POSITION* posSelected; //360ch, of CPartySelection list
	int u3610;
	int u3614;
	CProjectile* m_currentProjectile; //3618h, once projectile placed in area list, set to NULL
	ResSplContainer* m_currentSpell; //361ch
	int u3620; //assoc actions
	int u3624;
	short u3628[0x28];
	char u3678[8];
	char m_AttackSpeed; //3680h, (weaponSpeed - physicalSpeed - 1D6 - luck) / 0.5 * dieSize, range 0-10, determines the y-coordinate of the pixel to select in RNDBASE*.BMP
	char u3681;
	short u3682; //action opcode
	Object oDerived; //3684h, keeps General, scriptName is of thisCre
	Object oBase; //3698h, base for o and oDerived, used for gender for sounds, scriptName is of thisCre
	int u36ac;
	short u36b0;
	int u36b2;
	short u36b6;
	short u36b8;
	short u36ba; //assoc actions, and luck
	int u36bc; //assoc actions
	short u36c0;
	short u36c2[2];
	short wRoundTimer; //36c6h, range 0-100, determines the x-coordinate of the pixel to select in RNDBASE*.BMP
	int u36c8; //assoc actions (idle time?), ++ with NoAction()
	int u36cc;
	int u36d0; //1 = an effect is applied?
	char u36d4; //assoc actions
	char u36d5;
	BOOL bUsingLeftWeapon; //36d6h
	short u36da;
	int u36dc; //assoc with items
	int u36e0; //set to 1 when Set Item Color effect used
	int u36e4; //assoc with items
	int u36e8;
	int u36ec;
	CSelectionCircle cscSelf; //36f0h
	CSelectionCircle cscTarget; //3714h
	Enum eTarget; //3738h, the target of actions?
	POINT ptTarget; //373ch, set by ProtectPoint(), MoveToPoint(), Leader(), cscTarget places here
	short u3744;
	char nnSlotSelected; //3746h, copied from af6h
	char nnAbilitySelected; //3747h, copied from af8h
	struct _u3748 {
		ResRef u3748;
		int u3750;
		ResRef u3754;
		int u375c;
		short u3760;
		short u3762;
		short u3764;
		short u3766;
		ResRef u3768;
		int u3770;
		short u3774;
		char u3776;
		char u3777;
	} m_u3748;
	ResRef rDialog; //3778h
	ResRef rDialog2; //3780h
	char u3788;
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
	int u6294; //7fff
	int u6298; //contains char data
	BOOL bInAttack; //629ch, in the middle of attack phase of a round
	short u62a0; //assoc actions
	int u62a2;
	int u62a6; //countdown timer, related to 62aa
	Enum u62aa;
	int nSoundLength; //62aeh, in sec
	char u62b2[3];
	char u62b5; //padding?
	CDwordList m_PortraitIcons; //62b6h
	CVidCell u62d2;
	int u63a8;
	int u63ac; //0x105cc
	int u63b0; //assoc with berserk state?
	short u63b4;
	int u63b6; //related to constitution?
	int u63ba[6];
	char u63d2[2];
	int nUnselectableVariable; //63d4h
	ResRef voiceset; //63d8h, from CRE entry in GAM file
	int u63e0; //m_bStoneSkin?
	int u63e4;
	int u63e8;
	int u63ec;
	int u63f0;
	int u63f4;
	int u63f8;
	short u63fc; //contains an actionOpcode (a dialoge or escape area action?)
	int u63fe; //assoc actions
	int u6402; //assoc actions
	int u6406;
	int u640a;
	short u640e;
	short u6410;
	BOOL bUseCurrentState; //6412h, 0 = uses prevState, 1 = uses currentState, set to 0 when refreshing repeating effects
	short u6416;
	int u6418;
	int u641c;
	CVariableArray* pLocalVariables; //6420h
	int u6424; //1 when CRE copied over, 0 at constructor end
	IECPtrList ProtectedSpls; //6428h, Size 1Ch objects, DW nPower, DW nOpcodeEffect, CProjectile*, DW, STRREF, DW, DW
	int u6444;
	int u6448;
	int u644c;
	Enum u6450; //contains enum of CVisualEffect
	int u6454;
	CQuickObjectList* pSelectSpellSpells; //6458h
	CScript* pDream; //645ch
	CGameDialog dlgCurrent; //6460h
	CGameDialog dlgCurrent2; //64c4h
	short u6528;
	int u652a;
	int m_nContingencyDelay; //652eh, a countdown timer set to 100, delay processing contingency triggers until 0
	IECString sWeaponLeftToHitBonuses; //6532h
	IECString sWeaponRightToHitBonuses; //6536h
	IECString sWeaponLeftDamageBonuses; //653ah
	IECString sWeaponRightDamageBonuses; //653eh
	short u6542;
	int u6544; //bitflag
	CreFileMemSpellLevel memInfoWizardCopy[9]; //0x6548, copied from currentState after effect applied
	CreFileMemSpellLevel memInfoPriestCopy[7]; //0x65d8, copied from currentState after effect applied
	int u6648;
	char u664c;
	char u664d; //padding?
	int u664e;
	CDwordList u6652;
	IECPtrList u666e;
	BOOL bInStore; //668ah, prevents party required area transitions
	int u668e;
	int u6692;
	int u6696; //assoc actions
	int u669a;
	int u669e;
	int u66a2;
	int u66a6;
	int u66aa;
	CEventMessageList m_EventMessages; //66aeh
	int u66ca[2];
	_8DF1F2 u66d2;
	int u6722;
	int nDamageTaken; //6726h
	int u672a;
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
	int u6754[7];
	int u6770;
};

extern CGameObject& (CCreatureObject::*CCreatureObject_SetTarget)(Object&, char);
extern CDerivedStats& (CCreatureObject::*CCreatureObject_GetDerivedStats)();
extern ACTIONRESULT (CCreatureObject::*CCreatureObject_CastSpell)(ResRef&, CGameObject&, BOOL, STRREF, void*, BOOL, BOOL);
extern void (*CCreatureObject_RemoveItem)(CCreatureObject&, int);
extern CEffectList& (CCreatureObject::*CCreatureObject_GetEquippedEffectsList)();
extern CEffectList& (CCreatureObject::*CCreatureObject_GetMainEffectsList)();
extern void (CCreatureObject::*CCreatureObject_UnequipAll)(BOOL);
extern void (CCreatureObject::*CCreatureObject_EquipAll)(BOOL);
extern unsigned int (CCreatureObject::*CCreatureObject_GetKitUnusableFlag)();
extern CreFileKnownSpell& (CCreatureObject::*CCreatureObject_GetKnownSpellPriest)(int, int);
extern CreFileKnownSpell& (CCreatureObject::*CCreatureObject_GetKnownSpellMage)(int, int);
extern CreFileKnownSpell& (CCreatureObject::*CCreatureObject_GetKnownSpellInnate)(int, int);
extern CreFileMemSpell& (CCreatureObject::*CCreatureObject_GetMemSpellPriest)(int, int);
extern CreFileMemSpell& (CCreatureObject::*CCreatureObject_GetMemSpellMage)(int, int);
extern CreFileMemSpell& (CCreatureObject::*CCreatureObject_GetMemSpellInnate)(int, int);
extern BOOL (CCreatureObject::*CCreatureObject_AddMemSpellPriest)(int, int, int*);
extern BOOL (CCreatureObject::*CCreatureObject_AddMemSpellMage)(int, int, int*);
extern BOOL (CCreatureObject::*CCreatureObject_AddMemSpellInnate)(int, int, int*);
extern IECString& (CCreatureObject::*CCreatureObject_GetLongName)();
extern STRREF (CCreatureObject::*CCreatureObject_GetLongNameStrRef)();
extern void (CCreatureObject::*CCreatureObject_PrintEventMessage)(short, int, int, int, STRREF, BOOL, IECString&);

#endif //OBJCRE_H
