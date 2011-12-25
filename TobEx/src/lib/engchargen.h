#ifndef ENGCHARGEN_H
#define ENGCHARGEN_H

#include "engine.h"
#include "uicore.h"
#include "objcre.h"

class CCharGen : public CEngine { //Size 148Ch
//Constructor: 0x715333
public:
	//AAF5F0
	virtual void v0() {}

	//functions
	void KitPanelOnLoad(CPanel&, CCreatureObject&);
	void MageBookPanelOnLoad(CPanel&, CCreatureObject&);
	void UpdatePanel(DWORD, CCreatureObject&);
	void KitPanelOnUpdate(CPanel&, CCreatureObject&);
	void MageBookPanelOnUpdate(CPanel&, CCreatureObject&);
	void ClassPanelOnUpdate(CPanel&, CCreatureObject&);
	void MulticlassPanelOnUpdate(CPanel&, CCreatureObject&);
	void MageSchoolPanelOnUpdate(CPanel&, CCreatureObject&);
	void InitSoundset(CCreatureObject&);
	BOOL CanContinue(CCreatureObject&);

	//members
	CRuleTable Kit_Class_Race; //feh
	struct _5A7510 {
	//Size: 0x30
	//Constructor: 0x5A7510
		BYTE u0;
		BYTE u1[7];
		CPtrArray u8; //AAB3EC
		CPtrArray u1c; //AAB3E0
	} u122;

	CHotkey u152[91];

	DWORD u42a[23]; //42ah
	DWORD u486;
	DWORD u48a;
	DWORD u48e;
	DWORD u492;
	DWORD charType; //496h, 2 = newChar, 5 = BG1Char
	Enum eChar; //49ah, global enum value of chargen char
	DWORD u49e;
	DWORD u4a2;
	DWORD nSpellsRemaining; //4a6h
	DWORD u4aa[13];
	CPtrList m_OpenPanels; //4deh
	DWORD u4fa;
	DWORD u4fe;
	DWORD nTopHatedRace; //502h, sliderValue for racial enemy
	DWORD u506;
	DWORD u50a;
	DWORD u50e;
	DWORD u512;
	DWORD u516;
	DWORD u51a;
	DWORD u51e;
	DWORD u522;
	DWORD u526;
	DWORD u52a;
	DWORD u52e;
	DWORD u532;
	CVidFont u536;
	CVidFont ua32;
	CVidFont uf2e;
	WORD u142a;
	CResRefList MageBookSpells; //142ch (ResRef spells)
	BYTE u1448;
	BYTE u1449; //pad
	DWORD u144a;
	DWORD u144e;
	DWORD u1452;
	BYTE nCurrentMageBookLevel; //1456h, range: 1-9
	BYTE nMaxMageBookLevel; //1457h
	WORD u1458;
	WORD u145a; //pad
	BYTE m_class; //145ch
	BYTE u145d; //pad
	WORD u145e; //holds the kit number
	WORD u1460;
	DWORD u1462;
	BYTE u1466;
	BYTE u1467; //pad
	WORD nSpellsChosen; //1468h
	WORD u146a;
	WORD u146c;
	BYTE sliderValue; //146eh, for old skills
	BYTE u146f;
	WORD numHatedRaces; //1470h, total number of racial enemy choices
	DWORD u1472;
	STRREF strrefSpellDesc2; //1476h
	WORD u147a;
	STRREF strrefSpellDesc; //147ch
	DWORD u1480;
	DWORD u1484;
	IECString u1488;
};

extern void (CCharGen::*CCharGen_KitPanelOnLoad)(CPanel&, CCreatureObject&);
extern void (CCharGen::*CCharGen_MageBookPanelOnLoad)(CPanel&, CCreatureObject&);
extern void (CCharGen::*CCharGen_UpdatePanel)(DWORD, CCreatureObject&);
extern void (CCharGen::*CCharGen_KitPanelOnUpdate)(CPanel&, CCreatureObject&);
extern void (CCharGen::*CCharGen_MageBookPanelOnUpdate)(CPanel&, CCreatureObject&);
extern void (CCharGen::*CCharGen_ClassPanelOnUpdate)(CPanel&, CCreatureObject&);
extern void (CCharGen::*CCharGen_MulticlassPanelOnUpdate)(CPanel&, CCreatureObject&);
extern void (CCharGen::*CCharGen_MageSchoolPanelOnUpdate)(CPanel&, CCreatureObject&);
extern void (CCharGen::*CCharGen_InitSoundset)(CCreatureObject&);
extern BOOL (CCharGen::*CCharGen_CanContinue)(CCreatureObject&);

#endif //ENGCHAGEN_H