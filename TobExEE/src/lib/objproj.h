//TobExEE
#ifndef OBJPROJ_H
#define OBJPROJ_H

#include "stdafx.h"
#include "objcore.h"
#include "effcore.h"
#include "pathfind.h"
#include "sndcore.h"
#include "vidcore.h"
#include "animcore.h"

class CProjectile : public CGameObject { //Size 130h
//Projectile type 1
public:
	short m_nMissileId; //48h, MISSILE.IDS
	char m_bSparkTrail; //4ah, area list to put this object, bit5 not set = 0, bit5 set = 1
	char p4b;
	short m_nSpeed; //4ch
	char p4e[2];
	ENUM u50; //a party member (source)
	ENUM m_eTarget; //54h
	ENUM u58;
	CEffectList m_lEffects; //5ch, to apply on target affected by this (Preset target effects from SPL)
	
	short nSparkleColour; //88h
	//nSparkleColour refers to SPRKLCLR.2DA (row number)
	//1: BLACK (5)
	//2: BLUE (0)
	//3: CHROMATIC (6)
	//4: GOLD (1)
	//5: GREEN (8)
	//6: PURPLE (2)
	//7: RED (7)
	//8: WHITE (9)
	//9: ICE (3)
	//10: STONE (4)
	//11: MAGENTA (10)
	//12: ORANGE (11)

	char p8a[2];
	CPoint u8c; //calculation from location of ENUM source
	CPoint u94; //smoke
	int u9c;
	int ua0;
	CPoint ua4;
	CPoint uac;
	int ub4;
	CPoint ub8; //location to travel to (target)
	TerrainTable uc0;
	short ud0;
	char pd2[2];
	BOOL m_bShowSparkles; //d4h
	unsigned int m_dwDisplayFlags; //d8h, display flags, identical to VVC (at least bit3, bit13, bit17 used; bit17 is default)
	BOOL m_bIgnoreCenter; //dch
	CSoundWrapper m_snd; //e0h
	ResRef m_rNameSnd1; //f8h, used on creation
	BOOL m_bLoopSnd1; //100h
	ResRef m_rNamesnd2; //104h, used when arrived at destination
	BOOL m_bLoopSnd2; //10ch
	bool m_bUseHeight; //110h, flying?
	char p111[3];

	//to do with homing towards target?
	short u114;
	short u116;
	int u118; //radius^2 from an orbit?

	CPoint u11c;
	char u124;
	char p125[3];
	IECString m_sVisualEffect; //128h, value from VEFPROJ.IDS, used in CreateVisualEffect()
	ENUM m_eVisualEffect; //12ch, once constructed gets enum of visual effect
};

class CProjectileBAM : public CProjectile { //Size 274h
//Projectile type 2
public:
	CVidCell* m_vidProjectile; //130h, default is MAGMIS.BAM
	CVidCell* m_vidShadow; //134h
	VidPal u138; //type_range
	BOOL m_bDarken; //15ch
	BOOL m_bBamBit4; //u160h
	BOOL m_bEnableLightSpot; //164h
	int m_nLightWidth; //168h
	int m_nLightHeight; //16ch
	short m_nLightIntensity; //170h
	char p172[2];
	BOOL m_bEnableShadow; //174h
	short m_wOrientations; //178h, face target granularity
	short u17a;
	short m_wCurrentOrientation; //17ch
	char p17e[2];
	BOOL m_bProjectileVisible; //180h
	CVidBitmap m_vidFixedPalette; //184h
	bool m_bUseFixedPalette; //238h
	char u239;
	short u23a; //decrementing each update (radius / nSpeed + 1), purges projectile when 0
	BOOL m_bEnableSmoke; //23ch
	char m_cSmokeDelay; //240h
	bool m_bSmokeColours[7]; //241h, type_range
	char m_cSmokeDelayCounter; //248h, increments each frame; when == nSmokeDelay, reset to 0 and make a smoke object
	char p249;
	short m_wSmokeAnimId; //24ah, from ANIMATE.IDS

	//only the first one is used
	ResRef u24c; //trailing animation 1 (VEF, VVC, BAM)
	ResRef u254; //trailing animation 2 (VEF, VVC, BAM)
	ResRef u25c; //trailing animation 3 (VEF, VVC, BAM)
	short u264; //trailing animation 1 cycle (how many ticks to play vef)
	short u266; //trailing animation 2 cycle (how many ticks to play vef)
	short u268; //trailing animation 3 cycle (how many ticks to play vef)
	char p26a[2];
	int u26c; //u154 of .PRO file
	int u270; //incremented each update starting from 0
};

class CProjMagMis : public CProjectileBAM { //Size 298h
public:
	short m_wProjectiles; //274h
	char p276[2];
	IECPtrList u278; //AAC5D8
	short u294;
	char p296[2];
};

class CProjectileArea : public CProjectileBAM { //Size 2F8h
//Projectile type 3
public:
	ResRef m_rProjectileName; //274h
	short m_nEffectRadius; //27ch, the size of the effect
	short m_nTriggerRadius; //27eh, the size of the trigger
		
	short m_nExplosionIdx; //280h, explosion projectile, from PROJECTL.IDS
	//makes a copy of this projectile for each effect in effects
		
