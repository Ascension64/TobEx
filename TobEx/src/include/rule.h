#ifndef RULE_H
#define RULE_H

//CLASS.IDS
const unsigned char CLASS_MAGE		= 1;
const unsigned char CLASS_FIGHTER	= 2;
const unsigned char CLASS_CLERIC	= 3;
const unsigned char CLASS_THIEF		= 4;
const unsigned char CLASS_BARD		= 5;
const unsigned char CLASS_PALADIN	= 6;
const unsigned char CLASS_DRUID		= 11;
const unsigned char CLASS_RANGER	= 12;
const unsigned char CLASS_SORCERER	= 19;
const unsigned char CLASS_MONK		= 20;

//EA.IDS
const unsigned char EA_INANIMATE	= 1;
const unsigned char EA_PC			= 2;
const unsigned char EA_FAMILIAR		= 3;
const unsigned char EA_ALLY			= 4;
const unsigned char EA_CONTROLLED	= 5;
const unsigned char EA_CHARMED		= 6;
const unsigned char EA_GOODBUTRED	= 28;
const unsigned char EA_GOODBUTBLUE	= 29;
const unsigned char EA_GOODCUTOFF	= 30;
const unsigned char EA_NOTGOOD		= 31;
const unsigned char EA_ANYTHING		= 126;
const unsigned char EA_NEUTRAL		= 128;
const unsigned char EA_NOTEVIL		= 199;
const unsigned char EA_EVILCUTOFF	= 200;
const unsigned char EA_EVILBUTGREEN	= 201;
const unsigned char EA_EVILBUTBLUE	= 202;
const unsigned char EA_ENEMY		= 255;

//Facing, Orientation
const short OR_S		= 0;
const short OR_SSW		= 1;
const short OR_SW		= 2;
const short OR_WSW		= 3;
const short OR_W		= 4;
const short OR_WNW		= 5;
const short OR_NW		= 6;
const short OR_NNW		= 7;
const short OR_N		= 8;
const short OR_NNE		= 9;
const short OR_NE		= 10;
const short OR_ENE		= 11;
const short OR_E		= 12;
const short OR_ESE		= 13;
const short OR_SE		= 14;
const short OR_SSE		= 15;

//Game time (in script rounds, i.e. 15 * GTIMES.IDS)
const unsigned int ONE_HOUR			= 0x1194; //4500
const unsigned int SIX_HOURS		= 0x6978; //27000
const unsigned int SEVEN_HOURS		= 0x7B0C; //31500
const unsigned int TWELVE_HOURS		= 0xD2F0; //54000
const unsigned int EIGHTEEN_HOURS	= 0x13C68; //81000
const unsigned int TWENTYONE_HOURS	= 0x17124; //94500
const unsigned int TWENTYTWO_HOURS	= 0x182B8; //99000
const unsigned int ONE_DAY			= 0x1A5E0; //108000

//KIT.IDS
const unsigned int KIT_TRUECLASS			= 0x00004000;

const unsigned int KIT_BERSERKER			= 0x00000001;
const unsigned int KIT_WIZARDSLAYER			= 0x00000002;
const unsigned int KIT_KENSAI				= 0x00000004;
const unsigned int KIT_CAVALIER				= 0x00000008;
const unsigned int KIT_INQUISITOR			= 0x00000010;
const unsigned int KIT_UNDEADHUNTER			= 0x00000020;
const unsigned int MAGESCHOOL_ABJURER		= 0x00000040;
const unsigned int MAGESCHOOL_CONJURER		= 0x00000080;
const unsigned int MAGESCHOOL_DIVINER		= 0x00000100;
const unsigned int MAGESCHOOL_ENCHANTER		= 0x00000200;
const unsigned int MAGESCHOOL_ILLUSIONIST	= 0x00000400;
const unsigned int MAGESCHOOL_INVOKER		= 0x00000800;
const unsigned int MAGESCHOOL_NECROMANCER	= 0x00001000;
const unsigned int MAGESCHOOL_TRANSMUTER	= 0x00002000;
const unsigned int MAGESCHOOL_GENERALIST	= 0x00004000;
const unsigned int KIT_FERALAN				= 0x00008000;
const unsigned int KIT_STALKER				= 0x00010000;
const unsigned int KIT_BEASTMASTER			= 0x00020000;
const unsigned int KIT_ASSASIN				= 0x00040000;
const unsigned int KIT_BOUNTYHUNTER			= 0x00080000;
const unsigned int KIT_SWASHBUCKLER			= 0x00100000;
const unsigned int KIT_BLADE				= 0x00200000;
const unsigned int KIT_JESTER				= 0x00400000;
const unsigned int KIT_SKALD				= 0x00800000;
const unsigned int KIT_GODTALOS				= 0x01000000;
const unsigned int KIT_GODHELM				= 0x02000000;
const unsigned int KIT_GODLATHANDER			= 0x04000000;
const unsigned int KIT_TOTEMIC				= 0x08000000;
const unsigned int KIT_SHAPESHIFTER			= 0x10000000;
const unsigned int KIT_BEASTFRIEND			= 0x20000000;
const unsigned int KIT_BARBARIAN			= 0x40000000;

