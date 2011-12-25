#ifndef ANIMEXT_H
#define ANIMEXT_H

#include "animcore.h"
#include "datatypes.h"
#include "cstringex.h"
#include "arecore.h"

class CAnimation0000 : public CAnimation { //Size 976h
//Constructor: 0x7FAA53
public:
	//AB622C
	virtual ~CAnimation0000() {} //v0
	virtual bool CanUseMiddleVertList() { return true; } //v28

	CVidCell* m_pCurrentVidCell; //6d8h
	CVidCell* m_pAnimShadow; //6dch
	CVidCell m_AnimMain; //6e0h
	CVidCell m_AnimShadow; //7b6h
	VidPal u88c;
	char ub80;
	char u8b1;
	short u8b2;
	short u8b4;
	short wCurrentAnimationIdx; //8b6h
	short wCurrentOrientation; //8b8h
	char nOrientations; //8bah
	char u8bb; //pad
	int u8bc;
	CVidBitmap u8c0;
};

class CAnimation1000 : public CAnimation { //Size 73Ah
//0x10**, 0x11**
//Constructor: 0x8356F3
public:
	//AB6C00
	virtual ~CAnimation1000() {} //v0
	virtual LPCTSTR GetWalkingSound(short wTerrainCode); //v6c

	IECString sPrefix; //6d8h
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
	short wCurrentAnimationIdx; //724h
	short wCurrentOrientation; //726h
	BOOL bUseColorRange; //728h
	char nOrientations; //72ch, if wOrient > nOrient, use Extended VidCell
	char nParts; //72d, # parts per vidcell (e.g. MTANG1[1-4])
	int u72e;
	BOOL bUseExtendedVidCells; //732h
	int u736;
};

extern LPCTSTR (CAnimation1000::*CAnimation1000_GetWalkingSound)(short);

class CAnimation1200 : public CAnimation { //Size AC6h
//0x12**, 0x1X**
//Constructor: 0x82C8AE
public:
	//AB6B1C
	virtual ~CAnimation1200() {} //v0
	virtual LPCTSTR GetWalkingSound(short wTerrainCode); //v6c

	IECString sPrefix; //6d8h
	CVidCell* m_pCurrentVidCell; //6dch

	CVidCell* m_pCurrentVidCellBase; //6e0h
	CVidCell* m_pG1VidCellBase; //6e4h
	CVidCell* m_pG2VidCellBase; //6e8h
	CVidCell* m_pG3VidCellBase; //6ech
	CVidCell* m_pG4VidCellBase; //6f0h
	CVidCell* m_pG5VidCellBase; //6f4h

	VidPal vpColorRange; //6f8h
	short wCurrentAnimationIdx; //71ch
	short wCurrentOrientation; //71eh
	int u720;
	CVidBitmap* m_currentBitmap; //724h
	BOOL bUseColorRange; //728h
	CVidBitmap m_Bitmap1; //72ch
	CVidBitmap m_Bitmap2; //7e2h
	CVidBitmap m_Bitmap3; //898h
	CVidBitmap m_Bitmap4; //94eh
	CVidBitmap m_Bitmap5; //a04h
	char nOrientations; //abah, orientations until mirror
	char nParts; //abbh
	int uabc;
	int uac0;
	char cSuffix1; //ac4h
	char cSuffix2; //ac5h
};

extern LPCTSTR (CAnimation1200::*CAnimation1200_GetWalkingSound)(short);

class CAnimation1300 : public CAnimation { //Size 7F4h
//0x13**
//Constructor: 0x8746B1
public:
	//AB7158
	virtual ~CAnimation1300() {} //v0
	virtual bool CanUseMiddleVertList() { return bCanUseMiddleVertList; } //v28
	virtual LPCTSTR GetWalkingSound(short wTerrainCode); //v6c

	IECString sPrefix; //6d8h
	CVidCell* m_pCurrentVidCell; //6dch

	CVidCell* m_pCurrentVidCellBase; //6e0h
	CVidCell* m_pG1VidCellBase; //6e4h
	CVidCell* m_pG2VidCellBase; //6e8h

