//TobExEE
#ifndef ENGCHARGEN_H
#define ENGCHARGEN_H

#include "engine.h"
#include "uicore.h"
#include "objcre.h"

class CScreenCharGen : public CEngine { //Size 8A4h
public:
	virtual void v0() {}

	CRuleTable m_kitclassrace; //d0h

	struct unk1 { //Size 34h
		char u0[12];
		CPtrArray uc;
		CPtrArray u20;
	} uf4;

	CHotkey m_keymap[95]; //128h, size 474h
	int m_keybuffer[95]; //59ch, size 17Ch
	int u718;
	int u71c;
	int u720;
	int u724;
	
	//0: before Gender
	//1: before Race
	//2: before Class
	//3: before Abilities
	//4: before Alignment
	//5: before Skills/Proficiencies
	//6: before Color Choices
	//7: before Name
	int m_nChargenProgress; //728h

	ENUM m_eChar; //72ch, global enum value of chargen char
	int u730;
	int u734;
	int m_nSpellsRemaining; //738h
	int m_nThievingPointsRemaining; //73ch, used only for the BG1 Skills panel
	int u740;
	int u744;
	int u748;
	int u74c;
	int u750;
	int u754;
	int u758;
	char m_cMinStrValue; //75ch
	char m_cMinDexValue; //75dh
	char m_cMinConValue; //75eh
	char m_cMinIntValue; //75fh
	char m_cMinWisValue; //760h
	char m_cMinChrValue; //761h
	char m_cMaxStrValue; //762h
	char m_cMaxDexValue; //763h
	char m_cMaxConValue; //764h
	char m_cMaxIntValue; //765h
	char m_cMaxWisValue; //766h
	char m_cMaxChrValue; //767h
	int m_dwProfsMax; //768h, set but not used in-game
	int u76c;
	int u770;
	IECPtrList m_OpenPanels; //774h
	int u790;
	int u794;
	int m_nTopHatedRace; //798h, sliderValue for racial enemy
	int u79c;
	int u7a0;
	int u7a4;
	int u7a8;
	int u7ac;
	int u7b0;
	int u7b4;
	int u7b8;
	int u7bc;
	int u7c0;
	int u7c4;
	int u7c8;
	int u7cc;
	CVidFont u7d0;
	CVidFont u7f4;
	CVidFont u818;
	short u83c;
	char p83e[2];
	CResRefList m_lMageBookSpells; //840h (ResRef spells)
	char u85c;
	char p85d[3];
	int u860;
	int u864;
	int u868;
	char m_nCurrentMageBookLevel; //86ch, range: 1-9
	char m_nMaxMageBookLevel; //86dh
	short u86e;
	char p870[2];
	unsigned char m_cClass; //872h
	char p873;
	short u874; //holds the kit number
	short u876;
	int u878;
	char u87c;
	char p87d;
	short m_nSpellsChosen; //87eh
	short u880;
	short u882;
	char m_cSliderValue; //884h, for old skills
	char u885;
	short m_wNumHatedRaces; //886h, total number of racial enemy choices
	int u888;
	STRREF m_strrefSpellDesc2; //88ch
	short u890;
	char p892[2];
	STRREF m_strrefSpellDesc; //894h
	int u898;
	int u89c;
	IECString u8a0;
};

#endif //ENGCHARGEN_H