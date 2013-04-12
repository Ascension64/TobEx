#ifndef FILEWMP_H
#define FILEWMP_H

#include "stdafx.h"
#include "resref.h"

struct WmpFileHeader {
    DWORD m_nMapCount;
    DWORD m_nMapOffset;
};

struct WmpFileData {
    RESREF          m_resMosaic;
    DWORD           m_nWidth;
    DWORD           m_nHeight;
    DWORD           m_nMapID;
    STRREF          m_strTitle;
    DWORD           m_nStartCenteredOnX;
    DWORD           m_nStartCenteredOnY;
    DWORD           m_nAreas;
    DWORD           m_nAreasOffset;
    DWORD           m_nOffsetToLinks;
    DWORD           m_nLinks;
    RESREF          m_resAreaIcons;
    DWORD           m_nUnused[32];
};

#define CWORLDMAPAREA_FLAGS_VISIBLE         0X00000001
#define CWORLDMAPAREA_FLAGS_ENABLED         0X00000002
#define CWORLDMAPAREA_FLAGS_EXPLORABLE      0X00000004
#define CWORLDMAPAREA_FLAGS_EXPLORED        0X00000008

struct WmpFileArea {
    RESREF          m_resCurrentArea;
    RESREF          m_resOriginalArea;
    SCRIPTNAME      m_strName;
    DWORD           m_dwFlags;
    DWORD           m_sequence;
    DWORD           m_mapLocationX;
    DWORD           m_mapLocationY;
    STRREF          m_strLabel;
    STRREF          m_strAreaName;
    RESREF          m_resAreaLoadMosaic;
    DWORD           m_nNorthEdgeStartingLink;
    DWORD           m_nNorthEdgeCount;
    DWORD           m_nWestEdgeStartingLink;
    DWORD           m_nWestEdgeCount;
    DWORD           m_nSouthEdgeStartingLink;
    DWORD           m_nSouthEdgeCount;
    DWORD           m_nEastEdgeStartingLink;
    DWORD           m_nEastEdgeCount;
    DWORD           m_nUnused[32];
};

#define CWORLDMAPLINKS_FLAGS_DESTAREA_NORTHEDGE         0X00000001
#define CWORLDMAPLINKS_FLAGS_DESTAREA_EASTEDGE          0X00000002
#define CWORLDMAPLINKS_FLAGS_DESTAREA_SOUTHEDGE         0X00000004
#define CWORLDMAPLINKS_FLAGS_DESTAREA_WESTEDGE          0X00000008

struct WmpFileLinks {
    DWORD           m_nArea;
    SCRIPTNAME      m_entryPoint;
    DWORD           m_nDistanceScale;
    DWORD           m_dwLinkFlags;
    RESREF          m_resRandomEncounterArea0;
    RESREF          m_resRandomEncounterArea1;
    RESREF          m_resRandomEncounterArea2;
    RESREF          m_resRandomEncounterArea3;
    RESREF          m_resRandomEncounterArea4;
    DWORD           m_nEncounterProbability;
    DWORD           m_nUnused[32];
};

#endif //FILEWMP_H