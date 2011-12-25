#include "tlkcore.h"

#include "stdafx.h"

IECString (__cdecl *GetTlkString)(STRREF) =
	reinterpret_cast<IECString (__cdecl *)(STRREF)>(0x43B193);

bool (CTlkTbl::*CTlkTbl_GetTlkString)(STRREF, CStrRef&) =
	SetFP(static_cast<bool (CTlkTbl::*)(STRREF, CStrRef&)>	(&CTlkTbl::GetTlkString),	0x9AB27B);

bool CTlkTbl::GetTlkString(STRREF strref, CStrRef& ptr) { return (this->*CTlkTbl_GetTlkString)(strref, ptr); }
