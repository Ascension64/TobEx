#ifndef OBJCRE_H
#define OBJCRE_H

#include "utils.h"
#include "datatypes.h"
#include "resref.h"
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
#include "cstringex.h"
#include "tlkcore.h"

struct CFavorite { //Size Eh
//Constructor: 0x579E70
	DWORD* vtable; //0h
	ResRef name; //4h
	WORD nTimesUsed; //ch
};

struct CDerivedStatsBase { //Size 2B0h
	DWORD stateFlags; //0h
	WORD maxHP; //4h
	WORD ACEffective; //6h
	WORD ACCrushingMod;
	WORD ACMissileMod;
	WORD ACPiercingMod;
	WORD ACSlashingMod;
	WORD THAC0; //10h
	WORD numAttacks;
	WORD saveDeath;
	WORD saveWands;
	WORD savePolymorph;
	WORD saveBreath;
	WORD saveSpells;
	WORD resistFire;
	WORD resistCold; //20h
	WORD resistElectricity;
	WORD resistAcid;
	WORD resistMagic;
	WORD resistMagicFire;
	WORD resistMagicCold;
	WORD resistSlashing;
	WORD resistCrushing;
	WORD resistPiercing; //30h
	WORD resistMissile;
	WORD lore;
	WORD lockpicking;
	WORD stealth;
	WORD findTraps;
	WORD pickPockets;
	WORD fatigue;
	WORD intoxication; //40h
	WORD luck;
	WORD tracking;
	WORD levelPrimary;
	WORD levelSecondary;
	WORD levelTertiary;
	WORD sex;
	WORD strength;
	WORD strengthPercent; //50h
	WORD intelligence;
	WORD wisdom;
	WORD dexterity;
	WORD constitution;
	WORD charisma;
	DWORD XPWorth;
	DWORD currentXP; //60h
	DWORD gold;
	DWORD morale;
	DWORD reputation;
	WORD moraleBreak; //70h
	WORD racialEnemy;
	DWORD hideInShadows;
	DWORD detectIllusion;
	DWORD setTraps;
	WORD damageBonus; //80h
	WORD spellFailMage; //82h
	WORD spellFailPriest; //84h
	WORD spellDurationModMage; //86h
	WORD spellDurationModPriest; //88h
	WORD turnUndeadLevel; //8ah, priestLevel
	WORD backstabDamageMultiplier; //8ch, backstabMod
	WORD layOnHandsAmount; //8eh
	DWORD held; //90h
	DWORD polymorph; //94h
	DWORD identifyMode; //98h
	DWORD entangle; //9ch
	DWORD sanctuary; //a0h
	DWORD minorGlobe; //a4h
	DWORD shieldGlobe; //a8h
	DWORD grease; //ach
	DWORD web; //b0h
	DWORD casterHold; //b4h, pause
	WORD translucent; //b8h
	WORD encumberance; //bah
	WORD missileToHitBonus; //bch
	WORD magicResistance; //beh
	WORD resistPoison; //c0h
	DWORD doNotJump; //c2h - i.e. will not jump coordinates to search map allowable position
	DWORD auraCleansing; //c6h
	WORD mentalSpeed; //cah
	WORD physicalSpeed; //cch
	WORD castinglevelbonusmage; //ceh
	WORD castinglevelbonuscleric; //d0h
	DWORD seeInvisible; //d2h
	DWORD ignoreDialoguPause; //d6h
	DWORD minHitPoints; //dah, 1 = immune to opcode instant death
	DWORD toHitBonusRight; //deh
	DWORD toHitBonusLeft; //e2h
	DWORD damageBonusRight; //e6h
	DWORD damageBonusLeft; //eah
	DWORD m_nStoneSkins;
	DWORD proficiencies[46];
	Enum puppermasterId; //1aah
	DWORD puppermasterType; //1aeh
	DWORD puppetType; //1b2h
	Enum puppetId; //1b6h
	DWORD checkForBerserk; //1bah
	DWORD berserkStage1; //1beh
	DWORD berserkStage2; //1c2h
	DWORD damageLuck; //1c6h
	ResRef BardSongEffect; //1cah
	DWORD u1d2[6];
	WORD u1ea;
	WORD kit[2];
	DWORD forceSurge; //1f0h
	DWORD surgeMod; //1f4h
	DWORD improvedHaste; //1f8h
	DWORD u1fc[16];
	STRREF title0; //23ch
	STRREF title1; //240h
	DWORD u244;
	DWORD u248;
	DWORD u24c;
	DWORD u250;
	DWORD u254;
	DWORD u258;
	DWORD u25c;
	DWORD u260;
	DWORD u264;
	DWORD u268;
	DWORD u26c;
	DWORD speedHasteWithoutAttackBonuses; //270h
	DWORD u274;
	DWORD u278;
	DWORD u27c;
	DWORD u280;
	DWORD u284;
	DWORD u288;
	DWORD u28c;
	DWORD u290;
	DWORD u294;
	DWORD u298;
	DWORD u29c;
	DWORD u2a0;
	DWORD stoneskinGolem; //2a4h, immune to poison and display special effect icon?
	DWORD u2a8;
	DWORD u2ac;
};

