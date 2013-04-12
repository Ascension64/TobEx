//TobExEE
#include "engworld.h"
#include "p_engworld.h"

#include "stdafx.h"

DefineLibMemberFunc(POSITION, CScreenWorld, PrintToConsole, (
	IECString& sLeft,
	IECString& sRight,
	ABGR colLeft,
	ABGR colRight,
	int nUserArg,
	bool bResetScrollbar
	), PrintToConsole, PrintToConsole6, (sLeft, sRight, colLeft, colRight, nUserArg, bResetScrollbar), CSCREENWORLD_PRINTTOCONSOLE6);
DefineLibMemberFunc(POSITION, CScreenWorld, PrintToConsole, (
	IECString& sLeft,
	IECString& sRight,
	int nUserArg,
	bool bResetScrollbar
	), PrintToConsole, PrintToConsole4, (sLeft, sRight, nUserArg, bResetScrollbar), CSCREENWORLD_PRINTTOCONSOLE4);
