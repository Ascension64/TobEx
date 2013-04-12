#ifndef FILEPRO_H
#define FILEPRO_H

#include "stdafx.h"
#include "resref.h"

struct ProFileBase {
	WORD m_wFileType; // list of projectile file types, default PROFILE_FILETYPE_PROJECTILEBAM
	SHORT m_speed; // number, default 20
	DWORD m_dwFlags;
	ResRef m_fireSoundRef; // string, default empty
	ResRef m_arrivalSoundRef; // string, default empty
	ResRef m_visualEffectRef; // string, default empty
	SHORT m_sparkleColor; // list of sparkle colors, default CSPARKLE_COLORTYPE_BLACK 

	BYTE padding[2];
	DWORD reservedSpace[53];
};

#define PROFILE_FILETYPE_PROJECTILE 0x0001
#define PROFILE_FILETYPE_PROJECTILEBAM    0x0002
#define PROFILE_FILETYPE_PROJECTILEAREA   0x0003

#define PROFILE_FLAGS_SPARKLETRAIL		0x00000001  // default OFF
#define PROFILE_FLAGS_HASHEIGHT			0x00000002  // default ON
#define PROFILE_FLAGS_LOOPFIRESOUND 0x00000004  // default OFF
#define PROFILE_FLAGS_LOOPARRIVALSOUND    0x00000008  // default OFF
#define PROFILE_FLAGS_IGNORETARGET		0x00000010  // default OFF
#define PROFILE_FLAGS_BACKLIST			0x00000020  // default OFF

#define CSPARKLE_COLORTYPE_BLACK		0x0001
#define CSPARKLE_COLORTYPE_BLUE			0x0002
#define CSPARKLE_COLORTYPE_CHROMATIC	0x0003
#define CSPARKLE_COLORTYPE_GOLD			0x0004
#define CSPARKLE_COLORTYPE_GREEN		0x0005
#define CSPARKLE_COLORTYPE_PURPLE		0x0006
#define CSPARKLE_COLORTYPE_RED			0x0007
#define CSPARKLE_COLORTYPE_WHITE		0x0008
#define CSPARKLE_COLORTYPE_ICE			0x0009
#define CSPARKLE_COLORTYPE_STONE		0x000A
#define CSPARKLE_COLORTYPE_MAGENTA		0x000B
#define CSPARKLE_COLORTYPE_ORANGE		0x000C

#define PROFILEBAM_NUMCOLORS 7

#define PROFILEBAMFLAGS_FALSECOLORED			0x00000001      // default OFF
#define PROFILEBAMFLAGS_SMOKE				0x00000002      // default OFF
#define PROFILEBAMFLAGS_SMOKEFALSECOLORED	0x00000004      // default ON
#define PROFILEBAMFLAGS_TINT 0x00000008      // default ON
#define PROFILEBAMFLAGS_HEIGHT				0x00000010      // default OFF
#define PROFILEBAMFLAGS_SHADOW				0x00000020      // default OFF
#define PROFILEBAMFLAGS_GLOW 0x00000040      // default OFF
#define PROFILEBAMFLAGS_BRIGHTEST			0x00000080      // default OFF
#define PROFILEBAMFLAGS_BRIGHTESTIFFAST		0x00000100      // default OFF
#define PROFILEBAMFLAGS_BRIGHTEST3DONLYOFF	0x00000200      // default OFF

#define PROFILEBAMFLAGS_PUFF_ATTARGET	0x00000001      // default OFF
#define PROFILEBAMFLAGS_PUFF_ATSOURCE	0x00000002      // default OFF

// 504 bytes in size
struct ProFileBAM {
	DWORD m_dwBAMFlags;
	ResRef m_vidCell; // string, default empty
	ResRef m_shadowVidCell; // string, default empty
	BYTE m_seqVidCell; // number, default 0
	BYTE m_seqShadowVidCell; // number, default 0
	SHORT m_glowIntensity; // number, default 0
	SHORT m_glowSizeX; // number, default 0
	SHORT m_glowSizeY; // number, default 0
	ResRef m_paletteResRef; // string, default empty
	BYTE m_colors[PROFILEBAM_NUMCOLORS]; // list of color ranges, default CVIDPALETTE_HAIR_BLACK
	BYTE m_smokePeriod; // number, default 1
	BYTE m_smokeColors[PROFILEBAM_NUMCOLORS]; // list of color ranges, default CVIDPALETTE_CLOTH_DK_GREY
	BYTE m_numDirections; // list of {1, 5, 9}, default of 1
	WORD m_smokeAnimationCode; // list of animation codes, default of CGAMEANIMATIONTYPE_SMOKE_PUFF_LARGE

