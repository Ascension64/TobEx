#include "uicore.h"

#include "stdafx.h"
#include "datatypes.h"

//CManager
CPanel& (CManager::*CManager_GetPanel)(int) =
	SetFP(static_cast<CPanel& (CManager::*)(int)>		(&CManager::GetPanel),		0x585480);

CPanel& CManager::GetPanel(int index)		{ return (this->*CManager_GetPanel)(index); }

//CPanel
CUIControl& (CPanel::*CPanel_GetUIControl)(int) =
	SetFP(static_cast<CUIControl& (CPanel::*)(int)>	(&CPanel::GetUIControl),	0x5831CE);

CUIControl& CPanel::GetUIControl(int index)	{ return (this->*CPanel_GetUIControl)(index); }

//CUIControl
CUIControl& (CUIControl::*CUIControl_Construct)(CPanel&, ChuFileControlInfoBase&, BOOL) =
	SetFP(static_cast<CUIControl& (CUIControl::*)(CPanel&, ChuFileControlInfoBase&, BOOL)>
																		(&CUIControl::Construct),		0x582650);
void (CUIControl::*CUIControl_Deconstruct)() =
	SetFP(static_cast<void (CUIControl::*)()>							(&CUIControl::Deconstruct),		0x586530);
void (CUIControl::*CUIControl_SetEnable)(bool) =
	SetFP(static_cast<void (CUIControl::*)(bool)>						(&CUIControl::SetEnabled),		0x586380);
BOOL (CUIControl::*CUIControl_OnMouseHover)(POINT&) =
	SetFP(static_cast<BOOL (CUIControl::*)(POINT&)>						(&CUIControl::OnMouseHover),	0x5863A0);
void (CUIControl::*CUIControl_OnLoseFocus)() =
	SetFP(static_cast<void (CUIControl::*)()>							(&CUIControl::OnLoseFocus),		0x5863C0);
void (CUIControl::*CUIControl_OnGetFocus)() =
	SetFP(static_cast<void (CUIControl::*)()>							(&CUIControl::OnGetFocus),		0x5863D0);
void (CUIControl::*CUIControl_OnLMouseDrag)(POINT) =
	SetFP(static_cast<void (CUIControl::*)(POINT)>						(&CUIControl::OnLMouseDrag),	0x5863E0);
BOOL (CUIControl::*CUIControl_OnLMouseBtDn)(POINT) =
	SetFP(static_cast<BOOL (CUIControl::*)(POINT)>						(&CUIControl::OnLMouseBtDn),	0x5863F0);
void (CUIControl::*CUIControl_OnLMouseBtUp)(POINT) =
	SetFP(static_cast<void (CUIControl::*)(POINT)>						(&CUIControl::OnLMouseBtUp),	0x586400);
BOOL (CUIControl::*CUIControl_OnLMouseDblClk)(POINT) =
	SetFP(static_cast<BOOL (CUIControl::*)(POINT)>						(&CUIControl::OnLMouseDblClk),	0x586410);
BOOL (CUIControl::*CUIControl_OnRMouseBtDn)(POINT) =
	SetFP(static_cast<BOOL (CUIControl::*)(POINT)>						(&CUIControl::OnRMouseBtDn),	0x586420);
void (CUIControl::*CUIControl_OnRMouseBtUp)(POINT) =
	SetFP(static_cast<void (CUIControl::*)(POINT)>						(&CUIControl::OnRMouseBtUp),	0x586430);
void (CUIControl::*CUIControl_OnKeyPress)(short) =
	SetFP(static_cast<void (CUIControl::*)(short)>						(&CUIControl::OnKeyPress),		0x586440);
void (CUIControl::*CUIControl_ShowTooltip)(bool) =
	SetFP(static_cast<void (CUIControl::*)(bool)>						(&CUIControl::ShowTooltip),		0x5860A0);
STRREF (CUIControl::*CUIControl_GetTooltip)() =
	SetFP(static_cast<STRREF (CUIControl::*)()>							(&CUIControl::GetTooltip),		0x586450);
void (CUIControl::*CUIControl_HideTooltip)() =
	SetFP(static_cast<void (CUIControl::*)()>							(&CUIControl::HideTooltip),		0x586470);
void (CUIControl::*CUIControl_SetTooltip)(STRREF) =
	SetFP(static_cast<void (CUIControl::*)(STRREF)>						(&CUIControl::SetTooltip),		0x5861C0);
void (CUIControl::*CUIControl_SetTooltipHotkey)(short, short, IECString&) =
	SetFP(static_cast<void (CUIControl::*)(short, short, IECString&)>	(&CUIControl::SetTooltipHotkey),0x586490);
