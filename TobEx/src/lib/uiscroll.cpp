#include "uiscroll.h"

CUIScrollBar& (CUIScrollBar::*CUIScrollBar_Construct_2CPanel_ChuFileControlInfoBase)(CPanel&, ChuFileControlInfoBase&) =
	SetFP(static_cast<CUIScrollBar& (CUIScrollBar::*)(CPanel&, ChuFileControlInfoBase&)>
																		(&CUIScrollBar::Construct),				0x5A1940);
void (CUIScrollBar::*CUIScrollBar_Deconstruct)() =
	SetFP(static_cast<void (CUIScrollBar::*)()>							(&CUIScrollBar::Deconstruct),			0x5A1F51);
void (CUIScrollBar::*CUIScrollBar_UpdateKnobPosition)(short, short, short) =
	SetFP(static_cast<void (CUIScrollBar::*)(short, short, short)>		(&CUIScrollBar::UpdateKnobPosition),	0x5A202F);
void (CUIScrollBar::*CUIScrollBar_OnLoseFocus)() =
	SetFP(static_cast<void (CUIScrollBar::*)()>							(&CUIScrollBar::OnLoseFocus),			0x5A2476);
void (CUIScrollBar::*CUIScrollBar_OnLMouseDrag)(POINT) =
	SetFP(static_cast<void (CUIScrollBar::*)(POINT)>					(&CUIScrollBar::OnLMouseDrag),			0x5A2481);
BOOL (CUIScrollBar::*CUIScrollBar_OnLMouseBtDn)(POINT) =
	SetFP(static_cast<BOOL (CUIScrollBar::*)(POINT)>					(&CUIScrollBar::OnLMouseBtDn),			0x5A21D8);
void (CUIScrollBar::*CUIScrollBar_OnLMouseBtUp)(POINT) =
	SetFP(static_cast<void (CUIScrollBar::*)(POINT)>					(&CUIScrollBar::OnLMouseBtUp),			0x5A2372);
BOOL (CUIScrollBar::*CUIScrollBar_OnLMouseDblClk)(POINT) =
	SetFP(static_cast<BOOL (CUIScrollBar::*)(POINT)>					(&CUIScrollBar::OnLMouseDblClk),		0x5A2691);
void (CUIScrollBar::*CUIScrollBar_ShowTooltip)(bool) =
	SetFP(static_cast<void (CUIScrollBar::*)(bool)>						(&CUIScrollBar::ShowTooltip),			0x5A33E9);
void (CUIScrollBar::*CUIScrollBar_SetRedraw)() =
	SetFP(static_cast<void (CUIScrollBar::*)()>							(&CUIScrollBar::SetRedraw),				0x5A2111);
BOOL (CUIScrollBar::*CUIScrollBar_Redraw)(BOOL) =
	SetFP(static_cast<BOOL (CUIScrollBar::*)(BOOL)>						(&CUIScrollBar::Redraw),				0x5A2893);
BOOL (CUIScrollBar::*CUIScrollBar_NeedsRedraw)() =
	SetFP(static_cast<BOOL (CUIScrollBar::*)()>							(&CUIScrollBar::NeedsRedraw),			0x5A2829);
void (CUIScrollBar::*CUIScrollBar_OnLClicked)(POINT) =
	SetFP(static_cast<void (CUIScrollBar::*)(POINT)>					(&CUIScrollBar::OnLClicked),			0x5A2622);
void (CUIScrollBar::*CUIScrollBar_OnMouseDragKnob)() =
	SetFP(static_cast<void (CUIScrollBar::*)()>							(&CUIScrollBar::OnMouseDragKnob),		0x5A2771);
void (CUIScrollBar::*CUIScrollBar_OnLMouseBtnDnArrowUp)() =
	SetFP(static_cast<void (CUIScrollBar::*)()>							(&CUIScrollBar::OnLMouseBtnDnArrowUp),	0x5A2717);
