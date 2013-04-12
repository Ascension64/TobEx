#ifndef UIBUTTON_H
#define UIBUTTON_H

#include "uicore.h"
#include "scrcore.h"

class CUIButton : public CUIControl { //Size 650h
public:
	CUIButton();
	CUIButton(CPanel& panel, ChuFileControlInfoBase& controlInfo, char flags, BOOL b); //586570
	CUIButton& Construct(CPanel&, ChuFileControlInfoBase&, char, BOOL) { return *this; } //dummy
	void SetActive(BOOL b);

	//AAAE44
	virtual ~CUIButton(); //v0
	void Deconstruct() {} //dummy

	virtual void OnLoseFocus(); //vc
	virtual void OnLMouseDrag(CPoint pt); //v14
	virtual BOOL OnLMouseBtDn(CPoint pt); //v18
	virtual void OnLMouseBtUp(CPoint pt); //v1c
	virtual BOOL OnLMouseDblClk(CPoint pt); //v20
	virtual BOOL OnRMouseBtDn(CPoint pt); //v24
	virtual void OnRMouseBtUp(CPoint pt); //v28
	virtual void SetRedraw(); //v48
	virtual BOOL Redraw(BOOL bForceRedraw); //v4c
	virtual BOOL NeedsRedraw(); //v58

	virtual void OnLClicked(CPoint pt); //v5c
	virtual void OnLDblClicked(CPoint pt); //v60
	virtual void OnRClicked(CPoint pt); //v64
	virtual void SetText(IECString& sText); //v68

	CVidCell vc; //4ah
	short wFrameUp; //120h
	short wFrameDn; //122h
	short wFrameOff; //124h
	short wRedrawAmount; //126h
	BOOL bLock; //128h, 1: grabbed by mouse

	//bit0: enable LMB, double-click
	//bit1: enable RMB
	unsigned char m_flags; //12ch, Arg3
	char u12d;
	IECString* m_pText; //12eh, array of captions (size: m_nTextRows)
	CVidFont vf; //132h
	CPoint u62e;
	BOOL m_bActive; //636h, 0: greyed
	char u63a;
	char u63b; //pad
	int u63c;
	int u640; 
	unsigned short u644; //more flags, bit8: multi-row text
	char m_nTextRows; //646h
	char m_TextFlags; //647h
	int framePress; //stores a short, high char = pressed+1, low char = unpressed+1
	int frameState; //stores a short, high char = disabled+1, low char = pressed+1
};

class CUIButtonPlusMinus : public CUIButton { //Size 654h
//Constructor: 0x6F82C3 (profs), 0x6F889F (thief skills) -> 0x5A3C3A
//Note: for the + and - arrows in proficiencies/thief skills
public:
	//vtable: 0xAADAD0 (profs), 0xAADB40 (thief skills)
	virtual ~CUIButtonPlusMinus(); //v0

	virtual void OnPlusMinus() {} //v6c, called by LMouseBtDn (differs between the two button types)
			
	BOOL m_bLMouseBtState; //650h, 1 = down, 0 = up
};

class CUIButtonMageBookKnownSpell : public CUIButton { //Size 668h
public:
	CUIButtonMageBookKnownSpell(CPanel& panel, ChuFileControlInfoBase& controlInfo); //7BE8AE
	CUIButtonMageBookKnownSpell& Construct(CPanel&, ChuFileControlInfoBase&) { return *this; } //dummy
	void SetSpell(ResRef& rSpell);

	//AB4FC8
	virtual ~CUIButtonMageBookKnownSpell(); //v0
	void Deconstruct() {} //dummy

	virtual BOOL OnLMouseBtDn(CPoint pt); //v18
	virtual BOOL Redraw(BOOL bForceRedraw); //v4c

	virtual void OnLClicked(CPoint pt); //v5c
	virtual void OnRClicked(CPoint pt); //v64

