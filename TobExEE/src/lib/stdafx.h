//TobExEE
#ifndef STDAFX_H
#define STDAFX_H

#include "win32def.h"

#include <map>

#include "utils.h"
#include "MathPresso.h"
#include "console.h"
#include "log.h"

#include "cstringex.h"
#include "cptrlistex.h"
#include "cmapstrstrex.h"
#include "resref.h"

#include "globals.h"

#define DLL_INTERNAL_NAME "TobExEE.dll\0"

typedef IECPtrList CDwordList;
typedef IECPtrList CEnumList;
typedef IECPtrList CIECStringList;
typedef IECPtrList CPositionList;
typedef IECPtrList CResRefList;
typedef IECPtrList CGameObjectList;

#endif //STDAFX_H