struct CDerivedStats : public CDerivedStatsBase { //Size 8B8h
	CPtrList ProtProjId; //2b0h, AA6624, holds DWORDS of PROJECTL.IDS Idx
	CPtrList ProtEff; //2cch, AA6618, CEffects
	CPtrList ProtObj; //2e8h, AA660C, holds Object objects
	DWORD ProtSplLvl[10]; //304h
	CPtrList ProtWeapMelee; //32ch, AA6600
	CPtrList ToHitModCreType; //348h, AA65F4
	CPtrList DamageModCreType; //364h, AA65F4
	CPtrList ForbidItem; //380h, AA65E8
	CPtrList ForbidItemType; //39ch, AA65DC
	CPtrList ApplyEffOnEquipItem; //3b8h, AA65E8
	CPtrList ApplyEffOnEquipItemType; //3d4h, AA65DC
	CPtrList BounceProjId; //3f0h, AA6624
	CPtrList BounceEff; //40ch, AA6618, CEffect
	BOOL BounceSplLvl[10]; //428h, if 1 for a level, is affected by that power level
	QWORD BounceSplLvlDec[10]; //450h
	QWORD ProtSplLvlDec[10]; //4a0h

	//group of 14
	CPtrList ProtTypePrimary; //4f0h, AA65D0
	CPtrList ProtTypeSecondary; //50ch, AA65D0
	CPtrList BounceTypePrimary; //528h, AA65D0
	CPtrList BounceTypeSecondary; //544h, AA65D0
	CPtrList ForbidItem2; //560h, AA65E8
	CPtrList ForbidItemType2; //57ch, AA65DC
	CPtrList ProtSpl; //598h, AA65C4
	CPtrList BounceSpl; //5b4h, AA65C4
	CPtrList ImmuneTypePrimaryDec; //5d0h, AA65B8
	CPtrList ImmuneTypeSecondaryDec; //5ech, AA65B8
	CPtrList BounceTypePrimaryDec; //608h, AA65B8
	CPtrList BounceTypeSecondaryDec; //624h, AA65B8
	CPtrList CastSpellOnCondition; //640h, AA65AC
	CPtrList RepeatingEff; //65ch, AA65A0

	DWORD u678;
	QWORD SplLvlTrap[10]; //67ch
	CPtrList SplSequencer; //6cch, AA65AC
	CPtrList ColorListPal; //6e8h, AA6594, item color objects of 0x2?
	CPtrList ColorListRgb; //704h, AA6588
	CreFileMemSpellLevel memInfoWizard[9]; //720h
	CreFileMemSpellLevel memInfoPriest[7]; //7b0h
	DWORD ButtonDisable[14]; //820h
	DWORD ButtonDisableSplPriest; //858h
	DWORD ButtonDisableSplWizard; //85ch
	DWORD ButtonDisableSplInnate; //858h
	CPtrList MeleeEffects; //864h, AA657C
	CPtrList RangedEffects; //880h, AA657C
	CPtrList ACModCreType; //89ch, AA65F4
};


