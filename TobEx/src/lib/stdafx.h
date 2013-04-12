#ifndef STDAFX_H
#define STDAFX_H

#include "win32def.h"

#include <cassert>
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

#define DLL_INTERNAL_NAME "TobEx.dll\0"

typedef IECPtrList CDwordList; //AA5C50, all are EnumList?
typedef IECPtrList CEnumList; //AA5C50
typedef IECPtrList CIECStringList; //AA63B4
typedef IECPtrList CPositionList; //AA702C
typedef IECPtrList CResRefList; //AA6334
typedef IECPtrList CGameObjectList; //AA7128

#endif //STDAFX_H