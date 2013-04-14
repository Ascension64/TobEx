//TobExEE
#ifndef ANIMCORE_H
#define ANIMCORE_H

#include "stdafx.h"

#include "arecore.h"
#include "vidcore.h"

class CCreatureObject;

struct CAnimationSound { //Size Ch
	ResRef m_rSound; //0h, first row
	unsigned int m_nFrameToPlay; //8h, second row
};

class CAnimationSoundList : public IECPtrList { //Size 28h
public:
	BOOL PlayPrimedSound(int dwFrame, CCreatureObject& cre);

	POSITION m_posPrimedSound; //1ch
	BOOL m_bIgnorePrime; //20h
	unsigned int m_dwChannel; //24h
};

class CAnimation { //Size 6D0h
	DEFINE_MEMALLOC_FUNC;
public:
	CAnimation();
	CAnimation& Construct() { return *this; } //dummy

	void PlayCurrentSequenceSound(CCreatureObject& cre);

	//FIX_ME
	virtual ~CAnimation() {} //v0
	virtual void GetCurrentFrameDimensions(RECT* pFrame, CPoint* pCentre, int zPos) {} //v4
	virtual void v8() {} //? void GetBoundsRect(RECT* pBounds, CPoint* ppt1, CPoint* ppt2, zPos, width, height)
	virtual BOOL SetOrientation(short wOrient) { return TRUE; } //vc
	virtual void SetArmor(char cArmorLevel, CreFileColors& colors) {} //v10
	virtual void SetHelmet(IECString& sItemAnim, CreFileColors& colors) {} //v14
	virtual void SetShield(IECString& sItemAnim, CreFileColors& colors) {} //v18
	virtual void SetWeapon(IECString& sItemAnim, CreFileColors& colors, unsigned int nItemFlags, void* pAttackProb) {} //v1c
	virtual void v20() {} //VidPal& GetAnimGroupVidPal(nGroupId) (ids use second lowest digit i.e. 0xX0)
	virtual void GetAnimGroupPaperdollName(IECString* ptr, int nGroupId) {} //v24, ids use as above
	virtual bool CanLieDown() { return false; } //v28, CanUseMiddleVertList()
	virtual void v2c() {} //bool, 0 arg
	virtual short GetNumSeqPerAnimation() { return 0; } //v30
	virtual char GetVertListType() { return 0; } //v34, get 18h
	virtual void v38() {} //GetSomeGoreThing?, get 19h
	virtual char GetListType() { return 0; } //v3c
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
	virtual BOOL BltToBack(CInfinity& infinity, CVideo& vid) { return FALSE; } //v94
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
	virtual void vcc() {} //void, 1 arg (byte), set 3cch
	virtual void vd0() {} //void, 1 arg (byte), set 3cdh
	virtual void vd4() {} //short, 0 arg
	virtual void vd8() {} //void, 1 arg (pPt)
	virtual bool GetCurrentCycleAndFrame(short& wCycle, short& wFrame); //vdc
	virtual bool GetAnimationResRefs(IECString& s1, IECString& s2, IECString& s3, IECString& s4) { return false; } //ve0, specific animations only?
	
	unsigned short m_wAnimId; //4h
	unsigned char m_nMovementRateDefault; //6h
	unsigned char m_nMovementRateCurrent; //7h, modified by effects
	RECT m_rectFootcircle; //8h
	char u18;
	char u19;
	char p1a[2];
	int u1c; //related to animId
	LPCTSTR m_szFallingSound; //20h
	short u24[16]; //either 0, 10, or -10, to do with orientations?
	CVidBitmap m_cvdRoundBase[5]; //44h, rndbase1-5
	unsigned char m_nFootCircleSize; //3c8h; 3, 5, 7, 9, 13 (in diameter)
	char p3c9;
	short m_wCyclesPerAnimation; //3cah
	char u3cc;
	char u3cd;
	char u3ce;
	ResRef m_rAniSnd; //3cfh
	char p3d7;
	CAnimationSoundList m_soundset[19]; //3d8h, rows of anisnd 2DAs
};

struct AnimData { //Size 8h
	CAnimation* m_pAnimation; //0h
	short m_wCurrentSequence; //4h
	char p6[2];
};

#endif //ANIMCORE_H
