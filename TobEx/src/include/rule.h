#ifndef RULE_H
#define RULE_H

//ALIGN.IDS
const char ALIGN_ANY				= 0x00;
const char ALIGN_LAWFUL_GOOD		= 0x11;
const char ALIGN_LAWFUL_NEUTRAL		= 0x12;
const char ALIGN_LAWFUL_EVIL		= 0x13;
const char ALIGN_NEUTRAL_GOOD		= 0x21;
const char ALIGN_NEUTRAL			= 0x22;
const char ALIGN_NEUTRAL_EVIL		= 0x23;
const char ALIGN_CHAOTIC_GOOD		= 0x31;
const char ALIGN_CHAOTIC_NEUTRAL	= 0x32;
const char ALIGN_CHAOTIC_EVIL		= 0x33;
const char ALIGN_MASK_GOOD			= 0x01;
const char ALIGN_MASK_NEUTRAL		= 0x02;
const char ALIGN_MASK_EVIL			= 0x03;
const char ALIGN_LAWFUL_MASK		= 0x10;
const char ALIGN_NEUTRAL_MASK		= 0x20;
const char ALIGN_CHAOTIC_MASK		= 0x30;

//ACTION.IDS
const short ACTION_SET_GLOBAL				= 30;
const short ACTION_SPELL					= 31;
const short ACTION_SPELL_POINT				= 95;
const short ACTION_INCREMENT_GLOBAL			= 109;
const short ACTION_BREAK_INSTANTS			= 178;
const short ACTION_SPELL_NO_DEC				= 191;
const short ACTOIN_SPELL_POINT_NO_DEC		= 192;
const short ACTION_SG						= 307;
const short ACTION_LOSE_GAME				= 352; //new in TobEx
const short ACTION_DIALOG_SET_GLOBAL		= 353; //new in TobEx
const short ACTION_DIALOG_INCREMENT_GLOBAL	= 354; //new in TobEx
const short ACTION_DIALOG_SG				= 355; //new in TobEx

//CLASS.IDS
const unsigned char CLASS_ANY					= 0;
const unsigned char CLASS_MAGE					= 1;
const unsigned char CLASS_FIGHTER				= 2;
const unsigned char CLASS_CLERIC				= 3;
const unsigned char CLASS_THIEF					= 4;
const unsigned char CLASS_BARD					= 5;
const unsigned char CLASS_PALADIN				= 6;
const unsigned char CLASS_FIGHTER_MAGE			= 7;
const unsigned char CLASS_FIGHTER_CLERIC		= 8;
const unsigned char CLASS_FIGHTER_THIEF			= 9;
const unsigned char CLASS_FIGHTER_MAGE_THIEF	= 10;
const unsigned char CLASS_DRUID					= 11;
const unsigned char CLASS_RANGER				= 12;
const unsigned char CLASS_MAGE_THIEF			= 13;
const unsigned char CLASS_CLERIC_MAGE			= 14;
const unsigned char CLASS_CLERIC_THIEF			= 15;
const unsigned char CLASS_FIGHTER_DRUID			= 16;
const unsigned char CLASS_FIGHTER_MAGE_CLERIC	= 17;
const unsigned char CLASS_CLERIC_RANGER			= 18;
const unsigned char CLASS_SORCERER				= 19;
const unsigned char CLASS_MONK					= 20;

//DMGTYPE.IDS
const unsigned int DAMAGETYPE_CRUSHING		= 0x00000000;
const unsigned int DAMAGETYPE_ACID			= 0x00010000;
const unsigned int DAMAGETYPE_COLD			= 0x00020000;
const unsigned int DAMAGETYPE_ELECTRICITY	= 0x00040000;
const unsigned int DAMAGETYPE_FIRE			= 0x00080000;
const unsigned int DAMAGETYPE_PIERCING		= 0x00100000;
const unsigned int DAMAGETYPE_POISON		= 0x00200000;
const unsigned int DAMAGETYPE_MAGIC			= 0x00400000;
const unsigned int DAMAGETYPE_MISSILE		= 0x00800000;
const unsigned int DAMAGETYPE_SLASHING		= 0x01000000;
const unsigned int DAMAGETYPE_MAGICFIRE		= 0x02000000;
const unsigned int DAMAGETYPE_MAGICCOLD		= 0x04000000;
const unsigned int DAMAGETYPE_STUNNING		= 0x08000000;

