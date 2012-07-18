#ifndef DATACONS_H
#define DATACONS_H

//Area search map conversions
#define PIXELS_PER_SEARCHMAP_PT_X	16
#define PIXELS_PER_SEARCHMAP_PT_Y	12

//Creature flags
#define CREFLAG_FALLEN_PALADIN	0x0200
#define CREFLAG_FALLEN_RANGER	0x0400

//Creature item flags
#define CREITEM_IDENTIFIED		0x1
#define CREITEM_UNSTEALABLE		0x2
#define CREITEM_STOLEN			0x4
#define CREITEM_UNDROPPABLE		0x8

//Creature memorized spell flags
#define CREMEMSPELL_MEMORIZED		0x0001

//Creature saving throw flags
#define CRESAVE_USED	0x80

//Effect timing modes
#define TIMING_INSTANT_LIMITED			0
#define TIMING_INSTANT_PERMANENT		1
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
#define CEFFECT_OPCODE_ATTACKS_PER_ROUND	0x001
#define CEFFECT_OPCODE_AWAKEN				0x002
#define CEFFECT_OPCODE_CHARISMA_MOD			0x006
#define CEFFECT_OPCODE_CONSTITUTION_MOD		0x00A
#define CEFFECT_OPCODE_DAMAGE				0x00C
#define CEFFECT_OPCODE_INSTANT_DEATH		0x00D
#define CEFFECT_OPCODE_DEXTERITY_MOD		0x00F
#define CEFFECT_OPCODE_CURRENTHP_MOD		0x011
#define CEFFECT_OPCODE_INTELLIGENCE_MOD		0x013
#define CEFFECT_OPCODE_LORE_MOD				0x015
#define CEFFECT_OPCODE_LUCK_MOD				0x016
#define CEFFECT_OPCODE_POISON				0x019
#define CEFFECT_OPCODE_SAVE_VS_DEATH_MOD	0x021
#define CEFFECT_OPCODE_SAVE_VS_WANDS_MOD	0x022
#define CEFFECT_OPCODE_SAVE_VS_POLY_MOD		0x023
#define CEFFECT_OPCODE_SAVE_VS_BREATH_MOD	0x024
#define CEFFECT_OPCODE_SAVE_VS_SPELL_MOD	0x025
#define CEFFECT_OPCODE_UNCONSCIOUSNESS		0x027
#define CEFFECT_OPCODE_MAGE_MEM_SPELL_MOD	0x02A
#define CEFFECT_OPCODE_STRENGTH_MOD			0x02C
#define CEFFECT_OPCODE_WISDOM_MOD			0x031
#define CEFFECT_OPCODE_DISPEL				0x03A
#define CEFFECT_OPCODE_STEALTH_MOD			0x03B
#define CEFFECT_OPCODE_PRIEST_MEM_SPELL_MOD	0x03E
#define CEFFECT_OPCODE_BLINDNESS			0x04A
#define CEFFECT_OPCODE_DISEASE				0x04E
#define CEFFECT_OPCODE_OPEN_LOCKS_MOD		0x05A
#define CEFFECT_OPCODE_FIND_TRAPS_MOD		0x05B
#define CEFFECT_OPCODE_PICK_POCKETS_MOD		0x05C
#define CEFFECT_OPCODE_FATIGUE_MOD			0x05D
#define CEFFECT_OPCODE_INTOXICATION_MOD		0x05E
#define CEFFECT_OPCODE_TRACKING_MOD			0x05F
#define CEFFECT_OPCODE_LEVEL_MOD			0x060
#define CEFFECT_OPCODE_STRENGTH_EX_MOD		0x061
#define CEFFECT_OPCODE_REGENERATION			0x062
#define CEFFECT_OPCODE_MORALE_BREAK_MOD		0x06A
#define CEFFECT_OPCODE_REPUTATION_MOD		0x06C
#define CEFFECT_OPCODE_AID					0x081
#define CEFFECT_OPCODE_BLESS				0x082
#define CEFFECT_OPCODE_CHANT				0x083
#define CEFFECT_OPCODE_HOLY_MIGHT			0x084
#define CEFFECT_OPCODE_CHANT_BAD			0x089
#define CEFFECT_OPCODE_DISPLAY_ICON			0x08E
#define CEFFECT_OPCODE_DISABLE_BUTTON		0x090
#define CEFFECT_OPCODE_DISABLE_SPELLTYPE	0x091
#define CEFFECT_OPCODE_CAST_SPELL			0x092
#define CEFFECT_OPCODE_LEARN_SPELL			0x093
#define CEFFECT_OPCODE_MAGIC_RESIST_MOD		0x0A6
#define CEFFECT_OPCODE_USE_EFF_FILE			0x0B1
#define CEFFECT_OPCODE_MOVE_TO_AREA			0x0BA
#define CEFFECT_OPCODE_FREEDOM				0x0D4
#define CEFFECT_OPCODE_CAST_SPELL_FROM_LIST	0x0D6
#define CEFFECT_OPCODE_CAST_SPELL_CONDITION	0x0E8
#define CEFFECT_OPCODE_PROFICIENCY_MOD		0x0E9
#define CEFFECT_OPCODE_WING_BUFFET			0x0EB
#define CEFFECT_OPCODE_DISINTEGRATE			0x0EE
#define CEFFECT_OPCODE_AVATAR_REMOVAL		0x10F
#define CEFFECT_OPCODE_REPEATING_EFFECT		0x110
#define CEFFECT_OPCODE_REMOVE_PROJECTILE	0x111
#define CEFFECT_OPCODE_ENABLE_BUTTON		0x117
#define CEFFECT_OPCODE_CUTSCENE_2			0x12A
#define CEFFECT_OPCODE_ANIMATION_REMOVAL	0x13B
#define CEFFECT_OPCODE_SET_STAT				0x13E //added by TobEx

