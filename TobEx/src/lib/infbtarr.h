#ifndef INFBTARR_H
#define INFBTARR_H

#include "stdafx.h"
#include "vidcore.h"

#define CBUTTONARRAY_BTID_BARDSONG		2
#define CBUTTONARRAY_BTID_CASTSPELL		3
#define CBUTTONARRAY_BTID_FINDTRAPS		4
#define CBUTTONARRAY_BTID_TALK			5
#define CBUTTONARRAY_BTID_ABILITY		10
#define CBUTTONARRAY_BTID_STEALTH		11
#define CBUTTONARRAY_BTID_THIEVING		12
#define CBUTTONARRAY_BTID_TURNUNDEAD	13
#define CBUTTONARRAY_BTID_USEITEM		14
#define CBUTTONARRAY_BTID_QUICKITEM1	21
#define CBUTTONARRAY_BTID_QUICKITEM2	22
#define CBUTTONARRAY_BTID_QUICKITEM3	23
#define CBUTTONARRAY_BTID_QUICKSPELL1	24
#define CBUTTONARRAY_BTID_QUICKSPELL2	25
#define CBUTTONARRAY_BTID_QUICKSPELL3	26

struct CButtonArrayButton { //Size 1D4h
	int u0;
	int u4;
	int u8;
	int uc;
	int u10;
	CVidCell u14;
	CVidCell uea;
	int u1c0;
	BOOL m_bActive; //1c4h
	int u1c8;
	int u1cc;
	BOOL bDisabled; //1d0h
};
	
struct CButtonArray { //Size 1820h
//Constructor: 0x6607EF
//To do with the 12 quick bar buttons in GUI
	BOOL CheckButtonEnabled(int nIdx);

	CButtonArrayButton buttons[12]; //0h
	int u15f0[12]; //unused?
	int nButtonIdx[12]; //1620h
	int u1650;
	int nButtonArrayTypeCurrentIdx; //1654h
	int nButtonArrayTypePreviousIdx; //1658h
	int u165c;
	CVidCell cvcBackgrounds; //1660h, GUIWDBUT
	CVidCell cvcActions; //1736h, GUIBTACT
	int nItemSlotIdx; //180ch
	int u1810;
	int nActiveButtonIdx; //1814h
	int nIndexMageSpellStart; //1818h, of CQuickObjectList
	int u181c; //0 = showing priest spells, 1 = showing mage spells
};

#endif //INFBTARR_H