	VidPal vpColorRange; //6ech
	short wCurrentAnimationIdx; //710h
	short wCurrentOrientation; //712h
	short wShootAnimationIdx; //714h, = 3
	int u716;
	BOOL bUseColorRange; //71ah
	CVidBitmap u71e;
	char nOrientations; //7d4h
	char nParts; //7d5h
	int u7d6;
	char u7da;
	char u7db;
	int u7dc;
	int u7e0;
	int u7e4;
	char u7e8;
	char u7e9;
	BOOL bCanUseMiddleVertList; //7eah, retrieved as char (set to 1)
	int u7ee;
	char u7f2;
	char u7f3;
};

extern LPCTSTR (CAnimation1300::*CAnimation1300_GetWalkingSound)(short);

class CAnimation2000 : public CAnimation { //Size E0Ch
//Constructor: 0x83D12A
public:
	//AB6DC8
	virtual ~CAnimation2000() {} //v0
	virtual LPCTSTR GetWalkingSound(short wTerrainCode); //v6c

	IECString sPrefix; //6d8h
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

	short wCurrentAnimationIdx; //dech
	short wCurrentOrientation; //deeh
	int udf0;
	int udf4;
	BOOL bUseColorRange; //df8h
	IECString udfc;
	IECString ue00;
	bool m_bImmuneToDamage; //e04h
	char ue05; //pad
	int ue06;
	char nOrientations; //e0ah
	char ue0a; //pad
};

extern LPCTSTR (CAnimation2000::*CAnimation2000_GetWalkingSound)(short);

class CAnimation3000 : public CAnimation { //Size 1106h
//Constructor: 0x841063
public:
	//AB6EAC
	virtual ~CAnimation3000() {} //v0
	virtual BOOL CanBeTargetted() { return bCanBeTargetted; } //vc4

	IECString sPrefix; //6d8h
	CVidCell* m_pCurrentVidCell; //6dch

	CVidCell* m_pCurrentVidCellBase; //6e0h
	CVidCell* m_pCurrentVidCellExtend; //6e4

	CVidCell m_G1VidCellBase; //6e8h
	CVidCell m_G1VidCellExtend; //7beh
	CVidCell m_G2VidCellBase; //894h
	CVidCell m_G2VidCellExtend; //96ah
	CVidCell m_G3VidCellBase; //a40h
	CVidCell m_G3VidCellExtend; //b16h

	CVidCell* m_pCurrentVidCellHole; //bech
	CVidCell* m_pCurrentVidCellDGBase; //bf0h
	CVidCell* m_pCurrentVidCellDGExtend; //bf4h

	CVidCell m_DG1VidCellBase; //bf8h
	CVidCell m_DG1VidCellExtend; //cceh
	CVidCell m_DG2VidCellBase; //da4h
	CVidCell m_DG2VidCellExtend; //e7ah
	CVidCell m_DG3VidCellBase; //f50h
	CVidCell m_DG3VidCellExtend; //1026h

	short wCurrentAnimationIdx; //10fch
	short wCurrentOrientation; //10feh
	BOOL bCanBeTargetted; //1100h, set on SetAnimationSequence() when ankheg has SEQ_EMERGE/SEQ_HIDE
	char nOrientations; //1104h
	char u1105; //pad
};

class CAnimation4000 : public CAnimation { //Size 7E4h
//Constructor: 0x801EDE
public:
	//AB63F4
	virtual ~CAnimation4000() {} //v0
	virtual bool CanUseMiddleVertList() { return bCanUseMiddleVertList; } //v28

	CVidCell* m_pCurrentVidCellBase; //6d8h
	CVidCell* m_pCurrentVidCellExtend; //6dch
	
	CVidCell m_VidCell; //6e0h
	VidPal vpColorRangeBase; //7b6h
	short wCurrentAnimationIdx; //7dah
	short wCurrentOrientation; //7dch
	BOOL bUseColorRange; //7deh
	bool bCanUseMiddleVertList; //7e2h
	char u7e3; //pad
};

