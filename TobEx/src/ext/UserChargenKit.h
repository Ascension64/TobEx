#ifndef USERCHARGENKIT_H
#define USERCHARGENKIT_H

#include "uiscroll.h"

class CUIScrollBarChargenKit : public CUIScrollBar {
public:
	CUIScrollBarChargenKit(CPanel&, ChuFileControlInfoBase&);
	void UpdatePanel();

	virtual ~CUIScrollBarChargenKit(); //v0
	virtual void OnMouseDragKnob(void); //v60
	virtual void OnLMouseBtnDnArrowUp(void); //v64
	virtual void OnLMouseBtnDnArrowDn(void); //v68
	virtual void OnLClickedAboveKnob(DWORD); //v70
	virtual void OnLClickedBelowKnob(DWORD); //v74

	//members
	short nCurrentValue;
	short nValues;
	int nRows;
};

#endif //USERCHARGENKIT_H