	ResRef m_rSpell; //650h
	ResRef m_rSpellIcon; //658h
	BOOL u660;
	BOOL u664;
};

class CUIButtonPriestBookKnownSpell : public CUIButton { //Size 668h
public:
	CUIButtonPriestBookKnownSpell(CPanel& panel, ChuFileControlInfoBase& controlInfo); //788CFF
	CUIButtonPriestBookKnownSpell& Construct(CPanel&, ChuFileControlInfoBase&) { return *this; } //dummy
	void SetSpell(ResRef& rSpell);

	//AB3438
	virtual ~CUIButtonPriestBookKnownSpell(); //v0
	void Deconstruct() {} //dummy

	virtual BOOL OnLMouseBtDn(CPoint pt); //v18
	virtual BOOL Redraw(BOOL bForceRedraw); //v4c

	virtual void OnLClicked(CPoint pt); //v5c
	virtual void OnRClicked(CPoint pt); //v64

	ResRef m_rSpell; //650h
	ResRef m_rSpellIcon; //658h
	BOOL u660;
	BOOL u664;
};

class CUICheckButton : public CUIButton { //Size 658h
public:
	CUICheckButton();
	CUICheckButton(CPanel& panel, ChuFileControlInfoBase& controlInfo, char flags, BOOL b); //587FB2
	CUICheckButton& Construct(CPanel&, ChuFileControlInfoBase&, char, BOOL) { return *this; } //dummy
	void SetToggleState(BOOL b);

	//AAAEB0
	virtual ~CUICheckButton(); //v0
	void Deconstruct() {} //dummy
	virtual BOOL Redraw(BOOL bForceRedraw); //v4c

	virtual void OnLClicked(CPoint pt); //v5c

	short wFrameOn; //650h
	short wFrameOff; //652h
	BOOL bToggle; //654h
};

class CUICheckButtonChargenClass : public CUICheckButton { //Size 658h
public:
	CUICheckButtonChargenClass(CPanel& panel, ChuFileControlInfoBase& controlInfo); //733AB4
	CUICheckButtonChargenClass& Construct(CPanel&, ChuFileControlInfoBase&) { return *this; } //dummy
	unsigned char GetClass();

	//AAFDD8
	virtual ~CUICheckButtonChargenClass(); //v0
	void Deconstruct() {} //dummy

	virtual void OnLClicked(CPoint pt); //v5c
};

class CUICheckButtonChargenKit : public CUICheckButton { //Size 658h
public:
	CUICheckButtonChargenKit(CPanel& panel, ChuFileControlInfoBase& controlInfo); //73A6B7
	CUICheckButtonChargenKit& Construct(CPanel&, ChuFileControlInfoBase&) { return *this; } //dummy
	unsigned int GetKitId(Object& o);
	STRREF GetKitHelpText(Object& o);

	//AB05E4
	virtual ~CUICheckButtonChargenKit(); //v0
	void Deconstruct() {} //dummy

	virtual void OnLClicked(CPoint pt); //v5c
};

class CUICheckButtonChargenMageSchool : public CUICheckButton { //Size 658h
public:
	CUICheckButtonChargenMageSchool(CPanel& panel, ChuFileControlInfoBase& controlInfo); //734E97
	CUICheckButtonChargenMageSchool& Construct(CPanel&, ChuFileControlInfoBase&) { return *this; } //dummy
	unsigned int GetKit();

	//AAFF84
	virtual ~CUICheckButtonChargenMageSchool(); //v0
	void Deconstruct() {} //dummy

	virtual void OnLClicked(CPoint pt); //v5c
};

class CUICheckButtonChargenMulticlass : public CUICheckButton { //Size 658h
public:
	CUICheckButtonChargenMulticlass(CPanel& panel, ChuFileControlInfoBase& controlInfo); //7336BA
	CUICheckButtonChargenMulticlass& Construct(CPanel&, ChuFileControlInfoBase&) { return *this; } //dummy
	unsigned char GetClass();

