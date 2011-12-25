#ifndef ARECORE_H
#define ARECORE_H

#include "stdafx.h"
#include "rescore.h"
#include "vidcore.h"
#include "sndcore.h"
#include "scrcore.h"
#include "pathfind.h"

#define CAREA_SONGTYPE_DAY		0
#define CAREA_SONGTYPE_NIGHT	1
#define CAREA_SONGTYPE_VICTORY	2
#define CAREA_SONGTYPE_BATTLE	3
#define CAREA_SONGTYPE_DEFEAT	4
#define CAREA_SONGTYPE_5		5
#define CAREA_SONGTYPE_6		6
#define CAREA_SONGTYPE_7		7
#define CAREA_SONGTYPE_8		8
#define CAREA_SONGTYPE_9		9

class CInfGame;
class CArea;

struct CAreaNotes { //Size 8Ch
//Constructor: 0x4D6B40
	int u0; //ptr
	int u4;
	int u8;
	int uc;
	int u10;
	int u14;
	int u18;
	int u1c;
	IECPtrList u20; //AA7198, contains CAutomapNote (as per area automap note struct)
	int u3c[0xd];
	int u70;
	int u74;
	int u78;
	int u7c; //ptr
	ResRef areaName; //80h
	IECString u88;
};

struct CInfinity { //Size 29Eh
//Constructor: 0x6C356B
	CTileset* pTileset[5]; //0h, corresopnds to the tilesets in TIS file
	ResWed* pRes; //14h
	int u18; //pCInfGame372ch
	CVideoMode* pVideoMode; //1ch

	int u20;
	BOOL u24; //1 = to do with pausing? time stop?
	BOOL u28; //1 = after loading dimensions and tiles?
	BOOL u2c; //bLoaded?
	int u30; //gets g_windowRect.x1
	int u34; //gets g_windowRect.y1
	int m_tilesetMainWidth; //38h, Overlay0Width
	int m_tilesetMainHeight; //3ch, Overlay0Height
	int m_nScreenOffsetX; //40h, assoc u48 and u80, position of screen?
	int m_nScreenOffsetY; //44h, assoc u48 and u84, position of screen?
	RECT m_rWindow; //48h, copy of g_windowRect
				
	int u58; //-1
	int u5c; //-1
	int u60; //-1
	int u64; //-1
				
	RECT m_rTilesetMain; //68h, rectOverlay0

	int u78; //g_windowRectWidth/64 + 1 (window width in tiles?)
	int u7c; //g_windowRectHeight/64 + 1 (window height in tiles?)
	int m_areaWidth; //80h (53eh), in pixels, u38*64 (range: 320-5120)
	int m_areaHeight; //84h (542h), in pixels u3c*64 (range: 320-5120)
	int u88; //u90/64
	int u8c; //u94/64
	int u90; //0
	int u94; //0

	int u98;
	int u9c;
	int ua0;
	int ua4;
	int ua8;
	int uac;
	int ub0;
	int ub4;

	CSound m_Lightning; //b8h - lightning sound
	int u122; //lightning timer seed (64, 128, or 192)
	int u126;
	int u12a;
	int u12e;
	int u132;
	int u136;
	int u13a;
	int u13e;
	int u142;
	int m_LightningFlashTimer; //146h, how long until a lightning flash and sound
	int m_LightningTimer; //14ah, how long one lightning flash goes for
	int u14e; //assoc u152
	int u152; //timer that counts down?
	int u156;
	int u15a;
	unsigned short dwAreaTypeFlags; //15eh, gets 40h of CArea (areaType)
	char u160; //gets AAD291 for night Wed, AAD290 for day Wed
	char u161; //gets AAD291 for night Wed, AAD290 for day Wed
	char u162;
	char u163;
	char u164;
	char u165;
	int u166; //KERNEL32.GetTickCount()
	int u16a; //u40*10000
	int u16e; //u44*10000
#ifdef _DEBUG
	_CCriticalSection u172; //172h
#else
	CCriticalSection u172; //172h
#endif
	short u192;
	POINT u194;
	int u19c;
	char u1a0;
	char u1a1;
	BOOL m_bEnableLightning; //1a2h, assoc u146
	int u1a6; //assoc u14a
	char u1aa;
	char u1ab; //pad
	int u1ac; // = u1c0, gets AAD2C4 (5a4646) for night Wed, AAD2C0 (6e6e6e) for day Wed (ARGB)
				
