#include "uibutton.h"

#include "stdafx.h"

//CUIButton
CUIButton& (CUIButton::*CUIButton_Construct_4CPanel_ChuFileControlInfoBase_BYTE_BOOL)(CPanel&, ChuFileControlInfoBase&, char, BOOL) =
	SetFP(static_cast<CUIButton& (CUIButton::*)(CPanel&, ChuFileControlInfoBase&, char, BOOL)>
														(&CUIButton::Construct),		0x586570);
void (CUIButton::*CUIButton_Deconstruct)() =
	SetFP(static_cast<void (CUIButton::*)()>			(&CUIButton::Deconstruct),		0x5A54D0);
void (CUIButton::*CUIButton_SetActive)(BOOL) =
	SetFP(static_cast<void (CUIButton::*)(BOOL)>		(&CUIButton::SetActive),		0x587C9D);
void (CUIButton::*CUIButton_OnLoseFocus)() =
	SetFP(static_cast<void (CUIButton::*)()>			(&CUIButton::OnLoseFocus),		0x586B6A);
void (CUIButton::*CUIButton_OnLMouseDrag)(POINT) =
	SetFP(static_cast<void (CUIButton::*)(POINT)>		(&CUIButton::OnLMouseDrag),		0x586BBC);
BOOL (CUIButton::*CUIButton_OnLMouseBtDn)(POINT) =
	SetFP(static_cast<BOOL (CUIButton::*)(POINT)>		(&CUIButton::OnLMouseBtDn),		0x586CFC);
void (CUIButton::*CUIButton_OnLMouseBtUp)(POINT) =
	SetFP(static_cast<void (CUIButton::*)(POINT)>		(&CUIButton::OnLMouseBtUp),		0x586DD7);
BOOL (CUIButton::*CUIButton_OnLMouseDblClk)(POINT) =
	SetFP(static_cast<BOOL (CUIButton::*)(POINT)>		(&CUIButton::OnLMouseDblClk),	0x586F1B);
BOOL (CUIButton::*CUIButton_OnRMouseBtDn)(POINT) =
	SetFP(static_cast<BOOL (CUIButton::*)(POINT)>		(&CUIButton::OnRMouseBtDn),		0x586F66);
void (CUIButton::*CUIButton_OnRMouseBtUp)(POINT) =
	SetFP(static_cast<void (CUIButton::*)(POINT)>		(&CUIButton::OnRMouseBtUp),		0x587041);
void (CUIButton::*CUIButton_SetRedraw)() =
	SetFP(static_cast<void (CUIButton::*)()>			(&CUIButton::SetRedraw),		0x587C04);
BOOL (CUIButton::*CUIButton_Redraw)(BOOL) =
	SetFP(static_cast<BOOL (CUIButton::*)(BOOL)>		(&CUIButton::Redraw),			0x587101);
BOOL (CUIButton::*CUIButton_NeedsRedraw)() =
	SetFP(static_cast<BOOL (CUIButton::*)()>			(&CUIButton::NeedsRedraw),		0x586B27);
void (CUIButton::*CUIButton_OnLClicked)(POINT) =
	SetFP(static_cast<void (CUIButton::*)(POINT)>		(&CUIButton::OnLClicked),		0x5A55F0);
void (CUIButton::*CUIButton_OnLDblClicked)(POINT) =
	SetFP(static_cast<void (CUIButton::*)(POINT)>		(&CUIButton::OnLDblClicked),	0x5A5600);
void (CUIButton::*CUIButton_OnRClicked)(POINT) =
	SetFP(static_cast<void (CUIButton::*)(POINT)>		(&CUIButton::OnRClicked),		0x5A5610);
void (CUIButton::*CUIButton_SetText)(IECString&) =
	SetFP(static_cast<void (CUIButton::*)(IECString&)>	(&CUIButton::SetText),			0x587DF2);

CUIButton::CUIButton()						{ SetVT(this, 0xAAAE44); }
CUIButton::CUIButton(CPanel& panel, ChuFileControlInfoBase& controlInfo, char flags, BOOL b)
											{ (this->*CUIButton_Construct_4CPanel_ChuFileControlInfoBase_BYTE_BOOL)(panel, controlInfo, flags, b); }