class CAnimation5000 : public CAnimation { //Size 16E0h
//Playable humanoids
//0x5***, 0x6***, except 0x6400-0x6405
//Constructor: 0x843678
public:
	CAnimation5000(unsigned short wAnimId, ColorRangeValues& colors, int nOrientation);
	CAnimation5000& Construct(unsigned short, ColorRangeValues&, int) { return *this; }

	//AB6F90
	virtual ~CAnimation5000() {} //v0
	virtual bool CanUseMiddleVertList() { return m_bCanUseMiddleVertList; } //v28
	virtual LPCTSTR GetWalkingSound(short wTerrainCode); //v6c

	IECString sPrefix; //6d8h, C<RACE><SEX>B
	IECString sPrefixAndArmorLevel; //6dch, C<RACE><SEX>B - main
	IECString u6e0; //WQ* (single weapon prefix?)
	IECString u6e4; //WQ*
	IECString u6e8; //WQ*
	char charCurrentArmorLevel; //6ech, suffix - main
	char charMaxArmorLevel; //6edh, suffix

	CVidCell* m_pCurrentVidCell; //6eeh
	CVidCell* m_pCurrentVidCellBase; //6f2h

	CVidCell m_G1xVidCell; //6f6h
	CVidCell m_CAxVidCell; //7cch
	CVidCell m_A1xVidCell; //8a2h
	CVidCell m_A3xVidCell; //978h
	CVidCell m_A5xVidCell; //a4eh
	VidPal ub24;
	
	IECString ub48;
	CVidCell* ub4c;
	CVidCell* ub50;
	CVidCell ub54;
	CVidCell uc2a;
	CVidCell ud00;
	CVidCell udd6;	
	VidPal ueac;
	
	IECString ued0;
	CVidCell* m_pCurrentVidCellShield; //ed4h
	CVidCell* ued8;	
	CVidCell uedc;
	CVidCell ufb2;
	CVidCell u1088;
	CVidCell u115e;	
	VidPal u1234;

	IECString u1258;
	CVidCell* u125c;
	CVidCell* u1260;	
	CVidCell u1264;
	CVidCell u133a;
	CVidCell u1410;
	CVidCell u14e6;
	CVidCell u15bc;
	VidPal u1692;

	short wCurrentAnimation; //16b6h
	short wCurrentOrientation; //16b8h
	BOOL bUseAuxiliaryVidCells; //16bah, group indices 1 and 2
	BOOL bUseAuxiliaryVidCells2; //16beh, group index 3
	BOOL u16c2;
	int u16c6;
	BOOL bUseColorRange; //16cah, for first group of VidCells, other groups automatically use VidPals
	
	//bit4: MELEE_1HLR_MASK (16)
	char m_weaponCode; //16ceh //4, 5, 16, 1, 2, 3, controls which animations to load up into first group
	char nOrientations; //16cfh
	char u16d0;
	bool m_bImmuneToDamage; //16d1h
	bool m_bCanUseMiddleVertList; //16d2h, only SAREVOK (X404) is false
	char u16d3; //armor level suffix char
	char u16d4; //armor level suffix char
	char u16d5;
	int u16d6;
	int u16da;
	char u16de; //final suffix (after armor level)
	char u16df; //pad
};

extern CAnimation5000& (CAnimation5000::*CAnimation5000_Construct)(unsigned short, ColorRangeValues&, int);
extern LPCTSTR (CAnimation5000::*CAnimation5000_GetWalkingSound)(short);

class CAnimation6400 : public CAnimation { //Size 36B0h
//0x6400-0x6405
//Constructor: 0x8586AC
public:
	//AB7074
	virtual ~CAnimation6400() {} //v0
	virtual bool CanUseMiddleVertList() { return m_bCanUseMiddleVertList; } //v28
	virtual LPCTSTR GetWalkingSound(short wTerrainCode); //v6c

	IECString sPrefix; //6d8h, C<RACE><SEX>C - main
	IECString u6dc; //CSHD
	IECString u6e0; //WP*
	IECString u6e4; //WP*
	char u6e8; //'1' - main
	char u6e9; //'4'

	CVidCell* m_pCurrentVidCell; //6eah
	CVidCell* m_pCurrentVidCellBase; //6eeh
	CVidCell* m_pCurrentVidCellExtend; //6f2h

