#ifndef FILECRE_H
#define FILECRE_H

#include "stdafx.h"
#include "resref.h"

#define CGAMESPRITE_MAX_SPELL_LEVELS_PRIEST 7
#define CGAMESPRITE_MAX_SPELL_LEVELS_MAGE   9
#define CGAMESPRITE_MAX_SPELL_LEVELS_INNATE 1

#define CREFILEHEADER_NUM_COLORS                              7
#define CREFILEHEADER_NUM_PROFICIENCIES                       20

#define CREFILEHEADER_SOUND_NUM_SPEECH                        100
#define CREFILEHEADER_SOUND_OFFSET_INITIAL_MEETING            0
#define CREFILEHEADER_SOUND_OFFSET_MORALE                     1
#define CREFILEHEADER_SOUND_OFFSET_HAPPY                      2
#define CREFILEHEADER_SOUND_OFFSET_UNHAPPY_ANNOYED            3
#define CREFILEHEADER_SOUND_OFFSET_UNHAPPY_SERIOUS            4
#define CREFILEHEADER_SOUND_OFFSET_UNHAPPY_BREAKING_POINT     5
#define CREFILEHEADER_SOUND_OFFSET_LEADER                     6
#define CREFILEHEADER_SOUND_OFFSET_TIRED                      7
#define CREFILEHEADER_SOUND_OFFSET_BORED                      8
#define CREFILEHEADER_SOUND_OFFSET_BATTLE_CRY                 9
#define CREFILEHEADER_SOUND_OFFSET_ATTACK                     14
#define CREFILEHEADER_SOUND_OFFSET_DAMAGE                     18
#define CREFILEHEADER_SOUND_OFFSET_DYING                      19
#define CREFILEHEADER_SOUND_OFFSET_HURT                       20
#define CREFILEHEADER_SOUND_OFFSET_AREA_FOREST                21
#define CREFILEHEADER_SOUND_OFFSET_AREA_CITY                  22
#define CREFILEHEADER_SOUND_OFFSET_AREA_DUNGEON               23
#define CREFILEHEADER_SOUND_OFFSET_AREA_DAY                   24
#define CREFILEHEADER_SOUND_OFFSET_AREA_NIGHT                 25
#define CREFILEHEADER_SOUND_OFFSET_SELECT_COMMON              26
#define CREFILEHEADER_SOUND_OFFSET_SELECT_ACTION              32
//#define CREFILEHEADER_SOUND_OFFSET_SELECT_RARE                35
#define CREFILEHEADER_SOUND_OFFSET_SELECT_RARE                63
#define CREFILEHEADER_SOUND_OFFSET_INTERACTION                39
#define CREFILEHEADER_SOUND_OFFSET_INSULT                     44
#define CREFILEHEADER_SOUND_OFFSET_COMPLIMENT                 47
#define CREFILEHEADER_SOUND_OFFSET_SPECIAL                    50
#define CREFILEHEADER_SOUND_OFFSET_REACT_TO_DIE_GENERAL       53
#define CREFILEHEADER_SOUND_OFFSET_REACT_TO_DIE_SPECIFIC      54
#define CREFILEHEADER_SOUND_OFFSET_MISCELLANEOUS              55
#define CREFILEHEADER_SOUND_OFFSET_RESPONSE_TO_COMPLIMENT     55
#define CREFILEHEADER_SOUND_OFFSET_RESPONSE_TO_INSULT         58
#define CREFILEHEADER_SOUND_OFFSET_DIALOG_HOSTILE             61
#define CREFILEHEADER_SOUND_OFFSET_DIALOG_DEFAULT             62
#define CREFILEHEADER_SOUND_OFFSET_EXISTANCE                  69
//#define CREFILEHEADER_SOUND_OFFSET_ACTION_SOUND_COMMON2       63
#define CREFILEHEADER_SOUND_OFFSET_CRITICAL_HIT               65
#define CREFILEHEADER_SOUND_OFFSET_CRITICAL_MISS              66
#define CREFILEHEADER_SOUND_OFFSET_TARGET_IMMUNE              67
#define CREFILEHEADER_SOUND_OFFSET_INVENTORY_FULL             68
#define CREFILEHEADER_SOUND_OFFSET_PICKED_POCKET              69
#define CREFILEHEADER_SOUND_OFFSET_HIDDEN_IN_SHADOWS          70
#define CREFILEHEADER_SOUND_OFFSET_SPELL_DISRUPTED            71
#define CREFILEHEADER_SOUND_OFFSET_SET_A_TRAP                 72

