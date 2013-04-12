//TobExEE
#include "optionsext.h"

CGameOptionsEx* pGameOptionsEx = NULL;

void InitOptions() {
	pGameOptionsEx = new CGameOptionsEx();

	pGameOptionsEx->SetOption("Debug_LogDialogueBar", "Debug", "Log Dialogue Bar");
	pGameOptionsEx->SetOption("Debug_Verbose", "Debug", "Verbose Logging");

	return;
}