void (CUIScrollBar::*CUIScrollBar_OnLMouseBtnDnArrowDn)() =
	SetFP(static_cast<void (CUIScrollBar::*)()>							(&CUIScrollBar::OnLMouseBtnDnArrowDn),	0x5A2744);
void (CUIScrollBar::*CUIScrollBar_OnLMouseBtnUpArrow)(char) =
	SetFP(static_cast<void (CUIScrollBar::*)(char)>						(&CUIScrollBar::OnLMouseBtnUpArrow),	0x5A27B4);
void (CUIScrollBar::*CUIScrollBar_OnLClickedAboveKnob)(short) =
	SetFP(static_cast<void (CUIScrollBar::*)(short)>					(&CUIScrollBar::OnLClickedAboveKnob),	0x5A26B1);
void (CUIScrollBar::*CUIScrollBar_OnLClickedBelowKnob)(short) =
	SetFP(static_cast<void (CUIScrollBar::*)(short)>					(&CUIScrollBar::OnLClickedBelowKnob),	0x5A26E4);

CUIScrollBar::CUIScrollBar(CPanel& panel, ChuFileControlInfoBase& controlInfo)
																{ (this->*CUIScrollBar_Construct_2CPanel_ChuFileControlInfoBase)(panel, controlInfo); }
CUIScrollBar::~CUIScrollBar()									{ (this->*CUIScrollBar_Deconstruct)(); }
void CUIScrollBar::UpdateKnobPosition(short wValueCurrent, short wValues, short wRows)
																{ return (this->*CUIScrollBar_UpdateKnobPosition)(wValueCurrent, wValues, wRows); }
void CUIScrollBar::OnLoseFocus()								{ return (this->*CUIScrollBar_OnLoseFocus)(); }
void CUIScrollBar::OnLMouseDrag(POINT pt)						{ return (this->*CUIScrollBar_OnLMouseDrag)(pt); }
BOOL CUIScrollBar::OnLMouseBtDn(POINT pt)						{ return (this->*CUIScrollBar_OnLMouseBtDn)(pt); }
void CUIScrollBar::OnLMouseBtUp(POINT pt)						{ return (this->*CUIScrollBar_OnLMouseBtUp)(pt); }
BOOL CUIScrollBar::OnLMouseDblClk(POINT pt)						{ return (this->*CUIScrollBar_OnLMouseDblClk)(pt); }
void CUIScrollBar::ShowTooltip(bool b)							{ return (this->*CUIScrollBar_ShowTooltip)(b); }
void CUIScrollBar::SetRedraw()									{ return (this->*CUIScrollBar_SetRedraw)(); }
BOOL CUIScrollBar::Redraw(BOOL bForceRedraw)					{ return (this->*CUIScrollBar_Redraw)(bForceRedraw); }
BOOL CUIScrollBar::NeedsRedraw()								{ return (this->*CUIScrollBar_NeedsRedraw)(); }
void CUIScrollBar::OnLClicked(POINT pt)							{ return (this->*CUIScrollBar_OnLClicked)(pt); }
void CUIScrollBar::OnMouseDragKnob()							{ return (this->*CUIScrollBar_OnMouseDragKnob)(); }
void CUIScrollBar::OnLMouseBtnDnArrowUp()						{ return (this->*CUIScrollBar_OnLMouseBtnDnArrowUp)(); }
void CUIScrollBar::OnLMouseBtnDnArrowDn()						{ return (this->*CUIScrollBar_OnLMouseBtnDnArrowDn)(); }
void CUIScrollBar::OnLMouseBtnUpArrow(char b)					{ return (this->*CUIScrollBar_OnLMouseBtnUpArrow)(b); }
void CUIScrollBar::OnLClickedAboveKnob(short interval)			{ return (this->*CUIScrollBar_OnLClickedAboveKnob)(interval); }
void CUIScrollBar::OnLClickedBelowKnob(short interval)			{ return (this->*CUIScrollBar_OnLClickedBelowKnob)(interval); }