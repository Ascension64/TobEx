#ifndef USERMAGEBOOK_H
#define USERMAGEBOOK_H

#include "uibutton.h"

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

#endif //USERMAGEBOOK_H
