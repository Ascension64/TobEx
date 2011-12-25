#include "uiscroll.h"

CUIScrollBar& (CUIScrollBar::*CUIScrollBar_Construct_2CPanel_ChuFileControlInfoBase)(CPanel&, ChuFileControlInfoBase&) =
	SetFP(static_cast<CUIScrollBar& (CUIScrollBar::*)(CPanel&, ChuFileControlInfoBase&)>
																		(&CUIScrollBar::Construct),				0x5A1940);
void (CUIScrollBar::*CUIScrollBar_Deconstruct)() =
	SetFP(static_cast<void (CUIScrollBar::*)()>							(&CUIScrollBar::Deconstruct),			0x5A1F51);
void (CUIScrollBar::*CUIScrollBar_UpdateKnobPosition)(WORD, WORD, DWORD) =
	SetFP(static_cast<void (CUIScrollBar::*)(WORD, WORD, DWORD)>		(&CUIScrollBar::UpdateKnobPosition),	0x5A202F);
void (CUIScrollBar::*CUIScrollBar_OnLoseFocus)(void) =
	SetFP(static_cast<void (CUIScrollBar::*)(void)>						(&CUIScrollBar::OnLoseFocus),			0x5A2476);
void (CUIScrollBar::*CUIScrollBar_OnLMouseDrag)(POINT) =
	SetFP(static_cast<void (CUIScrollBar::*)(POINT)>					(&CUIScrollBar::OnLMouseDrag),			0x5A2481);
BOOL (CUIScrollBar::*CUIScrollBar_OnLMouseBtDn)(POINT) =
	SetFP(static_cast<BOOL (CUIScrollBar::*)(POINT)>					(&CUIScrollBar::OnLMouseBtDn),			0x5A21D8);
void (CUIScrollBar::*CUIScrollBar_OnLMouseBtUp)(POINT) =
	SetFP(static_cast<void (CUIScrollBar::*)(POINT)>					(&CUIScrollBar::OnLMouseBtUp),			0x5A2372);
BOOL (CUIScrollBar::*CUIScrollBar_OnLMouseDblClk)(POINT) =
	SetFP(static_cast<BOOL (CUIScrollBar::*)(POINT)>					(&CUIScrollBar::OnLMouseDblClk),		0x5A2691);
void (CUIScrollBar::*CUIScrollBar_UpdateToolTip)(bool) =
	SetFP(static_cast<void (CUIScrollBar::*)(bool)>						(&CUIScrollBar::UpdateToolTip),			0x5A33E9);
void (CUIScrollBar::*CUIScrollBar_SetRedraw)(void) =
	SetFP(static_cast<void (CUIScrollBar::*)(void)>						(&CUIScrollBar::SetRedraw),				0x5A2111);
BOOL (CUIScrollBar::*CUIScrollBar_Redraw)(BOOL) =
	SetFP(static_cast<BOOL (CUIScrollBar::*)(BOOL)>						(&CUIScrollBar::Redraw),				0x5A2893);
BOOL (CUIScrollBar::*CUIScrollBar_NeedsRedraw)(void) =
	SetFP(static_cast<BOOL (CUIScrollBar::*)(void)>						(&CUIScrollBar::NeedsRedraw),			0x5A2829);
void (CUIScrollBar::*CUIScrollBar_OnLClicked)(POINT) =
	SetFP(static_cast<void (CUIScrollBar::*)(POINT)>					(&CUIScrollBar::OnLClicked),			0x5A2622);
void (CUIScrollBar::*CUIScrollBar_OnMouseDragKnob)(void) =
	SetFP(static_cast<void (CUIScrollBar::*)(void)>						(&CUIScrollBar::OnMouseDragKnob),		0x5A2771);
void (CUIScrollBar::*CUIScrollBar_OnLMouseBtnDnArrowUp)(void) =
	SetFP(static_cast<void (CUIScrollBar::*)(void)>						(&CUIScrollBar::OnLMouseBtnDnArrowUp),	0x5A2717);
