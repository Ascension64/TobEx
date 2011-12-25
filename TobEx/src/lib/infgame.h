#ifndef INFGAME_H
#define INFGAME_H

#include "utils.h"
#include "rescore.h"
#include "objcore.h"
#include "objcre.h"
#include "resref.h"
#include "vidcore.h"
#include "arecore.h"
#include "sndcore.h"
#include "stocore.h"
#include "cstringex.h"

typedef CPtrList CPartyLocationList; //AAB968

//CRuleTableString __EHVectorDtor flags
#define CRULETABLESTRING_DELETE		0x1
#define CRULETABLESTRING_MULTIPLE	0x2

struct Res2daContainer { //Size 10h
	BOOL bLoaded; //0h
	ResTxt* pRes; //4h
	ResRef name; //8h
};

struct CRuleTable { //Size 24h
	//functions
	CRuleTable(); //63E230
	CRuleTable& Construct(void) { return *this; } //dummy
	~CRuleTable();
	void LoadTable(ResRef&);
	IECString& GetValue(IECString&, IECString&);
	void UnloadRes();


	//members
	Res2daContainer m_2da; //0h
	IECString* pColHeaderArray; //10h
	IECString* pRowHeaderArray; //14h
	IECString* pDataArray; //18h
	IECString defaultVal; //1ch
	WORD nCols; //20h
	WORD nRows; //22h
};

extern CRuleTable& (CRuleTable::*CRuleTable_Construct)(void);
extern void (CRuleTable::*CRuleTable_LoadRes)(ResRef&);
extern IECString& (CRuleTable::*CRuleTable_GetValue)(IECString&, IECString&);
extern void (CRuleTable::*CRuleTable_UnloadRes)();

struct IdsEntry { //Size Ch
	DWORD opcode;
	IECString value; //entire value (i.e. full function description)
	IECString head; //i.e. function name only
};

struct CRuleTables { //Size 1DB0h
	//functions
	CRuleTables(); //6213DC
	CRuleTables& Construct() { return *this; } //dummy

	~CRuleTables();
	void Deconstruct() {} //dummy

	IECString GetRaceString(BYTE);
	IECString GetAlignmentString(BYTE);
	IECString GetClassString(BYTE, DWORD);
	ResRef GetMageSpellRef(DWORD, DWORD);
	STRREF GetCharSndStrRef(DWORD, DWORD, BYTE);
	void GetDetailedClassString(BYTE, DWORD, DWORD, IECString&, CCreatureObject&);
	DWORD GetWeapProfMax(BYTE, BYTE, BYTE, BOOL, DWORD, DWORD);
	BOOL IsMageSchoolAllowed(DWORD, BYTE);
	ResRef GetMageSpellRefAutoPick(BYTE, BYTE);

