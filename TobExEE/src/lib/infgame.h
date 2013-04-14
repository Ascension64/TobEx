//TobExEE
#ifndef INFGAME_H
#define INFGAME_H

#include "stdafx.h"
#include "infbtarr.h"
#include "rescore.h"
#include "objcore.h"
#include "objcre.h"
#include "vidcore.h"
#include "arecore.h"
#include "scrcore.h"
#include "sndcore.h"
#include "stocore.h"
#include "itmcore.h"

typedef IECPtrList CPartyLocationList; //AAB968

struct Res2daFile { //Size 10h
	BOOL m_bLoaded; //0h
	ResTxt* m_pRes; //4h
	ResRef m_rName; //8h
};

struct CWorldTimer { //Size 8h
	void UnpauseGame();

	unsigned int m_nGameTime; //0h, current game time (in ticks)
	bool m_bRun; //4h, 0 = paused, 1 = unpaused
	unsigned char m_nPartsOfHour; //5h, during dawn/dusk hour, is the part of the hour out of 255 (1dd5h)
	char p6[2];
};

struct CPartySelection { //Size 24h
	short u0; //ffff
	char p2[2];
	int u4; //always set to 1 on remove
	CEnumList m_lSelected; //8h, party members first in number order, then non-members
};

struct CRuleTable { //Size 24h
	Res2daFile m_2da; //0h
	IECString* m_pColHeaderArray; //10h
	IECString* m_pRowHeaderArray; //14h
	IECString* m_pDataArray; //18h
	IECString m_sDefaultVal; //1ch
	short m_nCols; //20h
	short m_nRows; //22h
};

struct IdsEntry { //Size Ch
	int m_nOpcode;
	IECString m_sValue; //entire value (i.e. full function description)
	IECString m_sHead; //i.e. function name only
};

