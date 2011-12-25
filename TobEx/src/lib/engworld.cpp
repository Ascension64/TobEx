#include "engworld.h"

#include "stdafx.h"

extern short (CWorld::*CWorld_PrintToConsole)(IECString&, IECString&, ARGB, ARGB, int, BOOL) =
	SetFP(static_cast<short (CWorld::*)(IECString&, IECString&, ARGB, ARGB, int, BOOL)>		(&CWorld::PrintToConsole),	0x7DDE63);

short CWorld::PrintToConsole(IECString& sLeft, IECString& sRight, ARGB colLeft, ARGB colRight, int dw, BOOL b) {
	return (this->*CWorld_PrintToConsole)(sLeft, sRight, colLeft, colRight, dw, b); }