	//AAFD6C
	virtual ~CUICheckButtonChargenMulticlass(); //v0
	void Deconstruct() {} //dummy

	virtual void OnLClicked(CPoint pt); //v5c
};

class CUICheckButtonChargenMageSpell : public CUICheckButton { //Size 66Eh
//Constructor: 0x7328A0
public:
	//AAFC94
	ResRef m_rSpellIcon; //658h
	ResRef m_rSpell; //660h
	BOOL u668; //grey out?
	short u66c;
};

class CUICheckButtonMageBookContChoice : public CUICheckButton { //Size 66Eh
public:
	CUICheckButtonMageBookContChoice(CPanel& panel, ChuFileControlInfoBase& controlInfo); //7C124D
	CUICheckButtonMageBookContChoice& Construct(CPanel&, ChuFileControlInfoBase&) { return *this; } //dummy
	void SetSpell(ResRef rSpell, short wNumber);
	void SetArrowIcon(BOOL bDirection);

	//AB5394
	virtual ~CUICheckButtonMageBookContChoice(); //v0
	void Deconstruct() {} //dummy
	virtual void OnLMouseBtUp(CPoint pt); //v1c
	virtual BOOL OnLMouseDblClk(CPoint pt); //v20
	virtual BOOL Redraw(BOOL bForceRedraw); //v4c

	virtual void OnLClicked(CPoint pt); //v5c

	short wNumber; //658h
	ResRef rIcon; //65ah
	ResRef rSpell; //662h
	int nArrowDirection; //66ah, 0: no arrow, -1: left arrow, 1: right arrow
};

class CUICheckButtonMageBookContSelected : public CUICheckButton { //Size 668h
public:
	CUICheckButtonMageBookContSelected(CPanel& panel, ChuFileControlInfoBase& controlInfo); //7C0CAC
	CUICheckButtonMageBookContSelected& Construct(CPanel& panel, ChuFileControlInfoBase& controlInfo) { return *this; } //dummy
	void SetSpell(ResRef rSpell);

	//AB5328
	virtual ~CUICheckButtonMageBookContSelected(); //v0
	void Deconstruct() {} //dummy
	virtual BOOL Redraw(BOOL bForceRedraw); //v4c

	virtual void OnLClicked(CPoint pt); //v5c

	ResRef rIcon; //658h
	ResRef rSpell; //660h
};

class CUICheckButtonMageBookContSwitch : public CUICheckButton { //Size 658h
public:
	CUICheckButtonMageBookContSwitch(CPanel& panel, ChuFileControlInfoBase& controlInfo); //7C0AEC
	CUICheckButtonMageBookContSwitch& Construct(CPanel&, ChuFileControlInfoBase&) { return *this; } //dummy

	//AB5250
	virtual ~CUICheckButtonMageBookContSwitch(); //v0
	void Deconstruct() {} //dummy

	virtual void OnLClicked(CPoint pt); //v5c
};

class CUICheckButtonRecMageSpell : public CUICheckButton { //Size 66Ch
public:
	CUICheckButtonRecMageSpell(CPanel& panel, ChuFileControlInfoBase& controlInfo); //6FA496
	CUICheckButtonRecMageSpell& Construct(CPanel& panel, ChuFileControlInfoBase& controlInfo) { return *this; } //dummy
	void SetSpell(ResRef rSpell);

	//AADE3C
	virtual ~CUICheckButtonRecMageSpell(); //v0
	void Deconstruct() {} //dummy
	virtual BOOL Redraw(BOOL bForceRedraw); //v4c

	virtual void OnLClicked(CPoint pt); //v5c
	virtual void OnLClickedHLA(CPoint pt); //v6c

	ResRef m_rSpellIcon; //658h
	ResRef m_rSpell; //660h
	BOOL u668;
};

#endif //UIBUTTON_H