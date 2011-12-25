#include "InfGameCore.h"

#include "stdafx.h"
#include "objcre.h"
#include "chitin.h"
#include "infgame.h"
#include "cstringex.h"
#include "console.h"
#include "log.h"
#include "InfGameCommon.h"

CRuleTables& (CRuleTables::*Tramp_CRuleTables_Construct)() =
	SetFP(static_cast<CRuleTables& (CRuleTables::*)()>									(&CRuleTables::Construct),					0x6213DC);
void (CRuleTables::*Tramp_CRuleTables_Deconstruct)() =
	SetFP(static_cast<void (CRuleTables::*)()>											(&CRuleTables::Deconstruct),				0x6279D1);
int (CRuleTables::*Tramp_CRuleTables_CalculateNewHPSubclass)(char, char, CDerivedStats&, CDerivedStats&, int, int) =
	SetFP(static_cast<int (CRuleTables::*)(char, char, CDerivedStats&, CDerivedStats&, int, int)>
																						(&CRuleTables::CalculateNewHPSubclass),		0x631055);
ResRef (CRuleTables::*Tramp_CRuleTables_GetMageSpellRef)(int, int) =
	SetFP(static_cast<ResRef (CRuleTables::*)(int, int)>								(&CRuleTables::GetMageSpellRef),			0x633691);
int (CRuleTables::*Tramp_CRuleTables_GetWeapProfMax)(char, char, char, BOOL, int, unsigned int) =
	SetFP(static_cast<int (CRuleTables::*)(char, char, char, BOOL, int, unsigned int)>	(&CRuleTables::GetWeapProfMax),				0x636C57);
BOOL (CRuleTables::*Tramp_CRuleTables_IsMageSchoolAllowed)(unsigned int, unsigned char) =
	SetFP(static_cast<BOOL (CRuleTables::*)(unsigned int, unsigned char)>				(&CRuleTables::IsMageSchoolAllowed),		0x637DEE);
ResRef (CRuleTables::*Tramp_CRuleTables_GetMageSpellRefAutoPick)(char, char) =
	SetFP(static_cast<ResRef (CRuleTables::*)(char, char)>								(&CRuleTables::GetMageSpellRefAutoPick),	0x63AD1A);

CRuleTables& DETOUR_CRuleTables::DETOUR_Construct() {
	pRuleEx = new CRuleTablesEx();
	return (this->*Tramp_CRuleTables_Construct)();
}

void DETOUR_CRuleTables::DETOUR_Deconstruct() {
	delete pRuleEx;
	pRuleEx = NULL;
	return (this->*Tramp_CRuleTables_Deconstruct)();
}