	//note: get lowest(1b4, 1bc) for each color, add 1b0, then set 1b8
	int u1b0; //additive lighting (can be used to control fades)
	int u1b4; //lighting
	int u1b8; //current lightmask, copied to CVideoMode.ua4
	int u1bc; //lighting

	int u1c0;
	int u1c4; //assoc u16a, u16e
	CArea* pArea; //1c8h, owning area
	CVidBitmap u1cc;
	int u282;
	char u286;
	char u287; //pad
	short u288;
	int u28a;
	int u28e;
	int u292;
	int u296;
	int u29a;
};

struct CSearchBitmap : public CVidBitmap { //Size F0h
//Constructor: 0x63E360
	char* pTerrainMap; //b6h, ptr to 2D search map char array
	//values of the BYTEs in array
	//1 = override with DarkGrey(TerrainTable[8]), if not set, gets terraintable[2]
	//e = if not set, gets terraintable[2]
	//70 = if not set, gets terraintable[2]
	//80 = if not set, gets terraintable[0]

	int uba;
	int ube;
#ifdef _DEBUG
	_CCriticalSection uc2; //c2h
#else
	CCriticalSection uc2; //c2h
#endif
	int width; //ue2h (842h)
	int height; //ue6h (846h)
	CArea* pArea; //ueah, owning area
	char uee;
	char uef; //pad
};

struct CVisibilityMap { //Size 72h
//Constructor: 0x64EF10
//fog table
	int* pMap; //0h, 2D array of words (vismap)
	//one fog pixel is [32x32] by (x.y)
	//bit 15 = discovered
	//bit 1 = visible (no fog)

	short u4; //width of map (nAreaX/32 + 1)
	short u6; //height of map (nAreaY/32 + 1)
	char u8; //bOutdoor (based on AreaType)
	char u9; //pad
#ifdef _DEBUG
	_CCriticalSection ua; //ah
#else
	CCriticalSection ua; //ah
#endif
	CSearchBitmap* pSearchMap; //2ah, associated search map
	int u2e[15]; //array of enums
	int* u6a; //60h size object
	int* u6e; //4h of 170h size object
};

class CArea { //Size B6Eh
//Constructor: 0x4B7B80
public:
	char GetSong(short wType);

	//entire ARE V1.0 header (m_header)
	ResRef areaPrefix; //0h, used for LM, LN, HT, wed, Nwed
	int m_lastSaved; //8h, in game time (script rounds)
	int areaFlags; //ch
	ResRef areaNorth;
	int u18;
	ResRef areaEast;
	int u24;
	ResRef areaSouth;
	int u30;
	ResRef areaWest;
	int u3c;
	unsigned short areaType; //40h
	short probRain; //42h
	short probSnow; //44h
	short probFog; //46h
	short probLightning; //48h
	short u4a;

	int u4c; //disable EXTENDED_NIGHT? (see 0x4C882F)

	//entire Song entry struct
	int nSongDay; //50h
	int nSongNight;
	int nSongVictory;
	int nSongBattle;
	int nSongDefeat; //60h
	int nSong5; //64h
	int nSong6; //68h
	int nSong7; //6ch
	int nSong8; //70h
	int nSong9; //74h
	ResRef ambDay1; //78h
	ResRef ambDay2;
	int ambDayVolume; //88h
	ResRef ambNight1;
	ResRef ambNight2;
	int ambNightVolume; //9ch
	int reverb;
	char ua4[0x3c];

	//entire Rest spawn struct
	char restSpawnName[32]; //0xe0
	char u100[0xc4];