	//members
	CRuleTable RMODCHR; //0x0
	CRuleTable RMODREP; //0x24
	CRuleTable REPUTATI; //0x48
	Identifiers NODECODE; //0x6c
	CRuleTable PROFS; //0xac
	CRuleTable PROFSMAX; //0xd0
	CRuleTable SKILLRAC; //0xf4
	CRuleTable SKILLDEX; //0x118
	CRuleTable SKILLBRD; //0x13C
	CRuleTable SKILLRNG; //0x160
	CRuleTable ABRACERQ; //0x184
	CRuleTable ABRACEAD; //0x1a8
	CRuleTable ABCLASRQ; //0x1cc
	CRuleTable ABCLSMOD; //0x1f0
	CRuleTable ABDCSCRQ; //0x214
	CRuleTable ABCDCSRQ; //0x238
	CRuleTable SAVEPRS; //0x25c
	CRuleTable SAVEWAR; //0x280
	CRuleTable SAVEWIZ; //0x2a4
	CRuleTable SAVEROG; //0x2c8
	CRuleTable SAVECNDHD; //0x2ec
	CRuleTable SAVECNG; //0x310
	CRuleTable SAVEMONK; //0x334
	CRuleTable HPWAR; //0x358
	CRuleTable HPWIZ; //0x37c
	CRuleTable HPPRS; //0x3a0
	CRuleTable HPROG; //0x3c4
	CRuleTable HPCONBON; //0x3e8
	CRuleTable HPMONK; //0x40c
	CRuleTable STRTGOLD; //0x430
	CRuleTable THAC0; //0x454
	CRuleTable MXSPLPRS; //0x478
	CRuleTable MXSPLPAL; //0x49c
	CRuleTable MXSPLRAN; //0x4c0
	CRuleTable MXSPLWIZ; //0x4e4
	CRuleTable MXSPLBRD; //0x508
	CRuleTable MXSPLSRC; //0x52c
	CRuleTable MXSPLWIS; //0x550
	CRuleTable MXSPLDRU; //0x574
	CRuleTable SPLSRCKN; //0x598
	CRuleTable BACKSTAB; //0x5bc
	CRuleTable XPLEVEL; //0x5e0
	CRuleTable LAYHANDS; //0x604
	Identifiers INSTANT; //0x628
	Identifiers ACTSLEEP; //0x668
	CRuleTable MONSUM01; //0x6a8
	CRuleTable MONSUM02; //0x6cc
	CRuleTable MONSUM03; //0x6f0
	CRuleTable ANISUM01; //0x714
	CRuleTable ANISUM02; //0x738
	CRuleTable STRMOD; //0x75c
	CRuleTable STRMODEX; //0x780
	CRuleTable INTOXMOD; //0x7a4
	CRuleTable FATIGMOD; //0x7c8
	CRuleTable EFFTEXT; //0x7ec
	CRuleTable INTERACT; //0x810
	CRuleTable SPELLS; //0x834
	CRuleTable TOOLTIP; //0x858
	CRuleTable STARTARE; //0x87c
	CRuleTable STARTPOS; //0x8a0
	CRuleTable SPRKLCLR; //0x8c4
	CRuleTable MONTHS; //0x8e8
	CRuleTable YEARS; //0x90c
	CRuleTable DEXMOD; //0x930
	CRuleTable PDIALOG; //0x954
	CRuleTable CHARSND; //0x978
	CRuleTable RNDEQUIP; //0x99c
	CRuleTable RNDTREAS; //0x9c0
	CRuleTable RNDMAGIC; //0x9e4
	CRuleTable RNDSCROL; //0xa08
	CRuleTable RNDWEP; //0xa2c
	CRuleTable INTERDIA; //0xa50
	CRuleTable INTMOD; //0xa74
	CRuleTable DONARUMR; //0xa98
	CRuleTable AREALINK; //0xabc, //used for multiplayer
	CRuleTable AREALINS; //0xae0, //used for single player
	CRuleTable CACHVALD; //0xb04
	CRuleTable SCRPDESC; //0xb28
	CRuleTable STATDESC; //0xb4c
	CRuleTable MASTAREA; //0xb70
	CRuleTable MOVIDESC; //0xb94
	CRuleTable SPELDESC; //0xbb8
	CRuleTable BNTYCHNC; //0xbdc
	CRuleTable NPCLEVEL; //0xc00
	CRuleTable NPCLVL25; //0xc24
	CRuleTable DEATH; //0xc48
	CRuleTable ALIGNMNT; //0xc6c
	CRuleTable REPMODST; //0xc90
	CRuleTable REPSTART; //0xcb4
	CRuleTable XPCAP; //0xcd8
	CRuleTable WSPECIAL; //0xcfc
	CRuleTable WSPATCK; //0xd20
	CRuleTable LORE; //0xd44
	CRuleTable LOREBON; //0xd68
	CRuleTable CHRMODST; //0xd8c
	CRuleTable RAISDEAD; //0xdb0
	CRuleTable HAPPY; //0xdd4
	CRuleTable REPTXT; //0xdf8
	CRuleTable PORTRAIT; //0xe1c
	CRuleTable INTOXCON; //0xe40
	CRuleTable CSOUND; //0xe64
	CRuleTable ITEMEXCL; //0xe88
	Identifiers CHASE; //0xeac
	Identifiers VEFPROJ; //0xeec
	Identifiers PROJECTL; //0xf2c
	CRuleTable CONTCOND; //0xf6c
	CRuleTable CONTTARG; //0xf90
	CRuleTable ABSTART; //0xfb4
	CRuleTable WEAPPROF; //0xfd8
	CRuleTable CLABFI01; //0xffc
	CRuleTable CLABFI02; //0x1020
	CRuleTable CLABFI03; //0x1044
	CRuleTable CLABFI04; //0x1068
	CRuleTable CLABPA01; //0x108c
	CRuleTable CLABPA02; //0x10b0
	CRuleTable CLABPA03; //0x10d4
	CRuleTable CLABPA04; //0x10f8
	CRuleTable CLABPA05; //0x111c
	CRuleTable CLABRN01; //0x1140
	CRuleTable CLABRN02; //0x1164
	CRuleTable CLABRN03; //0x1188
	CRuleTable CLABRN04; //0x11ac
	CRuleTable CLABRN05; //0x11d0
	CRuleTable CLABTH01; //0x11f4
	CRuleTable CLABTH02; //0x1218
	CRuleTable CLABTH03; //0x123c
	CRuleTable CLABTH04; //0x1260
	CRuleTable CLABBA01; //0x1284
	CRuleTable CLABBA02; //0x12a8
	CRuleTable CLABBA03; //0x12cc
	CRuleTable CLABBA04; //0x12f0
	CRuleTable CLABDR01; //0x1314
	CRuleTable CLABDR02; //0x1338
	CRuleTable CLABDR03; //0x135c
	CRuleTable CLABDR04; //0x1380
	CRuleTable CLABPR01; //0x13a4
	CRuleTable CLABPR02; //0x13c8
	CRuleTable CLABPR03; //0x13ec
	CRuleTable CLABPR04; //0x1410
	CRuleTable empty[9]; //0x1434
	CRuleTable CLABMO01; //0x1578
	CRuleTable CLABFI05; //0x159c
	CRuleTable SPLAUTOP; //0x15c0
	CRuleTable DUALCLAS4; //0x15e4
	CRuleTable RANDCOLR; //0x1608
	CRuleTable SPAWNGRP; //0x162c
	CRuleTable ITEMANIM; //0x1650
	CRuleTable HATERACE; //0x1674
	CRuleTable XPBONUS; //0x1698
	CRuleTable CLEARAIR; //0x16bc
	CRuleTable SPLASHSC; //0x16e0
	CRuleTable LVLMODWM; //0x1704
	CRuleTable KITTABLE; //0x1728
	CRuleTable KITLIST; //0x174c
	CRuleTable* kits[256]; //0x1770
	CRuleTable SNDRESRF; //0x1b70
	CRuleTable SNDENVRND; //0x1b94
	CRuleTable ITEMDIAL; //0x1bb8
	CRuleTable LOADHINT; //0x1bdc
	CRuleTable MSCHOOL; //0x1c00
	CRuleTable MSECTYPE; //0x1c24
	CRuleTable CONTINGX; //0x1c48
	CRuleTable LUABBR; //0x1c6c
	CRuleTable LUNUMAB; //0x1c90
	CRuleTable XPLIST; //0x1cb4
	CRuleTable TRACKING; //0x1cd8
	CRuleTable MVESND; //0x1cfc
	CRuleTable _25STWEAP; //0x1d20
	CRuleTable WISH; //0x1d44
	CRuleTable ENTRIES; //0x1d68
	CRuleTable LOADH25; //0x1d8c
};