int DETOUR_CRuleTables::DETOUR_CalculateNewHPSubclass(char nClass, char nSubclass, CDerivedStats& cdsOld, CDerivedStats& cdsNew, int nMinRoll, int nDivisor) {
	if (!pRuleEx->m_HPClass.m_2da.bLoaded ||
		!pRuleEx->m_HPBarbarian.m_2da.bLoaded) {
		return (this->*Tramp_CRuleTables_CalculateNewHPSubclass)(nClass, nSubclass, cdsOld, cdsNew, nMinRoll, nDivisor);
	}

	char nSubclassLevelOld = cdsOld.GetSubclassLevel(nClass, nSubclass);
	char nSubclassLevelNew = cdsNew.GetSubclassLevel(nClass, nSubclass);

	IECString sSubclass;
	if (nSubclass == CLASS_FIGHTER) {
		unsigned int nKitUnusableFlag = cdsNew.kit;
		if (cdsNew.kit & KIT_TRUECLASS &&
			cdsNew.kit & 0xBFFF) {
			unsigned int dwKitOnly = cdsNew.kit & 0xBFFF;
			int col = 6;
			int row = dwKitOnly;

			IECString sKitUnusableFlag;
			if (col < KITLIST.nCols &&
				row < KITLIST.nRows &&
				col >= 0 &&
				row >= 0) {
				sKitUnusableFlag = *((KITLIST.pDataArray) + (KITLIST.nCols * row + col));
			} else {
				sKitUnusableFlag = KITLIST.defaultVal;
			}

			sscanf_s((LPCTSTR)sKitUnusableFlag, "%d", &nKitUnusableFlag);
		}

		if (nKitUnusableFlag == KIT_BARBARIAN) {
			sSubclass = "BARBARIAN";
		} else {
			sSubclass = GetClassString(nSubclass, KIT_TRUECLASS);
		}
	} else {
		sSubclass = GetClassString(nSubclass, KIT_TRUECLASS);
	}

	IECString sColName = "TABLE";
	IECString sTable = pRuleEx->m_HPClass.GetValue(sColName, sSubclass);
	
	CRuleTable table;
	table.LoadTable(ResRef(sTable));
	if (!table.m_2da.bLoaded) {
		LPCTSTR lpsz = "DETOUR_CRuleTables::DETOUR_CalculateNewHPSubclass(): %s.2DA not found\r\n";
		L.timestamp();
		L.append(lpsz);
		console.write(lpsz);

		return (this->*Tramp_CRuleTables_CalculateNewHPSubclass)(nClass, nSubclass, cdsOld, cdsNew, nMinRoll, nDivisor);
	}

	if (pGameOptionsEx->bDebugVerbose) {
		LPCTSTR lpsz = "DETOUR_CRuleTables::DETOUR_CalculateNewHPSubclass(): Using table %s.2DA\r\n";
		L.timestamp();
		L.append(lpsz, 1, (LPCTSTR)sTable);
		console.write(lpsz, 1, (LPCTSTR)sTable);
	}

	return CalculateNewHPRule(table, nSubclassLevelOld, nSubclassLevelNew, nMinRoll, nDivisor, FALSE, 0, FALSE, 0);
}

ResRef DETOUR_CRuleTables::DETOUR_GetMageSpellRef(int nSpellLevel, int nIndex) {
	ResRef rSpell = (this->*Tramp_CRuleTables_GetMageSpellRef)(nSpellLevel, nIndex);
	return CRuleTables_TryHideSpell(rSpell);
}

int DETOUR_CRuleTables::DETOUR_GetWeapProfMax(char dwClassId, char bClassPrimary, char bClassSecondary, BOOL bClassMage, int dwWeapProfId, unsigned int dwKit) {
	int dwWeapProfMax = (this->*Tramp_CRuleTables_GetWeapProfMax)(dwClassId, bClassPrimary, bClassSecondary, bClassMage, dwWeapProfId, dwKit);
	int dwClassProfsMax = g_pChitin->pCharacter->dwProfsMax;
	if (dwClassProfsMax) {
		return dwClassProfsMax < dwWeapProfMax ? dwClassProfsMax : dwWeapProfMax;
	} else {
		return dwWeapProfMax;
	}
}

BOOL DETOUR_CRuleTables::DETOUR_IsMageSchoolAllowed(unsigned int dwKit, unsigned char nRace) {
	if (!pRuleEx->m_MageSchoolRaceReq.m_2da.bLoaded) return (this->*Tramp_CRuleTables_IsMageSchoolAllowed)(dwKit, nRace);

	CInfGame* pGame = g_pChitin->pGame;
	IECString sRace = pGame->GetRaceString(nRace);
	IECString sClass = pGame->GetClassString(CLASS_MAGE, dwKit);
	IECString sAllowed = pRuleEx->m_MageSchoolRaceReq.GetValue(sRace, sClass);
	BOOL bAllowed;
	sscanf_s((LPCTSTR)sAllowed, "%d", &bAllowed);

	return bAllowed;
}

