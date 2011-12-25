#ifndef AREACORE_H
#define AREACORE_H

#include "utils.h"
#include "resref.h"
#include "rescore.h"
#include "vidcore.h"
#include "sndcore.h"
#include "scrcore.h"
#include "pathfind.h"
#include "cstringex.h"

#define CAREA_SONGTYPE_DAY 0
#define CAREA_SONGTYPE_NIGHT 1
#define CAREA_SONGTYPE_VICTORY 2
#define CAREA_SONGTYPE_BATTLE 3
#define CAREA_SONGTYPE_DEFEAT 4
#define CAREA_SONGTYPE_5 5
#define CAREA_SONGTYPE_6 6
#define CAREA_SONGTYPE_7 7
#define CAREA_SONGTYPE_8 8
#define CAREA_SONGTYPE_9 9

class CInfGame;
class CArea;

struct CAreaNotes {
//Size: 0x8C
//Constructor: 0x4D6B40
	DWORD u0; //ptr
	DWORD u4;
	DWORD u8;
	DWORD uc;
	DWORD u10;
	DWORD u14;
	DWORD u18;
	DWORD u1c;
	CPtrList u20; //AA7198, contains CAutomapNote (as per area automap note struct)
	DWORD u3c[0xd];
	DWORD u70;
	DWORD u74;
	DWORD u78;
	DWORD u7c; //ptr
	ResRef areaName; //80h
	IECString u88;
};

struct CInfinity {
//Size: 0x29e
//Constructor: 0x6C356B
	CTileset* tileset[5]; //0h, corresopnds to the tilesets in TIS file
	ResWed* pRes; //14h
	DWORD u18; //pCInfGame372ch
	DWORD* pVideoMode; //1ch

	DWORD u20;
	BOOL u24; //1 = to do with pausing? time stop?
	BOOL u28; //1 = after loading dimensions and tiles?
	BOOL u2c; //bLoaded?
	DWORD u30; //gets g_windowRect.x1
	DWORD u34; //gets g_windowRect.y1
	DWORD m_tilesetMainWidth; //38h, Overlay0Width
	DWORD m_tilesetMainHeight; //3ch, Overlay0Height
	DWORD m_nScreenOffsetX; //40h, assoc u48 and u80, position of screen?
	DWORD m_nScreenOffsetY; //44h, assoc u48 and u84, position of screen?
	RECT m_rWindow; //48h, copy of g_windowRect
				
	DWORD u58; //-1
	DWORD u5c; //-1
	DWORD u60; //-1
	DWORD u64; //-1
				
	RECT m_rTilesetMain; //68h, rectOverlay0

	DWORD u78; //g_windowRectWidth/64 + 1 (window width in tiles?)
	DWORD u7c; //g_windowRectHeight/64 + 1 (window height in tiles?)
	DWORD m_areaWidth; //80h (53eh), in pixels, u38*64 (range: 320-5120)
	DWORD m_areaHeight; //84h (542h), in pixels u3c*64 (range: 320-5120)
	DWORD u88; //u90/64
	DWORD u8c; //u94/64
	DWORD u90; //0
	DWORD u94; //0

	DWORD u98;
	DWORD u9c;
	DWORD ua0;
	DWORD ua4;
	DWORD ua8;
	DWORD uac;
	DWORD ub0;
	DWORD ub4;

	CSound m_sndLightning; //b8h - lightning sound
	DWORD u122; //lightning timer seed (64, 128, or 192)
	DWORD u126;
	DWORD u12a;
	DWORD u12e;
	DWORD u132;
	DWORD u136;
	DWORD u13a;
	DWORD u13e;
	DWORD u142;
	DWORD m_LightningFlashTimer; //146h, how long until a lightning flash and sound
	DWORD m_LightningTimer; //14ah, how long one lightning flash goes for
	DWORD u14e; //assoc u152
	DWORD u152; //timer that counts down?
	DWORD u156;
	DWORD u15a;
	WORD dwAreaTypeFlags; //15eh, gets 40h of CArea (areaType)
	BYTE u160; //gets AAD291 for night Wed, AAD290 for day Wed
	BYTE u161; //gets AAD291 for night Wed, AAD290 for day Wed
	BYTE u162;
	BYTE u163;
	BYTE u164;
	BYTE u165;
	DWORD u166; //KERNEL32.GetTickCount()
	DWORD u16a; //u40*10000
	DWORD u16e; //u44*10000
#ifdef _DEBUG
	_CCriticalSection u172; //172h
#else
	CCriticalSection u172; //172h
#endif
	WORD u192;
	POINT u194;
	DWORD u19c;
	BYTE u1a0;
	BYTE u1a1;
	BOOL m_bEnableLightning; //1a2h, assoc u146
	DWORD u1a6; //assoc u14a
	BYTE u1aa;
	BYTE u1ab; //pad
	DWORD u1ac; // = u1c0, gets AAD2C4 (5a4646) for night Wed, AAD2C0 (6e6e6e) for day Wed (ARGB)
				
