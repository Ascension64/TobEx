#ifndef ENGINEWORLD_H
#define ENGINEWORLD_H

#include "engworld.h"

extern POSITION (CWorld::*Tramp_CWorld_PrintToConsole_6)(IECString&, IECString&, ABGR, ABGR, int, bool);
extern POSITION (CWorld::*Tramp_CWorld_PrintToConsole_4)(IECString&, IECString&, int, bool);

class DETOUR_CWorld : public CWorld {
public:
	POSITION DETOUR_PrintToConsoleColor(IECString& sLeft, IECString& sRight, ABGR colLeft, ABGR colRight, int nUserArg, bool bResetScrollbar);
	POSITION DETOUR_PrintToConsole(IECString& sLeft, IECString& sRight, int nUserArg, bool bResetScrollbar);
};

#endif //ENGINEWORLD_H