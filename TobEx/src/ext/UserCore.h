#ifndef USERCORE_h
#define USERCORE_H

#include "uicore.h"

extern CUIControl* (__cdecl *Tramp_CreateUIControl)(CPanel&, ChuFileControlInfoBase&);

CUIControl* __cdecl DETOUR_CreateUIControl(CPanel& panel, ChuFileControlInfoBase& controlInfo);

#endif //USERCORE_h