void CUIButton::SetActive(BOOL b)			{ return (this->*CUIButton_SetActive)(b); }
CUIButton::~CUIButton()						{ (this->*CUIButton_Deconstruct)(); }
void CUIButton::OnLoseFocus()				{ return (this->*CUIButton_OnLoseFocus)(); }
void CUIButton::OnLMouseDrag(POINT pt)		{ return (this->*CUIButton_OnLMouseDrag)(pt); }
BOOL CUIButton::OnLMouseBtDn(POINT pt)		{ return (this->*CUIButton_OnLMouseBtDn)(pt); }
void CUIButton::OnLMouseBtUp(POINT pt)		{ return (this->*CUIButton_OnLMouseBtUp)(pt); }
BOOL CUIButton::OnLMouseDblClk(POINT pt)	{ return (this->*CUIButton_OnLMouseDblClk)(pt); }
BOOL CUIButton::OnRMouseBtDn(POINT pt)		{ return (this->*CUIButton_OnRMouseBtDn)(pt); }
void CUIButton::OnRMouseBtUp(POINT pt)		{ return (this->*CUIButton_OnRMouseBtUp)(pt); }
void CUIButton::SetRedraw()					{ return (this->*CUIButton_SetRedraw)(); }
BOOL CUIButton::Redraw(BOOL bForceRedraw)	{ return (this->*CUIButton_Redraw)(bForceRedraw); }
BOOL CUIButton::NeedsRedraw()				{ return (this->*CUIButton_NeedsRedraw)(); }
void CUIButton::OnLClicked(POINT pt)		{ return (this->*CUIButton_OnLClicked)(pt); }
void CUIButton::OnLDblClicked(POINT pt)		{ return (this->*CUIButton_OnLDblClicked)(pt); }
void CUIButton::OnRClicked(POINT pt)		{ return (this->*CUIButton_OnRClicked)(pt); }
void CUIButton::SetText(IECString& sText)	{ return (this->*CUIButton_SetText)(sText); }

//CUIButtonMageBookKnownSpell
CUIButtonMageBookKnownSpell& (CUIButtonMageBookKnownSpell::*CUIButtonMageBookKnownSpell_Construct_2CPanel_ChuFileControlInfoBase)(CPanel&, ChuFileControlInfoBase&) =
	SetFP(static_cast<CUIButtonMageBookKnownSpell& (CUIButtonMageBookKnownSpell::*)(CPanel&, ChuFileControlInfoBase&)>
																		(&CUIButtonMageBookKnownSpell::Construct),		0x7BE8AE);
void (CUIButtonMageBookKnownSpell::*CUIButtonMageBookKnownSpell_SetSpell)(ResRef&) =
	SetFP(static_cast<void (CUIButtonMageBookKnownSpell::*)(ResRef&)>	(&CUIButtonMageBookKnownSpell::SetSpell),		0x7BE9E2);
void (CUIButtonMageBookKnownSpell::*CUIButtonMageBookKnownSpell_Deconstruct)() =
	SetFP(static_cast<void (CUIButtonMageBookKnownSpell::*)()>			(&CUIButtonMageBookKnownSpell::Deconstruct),	0x7C2A70);
BOOL (CUIButtonMageBookKnownSpell::*CUIButtonMageBookKnownSpell_OnLMouseBtDn)(POINT) =
	SetFP(static_cast<BOOL (CUIButtonMageBookKnownSpell::*)(POINT)>		(&CUIButtonMageBookKnownSpell::OnLMouseBtDn),	0x7BEBFB);
BOOL (CUIButtonMageBookKnownSpell::*CUIButtonMageBookKnownSpell_Redraw)(BOOL) =
	SetFP(static_cast<BOOL (CUIButtonMageBookKnownSpell::*)(BOOL)>		(&CUIButtonMageBookKnownSpell::Redraw),			0x7BF1AF);
void (CUIButtonMageBookKnownSpell::*CUIButtonMageBookKnownSpell_OnLClicked)(POINT) =
	SetFP(static_cast<void (CUIButtonMageBookKnownSpell::*)(POINT)>		(&CUIButtonMageBookKnownSpell::OnLClicked),		0x7BECB9);
void (CUIButtonMageBookKnownSpell::*CUIButtonMageBookKnownSpell_OnRClicked)(POINT) =
	SetFP(static_cast<void (CUIButtonMageBookKnownSpell::*)(POINT)>		(&CUIButtonMageBookKnownSpell::OnRClicked),		0x7BF0B8);

CUIButtonMageBookKnownSpell::CUIButtonMageBookKnownSpell(CPanel& panel, ChuFileControlInfoBase& controlInfo)
															{ (this->*CUIButtonMageBookKnownSpell_Construct_2CPanel_ChuFileControlInfoBase)(panel, controlInfo); }

