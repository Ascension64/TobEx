//TobExEE
#include "InfGameCore.h"
#include "p_infgame.h"

#include "InfGameCommon.h"

//CRuleTables
DefineTrampMemberFunc(CRuleTables&, CRuleTables, Construct, (), Construct, Construct, CRULETABLES_CONSTRUCT);
DefineTrampMemberFunc(void, CRuleTables, Deconstruct, (), Deconstruct, Deconstruct, CRULETABLES_DECONSTRUCT);

CRuleTables& DETOUR_CRuleTables::DETOUR_Construct() {
	CRuleTables& rule = (this->*Tramp_CRuleTables_Construct)();
	pRuleEx = new CRuleTablesEx(rule);
	return rule;	
}

void DETOUR_CRuleTables::DETOUR_Deconstruct() {
	delete pRuleEx;
	pRuleEx = NULL;
	return (this->*Tramp_CRuleTables_Deconstruct)();
}

//CInfGame
DefineTrampMemberFunc(void, CInfGame, InitGame, (int nUnused, int nUnused2), InitGame, InitGame, CINFGAME_INITGAME);
DefineTrampMemberFunc(void, CInfGame, SetLoseCutscene, (), SetLoseCutscene, SetLoseCutscene, CINFGAME_SETLOSECUTSCENE);

void DETOUR_CInfGame::DETOUR_InitGame(int nUnused, int nUnused2) {
	std::map<ENUM, CBlockVariables*>::iterator it;
	for (it = pRuleEx->m_MapActionVars.begin(); it != pRuleEx->m_MapActionVars.end(); it++) {
		delete it->second;
		it->second = NULL;
	}
	pRuleEx->m_MapActionVars.clear();

	return (this->*Tramp_CInfGame_InitGame)(nUnused, nUnused2);
}

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
