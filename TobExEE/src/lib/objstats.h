//TobExEE
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

struct CConditionalSpell { //Size 204h, FIX_ME
	DEFINE_MEMALLOC_FUNC;

	Trigger m_t; //0h
	ResRef m_rResource1; //2eh, spell 1
	ResRef m_rResource2; //36h, spell 2
	ResRef m_rResource3; //3eh, spell 3
	Object m_oTarget; //46h

	//bit0: add portrait icon 0x4B, display text on contingency fire
	unsigned int m_dwFlags; //5ah
	CEffect m_eff; //5eh, copy of the source effect
	STRREF m_strrefTarget; //1f8h, name of contingency target
	STRREF m_strrefCondition; //1fch, name of contingency condition
	int m_nTicksLastCheck; //200h
};

class CConditionalSpellList : public IECPtrList { //Size 1Ch, FIX_ME
public:
};

struct ColorPal { //Size 2h, FIX_ME
	char m_cColorGroup;
	char m_cGroupRangeId;
};

struct COnEquipItem { //Size 10h, FIX_ME
	ResRef m_rItem; //0h
	STRREF m_strrefMsg; //8h
	CEffect* m_pEffect; //ch
};

class COnEquipItemList : public IECPtrList { //Size 1Ch, FIX_ME
};

struct COnEquipItemType { //Size Ch, FIX_ME
	int m_nItemType; //0h
	STRREF m_strrefMsg; //4h
	CEffect* m_pEffect; //8h
};

class COnEquipItemtypeList : public IECPtrList { //Size 1Ch, FIX_ME
};

struct CItemProperties { //Size Eh, FIX_ME
//Used for CCreatureObject::ProtWeapMelee
	short m_wType; //0h
	unsigned int m_dwFlags; //2h
	int u6;
	int m_nEnchantment; //ah
};

class CItemPropertiesList : public IECPtrList { //Size 1Ch, FIX_ME
public:
};

class CObjectList : public IECPtrList { //Size 1Ch, FIX_ME
public:
};

class CRepeatingEffBase { //Size 14h, FIX_ME
public:
	BOOL m_bExpired; //4h
	BOOL m_bPurge; //8h
	short uc;

	//3: Poison
	//4: Disease
	//5: Regeneration, Repeating EFF
	short m_wType; //eh
	ENUM m_eSource; //10h
};

class CRepeatingDisease : public CRepeatingEffBase { //26h, FIX_ME
public:
	int m_nTicksElapsed; //14h, range 0-15, reset to 0 on the second
	
	//0: DAMAGE_ONE_PER_SEC (used for effect types 0 and 1)
	//1: crash
	//2: DAMAGE_AMOUNT_PER_SEC (used for effect type 2)
	//3: DAMAGE_AMOUNT_PER_PERIOD (used for effect types 3)
	short m_wMode; //18h

	short m_wPostDelayDuration; //1ah, gets nParam1 for type 0, gets nParam1/100*currentHP for type 2
	short m_wAmount; //1ch
	short m_wPeriod; //1eh (apply every wPeriod-th second)
	int m_nTicksLeft; //20h (gameTime - nDuration)
	short m_wSecondsElapsed; //24h, range 0-(wPeriod) to determine when to apply for mode 3
};

class CRepeatingEff : public CRepeatingEffBase { //Size 32h, FIX_ME
public:
	int m_nTicksElapsed; //14h

	//0: APPLY_ONE_PER_SEC (used for effect type 0)
	//1: crash
	//2: APPLY_AMOUNT_PER_SEC (used for effect type 2)
	//3: APPLY_AMOUNT_PER_PERIOD (used for effect types 3 and 4)
	short m_wMode; //18h (nParam2)

	short m_wPostDelayDuration; //1ah, gets nParam1 for type 0
	short m_wAmount; //1ch
	short m_wPeriod; //1eh (apply every wPeriod-th round)
	int m_nTicksLeft; //20h (gameTime - nDuration)
	short m_wSecondsElapsed; //24h, range 0-(wPeriod) to determine when to apply for mode 3
	ResRef m_rResource; //26h
	CEffect* m_pEffect; //2eh
};

class CRepeatingWingBuffet : public CRepeatingEffBase { //Size 2Ah, FIX_ME
public:
	int m_nTicksElapsed; //14h
	short m_wMode; //18h
	int m_nDistance; //1ah
	CPoint m_ptOrigin; //1eh
	ENUM m_eOrigin; //26h, trumps ptOrigin if present
};