void (CUIControl::*CUIControl_OnShowTooltip)() =
	SetFP(static_cast<void (CUIControl::*)()>							(&CUIControl::OnShowTooltip),	0x582878);
void (CUIControl::*CUIControl_SetRedraw)() =
	SetFP(static_cast<void (CUIControl::*)()>							(&CUIControl::SetRedraw),		0xA398B5);
BOOL (CUIControl::*CUIControl_Redraw)(BOOL) =
	SetFP(static_cast<BOOL (CUIControl::*)(BOOL)>						(&CUIControl::Redraw),			0xA398B5);
BOOL (CUIControl::*CUIControl_GetVisible)() =
	SetFP(static_cast<BOOL (CUIControl::*)()>							(&CUIControl::GetVisible),		0x5864D0);
void (CUIControl::*CUIControl_SetVisible)(BOOL) =
	SetFP(static_cast<void (CUIControl::*)(BOOL)>						(&CUIControl::SetVisible),		0x586080);
BOOL (CUIControl::*CUIControl_NeedsRedraw)() =
	SetFP(static_cast<BOOL (CUIControl::*)()>							(&CUIControl::NeedsRedraw),		0x5864F0);

CUIControl::CUIControl()															{ SetVT(this, 0xAAAD54); }
CUIControl::CUIControl(CPanel& panel, ChuFileControlInfoBase& controlInfo, BOOL b)	{ (this->*CUIControl_Construct)(panel, controlInfo, b); }
CUIControl::~CUIControl()															{ (this->*CUIControl_Deconstruct)(); }
void CUIControl::SetEnabled(bool b)													{ return (this->*CUIControl_SetEnable)(b); }
BOOL CUIControl::OnMouseHover(POINT& pt)											{ return (this->*CUIControl_OnMouseHover)(pt); }
void CUIControl::OnLoseFocus()														{ return (this->*CUIControl_OnLoseFocus)(); }
void CUIControl::OnGetFocus()														{ return (this->*CUIControl_OnGetFocus)(); }
void CUIControl::OnLMouseDrag(POINT pt)												{ return (this->*CUIControl_OnLMouseDrag)(pt); }
BOOL CUIControl::OnLMouseBtDn(POINT pt)												{ return (this->*CUIControl_OnLMouseBtDn)(pt); }
void CUIControl::OnLMouseBtUp(POINT pt)												{ return (this->*CUIControl_OnLMouseBtUp)(pt); }
BOOL CUIControl::OnLMouseDblClk(POINT pt)											{ return (this->*CUIControl_OnLMouseDblClk)(pt); }
BOOL CUIControl::OnRMouseBtDn(POINT pt)												{ return (this->*CUIControl_OnRMouseBtDn)(pt); }
void CUIControl::OnRMouseBtUp(POINT pt)												{ return (this->*CUIControl_OnRMouseBtUp)(pt); }
void CUIControl::OnKeyPress(short wChar)											{ return (this->*CUIControl_OnKeyPress)(wChar); }
void CUIControl::ShowTooltip(bool b)												{ return (this->*CUIControl_ShowTooltip)(b); }
STRREF CUIControl::GetTooltip()														{ return (this->*CUIControl_GetTooltip)(); }
void CUIControl::HideTooltip()														{ return (this->*CUIControl_HideTooltip)(); }
void CUIControl::SetTooltip(STRREF strref)											{ return (this->*CUIControl_SetTooltip)(strref); }
void CUIControl::SetTooltipHotkey(short key1, short key2, IECString& text)			{ return (this->*CUIControl_SetTooltipHotkey)(key1, key2, text); }
void CUIControl::OnShowTooltip()													{ return (this->*CUIControl_OnShowTooltip)(); }
void CUIControl::SetRedraw()														{ return (this->*CUIControl_SetRedraw)(); }
BOOL CUIControl::Redraw(BOOL bForceRedraw)											{ return (this->*CUIControl_Redraw)(bForceRedraw); }
BOOL CUIControl::GetVisible()														{ return (this->*CUIControl_GetVisible)(); }
void CUIControl::SetVisible(BOOL b)													{ return (this->*CUIControl_SetVisible)(b); }
BOOL CUIControl::NeedsRedraw()														{ return (this->*CUIControl_NeedsRedraw)(); }

CUIControl* (__cdecl *CreateUIControl)(CPanel&, ChuFileControlInfoBase&) =
	reinterpret_cast<CUIControl* (__cdecl *)(CPanel&, ChuFileControlInfoBase&)>	(0x95D5E0);