	//main
	CVidCell m_G1xVidCellBase; //6f6h
	CVidCell m_G1xVidCellExtend; //7cch
	CVidCell m_W2xVidCellBase; //8a2h
	CVidCell m_W2xVidCellExtend; //978h
	CVidCell m_CAxVidCellBase; //a4eh
	CVidCell m_CAxVidCellExtend; //b24h
	CVidCell m_A1xVidCellBase; //bfah
	CVidCell m_A1xVidCellExtend; //cd0h
	CVidCell m_A3xVidCellBase; //da6h
	CVidCell m_A3xVidCellExtend; //e7ch
	CVidCell m_A5xVidCellBase; //f52h
	CVidCell m_A5xVidCellExtend; //1028h
	VidPal vpColorRangeBase; //10feh

	IECString u1122;
	CVidCell* u1126;
	CVidCell* u112a;
	CVidCell* u112e;
	CVidCell u1132;
	CVidCell u1208;
	CVidCell u12de;
	CVidCell u13b4;
	CVidCell u148a;
	CVidCell u1560;
	CVidCell u1636;
	CVidCell u170c;
	CVidCell u17e2;
	CVidCell u18b8;
	VidPal u198e;

	IECString u19b2;
	CVidCell* u19b6;
	CVidCell* u19ba;
	CVidCell* u19be;
	CVidCell u19c2;
	CVidCell u1a98;
	CVidCell u1b6e;
	CVidCell u1c44;
	CVidCell u1d1a;
	CVidCell u1df0;
	CVidCell u1ec6;
	CVidCell u1f9c;
	CVidCell u2072;
	CVidCell u2148;
	VidPal u221e;

	IECString u2242;
	CVidCell* u2246;
	CVidCell* u224a;
	CVidCell* u224e;
	CVidCell u2252;
	CVidCell u2328;
	CVidCell u23fe;
	CVidCell u24d4;
	CVidCell u25aa;
	CVidCell u2680;
	CVidCell u2756;
	CVidCell u282c;
	CVidCell u2902;
	CVidCell u29d8;
	CVidCell u2aae;
	CVidCell u2b84;
	VidPal u2c5a;

	//CSHD (if sprite mirror, Extends get X suffix)
	CVidCell* m_pCurrentXVidCell; //2c7eh
	CVidCell* m_pCurrentXVidCellBase; //2c82h
	CVidCell* m_pCurrentXVidCellExtend; //2c86h
	CVidCell m_G1VidCellBase; //2c8ah
	CVidCell m_G1VidCellExtend; //2d60h
	CVidCell m_W2VidCellBase; //2e36h
	CVidCell m_W2VidCellExtend; //2f0ch
	CVidCell m_CAVidCellBase; //2fe2h
	CVidCell m_CAVidCellExtend; //30b8h
	CVidCell m_A1VidCellBase; //318eh
	CVidCell m_A1VidCellExtend; //3264h
	CVidCell m_A3VidCellBase; //333ah
	CVidCell m_A3VidCellExtend; //3410h
	CVidCell m_A5VidCellBase; //34e6h
	CVidCell m_A5VidCellExtend; //35bch

	short wCurrentAnimation; //3692h
	short wCurrentOrientation; //3694h
	int u3696;
	int u369a;
	int u369e;
	int u36a2;
	BOOL bUseColorRange; //36a6h (toggle for first set only, others are always on)
	
	//bit0+1: load A1
	//bit0 only: load SA into A1 slot
	//bit1 only: load SX into A1 slot
	//bit2: load A1
	//bit3: load A3
	//bit4: load A5
	//bit5: load A2 into A1 slot
	//bit6: load A4 into A2 slot
	//bit7: load A6 into A5 slot
	char nFlags; //36aah
	char nOrientations; //36abh
	char u36ac;
	char u36ad;
	bool m_bCanUseMiddleVertList; //36aeh, only SAREVOK (X404) is false
	char u36af; //pad
};

extern LPCTSTR (CAnimation6400::*CAnimation6400_GetWalkingSound)(short);