	//note: get lowest(1b4, 1bc) for each color, add 1b0, then set 1b8
	DWORD u1b0; //additive lighting (can be used to control fades)
	DWORD u1b4; //lighting
	DWORD u1b8; //current lightmask, copied to CVideoMode.ua4
	DWORD u1bc; //lighting

	DWORD u1c0;
	DWORD u1c4; //assoc u16a, u16e
	CArea* pArea; //1c8h, owning area
	CVidBitmap u1cc;
	DWORD u282;
	BYTE u286;
	BYTE u287; //pad
	WORD u288;
	DWORD u28a;
	DWORD u28e;
	DWORD u292;
	DWORD u296;
	DWORD u29a;
};

struct CSearchBitmap : public CVidBitmap { //Size F0h
//Constructor: 0x63E360
	BYTE* pTerrainMap; //b6h, ptr to 2D search map BYTE array
	//values of the BYTEs in array
	//1 = override with DarkGrey(TerrainTable[8]), if not set, gets terraintable[2]
	//e = if not set, gets terraintable[2]
	//70 = if not set, gets terraintable[2]
	//80 = if not set, gets terraintable[0]

	DWORD uba;
	DWORD ube;
#ifdef _DEBUG
	_CCriticalSection uc2; //c2h
#else
	CCriticalSection uc2; //c2h
#endif
	DWORD width; //ue2h (842h)
	DWORD height; //ue6h (846h)
	CArea* pArea; //ueah, owning area
	BYTE uee;
	BYTE uef; //pad
};

struct CVisibilityMap {
//Size: 0x72
//Constructor: 0x64EF10
//fog table
	DWORD* pMap; //0h, 2D array of words (vismap)
	//one fog pixel is [32x32] by (x.y)
	//bit 15 = discovered
	//bit 1 = visible (no fog)

	WORD u4; //width of map (nAreaX/32 + 1)
	WORD u6; //height of map (nAreaY/32 + 1)
	BYTE u8; //bOutdoor (based on AreaType)
	BYTE u9; //pad
#ifdef _DEBUG
	_CCriticalSection ua; //ah
#else
	CCriticalSection ua; //ah
#endif
	CSearchBitmap* pSearchMap; //2ah, associated search map
	DWORD u2e[15]; //array of enums
	DWORD* u6a; //60h size object
	DWORD* u6e; //4h of 170h size object
};

class CArea { //Size B6Eh
//Constructor: 0x4B7B80
public:
	BYTE GetSong(WORD);

	//entire ARE V1.0 header (m_header)
	ResRef areaPrefix; //0h, used for LM, LN, HT, wed, Nwed
	DWORD m_lastSaved; //8h, in game time (script rounds)
	DWORD areaFlags; //ch
	ResRef areaNorth;
	DWORD u18;
	ResRef areaEast;
	DWORD u24;
	ResRef areaSouth;
	DWORD u30;
	ResRef areaWest;
	DWORD u3c;
	WORD areaType; //40h
	WORD probRain; //42h
	WORD probSnow; //44h
	WORD probFog; //46h
	WORD probLightning; //48h
	WORD u4a;

	DWORD u4c; //disable EXTENDED_NIGHT? (see 0x4C882F)

