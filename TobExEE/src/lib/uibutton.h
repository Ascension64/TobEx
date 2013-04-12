//TobExEE
#ifndef UIBUTTON_H
#define UIBUTTON_H

#include "uicore.h"
#include "scrcore.h"

class CUIButton : public CUIControl { //Size 174h
public:
	virtual ~CUIButton(); //v0
	void Deconstruct() {} //dummy

	virtual void OnLoseFocus(); //v10
	virtual void OnLMouseDrag(CPoint pt); //v18
	virtual BOOL OnLMouseBtDn(CPoint pt); //v1c
	virtual void OnLMouseBtUp(CPoint pt); //v20
	virtual BOOL OnLMouseDblClk(CPoint pt); //v24
	virtual BOOL OnRMouseBtDn(CPoint pt); //v28
	virtual void OnRMouseBtUp(CPoint pt); //v2c
	virtual void SetRedraw(); //v54
	virtual BOOL Redraw(BOOL bForceRedraw); //v58
	virtual BOOL NeedsRedraw(); //v64

	virtual void OnLClicked(CPoint pt); //v6c
	virtual void OnLDblClicked(CPoint pt); //v70
	virtual void OnRClicked(CPoint pt); //v74
	virtual void SetText(IECString& sText); //v78
	virtual void v7c() {}
	virtual void v80() {}

	CVidCell m_vid; //54h
	short m_wFrameUp; //118h
	short m_wFrameDn; //11ah
	short m_wFrameOff; //11ch
	short m_wRedrawAmount; //11eh
	BOOL m_bLock; //120h, 1: grabbed by mouse

	//bit0: enable LMB, double-click
	//bit1: enable RMB
	unsigned char m_cFlags; //124h, Arg3
	char p125[3];
	IECString* m_pText; //128h, array of captions (size: m_nTextRows)
	CVidFont m_fnt; //12ch
	CPoint u150;

	BOOL m_bActive; //158h, 0: greyed
	char u15c;
	char p15d[3];
	int u160;
	int u164; 
	unsigned short u168; //more flags, bit8: multi-row text
	char m_cTextRows; //16ah
	char m_cTextFlags; //16bh
	int m_nFramePress; //16ch, stores a short, high char = pressed+1, low char = unpressed+1
	int m_nFrameState; //170h, stores a short, high char = disabled+1, low char = pressed+1
};

class CUIButtonPlusMinus : public CUIButton { //Size 178h
//Note: for the + and - arrows in proficiencies/thief skills
public:
	virtual ~CUIButtonPlusMinus(); //v0

	virtual void OnPlusMinus() {} //v84, called by LMouseBtDn (differs between the two button types)
			
	BOOL m_bLMouseBtState; //174h, 1 = down, 0 = up
};

class CUICheckButton : public CUIButton { //Size 17Ch
public:
	virtual ~CUICheckButton(); //v0
	void Deconstruct() {} //dummy

	virtual BOOL Redraw(BOOL bForceRedraw); //v58
	virtual void OnLClicked(CPoint pt); //v6c

	short m_wFrameOn; //174h
	short m_wFrameOff; //176h
	BOOL m_bToggle; //178h
};

#endif //UIBUTTON_H