#ifndef OBJSTATS_H
#define OBJSTATS_H

#include "stdafx.h"
#include "resref.h"
#include "effcore.h"
#include "itmcore.h"
#include "scrcore.h"

#define CDERIVEDSTATS_BUTTONDISABLE_STEALTH		0
#define CDERIVEDSTATS_BUTTONDISABLE_THIEVING	1
#define CDERIVEDSTATS_BUTTONDISABLE_CASTSPELL	2
#define CDERIVEDSTATS_BUTTONDISABLE_QUICKSPELL1	3
#define CDERIVEDSTATS_BUTTONDISABLE_QUICKSPELL2	4
#define CDERIVEDSTATS_BUTTONDISABLE_QUICKSPELL3	5
#define CDERIVEDSTATS_BUTTONDISABLE_TURNUNDEAD	6
#define CDERIVEDSTATS_BUTTONDISABLE_TALK		7
#define CDERIVEDSTATS_BUTTONDISABLE_USEITEM		8
#define CDERIVEDSTATS_BUTTONDISABLE_QUICKITEM1	9
#define CDERIVEDSTATS_BUTTONDISABLE_BARDSONG	10 //new in TobEx
#define CDERIVEDSTATS_BUTTONDISABLE_QUICKITEM2	11
#define CDERIVEDSTATS_BUTTONDISABLE_QUICKITEM3	12
#define CDERIVEDSTATS_BUTTONDISABLE_ABILITY		13
#define CDERIVEDSTATS_BUTTONDISABLE_FINDTRAPS	14 //new in TobEx

#define CDERIVEDSTATS_BUTTONDISABLESPL_WIZARD	0
#define CDERIVEDSTATS_BUTTONDISABLESPL_PRIEST	1
#define CDERIVEDSTATS_BUTTONDISABLESPL_INNATE	2

typedef IECPtrList COnAttackEffList; //AA657C
typedef IECPtrList CColorPalList; //AA6594
typedef IECPtrList CColorRgbList; //AA6588
typedef IECPtrList CBounceEffList; //AA6618, CEffect elements

struct CConditionalSpell { //Size 204h
	void* operator new (size_t size);
	void operator delete(void* mem);

	Trigger t; //0h
	ResRef rResource1; //2eh, spell 1
	ResRef rResource2; //36h, spell 2
	ResRef rResource3; //3eh, spell 3
	Object oTarget; //46h

	//bit0: add portrait icon 0x4B, display text on contingency fire
	unsigned int dwFlags; //5ah
	CEffect eff; //5eh, copy of the source effect
	STRREF strrefTarget; //1f8h, name of contingency target
	STRREF strrefName; //1fch, name of contingency condition
	int nTicksLastCheck; //200h
};

class CConditionalSpellList : public IECPtrList {
public:
	//AA65AC
	void EvaluateTriggers(CCreatureObject& cre);
};

extern void (CConditionalSpellList::*CConditionalSpellList_EvaluateTriggers)(CCreatureObject&);

struct ColorPal { //Size 2h
	char m_cColorGroup;
	char m_cGroupRangeId;
};

struct COnEquipItem { //Size 10h
	ResRef rItem; //0h
	STRREF strrefMsg; //8h
	CEffect* pEffect; //ch
};

class COnEquipItemList : public IECPtrList { //Size 1Ch
//Constructor: 0x475CE0
	//AA65E8
};

struct COnEquipItemType { //Size Ch
//Constructor: 0x475D10
	//AA65DC
	int nItemType; //0h
	STRREF strrefMsg; //4h
	CEffect* pEffect; //8h
};

class COnEquipItemtypeList : public IECPtrList { //Size 1Ch
};

struct CItemProperties { //Size Eh
//Used for CCreatureObject::ProtWeapMelee
	short wType; //0h
	unsigned int dwFlags; //2h
	int u6;
	int nEnchantment; //ah
};

class CItemPropertiesList : public IECPtrList { //Size 1Ch
//Constructor: 0x475C80
public:
	//AA6600
};

