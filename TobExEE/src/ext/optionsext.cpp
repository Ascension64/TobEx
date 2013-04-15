//TobExEE
#include "optionsext.h"

CGameOptionsEx* pGameOptionsEx = NULL;

void InitOptions() {
	pGameOptionsEx = new CGameOptionsEx();

	pGameOptionsEx->SetOption("Action_ExpandedActions", "Action", "Expanded Actions");

	pGameOptionsEx->SetOption("Debug_ExpandedLUAConsole", "Debug", "Expanded LUA Console");
	pGameOptionsEx->SetOption("Debug_LogDialogueBar", "Debug", "Log Dialogue Bar");
	pGameOptionsEx->SetOption("Debug_LogMissingRes", "Debug", "Log Missing Resources");
	pGameOptionsEx->SetOption("Debug_Verbose", "Debug", "Verbose Logging");

	pGameOptionsEx->SetOption("Eff_StoneskinDisableColour", "Tweak", "Effect Opcodes:Disable Stoneskin Grey Colour");
	pGameOptionsEx->SetOption("Eff_DropInvDisintegrate", "Tweak", "Effect Opcodes:Drop Inventory on Disintegrate");
	pGameOptionsEx->SetOption("Eff_DropInvFrozenDeath", "Tweak", "Effect Opcodes:Drop Inventory on Frozen Death");
	pGameOptionsEx->SetOption("Eff_DropInvStoneDeath", "Tweak", "Effect Opcodes:Drop Inventory on Stone Death");

	pGameOptionsEx->SetOption("Engine_AllowEquipArmorCombat", "Tweak", "Engine:Allow Equipping Armor in Combat");
	pGameOptionsEx->SetOption("Engine_DisableEndPlayer1Dead", "Tweak", "Engine:Disable End On Player1 Dead");
	pGameOptionsEx->SetOption("Engine_DisableInvPauseSP", "Tweak", "Engine:Disable Force Inventory Pause");
	pGameOptionsEx->SetOption("Engine_AutoPauseAllSP", "Tweak","Engine:Enable Auto-Pause On All Screens");

	pGameOptionsEx->SetOption("Sound_AnimAttackSounds", "Tweak", "Sound:Enable Animation Attack Sounds");

	pGameOptionsEx->SetOption("Trigger_ExpandedTriggers", "Trigger", "Expanded Triggers");

	pGameOptionsEx->SetOption("User_CustomDlgBarSize", "UI", "Custom Dialogue Bar Buffer Size");
	pGameOptionsEx->GetMap()["User_CustomDlgBarSize"] = max(pGameOptionsEx->GetMap()["User_CustomDlgBarSize"], 0);

	return;
}