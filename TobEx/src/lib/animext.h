#ifndef ANIMEXT_H
#define ANIMEXT_H

#include "animcore.h"
#include "cstringex.h"
#include "arecore.h"

class CAnimation0000 : public CAnimation { //Size 976h
//Constructor: 0x7FAA53
public:
	//AB622C
	virtual ~CAnimation0000() {} //v0
	virtual bool CanLieDown() { return true; } //v28

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

class CAnimation1300 : public CAnimation { //Size 7F4h
//0x13**
//Constructor: 0x8746B1
public:
	//AB7158
	virtual ~CAnimation1300() {} //v0
	virtual bool CanLieDown() { return m_bCanLieDown; } //v28
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
	BOOL m_bCanLieDown; //7eah, retrieved as char (set to 1)
	int u7ee;
	char u7f2;
	char u7f3;
};

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
	virtual bool CanLieDown() { return m_bCanLieDown; } //v28

	CVidCell* m_pCurrentVidCellBase; //6d8h
	CVidCell* m_pCurrentVidCellExtend; //6dch
	
	CVidCell m_VidCell; //6e0h
	VidPal vpColorRangeBase; //7b6h
	short wCurrentAnimationIdx; //7dah
	short wCurrentOrientation; //7dch
	BOOL bUseColorRange; //7deh
	bool m_bCanLieDown; //7e2h
	char u7e3; //pad
};

class CAnimation5000 : public CAnimation { //Size 16E0h
//Playable humanoids
//0x5***, 0x6***, except 0x6400-0x6405
//Constructor: 0x843678
public:
	CAnimation5000(unsigned short wAnimId, CreFileColors& colors, int nOrientation);
	CAnimation5000& Construct(unsigned short, CreFileColors&, int nOrientation) { return *this; }

	//AB6F90
	virtual ~CAnimation5000() {} //v0
	virtual bool CanLieDown() { return m_bCanLieDown; } //v28
	virtual LPCTSTR GetWalkingSound(short wTerrainCode); //v6c

	IECString sPrefix; //6d8h, C<RACE><SEX>B
	IECString sPrefixAndArmorLevel; //6dch, C<RACE><SEX>B - main
	IECString u6e0; //WQ* (single weapon prefix?)
	IECString u6e4; //WQ*
	IECString u6e8; //WQ*
	char cArmorLevelCurr; //6ech, suffix - main
	char cArmorLevelMax; //6edh, suffix

	//main creature
	CVidCell* m_pvcMainCurrent; //6eeh
	CVidCell* m_pvcMain; //6f2h
	CVidCell m_vcMainGen; //6f6h, G1
	CVidCell m_vcMainCast; //7cch
	CVidCell m_vcMainAttack1; //8a2h, A1/A2/A7 [1H/2H/dual-wield]
	CVidCell m_vcMainAttack2; //978h, A3/A4/A8
	CVidCell m_vcMainAttack3; //a4eh, A5/A6/A9
	VidPal ub24;
	
	//weapon
	IECString sWeaponPrefix; //b48h
	CVidCell* ub4c;
	CVidCell* ub50;
	CVidCell ub54; //G1
	CVidCell uc2a; //A1
	CVidCell ud00; //A3
	CVidCell udd6; //A5
	VidPal ueac;
	
	//shield
	IECString sShieldPrefix; //ed0h
	CVidCell* m_pvcShieldCurrent; //ed4h
	CVidCell* ued8;	
	CVidCell uedc;
	CVidCell ufb2;
	CVidCell u1088;
	CVidCell u115e;	
	VidPal u1234;

	//helm
	IECString sHelmPrefix; //1258h
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
	BOOL u16c6; //set to 1 when ITEMFLAG_BOW is set
	BOOL bUseColorRange; //16cah, for first group of VidCells, other groups automatically use VidPals
	
	//1: bow/arrow
	//2: xbow/bolt
	//3: sling/bullet
	//4: main weapon or no weapon
	//5: 2-handed weapon
	//11h: offhand only
	//13h: dual-wield
	//10h (bit4): MELEE_1HLR_MASK (16)
	char m_cWeaponCode; //16ceh, controls which animations to load up into first group
	char nOrientations; //16cfh
	char u16d0;
	bool m_bImmuneToDamage; //16d1h
	bool m_bCanLieDown; //16d2h, only SAREVOK (X404) is false
	char u16d3; //armor level suffix char
	char u16d4; //armor level suffix char
	char u16d5;
	int u16d6;
	int u16da;
	char u16de; //final suffix (after armor level)
	char u16df; //pad
};

