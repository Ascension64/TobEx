#ifndef FILEITM_H
#define FILEITM_H

#include "stdafx.h"
#include "resref.h"

//Item flags
#define ITEM_FLAGS_INDESTRUCTABLE		0x000000001 // ITEMFLAG_CRITICAL, can't be lost
#define ITEM_FLAGS_TWOHANDED			0x000000002 // prevents shield from
#define ITEM_FLAGS_DROPPABLE			0x000000004 //ITEMFLAG_DROPPABLE
#define ITEM_FLAGS_DISPLAYABLE			0x000000008 //unused in BG2?
#define ITEM_FLAGS_CURSED				0x000000010
#define ITEM_FLAGS_NOTCOPYABLE			0x000000020 // applies only to scroll types, unused in BG2?
#define ITEM_FLAGS_MAGIC				0x000000040 // ITEMFLAG_MAGICAL, is the item considered magic, unused in BG2?
#define ITEM_FLAGS_LEFTHANDED			0x000000080 // ITEMFLAG_BOW, i.e. bow, unused in BG2?
#define ITEM_FLAGS_SILVER				0x000000100
#define ITEM_FLAGS_COLDIRON				0x000000200
#define ITEM_FLAGS_OFFHANDED			0x000000400 // ITEMFLAG_STOLEN, not for use by editors
#define ITEM_FLAGS_DIALOG				0x000000800 // ITEMFLAG_CONVERSABLE
#define ITEM_FLAGS_NOT_DISPELLABLE		0x01000000 //new in TobEx, tob_hacks, Spell Revisions
#define ITEM_FLAGS_TOGGLE_CRITICALHIT	0x02000000 //new in TobEx
#define ITEM_FLAGS_NO_TARGET_INVIS		0x04000000 //new in TobEx

//Item types
#define ITEMTYPE_MISC			0x00
#define ITEMTYPE_AMULET			0x01
#define ITEMTYPE_ARMOR			0x02
#define ITEMTYPE_BELT			0x03
#define ITEMTYPE_BOOTS			0x04
#define ITEMTYPE_ARROW			0x05
#define ITEMTYPE_GAUNTLET		0x06
#define ITEMTYPE_HELMET			0x07
#define ITEMTYPE_KEY			0x08
#define ITEMTYPE_POTION			0x09
#define ITEMTYPE_RING			0x0A
#define ITEMTYPE_SCROLL			0x0B
#define ITEMTYPE_SHIELD			0x0C
#define ITEMTYPE_FOOD			0x0D
#define ITEMTYPE_BULLET			0x0E
#define ITEMTYPE_BOW			0x0F
#define ITEMTYPE_DAGGER			0x10
#define ITEMTYPE_MACE			0x11
#define ITEMTYPE_SLING			0x12
#define ITEMTYPE_SMALL_SWORD	0x13
#define ITEMTYPE_LARGE_SWORD	0x14
#define ITEMTYPE_HAMMER			0x15
#define ITEMTYPE_MORNING_STAR	0x16
#define ITEMTYPE_FLAIL			0x17
#define ITEMTYPE_DART			0x18
#define ITEMTYPE_AXE			0x19
#define ITEMTYPE_STAFF			0x1A
#define ITEMTYPE_XBOW			0x1B
#define ITEMTYPE_HAND			0x1C
#define ITEMTYPE_SPEAR			0x1D
#define ITEMTYPE_HALBERD		0x1E
#define ITEMTYPE_BOLT			0x1F
#define ITEMTYPE_CLOAK			0x20
#define ITEMTYPE_GOLD			0x21
#define ITEMTYPE_GEM			0x22
#define ITEMTYPE_WAND			0x23
#define ITEMTYPE_CONTAINER		0x24

//Item unusable flags
#define ITEMUNUSABLE_THIEF		0x00400000

#define     ITEM_NOTUSEABLEBY_ALIGNMENT_CHAOTIC		0x00000001
#define     ITEM_NOTUSEABLEBY_ALIGNMENT_EVIL		0x00000002
#define     ITEM_NOTUSEABLEBY_ALIGNMENT_GOOD		0x00000004
#define     ITEM_NOTUSEABLEBY_ALIGNMENT_GE_NEUTRAL	0x00000008
#define     ITEM_NOTUSEABLEBY_ALIGNMENT_LAWFUL		0x00000010
#define     ITEM_NOTUSEABLEBY_ALIGNMENT_LC_NEUTRAL	0x00000020

struct ItmFileHeader {
	DWORD   m_nFileType;
	DWORD   m_nFileVersion;
	STRREF  m_strrefGenericName;
	STRREF  m_strrefIdentifiedName;
	RESREF  m_rUsedUpItem;
	DWORD   m_dwItemFlags;
	WORD    m_wItemType;
	DWORD   m_dwNotUsableBy;
	BYTE    m_cAnimationType[2]; //WORD animationType;
	WORD    m_cMinLevelRequired;
	WORD    m_cMinSTRRequired;
	BYTE    m_cMinSTRBonusRequired;
	BYTE    m_cNotUsableBy2a; //Uppermost byte of a DWORD
	BYTE    m_cMinINTRequired;
	BYTE    m_cNotUsableBy2b; 
	BYTE    m_cMinDEXRequired;
	BYTE    m_cNotUsableBy2c; 
	BYTE    m_cMinWISRequired;
	BYTE    m_cNotUsableBy2d; 
	BYTE    m_cMinCONRequired;
	BYTE    m_cProficiencyType;
	WORD    m_wMinCHRRequired;