	//entire Song entry struct
	DWORD nSongDay; //50h
	DWORD nSongNight;
	DWORD nSongVictory;
	DWORD nSongBattle;
	DWORD nSongDefeat; //60h
	DWORD nSong5; //64h
	DWORD nSong6; //68h
	DWORD nSong7; //6ch
	DWORD nSong8; //70h
	DWORD nSong9; //74h
	ResRef ambDay1; //78h
	ResRef ambDay2;
	DWORD ambDayVolume; //88h
	ResRef ambNight1;
	ResRef ambNight2;
	DWORD ambNightVolume; //9ch
	DWORD reverb;
	char ua4[0x3c];

	//entire Rest spawn struct
	char restSpawnName[32]; //0xe0
	char u100[0xc4];

	CPtrList u1c4; //AA7044 of CEntrance (68h size; as per area entrance struct)
	BYTE idxLoadedArea; //1e0h, refers CInfGame::38b6
	BYTE u1e1; //related to u218
	BYTE u1e2;
	BYTE u1e3; //related to u1c4
	ResRef rAreaName; //1e4h
	ResRef restMovieDay; //1ech
	ResRef restMovieNight; //1f4h
	ResWed* pWed; //1fch
	CRITICAL_SECTION u200; //for 1fch and 1e1h, 165h of CWed
	CRITICAL_SECTION u218; //for 906h, 8ceh, 8eah (to RemoveFromArea), 9aeh, 976h, 992h
	CInfGame* pGame; //230h
	DWORD u234;
	DWORD u238;
	BYTE u23c;
	BYTE u23d;
	DWORD u23e; //contains enum
	DWORD u242; //contains enum
	DWORD u246; //contains enum
	DWORD u24a;
	DWORD u24e;
	QWORD u252; //unused?
	CVidBitmap m_bmLum; //25ah, luminosity map (LM)
	CVidBitmap* m_pbmLumNight; //310h, night luminosity map (LN)
	CVidBitmap m_bmHeight; //314h, height map (HM)
	DWORD* u3ca; //pC5EObject (:: CGameObject) (c: 0x95BC40)
	BYTE u3ce; //used by CPtrListMessage?
	BYTE u3cf; //unused?
	DWORD u3d0;
	DWORD u3d4;
	DWORD u3d8;
	DWORD u3dc;
	WORD u3e0; //unused?
	QWORD u3e2;
	DWORD u3ea;
	TerrainTable u3ee;
	TerrainTable u3fe;
	Enum u40e; //this area CGameSprite
	DWORD u412; //nRefs?
	DWORD nPlayerID; //416h
	DWORD u41a;
	DWORD u41e; //GetTickCount() - 250
	DWORD u422; //GetTickCount() - 5000
	BYTE u426;
	BYTE u427; //pad
	WORD u428;
	BYTE u42a;
	BYTE u42b; //pad
	DWORD u42c;
			
	CAreaNotes m_AreaNotes; //430h
	WORD u4bc; //unused?
	CInfinity m_cInfinity; //4beh
	DWORD u75c; //unused?
	CSearchBitmap m_SearchMap; //760h
	CVisibilityMap m_VisMap; //850h

	DWORD u8c2; //ptr to BYTE array (search bitmap table)
	DWORD u8c6; //0h
	DWORD u8ca; //50h
			
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

	CPtrList u9ca; //AA7014 - gets CDoorObject 438h objects
	CDwordList u9e6;
	QWORD ua02;
	CVariableArray AreaVariables; //a0ah
	CVariableArray ObjectNames; //a12h, contains all CGameObjects from ARE file (value is the enum?)
	BYTE ua1a;
	BYTE ua1b; //pad
	WORD wCurrentSongType; //a1ch (day, night, battle, etc.)
	DWORD nCombatCounter; //a1eh
	DWORD nCombatCounter2; //a22h
	WORD ua26;
	WORD ua28;
	DWORD ua2a;
	CPtrList ua2e; //AA6FFC
	CEnumList ua4a; //containerObject enums
	DWORD ua66; //unused?
	DWORD ua6a;
	WORD u6e; //unused?
	DWORD ua70;
	DWORD ua74;
	DWORD ua78;
	DWORD ua7c;
	DWORD ua80;
	DWORD ua84;
	DWORD ua88;
	DWORD ua8c;
	DWORD u90; //unused?
	CSound ua94;
	CSound uafe;
	BYTE ub68;
	BYTE ub69; //pad
	DWORD ub6a; //unused?
};

extern BYTE (CArea::*CArea_GetSong)(WORD);

#endif //AREACORE_H