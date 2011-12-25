#ifndef OBJSTATS_H
#define OBJSTATS_H

#include "stdafx.h"
#include "resref.h"
#include "effcore.h"
#include "itmcore.h"
#include "scrcore.h"

struct CConditionalSpell { //Size 204h
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

class CRepeatingEffList : public IECPtrList { //20h
public:
	//AA65A0
	int nTicksElapsed; //1ch
};

struct CSpellProtection { //Size Ch
	ResRef rSpell; //0h
	STRREF strrefMsg; //08h
};

class CSpellProtectionList : public IECPtrList {
public:
	//AA65C4
};

struct CStatModVsObject { //Size 18h
	Object o; //0h
	int nModAmount; //14h
};


class CStatModVsObjectList : public IECPtrList { //Size 1Ch
	//AA65F4
};

struct CDerivedStatsTemplate { //Size 2B0h
	unsigned int stateFlags; //0h

	//stats 1-200
	short maxHP; //4h
	short ACEffective; //6h
	short ACCrushingMod; //8h
	short ACMissileMod; //ah
	short ACPiercingMod; //ch
	short ACSlashingMod; //eh
	short THAC0; //10h
	short numAttacks;
	short saveDeath;
	short saveWands;
	short savePolymorph;
	short saveBreath;
	short saveSpells; //1ch
	short resistFire; //1eh
	short resistCold; //20h
	short resistElectricity; //22h
	short resistAcid; //24h
	short resistMagic; //26h
	short resistMagicFire;
	short resistMagicCold;
	short resistSlashing; //2ch
	short resistCrushing; //2eh
	short resistPiercing; //30h
	short resistMissile;
	short lore;
	short lockpicking;
	short stealth;
	short findTraps;
	short pickPockets;
	short fatigue;
	short intoxication; //40h
	short luck; //42h
	short tracking; //44h
	short levelPrimary; //46h
	short levelSecondary;
	short levelTertiary;
	short sex;
	short strength; //4eh
	short strengthEx; //50h
	short intelligence; //52h
	short wisdom; //54h
	short dexterity; //56h
	short constitution; //58h
	short charisma; //5ah
	int XPWorth; //5ch
	int currentXP; //60h
	int gold;
	int morale;
	int reputation;
	short moraleBreak; //70h
	short racialEnemy; //72h
	int hideInShadows;
	int detectIllusion;
	int setTraps;
	short damageBonus; //80h
	short spellFailMage; //82h
	short spellFailPriest; //84h
	short spellDurationModMage; //86h
	short spellDurationModPriest; //88h
	short turnUndeadLevel; //8ah, priestLevel
	short m_BackstabDamageMultiplier; //8ch, backstabMod
	short layOnHandsAmount; //8eh
	int held; //90h
	int polymorph; //94h
	int identifyMode; //98h
	int entangle; //9ch
	int sanctuary; //a0h
	int minorGlobe; //a4h
	int shieldGlobe; //a8h
	int grease; //ach
	int web; //b0h
	int casterHold; //b4h, pause
	short translucent; //b8h
	short encumberance; //bah
	short missileToHitBonus; //bch
	short magicResistance; //beh
	short resistPoison; //c0h
	int doNotJump; //c2h - i.e. will not jump coordinates to search map allowable position
	int auraCleansing; //c6h
	short mentalSpeed; //cah
	short physicalSpeed; //cch
	short castinglevelbonusmage; //ceh
	short castinglevelbonuscleric; //d0h
	int seeInvisible; //d2h
	int ignoreDialoguPause; //d6h
	int minHitPoints; //dah, 1 = immune to opcode instant death
	int toHitBonusRight; //deh
	int toHitBonusLeft; //e2h
	int damageBonusRight; //e6h
	int damageBonusLeft; //eah
	int m_nStoneSkins; //eeh
	int proficiencies[46]; //f2h
	Enum puppermasterId; //1aah
	int puppermasterType; //1aeh
	int puppetType; //1b2h
	Enum puppetId; //1b6h
	int checkForBerserk; //1bah
	int berserkStage1; //1beh
	int berserkStage2; //1c2h
	int damageLuck; //1c6h
	ResRef BardSongEffect; //1cah
	int criticalHitBonus; //1d2h
	int visualRange; //1d6h
	int explore; //1dah
	int thrullCharm; //1deh
	int summonDisable; //1e2h
	int avatarRemoval; //1e6h
	short hitBonus; //1eah
	unsigned short kit[2];
	int forceSurge; //1f0h
	int surgeMod; //1f4h
	int improvedHaste; //1f8h
	int u1fc;
	int u200;
	int u204;
	int u208;
	int u20c;
	int u210;
	int u214;
	int u218;
	int u21c;
	int u220; //220h
	int meleeTHAC0Mod; //224h
	int meleeDamageMod; //228h
	int missileDamageMod; //22ch
	int hideSelectionCircle; //230h
	int firstTHAC0Mod; //234h
	int firstDamageMod; //238h
	STRREF title0; //23ch
	STRREF title1; //240h
	int disableVisualEffect; //244h
	int m_BackstabImmunity; //248h
	int openLocks9; //24ch
	int moveSilently9; //250h
	int findTraps9; //254h
	int pickPockets9; //258h
	int hideInShadows9; //25ch
	int detectIllusions9; //260h
	int setTraps9; //264h
	int offscreenAI; //268h
	int existanceSoundChance; //26ch
	int speedHasteWithoutAttackBonuses; //270h
	int disablePermanentDeath; //274h
	int immunityTurnUndead; //278h
	int chaosShield; //27ch
	int npcBump; //280h
	int useAnyItem; //284h
	int m_BackstabEveryHit; //288h
	int reverseGender; //28ch
	int spellFailInnate; //290h
	int immunityTracking; //294h
	int deadMagic; //298h
	int immunityTimeStop; //29ch
	int u2a0;
	int m_StoneSkinGolem; //2a4h, immune to poison and display special effect icon?
	int levelDrain; //2a8h
	int animationRemoval; //2ach
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
	short GetStat(int index);
	void LoadStats(CDerivedStatsTemplate& cds, int nSize);
	char GetEffectiveClericLevel(unsigned char nClass);
	char GetEffectiveMageLevel(unsigned char nClass);

