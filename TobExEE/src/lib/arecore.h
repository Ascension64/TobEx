//TobExEE
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

#define LIST_FRONT		0
#define LIST_BACK		1
#define LIST_2			2

class CInfGame;
class CArea;
class CObjectMarker;

struct CAreaNotes { //Size 8Ch
	void* u0;
	int u4;
	int u8[2];
	int u10[2];
	int u18[2];
	IECPtrList u20; //contains CAutomapNote (as per area automap note struct)
	char u3c[52];
	int u70;
	int u74;
	int u78;
	void* u7c;
	ResRef m_rAreaName; //80h
	IECString u88;
};

struct CInfinity { //Size 314h
	CTileset* m_pTileset[5]; //0h, corresopnds to the tilesets in TIS file
	ResWed* m_pRes; //14h
	int* u18; //gets value from CInfGame
	void* m_pVideo; //1ch
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
	RECT m_rectWindow; //48h, copy of g_windowRect
	RECT u58; //-1.-1.-1.-1
	RECT m_rectTilesetMain; //68h, rectOverlay0
	RECT u78; //[g_windowRectWidth/64 + 1 (window width in tiles?), g_windowRectHeight/64 + 1 (window height in tiles?), m_areaWidth in pixels, u38*64 (range: 320-5120), m_areaHeight in pixels u3c*64 (range: 320-5120)
	CPoint u88; //u90/64.u94/64
	CPoint u90; //0.0
	int u98;
	int u9c;
	int ua0;
	int ua4;
	int ua8;
	int uac;
	int ub0;
	int ub4;
	int ub8;
	int ubc;
	int uc0;
	int uc4;
	CSoundWrapper m_sndLightning; //c8h, lightning sound
	int ue0; //lightning timer seed (64, 128, or 192)
	int ue4;
	int ue8;
	int uec;
	int uf0;
	int uf4;
	int uf8;
	int ufc;
	int u100;
	int u104;
	int m_LightningFlashTimer; //108h
	int m_LightningTimer; //10ch
	int u110;
	int u114;
	int u118;
	CVidCell m_cvcGroundGlow; //11ch, GRNDGLOW
	unsigned short m_wAreaFlags; //1e0h
	char u1e2; //bit0: day, bit1: night, gets AAD291 for night Wed, AAD290 for day Wed
	char u1e3; //gets AAD291 for night Wed, AAD290 for day Wed
	char u1e4; //FF during day, 0 during night
	char u1e5; //bit0: day, bit1: night
	char u1e6;
	char u1e7;
	char u1e8; //GetTicks
	char p1e9[3];
	int u1ec; //u40*10000
	int u1f0; //u44*10000
	short u1f4;
	char p1f6[2];
	CPoint u1f8;
	int u200;
	char u204;
	char u205;
	char p206[2];
	BOOL m_bEnableLightning; //208h
	int u20c;
	char u210;
	char p211[3];
	int u214; // = u1c0, gets AAD2C4 (5a4646) for night Wed, AAD2C0 (6e6e6e) for day Wed (ABGR)
	//note: get lowest(1b4, 1bc) for each color, add 1b0, then set 1b8
	int u218; //additive lighting (can be used to control fades)
	int u21c; //lighting
	int u220; //current lightmask
	ABGR u224; //lighting (FFFFFF day, C86464 night)
	ABGR u228; //lighting (6E6E6E day, 5A4646 night)
	int u22c;
	CArea* pArea; //230h
	CVidBitmap u234;
	int u2e8;
	char u2ec;
	char p2ed;
	short u2ee;
	int u2f0;
	int u2f4;
	int u2f8;
	int u2fc;
	int u300;
	int u304;
	int u308;
	float u30c; //for touch UI
	int u310; //for touch UI
};

struct CSearchBitmap : public CVidBitmap { //Size D0h
	char* pTerrainMap; //b4h, ptr to 2D search map char array
	//values of the BYTEs in array
	//1 (bit 0) = override with DarkGrey(TerrainTable[8]), if set, gets terraintable[2] (metal)
	//e (bits 1, 2, 3) = if set, gets terraintable[2] (metal)
	//70 (bits 4, 5, 6) = if set, gets terraintable[2] (metal)
	//80 (bit 7) = if set, gets terraintable[0] (opaque obstacle)

	int ub8;
	int ubc;
	CPoint m_pt; //c0h, [width.height]
	CArea* m_pArea; //c8, owning area
	char ucc;
	char pcd[3];
};

struct CVisibilityMap { //Size 54h
	int* m_pMap; //0h, 2D array of words (vismap)
	//one fog pixel is [32x32] by (x.y)
	//bit 15 = discovered
	//bit 1 = visible (no fog)

	short m_wWidth; //4h, width of map (nAreaX/32 + 1)
	short m_wHeight; //6h, height of map (nAreaY/32 + 1)
	char u8; //bOutdoor (based on AreaType)
	char p9[3];
	CSearchBitmap* m_pSearchMap; //ch, associated search map
	ENUM u10[15]; //array
	void* u4c; //60h size object
	void* u50; //4h of 1a4h size object
};

