#include "uitext.h"

#include "stdafx.h"

//CUITextArea
DefineLibNoRetFunc(void, CUITextArea, ~CUITextArea, (), Deconstruct, Deconstruct, (), 0x59CA2F);
DefineLibMemberFunc(void, CUITextArea, SetEnabled, (bool b), SetEnabled, SetEnabled, (b), 0x59CC01);
DefineLibMemberFunc(void, CUITextArea, OnLMouseDrag, (CPoint pt), OnLMouseDrag, OnLMouseDrag, (pt), 0x59D97F);
DefineLibMemberFunc(BOOL, CUITextArea, OnLMouseBtDn, (CPoint pt), OnLMouseBtDn, OnLMouseBtDn, (pt), 0x59D8A8);
DefineLibMemberFunc(void, CUITextArea, OnLMouseBtUp, (CPoint pt), OnLMouseBtUp, OnLMouseBtUp, (pt), 0x59D8EA);
DefineLibMemberFunc(void, CUITextArea, ShowTooltip, (bool b), ShowTooltip, ShowTooltip, (b), 0x59FF2A);
DefineLibMemberFunc(void, CUITextArea, SetRedraw, (), SetRedraw, SetRedraw, (), 0x59D70D);
DefineLibMemberFunc(BOOL, CUITextArea, Redraw, (BOOL bForceRedraw), Redraw, Redraw, (bForceRedraw), 0x59EA6D);
DefineLibMemberFunc(BOOL, CUITextArea, NeedsRedraw, (), NeedsRedraw, NeedsRedraw, (), 0x5A5790);
DefineLibMemberFunc(void, CUITextArea, HighlightText, (POSITION pos), HighlightText, HighlightText, (pos), 0x59D286);
DefineLibMemberFunc(void, CUITextArea, UnhighlightText, (), UnhighlightText, UnhighlightText, (), 0x59D3A2);
DefineLibMemberFunc(void, CUITextArea, OnLClicked, (CPoint pt), OnLClicked, OnLClicked, (pt), 0x59D7A3);
DefineLibMemberFunc(void, CUITextArea, UserProc, (int nArg), UserProc, UserProc, (nArg), 0x5A5780);
DefineLibMemberFunc(POSITION, CUITextArea, Append, (
	IECString& sLeft,
	IECString& sRight,
	ABGR colLeft,
	ABGR colRight,
	int nUserArg,
	bool bResetScrollbar
	), Append, Append, (sLeft, sRight, colLeft, colRight, nUserArg, bResetScrollbar), 0x59CE80);
DefineLibMemberFunc(void, CUITextArea, ClearText, (), ClearText, ClearText, (), 0x59E069);

//CUITextField
DefineLibNoRetFunc(void, CUITextField, ~CUITextField, (), Deconstruct, Deconstruct, (), 0x5A4D30);
DefineLibMemberFunc(void, CUITextField, SetEnabled, (bool b), SetEnabled, SetEnabled, (b), 0x58E4EE);
DefineLibMemberFunc(void, CUITextField, OnLoseFocus, (), OnLoseFocus, OnLoseFocus, (), 0x590485);
DefineLibMemberFunc(void, CUITextField, OnGetFocus, (), OnGetFocus, OnGetFocus, (), 0x5905DD);
DefineLibMemberFunc(void, CUITextField, OnLMouseDrag, (CPoint pt), OnLMouseDrag, OnLMouseDrag, (pt), 0x59A126);
DefineLibMemberFunc(BOOL, CUITextField, OnLMouseBtDn, (CPoint pt), OnLMouseBtDn, OnLMouseBtDn, (pt), 0x59064D);
DefineLibMemberFunc(void, CUITextField, OnLMouseBtUp, (CPoint pt), OnLMouseBtUp, OnLMouseBtUp, (pt), 0x590EE2);
DefineLibMemberFunc(BOOL, CUITextField, OnRMouseBtDn, (CPoint pt), OnRMouseBtDn, OnRMouseBtDn, (pt), 0x590F64);
DefineLibMemberFunc(void, CUITextField, OnKeyPress, (short wChar), OnKeyPress, OnKeyPress, (wChar), 0x59108F);
DefineLibMemberFunc(void, CUITextField, SetRedraw, (), SetRedraw, SetRedraw, (), 0x59BC12);
DefineLibMemberFunc(BOOL, CUITextField, Redraw, (BOOL bForceRedraw), Redraw, Redraw, (bForceRedraw), 0x59A93F);
DefineLibMemberFunc(BOOL, CUITextField, NeedsRedraw, (), NeedsRedraw, NeedsRedraw, (), 0x59A8FC);
DefineLibMemberFunc(void, CUITextField, SetTextColors, (ABGR colText, ABGR colGreyed), SetTextColors, SetTextColors, (colText, colGreyed), 0x5A5710);
DefineLibMemberFunc(void, CUITextField, Execute, (IECString& s), Execute, Execute, (s), 0x5A5740);
DefineLibMemberFunc(IECString, CUITextField, GetText, (), GetText, GetText, (), 0x590371);
DefineLibMemberFunc(void, CUITextField, SetText, (IECString& s), SetText, SetText, (s), 0x59BF1F);
DefineLibMemberFunc(void, CUITextField, UpdateDisplayArea, (), UpdateDisplayArea, UpdateDisplayArea, (), 0x59C405);
