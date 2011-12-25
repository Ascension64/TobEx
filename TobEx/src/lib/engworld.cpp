#include "engworld.h"

#include "stdafx.h"

extern POSITION (CWorld::*CWorld_PrintToConsole_6)(IECString&, IECString&, ABGR, ABGR, int, bool) =
	SetFP(static_cast<POSITION (CWorld::*)(IECString&, IECString&, ABGR, ABGR, int, bool)>	(&CWorld::PrintToConsole),	0x7DDE63);
extern POSITION (CWorld::*CWorld_PrintToConsole_4)(IECString&, IECString&, int, bool) =
	SetFP(static_cast<POSITION (CWorld::*)(IECString&, IECString&, int, bool)>				(&CWorld::PrintToConsole),	0x7DE085);

POSITION CWorld::PrintToConsole(IECString& sLeft, IECString& sRight, ABGR colLeft, ABGR colRight, int nUserArg, bool bResetScrollbar) {
	return (this->*CWorld_PrintToConsole_6)(sLeft, sRight, colLeft, colRight, nUserArg, bResetScrollbar); }
POSITION CWorld::PrintToConsole(IECString& sLeft, IECString& sRight, int nUserArg, bool bResetScrollbar) {
	return (this->*CWorld_PrintToConsole_4)(sLeft, sRight, nUserArg, bResetScrollbar); }