class CObjectList : public IECPtrList { //Size 1Ch
public:
	//AA660C
};

class CRepeatingEffBase { //Size 14h
public:
	CRepeatingEffBase(); //5662C0
	CRepeatingEffBase& Construct() { return *this; } //dummy

	//AA9A1C
	virtual ~CRepeatingEffBase() {} //v0
	virtual void Update(CCreatureObject& cre, int nTicks) {} //v4
	virtual CRepeatingEffBase& Duplicate() { return *this; } //v8

	BOOL bExpired; //4h
	BOOL bPurge; //8h
	short uc;

	//3: Poison
	//4: Disease
	//5: Regeneration, Repeating EFF
	short wType; //eh
	Enum eSource; //10h
};

extern CRepeatingEffBase& (CRepeatingEffBase::*CRepeatingEffBase_Construct)();

class CRepeatingDisease : public CRepeatingEffBase { //26h
public:
	CRepeatingDisease();

	//AA9858
	virtual ~CRepeatingDisease() {} //v0
	virtual void Update(CCreatureObject& cre, int nTicks) {} //v4
	virtual CRepeatingEffBase& Duplicate() { return *this; } //v8

	int nTicksElapsed; //14h, range 0-15, reset to 0 on the second
	
	//0: DAMAGE_ONE_PER_SEC (used for effect types 0 and 1)
	//1: crash
	//2: DAMAGE_AMOUNT_PER_SEC (used for effect type 2)
	//3: DAMAGE_AMOUNT_PER_PERIOD (used for effect types 3)
	short wMode; //18h

	short wPostDelayDuration; //1ah, gets nParam1 for type 0, gets nParam1/100*currentHP for type 2
	short wAmount; //1ch
	short wPeriod; //1eh (apply every wPeriod-th second)
	int nTicksLeft; //20h (gameTime - nDuration)
	short wSecondsElapsed; //24h, range 0-(wPeriod) to determine when to apply for mode 3
};

class CRepeatingEff : public CRepeatingEffBase { //Size 32h
public:
	CRepeatingEff();

	//AA9A1C
	virtual ~CRepeatingEff() {} //v0
	virtual void Update(CCreatureObject& cre, int nTicks); //v4
	virtual CRepeatingEffBase& Duplicate() { return *this; } //v8

	int nTicksElapsed; //14h

	//0: APPLY_ONE_PER_SEC (used for effect type 0)
	//1: crash
	//2: APPLY_AMOUNT_PER_SEC (used for effect type 2)
	//3: APPLY_AMOUNT_PER_PERIOD (used for effect types 3 and 4)
	short wMode; //18h (nParam2)

	short wPostDelayDuration; //1ah, gets nParam1 for type 0
	short wAmount; //1ch
	short wPeriod; //1eh (apply every wPeriod-th round)
	int nTicksLeft; //20h (gameTime - nDuration)
	short wSecondsElapsed; //24h, range 0-(wPeriod) to determine when to apply for mode 3
	ResRef rResource; //26h
	CEffect* pEffect; //2eh
};

extern void (CRepeatingEff::*CRepeatingEff_Update)(CCreatureObject&, int);

class CRepeatingWingBuffet : public CRepeatingEffBase { //Size 2Ah
public:
	CRepeatingWingBuffet();

	//AA9A10
	virtual ~CRepeatingWingBuffet() {} //v0
	virtual void Update(CCreatureObject& cre, int nTicks); //v4
	virtual CRepeatingEffBase& Duplicate() { return *this; } //v8

	int nTicksElapsed; //14h
	short wMode; //18h
	int nDistance; //1ah
	POINT ptOrigin; //1eh
	Enum eOrigin; //26h, trumps ptOrigin if present
};

extern void (CRepeatingWingBuffet::*CRepeatingWingBuffet_Update)(CCreatureObject&, int);

class CRepeatingPoison : public CRepeatingEffBase { //26h
public:
	CRepeatingPoison();

	//AA984C
	virtual ~CRepeatingPoison() {} //v0
	virtual void Update(CCreatureObject& cre, int nTicks) {} //v4
	virtual CRepeatingEffBase& Duplicate() { return *this; } //v8

