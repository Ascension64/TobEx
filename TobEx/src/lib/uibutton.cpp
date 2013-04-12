#include "uibutton.h"

#include "stdafx.h"

//CUIButton
CUIButton::CUIButton() { SetVT(this, 0xAAAE44); }
DefineLibNoRetFunc(CUIButton&, CUIButton, CUIButton, (
	CPanel& panel,
	ChuFileControlInfoBase& controlInfo,
	char flags,
	BOOL b
	), Construct, Construct4, (panel, controlInfo, flags, b), 0x586570);
DefineLibNoRetFunc(void, CUIButton, ~CUIButton, (), Deconstruct, Deconstruct, (), 0x5A54D0);
DefineLibMemberFunc(void, CUIButton, SetActive, (BOOL b), SetActive, SetActive, (b), 0x587C9D);
DefineLibMemberFunc(void, CUIButton, OnLoseFocus, (), OnLoseFocus, OnLoseFocus, (), 0x586B6A);
DefineLibMemberFunc(void, CUIButton, OnLMouseDrag, (CPoint pt), OnLMouseDrag, OnLMouseDrag, (pt), 0x586BBC);
DefineLibMemberFunc(BOOL, CUIButton, OnLMouseBtDn, (CPoint pt), OnLMouseBtDn, OnLMouseBtDn, (pt), 0x586CFC);
DefineLibMemberFunc(void, CUIButton, OnLMouseBtUp, (CPoint pt), OnLMouseBtUp, OnLMouseBtUp, (pt), 0x586DD7);
DefineLibMemberFunc(BOOL, CUIButton, OnLMouseDblClk, (CPoint pt), OnLMouseDblClk, OnLMouseDblClk, (pt), 0x586F1B);
DefineLibMemberFunc(BOOL, CUIButton, OnRMouseBtDn, (CPoint pt), OnRMouseBtDn, OnRMouseBtDn, (pt), 0x586F66);
DefineLibMemberFunc(void, CUIButton, OnRMouseBtUp, (CPoint pt), OnRMouseBtUp, OnRMouseBtUp, (pt), 0x587041);
DefineLibMemberFunc(void, CUIButton, SetRedraw, (), SetRedraw, SetRedraw, (), 0x587C04);
DefineLibMemberFunc(BOOL, CUIButton, Redraw, (BOOL bForceRedraw), Redraw, Redraw, (bForceRedraw), 0x587101);
DefineLibMemberFunc(BOOL, CUIButton, NeedsRedraw, (), NeedsRedraw, NeedsRedraw, (), 0x586B27);
DefineLibMemberFunc(void, CUIButton, OnLClicked, (CPoint pt), OnLClicked, OnLClicked, (pt), 0x5A55F0);
DefineLibMemberFunc(void, CUIButton, OnLDblClicked, (CPoint pt), OnLDblClicked, OnLDblClicked, (pt), 0x5A5600);
DefineLibMemberFunc(void, CUIButton, OnRClicked, (CPoint pt), OnRClicked, OnRClicked, (pt), 0x5A5610);
DefineLibMemberFunc(void, CUIButton, SetText, (IECString& sText), SetText, SetText, (sText), 0x587DF2);

//CUIButtonMageBookKnownSpell
DefineLibNoRetFunc(CUIButtonMageBookKnownSpell&, CUIButtonMageBookKnownSpell, CUIButtonMageBookKnownSpell, (CPanel& panel, ChuFileControlInfoBase& controlInfo), Construct, Construct2, (panel, controlInfo), 0x7BE8AE);
DefineLibMemberFunc(void, CUIButtonMageBookKnownSpell, SetSpell, (ResRef& rSpell), SetSpell, SetSpell, (rSpell), 0x7BE9E2);
DefineLibNoRetFunc(void, CUIButtonMageBookKnownSpell, ~CUIButtonMageBookKnownSpell, (), Deconstruct, Deconstruct, (), 0x7C2A70);
DefineLibMemberFunc(BOOL, CUIButtonMageBookKnownSpell, OnLMouseBtDn, (CPoint pt), OnLMouseBtDn, OnLMouseBtDn, (pt), 0x7BEBFB);
DefineLibMemberFunc(BOOL, CUIButtonMageBookKnownSpell, Redraw, (BOOL bForceRedraw), Redraw, Redraw, (bForceRedraw), 0x7BF1AF);
DefineLibMemberFunc(void, CUIButtonMageBookKnownSpell, OnLClicked, (CPoint pt), OnLClicked, OnLClicked, (pt), 0x7BECB9);
DefineLibMemberFunc(void, CUIButtonMageBookKnownSpell, OnRClicked, (CPoint pt), OnRClicked, OnRClicked, (pt), 0x7BF0B8);

