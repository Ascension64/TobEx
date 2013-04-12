#include "engworld.h"

#include "stdafx.h"

DefineLibMemberFunc(void, CScreenWorld, StartStore, (
	Object& oHost,
	Object& oCustomer,
	ResRef rStore,
	BOOL bCheckMP,
	BOOL bCheckMPSettings,
	BOOL bCheckPermissions
	), StartStore, StartStore, (oHost, oCustomer, rStore, bCheckMP, bCheckMPSettings, bCheckPermissions), 0x7DA208);
DefineLibMemberFunc(POSITION, CScreenWorld, PrintToConsole, (
	IECString& sLeft,
	IECString& sRight,
	ABGR colLeft,
	ABGR colRight,
	int nUserArg,
	bool bResetScrollbar
	), PrintToConsole, PrintToConsole6, (sLeft, sRight, colLeft, colRight, nUserArg, bResetScrollbar), 0x7DDE63);
DefineLibMemberFunc(POSITION, CScreenWorld, PrintToConsole, (
	IECString& sLeft,
	IECString& sRight,
	int nUserArg,
	bool bResetScrollbar
	), PrintToConsole, PrintToConsole4, (sLeft, sRight, nUserArg, bResetScrollbar), 0x7DE085);