	int nTicksElapsed; //14h, range 0-15, reset to 0 on the second
	
	//0: DAMAGE_ONE_PER_SEC (used for effect types 0 and 1)
	//1: crash
	//2: DAMAGE_AMOUNT_PER_SEC (used for effect type 2)
	//3: DAMAGE_AMOUNT_PER_PERIOD (used for effect types 3 and 4)
	short wMode; //18h

	short wPostDelayDuration; //1ah, gets nParam1 for type 0, gets nParam1/100*currentHP for type 2
	short wAmount; //1ch
	short wPeriod; //1eh (apply every wPeriod-th second)
	int nTicksLeft; //20h (gameTime - nDuration)
	short wSecondsElapsed; //24h, range 0-(wPeriod) to determine when to apply for mode 3
};

class CRepeatingRegen : public CRepeatingEffBase { //Size 26h
public:
	CRepeatingRegen();

	//AA9864
	virtual ~CRepeatingRegen() {} //v0
	virtual void Update(CCreatureObject& cre, int nTicks) {} //v4
	virtual CRepeatingEffBase& Duplicate() { return *this; } //v8

	int nTicksElapsed; //14h, range 0-15, reset to 0 on the second
	
	//0: REGEN_ONE_PER_SEC (used for effect types 0 and 1)
	//1: crash
	//2: REGEN_AMOUNT_PER_SEC (used for effect type 2)
	//3: REGEN_AMOUNT_PER_PERIOD (used for effect types 3 and 4)
	short wMode; //18h

	short wPostDelayDuration; //1ah, gets nParam1 for type 0, gets nParam1/100*currentHP for type 2
	short wAmount; //1ch
	short wPeriod; //1eh (apply every wPeriod-th second)
	int nTicksLeft; //20h (gameTime - nDuration)
	short wSecondsElapsed; //24h, range 0-(wPeriod) to determine when to apply for mode 3
};

class CRepeatingEffList : public IECPtrList { //Size 20h
public:
	//AA65A0
	int nTicksElapsed; //1ch
};

struct CSpellProtection { //Size Ch
	CSpellProtection();

	ResRef rSpell; //0h
	STRREF strrefMsg; //8h
};

class CSpellProtectionList : public IECPtrList { //Size 1Ch
public:
	//AA65C4
};

struct CStatModVsObject { //Size 18h
	Object o; //0h
	int nModAmount; //14h
};

class CStatModVsObjectList : public IECPtrList { //Size 1Ch
public:
	//AA65F4
	int GetModValue(Object& o);
};

extern int (CStatModVsObjectList::*CStatModVsObjectList_GetModValue)(Object&);

struct SpellLevelDec { //Size 8h
	BOOL bOn; //0h
	int nCount; //4h
};

struct CDerivedStatsTemplate { //Size 2B0h
	unsigned int stateFlags; //0h