	//bit8: magelevel
	//bit9: clericlevel
	//none of those: duration/trigger count
	//gets u12 from area proj format
	short m_nTriggersRemaining; //282h, explosion count
		
	BOOL m_bProjectileBAMFinished; //284h, 0 = AIUpdate CProjectileBAM, 1 = BAM part finished so AIUpdate CProjectileArea
	short m_nExplosionDelay; //288h
	short m_nExplosionDelayCounter; //28ah, when 0, will check if explodes; copied from u2c6 if bit14 set (start with delay), or from area proj format u10
	BOOL m_bUseTrigger; //28ch, bit2

	//puts caster EA group here (evilcutoff, neutral, goodcutoff)
	//bit6: target by EA.IDS
	//bit7: 1 = same grouping as caster, 0 = opposite grouping from caster
	Object m_oTarget; //290h
		
	char m_nExplosionAnimId; //2a4h, nFireballId, from FIREBALL.IDS
	char p2a5[3];
	BOOL m_bEnable2ndProjectile; //2a8h, bit4
	short m_nProjectileSecondaryIdx; //2ach, +1 to get PROJECTL.IDS
	char p2ae[2];
	BOOL m_bNoOverlapEffects; //2b0h, bit3
	BOOL m_bEnableFragmentAnim; //2b4h, bit5, bEnableChunks
	BOOL m_bTriggeredByInanimateObjects; //2b8h, bit1
	BOOL m_bProjectileRemainsVisible; //2bch, bit0
	short m_nFragmentAnimId; //2c0h, from ANIMATE.IDS, nChunkAnimId
	ResRef m_nameTriggerSound; //2c2h, FireballSound
	char m_nExplosionColour; //2cah, nFireballColourRange
	char p2cb;
	BOOL m_bEnableVisualEffect; //2cch, bit10, useVVC
	ResRef u2d0; //2d0h, Visual Effect
	BOOL m_bConeShaped; //2d8h, bit11
	short m_nConeAngle; //2dch, range: 1-359
	char p2de[2];
	BOOL m_bAreaBit12; //2e0h, bit12, explode immediately, i.e. do not travel to target before exploding
	char m_nOwnerPartyIdx; //2e4h, party member that sourced this projectile, gets area proj u1b
	char p2e5[3];
	BOOL m_bOwnedByPartyMember; //2e8h, set if loaded from area, will change to 0 when used
	BOOL m_bNoExplosion; //2ech, bit13
	BOOL m_bDelayExplosion; //2f0h, bit14
	BOOL m_bAffectOneTarget; //2f4h, bit15
};

class CSmokeObject : public CGameObject { //Size 90h
public:
	TerrainTable u48;
	AnimData m_animation; //58h
	int u60;
	CPoint m_ptSource; //64h
	CPoint m_ptDest; //6ch
	short u74;
	char u76;
	char u77;
	CSoundWrapper m_snd; //78h
};

class CSparkle : public CGameObject { //Size ?, FIX_ME
//Constructor: 0x5F6CD5
public:
	//AABB68
	void* pVideoMode; //42h
	IECPtrList u46; //AABA88
	ABGR rgbStart; //62h
	ABGR rgbFade1; //66h
	ABGR rgbFade2; //6ah
	ABGR rgbFade3; //6eh
	ABGR rgbFade4; //72h
	int u76;
	RECT u7a;
	short u8a;
	int u8c;
	short u90;
	int u92;
	int u96;
	int u9a;
};

class CFireball3d : public CGameObject { //Size 27Ch
//For 'explosion' effects: fireball, color spray, web, cloudkill, etc.
public:
	TerrainTable u48;
	TerrainTable u58;
	short u68;
	short m_wSmokeAnimId; //6ah
	CreFileColors m_colors; //6ch, colour range, for this and smoke
	char p73;
	short u74;
	char p76[2];
	CVidCell u78; //3d animation, which one depends on FireballId (e.g. SPFIREPI, or SPBOOM if Use 3d Animations = 0)
	VidPal u13c; //type_range
	short u160; //duration?
	char u162; //(radius - 1)/speed + 1
	char u163;
	int u164;
	int u168;
	int* u16c; //ptr object of size (2*u16e+1)*(2*u172+1)
	int u170;
	int u174;
	int* u178; //ptr object of size related to u17a and u17e
	int* u17c; //ptr object of size related to u17a and u17e
	CSoundWrapper m_snd; //180h, which one depends on FireballId
	IECString u198;
	int u19c;
	int u1a0;
	int u1a4;
	BOOL m_bEnableSmoke; //1a8h
	int u1ac;
	BOOL m_bConeShaped; //1b0h
	short m_nConeRadius; //1b4h
	char p1b6[2];
	CPoint u1b8;
	char u1c0;
	char p1c1;
	short u1c2;
	int u1c4;
	CVidBitmap u1c8;
};

class CChunks : CGameObject { //Size 8Ch
public:
	TerrainTable u48;
	AnimData m_animation; //58h
	int u60;
	CPoint u64;
	int u6c;
	char u70;
	char u71;
	char u72;
	char p73;
	CSoundWrapper m_snd; //74h
};

#endif //OBJPROJ_H