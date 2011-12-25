#ifndef UISCROLL_H
#define UISCROLL_H

#include "uibutton.h"
#include "uicore.h"

class CUIScrollBar;

class CUIScrollBarButton : public CUIButton { //Size 658h
//Constructor: 0x5A37D4
public:
	//AAB220
	virtual ~CUIScrollBarButton();

	CUIScrollBar* pScrollBar; //650h
	BYTE u654;
	BYTE u655; //pad
	WORD u656;
};

class CUIScrollBar : public CUIControl { //Size 13Eh
public:
	CUIScrollBar(CPanel&, ChuFileControlInfoBase&); //5A1940
	CUIScrollBar& Construct(CPanel&, ChuFileControlInfoBase&) { return *this; } //dummy

	void UpdateKnobPosition(WORD, WORD, DWORD);

	//AAB1A8
	virtual ~CUIScrollBar(); //v0
	void Deconstruct() {} //dummy

	virtual void OnLoseFocus(void); //vc
	virtual void OnLMouseDrag(POINT); //v14
	virtual BOOL OnLMouseBtDn(POINT); //v18
	virtual void OnLMouseBtUp(POINT); //v1c
	virtual BOOL OnLMouseDblClk(POINT); //v20
	virtual void UpdateToolTip(bool); //v30
	virtual void SetRedraw(void); //v48
	virtual BOOL Redraw(BOOL); //v4c
	virtual BOOL NeedsRedraw(void); //v58

	virtual void OnLClicked(POINT); //v5c
	virtual void OnMouseDragKnob(void); //v60
	virtual void OnLMouseBtnDnArrowUp(void); //v64
	virtual void OnLMouseBtnDnArrowDn(void); //v68
	virtual void OnLMouseBtnUpArrow(BYTE); //v6c
	virtual void OnLClickedAboveKnob(DWORD); //v70
	virtual void OnLClickedBelowKnob(DWORD); //v74

	//members
	WORD wRedrawAmount; //4ah;
	DWORD nTextAreaID; //4ch
	CVidCell vc; //50h
	WORD wAnimSequence; //126h
	WORD wAnimFrameTrack; //128h
	WORD wAnimFrameKnob; //12ah
	CUIScrollBarButton* pBtUp; //12ch
	CUIScrollBarButton* pBtDn; //130h
	WORD wTrackHeight; //134h, control height - largest btn frame height (up) - largest btn frame height (down)
	WORD wKnobPosMax; //136h, wTrackHeight - slider knob frame height
	WORD wKnobPosCurrent; //138h
	bool bKnobLock; //13ah, 1: grabbed by mouse
	BYTE u13b; //pad
	WORD wKnobHeightClicked; //13ch, y offset of where you clicked the knob last
};

extern CUIScrollBar& (CUIScrollBar::*CUIScrollBar_Construct_2CPanel_ChuFileControlInfoBase)(CPanel&, ChuFileControlInfoBase&);
extern void (CUIScrollBar::*CUIScrollBar_Deconstruct)();
extern void (CUIScrollBar::*CUIScrollBar_UpdateKnobPosition)(WORD, WORD, DWORD);
extern void (CUIScrollBar::*CUIScrollBar_OnLoseFocus)(void);
extern void (CUIScrollBar::*CUIScrollBar_OnLMouseDrag)(POINT);
extern BOOL (CUIScrollBar::*CUIScrollBar_OnLMouseBtDn)(POINT);
extern void (CUIScrollBar::*CUIScrollBar_OnLMouseBtUp)(POINT);
extern BOOL (CUIScrollBar::*CUIScrollBar_OnLMouseDblClk)(POINT);
extern void (CUIScrollBar::*CUIScrollBar_UpdateToolTip)(bool);
extern void (CUIScrollBar::*CUIScrollBar_SetRedraw)(void);
extern BOOL (CUIScrollBar::*CUIScrollBar_Redraw)(BOOL);
extern BOOL (CUIScrollBar::*CUIScrollBar_NeedsRedraw)(void);
extern void (CUIScrollBar::*CUIScrollBar_OnLClicked)(POINT);
extern void (CUIScrollBar::*CUIScrollBar_OnMouseDragKnob)(void);
extern void (CUIScrollBar::*CUIScrollBar_OnLMouseBtnDnArrowUp)(void);
extern void (CUIScrollBar::*CUIScrollBar_OnLMouseBtnDnArrowDn)(void);
extern void (CUIScrollBar::*CUIScrollBar_OnLMouseBtnUpArrow)(BYTE);
extern void (CUIScrollBar::*CUIScrollBar_OnLClickedAboveKnob)(DWORD);
extern void (CUIScrollBar::*CUIScrollBar_OnLClickedBelowKnob)(DWORD);

#endif //UISCROLL_H