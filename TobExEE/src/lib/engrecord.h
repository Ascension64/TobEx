//TobExEE
#ifndef ENGRECORD_H
#define ENGRECORD_H

#include "engine.h"
#include "uicore.h"

class CScreenRecord : public CEngine { //Size 938h
public:
	CHotkey m_keymap[95]; //d0h, size 474h
	int m_keybuffer[95]; //544h, size 17Ch
	IECPtrList m_lPanels; //6c0h
	int m_dwProfsMax; //6dch, set but not used in-game
	int ude0;
	CPtrArray u6e4; //AAD7D0
	int m_nThievingPointsRemaining; //6f8h
	int u6fc;
	int u700;
	int u704;
	int u708;
	int u70c;
	int u710;
	int u714;
	char m_nSelectedDualClass; //718h
	char p719[3];
	int u71c; //nSpellsRemaining, # spells remaining for sorcerer to choose
	int u720;
	int m_pScripts; //724h
	int u728;
	int u72c;
	int u730;
	int u734; //nErrorButtons
	int u738;
	int u73c;
	int u740;
	int u744;
	int u748;
	int u74c;
	short u750;
	char p752[2];
	int u754;
	int u758;
	BOOL m_bPlayerControllable; //75ch
	int u760;
	int u764;
	short u766;
	short u768;
	int u76c;
	int u770; //customSoundSetIdx
	int u774;
	char u778;
	ResRef m_rPortraitSmall; //779h
	ResRef m_rPortraitLarge; //781h
	CreFileColors m_colors; //789h
	IECString m_sClassScript; //790h
	ResRef m_rPortraitSmall2; //794h
	ResRef m_rPortraitLarge2; //79ch
	short m_wSelectedDualClassKit; //7a4h, wKit low
	char p7a6[2];
	IECPtrList* m_pSounds; //7a8h, contains CStrings
	ResRef m_rVoiceset; //7ach
	CreFileHeader* u7b4; //m_pTempHeader
	CDerivedStats* u7b8; //m_pTempDerivedStats
	int u7bc;
	CVidFont u7c0;
	CVidFont u7e4;
	CVidFont u808;		
	char u82c; //bInChargen?
	char u82d;
	short u82e;
	CResRefList m_lMageBookSpells; //830h (Resref spells)
	short u84c;
	char m_nCurrentMageBookLevel; //84eh
	char p84f;
	short m_wFirstWeapProfRowIdx; //850h, the first row idx to read from in WEAPPROF.2DA in dual class proficiencies
	short u852;
	int u854[2];
	char u85c;
	char p85d[3];
	IECString u860;
	int u864; //character's previous level (on level-up)
	int u868;

	struct NewSpell { //Size 9h
		ResRef m_rName; //0h
		char m_cLevel; //8h
	} u86c[9];

	char u8bd;
	short u8be;
	int u8c0;
	CStringList m_szCharInfoStorage; //8c4h

	int u8e0[10];
	BOOL m_bHighLevelAbility; //908h
	int u90c;
	int u910;
	char m_nHLAFlags; //914h, bit4: allow cleric HLAs, bit5: allow mage HLAs
	char p915[3];
	
	/*
	elements 0x28?
	based on LU**0.2DA
	0x0 *
	0x4 icon
	0x8 strref
	0xc sAbility
	0x10 nMinLevel
	0x14 nMaxLevel
	0x18 nNumAllowed
	0x1c sPreReq
	0x20 sExcludedBy
	0x24 sAlignRestrict
	*/
	CPtrArray* u918;

	int u91c[6];
	char u934;
	char p935[3];
};

#endif //ENGRECORD_H