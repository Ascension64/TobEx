#ifndef ANIMCORE_H
#define ANIMCORE_H

#include "stdafx.h"

#include "vidcore.h"

class CCreatureObject;

class CAnimationSoundList : public IECPtrList { //Size 28h
//Constructor: 0x87B3E0
public:
	//AACCA0
	BOOL PlayPrimedSound(int dwFrame, CCreatureObject& cre);

	//Elements are 0xc size objects (0x0 ResRef sound [first row], 0x8 frameToPlay [second row])
	POSITION posPrimedSound; //1ch
	BOOL bIgnorePrime; //20h
	int dwChannel; //24h
};

extern BOOL (CAnimationSoundList::*CAnimationSoundList_PlayPrimedSound)(int, CCreatureObject&);

class CAnimation { //Size 6D8h 
public:
	CAnimation(); //7F9211
	CAnimation& Construct() { return *this; } //dummy
	void PlayCurrentSequenceSound(CCreatureObject& cre);

	static BOOL IsPlayableAnimation(unsigned short wAnimId);

	//AB6148
	virtual void v0() {}
	virtual void GetCurrentFrameDimensions(RECT* pFrame, POINT* pCentre, int zPos) {} //v4
	virtual void v8() {}
	virtual void vc() {}
	virtual void v10() {}
	virtual void v14() {}
	virtual void v18() {}
	virtual void v1c() {}
	virtual void v20() {}
	virtual void v24() {}
	virtual bool CanUseMiddleVertList() { return false; } //v28
	virtual void v2c() {}
	virtual void v30() {}
	virtual char GetVertListType() { return 0; } //v34, u18
	virtual void v38() {} //GetSomeGoreThing? u19
	virtual char GetDefaultVertListType() { return 0; } //v3c
	virtual unsigned char GetCurrentMovementRate() { return 0; } //v40
	virtual void SetCurrentMovementRate(unsigned char n) {} //v44
	virtual void ResetCurrentMovementRate() {} //v48, put 6h into 7h
	virtual char GetDefaultMovementRate() { return 0; } //v4c
	virtual void v50() {} //get u22[idx]
	virtual RECT* GetFootCircle() { return 0; } //v54
	virtual void v58() {}
	virtual char GetFootCircleSize() { return 0; } //v5c
	virtual void v60() {}
	virtual void v64() {}
	virtual void v68() {}
	virtual LPCTSTR GetWalkingSound(short wTerrainCode); //v6c
	virtual void v70() {}
	virtual void v74() {}
	virtual bool IsImmuneToDamage() { return false; } //v78
	virtual void v7c() {}
	virtual void v80() {}
	virtual void v84() {}
	virtual void v88() {}
	virtual void v8c() {}
	virtual void v90() {}
	virtual void v94() {}
	virtual void DeinitColor(char nGroupRangeID) {} //v98
	virtual void DeinitAllColors() {} //v9c
	virtual void InitColor(int nColorGroup, int nGroupRangeId, ABGR rgbColor, char n) {} //va0
	virtual void InitAllColors(int nGroupId, ABGR rgbColor, char n) {} //va4
	virtual void SetColorRange(int nColorIdx, int nGroupRangeId) {} //va8
	virtual void vac() {}
	virtual short SetAnimationSequence(short wSeq) { return SEQ_READY; } //vb0
	virtual void vb4() {}
	virtual void vb8() {}
	virtual void vbc() {}
	virtual char GetInRoundAction() { return 0; } //vc0
	virtual BOOL CanBeTargetted() { return FALSE; } //vc4, for ankhegs
	virtual void vc8() {}
	virtual void vcc() {}
	virtual void vd0() {}
	virtual void vd4() {}
	virtual void vd8() {}
	virtual bool GetCurrentCycleAndFrame(short& wCycle, short& wFrame); //vdc

	unsigned short wAnimId; //4h
	unsigned char nMovementRateDefault; //6h
	unsigned char nMovementRateCurrent; //7h, modified by effects
	RECT rFootcircle; //8h
	char u18;
	char u19;
	int u1a; //related to animId
	LPCTSTR szFallingSound; //1eh
	short u22[16]; //set by 0x7FA94F proc, either 0, 10, or -10, to do with orientations?

	//These graphics determine what to do during each 
	CVidBitmap cvdRoundBase[5]; //42h, rndbase1-5

	char nFootCircleSize; //3d0h, 3, 5, 7, 9, 13 (in diameter)
	char u3d1; //pad
	short wCyclesPerAnimation; //3d2h
	char u3d4;
	char u3d5;
	char u3d6;
	ResRef rAniSnd; //3d7h
	char u3df; //pad
	CAnimationSoundList soundset[19]; //3e0h, corresponds to rows of anim soundset 2DAs (19 in total)
};

extern CAnimation& (CAnimation::*CAnimation_Construct)();
extern void (CAnimation::*CAnimation_PlayCurrentSequenceSound)(CCreatureObject&);
extern BOOL (*CAnimation_IsPlayableAnimation)(unsigned short);
extern LPCTSTR (CAnimation::*CAnimation_GetWalkingSound)(short);
extern bool (CAnimation::*CAnimation_GetCurrentCycleAndFrame)(short&, short&);

struct AnimData { //Size 8h
	CAnimation* pAnimation; //0h
	short wCurrentSequence; //4h
};

#endif //ANIMCORE_H
