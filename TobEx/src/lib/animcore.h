#ifndef ANIMCORE_H
#define ANIMCORE_H

#include "utils.h"

#include "vidcore.h"
#include "resref.h"

class CCreatureObject;

class CAnimationSoundList : public CPtrList { //Size 28h
//Constructor: 0x87B3E0
//vtable: 0xAACCA0
public:
	BOOL PlayPrimedSound(DWORD, CCreatureObject*);

	//Elements are 0xc size objects (0x0 ResRef sound [first row], 0x8 frameToPlay [second row])
	POSITION posPrimedSound; //1ch
	BOOL bIgnorePrime; //20h
	DWORD dwChannel; //24h
};

extern BOOL (CAnimationSoundList::*CAnimationSoundList_PlayPrimedSound)(DWORD, CCreatureObject*);

class CAnimation { //Size 6D8h
//Constructor: 0x7F9211
//vtable: 0xAB6148 (generic), 0xAB678C (humanoids?), 0xAB6148 (7000h?)
public:
	void PlayCurrentAnimationSequenceSound(CCreatureObject*);

	virtual void v0() {}
	virtual void v4() {}
	virtual void v8() {}
	virtual void vc() {}
	virtual void v10() {}
	virtual void v14() {}
	virtual void v18() {}
	virtual void v1c() {}
	virtual void v20() {}
	virtual void v24() {}
	virtual void v28() {}
	virtual void v2c() {}
	virtual void v30() {}
	virtual void v34() {}
	virtual void v38() {}
	virtual void v3c() {}
	virtual void v40() {}
	virtual void v44() {}
	virtual void v48() {}
	virtual void v4c() {}
	virtual void v50() {}
	virtual void v54() {}
	virtual void v58() {}
	virtual void v5c() {}
	virtual void v60() {}
	virtual void v64() {}
	virtual void v68() {}
	virtual void v6c() {} //v6c, const char* GetWalkingSound()
	virtual void v70() {}
	virtual void v74() {}
	virtual void v78() {}
	virtual void v7c() {}
	virtual void v80() {}
	virtual void v84() {}
	virtual void v88() {}
	virtual void v8c() {}
	virtual void v90() {}
	virtual void v94() {}
	virtual void v98() {}
	virtual void v9c() {}
	virtual void va0() {}
	virtual void va4() {}
	virtual void va8() {}
	virtual void vac() {}
	virtual void vb0() {}
	virtual void vb4() {}
	virtual void vb8() {}
	virtual void vbc() {}
	virtual void vc0() {}
	virtual void vc4() {}
	virtual void vc8() {}
	virtual void vcc() {}
	virtual void vd0() {}
	virtual void vd4() {}
	virtual void vd8() {}
	virtual bool GetCurrentAnimationCycleAndFrame(WORD* pwCycle, WORD* pwFrame); //vdc, dummy

	WORD animId; //4h
	BYTE u6; //related to animId
	BYTE u7; //related to animId
	RECT rFootcircle; //8h
	BYTE u18;
	BYTE u19;
	DWORD u1a; //related to animId
	LPCTSTR szFallingSound; //1eh
	WORD u22[16]; //set by 0x7FA94F proc, either 0, 10, or -10, to do with orientations?
	CVidBitmap u42[5]; //42h, rndbase1-5
	BYTE nFootCircleSize; //3d0h, 3, 5, 7, 9, 13
	BYTE u3d1; //pad
	WORD wCyclesPerAnimation; //3d2h
	BYTE u3d4;
	BYTE u3d5;
	BYTE u3d6;
	ResRef rAniSnd; //3d7h
	BYTE u3df; //pad
	CAnimationSoundList soundset[19]; //3e0h, corresponds to rows of anim soundset 2DAs (19 in total)
};

extern void (CAnimation::*CAnimation_PlayCurrentAnimationSequenceSound)(CCreatureObject*);

struct AnimData {
//Size: 0x8
	CAnimation* pAnimation; //0h
	WORD wCurrentSequence; //4h
};

#endif //ANIMCORE_H
