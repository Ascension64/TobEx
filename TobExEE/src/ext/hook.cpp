//TobExEE
#include "hook.h"

#include "stdafx.h"
#include "detoursext.h"
#include "optionsext.h"

#include "ChitinCore.h"
#include "EngineWorld.h"

void InitHooks() {
	DetourTransactionBegin();

	//General
	DetourMemberFunction(Tramp_CBaldurChitin_Construct, DETOUR_CBaldurChitin::DETOUR_Construct); //get g_pChitin
	DetourMemberFunction(Tramp_CBaldurChitin_DoExit, DETOUR_CBaldurChitin::DETOUR_DoExit); //delete TobEx globals

	if (pGameOptionsEx->GetOption("Debug_LogDialogueBar")) {
		DetourMemberFunction(Tramp_CScreenWorld_PrintToConsole6, DETOUR_CScreenWorld::DETOUR_PrintToConsoleColor)
		DetourMemberFunction(Tramp_CScreenWorld_PrintToConsole4, DETOUR_CScreenWorld::DETOUR_PrintToConsole)
	}

	DetourTransactionCommit();
	return;
}