#define CREFILEHEADER_SOUND_NUM_INITIAL_MEETING            1
#define CREFILEHEADER_SOUND_NUM_MORALE                     1
#define CREFILEHEADER_SOUND_NUM_HAPPY                      1
#define CREFILEHEADER_SOUND_NUM_UNHAPPY_ANNOYED            1
#define CREFILEHEADER_SOUND_NUM_UNHAPPY_SERIOUS            1
#define CREFILEHEADER_SOUND_NUM_UNHAPPY_BREAKING_POINT     1
#define CREFILEHEADER_SOUND_NUM_LEADER                     1
#define CREFILEHEADER_SOUND_NUM_TIRED                      1
#define CREFILEHEADER_SOUND_NUM_BORED                      1
#define CREFILEHEADER_SOUND_NUM_BATTLE_CRY                 5
#define CREFILEHEADER_SOUND_NUM_ATTACK                     4
#define CREFILEHEADER_SOUND_NUM_DAMAGE                     1
#define CREFILEHEADER_SOUND_NUM_DYING                      1
#define CREFILEHEADER_SOUND_NUM_HURT                       1
#define CREFILEHEADER_SOUND_NUM_AREA_FOREST                1
#define CREFILEHEADER_SOUND_NUM_AREA_CITY                  1
#define CREFILEHEADER_SOUND_NUM_AREA_DUNGEON               1
#define CREFILEHEADER_SOUND_NUM_AREA_DAY                   1
#define CREFILEHEADER_SOUND_NUM_AREA_NIGHT                 1
#define CREFILEHEADER_SOUND_NUM_SELECT_COMMON              6
#define CREFILEHEADER_SOUND_NUM_SELECT_ACTION              7
//#define CREFILEHEADER_SOUND_NUM_SELECT_RARE                4
#define CREFILEHEADER_SOUND_NUM_SELECT_RARE                2
#define CREFILEHEADER_SOUND_NUM_INTERACTION                5
#define CREFILEHEADER_SOUND_NUM_INSULT                     3
#define CREFILEHEADER_SOUND_NUM_COMPLIMENT                 3
#define CREFILEHEADER_SOUND_NUM_SPECIAL                    3
#define CREFILEHEADER_SOUND_NUM_REACT_TO_DIE_GENERAL       1
#define CREFILEHEADER_SOUND_NUM_REACT_TO_DIE_SPECIFIC      1
#define CREFILEHEADER_SOUND_NUM_MISCELLANEOUS              20
#define CREFILEHEADER_SOUND_NUM_RESPONSE_TO_COMPLIMENT     3
#define CREFILEHEADER_SOUND_NUM_RESPONSE_TO_INSULT         3
#define CREFILEHEADER_SOUND_NUM_DIALOG_HOSTILE             1
#define CREFILEHEADER_SOUND_NUM_DIALOG_DEFAULT             1
#define CREFILEHEADER_SOUND_NUM_EXISTANCE                  5
//#define CREFILEHEADER_SOUND_NUM_ACTION_SOUND_COMMON2       1
#define CREFILEHEADER_SOUND_NUM_CRITICAL_HIT               1
#define CREFILEHEADER_SOUND_NUM_CRITICAL_MISS              1
#define CREFILEHEADER_SOUND_NUM_TARGET_IMMUNE              1
#define CREFILEHEADER_SOUND_NUM_INVENTORY_FULL             1
#define CREFILEHEADER_SOUND_NUM_PICKED_POCKET              1
#define CREFILEHEADER_SOUND_NUM_HIDDEN_IN_SHADOWS          1
#define CREFILEHEADER_SOUND_NUM_SPELL_DISRUPTED            1
#define CREFILEHEADER_SOUND_NUM_SET_A_TRAP                 1

#define CREFILEHEADER_SOUND_OFFSET_BIOGRAPHY               (CREFILEHEADER_SOUND_OFFSET_MISCELLANEOUS + CREFILEHEADER_SOUND_NUM_MISCELLANEOUS - 1)

