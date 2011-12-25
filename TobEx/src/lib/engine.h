#ifndef ENGINE_H
#define ENGINE_H

#include "utils.h"
#include "resref.h"
#include "objcre.h"
#include "scrcore.h"
#include "vidcore.h"
#include "uiscroll.h"
#include "uicore.h"
#include "cstringex.h"
#include "infgame.h"

struct CHotkey { //Size 8h
	DWORD u0;
	BYTE nAsciiKey; //4h
	BYTE nKeyboardDelay; //5h
	BYTE nKeyboardSpeed; //6h
	BYTE u7;
};

class CEngineBase : public CObject { //Size 28h
//Constructor: 0x9E3010
public:
	//AB99A0
	virtual CRuntimeClass* GetRuntimeClass() const; //v0
	virtual ~CEngineBase(); //v4
	virtual void Serialize(CArchive& ar); //v8
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#else
	virtual void vc() {} //involves CopyRect (moving the manager?)
	virtual void v10() {} //does nothing
#endif
	virtual void v14() {} //init
	virtual void v18() {}
	virtual void v1c() {} //deconstruct panels
	virtual void v20() {} //construct manager, panels, etc.
	virtual void v24() {} //resets kit?
	virtual void v28() {}
	virtual void LoadEngine(CEngineBase& eng) {} //v2c
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
	virtual void v6c() {}
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
	virtual void UpdateEngineObjects() {} //vc8

	CVideoMode* pVideoMode; //4h
	CEngineBase* pEnginePrevious; //8h
	CObList m_EngineObjects; //ch, appears unused
};

class CEngine : protected CEngineBase { //Size FEh
//Constructor: 0x43AC8F
public:
	//AA60CC
	virtual CManager& GetManager() { return manager; } //vcc
	virtual DWORD GetActivePlayerIdx(); //vd0
	virtual DWORD GetActivePlayerIdx_copy() { return 0; } //vd4
	virtual void SetActivePlayerIdx(DWORD) {} //vd8
	virtual void SetActivePlayerIdx_copy(DWORD) {} //vdc
	virtual void ve0() {}
	virtual void ve4() {}
	virtual void ve8() {}
	virtual void vec() {}
	virtual void vf0() {}
	virtual void vf4() {}
	virtual void vf8() {}
	virtual void vfc() {}
	virtual void v100() {}
	virtual void v104() {}
	virtual void v108() {}
	virtual void v10c() {}
	virtual void v110() {}
	virtual void v114() {}
	virtual void v118() {}

	DWORD nActivePlayerIdx; //28h, invalid becomes 0
	DWORD nActivePlayerIdx_copy; //2ch, unused, invalid becomes -1
	CManager manager; //30h
	CUIScrollBar* pScrollActive; //fah, active scroll bar in focus
};

extern DWORD (CEngine::*CEngine_GetActivePlayerIdx)();

struct CEngineObject : public CObject { //SIze 20h
//Constructor: 0x9E32DE
public:
	//AB9A6C
	virtual CRuntimeClass* GetRuntimeClass() const; //v0
	virtual ~CEngineObject(); //v4
	virtual void Serialize(CArchive& ar); //v8
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#else
	virtual void vc() {} //does nothing
#endif

	//members
	BOOL bHasDuration; //4h
	BOOL bRemoveOnExpire; //8h, Arg3
	BOOL bInList; //ch
	CEngine* pEngine; //10h
	POSITION pos; //14h
	DWORD nDuration; //18h, Arg2 * 10
	DWORD nTimeElapsed; //1ch
};

class CStart : public CEngine {
//size: 0x680
//constructor: 0x7934E2
//vtable: 0xAB3BEC
public:
	virtual void v0() {}

	DWORD ufe;
	DWORD u102;
	CHotkey u106[5];
	DWORD u12e;
	DWORD u132;
	BYTE u136;
	BYTE u137;
	DWORD u138;
	DWORD u13c;
	CPtrList u140;
	DWORD u15c[8];
	DWORD u17c;
	CVidFont u184; //STONESML
};

class CStore : public CEngine {
//size: 0x148a
//constructor: 0x799A53
//vtable: 0xAB3FD4
public:
	virtual void v0() {}

	CHotkey ufe[91];
	DWORD u3d6[22];
	char u42e[3];
	BYTE u431;
	BYTE u432;
	BYTE u433; //pad
	DWORD u434;
	DWORD u438;
	DWORD u43c;
	CPtrList u440;
	DWORD u45c;
	CPtrList u460;
	DWORD u47c;
	CPtrList u480;
	DWORD u49c;
	CPtrList u4a0;
	DWORD u4bc;
	ResRef u4c0;
	ResRef u4c8;
	DWORD u4d0[4];
	DWORD u4e0;
	DWORD u4e4;
	DWORD u4e8;
	DWORD u4ec;
	DWORD u4f0;
	DWORD u4f4;
	DWORD u4f8;
	Object u4fc;
	Object u510;
	DWORD u524;
	DWORD u528;
	DWORD u52c;
	CPtrList u530;
	DWORD u54c[2];
	ResRef u554;
	DWORD u55c;
	DWORD u560;
	DWORD u564;
	DWORD u568[6];
	WORD u580;
	CVidFont u582;
	CVidFont ua7e;
	CVidFont uf7a;
	DWORD u1476;
	DWORD u147a;
	DWORD u147e;
	DWORD u1482;
	DWORD u1486;
};

#endif //ENGINE_H