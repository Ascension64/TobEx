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
	virtual void OnLMouseDrag(POINT pt); //v14
	virtual BOOL OnLMouseBtDn(POINT pt); //v18
	virtual void OnLMouseBtUp(POINT pt); //v1c
	virtual BOOL OnLMouseDblClk(POINT pt); //v20
	virtual BOOL OnRMouseBtDn(POINT pt); //v24
	virtual void OnRMouseBtUp(POINT pt); //v28
	virtual void SetRedraw(); //v48
	virtual BOOL Redraw(BOOL bForceRedraw); //v4c
	virtual BOOL NeedsRedraw(); //v58

	virtual void OnLClicked(POINT pt); //v5c
	virtual void OnLDblClicked(POINT pt); //v60
	virtual void OnRClicked(POINT pt); //v64
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
	POINT u62e;
	BOOL bActive; //636h, 0: greyed
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

extern CUIButton& (CUIButton::*CUIButton_Construct_4CPanel_ChuFileControlInfoBase_BYTE_BOOL)(CPanel&, ChuFileControlInfoBase&, char, BOOL);
extern void (CUIButton::*CUIButton_SetActive)(BOOL);
extern void (CUIButton::*CUIButton_Deconstruct)();
extern void (CUIButton::*CUIButton_OnLoseFocus)();
extern void (CUIButton::*CUIButton_OnLMouseDrag)(POINT);
extern BOOL (CUIButton::*CUIButton_OnLMouseBtDn)(POINT);
extern void (CUIButton::*CUIButton_OnLMouseBtUp)(POINT);
extern BOOL (CUIButton::*CUIButton_OnLMouseDblClk)(POINT);
extern BOOL (CUIButton::*CUIButton_OnRMouseBtDn)(POINT);
extern void (CUIButton::*CUIButton_OnRMouseBtUp)(POINT);
extern void (CUIButton::*CUIButton_SetRedraw)();
extern BOOL (CUIButton::*CUIButton_Redraw)(BOOL);
extern BOOL (CUIButton::*CUIButton_NeedsRedraw)();
extern void (CUIButton::*CUIButton_OnLClicked)(POINT);
extern void (CUIButton::*CUIButton_OnLDblClicked)(POINT);
extern void (CUIButton::*CUIButton_OnRClicked)(POINT);
extern void (CUIButton::*CUIButton_SetText)(IECString&);

class CUIButtonChargenPlusMinus : public CUIButton { //Size 654h
//Constructor: 0x6F82C3 (profs), 0x6F889F (thief skills) -> 0x5A3C3A
//Note: for the + and - arrows in proficiencies/thief skills
public:
	//vtable: 0xAADAD0 (profs), 0xAADB40 (thief skills)
	virtual ~CUIButtonChargenPlusMinus(); //v0

	virtual void UpdateCharacter() {} //v6c, called by LMouseBtDn (differs between the two button types)
			
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

	virtual BOOL OnLMouseBtDn(POINT pt); //v18
	virtual BOOL Redraw(BOOL bForceRedraw); //v4c

	virtual void OnLClicked(POINT pt); //v5c
	virtual void OnRClicked(POINT pt); //v64

	ResRef m_rSpell; //650h
	ResRef m_rSpellIcon; //658h
	BOOL u660;
	BOOL u664;
};

extern CUIButtonMageBookKnownSpell& (CUIButtonMageBookKnownSpell::*CUIButtonMageBookKnownSpell_Construct_2CPanel_ChuFileControlInfoBase)(CPanel&, ChuFileControlInfoBase&);
extern void (CUIButtonMageBookKnownSpell::*CUIButtonMageBookKnownSpell_SetSpell)(ResRef&);
extern void (CUIButtonMageBookKnownSpell::*CUIButtonMageBookKnownSpell_Deconstruct)();
extern BOOL (CUIButtonMageBookKnownSpell::*CUIButtonMageBookKnownSpell_OnLMouseBtDn)(POINT);
extern BOOL (CUIButtonMageBookKnownSpell::*CUIButtonMageBookKnownSpell_Redraw)(BOOL);
extern void (CUIButtonMageBookKnownSpell::*CUIButtonMageBookKnownSpell_OnLClicked)(POINT);
extern void (CUIButtonMageBookKnownSpell::*CUIButtonMageBookKnownSpell_OnRClicked)(POINT);

class CUIButtonPriestBookKnownSpell : public CUIButton { //Size 668h
public:
	CUIButtonPriestBookKnownSpell(CPanel& panel, ChuFileControlInfoBase& controlInfo); //788CFF
	CUIButtonPriestBookKnownSpell& Construct(CPanel&, ChuFileControlInfoBase&) { return *this; } //dummy
	void SetSpell(ResRef& rSpell);