//RACE.IDS
const unsigned char RACE_HUMAN		= 1;
const unsigned char RACE_ELF		= 2;
const unsigned char RACE_HALF_ELF	= 3;
const unsigned char RACE_DWARF		= 4;
const unsigned char RACE_HALFLING	= 5;
const unsigned char RACE_GNOME		= 6;
const unsigned char RACE_HALFORC	= 7;

//SEQ.IDS
const short SEQ_ATTACK				= 0;
const short SEQ_AWAKE				= 1;
const short SEQ_CAST				= 2;
const short SEQ_CONJURE				= 3;
const short SEQ_DAMAGE				= 4;
const short SEQ_DIE					= 5;
const short SEQ_HEAD_TURN			= 6;
const short SEQ_READY				= 7;
const short SEQ_SHOOT				= 8;
const short SEQ_TWITCH				= 9;
const short SEQ_WALK				= 10; //A
const short SEQ_ATTACK_SLASH		= 11; //B
const short SEQ_ATTACK_BACKSLASH	= 12; //C
const short SEQ_ATTACK_JAB			= 13; //D
const short SEQ_EMERGE				= 14; //E
const short SEQ_HIDE				= 15; //F
const short SEQ_SLEEP				= 16; //10

//SLOTS.IDS
const char SLOT_AMULET			= 0;
const char SLOT_ARMOR			= 1;
const char SLOT_BELT			= 2;
const char SLOT_BOOTS			= 3;
const char SLOT_CLOAK			= 4;
const char SLOT_GAUNTLETS		= 5;
const char SLOT_HELMET			= 6;
const char SLOT_RING_LEFT		= 7;
const char SLOT_RING_RIGHT		= 8;
const char SLOT_SHIELD			= 9;
const char SLOT_FIST			= 10;
const char SLOT_AMMO0			= 11;
const char SLOT_AMMO1			= 12;
const char SLOT_AMMO2			= 13;
const char SLOT_AMMO3			= 14;
const char SLOT_MISC0			= 15;
const char SLOT_MISC1			= 16;
const char SLOT_MISC2			= 17;
const char SLOT_MISC3			= 18;
const char SLOT_MISC4			= 19;
const char SLOT_MISC5			= 20;
const char SLOT_MISC6			= 21;
const char SLOT_MISC7			= 22;
const char SLOT_MISC8			= 23;
const char SLOT_MISC9			= 24;
const char SLOT_MISC10			= 25;
const char SLOT_MISC11			= 26;
const char SLOT_MISC12			= 27;
const char SLOT_MISC13			= 28;
const char SLOT_MISC14			= 29;
const char SLOT_MISC15			= 30;
const char SLOT_MISC16			= 31;
const char SLOT_MISC17			= 32;
const char SLOT_MISC18			= 33;
const char SLOT_MISC19			= 34;
const char SLOT_WEAPON0			= 35;
const char SLOT_WEAPON1			= 36;
const char SLOT_WEAPON2			= 37;
const char SLOT_WEAPON3			= 38;

//STATE.IDS
const unsigned int STATE_SLEEPING				= 0x00000001;
const unsigned int STATE_BERSERK				= 0x00000002;
const unsigned int STATE_PANIC					= 0x00000004;
const unsigned int STATE_STUNNED				= 0x00000008;
const unsigned int STATE_INVISIBLE				= 0x00000010;
const unsigned int STATE_HELPLESS				= 0x00000020;
const unsigned int STATE_FROZEN_DEATH			= 0x00000040;
const unsigned int STATE_STONE_DEATH			= 0x00000080;
const unsigned int STATE_EXPLODING_DEATH		= 0x00000100;
const unsigned int STATE_FLAME_DEATH			= 0x00000200;
const unsigned int STATE_ACID_DEATH				= 0x00000400;
const unsigned int STATE_DEAD					= 0x00000800;
const unsigned int STATE_SILENCED				= 0x00001000;
const unsigned int STATE_CHARMED				= 0x00002000;
const unsigned int STATE_POISONED				= 0x00004000;
const unsigned int STATE_HASTED					= 0x00008000;
const unsigned int STATE_SLOWED					= 0x00010000;
const unsigned int STATE_INFRAVISION			= 0x00020000;
const unsigned int STATE_BLIND					= 0x00040000;
const unsigned int STATE_DISEASED				= 0x00080000;
const unsigned int STATE_FEEBLEMINDED			= 0x00100000;
const unsigned int STATE_NONDETECTION			= 0x00200000;
const unsigned int STATE_IMPROVEDINVISIBILITY	= 0x00400000;
const unsigned int STATE_BLESS					= 0x00800000;
const unsigned int STATE_CHANT					= 0x01000000;
const unsigned int STATE_DRAWUPONHOLYMIGHT		= 0x02000000;
const unsigned int STATE_LUCK					= 0x04000000;
const unsigned int STATE_AID					= 0x08000000;
const unsigned int STATE_CHANTBAD				= 0x10000000;
const unsigned int STATE_BLUR					= 0x20000000;
const unsigned int STATE_MIRRORIMAGE			= 0x40000000;
const unsigned int STATE_CONFUSED				= 0x80000000;

#endif //RULE_H