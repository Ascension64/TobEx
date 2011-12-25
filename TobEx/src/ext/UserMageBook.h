#ifndef USERMAGEBOOK_H
#define USERMAGEBOOK_H

#include "uibutton.h"

extern int CUIButtonMageBook_KnownSpellOffset;

class CUIButtonMageBookUp : public CUIButton {
public:
	CUIButtonMageBookUp(CPanel&, ChuFileControlInfoBase&);

	virtual ~CUIButtonMageBookUp(); //v0
	virtual void OnLClicked(POINT); //v5c
};

class CUIButtonMageBookDn : public CUIButton {
public:
	CUIButtonMageBookDn(CPanel&, ChuFileControlInfoBase&);

	virtual ~CUIButtonMageBookDn(); //v0
	virtual void OnLClicked(POINT); //v5c
};

#endif //USERMAGEBOOK_H
