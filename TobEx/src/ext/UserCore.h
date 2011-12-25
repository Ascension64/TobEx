#ifndef USERCORE_h
#define USERCORE_H

#include "uicore.h"

extern CUIControl* (__cdecl *Tramp_CreateUIControl)(CPanel&, ChuFileControlInfoBase&);

CUIControl* __cdecl DETOUR_CreateUIControl(CPanel&, ChuFileControlInfoBase&);

#endif //USERCORE_h