CUIButtonMageBookKnownSpell::~CUIButtonMageBookKnownSpell()	{ (this->*CUIButtonMageBookKnownSpell_Deconstruct)(); }
void CUIButtonMageBookKnownSpell::SetSpell(ResRef& rSpell)	{ return (this->*CUIButtonMageBookKnownSpell_SetSpell)(rSpell); }
BOOL CUIButtonMageBookKnownSpell::OnLMouseBtDn(POINT pt)	{ return (this->*CUIButtonMageBookKnownSpell_OnLMouseBtDn)(pt); }
BOOL CUIButtonMageBookKnownSpell::Redraw(BOOL b)			{ return (this->*CUIButtonMageBookKnownSpell_Redraw)(b); }
void CUIButtonMageBookKnownSpell::OnLClicked(POINT pt)		{ return (this->*CUIButtonMageBookKnownSpell_OnLClicked)(pt); }
void CUIButtonMageBookKnownSpell::OnRClicked(POINT pt)		{ return (this->*CUIButtonMageBookKnownSpell_OnRClicked)(pt); }

//CUIButtonPriestBookKnownSpell
CUIButtonPriestBookKnownSpell& (CUIButtonPriestBookKnownSpell::*CUIButtonPriestBookKnownSpell_Construct_2CPanel_ChuFileControlInfoBase)(CPanel&, ChuFileControlInfoBase&) =
	SetFP(static_cast<CUIButtonPriestBookKnownSpell& (CUIButtonPriestBookKnownSpell::*)(CPanel&, ChuFileControlInfoBase&)>
																			(&CUIButtonPriestBookKnownSpell::Construct),	0x788CFF);
void (CUIButtonPriestBookKnownSpell::*CUIButtonPriestBookKnownSpell_SetSpell)(ResRef&) =
	SetFP(static_cast<void (CUIButtonPriestBookKnownSpell::*)(ResRef&)>		(&CUIButtonPriestBookKnownSpell::SetSpell),		0x788E33);
void (CUIButtonPriestBookKnownSpell::*CUIButtonPriestBookKnownSpell_Deconstruct)() =
	SetFP(static_cast<void (CUIButtonPriestBookKnownSpell::*)()>			(&CUIButtonPriestBookKnownSpell::Deconstruct),	0x78AC90);
BOOL (CUIButtonPriestBookKnownSpell::*CUIButtonPriestBookKnownSpell_OnLMouseBtDn)(POINT) =
	SetFP(static_cast<BOOL (CUIButtonPriestBookKnownSpell::*)(POINT)>		(&CUIButtonPriestBookKnownSpell::OnLMouseBtDn),	0x78903D);
BOOL (CUIButtonPriestBookKnownSpell::*CUIButtonPriestBookKnownSpell_Redraw)(BOOL) =
	SetFP(static_cast<BOOL (CUIButtonPriestBookKnownSpell::*)(BOOL)>		(&CUIButtonPriestBookKnownSpell::Redraw),		0x789578);
void (CUIButtonPriestBookKnownSpell::*CUIButtonPriestBookKnownSpell_OnLClicked)(POINT) =
	SetFP(static_cast<void (CUIButtonPriestBookKnownSpell::*)(POINT)>		(&CUIButtonPriestBookKnownSpell::OnLClicked),	0x7890FB);
void (CUIButtonPriestBookKnownSpell::*CUIButtonPriestBookKnownSpell_OnRClicked)(POINT) =
	SetFP(static_cast<void (CUIButtonPriestBookKnownSpell::*)(POINT)>		(&CUIButtonPriestBookKnownSpell::OnRClicked),	0x789496);

CUIButtonPriestBookKnownSpell::CUIButtonPriestBookKnownSpell(CPanel& panel, ChuFileControlInfoBase& controlInfo)
																{ (this->*CUIButtonPriestBookKnownSpell_Construct_2CPanel_ChuFileControlInfoBase)(panel, controlInfo); }

CUIButtonPriestBookKnownSpell::~CUIButtonPriestBookKnownSpell()	{ (this->*CUIButtonPriestBookKnownSpell_Deconstruct)(); }
void CUIButtonPriestBookKnownSpell::SetSpell(ResRef& rSpell)	{ return (this->*CUIButtonPriestBookKnownSpell_SetSpell)(rSpell); }
BOOL CUIButtonPriestBookKnownSpell::OnLMouseBtDn(POINT pt)		{ return (this->*CUIButtonPriestBookKnownSpell_OnLMouseBtDn)(pt); }
BOOL CUIButtonPriestBookKnownSpell::Redraw(BOOL b)				{ return (this->*CUIButtonPriestBookKnownSpell_Redraw)(b); }
void CUIButtonPriestBookKnownSpell::OnLClicked(POINT pt)		{ return (this->*CUIButtonPriestBookKnownSpell_OnLClicked)(pt); }
void CUIButtonPriestBookKnownSpell::OnRClicked(POINT pt)		{ return (this->*CUIButtonPriestBookKnownSpell_OnRClicked)(pt); }

