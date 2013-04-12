//TobExEE
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

struct CButtonArrayButton { //Size 1B4h
	int u0;
	int u4;
	int u8;
	int uc;
	int u10;
	CVidCell u14;
	CVidCell ud8;
	int u19c;
	BOOL m_bActive; //1a0h
	int u1a4;
	int u1a8;
	int u1ac;
	BOOL m_bDisabled; //1b0h
};
	
struct CButtonArray { //Size 167Ch
	CButtonArrayButton m_buttons[12]; //0h
	int u1470[12]; //unused?
	int m_nButtonIdx[12]; //14a0h
	int u14d0;
	int m_nButtonArrayTypeCurrentIdx; //14d4h
	int m_nButtonArrayTypePreviousIdx; //14d8h
	int u14dc;
	CVidCell m_vidBackgrounds; //14e0h, GUIWDBUT
	CVidCell m_vidActions; //15a4h, GUIBTACT
	int u1668;
	int u166c;
	int u1670;
	int u1674;
	int u1678;
};

#endif //INFBTARR_H