void (CUIScrollBar::*CUIScrollBar_OnLMouseBtnDnArrowDn)(void) =
	SetFP(static_cast<void (CUIScrollBar::*)(void)>						(&CUIScrollBar::OnLMouseBtnDnArrowDn),	0x5A2744);
void (CUIScrollBar::*CUIScrollBar_OnLMouseBtnUpArrow)(BYTE) =
	SetFP(static_cast<void (CUIScrollBar::*)(BYTE)>						(&CUIScrollBar::OnLMouseBtnUpArrow),	0x5A27B4);
void (CUIScrollBar::*CUIScrollBar_OnLClickedAboveKnob)(DWORD) =
	SetFP(static_cast<void (CUIScrollBar::*)(DWORD)>					(&CUIScrollBar::OnLClickedAboveKnob),	0x5A26B1);
void (CUIScrollBar::*CUIScrollBar_OnLClickedBelowKnob)(DWORD) =
	SetFP(static_cast<void (CUIScrollBar::*)(DWORD)>					(&CUIScrollBar::OnLClickedBelowKnob),	0x5A26E4);

CUIScrollBar::CUIScrollBar(CPanel& panel, ChuFileControlInfoBase& controlInfo)
																{ (this->*CUIScrollBar_Construct_2CPanel_ChuFileControlInfoBase)(panel, controlInfo); }
CUIScrollBar::~CUIScrollBar()									{ (this->*CUIScrollBar_Deconstruct)(); }
void CUIScrollBar::UpdateKnobPosition(WORD wValueCurrent, WORD wValues, DWORD nRows)
																{ return (this->*CUIScrollBar_UpdateKnobPosition)(wValueCurrent, wValues, nRows); }
void CUIScrollBar::OnLoseFocus(void)							{ return (this->*CUIScrollBar_OnLoseFocus)(); }
void CUIScrollBar::OnLMouseDrag(POINT pt)						{ return (this->*CUIScrollBar_OnLMouseDrag)(pt); }
BOOL CUIScrollBar::OnLMouseBtDn(POINT pt)						{ return (this->*CUIScrollBar_OnLMouseBtDn)(pt); }
void CUIScrollBar::OnLMouseBtUp(POINT pt)						{ return (this->*CUIScrollBar_OnLMouseBtUp)(pt); }
BOOL CUIScrollBar::OnLMouseDblClk(POINT pt)						{ return (this->*CUIScrollBar_OnLMouseDblClk)(pt); }
void CUIScrollBar::UpdateToolTip(bool b)						{ return (this->*CUIScrollBar_UpdateToolTip)(b); }
void CUIScrollBar::SetRedraw(void)								{ return (this->*CUIScrollBar_SetRedraw)(); }
BOOL CUIScrollBar::Redraw(BOOL bForceRedraw)					{ return (this->*CUIScrollBar_Redraw)(bForceRedraw); }
BOOL CUIScrollBar::NeedsRedraw(void)							{ return (this->*CUIScrollBar_NeedsRedraw)(); }
void CUIScrollBar::OnLClicked(POINT pt)							{ return (this->*CUIScrollBar_OnLClicked)(pt); }
void CUIScrollBar::OnMouseDragKnob(void)						{ return (this->*CUIScrollBar_OnMouseDragKnob)(); }
void CUIScrollBar::OnLMouseBtnDnArrowUp(void)					{ return (this->*CUIScrollBar_OnLMouseBtnDnArrowUp)(); }
void CUIScrollBar::OnLMouseBtnDnArrowDn(void)					{ return (this->*CUIScrollBar_OnLMouseBtnDnArrowDn)(); }
void CUIScrollBar::OnLMouseBtnUpArrow(BYTE b)					{ return (this->*CUIScrollBar_OnLMouseBtnUpArrow)(b); }
void CUIScrollBar::OnLClickedAboveKnob(DWORD interval)			{ return (this->*CUIScrollBar_OnLClickedAboveKnob)(interval); }
void CUIScrollBar::OnLClickedBelowKnob(DWORD interval)			{ return (this->*CUIScrollBar_OnLClickedBelowKnob)(interval); }