//TobExEE
#ifndef ANIMEXT_H
#define ANIMEXT_H

#include "animcore.h"
#include "cstringex.h"
#include "arecore.h"

class CAnimation0000 : public CAnimation { //Size 948h
public:
	virtual ~CAnimation0000() {} //v0

	CVidCell* m_pCurrentVidCell; //6d0h
	CVidCell* m_pAnimShadow; //6d4h
	CVidCell m_AnimMain; //6d8h
	CVidCell m_AnimShadow; //79ch
	VidPal u860;
	char u884;
	char u885;
	short u886;
	short u888;
	short m_wCurrentAnimationIdx; //88ah
	short m_wCurrentOrientation; //88ch
	char m_nOrientations; //88eh
	char p88f;
	int u890;
	CVidBitmap u894;
};

class CAnimation1000 : public CAnimation { //Size 734h
//0x10**, 0x11**
public:
	virtual ~CAnimation1000() {} //v0

	IECString m_sPrefix; //6d0h
	CVidCell* m_pCurrentVidCell; //6d4h

	CVidCell* m_pCurrentVidCellBase; //6d8h
	//each contains nVidCells
	CVidCell* m_pG1VidCellBase; //6dch
	CVidCell* m_pG2VidCellBase; //6e0h
	CVidCell* m_pG3VidCellBase; //6e4h

	CVidCell* m_currentVidCellExtend; //6e8h
	//each contains nVidCells
	CVidCell* m_pG1VidCellExtend; //6ech
	CVidCell* m_pG2VidCellExtend; //6f0h
	CVidCell* m_pG3VidCellExtend; //6f4h

	VidPal m_vpColorRange; //6f8h
	short m_wCurrentAnimationIdx; //71ch
	short m_wCurrentOrientation; //71eh
	BOOL m_bUseColorRange; //720h
	char m_nOrientations; //724h, if wOrient > nOrient, use Extended VidCell
	char m_nParts; //725h, # parts per vidcell (e.g. MTANG1[1-4])
	char p726[2];
	int u728;
	BOOL m_bUseExtendedVidCells; //72ch
	int u730;
};

class CAnimation1200 : public CAnimation { //Size AB8h
//0x12**, 0x1X**
public:
	virtual ~CAnimation1200() {} //v0

	IECString m_sPrefix; //6d0h
	CVidCell* m_pCurrentVidCell; //6d4h

	CVidCell* m_pCurrentVidCellBase; //6d8h
	CVidCell* m_pG1VidCellBase; //6dch
	CVidCell* m_pG2VidCellBase; //6e0h
	CVidCell* m_pG3VidCellBase; //6e4h
	CVidCell* m_pG4VidCellBase; //6e8h
	CVidCell* m_pG5VidCellBase; //6ech

	VidPal m_vpColorRange; //6f0h
	short m_wCurrentAnimationIdx; //714h
	short m_wCurrentOrientation; //716h
	int u718;
	CVidBitmap* m_currentBitmap; //71ch
	BOOL m_bUseColorRange; //720h
	CVidBitmap m_Bitmap1; //724h
	CVidBitmap m_Bitmap2; //7d8h
	CVidBitmap m_Bitmap3; //88ch
	CVidBitmap m_Bitmap4; //940h
	CVidBitmap m_Bitmap5; //9f4h
	char m_nOrientations; //aa8h, orientations until mirror
	char m_nParts; //aa9h
	char paaa[2];
	int uaac;
	int uab0;
	char m_cSuffix1; //ab4h
	char m_cSuffix2; //ab5h
	char pab6[2];
};

class CAnimation1300 : public CAnimation { //Size 7F4h
//0x13**
public:
	virtual ~CAnimation1300() {} //v0

	IECString m_sPrefix; //6d0h
	CVidCell* m_pCurrentVidCell; //6d4h

	CVidCell* m_pCurrentVidCellBase; //6d8h
	CVidCell* m_pG1VidCellBase; //6dch
	CVidCell* m_pG2VidCellBase; //6e0h