//CUICheckButton
CUICheckButton& (CUICheckButton::*CUICheckButton_Construct_4CPanel_ChuFileControlInfoBase_BYTE_BOOL)(CPanel&, ChuFileControlInfoBase&, char, BOOL) =
	SetFP(static_cast<CUICheckButton& (CUICheckButton::*)(CPanel&, ChuFileControlInfoBase&, char, BOOL)>
																						(&CUICheckButton::Construct),		0x587FB2);
void (CUICheckButton::*CUICheckButton_Deconstruct)() =
	SetFP(static_cast<void (CUICheckButton::*)()>										(&CUICheckButton::Deconstruct),		0x5A4A30);
void (CUICheckButton::*CUICheckButton_SetToggleState)(BOOL) =
	SetFP(static_cast<void (CUICheckButton::*)(BOOL)>									(&CUICheckButton::SetToggleState),	0x588010);
BOOL (CUICheckButton::*CUICheckButton_Redraw)(BOOL) =
	SetFP(static_cast<BOOL (CUICheckButton::*)(BOOL)>									(&CUICheckButton::Redraw),			0x588067);
void (CUICheckButton::*CUICheckButton_OnLClicked)(POINT) =
	SetFP(static_cast<void (CUICheckButton::*)(POINT)>									(&CUICheckButton::OnLClicked),		0x588042);

CUICheckButton::CUICheckButton()					{ SetVT(this, 0xAAAEB0); }
CUICheckButton::CUICheckButton(CPanel& panel, ChuFileControlInfoBase& controlInfo, char flags, BOOL b)
													{ (this->*CUICheckButton_Construct_4CPanel_ChuFileControlInfoBase_BYTE_BOOL)(panel, controlInfo, flags, b); }
CUICheckButton::~CUICheckButton()					{ (this->*CUICheckButton_Deconstruct)(); }
void CUICheckButton::SetToggleState(BOOL b)			{ return (this->*CUICheckButton_SetToggleState)(b); }
BOOL CUICheckButton::Redraw(BOOL bForceRedraw)		{ return (this->*CUICheckButton_Redraw)(bForceRedraw); }
void CUICheckButton::OnLClicked(POINT pt)			{ return (this->*CUICheckButton_OnLClicked)(pt); }

//CUICheckButtonChargenClass
CUICheckButtonChargenClass& (CUICheckButtonChargenClass::*CUICheckButtonChargenClass_Construct_2CPanel_ChuFileControlInfoBase)(CPanel&, ChuFileControlInfoBase&) =
	SetFP(static_cast<CUICheckButtonChargenClass& (CUICheckButtonChargenClass::*)(CPanel&, ChuFileControlInfoBase&)>
																		(&CUICheckButtonChargenClass::Construct),	0x733AB4);
unsigned char (CUICheckButtonChargenClass::*CUICheckButtonChargenClass_GetClass)() =
	SetFP(static_cast<unsigned char (CUICheckButtonChargenClass::*)()>		(&CUICheckButtonChargenClass::GetClass),	0x73402E);
void (CUICheckButtonChargenClass::*CUICheckButtonChargenClass_Deconstruct)() =
	SetFP(static_cast<void (CUICheckButtonChargenClass::*)()>			(&CUICheckButtonChargenClass::Deconstruct),	0x73D270);
void (CUICheckButtonChargenClass::*CUICheckButtonChargenClass_OnLClicked)(POINT) =
	SetFP(static_cast<void (CUICheckButtonChargenClass::*)(POINT)>		(&CUICheckButtonChargenClass::OnLClicked),	0x733B95);

CUICheckButtonChargenClass::CUICheckButtonChargenClass(CPanel& panel, ChuFileControlInfoBase& controlInfo)
															{ (this->*CUICheckButtonChargenClass_Construct_2CPanel_ChuFileControlInfoBase)(panel, controlInfo); }
unsigned char CUICheckButtonChargenClass::GetClass()		{ return (this->*CUICheckButtonChargenClass_GetClass)(); }
CUICheckButtonChargenClass::~CUICheckButtonChargenClass()	{ (this->*CUICheckButtonChargenClass_Deconstruct)(); }
void CUICheckButtonChargenClass::OnLClicked(POINT pt)		{ return (this->*CUICheckButtonChargenClass_OnLClicked)(pt); }

//CUICheckButtonChargenKit
CUICheckButtonChargenKit& (CUICheckButtonChargenKit::*CUICheckButtonChargenKit_Construct_2CPanel_ChuFileControlInfoBase)(CPanel&, ChuFileControlInfoBase&) =
	SetFP(static_cast<CUICheckButtonChargenKit& (CUICheckButtonChargenKit::*)(CPanel&, ChuFileControlInfoBase&)>
																			(&CUICheckButtonChargenKit::Construct),		0x73A6B7);
