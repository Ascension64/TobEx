#ifndef FILEWED_H
#define FILEWED_H

#include "stdafx.h"
#include "resref.h"

struct FileWedWedHeader {
	DWORD   m_nFileType;
	DWORD   m_nFileVersion;
	DWORD   m_nLayers;
	DWORD   m_nTiledObjects;
	DWORD   m_nOffsetToLayerHeaders;
	DWORD   m_nOffsetToPolyHeader;
	DWORD   m_nOffsetToTiledObjects;
	DWORD   m_nOffsetToObjectTileList;
	WORD    m_nVisiblityRange;
	WORD    m_nChanceOfRain;
	WORD    m_nChanceOfFog;
	WORD    m_nChanceOfSnow;
	DWORD   m_dwFlags;
};

struct FileWedLayerHeader {
	WORD    m_nTilesAcross;
	WORD    m_nTilesDown;
	RESREF  m_rrTileSet;
	WORD    m_nNumUniqueTiles;
	WORD    m_nMovementType;
	DWORD   m_nOffsetToTileData;
	DWORD   m_nOffsetToTileList;
};

struct FileWedPolyHeader {
	DWORD   m_nPolys;
	DWORD   m_nOffsetToPolyList;
	DWORD   m_nOffsetToPointList;
	DWORD   m_nOffsetToScreenSectionList;
	DWORD   m_nOffsetToScreenPolyList;
};

struct FileWedTiledObject {
	RESREF  m_resID;
	WORD    m_bType;
	WORD    m_nStartingTile;
	WORD    m_nNumTiles;
	WORD    m_nNumPrimaryPolys;
	WORD    m_nNumSecondaryPolys;
	DWORD   m_nOffsetToPrimaryPolys;
	DWORD   m_nOffsetToSecondaryPolys;
};

struct FileWedTileData {
	WORD    m_nStartingTile;
	WORD    m_nNumTiles;
	short   m_nSecondary;
	BYTE    m_bFlags;
	BYTE    m_bAnimSpeed;
	WORD    m_wFlags;
};

struct FileWedScreenSectionList {
	WORD    m_nStartingPoly;
	WORD    m_nNumPolys;
};

struct FileWedPolyList {
	DWORD   m_nStartingPoint;
	DWORD   m_nNumPoints;
	BYTE    m_nType;
	BYTE    m_nHeight;
	WORD    m_nLeft;
	WORD    m_nRight;
	WORD    m_nTop;
	WORD    m_nBottom;
//	BYTE    m_wFlags;
};

struct FileWedPolyPoint {
	WORD    m_x;
	WORD    m_y;
};

#define WED_DAYNIGHT_ENABLED    0x00000001
#define WED_WEATHER_ENABLED     0x00000002
#define WED_MAINCLEAR           0x01
#define WED_SUBLAYER1ENABLED    0x02
#define WED_SUBLAYER2ENABLED    0x04
#define WED_SUBLAYER3ENABLED    0x08
#define WED_SUBLAYER4ENABLED    0x10
#define WED_SUBLAYERSENABLED    0x1E

#define WED_POLYTYPE_HORIZONTAL 0x00
#define WED_POLYTYPE_VERTICAL   0x01
#define WED_POLYTYPE_NORMAL     0x00
#define WED_POLYTYPE_TILED      0x80

#define WED_TILEDOBJECT_TYPE_NORMAL 0x00;
#define WED_TILEDOBJECT_TYPE_DOOR   0x01;

#define WED_GETMAINCLEAR(a) ((a) & WED_MAINCLEAR)
#define WED_GETSUBLAYER1ENABLED(a) ((a) & WED_SUBLAYER1ENABLED)
#define WED_GETSUBLAYER2ENABLED(a) ((a) & WED_SUBLAYER2ENABLED)
#define WED_GETSUBLAYER3ENABLED(a) ((a) & WED_SUBLAYER3ENABLED)
#define WED_GETSUBLAYER4ENABLED(a) ((a) & WED_SUBLAYER4ENABLED)
#define WED_GETSUBLAYERSENABLED(a) ((a) & WED_SUBLAYERSENABLED)

#endif //FILEWED_H