	VidPal m_vpColorRange; //6e4h
	short m_wCurrentAnimationIdx; //708h
	short m_wCurrentOrientation; //70ah
	short m_wShootAnimationIdx; //70ch, = 3
	char p70e[2];
	int u710;
	BOOL m_bUseColorRange; //714h
	CVidBitmap u718;
	char m_nOrientations; //7cch
	char m_nParts; //7cdh
	char p7ce[2];
	int u7d0;
	char u7d4;
	char u7d5;
	char p7d6[2];
	int u7d8;
	int u7dc;
	int u7e0;
	char u7e4;
	char u7e5;
	char p7e6[2];
	BOOL m_bCanLieDown; //7e8h, retrieved as char (set to 1)
	int u7ec;
	char u7f0;
	char u7f1;
	char p7f2[2];
};

class CAnimation2000 : public CAnimation { //Size D78h
public:
	virtual ~CAnimation2000() {} //v0

	IECString m_sPrefix; //6d0h
	CVidCell* m_pCurrentVidCell; //6d4h

	CVidCell* m_pCurrentVidCellBase; //6d8h
	CVidCell* m_pCurrentVidCellExtend; //6dch
	CVidCell m_G1VidCellBase; //6e0h
	CVidCell m_G1VidCellExtend; //7a4h
	CVidCell m_G2VidCellBase; //868h
	CVidCell m_G2VidCellExtend; //92ch
	VidPal m_vpColorRangeBase; //9f0h

	CVidCell* m_pCurrentVidCellShadow; //a14h
	
	CVidCell* m_pCurrentVidCellShadowBase; //a18h
	CVidCell* m_pCurrentVidCellShadowExtend; //a1ch
	CVidCell m_G1VidCellShadowBase; //a20h
	CVidCell m_G1VidCellShadowExtend; //ae4h
	CVidCell m_G2VidCellShadowBase; //ba8h
	CVidCell m_G2VidCellShadowExtend; //c6ch
	VidPal m_vpColorRangeExtend; //d30h

	short m_wCurrentAnimationIdx; //d54h
	short m_wCurrentOrientation; //d56h
	int ud58;
	int ud5c;
	BOOL m_bUseColorRange; //d60h
	IECString ud64;
	IECString ud68;
	bool m_bImmuneToDamage; //d6ch
	char pd6d;
	char pde6[2];
	int ud70;
	char m_nOrientations; //d74h
	char pd75;
	char pd76[2];
};

class CAnimation3000 : public CAnimation { //Size 1028h
public:
	virtual ~CAnimation3000() {} //v0

	IECString m_sPrefix; //6d0h
	CVidCell* m_pCurrentVidCell; //6d4h

	CVidCell* m_pCurrentVidCellBase; //6d8h
	CVidCell* m_pCurrentVidCellExtend; //6dch

	CVidCell m_G1VidCellBase; //6e0h
	CVidCell m_G1VidCellExtend; //7a4h
	CVidCell m_G2VidCellBase; //868h
	CVidCell m_G2VidCellExtend; //92ch
	CVidCell m_G3VidCellBase; //af0h
	CVidCell m_G3VidCellExtend; //ab4h

	CVidCell* m_pCurrentVidCellHole; //b78h
	CVidCell* m_pCurrentVidCellDGBase; //b7ch
	CVidCell* m_pCurrentVidCellDGExtend; //b80h

	CVidCell m_DG1VidCellBase; //b84h
	CVidCell m_DG1VidCellExtend; //c48h
	CVidCell m_DG2VidCellBase; //d0ch
	CVidCell m_DG2VidCellExtend; //dd0h
	CVidCell m_DG3VidCellBase; //e94h
	CVidCell m_DG3VidCellExtend; //f58h

	short m_wCurrentAnimationIdx; //101ch
	short m_wCurrentOrientation; //101eh
	BOOL m_bCanBeTargetted; //1020h, set on SetAnimationSequence() when ankheg has SEQ_EMERGE/SEQ_HIDE
	char m_nOrientations; //1024h
	char p1025;
	char p1026[2];
};

class CAnimation4000 : public CAnimation { //Size 7CCh
public:
	virtual ~CAnimation4000() {} //v0

