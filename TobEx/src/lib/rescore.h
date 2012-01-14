#ifndef RESCORE_H
#define RESCORE_H

#include "stdafx.h"
#include "datatypes.h"

//file types
const int CRES_TYPE_BMP = 0x001;
const int CRES_TYPE_WAV = 0x004;
const int CRES_TYPE_WFX = 0x005;
const int CRES_TYPE_PLT = 0x006;
const int CRES_TYPE_BAM = 0x3E8;
const int CRES_TYPE_WED = 0x3E9;
const int CRES_TYPE_CHU = 0x3EA;
const int CRES_TYPE_TIS = 0x3EB;
const int CRES_TYPE_MOS = 0x3EC;
const int CRES_TYPE_ITM = 0x3ED;
const int CRES_TYPE_SPL = 0x3EE;
const int CRES_TYPE_BCS = 0x3EF;
const int CRES_TYPE_IDS = 0x3F0;
const int CRES_TYPE_CRE = 0x3F1;
const int CRES_TYPE_ARE = 0x3F2;
const int CRES_TYPE_DLG = 0x3F3;
const int CRES_TYPE_2DA = 0x3F4;
const int CRES_TYPE_GAM = 0x3F5;
const int CRES_TYPE_STO = 0x3F6;
const int CRES_TYPE_WMP = 0x3F7;
const int CRES_TYPE_EFF = 0x3F8;
const int CRES_TYPE_BS  = 0x3F9;
const int CRES_TYPE_CHR = 0x3FA;
const int CRES_TYPE_VVC = 0x3FB;
const int CRES_TYPE_VEF = 0x3FC;
const int CRES_TYPE_PRO = 0x3FD;
const int CRES_TYPE_BIO = 0x3FE;
const int CRES_TYPE_BAH = 0x44C; //compressed BAM?

typedef IECPtrList CKeyTableEntryList; //AB8E94

struct KeyTableEntry;

class Res : public CObject { //Size 50h
//Constructor: 0x987D40
public:
	void RemoveFromHandler();
	void AddToHandler();

	virtual void v0() {}

	unsigned int dwFlags; //0x4
	//not bit 0 or 1 - add to CResHandler::ua (only if bit 2 set), else add to CResHandler::u5e
	//bit 0 - add to CResHandler::u26 (only if bit 2 set), else add to CResHandler::u7a
	//bit 1 - add to CResHandler::u42 (only if bit 2 set), else add to CResHandler::u96
	//bit 2 - size loaded into CResHandler::ud2
	//bit 3 - on a CObList (ptr at ch, node at 48h)
	//bit 4 - not on a CObList
	//bit 5
	//bit 6
	//bit 7
	void* pData; //8h
	CObList* pOwner; //ch, CObList (in CResHandler) containing this object
	KeyTableEntry* pKey; //10h, from CResHandler array
	int nFileSize; //14h
	int u18; //18h
	int m_nResSizeActual; //1ch, copied from 0x14 on OpenRes()
#ifdef _DEBUG
	_CCriticalSection ccs; //20h
#else
	CCriticalSection ccs; //20h, for pData access
#endif
	int m_nDemands; //40h, number of times demanded
	int nRefs; //44h, number of references from CResHandler ObLists
	POSITION pNode; //48h, CNode containing this object
	unsigned int u4c; //4ch, identical to uc of KeyTableEntry (12 bits ?, 8 bits ?, 12 bits biffIndex [-1 for not in biff?])
};

extern void (Res::*Res_RemoveFromHandler)();
extern void (Res::*Res_AddToHandler)();

class ResBah : public Res { //Size 7Ah
//Constructor: 0x98B355
public:
	BOOL bPointersLoaded; //50h
	int* m_pBamHeaderFile; //54h
	int* m_pBamHeaderCopy; //58h
	int* m_pFrames; //5ch, frame entries (IESDP)
	int* m_pSequences; //60h, cycle entries (IESDP)
	int* m_pFrameList; //64h, frame lookup table (IESDP)
	short nTotalFrames; //68h
	BamFileFrameEntry m_CurrentFrame; //6ah
	BOOL m_bParsing; //76h
};