ResRef DETOUR_CRuleTables::DETOUR_GetMageSpellRefAutoPick(char nSpellLevel, char nIndex) {
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
	IECString sClass = g_pChitin->pGame->GetClassString(cre.oBase.GetClass(), KIT_TRUECLASS);
	IECString sLevel = "2";
	IECString& sLevelExp = g_pChitin->pGame->XPLEVEL.GetValue(sLevel, sClass);
	int levelExp = atoi((LPCTSTR)sLevelExp);

	IECString sColName;
	cre.m_BaseStats.currentExp < levelExp ? sColName = "FIRST_LEVEL" : sColName = "NONE" /*"OTHER_LEVELS"*/;
		
	return g_pChitin->pGame->PROFSMAX.GetValue(sColName, sRowName); //placed into g_pChitin->pCharacter->dwProfsMax;
}

STRREF __stdcall CInfGame_GetRaceText(unsigned int nRace) {
	int Eip;
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
			strref = 0x1C19; //human
			break;
		case 1:
			strref = 0x1C1A; //elf
			break;
		case 2:
			strref = 0x1C1D; //half-elf
			break;
		case 3:
			strref = 0x1C0E; //dwarf
			break;
		case 4:
			strref = 0x1C1B; //halfling
			break;
		case 5:
			strref = 0x1C1C; //gnome
			break;
		case 6:
			strref = 0xCFC2; //half-orc
			break;
		case 152:
			strref = 0x208C; //tiefling
			break;
		default:
			strref = -1;
			break;
		}

		return strref;
	}

}

