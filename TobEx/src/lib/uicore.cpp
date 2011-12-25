#include "uicore.h"

#include "utils.h"
#include "datatypes.h"

//CManager
CPanel& (CManager::*CManager_GetPanel)(DWORD) =
	SetFP(static_cast<CPanel& (CManager::*)(DWORD)>		(&CManager::GetPanel),		0x585480);

CPanel& CManager::GetPanel(DWORD index)		{ return (this->*CManager_GetPanel)(index); }

//CPanel
CUIControl& (CPanel::*CPanel_GetUIControl)(DWORD) =
	SetFP(static_cast<CUIControl& (CPanel::*)(DWORD)>	(&CPanel::GetUIControl),	0x5831CE);

CUIControl& CPanel::GetUIControl(DWORD index)	{ return (this->*CPanel_GetUIControl)(index); }

//CUIControl
CUIControl& (CUIControl::*CUIControl_Construct)(CPanel&, ChuFileControlInfoBase&, BOOL) =
	SetFP(static_cast<CUIControl& (CUIControl::*)(CPanel&, ChuFileControlInfoBase&, BOOL)>	(&CUIControl::Construct),		0x582650);
void (CUIControl::*CUIControl_Deconstruct)() =
	SetFP(static_cast<void (CUIControl::*)()>												(&CUIControl::Deconstruct),		0x586530);
void (CUIControl::*CUIControl_SetEnable)(bool) =
	SetFP(static_cast<void (CUIControl::*)(bool)>											(&CUIControl::SetEnabled),		0x586380);
BOOL (CUIControl::*CUIControl_OnMouseHover)(POINT&) =
	SetFP(static_cast<BOOL (CUIControl::*)(POINT&)>											(&CUIControl::OnMouseHover),	0x5863A0);
void (CUIControl::*CUIControl_OnLoseFocus)(void) =
	SetFP(static_cast<void (CUIControl::*)(void)>											(&CUIControl::OnLoseFocus),		0x5863C0);
void (CUIControl::*CUIControl_OnGetFocus)(void) =
	SetFP(static_cast<void (CUIControl::*)(void)>											(&CUIControl::OnGetFocus),		0x5863D0);
void (CUIControl::*CUIControl_OnLMouseDrag)(POINT) =
	SetFP(static_cast<void (CUIControl::*)(POINT)>											(&CUIControl::OnLMouseDrag),	0x5863E0);
BOOL (CUIControl::*CUIControl_OnLMouseBtDn)(POINT) =
	SetFP(static_cast<BOOL (CUIControl::*)(POINT)>											(&CUIControl::OnLMouseBtDn),	0x5863F0);
void (CUIControl::*CUIControl_OnLMouseBtUp)(POINT) =
	SetFP(static_cast<void (CUIControl::*)(POINT)>											(&CUIControl::OnLMouseBtUp),	0x586400);
BOOL (CUIControl::*CUIControl_OnLMouseDblClk)(POINT) =
	SetFP(static_cast<BOOL (CUIControl::*)(POINT)>											(&CUIControl::OnLMouseDblClk),	0x586410);
BOOL (CUIControl::*CUIControl_OnRMouseBtDn)(POINT) =
	SetFP(static_cast<BOOL (CUIControl::*)(POINT)>											(&CUIControl::OnRMouseBtDn),	0x586420);
void (CUIControl::*CUIControl_OnRMouseBtUp)(POINT) =
	SetFP(static_cast<void (CUIControl::*)(POINT)>											(&CUIControl::OnRMouseBtUp),	0x586430);
void (CUIControl::*CUIControl_v2c)(int) =
	SetFP(static_cast<void (CUIControl::*)(int)>											(&CUIControl::v2c),				0x586440);
void (CUIControl::*CUIControl_UpdateToolTip)(bool) =
	SetFP(static_cast<void (CUIControl::*)(bool)>											(&CUIControl::UpdateToolTip),	0x5860A0);
STRREF (CUIControl::*CUIControl_GetToolTip)() =
	SetFP(static_cast<STRREF (CUIControl::*)()>												(&CUIControl::GetToolTip),		0x586450);
void (CUIControl::*CUIControl_v38)() =
	SetFP(static_cast<void (CUIControl::*)()>												(&CUIControl::v38),				0x586470);
void (CUIControl::*CUIControl_SetToolTip)(STRREF) =
	SetFP(static_cast<void (CUIControl::*)(STRREF)>											(&CUIControl::SetToolTip),		0x5861C0);
void (CUIControl::*CUIControl_SetToolTipHotkey)(WORD, WORD, IECString&) =
	SetFP(static_cast<void (CUIControl::*)(WORD, WORD, IECString&)>							(&CUIControl::SetToolTipHotkey),0x586490);
