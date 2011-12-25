#ifndef ANIMCORE_H
#define ANIMCORE_H

#include "stdafx.h"

#include "arecore.h"
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
	virtual ~CAnimation() {} //v0
	virtual void GetCurrentFrameDimensions(RECT* pFrame, POINT* pCentre, int zPos) {} //v4
	virtual void v8() {} //? void GetBoundsRect(RECT* pBounds, POINT* ppt1, POINT* ppt2, zPos, width, height)
	virtual BOOL SetOrientation(short wOrient) { return TRUE; } //vc
	virtual void SetArmorLevel(char szArmorLevel, ColorRangeValues& colors) {} //v10
	virtual void v14() {} //void LoadAnimGroup3?(IECString& suffix, ColorRangeValues& colors)
	virtual void v18() {} //void LoadAnimGroup2[Shield]?(IECString& suffix, ColorRangeValues& colors)
	virtual void v1c() {} //void LoadAnimGroup1[twohanded]?(IECString& suffix, ColorRangeValues& colors, nItemFlags, pAttackProb)
	virtual void v20() {} //VidPal& GetAnimGroupVidPal(nGroupId) (ids use second lowest digit i.e. 0xX0)
	virtual void GetAnimGroupPaperdollName(IECString* ptr, int nGroupId) {} //v24, ids use as above
	virtual bool CanUseMiddleVertList() { return false; } //v28
	virtual void v2c() {} //bool, 0 arg
	virtual short GetNumSeqPerAnimation() { return 0; } //v30
	virtual char GetVertListType() { return 0; } //v34, get 18h
	virtual void v38() {} //GetSomeGoreThing?, get 19h
	virtual char GetDefaultVertListType() { return 0; } //v3c
	virtual unsigned char GetCurrentMovementRate() { return 0; } //v40, get 7h
	virtual void SetCurrentMovementRate(unsigned char n) {} //v44
	virtual void ResetCurrentMovementRate() {} //v48, put 6h into 7h
	virtual char GetDefaultMovementRate() { return 0; } //v4c
	virtual void v50() {} //int* Get22h(int* ptr, short idx)
	virtual RECT* GetFootCircle() { return 0; } //v54
	virtual void v58() {} //BOOL?, 0 arg
	virtual char GetFootCircleSize() { return 0; } //v5c
	virtual void v60() {} //LPCTSTR GetArmorLevelName()?
	virtual LPCTSTR GetFallingSound() { return 0; } //v64
	virtual void v68() {} //LPCTSTR, 0 arg
	virtual LPCTSTR GetWalkingSound(short wTerrainCode); //v6c
	virtual void v70() {} //int, 0 arg, get 1ah
	virtual BOOL GetUseColorRange() { return FALSE; } //v74
	virtual bool IsImmuneToDamage() { return false; } //v78
	virtual BOOL IsInMirrorOrientation() { return FALSE; } //v7c
	virtual BOOL IsCurrentFrameFirstFrame() { return FALSE; } //v80
	virtual BOOL IsAtEndOfCycle() { return FALSE; } //v84
	virtual void v88() {} //BOOL, 0 args, another cycle related thing
	virtual void DeleteCurrentVidCell() {} //v8c
	virtual void DecrementFrame() {} //v90
	virtual BOOL BltToBack(CInfinity& infinity, CVideoMode& vidmode) { return FALSE; } //v94
	virtual void DeinitColor(char nGroupRangeID) {} //v98
	virtual void DeinitAllColors() {} //v9c
	virtual void InitColor(int nColorGroup, int nGroupRangeId, ABGR rgbColor, char n) {} //va0
	virtual void InitAllColors(int nGroupId, ABGR rgbColor, char n) {} //va4
	virtual void SetColorRange(int nColorIdx, int nGroupRangeId) {} //va8
	virtual void SetAllColorRanges(int nGroupRangeId) {} //vac
	virtual short SetAnimationSequence(short wSeq) { return SEQ_READY; } //vb0
	virtual void vb4() {} //void, 3 args (pRect, pPt, ?)
	virtual void SetFootCircle() {} //vb8
	virtual void vbc() {} //set 22h
	virtual char GetInRoundAction() { return 0; } //vc0
	virtual BOOL CanBeTargetted() { return FALSE; } //vc4, for ankhegs
	virtual void vc8() {} //short, 1 arg
	virtual void vcc() {} //void, 1 arg (byte), set 3d4h
	virtual void vd0() {} //void, 1 arg (byte), set 3d5h
	virtual void vd4() {} //short, 0 arg
	virtual void vd8() {} //void, 1 arg (pPt)
	virtual bool GetCurrentCycleAndFrame(short& wCycle, short& wFrame); //vdc
	virtual bool GetAnimationResRefs(IECString& s1, IECString& s2, IECString& s3, IECString& s4) { return false; } //ve0, specific animations only?

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
