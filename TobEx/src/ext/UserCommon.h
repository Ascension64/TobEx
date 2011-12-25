#ifndef USERCOMMON_H
#define USERCOMMON_H

#include "objcre.h"
#include "splcore.h"
#include "resref.h"
#include "infgame.h"

bool UserCommon_HasSpell(CCreatureObject* pCre, ResRef& rSpell, CKnownSpellList* cplKnownSpell);
bool UserCommon_HasKnownSpell(CCreatureObject* pCre, ResRef& rSpell, int nLevel);

#endif //USERCOMMON_H
