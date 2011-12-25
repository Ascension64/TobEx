#ifndef USERRECMAGESPELL_H
#define USERRECMAGESPELL_H

#include "uiscroll.h"

class CUIScrollBarRecMageSpell : public CUIScrollBar {
public:
	CUIScrollBarRecMageSpell(CPanel&, ChuFileControlInfoBase&);
	void UpdatePanel();

	virtual ~CUIScrollBarRecMageSpell(); //v0
	virtual void OnMouseDragKnob(void); //v60
	virtual void OnLMouseBtnDnArrowUp(void); //v64
	virtual void OnLMouseBtnDnArrowDn(void); //v68
	virtual void OnLClickedAboveKnob(DWORD); //v70
	virtual void OnLClickedBelowKnob(DWORD); //v74

	//members
	short nCurrentValue;
	short nValues;
	int nRows;
	CPtrList cplTempSpells;
};

#endif //USERRECMAGESPELL_H
