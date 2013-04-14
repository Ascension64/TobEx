//TobExEE
#ifndef UICORE_H
#define UICORE_H

#include "stdafx.h"
#include "p_uicore.h"

#include "vidcore.h"

class CEngine;
class CPanel;
class CUIControl;

struct CManager { //94h
	int* u0; //0h
	BOOL m_bConstructed; //4h, checks if run constructor yet
	int u8;
	ResRef m_rName; //ch
	CEngine* m_pEngine; //14h
	CUIControl* m_pActiveControl; //18h
	int u1c;
	int u20;
	int u24;
	int u28;
	int u2c;
	char u30;
	char u31;
	char p32[2];
	int u34;
	int m_dwActiveButtonIndex; //38h
	int u3c;
	RECT u40;
	RECT u50;
	RECT u60;
	int u70;
	BOOL m_bDoubleSizeOfControls; //74h
	IECPtrList m_lPanels; //78h
};

struct CPanel { //Size 130h
	//AKA Window in IESDP
	CManager* m_pManager; //0h, pointer to parent CEngine.manager
	IECPtrList m_lControls; //4h
	int m_nIndex; //20h
	CPoint m_pt2; //24h
	CPoint m_pt1; //2ch
	CPoint m_ptSize; //34h
	CPoint u3c;
	short u44; //unknown 0x1a of CHU window, bitfield bit 0 = negated and used, bit 1 = do not load?
	char p46[2];
	CVidMosaic u48; //48h
	short m_wRedrawAmount; //f8h
	char pfa[2];
	BOOL m_bEnabled; //fch
	RECT u100;
	bool u110; //set if byte dh of controlInfo == 1
	char p111[3];
	BOOL m_bVisible; //114h
	BOOL m_bActive; //118h, if 0 greys out the area
	RECT u11c;
	int u12c;
};

class CUIControl { //Size 54h
public:
	virtual ~CUIControl(); //v0
	void Deconstruct() {} //dummy

	virtual void v4() {}
	virtual void SetEnabled(bool b); //v8
	virtual BOOL OnMouseHover(CPoint& pt); //vc
	virtual void OnLoseFocus(); //v10
	virtual void OnGetFocus(); //v14
	virtual void OnLMouseDrag(CPoint pt); //v18
	virtual BOOL OnLMouseBtDn(CPoint pt); //v1c
	virtual void OnLMouseBtUp(CPoint pt); //v20
	virtual BOOL OnLMouseDblClk(CPoint pt); //v24
	virtual BOOL OnRMouseBtDn(CPoint pt); //v28
	virtual void OnRMouseBtUp(CPoint pt); //v2c
	virtual void v30() {}
	virtual void v34() {}
	virtual void OnKeyPress(short wChar); //v38
	virtual void ShowTooltip(bool b); //v3c
	virtual STRREF GetTooltip(); //v40
	virtual void HideTooltip(); //v44
	virtual void SetTooltip(STRREF strref); //v48
	virtual void SetTooltipHotkey(short key1, short key2, IECString& text); //v4c
	virtual void OnShowTooltip(); //v50
	virtual void SetRedraw(); //v54
	virtual BOOL Redraw(BOOL bForceRedraw); //v58
	virtual BOOL GetVisible(); //v5c
	virtual void SetVisible(BOOL b); //v60
	virtual BOOL NeedsRedraw(); //v64
	virtual void v68() {} //v68

	char u4;
	char p5[3];
	CPanel* m_pPanel; //8h
	short m_wIndex; //ch
	short uc; //eh
	CPoint m_ptPos; //10h
	CPoint m_ptPos2; //18h
	CPoint m_ptSize; //20h
	bool m_bEnabled; //28h, 1 = visible and active, 0 = inactive, but may be visible
	bool u29; //set if byte dh of controlInfo == 1
	char u2a;
	char p2b;
	RECT u2c;
	BOOL m_bVisible; //3ch, 1 = visible, 0 = not visible unless bEnabled is set
	BOOL u40; //Arg3
	BOOL m_bTooltipState; //44h
	STRREF m_strrefTooltipText; //48h
	short m_wHotkey1; //4ch, index of CInfGame::m_Keymap
	short m_wHotkey2; //4eh, index of CInfGame::m_Keymap
	IECString m_sHotkeyTemp; //50h, gets full hotkey string
};

class CUILabel : public CUIControl { //Size 554h, FIX_ME
//Constructor: 0x5A0BD7
public:

	int* pText; //4ah
	short u4e;
	CVidFont u50;
	short u54c;
	unsigned short textFlags;
	short u550;
	char u552; //to do with colors
	char u553; //padding?
};

DefineGlobalFuncPtr(CUIControl*, __cdecl, CreateUIControl, (CPanel& panel, ChuFileControlInfoBase& controlInfo), _CREATEUICONTROL);

#endif //UICORE_H