class CAnimation6400 : public CAnimation { //Size 36B0h
//0x6400-0x6405
//Constructor: 0x8586AC
public:
	//AB7074
	virtual ~CAnimation6400() {} //v0
	virtual bool CanLieDown() { return m_bCanLieDown; } //v28
	virtual LPCTSTR GetWalkingSound(short wTerrainCode); //v6c

	IECString sMainPrefix; //6d8h, C<RACE><SEX>C, group1
	IECString sShadowPrefix; //u6dc, CSHD, group5
	IECString u6e0; //WP*, WPL, group2 group3
	IECString u6e4; //WP*, WPL, group4?
	char u6e8; //'1' - main
	char u6e9; //'4'

	//main creature animation (main prefix)
	CVidCell* m_pvcMainCurrent; //6eah
	CVidCell* m_pvcMainBase; //6eeh
	CVidCell* m_pvcMainExtend; //6f2h
	CVidCell m_vcMainGenBase; //6f6h, G1
	CVidCell m_vcMainGenExtend; //7cch
	CVidCell m_vcMainWalkBase; //8a2h, W2
	CVidCell m_vcMainWalkExtend; //978h
	CVidCell m_vcMainCastBase; //a4eh
	CVidCell m_vcMainCastExtend; //b24h
	CVidCell m_vcMainAttack1Base; //bfah, A1 (overhand)
	CVidCell m_vcMainAttack1Extend; //cd0h
	CVidCell m_vcMainAttack2Base; //da6h, A3 (backhand)
	CVidCell m_vcMainAttack2Extend; //e7ch
	CVidCell m_vcMainAttack3Base; //f52h, A5 (thrust)
	CVidCell m_vcMainAttack3Extend; //1028h
	VidPal m_vpMainColorRanges; //10feh

	//common to all weapons, uses 6e0 prefix, WP*<itemanim>[O]... (O if offhand)
	IECString sWeaponPrefix; //1122h
	CVidCell* m_pvcWeaponCurrent; //1126h
	CVidCell* m_pvcWeaponBase; //112ah
	CVidCell* m_pvcWeaponExtend; //112eh
	CVidCell m_vcWeaponGenBase; //1132h
	CVidCell m_vcWeaponGenExtend; //1208h
	CVidCell m_vcWeaponWalkBase; //12deh
	CVidCell m_vcWeaponWalkExtend; //13b4h
	CVidCell m_vcWeaponAttack1Base; //148ah
	CVidCell m_vcWeaponAttack1Extend; //1560h
	CVidCell m_vcWeaponAttack2Base; //1636h
	CVidCell m_vcWeaponAttack2Extend; //170ch
	CVidCell m_vcWeaponAttack3Base; //17e2h
	CVidCell m_vcWeaponAttack3Extend; //18b8h
	VidPal m_vpWeaponColorRanges; //198eh

	//shield, uses 6e0 prefix
	IECString sShieldPrefix; //19b2h
	CVidCell* m_pvcShieldCurrent; //19b6h
	CVidCell* m_pvcShieldBase; //19bah
	CVidCell* m_pvcShieldExtend; //19beh
	CVidCell m_vcShieldGenBase; //19c2h
	CVidCell m_vcShieldGenExtend; //1a98h
	CVidCell m_vcShieldWalkBase; //1b6eh
	CVidCell m_vcShieldWalkExtend; //1c44h
	CVidCell m_vcShieldAttack1Base; //1d1ah
	CVidCell m_vcShieldAttack1Extend; //1df0h
	CVidCell m_vcShieldAttack2Base; //1ec6h
	CVidCell m_vcShieldAttack2Extend; //1f9ch
	CVidCell m_vcShieldAttack3Base; //1ec6h
	CVidCell m_vcShieldAttack3Extend; //2148h
	VidPal m_vpShieldColorRanges; //221eh

