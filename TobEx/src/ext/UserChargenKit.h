#ifndef USERCHARGENKIT_H
#define USERCHARGENKIT_H

#include "uiscroll.h"

class CUIScrollBarChargenKit : public CUIScrollBar {
public:
	CUIScrollBarChargenKit(CPanel& panel, ChuFileControlInfoBase& controlInfo);
	void UpdatePanel();

	virtual ~CUIScrollBarChargenKit(); //v0
	virtual void OnMouseDragKnob(); //v60
	virtual void OnLMouseBtnDnArrowUp(); //v64
	virtual void OnLMouseBtnDnArrowDn(); //v68
	virtual void OnLClickedAboveKnob(short interval); //v70
	virtual void OnLClickedBelowKnob(short interval); //v74

	short nCurrentValue;
	short nValues;
	short nRows;
};

#endif //USERCHARGENKIT_H