class CRuleTables { //Size 1FA8h
public:
	CRuleTable m_RMODCHR; //0h
	CRuleTable m_RMODREP; //24h
	CRuleTable m_REPUTATI; //48h
	Identifiers m_NODECODE; //6ch
	CRuleTable m_PROFS; //ach
	CRuleTable m_PROFSMAX; //d0h
	CRuleTable m_SKILLRAC; //f4h
	CRuleTable m_SKILLDEX; //118h
	CRuleTable m_SKILLBRD; //13Ch
	CRuleTable m_SKILLRNG; //160h
	CRuleTable m_ABRACERQ; //184h
	CRuleTable m_ABRACEAD; //1a8h
	CRuleTable m_ABCLASRQ; //1cch
	CRuleTable m_ABCLSMOD; //1f0h
	CRuleTable m_AbDCScRq; //214h
	CRuleTable m_AbDCDsRq; //238h
	CRuleTable m_SAVEPRS; //25ch
	CRuleTable m_SAVEWAR; //280h
	CRuleTable m_SAVEWIZ; //2a4h
	CRuleTable m_SAVEROG; //2c8h
	CRuleTable m_SAVECNDH; //2ech
	CRuleTable m_SAVECNG; //310h
	CRuleTable m_SAVEMONK; //334h
	CRuleTable m_HPWAR; //358h
	CRuleTable m_HPWIZ; //37ch
	CRuleTable m_HPPRS; //3a0h
	CRuleTable m_HPROG; //3c4h
	CRuleTable m_HPCONBON; //3e8h
	CRuleTable m_HPMONK; //40ch
	CRuleTable m_STRTGOLD; //430h
	CRuleTable m_THAC0; //454h
	CRuleTable m_MXSPLPRS; //478h
	CRuleTable m_MXSPLPAL; //49ch
	CRuleTable m_MXSPLRAN; //4c0h
	CRuleTable m_MXSPLWIZ; //4e4h
	CRuleTable m_MXSPLBRD; //508h
	CRuleTable m_MXSPLSRC; //52ch
	CRuleTable m_MXSPLDD; //550h, new in BG:EE
	CRuleTable m_MXSPLWIS; //574h 
	CRuleTable m_MXSPLDRU; //598h
	CRuleTable m_SPLSRCKN; //5bch
	CRuleTable m_BACKSTAB; //5e0h
	CRuleTable m_XPLEVEL; //604h
	CRuleTable m_LAYHANDS; //628h
	Identifiers m_INSTANT; //668h
	Identifiers m_ACTSLEEP; //6a8h
	CRuleTable m_MONSUM01; //6cch
	CRuleTable m_MONSUM02; //6f0h
	CRuleTable m_MONSUM03; //714h
	CRuleTable m_ANISUM01; //738h
	CRuleTable m_ANISUM02; //75ch
	CRuleTable m_STRMOD; //780h
	CRuleTable m_STRMODEX; //7a4h
	CRuleTable m_INTOXMOD; //7c8h
	CRuleTable m_FATIGMOD; //7ech
	CRuleTable m_EFFTEXT; //810h
	CRuleTable m_INTERACT; //834h
	CRuleTable m_SPELLS; //858h
	CRuleTable m_TOOLTIP; //87ch
	CRuleTable m_STARTARE; //8a0h
	CRuleTable m_STARTPOS; //8c4h
	CRuleTable m_SPRKLCLR; //8e8h
	CRuleTable m_MONTHS; //90ch
	CRuleTable m_YEARS; //930h
	CRuleTable m_DEXMOD; //954h
	CRuleTable m_PDIALOG; //978h
	CRuleTable m_CHARSND; //99ch
	CRuleTable m_RNDEQUIP; //9c0h
	CRuleTable m_RNDTREAS; //9e4h
	CRuleTable m_RNDMAGIC; //a08h
	CRuleTable m_RNDSCROL; //a2ch
	CRuleTable m_RNDWEP; //a50h
	CRuleTable m_INTERDIA; //a74h
	CRuleTable m_INTMOD; //a98h
	CRuleTable m_DONARUMR; //abch, used for multiplayer
	CRuleTable m_AREALINK; //ae0h, used for single player
	CRuleTable m_AREALINS; //b04h
	CRuleTable m_CACHVALD; //b28h
	CRuleTable m_SCRPDESC; //b4ch
	CRuleTable m_STATDESC; //b70h
	CRuleTable m_MASTAREA; //b94h
	CRuleTable m_MOVIDESC; //bb8h
	CRuleTable m_SPELDESC; //bdch
	CRuleTable m_BNTYCHNC; //c00h
	CRuleTable m_NPCLEVEL; //c24h
	CRuleTable m_NPCLVL25; //c48h
	CRuleTable m_DEATH; //c6ch
	CRuleTable m_ALIGNMNT; //c90h
	CRuleTable m_REPMODST; //cb4h
	CRuleTable m_REPSTART; //cd8h
	CRuleTable m_XPCAP; //cfch
	CRuleTable m_WSPECIAL; //d20h
	CRuleTable m_WSPATCK; //d44h
	CRuleTable m_LORE; //d68h
	CRuleTable m_LOREBON; //d8ch
	CRuleTable m_CHRMODST; //db0h
	CRuleTable m_RAISDEAD; //dd4h
	CRuleTable m_HAPPY; //df8h
	CRuleTable m_REPTXT; //e1ch
	CRuleTable m_PORTRAIT; //e40h
	CRuleTable m_INTOXCON; //e64h
	CRuleTable m_CSOUND; //e88h
	CRuleTable m_ITEMEXCL; //each
	Identifiers m_CHASE; //eech
	Identifiers m_VEFPROJ; //f2ch
	Identifiers m_PROJECTL; //f6ch
	CRuleTable m_CONTCOND; //f90h
	CRuleTable m_CONTTARG; //fb4h
	CRuleTable m_ABSTART; //fd8h
	CRuleTable m_WEAPPROF; //ffch
	CRuleTable m_CLABFI01; //1020h
	CRuleTable m_CLABFI02; //1044h
	CRuleTable m_CLABFI03; //1068h
	CRuleTable m_CLABFI04; //108ch
	CRuleTable m_CLABPA01; //10b0h
	CRuleTable m_CLABPA02; //10d4h
	CRuleTable m_CLABPA03; //10f8h
	CRuleTable m_CLABPA04; //111ch
	CRuleTable m_CLABPA05; //1140h
	CRuleTable m_CLABRN01; //1164h
	CRuleTable m_CLABRN02; //1188h
	CRuleTable m_CLABRN03; //11ach
	CRuleTable m_CLABRN04; //11d0h
	CRuleTable m_CLABRN05; //11f4h
	CRuleTable m_CLABTH01; //1218h
	CRuleTable m_CLABTH02; //123ch
	CRuleTable m_CLABTH03; //1260h
	CRuleTable m_CLABTH04; //1284h
	CRuleTable m_CLABBA01; //12a8h
	CRuleTable m_CLABBA02; //12cch
	CRuleTable m_CLABBA03; //12f0h
	CRuleTable m_CLABBA04; //1314h
	CRuleTable m_CLABDR01; //1338h
	CRuleTable m_CLABDR02; //135ch
	CRuleTable m_CLABDR03; //1380h
	CRuleTable m_CLABDR04; //13a4h
	CRuleTable m_CLABPR01; //13c8h
	CRuleTable m_CLABPR02; //13ech
	CRuleTable m_CLABPR03; //1410h
	CRuleTable m_CLABPR04; //1434h
	CRuleTable m_CLABMA01; //1458h
	CRuleTable m_CLABMA02; //147ch
	CRuleTable m_CLABMA03; //14a0h
	CRuleTable m_CLABMA04; //14c4h
	CRuleTable m_CLABMA05; //14e8h
	CRuleTable m_CLABMA06; //150ch
	CRuleTable m_CLABMA07; //1530h
	CRuleTable m_CLABMA08; //1554h
	CRuleTable m_CLABMA09; //1578h
	CRuleTable m_CLABMO01; //159ch
	CRuleTable m_CLABMO02; //15c0h, new in BGEE
	CRuleTable m_CLABMO03; //15e4h new in BGEE
	CRuleTable m_CLABFI05; //1608h
	CRuleTable m_SPLAUTOP; //162ch
	CRuleTable m_DUALCLAS; //1650h
	CRuleTable m_RANDCOLR; //1674h
	CRuleTable m_SPAWNGRP; //1698h
	CRuleTable m_ITEMANIM; //16bch
	CRuleTable m_HATERACE; //16e0h
	CRuleTable m_XPBONUS; //1704h
	CRuleTable m_CLEARAIR; //1728h
	CRuleTable m_SPLASHSC; //174ch
	CRuleTable m_LVLMODWM; //1770h
	CRuleTable m_KITTABLE; //1794h
	CRuleTable m_KITLIST; //17b8h
	CRuleTable* m_kits[256]; //17dch
	CRuleTable m_SNDRESRF; //1bdch
	CRuleTable m_SNDENVRND; //1c00h
	CRuleTable m_ITEMDIAL; //1c24h
	CRuleTable m_LOADHINT; //1c48h
	CRuleTable m_MSCHOOL; //1c6ch
	CRuleTable m_MSECTYPE; //1c90h
	CRuleTable m_CONTINGX; //1cb4h
	CRuleTable m_LUABBR; //1cd8h
	CRuleTable m_LUNUMAB; //1cfch
	CRuleTable m_XPLIST; //1d20h
	CRuleTable m_TRACKING; //1d44h
	CRuleTable m_MVESND; //1d68h
	CRuleTable m_25STWEAP; //1d8ch
	CRuleTable m_WISH; //1db0h
	CRuleTable m_ENTRIES; //1dd4h
	CRuleTable m_LOADH25; //1df8h

