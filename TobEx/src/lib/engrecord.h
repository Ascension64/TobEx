#ifndef ENGRECORD_H
#define ENGRECORD_H

#include "engine.h"
#include "uicore.h"

class CRecord : public CEngine { //Size 1520h
//Constructor: 0x6D62B2
public:
	//AAD6B4
	virtual void v0() {}

	//functions
	void MageBookPanelOnLoad(CCreatureObject&);
	void MageBookPanelOnUpdate(CCreatureObject&);
	void UpdatePanel(DWORD, CCreatureObject&);
	CPanel& GetTopPanel();
	void UpdateCharacter();

	//members
	CHotkey ufe[91];
	DWORD u3d6[23];

	CPtrList u432; //open Panels
	DWORD dwProfsMax; //44eh, set but not used in-game
	DWORD u452;
	CPtrArray u456; //AAD7D0
	DWORD u46a;
	DWORD u46e[7];
	BYTE u48a;
	BYTE u48b; //pad
	DWORD u48c; //nSpellsRemaining, # spells remaining for sorcerer to choose
	DWORD u490;
	DWORD u494;
	DWORD u498;
	DWORD u49c;
	DWORD u4a0;
	DWORD u4a4; //nErrorButtons
	DWORD u4a8;
	DWORD u4ac;
	DWORD u4b0;
	DWORD u4b4;
	DWORD u4b8;
	DWORD u4bc[6];
	WORD u4d4;
	DWORD u4d6;
	DWORD u4da; //customSoundSetIdx
	DWORD u4de;
	BYTE u4e2;
	ResRef u4e3;
	ResRef u4eb;
	char u4f3[7];
	IECString u4fa;
	ResRef u4fe;
	ResRef u506;
	WORD u50e;
	DWORD u510; //CPtrList m_pSounds (contains CStrings)
	ResRef u514;
	CreFileData* u51c; //m_pTempBaseStats
	CDerivedStats* u520; //m_pTempDerivedStats
	DWORD u524;
	CVidFont u528;
	CVidFont ua24;
	CVidFont uf20;		
	BYTE u141c; //bInChargen?
	BYTE u141d;
	WORD u141e;
	CResRefList MageBookSpells; //1420h (Resref spells)
	WORD u143c;
	BYTE nCurrentMageBookLevel; //143eh
	BYTE u143f; //pad?
	DWORD u1440[3];
	BYTE u144c;
	BYTE u144d; //pad
	IECString u144e;
	DWORD u1452; //character's previous level (on level-up)
	DWORD u1456;

	struct NewSpell {
	//size: 0x9
		ResRef name; //0h
		BYTE level; //8h
	} u145a[9];

	BYTE u14ab;
	DWORD u14ac;
	CStringList m_szCharInfoStroage; //u14b0
	DWORD u14cc[10];
	DWORD u14f4;
	DWORD u14f8;
	DWORD u14fc;
	BYTE u1500;
	BYTE u1501; //pad
	DWORD u1502;
	DWORD u1506[6];
	BYTE u151e;
	BYTE u151f; //pad
};

extern void (CRecord::*CRecord_MageBookPanelOnLoad)(CCreatureObject&);
extern void (CRecord::*CRecord_MageBookPanelOnUpdate)(CCreatureObject&);
extern void (CRecord::*CRecord_UpdatePanel)(DWORD, CCreatureObject&);
extern CPanel& (CRecord::*CRecord_GetTopPanel)(void);
extern void (CRecord::*CRecord_UpdateCharacter)(void);

#endif //ENGRECORD_H