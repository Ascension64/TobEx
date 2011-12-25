#ifndef RESCORE_H
#define RESCORE_H

#include "utils.h"
#include "datatypes.h"
#include "resref.h"
#include "cstringex.h"

//file types
const DWORD CRES_TYPE_BMP = 0x001;
const DWORD CRES_TYPE_WAV = 0x004;
const DWORD CRES_TYPE_WFX = 0x005;
const DWORD CRES_TYPE_PLT = 0x006;
const DWORD CRES_TYPE_BAM = 0x3E8;
const DWORD CRES_TYPE_WED = 0x3E9;
const DWORD CRES_TYPE_CHU = 0x3EA;
const DWORD CRES_TYPE_TIS = 0x3EB;
const DWORD CRES_TYPE_MOS = 0x3EC;
const DWORD CRES_TYPE_ITM = 0x3ED;
const DWORD CRES_TYPE_SPL = 0x3EE;
const DWORD CRES_TYPE_BCS = 0x3EF;
const DWORD CRES_TYPE_IDS = 0x3F0;
const DWORD CRES_TYPE_CRE = 0x3F1;
const DWORD CRES_TYPE_ARE = 0x3F2;
const DWORD CRES_TYPE_DLG = 0x3F3;
const DWORD CRES_TYPE_2DA = 0x3F4;
const DWORD CRES_TYPE_GAM = 0x3F5;
const DWORD CRES_TYPE_STO = 0x3F6;
const DWORD CRES_TYPE_WMP = 0x3F7;
const DWORD CRES_TYPE_EFF = 0x3F8;
const DWORD CRES_TYPE_BS  = 0x3F9;
const DWORD CRES_TYPE_CHR = 0x3FA;
const DWORD CRES_TYPE_VVC = 0x3FB;
const DWORD CRES_TYPE_VEF = 0x3FC;
const DWORD CRES_TYPE_PRO = 0x3FD;
const DWORD CRES_TYPE_BIO = 0x3FE;
const DWORD CRES_TYPE_BAH = 0x44C; //compressed BAM?

typedef CPtrList CPtrListKeyTableEntry; //AB8E94

struct KeyTableEntry;

class Res : public CObject { //Size 50h
//Constructor: 0x987D40
public:
	virtual void v0() {}

	DWORD dwFlags; //0x4
	//bit 0
	//bit 1
	//bit 2 - size loaded into CResHandler::ud2
	//bit 3
	//bit 4 - not on a CObList
	//bit 5
	//bit 6
	//bit 7
	void* pData; //0x8
	CObList* pOwner; //0xc, CObList containing this object
	KeyTableEntry* pKey; //0x10, from CResHandler array
	DWORD nFileSize; //0x14
	DWORD u18; //0x18
	DWORD m_nResSizeActual; //0x1c, copied from 0x14 on OpenRes()
#ifdef _DEBUG
	_CCriticalSection ccs; //0x20
#else
	CCriticalSection ccs; //0x20, for pData access
#endif
	DWORD m_nDemands; //0x40, number of times demanded
	DWORD nRefs; //0x44, number of CPtr objects in master CPtrList containing this object
	POSITION pNode; //0x48, CNode containing this object
	DWORD dwFlags2; //0x4c
};

class ResDlg : public Res {
//Size: 0x54
//Constructor: 0x434D1C (find all Res constructors here)
public:
	virtual void v0() {}

	DWORD u50;
};

class ResEff : public Res {
//Size: 0x54
//Constructor: 0x434D1C (find all Res constructors here)
public:
	virtual void v0() {}
		
	BOOL bHeaderValid; //50h, pFile points to file with correct header
};

class ResBam : public Res {
//game refers to this as CResCell
//Size: 0x82
//Constructor: 0x434D1C (find all Res constructors here)
public:
	virtual void v0() {}

	BOOL bPointersLoaded; //50h
	DWORD* m_pBamHeaderFile; //54h
	DWORD* m_pBamHeaderCopy; //58h
	DWORD* m_pFrames; //5ch, frame entries (IESDP)
	DWORD* m_pSequences; //60h, cycle entries (IESDP)
	DWORD* m_pFrameList; //64h, frame lookup table (IESDP)
	WORD nTotalFrames; //68h
	DWORD* m_pPalette; //6ah, ARGB[256]
	BamFileFrameEntry m_CurrentFrame; //6eh
	BOOL m_bParsing; //7ah
	BOOL m_bCopyResData; //7eh
};

class ResBah : public Res { //Size 7Ah
//Constructor: 0x98B355
public:
	virtual void v0() {}

	BOOL bPointersLoaded; //50h
	DWORD* m_pBamHeaderFile; //54h
	DWORD* m_pBamHeaderCopy; //58h
	DWORD* m_pFrames; //5ch, frame entries (IESDP)
	DWORD* m_pSequences; //60h, cycle entries (IESDP)
	DWORD* m_pFrameList; //64h, frame lookup table (IESDP)
	WORD nTotalFrames; //68h
	BamFileFrameEntry m_CurrentFrame; //6ah
	BOOL m_bParsing; //76h
};

class ResBmp : public Res {
//Size: 0x6c
//Constructor: 0x434D1C (find all Res constructors here)
public:
	virtual void v0() {}

	DWORD u50; //nColorsUsed
	DWORD u54; //a manipulation of width
	DWORD u58; //bLoaded
	DWORD u5c; //pRasterData
	DWORD u60; //pHeader
	DWORD u64; //pBitmapInfoHeader
	DWORD u68; //pPalette
};

class ResTis : public Res {
//Size: 0x64
//Constructor: 0x434D1C (find all Res constructors here)
public:
	virtual void v0() {}