extern CRuleTables& (CRuleTables::*CRuleTables_Construct)();
extern void (CRuleTables::*CRuleTables_Deconstruct)();
extern IECString (CRuleTables::*CRuleTables_GetRaceString)(BYTE);
extern IECString (CRuleTables::*CRuleTables_GetAlignmentString)(BYTE);
extern IECString (CRuleTables::*CRuleTables_GetClassString)(BYTE, DWORD);
extern ResRef (CRuleTables::*CRuleTables_GetMageSpellRef)(DWORD, DWORD);
extern STRREF (CRuleTables::*CRuleTables_GetCharSndStrRef)(DWORD, DWORD, BYTE);
extern void (CRuleTables::*CRuleTables_GetDetailedClassString)(BYTE, DWORD, DWORD, IECString&, CCreatureObject&);
extern DWORD (CRuleTables::*CRuleTables_GetWeapProfMax)(BYTE, BYTE, BYTE, BOOL, DWORD, DWORD);
extern BOOL (CRuleTables::*CRuleTables_IsMageSchoolAllowed)(DWORD, BYTE);
extern ResRef (CRuleTables::*CRuleTables_GetMageSpellRefAutoPick)(BYTE, BYTE);

struct CInfGame : public CRuleTables { //Size 4DC8h
	//Constructor: 0x67AD88