class ResBam : public Res { //Size 82h
//game refers to this as CResCell
//Constructor: 0x434D1C (find all Res constructors here)
public:
	BOOL bPointersLoaded; //50h
	int* m_pBamHeaderFile; //54h
	int* m_pBamHeaderCopy; //58h
	int* m_pFrames; //5ch, frame entries (IESDP)
	int* m_pSequences; //60h, cycle entries (IESDP)
	int* m_pFrameList; //64h, frame lookup table (IESDP)
	short nTotalFrames; //68h
	int* m_pPalette; //6ah, ABGR[256]
	BamFileFrameEntry m_CurrentFrame; //6eh
	BOOL m_bParsing; //7ah
	BOOL m_bCopyResData; //7eh
};

class ResBmp : public Res { //Size 6Ch
//Constructor: 0x434D1C (find all Res constructors here)
public:
	int u50; //nColorsUsed
	int u54; //a manipulation of width
	int u58; //bLoaded
	int u5c; //pRasterData
	int u60; //pHeader
	int u64; //pBitmapInfoHeader
	int u68; //pPalette
};

class ResDlg : public Res { //Size 54h
//Constructor: 0x434D1C (find all Res constructors here)
public:
	int u50;
};

class ResEff : public Res { //Size 54h
//Constructor: 0x434D1C (find all Res constructors here)
public:
	BOOL bHeaderValid; //50h, pFile points to file with correct header
};

class ResItm : public Res { //Size 60h
//Constructor: 0x434D1C (find all Res constructors here)
public:
	void* Demand();
	int Release();

	int* pAbilities; //0x50
	int* pEffects; //0x54
	int* pFile; //0x58
	BOOL bPointersLoaded; //0x5c
};

extern void* (ResItm::*ResItm_Demand)();
extern int (ResItm::*ResItm_Release)();

class ResSpl : public Res { //Size 60h
//Constructor: 0x434D1C (find all Res constructors here)
public:
	int* pAbilities; //50h
	int* pEffects; //54h
	int* pFile; //58h
	int* numAbilities; //5ch
};

class ResSto : public Res { //Size 54h
//Constructor: 0x434D1C (find all Res constructors here)
public:
	BOOL bPointersLoaded; //50h
};

class ResTis : public Res { //Size 64h
//Constructor: 0x434D1C (find all Res constructors here)
public:
	int u50;
	int u54;
	ResRef owningArea; //58h
	int u60;
};

class ResTxt : public Res { //Size 5Ch
//Common to BCS, BS, 2DA, and IDS
//Constructor: 0x434D1C (find all Res constructors here)
public:
	BOOL bPointersLoaded; //50h
	int u54; //54h
	IECString csData; //58h
};

class ResWav : public Res { //Size 68h
//Constructor: 0x434D1C (find all Res constructors here)
public:
	BOOL bCompressed; //50h, 0 = RIFF/WAVE, 1 = WAVC
	BOOL bPointerLoaded; //54h
	int nUncompressedSize; //58h
	int nCompressedSize; //5ch
	void* pData; //60h
	int* pWaveFormatEx; //64h
};

class ResWed : public Res { //Size 6Ch
//Constructor: 0x434D1C (find all Res constructors here)
public:
	int* pHeader; //50h
	int* pOverlays; //54h
	int* pSecondHeader; //58h, wall polygons
	int* pWallGroupsu; //5ch
	int* pWallPolygons; //60h
	int* pVertices; //64h
	BOOL bPointerLoaded; //68h
};

class ResVid : public Res { //Size 58h
//Constructor: 0x434D1C (find all Res constructors here)
//Used VVC, VEF, PRO, WFX files
public:
	int* u50; //pFile+4
	BOOL bPointersLoaded; //54h
};

