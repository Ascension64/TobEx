#ifndef UIBUTTON_H
#define UIBUTTON_H

#include "uicore.h"
#include "scrcore.h"

class CUIButton : public CUIControl { //Size 650h
public:
	CUIButton();
	CUIButton(CPanel&, ChuFileControlInfoBase&, BYTE, BOOL); //586570
	CUIButton& Construct(CPanel&, ChuFileControlInfoBase&, BYTE, BOOL) { return *this; } //dummy
	void SetActive(bool);

	//AAAE44
	virtual ~CUIButton(); //v0
	void Deconstruct() {} //dummy

	virtual void OnLoseFocus(void); //vc
	virtual void OnLMouseDrag(POINT); //v14
	virtual BOOL OnLMouseBtDn(POINT); //v18
	virtual void OnLMouseBtUp(POINT); //v1c
	virtual BOOL OnLMouseDblClk(POINT); //v20
	virtual BOOL OnRMouseBtDn(POINT); //v24
	virtual void OnRMouseBtUp(POINT); //v28
	virtual void SetRedraw(void); //v48
	virtual BOOL Redraw(BOOL); //v4c
	virtual BOOL NeedsRedraw(void); //v58

	virtual void OnLClicked(POINT); //v5c
	virtual void OnLDblClicked(POINT); //v60
	virtual void OnRClicked(POINT); //v64
	virtual void SetText(IECString&); //v68

	CVidCell vc; //4ah
	WORD wFrameUp; //120h
	WORD wFrameDn; //122h
	WORD wFrameOff; //124h
	WORD wRedrawAmount; //126h
	BOOL bLock; //128h, 1: grabbed by mouse

	//bit0: enable LMB double-click
	//bit1: enable RMB
	BYTE m_flags; //12ch, Arg3
	BYTE u12d;
	IECString* m_pText; //12eh, array of captions (size: m_nTextRows)
	CVidFont vf; //132h
	POINT u62e;
	BOOL bActive; //636h, 0: greyed
	BYTE u63a;
	BYTE u63b; //pad
	DWORD u63c;
	DWORD u640; 
	WORD u644; //more flags, bit8: multi-row text
	BYTE m_nTextRows; //646h
	BYTE m_TextFlags; //647h
	DWORD framePress; //stores a WORD, high BYTE = pressed+1, low BYTE = unpressed+1
	DWORD frameState; //stores a WORD, high BYTE = disabled+1, low BYTE = pressed+1
};

extern CUIButton& (CUIButton::*CUIButton_Construct_4CPanel_ChuFileControlInfoBase_BYTE_BOOL)(CPanel&, ChuFileControlInfoBase&, BYTE, BOOL);
extern void (CUIButton::*CUIButton_SetActive)(bool);
extern void (CUIButton::*CUIButton_Deconstruct)();
extern void (CUIButton::*CUIButton_OnLoseFocus)(void);
extern void (CUIButton::*CUIButton_OnLMouseDrag)(POINT);
extern BOOL (CUIButton::*CUIButton_OnLMouseBtDn)(POINT);
extern void (CUIButton::*CUIButton_OnLMouseBtUp)(POINT);
extern BOOL (CUIButton::*CUIButton_OnLMouseDblClk)(POINT);
extern BOOL (CUIButton::*CUIButton_OnRMouseBtDn)(POINT);
extern void (CUIButton::*CUIButton_OnRMouseBtUp)(POINT);
extern void (CUIButton::*CUIButton_SetRedraw)(void);
extern BOOL (CUIButton::*CUIButton_Redraw)(BOOL);
extern BOOL (CUIButton::*CUIButton_NeedsRedraw)(void);
extern void (CUIButton::*CUIButton_OnLClicked)(POINT);
extern void (CUIButton::*CUIButton_OnLDblClicked)(POINT);
extern void (CUIButton::*CUIButton_OnRClicked)(POINT);
extern void (CUIButton::*CUIButton_SetText)(IECString&);

class CUIButton654 : public CUIButton { //Size 654h
//Constructor: 0x6F82C3 (profs), 0x6F889F (thief skills)
//Note: for the + and - arrows in proficiencies
public:
	//vtable: 0xAADAD0 (profs), 0xAADB40 (thief skills)
	virtual ~CUIButton654(); //v0

	virtual void v6c() {} //CallbackProc (differs between the two button types)
			
	DWORD u650;
};

class CUIButtonMageBookKnownSpell : public CUIButton { //Size 668h
public:
	CUIButtonMageBookKnownSpell(CPanel&, ChuFileControlInfoBase&); //7BE8AE
	CUIButtonMageBookKnownSpell& Construct(CPanel&, ChuFileControlInfoBase&) { return *this; } //dummy
	void SetSpell(ResRef&);

