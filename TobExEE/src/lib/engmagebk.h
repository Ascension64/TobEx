//TobExEE
#ifndef ENGMAGEBK_H
#define ENGMAGEBK_H

#include "engine.h"

class CScreenMageBook : public CEngine { //Size 8C0h
public:
	CHotkey m_keymap[95]; //d0h, size 474h
	int m_keybuffer[95]; //544h, size 17Ch
	int currLevel; //6c0h
	CVidCell u6c4;
	int u788;
	int u78c;
	int u790;
	int u794;
	int u798;
	int u79c;
	IECPtrList m_OpenPanels; //7a0h
	ResRef u7bc;
	int u7c4;
	int u7c8;
	BOOL m_bShowKnownSpellIcons; //7cch, ?
	int u7d0;
	int u7d4;
	int u7d8;
	int u7dc;
	int u7e0;
	char u7e4;
	char p7e5[3];
	CVidFont u7e8;
	CVidFont u80c;
	CVidFont u830;
	BOOL m_bIsSorcererClass; //854h
	char m_nContNumSpellLevels; //858h
	char m_nMaxContSpells; //859h

	//0: Chain Contingency/Spell Sequencer
	//1: one spell only (Contingency)
	//2: Spell Sequencer
	//3: two spells only
	short m_wContType; //85ah

	int u85c;
	ResRef m_rContSpell1; //860h
	ResRef m_rContSpell2; //868h
	ResRef m_rContSpell3; //870h

	int m_nContCurrConditionIdx; //878h
	int u87c;
	char m_nCurrContSpellLevel; //880h
	char p881[3];
	int m_nContSpellType; //884h, 0 = mage, 1 = priest, treated as char
	short m_wContScrollIdx; //888h
	short m_wContSpellNum; //88ah, number of contingencies in conditional spell list
	CMemSpellList m_ContSpells; //88ch, here unsigned short wSpellFlags holds nNumMemorized instead 
	int u8a8;
	ResRef m_rContSpellName; //8ach
	int u8b4;
	int u8b8;
	int u8bc;
};

#endif //ENGMAGEBK_H