BOOL __stdcall CRuleTables_DoesEquipSlotPassCreExclude(CCreatureObject& cre, short wSlot, CItem& itmGrabbed, STRREF* pStrRef) {
	BOOL bPass = TRUE;

	if (pRuleEx->m_ItemCreExclude.m_2da.bLoaded) {
		for (int row = 0; row < pRuleEx->m_ItemCreExclude.nRows; row++) {
			IECString sRowName = pRuleEx->m_ItemCreExclude.GetRowName(row);
			IECString sCreName(cre.name);

			POINT loc;
			loc.y = row;

			loc.x = 0;
			IECString sItm = pRuleEx->m_ItemCreExclude.GetValue(loc);

			loc.x = 1;
			BOOL bNoPickupEquip = atoi((LPCTSTR)pRuleEx->m_ItemCreExclude.GetValue(loc));

			loc.x = 3;
			BOOL bOnlyEquip = atoi((LPCTSTR)pRuleEx->m_ItemCreExclude.GetValue(loc));

			loc.x = 9;
			BOOL bNoEquip = atoi((LPCTSTR)pRuleEx->m_ItemCreExclude.GetValue(loc));

			if (cre.m_Inventory.items[wSlot] != NULL) {
				if (!sRowName.CompareNoCase((LPCTSTR)sCreName) &&
					!sItm.CompareNoCase(cre.m_Inventory.items[wSlot]->m_itm.name) &&
					bNoPickupEquip) {
					loc.x = 2;
					STRREF strref = atoi((LPCTSTR)pRuleEx->m_ItemCreExclude.GetValue(loc));
					*pStrRef = strref;
					if (pGameOptionsEx->bDebugVerbose) {
						LPCTSTR lpsz = "CRuleTables_DoesEquipSlotPassCreExclude(): Found %s with NO_PICKUP_E %s\r\n";
						L.timestamp();
						L.append(lpsz, 2, (LPCTSTR)sRowName, (LPCTSTR)sItm);
						console.write(lpsz, 2, (LPCTSTR)sRowName, (LPCTSTR)sItm);
					}
					bPass = FALSE;
				}
			}

			if (&itmGrabbed != NULL) {
				if (sRowName.CompareNoCase((LPCTSTR)sCreName) &&
					!sItm.CompareNoCase(itmGrabbed.m_itm.name) &&
					bOnlyEquip) {
					loc.x = 4;
					STRREF strref = atoi((LPCTSTR)pRuleEx->m_ItemCreExclude.GetValue(loc));
					*pStrRef = strref;
					if (pGameOptionsEx->bDebugVerbose) {
						LPCTSTR lpsz = "CRuleTables_DoesEquipSlotPassCreExclude(): Found %s with ONLY_EQUIP %s\r\n";
						L.timestamp();
						L.append(lpsz, 2, (LPCTSTR)sRowName, (LPCTSTR)sItm);
						console.write(lpsz, 2, (LPCTSTR)sRowName, (LPCTSTR)sItm);
					}
					bPass = FALSE;
				}
			}

			if (&itmGrabbed != NULL) {
				if (!sRowName.CompareNoCase((LPCTSTR)sCreName) &&
					!sItm.CompareNoCase(itmGrabbed.m_itm.name) &&
					bNoEquip) {
					loc.x = 10;
					STRREF strref = atoi((LPCTSTR)pRuleEx->m_ItemCreExclude.GetValue(loc));
					*pStrRef = strref;
					if (pGameOptionsEx->bDebugVerbose) {
						LPCTSTR lpsz = "CRuleTables_DoesEquipSlotPassCreExclude(): Found %s with NO_DROP_E %s\r\n";
						L.timestamp();
						L.append(lpsz, 2, (LPCTSTR)sRowName, (LPCTSTR)sItm);
						console.write(lpsz, 2, (LPCTSTR)sRowName, (LPCTSTR)sItm);
					}
					bPass = FALSE;
				}
			}

		}
	} else {
		IECString sName(cre.name);

		if (cre.m_Inventory.items[wSlot] != NULL) {
			//fail if target slot has cre-specific item
			if (!sName.CompareNoCase("MINSC") && cre.m_Inventory.items[wSlot]->m_itm.name == "MISC84") {
				*pStrRef = 0x27EA;
				bPass = FALSE;
			}
			if (!sName.CompareNoCase("ALORA") && cre.m_Inventory.items[wSlot]->m_itm.name == "MISC88") {
				*pStrRef = 0x27EB;
				bPass = FALSE;
			}
			if (!sName.CompareNoCase("EDWIN") && cre.m_Inventory.items[wSlot]->m_itm.name == "MISC89") {
				*pStrRef = 0x27EE;
				bPass = FALSE;
			}
		}

		//fail if active item to be equipped is cre-specific
		if (&itmGrabbed != NULL) {
			if (sName.CompareNoCase("XAN") && itmGrabbed.m_itm.name == "SW1H13") {
				*pStrRef = 0x27EC;
				bPass = FALSE;
			}
			if (sName.CompareNoCase("ELDOTH") && itmGrabbed.m_itm.name == "AROW14") {
				*pStrRef = 0x27EC;
				bPass = FALSE;
			}
			if (sName.CompareNoCase("MINSC") && itmGrabbed.m_itm.name == "MISC84") {
				*pStrRef = 0x27EA;
				bPass = FALSE;
			}
			if (sName.CompareNoCase("ALORA") && itmGrabbed.m_itm.name == "MISC88") {
				*pStrRef = 0x27EB;
				bPass = FALSE;
			}
			if (sName.CompareNoCase("EDWIN") && itmGrabbed.m_itm.name == "MISC89") {
				*pStrRef = 0x27EE;
				bPass = FALSE;
			}
		}

	}

	return bPass;
}

