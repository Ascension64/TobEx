#include "utils.h"

const char* months[] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
const char* days[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };

static LPCTSTR szDefault = "0";
static const DWORD nBufSize = 2;
static char szBuf[2] = { 0 };
static LPCTSTR szFile = "./TobEx.ini";

static void* (__cdecl *_New)(size_t) =
	reinterpret_cast<void* (__cdecl  *)(size_t)>	(0xA50608);
static void (__cdecl *_Delete)(void*) =
	reinterpret_cast<void (__cdecl  *)(void*)>		(0xA50631);
static int (__cdecl *_Rand)(void) =
	reinterpret_cast<int (__cdecl *)(void)>			(0xA39100);

void* __cdecl operator new (size_t size, int i) { return (*_New)(size); }
void* __cdecl operator new[] (size_t size, int i) { return (*_New)(size); }
void __cdecl operator delete (void* mem, int i) { return (*_Delete)(mem); }
void __cdecl operator delete[] (void* mem, int i) { return (*_Delete)(mem); }
int __cdecl IERand() { return (*_Rand)(); }

int GetIniValue(LPCTSTR szSection, LPCTSTR szKey) {
	GetPrivateProfileString(szSection, szKey, szDefault, szBuf, nBufSize, szFile);
	return atoi(szBuf);
}

void* ThisCall(void* func, void* pThis) {
	void* returnVal;
	__asm {
		mov ecx, pThis
		call func
		mov returnVal, eax
	}
	return returnVal;
}

void* ThisCall(void* func, void* pThis, void* Arg1){
	void* returnVal;
	__asm {
		push Arg1
		mov ecx, pThis
		call func
		mov returnVal, eax
	}
	return returnVal;
}

void* ThisCall(void* func, void* pThis, void* Arg1, void* Arg2){
	void* returnVal;
	__asm {
		push Arg2
		push Arg1
		mov ecx, pThis
		call func
		mov returnVal, eax
	}
	return returnVal;
}

void* ThisCall(void* func, void* pThis, void* Arg1, void* Arg2, void* Arg3){
	void* returnVal;
	__asm {
		push Arg3
		push Arg2
		push Arg1
		mov ecx, pThis
		call func
		mov returnVal, eax
	}
	return returnVal;
}

void* ThisCall(void* func, void* pThis, void* Arg1, void* Arg2, void* Arg3, void* Arg4){
	void* returnVal;
	__asm {
		push Arg4
		push Arg3
		push Arg2
		push Arg1
		mov ecx, pThis
		call func
		mov returnVal, eax
	}
	return returnVal;
}

void* ThisCall(void* func, void* pThis, void* Arg1, void* Arg2, void* Arg3, void* Arg4, void* Arg5){
	void* returnVal;
	__asm {
		push Arg5
		push Arg4
		push Arg3
		push Arg2
		push Arg1
		mov ecx, pThis
		call func
		mov returnVal, eax
	}
	return returnVal;
}

void* ThisCall(void* func, void* pThis, void* Arg1, void* Arg2, void* Arg3, void* Arg4, void* Arg5, void* Arg6){
	void* returnVal;
	__asm {
		push Arg6
		push Arg5
		push Arg4
		push Arg3
		push Arg2
		push Arg1
		mov ecx, pThis
		call func
		mov returnVal, eax
	}
	return returnVal;
}

void* ThisCall(void* func, void* pThis, void* Arg1, void* Arg2, void* Arg3, void* Arg4, void* Arg5, void* Arg6, void* Arg7){
	void* returnVal;
	__asm {
		push Arg7
		push Arg6
		push Arg5
		push Arg4
		push Arg3
		push Arg2
		push Arg1
		mov ecx, pThis
		call func
		mov returnVal, eax
	}
	return returnVal;
}

void* ThisCall(void* func, void* pThis, void* Arg1, void* Arg2, void* Arg3, void* Arg4, void* Arg5, void* Arg6, void* Arg7, void* Arg8){
	void* returnVal;
	__asm {
		push Arg8
		push Arg7
		push Arg6
		push Arg5
		push Arg4
		push Arg3
		push Arg2
		push Arg1
		mov ecx, pThis
		call func
		mov returnVal, eax
	}
	return returnVal;
}

void* ThisCall(void* func, void* pThis, void* Arg1, void* Arg2, void* Arg3, void* Arg4, void* Arg5, void* Arg6, void* Arg7, void* Arg8, void* Arg9){
	void* returnVal;
	__asm {
		push Arg9
		push Arg8
		push Arg7
		push Arg6
		push Arg5
		push Arg4
		push Arg3
		push Arg2
		push Arg1
		mov ecx, pThis
		call func
		mov returnVal, eax
	}
	return returnVal;
}

void* ThisCall(void* func, void* pThis, void* Arg1, void* Arg2, void* Arg3, void* Arg4, void* Arg5, void* Arg6, void* Arg7, void* Arg8, void* Arg9, void* Arg10){
	void* returnVal;
	__asm {
		push Arg10
		push Arg9
		push Arg8
		push Arg7
		push Arg6
		push Arg5
		push Arg4
		push Arg3
		push Arg2
		push Arg1
		mov ecx, pThis
		call func
		mov returnVal, eax
	}
	return returnVal;
}