unsigned int (CUICheckButtonChargenKit::*CUICheckButtonChargenKit_GetKitId)(Object&) =
	SetFP(static_cast<unsigned int (CUICheckButtonChargenKit::*)(Object&)>	(&CUICheckButtonChargenKit::GetKitId),		0x73A6E8);
STRREF (CUICheckButtonChargenKit::*CUICheckButtonChargenKit_GetKitHelpText)(Object&) =
	SetFP(static_cast<STRREF (CUICheckButtonChargenKit::*)(Object&)>		(&CUICheckButtonChargenKit::GetKitHelpText),0x73A84E);
void (CUICheckButtonChargenKit::*CUICheckButtonChargenKit_Deconstruct)() =
	SetFP(static_cast<void (CUICheckButtonChargenKit::*)()>					(&CUICheckButtonChargenKit::Deconstruct),	0x73E3E0);
void (CUICheckButtonChargenKit::*CUICheckButtonChargenKit_OnLClicked)(POINT) =
	SetFP(static_cast<void (CUICheckButtonChargenKit::*)(POINT)>			(&CUICheckButtonChargenKit::OnLClicked),	0x73ABDF);

CUICheckButtonChargenKit::CUICheckButtonChargenKit(CPanel& panel, ChuFileControlInfoBase& controlInfo)
															{ (this->*CUICheckButtonChargenKit_Construct_2CPanel_ChuFileControlInfoBase)(panel, controlInfo); }
unsigned int CUICheckButtonChargenKit::GetKitId(Object& o)	{ return (this->*CUICheckButtonChargenKit_GetKitId)(o); }
STRREF CUICheckButtonChargenKit::GetKitHelpText(Object& o)	{ return (this->*CUICheckButtonChargenKit_GetKitHelpText)(o); }
CUICheckButtonChargenKit::~CUICheckButtonChargenKit()		{ (this->*CUICheckButtonChargenKit_Deconstruct)(); }
void CUICheckButtonChargenKit::OnLClicked(POINT pt)			{ return (this->*CUICheckButtonChargenKit_OnLClicked)(pt); }

//CUICheckButtonChargenMageSchool
CUICheckButtonChargenMageSchool& (CUICheckButtonChargenMageSchool::*CUICheckButtonChargenMageSchool_Construct_2CPanel_ChuFileControlInfoBase)(CPanel&, ChuFileControlInfoBase&) =
	SetFP(static_cast<CUICheckButtonChargenMageSchool& (CUICheckButtonChargenMageSchool::*)(CPanel&, ChuFileControlInfoBase&)>
																				(&CUICheckButtonChargenMageSchool::Construct),	0x734E97);
unsigned int (CUICheckButtonChargenMageSchool::*CUICheckButtonChargenMageSchool_GetKit)() =
	SetFP(static_cast<unsigned int (CUICheckButtonChargenMageSchool::*)()>		(&CUICheckButtonChargenMageSchool::GetKit),		0x734F4C);
void (CUICheckButtonChargenMageSchool::*CUICheckButtonChargenMageSchool_Deconstruct)() =
	SetFP(static_cast<void (CUICheckButtonChargenMageSchool::*)()>				(&CUICheckButtonChargenMageSchool::Deconstruct),0x73D770);
void (CUICheckButtonChargenMageSchool::*CUICheckButtonChargenMageSchool_OnLClicked)(POINT) =
	SetFP(static_cast<void (CUICheckButtonChargenMageSchool::*)(POINT)>			(&CUICheckButtonChargenMageSchool::OnLClicked),	0x735019);

CUICheckButtonChargenMageSchool::CUICheckButtonChargenMageSchool(CPanel& panel, ChuFileControlInfoBase& controlInfo)
																	{ (this->*CUICheckButtonChargenMageSchool_Construct_2CPanel_ChuFileControlInfoBase)(panel, controlInfo); }
unsigned int CUICheckButtonChargenMageSchool::GetKit()				{ return (this->*CUICheckButtonChargenMageSchool_GetKit)(); }
CUICheckButtonChargenMageSchool::~CUICheckButtonChargenMageSchool()	{ (this->*CUICheckButtonChargenMageSchool_Deconstruct)(); }
void CUICheckButtonChargenMageSchool::OnLClicked(POINT pt)			{ return (this->*CUICheckButtonChargenMageSchool_OnLClicked)(pt); }

//CUICheckButtonChargenMulticlass
CUICheckButtonChargenMulticlass& (CUICheckButtonChargenMulticlass::*CUICheckButtonChargenMulticlass_Construct_2CPanel_ChuFileControlInfoBase)(CPanel&, ChuFileControlInfoBase&) =
	SetFP(static_cast<CUICheckButtonChargenMulticlass& (CUICheckButtonChargenMulticlass::*)(CPanel&, ChuFileControlInfoBase&)>
																				(&CUICheckButtonChargenMulticlass::Construct),		0x7336BA);