	//stats 1-200
	short maxHP; //4h, MAXHITPOINTS (1)
	short ACEffective; //6h, ARMORCLASS (2)
	short ACCrushingMod; //8h, ACCRUSHINGMOD (3)
	short ACMissileMod; //ah, ACMISSILEMOD (4)
	short ACPiercingMod; //ch, ACPIERCINGMOD (5)
	short ACSlashingMod; //eh, ACSLASHINGMOD (6)
	short THAC0; //10h, THAC0 (7)
	short numAttacks; //12h, NUMBEROFATTACKS (8)
	short saveDeath; //14h, SAVEVSDEATH (9)
	short saveWands; //16h, SAVEVSWANDS (10)
	short savePoly; //18h, SAVEVSPOLY (11)
	short saveBreath; //1ah, SAVEVSBREATH (12)
	short saveSpell; //1ch, SAVEVSSPELL (13)
	short resistFire; //1eh, RESISTFIRE (14)
	short resistCold; //20h, RESISTCOLD (15)
	short resistElectricity; //22h, RESISTELECTRICITY
	short resistAcid; //24h, RESISTACID
	short resistMagic; //26h, RESISTMAGIC
	short resistMagicFire; //28h, RESISTMAGICFIRE
	short resistMagicCold; //2ah, RESISTMAGICCOLD (20)
	short resistSlashing; //2ch, RESISTSLASHING
	short resistCrushing; //2eh, RESISTCRUSHING
	short resistPiercing; //30h, RESISTPIERCING
	short resistMissile; //32h, RESISTMISSILE
	short lore; //34h, LORE
	short lockpicking; //36h, LOCKPICKING
	short stealth; //38h, STEALTH
	short findTraps; //3ah, TRAPS
	short pickPockets; //3ch, PICKPOCKET
	short fatigue; //3eh, FATIGUE (30)
	short intoxication; //40h, INTOXICATION
	short luck; //42h, LUCK
	short tracking; //44h, TRACKING
	short levelPrimary; //46h, LEVEL (34)
	short levelSecondary; //48h, LEVEL2 (68)
	short levelTertiary; //4ah, LEVEL3 (69)
	short sex; //4ch, SEX (35)
	short strength; //4eh, STR
	short strengthEx; //50h, STREXTRA
	short intelligence; //52h, INT
	short wisdom; //54h, WIS
	short dexterity; //56h, DEX (40)
	short constitution; //58h, CON
	short charisma; //5ah, CHR
	int XPWorth; //5ch, XPVALUE
	int currentXP; //60h, XP
	int gold; //64h, GOLD
	int moraleBreak; //68h, MORALEBREAK
	int moraleRecovery; //6ch, MORALERECOVERYTIME
	short reputation; //70h, REPUTATION
	short racialEnemy; //72h, HATEDRACE (49)
	int hideInShadows; //74h, HIDEINSHADOWS (135)
	int detectIllusion; //78h, DETECTILLUSIONS (136)
	int setTraps; //7ch, SETTRAPS (137)
	short damageBonus; //80h, DAMAGEBONUS (50)
	short spellFailMage; //82h, SPELLFAILUREMAGE
	short spellFailPriest; //84h, SPELLFAILUREPRIEST
	short spellDurationModMage; //86h, SPELLDURATIONMODMAGE
	short spellDurationModPriest; //88h, SPELLDURATIONMODPRIEST
	short turnUndeadLevel; //8ah, TURNUNDEADLEVEL, priestLevel
	short m_BackstabDamageMultiplier; //8ch, BACKSTABDAMAGEMULTIPLIER, backstabMod
	short layOnHandsAmount; //8eh, LAYONHANDSAMOUNT
	int held; //90h, HELD
	int polymorph; //94h, POLYMORPHED (59)
	int identifyMode; //98h, IDENTIFYMODE (61)
	int entangle; //9ch, ENTANGLE (62)
	int sanctuary; //a0h, SANCTUARY (63)
	int minorGlobe; //a4h, MINORGLOBE (64)
	int shieldGlobe; //a8h, SHIELDGLOBE (65)
	int grease; //ach, GREASE (66)
	int web; //b0h, WEB (67)
	int casterHold; //b4h, CasterHold, pause (70)
	short translucent; //b8h, TRANSLUCENT (60)
	short encumberance; //bah, ENCUMBERANCE (71)
	short missileToHitBonus; //bch, MISSILETHAC0BONUS (72)
	short resistMagicDamage; //beh, MAGICDAMAGERESISTANCE (73)
	short resistPoison; //c0h, RESISTPOISON (74)
	int doNotJump; //c2h, DONOTJUMP, i.e. will not jump coordinates to search map allowable position
	int auraCleansing; //c6h, AURACLEANSING
	short mentalSpeed; //cah, MENTALSPEED
	short physicalSpeed; //cch, PHYSICALSPEED
	short castinglevelbonusmage; //ceh, CASTINGLEVELBONUSMAGE
	short castinglevelbonuscleric; //d0h, CASTINGLEVELBONUSCLERIC
	int seeInvisible; //d2h, SEEINVISIBLE
	int ignoreDialogPause; //d6h, IGNOREDIALOGPAUSE
	int minHitPoints; //dah, MINHITPOINTS, 1 = immune to opcode instant death
	int toHitBonusRight; //deh, THAC0BONUSRIGHT
	int toHitBonusLeft; //e2h, THAC0BONUSLEFT
	int damageBonusRight; //e6h, DAMAGEBONUSRIGHT
	int damageBonusLeft; //eah, DAMAGEBONUSLEFT
	int m_nStoneSkins; //eeh, STONESKINS
	int proficiencyBastardSword; //f2h, PROFICIENCYBASTARDSWORD (89)
	int proficiencyLongSword; //f6h, PROFICIENCYLONGSWORD (90)
	int proficiencyShortSword; //fah, PROFICIENCYSHORTSWORD (91)
	int proficiencyAxe; //feh, PROFICIENCYAXE (92)
	int proficiencyTwoHandedSword; //102h, PROFICIENCYTWOHANDEDSWORD (93)
	int proficiencyKatana; //106h, PROFICIENCYKATANA (94)
	int proficiencyScimitarWakizashiNinjato; //10ah, PROFICIENCYSCIMITARWAKISASHININJATO (95)
	int proficiencyDagger; //10eh, PROFICIENCYDAGGER (96)
	int proficiencyWarhammer; //112h, PROFICIENCYWARHAMMER (97)
	int proficiencySpear; //116h, PROFICIENCYSPEAR (98)
	int proficiencyHalberd; //11ah, PROFICIENCYHALBERD (99)
	int proficiencyFlailMorningstar; //11eh, PROFICIENCYFLAILMORNINGSTAR (100)
	int proficiencyMace; //122h, PROFICIENCYMACE (101)
	int proficiencyQuarterstaff; //126h, PROFICIENCYQUARTERSTAFF (102)
	int proficiencyCrossbow; //12ah, PROFICIENCYCROSSBOW (103)
	int proficiencyLongbow; //12eh, PROFICIENCYLONGBOW (104)
	int proficiencyShortbow; //132h, PROFICIENCYSHORTBOW (105)
	int proficiencyDart; //136h, PROFICIENCYDART (106)
	int proficiencySling; //13ah, PROFICIENCYSLING (107)
	int proficiencyBlackjack; //13eh, PROFICIENCYBLACKJACK (108)
	int proficiencyGun; //142h, PROFICIENCYGUN (109)
	int proficiencyMartialArts; //146h, PROFICIENCYMARTIALARTS (110)
	int proficiencyTwoHanded; //14ah, PROFICIENCY2HANDED (111)
	int proficiencySwordAndShield; //14eh, PROFICIENCYSWORDANDSHIELD (112)
	int proficiencySingleWeapon; //152h, PROFICIENCYSINGLEWEAPON (113)
	int proficiencyTwoWeapon; //156h, PROFICIENCY2WEAPON (114)
	int proficiencyExtra1; //15ah, EXTRAPROFICIENCY1 (115)
	int proficiencyExtra2; //15eh, EXTRAPROFICIENCY2 (116)
	int proficiencyExtra3; //162h, EXTRAPROFICIENCY3 (117)
	int proficiencyExtra4; //166h, EXTRAPROFICIENCY4 (118)
	int proficiencyExtra5; //16ah, EXTRAPROFICIENCY5 (119)
	int proficiencyExtra6; //16eh, EXTRAPROFICIENCY6 (120)
	int proficiencyExtra7; //172h, EXTRAPROFICIENCY7 (121)
	int proficiencyExtra8; //176h, EXTRAPROFICIENCY8 (122)
	int proficiencyExtra9; //17ah, EXTRAPROFICIENCY9 (123)
	int proficiencyExtra10; //17eh, EXTRAPROFICIENCY10 (124)
	int proficiencyExtra11; //182h, EXTRAPROFICIENCY11 (125)
	int proficiencyExtra12; //186h, EXTRAPROFICIENCY12 (126)
	int proficiencyExtra13; //18ah, EXTRAPROFICIENCY13 (127)
	int proficiencyExtra14; //18eh, EXTRAPROFICIENCY14 (128)
	int proficiencyExtra15; //192h, EXTRAPROFICIENCY15 (129)
	int proficiencyExtra16; //196h, EXTRAPROFICIENCY16 (130)
	int proficiencyExtra17; //19ah, EXTRAPROFICIENCY17 (131)
	int proficiencyExtra18; //19eh, EXTRAPROFICIENCY18 (132)
	int proficiencyExtra19; //1a2h, EXTRAPROFICIENCY19 (133)
	int proficiencyExtra20; //1a6h, EXTRAPROFICIENCY20 (134)
	Enum puppermasterId; //1aah, PUPPETMASTERID
	int puppermasterType; //1aeh, PUPPETMASTERTYPE, 1 or 2
	int puppetType; //1b2h, PUPPETTYPE
	Enum puppetId; //1b6h, PUPPETID
	int checkForBerserk; //1bah, CHECKFORBERSERK
	int berserkStage1; //1beh, BERSERKSTAGE1
	int berserkStage2; //1c2h, BERSERKSTAGE2
	int damageLuck; //1c6h, DAMAGELUCK
	ResRef BardSongEffect; //1cah
	int criticalHitBonus; //1d2h, CRITICALHITBONUS
	int visualRange; //1d6h, VISUALRANGE
	int explore; //1dah, EXPLORE
	int thrullCharm; //1deh, THRULLCHARM
	int summonDisable; //1e2h, SUMMONDISABLE
	int avatarRemoval; //1e6h (188)
	short hitBonus; //1eah, HITBONUS
	unsigned int kit; //1ec, KIT
	int forceSurge; //1f0h, FORCESURGE
	int surgeMod; //1f4h, SURGEMOD
	int improvedHaste; //1f8h, IMPROVEDHASTE
	int scriptingState1; //1fch, SCRIPTINGSTATE1
	int scriptingState2; //200h, SCRIPTINGSTATE2
	int scriptingState3; //204h, SCRIPTINGSTATE3
	int scriptingState4; //208h, SCRIPTINGSTATE4
	int scriptingState5; //20ch, SCRIPTINGSTATE5
	int scriptingState6; //210h, SCRIPTINGSTATE6
	int scriptingState7; //214h, SCRIPTINGSTATE7
	int scriptingState8; //218h, SCRIPTINGSTATE8
	int scriptingState9; //21ch, SCRIPTINGSTATE9
	int scriptingState10; //220h, SCRIPTINGSTATE10 (165)
	int meleeTHAC0Mod; //224h, MELEETHAC0MOD (166)
	int meleeDamageMod; //228h, MELEEDAMAGE (167)
	int missileDamageMod; //22ch, MISSILEDAMAGE (168)
	int hideSelectionCircle; //230h, NOCIRCLE (169)
	int fistTHAC0Mod; //234h, FISTTHAC0 (170)
	int fistDamageMod; //238h, FISTDAMAGE (171)
	STRREF title0; //23ch, TITLE1 (172)
	STRREF title1; //240h, TITLE2 (173)
	int disableVisualEffect; //244h, DISABLEOVERLAY (174)
	int m_BackstabImmunity; //248h, DISABLEBACKSTAB (175)
	int openLocks9; //24ch, LOCKPICKINGCP (176)
	int moveSilently9; //250h, STEALTHCP (177)
	int findTraps9; //254h, TRAPSCP (178)
	int pickPockets9; //258h, PICKPOCKETCP (179)
	int hideInShadows9; //25ch, HIDEINSHADOWSCP (180)
	int detectIllusions9; //260h, DETECTILLUSIONSCP (181)
	int setTraps9; //264h, SETTRAPSCP (182)
	int offscreenAI; //268h, ENABLEOFFSCREENAI (183)
	int existanceSoundChance; //26ch, EXISTANCESOUND (184)
	int speedHasteWithoutAttackBonuses; //270h, HASTE (185)
	int disablePermanentDeath; //274h, DISABLECHUNKYDEATH (186)
	int immunityTurnUndead; //278h, DISABLETURNUNDEAD (187)
	int chaosShield; //27ch, CHAOSSHIELD (189)
	int npcBump; //280h, NPCBUMP (190)
	int useAnyItem; //284h, CANUSEANYITEM (191)
	int m_BackstabEveryHit; //288h, ALWAYSBACKSTAB (192)
	int reverseGender; //28ch, SEXCHANGE (193)
	int spellFailInnate; //290h, SPELLFAILUREINNATE (194)
	int immunityTracking; //294h, DISABLETRACKING (195)
	int deadMagic; //298h, DEADMAGIC (196)
	int immunityTimeStop; //29ch, DISABLETIMESTOP (197)
	int freedom; //2a0h, FREEDOM (198)
	int m_StoneSkinGolem; //2a4h, STONESKINGOLEM (199), immune to poison and display special effect icon?
	int levelDrain; //2a8h, LEVELDRAIN (200)
	int animationRemoval; //2ach, ANIMATIONREMOVAL (201)
};

