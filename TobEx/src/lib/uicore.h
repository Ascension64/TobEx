#ifndef UICORE_H
#define UICORE_H

#include "utils.h"
#include "resref.h"
#include "vidcore.h"
#include "cstringex.h"

typedef void* CUIScrollBarVT[30];

class CEngine;
class CPanel;
class CUIControl;

struct CManager { //CAh
//Constructor: 0x584BE3
	//functions
	CPanel& GetPanel(DWORD);

	//members
	DWORD u0; //0h
	BOOL bConstructed; //4h, checks if run constructor yet
	ResRef name; //8h
	CEngine* pEngine; //10h
	CUIControl* pActiveControl; //14h
	DWORD u18; //18h
	DWORD u1c; //1ch
	DWORD u20; //20h
	DWORD u24; //24h
	DWORD u28; //28h
	BYTE u2c; //2ch
	BYTE u2d; //2dh
	BOOL u2e; //2eh
	DWORD dwActiveButtonIndex; //32h
#ifdef _DEBUG
	_CCriticalSection u36; //36h
	_CCriticalSection u56; //56h, access to the global redraw counts
#else
	CCriticalSection u36; //36h
	CCriticalSection u56; //56h
#endif
	DWORD u76; //76h
	RECT u7a; //7ah
	RECT u8a; //8ah
	RECT u9a; //9ah
	DWORD uaa; //aah
	CPtrList panels; //aeh
};

extern CPanel& (CManager::*CManager_GetPanel)(DWORD);

struct CPanel { //Size 122h, in IESDP this is Window
//Constructor: 0x5828FA
	//functions
	CUIControl& GetUIControl(DWORD);

	//members
	CManager* pManager; //0h, pointer to parent CEngine.manager
	CPtrList controls; //4h
	DWORD index; //20h
	POINT pt2; //24h
	POINT pt1; //2ch
	DWORD width; //34h
	DWORD height; //38h
	WORD u3c; //unknown 0x1a of CHU window, bitfield bit 0 = negated and used, bit 1 = do not load?
	CVidMosaic u3e; //3eh
	WORD wRedrawAmount; //eeh
	BOOL bEnabled; //f0h
	RECT uf4;
	bool u104; //set if byte dh of controlInfo == 1
	BYTE u105;
	BOOL bVisible; //106h
	DWORD u10a;
	RECT u10e;
	DWORD u11e;
};

extern CUIControl& (CPanel::*CPanel_GetUIControl)(DWORD);

class CUIControl { //4Ah
public:
	CUIControl();
	CUIControl(CPanel&, ChuFileControlInfoBase&, BOOL); //0x582650
	CUIControl& Construct(CPanel&, ChuFileControlInfoBase&, BOOL) { return *this; } //dummy

	//AAAD54
	virtual ~CUIControl(); //v0
	void Deconstruct() {} //dummy

	virtual void SetEnabled(bool); //v4
	virtual BOOL OnMouseHover(POINT&); //v8
	virtual void OnLoseFocus(void); //vc
	virtual void OnGetFocus(void); //v10
	virtual void OnLMouseDrag(POINT); //v14
	virtual BOOL OnLMouseBtDn(POINT); //v18
	virtual void OnLMouseBtUp(POINT); //v1c
	virtual BOOL OnLMouseDblClk(POINT); //v20
	virtual BOOL OnRMouseBtDn(POINT); //v24
	virtual void OnRMouseBtUp(POINT); //v28
	virtual void v2c(int); //v2c
	virtual void UpdateToolTip(bool); //v30
	virtual STRREF GetToolTip(); //v34
	virtual void v38(); //v38
	virtual void SetToolTip(STRREF); //v3c
	virtual void SetToolTipHotkey(WORD, WORD, IECString&); //v40
	virtual void ShowToolTip(void); //v44
	virtual void SetRedraw(void); //v48
	virtual BOOL Redraw(BOOL); //v4c
	virtual BOOL GetVisible(void); //v50
	virtual void SetVisible(BOOL); //v54
	virtual BOOL NeedsRedraw(void); //v58

	//members
	BYTE u4;
	BYTE u5; //pad
	CPanel* pPanel; //6h
	WORD index; //ah
	WORD uc; //ch
	POINT pos; //eh
	DWORD width; //16h
	DWORD height; //1ah
	bool bEnabled; //1eh, 1 = visible and active, 0 = inactive, but may be visible
	bool u1f; //set if byte dh of controlInfo == 1
	BYTE u20;
	BYTE u21; //padding?
	RECT u22;
	BOOL bVisible; //1 = visible, 0 = not visible unless bEnabled is set
	BOOL u36; //Arg3
	BOOL u3a;
	STRREF u3e; //tooltip?
	WORD u42;
	WORD u44;
	IECString sHotkeyName; //46h
};

extern CUIControl& (CUIControl::*CUIControl_Construct)(CPanel&, ChuFileControlInfoBase&, BOOL);
extern void (CUIControl::*CUIControl_Deconstruct)();
extern void (CUIControl::*CUIControl_SetEnable)(bool);
extern BOOL (CUIControl::*CUIControl_OnMouseHover)(POINT&);
extern void (CUIControl::*CUIControl_OnLoseFocus)(void);
extern void (CUIControl::*CUIControl_OnGetFocus)(void);
extern void (CUIControl::*CUIControl_OnLMouseDrag)(POINT);
extern BOOL (CUIControl::*CUIControl_OnLMouseBtDn)(POINT);
extern void (CUIControl::*CUIControl_OnLMouseBtUp)(POINT);
extern BOOL (CUIControl::*CUIControl_OnLMouseDblClk)(POINT);
extern BOOL (CUIControl::*CUIControl_OnRMouseBtDn)(POINT);
extern void (CUIControl::*CUIControl_OnRMouseBtUp)(POINT);
extern void (CUIControl::*CUIControl_v2c)(int);
extern void (CUIControl::*CUIControl_UpdateToolTip)(bool);
extern STRREF (CUIControl::*CUIControl_GetToolTip)();
extern void (CUIControl::*CUIControl_v38)();
extern void (CUIControl::*CUIControl_SetToolTip)(STRREF);
extern void (CUIControl::*CUIControl_SetToolTipHotkey)(WORD, WORD, IECString&);
extern void (CUIControl::*CUIControl_ShowToolTip)(void);
extern void (CUIControl::*CUIControl_SetRedraw)(void);
extern BOOL (CUIControl::*CUIControl_Redraw)(BOOL);
extern BOOL (CUIControl::*CUIControl_GetVisible)(void);
extern void (CUIControl::*CUIControl_SetVisible)(BOOL);
extern BOOL (CUIControl::*CUIControl_NeedsRedraw)(void);

class CUILabel : public CUIControl { //Size 554h
//Constructor: 0x5A0BD7
public:

	DWORD* pText; //0x4A
	WORD u4e;
	CVidFont u50;
	WORD u54c;
	WORD textFlags;
	WORD u550;
	BYTE u552; //to do with colors
	BYTE u553; //padding?
};

class CUITextArea : public CUIControl { //Size AA8h
//Constructor: 0x59C60C
//FIX_ME
public:
};

class CUITextField : public CUIControl { //Size 87Eh
//Constructor: 0x59C00A
//FIX_ME
public:
};

extern CUIControl* (__cdecl *CreateUIControl)(CPanel&, ChuFileControlInfoBase&);

#endif //UICORE_H