	//functions
	void StorePartyLocations(BOOL);
	
	//members
#ifdef _DEBUG
	_CCriticalSection u1db0;
#else
	CCriticalSection u1db0; //for CSearchRequests
#endif
	struct CWorldTimer {
	//Size: 0x6
	//Constructor: 0x648F4D
		DWORD nGameTime; //1dd0h, current game time (in ticks)
		BYTE bRun; //0 = paused, 1 = unpaused
		BYTE u1dd5;
	} timer; //1dd0h

	DWORD u1dd6;
	BYTE u1dda;
	BYTE u1ddb;
	DWORD u1ddc[2];
	BYTE u1de4;
	BYTE u1de5;
	BYTE u1de6;
	BYTE u1de7;
	DWORD u1de8;
	CPtrList u1dec; //AA5C58
	CPtrList u1e08; //AA9CD0
	WORD u1e24;
	BYTE u1e26;
	BYTE u1e27;
	ResRef u1e28;
	BYTE u1e30;
	BYTE u1e31;
	DWORD u1e32;
	Enum u1e36; //used in ObjectActionListEmpty()
	DWORD u1e3a;

	struct CGamePermission {
	//Size: 0x8
	//Constructor: 0x573EB0
		bool bPermitBuySell; //0h
		bool bPermitAreaTransition; //0h
		bool bPermitDialog; //2h
		bool bPermitViewCharacter; //3h
		bool bPermitPausing; //4h
		bool u5; //5h
		bool bPermitLeader; //6h
		bool bPermitModifyCharacters; //7h
	} m_CGamePermission; //1e3eh

	struct CMultiplayerSettings { //Size AEh
	//Constructor: 0x5F0150
		CGamePermission u0[6]; //by PlayerIdx
		CGamePermission u30; //SoloServer
		DWORD u38[6];
		DWORD u50[6];
		bool bCharacterReady[6]; //68h, by PlayerIdx
		BYTE bCharacterStatus[6]; //6eh, by PlayerIdx
		DWORD u74[6]; //unused?
		BYTE u8c;
		
		//bit1: Experience
		//bit2: Items
		BYTE bImportFlags; //8dh

		BYTE u8e;
		BYTE u8f;
		BYTE u90;
		BYTE u91;
		DWORD u92[2]; //unused?
		IECString u9a;
		DWORD u9e;
		DWORD ua2;
		BYTE ua6;
		BYTE ua7;
		DWORD ua8;
		BYTE uac;
		BYTE uad; //padding?
	} m_CMultiplayerSettings; //1e46h

	struct _5B0C30 {
	//Size: 0x1C
	//Constructor: 0x5B0C30
		DWORD u0[6]; //init to -1, set to 0x502 or 0x182
	} m_5B0C30; //1ef4h

