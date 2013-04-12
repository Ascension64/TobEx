#include "uiscroll.h"

#include "stdafx.h"

DefineLibNoRetFunc(CUIScrollBar&, CUIScrollBar, CUIScrollBar, (CPanel& panel, ChuFileControlInfoBase& controlInfo), Construct, Construct2, (panel, controlInfo), 0x5A1940);
DefineLibNoRetFunc(void, CUIScrollBar, ~CUIScrollBar, (), Deconstruct, Deconstruct, (), 0x5A1F51);
DefineLibMemberFunc(void, CUIScrollBar, UpdateKnobPosition, (short wValueCurrent, short wValues, short wRows), UpdateKnobPosition, UpdateKnobPosition, (wValueCurrent, wValues, wRows), 0x5A202F);
DefineLibMemberFunc(void, CUIScrollBar, OnLoseFocus, (), OnLoseFocus, OnLoseFocus, (), 0x5A2476);
DefineLibMemberFunc(void, CUIScrollBar, OnLMouseDrag, (CPoint pt), OnLMouseDrag, OnLMouseDrag, (pt), 0x5A2481);
DefineLibMemberFunc(BOOL, CUIScrollBar, OnLMouseBtDn, (CPoint pt), OnLMouseBtDn, OnLMouseBtDn, (pt), 0x5A21D8);
DefineLibMemberFunc(void, CUIScrollBar, OnLMouseBtUp, (CPoint pt), OnLMouseBtUp, OnLMouseBtUp, (pt), 0x5A2372);
DefineLibMemberFunc(BOOL, CUIScrollBar, OnLMouseDblClk, (CPoint pt), OnLMouseDblClk, OnLMouseDblClk, (pt), 0x5A2691);
DefineLibMemberFunc(void, CUIScrollBar, ShowTooltip, (bool b), ShowTooltip, ShowTooltip, (b), 0x5A33E9);
DefineLibMemberFunc(void, CUIScrollBar, SetRedraw, (), SetRedraw, SetRedraw, (), 0x5A2111);
DefineLibMemberFunc(BOOL, CUIScrollBar, Redraw, (BOOL bForceRedraw), Redraw, Redraw, (bForceRedraw), 0x5A2893);
DefineLibMemberFunc(BOOL, CUIScrollBar, NeedsRedraw, (), NeedsRedraw, NeedsRedraw, (), 0x5A2829);
DefineLibMemberFunc(void, CUIScrollBar, OnLClicked, (CPoint pt), OnLClicked, OnLClicked, (pt), 0x5A2622);
DefineLibMemberFunc(void, CUIScrollBar, OnMouseDragKnob, (), OnMouseDragKnob, OnMouseDragKnob, (), 0x5A2771);
DefineLibMemberFunc(void, CUIScrollBar, OnLMouseBtnDnArrowUp, (), OnLMouseBtnDnArrowUp, OnLMouseBtnDnArrowUp, (), 0x5A2717);
DefineLibMemberFunc(void, CUIScrollBar, OnLMouseBtnDnArrowDn, (), OnLMouseBtnDnArrowDn, OnLMouseBtnDnArrowDn, (), 0x5A2744);
DefineLibMemberFunc(void, CUIScrollBar, OnLMouseBtnUpArrow, (char b), OnLMouseBtnUpArrow, OnLMouseBtnUpArrow, (b), 0x5A27B4);
DefineLibMemberFunc(void, CUIScrollBar, OnLClickedAboveKnob, (short interval), OnLClickedAboveKnob, OnLClickedAboveKnob, (interval), 0x5A26B1);
DefineLibMemberFunc(void, CUIScrollBar, OnLClickedBelowKnob, (short interval), OnLClickedBelowKnob, OnLClickedBelowKnob, (interval), 0x5A26E4);
