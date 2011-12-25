#ifndef LOGCORE_H
#define LOGCORE_H

#include "stdafx.h"

extern void (__stdcall *Tramp_CloseLogAndErr)();
extern void (__cdecl *Tramp_WriteToFile)(CFile&, CString&);
extern void (__cdecl *Tramp_AssertFailedQuit)(int, LPCTSTR, LPCTSTR, LPCTSTR);
extern void (__cdecl *Tramp_AssertFailedContinue)(int, LPCTSTR, LPCTSTR, LPCTSTR);

void __stdcall DETOUR_CloseLogAndErr();
void __cdecl DETOUR_WriteToFile(CFile& file, CString& str);
void __cdecl DETOUR_AssertFailedQuit(int dwLine, LPCTSTR szPath, LPCTSTR szExpression, LPCTSTR szMessage);
void __cdecl DETOUR_AssertFailedContinue(int dwLine, LPCTSTR szPath, LPCTSTR szExpression, LPCTSTR szMessage);

#endif LOGCORE_H