//CUIButtonPriestBookKnownSpell
DefineLibNoRetFunc(CUIButtonPriestBookKnownSpell&, CUIButtonPriestBookKnownSpell, CUIButtonPriestBookKnownSpell, (CPanel& panel, ChuFileControlInfoBase& controlInfo), Construct, Construct2, (panel, controlInfo), 0x788CFF);
DefineLibMemberFunc(void, CUIButtonPriestBookKnownSpell, SetSpell, (ResRef& rSpell), SetSpell, SetSpell, (rSpell), 0x788E33);
DefineLibNoRetFunc(void, CUIButtonPriestBookKnownSpell, ~CUIButtonPriestBookKnownSpell, (), Deconstruct, Deconstruct, (), 0x78AC90);
DefineLibMemberFunc(BOOL, CUIButtonPriestBookKnownSpell, OnLMouseBtDn, (CPoint pt), OnLMouseBtDn, OnLMouseBtDn, (pt), 0x78903D);
DefineLibMemberFunc(BOOL, CUIButtonPriestBookKnownSpell, Redraw, (BOOL bForceRedraw), Redraw, Redraw, (bForceRedraw), 0x789578);
DefineLibMemberFunc(void, CUIButtonPriestBookKnownSpell, OnLClicked, (CPoint pt), OnLClicked, OnLClicked, (pt), 0x7890FB);
DefineLibMemberFunc(void, CUIButtonPriestBookKnownSpell, OnRClicked, (CPoint pt), OnRClicked, OnRClicked, (pt), 0x789496);

//CUICheckButton
CUICheckButton::CUICheckButton() { SetVT(this, 0xAAAEB0); }
DefineLibNoRetFunc(CUICheckButton&, CUICheckButton, CUICheckButton, (
	CPanel& panel,
	ChuFileControlInfoBase& controlInfo,
	char flags,
	BOOL b
	), Construct, Construct4, (panel, controlInfo, flags, b), 0x587FB2);
DefineLibNoRetFunc(void, CUICheckButton, ~CUICheckButton, (), Deconstruct, Deconstruct, (), 0x5A4A30);
DefineLibMemberFunc(void, CUICheckButton, SetToggleState, (BOOL b), SetToggleState, SetToggleState, (b), 0x588010);
DefineLibMemberFunc(BOOL, CUICheckButton, Redraw, (BOOL bForceRedraw), Redraw, Redraw, (bForceRedraw), 0x588067);
DefineLibMemberFunc(void, CUICheckButton, OnLClicked, (CPoint pt), OnLClicked, OnLClicked, (pt), 0x588042);

//CUICheckButtonChargenClass
DefineLibNoRetFunc(CUICheckButtonChargenClass&, CUICheckButtonChargenClass, CUICheckButtonChargenClass, (CPanel& panel, ChuFileControlInfoBase& controlInfo), Construct, Construct2, (panel, controlInfo), 0x733AB4);
DefineLibMemberFunc(unsigned char, CUICheckButtonChargenClass, GetClass, (), GetClass, GetClass, (), 0x73402E);
DefineLibNoRetFunc(void, CUICheckButtonChargenClass, ~CUICheckButtonChargenClass, (), Deconstruct, Deconstruct, (), 0x73D270);
DefineLibMemberFunc(void, CUICheckButtonChargenClass, OnLClicked, (CPoint pt), OnLClicked, OnLClicked, (pt), 0x733B95);

