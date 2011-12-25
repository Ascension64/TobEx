#ifndef ANIMEXT_H
#define ANIMEXT_H

#include "animcore.h"
#include "cstringex.h"

class CAnimation0000 : public CAnimation { //Size 976h
//Constructor: 0x7FAA53
//vtable: 0xAB622C
public:
	CVidCell* m_pCurrentVidCell; //6d8h
	CVidCell* m_pAnimShadow; //6dch
	CVidCell m_AnimMain; //6e0h
	CVidCell m_AnimShadow; //7b6h
	VidPal u88c;
	BYTE ub80;
	BYTE u8b1;
	WORD u8b2;
	WORD u8b4;
	WORD wCurrentAnimation; //8b6h
	WORD wCurrentOrientation; //8b8h
	BYTE nOrientations; //8bah
	BYTE u8bb; //pad
	DWORD u8bc;
	CVidBitmap u8c0;
};

class CAnimation1000 : public CAnimation { //Size 73Ah
//includes 0x1100 set
//Constructor: 0x8356F3
//vtable: 0xAB6C00
public:
	IECString sAniSnd; //6d8h
	CVidCell* m_pCurrentVidCell; //6dch

	CVidCell* m_pCurrentVidCellBase; //6e0h
	//each contains nVidCells
	CVidCell* m_pG1VidCellBase; //6e4h
	CVidCell* m_pG2VidCellBase; //6e8h
	CVidCell* m_pG3VidCellBase; //6ech

	CVidCell* m_currentVidCellExtend; //6f0h
	//each contains nVidCells
	CVidCell* m_pG1VidCellExtend; //6f4h
	CVidCell* m_pG2VidCellExtend; //6f8h
	CVidCell* m_pG3VidCellExtend; //6fch

	VidPal vpColorRange; //700h
	WORD wCurrentAnimation; //724h
	WORD wCurrentOrientation; //726h
	BOOL bUseColorRange; //728h
	BYTE nOrientations; //72ch, if wOrient > nOrient, use Extended VidCell
	BYTE nParts; //72d, # parts per vidcell (e.g. MTANG1[1-4])
	DWORD u72e;
	BOOL bUseExtendedVidCells; //732h
	DWORD u736;
};

class CAnimation1200 : public CAnimation { //Size AC6h
//Constructor: 0x82C8AE
//vtable: 0xAB6B1C
public:
	IECString sAniSnd; //6d8h
	CVidCell* m_pCurrentVidCell; //6dch

	CVidCell* m_pCurrentVidCellBase; //6e0h
	CVidCell* m_pG1VidCellBase; //6e4h
	CVidCell* m_pG2VidCellBase; //6e8h
	CVidCell* m_pG3VidCellBase; //6ech
	CVidCell* m_pG4VidCellBase; //6f0h
	CVidCell* m_pG5VidCellBase; //6f4h

	VidPal vpColorRange; //6f8h
	WORD wCurrentAnimation; //71ch
	WORD wCurrentOrientation; //71eh
	DWORD u720;
	CVidBitmap* m_currentBitmap; //724h
	BOOL bUseColorRange; //728h
	CVidBitmap m_Bitmap1; //72ch
	CVidBitmap m_Bitmap2; //7e2h
	CVidBitmap m_Bitmap3; //898h
	CVidBitmap m_Bitmap4; //94eh
	CVidBitmap m_Bitmap5; //a04h
	BYTE nOrientations; //abah, orientations until mirror
	BYTE nParts; //abbh
	DWORD uabc;
	DWORD uac0;
	char cSuffix1; //ac4h
	char cSuffix2; //ac5h
};

class CAnimation1300 : public CAnimation { //Size 7F4h
//Constructor: 0x8746B1
//vtable: 0xAB7158
public:
	IECString sAniSnd; //6d8h
	CVidCell* m_pCurrentVidCell; //6dch

	CVidCell* m_pCurrentVidCellBase; //6e0h
	CVidCell* m_pG1VidCellBase; //6e4h
	CVidCell* m_pG2VidCellBase; //6e8h