	//helmet, uses 6e4 prefix
	IECString sHelmPrefix; //u2242
	CVidCell* m_pvcHelmCurrent; //u2246
	CVidCell* m_pvcHelmBase; //u224a
	CVidCell* m_pvcHelmExtend; //u224e
	CVidCell m_vcHelmGenBase; //u2252
	CVidCell m_vcHelmGenExtend; //u2328
	CVidCell m_vcHelmWalkBase; //u23fe
	CVidCell m_vcHelmWalkExtend; //u24d4
	CVidCell m_vcHelmCastBase; //u25aa
	CVidCell m_vcHelmCastExtend; //u2680
	CVidCell m_vcHelmAttack1Base; //u2756
	CVidCell m_vcHelmAttack1Extend; //u282c
	CVidCell m_vcHelmAttack2Base; //u2902
	CVidCell m_vcHelmAttack2Extend; //u29d8
	CVidCell m_vcHelmAttack3Base; //u2aae
	CVidCell m_vcHelmAttack3Extend; //u2b84
	VidPal m_vpHelmColorRanges; //u2c5a

	//CSHD Shadow (if sprite mirror, Extends get X suffix)
	CVidCell* m_pvcShadowCurrent; //2c7eh
	CVidCell* m_pvcShadowBase; //2c82h
	CVidCell* m_pvcShadowExtend; //2c86h
	CVidCell m_vcShadowGenBase; //2c8ah
	CVidCell m_vcShadowGenExtend; //2d60h
	CVidCell m_vcShadowWalkBase; //2e36h
	CVidCell m_vcShadowWalkExtend; //2f0ch
	CVidCell m_vcShadowCastBase; //2fe2h
	CVidCell m_vcShadowCastExtend; //30b8h
	CVidCell m_vcShadowAttack1Base; //318eh
	CVidCell m_vcShadowAttack1Extend; //3264h
	CVidCell m_vcShadowAttack2Base; //333ah
	CVidCell m_vcShadowAttack2Extend; //3410h
	CVidCell m_vcShadowAttack3Base; //34e6h
	CVidCell m_vcShadowAttack3Extend; //35bch

	short m_wCurrentAnimation; //3692h
	short m_wCurrentOrientation; //3694h
	int u3696;
	int u369a;
	int u369e;
	BOOL u36a2; //set when ITEMFLAG_BOW is set
	BOOL m_bUseColorRange; //36a6h (toggle for first set only, others are always on)
	
	//local attack prob (size 3)
	//0: 1 = overhand, bow/arrow, xbow/bolt, sling/bullet
	//1: 1 = backhand
	//2: 1 = thrust

	//bit0+1: load A1 (sling/bullet)
	//bit0 only: load SA into A1 slot (bow/arrow)
	//bit1 only: load SX into A1 slot (xbow/bolt)
	//bit2: load A1 (one hand overhand)
	//bit3: load A3 (one hand backhand)
	//bit4: load A5 (one hand thrust)
	//bit5: load A2 into A1 slot (two hand overhand)
	//bit6: load A4 into A2 slot (two hand backhand)
	//bit7: load A6 into A5 slot (two hand thrust)
	char m_cWeaponCode; //36aah
	char nOrientations; //36abh
	char u36ac;
	char u36ad;
	bool m_bCanLieDown; //36aeh, only SAREVOK (X404) is false
	char u36af; //pad
};

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

class CAnimation7300 : public CAnimation { //Size D3Ch
//0x7300, 0x7703, 0x7F00, all outliers of above
//Constructor: 0x807184
public:
	//AB66A0
	virtual ~CAnimation7300() {} //v0
	virtual bool CanLieDown() { return m_bCanLieDown; } //v28
	virtual LPCTSTR GetWalkingSound(short wTerrainCode); //v6c

	IECString sPrefix; //6d8h
	CVidCell* m_pCurrentVidCell; //6dch
	CVidCell* m_pCurrentVidCellBase; //6e0h
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
	BOOL m_bCanLieDown; //b72h, retrieved as char (always 1)
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
	virtual char GetListType() { return m_nListType; } //v3c
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
	char m_nListType; //8c8h, always LIST_FRONT except for C500 is LIST_2
	char nOrientations; //8c9h
};

class CAnimationD000 : public CAnimation { //Size 7E4h
//Constructor: 0x800D4F
public:
	//AB6310
	virtual ~CAnimationD000() {} //v0
	virtual bool CanLieDown() { return false; } //v28
	virtual char GetListType() { return LIST_2; } //v3c

	CVidCell* m_pCurrentVidCell; //6d8h
	CVidCell* m_pCurrentVidCellBase; //6dch
	CVidCell m_G1VidCellBase; //6e0h
	VidPal vpColorRange; //7b6h

	short wCurrentAnimation; //7dah
	short wCurrentOrientation; //7dch
	BOOL bUseColorRange; //7deh
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

#endif //ANIMEXT_H