	struct CButtonArray {
	//Size: 0x1820
	//Constructor: 0x6607EF
	//To do with the 12 GUI action buttons?
		char u0[0x1d4][12];
		DWORD u15f0[12]; //unused?
		DWORD u1620[12];
		DWORD u1650;
		DWORD u1654;
		DWORD u1658;
		DWORD u165c;
		CVidCell u1660; //GUIWDBUT
		CVidCell u1736; //GUIBTACT
		DWORD u180c;
		DWORD u1810;
		DWORD u1814;
		DWORD u1818;
		DWORD u181c;
	} m_CButtonArray; //1f0ch

	struct _6C2B7B {
	//Size: 0xC
	//Constructor: 0x6C2B7B
	//ptr to this object copied to CTileset.u18 (a ptr) and to CTileset.uac
		DWORD u0; //gets CVideoMode.u674
		DWORD u4; //gets CVideoMode.u670 (nSize)
		DWORD u8; //array of nSize*0xch objects
	} m_6C2B7B; //372ch

	DWORD u3738;
	IECString u373c;
	CVidBitmap u3740; //colour range palette
	CGameObjectArrayHandler m_GameObjectArrayHandler; //37f6h
	CGameRemoteObjectArrayHandler m_GameRemoteObjectArrayHandler; //3824h
	BYTE m_VisibleAreaIdx; //38b4h, index to loaded area array of the currently visible area
	BYTE u38b5; //pad
	CArea* pLoadedAreas[12]; //38b6h
	CArea* pMasterArea; //38e6h
	Enum ePlayersJoinOrder[6]; //38eah
	Enum ePlayersPartyOrder[6]; //3902h, 0: leader
	WORD numInParty; //391ah
	CEnumList u391c; //enums global characters
	CPtrArray u3938;
	WORD u394c;
	WORD nReputation; //394eh, 10*that displayed in game
	DWORD* u3950; //CPathSearch* (18h size)
	DWORD* u3954; //ListGrid* (x*y/2 size)
	
	struct CPartySelection {
		WORD u0; //ffff
		DWORD u2; //always set to 1 on remove
		CEnumList u6; //party members first in number order, then non-members
	} m_PartySelection; //3958h

	CEnumList u397a; //non-party idx
	CEnumList u3996; //non-party idx, familiars? enums in Areas?
	ResRef u39b2[9]; //array of familiar names
	char u39fa[81][0x1c]; //39fah, 0x51 (81) * 0x1c size objects
	DWORD u42d6;
	char* tempPath; //42dah, IECString.GetBuffer()
	char* tempsavePath; //42deh 
	char* scriptsPath; //42e2h
	char* soundsPath; //42e6h
	char* portraitsPath; //42eah
	char* charactersPath; //42eeh
	IECString currentSaveGameName; //42f2h
	char* savePath; //42f6h
	char* mpsavePath; //42fah
	char* arenasPath; //42feh

	struct CGameSave {
		/*
		-1 None
		0x182
		0x502
		0x802
		0x1000
		0x4000
		0x8000
		0x1016e CutSceneMode
		0x3016e CutSceneLite
		*/
		DWORD mode; //0h

		ResRef u4;
		DWORD uc;
		DWORD nGold; //4312h, amount of gold player currently has
	} m_GameSave; //4302h

	WORD u4316;
	DWORD u4318[5];
	char u432c[390];
	DWORD u44b2;
	DWORD u44b6;
	WORD u44ba;
	DWORD u44bc; //bInCutscene?
	DWORD u44c0;

