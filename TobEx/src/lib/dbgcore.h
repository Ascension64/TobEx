#ifndef DBGCORE_H
#define DBGCORE_H

#include "stdafx.h"

extern void (__cdecl *AssertFailedQuit)(int, LPCTSTR, LPCTSTR, LPCTSTR);
extern void (__cdecl *AssertFailedContinue)(int, LPCTSTR, LPCTSTR, LPCTSTR);
extern void (__cdecl *WriteToFile)(CFile&, CString&);
extern void (__stdcall *CloseLogAndErr)();

#endif //DBGCORE_H