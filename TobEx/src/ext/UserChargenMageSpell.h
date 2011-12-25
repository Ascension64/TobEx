#ifndef USERCHARGENMAGESPELL_H
#define USERCHARGENMAGESPELL_H

#include "uiscroll.h"
#include "cptrlistex.h"

class CUIScrollBarChargenMageSpell : public CUIScrollBar {
public:
	CUIScrollBarChargenMageSpell(CPanel& panel, ChuFileControlInfoBase& controlInfo);
	void UpdatePanel();

	virtual ~CUIScrollBarChargenMageSpell(); //v0
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

#endif //USERCHARGENMAGESPELL_H
