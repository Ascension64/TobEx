//TobExEE
#ifndef UITEXT_H
#define UITEXT_H

#include "uicore.h"

typedef IECPtrList CTextAreaEntryList;

#define CUITEXTAREA_USERARG_NONE	0

struct TextAreaEntry { //Size 20h
	IECString m_sLeft; //0h
	IECString m_sRight; //4h
	POSITION m_posBoss; //8h, pos containing first TextAreaEntry
	int m_nUserArg; //ch, passed to CTextArea::UserProc()
	ABGR m_rgbLeft; //10h
	ABGR m_rgbRight; //14h
	int m_nRows; //18h, only for first TextAreaEntry
	short m_wIndent; //1ch, in pixels
	short m_wRowIdx; //1eh
};

class CUITextArea : public CUIControl { //Size F0h
public:
	virtual ~CUITextArea(); //v0
	void Deconstruct() {} //dummy

	virtual void SetEnabled(bool b); //v8
	virtual void OnLoseFocus(); //v10
	virtual void OnLMouseDrag(CPoint pt); //v18
	virtual BOOL OnLMouseBtDn(CPoint pt); //v1c
	virtual void OnLMouseBtUp(CPoint pt); //v20
	virtual void ShowTooltip(bool b); //v30
	virtual void SetRedraw(); //v54
	virtual BOOL Redraw(BOOL bForceRedraw); //v58
	virtual BOOL NeedsRedraw(); //v64

	virtual void HighlightText(POSITION pos); //v6c
	virtual void UnhighlightText(); //v70
	virtual void OnLClicked(CPoint pt); //v74, calls UserProc()
	virtual void UserProc(int nArg); //v78, nArg = TextAreaEntry.nUserArg, e.g. selecting custom script

	CTextAreaEntryList* m_plStrings; //54h
	POSITION m_posCurrString; //58h
	short m_wCurrString; //5ch, to set the scroll bar position
	short u5e;
	short u60;
	char p62[2];
	CVidFont m_fntLeft; //64h
	CVidFont m_fntRight; //88h
	short m_wFontHeight; //ach
	short uae;
	char ub0;
	char m_nNewRows; //b1h
	char ub2;
	char ub3;
	short m_wRowsMax; //b4h (0xB15016)
	short m_wRowsPerPage; //b6h
	short m_wNumStrings; //b8h
	char pba[2];
	int m_nScrollBarId; //bch
	ABGR m_rgbLeft; //c0h, col2
	ABGR m_rgbColor3; //c4h, col3
	ABGR m_rgbRight; //c8h, col1
	ABGR m_rgbSelected; //cch
	POSITION m_posSelected; //d0h
	ABGR m_rgbStoredRight; //d4h, stores old color of selected text
	ABGR m_rgbStoredLeft; //d8h, stores old color of selected text
	bool m_bSingleColorLeft; //dch
	bool m_bSingleColorRight; //ddh
	char pde[2];
	IECString m_sDivider; //e0h, "- "
	short ue4;
	bool m_bMultiline; //e6h
	bool m_bConstructed; //e7h
	char ue8;
	char pe9[3];
	int uec;
};

class CUITextField : public CUIControl { //Size 39Ch
public:
	virtual ~CUITextField(); //v0
	void Deconstruct() {} //dummy

	virtual void SetEnabled(bool b); //v8
	virtual void OnLoseFocus(); //v10
	virtual void OnGetFocus(); //v14
	virtual void OnLMouseDrag(CPoint pt); //v18
	virtual BOOL OnLMouseBtDn(CPoint pt); //v1c
	virtual void OnLMouseBtUp(CPoint pt); //v20
	virtual BOOL OnRMouseBtDn(CPoint pt); //v28
	virtual void OnKeyPress(short wChar); //v38
	virtual void ShowTooltip(bool b); //v30
	virtual void SetRedraw(); //v54
	virtual BOOL Redraw(BOOL bForceRedraw); //v58
	virtual BOOL NeedsRedraw(); //v64

	void SetTextColors(ABGR colText, ABGR colGreyed); //v6c
	void Execute(IECString& s); //v70
	IECString GetText(); //v74
	void SetText(IECString& s); //v78
	void UpdateDisplayArea(); //v7c

	CVidMosaic u54;
	CVidMosaic u104;
	CVidMosaic u1b4;
	CVidCell m_vidCursor; //264h
	CPoint m_ptPos; //328h, from controlInfo (32h, 34h)
	CPoint m_pt; //330h
	CVidFont m_fnt; //338h
	short u35c; //from controlInfo 66h
	short u35e; //from controlInfo 68h
	short u360;
	char p362[2];
	int u364;
	IECString m_sText; //368h, from controlInfo 44h (null-terminated string, size 32?)
	IECString m_sTemp; //36ch, used during SetText()
	int m_nCaretPosition; //370h
	int m_wCurrScrollValue; //374h
	int u378;
	char u37c;
	char u37d;
	short m_wRows; //37eh
	short m_wMaxScrollValue; //380h
	char p382[2];
	ABGR m_rgbText; //384h
	ABGR m_rgbGreyed; //388h
	int u38c;
	char u390;
	char p391[3];
	int m_nHighlightLeftIndex; //394h
	int m_nHighlightRightIndex; //398h
	//for derived structures - int m_nScrollBarId; ///39ch, from controlInfo 36h
	//char u3a0;
	//char u3a1;
	//char u3a2;
	//char u3a3;
};

class CUITextBar : public CUIControl { //size 3ACh
//Similar to CUITextField except it only supports a single row
public:
	//AAAF80
	virtual ~CUITextBar(); //v0
	void Deconstruct() {} //dummy

	virtual void SetEnabled(bool b); //v8
	virtual void OnLoseFocus(); //v10
	virtual void OnGetFocus(); //v14
	virtual BOOL OnLMouseBtDn(CPoint pt); //v1c
	virtual BOOL OnRMouseBtDn(CPoint pt); //v28
	virtual void OnKeyPress(short wChar); //v38
	virtual void SetRedraw(); //v54
	virtual BOOL Redraw(BOOL bForceRedraw); //v58
	virtual BOOL NeedsRedraw(); //v64

	void Execute(IECString& s); //v6c
	IECString GetText(); //v70
	void SetText(IECString& s); //v74

	CVidMosaic u54;
	CVidMosaic u104;
	CVidMosaic u1b4;
	CVidCell m_vidCursor; //264h
	CPoint m_ptPos; //328h, from controlInfo (32h, 34h)
	CPoint m_pt; //330h, from controlInfo (36h, 38h)
	CVidFont m_fnt; //338h
	short m_wMaxInputLength; //35ch, from controlInfo 64h
	short m_wTextCase; //35eh, from controlInfo 66h
	short m_wTextMode; //360h, 2 = ignore space and letters
	short m_wTextLength; //362h
	int u364;
	IECString m_sText; //368h, from controlInfo 44h (initial text)
	IECString m_sTextPrevious; //36ch, for when user cancels
	short m_wCaretPosition; //370h
	char p372[2];
	int m_nScrollPosition; //374h, first index when text scrolled right
	char m_nBufferIdx; //378h
	char m_nBuffers; //379h
	char p37a[2];
	IECString m_sBuffers[10]; //37ch
	int u3a4;
	char u3a8;
	char p3a9[3];
};

#endif //UITEXT_H