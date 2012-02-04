#include "EngineInventory.h"

#include "chitin.h"

void (CScreenInventory::*Tramp_CScreenInventory_Init)() =
	SetFP(static_cast<void (CScreenInventory::*)()>	(&CScreenInventory::Init),	0x740178);

void DETOUR_CScreenInventory::DETOUR_Init() {
	(this->*Tramp_CScreenInventory_Init)();
	if (!g_pChitin->pWorld->bPaused &&
		!g_pChitin->cNetwork.bSessionOpen)
		g_pChitin->pGame->m_WorldTimer.UnpauseGame();
	return;
}