#ifndef USERCOMMON_H
#define USERCOMMON_H

#include "objcre.h"
#include "splcore.h"
#include "resref.h"
#include "infgame.h"

bool UserCommon_HasSpell(CCreatureObject*, ResRef&, CKnownSpellList*);
bool UserCommon_HasKnownSpell(CCreatureObject*, ResRef&, DWORD);

#endif //USERCOMMON_H
