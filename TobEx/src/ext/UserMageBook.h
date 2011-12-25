#ifndef USERMAGEBOOK_H
#define USERMAGEBOOK_H

#include "uibutton.h"
#include "engmagebk.h"

extern int CUIButtonMageBook_KnownSpellOffset;

class CUIButtonMageBookUp : public CUIButton {
public:
	CUIButtonMageBookUp(CPanel& panel, ChuFileControlInfoBase& controlInfo);

	virtual ~CUIButtonMageBookUp(); //v0
	virtual void OnLClicked(POINT pt); //v5c
};

class CUIButtonMageBookDn : public CUIButton {
public:
	CUIButtonMageBookDn(CPanel& panel, ChuFileControlInfoBase& controlInfo);

	virtual ~CUIButtonMageBookDn(); //v0
	virtual void OnLClicked(POINT pt); //v5c
};

extern CUICheckButtonMageBookContChoice& (CUICheckButtonMageBookContChoice::*Tramp_CUICheckButtonMageBookContChoice_Construct_2CPanel_ChuFileControlInfoBase)(CPanel&, ChuFileControlInfoBase&);
extern void (CUICheckButtonMageBookContChoice::*Tramp_CUICheckButtonMageBookContChoice_OnLClicked)(POINT);

class DETOUR_CUICheckButtonMageBookContChoice : public CUICheckButtonMageBookContChoice {
public:
	CUICheckButtonMageBookContChoice& DETOUR_Construct(CPanel& panel, ChuFileControlInfoBase& controlInfo);
	void DETOUR_OnLClicked(POINT pt);

	ResRef rParentSpell;
};

extern CUICheckButtonMageBookContSelected& (CUICheckButtonMageBookContSelected::*Tramp_CUICheckButtonMageBookContSelected_Construct_2CPanel_ChuFileControlInfoBase)(CPanel&, ChuFileControlInfoBase&);
extern void (CUICheckButtonMageBookContSelected::*Tramp_CUICheckButtonMageBookContSelected_OnLClicked)(POINT);

class DETOUR_CUICheckButtonMageBookContSelected : public CUICheckButtonMageBookContSelected {
public:
	CUICheckButtonMageBookContSelected& DETOUR_Construct(CPanel& panel, ChuFileControlInfoBase& controlInfo);
	void DETOUR_OnLClicked(POINT pt);

	ResRef rParentSpell;
};

bool __stdcall CMageBook_AddContingencySpellEx(CMageBook* pWiz, IECString sSpell, IECString sParentSpell);

#endif //USERMAGEBOOK_H