class CCreatureObject : public CGameSprite { //Size 6774h
//Constructor: 0x87FB08
public:
	CreFileKnownSpell& GetKnownSpellPriest(DWORD, DWORD);
	CreFileKnownSpell& GetKnownSpellMage(DWORD, DWORD);
	CreFileKnownSpell& GetKnownSpellInnate(DWORD, DWORD);
	CreFileMemSpell& GetMemSpellPriest(DWORD, DWORD);
	CreFileMemSpell& GetMemSpellMage(DWORD, DWORD);
	CreFileMemSpell& GetMemSpellInnate(DWORD, DWORD);
	BOOL AddMemSpellPriest(DWORD, DWORD, DWORD*);
	BOOL AddMemSpellMage(DWORD, DWORD, DWORD*);
	BOOL AddMemSpellInnate(DWORD, DWORD, DWORD*);

	//AA98A8
	virtual ~CCreatureObject() {} //v0

	WORD u3d4;
	WORD u3d6;
	ResRef saveName; //0x3d8, CRE name with * prefix
	WORD isSpawned; //0x3e0, bHasSpawned
	DWORD Arg4; //0x3e2, TicksTillRemove
	WORD Arg5; //0x3e6, Actor3C
	WORD Arg6; //0x3e8, Actor3E
	DWORD destY; //0x3ea
	DWORD destX; //0x3ee
	DWORD timesOfDay; //0x3f2, creature schedule
	CreFileData m_BaseStats; //0x3f6
	CKnownSpellList m_KnownSpellsPriest[7]; //0x65e
	CKnownSpellList m_KnownSpellsWizard[9]; //0x722
	CKnownSpellList m_KnownSpellsInnate; //0x81e
	CreFileMemSpellLevel* m_MemInfoPriest[7]; //0x83a
	CreFileMemSpellLevel* m_MemInfoWizard[9]; //0x856
	CreFileMemSpellLevel* m_MemInfoInnate; //0x87a
	CMemSpellList m_MemSpellsPriest[7]; //0x87e
	CMemSpellList m_MemSpellsWizard[9]; //0x942
	CMemSpellList m_MemSpellsInnate; //0xa3e