	VidPal vpColorRange; //6ech
	WORD wCurrentAnimation; //710h
	WORD wCurrentOrientation; //712h
	WORD u714;
	DWORD u716;
	BOOL bUseColorRange; //71ah
	CVidBitmap u71e;
	BYTE nOrientations; //7d4h
	BYTE nParts; //7d5h
	DWORD u7d6;
	DWORD u7dc;
	DWORD u7e0;
	DWORD u7e4;
	BYTE u7e8;
	DWORD u7ea;
	DWORD u7ee;
	BYTE u7f2;
};

class CAnimation2000 : public CAnimation { //Size E0Ch
//Constructor: 0x83D12A
//vtable: 0xAB6DC8
public:
	IECString AniSnd; //6d8h
	CVidCell* m_pCurrentVidCell; //6dch

	CVidCell* m_pCurrentVidCellBase; //6e0h
	CVidCell* m_pCurrentVidCellExtend; //6e4h
	CVidCell m_G1VidCellBase; //6e8h
	CVidCell m_G1VidCellExtend; //7beh
	CVidCell m_G2VidCellBase; //894h
	CVidCell m_G2VidCellExtend; //96ah
	VidPal vpColorRangeBase; //a40h

	CVidCell* m_pCurrentVidCellShadow; //a64h

	CVidCell* m_pCurrentVidCellShadowBase; //a68h
	CVidCell* m_pCurrentVidCellShadowExtend; //a6ch
	CVidCell m_G1VidCellShadowBase; //a70h
	CVidCell m_G2VidCellShadowExtend; //b46h
	CVidCell m_G1VidCellShadowBase; //c1ch
	CVidCell m_G2VidCellShadowExtend; //cf2h
	VidPal vpColorRangeExtend; //dc8h

	WORD wCurrentAnimation; //dech
	WORD wCurrentOrientation; //deeh
	DWORD udf0;
	DWORD udf4;
	BOOL bUseColorRange; //df8h
	IECString udfc;
	IECString ue00;
	BYTE ue04;
	BYTE ue05; //pad
	DWORD ue06;
	BYTE nOrientations; //e0ah
	BYTE ue0a; //pad
};

class CAnimation3000 : public CAnimation { //Size 1106h
//Constructor: 0x841063
public:
};

class CAnimation4000 : public CAnimation { //Size 7E4h
//Constructor: 0x7FA344
public:
};

class CAnimation5000 : public CAnimation { //Size 16E0h
//includes 0x6000 set (except 0x6400)
//Constructor: 0x8436378
public:
};

class CAnimation6400 : public CAnimation { //Size 36B0h
//Constructor: 0x8586AC
public:
};


class CAnimation7000 : public CAnimation { //Size B2Ch
//Constructor: 0x8176A5
//vtable: 0xAB678C
public:
	IECString sAniSnd; //6d8h
	CVidCell* m_pCurrentVidCell; //6dch

	CVidCell* m_pCurrentVidCellBase; //6e0h
	CVidCell* m_pCurrentVidCellExtend; //6e4h
	CVidCell m_G1VidCellBase; //6e8h
	CVidCell m_G1VidCellExtend; //7beh
	CVidCell m_G2VidCellBase; //894h
	CVidCell m_G2VidCellExtend; //96ah
	VidPal vpColorRangeBase; //a40h

	WORD wCurrentAnimation; //a64h
	WORD wCurrentOrientation; //a66h
	BOOL bUseColorRange; //a68h
	DWORD ua6c;
	DWORD ua70;
	CVidBitmap ua74;
	BYTE ub2a;
	BYTE nOrientations; //b2bh
};

class CAnimation7000Special : public CAnimation { //Size D3Ch
//unused
//Constructor: 0x807184
public:
};


class CAnimation8000 : public CAnimation { //Size E02h
//Constructor: 0x839BE6
public:
};


class CAnimation9000 : public CAnimation { //Size C1Ah
//Constructor: 0x828165
public:
};


class CAnimationA000 : public CAnimation { //Size C1Ah
//Constructor: 0x7FA67A
public:
};


class CAnimationB000 : public CAnimation { //Size 8C2h
//Constructor: 0x803352
public:
};


class CAnimationC000 : public CAnimation { //Size 8CAh
//Constructor: 0x804D2B
public:
};


class CAnimationD000 : public CAnimation { //Size 7E4h
//Constructor: 0x800D4F
public:
};


class CAnimationE000 : public CAnimation { //Size 3278h
//Constructor: 0x81C723
public:
};


#endif //ANIMEXT_H