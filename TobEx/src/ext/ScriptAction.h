#ifndef SCRIPTACTION_H
#define SCRIPTACTION_H

#include "objcre.h"

BOOL CGameSprite_AtomicSetGlobal(CGameSprite& sprite, Action& a);
ACTIONRESULT CGameSprite_ActionAssign(CGameSprite& sprite, Action& a);
ACTIONRESULT CGameSprite_ActionEval(CGameSprite& sprite, Action& a);
ACTIONRESULT CGameSprite_ActionClearBlockVars(CGameSprite& sprite);
void CCreatureObject_ActionChangeAnimation_CopyState(CCreatureObject& creOld, CCreatureObject& creNew);

#endif //SCRIPTACTION_H
