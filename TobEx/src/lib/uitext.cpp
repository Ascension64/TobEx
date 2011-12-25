#include "uitext.h"

//CUITextArea
extern void (CUITextArea::*CUITextArea_Deconstruct)() =
	SetFP(static_cast<void (CUITextArea::*)()>			(&CUITextArea::Deconstruct),		0x59CA2F);
extern void (CUITextArea::*CUITextArea_SetEnabled)(bool) =
	SetFP(static_cast<void (CUITextArea::*)(bool)>		(&CUITextArea::SetEnabled),			0x59CC01);
extern void (CUITextArea::*CUITextArea_OnLMouseDrag)(POINT) =
	SetFP(static_cast<void (CUITextArea::*)(POINT)>		(&CUITextArea::OnLMouseDrag),		0x59D97F);
extern BOOL (CUITextArea::*CUITextArea_OnLMouseBtDn)(POINT) =
	SetFP(static_cast<BOOL (CUITextArea::*)(POINT)>		(&CUITextArea::OnLMouseBtDn),		0x59D8A8);
extern void (CUITextArea::*CUITextArea_OnLMouseBtUp)(POINT) =
	SetFP(static_cast<void (CUITextArea::*)(POINT)>		(&CUITextArea::OnLMouseBtUp),		0x59D8EA);
extern void (CUITextArea::*CUITextArea_ShowTooltip)(bool) =
	SetFP(static_cast<void (CUITextArea::*)(bool)>		(&CUITextArea::ShowTooltip),		0x59FF2A);
extern void (CUITextArea::*CUITextArea_SetRedraw)() =
	SetFP(static_cast<void (CUITextArea::*)()>			(&CUITextArea::SetRedraw),			0x59D70D);
extern BOOL (CUITextArea::*CUITextArea_Redraw)(BOOL) =
	SetFP(static_cast<BOOL (CUITextArea::*)(BOOL)>		(&CUITextArea::Redraw),				0x59EA6D);
extern BOOL (CUITextArea::*CUITextArea_NeedsRedraw)() =
	SetFP(static_cast<BOOL (CUITextArea::*)()>			(&CUITextArea::NeedsRedraw),		0x5A5790);	
extern void (CUITextArea::*CUITextArea_HighlightText)(POSITION) =
	SetFP(static_cast<void (CUITextArea::*)(POSITION)>	(&CUITextArea::HighlightText),		0x59D286);	
extern void (CUITextArea::*CUITextArea_UnhighlightText)() =
	SetFP(static_cast<void (CUITextArea::*)()>			(&CUITextArea::UnhighlightText),	0x59D3A2);	
extern void (CUITextArea::*CUITextArea_OnLClicked)(POINT) =
	SetFP(static_cast<void (CUITextArea::*)(POINT)>		(&CUITextArea::OnLClicked),			0x59D7A3);
extern void (CUITextArea::*CUITextArea_UserProc)(int) =
	SetFP(static_cast<void (CUITextArea::*)(int)>		(&CUITextArea::UserProc),			0x5A5780);
extern POSITION (CUITextArea::*CUITextArea_Append)(IECString&, IECString&, ABGR, ABGR, int, bool) =
	SetFP(static_cast<POSITION (CUITextArea::*)(IECString&, IECString&, ABGR, ABGR, int, bool)>
														(&CUITextArea::Append),				0x59CE80);
extern void (CUITextArea::*CUITextArea_ClearText)() =
	SetFP(static_cast<void (CUITextArea::*)()>			(&CUITextArea::ClearText),			0x59E069);

CUITextArea::~CUITextArea()						{ (this->*CUITextArea_Deconstruct)(); }
void CUITextArea::SetEnabled(bool b)			{ return (this->*CUITextArea_SetEnabled)(b); }
void CUITextArea::OnLMouseDrag(POINT pt)		{ return (this->*CUITextArea_OnLMouseDrag)(pt); }
BOOL CUITextArea::OnLMouseBtDn(POINT pt)		{ return (this->*CUITextArea_OnLMouseBtDn)(pt); }
void CUITextArea::OnLMouseBtUp(POINT pt)		{ return (this->*CUITextArea_OnLMouseBtUp)(pt); }
void CUITextArea::ShowTooltip(bool b)			{ return (this->*CUITextArea_ShowTooltip)(b); }
void CUITextArea::SetRedraw()					{ return (this->*CUITextArea_SetRedraw)(); }
BOOL CUITextArea::Redraw(BOOL bForceRedraw)		{ return (this->*CUITextArea_Redraw)(bForceRedraw); }
BOOL CUITextArea::NeedsRedraw()					{ return (this->*CUITextArea_NeedsRedraw)(); }
void CUITextArea::HighlightText(POSITION pos)	{ return (this->*CUITextArea_HighlightText)(pos); }
void CUITextArea::UnhighlightText()				{ return (this->*CUITextArea_UnhighlightText)(); }
void CUITextArea::OnLClicked(POINT pt)			{ return (this->*CUITextArea_OnLClicked)(pt); }
void CUITextArea::UserProc(int nArg)			{ return (this->*CUITextArea_UserProc)(nArg); }
POSITION CUITextArea::Append(IECString& sLeft, IECString& sRight, ABGR colLeft, ABGR colRight, int nUserArg, bool bResetScrollbar)
	{ return (this->*CUITextArea_Append)(sLeft, sRight, colLeft, colRight, nUserArg, bResetScrollbar); }
void CUITextArea::ClearText()					{ return (this->*CUITextArea_ClearText)(); }