	ResRef m_cPuffEffect1;
	ResRef m_cPuffEffect2;
	ResRef m_cPuffEffect3;
	WORD m_nPuff1Spacing;
	WORD m_nPuff2Spacing;
	WORD m_nPuff3Spacing;
	DWORD m_dwPuffFlags;

	DWORD reservedSpace[42];
};

#define PROFILEAREA_FLAGS_CENTERBAM					0x00000001  // default OFF
#define PROFILEAREA_FLAGS_CHECKFORNONSPRITES		0x00000002  // default OFF
#define PROFILEAREA_FLAGS_DETONATEONLYIFTARGETS		0x00000004  // default OFF
#define PROFILEAREA_FLAGS_DELAYEDTRIGGER			0x00000008  // default OFF
#define PROFILEAREA_FLAGS_SPARKLEEXPLOSION			0x00000010  // default OFF
#define PROFILEAREA_FLAGS_CHUNKSEXPLOSION			0x00000020  // default OFF
#define PROFILEAREA_FLAGS_LIMITTARGETS				0x00000040  // default OFF
#define PROFILEAREA_FLAGS_PARTYONLY					0x00000080  // default ON
#define PROFILEAREA_FLAGS_DURATIONEQUALWIZLEVEL		0x00000100  // default OFF
#define PROFILEAREA_FLAGS_DURATIONEQUALPRSLEVEL		0x00000200  // default OFF
#define PROFILEAREA_FLAGS_VVCATCENTER				0x00000400  // default OFF
#define PROFILEAREA_FLAGS_CONEFROMCASTER			0x00000800  // default OFF
#define PROFILEAREA_FLAGS_IGNORELOS					0x00001000  // default OFF
#define PROFILEAREA_FLAGS_CENTERBAMWAIT				0x00002000  // default OFF
#define PROFILEAREA_FLAGS_FORCEINITIALDELAY  		0x00004000  // default OFF
#define PROFILEAREA_FLAGS_ONETARGETONLY				0x00008000  // default OFF

#define CGAMEFIREBALL_TYPE_NONE					MAXBYTE
#define CGAMEFIREBALL_TYPE_FIRE					0
#define CGAMEFIREBALL_TYPE_CLOUD				1
#define CGAMEFIREBALL_TYPE_CLOUDKILL   			2
#define CGAMEFIREBALL_TYPE_STORM				3
#define CGAMEFIREBALL_TYPE_GREASE      			4
#define CGAMEFIREBALL_TYPE_WEB					5
#define CGAMEFIREBALL_TYPE_METEOR      			6
#define CGAMEFIREBALL_TYPE_WILTING     			7
#define CGAMEFIREBALL_TYPE_WEIRD				8
#define CGAMEFIREBALL_TYPE_ENTANGLE    			9
#define CGAMEFIREBALL_TYPE_COLORSPRAY   		10
#define CGAMEFIREBALL_TYPE_CONECOLD     		11
#define CGAMEFIREBALL_TYPE_HOLYSMITE    		12
#define CGAMEFIREBALL_TYPE_UNHOLYSMITE  		13
#define CGAMEFIREBALL_TYPE_PRISMSPRAY   		14
#define CGAMEFIREBALL_TYPE_FIRE_DRAGON			15
#define CGAMEFIREBALL_TYPE_STORM_OF_VENGEANCE	16
#define CGAMEFIREBALL_TYPE_FIRE_PURPLE			17
#define CGAMEFIREBALL_TYPE_FIRE_DRAGON_GREEN	18

// 760 bytes in size
struct ProFileArea {
	DWORD m_dwAreaFlags;
	WORD m_triggerRange; // number, default 256
	WORD m_explosionRange; // number, default 256
	ResRef m_explodeSound; // string, default empty
	WORD m_nDelay; // number, default 100
	WORD m_explodeId; // list of animation codes, default CGAMEANIMATIONTYPE_CHUNKS
	WORD m_sparkleExplosionProjectile; // list of projectile types, default ITEM_MISSILETYPE_HIT_NECROMANCY_AREA
	BYTE m_nRepetitionCount; // number, default 1
	BYTE m_fireBallType; // list of fireball types, default CGAMEFIREBALL_TYPE_FIRE
	BYTE m_ringColor; // list of color ranges, default CVIDPALETTE_FIRE_NORMAL
	BYTE padding1;
	WORD m_secondaryProjectile; // list of projectile types, default ITEM_MISSILETYPE_INVISIBLE_TRAVELLING
	ResRef m_centerVVC;
	WORD m_coneSize; // cone arc in degrees (1-359), default 45
	WORD padding2;

	DWORD reservedSpace[54];
};

#endif //FILEPRO_H