#ifndef ANIMEXT_H
#define ANIMEXT_H

#include "animcore.h"
#include "datatypes.h"
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
//0x10**, 0x11**
//Constructor: 0x8356F3
public:
	//AB6C00
	virtual LPCTSTR GetWalkingSound(WORD); //v6c

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

extern LPCTSTR (CAnimation1000::*CAnimation1000_GetWalkingSound)(WORD);

class CAnimation1200 : public CAnimation { //Size AC6h
//0x12**, 0x1X**
//Constructor: 0x82C8AE
public:
	//AB6B1C
	virtual LPCTSTR GetWalkingSound(WORD); //v6c

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

extern LPCTSTR (CAnimation1200::*CAnimation1200_GetWalkingSound)(WORD);

class CAnimation1300 : public CAnimation { //Size 7F4h
//0x13**
//Constructor: 0x8746B1
public:
	//AB7158
	virtual LPCTSTR GetWalkingSound(WORD); //v6c

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

extern LPCTSTR (CAnimation1300::*CAnimation1300_GetWalkingSound)(WORD);

class CAnimation2000 : public CAnimation { //Size E0Ch
//Constructor: 0x83D12A
public:
	//AB6DC8
	virtual LPCTSTR GetWalkingSound(WORD); //v6c

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
	CVidCell m_G1VidCellShadowExtend; //b46h
	CVidCell m_G2VidCellShadowBase; //c1ch
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

extern LPCTSTR (CAnimation2000::*CAnimation2000_GetWalkingSound)(WORD);

class CAnimation3000 : public CAnimation { //Size 1106h
//Constructor: 0x841063
public:
	//AB6EAC
};

class CAnimation4000 : public CAnimation { //Size 7E4h
//Constructor: 0x801EDE
public:
	//AB63F4
};

class CAnimation5000 : public CAnimation { //Size 16E0h
//Playable humanoids
//0x5***, 0x6***, except 0x6400-0x6405
//Constructor: 0x843678
public:
	CAnimation5000(WORD, ColorRangeValues&, DWORD);
	CAnimation5000& Construct(WORD, ColorRangeValues&, DWORD) { return *this; }

	//AB6F90
	virtual LPCTSTR GetWalkingSound(WORD); //v6c
};

extern CAnimation5000& (CAnimation5000::*CAnimation5000_Construct)(WORD, ColorRangeValues&, DWORD);
extern LPCTSTR (CAnimation5000::*CAnimation5000_GetWalkingSound)(WORD);

class CAnimation6400 : public CAnimation { //Size 36B0h
//0x6400-0x6405
//Constructor: 0x8586AC
public:
	//AB7074
	virtual LPCTSTR GetWalkingSound(WORD); //v6c
};

extern LPCTSTR (CAnimation6400::*CAnimation6400_GetWalkingSound)(WORD);

class CAnimation7000 : public CAnimation { //Size B2Ch
//0x7[015CE]*[01], 0x72*[0-3], 0x7[47]*[0-2], 0x7[68D]*0, 0x7[9A]*[0-4], 0x7B*[0-6]
//Constructor: 0x8176A5
public:
	//AB678C
	virtual LPCTSTR GetWalkingSound(WORD); //v6c

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

extern LPCTSTR (CAnimation7000::*CAnimation7000_GetWalkingSound)(WORD);

class CAnimation7300 : public CAnimation { //Size D3Ch
//0x7300, 0x7703, 0x7F00, all outliers of above
//Constructor: 0x807184
public:
	//AB66A0
	virtual LPCTSTR GetWalkingSound(WORD); //v6c
};

extern LPCTSTR (CAnimation7300::*CAnimation7300_GetWalkingSound)(WORD);

class CAnimation8000 : public CAnimation { //Size E02h
//Constructor: 0x839BE6
public:
	//AB6CE4
	virtual LPCTSTR GetWalkingSound(WORD); //v6c
};

extern LPCTSTR (CAnimation8000::*CAnimation8000_GetWalkingSound)(WORD);

class CAnimation9000 : public CAnimation { //Size C1Ah
//Constructor: 0x828165
public:
	//AB6954
	virtual LPCTSTR GetWalkingSound(WORD); //v6c
};

extern LPCTSTR (CAnimation9000::*CAnimation9000_GetWalkingSound)(WORD);

class CAnimationA000 : public CAnimation { //Size C1Ah
//Constructor: 0x82A22F
public:
	//AB6A38
	virtual LPCTSTR GetWalkingSound(WORD); //v6c
};

extern LPCTSTR (CAnimationA000::*CAnimationA000_GetWalkingSound)(WORD);

class CAnimationB000 : public CAnimation { //Size 8C2h
//Constructor: 0x803352
public:
	//AB64D8
};


class CAnimationC000 : public CAnimation { //Size 8CAh
//Constructor: 0x804D2B
public:
	//AB65BC
	virtual LPCTSTR GetWalkingSound(WORD); //v6c
};

extern LPCTSTR (CAnimationC000::*CAnimationC000_GetWalkingSound)(WORD);

class CAnimationD000 : public CAnimation { //Size 7E4h
//Constructor: 0x800D4F
public:
	//AB6310
};


class CAnimationE000 : public CAnimation { //Size 3278h
//Constructor: 0x81C723
public:
	//AB6870
};


#endif //ANIMEXT_H