	//AB4FC8
	virtual ~CUIButtonMageBookKnownSpell(); //v0
	void Deconstruct() {} //dummy

	virtual BOOL OnLMouseBtDn(POINT); //v18
	virtual BOOL Redraw(BOOL); //v4c

	virtual void OnLClicked(POINT); //v5c
	virtual void OnRClicked(POINT); //v64

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
	CUIButtonPriestBookKnownSpell(CPanel&, ChuFileControlInfoBase&); //788CFF
	CUIButtonPriestBookKnownSpell& Construct(CPanel&, ChuFileControlInfoBase&) { return *this; } //dummy
	void SetSpell(ResRef&);

	//AB3438
	virtual ~CUIButtonPriestBookKnownSpell(); //v0
	void Deconstruct() {} //dummy

	virtual BOOL OnLMouseBtDn(POINT); //v18
	virtual BOOL Redraw(BOOL); //v4c

	virtual void OnLClicked(POINT); //v5c
	virtual void OnRClicked(POINT); //v64

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
	CUICheckButton(CPanel&, ChuFileControlInfoBase&, BYTE, BOOL); //587FB2
	CUICheckButton& Construct(CPanel&, ChuFileControlInfoBase&, BYTE, BOOL) { return *this; } //dummy
	void SetToggleState(BOOL);

	//AAAEB0
	virtual ~CUICheckButton(); //v0
	void Deconstruct() {} //dummy
	virtual BOOL Redraw(BOOL); //v4c

	virtual void OnLClicked(POINT); //v5c

	WORD wFrameOn; //650h
	WORD wFrameOff; //652h
	BOOL bToggle; //654h
};

extern CUICheckButton& (CUICheckButton::*CUICheckButton_Construct_4CPanel_ChuFileControlInfoBase_BYTE_BOOL)(CPanel&, ChuFileControlInfoBase&, BYTE, BOOL);
extern void (CUICheckButton::*CUICheckButton_Deconstruct)();
extern void (CUICheckButton::*CUICheckButton_SetToggleState)(BOOL);
extern BOOL (CUICheckButton::*CUICheckButton_Redraw)(BOOL);
extern void (CUICheckButton::*CUICheckButton_OnLClicked)(POINT);

class CUICheckButtonChargenKit : public CUICheckButton { //Size 658h
//Constructor: 73A6B7
public:
	CUICheckButtonChargenKit(CPanel&, ChuFileControlInfoBase&); //587FB2
	CUICheckButtonChargenKit& Construct(CPanel&, ChuFileControlInfoBase&) { return *this; } //dummy
	DWORD GetKitId(Object&);
	STRREF GetKitHelpText(Object&);

	//AB05E4
	virtual ~CUICheckButtonChargenKit(); //v0
	void Deconstruct() {} //dummy

	virtual void OnLClicked(POINT); //v5c
};

extern CUICheckButtonChargenKit& (CUICheckButtonChargenKit::*CUICheckButtonChargenKit_Construct_2CPanel_ChuFileControlInfoBase)(CPanel&, ChuFileControlInfoBase&);
extern DWORD (CUICheckButtonChargenKit::*CUICheckButtonChargenKit_GetKitId)(Object&);
extern STRREF (CUICheckButtonChargenKit::*CUICheckButtonChargenKit_GetKitHelpText)(Object&);
extern void (CUICheckButtonChargenKit::*CUICheckButtonChargenKit_Deconstruct)();
extern void (CUICheckButtonChargenKit::*CUICheckButtonChargenKit_OnLClicked)(POINT);

class CUICheckButtonChargenMageSpell : public CUICheckButton { //Size 66Eh
//Constructor: 0x7328A0
//vtable: 0xAAFC94
public:
	ResRef m_rSpellIcon; //658h
	ResRef m_rSpell; //660h
	BOOL u668; //grey out?
	WORD u66c;
};

class CUICheckButtonRecMageSpell : public CUICheckButton { //Size 66Ch
public:
	CUICheckButtonRecMageSpell(CPanel&, ChuFileControlInfoBase&); //6FA496
	CUICheckButtonRecMageSpell& Construct(CPanel&, ChuFileControlInfoBase&) { return *this; } //dummy
	void SetSpell(ResRef);

	//AADE3C
	virtual ~CUICheckButtonRecMageSpell(); //v0
	void Deconstruct() {} //dummy
	virtual BOOL Redraw(BOOL); //v4c

	virtual void OnLClicked(POINT); //v5c
	virtual void OnLClickedHLA(POINT); //v6c

	//members
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