	struct ItemSlots {
		//slots follow SLOTS.IDS
		CItem* m_pItemAmulet; //0xa5a
		CItem* m_pItemArmor; //0xa5e
		CItem* m_pItemBelt; //0xa62
		CItem* m_pItemBoots; //0xa66
		CItem* m_pItemCloak; //0xa6a
		CItem* m_pItemGauntlets; //0xa6e
		CItem* m_pItemHelmet; //0xa72
		CItem* m_pItemRingLeft; //0xa76
		CItem* m_pItemRingRight; //0xa7a
		CItem* m_pItemShield; //0xa7e
		CItem* m_pItemFist; //0xa82
		CItem* m_pItemAmmo0; //0xa86
		CItem* m_pItemAmmo1; //0xa8a
		CItem* m_pItemAmmo2; //0xa8e
		CItem* m_pItemAmmo3; //0xa92
		CItem* m_pItemMisc0; //0xa96
		CItem* m_pItemMisc1; //0xa9a
		CItem* m_pItemMisc2; //0xa9e
		CItem* m_pItemMisc3; //0xaa2
		CItem* m_pItemMisc4; //0xaa6
		CItem* m_pItemMisc5; //0xaaa
		CItem* m_pItemMisc6; //0xaae
		CItem* m_pItemMisc7; //0xab2
		CItem* m_pItemMisc8; //0xab6
		CItem* m_pItemMisc9; //0xaba
		CItem* m_pItemMisc10; //0xabe
		CItem* m_pItemMisc11; //0xac2
		CItem* m_pItemMisc12; //0xac6
		CItem* m_pItemMisc13; //0xaca
		CItem* m_pItemMisc14; //0xace
		CItem* m_pItemMisc15; //0xad2
		CItem* m_pItemMisc16; //0xad6
		CItem* m_pItemMisc17; //0xada
		CItem* m_pItemMisc18; //0xade
		CItem* m_pItemMisc19; //0xae2, magical weapon slot
		CItem* m_pItemWeapon0; //0xae6
		CItem* m_pItemWeapon1; //0xaea
		CItem* m_pItemWeapon2; //0xaee
		CItem* m_pItemWeapon3; //0xaf2
		BYTE weaponSlotSelected; //0xaf6
		BYTE uaf7; //pad
		BYTE weaponAbilitySelected; //af8h
		BYTE uaf9; //pad
		DWORD uafa; //pCItem is bit 16 set in creature flags
	} itemSlots;
	CGameObject* pThis;
	DWORD ub02;
	DWORD ub06;
	CDerivedStats cdsCurrent; //0xub0a
	CDerivedStats cdsPrevious; //0x13c2, previous state to restore after effect finishes
	CDerivedStats cdsDiff; //0x1c7a, difference to add to currentState
	DWORD u2532;
	CIcon weapon0; //0x2536
	CIcon weapon1;
	CIcon weapon2;
	CIcon weapon3;
	CIcon spell0; //0x25f6
	CIcon spell1;
	CIcon spell2;
	CIcon item0; //0x2686
	CIcon item1;
	CIcon item2;
	IECString sLongName; //0x2716
	BYTE u271a;
	BYTE u271b; //padding?
	struct CStatistics {
		STRREF mostPowerfulFoe; //0h
		DWORD mostPowerfulXP; //4h
		DWORD inPartyTime; //8h
		DWORD joinedTime; //ch
		BOOL inParty; //10h
		DWORD chapterKillXP; //14h
		DWORD chapterNumKills; //18h
		DWORD gameKillXP; //1ch
		DWORD gameNumKills; //20h
		CFavorite favSpell[4]; //24h
		CFavorite favWeapon[4]; //5ch
	} statistics; //271ch
	ResRef currentArea;
	BYTE m_bGlobal; //0x27b8, is this Cre Global
	BYTE u27b9;
	CSound WalkingSounds[2]; //27bah
	DWORD u288e;
	CSound u2892[2];
	BYTE bCurrentWalkingSoundIdx; //2966h
	BYTE u2967; //which CSound of u2892 to use
	CSound u2968;
	CSound u29d2;
	CSound u2a3c; //casting sound
	CSound u2aa6;
	CSound u2b10; //associated with overlays
	DWORD nTimesTalkedTo; //2b7ah, for NumTimesTalkedTo() trigger
	DWORD u2b7e;
	ResRef areaSpecificScriptName;
	DWORD nTimesInteractedWith[24]; //2b8ah, each element associated with NPC.IDS //copied from saved game unknown area under happiness
	WORD u2bea;
	Object oInteractee; //2bech, for InteractingWith() trigger
	Enum u2c00;
	DWORD u2c04;
	DWORD u2c08;
	DWORD u2c0c;
	DWORD u2c10;
	DWORD u2c14;
	BYTE u2c18;
	TerrainTable tt; //2c19h
	TerrainTable tt2; //2c29h
	TerrainTable tt3; //2c39h
	BYTE u2c49;
	AnimData m_animation; //2c4ah
	DWORD u2c50;
	DWORD u2c54;
	BYTE u2c58;
	BYTE u2c59; //padding?
	BYTE u2c5a;
	BYTE u2c5b; //padding?
	WORD u2c5c;
	CVidCell u2c5e;
	VidPal u2d34;
	DWORD u2d58;
	CVidCell u2d5c;
	VidPal u2e32;
	DWORD u2e56;
	char u2e5a[24]; //don't know the type here
	BYTE u2e72; //don't know the type here
	BYTE u2e73;
	DWORD isAnimationMovable; //0 = static animation (ANIMATE.IDS values < 0x1000)
	DWORD u2e78;
	BYTE u2e7c; //3
	BYTE m_nMirrorImages; //immune to poison and display special effect icon?
	bool m_bBlur; //2e7eh
	bool m_bInvisible; //invisibility and improved invisibility
	bool m_bSanctuary;
	BYTE u2e81;
	CVidCell SANCTRY; //0x2e82
	bool m_bEntangle; //0x2f58
	BYTE u2f59; //padding
	CVidCell SPEntaCl;
	bool m_bInvGlobe;
	BYTE u3031; //padding
	CVidCell MinorGlb;
	bool m_bSpellShield;
	BYTE u3109; //padding
	CVidCell SpShield;
	bool m_bGrease;
	BYTE u31e1; //padding
	CVidCell GreaseD;
	bool m_bWeb;
	BYTE u32b9; //padding
	CVidCell WebEntD;

