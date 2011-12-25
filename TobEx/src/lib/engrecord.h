#ifndef ENGRECORD_H
#define ENGRECORD_H

#include "engine.h"
#include "uicore.h"

class CRecord : public CEngine { //Size 1520h
//Constructor: 0x6D62B2
public:
	//AAD6B4
	virtual void v0() {}

	void MageBookPanelOnLoad(CCreatureObject& cre);
	void MageBookPanelOnUpdate(CCreatureObject& cre);
	void UpdatePanel(int nPanelIdx, CCreatureObject& cre);
	CPanel& GetTopPanel();
	void UpdateCharacter();

	CHotkey ufe[91];
	int u3d6[23];

	IECPtrList u432; //open Panels
	int dwProfsMax; //44eh, set but not used in-game
	int u452;
	CPtrArray u456; //AAD7D0
	int u46a;
	int u46e[7];
	char u48a;
	char u48b; //pad
	int u48c; //nSpellsRemaining, # spells remaining for sorcerer to choose
	int u490;
	int u494;
	int u498;
	int u49c;
	int u4a0;
	int u4a4; //nErrorButtons
	int u4a8;
	int u4ac;
	int u4b0;
	int u4b4;
	int u4b8;
	int u4bc[6];
	short u4d4;
	int u4d6;
	int u4da; //customSoundSetIdx
	int u4de;
	char u4e2;
	ResRef u4e3;
	ResRef u4eb;
	char u4f3[7];
	IECString u4fa;
	ResRef u4fe;
	ResRef u506;
	short u50e;
	IECPtrList* m_pSounds; //510h, contains CStrings
	ResRef u514;
	CreFileData* u51c; //m_pTempBaseStats
	CDerivedStats* u520; //m_pTempDerivedStats
	int u524;
	CVidFont u528;
	CVidFont ua24;
	CVidFont uf20;		
	char u141c; //bInChargen?
	char u141d;
	short u141e;
	CResRefList MageBookSpells; //1420h (Resref spells)
	short u143c;
	char nCurrentMageBookLevel; //143eh
	char u143f; //pad?
	int u1440[3];
	char u144c;
	char u144d; //pad
	IECString u144e;
	int u1452; //character's previous level (on level-up)
	int u1456;

	struct NewSpell { //SIze 9h
		ResRef name; //0h
		char level; //8h
	} u145a[9];

	char u14ab;
	int u14ac;
	CStringList m_szCharInfoStroage; //u14b0
	int u14cc[10];
	int u14f4;
	int u14f8;
	int u14fc;
	char u1500;
	char u1501; //pad
	int u1502;
	int u1506[6];
	char u151e;
	char u151f; //pad
};

extern void (CRecord::*CRecord_MageBookPanelOnLoad)(CCreatureObject&);
extern void (CRecord::*CRecord_MageBookPanelOnUpdate)(CCreatureObject&);
extern void (CRecord::*CRecord_UpdatePanel)(int, CCreatureObject&);
extern CPanel& (CRecord::*CRecord_GetTopPanel)(void);
extern void (CRecord::*CRecord_UpdateCharacter)(void);

#endif //ENGRECORD_H