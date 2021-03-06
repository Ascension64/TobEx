#ifndef FILESPL_H
#define FILESPL_H

#include "stdafx.h"
#include "resref.h"

#define SPELL_SPELLTYPE_INSTANT		0x0001
#define SPELL_SPELLTYPE_TRAVELLING	0x0002

#define SPELL_FLAGS_HOSTILE				0x00000400 //lose invis when cast on self
#define SPELL_FLAGS_NO_LINE_OF_SIGHT	0x00000800 //SPELLFLAG_IGNORE_LOS
#define SPELL_FLAGS_ALLOW_SPOTTING		0x00001000
#define SPELL_FLAGS_OUTSIDE_ONLY		0x00002000 //SPELLFLAG_OUTDOOR
#define SPELL_FLAGS_IGNORESURGEANDDEAD	0x00004000 //SPELLFLAG_NONMAGICAL
#define SPELL_FLAGS_IGNORESURGEONLY		0x00008000 //SPELLFLAG_CONDITIONAL
#define SPELL_FLAGS_NOTINCOMBAT			0x00010000 //SPELLFLAG_NONCOMBAT
#define SPELL_FLAGS_TARGET_INVISIBLE	0x01000000 //new in TobEx
#define SPELL_FLAGS_NO_VOICE			0x02000000 //new in TobEx

#define     SPELL_ANIMATIONTYPE_NONE			0x0000
#define     SPELL_ANIMATIONTYPE_FIRE_AQUA		0x0001
#define     SPELL_ANIMATIONTYPE_FIRE_BLUE		0x0002
#define     SPELL_ANIMATIONTYPE_FIRE_GOLD		0x0003
#define     SPELL_ANIMATIONTYPE_FIRE_GREEN		0x0004
#define     SPELL_ANIMATIONTYPE_FIRE_MAGENTA	0x0005
#define     SPELL_ANIMATIONTYPE_FIRE_PURPLE		0x0006
#define     SPELL_ANIMATIONTYPE_FIRE_RED		0x0007
#define     SPELL_ANIMATIONTYPE_FIRE_WHITE		0x0008

#define     SPELL_ANIMATIONTYPE_GLOW_NECROMANCY		0x0009
#define     SPELL_ANIMATIONTYPE_GLOW_ALTERATION		0x000A
#define     SPELL_ANIMATIONTYPE_GLOW_ENCHANTMENT	0x000B
#define     SPELL_ANIMATIONTYPE_GLOW_ABJURATION		0x000C
#define     SPELL_ANIMATIONTYPE_GLOW_ILLUSION		0x000D
#define     SPELL_ANIMATIONTYPE_GLOW_CONJURE		0x000E
#define     SPELL_ANIMATIONTYPE_GLOW_INVOCATION		0x000F
#define     SPELL_ANIMATIONTYPE_GLOW_DIVINATION		0x0010

#define     SPELL_ANIMATIONTYPE_SPARKLES_FOUNTAIN_AQUA      0x0011
#define     SPELL_ANIMATIONTYPE_SPARKLES_FOUNTAIN_BLACK     0x0012
#define     SPELL_ANIMATIONTYPE_SPARKLES_FOUNTAIN_BLUE      0x0013
#define     SPELL_ANIMATIONTYPE_SPARKLES_FOUNTAIN_GOLD      0x0014
#define     SPELL_ANIMATIONTYPE_SPARKLES_FOUNTAIN_GREEN     0x0015
#define     SPELL_ANIMATIONTYPE_SPARKLES_FOUNTAIN_MAGENTA   0x0016
#define     SPELL_ANIMATIONTYPE_SPARKLES_FOUNTAIN_PURPLE    0x0017
#define     SPELL_ANIMATIONTYPE_SPARKLES_FOUNTAIN_RED       0x0018
#define     SPELL_ANIMATIONTYPE_SPARKLES_FOUNTAIN_WHITE     0x0019

