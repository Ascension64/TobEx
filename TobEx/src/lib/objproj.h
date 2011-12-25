#ifndef OBJPROJ_H
#define OBJPROJ_H

#include "stdafx.h"
#include "objcore.h"
#include "effcore.h"
#include "pathfind.h"
#include "sndcore.h"
#include "vidcore.h"
#include "animcore.h"

class CProjectile : public CGameObject { //Size 172h
//Projectile type 1
//Constructor: 0x5FE560
public:
	//AABD44
	short nMissileId; //42h, MISSILE.IDS
	char bSparkTrail; //44h, area list to put this object, bit5 not set = 0, bit5 set = 1
	char u45; //pad?
	short nSpeed; //46h
	Enum u48; //a party member (source)
	Enum u4c; //target
	Enum u50;
	CEffectList effects; //54h, to apply on target affected by this (Preset target effects from SPL)
	
	short nSparkleColour; //80h
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

	POINT u82; //calculation from location of Enum source
	POINT u8a; //smoke
	int u92;
	int u96;
	POINT u9a;
	POINT ua2;
	int uaa;
	POINT uae; //location to travel to (target)
	TerrainTable ub6;
	short uc6;
	BOOL bShowSparkles; //c8h
	unsigned int dwDisplayFlags; //display flags, identical to VVC (at least bit3, bit13, bit17 used; bit17 is default)
	BOOL bIgnoreCenter; //d0h
	CSound sound; //d4h
	ResRef nameSnd1; //13eh, used on creation
	BOOL bLoopSnd1; //146h
	ResRef namesnd2; //14ah, used when arrived at destination
	BOOL bLoopSnd2; //152h
	bool bUseHeight; //156h, flying?
	char u157; //pad?

	//to do with homing towards target?
	short u158;
	short u15a;
	int u15c; //radius^2 from an orbit?

	long long u160;
	char u168;
	char u169; //pad?
	IECString VisualEffect; //16ah, value from VEFPROJ.IDS, used in CreateVisualEffect()
	Enum eVisualEffect; //16eh, once constructed gets enum of visual effect
};

class CProjectileBAM : public CProjectile { //Size 2B2h
//Projectile type 2
//Constructor: 0x6054A1
public:
	//AABEDC
	CVidCell* animProjectile; //172h, default is MAGMIS.BAM
	CVidCell* animShadow; //176h
	VidPal u17a; //type_range
	BOOL bDarken; //19eh
	BOOL bBamBit4; //u1a2h
	BOOL bEnableLightSpot; //1a6h
	int nLightWidth; //1aah
	int nLightHeight; //1aeh
	short nLightIntensity; //1b2h
	BOOL bEnableShadow; //1b4h
	short nOrientations; //1b8h, face target granularity
	short u1ba;
	short m_currentOrientation; //1bch
	BOOL bProjectileVisible; //1beh
	CVidBitmap m_FixedPalette; //1c2h
	bool bUseFixedPalette; //278h
	char u279;
	short u27a; //decrementing each update (radius / nSpeed + 1), purges projectile when 0
	BOOL bEnableSmoke; //27ch
	char nSmokeDelay; //280h
	char bSmokeColours[7]; //281h, type_range
	char nSmokeDelayCounter; //288h, increments each frame; when == nSmokeDelay, reset to 0 and make a smoke object
	char u289; //pad
	short nSmokeAnimId; //28ah, from ANIMATE.IDS

	//only the first one is used
	ResRef u28c; //trailing animation 1 (VEF, VVC, BAM)
	ResRef u294; //trailing animation 2 (VEF, VVC, BAM)
	ResRef u29c; //trailing animation 3 (VEF, VVC, BAM)
	short u2a4; //trailing animation 1 cycle (how many ticks to play vef)
	short u2a6; //trailing animation 2 cycle (how many ticks to play vef)
	short u2a8; //trailing animation 3 cycle (how many ticks to play vef)
	int u2aa; //u154 of .PRO file
	int u2ae; //incremented each update starting from 0
};

class CProjMagMis : public CProjectileBAM { //Size 2D2h
//Constructor: 0x610AD9
public:
	//AAC544
	short nProjectiles; //2b2h
	IECPtrList u2b4; //AAC5D8
	short u2d0;
};

class CProjectileArea : public CProjectileBAM { //Size 32Eh
//Projectile type 3
//Constructor: 0x608CB6
public:
	//AABF70
	//v60, return 0
	//v64, void CProjectileArea::Initialise(pArea, Enum src, Enum target, x, y, z, nSparkleColour)
	//v68, void CProjectileArea::DoArrivedAtTarget()
	//v6c, void CProjectile::Purge()
	//v70, void CProjectile::ApplyEffectsToTarget()
	//v74, return
	//v78, BOOL UsingTrigger() - not really, but the coding actually does this
	//v7c, void CProjectileArea::Marshal(CFileAreProj* ptr)
	//v80, Object* CProjectileArea::GetTargetingObject(Object*)
	//v84, void CProjectileArea::SetTargetingObject(Object*)
	//v88, unsigned int CProjectile::GetDisplayFlags()
	//v8c, void CProjectile::SetDisplayFlags()
	//v90, ? void CProjectileBAM::UpdatePosition(x, y)