	struct GameOptions {
		DWORD m_gore; //44c4h, Memory Level (m_gore)
		DWORD u44c8; //Memory Access
		DWORD m_scrollSpeed; //44cch, Mouse Scroll Speed (m_scrollSpeed)
		DWORD m_displayVerbalText; //44d0h, Subtitles (m_displayVerbalText)
		DWORD m_guiFeedBackLevel; //44d4h, GUI Feedback Level (m_guiFeedBackLevel)
		DWORD m_locatorFeedbackLevel; //44d8h, Locator Feedback Level
		DWORD m_soundMusicVolume; //44dch
		DWORD m_soundFXVolume; //44e0h
		DWORD m_soundDialogVolume; //44e4h, all voices
		DWORD m_soundAmbientVolume; //44e8h
		DWORD m_soundMovieVolume; //44ech
		DWORD m_soundFootStepsOn; //44f0h, Footsteps (m_soundFootStepsOn)
		DWORD m_soundVoicesNo; //44f4h
		DWORD m_graphicsTranslucentShadows; //44f8h
		DWORD m_graphicsForceMirroringOff; //44fch
		DWORD m_graphicsTranslucentEffects; //4500h
		DWORD m_toolTips; //4504h, Tooltips (tool tip delay)
		DWORD m_nBoredTime; //4508h, Bored Timeout
		DWORD m_nCommandSoundsFrequency; //450ch, CommandSoundFrequency, 1 = never, 2 = seldom, 3 = always
		DWORD m_nSelectSoundsFrequency; //4510h, SelectionSoundFrequency, 1 = never, 2 = seldom, 3 = always
		BOOL m_bAlwaysDither; //4514h, Always Dither
		DWORD m_nKeyBoardScrollAmount; //4518h, Keyboard Scroll Speed
		DWORD m_nEffectTextLevel; //451ch, Effect Text Level
		DWORD m_nTutorialState; //4520h, Tutorial State
		DWORD m_nAttackSounds; //4524h, Attack Sounds
		DWORD m_nAutoPauseState; //4528h, Auto Pause State
		BOOL m_bAutoPauseCenter; //452ch, Auto Pause Center
		DWORD m_nDifficultyLevel; //4530h, Difficulty Level
		DWORD m_nDifficultyMultiplier; //4534h, % based on difficulty, e.g. -25 means -25%
		DWORD m_nMPDifficultyMultiplier; //4538h, as above for multiplayer
		BOOL m_bInfravision; //453ch, Infravision
		BOOL m_bStupidQuickItemStuff; //4540h, Quick Item Mapping
		BOOL m_bWeatherEnabled; //4544h, Weather
		BOOL m_bCheatsEnabled; //4548h, Cheats
		BOOL m_bEnvironmentalAudio; //454ch, Environmental Audio
		BOOL m_bRestHealParty; //4550h, Heal Party on Rest
		BOOL m_bTerrainHugging; //4554h, Terrain Hugging
		BOOL m_bHPOverHead; //4558h, HP Over Head
		BOOL m_bDebugMode; //455ch - Debug Mode
		BOOL m_bForceDialogPause; //4560h, Force Dialog Pause
		BOOL m_bUse3dAnimations; //4564h, Use 3d Animations
		BOOL m_bCriticalHitScreenShake; //4568h, Critical Hit Screen Shake
		BOOL m_bLowPerformance; //456ch, Low End Machine
		BOOL m_bHotkeysOnTooltips; //4570h, Hotkeys On Tooltips
		BOOL m_bVeryLowPerformance; //4574h, Low End Machine 2
		BOOL m_bDisplayExtraCombatInfo; //4578h, Extra Combat Info
		WORD m_nAreaEffectsDensity; //457ch, Area Effects Density
		BOOL m_bDuplicateFloatingText; //457eh, Duplicate Floating Text
		BYTE u4582; //Tiles Precache Percent
		BYTE u4583; //pad?
		BOOL m_bDisableCastingGlows; //4584h, Disable Casting Glows
		BOOL m_bLowMemSounds1; //4588h, Low Mem Sounds 1
		BOOL m_bLowMemSounds2; //458ch, Low Mem Sounds 2
		BOOL m_bDisableVEFVidCells; //4590h, Disable VEFVidCells
		BOOL m_bDisableDisplayText; //4594h, Disable Display Text
		DWORD u4598; //Mid Level Brighten
		DWORD u459c; //High Level Brighten
		WORD m_nAreaEffectsRefreshProb; //45a0h, Area Effects Refresh Probability
		DWORD u45a2; //Enhanced Path Search/Finding
		DWORD u45a6; //Pausing Map
		DWORD u45aa; //Extra Feedback
		DWORD u45ae; //Filter Games
		DWORD u45b2; //All Learn Spell Info
		DWORD u45b6; //Disable Statics During Combat
		DWORD u45ba; //Disable Foot Steps During Combat
		DWORD u45be; //Disable Placed Sounds During Combat
		DWORD u45c2; //Super Atomic Speed Fighting Action
		DWORD u45c6; //Automated Speed Adjustment
		BOOL u45ca; //1 (bAutoTranslucentShadows) - only if no3d
		BOOL u45ce; //0 (bAutoVeryLowPerformance)
		BOOL u45d2; //0 (bAutoLowPerformance)
		BOOL u45d6; //0 (bAutoDisableBrightest) - only if no3d
		BOOL u45da; //0 (bAutoLimitTransparency) - only if no3d
		BOOL u45de; //0 (bAutoDisableCastingGlows)
		BOOL u45e2; //0 (bAutoDisableVEFVidCells)
		BOOL u45e6; //1 (bAutoMidLevelBrighten) - only if no3d
		BOOL u45ea; //1 (bAutoHighLevelBrighten) - only if no3d
		BOOL u45ee; //1 (bAutoFootSteps)
		BOOL u45f2; //1 (bAutoAttackSounds)
		BOOL u45f6; //1 (bAuto3dAnimations)
		BOOL u45fa; //0 (bAutoDisableVVCSounds)
		BOOL u45fe; //0 (bAutoFasterBlur) - only if no3d
		DWORD u4602; //Automated Translucent Shadows
		DWORD u4606; //Automated Very Low Performance
		DWORD u460a; //Automated Low Performance
		DWORD u460e; //Automated Disable Brightest
		DWORD u4612; //Automated Limit Transparency
		DWORD u4616; //Automated Disable Casting Glows
		DWORD u461a; //Automated Disable VEFVidCells
		DWORD u461e; //Automated Mid Level Brighten
		DWORD u4622; //Automated High Level Brighten
		DWORD u4626; //Automated Foot Steps
		DWORD u462a; //Automated Attack Sounds
		DWORD u462e; //Automated 3D Animations
		DWORD u4632; //Automated Disable VVC Sounds
		DWORD u4636; //Automated Faster Blur		
		BOOL u463a; //1, Conditional Battle Music Change (do not change music if source and target not in party, or if source = target)
		DWORD u463e; //Fully Disable Non Visible During Combat
		DWORD u4642; //Disable VVC Sounds
		DWORD u4646; //Faster Blur
	} m_GameOptions; //44c4h

