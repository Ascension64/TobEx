#include "engworld.h"

#include "stdafx.h"

extern POSITION (CScreenWorld::*CScreenWorld_PrintToConsole_6)(IECString&, IECString&, ABGR, ABGR, int, bool) =
	SetFP(static_cast<POSITION (CScreenWorld::*)(IECString&, IECString&, ABGR, ABGR, int, bool)>	(&CScreenWorld::PrintToConsole),	0x7DDE63);
extern POSITION (CScreenWorld::*CScreenWorld_PrintToConsole_4)(IECString&, IECString&, int, bool) =
	SetFP(static_cast<POSITION (CScreenWorld::*)(IECString&, IECString&, int, bool)>				(&CScreenWorld::PrintToConsole),	0x7DE085);

POSITION CScreenWorld::PrintToConsole(IECString& sLeft, IECString& sRight, ABGR colLeft, ABGR colRight, int nUserArg, bool bResetScrollbar) {
	return (this->*CScreenWorld_PrintToConsole_6)(sLeft, sRight, colLeft, colRight, nUserArg, bResetScrollbar); }
POSITION CScreenWorld::PrintToConsole(IECString& sLeft, IECString& sRight, int nUserArg, bool bResetScrollbar) {
	return (this->*CScreenWorld_PrintToConsole_4)(sLeft, sRight, nUserArg, bResetScrollbar); }
