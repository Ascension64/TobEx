#ifndef SCRIPTACTION_H
#define SCRIPTACTION_H

#include "objcre.h"

void __stdcall CCreatureObject_ForceVisible(CCreatureObject& creSource);
BOOL CGameSprite_AtomicSetGlobal(CGameSprite& sprite, Action& a);

#endif //SCRIPTACTION_H