//EA.IDS
const unsigned char EA_INANIMATE			= 1;
const unsigned char EA_PC					= 2;
const unsigned char EA_FAMILIAR				= 3;
const unsigned char EA_ALLY					= 4;
const unsigned char EA_CONTROLLED			= 5;
const unsigned char EA_CHARMED				= 6;
const unsigned char EA_CONTROLLEDFORCEADD	= 7; //force add to controlled objects list
const unsigned char EA_CONTROLLEDCUTOFF		= 15;
const unsigned char EA_GOODBUTRED			= 28;
const unsigned char EA_GOODBUTBLUE			= 29;
const unsigned char EA_GOODCUTOFF			= 30;
const unsigned char EA_NOTGOOD				= 31;
const unsigned char EA_ANYTHING				= 126;
const unsigned char EA_NEUTRAL				= 128;
const unsigned char EA_GOODOREVIL			= 198;
const unsigned char EA_NOTEVIL				= 199;
const unsigned char EA_EVILCUTOFF			= 200;
const unsigned char EA_EVILBUTGREEN			= 201;
const unsigned char EA_EVILBUTBLUE			= 202;
const unsigned char EA_SPECIFICGROUP		= 253;
const unsigned char EA_ENEMY				= 255;

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

//GENERAL.IDS
const unsigned char GENDER_ANY		= 0;

//GENDER.IDS
const unsigned char GENDER_MALE		= 1;
const unsigned char GENDER_FEMALE	= 2;
const unsigned char GENDER_OTHER	= 3;
const unsigned char GENDER_NIETHER	= 4;

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

//OBJECT.IDS
const unsigned char OBJECT_NOTHING			= 0;
const unsigned char OBJECT_MYSELF			= 1;
const unsigned char OBJECT_LEADEROF			= 2;
const unsigned char OBJECT_GROUPOF			= 3;
const unsigned char OBJECT_WEAKESTOF		= 4;
const unsigned char OBJECT_STRONGESTOF		= 5;
const unsigned char OBJECT_MOSTDAMAGEDOF	= 6;
const unsigned char OBJECT_LEASTDAMAGEDOF	= 7;
const unsigned char OBJECT_PROTECTEDBY		= 8;
const unsigned char OBJECT_PROTECTOROF		= 9;
const unsigned char OBJECT_LASTATTACKEROF	= 10;
const unsigned char OBJECT_LASTTARGETEDBY	= 11;
const unsigned char OBJECT_NEARESTENEMYOF	= 12;
const unsigned char OBJECT_LASTCOMMANDEDBY	= 13;
const unsigned char OBJECT_NEAREST			= 14;
const unsigned char OBJECT_LASTHITTER		= 15;
const unsigned char OBJECT_LASTHELP			= 16;
const unsigned char OBJECT_LASTTRIGGER		= 17;
const unsigned char OBJECT_LASTSEENBY		= 18;
const unsigned char OBJECT_LASTTALKEDTOBY	= 19;
const unsigned char OBJECT_LASTHEARDBY		= 20;
const unsigned char OBJECT_PLAYER1			= 21;
const unsigned char OBJECT_PLAYER2			= 22;
const unsigned char OBJECT_PLAYER3			= 23;
const unsigned char OBJECT_PLAYER4			= 24;
const unsigned char OBJECT_PLAYER5			= 25;
const unsigned char OBJECT_PLAYER6			= 26;
const unsigned char OBJECT_PROTAGONIST		= 27;
const unsigned char OBJECT_STRONGESTOFMALE	= 28;
const unsigned char OBJECT_2NEARESTENEMYOF	= 29;
const unsigned char OBJECT_3NEARESTENEMYOF	= 30;
const unsigned char OBJECT_4NEARESTENEMYOF	= 31;
const unsigned char OBJECT_5NEARESTENEMYOF	= 32;

