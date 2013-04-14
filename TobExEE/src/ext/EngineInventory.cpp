//TobExEE
#include "EngineInventory.h"
#include "p_enginv.h"

#include "chitin.h"

DefineTrampMemberFunc(void, CScreenInventory, Init, (), Init, Init, CSCREENINVENTORY_INIT);

void DETOUR_CScreenInventory::DETOUR_Init() {
	(this->*Tramp_CScreenInventory_Init)();
	if (!g_pChitin->GetWorld().bPaused &&
		!g_pChitin->m_Network.GetSessionOpen())
		g_pChitin->GetInfGame().GetWorldTimer().UnpauseGame();
	return;
}