struct CDerivedStats : public CDerivedStatsTemplate { //Size 8B8h
	CDerivedStats(CreFileData& stats, CreFileMemSpellLevel* memArrayMage, CreFileMemSpellLevel* memArrayPriest);
	CDerivedStats& Construct(CreFileData&, CreFileMemSpellLevel*, CreFileMemSpellLevel*) { return *this; } //dummy

	CDerivedStats(); //46D1B2
	CDerivedStats& Construct() { return *this; } //dummy

	void Init(CreFileData& stats, CreFileMemSpellLevel* memArrayMage, CreFileMemSpellLevel* memArrayPriest);
	
	CDerivedStats& operator=(CDerivedStats& cds);
	CDerivedStats& OpAssign(CDerivedStats&) { return *this; } //dummy

	void ClearStats();
	
	CDerivedStats& operator+(CDerivedStats& cds);
	CDerivedStats& OpAdd(CDerivedStats&) { return *this; } //dummy

	void LimitStats();
	int GetStat(short nOpcode);
	char GetSubclassLevel(char nClass, char nSubclass);
	short GetMeanLevel(char nClass);
	unsigned char GetFighterClassLevel(unsigned char cClass);
	unsigned char GetMageClassLevel(unsigned char cClass);
	unsigned char GetThiefClassLevel(unsigned char cClass);
	unsigned char GetClericClassLevel(unsigned char cClass);
	void MarshalTemplate(CDerivedStatsTemplate** ppcdst, int* pnSize);
	void UnmarshalTemplate(CDerivedStatsTemplate& cds, int nSize);
	char GetEffectiveClericLevel(unsigned char nClass);
	char GetEffectiveMageLevel(unsigned char nClass);