	CVidCell* m_pCurrentVidCellBase; //6d0h
	CVidCell* m_pCurrentVidCellExtend; //6d4h
	
	CVidCell m_VidCell; //6d8h
	VidPal vpColorRangeBase; //79ch
	short wCurrentAnimationIdx; //7c0h
	short wCurrentOrientation; //7c2h
	BOOL bUseColorRange; //7c4h
	bool m_bCanLieDown; //7c8h
	char p7c9[3];
};

class CAnimation5000 : public CAnimation { //Size 1598h
//Playable humanoids
//0x5***, 0x6***, except 0x6400-0x6405
public:
	virtual ~CAnimation5000() {} //v0

	IECString sPrefix; //6d0h, C<RACE><SEX>B
	IECString sPrefixAndArmorLevel; //6d4h, C<RACE><SEX>B - main
	IECString u6d8; //WQ* (single weapon prefix?)
	IECString u6dc; //WQ*
	IECString u6e0; //WQ*
	char cArmorLevelCurr; //6e4h, suffix - main
	char cArmorLevelMax; //6e5h, suffix
	char p6e6[2];

	//main creature
	CVidCell* m_pvcMainCurrent; //6e8h
	CVidCell* m_pvcMain; //6ech
	CVidCell m_vcMainGen; //6f0h, G1
	CVidCell m_vcMainCast; //7b4h
	CVidCell m_vcMainAttack1; //878h, A1/A2/A7 [1H/2H/dual-wield]
	CVidCell m_vcMainAttack2; //93ch, A3/A4/A8
	CVidCell m_vcMainAttack3; //a00h, A5/A6/A9
	VidPal uac4;
	
	//weapon
	IECString sWeaponPrefix; //ae8h
	CVidCell* uaec;
	CVidCell* uaf0;
	CVidCell uaf4; //G1
	CVidCell ubb8; //A1
	CVidCell uc7c; //A3
	CVidCell ud40; //A5
	VidPal ue04;
	
	//shield
	IECString sShieldPrefix; //e28h
	CVidCell* m_pvcShieldCurrent; //e2ch
	CVidCell* ue30;	
	CVidCell ue34;
	CVidCell uef8;
	CVidCell ufbc;
	CVidCell u1080;	
	VidPal u1144;

	//helm
	IECString sHelmPrefix; //1168h
	CVidCell* u116c;
	CVidCell* u1170;	
	CVidCell u1174;
	CVidCell u1238;
	CVidCell u12fc;
	CVidCell u13c0;
	CVidCell u1484;
	VidPal u1548;

	short wCurrentAnimation; //156ch
	short wCurrentOrientation; //156eh
	BOOL bUseAuxiliaryVidCells; //1570h, group indices 1 and 2
	BOOL bUseAuxiliaryVidCells2; //1574h, group index 3
	BOOL u1578;
	BOOL u157c; //set to 1 when ITEMFLAG_BOW is set
	BOOL bUseColorRange; //1580h, for first group of VidCells, other groups automatically use VidPals
	
	//1: bow/arrow
	//2: xbow/bolt
	//3: sling/bullet
	//4: main weapon or no weapon
	//5: 2-handed weapon
	//11h: offhand only
	//13h: dual-wield
	//10h (bit4): MELEE_1HLR_MASK (16)
	char m_cWeaponCode; //1584h, controls which animations to load up into first group
	char nOrientations; //1585h
	char u1586;
	bool m_bImmuneToDamage; //1587h
	bool m_bCanLieDown; //1588h, only SAREVOK (X404) is false
	char u1589; //armor level suffix char
	char u158a; //armor level suffix char
	char u158b;
	int u158c;
	int u1590;
	char u1594; //final suffix (after armor level)
	char p1595[3];
};

class CAnimation6400 : public CAnimation { //Size 32BCh
//0x6400-0x6405
public:
	virtual ~CAnimation6400() {} //v0

	IECString sMainPrefix; //6d0h, C<RACE><SEX>C, group1
	IECString sShadowPrefix; //6d4h, CSHD, group5
	IECString u6d8; //WP*, WPL, group2 group3
	IECString u6dc; //WP*, WPL, group4?
	char u6e0; //'1' - main
	char u6e1; //'4'
	char p6e2[2];

