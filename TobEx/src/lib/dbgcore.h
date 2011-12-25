#ifndef DBGCORE_H
#define DBGCORE_H

#include "stdafx.h"

extern void (__cdecl *AssertFailedQuit)(int dwLine, LPCTSTR szPath, LPCTSTR szExpression, LPCTSTR szMessage);
extern void (__cdecl *AssertFailedContinue)(int dwLine, LPCTSTR szPath, LPCTSTR szExpression, LPCTSTR szMessage);
extern void (__cdecl *WriteToFile)(CFile& file, CString& str);
extern void (__stdcall *CloseLogAndErr)();

#endif //DBGCORE_H