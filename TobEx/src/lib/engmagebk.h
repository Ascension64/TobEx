#ifndef ENGMAGEBK_H
#define ENGMAGEBK_H

#include "engine.h"

class CScreenMageBook : public CEngine { //Size 14DAh
//constructor: 0x7B5970
public:
	//AB4EAC
	virtual void v0() {}

	void SetLevel(int);
	BOOL UpdatePanel(int);
	void ContingencySelectOnLoad(CPanel& panel);
	void ContingencySelectOnUpdate(int nPanelIdx);
	CPanel& GetTopPanel();
	BOOL CanContinue();
	void SetSpellContingencyState(IECString sSpell, bool bState);
	bool AddContingencySpell(IECString sSpell);
	bool ClearContingencySpell(char index);
	void UpdateContingencySpellList();
	void CreateContingencySpellList(char nSpellType, char nLevel);
	bool IsSpellAllowedInContingency(int nLevel, IECString sSpell);

	CHotkey keymap[93]; //feh
	char keybuffer[92]; //3e6h
	short u442;
	int currLevel; //444h
	CVidCell u448;
	int u51e;
	int u522;
	int u526;
	int u52a;
	int u52e;
	int u532;
	IECPtrList m_OpenPanels; //536h
	ResRef u552;
	int u55a;
	int u55e;
	int u562;
	int u566;
	int u56a;
	int u56e;
	BOOL showKnownSpellIcons; //572h (?)
	int u576;
	char u57a;
	char u57b;
	CVidFont u57c;
	CVidFont ua78;
	CVidFont uf74;
	BOOL isSorcererClass; //1470h
	char m_nContNumSpellLevels; //1474h
	char m_nMaxContSpells; //1475h

	//0: Chain Contingency/Spell Sequencer
	//1: one spell only (Contingency)
	//2: Spell Sequencer
	//3: two spells only
	short m_wContType; //1476h

	int u1478;
	ResRef m_rContSpell1; //147ch
	ResRef m_rContSpell2; //1484h
	ResRef m_rContSpell3; //148ch
	int m_nContCurrConditionIdx; //1494h
	int u1498;
	char m_nCurrContSpellLevel; //149ch
	char u149d;
	int m_nContSpellType; //149eh, 0 = mage, 1 = priest, treated as char
	short m_wContScrollIdx; //14a2h
	short u14a4;
	CMemSpellList m_ContSpells; //14a6h, here unsigned short wSpellFlags holds nNumMemorized instead 
	int u14c2;
	ResRef m_rContSpellName; //14c6h
	int u14ce;
	int u14d2;
	int u14d6;
};

extern void (CScreenMageBook::*CScreenMageBook_SetLevel)(int);
extern BOOL (CScreenMageBook::*CScreenMageBook_UpdatePanel)(int);
extern CPanel& (CScreenMageBook::*CScreenMageBook_GetTopPanel)();
extern BOOL (CScreenMageBook::*CScreenMageBook_CanContinue)();
extern void (CScreenMageBook::*CScreenMageBook_ContingencySelectOnLoad)(CPanel&);
extern void (CScreenMageBook::*CScreenMageBook_ContingencySelectOnUpdate)(int);
extern bool (CScreenMageBook::*CScreenMageBook_AddContingencySpell)(IECString);
extern bool (CScreenMageBook::*CScreenMageBook_ClearContingencySpell)(char index);
extern void (CScreenMageBook::*CScreenMageBook_SetSpellContingencyState)(IECString, bool);
extern void (CScreenMageBook::*CScreenMageBook_UpdateContingencySpellList)();
extern void (CScreenMageBook::*CScreenMageBook_CreateContingencySpellList)(char, char);
extern bool (CScreenMageBook::*CScreenMageBook_IsSpellAllowedInContingency)(int, IECString);

#endif //ENGMAGEBK_H