class CRepeatingPoison : public CRepeatingEffBase { //26h, FIX_ME
public:
	int m_nTicksElapsed; //14h, range 0-15, reset to 0 on the second
	
	//0: DAMAGE_ONE_PER_SEC (used for effect types 0 and 1)
	//1: crash
	//2: DAMAGE_AMOUNT_PER_SEC (used for effect type 2)
	//3: DAMAGE_AMOUNT_PER_PERIOD (used for effect types 3 and 4)
	short m_wMode; //18h

	short m_wPostDelayDuration; //1ah, gets nParam1 for type 0, gets nParam1/100*currentHP for type 2
	short m_wAmount; //1ch
	short m_wPeriod; //1eh (apply every wPeriod-th second)
	int m_nTicksLeft; //20h (gameTime - nDuration)
	short m_wSecondsElapsed; //24h, range 0-(wPeriod) to determine when to apply for mode 3
};

class CRepeatingRegen : public CRepeatingEffBase { //Size 26h, FIX_ME
public:
	int m_nTicksElapsed; //14h, range 0-15, reset to 0 on the second
	
	//0: REGEN_ONE_PER_SEC (used for effect types 0 and 1)
	//1: crash
	//2: REGEN_AMOUNT_PER_SEC (used for effect type 2)
	//3: REGEN_AMOUNT_PER_PERIOD (used for effect types 3 and 4)
	short m_wMode; //18h

	short m_wPostDelayDuration; //1ah, gets nParam1 for type 0, gets nParam1/100*currentHP for type 2
	short m_wAmount; //1ch
	short m_wPeriod; //1eh (apply every wPeriod-th second)
	int m_nTicksLeft; //20h (gameTime - nDuration)
	short m_wSecondsElapsed; //24h, range 0-(wPeriod) to determine when to apply for mode 3
};

class CRepeatingEffList : public IECPtrList { //Size 20h, FIX_ME
public:
	int m_nTicksElapsed; //1ch
};

struct CSpellProtection { //Size Ch, FIX_ME
	ResRef m_rSpell; //0h
	STRREF m_strrefMsg; //8h
};

class CSpellProtectionList : public IECPtrList { //Size 1Ch, FIX_ME
public:
};

struct CStatModVsObject { //Size 18h, FIX_ME
	Object m_o; //0h
	int m_nModAmount; //14h
};

class CStatModVsObjectList : public IECPtrList { //Size 1Ch, FIX_ME
public:
};

struct SpellLevelDec { //Size 8h, FIX_ME
	BOOL m_bOn; //0h
	int m_nCount; //4h
};

struct CDerivedStatsTemplate { //Size 2B4h
	unsigned int m_dwStateFlags; //0h

