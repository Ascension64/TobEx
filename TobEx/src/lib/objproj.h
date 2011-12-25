#ifndef OBJPROJ_H
#define OBJPROJ_H

#include "utils.h"
#include "objcore.h"
#include "effcore.h"
#include "pathfind.h"
#include "sndcore.h"
#include "resref.h"
#include "vidcore.h"
#include "animcore.h"
#include "cstringex.h"

class CProjectile : public CGameObject {
//Projectile type 1
//Size: 0x172
//Constructor: 0x5FE560
//vtable: 0xAABD44
public:
	WORD nMissileId; //42h, MISSILE.IDS
	BYTE bSparkTrail; //44h, area list to put this object, bit5 not set = 0, bit5 set = 1
	BYTE u45; //pad?
	WORD nSpeed; //46h
	Enum u48; //a party member (source)
	Enum u4c; //target
	Enum u50;
	CPtrListEffect effects; //54h, to apply on target affected by this (Preset target effects from SPL)
	
	WORD nSparkleColour; //80h
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
	DWORD u92;
	DWORD u96;
	POINT u9a;
	POINT ua2;
	DWORD uaa;
	POINT uae; //location to travel to (target)
	TerrainTable ub6;
	WORD uc6;
	BOOL bShowSparkles; //c8h
	DWORD dwDisplayFlags; //display flags, identical to VVC (at least bit3, bit13, bit17 used; bit17 is default)
	BOOL bIgnoreCenter; //d0h
	CSound sound; //d4h
	ResRef nameSnd1; //13eh, used on creation
	BOOL bLoopSnd1; //146h
	ResRef namesnd2; //14ah, used when arrived at destination
	BOOL bLoopSnd2; //152h
	bool bUseHeight; //156h, flying?
	BYTE u157; //pad?

	//to do with homing towards target?
	WORD u158;
	WORD u15a;
	DWORD u15c; //radius^2 from an orbit?

	QWORD u160;
	BYTE u168;
	BYTE u169; //pad?
	IECString VisualEffect; //16ah, value from VEFPROJ.IDS, used in CreateVisualEffect()
	Enum eVisualEffect; //16eh, once constructed gets enum of visual effect
};

class CProjectileBAM : public CProjectile {
//Projectile type 2
//Size: 0x2B2
//Constructor: 0x6054A1
//vtable: 0xAABEDC
public:
	CVidCell* animProjectile; //172h, default is MAGMIS.BAM
	CVidCell* animShadow; //176h
	VidPal u17a; //type_range
	BOOL bDarken; //19eh
	BOOL bBamBit4; //u1a2h
	BOOL bEnableLightSpot; //1a6h
	DWORD nLightWidth; //1aah
	DWORD nLightHeight; //1aeh
	WORD nLightIntensity; //1b2h
	BOOL bEnableShadow; //1b4h
	WORD nOrientations; //1b8h, face target granularity
	WORD u1ba;
	WORD m_currentOrientation; //1bch
	BOOL bProjectileVisible; //1beh
	CVidBitmap m_FixedPalette; //1c2h
	bool bUseFixedPalette; //278h
	BYTE u279;
	WORD u27a; //decrementing each update (radius / nSpeed + 1), purges projectile when 0
	BOOL bEnableSmoke; //27ch
	BYTE nSmokeDelay; //280h
	BYTE bSmokeColours[7]; //281h, type_range
	BYTE nSmokeDelayCounter; //288h, increments each frame; when == nSmokeDelay, reset to 0 and make a smoke object
	BYTE u289; //pad
	WORD nSmokeAnimId; //28ah, from ANIMATE.IDS

	//only the first one is used
	ResRef u28c; //trailing animation 1 (VEF, VVC, BAM)
	ResRef u294; //trailing animation 2 (VEF, VVC, BAM)
	ResRef u29c; //trailing animation 3 (VEF, VVC, BAM)
	WORD u2a4; //trailing animation 1 cycle (how many ticks to play vef)
	WORD u2a6; //trailing animation 2 cycle (how many ticks to play vef)
	WORD u2a8; //trailing animation 3 cycle (how many ticks to play vef)
	DWORD u2aa; //u154 of .PRO file
	DWORD u2ae; //incremented each update starting from 0
};

class CProjMagMis : public CProjectileBAM {
//Size: 0x2D2
//Constructor: 0x610AD9
//vtable: 0xAAC544
public:
	WORD nProjectiles; //2b2h
	CPtrList u2b4; //AAC5D8
	WORD u2d0;
};

class CProjectileArea : public CProjectileBAM {
//Projectile type 3
//Size: 0x32E
//Constructor: 0x608CB6
//vtable: 0xAABF70

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
//v88, DWORD CProjectile::GetDisplayFlags()
//v8c, void CProjectile::SetDisplayFlags()
//v90, ? void CProjectileBAM::UpdatePosition(x, y)
public:
	ResRef ProjectileName; //2b2h
	WORD nEffectRadius; //2bah, the size of the effect
	WORD nTriggerRadius; //2bch, the size of the trigger
		
	WORD nExplosionIdx; //2beh, explosion projectile, from PROJECTL.IDS
	//makes a copy of this projectile for each effect in effects
		
	//bit8: magelevel
	//bit9: clericlevel
	//none of those: duration/trigger count
	//gets u12 from area proj format
	WORD nTriggersRemaining; //2c0h, explosion count
		
