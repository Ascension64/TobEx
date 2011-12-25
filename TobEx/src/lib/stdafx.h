#ifndef STDAFX_H
#define STDAFX_H

#include "win32def.h"

#include <cassert>

#include "utils.h"

#include "cstringex.h"
#include "cptrlistex.h"
#include "resref.h"

#include "globals.h"

#include "console.h"
#include "log.h"

#include "options.h"

#define DLL_INTERNAL_NAME "TobEx.dll\0"

typedef int STRREF;
typedef unsigned int Enum; //index to CGameObjectArrayHandler element

typedef IECPtrList CDwordList; //AA5C50, all are EnumList?
typedef IECPtrList CEnumList; //AA5C50
typedef IECPtrList CPositionList; //AA702C
typedef IECPtrList CResRefList; //AA6334
typedef IECPtrList CGameObjectList; //AA7128

const Enum ENUM_INVALID_INDEX = UINT_MAX;
extern const char* months[];
extern const char* days[];

const DWORD g_nPEAddressDefault = 0x400000;

#endif //STDAFX_H