	//stats 1-200
	short m_wMaxHP; //4h, MAXHITPOINTS (1)
	short m_wACEffective; //6h, ARMORCLASS (2)
	short m_wACCrushingMod; //8h, ACCRUSHINGMOD (3)
	short m_wACMissileMod; //ah, ACMISSILEMOD (4)
	short m_wACPiercingMod; //ch, ACPIERCINGMOD (5)
	short m_wACSlashingMod; //eh, ACSLASHINGMOD (6)
	short m_wTHAC0; //10h, THAC0 (7)
	short m_wNumAttacks; //12h, NUMBEROFATTACKS (8)
	short m_wSaveDeath; //14h, SAVEVSDEATH (9)
	short m_wSaveWands; //16h, SAVEVSWANDS (10)
	short m_wSavePoly; //18h, SAVEVSPOLY (11)
	short m_wSaveBreath; //1ah, SAVEVSBREATH (12)
	short m_wSaveSpell; //1ch, SAVEVSSPELL (13)
	short m_wResistFire; //1eh, RESISTFIRE (14)
	short m_wResistCold; //20h, RESISTCOLD (15)
	short m_wResistElectricity; //22h, RESISTELECTRICITY
	short m_wResistAcid; //24h, RESISTACID
	short m_wResistMagic; //26h, RESISTMAGIC
	short m_wResistMagicFire; //28h, RESISTMAGICFIRE
	short m_wResistMagicCold; //2ah, RESISTMAGICCOLD (20)
	short m_wResistSlashing; //2ch, RESISTSLASHING
	short m_wResistCrushing; //2eh, RESISTCRUSHING
	short m_wResistPiercing; //30h, RESISTPIERCING
	short m_wResistMissile; //32h, RESISTMISSILE
	short m_wLore; //34h, LORE
	short m_wLockpicking; //36h, LOCKPICKING
	short m_wStealth; //38h, STEALTH
	short m_wFindTraps; //3ah, TRAPS
	short m_wPickPockets; //3ch, PICKPOCKET
	short m_wFatigue; //3eh, FATIGUE (30)
	short m_wIntoxication; //40h, INTOXICATION
	short m_wLuck; //42h, LUCK
	short m_wTracking; //44h, TRACKING
	short m_wLevelPrimary; //46h, LEVEL (34)
	short m_wLevelSecondary; //48h, LEVEL2 (68)
	short m_wLevelTertiary; //4ah, LEVEL3 (69)
	short m_wSex; //4ch, SEX (35)
	short m_wStrength; //4eh, STR
	short m_wStrengthEx; //50h, STREXTRA
	short m_wIntelligence; //52h, INT
	short m_wWisdom; //54h, WIS
	short m_wDexterity; //56h, DEX (40)
	short m_wConstitution; //58h, CON
	short m_wCharisma; //5ah, CHR
	int m_nXPWorth; //5ch, XPVALUE
	int m_nCurrentXP; //60h, XP
	int m_nGold; //64h, GOLD
	int m_nMoraleBreak; //68h, MORALEBREAK, range 0-20
	int m_nMoraleRecovery; //6ch, MORALERECOVERYTIME, range 0-UINT_MAX
	short m_wReputation; //70h, REPUTATION
	short m_wRacialEnemy; //72h, HATEDRACE (49)
	int m_nHideInShadows; //74h, HIDEINSHADOWS (135)
	int m_nDetectIllusion; //78h, DETECTILLUSIONS (136)
	int m_nSetTraps; //7ch, SETTRAPS (137)
	short m_wDamageBonus; //80h, DAMAGEBONUS (50)
	short m_wSpellFailMage; //82h, SPELLFAILUREMAGE
	short m_wSpellFailPriest; //84h, SPELLFAILUREPRIEST
	short m_wSpellDurationModMage; //86h, SPELLDURATIONMODMAGE
	short m_wSpellDurationModPriest; //88h, SPELLDURATIONMODPRIEST
	short m_wTurnUndeadLevel; //8ah, TURNUNDEADLEVEL, priestLevel
	short m_wBackstabDamageMultiplier; //8ch, BACKSTABDAMAGEMULTIPLIER, backstabMod
	short m_wLayOnHandsAmount; //8eh, LAYONHANDSAMOUNT
	int m_nHeld; //90h, HELD
	int m_nPolymorph; //94h, POLYMORPHED (59)
	int m_nIdentifyMode; //98h, IDENTIFYMODE (61)
	int m_nEntangle; //9ch, ENTANGLE (62)
	int m_nSanctuary; //a0h, SANCTUARY (63)
	int m_nMinorGlobe; //a4h, MINORGLOBE (64)
	int m_nShieldGlobe; //a8h, SHIELDGLOBE (65)
	int m_nGrease; //ach, GREASE (66)
	int m_nWeb; //b0h, WEB (67)
	int m_nCasterHold; //b4h, CasterHold, pause (70)
	short m_wTranslucent; //b8h, TRANSLUCENT (60)
	short m_wEncumberance; //bah, ENCUMBERANCE (71)
	short m_wMissileToHitBonus; //bch, MISSILETHAC0BONUS (72)
	short m_wResistMagicDamage; //beh, MAGICDAMAGERESISTANCE (73)
	short m_wResistPoison; //c0h, RESISTPOISON (74)

	char pc2[2];