	IECPtrList ProtProjId; //2b0h, AA6624, holds DWORDS of PROJECTL.IDS Idx
	IECPtrList ProtEff; //2cch, AA6618, CEffects
	CObjectList m_ObjectProtections; //2e8h
	int ProtSplLvl[10]; //304h
	CItemPropertiesList m_WeaponProtections; //32ch
	CStatModVsObjectList m_ToHitBonusVsObject; //348h
	CStatModVsObjectList m_DamageBonusVsObject; //364h
	COnEquipItemList m_ForbidItems; //380h
	COnEquipItemtypeList m_ForbidItemTypes; //39ch
	COnEquipItemList ApplyEffOnEquipItem; //3b8h, added by effect 182 but not used
	COnEquipItemtypeList ApplyEffOnEquipItemType; //3d4h, added by effect 183 but not used
	IECPtrList BounceProjId; //3f0h, AA6624
	IECPtrList BounceEff; //40ch, AA6618, CEffect
	BOOL BounceSplLvl[10]; //428h, if 1 for a level, is affected by that power level
	long long BounceSplLvlDec[10]; //450h
	long long ProtSplLvlDec[10]; //4a0h

	//group of 14
	IECPtrList ProtTypePrimary; //4f0h, AA65D0
	IECPtrList ProtTypeSecondary; //50ch, AA65D0
	IECPtrList BounceTypePrimary; //528h, AA65D0
	IECPtrList BounceTypeSecondary; //544h, AA65D0
	COnEquipItemList ForbidItem2; //560h, objects in this list never used
	COnEquipItemtypeList ForbidItemType2; //57ch, objects in this list never used
	CSpellProtectionList m_SpellProtections; //598h
	IECPtrList BounceSpl; //5b4h, AA65C4
	IECPtrList ImmuneTypePrimaryDec; //5d0h, AA65B8
	IECPtrList ImmuneTypeSecondaryDec; //5ech, AA65B8
	IECPtrList BounceTypePrimaryDec; //608h, AA65B8
	IECPtrList BounceTypeSecondaryDec; //624h, AA65B8
	CConditionalSpellList m_ConditionalSpells; //640h
	CRepeatingEffList m_RepeatingEffs; //65ch

	long long SplLvlTrap[10]; //67ch
	IECPtrList SplSequencer; //6cch, AA65AC
	IECPtrList ColorListPal; //6e8h, AA6594, item color objects of 0x2?
	IECPtrList ColorListRgb; //704h, AA6588
	CreFileMemSpellLevel MemInfoMage[9]; //720h
	CreFileMemSpellLevel MemInfoPriest[7]; //7b0h

	/*
	0 - stealth
	1 - thieving
	2 - cast spell
	3 - quick spell 1
	4 - quick spell 2
	5 - quick spell 3
	6 - turn undead
	7 - talk
	8 - use item
	9 - quick item 1
	A - nil
	B - quick item 2
	C - quick item 3
	D - special ability
	*/
	int ButtonDisable[14]; //820h
	int ButtonDisableSplPriest; //858h
	int ButtonDisableSplWizard; //85ch
	int ButtonDisableSplInnate; //860h
	IECPtrList MeleeEffects; //864h, AA657C
	IECPtrList RangedEffects; //880h, AA657C
	CStatModVsObjectList m_SaveBonusVsObject; //89ch
};

extern CDerivedStats& (CDerivedStats::*CDerivedStats_Construct_3)(CreFileData&, CreFileMemSpellLevel*, CreFileMemSpellLevel*);
extern CDerivedStats& (CDerivedStats::*CDerivedStats_Construct_0)();
extern void (CDerivedStats::*CDerivedStats_Init)(CreFileData&, CreFileMemSpellLevel*, CreFileMemSpellLevel*);
extern CDerivedStats& (CDerivedStats::*CDerivedStats_OpAssign)(CDerivedStats&);
extern void (CDerivedStats::*CDerivedStats_ClearStats)();
extern CDerivedStats& (CDerivedStats::*CDerivedStats_OpAdd)(CDerivedStats&);
extern void (CDerivedStats::*CDerivedStats_LimitStats)();
extern short (CDerivedStats::*CDerivedStats_GetStat)(int);
extern void (CDerivedStats::*CDerivedStats_LoadStats)(CDerivedStatsTemplate&, int);
extern char (CDerivedStats::*CDerivedStats_GetEffectiveClericLevel)(unsigned char);
extern char (CDerivedStats::*CDerivedStats_GetEffectiveMageLevel)(unsigned char);

#endif //OBJSTATS_H