	//new in BG:EE
	CRuleTable m_STWEAPON; //1e1ch
	CRuleTable m_FAMILIAR; //1e40h
	CRuleTable m_THIEFSKL; //1e64h
	CRuleTable m_THIEFSCL; //1e88h
	CRuleTable m_CLASTHAC; //1each
	CRuleTable m_CLASISKL; //1ed0h
	CRuleTable m_TBPPARTY; //1ef4h
	CRuleTable m_EXTANIM; //1f18h
	CRuleTable m_EXTSPEED; //1f3ch
	CRuleTable m_WILDMAG; //1f60h
	CRuleTable m_ITEMTYPE; //1f84h
	/*CRuleTable m_RACETHAC; //1fa8h //add size FCh
	CRuleTable m_CLASCOLR; //1fcch
	CRuleTable m_RACECOLR; //1ff0h
	CRuleTable m_SLTSTEAL; //2014h
	CRuleTable m_NUMWSLOT; //2038h
	CRuleTable m_ITEM_USE; //205ch
	CRuleTable m_RACETEXT; //2080h*/
};

struct MoveAreasElement { //Size 24h
	ENUM m_eCre; //0h
	ResRef m_rArea; //4h
	CPoint m_ptDest; //ch
	CPoint u14;
	char m_cOrient; //1ch
	char p1d[3];
	int m_nDelay; //20h
};

class CMoveAreasList : public IECPtrList { //Size 1Ch
public:
};

class CInfGame : public CRuleTables { //Size 5004h (5100h)
public:
	CWorldTimer& GetWorldTimer();
	CScriptParser& GetScriptParser();
	void SetLoseCutscene();

