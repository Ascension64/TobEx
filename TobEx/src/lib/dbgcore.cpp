#include "dbgcore.h"

void (__cdecl *AssertFailedQuit)(int, LPCTSTR, LPCTSTR, LPCTSTR) =
	reinterpret_cast<void (__cdecl *)(int, LPCTSTR, LPCTSTR, LPCTSTR)>	(0x99F06C);
void (__cdecl *AssertFailedContinue)(int, LPCTSTR, LPCTSTR, LPCTSTR) =
	reinterpret_cast<void (__cdecl *)(int, LPCTSTR, LPCTSTR, LPCTSTR)>	(0x99F193);
void (__cdecl *WriteToFile)(CFile&, CString&) =
	reinterpret_cast<void (__cdecl *)(CFile&, CString&)>				(0x99F371);
void (__stdcall *CloseLogAndErr)() =
	reinterpret_cast<void (__stdcall *)()>								(0x99F1BA);