	~CDerivedStats();
	void Deconstruct() { return; } //dummy

	IECPtrList ProtProjId; //2b0h, AA6624, holds DWORDS of PROJECTL.IDS Idx
	IECPtrList ProtEff; //2cch, AA6618, CEffects
	CObjectList m_ObjectProtections; //2e8h
	BOOL ProtSplLvl[10]; //304h
	CItemPropertiesList m_WeaponProtections; //32ch
	CStatModVsObjectList m_ToHitBonusVsObject; //348h
	CStatModVsObjectList m_DamageBonusVsObject; //364h
	COnEquipItemList m_ForbidItems; //380h
	COnEquipItemtypeList m_ForbidItemTypes; //39ch
	COnEquipItemList ApplyEffOnEquipItem; //3b8h, added by effect 182 but not used
	COnEquipItemtypeList ApplyEffOnEquipItemType; //3d4h, added by effect 183 but not used
	IECPtrList BounceProjId; //3f0h, AA6624
	CBounceEffList BounceEff; //40ch
	BOOL BounceSplLvl[10]; //428h, if 1 for a level, is affected by that power level
	SpellLevelDec BounceSplLvlDec[10]; //450h
	SpellLevelDec ProtSplLvlDec[10]; //4a0h

	//group of 14
	IECPtrList ProtTypePrimary; //4f0h, AA65D0
	IECPtrList ProtTypeSecondary; //50ch, AA65D0
	IECPtrList BounceTypePrimary; //528h, AA65D0
	IECPtrList BounceTypeSecondary; //544h, AA65D0
	COnEquipItemList ForbidItem2; //560h, objects in this list never used
	COnEquipItemtypeList ForbidItemType2; //57ch, objects in this list never used
	CSpellProtectionList m_SpellProtections; //598h
	IECPtrList BounceSpl; //5b4h, AA65C4
	IECPtrList ProtTypePrimaryDec; //5d0h, AA65B8
	IECPtrList ProtTypeSecondaryDec; //5ech, AA65B8
	IECPtrList BounceTypePrimaryDec; //608h, AA65B8
	IECPtrList BounceTypeSecondaryDec; //624h, AA65B8
	CConditionalSpellList m_ConditionalSpells; //640h
	CRepeatingEffList m_RepeatingEffs; //65ch

