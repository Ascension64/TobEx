#ifndef LOGCORE_H
#define LOGCORE_H

#include "utils.h"

void __cdecl DETOUR_AssertFailedQuit(DWORD, LPCTSTR, LPCTSTR, LPCTSTR);
void __cdecl DETOUR_AssertFailedContinue(DWORD, LPCTSTR, LPCTSTR, LPCTSTR);
void __cdecl DETOUR_WriteToFile(CFile&, CString&);
void __stdcall DETOUR_CloseLogAndErr();

#endif LOGCORE_H