#define     SPELL_ANIMATIONTYPE_SPARKLES_SWIRL_AQUA		0x001A
#define     SPELL_ANIMATIONTYPE_SPARKLES_SWIRL_BLACK	0x001B
#define     SPELL_ANIMATIONTYPE_SPARKLES_SWIRL_BLUE		0x001C
#define     SPELL_ANIMATIONTYPE_SPARKLES_SWIRL_GOLD		0x001D
#define     SPELL_ANIMATIONTYPE_SPARKLES_SWIRL_GREEN	0x001E
#define     SPELL_ANIMATIONTYPE_SPARKLES_SWIRL_MAGENTA	0x001F
#define     SPELL_ANIMATIONTYPE_SPARKLES_SWIRL_PURPLE	0x0020
#define     SPELL_ANIMATIONTYPE_SPARKLES_SWIRL_RED		0x0021
#define     SPELL_ANIMATIONTYPE_SPARKLES_SWIRL_WHITE	0x0022

/*  equal to ITEM_NOTUSEABLEBY_ALIGNMENT_
#define     SPELL_NOTUSEABLEBY_ALIGNMENT_CHAOTIC	0x00000001
#define     SPELL_NOTUSEABLEBY_ALIGNMENT_EVIL		0x00000002
#define     SPELL_NOTUSEABLEBY_ALIGNMENT_GOOD		0x00000004
#define     SPELL_NOTUSEABLEBY_ALIGNMENT_GE_NEUTRAL	0x00000008
#define     SPELL_NOTUSEABLEBY_ALIGNMENT_LAWFUL		0x00000010
#define     SPELL_NOTUSEABLEBY_ALIGNMENT_LC_NEUTRAL	0x00000020
*/
#define     SPELL_NOTUSEABLEBY_MAGESCHOOL_ABJURER		0x00000040
#define     SPELL_NOTUSEABLEBY_MAGESCHOOL_CONJURER		0x00000080
#define     SPELL_NOTUSEABLEBY_MAGESCHOOL_DIVINER		0x00000100
#define     SPELL_NOTUSEABLEBY_MAGESCHOOL_ENCHANTER		0x00000200
#define     SPELL_NOTUSEABLEBY_MAGESCHOOL_ILLUSIONIST	0x00000400
#define     SPELL_NOTUSEABLEBY_MAGESCHOOL_INVOKER		0x00000800
#define     SPELL_NOTUSEABLEBY_MAGESCHOOL_NECROMANCER	0x00001000
#define     SPELL_NOTUSEABLEBY_MAGESCHOOL_TRANSMUTER	0x00002000
#define     SPELL_NOTUSEABLEBY_MAGESCHOOL_GENERALIST	0x00004000

#define     SPELL_NOTUSEABLEBY_DIETYCLASS_0		0x00000040
#define     SPELL_NOTUSEABLEBY_DIETYCLASS_1		0x00000080
#define     SPELL_NOTUSEABLEBY_DIETYCLASS_2		0x00000100
#define     SPELL_NOTUSEABLEBY_DIETYCLASS_3		0x00000200
#define     SPELL_NOTUSEABLEBY_DIETYCLASS_4		0x00000400
#define     SPELL_NOTUSEABLEBY_DIETYCLASS_5		0x00000800
#define     SPELL_NOTUSEABLEBY_DIETYCLASS_6		0x00001000
#define     SPELL_NOTUSEABLEBY_DIETYCLASS_7		0x00002000
#define     SPELL_NOTUSEABLEBY_DIETYCLASS_8		0x00004000
#define     SPELL_NOTUSEABLEBY_DIETYCLASS_9		0x00008000
#define     SPELL_NOTUSEABLEBY_DIETYCLASS_10	0x00010000
#define     SPELL_NOTUSEABLEBY_DIETYCLASS_11	0x00020000
#define     SPELL_NOTUSEABLEBY_DIETYCLASS_12	0x00040000
#define     SPELL_NOTUSEABLEBY_DIETYCLASS_13	0x00080000
#define     SPELL_NOTUSEABLEBY_DIETYCLASS_14	0x00100000
#define     SPELL_NOTUSEABLEBY_DIETYCLASS_15	0x00200000
#define     SPELL_NOTUSEABLEBY_DIETYCLASS_16	0x00400000
#define     SPELL_NOTUSEABLEBY_RACE_ELF			0x00800000
#define     SPELL_NOTUSEABLEBY_RACE_DWARF		0x01000000
#define     SPELL_NOTUSEABLEBY_RACE_HALFELF		0x02000000
#define     SPELL_NOTUSEABLEBY_RACE_HALFLING	0x04000000
#define     SPELL_NOTUSEABLEBY_RACE_HUMAN		0x08000000
#define     SPELL_NOTUSEABLEBY_RACE_GNOME		0x10000000
#define     SPELL_NOTUSEABLEBY_DIETYCLASS_17	0x20000000
#define     SPELL_NOTUSEABLEBY_CLERIC			0x40000000
#define     SPELL_NOTUSEABLEBY_DRUID			0x80000000