	//main creature animation (main prefix)
	CVidCell* m_pvcMainCurrent; //6e4h
	CVidCell* m_pvcMainBase; //6e8h
	CVidCell* m_pvcMainExtend; //6ech
	CVidCell m_vcMainGenBase; //6f0h, G1
	CVidCell m_vcMainGenExtend; //7b4h
	CVidCell m_vcMainWalkBase; //878h, W2
	CVidCell m_vcMainWalkExtend; //93ch
	CVidCell m_vcMainCastBase; //a00h
	CVidCell m_vcMainCastExtend; //ac4h
	CVidCell m_vcMainAttack1Base; //b88h, A1 (overhand)
	CVidCell m_vcMainAttack1Extend; //c4ch
	CVidCell m_vcMainAttack2Base; //d10h, A3 (backhand)
	CVidCell m_vcMainAttack2Extend; //ed4h
	CVidCell m_vcMainAttack3Base; //e98h, A5 (thrust)
	CVidCell m_vcMainAttack3Extend; //f5ch
	VidPal m_vpMainColorRanges; //1020h

	//common to all weapons, uses 6e0 prefix, WP*<itemanim>[O]... (O if offhand)
	IECString sWeaponPrefix; //1044h
	CVidCell* m_pvcWeaponCurrent; //1048h
	CVidCell* m_pvcWeaponBase; //104ch
	CVidCell* m_pvcWeaponExtend; //1050h
	CVidCell m_vcWeaponGenBase; //1054h
	CVidCell m_vcWeaponGenExtend; //1118h
	CVidCell m_vcWeaponWalkBase; //11dch
	CVidCell m_vcWeaponWalkExtend; //12a0h
	CVidCell m_vcWeaponAttack1Base; //1364h
	CVidCell m_vcWeaponAttack1Extend; //1428h
	CVidCell m_vcWeaponAttack2Base; //14ech
	CVidCell m_vcWeaponAttack2Extend; //15b0h
	CVidCell m_vcWeaponAttack3Base; //1674h
	CVidCell m_vcWeaponAttack3Extend; //1738h
	VidPal m_vpWeaponColorRanges; //17fch

	//shield, uses 6e0 prefix
	IECString sShieldPrefix; //1820h
	CVidCell* m_pvcShieldCurrent; //1824h
	CVidCell* m_pvcShieldBase; //1828h
	CVidCell* m_pvcShieldExtend; //182ch
	CVidCell m_vcShieldGenBase; //1830h
	CVidCell m_vcShieldGenExtend; //18f4h
	CVidCell m_vcShieldWalkBase; //19b8h
	CVidCell m_vcShieldWalkExtend; //1a7ch
	CVidCell m_vcShieldAttack1Base; //1b40h
	CVidCell m_vcShieldAttack1Extend; //1c04h
	CVidCell m_vcShieldAttack2Base; //1cc8h
	CVidCell m_vcShieldAttack2Extend; //1d8ch
	CVidCell m_vcShieldAttack3Base; //1e50h
	CVidCell m_vcShieldAttack3Extend; //1f14h
	VidPal m_vpShieldColorRanges; //1fd8h

	//helmet, uses 6e4 prefix
	IECString sHelmPrefix; //1ffch
	CVidCell* m_pvcHelmCurrent; //2000h
	CVidCell* m_pvcHelmBase; //2004h
	CVidCell* m_pvcHelmExtend; //2008h
	CVidCell m_vcHelmGenBase; //200ch
	CVidCell m_vcHelmGenExtend; //20d0h
	CVidCell m_vcHelmWalkBase; //2194h
	CVidCell m_vcHelmWalkExtend; //2258h
	CVidCell m_vcHelmCastBase; //231ch
	CVidCell m_vcHelmCastExtend; //23e0h
	CVidCell m_vcHelmAttack1Base; //24a4h
	CVidCell m_vcHelmAttack1Extend; //2568h
	CVidCell m_vcHelmAttack2Base; //262ch
	CVidCell m_vcHelmAttack2Extend; //26f0h
	CVidCell m_vcHelmAttack3Base; //27b4h
	CVidCell m_vcHelmAttack3Extend; //2878h
	VidPal m_vpHelmColorRanges; //293ch

