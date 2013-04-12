#ifndef ENGRECORD_H
#define ENGRECORD_H

#include "engine.h"
#include "uicore.h"

class CScreenRecord : public CEngine { //Size 1520h
//Constructor: 0x6D62B2
public:
	//AAD6B4
	virtual void v0() {}

	void MageBookPanelOnLoad(CCreatureObject& cre);
	void MageBookPanelOnUpdate(CCreatureObject& cre);
	void UpdatePanel(int nPanelIdx, CCreatureObject& cre);
	CPanel& GetTopPanel();
	void UpdateCharacter();

	CHotkey keymap[91]; //feh
	char keybuffer[92]; //3d6h

	IECPtrList cplOpenPanels; //432h
	int dwProfsMax; //44eh, set but not used in-game
	int u452;
	CPtrArray u456; //AAD7D0
	int nThievingPointsRemaining; //46ah
	int u46e[7];
	char m_nSelectedDualClass; //48ah
	char u48b; //pad
	int u48c; //nSpellsRemaining, # spells remaining for sorcerer to choose
	int u490;
	int m_pScripts; //494h
	int u498;
	int u49c;
	int u4a0;
	int u4a4; //nErrorButtons
	int u4a8;
	int u4ac;
	int u4b0;
	int u4b4;
	int u4b8;
	int u4bc;
	short u4c0;
	int u4c2;
	BOOL m_bPlayerControllable; //4c6h
	int u4ca;
	int u4ce;
	short u4d2;
	short u4d4;
	int u4d6;
	int u4da; //customSoundSetIdx
	int u4de;
	char u4e2;
	ResRef rPortraitSmall; //4e3h
	ResRef rPortraitLarge; //4ebh
	CreFileColors colors; //4f3h
	IECString sClassScript; //4fah
	ResRef rPortraitSmall2; //4feh
	ResRef rPortraitLarge2; //506h
	short m_wSelectedDualClassKit; //50eh, wKit low
	IECPtrList* m_pSounds; //510h, contains CStrings
	ResRef rVoiceset; //514h
	CreFileHeader* u51c; //m_pTempHeader
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
	short m_wFirstWeapProfRowIdx; //1440h, the first row idx to read from in WEAPPROF.2DA in dual class proficiencies
	short u1442;
	int u1444[2];
	char u144c;
	char u144d; //pad
	IECString u144e;
	int u1452; //character's previous level (on level-up)
	int u1456;

	struct NewSpell { //Size 9h
		ResRef name; //0h
		char level; //8h
	} u145a[9];

	char u14ab;
	int u14ac;
	CStringList m_szCharInfoStorage; //14b0h
	int u14cc[10];
	BOOL bHighLevelAbility; //14f4h
	int u14f8;
	int u14fc;
	char nHLAFlags; //1500h, bit4: allow cleric HLAs, bit5: allow mage HLAs
	char u1501; //pad
	
	
	/*
	elements 0x28?
	based on LU**0.2DA
	0x0 *
	0x4 icon
	0x8 strref
	0xc sAbility
	0x10 nMinLevel
	0x14 nMaxLevel
	0x18 nNumAllowed
	0x1c sPreReq
	0x20 sExcludedBy
	0x24 sAlignRestrict
	*/
	CPtrArray* u1502;

	int u1506[6];
	char u151e;
	char u151f; //pad
};

#endif //ENGRECORD_H