	DWORD   m_dwBaseValue;
	WORD    m_wMaxStackable;
	RESREF  m_rItemIcon;
	WORD    m_wLoreValue;
	RESREF  m_rGroundIcon;
	DWORD   m_dwBaseWeight;
	STRREF  m_strrefGenericDescription;
	STRREF  m_strrefIdentifiedDescription;
	RESREF  m_rDescriptionPicture;
	DWORD   m_dwAttributes;

	DWORD   m_dwAbilityOffset;
	WORD    m_wAbilityCount;

	DWORD   m_dwEffectsOffset;
	WORD    m_wEquippedStartingEffect;
	WORD    m_wEquippedEffectCount;
};

//Item ability attack types
#define ITEMABILITYATTACKTYPE_DEFAULT	0
#define ITEMABILITYATTACKTYPE_MELEE		1
#define ITEMABILITYATTACKTYPE_RANGED	2
#define ITEMABILITYATTACKTYPE_MAGICAL	3
#define ITEMABILITYATTACKTYPE_LAUNCHER	4

//Item ability flags
#define ITEMABILITYFLAG_STRENGTH_BONUS			0x00000001
#define ITEMABILITYFLAG_BREAKABLE				0x00000002 //unused in BG2?
#define ITEMABILITYFLAG_RECHARGES				0x00000800
#define ITEMABILITYFLAG_IWD2_BYPASS_ARMOR		0x00010000 //IWD2 only
#define ITEMABILITYFLAG_IWD2_KEEN				0x00020000 //IWD2 only
#define ITEMABILITYFLAG_RESERVED				0x01000000 //tob_hacks and Spell Revisions use for 'Bypass Mirror Images' (TobEx uses different flag for this)
#define ITEMABILITYFLAG_TOGGLE_BACKSTAB			0x02000000 //new in TobEx

#define ITEM_ABILITY_NUM_ATTACK_TYPES 3

struct ItmFileAbility { //Size 38h
	//IE uses WORD type;
	BYTE	m_cAttackType; //0h
	BYTE	m_cIdRequired; //1h
	BYTE    m_cQuickSlotType; //2h, loc
	BYTE    m_cLargeDamageDice; //3h
	RESREF  m_rQuickSlotIcon; //4h, useIcon
	BYTE    m_cActionType; //ch, targetType
	BYTE    m_cActionCount; //dh, targetCnt
	WORD    m_wRange; //eh, range
	BYTE    m_cLauncherType; //10h, projType
	BYTE    m_cLargeDamageDiceCount;
	BYTE    m_cSpeedFactor; //12h, speed
	BYTE    m_cLargeDamageDiceBonus;
	SHORT   m_wTHAC0Bonus; //14h, toHitBonus
	BYTE    m_cDamageDice; //16h, sizeDice
	BYTE    m_cSchool; //17h, nType1
	BYTE    m_cDamageDiceCount; //18h, nDice
	BYTE    m_cSecondaryType; //19h, nType2
	WORD    m_wDamageDiceBonus; //1ah, damBonus
	WORD    m_wDamageType; //1ch, damType
	WORD    m_wEffectCount; //1eh, nEffects
	WORD    m_wStartingEffect; //20h, offEffects
	WORD    m_wMaxUsageCount; //22h, charges
	WORD    m_wUsageFlags; //24h, chargeType
	DWORD   m_dwAbilityFlags; //26h, flags
	WORD    m_wMissileType; //2ah, projIdx
	WORD    m_wAttackProbability[ITEM_ABILITY_NUM_ATTACK_TYPES]; //2ch, meleeIdx[3]
	short	m_wIsArrow; //32h, not in IE
	short	m_wIsBolt; //34h, not in IE
	short	m_wIsMiscProj; //36h, not in IE
};

struct ItmFileEffect { //Size 30h, also SplFileEffect
	DEFINE_MEMALLOC_FUNC;

	WORD    m_wOpcode; //0h, effectID
	BYTE    m_cTargetType; //2h, target
	BYTE    m_cSpellLevel; //3h, power
	int     m_nParam1; //4h, effectAmount
	DWORD   m_nParam2; //8h, flags
	char	m_cTiming; //ch, IE uses WORD durationType;

	//bit0: Dispellable
	//bit1: Ignore Resistance
	unsigned char m_cFlags; //dh

	DWORD   m_dwDuration; //eh
	BYTE    m_cProbabilityUpper; //12h, highProb
	BYTE    m_cProbabilityLower; //13h, lowProb
	RESREF  m_rResource; //14h
	DWORD   m_dwNumDice; //1ch, numDiceOrMaxLevel
	DWORD   m_dwDiceSize; //20h, sizeDiceOrMinLevel
	DWORD   m_dwSavingThrow; //24h, saveType
	LONG    m_nSaveMod; //28h, saveBonus
	DWORD   m_dwSpecial; //2ch
};

#endif //FILEITM_H