	int m_nDoNotJump; //c4h, DONOTJUMP, i.e. will not jump coordinates to search map allowable position
	int m_nAuraCleansing; //c8h, AURACLEANSING
	short m_wMentalSpeed; //cch, MENTALSPEED
	short m_wPhysicalSpeed; //deh, PHYSICALSPEED
	short m_wCastinglevelbonusmage; //d0h, CASTINGLEVELBONUSMAGE
	short m_wCastinglevelbonuscleric; //d2h, CASTINGLEVELBONUSCLERIC
	int m_nSeeInvisible; //d4h, SEEINVISIBLE
	int m_nIgnoreDialogPause; //d8h, IGNOREDIALOGPAUSE
	int m_nMinHitPoints; //dch, MINHITPOINTS, 1 = immune to opcode instant death
	int m_nToHitBonusRight; //e0h, THAC0BONUSRIGHT
	int m_nToHitBonusLeft; //e4h, THAC0BONUSLEFT
	int m_nDamageBonusRight; //e8h, DAMAGEBONUSRIGHT
	int m_nDamageBonusLeft; //ech, DAMAGEBONUSLEFT
	int m_nStoneSkins; //f0h, STONESKINS
	int m_nProficiencyBastardSword; //f4h, PROFICIENCYBASTARDSWORD (89)
	int m_nProficiencyLongSword; //f8h, PROFICIENCYLONGSWORD (90)
	int m_nProficiencyShortSword; //fch, PROFICIENCYSHORTSWORD (91)
	int m_nProficiencyAxe; //100h, PROFICIENCYAXE (92)
	int m_nProficiencyTwoHandedSword; //104h, PROFICIENCYTWOHANDEDSWORD (93)
	int m_nProficiencyKatana; //108h, PROFICIENCYKATANA (94)
	int m_nProficiencyScimitarWakizashiNinjato; //10ch, PROFICIENCYSCIMITARWAKISASHININJATO (95)
	int m_nProficiencyDagger; //110h, PROFICIENCYDAGGER (96)
	int m_nProficiencyWarhammer; //114h, PROFICIENCYWARHAMMER (97)
	int m_nProficiencySpear; //118h, PROFICIENCYSPEAR (98)
	int m_nProficiencyHalberd; //11ch, PROFICIENCYHALBERD (99)
	int m_nProficiencyFlailMorningstar; //120h, PROFICIENCYFLAILMORNINGSTAR (100)
	int m_nProficiencyMace; //124h, PROFICIENCYMACE (101)
	int m_nProficiencyQuarterstaff; //128h, PROFICIENCYQUARTERSTAFF (102)
	int m_nProficiencyCrossbow; //12ch, PROFICIENCYCROSSBOW (103)
	int m_nProficiencyLongbow; //130h, PROFICIENCYLONGBOW (104)
	int m_nProficiencyShortbow; //134h, PROFICIENCYSHORTBOW (105)
	int m_nProficiencyDart; //138h, PROFICIENCYDART (106)
	int m_nProficiencySling; //13ch, PROFICIENCYSLING (107)
	int m_nProficiencyBlackjack; //140h, PROFICIENCYBLACKJACK (108)
	int m_nProficiencyGun; //144h, PROFICIENCYGUN (109)
	int m_nProficiencyMartialArts; //148h, PROFICIENCYMARTIALARTS (110)
	int m_nProficiencyTwoHanded; //14ch, PROFICIENCY2HANDED (111)
	int m_nProficiencySwordAndShield; //150h, PROFICIENCYSWORDANDSHIELD (112)
	int m_nProficiencySingleWeapon; //154h, PROFICIENCYSINGLEWEAPON (113)
	int m_nProficiencyTwoWeapon; //158h, PROFICIENCY2WEAPON (114)
	int m_nProficiencyExtra1; //15ch, EXTRAPROFICIENCY1 (115)
	int m_nProficiencyExtra2; //160h, EXTRAPROFICIENCY2 (116)
	int m_nProficiencyExtra3; //164h, EXTRAPROFICIENCY3 (117)
	int m_nProficiencyExtra4; //168h, EXTRAPROFICIENCY4 (118)
	int m_nProficiencyExtra5; //16ch, EXTRAPROFICIENCY5 (119)
	int m_nProficiencyExtra6; //170h, EXTRAPROFICIENCY6 (120)
	int m_nProficiencyExtra7; //174h, EXTRAPROFICIENCY7 (121)
	int m_nProficiencyExtra8; //178h, EXTRAPROFICIENCY8 (122)
	int m_nProficiencyExtra9; //17ch, EXTRAPROFICIENCY9 (123)
	int m_nProficiencyExtra10; //180h, EXTRAPROFICIENCY10 (124)
	int m_nProficiencyExtra11; //184h, EXTRAPROFICIENCY11 (125)
	int m_nProficiencyExtra12; //188h, EXTRAPROFICIENCY12 (126)
	int m_nProficiencyExtra13; //18ch, EXTRAPROFICIENCY13 (127)
	int m_nProficiencyExtra14; //190h, EXTRAPROFICIENCY14 (128)
	int m_nProficiencyExtra15; //194h, EXTRAPROFICIENCY15 (129)
	int m_nProficiencyExtra16; //198h, EXTRAPROFICIENCY16 (130)
	int m_nProficiencyExtra17; //19ch, EXTRAPROFICIENCY17 (131)
	int m_nProficiencyExtra18; //1a0h, EXTRAPROFICIENCY18 (132)
	int m_nProficiencyExtra19; //1a4h, EXTRAPROFICIENCY19 (133)
	int m_nProficiencyExtra20; //1a8h, EXTRAPROFICIENCY20 (134)
	ENUM m_ePuppermasterId; //1ach, PUPPETMASTERID
	int m_nPuppermasterType; //1b0h, PUPPETMASTERTYPE, 1 or 2
	int m_nPuppetType; //1b4h, PUPPETTYPE
	ENUM m_ePuppetId; //1b8h, PUPPETID
	int m_nCheckForBerserk; //1bch, CHECKFORBERSERK
	int m_nBerserkStage1; //1c0h, BERSERKSTAGE1
	int m_nBerserkStage2; //1c4h, BERSERKSTAGE2
	int m_nDamageLuck; //1c8h, DAMAGELUCK
	ResRef m_rBardSongEffect; //1cch
	int m_nCriticalHitBonus; //1d4h, CRITICALHITBONUS
	int m_nVisualRange; //1d8h, VISUALRANGE
	int m_nExplore; //1dch, EXPLORE
	int m_nThrullCharm; //1e0h, THRULLCHARM
	int m_nSummonDisable; //1e4h, SUMMONDISABLE
	int m_nAvatarRemoval; //1e8h (188)
	short m_wHitBonus; //1ech, HITBONUS

