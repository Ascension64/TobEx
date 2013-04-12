#include "uicore.h"

#include "stdafx.h"

//CManager
DefineLibMemberFunc(CPanel&, CManager, GetPanel, (int index), GetPanel, GetPanel, (index), 0x585480);

//CPanel
DefineLibMemberFunc(CUIControl&, CPanel, GetUIControl, (int index), GetUIControl, GetUIControl, (index), 0x5831CE);
DefineLibMemberFunc(void, CPanel, Redraw, (RECT* pr), Redraw, Redraw, (pr), 0x5848C7);

//CUIControl
CUIControl::CUIControl() { SetVT(this, 0xAAAD54); }
DefineLibNoRetFunc(CUIControl&, CUIControl, CUIControl, (
	CPanel& panel,
	ChuFileControlInfoBase& controlInfo,
	BOOL b
	), Construct, Construct3, (panel, controlInfo, b), 0x582650);
DefineLibNoRetFunc(void, CUIControl, ~CUIControl, (), Deconstruct, Deconstruct, (), 0x586530);
DefineLibMemberFunc(void, CUIControl, SetEnabled, (bool b), SetEnabled, SetEnabled, (b), 0x586380);
DefineLibMemberFunc(BOOL, CUIControl, OnMouseHover, (CPoint& pt), OnMouseHover, OnMouseHover, (pt), 0x5863A0);
DefineLibMemberFunc(void, CUIControl, OnLoseFocus, (), OnLoseFocus, OnLoseFocus, (), 0x5863C0);
DefineLibMemberFunc(void, CUIControl, OnGetFocus, (), OnGetFocus, OnGetFocus, (), 0x5863D0);
DefineLibMemberFunc(void, CUIControl, OnLMouseDrag, (CPoint pt), OnLMouseDrag, OnLMouseDrag, (pt), 0x5863E0);
DefineLibMemberFunc(BOOL, CUIControl, OnLMouseBtDn, (CPoint pt), OnLMouseBtDn, OnLMouseBtDn, (pt), 0x5863F0);
DefineLibMemberFunc(void, CUIControl, OnLMouseBtUp, (CPoint pt), OnLMouseBtUp, OnLMouseBtUp, (pt), 0x586400);
DefineLibMemberFunc(BOOL, CUIControl, OnLMouseDblClk, (CPoint pt), OnLMouseDblClk, OnLMouseDblClk, (pt), 0x586410);
DefineLibMemberFunc(BOOL, CUIControl, OnRMouseBtDn, (CPoint pt), OnRMouseBtDn, OnRMouseBtDn, (pt), 0x586420);
DefineLibMemberFunc(void, CUIControl, OnRMouseBtUp, (CPoint pt), OnRMouseBtUp, OnRMouseBtUp, (pt), 0x586430);
DefineLibMemberFunc(void, CUIControl, OnKeyPress, (short wChar), OnKeyPress, OnKeyPress, (wChar), 0x586440);
DefineLibMemberFunc(void, CUIControl, ShowTooltip, (bool b), ShowTooltip, ShowTooltip, (b), 0x5860A0);
DefineLibMemberFunc(STRREF, CUIControl, GetTooltip, (), GetTooltip, GetTooltip, (), 0x586450);
DefineLibMemberFunc(void, CUIControl, HideTooltip, (), HideTooltip, HideTooltip, (), 0x586470);
DefineLibMemberFunc(void, CUIControl, SetTooltip, (STRREF strref), SetTooltip, SetTooltip, (strref), 0x5861C0);
DefineLibMemberFunc(void, CUIControl, SetTooltipHotkey, (short key1, short key2, IECString& text), SetTooltipHotkey, SetTooltipHotkey, (key1, key2, text), 0x586490);
DefineLibMemberFunc(void, CUIControl, OnShowTooltip, (), OnShowTooltip, OnShowTooltip, (), 0x582878);
DefineLibMemberFunc(void, CUIControl, SetRedraw, (), SetRedraw, SetRedraw, (), 0xA398B5);
DefineLibMemberFunc(BOOL, CUIControl, Redraw, (BOOL bForceRedraw), Redraw, Redraw, (bForceRedraw), 0xA398B5);
DefineLibMemberFunc(BOOL, CUIControl, GetVisible, (), GetVisible, GetVisible, (), 0x5864D0);
DefineLibMemberFunc(void, CUIControl, SetVisible, (BOOL b), SetVisible, SetVisible, (b), 0x586080);
DefineLibMemberFunc(BOOL, CUIControl, NeedsRedraw, (), NeedsRedraw, NeedsRedraw, (), 0x5864F0);
