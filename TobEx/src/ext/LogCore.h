#ifndef LOGCORE_H
#define LOGCORE_H

#include "utils.h"

extern void (__cdecl *Tramp_AssertFailedQuit)(DWORD, LPCTSTR, LPCTSTR, LPCTSTR);
extern void (__cdecl *Tramp_AssertFailedContinue)(DWORD, LPCTSTR, LPCTSTR, LPCTSTR);
extern void (__cdecl *Tramp_WriteToFile)(CFile&, CString&);
extern void (__stdcall *Tramp_CloseLogAndErr)();

void __cdecl DETOUR_AssertFailedQuit(DWORD, LPCTSTR, LPCTSTR, LPCTSTR);
void __cdecl DETOUR_AssertFailedContinue(DWORD, LPCTSTR, LPCTSTR, LPCTSTR);
void __cdecl DETOUR_WriteToFile(CFile&, CString&);
void __stdcall DETOUR_CloseLogAndErr();

#endif LOGCORE_H