	char p1eeh[2];

	unsigned int m_dwKit; //1f0, KIT
	int m_nForceSurge; //1f4h, FORCESURGE
	int m_nSurgeMod; //1f8h, SURGEMOD
	int m_nImprovedHaste; //1fch, IMPROVEDHASTE
	int m_nScriptingState1; //200h, SCRIPTINGSTATE1
	int m_nScriptingState2; //204h, SCRIPTINGSTATE2
	int m_nScriptingState3; //208h, SCRIPTINGSTATE3
	int m_nScriptingState4; //20ch, SCRIPTINGSTATE4
	int m_nScriptingState5; //210h, SCRIPTINGSTATE5
	int m_nScriptingState6; //214h, SCRIPTINGSTATE6
	int m_nScriptingState7; //218h, SCRIPTINGSTATE7
	int m_nScriptingState8; //21ch, SCRIPTINGSTATE8
	int m_nScriptingState9; //220h, SCRIPTINGSTATE9
	int m_nScriptingState10; //224h, SCRIPTINGSTATE10 (165)
	int m_nMeleeTHAC0Mod; //228h, MELEETHAC0MOD (166)
	int m_nMeleeDamageMod; //22ch, MELEEDAMAGE (167)
	int m_nMissileDamageMod; //230h, MISSILEDAMAGE (168)
	int m_nHideSelectionCircle; //234h, NOCIRCLE (169)
	int m_nFistTHAC0Mod; //238h, FISTTHAC0 (170)
	int m_nFistDamageMod; //23ch, FISTDAMAGE (171)
	STRREF m_strrefTitle0; //240h, TITLE1 (172)
	STRREF m_strrefTitle1; //244h, TITLE2 (173)
	int m_nDisableVisualEffect; //248h, DISABLEOVERLAY (174)
	int m_nBackstabImmunity; //24ch, DISABLEBACKSTAB (175)
	int m_nOpenLocks9; //250h, LOCKPICKINGCP (176)
	int m_nMoveSilently9; //254h, STEALTHCP (177)
	int m_nFindTraps9; //258h, TRAPSCP (178)
	int m_nPickPockets9; //25ch, PICKPOCKETCP (179)
	int m_nHideInShadows9; //260h, HIDEINSHADOWSCP (180)
	int m_nDetectIllusions9; //264h, DETECTILLUSIONSCP (181)
	int m_nSetTraps9; //268h, SETTRAPSCP (182)
	int m_nOffscreenAI; //26ch, ENABLEOFFSCREENAI (183)
	int m_nExistanceSoundChance; //270h, EXISTANCESOUND (184)
	int m_nSpeedHasteWithoutAttackBonuses; //274h, HASTE (185)
	int m_nDisablePermanentDeath; //278h, DISABLECHUNKYDEATH (186)
	int m_nImmunityTurnUndead; //27ch, DISABLETURNUNDEAD (187)
	int m_nChaosShield; //280h, CHAOSSHIELD (189)
	int m_nNpcBump; //284h, NPCBUMP (190)
	int m_nUseAnyItem; //288h, CANUSEANYITEM (191)
	int m_nBackstabEveryHit; //28ch, ALWAYSBACKSTAB (192)
	int m_nReverseGender; //290h, SEXCHANGE (193)
	int m_nSpellFailInnate; //294h, SPELLFAILUREINNATE (194)
	int m_nImmunityTracking; //298h, DISABLETRACKING (195)
	int m_nDeadMagic; //29ch, DEADMAGIC (196)
	int m_nImmunityTimeStop; //2a0h, DISABLETIMESTOP (197)
	int m_nFreedom; //2a4h, FREEDOM (198)
	int m_nStoneSkinGolem; //2a8h, STONESKINGOLEM (199), immune to poison and display special effect icon?
	int m_nLevelDrain; //2ach, LEVELDRAIN (200)
	int m_nAnimationRemoval; //2b0h, ANIMATIONREMOVAL (201)
};

