#include "dbgcore.h"

void (__cdecl *AssertFailedQuit)(DWORD, LPCTSTR, LPCTSTR, LPCTSTR) =
	reinterpret_cast<void (__cdecl *)(DWORD, LPCTSTR, LPCTSTR, LPCTSTR)>	(0x99F06C);
void (__cdecl *AssertFailedContinue)(DWORD, LPCTSTR, LPCTSTR, LPCTSTR) =
	reinterpret_cast<void (__cdecl *)(DWORD, LPCTSTR, LPCTSTR, LPCTSTR)>	(0x99F193);
void (__cdecl *WriteToFile)(CFile&, CString&) =
	reinterpret_cast<void (__cdecl *)(CFile&, CString&)>					(0x99F371);
void (__stdcall *CloseLogAndErr)() =
	reinterpret_cast<void (__stdcall *)()>									(0x99F1BA);