	//AB3438
	virtual ~CUIButtonPriestBookKnownSpell(); //v0
	void Deconstruct() {} //dummy

	virtual BOOL OnLMouseBtDn(POINT pt); //v18
	virtual BOOL Redraw(BOOL bForceRedraw); //v4c

	virtual void OnLClicked(POINT pt); //v5c
	virtual void OnRClicked(POINT pt); //v64

	ResRef m_rSpell; //650h
	ResRef m_rSpellIcon; //658h
	BOOL u660;
	BOOL u664;
};

extern CUIButtonPriestBookKnownSpell& (CUIButtonPriestBookKnownSpell::*CUIButtonPriestBookKnownSpell_Construct_2CPanel_ChuFileControlInfoBase)(CPanel&, ChuFileControlInfoBase&);
extern void (CUIButtonPriestBookKnownSpell::*CUIButtonPriestBookKnownSpell_SetSpell)(ResRef&);
extern void (CUIButtonPriestBookKnownSpell::*CUIButtonPriestBookKnownSpell_Deconstruct)();
extern BOOL (CUIButtonPriestBookKnownSpell::*CUIButtonPriestBookKnownSpell_OnLMouseBtDn)(POINT);
extern BOOL (CUIButtonPriestBookKnownSpell::*CUIButtonPriestBookKnownSpell_Redraw)(BOOL);
extern void (CUIButtonPriestBookKnownSpell::*CUIButtonPriestBookKnownSpell_OnLClicked)(POINT);
extern void (CUIButtonPriestBookKnownSpell::*CUIButtonPriestBookKnownSpell_OnRClicked)(POINT);

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

	virtual void OnLClicked(POINT pt); //v5c

	short wFrameOn; //650h
	short wFrameOff; //652h
	BOOL bToggle; //654h
};

extern CUICheckButton& (CUICheckButton::*CUICheckButton_Construct_4CPanel_ChuFileControlInfoBase_BYTE_BOOL)(CPanel&, ChuFileControlInfoBase&, char, BOOL);
extern void (CUICheckButton::*CUICheckButton_Deconstruct)();
extern void (CUICheckButton::*CUICheckButton_SetToggleState)(BOOL);
extern BOOL (CUICheckButton::*CUICheckButton_Redraw)(BOOL);
extern void (CUICheckButton::*CUICheckButton_OnLClicked)(POINT);

class CUICheckButtonChargenClass : public CUICheckButton { //Size 658h
public:
	CUICheckButtonChargenClass(CPanel& panel, ChuFileControlInfoBase& controlInfo); //733AB4
	CUICheckButtonChargenClass& Construct(CPanel&, ChuFileControlInfoBase&) { return *this; } //dummy
	unsigned char GetClass();

	//AAFDD8
	virtual ~CUICheckButtonChargenClass(); //v0
	void Deconstruct() {} //dummy

	virtual void OnLClicked(POINT pt); //v5c
};

extern CUICheckButtonChargenClass& (CUICheckButtonChargenClass::*CUICheckButtonChargenClass_Construct_2CPanel_ChuFileControlInfoBase)(CPanel&, ChuFileControlInfoBase&);
extern unsigned char (CUICheckButtonChargenClass::*CUICheckButtonChargenClass_GetClass)();
extern void (CUICheckButtonChargenClass::*CUICheckButtonChargenClass_Deconstruct)();
extern void (CUICheckButtonChargenClass::*CUICheckButtonChargenClass_OnLClicked)(POINT);

class CUICheckButtonChargenKit : public CUICheckButton { //Size 658h
public:
	CUICheckButtonChargenKit(CPanel& panel, ChuFileControlInfoBase& controlInfo); //73A6B7
	CUICheckButtonChargenKit& Construct(CPanel&, ChuFileControlInfoBase&) { return *this; } //dummy
	unsigned int GetKitId(Object& o);
	STRREF GetKitHelpText(Object& o);

	//AB05E4
	virtual ~CUICheckButtonChargenKit(); //v0
	void Deconstruct() {} //dummy

	virtual void OnLClicked(POINT pt); //v5c
};

extern CUICheckButtonChargenKit& (CUICheckButtonChargenKit::*CUICheckButtonChargenKit_Construct_2CPanel_ChuFileControlInfoBase)(CPanel&, ChuFileControlInfoBase&);
extern unsigned int (CUICheckButtonChargenKit::*CUICheckButtonChargenKit_GetKitId)(Object&);
extern STRREF (CUICheckButtonChargenKit::*CUICheckButtonChargenKit_GetKitHelpText)(Object&);
extern void (CUICheckButtonChargenKit::*CUICheckButtonChargenKit_Deconstruct)();
extern void (CUICheckButtonChargenKit::*CUICheckButtonChargenKit_OnLClicked)(POINT);