//CUICheckButtonChargenKit
DefineLibNoRetFunc(CUICheckButtonChargenKit&, CUICheckButtonChargenKit, CUICheckButtonChargenKit, (CPanel& panel, ChuFileControlInfoBase& controlInfo), Construct, Construct2, (panel, controlInfo), 0x73A6B7);
DefineLibMemberFunc(unsigned int, CUICheckButtonChargenKit, GetKitId, (Object& o), GetKitId, GetKitId, (o), 0x73A6E8);
DefineLibMemberFunc(STRREF, CUICheckButtonChargenKit, GetKitHelpText, (Object& o), GetKitHelpText, GetKitHelpText, (o), 0x73A84E);
DefineLibNoRetFunc(void, CUICheckButtonChargenKit, ~CUICheckButtonChargenKit, (), Deconstruct, Deconstruct, (), 0x73E3E0);
DefineLibMemberFunc(void, CUICheckButtonChargenKit, OnLClicked, (CPoint pt), OnLClicked, OnLClicked, (pt), 0x73ABDF);

//CUICheckButtonChargenMageSchool
DefineLibNoRetFunc(CUICheckButtonChargenMageSchool&, CUICheckButtonChargenMageSchool, CUICheckButtonChargenMageSchool, (CPanel& panel, ChuFileControlInfoBase& controlInfo), Construct, Construct2, (panel, controlInfo), 0x734E97);
DefineLibMemberFunc(unsigned int, CUICheckButtonChargenMageSchool, GetKit, (), GetKit, GetKit, (), 0x734F4C);
DefineLibNoRetFunc(void, CUICheckButtonChargenMageSchool, ~CUICheckButtonChargenMageSchool, (), Deconstruct, Deconstruct, (), 0x73D770);
DefineLibMemberFunc(void, CUICheckButtonChargenMageSchool, OnLClicked, (CPoint pt), OnLClicked, OnLClicked, (pt), 0x735019);

//CUICheckButtonChargenMulticlass
DefineLibNoRetFunc(CUICheckButtonChargenMulticlass&, CUICheckButtonChargenMulticlass, CUICheckButtonChargenMulticlass, (CPanel& panel, ChuFileControlInfoBase& controlInfo), Construct, Construct2, (panel, controlInfo), 0x7336BA);
DefineLibMemberFunc(unsigned char, CUICheckButtonChargenMulticlass, GetClass, (), GetClass, GetClass, (), 0x733A11);
DefineLibNoRetFunc(void, CUICheckButtonChargenMulticlass, ~CUICheckButtonChargenMulticlass, (), Deconstruct, Deconstruct, (), 0x73D120);
DefineLibMemberFunc(void, CUICheckButtonChargenMulticlass, OnLClicked, (CPoint pt), OnLClicked, OnLClicked, (pt), 0x7336EB);

//CUICheckButtonMageBookContChoice
DefineLibNoRetFunc(CUICheckButtonMageBookContChoice&, CUICheckButtonMageBookContChoice, CUICheckButtonMageBookContChoice, (CPanel& panel, ChuFileControlInfoBase& controlInfo), Construct, Construct2, (panel, controlInfo), 0x7C124D);
DefineLibNoRetFunc(void, CUICheckButtonMageBookContChoice, ~CUICheckButtonMageBookContChoice, (), Deconstruct, Deconstruct, (), 0x7C3640);
DefineLibMemberFunc(void, CUICheckButtonMageBookContChoice, OnLMouseBtUp, (CPoint pt), OnLMouseBtUp, OnLMouseBtUp, (pt), 0x7C16FF);
DefineLibMemberFunc(BOOL, CUICheckButtonMageBookContChoice, OnLMouseDblClk, (CPoint pt), OnLMouseDblClk, OnLMouseDblClk, (pt), 0x7C1763);
DefineLibMemberFunc(BOOL, CUICheckButtonMageBookContChoice, Redraw, (BOOL bForceRedraw), Redraw, Redraw, (bForceRedraw), 0x7C1A4C);
DefineLibMemberFunc(void, CUICheckButtonMageBookContChoice, OnLClicked, (CPoint pt), OnLClicked, OnLClicked, (pt), 0x7C1304);
DefineLibMemberFunc(void, CUICheckButtonMageBookContChoice, SetSpell, (ResRef rSpell, short wNumber), SetSpell, SetSpell, (rSpell, wNumber), 0x7C17C5);
DefineLibMemberFunc(void, CUICheckButtonMageBookContChoice, SetArrowIcon, (BOOL bDirection), SetArrowIcon, SetArrowIcon, (bDirection), 0x7C19E6);

