#ifndef UTILS_H
#define UTILS_H

#include "globals.h"

#define VC_EXTRALEAN        // Exclude rarely-used stuff from Windows headers

//MFC version 4.2 library
#include "afxwin.h"         // MFC core and standard components
//#include "afxext.h"         // MFC extensions
//#include "afxdisp.h"        // MFC OLE automation classes
//#include "afxcmn.h"         // MFC support for Windows Common Controls
//#include "afxdtctl.h"
#include "afxmt.h"			// MFC multi-threading

#define GetEip(Eip) __asm {						\
	__asm mov eax, [ebp+4] /*return address*/	\
	__asm mov Eip, eax							\
}

#define SetVT(obj, vt) (*(DWORD*)obj = vt)
#define IENew new(0)
#define IEDelete(obj) operator delete(obj, 0)

#ifdef _DEBUG 
//In _DEBUG, CSyncObject contains an extra CString, screwing up the sizes of game objects
class _CCriticalSection { //Size 20h
	DWORD* vt; //0h, 0xAA61F8
	HANDLE m_hObject; //4h, from CSyncObject
	CRITICAL_SECTION cs; //8h
};
#endif

typedef unsigned __int64 QWORD;
typedef unsigned int STRREF;

typedef DWORD Enum; //Index to CGameObjectArrayHandler element

typedef CPtrList CDwordList; //AA5C50, all are EnumList?
typedef CPtrList CEnumList; //AA5C50
typedef CPtrList CPositionList; //AA702C
typedef CPtrList CGameObjectList; //AA7128

const Enum ENUM_INVALID_INDEX = -1;
extern const char* months[];
extern const char* days[];

const DWORD g_nPEAddressDefault = 0x400000;

int GetIniValue(LPCTSTR, LPCTSTR);

template <typename T> T SetFP(T pFunction, DWORD dwAddress) {
	if (sizeof(T) == 4) {
		*(DWORD*)&pFunction = dwAddress;
	}
	return pFunction;
}

void* operator new (size_t, int);
void* operator new[] (size_t, int);
void operator delete (void*, int);
void operator delete[] (void*, int);

void* ThisCall(void*, void*);
void* ThisCall(void*, void*, void*);
void* ThisCall(void*, void*, void*, void*);
void* ThisCall(void*, void*, void*, void*, void*);
void* ThisCall(void*, void*, void*, void*, void*, void*);
void* ThisCall(void*, void*, void*, void*, void*, void*, void*);
void* ThisCall(void*, void*, void*, void*, void*, void*, void*, void*);
void* ThisCall(void*, void*, void*, void*, void*, void*, void*, void*, void*);
void* ThisCall(void*, void*, void*, void*, void*, void*, void*, void*, void*, void*);
void* ThisCall(void*, void*, void*, void*, void*, void*, void*, void*, void*, void*, void*);
void* ThisCall(void*, void*, void*, void*, void*, void*, void*, void*, void*, void*, void*, void*);

#endif //UTILS_H
