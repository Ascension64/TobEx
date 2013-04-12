#ifndef ENGINE_H
#define ENGINE_H

#include "stdafx.h"
#include "resref.h"
#include "objcre.h"
#include "scrcore.h"
#include "vidcore.h"
#include "uiscroll.h"
#include "uicore.h"
#include "cstringex.h"
#include "infgame.h"

struct CHotkey { //Size 8h
	int nTicksPressed; //0h
	unsigned char nAsciiKey; //4h
	char nKeyboardDelay; //5h
	char nKeyboardSpeed; //6h
	char u7;
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
	virtual void Init() {} //v14, show engine
	virtual void Deinit() {} //v18, hide engine
	virtual void v1c() {} //deconstruct panels
	virtual void v20() {} //construct manager, panels, etc.
	virtual void v24() {} //resets kit?
	virtual void v28() {}
	virtual void LoadEngine(CEngineBase& eng) {} //v2c, closes current engine, loads Arg1
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
	virtual int GetNumHotkeys() { return 0; } //va0
	virtual CHotkey* GetKeymap() { return NULL; } //va4
	virtual char* GetKeyBuffer() { return NULL; } //va8
	virtual void ProcessKeyBuffer(short wKeysPressed) {} //vac
	virtual void vb0() {}
	virtual void vb4() {}
	virtual void vb8() {}
	virtual void vbc() {}
	virtual void vc0() {} //UpdateProc()
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
	virtual int GetActivePlayerIdx(); //vd0
	virtual int GetActivePlayerIdx_copy() { return 0; } //vd4
	virtual void SetActivePlayerIdx(int) {} //vd8
	virtual void SetActivePlayerIdx_copy(int) {} //vdc
	virtual void ve0() {}
	virtual void ve4() {}
	virtual void ve8() {}
	virtual void vec() {}
	virtual void vf0() {}
	virtual void vf4() {}
	virtual void UpdatePartyMemberControlStates(int nPanelIndex); //vf8
	virtual void UpdatePartyMemberControlSelectedState(); //vfc
	virtual void v100() {}
	virtual void v104() {}
	virtual void v108() {}
	virtual void v10c() {}
	virtual void SetEnableAndVisible(int nPanelIndex, int nControlIndex, BOOL bActive) {} //v100
	virtual void v114() {}
	virtual void v118() {}

	int nActivePlayerIdx; //28h, invalid becomes 0
	int nActivePlayerIdx_copy; //2ch, unused, invalid becomes -1
	CManager manager; //30h
	CUIScrollBar* pScrollActive; //fah, active scroll bar in focus
};

struct CEngineObject : public CObject { //Size 20h
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

	BOOL bHasDuration; //4h
	BOOL bRemoveOnExpire; //8h, Arg3
	BOOL bInList; //ch
	CEngine* pEngine; //10h
	POSITION pos; //14h
	int nDuration; //18h, Arg2 * 10
	int nTimeElapsed; //1ch
};

class CScreenStart : public CEngine { //Size 680h
//constructor: 0x7934E2
public:
	//AB3BEC
	virtual void v0() {}

	int ufe;
	int u102;
	CHotkey u106[5];
	int u12e;
	int u132;
	char u136;
	char u137;
	int m_nMenuProgress; //138h, 0: main, 1: SP submenu, 2: MP submenu
	int u13c;
	IECPtrList m_OpenPanels; //140h
	int u15c[8];
	int u17c;
	CVidFont u184; //STONESML
};

#endif //ENGINE_H