//RACE.IDS
const unsigned char RACE_ANY		= 0;
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
const char SLOT_MISC0			= 15; //QUICK1
const char SLOT_MISC1			= 16; //QUICK2
const char SLOT_MISC2			= 17; //QUICK3
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

//SPECIFIC.IDS
const unsigned int SPECIFIC_ANY	= 0;

//STATS.IDS
const unsigned short  STATS_PROFICIENCYBASTARDSWORD				=  89;
const unsigned short  STATS_PROFICIENCYLONGSWORD				=  90;
const unsigned short  STATS_PROFICIENCYSHORTSWORD				=  91;
const unsigned short  STATS_PROFICIENCYAXE						=  92;
const unsigned short  STATS_PROFICIENCYTWOHANDEDSWORD			=  93;
const unsigned short  STATS_PROFICIENCYKATANA					=  94;
const unsigned short  STATS_PROFICIENCYSCIMITARWAKISASHININJATO	=  95;
const unsigned short  STATS_PROFICIENCYDAGGER					=  96;
const unsigned short  STATS_PROFICIENCYWARHAMMER				=  97;
const unsigned short  STATS_PROFICIENCYSPEAR					=  98;
const unsigned short  STATS_PROFICIENCYHALBERD					=  99;
const unsigned short  STATS_PROFICIENCYFLAILMORNINGSTAR			=  100;
const unsigned short  STATS_PROFICIENCYMACE						=  101;
const unsigned short  STATS_PROFICIENCYQUARTERSTAFF				=  102;
const unsigned short  STATS_PROFICIENCYCROSSBOW					=  103;
const unsigned short  STATS_PROFICIENCYLONGBOW					=  104;
const unsigned short  STATS_PROFICIENCYSHORTBOW					=  105;
const unsigned short  STATS_PROFICIENCYDART						=  106;
const unsigned short  STATS_PROFICIENCYSLING					=  107;
const unsigned short  STATS_PROFICIENCYBLACKJACK				=  108;
const unsigned short  STATS_PROFICIENCYGUN						=  109;
const unsigned short  STATS_PROFICIENCYMARTIALARTS				=  110;
const unsigned short  STATS_PROFICIENCY2HANDED					=  111;
const unsigned short  STATS_PROFICIENCYSWORDANDSHIELD			=  112;
const unsigned short  STATS_PROFICIENCYSINGLEWEAPON				=  113;
const unsigned short  STATS_PROFICIENCY2WEAPON					=  114;
const unsigned short  STATS_EXTRAPROFICIENCY1					=  115;
const unsigned short  STATS_EXTRAPROFICIENCY2					=  116;
const unsigned short  STATS_EXTRAPROFICIENCY3					=  117;
const unsigned short  STATS_EXTRAPROFICIENCY4					=  118;
const unsigned short  STATS_EXTRAPROFICIENCY5					=  119;
const unsigned short  STATS_EXTRAPROFICIENCY6					=  120;
const unsigned short  STATS_EXTRAPROFICIENCY7					=  121;
const unsigned short  STATS_EXTRAPROFICIENCY8					=  122;
const unsigned short  STATS_EXTRAPROFICIENCY9					=  123;
const unsigned short  STATS_EXTRAPROFICIENCY10					=  124;
const unsigned short  STATS_EXTRAPROFICIENCY11					=  125;
const unsigned short  STATS_EXTRAPROFICIENCY12					=  126;
const unsigned short  STATS_EXTRAPROFICIENCY13					=  127;
const unsigned short  STATS_EXTRAPROFICIENCY14					=  128;
const unsigned short  STATS_EXTRAPROFICIENCY15					=  129;
const unsigned short  STATS_EXTRAPROFICIENCY16					=  130;
const unsigned short  STATS_EXTRAPROFICIENCY17					=  131;
const unsigned short  STATS_EXTRAPROFICIENCY18					=  132;
const unsigned short  STATS_EXTRAPROFICIENCY19					=  133;
const unsigned short  STATS_EXTRAPROFICIENCY20					=  134;