class CUICheckButtonChargenMageSchool : public CUICheckButton { //Size 658h
public:
	CUICheckButtonChargenMageSchool(CPanel& panel, ChuFileControlInfoBase& controlInfo); //734E97
	CUICheckButtonChargenMageSchool& Construct(CPanel&, ChuFileControlInfoBase&) { return *this; } //dummy
	unsigned int GetKit();

	//AAFF84
	virtual ~CUICheckButtonChargenMageSchool(); //v0
	void Deconstruct() {} //dummy

	virtual void OnLClicked(POINT pt); //v5c
};

extern CUICheckButtonChargenMageSchool& (CUICheckButtonChargenMageSchool::*CUICheckButtonChargenMageSchool_Construct_2CPanel_ChuFileControlInfoBase)(CPanel&, ChuFileControlInfoBase&);
extern unsigned int (CUICheckButtonChargenMageSchool::*CUICheckButtonChargenMageSchool_GetKit)();
extern void (CUICheckButtonChargenMageSchool::*CUICheckButtonChargenMageSchool_Deconstruct)();
extern void (CUICheckButtonChargenMageSchool::*CUICheckButtonChargenMageSchool_OnLClicked)(POINT);

class CUICheckButtonChargenMulticlass : public CUICheckButton { //Size 658h
public:
	CUICheckButtonChargenMulticlass(CPanel& panel, ChuFileControlInfoBase& controlInfo); //7336BA
	CUICheckButtonChargenMulticlass& Construct(CPanel&, ChuFileControlInfoBase&) { return *this; } //dummy
	unsigned char GetClass();

	//AAFD6C
	virtual ~CUICheckButtonChargenMulticlass(); //v0
	void Deconstruct() {} //dummy

	virtual void OnLClicked(POINT pt); //v5c
};

extern CUICheckButtonChargenMulticlass& (CUICheckButtonChargenMulticlass::*CUICheckButtonChargenMulticlass_Construct_2CPanel_ChuFileControlInfoBase)(CPanel&, ChuFileControlInfoBase&);
extern unsigned char (CUICheckButtonChargenMulticlass::*CUICheckButtonChargenMulticlass_GetClass)();
extern void (CUICheckButtonChargenMulticlass::*CUICheckButtonChargenMulticlass_Deconstruct)();
extern void (CUICheckButtonChargenMulticlass::*CUICheckButtonChargenMulticlass_OnLClicked)(POINT);

class CUICheckButtonChargenMageSpell : public CUICheckButton { //Size 66Eh
//Constructor: 0x7328A0
public:
	//AAFC94
	ResRef m_rSpellIcon; //658h
	ResRef m_rSpell; //660h
	BOOL u668; //grey out?
	short u66c;
};

class CUICheckButtonRecMageSpell : public CUICheckButton { //Size 66Ch
public:
	CUICheckButtonRecMageSpell(CPanel& panel, ChuFileControlInfoBase& controlInfo); //6FA496
	CUICheckButtonRecMageSpell& Construct(CPanel&, ChuFileControlInfoBase&) { return *this; } //dummy
	void SetSpell(ResRef rSpell);

	//AADE3C
	virtual ~CUICheckButtonRecMageSpell(); //v0
	void Deconstruct() {} //dummy
	virtual BOOL Redraw(BOOL bForceRedraw); //v4c

	virtual void OnLClicked(POINT pt); //v5c
	virtual void OnLClickedHLA(POINT pt); //v6c

	ResRef m_rSpellIcon; //658h
	ResRef m_rSpell; //660h
	BOOL u668;
};

extern CUICheckButtonRecMageSpell& (CUICheckButtonRecMageSpell::*CUICheckButtonRecMageSpell_Construct_2CPanel_ChuFileControlInfoBase)(CPanel&, ChuFileControlInfoBase&);
extern void (CUICheckButtonRecMageSpell::*CUICheckButtonRecMageSpell_SetSpell)(ResRef);
extern void (CUICheckButtonRecMageSpell::*CUICheckButtonRecMageSpell_Deconstruct)();
extern BOOL (CUICheckButtonRecMageSpell::*CUICheckButtonRecMageSpell_Redraw)(BOOL);
extern void (CUICheckButtonRecMageSpell::*CUICheckButtonRecMageSpell_OnLClicked)(POINT);
extern void (CUICheckButtonRecMageSpell::*CUICheckButtonRecMageSpell_OnLClickedHLA)(POINT);

#endif //UIBUTTON_H