class CArea { //Size B44h (->B68h)
public:
	AreFileHeader m_header; //0h, ARE V1.0 header
	int u4c; //disable EXTENDED_NIGHT?
	AreSoundsAndMusic m_music; //50h
	AreFileRestEncounter m_spawns; //e0h
	IECPtrList u1c4; //of CEntrance (68h size; as per area entrance struct)
	char m_idxLoadedArea; //1e0h, refers CInfGame::38b6
	char u1e1; //related to u218
	char u1e2;
	char u1e3; //related to u1c4
	ResRef m_rAreaName; //1e4h
	ResRef m_restMovieDay; //1ech
	ResRef m_restMovieNight; //1f4h
	ResWed* m_pWed; //1fch
	CInfGame* m_pGame; //200h
	int u204;
	int u208;
	char u20c;
	char u20d;
	char p20e[2];
	int u210;
	int u214;
	ENUM u218;
	ENUM m_eCursorTarget; //21ch, eDamageLocatorTarget
	ENUM u220;
	int u224;
	int u228;
	int u22c;
	int u230;
	CVidBitmap m_bmLum; //234h, luminosity map (LM)
	CVidBitmap* m_pbmLumNight; //2e8h, night luminosity map (LN)
	CVidBitmap m_bmHeight; //2ech, height map (HM)
	int u3a0;
	int u3a4;
	CRect u3a8;
	int u3b8;
	CPoint u3bc;
	CObjectMarker* m_pObjectMarker; //3c4h
	TerrainTable u3c8;
	TerrainTable u3d8;
	ENUM m_eAreaObject; //3e8h, this area CGameSprite
	int u3ec;
	int m_nPlayerID; //3f0h
	int u3f4; //-1
	int u3f8;
	int u3fc;
	char u400;
	char p401;
	short u402;
	bool m_bSaved; //404h
	char p405[3];
	unsigned int m_nSavedTime; //408h
	CAreaNotes m_AreaNotes; //40ch
	int u498;
	CInfinity m_cInfinity; //49ch
	CSearchBitmap m_SearchMap; //7b0h
	CVisibilityMap m_VisMap; //880h
	char* m_SearchBitmapTableArray; //8d4h, ptr to char array (search bitmap table)
	int u8d8;
	int u8dc;
			
	//0: front, 1: back, 2: ?
	CEnumList m_lVertSortFront; //8e0h, m_lVertSort, CVisualEffectVidCells
	CEnumList m_lVertSortBack; //8fch
	CEnumList m_lVertSort2; //918h
			
	//on AddToArea(), gets ENUM
	//adds to active area lists after removing from here
	CEnumList m_lFrontAdd; //934h
	CEnumList m_lBackAdd; //950h
	CEnumList m_l2Add; //96ch
			
	//on RemoveFromArea(), gets POSITION from above lists
	//removes from active area lists before adding heere
	CPositionList m_lFrontRemove; //988h
	CPositionList m_lBackRemove; //9a4h
	CPositionList m_l2Remove; //9c0h

	IECPtrList u9dc; //gets CDoorObjects
	CEnumList m_ObjectsToMarshal; //9f8h, enums to save into area on Marshal()
	IECPtrList ua14;
	CPoint ua30;
	CVariableMap m_mapAreaVariables; //a38h
	CVariableMap m_mapNamedCreatures; //a40h, CGameObjects from ARE file (value is enum)
	char ua48;
	char pa49;
	short m_wCurrentSongType; //a4ah (day, night, battle, etc.)
	int m_nCombatCounter; //a4ch
	int m_nCombatCounter2; //a50h
	short ua54;
	short ua56;
	int ua58;
	IECPtrList ua5c; //AA6FFC
	CEnumList m_eContainers; //a78h, for multiplayer only?
	int ua94;
	int ua98;
	int ua9c;
	int uaa0;
	int uaa4;
	int uaa8;
	int uaac;
	int uab0;
	int uab4;
	int uab8;
	int uabc;
	int uac0;
	int uac4;
	CSoundWrapper m_sndAmbDay; //ac8h
	CSoundWrapper m_sndAmbNight; //ae0h
	char m_nSndAmbVolumePercent; //af8h (of 100%)
	char paf9[3];
	int m_nSndAmbVolume; //afch

	struct unk1 { //Size Ch
		CPoint u0;
		int u8;

		//=>Size 1Ch
		//int u0;
		//CPoint u4;
		//int uc[2];
		//int u14;
		//int u18;
	} ub00[2];
	struct unk2 { //Size 14h, to do with touch UI
		float u0;
		CPoint u4;
		int uc;
		int u10;
	} ub18; //=>b38h
	struct unk3 { //Size 18h
		CPoint u0;
		float u8;
		float uc;
		float u10;
		float u14;
		
		//=>Size 1Ch
		//int u0;
		//CPoint u4;
		//float uc;
		//float u10;
		//float u14;
		//float u18;
	} ub2c; //=>b4ch
};

#endif //ARECORE_H