//TRIGGER.IDS
const short TRIGGER_NONE						= 0x0000;
const short TRIGGER_ATTACKED_BY					= 0x0002;
const short TRIGGER_SEE							= 0x401C;
const short TRIGGER_HIT_BY						= 0x0020;
const short TRIGGER_HP_PERCENT_LT				= 0x402D;
const short TRIGGER_STATE_CHECK					= 0x4037;
const short TRIGGER_OR							= 0x4089;
const short TRIGGER_PERSONAL_SPACE_DISTANCE		= 0x40B3;
const short TRIGGER_TOOK_DAMAGE					= 0x00CC;
const short TRIGGER_NEXT_TRIGGER_OBJECT			= 0x4100; //new in TobEx
const short TRIGGER_MOVEMENT_RATE				= 0x4101; //new in TobEx
const short TRIGGER_MOVEMENT_RATE_GT			= 0x4102; //new in TobEx
const short TRIGGER_MOVEMENT_RATE_LT			= 0x4103; //new in TobEx
const short TRIGGER_NUM_MIRRORIMAGES			= 0x4104; //new in TobEx
const short TRIGGER_NUM_MIRRORIMAGES_GT			= 0x4105; //new in TobEx
const short TRIGGER_NUM_MIRRORIMAGES_LT			= 0x4106; //new in TobEx
const short TRIGGER_BOUNCING_SPELL_LEVEL		= 0x4107; //new in TobEx
const short TRIGGER_NUM_BOUNCING_SPELL_LEVEL	= 0x4108; //new in TobEx
const short TRIGGER_NUM_BOUNCING_SPELL_LEVEL_GT	= 0x4109; //new in TobEx
const short TRIGGER_NUM_BOUNCING_SPELL_LEVEL_LT	= 0x410A; //new in TobEx
const short TRIGGER_IMMUNE_SPELL_LEVEL			= 0x410B; //new in TobEx
const short TRIGGER_NUM_IMMUNE_SPELL_LEVEL		= 0x410C; //new in TobEx
const short TRIGGER_NUM_IMMUNE_SPELL_LEVEL_GT	= 0x410D; //new in TobEx
const short TRIGGER_NUM_IMMUNE_SPELL_LEVEL_LT	= 0x410E; //new in TobEx
const short TRIGGER_TIME_STOP_COUNTER			= 0x410F; //new in TobEx
const short TRIGGER_TIME_STOP_COUNTER_GT		= 0x4110; //new in TobEx
const short TRIGGER_TIME_STOP_COUNTER_LT		= 0x4111; //new in TobEx
const short TRIGGER_TIME_STOP_OBJECT			= 0x4112; //new in TobEx
const short TRIGGER_NUM_TRAPPING_SPELL_LEVEL	= 0x4113; //new in TobEx
const short TRIGGER_NUM_TRAPPING_SPELL_LEVEL_GT	= 0x4114; //new in TobEx
const short TRIGGER_NUM_TRAPPING_SPELL_LEVEL_LT	= 0x4115; //new in TobEx
const short TRIGGER_ORIGINAL_CLASS				= 0x4116; //new in TobEx
const short TRIGGER_HP_LOST						= 0x4117; //new in TobEx
const short TRIGGER_HP_LOST_GT					= 0x4118; //new in TobEx
const short TRIGGER_HP_LOST_LT					= 0x4119; //new in TobEx

#endif //RULE_H