	IECPtrList u1c4; //AA7044 of CEntrance (68h size; as per area entrance struct)
	char idxLoadedArea; //1e0h, refers CInfGame::38b6
	char u1e1; //related to u218
	char u1e2;
	char u1e3; //related to u1c4
	ResRef rAreaName; //1e4h
	ResRef restMovieDay; //1ech
	ResRef restMovieNight; //1f4h
	ResWed* pWed; //1fch
	CRITICAL_SECTION u200; //for 1fch and 1e1h, 165h of CWed
	CRITICAL_SECTION u218; //for 906h, 8ceh, 8eah (to RemoveFromArea), 9aeh, 976h, 992h
	CInfGame* pGame; //230h
	int u234;
	int u238;
	char u23c;
	char u23d;
	int u23e; //contains enum
	int u242; //contains enum
	int u246; //contains enum
	int u24a;
	int u24e;
	int u252;
	int u256;
	CVidBitmap m_bmLum; //25ah, luminosity map (LM)
	CVidBitmap* m_pbmLumNight; //310h, night luminosity map (LN)
	CVidBitmap m_bmHeight; //314h, height map (HM)
	int* u3ca; //pC5EObject (:: CGameObject) (c: 0x95BC40)
	char u3ce; //used by CPtrListMessage?
	char u3cf; //unused?
	int u3d0;
	int u3d4;
	int u3d8;
	int u3dc;
	short u3e0; //unused?
	long long u3e2;
	int u3ea;
	TerrainTable u3ee;
	TerrainTable u3fe;
	Enum u40e; //this area CGameSprite
	int u412; //nRefs?
	int nPlayerID; //416h
	int u41a;
	int u41e; //GetTickCount() - 250
	int u422; //GetTickCount() - 5000
	char u426;
	char u427; //pad
	short u428;
	char u42a;
	char u42b; //pad
	int u42c;
			
	CAreaNotes m_AreaNotes; //430h
	short u4bc; //unused?
	CInfinity m_cInfinity; //4beh
	int u75c; //unused?
	CSearchBitmap m_SearchMap; //760h
	CVisibilityMap m_VisMap; //850h

	int u8c2; //ptr to char array (search bitmap table)
	int u8c6; //0h
	int u8ca; //50h
			
	//0: front, 1: middle?, 2: back?
	CEnumList u8ce; //8ceh, m_lVertSort, assoc 922h, CVisualEffectVidCells
	CEnumList u8ea; //8eah, assoc 93eh
	CEnumList u906; //906h, assoc 95ah
			
	//on AddToArea(), gets Enum
	//adds to active area lists after remove
	CEnumList m_lFrontAdd; //922h
	CEnumList objects1; //93eh
	CEnumList objects2; //95ah
			
	//on RemoveFromArea(), gets POSITION from above lists
	//removes from active area lists before add
	CPositionList u976;
	CPositionList u992;
	CPositionList u9ae;

	IECPtrList u9ca; //AA7014 - gets CDoorObject 438h objects
	CDwordList u9e6;
	long long ua02;
	CVariableArray AreaVariables; //a0ah
	CVariableArray ObjectNames; //a12h, contains all CGameObjects from ARE file (value is the enum?)
	char ua1a;
	char ua1b; //pad
	short wCurrentSongType; //a1ch (day, night, battle, etc.)
	int nCombatCounter; //a1eh
	int nCombatCounter2; //a22h
	short ua26;
	short ua28;
	int ua2a;
	IECPtrList ua2e; //AA6FFC
	CEnumList ua4a; //containerObject enums
	int ua66; //unused?
	int ua6a;
	short u6e; //unused?
	int ua70;
	int ua74;
	int ua78;
	int ua7c;
	int ua80;
	int ua84;
	int ua88;
	int ua8c;
	int u90; //unused?
	CSound ua94;
	CSound uafe;
	char ub68;
	char ub69; //pad
	int ub6a; //unused?
};

extern char (CArea::*CArea_GetSong)(short);

#endif //ARECORE_H