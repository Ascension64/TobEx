#ifndef USERCORE_h
#define USERCORE_H

#include "uicore.h"

DeclareTrampGlobalFuncPtr(CUIControl*, __cdecl, CreateUIControl, (CPanel& panel, ChuFileControlInfoBase& controlInfo));

CUIControl* __cdecl DETOUR_CreateUIControl(CPanel& panel, ChuFileControlInfoBase& controlInfo);

#endif //USERCORE_h
