#include "InfGameCore.h"

#include "utils.h"
#include "objcre.h"
#include "chitin.h"
#include "infgame.h"
#include "cstringex.h"
#include "console.h"
#include "log.h"
#include "InfGameCommon.h"

CRuleTables& (CRuleTables::*Tramp_CRuleTables_Construct)() =
	SetFP(static_cast<CRuleTables& (CRuleTables::*)()>											(&CRuleTables::Construct),					0x6213DC);
void (CRuleTables::*Tramp_CRuleTables_Deconstruct)() =
	SetFP(static_cast<void (CRuleTables::*)()>													(&CRuleTables::Deconstruct),				0x6279D1);
ResRef (CRuleTables::*Tramp_CRuleTables_GetMageSpellRef)(DWORD, DWORD) =
	SetFP(static_cast<ResRef (CRuleTables::*)(DWORD, DWORD)>									(&CRuleTables::GetMageSpellRef),			0x633691);
DWORD (CRuleTables::*Tramp_CRuleTables_GetWeapProfMax)(BYTE, BYTE, BYTE, BOOL, DWORD, DWORD) =
	SetFP(static_cast<DWORD (CRuleTables::*)(BYTE, BYTE, BYTE, BOOL, DWORD, DWORD)>				(&CRuleTables::GetWeapProfMax),				0x636C57);
BOOL (CRuleTables::*Tramp_CRuleTables_IsMageSchoolAllowed)(DWORD, BYTE) =
	SetFP(static_cast<BOOL (CRuleTables::*)(DWORD, BYTE)>										(&CRuleTables::IsMageSchoolAllowed),		0x637DEE);
ResRef (CRuleTables::*Tramp_CRuleTables_GetMageSpellRefAutoPick)(BYTE, BYTE) =
	SetFP(static_cast<ResRef (CRuleTables::*)(BYTE, BYTE)>										(&CRuleTables::GetMageSpellRefAutoPick),	0x63AD1A);

CRuleTables& DETOUR_CRuleTables::DETOUR_Construct() {
	pRuleEx = new CRuleTablesEx();
	return (this->*Tramp_CRuleTables_Construct)();
}

void DETOUR_CRuleTables::DETOUR_Deconstruct() {
	delete pRuleEx;
	pRuleEx = NULL;
	return (this->*Tramp_CRuleTables_Deconstruct)();
}

ResRef DETOUR_CRuleTables::DETOUR_GetMageSpellRef(DWORD nSpellLevel, DWORD nIndex) {
	ResRef rSpell = (this->*Tramp_CRuleTables_GetMageSpellRef)(nSpellLevel, nIndex);
	return CRuleTables_TryHideSpell(rSpell);
}

DWORD DETOUR_CRuleTables::DETOUR_GetWeapProfMax(BYTE dwClassId, BYTE bClassPrimary, BYTE bClassSecondary, BOOL bClassMage, DWORD dwWeapProfId, DWORD dwKit) {
	DWORD dwWeapProfMax = (this->*Tramp_CRuleTables_GetWeapProfMax)(dwClassId, bClassPrimary, bClassSecondary, bClassMage, dwWeapProfId, dwKit);
	DWORD dwClassProfsMax = g_pChitin->pCharacter->dwProfsMax;
	if (dwClassProfsMax) {
		return dwClassProfsMax < dwWeapProfMax ? dwClassProfsMax : dwWeapProfMax;
	} else {
		return dwWeapProfMax;
	}
}

BOOL DETOUR_CRuleTables::DETOUR_IsMageSchoolAllowed(DWORD dwKit, BYTE race) {
	if (!pRuleEx->m_MageSchoolRaceReq.m_2da.bLoaded) return (this->*Tramp_CRuleTables_IsMageSchoolAllowed)(dwKit, race);

	CInfGame* pGame = g_pChitin->pGame;
	IECString sRace = pGame->GetRaceString(race);
	IECString sClass = pGame->GetClassString(MAGE, dwKit);
	IECString sAllowed = pRuleEx->m_MageSchoolRaceReq.GetValue(sRace, sClass);
	BOOL bAllowed;
	sscanf_s((LPCTSTR)sAllowed, "%d", &bAllowed);

	return bAllowed;
}