struct CDerivedStats : public CDerivedStatsTemplate { //Size 8BCh
	IECPtrList m_lProtProjId; //2b4h, holds DWORDS of PROJECTL.IDS Idx
	IECPtrList m_lProtEff; //2d0h, CEffects
	CObjectList m_lObjectProtections; //2ech
	BOOL m_bProtSplLvl[10]; //308h
	CItemPropertiesList m_lWeaponProtections; //330h
	CStatModVsObjectList m_lToHitBonusVsObject; //34ch
	CStatModVsObjectList m_lDamageBonusVsObject; //368h
	COnEquipItemList m_lForbidItems; //384h
	COnEquipItemtypeList m_lForbidItemTypes; //3a0h
	COnEquipItemList m_lApplyEffOnEquipItem; //3bch, added by effect 182 but not used
	COnEquipItemtypeList m_lApplyEffOnEquipItemType; //3d8h, added by effect 183 but not used
	IECPtrList m_lBounceProjId; //3f4h
	CBounceEffList m_lBounceEff; //410h
	BOOL m_bBounceSplLvl[10]; //42ch, if 1 for a level, is affected by that power level
	SpellLevelDec m_BounceSplLvlDec[10]; //454h
	SpellLevelDec m_ProtSplLvlDec[10]; //4a4h

	//group of 14
	IECPtrList m_lProtTypePrimary; //4f4h
	IECPtrList m_lProtTypeSecondary; //510h
	IECPtrList m_lBounceTypePrimary; //52ch
	IECPtrList m_lBounceTypeSecondary; //548h
	COnEquipItemList m_lForbidItem2; //564h, objects in this list never used
	COnEquipItemtypeList m_lForbidItemType2; //580h, objects in this list never used
	CSpellProtectionList m_lSpellProtections; //59ch
	IECPtrList m_lBounceSpl; //5b8h
	IECPtrList m_lProtTypePrimaryDec; //5d4h
	IECPtrList m_lProtTypeSecondaryDec; //5f0h
	IECPtrList m_lBounceTypePrimaryDec; //60ch
	IECPtrList m_lBounceTypeSecondaryDec; //628h
	CConditionalSpellList m_lConditionalSpells; //644h
	CRepeatingEffList m_lRepeatingEffs; //660h

	SpellLevelDec m_SplTrapLvl[10]; //680h
	IECPtrList m_lSplSequencer; //6d0h
	CColorPalList m_ColorListPal; //6ech, size 0x2 objects (byte cColorGroup [location], byte cGroupRangeId [gradient])
	CColorRgbList m_ColorListRgb; //708h, size 0x8 objects (byte cColorGroup, byte cGroupRangeId, ARGB rgbColor, byte n, byte pad)
	CreFileMemorizedSpellLevel m_MemInfoMage[9]; //724h
	CreFileMemorizedSpellLevel m_MemInfoPriest[7]; //7b4h

	int m_nButtonDisable[14]; //824h
	int m_nButtonDisableSpl[3]; //85ch
	COnAttackEffList m_lMeleeEffects; //868h, is checked on non-ranged attack, but FX never added to this list
	COnAttackEffList m_lRangedEffects; //884h, is checked on ranged attack, but FX never added to this list
	CStatModVsObjectList m_lSaveBonusVsObject; //8a0h
};

#endif //OBJSTATS_H