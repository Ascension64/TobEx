#ifndef UTILS_H
#define UTILS_H

#include "win32def.h"

#define GetEip(Eip) __asm {						\
	__asm mov eax, [ebp+4] /*return address*/	\
	__asm mov Eip, eax							\
}

#define SetVT(obj, vt) (*(DWORD*)obj = vt)
#define IENew new(0)
#define IENewA new[](0)

#ifdef _DEBUG 
//In _DEBUG, CSyncObject contains an extra CString, screwing up the sizes of game objects
class _CCriticalSection { //Size 20h
	DWORD* vt; //0h, AA61F8
	HANDLE m_hObject; //4h, from CSyncObject
	CRITICAL_SECTION cs; //8h
};
#endif

template <typename T> T SetFP(T pFunction, DWORD dwAddress) {
	if (sizeof(T) == 4) {
		*(DWORD*)&pFunction = dwAddress;
	}
	return pFunction;
}

void* __cdecl operator new (size_t, int);
void* __cdecl operator new[] (size_t, int);
void __cdecl operator delete (void*, int);
void __cdecl operator delete[] (void*, int);
int __cdecl IERand(void);
int __cdecl IERand(int n);

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
