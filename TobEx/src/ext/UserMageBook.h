#ifndef USERMAGEBOOK_H
#define USERMAGEBOOK_H

#include "uibutton.h"
#include "engmagebk.h"

extern int CUIButtonMageBook_KnownSpellOffset;

class CUIButtonMageBookUp : public CUIButton {
public:
	CUIButtonMageBookUp(CPanel& panel, ChuFileControlInfoBase& controlInfo);

	virtual ~CUIButtonMageBookUp(); //v0
	virtual void OnLClicked(CPoint pt); //v5c
};

class CUIButtonMageBookDn : public CUIButton {
public:
	CUIButtonMageBookDn(CPanel& panel, ChuFileControlInfoBase& controlInfo);

	virtual ~CUIButtonMageBookDn(); //v0
	virtual void OnLClicked(CPoint pt); //v5c
};

//CUICheckButtonMageBookContChoice
DeclareTrampMemberFunc(CUICheckButtonMageBookContChoice&, CUICheckButtonMageBookContChoice, Construct, (CPanel& panel, ChuFileControlInfoBase& controlInfo), Construct2);
DeclareTrampMemberFunc(void, CUICheckButtonMageBookContChoice, OnLClicked, (CPoint pt), OnLClicked);

class DETOUR_CUICheckButtonMageBookContChoice : public CUICheckButtonMageBookContChoice {
public:
	CUICheckButtonMageBookContChoice& DETOUR_Construct(CPanel& panel, ChuFileControlInfoBase& controlInfo);
	void DETOUR_OnLClicked(CPoint pt);

	ResRef rParentSpell;
};

//CUICheckButtonMageBookContSelected
DeclareTrampMemberFunc(CUICheckButtonMageBookContSelected&, CUICheckButtonMageBookContSelected, Construct, (CPanel& panel, ChuFileControlInfoBase& controlInfo), Construct2);
DeclareTrampMemberFunc(void, CUICheckButtonMageBookContSelected, OnLClicked, (CPoint pt), OnLClicked);

class DETOUR_CUICheckButtonMageBookContSelected : public CUICheckButtonMageBookContSelected {
public:
	CUICheckButtonMageBookContSelected& DETOUR_Construct(CPanel& panel, ChuFileControlInfoBase& controlInfo);
	void DETOUR_OnLClicked(CPoint pt);

	ResRef rParentSpell;
};

bool __stdcall CScreenMageBook_AddContingencySpellEx(CScreenMageBook* pWiz, IECString sSpell, IECString sParentSpell);

#endif //USERMAGEBOOK_H