	//CSHD Shadow (if sprite mirror, Extends get X suffix)
	CVidCell* m_pvcShadowCurrent; //2960h
	CVidCell* m_pvcShadowBase; //2964h
	CVidCell* m_pvcShadowExtend; //2968h
	CVidCell m_vcShadowGenBase; //296ch
	CVidCell m_vcShadowGenExtend; //2a30h
	CVidCell m_vcShadowWalkBase; //2af4h
	CVidCell m_vcShadowWalkExtend; //2bb8h
	CVidCell m_vcShadowCastBase; //2c7ch
	CVidCell m_vcShadowCastExtend; //2d40h
	CVidCell m_vcShadowAttack1Base; //2e04h
	CVidCell m_vcShadowAttack1Extend; //2ec8h
	CVidCell m_vcShadowAttack2Base; //2f8ch
	CVidCell m_vcShadowAttack2Extend; //3050h
	CVidCell m_vcShadowAttack3Base; //3114h
	CVidCell m_vcShadowAttack3Extend; //31d8h

	short m_wCurrentAnimation; //329ch
	short m_wCurrentOrientation; //329eh
	int u32a0;
	int u32a4;
	int u32a8;
	BOOL u32ac; //set when ITEMFLAG_BOW is set
	BOOL m_bUseColorRange; //32b0h (toggle for first set only, others are always on)
	
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
	char m_cWeaponCode; //32b4h
	char nOrientations; //32b5h
	char u32b6;
	char u32b7;
	bool m_bCanLieDown; //32b8h, only SAREVOK (X404) is false
	char p32b9[3];;
};

class CAnimation7000 : public CAnimation { //Size ADCh
//0x7[015CE]*[01], 0x72*[0-3], 0x7[47]*[0-2], 0x7[68D]*0, 0x7[9A]*[0-4], 0x7B*[0-6]
public:
	virtual ~CAnimation7000() {} //v0

	IECString sPrefix; //6d0h
	CVidCell* m_pCurrentVidCell; //6d4h

	CVidCell* m_pCurrentVidCellBase; //6d8h
	CVidCell* m_pCurrentVidCellExtend; //6dch
	CVidCell m_G1VidCellBase; //6e0h
	CVidCell m_G1VidCellExtend; //7a4h
	CVidCell m_G2VidCellBase; //868h
	CVidCell m_G2VidCellExtend; //92ch
	VidPal vpColorRangeBase; //9f0h

	short wCurrentAnimation; //a14h
	short wCurrentOrientation; //a16h
	BOOL bUseColorRange; //a18h
	int ua1c;
	int ua20;
	CVidBitmap ua24;
	char uad8;
	char nOrientations; //ad9h
	char pada[2];
};

class CAnimation7300 : public CAnimation { //Size CCCh
//0x7300, 0x7703, 0x7F00, all outliers of above
public:
	virtual ~CAnimation7300() {} //v0

	IECString sPrefix; //6d0h
	CVidCell* m_pCurrentVidCell; //6d4h
	CVidCell* m_pCurrentVidCellBase; //6d8h
	CVidCell m_G1VidCellBase; //6dch
	CVidCell m_G2VidCellBase; //7a0h
	VidPal vpColorRangeBase; //864h

	CVidCell* u888;
	CVidCell* u88c;
	CVidCell u890;
	CVidCell u954;
	VidPal ua18;

	short wCurrentAnimation; //a3ch
	short wCurrentOrientation; //a3eh
	short wShootAnimationIdx; //a40h, = 3 or 4
	char pa42[2];
	BOOL bUseColorRange; //a44h
	int ua48;
	int ua4c;
	CVidBitmap ua50;
	int ub04;
	ResRef ub08;
	ResRef ub10;
	int ub18;
	int ub1c;
	char ub20;
	char nOrientations; //b21h
	char pb22[2];
	BOOL m_bCanLieDown; //b24h, retrieved as char (always 1)
	int ub28;
	int ub2c;
	char ub30;
	char ub31;
	char pb32[2];