	struct CGameJournal {
	//Size: 0x10
	//Constructor: 0x56FFD9
		CPtrArray u0; //of CPtrList AAA9A4s (11 of them)
	} m_CGameJournal; //464ah

	struct CWorldMap {
	//Size: 0x1C
	//Constructor: 0x65CCD0
		ResRef u0;
		QWORD u8; //struct
		DWORD u10;
		DWORD u14;
		DWORD u18;
	} m_CWorldMap; //465eh

	//char+20 = hotkey for keymap
	//0-8: [Keymap Page]
	//9-22: [Keymap Actions]
	//23-32: [Keymap Miscellaneous]
	//33-47: [Keymap Quick Slots]
	//48-386:  [Keymap Priest Spells][Keymap Wizard Spells][Keymap High Level Abilities]
	BYTE bKeymap[387]; //467ah
	BYTE bCtrl[387]; //47fdh, for each array entry as above for keymap, is Ctrl- required?

	CVariableArray GlobalVariables; //4980h
	CVariableArray u4988; //4988h, global object names?

	struct u4990 {
		IECString u0;
		CSound u4;
	} m_u4990;
	struct u49fe {
		IECString u0;
		CSound u4;
	} m_u49fe;

	BYTE u4a6c;
	BYTE u4a6d;

	//to do with PathSearch
	CVidCell locator; //4a6eh
	CPtrList u4b44; //AAD264 (of CSearchRequests)
	CPtrList u4b60; //AAD264
	DWORD u4b7c;
	DWORD u4b80;
	DWORD u4b84; //handle to Semaphore for SearchBitmapThread
#ifdef _DEBUG
	_CCriticalSection u4b88;
#else
	CCriticalSection u4b88;
#endif
	CPtrList u4ba8;
	WORD u4bc4;
	WORD u4bc6;
	Identifiers SVTRIOBJ; //4bc8h
	DWORD u4c08;
	WORD u4c0c;
	BYTE u4c0e; //random number
	ResRef u4c0f;
	BYTE u4c17;
	DWORD u4c18; //KERNEL32.GetTickCount()
	DWORD u4c1c; //KERNEL32.GetTickCount()
	DWORD u4c20;
	DWORD m_nRealTimer; //4c24h
	char u4c28[14];
	VidPal u4c36;
	VidPal u4c5a;
	DWORD u4c7e;
	DWORD u4c82;
	BYTE u4c86;
	BYTE u4c87;

