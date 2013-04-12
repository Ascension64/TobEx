#include "EngineInventory.h"

#include "chitin.h"

DefineTrampMemberFunc(void, CScreenInventory, Init, (), Init, Init, 0x740178);

void DETOUR_CScreenInventory::DETOUR_Init() {
	(this->*Tramp_CScreenInventory_Init)();
	if (!g_pChitin->pWorld->bPaused &&
		!g_pChitin->cNetwork.bSessionOpen)
		g_pChitin->pGame->m_WorldTimer.UnpauseGame();
	return;
}