class CAnimation7000 : public CAnimation { //Size B2Ch
//0x7[015CE]*[01], 0x72*[0-3], 0x7[47]*[0-2], 0x7[68D]*0, 0x7[9A]*[0-4], 0x7B*[0-6]
//Constructor: 0x8176A5
public:
	//AB678C
	virtual ~CAnimation7000() {} //v0
	virtual LPCTSTR GetWalkingSound(short wTerrainCode); //v6c

	IECString sPrefix; //6d8h
	CVidCell* m_pCurrentVidCell; //6dch

	CVidCell* m_pCurrentVidCellBase; //6e0h
	CVidCell* m_pCurrentVidCellExtend; //6e4h
	CVidCell m_G1VidCellBase; //6e8h
	CVidCell m_G1VidCellExtend; //7beh
	CVidCell m_G2VidCellBase; //894h
	CVidCell m_G2VidCellExtend; //96ah
	VidPal vpColorRangeBase; //a40h

	short wCurrentAnimation; //a64h
	short wCurrentOrientation; //a66h
	BOOL bUseColorRange; //a68h
	int ua6c;
	int ua70;
	CVidBitmap ua74;
	char ub2a;
	char nOrientations; //b2bh
};

extern LPCTSTR (CAnimation7000::*CAnimation7000_GetWalkingSound)(short);

class CAnimation7300 : public CAnimation { //Size D3Ch
//0x7300, 0x7703, 0x7F00, all outliers of above
//Constructor: 0x807184
public:
	//AB66A0
	virtual ~CAnimation7300() {} //v0
	virtual bool CanUseMiddleVertList() { return bCanUseMiddleVertList; } //v28
	virtual LPCTSTR GetWalkingSound(short wTerrainCode); //v6c

	IECString sPrefix; //6d8h
	CVidCell m_pCurrentVidCell; //6dch
	CVidCell m_pCurrentVidCellBase; //6e0h
	CVidCell m_G1VidCellBase; //6e4h
	CVidCell m_G2VidCellBase; //7bah
	VidPal vpColorRangeBase; //890h

	CVidCell* u8b4;
	CVidCell* u8b8;
	CVidCell u8bc;
	CVidCell u992;
	VidPal ua68;

	short wCurrentAnimation; //a8ch
	short wCurrentOrientation; //a8eh
	short wShootAnimationIdx; //a90h, = 3 or 4
	BOOL bUseColorRange; //a92h
	int ua96;
	int ua9a;
	CVidBitmap ua9e;
	int ub54;
	ResRef ub58;
	ResRef ub60;
	int ub68;
	int ub6c;
	char ub70;
	char nOrientations; //b71h
	BOOL bCanUseMiddleVertList; //b72h, retrieved as char (always 1)
	int ub76;
	int ub7a;
	char ub7e;
	char ub7f;

	BOOL bUseSecondAnim; //b80h, refers to below
	IECString sPrefix2; //b84h, if DisableBrightest == 1
	CVidCell* m_pCurrentVidCell2; //b88h
	CVidCell* m_pCurrentVidCellBase2; //b8ch
	CVidCell m_G1VidCellBase2; //b90h
	CVidCell m_G2VidCellBase2; //c66h
};

extern LPCTSTR (CAnimation7300::*CAnimation7300_GetWalkingSound)(short);

class CAnimation8000 : public CAnimation { //Size E02h
//Constructor: 0x839BE6
public:
	//AB6CE4
	virtual ~CAnimation8000() {} //v0
	virtual LPCTSTR GetWalkingSound(short wTerrainCode); //v6c

	IECString sPrefix; //6d8h
	CVidCell* m_pCurrentVidCell; //6dch
	CVidCell* m_pCurrentVidCellBase; //6e0h
	CVidCell* m_pCurrentVidCellExtend; //6e4h

	CVidCell m_G1VidCellBase; //6e8h
	CVidCell m_G1VidCellExtend; //7beh
	CVidCell m_G2VidCellBase; //894h
	CVidCell m_G2VidCellExtend; //96ah
	VidPal vpColorRange; //a40h

	CVidCell* ua64;
	CVidCell* ua68;
	CVidCell* ua6c;
	CVidCell ua70;
	CVidCell ub46;
	CVidCell uc1c;
	CVidCell ucf2;
	VidPal udc8;