	CPtrList u4c88; //AAD240 - CPtrListMoveBtwAreas, any MoveBetweenAreas() Cre has entry here
	//contains objects related to areaNames
	//DWORD enum; //0h - CCreatureObject
	//ResRef areaName; //4h
	//POINT ptDest; //ch
	//DWORD orientation; //14h

	CPtrList u4ca4; //AAD240
	CPtrList u4cc0; //AA70B0
	IECString u4cdc;
	DWORD u4ce0;
	DWORD u4ce4;
	DWORD u4ce8;
	BOOL m_bThroneOfBhaalSong; //4cech - used to determine which song to play at start screen
	Enum u4cf0; //BALDUR.BCS CBaldurObject
	DWORD u4cf4; //Remaining timestop (area sprites) ticks
	DWORD u4cf8; //enum exempt from timestop (area sprites)
	DWORD u4cfc; //Remaining timestop (Greyscale) ticks
	DWORD u4d00; //Remaining dream (Sepia) ticks
	DWORD* u4d04; //pScriptParser, 0xee size
	CServerStore* m_aServerStore[12]; //4d08h
	BYTE m_nServerStoreDemands[12]; //4d38h
	IECString u4d44;
	IECString u4d48;
	IECString u4d4c;
	IECString u4d50;
	DWORD u4d54[7];
	DWORD u4d70;
	IECString u4d74;
	DWORD u4d78;
	BOOL m_bThroneOfBhaal; //4d7ch - used to determine if 25-prefixed files are used
	DWORD u4d80;

	CPartyLocationList cplStorePartyLoc; //4d84h, used in Store/RestorePartyLocations(), CPartyLocation0 (0x0 Resref areaname, 0x8 POINT)
	CPartyLocationList cplPrePocketPlane; //4da0h, used in ExitPocketPlane() and Cutscene2 effect, CPartyLocation1 (0x0 Resref areaname, 0x8 POINT)

	struct CVvcArray {
	//Size: 0x8
	//Constructor: 0x64B3C1
		DWORD* pArray; //of VvcEntries (0x12 size objects - ResRef, w, dw, dw)
		DWORD nElements;
	} m_CVvcArray; //4dbch

	DWORD u4dc4; //? compared with CVisualEffectVidCell.u39c*/
};

extern void (CInfGame::*CInfGame_StorePartyLocations)(BOOL);

#endif //INFGAME_H