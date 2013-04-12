//TobExEE
#ifndef RESCORE_H
#define RESCORE_H

#include "stdafx.h"
#include "fileare.h"
#include "filebam.h"
#include "filebif.h"
#include "filechu.h"
#include "filecre.h"
#include "filedlg.h"
#include "fileeff.h"
#include "filegam.h"
#include "fileitm.h"
#include "filepro.h"
#include "filespl.h"
#include "filesto.h"
#include "filevvc.h"
#include "filewed.h"
#include "filewmp.h"

//file types
typedef const int CRES_TYPE;
const int CRES_TYPE_BMP = 0x001; //1
const int CRES_TYPE_WAV = 0x004; //4
const int CRES_TYPE_WFX = 0x005; //5
const int CRES_TYPE_PLT = 0x006; //6
const int CRES_TYPE_BAM = 0x3E8; //1000
const int CRES_TYPE_WED = 0x3E9; //1001
const int CRES_TYPE_CHU = 0x3EA; //1002
const int CRES_TYPE_TIS = 0x3EB; //1003
const int CRES_TYPE_MOS = 0x3EC; //1004
const int CRES_TYPE_ITM = 0x3ED; //1005
const int CRES_TYPE_SPL = 0x3EE; //1006
const int CRES_TYPE_BCS = 0x3EF; //1007
const int CRES_TYPE_IDS = 0x3F0; //1008
const int CRES_TYPE_CRE = 0x3F1; //1009
const int CRES_TYPE_ARE = 0x3F2; //1010
const int CRES_TYPE_DLG = 0x3F3; //1011
const int CRES_TYPE_2DA = 0x3F4; //1012
const int CRES_TYPE_GAM = 0x3F5; //1013
const int CRES_TYPE_STO = 0x3F6; //1014
const int CRES_TYPE_WMP = 0x3F7; //1015
const int CRES_TYPE_EFF = 0x3F8; //1016
const int CRES_TYPE_BS  = 0x3F9; //1017
const int CRES_TYPE_CHR = 0x3FA; //1018
const int CRES_TYPE_VVC = 0x3FB; //1019
const int CRES_TYPE_VEF = 0x3FC; //1020
const int CRES_TYPE_PRO = 0x3FD; //1021
const int CRES_TYPE_BIO = 0x3FE; //1022
const int CRES_TYPE_WBM = 0x3FF; //1023, BGEE
const int CRES_TYPE_FNT = 0x400; //1024, BGEE
const int CRES_TYPE_GUI = 0x402; //1026, BGEE
const int CRES_TYPE_SQL = 0x403; //1027, BGEE
const int CRES_TYPE_PVRZ = 0x404; //1028, BGEE
const int CRES_TYPE_BAH = 0x44C; //compressed BAM?

typedef IECPtrList CKeyTableEntryList;

struct KeyTableEntry;

class Res : public CObject { //Size 30h
public:
	virtual void v0() {}

	unsigned int m_dwFlags; //0x4
	//not bit 0 or 1 - add to CResHandler::ua (only if bit 2 set), else add to CResHandler::u5e
	//bit 0 - add to CResHandler::u26 (only if bit 2 set), else add to CResHandler::u7a
	//bit 1 - add to CResHandler::u42 (only if bit 2 set), else add to CResHandler::u96
	//bit 2 - size loaded into CResHandler::ud2
	//bit 3 - on a CObList (ptr at ch, node at 48h)
	//bit 4 - not on a CObList
	//bit 5
	//bit 6
	//bit 7
	void* m_pData; //8h
	CObList* m_pOwner; //ch, CObList (in CResHandler) containing this object
	KeyTableEntry* m_pKey; //10h, from CResHandler array
	int m_nFileSize; //14h
	int u18; //18h
	int m_nResSizeActual; //1ch, copied from 0x14 on OpenRes()
	int m_nDemands; //20h, number of times demanded
	int m_nRefs; //24h, number of references from CResHandler ObLists
	POSITION m_pNode; //28h, CNode containing this object
	unsigned int u2c; //2ch, identical to uc of KeyTableEntry (12 bits ?, 8 bits ?, 12 bits biffIndex [-1 for not in biff?])
};

class ResBah : public Res { //Size 7Ah, FIX_ME
public:
	BOOL m_bPointersLoaded; //50h
	int* m_pBamHeaderFile; //54h
	int* m_pBamHeaderCopy; //58h
	int* m_pFrames; //5ch, frame entries (IESDP)
	int* m_pSequences; //60h, cycle entries (IESDP)
	int* m_pFrameList; //64h, frame lookup table (IESDP)
	short m_nTotalFrames; //68h
	BamFileFrameEntry m_CurrentFrame; //6ah
	BOOL m_bParsing; //76h
};

class ResBam : public Res { //Size 4Eh, FIX_ME
//game refers to this as CResCell
public:
	BOOL m_bPointersLoaded; //30h
	int* m_pBamHeaderFile; //34h
	int* m_pFrames; //38h, frame entries (IESDP)
	int* m_pSequences; //3ch, cycle entries (IESDP)
	int* m_pFrameList; //40h, frame lookup table (IESDP)
	short nTotalFrames; //44h
	int* m_pPalette; //46h, ABGR[256]
	BOOL m_bParsing; //4ah
};

