#ifndef SCRIPTCORE_H
#define SCRIPTCORE_H

#include "scrcore.h"

struct DETOUR_CScriptBlock : public CScriptBlock {
	BOOL DETOUR_Evaluate(CTriggerList& triggers, CGameSprite& sprite);
};

extern BOOL (CScriptBlock::*Tramp_CScriptBlock_Evaluate)(CTriggerList&, CGameSprite&);

#endif //SCRIPTCORE_H