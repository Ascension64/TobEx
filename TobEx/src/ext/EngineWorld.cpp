#include "EngineWorld.h"

#include "chitin.h"

extern POSITION (CWorld::*Tramp_CWorld_PrintToConsole_6)(IECString&, IECString&, ABGR, ABGR, int, bool) =
	SetFP(static_cast<POSITION (CWorld::*)(IECString&, IECString&, ABGR, ABGR, int, bool)>	(&CWorld::PrintToConsole),	0x7DDE63);
extern POSITION (CWorld::*Tramp_CWorld_PrintToConsole_4)(IECString&, IECString&, int, bool) =
	SetFP(static_cast<POSITION (CWorld::*)(IECString&, IECString&, int, bool)>				(&CWorld::PrintToConsole),	0x7DE085);

POSITION DETOUR_CWorld::DETOUR_PrintToConsoleColor(IECString& sLeft, IECString& sRight, ABGR colLeft, ABGR colRight, int nUserArg, bool bResetScrollbar) {
	char* buffer;
	if (LD.bFileOpen) {
		if (sLeft.IsEmpty()) {
			buffer = "[%.8X] %s%s\r\n";
		} else {
			buffer = "[%.8X] %s- %s\r\n";
		}
		LD.append(buffer, 3, g_pChitin->pGame->m_WorldTimer.nGameTime, (LPCTSTR)sLeft, (LPCTSTR)sRight);
	}
	return (this->*Tramp_CWorld_PrintToConsole_6)(sLeft, sRight, colLeft, colRight, nUserArg, bResetScrollbar);
}

POSITION DETOUR_CWorld::DETOUR_PrintToConsole(IECString& sLeft, IECString& sRight, int nUserArg, bool bResetScrollbar) {
	char* buffer;
	if (LD.bFileOpen) {
		if (sLeft.IsEmpty()) {
			buffer = "[%.8X] %s%s\r\n";
		} else {
			buffer = "[%.8X] %s- %s\r\n";
		}
		LD.append(buffer, 3, g_pChitin->pGame->m_WorldTimer.nGameTime, (LPCTSTR)sLeft, (LPCTSTR)sRight);
	}
	return (this->*Tramp_CWorld_PrintToConsole_4)(sLeft, sRight, nUserArg, bResetScrollbar);
}
