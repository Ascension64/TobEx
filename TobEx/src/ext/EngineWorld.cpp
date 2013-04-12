#include "EngineWorld.h"

#include "chitin.h"

DefineTrampMemberFunc(POSITION, CScreenWorld, PrintToConsole, (
	IECString& sLeft,
	IECString& sRight,
	ABGR colLeft,
	ABGR colRight,
	int nUserArg,
	bool bResetScrollbar
	), PrintToConsole, PrintToConsole6, 0x7DDE63);
DefineTrampMemberFunc(POSITION, CScreenWorld, PrintToConsole, (
	IECString& sLeft,
	IECString& sRight,
	int nUserArg,
	bool bResetScrollbar
	), PrintToConsole, PrintToConsole4, 0x7DE085);

POSITION DETOUR_CScreenWorld::DETOUR_PrintToConsoleColor(IECString& sLeft, IECString& sRight, ABGR colLeft, ABGR colRight, int nUserArg, bool bResetScrollbar) {
	char* buffer;
	if (LD.bFileOpen) {
		if (sLeft.IsEmpty()) {
			buffer = "[%.8X] %s%s\r\n";
		} else {
			buffer = "[%.8X] %s- %s\r\n";
		}
		LD.appendf(buffer, g_pChitin->pGame->m_WorldTimer.nGameTime, (LPCTSTR)sLeft, (LPCTSTR)sRight);
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
		LD.appendf(buffer, g_pChitin->pGame->m_WorldTimer.nGameTime, (LPCTSTR)sLeft, (LPCTSTR)sRight);
	}
	return (this->*Tramp_CScreenWorld_PrintToConsole4)(sLeft, sRight, nUserArg, bResetScrollbar);
}
