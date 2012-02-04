#ifndef ENGCHARGEN_H
#define ENGCHARGEN_H

#include "engine.h"
#include "uicore.h"
#include "objcre.h"

class CScreenCharGen : public CEngine { //Size 148Ch
//Constructor: 0x715333
public:
	//AAF5F0
	virtual void v0() {}

	void KitPanelOnLoad(CPanel& panel, CCreatureObject& cre);
	void MageBookPanelOnLoad(CPanel& panel, CCreatureObject& cre);
	void UpdatePanel(int nPanelIdx, CCreatureObject& cre);
	void KitPanelOnUpdate(CPanel& panel, CCreatureObject& cre);
	void MageBookPanelOnUpdate(CPanel& panel, CCreatureObject& cre);
	void ClassPanelOnUpdate(CPanel& panel, CCreatureObject& cre);
	void MulticlassPanelOnUpdate(CPanel& panel, CCreatureObject& cre);
	void MageSchoolPanelOnUpdate(CPanel& panel, CCreatureObject& cre);
	void InitSoundset(CCreatureObject& cre);
	BOOL CanContinue(CCreatureObject& cre);

	CRuleTable Kit_Class_Race; //feh
	struct _5A7510 { //Size 30h
	//Constructor: 0x5A7510
		char u0;
		char u1[7];
		CPtrArray u8; //AAB3EC
		CPtrArray u1c; //AAB3E0
	} u122;

	CHotkey keymap[91]; //152h
	char keybuffer[92]; //42ah
	int u486;
	int u48a;
	int u48e;
	int u492;
	
	//0: before Gender
	//1: before Race
	//2: before Class
	//3: before Abilities
	//4: before Alignment
	//5: before Skills/Proficiencies
	//6: before Color Choices
	//7: before Name
	int nChargenProgress; //496h

	Enum eChar; //49ah, global enum value of chargen char
	int u49e;
	int u4a2;
	int nSpellsRemaining; //4a6h
	int nThievingPointsRemaining; //4aah, used only for the BG1 Skills panel
	int u4ae[10];
	int dwProfsMax; //4d6h, set but not used in-game
	int u4da;
	IECPtrList m_OpenPanels; //4deh
	int u4fa;
	int u4fe;
	int nTopHatedRace; //502h, sliderValue for racial enemy
	int u506;
	int u50a;
	int u50e;
	int u512;
	int u516;
	int u51a;
	int u51e;
	int u522;
	int u526;
	int u52a;
	int u52e;
	int u532;
	CVidFont u536;
	CVidFont ua32;
	CVidFont uf2e;
	short u142a;
	CResRefList MageBookSpells; //142ch (ResRef spells)
	char u1448;
	char u1449; //pad
	int u144a;
	int u144e;
	int u1452;
	char nCurrentMageBookLevel; //1456h, range: 1-9
	char nMaxMageBookLevel; //1457h
	short u1458;
	short u145a; //pad
	unsigned char m_class; //145ch
	char u145d; //pad
	short u145e; //holds the kit number
	short u1460;
	int u1462;
	char u1466;
	char u1467; //pad
	short nSpellsChosen; //1468h
	short u146a;
	short u146c;
	char sliderValue; //146eh, for old skills
	char u146f;
	short numHatedRaces; //1470h, total number of racial enemy choices
	int u1472;
	STRREF strrefSpellDesc2; //1476h
	short u147a;
	STRREF strrefSpellDesc; //147ch
	int u1480;
	int u1484;
	IECString u1488;
};

extern void (CScreenCharGen::*CScreenCharGen_KitPanelOnLoad)(CPanel&, CCreatureObject&);
extern void (CScreenCharGen::*CScreenCharGen_MageBookPanelOnLoad)(CPanel&, CCreatureObject&);
extern void (CScreenCharGen::*CScreenCharGen_UpdatePanel)(int, CCreatureObject&);
extern void (CScreenCharGen::*CScreenCharGen_KitPanelOnUpdate)(CPanel&, CCreatureObject&);
extern void (CScreenCharGen::*CScreenCharGen_MageBookPanelOnUpdate)(CPanel&, CCreatureObject&);
extern void (CScreenCharGen::*CScreenCharGen_ClassPanelOnUpdate)(CPanel&, CCreatureObject&);
extern void (CScreenCharGen::*CScreenCharGen_MulticlassPanelOnUpdate)(CPanel&, CCreatureObject&);
extern void (CScreenCharGen::*CScreenCharGen_MageSchoolPanelOnUpdate)(CPanel&, CCreatureObject&);
extern void (CScreenCharGen::*CScreenCharGen_InitSoundset)(CCreatureObject&);
extern BOOL (CScreenCharGen::*CScreenCharGen_CanContinue)(CCreatureObject&);

#endif //ENGCHAGEN_H