	CWorldTimer m_WorldTimer; //1fa8h
	BOOL m_bGameRunning; //1fb0h
	char u1fb4;
	char u1fb5;
	char p1fb6[2];
	int u1fb8[2];
	char u1fc0;
	char u1fc1;
	char u1fc2;
	char u1fc3;
	BOOL u1fc4; //set when preparing to show end cutscene
	CEnumList u1fc8;
	IECPtrList u1fe4;
	short u2000; //2: thieving mode
	char p2002[2];
	int u2004;
	char u2008; //36: thief thieving, 40: bard thieving
	ResRef u2009;
	char u2011; //0x65 = tooltip on, 0x04 = tooltip off?
	char u2012;
	char p2013;
	int u2014; 
	ENUM u2018; //used in ObjectActionListEmpty()
	int u201c;

	struct CGamePermission { //Size 8h
		bool m_bPermitBuySell; //0h
		bool m_bPermitAreaTransition; //1h
		bool m_bPermitDialog; //2h
		bool m_bPermitViewCharacter; //3h
		bool m_bPermitPausing; //4h
		bool u5; //5h
		bool m_bPermitLeader; //6h
		bool m_bPermitModifyCharacters; //7h
	} m_CGamePermission; //2020h

	struct CMultiplayerSettings { //Size B0h
		CGamePermission u0[6]; //by PlayerIdx
		CGamePermission u30; //SoloServer
		int m_nPlayerID[6]; //38h
		int u50[6];
		bool m_bCharacterReady[6]; //68h, by PlayerIdx
		char m_bCharacterStatus[6]; //6eh, by PlayerIdx
		int u74[6]; //unused?
		char u8c;

		//bit1: Experience
		//bit2: Items
		unsigned char m_cImportFlags; //8dh

		char u8e;
		char u8f;
		char u90;
		char u91;
		char u92[2]; //BGEE - two extra char here
		ResRef u94;
		IECString u9c;
		int ua0;
		int ua4;
		bool m_bDialogueAboutToStart; //a8h
		char ua9;
		int uaa;
		char uae;
		char paf;
		char ub0;
		char pb1[3];
	} m_MultiplayerSettings; //2028h

	struct CRemoteGameMode { //Size 18h
		int m_nMode[6]; //0h, init to -1, set to 0x502 or 0x182
	} m_RemoteGameMode; //20dch

	CButtonArray m_ButtonArray; //20f4h

	struct unk1 { //Size Ch
	//ptr to this object copied to CTileset.u18 (a ptr) and to CTileset.uac
		int u0; //gets CVideoMode.u674
		int u4; //gets CVideoMode.u670 (nSize)
		int u8; //array of nSize*0xch objects
	} u3770;

	IECString u377c;
	CVidBitmap m_colorRangePalette; //3780h
	CGameObjectArray m_GameObjectArray; //3834h
	CGameRemoteObjectArray m_GameRemoteObjectArray; //3838h
	char m_cVisibleAreaIdx; //38ach, index to loaded area array of the currently visible area
	char u38ad;
	char p38ae[2];
	CArea* m_pLoadedAreas[12]; //38b0h
	CArea* m_pMasterArea; //38e0h
	ENUM m_ePlayersJoinOrder[6]; //38e4h
	ENUM m_ePlayersPartyOrder[6]; //38fch, 0: leader
	short m_wNumInParty; //3914h
	char p3916[2];
	CEnumList u3918; //enums global characters
	CPtrArray u3934;
	short u3948;
	short m_wReputation; //394ah, 10*that displayed in game
	int* u394c; //CPathSearch* (18h size)
	int* u3950; //ListGrid* (x*y/2 size)
	CPartySelection m_PartySelection; //3954h
	CEnumList m_lControlledObjects; //3978h
	CEnumList m_lFamiliars; //3994h, treated as if party-like
	ResRef u39b0[9]; //array of familiar names
	char u39f8[81][0x1c]; //39f8h, 0x51 (81) * 0x1c size objects
	int u42d4;
	IECString m_sTempPath; //42d8h, IECString.GetBuffer()
	IECString m_sTempsavePath; //42dch 
	IECString m_sScriptsPath; //42e0h
	IECString m_sSoundsPath; //42e4h
	IECString m_sPortraitsPath; //42e8h
	IECString m_sCharactersPath; //42ech
	IECString m_sCurrentSaveGameName; //42f0h
	IECString m_sMoviesPath; //42f4h
	IECString m_sSavePath; //42f8h
	IECString m_sMPSavePath; //42fch
	IECString m_sArenasPath; //4300h
	IECString m_sBPSavePath; //4304h
	IECString m_sMPBPSavePath; //4308h

	struct CGameSave { //Size 14h
		//bit1: pass key presses onto active ui control
		
		//-1 None
		//0x182 DialogMode
		//0x502 MultiDialogMode
		//0x802
		//0x1000
		//0x4000
		//0x8000
		//0x1016e CutSceneMode
		//0x3016e CutSceneLite
		
