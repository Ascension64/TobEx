//TobExEE
#include "optionsext.h"

CGameOptionsEx* pGameOptionsEx = NULL;

void InitOptions() {
	pGameOptionsEx = new CGameOptionsEx();

	pGameOptionsEx->SetOption("Debug_ExpandedLUAConsole", "Debug", "Expanded LUA Console");
	pGameOptionsEx->SetOption("Debug_LogDialogueBar", "Debug", "Log Dialogue Bar");
	pGameOptionsEx->SetOption("Debug_LogMissingRes", "Debug", "Log Missing Resources");
	pGameOptionsEx->SetOption("Debug_Verbose", "Debug", "Verbose Logging");

	pGameOptionsEx->SetOption("Eff_StoneskinDisableColour", "Tweak", "Effect Opcodes:Disable Stoneskin Grey Colour");

	pGameOptionsEx->SetOption("Engine_AllowEquipArmorCombat", "Tweak", "Engine:Allow Equipping Armor in Combat");
	pGameOptionsEx->SetOption("Engine_DisableInvPauseSP", "Tweak", "Engine:Disable Force Inventory Pause");

	pGameOptionsEx->SetOption("User_CustomDlgBarSize", "UI", "Custom Dialogue Bar Buffer Size");
	pGameOptionsEx->GetMap()["User_CustomDlgBarSize"] = max(pGameOptionsEx->GetMap()["User_CustomDlgBarSize"], 0);

	return;
}