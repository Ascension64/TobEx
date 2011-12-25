#include "engworld.h"

#include "stdafx.h"

extern POSITION (CWorld::*CWorld_PrintToConsole_6)(IECString&, IECString&, ABGR, ABGR, int, BOOL) =
	SetFP(static_cast<POSITION (CWorld::*)(IECString&, IECString&, ABGR, ABGR, int, BOOL)>	(&CWorld::PrintToConsole),	0x7DDE63);
extern POSITION (CWorld::*CWorld_PrintToConsole_4)(IECString&, IECString&, int, BOOL) =
	SetFP(static_cast<POSITION (CWorld::*)(IECString&, IECString&, int, BOOL)>				(&CWorld::PrintToConsole),	0x7DE085);

POSITION CWorld::PrintToConsole(IECString& sLeft, IECString& sRight, ABGR colLeft, ABGR colRight, int dw, BOOL b) {
	return (this->*CWorld_PrintToConsole_6)(sLeft, sRight, colLeft, colRight, dw, b); }
POSITION CWorld::PrintToConsole(IECString& sLeft, IECString& sRight, int dw, BOOL b) {
	return (this->*CWorld_PrintToConsole_4)(sLeft, sRight, dw, b); }
