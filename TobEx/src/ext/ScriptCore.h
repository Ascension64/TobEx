#ifndef SCRIPTCORE_H
#define SCRIPTCORE_H

#include "scrcore.h"

//CVariableMap
extern BOOL (CVariableMap::*Tramp_CVariableMap_Add)(CVariable&);
extern CVariable& (CVariableMap::*Tramp_CVariableMap_Find)(IECString);
extern unsigned int (CVariableMap::*Tramp_CVariableMap_GetHash)(IECString);

struct DETOUR_CVariableMap : public CVariableMap { //Size 8h
	BOOL DETOUR_Add(CVariable& var);
	CVariable& DETOUR_Find(IECString sVar);
	unsigned int DETOUR_GetHash(IECString sVar);
};

//CScriptBlock
extern BOOL (CScriptBlock::*Tramp_CScriptBlock_Evaluate)(CTriggerList&, CGameSprite&);

struct DETOUR_CScriptBlock : public CScriptBlock {
	BOOL DETOUR_Evaluate(CTriggerList& triggers, CGameSprite& sprite);
};

#endif //SCRIPTCORE_H