struct KeyTableEntry { //Size 18h
	ResRef name; //0h
	Res* pRes; //8h
	int uc; //ch, two short, 0xc ?, 0xe biffIndex
	short nLoaded; //10h, numDemands?
	short nCResType; //12h
	int u14; //14h
};

class CBiff : public CObject { //Size 3Ah
//Constructor: 0x99814F
public:
	//AB8E88
	virtual ~CBiff() {} //v4

	int u4;
	int m_nDemands; //8h
	int uc;
	int m_nBiffIndex; //10h
	BifFileHeader* m_pBiffHeader; //14h
	BifFileEntry* m_pFilesArray; //18h
	BifTileEntry* m_pTilesArray; //1ch
	int u20;
	BOOL m_bBiffLoaded; //24h
	CFile m_file; //28h
	bool m_bFromCD; //38h
	char u39; //pad
};

struct CResHandler { //Size 2A8h
//Constructor: 0x98CB00
	void Free(Res& res);

	int u0;
	BOOL bServiceRequested; //4h, currently demanded or not
	short nRequests; //8h
		
	//CRITICAL_SECTION required to access (see CBaldurChitin)
	CObList ua; //contains Res with flags bit 0 and 1 both not set (only if bit 2 set), for 2DA Res only?
	CObList u26; //contains Res with flags bit 0 set (only if bit 2 set)
	CObList u42; //contains Res with flags bit 1 set (only if bit 2 set)
	CObList u5e; //contains Res with flags bit 0 and 1 both not set (only if bit 2 not set)
	CObList u7a; //contains Res with flags bit 1 set (only if bit 2 not set)
	CObList u96; //contains Res with flags bit 2 set (only if bit 2 not set)
	CObList ub2; //for graphic Res only?

	Res* uce; //if this matches currentRes being demanded, will close the Res when demanded
	int ud2; //filesize of tempRes
	int ud6; //assoc with uda
	int uda; //sum of all file sizes that are loaded, if this > ud6, then clear all above CObLists
	SIZE_T dwTotalPhys; //deh, from GlobalMemoryStatus
	int ue2; //current biffIndex? compared to Res u4c
	int ue6;
	short uea;
	int* pBiffPtrArray; //ech, pointer to array of CBiff* pointers
	struct CResCache { //Size 15Ch
	//Constructor: 0x99C3BC
		BOOL m_bCacheInitialized;; //0h
		char cwd[260]; //4h, getcwd() - current working directory (game path)
		IECString cacheDirectory; //108h, "hd0:\\cache\\"
		IECString u10c;
		int u110;
		int u114;
		int u118;
		int u11c;
		int u120; //nDumpedFilesize?
		int u124; //nCacheFiles
		IECPtrList u128; //AB8EAC, 0x0 biffIndex, 0x4 ?, 0x8 int fileSize
		CRITICAL_SECTION u144; //access to IECPtrList u128
	} m_cache; //f0h
		
	struct KeyTable { //Size 24h
		int u0; //isLoaded or bEnabled?

		int* pBiffKeyArray; //4h - help to find name of biff
		//CBiffKey
		//Size: Ch
		//int m_filesize; //0h
		//int offset; //4h, pBiffs + offset = char* biffshortpath
		//short u8; //flags
		//short ua;

		int nBiffs; //8h
		int uc; //nKeys
		KeyTableEntry* keys; //10h
		int u14;
		int u18;
		int u1c;
		int u20;
	} m_KeyTable; //0x24c
	Res* pResTemp; //270h, CRITICAL_SECTION required to access (see CBaldurChitin)
	int u274;
	IECPtrList directories; //278h, AB8E7C, of CStrings (full path directories, e.g. override, cache)
	char u294;
	char u295[3]; //pad
	IECString u298;
	int u29c; //sum of all file sizes that are loaded
	int u2a0;
	char u2a4; //pad
	char u2a5;
	char u2a6;
	char u2a7; //pad
};

extern void (CResHandler::*CResHandler_Free)(Res&);

#endif //RESCORE_H