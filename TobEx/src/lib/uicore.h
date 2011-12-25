#ifndef UICORE_H
#define UICORE_H

#include "stdafx.h"
#include "vidcore.h"

class CEngine;
class CPanel;
class CUIControl;

extern void (__cdecl *FormatLabel)(CEngine& engine, CPanel& panel, int nLabelIdx, LPCTSTR szFormat, void* ptr);

struct CManager { //CAh
//Constructor: 0x584BE3
	CPanel& GetPanel(int index);

	int* u0; //0h
	BOOL bConstructed; //4h, checks if run constructor yet
	ResRef name; //8h
	CEngine* pEngine; //10h
	CUIControl* pActiveControl; //14h
	int u18; //18h
	int u1c; //1ch
	int u20; //20h
	int u24; //24h
	int u28; //28h
	char u2c; //2ch
	char u2d; //2dh
	BOOL u2e; //2eh
	int dwActiveButtonIndex; //32h
#ifdef _DEBUG
	_CCriticalSection u36; //36h
	_CCriticalSection u56; //56h, access to the global redraw counts
#else
	CCriticalSection u36; //36h
	CCriticalSection u56; //56h
#endif
	int u76; //76h
	RECT u7a; //7ah
	RECT u8a; //8ah
	RECT u9a; //9ah
	BOOL bDoubleSizeOfControls; //aah
	IECPtrList panels; //aeh
};

extern CPanel& (CManager::*CManager_GetPanel)(int);

struct CPanel { //Size 122h, in IESDP this is Window
//Constructor: 0x5828FA
	CUIControl& GetUIControl(int index);
	void Redraw(RECT* pr);

	CManager* pManager; //0h, pointer to parent CEngine.manager
	IECPtrList controls; //4h
	int index; //20h
	POINT pt2; //24h
	POINT pt1; //2ch
	int width; //34h
	int height; //38h
	short u3c; //unknown 0x1a of CHU window, bitfield bit 0 = negated and used, bit 1 = do not load?
	CVidMosaic u3e; //3eh
	short wRedrawAmount; //eeh
	BOOL bEnabled; //f0h
	RECT uf4;
	bool u104; //set if byte dh of controlInfo == 1
	char u105;
	BOOL bVisible; //106h
	BOOL bActive; //10ah, if 0 greys out the area
	RECT u10e;
	int u11e;
};

extern CUIControl& (CPanel::*CPanel_GetUIControl)(int);
extern void (CPanel::*CPanel_Redraw)(RECT*);

class CUIControl { //Size 4Ah
public:
	CUIControl();
	CUIControl(CPanel& panel, ChuFileControlInfoBase& controlInfo, BOOL b); //0x582650
	CUIControl& Construct(CPanel&, ChuFileControlInfoBase&, BOOL) { return *this; } //dummy

	//AAAD54
	virtual ~CUIControl(); //v0
	void Deconstruct() {} //dummy

	virtual void SetEnabled(bool b); //v4
	virtual BOOL OnMouseHover(POINT& pt); //v8
	virtual void OnLoseFocus(); //vc
	virtual void OnGetFocus(); //v10
	virtual void OnLMouseDrag(POINT pt); //v14
	virtual BOOL OnLMouseBtDn(POINT pt); //v18
	virtual void OnLMouseBtUp(POINT pt); //v1c
	virtual BOOL OnLMouseDblClk(POINT pt); //v20
	virtual BOOL OnRMouseBtDn(POINT pt); //v24
	virtual void OnRMouseBtUp(POINT pt); //v28
	virtual void OnKeyPress(short wChar); //v2c
	virtual void ShowTooltip(bool b); //v30
	virtual STRREF GetTooltip(); //v34
	virtual void HideTooltip(); //v38
	virtual void SetTooltip(STRREF strref); //v3c
	virtual void SetTooltipHotkey(short key1, short key2, IECString& text); //v40
	virtual void OnShowTooltip(); //v44
	virtual void SetRedraw(); //v48
	virtual BOOL Redraw(BOOL bForceRedraw); //v4c
	virtual BOOL GetVisible(); //v50
	virtual void SetVisible(BOOL b); //v54
	virtual BOOL NeedsRedraw(); //v58

	char u4;
	char u5; //pad
	CPanel* pPanel; //6h
	short index; //ah
	short uc; //ch
	POINT pos; //eh
	int width; //16h
	int height; //1ah
	bool bEnabled; //1eh, 1 = visible and active, 0 = inactive, but may be visible
	bool u1f; //set if byte dh of controlInfo == 1
	char u20;
	char u21; //padding?
	RECT u22;
	BOOL bVisible; //1 = visible, 0 = not visible unless bEnabled is set
	BOOL u36; //Arg3
	BOOL bTooltipState; //3ah
	STRREF strrefTooltipText; //3eh
	short wHotkey1; //42h, index of CInfGame::m_Keymap
	short wHotkey2; //44h, index of CInfGame::m_Keymap
	IECString sHotkeyTemp; //46h, gets full hotkey string
};

extern CUIControl& (CUIControl::*CUIControl_Construct)(CPanel&, ChuFileControlInfoBase&, BOOL);
extern void (CUIControl::*CUIControl_Deconstruct)();
extern void (CUIControl::*CUIControl_SetEnable)(bool);
extern BOOL (CUIControl::*CUIControl_OnMouseHover)(POINT&);
extern void (CUIControl::*CUIControl_OnLoseFocus)();
extern void (CUIControl::*CUIControl_OnGetFocus)();
extern void (CUIControl::*CUIControl_OnLMouseDrag)(POINT);
extern BOOL (CUIControl::*CUIControl_OnLMouseBtDn)(POINT);
extern void (CUIControl::*CUIControl_OnLMouseBtUp)(POINT);
extern BOOL (CUIControl::*CUIControl_OnLMouseDblClk)(POINT);
extern BOOL (CUIControl::*CUIControl_OnRMouseBtDn)(POINT);
extern void (CUIControl::*CUIControl_OnRMouseBtUp)(POINT);
extern void (CUIControl::*CUIControl_OnKeyPress)(short);
extern void (CUIControl::*CUIControl_ShowTooltip)(bool);
extern STRREF (CUIControl::*CUIControl_GetTooltip)();
extern void (CUIControl::*CUIControl_HideTooltip)();
extern void (CUIControl::*CUIControl_SetTooltip)(STRREF);
extern void (CUIControl::*CUIControl_SetTooltipHotkey)(short, short, IECString&);
extern void (CUIControl::*CUIControl_OnShowTooltip)();
extern void (CUIControl::*CUIControl_SetRedraw)();
extern BOOL (CUIControl::*CUIControl_Redraw)(BOOL);
extern BOOL (CUIControl::*CUIControl_GetVisible)();
extern void (CUIControl::*CUIControl_SetVisible)(BOOL);
extern BOOL (CUIControl::*CUIControl_NeedsRedraw)();

class CUILabel : public CUIControl { //Size 554h
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

extern CUIControl* (__cdecl *CreateUIControl)(CPanel&, ChuFileControlInfoBase&);

#endif //UICORE_H