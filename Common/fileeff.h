#ifndef FILEEFF_H
#define FILEEFF_H

#include "stdafx.h"
#include "resref.h"

//Effect timing modes
#define TIMING_INSTANT_LIMITED			0
#define TIMING_INSTANT_PERMANENT		1 //EFFECTTYPE_PERMANENT
#define TIMING_INSTANT_EQUIPPED			2
#define TIMING_DELAY_LIMITED			3
#define TIMING_DELAY_PERMANENT			4
#define TIMING_DELAY_EQUIPPED			5
#define TIMING_DELAYEND_LIMITED			6
#define TIMING_DELAYEND_PERMANENT		7
#define TIMING_DELAYEND_EQUIPPED		8
#define TIMING_VERY_PERMANENT			9
#define TIMING_INSTANT_LIMITED_TICKS	10
#define TIMING_END_TICKS				0x1000

//Effect flags
#define CEFFECT_FLAG_DISPELLABLE					1
#define CEFFECT_FLAG_IGNORE_RESISTANCE				2
#define CEFFECT_FLAG_IGNORE_SPELL_LVL_RESISTANCE	4

//Effect opcodes
#define CEFFECT_OPCODE_ATTACKS_PER_ROUND		0x001
#define CEFFECT_OPCODE_AWAKEN					0x002
#define CEFFECT_OPCODE_CHARISMA_MOD				0x006
#define CEFFECT_OPCODE_CONSTITUTION_MOD			0x00A
#define CEFFECT_OPCODE_DAMAGE					0x00C
#define CEFFECT_OPCODE_INSTANT_DEATH			0x00D
#define CEFFECT_OPCODE_DEXTERITY_MOD			0x00F
#define CEFFECT_OPCODE_CURRENTHP_MOD			0x011
#define CEFFECT_OPCODE_INTELLIGENCE_MOD			0x013
#define CEFFECT_OPCODE_LORE_MOD					0x015
#define CEFFECT_OPCODE_LUCK_MOD					0x016
#define CEFFECT_OPCODE_POISON					0x019
#define CEFFECT_OPCODE_SAVE_VS_DEATH_MOD		0x021
#define CEFFECT_OPCODE_SAVE_VS_WANDS_MOD		0x022
#define CEFFECT_OPCODE_SAVE_VS_POLY_MOD			0x023
#define CEFFECT_OPCODE_SAVE_VS_BREATH_MOD		0x024
#define CEFFECT_OPCODE_SAVE_VS_SPELL_MOD		0x025
#define CEFFECT_OPCODE_UNCONSCIOUSNESS			0x027
#define CEFFECT_OPCODE_MAGE_MEM_SPELL_MOD		0x02A
#define CEFFECT_OPCODE_STRENGTH_MOD				0x02C
#define CEFFECT_OPCODE_WISDOM_MOD				0x031
#define CEFFECT_OPCODE_DISPEL					0x03A
#define CEFFECT_OPCODE_STEALTH_MOD				0x03B
#define CEFFECT_OPCODE_PRIEST_MEM_SPELL_MOD		0x03E
#define CEFFECT_OPCODE_BLINDNESS				0x04A
#define CEFFECT_OPCODE_DISEASE					0x04E
#define CEFFECT_OPCODE_OPEN_LOCKS_MOD			0x05A
#define CEFFECT_OPCODE_FIND_TRAPS_MOD			0x05B
#define CEFFECT_OPCODE_PICK_POCKETS_MOD			0x05C
#define CEFFECT_OPCODE_FATIGUE_MOD				0x05D
#define CEFFECT_OPCODE_INTOXICATION_MOD			0x05E
#define CEFFECT_OPCODE_TRACKING_MOD				0x05F
#define CEFFECT_OPCODE_LEVEL_MOD				0x060
#define CEFFECT_OPCODE_STRENGTH_EX_MOD			0x061
#define CEFFECT_OPCODE_REGENERATION				0x062
#define CEFFECT_OPCODE_MORALE_BREAK_MOD			0x06A
#define CEFFECT_OPCODE_REPUTATION_MOD			0x06C
#define CEFFECT_OPCODE_AID						0x081
#define CEFFECT_OPCODE_BLESS					0x082
#define CEFFECT_OPCODE_CHANT					0x083
#define CEFFECT_OPCODE_HOLY_MIGHT				0x084
#define CEFFECT_OPCODE_CHANT_BAD				0x089
#define CEFFECT_OPCODE_DISPLAY_ICON				0x08E
#define CEFFECT_OPCODE_DISABLE_BUTTON			0x090
#define CEFFECT_OPCODE_DISABLE_SPELLTYPE		0x091
#define CEFFECT_OPCODE_CAST_SPELL				0x092
#define CEFFECT_OPCODE_LEARN_SPELL				0x093
#define CEFFECT_OPCODE_MAGIC_RESIST_MOD			0x0A6
#define CEFFECT_OPCODE_POISON_RESIST_MOD		0x0AD
#define CEFFECT_OPCODE_USE_EFF_FILE				0x0B1
#define CEFFECT_OPCODE_MOVE_TO_AREA				0x0BA
#define CEFFECT_OPCODE_FREEDOM					0x0D4
#define CEFFECT_OPCODE_CAST_SPELL_FROM_LIST		0x0D6
#define CEFFECT_OPCODE_CAST_SPELL_CONDITION		0x0E8
#define CEFFECT_OPCODE_PROFICIENCY_MOD			0x0E9
#define CEFFECT_OPCODE_WING_BUFFET				0x0EB
#define CEFFECT_OPCODE_DISINTEGRATE				0x0EE
#define CEFFECT_OPCODE_AVATAR_REMOVAL			0x10F
#define CEFFECT_OPCODE_REPEATING_EFFECT			0x110
#define CEFFECT_OPCODE_REMOVE_PROJECTILE		0x111
#define CEFFECT_OPCODE_ENABLE_BUTTON			0x117
#define CEFFECT_OPCODE_CUTSCENE_2				0x12A
#define CEFFECT_OPCODE_ANIMATION_REMOVAL		0x13B
#define CEFFECT_OPCODE_SET_STAT					0x13E //318, new in TobEx
#define CEFFECT_OPCODE_USABILITY				0x13F //319, new in BG:EE
#define CEFFECT_OPCODE_CHANGE_WEATHER			0x140 //320, new in BG:EE
#define CEFFECT_OPCODE_REMOVE_EFFECTS_BY_RES	0x141 //321, new in BG:EE