#define CREFILEHEADER_FLAG_HERDING_ALLEGIANCE         0x01000000
#define CREFILEHEADER_FLAG_HERDING_GENERAL            0x02000000
#define CREFILEHEADER_FLAG_HERDING_RACE               0x04000000
#define CREFILEHEADER_FLAG_HERDING_					0x08000000
#define CREFILEHEADER_FLAG_HERDING_SPECIFICS          0x10000000
#define CREFILEHEADER_FLAG_HERDING_GENDER             0x20000000
#define CREFILEHEADER_FLAG_HERDING_ALIGNMENT          0x40000000
#define CREFILEHEADER_FLAG_IDENTIFIED                 0x00000001
#define CREFILEHEADER_FLAG_NOINTERRUPT                0x80000000
#define CREFILEHEADER_FLAG_REMOVE_BODY_ON_DEATH       0x00000002
#define CREFILEHEADER_FLAG_NEVER_REMOVE_BODY          0x00000004
#define CREFILEHEADER_FLAG_CLASS_INACTIVE_FIGHTER     0x00000008
#define CREFILEHEADER_FLAG_CLASS_INACTIVE_MAGE        0x00000010
#define CREFILEHEADER_FLAG_CLASS_INACTIVE_CLERIC      0x00000020
#define CREFILEHEADER_FLAG_CLASS_INACTIVE_THIEF       0x00000040
#define CREFILEHEADER_FLAG_CLASS_INACTIVE_DRUID       0x00000080
#define CREFILEHEADER_FLAG_CLASS_INACTIVE_RANGER      0x00000100
#define CREFILEHEADER_FLAG_CLASS_INACTIVE_ALL         0x000001F8
#define CREFILEHEADER_FLAG_CLASS_FALLEN_PALADIN       0x00000200 //CREFLAG_FALLEN_PALADIN
#define CREFILEHEADER_FLAG_CLASS_FALLEN_RANGER        0x00000400 //CREFLAG_FALLEN_RANGER
#define CREFILEHEADER_FLAG_PC                         0x00000800
#define CREFILEHEADER_FLAG_DONT_DISPLAY_HEALTH        0x00001000
#define CREFILEHEADER_FLAG_LARGE_CREATURE             0x00002000
#define CREFILEHEADER_FLAG_LIMBO_CREATURE             0x00004000
#define CREFILEHEADER_FLAG_BEEN_IN_PARTY              0x00008000
#define CREFILEHEADER_FLAG_SAVE_TEMP_ITEM             0x00010000
#define CREFILEHEADER_FLAG_NEVER_SET_ME               0x00020000 //If I am set un set all of the flags!

#define CREFILEHEADER_PROFICIENCIES_ACTIVEMASK        0x07
#define CREFILEHEADER_PROFICIENCIES_INACTIVEMASK      0x38
#define CREFILEHEADER_PROFICIENCIES_ACTIVESHIFT       0
#define CREFILEHEADER_PROFICIENCIES_INACTIVESHIFT     3

#define CREFILEHEADER_PROFICIENCIES_LARGE_SWORD	0
#define CREFILEHEADER_PROFICIENCIES_SMALL_SWORD	1
#define CREFILEHEADER_PROFICIENCIES_BOW			2
#define CREFILEHEADER_PROFICIENCIES_SPEAR		3
#define CREFILEHEADER_PROFICIENCIES_BLUNT		4
#define CREFILEHEADER_PROFICIENCIES_SPIKED		5
#define CREFILEHEADER_PROFICIENCIES_AXE			6
#define CREFILEHEADER_PROFICIENCIES_MISSILE		7

#define CGAMEEFFECT_FORMAT_ITEMEFFECT 0
#define CGAMEEFFECT_FORMAT_CGAMEEFFECTBASE 1

struct CreFileColors { //Size 7h
	unsigned char colorMetal; //0h
	unsigned char colorMinor; //1h
	unsigned char colorMajor; //2h
	unsigned char colorSkin; //3h
	unsigned char colorLeather; //4h
	unsigned char colorArmor; //5h
	unsigned char colorHair; //6h
};

