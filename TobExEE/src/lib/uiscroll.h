//TobExEE
#ifndef UISCROLL_H
#define UISCROLL_H

#include "uibutton.h"
#include "uicore.h"

class CUIScrollBar;

class CUIScrollBarButton : public CUIButton { //Size 17Ch
public:
	virtual ~CUIScrollBarButton();

	CUIScrollBar* m_pScrollBar; //174h
	char u178;
	char p179;
	short u17a;
};

class CUIScrollBar : public CUIControl { //Size 158h
public:
	virtual ~CUIScrollBar(); //v0
	void Deconstruct() {} //dummy

	virtual void OnLoseFocus(); //v10
	virtual void OnLMouseDrag(CPoint pt); //v18
	virtual BOOL OnLMouseBtDn(CPoint pt); //v1c
	virtual void OnLMouseBtUp(CPoint pt); //v20
	virtual BOOL OnLMouseDblClk(CPoint pt); //v24
	virtual void ShowTooltip(bool b); //v30
	virtual void SetRedraw(); //v54
	virtual BOOL Redraw(BOOL bForceRedraw); //v58
	virtual BOOL NeedsRedraw(); //v64

	virtual void OnLClicked(CPoint pt); //v6c
	virtual void OnMouseDragKnob(); //v70
	virtual void OnLMouseBtnDnArrowUp(); //v74
	virtual void OnLMouseBtnDnArrowDn(); //v78
	virtual void OnLMouseBtnUpArrow(char b); //v7c
	virtual void OnLClickedAboveKnob(short interval); //v80
	virtual void OnLClickedBelowKnob(short interval); //v84

	short m_wRedrawAmount; //54h;
	char p56[2];
	int m_nTextAreaID; //58h
	CVidCell m_vid; //5ch
	short m_wAnimSequence; //120h
	short m_wAnimFrameTrack; //122h
	short m_wAnimFrameKnob; //124h
	char p126[2];
	CUIScrollBarButton* m_pBtUp; //128h
	CUIScrollBarButton* m_pBtDn; //12ch
	short m_wTrackHeight; //130h, control height - largest btn frame height (up) - largest btn frame height (down)
	short m_wKnobPosMax; //132h, wTrackHeight - slider knob frame height
	short m_wKnobPosCurrent; //134h
	bool m_bKnobLock; //136h, 1: grabbed by mouse
	char p137;
	short m_wKnobHeightClicked; //138h, y offset of where you clicked the knob last
	char u13a;
	char p13b;
	RECT u13c;
	int u14c;
	int u150;
	int u154;
};

#endif //UISCROLL_H