//Effect save types
#define CEFFECT_SAVETYPE_NONE		0x00
#define CEFFECT_SAVETYPE_SPELLS		0x01
#define CEFFECT_SAVETYPE_BREATH		0x02
#define CEFFECT_SAVETYPE_DEATH		0x04
#define CEFFECT_SAVETYPE_WANDS		0x08
#define CEFFECT_SAVETYPE_POLYMORPH	0x10

//Item flags
#define ITEMFLAG_CRITICAL			0x00000001
#define ITEMFLAG_TWO_HANDED			0x00000002
#define ITEMFLAG_DROPPABLE			0x00000004
#define ITEMFLAG_DISPLAYABLE		0x00000008 //unused in BG2?
#define ITEMFLAG_CURSED				0x00000010
#define ITEMFLAG_NOT_COPYABLE		0x00000020 //unused in BG2?
#define ITEMFLAG_MAGICAL			0x00000040 //unused in BG2?
#define ITEMFLAG_BOW				0x00000080 //unused in BG2?
#define ITEMFLAG_SILVER				0x00000100
#define ITEMFLAG_COLD_IRON			0x00000200
#define ITEMFLAG_STOLEN				0x00000400
#define ITEMFLAG_CONVERSABLE		0x00000800
#define ITEMFLAG_NOT_DISPELLABLE	0x01000000 //new in TobEx, tob_hacks, Spell Revisions
#define ITEMFLAG_TOGGLE_CRITICALHIT	0x02000000 //new in TobEx
#define ITEMFLAG_NO_TARGET_INVIS	0x04000000 //new in TobEx

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
#define ITEMABILITYFLAG_BYPASS_MIRROR_IMAGE		0x01000000 //new in TobEx, tob_hacks, Spell Revisions
#define ITEMABILITYFLAG_TOGGLE_BACKSTAB			0x02000000 //new by TobEx

//Spell flags
#define SPELLFLAG_HOSTILE			0x00000400 //lose invis when cast on self
#define SPELLFLAG_IGNORE_LOS		0x00000800
#define SPELLFLAG_OUTDOOR			0x00002000
#define SPELLFLAG_NONMAGICAL		0x00004000
#define SPELLFLAG_CONDITIONAL		0x00008000
#define SPELLFLAG_NONCOMBAT			0x00010000
#define SPELLFLAG_TARGET_INVISIBLE	0x01000000 //new in TobEx
#define SPELLFLAG_NO_VOICE			0x02000000 //new in TobEx

//Spell types
#define SPELLTYPE_SPECIAL	0
#define SPELLTYPE_MAGE		1
#define SPELLTYPE_PRIEST	2
#define SPELLTYPE_PSIONIC	3
#define SPELLTYPE_INNATE	4
#define SPELLTYPE_BARDSONG	5

//Store flags
#define STOREFLAG_BUY		0x1
#define STOREFLAG_SELL		0x2
#define STOREFLAG_IDENTIFY	0x4
#define STOREFLAG_STEAL		0x8
#define STOREFLAG_DONATE	0x10
#define STOREFLAG_SPELLS	0x20
#define STOREFLAG_DRINKS	0x40
#define STOREFLAG_QUALITY_1	0x200
#define STOREFLAG_QUALITY_2	0x400
#define STOREFLAG_FENCE		0x1000
#define STOREFLAG_RECHARGE	0x4000

//Store types
#define STORETYPE_STORE		0
#define STORETYPE_TAVERN	1
#define STORETYPE_INN		2
#define STORETYPE_TEMPLE	3
#define STORETYPE_4			4
#define STORETYPE_BAG		5

//Vvc orientation flags
#define VVCORIENTATION_PREVIOUS	0x0
#define VVCORIENTATION_ORIGIN	0x1
#define VVCORIENTATION_PARENT	0x4
#define VVCORIENTATION_IGNORE	0x8

#endif //DATACONS_H