unsigned char (CUICheckButtonChargenMulticlass::*CUICheckButtonChargenMulticlass_GetClass)() =
	SetFP(static_cast<unsigned char (CUICheckButtonChargenMulticlass::*)()>		(&CUICheckButtonChargenMulticlass::GetClass),		0x733A11);
void (CUICheckButtonChargenMulticlass::*CUICheckButtonChargenMulticlass_Deconstruct)() =
	SetFP(static_cast<void (CUICheckButtonChargenMulticlass::*)()>				(&CUICheckButtonChargenMulticlass::Deconstruct),	0x73D120);
void (CUICheckButtonChargenMulticlass::*CUICheckButtonChargenMulticlass_OnLClicked)(POINT) =
	SetFP(static_cast<void (CUICheckButtonChargenMulticlass::*)(POINT)>			(&CUICheckButtonChargenMulticlass::OnLClicked),		0x7336EB);

CUICheckButtonChargenMulticlass::CUICheckButtonChargenMulticlass(CPanel& panel, ChuFileControlInfoBase& controlInfo)
																	{ (this->*CUICheckButtonChargenMulticlass_Construct_2CPanel_ChuFileControlInfoBase)(panel, controlInfo); }
unsigned char CUICheckButtonChargenMulticlass::GetClass()			{ return (this->*CUICheckButtonChargenMulticlass_GetClass)(); }
CUICheckButtonChargenMulticlass::~CUICheckButtonChargenMulticlass()	{ (this->*CUICheckButtonChargenMulticlass_Deconstruct)(); }
void CUICheckButtonChargenMulticlass::OnLClicked(POINT pt)			{ return (this->*CUICheckButtonChargenMulticlass_OnLClicked)(pt); }

//CUICheckButtonMageBookContChoice
CUICheckButtonMageBookContChoice& (CUICheckButtonMageBookContChoice::*CUICheckButtonMageBookContChoice_Construct_2CPanel_ChuFileControlInfoBase)(CPanel&, ChuFileControlInfoBase&) =
	SetFP(static_cast<CUICheckButtonMageBookContChoice& (CUICheckButtonMageBookContChoice::*)(CPanel&, ChuFileControlInfoBase&)>
																					(&CUICheckButtonMageBookContChoice::Construct),			0x7C124D);
void (CUICheckButtonMageBookContChoice::*CUICheckButtonMageBookContChoice_Deconstruct)() =
	SetFP(static_cast<void (CUICheckButtonMageBookContChoice::*)()>					(&CUICheckButtonMageBookContChoice::Deconstruct),		0x7C3640);
void (CUICheckButtonMageBookContChoice::*CUICheckButtonMageBookContChoice_OnLMouseBtUp)(POINT) =
	SetFP(static_cast<void (CUICheckButtonMageBookContChoice::*)(POINT)>			(&CUICheckButtonMageBookContChoice::OnLMouseBtUp),		0x7C16FF);
BOOL (CUICheckButtonMageBookContChoice::*CUICheckButtonMageBookContChoice_OnLMouseDblClk)(POINT) =
	SetFP(static_cast<BOOL (CUICheckButtonMageBookContChoice::*)(POINT)>			(&CUICheckButtonMageBookContChoice::OnLMouseDblClk),	0x7C1763);
BOOL (CUICheckButtonMageBookContChoice::*CUICheckButtonMageBookContChoice_Redraw)(BOOL) =
	SetFP(static_cast<BOOL (CUICheckButtonMageBookContChoice::*)(BOOL)>				(&CUICheckButtonMageBookContChoice::Redraw),			0x7C1A4C);
void (CUICheckButtonMageBookContChoice::*CUICheckButtonMageBookContChoice_OnLClicked)(POINT) =
	SetFP(static_cast<void (CUICheckButtonMageBookContChoice::*)(POINT)>			(&CUICheckButtonMageBookContChoice::OnLClicked),		0x7C1304);
void (CUICheckButtonMageBookContChoice::*CUICheckButtonMageBookContChoice_SetSpell)(ResRef, short) =
	SetFP(static_cast<void (CUICheckButtonMageBookContChoice::*)(ResRef, short)>	(&CUICheckButtonMageBookContChoice::SetSpell),			0x7C17C5);
void (CUICheckButtonMageBookContChoice::*CUICheckButtonMageBookContChoice_SetArrowIcon)(BOOL) =
	SetFP(static_cast<void (CUICheckButtonMageBookContChoice::*)(BOOL)>				(&CUICheckButtonMageBookContChoice::SetArrowIcon),		0x7C19E6);

CUICheckButtonMageBookContChoice::CUICheckButtonMageBookContChoice(CPanel& panel, ChuFileControlInfoBase& controlInfo)
																				{ (this->*CUICheckButtonMageBookContChoice_Construct_2CPanel_ChuFileControlInfoBase)(panel, controlInfo); }
