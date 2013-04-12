//TobExEE
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

struct CHotkey { //Size Ch
	int m_nTicksPressed; //0h
	int m_nAsciiKey; //4h
	char m_nKeyboardDelay; //8h
	char m_nKeyboardSpeed; //9h
	char pa[2];
};

class CEngineBase /*: public CObject*/ { //Size 24h
public:
	virtual ~CEngineBase(); //v0
	virtual void v4() {}
	virtual void v8() {}
	virtual void vc() {}
	virtual void v10() {}
	virtual void v14() {}
	virtual void Init() {} //v18, show engine
	virtual void Deinit() {} //v1c, hide engine
	virtual void v20() {} //deconstruct panels
	virtual void v24() {} //construct manager, panels, etc.
	virtual void v28() {} //resets kit?
	virtual void v2c() {}
	virtual void v30() {} //? LoadEngine(CEngineBase& eng), closes current engine, loads Arg1
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
	virtual void va4() {} //? GetNumHotkeys()
	virtual void va8() {} //? CHotkey* GetKeymap()
	virtual void vac() {} //? char* GetKeyBuffer()
	virtual void vb0() {} //? void ProcessKeyBuffer(short wKeysPressed)
	virtual void vb4() {}
	virtual void vb8() {}
	virtual void vbc() {} //ProcessKeyBuffer()
	virtual void vc0() {}
	virtual void vc4() {}
	virtual void vc8() {}
	virtual void vec() {}
	virtual void vd0() {}
	virtual void vd4() {}
	virtual void vd8() {}
	virtual void vdc() {}
	virtual void UpdateEngineObjects() {} //ve0

	CEngineBase* pEnginePrevious; //4h
	CObList m_EngineObjects; //8h, unused CEngineObject not defined in BG:EE
};

class CEngine : protected CEngineBase { //Size D0h
public:
	virtual CManager& GetManager() { return manager; } //ve4
	virtual int GetActivePlayerIdx(); //ve8
	virtual int GetActivePlayerIdx_copy() { return 0; } //vec
	virtual void SetActivePlayerIdx(int) {} //vf0
	virtual void SetActivePlayerIdx_copy(int) {} //vf4
	virtual void vf8() {}
	virtual void vfc() {}
	virtual void v100() {}
	virtual void v104() {}
	virtual void v108() {} //? UpdatePartyMemberControlStates(int nPanelIndex)
	virtual void v10c() {} //? UpdatePartyMemberControlSelectedState()
	virtual void v110() {}
	virtual void v114() {}
	virtual void v118() {}
	virtual void v11c() {}
	virtual void v120() {} //SetEnableAndVisible(int nPanelIndex, int nControlIndex, BOOL bActive)
	virtual void v124() {}
	virtual void v128() {}
	virtual void v12c() {}
	virtual void v130() {}

	int nActivePlayerIdx; //24h, invalid becomes 0
	int nActivePlayerIdx_copy; //28h, unused, invalid becomes -1
	CManager manager; //2ch
	CUIScrollBar* pScrollActive; //c0h, active scroll bar in focus
	int uc4;
	int uc8;
	int ucc;
};

class CScreenStart : public CEngine { //Size 1A0h
public:
	int ud0;
	int ud4;
	CHotkey ud8[5];
	int u114;
	int u118;
	int u11c;
	int u120;
	int u124;
	int u128;
	char u12c;
	char p12d[3];
	int m_nMenuProgress; //130h, 0: main, 1: SP submenu, 2: MP submenu
	int u134;
	IECPtrList m_OpenPanels; //138h
	int u154;
	int u158;
	int u15c;
	int u160;
	int u164;
	int u168;
	int u16c;
	int u170;
	int u174;
	int u178;
	CVidFont u17c; //STONESML
};

#endif //ENGINE_H