	BOOL bUseSecondAnim; //b34h, refers to below
	IECString sPrefix2; //b38h, if DisableBrightest == 1
	CVidCell* m_pCurrentVidCell2; //b3ch
	CVidCell* m_pCurrentVidCellBase2; //b40h
	CVidCell m_G1VidCellBase2; //b44h
	CVidCell m_G2VidCellBase2; //c08h
};

class CAnimation8000 : public CAnimation { //Size D6Ch
public:
	virtual ~CAnimation8000() {} //v0

	IECString sPrefix; //6d0h
	CVidCell* m_pCurrentVidCell; //6d4h
	CVidCell* m_pCurrentVidCellBase; //6d8h
	CVidCell* m_pCurrentVidCellExtend; //6dch

	CVidCell m_G1VidCellBase; //6e0h
	CVidCell m_G1VidCellExtend; //7a4h
	CVidCell m_G2VidCellBase; //868h
	CVidCell m_G2VidCellExtend; //92ch
	VidPal vpColorRange; //9f0h

	CVidCell* ua14;
	CVidCell* ua18;
	CVidCell* ua1c;
	CVidCell ua20;
	CVidCell uae4;
	CVidCell uba8;
	CVidCell uc6c;
	VidPal ud30;

	short wCurrentAnimation; //d54h
	short wCurrentOrientation; //d56h
	int ud58;
	int ud5c;
	char ud60;
	char nOrientations; //d61h
	char pd62[2];
	IECString ud64; //S1/SS
	IECString ud68; //HB/BW
};

class CAnimation9000 : public CAnimation { //Size BA8h
public:
	virtual ~CAnimation9000() {} //v0

	IECString sPrefix; //6d0h
	CVidCell* m_pCurrentVidCell; //6d4h
	CVidCell* m_pCurrentVidCellBase; //6d8h
	CVidCell* m_pCurrentVidCellExtend; //6dch

	CVidCell m_G1VidCellBase; //6e0h
	CVidCell m_G1VidCellExtend; //7a4h
	CVidCell m_G2VidCellBase; //868h
	CVidCell m_G2VidCellExtend; //92ch
	CVidCell m_G3VidCellBase; //9f0h
	CVidCell m_G3VidCellExtend; //ab4h
	VidPal vpColorRange; //b78h

	short wCurrentAnimation; //b9ch
	short wCurrentOrientation; //b9eh
	BOOL bUseColorRange; //ba0h
	char nOrientations; //ba4h
	char pba5[3];
};

class CAnimationA000 : public CAnimation { //Size BA8h
public:
	virtual ~CAnimationA000() {} //v0

	IECString sPrefix; //6d0h
	CVidCell* m_pCurrentVidCell; //6d4h
	CVidCell* m_pCurrentVidCellBase; //6d8h
	CVidCell* m_pCurrentVidCellExtend; //6dch

	CVidCell m_G1VidCellBase; //6e0h
	CVidCell m_G1VidCellExtend; //7a4h
	CVidCell m_G2VidCellBase; //868h
	CVidCell m_G2VidCellExtend; //92ch
	CVidCell m_G3VidCellBase; //9f0h
	CVidCell m_G3VidCellExtend; //ab4h
	VidPal vpColorRange; //b78h

	short wCurrentAnimation; //b9ch
	short wCurrentOrientation; //b9eh
	BOOL bUseColorRange; //ba0h
	char nOrientations; //ba4h
	char pba5[3];
};

class CAnimationB000 : public CAnimation { //Size 898h
public:
	virtual ~CAnimationB000() {} //v0

	CVidCell* m_pCurrentVidCell; //6d0h
	CVidCell* m_pCurrentVidCellBase; //6d4h
	CVidCell* m_pCurrentVidCellExtend; //6d8h

	CVidCell m_G1VidCellBase; //6dch
	CVidCell m_G1VidCellExtend; //7a0h
	VidPal vpColorRange; //864h

	short wCurrentAnimation; //888h
	short wCurrentOrientation; //88ah
	BOOL bUseColorRange; //88ch
	BOOL bImmuneToDamage; //890h
	char nOrientations; //894h
	char p895[3];
};

