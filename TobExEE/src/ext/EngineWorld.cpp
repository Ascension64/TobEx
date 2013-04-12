//TobExEE
#include "EngineWorld.h"
#include "p_engworld.h"

#include "chitin.h"

DefineTrampMemberFunc(POSITION, CScreenWorld, PrintToConsole, (
	IECString& sLeft,
	IECString& sRight,
	ABGR colLeft,
	ABGR colRight,
	int nUserArg,
	bool bResetScrollbar
	), PrintToConsole, PrintToConsole6, CSCREENWORLD_PRINTTOCONSOLE6);
DefineTrampMemberFunc(POSITION, CScreenWorld, PrintToConsole, (
	IECString& sLeft,
	IECString& sRight,
	int nUserArg,
	bool bResetScrollbar
	), PrintToConsole, PrintToConsole4, CSCREENWORLD_PRINTTOCONSOLE4);

POSITION DETOUR_CScreenWorld::DETOUR_PrintToConsoleColor(IECString& sLeft, IECString& sRight, ABGR colLeft, ABGR colRight, int nUserArg, bool bResetScrollbar) {
	char* buffer;
	if (LD.bFileOpen) {
		if (sLeft.IsEmpty()) {
			buffer = "[%.8X] %s%s\r\n";
		} else {
			buffer = "[%.8X] %s- %s\r\n";
		}
		LD.appendf(buffer, g_pChitin->GetInfGame().GetWorldTimer().m_nGameTime, (LPCTSTR)sLeft, (LPCTSTR)sRight);
	}
	return (this->*Tramp_CScreenWorld_PrintToConsole6)(sLeft, sRight, colLeft, colRight, nUserArg, bResetScrollbar);
}

POSITION DETOUR_CScreenWorld::DETOUR_PrintToConsole(IECString& sLeft, IECString& sRight, int nUserArg, bool bResetScrollbar) {
	char* buffer;
	if (LD.bFileOpen) {
		if (sLeft.IsEmpty()) {
			buffer = "[%.8X] %s%s\r\n";
		} else {
			buffer = "[%.8X] %s- %s\r\n";
		}
		LD.appendf(buffer, g_pChitin->GetInfGame().GetWorldTimer().m_nGameTime, (LPCTSTR)sLeft, (LPCTSTR)sRight);
	}
	return (this->*Tramp_CScreenWorld_PrintToConsole4)(sLeft, sRight, nUserArg, bResetScrollbar);
}
