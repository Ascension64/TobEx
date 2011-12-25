#ifndef USERPRIESTBOOK_H
#define USERPRIESTBOOK_H

#include "uibutton.h"

extern int CUIButtonPriestBook_KnownSpellOffset;

class CUIButtonPriestBookUp : public CUIButton {
public:
	CUIButtonPriestBookUp(CPanel&, ChuFileControlInfoBase&);

	virtual ~CUIButtonPriestBookUp(); //v0
	virtual void OnLClicked(POINT); //v5c
};

class CUIButtonPriestBookDn : public CUIButton {
public:
	CUIButtonPriestBookDn(CPanel&, ChuFileControlInfoBase&);

	virtual ~CUIButtonPriestBookDn(); //v0
	virtual void OnLClicked(POINT); //v5c
};

#endif //USERPRIESTBOOK_H
