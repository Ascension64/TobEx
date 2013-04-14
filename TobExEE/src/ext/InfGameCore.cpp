//TobExEE
#include "InfGameCore.h"
#include "p_infgame.h"

DefineTrampMemberFunc(void, CInfGame, SetLoseCutscene, (), SetLoseCutscene, SetLoseCutscene, CINFGAME_SETLOSECUTSCENE);

void DETOUR_CInfGame::DETOUR_SetLoseCutscene() {
	DWORD Eip;
	GetEip(Eip);

	if (0) IECString("DETOUR_CInfGame::DETOUR_SetLoseCutscene");

	//FIX_ME - when implementing action LoseGame(), re-implement the original function instead of relying on this
	if (Eip == DETOUR_CINFGAME_SETLOSECUTSCENE_EIP1 || //CEffectInstantDeath::ApplyEffect()
		Eip == DETOUR_CINFGAME_SETLOSECUTSCENE_EIP2 || //CEffectInstantDeath::ApplyEffect()
		Eip == DETOUR_CINFGAME_SETLOSECUTSCENE_EIP3 || //CEffectConstitutionLossByDeath::ApplyEffect()
		Eip == DETOUR_CINFGAME_SETLOSECUTSCENE_EIP4 || //CEffectPetrification::ApplyEffect()
		Eip == DETOUR_CINFGAME_SETLOSECUTSCENE_EIP5 || //CEffectPetrification::ApplyEffect()
		Eip == DETOUR_CINFGAME_SETLOSECUTSCENE_EIP6 || //CEffectImprisonment::ApplyEffect()
		Eip == DETOUR_CINFGAME_SETLOSECUTSCENE_EIP7 || //CScreenWorld::Init()
		Eip == DETOUR_CINFGAME_SETLOSECUTSCENE_EIP8) { //CScreenWorld::Update()
		return;
	}
	
	return (this->*Tramp_CInfGame_SetLoseCutscene)();
}
