#ifndef ENGINEWORLD_H
#define ENGINEWORLD_H

#include "engworld.h"

extern POSITION (CWorld::*Tramp_CWorld_PrintToConsole_6)(IECString&, IECString&, ARGB, ARGB, int, BOOL);
extern POSITION (CWorld::*Tramp_CWorld_PrintToConsole_4)(IECString&, IECString&, int, BOOL);

class DETOUR_CWorld : public CWorld {
public:
	POSITION DETOUR_PrintToConsoleColor(IECString& sLeft, IECString& sRight, ARGB colLeft, ARGB colRight, int dw, BOOL b);
	POSITION DETOUR_PrintToConsole(IECString& sLeft, IECString& sRight, int dw, BOOL b);
};

#endif //ENGINEWORLD_H