	BOOL bProjectileBAMFinished; //2c2h, 0 = AIUpdate CProjectileBAM, 1 = BAM part finished so AIUpdate CProjectileArea
	WORD nExplosionDelay; //2c6h
	WORD nExplosionDelayCounter; //2c8, when 0, will check if explodes; copied from u2c6 if bit14 set (start with delay), or from area proj format u10
	BOOL bUseTrigger; //2cah, bit2

	//puts caster EA group here (evilcutoff, neutral, goodcutoff)
	//bit6: target by EA.IDS
	//bit7: 1 = same grouping as caster, 0 = opposite grouping from caster
	Object obTarget; //2ceh
		
	BYTE nExplosionAnimId; //2e2h, nFireballId, from FIREBALL.IDS
	BYTE u2e3; //pad
	BOOL bEnable2ndProjectile; //2e4h, bit4
	WORD nProjectileSecondaryIdx; //2e8h, +1 to get PROJECTL.IDS
	BOOL bNoOverlapEffects; //2eah, bit3
	BOOL bEnableFragmentAnim; //2eeh, bit5, bEnableChunks
	BOOL bTriggeredByInanimateObjects; //2f2h, bit1
	BOOL bProjectileRemainsVisible; //2f6h, bit0
	WORD nFragmentAnimId; //2fah, from ANIMATE.IDS, nChunkAnimId
	ResRef nameTriggerSound; //2fch, FireballSound
	BYTE nExplosionColour; //304h, nFireballColourRange
	BYTE u305; //pad
	BOOL bEnableVisualEffect; //306h, bit10, useVVC
	ResRef u30a; //Visual Effect
	BOOL bConeShaped; //312h, bit11
	WORD nConeAngle; //316h, range: 1-359
	BOOL bAreaBit12; //318h, bit12, explode immediately, i.e. do not travel to target before exploding
	BYTE nOwnerPartyIdx; //31ch, party member that sourced this projectile, gets area proj u1b
	BYTE u31d; //pad
	BOOL bOwnedByPartyMember; //31eh, set if loaded from area, will change to 0 when used
	BOOL bNoExplosion; //322h, bit13
	BOOL bDelayExplosion; //326, bit14
	BOOL bAffectOneTarget; //32ah, bit15
};

class CSmokeObject : public CGameObject {
//Size: 0xDA
//Constructor: 0x8BD53C
//vtable: 0xAB748C
public:
	TerrainTable u42;
	AnimData m_animation; //52h
	DWORD u58;
	POINT ptSource; //5ch
	POINT ptDest; //64h
	WORD u6c;
	BYTE u6e;
	BYTE u6f;
	CSound sound; //70h
};

class CSparkle : public CGameObject {
//Size: 0x9E
//Constructor: 0x5F6CD5
//vtable: 0xAABB68
public:
	CVideoMode* pVideoMode; //42h
	CPtrList u46; //AABA88
	ARGB rgbStart; //62h
	ARGB rgbFade1; //66h
	ARGB rgbFade2; //6ah
	ARGB rgbFade3; //6eh
	ARGB rgbFade4; //72h
	DWORD u76;
	RECT u7a;
	WORD u8a;
	DWORD u8c;
	WORD u90;
	DWORD u92;
	DWORD u96;
	DWORD u9a;
};

class CFireball3d : public CGameObject {
//Size: 0x2D8
//Constructor: 0x568C00
//vtable: 0xAAA93C
//For all kind of 'explosion' effects: fireball, color spray, web, cloudkill, etc.
public:
	TerrainTable u42;
	TerrainTable u52;
	WORD u62;
	WORD u64; //nSmokeAnimId
	BYTE u66[7]; //colour range, for this and smoke
	BYTE u6d; //pad
	WORD u6e;
	CVidCell u70; //3d animation, which one depends on FireballId (e.g. SPFIREPI, or SPBOOM if Use 3d Animations = 0)
	VidPal u146; //type_range
	WORD u16a; //duration?
	BYTE u16c; //(radius - 1)/speed + 1
	BYTE u16d;
	DWORD u16e;
	DWORD u172;
	DWORD* u176; //ptr object of size (2*u16e+1)*(2*u172+1)
	DWORD u17a;
	DWORD u17e;
	DWORD* u182; //ptr object of size related to u17a and u17e
	DWORD* u186; //ptr object of size related to u17a and u17e
	CSound sound; //18ah, which one depends on FireballId
	IECString u1f4;
	DWORD u1f8;
	DWORD u1fc;
	DWORD u200;
	BOOL u204; //bEnableSmoke
	DWORD u208;
	BOOL bConeShaped; //20ch
	WORD nConeRadius; //210h
	POINT u212;
	BYTE u21a;
	BYTE u21b; //pad
	WORD u21c;
	DWORD u21e;
	CVidBitmap u222;
};

class CChunks : CGameObject {
//Size: 0xD6
//Constructor: 0x8BCA37
//vtable: 0xAB7428
public:
	TerrainTable u42;
	AnimData m_animation; //52h
	DWORD u58;
	POINT u5c;
	DWORD u64;
	BYTE u68;
	BYTE u69;
	BYTE u6a;
	CSound sound; //6ch
};

#endif //OBJPROJ_H