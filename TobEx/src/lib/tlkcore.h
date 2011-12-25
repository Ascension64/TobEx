#ifndef TLKCORE_H
#define TLKCORE_H

#include "utils.h"
#include "cstringex.h"
#include "sndcore.h"

extern IECString (__cdecl *GetTlkString)(STRREF);

class CFileTlk : public CFile { //Size 12h
//Constructor: 0x9AAD00
public:
	//AB902C
	BYTE bOpened; //10h
	BYTE u11; //pad
};

struct CStrRef { //Size 6Eh
	//AAF70C
	IECString text;
	CSound sound;
};

class CTlkTbl { //Size A6h
//Constructor: 0x9AADCA
public:
	//functions
	bool GetTlkString(STRREF, CStrRef&);

	//members
	CMapWordToPtr files; //0h, key->CFileTlk
	CMapStringToString u1c;
#ifdef _DEBUG
	_CCriticalSection ccs; //38h
#else
	CCriticalSection ccs; //38h
#endif

	BYTE u58;
	BYTE u59; //pad
	
	//handles sounds?
	struct _u5a {
		IECString u0;
		IECString u4;
		class _u8 : public CFile { //Size 2Eh
		//Constructor: 0x9E460F
			//AB9A84
			BYTE u10;
			BYTE u11; //pad
			DWORD* u12; //pArray
			DWORD u16; //nArraySize
			DWORD u1a[5];
		} u8; //8h
		class _u36 : public CFile { //Size 16h
			//AB9080
		DWORD u10;
		BYTE u14;
		BYTE u15; //pad
		} u36; //36h
	} u5a; //5ah

};

extern bool (CTlkTbl::*CTlkTbl_GetTlkString)(STRREF, CStrRef&);

#endif //TLKCORE_H