	short wCurrentAnimation; //dech
	short wCurrentOrientation; //deeh
	int udf0;
	int udf4;
	char udf8;
	char nOrientations; //df9h
	IECString udfa; //S1/SS
	IECString udfe; //HB/BW
};

extern LPCTSTR (CAnimation8000::*CAnimation8000_GetWalkingSound)(short);

class CAnimation9000 : public CAnimation { //Size C1Ah
//Constructor: 0x828165
public:
	//AB6954
	virtual ~CAnimation9000() {} //v0
	virtual LPCTSTR GetWalkingSound(short wTerrainCode); //v6c

	IECString sPrefix; //6d8h
	CVidCell* m_pCurrentVidCell; //6dch
	CVidCell* m_pCurrentVidCellBase; //6e0h
	CVidCell* m_pCurrentVidCellExtend; //6e4h

	CVidCell m_G1VidCellBase; //6e8h
	CVidCell m_G1VidCellExtend; //7beh
	CVidCell m_G2VidCellBase; //894h
	CVidCell m_G2VidCellExtend; //96ah
	CVidCell m_G3VidCellBase; //a40h
	CVidCell m_G3VidCellExtend; //b16h
	VidPal vpColorRange; //bech

	short wCurrentAnimation; //c10h
	short wCurrentOrientation; //c12h
	BOOL bUseColorRange; //c14h
	char nOrientations; //c18h
	char uc19; //pad
};

extern LPCTSTR (CAnimation9000::*CAnimation9000_GetWalkingSound)(short);

class CAnimationA000 : public CAnimation { //Size C1Ah
//Constructor: 0x82A22F
public:
	//AB6A38
	virtual ~CAnimationA000() {} //v0
	virtual LPCTSTR GetWalkingSound(short wTerrainCode); //v6c

	IECString sPrefix; //6d8h
	CVidCell* m_pCurrentVidCell; //6dch
	CVidCell* m_pCurrentVidCellBase; //6e0h
	CVidCell* m_pCurrentVidCellExtend; //6e4h

	CVidCell m_G1VidCellBase; //6e8h
	CVidCell m_G1VidCellExtend; //7beh
	CVidCell m_G2VidCellBase; //894h
	CVidCell m_G2VidCellExtend; //96ah
	CVidCell m_G3VidCellBase; //a40h
	CVidCell m_G3VidCellExtend; //b16h
	VidPal vpColorRange; //bech

	short wCurrentAnimation; //c10h
	short wCurrentOrientation; //c12h
	BOOL bUseColorRange; //c14h
	char nOrientations; //c18h
	char uc19; //pad
};

extern LPCTSTR (CAnimationA000::*CAnimationA000_GetWalkingSound)(short);

class CAnimationB000 : public CAnimation { //Size 8C2h
//Constructor: 0x803352
public:
	//AB64D8
	virtual ~CAnimationB000() {} //v0

	CVidCell* m_pCurrentVidCell; //6d8h
	CVidCell* m_pCurrentVidCellBase; //6dch
	CVidCell* m_pCurrentVidCellExtend; //6e0h

	CVidCell m_G1VidCellBase; //6e4h
	CVidCell m_G1VidCellExtend; //7bah
	VidPal vpColorRange; //890h

	short wCurrentAnimation; //8b4h
	short wCurrentOrientation; //8b6h
	BOOL bUseColorRange; //8b8h
	BOOL bImmuneToDamage; //8bch
	char nOrientations; //8c0h
	char u8c1; //pad
};


class CAnimationC000 : public CAnimation { //Size 8CAh
//Constructor: 0x804D2B
public:
	//AB65BC
	virtual ~CAnimationC000() {} //v0
	virtual char GetDefaultVertListType() { return nDefaultVertListType; } //v3c
	virtual LPCTSTR GetWalkingSound(short wTerrainCode); //v6c

	IECString sPrefix; //6d8h
	CVidCell* m_pCurrentVidCell; //6dch
	CVidCell* m_pCurrentVidCellBase; //6e0h
	CVidCell* m_pCurrentVidCellExtend; //6e4h

