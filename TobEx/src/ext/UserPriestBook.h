#ifndef USERPRIESTBOOK_H
#define USERPRIESTBOOK_H

#include "uibutton.h"

extern int CUIButtonPriestBook_KnownSpellOffset;

class CUIButtonPriestBookUp : public CUIButton {
public:
	CUIButtonPriestBookUp(CPanel& panel, ChuFileControlInfoBase& controlInfo);

	virtual ~CUIButtonPriestBookUp(); //v0
	virtual void OnLClicked(POINT pt); //v5c
};

class CUIButtonPriestBookDn : public CUIButton {
public:
	CUIButtonPriestBookDn(CPanel& panel, ChuFileControlInfoBase& controlInfo);

	virtual ~CUIButtonPriestBookDn(); //v0
	virtual void OnLClicked(POINT pt); //v5c
};

#endif //USERPRIESTBOOK_H