	SpellLevelDec SplTrapLvl[10]; //67ch
	IECPtrList SplSequencer; //6cch, AA65AC
	CColorPalList ColorListPal; //6e8h, size 0x2 objects (byte cColorGroup [location], byte cGroupRangeId [gradient])
	CColorRgbList ColorListRgb; //704h, size 0x8 objects (byte cColorGroup, byte cGroupRangeId, ARGB rgbColor, byte n, byte pad)
	CreFileMemSpellLevel MemInfoMage[9]; //720h
	CreFileMemSpellLevel MemInfoPriest[7]; //7b0h

	int ButtonDisable[14]; //820h
	int ButtonDisableSpl[3]; //858h
	COnAttackEffList m_MeleeEffects; //864h, is checked on non-ranged attack, but FX never added to this list
	COnAttackEffList m_RangedEffects; //880h, is checked on ranged attack, but FX never added to this list
	CStatModVsObjectList m_SaveBonusVsObject; //89ch
};

extern CDerivedStats& (CDerivedStats::*CDerivedStats_Construct_3)(CreFileData&, CreFileMemSpellLevel*, CreFileMemSpellLevel*);
extern CDerivedStats& (CDerivedStats::*CDerivedStats_Construct_0)();
extern void (CDerivedStats::*CDerivedStats_Init)(CreFileData&, CreFileMemSpellLevel*, CreFileMemSpellLevel*);
extern CDerivedStats& (CDerivedStats::*CDerivedStats_OpAssign)(CDerivedStats&);
extern void (CDerivedStats::*CDerivedStats_ClearStats)();
extern CDerivedStats& (CDerivedStats::*CDerivedStats_OpAdd)(CDerivedStats&);
extern void (CDerivedStats::*CDerivedStats_LimitStats)();
extern int (CDerivedStats::*CDerivedStats_GetStat)(short);
extern char (CDerivedStats::*CDerivedStats_GetSubclassLevel)(char, char);
extern short (CDerivedStats::*CDerivedStats_GetMeanLevel)(char);
extern unsigned char (CDerivedStats::*CDerivedStats_GetFighterClassLevel)(unsigned char);
extern unsigned char (CDerivedStats::*CDerivedStats_GetMageClassLevel)(unsigned char);
extern unsigned char (CDerivedStats::*CDerivedStats_GetThiefClassLevel)(unsigned char);
extern unsigned char (CDerivedStats::*CDerivedStats_GetClericClassLevel)(unsigned char);
extern void (CDerivedStats::*CDerivedStats_MarshalTemplate)(CDerivedStatsTemplate**, int*);
extern void (CDerivedStats::*CDerivedStats_UnmarshalTemplate)(CDerivedStatsTemplate&, int);
extern char (CDerivedStats::*CDerivedStats_GetEffectiveClericLevel)(unsigned char);
extern char (CDerivedStats::*CDerivedStats_GetEffectiveMageLevel)(unsigned char);
extern void (CDerivedStats::*CDerivedStats_Deconstruct)();

#endif //OBJSTATS_H