//Effect save types
#define ITEM_SAVINGTHROW_NONE		0x00
#define ITEM_SAVINGTHROW_SPELLS		0x01
#define ITEM_SAVINGTHROW_BREATH		0x02
#define ITEM_SAVINGTHROW_DEATH		0x04
#define ITEM_SAVINGTHROW_WANDS		0x08
#define ITEM_SAVINGTHROW_POLYMORPH	0x10

//Effect save types extras
#define CEFFECT_BYPASS_MIRRORIMAGES	0x01000000 //new in TobEx
#define CEFFECT_STACKING_LIMIT		0x02000000 //new in TobEx
#define CEFFECT_STACKING_SUSPEND	0x04000000 //new in TobEx

#define CGAMEEFFECT_USEDROLL	0x80


struct EffFileData { //size 108h
//AKA CGameEffectBase
	ResRef rHeader; //0h
	int nOpcode; //8h
	int nTarget; //ch
	unsigned int nSplLvl; //10h
	int nParam1; //14h
	int nParam2; //18h

	//note, 'set duration' will always set to a gameTime
	//0: convert to 1000, Apply now, set duration [sec]
	//1: Apply now, add to main effect list (permanent until death)
	//2: Apply now, add to equipped effect list (while equipped)
	//3: convert to 6, Apply later, set duration [sec]
	//4: convert to 7, Apply later, set duration [sec]
	//5: convert to 8, Apply later, set duration [sec]
	//6: if gameTime >= duration (ticks), convert to 1000, Apply now set duration [sec]
	//7: if gameTime >= duration (ticks), convert to 1, Apply now
	//8: if gameTime >= duration (ticks), convert to 2, Apply now
	//9: Apply now, will not be removed from CEffectList
	//10: convert to 1000, Apply now, set duration (duration in ticks)
	//1000: if gameTime < duration (ticks), Apply; else purge
	int nTiming; //1ch, in seconds (converted to ticks)

	unsigned int nDuration; //20h
	short wProbHigh; //24h
	short wProbLow; //26h
	ResRef rResource; //28h
	int nDice; //30h
	int nDieSides; //34h
	unsigned int nSaveType; //38h
	int nSaveBonus; //3ch
	int nSpecial; //40h
	int nType1; //44h
	int u4c; //48h
	int nLevelMin; //4ch
	int nLevelMax; //50h
		
	//bit0: CEFFECTFLAG_DISPELLABLE
	//bit1: CEFFECTFLAG_IGNORE_RESISTANCE
	//bit2: CEFFECTFLAG_IGNORE_SPELL_LVL_RESISTANCE (only for BounceSplLvl[Dec], ProtSplLvl[Dec], and SplLvlTrap; does not affect ProtSplLvl)
	unsigned int dwFlags; //54h, DispelResistFlags
		
	int nParam3; //58h
	int nParam4; //5ch
	int u64; //60h
	int u68; //64h
	ResRef rResource2; //68h
	ResRef rResource3; //70h
	CPoint ptSource; //78h
	CPoint ptDest; //80h
	int nParentResourceType; //88h, 0 = none, 1 = SPL, 2 = ITM
	ResRef rParentResource; //8ch
	unsigned int dwParentFlags; //94h, dwFlags of SplFileData or dwFlags of ItmFileAbility
	int nParentProjectile; //98h, PROJECTL.IDS
	int nParentItemSlot; //9ch
	char variable[32]; //a0h
	int nSourceCreLevel; //c0h
	BOOL bDoSingleUse; //c4h, all effects start with 1, some opcodes will check this, do once off stuff, and then set to 0
	int nType2; //c8h
	int ud0[15]; //cch
};

#endif //FILEEFF_H