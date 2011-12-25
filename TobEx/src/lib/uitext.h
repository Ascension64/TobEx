#ifndef UITEXT_H
#define UITEXT_H

#include "uicore.h"

typedef IECPtrList CTextAreaEntryList; //AAB0C8

struct TextAreaEntry { //Size 20h
//Constructor: 0x59C518
	IECString sLeft; //0h
	IECString sRight; //4h
	POSITION posBoss; //8h
	int ch; //ch
	ARGB rgbLeft; //10h
	ARGB rgbRight; //14h
	int nRows; //18h?
	short u1c;
	short u1e;
};

class CUITextArea : public CUIControl { //Size AA8h
//Constructor: 0x59C60C
public:
	//AAB0E0
	virtual ~CUITextArea(); //v0
	void Deconstruct() {} //dummy

	virtual void SetEnabled(bool b); //v4
	virtual void OnLMouseDrag(POINT pt); //v14
	virtual BOOL OnLMouseBtDn(POINT pt); //v18
	virtual void OnLMouseBtUp(POINT pt); //v1c
	virtual void ShowTooltip(bool b); //v30
	virtual void SetRedraw(); //v48
	virtual BOOL Redraw(BOOL bForceRedraw); //v4c
	virtual BOOL NeedsRedraw(); //v58

	virtual void HighlightText(POSITION pos); //v5c
	virtual void UnhighlightText(); //v60
	virtual void OnLClicked(POINT pt); //v64
	virtual void v68(int n); //v68, Arg1 = ch of TextAreaEntry

	CTextAreaEntryList* m_plstStrings; //4ah
	POSITION m_posTopString; //4eh
	short wCurrentEntry; //52h
	short u54;
	short u56;
	CVidFont fontLeft; //58h
	CVidFont fontRight; //554h
	short wFontHeight; //a50h
	short ua52;
	char ua54;
	char ua55;
	char ua56;
	char ua57;
	short wRowsMax; //a58h (0xB15016)
	short wTextLines; //a5ah
	short wRowsCurrent; //a5ch
	int nScrollBarId; //a5eh
	ARGB rgbColor2; //a62h
	ARGB rgbColor3; //a66h
	ARGB rgbColor1; //a6ah
	ARGB colSelected; //a6eh
	POSITION posSelected; //a72h
	ARGB colStoredRight; //a76h, stores old color of selected text
	ARGB colStoredLeft; //a7ah, stores old color of selected text
#ifdef _DEBUG
	_CCriticalSection ua7e;
#else
	CCriticalSection ua7e;
#endif
	bool bSingleColorLeft; //a9eh
	bool bSingleColorRight; //a9fh
	IECString sDivider; //aa0h, "- "
	short uaa4;
	bool bMultiline; //aa6h
	bool bConstructed; //aa7h
};

extern void (CUITextArea::*CUITextArea_Deconstruct)();
extern void (CUITextArea::*CUITextArea_SetEnabled)(bool);
extern void (CUITextArea::*CUITextArea_OnLMouseDrag)(POINT);
extern BOOL (CUITextArea::*CUITextArea_OnLMouseBtDn)(POINT);
extern void (CUITextArea::*CUITextArea_OnLMouseBtUp)(POINT);
extern void (CUITextArea::*CUITextArea_ShowTooltip)(bool);
extern void (CUITextArea::*CUITextArea_SetRedraw)();
extern BOOL (CUITextArea::*CUITextArea_Redraw)(BOOL);
extern BOOL (CUITextArea::*CUITextArea_NeedsRedraw)();
extern void (CUITextArea::*CUITextArea_HighlightText)(POSITION);
extern void (CUITextArea::*CUITextArea_UnhighlightText)();
extern void (CUITextArea::*CUITextArea_OnLClicked)(POINT);
extern void (CUITextArea::*CUITextArea_v68)(int);

class CUITextField : public CUIControl { //Size 87Eh
//Constructor: 0x59C00A
public:
	//AAB058 (base AAAFE8)
	virtual ~CUITextField(); //v0
	void Deconstruct() {} //dummy

	virtual void SetEnabled(bool b); //v4
	virtual void OnLoseFocus(); //vc
	virtual void OnGetFocus(); //v10
	virtual void OnLMouseDrag(POINT pt); //v14
	virtual BOOL OnLMouseBtDn(POINT pt); //v18
	virtual void OnLMouseBtUp(POINT pt); //v1c
	virtual BOOL OnRMouseBtDn(POINT pt); //v24
	virtual void OnKeyPress(short wChar); //v2c
	virtual void SetRedraw(); //v48
	virtual BOOL Redraw(BOOL bForceRedraw); //v4c
	virtual BOOL NeedsRedraw(); //v58

	void SetTextColors(ARGB colText, ARGB colGreyed); //v5c
	void ClearText(IECString& s); //v60
	IECString GetText(); //v64
	void SetText(IECString& s); //v68
	void UpdateDisplayArea(); //v6c

	CVidMosaic u4a;
	CVidMosaic ufa;
	CVidMosaic u1aa;
	CVidCell cvcCursor; //25ah
	POINT ptXY; //330h, from controlInfo (32h, 34h)
	POINT pt; //338h
	CVidFont font; //340h
	short u83c; //from controlInfo 66h
	short u83e; //from controlInfo 68h
	short u840;
	int u842;
	IECString sText; //846h, from controlInfo 44h (null-terminated string, size 32?)
	IECString sTemp; //84ah, used during SetText()
	int nCaretPosition; //84eh
	int wCurrScrollValue; //852h
	int u856;
	char u85a;
	char u85b;
	short wRows; //85ch
	short wMaxScrollValue; //85eh
	ARGB colText; //860h
	ARGB colGreyed; //864h
	int u868;
	char u86c;
	char u86d; //pad
	int nHighlightLeftIndex; //86eh
	int nHighlightRightIndex; //872h
	int nScrollBarId; ///876h, from controlInfo 36h
	char u87a;
	char u87b;
	char u87c;
	char u87d;
};

extern void (CUITextField::*CUITextField_Deconstruct)();
extern void (CUITextField::*CUITextField_SetEnabled)(bool);
extern void (CUITextField::*CUITextField_OnLoseFocus)();
extern void (CUITextField::*CUITextField_OnGetFocus)();
extern void (CUITextField::*CUITextField_OnLMouseDrag)(POINT);
extern BOOL (CUITextField::*CUITextField_OnLMouseBtDn)(POINT);
extern void (CUITextField::*CUITextField_OnLMouseBtUp)(POINT);
extern BOOL (CUITextField::*CUITextField_OnRMouseBtDn)(POINT);
extern void (CUITextField::*CUITextField_OnKeyPress)(short);
extern void (CUITextField::*CUITextField_SetRedraw)();
extern BOOL (CUITextField::*CUITextField_Redraw)(BOOL);
extern BOOL (CUITextField::*CUITextField_NeedsRedraw)();
extern void (CUITextField::*CUITextField_SetTextColors)(ARGB, ARGB);
extern void (CUITextField::*CUITextField_ClearText)(IECString&);
extern IECString (CUITextField::*CUITextField_GetText)();
extern void (CUITextField::*CUITextField_SetText)(IECString&);
extern void (CUITextField::*CUITextField_UpdateDisplayArea)();

#endif //UITEXT_H