#define SPELL_TYPE_SPECIAL	0x00000000 //Not defined in IE
#define SPELL_TYPE_WIZARD	0x00000001 //SPELL_TYPE_MAGE
#define SPELL_TYPE_CLERIC	0x00000002 //SPELL_TYPE_PRIEST
#define SPELL_TYPE_PSIONIC	0x00000003
#define SPELL_TYPE_NATIVE	0x00000004 //SPELL_TYPE_INNATE
#define SPELL_TYPE_BARDSONG	0x00000005 //Not defined in IE

struct SplFileHeader {
	DWORD   m_nFileType;
	DWORD   m_nFileVersion;
	STRREF  m_strrefGenericName;
	STRREF  m_strrefIdentifiedName;
	RESREF  m_rUsedUpItem; //usedUpItemID
	DWORD   m_dwItemFlags;
	WORD    m_wItemType;
	DWORD   m_dwNotUsableBy;
	WORD    m_wCastingAnimationType;
	BYTE    m_cMinLevelRequired;
	BYTE    m_cSchool;
	BYTE    m_cMinSTRRequired;
	BYTE    m_cSecondaryType;
	BYTE    m_cMinSTRBonusRequired;
	BYTE    m_cNotUsableBy2a; //Uppermost byte of a DWORD
	BYTE    m_cMinINTRequired;
	BYTE    m_cNotUsableBy2b; 
	BYTE    m_cMinDEXRequired;
	BYTE    m_cNotUsableBy2c; 
	BYTE    m_cMinWISRequired;
	BYTE    m_cNotUsableBy2d; 
	WORD    m_cMinCONRequired;
	WORD    m_cMinCHRRequired;

	DWORD   m_dwSpellLevel;
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
	WORD    m_wCastingStartingEffect;
	WORD    m_wCastingEffectCount;
};

struct SplFileAbility { //Size 28h
	WORD    m_wType; //0h
	WORD    m_wQuickSlotType; //2h, loc
	RESREF  m_rQuickSlotIcon; //4h, memIcon
	BYTE    m_cActionType; //ch, targetType
	BYTE    m_cActionCount; //dh, targetNum
	WORD    m_wRange; //eh
	WORD    m_wMinCasterLevel; //10h
	WORD    m_wSpeedFactor; //12h
	WORD    m_wTimesPerDay; //14h, times/per/day 0xFFFF is unlimited
	WORD    m_wDamageDice; //16h, sizeDice
	WORD    m_wDamageDiceCount; //18h, nDice
	WORD    m_wDamageDiceBonus; //1ah, enchanted
	WORD    m_wDamageType; //1ch
	WORD    m_wEffectCount; //1eh, wNumEffects
	WORD    m_wStartingEffect; //20h, wEffectIdx
	WORD    m_wMaxUsageCount; //22h, nCharges
	WORD    m_wUsageFlags; //24h, chargeType
	WORD    m_wMissileType; //26h, projIdx
};

#endif //FILESPL_H