struct CreFileHeader { //Size 268h
	STRREF m_strrefName; //0h, longNameStrRef, for dialogue
	STRREF m_strrefApparentName; //4h, shortNameStrRef, for tooltip
	DWORD m_dwFlags; //8h, dwFlags
	DWORD m_dwXpValue; //ch, ExpWorth
	DWORD m_dwXp; //10h, currentExp
	DWORD m_dwGold; //14h
	DWORD m_dwGeneralState; //18h, stateFlags
	SHORT m_wHitPoints; //1ch, currentHP
	WORD m_wMaxHitPointsBase; //1eh, maxHP
	DWORD m_dwAnimationType; //20h, animId
	CreFileColors m_colors; //24h, IE uses BYTE m_colors[CREFILEHEADER_NUM_COLORS];
	BYTE m_cEffectVersion; //2bh, 0 = ItmFileEffect, 1 = CEffect, effType
	RESREF m_rPortraitSmall; //2ch
	RESREF m_rPortraitLarge; //34h
	BYTE m_cReputation; //3ch, note split this into 2 bytes
	BYTE m_cHideInShadowsBase; //Not in editor
	SHORT m_wArmorClass; //ACNatural
	SHORT m_wArmorClassBase; //40h, ACEffective
	SHORT m_wArmorClassCrushingAdjustment; //ACCrushingMod
	SHORT m_wArmorClassMissileAdjustment; //ACMissileMod
	SHORT m_wArmorClassPiercingAdjustment; //ACPiercingMod
	SHORT m_wArmorClassSlashingAdjustment; //ACSlashingMod
	char m_cTHAC0Base; //THAC0
	BYTE m_cNumberOfAttacksBase; //numAttacks
	BYTE m_cSaveVsDeathBase; //4ch, saveDeath
	BYTE m_cSaveVsWandsBase; //saveWands
	BYTE m_cSaveVsPolyBase; //savePoly
	BYTE m_cSaveVsBreathBase; //saveBreath
	BYTE m_cSaveVsSpellBase; //50h, saveSpell
	char m_cResistFireBase; //resistFire
	char m_cResistColdBase; //resistCold
	char m_cResistElectricityBase; //resistElectricity
	char m_cResistAcidBase; //resistAcid
	char m_cResistMagicBase; //resistMagic
	char m_cResistMagicFireBase; //resistMagicFire
	char m_cResistMagicColdBase; //resistMagicCold
	char m_cResistSlashingBase; //resistSlashing
	char m_cResistCrushingBase; //resistCrushing
	char m_cResistPiercingBase; //resistPiercing
	char m_cResistMissileBase; //resistMissile
	BYTE m_cDetectIllusionBase; //detectIllusion, not in editor
	BYTE m_cSetTrapsBase; //setTraps, not in editor
	BYTE m_cLoreBase; //lore
	BYTE m_cLockPickingBase; //lockpicking
	BYTE m_cMoveSilentlyBase; //60h, stealth
	BYTE m_cTrapsBase; //findTraps
	BYTE m_cPickPocketBase; //pickPockets
	BYTE m_cFatigueLimit; //63h, fatigue, fatigue above this value results in fatigue
	BYTE m_cIntoxication;
	CHAR m_cLuckBase; //luck
	CHAR m_cProficiencies[CREFILEHEADER_NUM_PROFICIENCIES]; //6h, BG1 proficiencies
	BYTE m_cUndeadLevel; //7ah
	BYTE m_cTrackingBase; //tracking
	SCRIPTNAME m_szTrackingTarget;  //The thing I am currently tracking
	STRREF m_strrefSoundset[CREFILEHEADER_SOUND_NUM_SPEECH]; //9ch, speech
	BYTE m_cLevel1; //22ch, levelPrimary
	BYTE m_cLevel2; //22dh, levelSecondary
	BYTE m_cLevel3; //22eh, levelTertiary
	BYTE m_cSex; //22fh
	BYTE m_cSTRBase; //strength
	BYTE m_cSTRExtraBase; //strengthEx
	BYTE m_cINTBase; //intelligence
	BYTE m_cWISBase; //wisdom
	BYTE m_cDEXBase; //dexterity
	BYTE m_cCONBase; //constitution
	BYTE m_cCHRBase; //charisma
	BYTE m_cMorale; //236h, range: 0-20, add -1 when PC dies
	BYTE m_cMoraleBreak;
	BYTE m_cHatedRace; //239h, racialEnemy, rangers get a +4 to hit and damage
	WORD m_cMoraleRecoveryTime;
	WORD m_wKit[2]; //23ch, [high WORD.low WORD]; //IE uses WORD m_mageSpecUpperWord; WORD m_mageSpecialization;
	RESREF m_rScriptOverride; //240h
	RESREF m_rScriptClass;
	RESREF m_rScriptRace; //250h
	RESREF m_rScriptGeneral;
	RESREF m_rScriptDefault; //260h
};

