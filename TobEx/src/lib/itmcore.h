#ifndef ITMCORE_H
#define ITMCORE_H

#include "resref.h"
#include "rescore.h"
#include "sndcore.h"

struct ResItmContainer { //Size 10h
	BOOL bLoaded; //0x0
	ResItm* pRes; //0x4
	ResRef name; //0x8
};

class CItem {
//Size: 0xfa
//Constructor: 0x5A83F0 (0 args), 0x5A9538 (6 args), 0x5A84BE (1 arg)
//Notes: AKA m_item
public:
	DWORD* pvtable; //0x0
	ResItmContainer m_itm; //0x4
	DWORD numAbilities; //0x14
	WORD Arg3; //0x18, usage1? is it a randomly generated item?
	WORD Arg4; //0x1a, usage2?
	WORD Arg5; //0x1c, usage3? (time to recharge in ai updates?)
	WORD Arg6; //0x1e, related to usage3 (time to recharge in days?)
	BOOL bIdentified; //0x20, Arg7
	CSound sound; //0x24
	CSound sound2; //0x8e
	WORD uf8; //0xf8
};

struct _95BFAF {
//Size: 0x24
//Constructor: 0x95BFAF, also 0x95D095
	BYTE u0;
	BYTE u1; //padding?
	WORD u2;
	BYTE u4;
	BYTE u5;
	DWORD u6;
	DWORD ua[6];
	BYTE u22;
	BYTE u23; //padding?
};

#endif //ITMCORE_H