CUICheckButtonMageBookContChoice::~CUICheckButtonMageBookContChoice()			{ (this->*CUICheckButtonMageBookContChoice_Deconstruct)(); }
void CUICheckButtonMageBookContChoice::OnLMouseBtUp(POINT pt)					{ return (this->*CUICheckButtonMageBookContChoice_OnLMouseBtUp)(pt); }
BOOL CUICheckButtonMageBookContChoice::OnLMouseDblClk(POINT pt)					{ return (this->*CUICheckButtonMageBookContChoice_OnLMouseDblClk)(pt); }
BOOL CUICheckButtonMageBookContChoice::Redraw(BOOL bForceRedraw)				{ return (this->*CUICheckButtonMageBookContChoice_Redraw)(bForceRedraw); }
void CUICheckButtonMageBookContChoice::OnLClicked(POINT pt)						{ return (this->*CUICheckButtonMageBookContChoice_OnLClicked)(pt); }
void CUICheckButtonMageBookContChoice::SetSpell(ResRef rSpell, short wNumber)	{ return (this->*CUICheckButtonMageBookContChoice_SetSpell)(rSpell, wNumber); }
void CUICheckButtonMageBookContChoice::SetArrowIcon(BOOL bDirection)			{ return (this->*CUICheckButtonMageBookContChoice_SetArrowIcon)(bDirection); }

//CUICheckButtonMageBookContSelected
CUICheckButtonMageBookContSelected& (CUICheckButtonMageBookContSelected::*CUICheckButtonMageBookContSelected_Construct_2CPanel_ChuFileControlInfoBase)(CPanel&, ChuFileControlInfoBase&) =
	SetFP(static_cast<CUICheckButtonMageBookContSelected& (CUICheckButtonMageBookContSelected::*)(CPanel&, ChuFileControlInfoBase&)>
																			(&CUICheckButtonMageBookContSelected::Construct),	0x7C0CAC);
void (CUICheckButtonMageBookContSelected::*CUICheckButtonMageBookContSelected_Deconstruct)() =
	SetFP(static_cast<void (CUICheckButtonMageBookContSelected::*)()>		(&CUICheckButtonMageBookContSelected::Deconstruct),	0x7C34F0);
BOOL (CUICheckButtonMageBookContSelected::*CUICheckButtonMageBookContSelected_Redraw)(BOOL) =
	SetFP(static_cast<BOOL (CUICheckButtonMageBookContSelected::*)(BOOL)>	(&CUICheckButtonMageBookContSelected::Redraw),		0x7C0DC4);
void (CUICheckButtonMageBookContSelected::*CUICheckButtonMageBookContSelected_OnLClicked)(POINT) =
	SetFP(static_cast<void (CUICheckButtonMageBookContSelected::*)(POINT)>	(&CUICheckButtonMageBookContSelected::OnLClicked),	0x7C0D56);
void (CUICheckButtonMageBookContSelected::*CUICheckButtonMageBookContSelected_SetSpell)(ResRef) =
	SetFP(static_cast<void (CUICheckButtonMageBookContSelected::*)(ResRef)>	(&CUICheckButtonMageBookContSelected::SetSpell),	0x7C1053);

CUICheckButtonMageBookContSelected::CUICheckButtonMageBookContSelected(CPanel& panel, ChuFileControlInfoBase& controlInfo)
																			{ (this->*CUICheckButtonMageBookContSelected_Construct_2CPanel_ChuFileControlInfoBase)(panel, controlInfo); }
CUICheckButtonMageBookContSelected::~CUICheckButtonMageBookContSelected()	{ (this->*CUICheckButtonMageBookContSelected_Deconstruct)(); }
BOOL CUICheckButtonMageBookContSelected::Redraw(BOOL bForceRedraw)			{ return (this->*CUICheckButtonMageBookContSelected_Redraw)(bForceRedraw); }
void CUICheckButtonMageBookContSelected::OnLClicked(POINT pt)				{ return (this->*CUICheckButtonMageBookContSelected_OnLClicked)(pt); }
void CUICheckButtonMageBookContSelected::SetSpell(ResRef rSpell)			{ return (this->*CUICheckButtonMageBookContSelected_SetSpell)(rSpell); }

//CUICheckButtonMageBookContSwitch
CUICheckButtonMageBookContSwitch& (CUICheckButtonMageBookContSwitch::*CUICheckButtonMageBookContSwitch_Construct_2CPanel_ChuFileControlInfoBase)(CPanel&, ChuFileControlInfoBase&) =
	SetFP(static_cast<CUICheckButtonMageBookContSwitch& (CUICheckButtonMageBookContSwitch::*)(CPanel&, ChuFileControlInfoBase&)>
																		(&CUICheckButtonMageBookContSwitch::Construct),		0x7C0AEC);
