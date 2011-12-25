#ifndef DBGCORE_H
#define DBGCORE_H

#include "utils.h"

extern void (__cdecl *AssertFailedQuit)(DWORD, LPCTSTR, LPCTSTR, LPCTSTR);
extern void (__cdecl *AssertFailedContinue)(DWORD, LPCTSTR, LPCTSTR, LPCTSTR);
extern void (__cdecl *WriteToFile)(CFile&, CString&);
extern void (__stdcall *CloseLogAndErr)();

#endif //DBGCORE_H