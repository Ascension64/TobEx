#include "InfGameCore.h"

#include "utils.h"
#include "objcre.h"
#include "chitin.h"
#include "infgame.h"
#include "cstringex.h"
#include "console.h"
#include "log.h"

ResRef DETOUR_CRuleTables::DETOUR_GetMageSpellRef(DWORD nSpellLevel, DWORD nIndex) {
	ResRef rSpell = GetMageSpellRef(nSpellLevel, nIndex);
	return CRuleTables_TryHideSpell(rSpell);
}

ResRef DETOUR_CRuleTables::DETOUR_GetMageSpellRefAutoPick(BYTE nSpellLevel, BYTE nIndex) {
	ResRef rSpell = GetMageSpellRefAutoPick(nSpellLevel, nIndex);
	return CRuleTables_TryHideSpell(rSpell);
}

DWORD DETOUR_CRuleTables::DETOUR_GetWeapProfMax(BYTE dwClassId, BYTE bClassPrimary, BYTE bClassSecondary, BOOL bClassMage, DWORD dwWeapProfId, DWORD dwKit) {
	DWORD dwWeapProfMax = GetWeapProfMax(dwClassId, bClassPrimary, bClassSecondary, bClassMage, dwWeapProfId, dwKit);
	DWORD dwClassProfsMax = g_pChitin->pCharacter->dwProfsMax;
	if (dwClassProfsMax) {
		return dwClassProfsMax < dwWeapProfMax ? dwClassProfsMax : dwWeapProfMax;
	} else {
		return dwWeapProfMax;
	}
}

BOOL __stdcall CRuleTables_HasKnownMageSpells(CCreatureObject& cre) {
	for (int i = 0; i < 9; i++) {
		if (cre.m_KnownSpellsWizard[i].GetCount()) return TRUE;
	}
	return FALSE;
}

ResRef CRuleTables_TryHideSpell(ResRef& rSpell) {
	CRuleTable crtHideSpl;
	crtHideSpl.m_2da.LoadRes(ResRef("HIDESPL"));

	if (crtHideSpl.m_2da.bLoaded) {
		if (crtHideSpl.nCols && crtHideSpl.nRows) {
			for (int i = 0; i < crtHideSpl.nRows; i++) {
				IECString* sSpellHide= crtHideSpl.pRowHeaderArray + i;
				if (rSpell == *sSpellHide) {
					rSpell = "NO_SPELL";
					break;
				}
			}
		}
	} else {
		LPCTSTR lpsz = "CRuleTables_TryHideSpell(): HIDESPL.2DA not found. Did you install the required WeiDU component?\r\n";
		console.write(lpsz);
		L.timestamp();
		L.append(lpsz);
	}

	return rSpell;
}

IECString& __stdcall CRuleTables_GetMaxProfs(CCreatureObject& cre, IECString& sRowName) {
	IECString sClass = g_pChitin->pGame->GetClassString(cre.IdsCopy1.GetClass(), TRUECLASS);
	IECString sLevel = "2";
	IECString& sLevelExp = g_pChitin->pGame->XPLEVEL.m_2da.GetValue(sLevel, sClass);
	DWORD levelExp = atoi((LPCTSTR)sLevelExp);

	IECString sColName;
	cre.m_BaseStats.currentExp < levelExp ? sColName = "FIRST_LEVEL" : sColName = "NONE" /*"OTHER_LEVELS"*/;
		
	return g_pChitin->pGame->PROFSMAX.m_2da.GetValue(sColName, sRowName); //placed into g_pChitin->pCharacter->dwProfsMax;
}

STRREF __stdcall CInfGame_GetRaceText(DWORD nRace) {
	CRuleTable crtRaceText;
	crtRaceText.m_2da.LoadRes(ResRef("RACETEXT"));

	if (crtRaceText.m_2da.bLoaded) {
		char szRace[8];
		_itoa_s(++nRace, szRace, 10);
		IECString rowName(szRace);
		IECString colName("STRREF");
		IECString sStrRef = crtRaceText.m_2da.GetValue(colName, rowName);

		return sStrRef.IsEmpty() ? -1 : atoi((LPCTSTR)sStrRef);
	} else {
		LPCTSTR lpsz = "CInfGame_GetRaceText(): RACETEXT.2DA not found. Did you install the required WeiDU component?\r\n";
		console.write(lpsz);
		L.timestamp();
		L.append(lpsz);

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