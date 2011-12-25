#ifndef ENGWORLD_H
#define ENGWORLD_H

#include "engine.h"
#include "cstringex.h"
#include "vidcore.h"

class CWorld : public CEngine { //Size 124Ch
//Constructor: 0x7C3EE0
public:
	short PrintToConsole(IECString& sLeft, IECString& sRight, ARGB colLeft, ARGB colRight, int dw, BOOL b);

	//FIX_ME

	//AB5768
};

extern short (CWorld::*CWorld_PrintToConsole)(IECString&, IECString&, ARGB, ARGB, int, BOOL);

#endif //ENGWORLD_H