//CUITextField
void (CUITextField::*CUITextField_Deconstruct)() =
	SetFP(static_cast<void (CUITextField::*)()>					(&CUITextField::Deconstruct),		0x5A4D30);
void (CUITextField::*CUITextField_SetEnabled)(bool) =
	SetFP(static_cast<void (CUITextField::*)(bool)>				(&CUITextField::SetEnabled),		0x58E4EE);
void (CUITextField::*CUITextField_OnLoseFocus)() =
	SetFP(static_cast<void (CUITextField::*)()>					(&CUITextField::OnLoseFocus),		0x590485);
void (CUITextField::*CUITextField_OnGetFocus)() =
	SetFP(static_cast<void (CUITextField::*)()>					(&CUITextField::OnGetFocus),		0x5905DD);
void (CUITextField::*CUITextField_OnLMouseDrag)(POINT) =
	SetFP(static_cast<void (CUITextField::*)(POINT)>			(&CUITextField::OnLMouseDrag),		0x59A126);
BOOL (CUITextField::*CUITextField_OnLMouseBtDn)(POINT) =
	SetFP(static_cast<BOOL (CUITextField::*)(POINT)>			(&CUITextField::OnLMouseBtDn),		0x59064D);
void (CUITextField::*CUITextField_OnLMouseBtUp)(POINT) =
	SetFP(static_cast<void (CUITextField::*)(POINT)>			(&CUITextField::OnLMouseBtUp),		0x590EE2);
BOOL (CUITextField::*CUITextField_OnRMouseBtDn)(POINT) =
	SetFP(static_cast<BOOL (CUITextField::*)(POINT)>			(&CUITextField::OnRMouseBtDn),		0x590F64);
void (CUITextField::*CUITextField_OnKeyPress)(short) =
	SetFP(static_cast<void (CUITextField::*)(short)>			(&CUITextField::OnKeyPress),		0x59108F);
void (CUITextField::*CUITextField_SetRedraw)() =
	SetFP(static_cast<void (CUITextField::*)()>					(&CUITextField::SetRedraw),			0x59BC12);
BOOL (CUITextField::*CUITextField_Redraw)(BOOL) =
	SetFP(static_cast<BOOL (CUITextField::*)(BOOL)>				(&CUITextField::Redraw),			0x59A93F);
BOOL (CUITextField::*CUITextField_NeedsRedraw)() =
	SetFP(static_cast<BOOL (CUITextField::*)()>					(&CUITextField::NeedsRedraw),		0x59A8FC);
void (CUITextField::*CUITextField_SetTextColors)(ABGR, ABGR) =
	SetFP(static_cast<void (CUITextField::*)(ABGR, ABGR)>		(&CUITextField::SetTextColors),		0x5A5710);
void (CUITextField::*CUITextField_ClearText)(IECString&) =
	SetFP(static_cast<void (CUITextField::*)(IECString&)>		(&CUITextField::ClearText),			0x5A5740);
IECString (CUITextField::*CUITextField_GetText)() =
	SetFP(static_cast<IECString (CUITextField::*)()>			(&CUITextField::GetText),			0x590371);
void (CUITextField::*CUITextField_SetText)(IECString&) =
	SetFP(static_cast<void (CUITextField::*)(IECString&)>		(&CUITextField::SetText),			0x59BF1F);
void (CUITextField::*CUITextField_UpdateDisplayArea)() =
	SetFP(static_cast<void (CUITextField::*)()>					(&CUITextField::UpdateDisplayArea),	0x59C405);

CUITextField::~CUITextField()									{ (this->*CUITextField_Deconstruct)(); }
void CUITextField::SetEnabled(bool b)							{ return (this->*CUITextField_SetEnabled)(b); }
void CUITextField::OnLoseFocus()								{ return (this->*CUITextField_OnLoseFocus)(); }
void CUITextField::OnGetFocus()									{ return (this->*CUITextField_OnGetFocus)(); }
void CUITextField::OnLMouseDrag(POINT pt)						{ return (this->*CUITextField_OnLMouseDrag)(pt); }
BOOL CUITextField::OnLMouseBtDn(POINT pt)						{ return (this->*CUITextField_OnLMouseBtDn)(pt); }
void CUITextField::OnLMouseBtUp(POINT pt)						{ return (this->*CUITextField_OnLMouseBtUp)(pt); }
BOOL CUITextField::OnRMouseBtDn(POINT pt)						{ return (this->*CUITextField_OnRMouseBtDn)(pt); }
void CUITextField::OnKeyPress(short wChar)						{ return (this->*CUITextField_OnKeyPress)(wChar); }
void CUITextField::SetRedraw()									{ return (this->*CUITextField_SetRedraw)(); }
BOOL CUITextField::Redraw(BOOL bForceRedraw)					{ return (this->*CUITextField_Redraw)(bForceRedraw); }
BOOL CUITextField::NeedsRedraw()								{ return (this->*CUITextField_NeedsRedraw)(); }
void CUITextField::SetTextColors(ABGR colText, ABGR colGreyed)	{ return (this->*CUITextField_SetTextColors)(colText, colGreyed); }
void CUITextField::ClearText(IECString& s)						{ return (this->*CUITextField_ClearText)(s); }
IECString CUITextField::GetText()								{ return (this->*CUITextField_GetText)(); }
void CUITextField::SetText(IECString& s)						{ return (this->*CUITextField_SetText)(s); }
void CUITextField::UpdateDisplayArea()							{ return (this->*CUITextField_UpdateDisplayArea)(); }
