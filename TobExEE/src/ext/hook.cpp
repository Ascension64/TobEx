//TobExEE
#include "hook.h"

#include "stdafx.h"
#include "detoursext.h"
#include "optionsext.h"

#include "ChitinCore.h"
#include "EngineInventory.h"
#include "EngineWorld.h"
#include "LuaCore.h"
#include "UserCore.h"

void InitHooks() {
	DetourTransactionBegin();

	//General
	DetourMemberFunction(Tramp_CBaldurChitin_Construct, DETOUR_CBaldurChitin::DETOUR_Construct); //get g_pChitin
	DetourMemberFunction(Tramp_CBaldurChitin_DoExit, DETOUR_CBaldurChitin::DETOUR_DoExit); //delete TobEx globals

	//Debug
	if (pGameOptionsEx->GetOption("Debug_ExpandedLUAConsole"))
		DetourFunction(Tramp_IElua_init, DETOUR_IElua_init);

	if (pGameOptionsEx->GetOption("Debug_LogDialogueBar")) {
		DetourMemberFunction(Tramp_CScreenWorld_PrintToConsole6, DETOUR_CScreenWorld::DETOUR_PrintToConsoleColor)
		DetourMemberFunction(Tramp_CScreenWorld_PrintToConsole4, DETOUR_CScreenWorld::DETOUR_PrintToConsole)
	}

	//Engine
	if (pGameOptionsEx->GetOption("Engine_DisableInvPauseSP"))
		DetourMemberFunction(Tramp_CScreenInventory_Init, DETOUR_CScreenInventory::DETOUR_Init);

	//UI
	DetourFunction(Tramp_CreateUIControl, DETOUR_CreateUIControl);

	DetourTransactionCommit();
	return;
}