class CAnimationC000 : public CAnimation { //Size 8A0h
public:
	virtual ~CAnimationC000() {} //v0

	IECString sPrefix; //6d0h
	CVidCell* m_pCurrentVidCell; //6d4h
	CVidCell* m_pCurrentVidCellBase; //6d8h
	CVidCell* m_pCurrentVidCellExtend; //6dch

	CVidCell m_G1VidCellBase; //6e0h
	CVidCell m_G1VidCellExtend; //7a4h
	VidPal vpColorRange; //868h

	short wCurrentAnimation; //88ch
	short wCurrentOrientation; //88eh
	BOOL bUseColorRange; //890h
	int u894;
	int u898;
	char m_nListType; //89ch, always LIST_FRONT except for C500 is LIST_2
	char nOrientations; //89dh
	char p89e[2];
};

class CAnimationD000 : public CAnimation { //Size 7CCh
public:
	virtual ~CAnimationD000() {} //v0

	CVidCell* m_pCurrentVidCell; //6d0h
	CVidCell* m_pCurrentVidCellBase; //6d4h
	CVidCell m_G1VidCellBase; //6d8h
	VidPal vpColorRange; //79ch

	short wCurrentAnimation; //7c0h
	short wCurrentOrientation; //7c2h
	BOOL bUseColorRange; //7c4h
	char nOrientations; //7c8h
	char p7c9[3];
};

class CAnimationE000 : public CAnimation { //Size 2ECCh
public:
	virtual ~CAnimationE000() {} //v0

	IECString sPrefix; //6d0h
	CVidCell* m_pCurrentVidCell; //6d4h
	CVidCell* m_pCurrentVidCellBase; //6d8h
	CVidCell* m_pCurrentVidCellExtend; //6dch

	CVidCell u6e0; //A1
	CVidCell u7a4; //A1E
	CVidCell u868; //A2
	CVidCell u92c; //A2E
	CVidCell u9f0; //A3
	CVidCell uab4; //A2E (bugged, should be A3E)
	CVidCell ub78; //A4
	CVidCell uc3c; //A4E
	CVidCell ud00; //Gu
	CVidCell udc4; //GuE
	CVidCell ue88; //Sl
	CVidCell uf4c; //SlE
	CVidCell u1010; //De
	CVidCell u10d4; //DeE
	CVidCell u1198; //GH
	CVidCell u125c; //GHE
	CVidCell u1320; //Sd
	CVidCell u13e4; //SdE
	CVidCell u14a8; //Sc
	CVidCell u156c; //ScE
	CVidCell u1630; //Sp
	CVidCell u16f4; //SpE
	CVidCell u17b8; //Ca
	CVidCell u187c; //CaE
	CVidCell u1940; //Tw
	CVidCell u1a04; //TwE
	CVidCell u1ac8; //Wk
	CVidCell u1b8c; //WkE

	CVidCell* m_pCurrentVidCell2; //1c50h
	CVidCell* m_pCurrentVidCellBase2; //1c54h
	CVidCell* m_pCurrentVidCellExtend2; //1c58h

	CVidCell u1c5c;
	CVidCell u1d20;
	CVidCell u1de4;
	CVidCell u1ea8;
	CVidCell u1f6c;
	CVidCell u2030;
	CVidCell u20f4;
	CVidCell u21b8;
	CVidCell u227c;
	CVidCell u2340;
	CVidCell u2404;
	CVidCell u24c8;
	CVidCell u258c;
	CVidCell u2650;
	CVidCell u2714;
	CVidCell u27d8;
	CVidCell u289c;
	CVidCell u2960;
	CVidCell u2a24;
	CVidCell u2ae8;
	CVidCell u2bac;
	CVidCell u2c70;
	CVidCell u2d34;
	CVidCell u2df8;

	short wCurrentOrientation; //2ebch
	char p2ebe[2];
	int u2ec0;
	int u2ec4;
	char u2ec8;
	char nOrientations; //2ec9h
	char p2eca[2];
};

#endif //ANIMEXT_H