	float u3390;
	DWORD u3394;
	float u3398;
	float u339c; //1.875f
	WORD u33a0; //range?
	BYTE u33a2; //mirror 33a4 through X axis
	BYTE u33a3;
	float u33a4; //radians CCW to North
	DWORD u33a8;
	WORD wCurrentSequenceSimplified; //33ach, used in animation sound selection (see animation sound 2DA files for values)
	QWORD u33ae; //linked to coordinates
	QWORD u33b6;
	QWORD u33be;
	POINT ptBlur1; //33c6h, copied from 0x6 and 0xa
	POINT ptBlur2; //33ceh, copied from above
	DWORD u33d6;
	DWORD u33da;
	DWORD u33de;
	WORD u33e2;
	WORD u33e4;
	WORD orientation; //33e6h, bits from Arg10 (orientation), linked to animations
	WORD orientation2; //33e8h, bits from Arg10 (orientation), linked to animations
	DWORD u33ea;
	WORD u33ee;
	CDwordList u33f0;
	CDwordList u340c;
	WORD u3428;
	DWORD u342a;
	DWORD u342e;
	DWORD u3432; //0x8000
	DWORD u3436;
	DWORD u343a;
	CSearchRequest* m_currentSearchRequest; //343eh
	WORD u3442;
	WORD u3444;
	DWORD u3446; //0x001e1eff
	DWORD u344a;
	DWORD u344e;
	CVidBitmap smallPortrait; //3452h
	DWORD u3508;
	DWORD u350c;
	BYTE u3510;
	BYTE u3511; //padding?
	QWORD u3512;
	DWORD u351a;
	DWORD u351e;
	DWORD u3522;
	DWORD u3526;
	DWORD u352a; //assoc with action 0x30
	CPtrList u352e;
	WORD u354a;
	WORD u354c; //assoc actions
	WORD u354e;
	DWORD u3550; //assoc actions
	WORD u3554;
	WORD u3556; //assoc actions
	WORD u3558;
	WORD u355a;
	DWORD u355c;
	DWORD u3560;
	CPtrListEffect EffectsEquipped; //3564h, for while equipped effects
	CPtrListEffect EffectsMain; //3590h, for all other effects
	CPtrList u35bc;
	CPtrArray u35d8;
	POINT u35ec; //assoc actions
	DWORD u35f4;
	DWORD u35f8;
	DWORD u35fc;
	DWORD u3600;
	DWORD u3604;
	DWORD u3608;
	POSITION* posSelected; //360ch, of CPartySelection list
	DWORD u3610;
	DWORD u3614;
	CProjectile* m_currentProjectile; //3618h, once projectile placed in area list, set to NULL
	ResSplContainer* m_currentSpell; //361ch
	DWORD u3620; //assoc actions
	DWORD u3624;
	WORD u3628[0x28];
	BYTE u3678[8];
	BYTE u3680; //range 0-10
	BYTE u3681;
	WORD u3682; //action opcode
	Object IdsCopy2; //0x3684, derived from 0x3698, except general is kept?, scriptName is of thisCre
	Object IdsCopy1; //0x3698, basis for 0x1c and 0x3684?, used for gender for sounds, scriptName is of thisCre
	DWORD u36ac;
	WORD u36b0;
	DWORD u36b2;
	WORD u36b6;
	WORD u36b8;
	WORD u36ba; //assoc actions, and luck
	DWORD u36bc; //assoc actions
	WORD u36c0;
	WORD u36c2[2];
	WORD u36c6; //range 0-100
	DWORD u36c8; //assoc actions (idle time?), ++ with NoAction()
	DWORD u36cc;
	DWORD u36d0; //1 = an effect is applied?
	BYTE u36d4; //assoc actions
	BYTE u36d5;
	DWORD u36d6; //assoc actions
	WORD u36da;
	DWORD u36dc; //assoc with items
	DWORD u36e0; //set to 1 when Set Item Color effect used
	DWORD u36e4; //assoc with items
	DWORD u36e8;
	DWORD u36ec;
	_95BFAF u36f0;
	_95BFAF u3714;
	Enum u3738;
	POINT ptTarget; //373ch, set by ProtectPoint(), MoveToPoint(), Leader()
	WORD u3744;
	BYTE nWeaponSlotSelected; //3746h, copied from af6h
	BYTE nWeaponAbilitySelected; //3747h, copied from af8h
	struct unk3748 {
		ResRef u3748;
		DWORD u3750;
		ResRef u3754;
		DWORD u375c;
		WORD u3760;
		WORD u3762;
		WORD u3764;
		WORD u3766;
		ResRef u3768;
		DWORD u3770;
		WORD u3774;
		BYTE u3776;
		BYTE u3777;
	} unk37481;
	ResRef dialogueFilename; //0x3778
	ResRef u3780;
	BYTE u3788;
	BYTE u3789; //padding?
	CStrRef soundset[100]; //0x378a
	BYTE rndEffSaveDeath; //0x6282, 1D20
	BYTE rndEffSaveWand; //0x6283, 1D20
	BYTE rndEffSavePolymorph; //0x6284, 1D20
	BYTE rndEffSaveBreath; //0x6285, 1D20
	BYTE rndEffSaveSpell; //0x6286, 1D20
	BYTE rndEffResistMagic; //0x6287, 1D100
	BYTE rndDoEff; //0x6288, 1D100, test against effect prob1 and prob2
	BYTE rndWildMagicLevel; //0x6289, 1D20, column of LVLMODWM.2DA
	BYTE rndDoWildMagic; //0x628A, 1D20, if 0, do wild magic
	BYTE u628b; //padding?
	QWORD u628c;
	DWORD u6294; //7fff
	DWORD u6298; //contains BYTE data
	DWORD u629c; //assoc actions
	WORD u62a0; //assoc actions
	DWORD u62a2;
	DWORD u62a6; //countdown timer, related to 62aa
	Enum u62aa;
	DWORD nSoundLength; //62aeh, in sec
	BYTE u62b2[3];
	BYTE u62b5; //padding?
	CDwordList portraitIcons; //62b6h
	CVidCell u62d2;
	DWORD u63a8;
	DWORD u63ac; //0x105cc
	DWORD u63b0; //assoc with berserk state?
	WORD u63b4;
	DWORD u63b6; //related to constitution?
	DWORD u63ba[6];
	BYTE u63d2[2];
	DWORD nUnselectableVariable; //63d4h
	ResRef voiceset; //from CRE entry in GAM file
	DWORD u63e0; //m_bStoneSkin?
	DWORD u63e4;
	DWORD u63e8;
	DWORD u63ec;
	DWORD u63f0;
	DWORD u63f4;
	DWORD u63f8;
	WORD u63fc; //contains an actionOpcode (a dialoge or escape area action?)
	DWORD u63fe; //assoc actions
	DWORD u6402; //assoc actions
	DWORD u6406;
	DWORD u640a;
	WORD u640e;
	WORD u6410;
	BOOL bUseCurrentState; //0x6412, 0 = uses prevState, 1 = uses currentState
	WORD u6416;
	DWORD u6418;
	DWORD u641c;
	CVariableArray* pLocalVariables; //6420h
	DWORD u6424; //1 when CRE copied over, 0 at constructor end
	CPtrList ProtectedSpls; //6428h, Size 1Ch objects, DW nPower, DW nOpcodeEffect, CProjectile*, DW, STRREF, DW, DW
	DWORD u6444;
	DWORD u6448;
	DWORD u644c;
	DWORD u6450; //contains enum of CVisualEffect
	DWORD u6454;
	DWORD u6458;
	CScript* pDream; //645ch
	CGameDialog u6460; //loaded when player having a dialogue with me
	CGameDialog u64c4;
	WORD u6528;
	DWORD u652a;
	DWORD u652e;
	IECString u6532;
	IECString u6536;
	IECString u653a;
	IECString u653e;
	WORD u6542;
	DWORD u6544; //bitflag
	CreFileMemSpellLevel memInfoWizardCopy[9]; //0x6548, copied from currentState after effect applied
	CreFileMemSpellLevel memInfoPriestCopy[7]; //0x65d8, copied from currentState after effect applied
	DWORD u6648;
	BYTE u664c;
	BYTE u664d; //padding?
	DWORD u664e;
	CDwordList u6652;
	CPtrList u666e;
	BOOL bInStore; //668ah, prevents party required area transitions
	DWORD u668e;
	DWORD u6692;
	DWORD u6696; //assoc actions
	DWORD u669a;
	DWORD u669e;
	DWORD u66a2;
	DWORD u66a6;
	DWORD u66aa;
	CPtrList u66ae;
	DWORD u66ca[2];
	_8DF1F2 u66d2;
	DWORD u6722;
	DWORD nDamageTaken; //6726h
	DWORD u672a;
	DWORD u672e;
	BYTE u6732; //default = 14 (AACF46), how far you can see?, when retrieved * 32
	BYTE u6733; //padding?
	BOOL u6734; //play animSound battle cry?, set to 0 after use
	BOOL u6738; //play animSound selection?, set to 0 after use
	BYTE u673c[9];
	BYTE u6745; //padding?
	DWORD u6746; //assoc actions
	DWORD u674a; //to do with items
	DWORD u674e; //to do with items
	BYTE u6752; //default = 2a; if CRE name does not start with *, will put first character in here; inherits value from GAM (unknown above killXP(chapter), inherits from Actor2E (BYTE)
	BYTE u6753;
	DWORD u6754[7];
	DWORD u6770;
};

extern CreFileKnownSpell& (CCreatureObject::*CCreatureObject_GetKnownSpellPriest)(DWORD, DWORD);
extern CreFileKnownSpell& (CCreatureObject::*CCreatureObject_GetKnownSpellMage)(DWORD, DWORD);
extern CreFileKnownSpell& (CCreatureObject::*CCreatureObject_GetKnownSpellInnate)(DWORD, DWORD);
extern CreFileMemSpell& (CCreatureObject::*CCreatureObject_GetMemSpellPriest)(DWORD, DWORD);
extern CreFileMemSpell& (CCreatureObject::*CCreatureObject_GetMemSpellMage)(DWORD, DWORD);
extern CreFileMemSpell& (CCreatureObject::*CCreatureObject_GetMemSpellInnate)(DWORD, DWORD);
extern BOOL (CCreatureObject::*CCreatureObject_AddMemSpellPriest)(DWORD, DWORD, DWORD*);
extern BOOL (CCreatureObject::*CCreatureObject_AddMemSpellMage)(DWORD, DWORD, DWORD*);
extern BOOL (CCreatureObject::*CCreatureObject_AddMemSpellInnate)(DWORD, DWORD, DWORD*);

#endif //OBJCRE_H
