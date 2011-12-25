#ifndef RULE_H
#define RULE_H

//CLASS.IDS
const unsigned char MAGE		= 1;
const unsigned char FIGHTER		= 2;
const unsigned char CLERIC		= 3;
const unsigned char THIEF		= 4;
const unsigned char BARD		= 5;
const unsigned char PALADIN		= 6;
const unsigned char DRUID		= 11;
const unsigned char RANGER		= 12;
const unsigned char SORCERER	= 19;
const unsigned char MONK		= 20;

//Game time (in script rounds, i.e. 15 * GTIMES.IDS)
const unsigned long ONE_DAY			= 0x1A5E0; //108000.
const unsigned long ONE_HOUR		= 0x1194; //4500.
const unsigned long SIX_HOURS		= 0x6978; //27000.
const unsigned long SEVEN_HOURS		= 0x7B0C; //31500.
const unsigned long TWELVE_HOURS	= 0xD2F0; //54000.
const unsigned long EIGHTEEN_HOURS  = 0x13C68; //81000.
const unsigned long TWENTYONE_HOURS	= 0x17124; //94500.
const unsigned long TWENTYTWO_HOURS = 0x182B8; //99000.

//KIT.IDS
const unsigned long TRUECLASS				= 0x4000;
const unsigned long BERSERKER				= 0x00000001;
const unsigned long WIZARDSLAYER			= 0x00000002;
const unsigned long KENSAI					= 0x00000004;
const unsigned long CAVALIER				= 0x00000008;
const unsigned long INQUISITOR				= 0x00000010;
const unsigned long UNDEADHUNTER			= 0x00000020;
const unsigned long MAGESCHOOL_ABJURER		= 0x00000040;
const unsigned long MAGESCHOOL_CONJURER		= 0x00000080;
const unsigned long MAGESCHOOL_DIVINER		= 0x00000100;
const unsigned long MAGESCHOOL_ENCHANTER	= 0x00000200;
const unsigned long MAGESCHOOL_ILLUSIONIST	= 0x00000400;
const unsigned long MAGESCHOOL_INVOKER		= 0x00000800;
const unsigned long MAGESCHOOL_NECROMANCER	= 0x00001000;
const unsigned long MAGESCHOOL_TRANSMTUER	= 0x00002000;
const unsigned long MAGESCHOOL_GENERALIST	= 0x00004000;
const unsigned long FERALAN					= 0x00008000;
const unsigned long STALKER					= 0x00010000;
const unsigned long BEASTMASTER				= 0x00020000;
const unsigned long ASSASIN					= 0x00040000;
const unsigned long BOUNTYHUNTER			= 0x00080000;
const unsigned long SWASHBUCKLER			= 0x00100000;
const unsigned long BLADE					= 0x00200000;
const unsigned long JESTER					= 0x00400000;
const unsigned long SKALD					= 0x00800000;
const unsigned long GODTALOS				= 0x01000000;
const unsigned long GODHELM					= 0x02000000;
const unsigned long GODLATHANDER			= 0x04000000;
const unsigned long TOTEMIC					= 0x08000000;
const unsigned long SHAPESHIFTER			= 0x10000000;
const unsigned long BEASTFRIEND				= 0x20000000;
const unsigned long BARBARIAN				= 0x40000000;

//RACE.IDS
const unsigned char HUMAN		= 1;
const unsigned char ELF			= 2;
const unsigned char HALF_ELF	= 3;
const unsigned char DWARF		= 4;
const unsigned char HALFLING	= 5;
const unsigned char GNOME		= 6;
const unsigned char HALFORC		= 7;

//SEQ.IDS
const unsigned short SEQ_ATTACK				= 0;
const unsigned short SEQ_AWAKE				= 1;
const unsigned short SEQ_CAST				= 2;
const unsigned short SEQ_CONJURE			= 3;
const unsigned short SEQ_DAMAGE				= 4;
const unsigned short SEQ_DIE				= 5;
const unsigned short SEQ_HEAD_TURN			= 6;
const unsigned short SEQ_READY				= 7;
const unsigned short SEQ_SHOOT				= 8;
const unsigned short SEQ_TWITCH				= 9;
const unsigned short SEQ_WALK				= 10; //A
const unsigned short SEQ_ATTACK_SLASH		= 11; //B
const unsigned short SEQ_ATTACK_BACKSLASH	= 12; //C
const unsigned short SEQ_ATTACK_JAB			= 13; //D
const unsigned short SEQ_EMERGE				= 14; //E
const unsigned short SEQ_HIDE				= 15; //F
const unsigned short SEQ_SLEEP				= 16; //10

//STATE.IDS
const unsigned long STATE_SLEEPING				= 0x00000001;
const unsigned long STATE_BERSERK				= 0x00000002;
const unsigned long STATE_PANIC					= 0x00000004;
const unsigned long STATE_STUNNED				= 0x00000008;
const unsigned long STATE_INVISIBLE				= 0x00000010;
const unsigned long STATE_HELPLESS				= 0x00000020;
const unsigned long STATE_FROZEN_DEATH			= 0x00000040;
const unsigned long STATE_STONE_DEATH			= 0x00000080;
const unsigned long STATE_EXPLODING_DEATH		= 0x00000100;
const unsigned long STATE_FLAME_DEATH			= 0x00000200;
const unsigned long STATE_ACID_DEATH			= 0x00000400;
const unsigned long STATE_DEAD					= 0x00000800;
const unsigned long STATE_SILENCED				= 0x00001000;
const unsigned long STATE_CHARMED				= 0x00002000;
const unsigned long STATE_POISONED				= 0x00004000;
const unsigned long STATE_HASTED				= 0x00008000;
const unsigned long STATE_SLOWED				= 0x00010000;
const unsigned long STATE_INFRAVISION			= 0x00020000;
const unsigned long STATE_BLIND					= 0x00040000;
const unsigned long STATE_DISEASED				= 0x00080000;
const unsigned long STATE_FEEBLEMINDED			= 0x00100000;
const unsigned long STATE_NONDETECTION			= 0x00200000;
const unsigned long STATE_IMPROVEDINVISIBILITY	= 0x00400000;
const unsigned long STATE_BLESS					= 0x00800000;
const unsigned long STATE_CHANT					= 0x01000000;
const unsigned long STATE_DRAWUPONHOLYMIGHT		= 0x02000000;
const unsigned long STATE_LUCK					= 0x04000000;
const unsigned long STATE_AID					= 0x08000000;
const unsigned long STATE_CHANTBAD				= 0x10000000;
const unsigned long STATE_BLUR					= 0x20000000;
const unsigned long STATE_MIRRORIMAGE			= 0x40000000;
const unsigned long STATE_CONFUSED				= 0x80000000;

#endif //RULE_H