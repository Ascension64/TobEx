#ifndef TLKCORE_H
#define TLKCORE_H

#include "stdafx.h"
#include "cstringex.h"
#include "sndcore.h"

extern IECString (__cdecl *GetTlkString)(STRREF);

class CFileTlk : public CFile { //Size 12h
//Constructor: 0x9AAD00
public:
	//AB902C
	char bOpened; //10h
	char u11; //pad
};

struct CStrRef { //Size 6Eh
	//AAF70C
	IECString text;
	CSound sound;
};

class CTlkTbl { //Size A6h
//Constructor: 0x9AADCA
public:
	bool GetTlkString(STRREF strref, CStrRef& ptr);

	CMapWordToPtr files; //0h, key->CFileTlk
	CMapStringToString u1c;
#ifdef _DEBUG
	_CCriticalSection ccs; //38h
#else
	CCriticalSection ccs; //38h
#endif

	char u58;
	char u59; //pad
	
	//handles sounds?
	struct _u5a {
		IECString u0;
		IECString u4;
		class _u8 : public CFile { //Size 2Eh
		//Constructor: 0x9E460F
			//AB9A84
			char u10;
			char u11; //pad
			int* u12; //pArray
			int u16; //nArraySize
			int u1a[5];
		} u8; //8h
		class _u36 : public CFile { //Size 16h
			//AB9080
		int u10;
		char u14;
		char u15; //pad
		} u36; //36h
	} u5a; //5ah

};

extern bool (CTlkTbl::*CTlkTbl_GetTlkString)(STRREF, CStrRef&);

#endif //TLKCORE_H