	ResRef ProjectileName; //2b2h
	short nEffectRadius; //2bah, the size of the effect
	short nTriggerRadius; //2bch, the size of the trigger
		
	short nExplosionIdx; //2beh, explosion projectile, from PROJECTL.IDS
	//makes a copy of this projectile for each effect in effects
		
	//bit8: magelevel
	//bit9: clericlevel
	//none of those: duration/trigger count
	//gets u12 from area proj format
	short nTriggersRemaining; //2c0h, explosion count
		
	BOOL bProjectileBAMFinished; //2c2h, 0 = AIUpdate CProjectileBAM, 1 = BAM part finished so AIUpdate CProjectileArea
	short nExplosionDelay; //2c6h
	short nExplosionDelayCounter; //2c8, when 0, will check if explodes; copied from u2c6 if bit14 set (start with delay), or from area proj format u10
	BOOL bUseTrigger; //2cah, bit2

	//puts caster EA group here (evilcutoff, neutral, goodcutoff)
	//bit6: target by EA.IDS
	//bit7: 1 = same grouping as caster, 0 = opposite grouping from caster
	Object obTarget; //2ceh
		
	char nExplosionAnimId; //2e2h, nFireballId, from FIREBALL.IDS
	char u2e3; //pad
	BOOL bEnable2ndProjectile; //2e4h, bit4
	short nProjectileSecondaryIdx; //2e8h, +1 to get PROJECTL.IDS
	BOOL bNoOverlapEffects; //2eah, bit3
	BOOL bEnableFragmentAnim; //2eeh, bit5, bEnableChunks
	BOOL bTriggeredByInanimateObjects; //2f2h, bit1
	BOOL bProjectileRemainsVisible; //2f6h, bit0
	short nFragmentAnimId; //2fah, from ANIMATE.IDS, nChunkAnimId
	ResRef nameTriggerSound; //2fch, FireballSound
	char nExplosionColour; //304h, nFireballColourRange
	char u305; //pad
	BOOL bEnableVisualEffect; //306h, bit10, useVVC
	ResRef u30a; //Visual Effect
	BOOL bConeShaped; //312h, bit11
	short nConeAngle; //316h, range: 1-359
	BOOL bAreaBit12; //318h, bit12, explode immediately, i.e. do not travel to target before exploding
	char nOwnerPartyIdx; //31ch, party member that sourced this projectile, gets area proj u1b
	char u31d; //pad
	BOOL bOwnedByPartyMember; //31eh, set if loaded from area, will change to 0 when used
	BOOL bNoExplosion; //322h, bit13
	BOOL bDelayExplosion; //326, bit14
	BOOL bAffectOneTarget; //32ah, bit15
};

class CSmokeObject : public CGameObject { //Size DAh
//Constructor: 0x8BD53C
public:
	//AB748C
	TerrainTable u42;
	AnimData m_animation; //52h
	int u58;
	POINT ptSource; //5ch
	POINT ptDest; //64h
	short u6c;
	char u6e;
	char u6f;
	CSound sound; //70h
};

class CSparkle : public CGameObject { //Size 
//Constructor: 0x5F6CD5
public:
	//AABB68
	CVideoMode* pVideoMode; //42h
	IECPtrList u46; //AABA88
	ARGB rgbStart; //62h
	ARGB rgbFade1; //66h
	ARGB rgbFade2; //6ah
	ARGB rgbFade3; //6eh
	ARGB rgbFade4; //72h
	int u76;
	RECT u7a;
	short u8a;
	int u8c;
	short u90;
	int u92;
	int u96;
	int u9a;
};

class CFireball3d : public CGameObject { //Size 2D8h
//Constructor: 0x568C00
//For all kind of 'explosion' effects: fireball, color spray, web, cloudkill, etc.
public:
	//AAA93C
	TerrainTable u42;
	TerrainTable u52;
	short u62;
	short u64; //nSmokeAnimId
	char u66[7]; //colour range, for this and smoke
	char u6d; //pad
	short u6e;
	CVidCell u70; //3d animation, which one depends on FireballId (e.g. SPFIREPI, or SPBOOM if Use 3d Animations = 0)
	VidPal u146; //type_range
	short u16a; //duration?
	char u16c; //(radius - 1)/speed + 1
	char u16d;
	int u16e;
	int u172;
	int* u176; //ptr object of size (2*u16e+1)*(2*u172+1)
	int u17a;
	int u17e;
	int* u182; //ptr object of size related to u17a and u17e
	int* u186; //ptr object of size related to u17a and u17e
	CSound sound; //18ah, which one depends on FireballId
	IECString u1f4;
	int u1f8;
	int u1fc;
	int u200;
	BOOL u204; //bEnableSmoke
	int u208;
	BOOL bConeShaped; //20ch
	short nConeRadius; //210h
	POINT u212;
	char u21a;
	char u21b; //pad
	short u21c;
	int u21e;
	CVidBitmap u222;
};

class CChunks : CGameObject { //Size D6h
//Constructor: 0x8BCA37
public:
	//AB7428
	TerrainTable u42;
	AnimData m_animation; //52h
	int u58;
	POINT u5c;
	int u64;
	char u68;
	char u69;
	char u6a;
	CSound sound; //6ch
};

#endif //OBJPROJ_H