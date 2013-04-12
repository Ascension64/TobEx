#ifndef DBGCORE_H
#define DBGCORE_H

#include "stdafx.h"

DefineGlobalFuncPtr(void, __cdecl, AssertFailedQuit, (int dwLine, LPCTSTR szPath, LPCTSTR szExpression, LPCTSTR szMessage), 0x99F06C);
DefineGlobalFuncPtr(void, __cdecl, AssertFailedContinue, (int dwLine, LPCTSTR szPath, LPCTSTR szExpression, LPCTSTR szMessage), 0x99F193);
DefineGlobalFuncPtr(void, __cdecl, WriteToFile, (CFile& file, CString& str), 0x99F371);
DefineGlobalFuncPtr(void, __stdcall, CloseLogAndErr, (), 0x99F1BA);

#endif //DBGCORE_H