		int m_nMode; //0h, essentially a huge bunch of flags

		ResRef u4;
		int uc;
		int m_nGold; //431ch, amount of gold player currently has
	} m_GameSave; //430ch

	short u4320;
	int u4322[5];
	char u4336[390];
	BOOL m_bArenaMode; //44bch
	int u44c0;
	short u44c4;
	char p44c6[2];
	int u44c8;
	int u44cc;
	char u44d0[408]; //? m_GameOptions

	struct CGameJournal { //Size 14h
		CPtrArray u0; //of IECPtrList (11 of them)
	} m_GameJournal; //4668h

	struct CWorldMap { //Size 1Ch
		ResRef u0;
		long u8[2]; //struct
		int u10;
		int u14;
		int u18;
	} m_WorldMap; //467ch

	char u4698[0x5f0]; //? keymap

	CVariableMap m_GlobalVariables; //4c88h
	CVariableMap m_GlobalNPCScriptNames; //4c90h, values are enums
	CStrRef u4c98;
	CStrRef u4cb4;
	int u4cd0;
	CVidCell m_vidLocator; //4cd4h

	//to do with PathSearch
	IECPtrList u4d98; //AAD264 (of CSearchRequests)
	IECPtrList u4db4; //AAD264
	int u4dd0;
	int u4dd4;
	CItemList m_lItemsToPurge; //4dd8h
	short u4df4;
	short u4df6;
	Identifiers m_SVTRIOBJ; //4df8h
	int u4e38;
	bool u4e3c; //when set, override script actions take precedence in party members (even if Continue())
	char p4e3d;
	char u4e3e;
	ResRef u4e3f;
	char u4e47;
	int u4e48; //KERNEL32.GetTickCount()
	int u4e4c; //KERNEL32.GetTickCount()
	int u4e50;
	int m_nRealTimer; //4e54h
	int u4e58;
	CPoint u4e5c;
	ENUM u4e64;
	short u4e68;
	char p4e6a[2];
	VidPal u4e6c;
	VidPal u4e90;
	int m_nDeathTimer; //4eb4h, ticks until ending game on player1 death
	int u4eb8; //to do with dreams
	int u4ebc;
	CMoveAreasList m_lMoveAreasDelay; //4ec0, any MoveBetweenAreas() Cre has entry here
	CMoveAreasList m_lMoveAreaNoDelay; //4edch
	IECPtrList u4ef8; //AA70B0
	IECString u4f14;
	ResRef u4f18;
	BOOL m_bTutorialGame; //4f20h
	BOOL m_bThroneOfBhaalGame; //4f24h - used to determine which song to play at start screen, 1 = use MP in STARTARE.2DA
	int u4f28; //?m_bBlackPitsGame
	ENUM m_eBaldurObject; //4f2ch, BALDUR.BCS CBaldurObject
	int m_nTimeStopObjectsTicksLeft; //4f30h, remaining timestop (area sprites) ticks
	ENUM m_eTimeStopExempt; //4f34h, exempt from timestop (area sprites)
	int m_nTimeStopGreyscaleTicksLeft; //4f38h, remaining timestop (Greyscale) ticks
	int m_nDreamSepiaTicksLeft; //4f3ch, remaining dream (Sepia) ticks
	CScriptParser* m_pScriptParser; //4f40h
	CStore* m_aServerStore[12]; //4f44h
	char m_nServerStoreDemands[12]; //4f74h
	IECString u4f80;
	IECString u4f84;
	IECString u4f88;
	IECString u4f8c;
	int u4f90[7];
	int u4fac;
	IECString u4fb0;
	int u4fb4;
	BOOL m_bThroneOfBhaal; //4fb8h - used to determine if 25-prefixed files are used
	int u4fbc;

	CPartyLocationList m_lStorePartyLoc; //4fc0h, used in Store/RestorePartyLocations(), CPartyLocation0 (0x0 Resref areaname, 0x8 CPoint)
	CPartyLocationList m_lPrePocketPlane; //4fdch, used in ExitPocketPlane() and Cutscene2 effect, CPartyLocation1 (0x0 Resref areaname, 0x8 CPoint)

	struct CVvcMap { //Size 8h
		struct CVvcMapEntry { //Size 14h
			ResRef m_r; //0h
			short u8;
			char pa[2];
			int uc;
			int u10;
		};

		CVvcMapEntry* m_pArray; //0h, VvcMapEntry
		int m_nElements; //4h
	} m_VvcMap; //4ff8h

	int u5000; //? compared with CVisualEffectVidCell.u39c
};

#endif //INFGAME_H