#define CREFILEOFFSETS_NUM_SPECIALCASE    5

struct CreFileOffsets {
	BYTE m_cEnemyAlly;
	BYTE m_cGeneral;
	BYTE m_cRace;
	BYTE m_cClass;
	BYTE m_cSpecifics;
	BYTE m_cGender;
	BYTE m_cSpecialCase[CREFILEOFFSETS_NUM_SPECIALCASE];
	BYTE m_cAlignment;
	LONG m_nInstance;
	SCRIPTNAME m_szName;
	DWORD m_dwKnownSpellListOffset;
	DWORD m_dwKnownSpellListCount;
	DWORD m_dwMemorizationLevelListOffset;
	DWORD m_dwMemorizationLevelListCount;
	DWORD m_dwMemorizationSpellListOffset;
	DWORD m_dwMemorizationSpellListCount;
	DWORD m_dwEquipmentListOffset;
	DWORD m_dwItemListOffset;
	DWORD m_dwItemListCount;
	DWORD m_dwEffectListOffset;
	DWORD m_dwEffectListCount;
	RESREF m_rDialog;
};

struct CreFileKnownSpell { //Size Ch
	RESREF m_rKnownSpellName; //0h, name
	WORD m_wSpellLevel; //8h, level
	WORD m_wMagicType; //ah, type
};

struct CreFileMemorizedSpellLevel { //Size 10h
	WORD m_wSpellLevel; //0h, wLevel
	WORD m_wMemSpellsMax; //2h, wBaseCount
	WORD m_wMemSpellsCount; //4h, wCount
	WORD m_wMagicType; //6h, type, 0 = priest, 1 = wizard, 2 = innate
	DWORD m_wMemorizedStartingSpell; //8h, index, of spell table
	DWORD m_wMemorizedCount; //ch, nNumSpells, count of spells
};

#define CREFILEMEMORIZEDSPELL_FLAG_MEMORIZED 0x0001 //CREMEMSPELL_MEMORIZED
#define CREFILEMEMORIZEDSPELL_FLAG_DISABLED  0x0002

struct CreFileMemorizedSpell { //Size Ch
	RESREF m_rSpellName; //0h, name
	WORD m_wFlags; //8h, bit1: is a SPIN107, 108, 109, 110, 111 (a Paladin, Ranger, Druid special innate)
	BYTE m_cStructureAlignment1[2];
};

#define CREFILEITEM_NUM_USAGECOUNT    3
#define CREFILEITEM_FLAGS_IDENTIFIED  0x00000001 //CREITEM_IDENTIFIED
#define CREFILEITEM_FLAGS_GIVEN       0x00000002 //CREITEM_UNSTEALABLE
#define CREFILEITEM_FLAGS_STOLEN      0x00000004 //CREITEM_STOLEN
#define CREFILEITEM_FLAGS_NONDROPPABLE  0x00000008 //CREITEM_UNDROPPABLE

struct CreFileItem {
	RESREF m_rItemName;
	WORD m_wWear;
	WORD m_wUsageCount[CREFILEITEM_NUM_USAGECOUNT];
	DWORD m_dwDynamicFlags;
};

#define CREFILEEQUIPMENT_WEAPON_NUM   4
#define CREFILEEQUIPMENT_AMMO_NUM     4
#define CREFILEEQUIPMENT_MISC_NUM     20

struct CreFileEquipment {
	WORD m_wHelmetItem;
	WORD m_wArmorItem;
	WORD m_wShieldItem;
	WORD m_wGauntletsItem;
	WORD m_wRingLeftItem;
	WORD m_wRingRightItem;
	WORD m_wAmuletItem;
	WORD m_wBeltItem;
	WORD m_wBootsItem;
	WORD m_wWeaponItem[CREFILEEQUIPMENT_WEAPON_NUM];
	WORD m_wAmmoItem[CREFILEEQUIPMENT_AMMO_NUM];
	WORD m_wCloakItem;
	WORD m_wMiscItem[CREFILEEQUIPMENT_MISC_NUM];
	WORD m_wSelectedWeapon;
	WORD m_wSelectedWeaponAbility;
};

#endif //FILECRE_H