	CVidCell m_G1VidCellBase; //6e8h
	CVidCell m_G1VidCellExtend; //7beh
	VidPal vpColorRange; //894h

	short wCurrentAnimation; //8b8h
	short wCurrentOrientation; //8bah
	BOOL bUseColorRange; //8bch
	int u8c0;
	int u8c4;
	char nDefaultVertListType; //8c8h, always LIST_FRONT except for C500 is LIST_BACK
	char nOrientations; //8c9h
};

extern LPCTSTR (CAnimationC000::*CAnimationC000_GetWalkingSound)(short);

class CAnimationD000 : public CAnimation { //Size 7E4h
//Constructor: 0x800D4F
public:
	//AB6310
	virtual ~CAnimationD000() {} //v0
	virtual bool CanUseMiddleVertList() { return false; } //v28
	virtual char GetDefaultVertListType() { return LIST_BACK; } //v3c

	CVidCell* m_pCurrentVidCell; //6d8h
	CVidCell* m_pCurrentVidCellBase; //6dch
	CVidCell m_G1VidCellBase; //6e0h
	VidPal vpColorRange; //7b6h

	short wCurrentAnimation; //7dah
	short wCurrentOrientation; //7dch
	BOOL bUseColorRange;; //7deh
	char nOrientations; //7e2h
	char u7e3; //pad
};

class CAnimationE000 : public CAnimation { //Size 3278h
//Constructor: 0x81C723
public:
	//AB6870
	virtual ~CAnimationE000() {} //v0
	virtual LPCTSTR GetWalkingSound(short wTerrainCode); //v6c

	IECString sPrefix; //6d8h
	CVidCell* m_pCurrentVidCell; //6dch
	CVidCell* m_pCurrentVidCellBase; //6e0h
	CVidCell* m_pCurrentVidCellExtend; //6e4h

	CVidCell u6e8; //A1
	CVidCell u7be; //A1E
	CVidCell u894; //A2
	CVidCell u96a; //A2E
	CVidCell ua40; //A3
	CVidCell ub16; //A2E (bugged, should be A3E)
	CVidCell ubec; //A4
	CVidCell ucc2; //A4E
	CVidCell ud98; //Gu
	CVidCell ue6e; //GuE
	CVidCell uf44; //Sl
	CVidCell u101a; //SlE
	CVidCell u10f0; //De
	CVidCell u11c6; //DeE
	CVidCell u129c; //GH
	CVidCell u1372; //GHE
	CVidCell u1448; //Sd
	CVidCell u151e; //SdE
	CVidCell u15f4; //Sc
	CVidCell u16ca; //ScE
	CVidCell u17a0; //Sp
	CVidCell u1876; //SpE
	CVidCell u194c; //Ca
	CVidCell u1a22; //CaE
	CVidCell u1af8; //Tw
	CVidCell u1bce; //TwE
	CVidCell u1ca4; //Wk
	CVidCell u1d7a; //WkE

	CVidCell* m_pCurrentVidCell2; //1e50h
	CVidCell* m_pCurrentVidCellBase2; //1e54h
	CVidCell* m_pCurrentVidCellExtend2; //1e58h

	CVidCell u1e5c;
	CVidCell u1f32;
	CVidCell u2008;
	CVidCell u20de;
	CVidCell u21b4;
	CVidCell u228a;
	CVidCell u2360;
	CVidCell u2436;
	CVidCell u250c;
	CVidCell u25e2;
	CVidCell u26b8;
	CVidCell u278e;
	CVidCell u2864;
	CVidCell u293a;
	CVidCell u2a10;
	CVidCell u2ae6;
	CVidCell u2bbc;
	CVidCell u2c92;
	CVidCell u2d68;
	CVidCell u2e3e;
	CVidCell u2f14;
	CVidCell u2fea;
	CVidCell u30c0;
	CVidCell u3196;

	short wCurrentOrientation; //326ch
	int u326e;
	int u3272;
	char u3276;
	char nOrientations; //3277h
};

extern LPCTSTR (CAnimationE000::*CAnimationE000_GetWalkingSound)(short);

#endif //ANIMEXT_H