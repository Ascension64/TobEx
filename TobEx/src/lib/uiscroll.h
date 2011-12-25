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
	char u654;
	char u655; //pad
	short u656;
};

class CUIScrollBar : public CUIControl { //Size 13Eh
public:
	CUIScrollBar(CPanel& panel, ChuFileControlInfoBase& controlInfo); //5A1940
	CUIScrollBar& Construct(CPanel&, ChuFileControlInfoBase&) { return *this; } //dummy

	void UpdateKnobPosition(short wValueCurrent, short wValues, short wRows);

	//AAB1A8
	virtual ~CUIScrollBar(); //v0
	void Deconstruct() {} //dummy

	virtual void OnLoseFocus(); //vc
	virtual void OnLMouseDrag(POINT pt); //v14
	virtual BOOL OnLMouseBtDn(POINT pt); //v18
	virtual void OnLMouseBtUp(POINT pt); //v1c
	virtual BOOL OnLMouseDblClk(POINT pt); //v20
	virtual void ShowTooltip(bool b); //v30
	virtual void SetRedraw(); //v48
	virtual BOOL Redraw(BOOL bForceRedraw); //v4c
	virtual BOOL NeedsRedraw(); //v58

	virtual void OnLClicked(POINT pt); //v5c
	virtual void OnMouseDragKnob(); //v60
	virtual void OnLMouseBtnDnArrowUp(); //v64
	virtual void OnLMouseBtnDnArrowDn(); //v68
	virtual void OnLMouseBtnUpArrow(char b); //v6c
	virtual void OnLClickedAboveKnob(short interval); //v70
	virtual void OnLClickedBelowKnob(short interval); //v74

	short wRedrawAmount; //4ah;
	int nTextAreaID; //4ch
	CVidCell vc; //50h
	short wAnimSequence; //126h
	short wAnimFrameTrack; //128h
	short wAnimFrameKnob; //12ah
	CUIScrollBarButton* pBtUp; //12ch
	CUIScrollBarButton* pBtDn; //130h
	short wTrackHeight; //134h, control height - largest btn frame height (up) - largest btn frame height (down)
	short wKnobPosMax; //136h, wTrackHeight - slider knob frame height
	short wKnobPosCurrent; //138h
	bool bKnobLock; //13ah, 1: grabbed by mouse
	char u13b; //pad
	short wKnobHeightClicked; //13ch, y offset of where you clicked the knob last
};

extern CUIScrollBar& (CUIScrollBar::*CUIScrollBar_Construct_2CPanel_ChuFileControlInfoBase)(CPanel&, ChuFileControlInfoBase&);
extern void (CUIScrollBar::*CUIScrollBar_Deconstruct)();
extern void (CUIScrollBar::*CUIScrollBar_UpdateKnobPosition)(short, short, short);
extern void (CUIScrollBar::*CUIScrollBar_OnLoseFocus)();
extern void (CUIScrollBar::*CUIScrollBar_OnLMouseDrag)(POINT);
extern BOOL (CUIScrollBar::*CUIScrollBar_OnLMouseBtDn)(POINT);
extern void (CUIScrollBar::*CUIScrollBar_OnLMouseBtUp)(POINT);
extern BOOL (CUIScrollBar::*CUIScrollBar_OnLMouseDblClk)(POINT);
extern void (CUIScrollBar::*CUIScrollBar_ShowTooltip)(bool);
extern void (CUIScrollBar::*CUIScrollBar_SetRedraw)();
extern BOOL (CUIScrollBar::*CUIScrollBar_Redraw)(BOOL);
extern BOOL (CUIScrollBar::*CUIScrollBar_NeedsRedraw)();
extern void (CUIScrollBar::*CUIScrollBar_OnLClicked)(POINT);
extern void (CUIScrollBar::*CUIScrollBar_OnMouseDragKnob)();
extern void (CUIScrollBar::*CUIScrollBar_OnLMouseBtnDnArrowUp)();
extern void (CUIScrollBar::*CUIScrollBar_OnLMouseBtnDnArrowDn)();
extern void (CUIScrollBar::*CUIScrollBar_OnLMouseBtnUpArrow)(char);
extern void (CUIScrollBar::*CUIScrollBar_OnLClickedAboveKnob)(short);
extern void (CUIScrollBar::*CUIScrollBar_OnLClickedBelowKnob)(short);

#endif //UISCROLL_H