BOOL __stdcall CRuleTables_DoesInvSlotPassCreExclude(CCreatureObject& cre, short wSlot, CItem& itmGrabbed, STRREF* pStrRef) {
	BOOL bPass = TRUE;

	if (pRuleEx->m_ItemCreExclude.m_2da.bLoaded) {
		for (int row = 0; row < pRuleEx->m_ItemCreExclude.nRows; row++) {
			IECString sRowName = pRuleEx->m_ItemCreExclude.GetRowName(row);
			IECString sCreName(cre.name);

			POINT loc;
			loc.y = row;

			loc.x = 0;
			IECString sItm = pRuleEx->m_ItemCreExclude.GetValue(loc);

			loc.x = 5;
			BOOL bNoPickupInv = atoi((LPCTSTR)pRuleEx->m_ItemCreExclude.GetValue(loc));

			loc.x = 7;
			BOOL bNoDropInv = atoi((LPCTSTR)pRuleEx->m_ItemCreExclude.GetValue(loc));

			if (cre.m_Inventory.items[wSlot] != NULL) {
				if (!sRowName.CompareNoCase((LPCTSTR)sCreName) &&
					!sItm.CompareNoCase(cre.m_Inventory.items[wSlot]->m_itm.name) &&
					bNoPickupInv) {
					loc.x = 6;
					STRREF strref = atoi((LPCTSTR)pRuleEx->m_ItemCreExclude.GetValue(loc));
					*pStrRef = strref;
					if (pGameOptionsEx->bDebugVerbose) {
						LPCTSTR lpsz = "CRuleTables_DoesInvSlotPassCreExclude(): Found %s with NO_PICKUP_I %s\r\n";
						L.timestamp();
						L.append(lpsz, 2, (LPCTSTR)sRowName, (LPCTSTR)sItm);
						console.write(lpsz, 2, (LPCTSTR)sRowName, (LPCTSTR)sItm);
					}
					bPass = FALSE;
				}
			}

			if (&itmGrabbed != NULL) {
				if (!sRowName.CompareNoCase((LPCTSTR)sCreName) &&
					!sItm.CompareNoCase(itmGrabbed.m_itm.name) &&
					bNoDropInv) {
					loc.x = 8;
					STRREF strref = atoi((LPCTSTR)pRuleEx->m_ItemCreExclude.GetValue(loc));
					*pStrRef = strref;
					if (pGameOptionsEx->bDebugVerbose) {
						LPCTSTR lpsz = "CRuleTables_DoesInvSlotPassCreExclude(): Found %s with NO_DROP_I %s\r\n";
						L.timestamp();
						L.append(lpsz, 2, (LPCTSTR)sRowName, (LPCTSTR)sItm);
						console.write(lpsz, 2, (LPCTSTR)sRowName, (LPCTSTR)sItm);
					}
					bPass = FALSE;
				}
			}

		}
	} else {
		IECString sName(cre.name);

		if (cre.m_Inventory.items[wSlot] != NULL) {
			//fail if target slot has cre-specific item
			if (!sName.CompareNoCase("MINSC") && cre.m_Inventory.items[wSlot]->m_itm.name == "MISC84") {
				*pStrRef = 0x27EA;
				bPass = FALSE;
			}
			if (!sName.CompareNoCase("ALORA") && cre.m_Inventory.items[wSlot]->m_itm.name == "MISC88") {
				*pStrRef = 0x27EB;
				bPass = FALSE;
			}
			if (!sName.CompareNoCase("EDWIN") && cre.m_Inventory.items[wSlot]->m_itm.name == "MISC89") {
				*pStrRef = 0x27EE;
				bPass = FALSE;
			}
		}
	}

	return bPass;
}

BOOL __stdcall CRuleTables_IsLowEncumbrance(unsigned int nWeight, unsigned int nWeightAllowance) {
	if (pRuleEx->m_nEncumbranceLowThreshold == 0) return FALSE;
	return (nWeight * 100 / nWeightAllowance) > pRuleEx->m_nEncumbranceLowThreshold;
}

BOOL __stdcall CRuleTables_IsHighEncumbrance(unsigned int nWeight, unsigned int nWeightAllowance) {
	if (pRuleEx->m_nEncumbranceHighThreshold == 0) return FALSE;
	return (nWeight * 100 / nWeightAllowance) > pRuleEx->m_nEncumbranceHighThreshold;
}