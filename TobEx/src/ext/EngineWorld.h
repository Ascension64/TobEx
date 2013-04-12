#ifndef ENGINEWORLD_H
#define ENGINEWORLD_H

#include "engworld.h"

DeclareTrampMemberFunc(POSITION, CScreenWorld, PrintToConsole, (
	IECString& sLeft,
	IECString& sRight,
	ABGR colLeft,
	ABGR colRight,
	int nUserArg,
	bool bResetScrollbar
	), PrintToConsole6);
DeclareTrampMemberFunc(POSITION, CScreenWorld, PrintToConsole, (
	IECString& sLeft,
	IECString& sRight,
	int nUserArg,
	bool bResetScrollbar
	), PrintToConsole4);

class DETOUR_CScreenWorld : public CScreenWorld {
public:
	POSITION DETOUR_PrintToConsoleColor(IECString& sLeft, IECString& sRight, ABGR colLeft, ABGR colRight, int nUserArg, bool bResetScrollbar);
	POSITION DETOUR_PrintToConsole(IECString& sLeft, IECString& sRight, int nUserArg, bool bResetScrollbar);
};

#endif //ENGINEWORLD_H