class ResBmp : public Res { //Size 4Ch
public:
	int u30; //nColorsUsed
	int u34; //a manipulation of width
	int u38; //bLoaded
	int u3c; //pRasterData
	int u40; //pHeader
	int u44; //pBitmapInfoHeader
	int u48; //pPalette
};

class ResDlg : public Res { //Size 34h
public:
	int u30;
};

class ResEff : public Res { //Size 34h
public:
	BOOL m_bHeaderValid; //30h, pFile points to file with correct header
};

class ResItm : public Res { //Size 40h
public:
	int* m_pAbilities; //30h
	int* m_pEffects; //34h
	int* m_pFile; //38h
	BOOL m_bPointersLoaded; //3ch
};

class ResSpl : public Res { //Size 40h
public:
	int* m_pAbilities; //30h
	int* m_pEffects; //34h
	int* m_pFile; //38h
	int* m_numAbilities; //3ch
};

class ResSto : public Res { //Size 34h
public:
	BOOL m_bPointersLoaded; //30h
};

class ResTis : public Res { //Size 50h
public:
	int u30;
	int u34;
	ResRef m_rOwningArea; //38h
	int u40;
	int u44;
	int u48;
	int u4c;
};

class ResTxt : public Res { //Size 3Ch
//BCS, BS, 2DA, IDS, SQL
public:
	BOOL m_bPointersLoaded; //30h
	int u34;
	IECString m_sData; //38h
};

class ResWav : public Res { //Size 4Ch
public:
	BOOL m_bCompressed; //30h, 0 = RIFF/WAVE, 1 = WAVC
	BOOL m_bPointerLoaded; //34h
	int m_nUncompressedSize; //38h
	int m_nCompressedSize; //3ch
	void* m_pData; //40h
	int* m_pWaveFormatEx; //44h
	int u48;
};

class ResWed : public Res { //Size 4Ch
public:
	int* m_pHeader; //30h
	int* m_pOverlays; //34h
	int* m_pSecondHeader; //38h, wall polygons
	int* m_pWallGroupsu; //3ch
	int* m_pWallPolygons; //40h
	int* m_pVertices; //44h
	BOOL m_bPointerLoaded; //48h
};

class ResVid : public Res { //Size 38h
//VVC, VEF, PRO, WFX
public:
	int* u30; //pFile+4
	BOOL m_bPointersLoaded; //34h
};

struct CKeyTableEntry { //Size 18h, FIX_ME
	ResRef m_rName; //0h
	Res* m_pRes; //8h
	int uc; //ch, two short, 0xc ?, 0xe biffIndex
	short m_wLoaded; //10h, numDemands?
	short m_wResType; //12h
	int u14; //14h
};

class CBiff : public CObject { //Size 38h, FIX_ME
public:
	int u4;
	int m_nDemands; //8h
	int uc;
	int m_nBiffIndex; //10h
	BifFileHeader* m_pBiffHeader; //14h
	BifFileEntry* m_pFilesArray; //18h
	BifTileEntry* m_pTilesArray; //1ch
	BOOL m_bBiffLoaded; //20h
	CFile m_file; //24h
	bool m_bFromCD; //34h
	char p35[3];
};

struct CBiffKey { //Size Ch, FIX_ME
	int m_nFilesize; //0h
	int m_nOffset; //4h, pBiffs + offset = char* biffshortpath
	short u8; //flags
	short ua;
};

struct CKeyTable { //Size 24h
	int u0; //isLoaded or bEnabled?
	CBiffKey* m_pBiffKeyArray; //4h - help to find name of biff
	int m_nBiffs; //8h
	int uc; //nKeys
	CKeyTableEntry* m_keys; //10h
	int u14;
	int u18;
	int u1c;
	int u20;
};

class CCache : public CObject { //Size 1Ch
public:
	int u4;
	int u8;
	int uc;
	int u10;
	int u14;
	int u18;
};

struct CResHandler { //Size 140h
	int u0;
	CObList u4; //contains Res with flags bit 0 and 1 both not set (only if bit 2 set), for 2DA Res only?
	CObList u20; //contains Res with flags bit 0 set (only if bit 2 set)
	CObList u3c; //contains Res with flags bit 1 set (only if bit 2 set)
	CObList u58; //contains Res with flags bit 0 and 1 both not set (only if bit 2 not set)
	CObList u74; //contains Res with flags bit 1 set (only if bit 2 not set)
	CObList u90; //contains Res with flags bit 2 set (only if bit 2 not set)
	CObList uac; //for graphic Res only?
	int uc8;
	int ucc;
	int ud0; //0x4000000
	int ud4;
	int ud8; //12000000
	int udc;
	int ue0; //1
	int ue4;
	CKeyTable m_KeyTable; //e8h
	int u10c;
	int u110;
	CCache u114;
	char u130;
	char p131[3];
	IECString u134;
	int u138;
	char u13c;
	char u13d;
	char u13e;
	char p13f;
};

#endif //RESCORE_H