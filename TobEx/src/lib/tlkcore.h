#ifndef TLKCORE_H
#define TLKCORE_H

#include "stdafx.h"
#include "sndcore.h"

DefineGlobalFuncPtr(IECString, __cdecl, GetTlkString, (STRREF strref), 0x43B193);

class CFileTlk : public CFile { //Size 12h
//Constructor: 0x9AAD00
public:
	//AB902C
	char bOpened; //10h
	char u11; //pad
};

struct CStrRef { //Size 6Eh
	IECString text; //0h
	CSound sound; //4h
};

class CTlkTbl { //Size A6h
//Constructor: 0x9AADCA
public:
	bool GetTlkString(STRREF strref, CStrRef& ptr);

	CMapWordToPtr m_FileMap; //0h, key->CFileTlk
	IECMapStringToString m_StringMap; //1ch
#ifdef _DEBUG
	_CCriticalSection ccs; //38h
#else
	CCriticalSection ccs; //38h
#endif

	char nKeyLow; //58h, the low byte of the key to use for dialog (dialog.tlk vs dialogF.tlk)
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

#endif //TLKCORE_H