	DWORD u50;
	DWORD u54;
	ResRef owningArea; //58h
	DWORD u60;
};

class ResTxt : public Res {
//Common to BCS, BS, 2DA, and IDS
//Size: 0x5c
//Constructor: 0x434D1C (find all Res constructors here)
public:
	virtual void v0() {}

	BOOL bPointersLoaded; //50h
	DWORD u54; //54h
	IECString csData; //58h
};

class ResWed : public Res {
//Size: 0x6c
//Constructor: 0x434D1C (find all Res constructors here)
public:
	virtual void v0() {}

	DWORD u50; //pHeader
	DWORD u54; //pOverlays
	DWORD u58; //pSecondHeader (wall polygons)
	DWORD u5c; //pWallGroups
	DWORD u60; //pWallPolygons
	DWORD u64; //pVertices
	DWORD u68; //bPointersLoaded
};

class ResSpl : public Res {
//Size: 0x60
//Constructor: 0x434D1C (find all Res constructors here)
public:
	virtual void v0() {}

	DWORD* pAbilities; //0x50
	DWORD* pEffects; //0x54
	DWORD* pFile; //0x58
	DWORD* numAbilities; //0x5c
};

class ResSto : public Res {
//Size: 0x54
//Constructor: 0x434D1C (find all Res constructors here)
public:
	virtual void v0() {}

	BOOL bPointersLoaded; //0x50
};

class ResItm : public Res {
//Size: 0x60
//Constructor: 0x434D1C (find all Res constructors here)
public:
	virtual void v0() {}

	DWORD* pAbilities; //0x50
	DWORD* pEffects; //0x54
	DWORD* pFile; //0x58
	DWORD* numAbilities; //0x5c
};

class ResVid : public Res {
//Size: 0x58
//Constructor: 0x434D1C (find all Res constructors here)
//Used VVC, VEF, PRO, WFX files
public:
	virtual void v0() {}

	DWORD u50; //pFile+4
	DWORD u54; //bPointersLoaded
};

class ResWav : public Res {
//Size: 0x68
//Constructor: 0x434D1C (find all Res constructors here)
public:
	virtual void v0() {}

	BOOL bCompressed; //50h, 0 = RIFF/WAVE, 1 = WAVC
	BOOL bPointerLoaded; //54h
	DWORD nUncompressedSize; //58h
	DWORD nCompressedSize; //5ch
	void* pData; //60h
	DWORD* pWaveFormatEx; //64h
};

struct KeyTableEntry {
//Size: 0x18
	ResRef name; //0h
	Res* pRes; //8h
	DWORD uc; //ch, two WORD, 0xc ?, 0xe biffIndex
	WORD nLoaded; //10h
	WORD nCResType; //12h
	DWORD u14; //14h
};

struct CResHandler {
	//Size: 0x2A8
	//Constructor: 0x98CB00
	DWORD u0;
	BOOL bServiceRequested; //4h, currently demanded or not
	WORD nRequests; //8h
		
	//CRITICAL_SECTION required to access (see CBaldurChitin)
	CObList ua; //contains Res with flags bit 0 and 1 both not set, for 2DA Res only?
	CObList u26; //contains Res with flags bit 0 set
	CObList u42; //contains Res with flags bit 1 set
	CObList u5e; //0
	CObList u7a; //1
	CObList u96; //2
	CObList ub2; //for graphic Res only?

	Res* uce; //if this matches currentRes being demanded, will close the Res when demanded
	DWORD ud2; //filesize of tempRes
	DWORD ud6; //assoc with uda
	DWORD uda; //sum of all file sizes that are loaded, if this > ud6, then clear all above CObLists
	SIZE_T dwTotalPhys; //deh, from GlobalMemoryStatus
	DWORD ue2; //flags2, compare to Res
	DWORD ue6;
	WORD uea;
	DWORD* uec; //pointer to array of CBiff* pointers
	struct CCache { //f0h
	//Size: 0x15C
	//Constructor: 0x99C3BC
		DWORD u0; //bEnabled?
		char cwd[260]; //4h, getcwd() - current working directory (game path)
		IECString cacheDirectory; //108h, "hd0:\\cache\\"
		IECString u10c;
		DWORD u110;
		DWORD u114;
		DWORD u118;
		DWORD u11c;
		DWORD u120; //nDumpedFilesize?
		DWORD u124; //nCacheFiles
		CPtrList u128; //AB8EAC, 0x0 biffIndex, 0x4 ?, 0x8 DWORD fileSize
		CRITICAL_SECTION u144; //access to CPtrList u128
	} m_cache;
		
	struct KeyTable {
		//size: 0x24
		DWORD u0; //isLoaded or bEnabled?

		DWORD* pBiffs; //4h (0xc size objects) - help to find name of biff
		//CBiff
		//size+ 0xc
		//DWORD m_filesize; //0h
		//DWORD offset; //pBiffs + offset = char* biffshortpath
		//WORD u8;
		//WORD ua;

		DWORD nBiffs; //8h
		DWORD uc; //nKeys
		KeyTableEntry* keys; //10h
		DWORD u14;
		DWORD u18;
		DWORD u1c;
		DWORD u20;
	} m_KeyTable; //0x24c
	Res* pResTemp; //270h, CRITICAL_SECTION required to access (see CBaldurChitin)
	DWORD u274;
	CPtrList directories; //278h, AB8E7C, of CStrings (full path directories, e.g. override, cache)
	BYTE u294;
	BYTE u295[3]; //padding
	IECString u298;
	DWORD u29c; //sum of all file sizes that are loaded
	DWORD u2a0;
	BYTE u2a4; //padding
	BYTE u2a5;
	BYTE u2a6;
	BYTE u2a7; //padding
};

#endif //RESCORE_H