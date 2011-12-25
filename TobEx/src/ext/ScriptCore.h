#ifndef SCRIPTCORE_H
#define SCRIPTCORE_H

#include "scrcore.h"

extern BOOL (CScriptBlock::*Tramp_CScriptBlock_Evaluate)(CTriggerList&, CGameSprite&);

struct DETOUR_CScriptBlock : public CScriptBlock {
	BOOL DETOUR_Evaluate(CTriggerList& triggers, CGameSprite& sprite);
};

#endif //SCRIPTCORE_H