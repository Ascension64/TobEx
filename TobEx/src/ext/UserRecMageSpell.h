#ifndef USERRECMAGESPELL_H
#define USERRECMAGESPELL_H

#include "uiscroll.h"

class CUIScrollBarRecMageSpell : public CUIScrollBar {
public:
	CUIScrollBarRecMageSpell(CPanel& panel, ChuFileControlInfoBase& controlInfo);
	void UpdatePanel();

	virtual ~CUIScrollBarRecMageSpell(); //v0
	virtual void OnMouseDragKnob(); //v60
	virtual void OnLMouseBtnDnArrowUp(); //v64
	virtual void OnLMouseBtnDnArrowDn(); //v68
	virtual void OnLClickedAboveKnob(short interval); //v70
	virtual void OnLClickedBelowKnob(short interval); //v74

	short nCurrentValue;
	short nValues;
	short nRows;
	IECPtrList cplTempSpells;
};

#endif //USERRECMAGESPELL_H
