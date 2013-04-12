#ifndef UITEXT_H
#define UITEXT_H

#include "uicore.h"

typedef IECPtrList CTextAreaEntryList; //AAB0C8

#define CUITEXTAREA_USERARG_NONE	0 //AAAE20

struct TextAreaEntry { //Size 20h
//Constructor: 0x59C518
	IECString sLeft; //0h
	IECString sRight; //4h
	POSITION posBoss; //8h, pos containing first TextAreaEntry
	int nUserArg; //ch, passed to CTextArea::UserProc()
	ABGR rgbLeft; //10h
	ABGR rgbRight; //14h
	int nRows; //18h, only for first TextAreaEntry
	short wIndent; //1ch, in pixels
	short wRowIdx; //1eh
};

class CUITextArea : public CUIControl { //Size AA8h
//Constructor: 0x59C60C
public:
	//AAB0E0
	virtual ~CUITextArea(); //v0
	void Deconstruct() {} //dummy

	virtual void SetEnabled(bool b); //v4
	virtual void OnLMouseDrag(CPoint pt); //v14
	virtual BOOL OnLMouseBtDn(CPoint pt); //v18
	virtual void OnLMouseBtUp(CPoint pt); //v1c
	virtual void ShowTooltip(bool b); //v30
	virtual void SetRedraw(); //v48
	virtual BOOL Redraw(BOOL bForceRedraw); //v4c
	virtual BOOL NeedsRedraw(); //v58

	virtual void HighlightText(POSITION pos); //v5c
	virtual void UnhighlightText(); //v60
	virtual void OnLClicked(CPoint pt); //v64, calls UserProc()
	virtual void UserProc(int nArg); //v68, nArg = TextAreaEntry.nUserArg, e.g. selecting custom script

	POSITION Append(IECString& sLeft, IECString& sRight, ABGR colLeft, ABGR colRight, int nUserArg, bool bResetScrollbar);
	void ClearText();

	CTextAreaEntryList* m_plstStrings; //4ah
	POSITION m_posCurrString; //4eh
	short wCurrString; //52h, to set the scroll bar position
	short u54;
	short u56;
	CVidFont fontLeft; //58h
	CVidFont fontRight; //554h
	short wFontHeight; //a50h
	short ua52;
	char ua54;
	char m_nNewRows; //a55h?
	char ua56;
	char ua57;
	short wRowsMax; //a58h (0xB15016)
	short wRowsPerPage; //a5ah
	short wNumStrings; //a5ch
	int nScrollBarId; //a5eh
	ABGR colLeft; //a62h, col2
	ABGR rgbColor3; //a66h, col3
	ABGR colRight; //a6ah, col1
	ABGR colSelected; //a6eh
	POSITION posSelected; //a72h
	ABGR colStoredRight; //a76h, stores old color of selected text
	ABGR colStoredLeft; //a7ah, stores old color of selected text
#ifdef _DEBUG
	_CCriticalSection csStrings; //a7eh, for access to m_plstStrings
#else
	CCriticalSection csString; //a7eh
#endif
	bool bSingleColorLeft; //a9eh
	bool bSingleColorRight; //a9fh
	IECString sDivider; //aa0h, "- "
	short uaa4;
	bool bMultiline; //aa6h
	bool bConstructed; //aa7h
};

class CUITextField : public CUIControl { //Size 87Eh
//Constructor: 0x59C00A
public:
	//AAB058 (base AAAFE8)
	virtual ~CUITextField(); //v0
	void Deconstruct() {} //dummy

	virtual void SetEnabled(bool b); //v4
	virtual void OnLoseFocus(); //vc
	virtual void OnGetFocus(); //v10
	virtual void OnLMouseDrag(CPoint pt); //v14
	virtual BOOL OnLMouseBtDn(CPoint pt); //v18
	virtual void OnLMouseBtUp(CPoint pt); //v1c
	virtual BOOL OnRMouseBtDn(CPoint pt); //v24
	virtual void OnKeyPress(short wChar); //v2c
	virtual void SetRedraw(); //v48
	virtual BOOL Redraw(BOOL bForceRedraw); //v4c
	virtual BOOL NeedsRedraw(); //v58

	void SetTextColors(ABGR colText, ABGR colGreyed); //v5c
	void Execute(IECString& s); //v60
	IECString GetText(); //v64
	void SetText(IECString& s); //v68
	void UpdateDisplayArea(); //v6c

	CVidMosaic u4a;
	CVidMosaic ufa;
	CVidMosaic u1aa;
	CVidCell cvcCursor; //25ah
	CPoint ptXY; //330h, from controlInfo (32h, 34h)
	CPoint pt; //338h
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
	ABGR colText; //860h
	ABGR colGreyed; //864h
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

class CUITextBar : public CUIControl { //size 886h
//Similar to CUITextField except it only supports a single row
//Constructor: 0x58931D
public:
	//AAAF80
	virtual ~CUITextBar(); //v0
	void Deconstruct() {} //dummy

	virtual void SetEnabled(bool b); //v4
	virtual void OnLoseFocus(); //vc
	virtual void OnGetFocus(); //v10
	virtual BOOL OnLMouseBtDn(CPoint pt); //v18
	virtual BOOL OnRMouseBtDn(CPoint pt); //v24
	virtual void OnKeyPress(short wChar); //v2c
	virtual void SetRedraw(); //v48
	virtual BOOL Redraw(BOOL bForceRedraw); //v4c
	virtual BOOL NeedsRedraw(); //v58

	void Execute(IECString& s); //v5c
	IECString GetText(); //v60
	void SetText(IECString& s); //v64

	CVidMosaic u4a;
	CVidMosaic ufa;
	CVidMosaic u1aa;
	CVidCell cvcCursor; //25ah
	CPoint ptXY; //330h, from controlInfo (32h, 34h)
	CPoint pt; //338h, from controlInfo (36h, 38h)
	CVidFont font; //340h
	short m_wMaxInputLength; //83ch, from controlInfo 64h
	short m_wTextCase; //83eh, from controlInfo 66h
	short m_wTextMode; //840h, 2 = ignore space and letters
	short m_wTextLength;
	int u844;
	IECString sText; //848h, from controlInfo 44h (initial text)
	IECString sTextPrevious; //84ch, for when user cancels
	short m_wCaretPosition; //850h
	int m_nScrollPosition; //852h, first index when text scrolled right
	char m_nBufferIdx; //856h
	char m_nBuffers; //857h
	IECString m_sBuffers[10]; //858h
	int u880;
	char u884;
	char u885; //pad
};

class CUITextBarWorldChat : public CUITextBar { //size 88Ch
//Constructor: 0x97B131
public:
	//AB7AA0
	virtual ~CUITextBarWorldChat(); //v0
	void Deconstruct() {} //dummy

	void Execute(IECString& s); //v5c

	ENUM m_eDebug; //886h, the enum to debug dump on
	bool m_bDebugState; //88ah, true = do debug dump
	char u88b; //pad
};

#endif //UITEXT_H