#ifndef LOGCORE_H
#define LOGCORE_H

#include "stdafx.h"

DeclareTrampGlobalFuncPtr(void, __cdecl, AssertFailedQuit, (int dwLine, LPCTSTR szPath, LPCTSTR szExpression, LPCTSTR szMessage));
DeclareTrampGlobalFuncPtr(void, __cdecl, AssertFailedContinue, (int dwLine, LPCTSTR szPath, LPCTSTR szExpression, LPCTSTR szMessage));
DeclareTrampGlobalFuncPtr(void, __cdecl, WriteToFile, (CFile& file, CString& str));
DeclareTrampGlobalFuncPtr(void, __cdecl, CloseLogAndErr, ());

void __cdecl DETOUR_AssertFailedQuit(int dwLine, LPCTSTR szPath, LPCTSTR szExpression, LPCTSTR szMessage);
void __cdecl DETOUR_AssertFailedContinue(int dwLine, LPCTSTR szPath, LPCTSTR szExpression, LPCTSTR szMessage);
void __cdecl DETOUR_WriteToFile(CFile& file, CString& str);
void __stdcall DETOUR_CloseLogAndErr();

#endif LOGCORE_H