void (CUIControl::*CUIControl_ShowToolTip)(void) =
	SetFP(static_cast<void (CUIControl::*)(void)>											(&CUIControl::ShowToolTip),		0x582878);
void (CUIControl::*CUIControl_SetRedraw)(void) =
	SetFP(static_cast<void (CUIControl::*)(void)>											(&CUIControl::SetRedraw),		0xA398B5);
BOOL (CUIControl::*CUIControl_Redraw)(BOOL) =
	SetFP(static_cast<BOOL (CUIControl::*)(BOOL)>											(&CUIControl::Redraw),			0xA398B5);
BOOL (CUIControl::*CUIControl_GetVisible)(void) =
	SetFP(static_cast<BOOL (CUIControl::*)(void)>											(&CUIControl::GetVisible),		0x5864D0);
void (CUIControl::*CUIControl_SetVisible)(BOOL) =
	SetFP(static_cast<void (CUIControl::*)(BOOL)>											(&CUIControl::SetVisible),		0x586080);
BOOL (CUIControl::*CUIControl_NeedsRedraw)(void) =
	SetFP(static_cast<BOOL (CUIControl::*)(void)>											(&CUIControl::NeedsRedraw),		0x5864F0);

CUIControl::CUIControl()															{ SetVT(this, 0xAAAD54); }
CUIControl::CUIControl(CPanel& panel, ChuFileControlInfoBase& controlInfo, BOOL b)	{ (this->*CUIControl_Construct)(panel, controlInfo, b); }
CUIControl::~CUIControl()															{ (this->*CUIControl_Deconstruct)(); }
void CUIControl::SetEnabled(bool b)													{ return (this->*CUIControl_SetEnable)(b); }
BOOL CUIControl::OnMouseHover(POINT& pt)											{ return (this->*CUIControl_OnMouseHover)(pt); }
void CUIControl::OnLoseFocus(void)													{ return (this->*CUIControl_OnLoseFocus)(); }
void CUIControl::OnGetFocus(void)													{ return (this->*CUIControl_OnGetFocus)(); }
void CUIControl::OnLMouseDrag(POINT pt)												{ return (this->*CUIControl_OnLMouseDrag)(pt); }
BOOL CUIControl::OnLMouseBtDn(POINT pt)												{ return (this->*CUIControl_OnLMouseBtDn)(pt); }
void CUIControl::OnLMouseBtUp(POINT pt)												{ return (this->*CUIControl_OnLMouseBtUp)(pt); }
BOOL CUIControl::OnLMouseDblClk(POINT pt)											{ return (this->*CUIControl_OnLMouseDblClk)(pt); }
BOOL CUIControl::OnRMouseBtDn(POINT pt)												{ return (this->*CUIControl_OnRMouseBtDn)(pt); }
void CUIControl::OnRMouseBtUp(POINT pt)												{ return (this->*CUIControl_OnRMouseBtUp)(pt); }
void CUIControl::v2c(int i)															{ return (this->*CUIControl_v2c)(i); }
void CUIControl::UpdateToolTip(bool b)												{ return (this->*CUIControl_UpdateToolTip)(b); }
STRREF CUIControl::GetToolTip()														{ return (this->*CUIControl_GetToolTip)(); }
void CUIControl::v38()																{ return (this->*CUIControl_v38)(); }
void CUIControl::SetToolTip(STRREF strref)											{ return (this->*CUIControl_SetToolTip)(strref); }
void CUIControl::SetToolTipHotkey(WORD key1, WORD key2, IECString& text)			{ return (this->*CUIControl_SetToolTipHotkey)(key1, key2, text); }
void CUIControl::ShowToolTip(void)													{ return (this->*CUIControl_ShowToolTip)(); }
void CUIControl::SetRedraw(void)													{ return (this->*CUIControl_SetRedraw)(); }
BOOL CUIControl::Redraw(BOOL bForceRedraw)											{ return (this->*CUIControl_Redraw)(bForceRedraw); }
BOOL CUIControl::GetVisible(void)													{ return (this->*CUIControl_GetVisible)(); }
void CUIControl::SetVisible(BOOL b)													{ return (this->*CUIControl_SetVisible)(b); }
BOOL CUIControl::NeedsRedraw(void)													{ return (this->*CUIControl_NeedsRedraw)(); }

CUIControl* (__cdecl *CreateUIControl)(CPanel&, ChuFileControlInfoBase&) =
	reinterpret_cast<CUIControl* (__cdecl *)(CPanel&, ChuFileControlInfoBase&)>	(0x95D5E0);