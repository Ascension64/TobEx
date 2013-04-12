#ifndef PATCHEXT_H
#define PATCHEXT_H

#include "stdafx.h"

#include "patch.h"

#include "infgame.h"

extern CRuleTable** ClassAbilityTable;

typedef CRuleTable* ClAbTable[1281]; //for KitExtend

void InitPatches();

#endif //PATCHEXT_H