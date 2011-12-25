#include "EngineInventory.h"

#include "chitin.h"

void (CInventory::*Tramp_CInventory_Init)() =
	SetFP(static_cast<void (CInventory::*)()>	(&CInventory::Init),	0x740178);

void DETOUR_CInventory::DETOUR_Init() {
	(this->*Tramp_CInventory_Init)();
	if (!g_pChitin->pWorld->bPaused &&
		!g_pChitin->cNetwork.bSessionOpen)
		g_pChitin->pGame->m_WorldTimer.UnpauseGame();
	return;
}