//CUICheckButtonMageBookContSelected
DefineLibNoRetFunc(CUICheckButtonMageBookContSelected&, CUICheckButtonMageBookContSelected, CUICheckButtonMageBookContSelected, (CPanel& panel, ChuFileControlInfoBase& controlInfo), Construct, Construct2, (panel, controlInfo), 0x7C0CAC);
DefineLibNoRetFunc(void, CUICheckButtonMageBookContSelected, ~CUICheckButtonMageBookContSelected, (), Deconstruct, Deconstruct, (), 0x7C34F0);
DefineLibMemberFunc(BOOL, CUICheckButtonMageBookContSelected, Redraw, (BOOL bForceRedraw), Redraw, Redraw, (bForceRedraw), 0x7C0DC4);
DefineLibMemberFunc(void, CUICheckButtonMageBookContSelected, OnLClicked, (CPoint pt), OnLClicked, OnLClicked, (pt), 0x7C0D56);
DefineLibMemberFunc(void, CUICheckButtonMageBookContSelected, SetSpell, (ResRef rSpell), SetSpell, SetSpell, (rSpell), 0x7C1053);

//CUICheckButtonMageBookContSwitch
DefineLibNoRetFunc(CUICheckButtonMageBookContSwitch&, CUICheckButtonMageBookContSwitch, CUICheckButtonMageBookContSwitch, (CPanel& panel, ChuFileControlInfoBase& controlInfo), Construct, Construct2, (panel, controlInfo), 0x7C0AEC);
DefineLibNoRetFunc(void, CUICheckButtonMageBookContSwitch, ~CUICheckButtonMageBookContSwitch, (), Deconstruct, Deconstruct, (), 0x7C3250);
DefineLibMemberFunc(void, CUICheckButtonMageBookContSwitch, OnLClicked, (CPoint pt), OnLClicked, OnLClicked, (pt), 0x7C0B82);

//CUICheckButtonRecMageSpell
DefineLibNoRetFunc(CUICheckButtonRecMageSpell&, CUICheckButtonRecMageSpell, CUICheckButtonRecMageSpell, (CPanel& panel, ChuFileControlInfoBase& controlInfo), Construct, Construct2, (panel, controlInfo), 0x6FA496);
DefineLibMemberFunc(void, CUICheckButtonRecMageSpell, SetSpell, (ResRef rSpell), SetSpell, SetSpell, (rSpell), 0x6FA54D);
DefineLibNoRetFunc(void, CUICheckButtonRecMageSpell, ~CUICheckButtonRecMageSpell, (), Deconstruct, Deconstruct, (), 0x7045C0);
DefineLibMemberFunc(BOOL, CUICheckButtonRecMageSpell, Redraw, (BOOL bForceRedraw), Redraw, Redraw, (bForceRedraw), 0x6FAF41);
DefineLibMemberFunc(void, CUICheckButtonRecMageSpell, OnLClicked, (CPoint pt), OnLClicked, OnLClicked, (pt), 0x6FA76B);
DefineLibMemberFunc(void, CUICheckButtonRecMageSpell, OnLClickedHLA, (CPoint pt), OnLClickedHLA, OnLClickedHLA, (pt), 0x6FA76B);
