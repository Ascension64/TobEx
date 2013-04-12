#ifndef SCRIPTCORE_H
#define SCRIPTCORE_H

#include "scrcore.h"

//CVariableMap
DeclareTrampMemberFunc(BOOL, CVariableMap, Add, (CVariable& var), Add);
DeclareTrampMemberFunc(CVariable&, CVariableMap, Find, (IECString sVar), Find);
DeclareTrampMemberFunc(unsigned int, CVariableMap, GetHash, (IECString sVar), GetHash);

struct DETOUR_CVariableMap : public CVariableMap { //Size 8h
	BOOL DETOUR_Add(CVariable& var);
	CVariable& DETOUR_Find(IECString sVar);
	unsigned int DETOUR_GetHash(IECString sVar);
};

//CScriptBlock
DeclareTrampMemberFunc(BOOL, CScriptBlock, Evaluate, (CTriggerList& triggers, CGameSprite& sprite), Evaluate);

struct DETOUR_CScriptBlock : public CScriptBlock {
	BOOL DETOUR_Evaluate(CTriggerList& triggers, CGameSprite& sprite);
};

#endif //SCRIPTCORE_H