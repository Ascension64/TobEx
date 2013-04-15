//TobExEE
#include "hook.h"

#include "stdafx.h"
#include "detoursext.h"
#include "optionsext.h"

#include "AnimationCore.h"
#include "ChitinCore.h"
#include "EngineInventory.h"
#include "EngineWorld.h"
#include "InfGameCore.h"
#include "LuaCore.h"
#include "ObjectCore.h"
#include "ObjectCreature.h"
#include "ScriptCore.h"
#include "UserCore.h"

void InitHooks() {
	DetourTransactionBegin();

	//General
	DetourMemberFunction(Tramp_CBaldurChitin_Construct, DETOUR_CBaldurChitin::DETOUR_Construct); //get g_pChitin
	DetourMemberFunction(Tramp_CBaldurChitin_DoExit, DETOUR_CBaldurChitin::DETOUR_DoExit); //delete TobEx globals
	DetourMemberFunction(Tramp_CRuleTables_Construct, DETOUR_CRuleTables::DETOUR_Construct);
	DetourMemberFunction(Tramp_CRuleTables_Deconstruct, DETOUR_CRuleTables::DETOUR_Deconstruct);

	//Action
	if (pGameOptionsEx->GetOption("Action_ExpandedActions")) {
		DetourMemberFunction(Tramp_CInfGame_InitGame, DETOUR_CInfGame::DETOUR_InitGame);
		DetourMemberFunction(Tramp_CGameSprite_QueueActions, DETOUR_CGameSprite::DETOUR_QueueActions);
		DetourMemberFunction(Tramp_CGameSprite_ClearAllActions, DETOUR_CGameSprite::DETOUR_ClearAllActions);
		DetourMemberFunction(Tramp_CGameSprite_ExecuteAction, DETOUR_CGameSprite::DETOUR_ExecuteAction);
		DetourMemberFunction(Tramp_CCreatureObject_ExecuteAction, DETOUR_CCreatureObject::DETOUR_ExecuteAction);
	}

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
	if (pGameOptionsEx->GetOption("Engine_DisableEndPlayer1Dead"))
		DetourMemberFunction(Tramp_CInfGame_SetLoseCutscene, DETOUR_CInfGame::DETOUR_SetLoseCutscene);

	//Sound
	if (pGameOptionsEx->GetOption("Sound_AnimAttackSounds"))
		DetourMemberFunction(Tramp_CAnimation_PlayCurrentSequenceSound, DETOUR_CAnimation::DETOUR_PlayCurrentSequenceSound);

	//tRIGGER
	if (pGameOptionsEx->GetOption("Trigger_ExpandedTriggers")) {
		DetourMemberFunction(Tramp_CScriptBlock_Evaluate, DETOUR_CScriptBlock::DETOUR_Evaluate);
		DetourMemberFunction(Tramp_CCreatureObject_EvaluateTrigger, DETOUR_CCreatureObject::DETOUR_EvaluateTrigger);
		DetourMemberFunction(Tramp_CGameSprite_EvaluateTrigger, DETOUR_CGameSprite::DETOUR_EvaluateTrigger);
	}

	//UI
	DetourFunction(Tramp_CreateUIControl, DETOUR_CreateUIControl);

	DetourTransactionCommit();
	return;
}