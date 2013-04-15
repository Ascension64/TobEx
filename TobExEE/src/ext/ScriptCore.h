//TobExEE
#ifndef SCRIPTCORE_H
#define SCRIPTCORE_H

#include "scrcore.h"

//CScriptBlock
DeclareTrampMemberFunc(BOOL, CScriptBlock, Evaluate, (CTriggerList& triggers, CGameSprite& sprite), Evaluate);

struct DETOUR_CScriptBlock : public CScriptBlock {
	BOOL DETOUR_Evaluate(CTriggerList& triggers, CGameSprite& sprite);
};

#endif //SCRIPTCORE_H