ResRef DETOUR_CRuleTables::DETOUR_GetMageSpellRefAutoPick(BYTE nSpellLevel, BYTE nIndex) {
	ResRef rSpell = (this->*Tramp_CRuleTables_GetMageSpellRefAutoPick)(nSpellLevel, nIndex);
	return CRuleTables_TryHideSpell(rSpell);
}

BOOL __stdcall CRuleTables_HasKnownMageSpells(CCreatureObject& cre) {
	for (int i = 0; i < 9; i++) {
		if (cre.m_KnownSpellsWizard[i].GetCount()) return TRUE;
	}
	return FALSE;
}

ResRef CRuleTables_TryHideSpell(ResRef& rSpell) {
	if (!pRuleEx->m_HideSpell.m_2da.bLoaded) return rSpell;

	if (pRuleEx->m_HideSpell.nCols && pRuleEx->m_HideSpell.nRows) {
		for (int i = 0; i < pRuleEx->m_HideSpell.nRows; i++) {
			IECString* sSpellHide = pRuleEx->m_HideSpell.pRowHeaderArray + i;
			if (rSpell == *sSpellHide) {
				rSpell = "NO_SPELL";
				break;
			}
		}
	}

	return rSpell;
}

IECString& __stdcall CRuleTables_GetMaxProfs(CCreatureObject& cre, IECString& sRowName) {
	IECString sClass = g_pChitin->pGame->GetClassString(cre.IdsCopy1.GetClass(), TRUECLASS);
	IECString sLevel = "2";
	IECString& sLevelExp = g_pChitin->pGame->XPLEVEL.GetValue(sLevel, sClass);
	DWORD levelExp = atoi((LPCTSTR)sLevelExp);

	IECString sColName;
	cre.m_BaseStats.currentExp < levelExp ? sColName = "FIRST_LEVEL" : sColName = "NONE" /*"OTHER_LEVELS"*/;
		
	return g_pChitin->pGame->PROFSMAX.GetValue(sColName, sRowName); //placed into g_pChitin->pCharacter->dwProfsMax;
}

STRREF __stdcall CInfGame_GetRaceText(DWORD nRace) {
	DWORD Eip;
	GetEip(Eip);

	if (Eip == 0x734392) {
		if (nRace == 5) {
			nRace = 3;
		} else {
			if (nRace == 3) {
				nRace = 5;
			}
		}
	}

	if (pRuleEx->m_RaceText.m_2da.bLoaded) {
		IECString sStrRef;

		int nCol = 0;
		int nRow = nRace;
		if (nCol < pRuleEx->m_RaceText.nCols &&
			nRow < pRuleEx->m_RaceText.nRows &&
			nCol >= 0 &&
			nRow >= 0) {
			sStrRef = *((pRuleEx->m_RaceText.pDataArray) + (pRuleEx->m_RaceText.nCols * nRow + nCol));
		} else {
			sStrRef = pRuleEx->m_RaceText.defaultVal;
		}

		STRREF strref;
		sscanf_s((LPCTSTR)sStrRef, "%d", &strref);
		return strref;
	} else {
		STRREF strref;
		switch (nRace) {
		case 0:
			strref = 0x1C19;
			break;
		case 1:
			strref = 0x1C1A;
			break;
		case 2:
			strref = 0x1C1D;
			break;
		case 3:
			strref = 0x1C0E;
			break;
		case 4:
			strref = 0x1C1B;
			break;
		case 5:
			strref = 0x1C1C;
			break;
		case 6:
			strref = 0xCFC2;
			break;
		case 152:
			strref = 0x208C;
			break;
		default:
			strref = -1;
			break;
		}

		return strref;
	}

}