void (CUICheckButtonMageBookContSwitch::*CUICheckButtonMageBookContSwitch_Deconstruct)() =
	SetFP(static_cast<void (CUICheckButtonMageBookContSwitch::*)()>		(&CUICheckButtonMageBookContSwitch::Deconstruct),	0x7C3250);
void (CUICheckButtonMageBookContSwitch::*CUICheckButtonMageBookContSwitch_OnLClicked)(POINT) =
	SetFP(static_cast<void (CUICheckButtonMageBookContSwitch::*)(POINT)>(&CUICheckButtonMageBookContSwitch::OnLClicked),	0x7C0B82);

CUICheckButtonMageBookContSwitch::CUICheckButtonMageBookContSwitch(CPanel& panel, ChuFileControlInfoBase& controlInfo)
																		{ (this->*CUICheckButtonMageBookContSwitch_Construct_2CPanel_ChuFileControlInfoBase)(panel, controlInfo); }
CUICheckButtonMageBookContSwitch::~CUICheckButtonMageBookContSwitch()	{ (this->*CUICheckButtonMageBookContSwitch_Deconstruct)(); }
void CUICheckButtonMageBookContSwitch::OnLClicked(POINT pt)				{ return (this->*CUICheckButtonMageBookContSwitch_OnLClicked)(pt); }

//CUICheckButtonRecMageSpell
CUICheckButtonRecMageSpell& (CUICheckButtonRecMageSpell::*CUICheckButtonRecMageSpell_Construct_2CPanel_ChuFileControlInfoBase)(CPanel&, ChuFileControlInfoBase&) =
	SetFP(static_cast<CUICheckButtonRecMageSpell& (CUICheckButtonRecMageSpell::*)(CPanel&, ChuFileControlInfoBase&)>
																				(&CUICheckButtonRecMageSpell::Construct),		0x6FA496);
void (CUICheckButtonRecMageSpell::*CUICheckButtonRecMageSpell_SetSpell)(ResRef) =
	SetFP(static_cast<void (CUICheckButtonRecMageSpell::*)(ResRef)>				(&CUICheckButtonRecMageSpell::SetSpell),		0x6FA54D);
void (CUICheckButtonRecMageSpell::*CUICheckButtonRecMageSpell_Deconstruct)() =
	SetFP(static_cast<void (CUICheckButtonRecMageSpell::*)()>					(&CUICheckButtonRecMageSpell::Deconstruct),		0x7045C0);
BOOL (CUICheckButtonRecMageSpell::*CUICheckButtonRecMageSpell_Redraw)(BOOL) =
	SetFP(static_cast<BOOL (CUICheckButtonRecMageSpell::*)(BOOL)>				(&CUICheckButtonRecMageSpell::Redraw),			0x6FAF41);
void (CUICheckButtonRecMageSpell::*CUICheckButtonRecMageSpell_OnLClicked)(POINT) =
	SetFP(static_cast<void (CUICheckButtonRecMageSpell::*)(POINT)>				(&CUICheckButtonRecMageSpell::OnLClicked),		0x6FA76B);
void (CUICheckButtonRecMageSpell::*CUICheckButtonRecMageSpell_OnLClickedHLA)(POINT) =
	SetFP(static_cast<void (CUICheckButtonRecMageSpell::*)(POINT)>				(&CUICheckButtonRecMageSpell::OnLClickedHLA),	0x6FA76B);

CUICheckButtonRecMageSpell::CUICheckButtonRecMageSpell(CPanel& panel, ChuFileControlInfoBase& controlInfo)
															{ (this->*CUICheckButtonRecMageSpell_Construct_2CPanel_ChuFileControlInfoBase)(panel, controlInfo); }
void CUICheckButtonRecMageSpell::SetSpell(ResRef rSpell)	{ return (this->*CUICheckButtonRecMageSpell_SetSpell)(rSpell); }
CUICheckButtonRecMageSpell::~CUICheckButtonRecMageSpell()	{ (this->*CUICheckButtonRecMageSpell_Deconstruct)(); }
BOOL CUICheckButtonRecMageSpell::Redraw(BOOL bForceRedraw)	{ return (this->*CUICheckButtonRecMageSpell_Redraw)(bForceRedraw); }
void CUICheckButtonRecMageSpell::OnLClicked(POINT pt)		{ return (this->*CUICheckButtonRecMageSpell_OnLClicked)(pt); }
void CUICheckButtonRecMageSpell::OnLClickedHLA(POINT pt)	{ return (this->*CUICheckButtonRecMageSpell_OnLClickedHLA)(pt); }
