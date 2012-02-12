#include "InfGameCore.h"

#include "stdafx.h"
#include "objcre.h"
#include "chitin.h"
#include "infgame.h"
#include "cstringex.h"
#include "console.h"
#include "log.h"
#include "InfGameCommon.h"
#include "ObjectStats.h"

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

void (CMoveAreasList::*Tramp_CMoveAreasList_MoveAllTo)(CArea&) =
	SetFP(static_cast<void (CMoveAreasList::*)(CArea&)>	(&CMoveAreasList::MoveAllTo),	0x5EFA6D);

int (CInfGame::*Tramp_CInfGame_GetNumOfItemInBag)(ResRef&, ResRef&, BOOL) =
	SetFP(static_cast<int (CInfGame::*)(ResRef&, ResRef&, BOOL)>	(&CInfGame::GetNumOfItemInBag),		0x68F35C);
void (CInfGame::*Tramp_CInfGame_SetLoseCutscene)() =
	SetFP(static_cast<void (CInfGame::*)()>							(&CInfGame::SetLoseCutscene),		0x6AE3E0);

//CRuleTables
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

int DETOUR_CRuleTables::DETOUR_CalculateNewHPSubclass(char nClass, char nSubclass, CDerivedStats& cdsOld, CDerivedStats& cdsNew, int nMinRoll, int nDivisor) {
	if (0) IECString("DETOUR_CRuleTables::DETOUR_CalculateNewHPSubclass");

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
	if (0) IECString("DETOUR_CRuleTables::DETOUR_GetMageSpellRef");

	ResRef rSpell;
	int nMaxSpells = 50;
	
	if (nSpellLevel <= 0 || nSpellLevel > 9) {
		LPCTSTR lpsz = "DETOUR_CRuleTables::DETOUR_GetMageSpellRef(): Invalid spell level %d\r\n";
		L.timestamp();
		L.append(lpsz, 1, nSpellLevel);
		console.write(lpsz, 1, nSpellLevel);

		return rSpell;
	}

	if (pGameOptionsEx->bEngineExternMageSpellsCap) {
		//FIX_ME - do not use itoa
		char szCol[2] = {0};
		itoa(nSpellLevel, szCol, 10);
		IECString sCol(szCol);
		IECString sRow("MAGE");
		IECString sMax(g_pChitin->pGame->SPELLS.GetValue(sCol, sRow));

		if (nSpellLevel == 9 && nIndex >= 99) {
			nMaxSpells = min(99, atoi((LPCTSTR)sMax) - 100);

			nSpellLevel = 0;
			nIndex -= 100;

			//a bit of hackery for index 99
			if (nIndex == -1 && nIndex < nMaxSpells) {
				char szSpell[8] = {0};
				sprintf_s(szSpell, 8, "SPWI%d%02d", nSpellLevel, nIndex + 1);
				rSpell = szSpell;
			}

			//safety for index 199+
			if (nIndex >= 99) {
				return pGameOptionsEx->bUserExternMageSpellHiding ? CRuleTables_TryHideSpell(rSpell): rSpell;
			}
		} else {
			//spell levels 1-8, and level 9 with normal nMaxSpells
			nMaxSpells = min(99, atoi((LPCTSTR)sMax));
		}
	}

	if (nIndex >= 0 && nIndex < nMaxSpells) {
		char szSpell[8] = {0};
		sprintf_s(szSpell, 8, "SPWI%d%02d", nSpellLevel, nIndex + 1);
		rSpell = szSpell;
	}

	return pGameOptionsEx->bUserExternMageSpellHiding ? CRuleTables_TryHideSpell(rSpell): rSpell;
}

int DETOUR_CRuleTables::DETOUR_GetWeapProfMax(char nClassId, char nClassPrimary, char nClassSecondary, BOOL bTwoClasses, int nWeapProfId, unsigned int dwKit) {
	DWORD Eip;
	GetEip(Eip);

	if (0) IECString("DETOUR_CRuleTables::DETOUR_GetWeapProfMax");

	int dwWeapProfMax = (this->*Tramp_CRuleTables_GetWeapProfMax)(nClassId, nClassPrimary, nClassSecondary, bTwoClasses, nWeapProfId, dwKit);
	int dwClassProfsMax = 0;

	if (Eip == 0x6DAEC1 || //CScreenRecord::DualClassProficiencyPanelOnLoad()
		Eip == 0x6DC79A || //CScreenRecord::LevelUpPanelOnLoad()
		Eip == 0x6DC80C || //CScreenRecord::LevelUpPanelOnLoad()
		Eip == 0x6DFAFE || //CScreenRecord::LevelUpPanelOnLoad()
		Eip == 0x6E2196 || //CScreenRecord::DualClassProficiencyPanelOnUpdate()
		Eip == 0x6E28BE || //CScreenRecord::LevelUpPanelOnUpdate()
		Eip == 0x6F082C || //CScreenRecord::DualClass()
		Eip == 0x6F86E9 || //CUIButtonRecordLevelUpProficiency::UpdateCharacter()
		Eip == 0x6FD498) //CUIButtonRecordDualClassProficiency::UpdateCharacter()
		dwClassProfsMax = g_pChitin->pCharacter->dwProfsMax;

	if (Eip == 0x71D9B7 || //CScreenCharGen::ProficienciesPanelOnLoad()
		Eip == 0x71FAC2 || //CScreenCharGen::ProficienciesPanelOnUpdate()
		Eip == 0x71FB11 || //CScreenCharGen::ProficienciesPanelOnUpdate()
		Eip == 0x7305F5 || //CUIButtonCharGenProficiency::UpdateCharacter()
		Eip == 0x730649) //CUIButtonCharGenProficiency::UpdateCharacter()
		dwClassProfsMax = g_pChitin->pCreateChar->dwProfsMax;

	if (dwClassProfsMax) {
		return dwClassProfsMax < dwWeapProfMax ? dwClassProfsMax : dwWeapProfMax;
	} else {
		return dwWeapProfMax;
	}
}

BOOL DETOUR_CRuleTables::DETOUR_IsMageSchoolAllowed(unsigned int dwKit, unsigned char nRace) {
	if (0) IECString("DETOUR_CRuleTables::DETOUR_IsMageSchoolAllowed");

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
	if (0) IECString("DETOUR_CRuleTables::DETOUR_GetMageSpellRefAutoPick");

	ResRef rSpell = (this->*Tramp_CRuleTables_GetMageSpellRefAutoPick)(nSpellLevel, nIndex);
	return CRuleTables_TryHideSpell(rSpell);
}

//CMoveAreasList
void DETOUR_CMoveAreasList::DETOUR_MoveAllTo(CArea& area) { 
	if (0) IECString("DETOUR_CMoveAreasList::DETOUR_MoveAllTo");

	ITEM_EFFECT* pItmEff = new ITEM_EFFECT;
	CEffect::CreateItemEffect(*pItmEff, CEFFECT_OPCODE_MOVE_TO_AREA);
	IECPtrList cp;

	POSITION pos_i = GetHeadPosition();
	while (pos_i != NULL) {
		MoveAreasElement* pElement = (MoveAreasElement*)GetNext(pos_i);
		MoveAreasComparator* pComp = new MoveAreasComparator;

		pComp->rArea = pElement->rArea;
		pComp->ptDest = pElement->ptDest;

		pItmEff->param2 = pElement->cOrient;
		pItmEff->param1 = pElement->nDelay;
		pElement->rArea.Copy(pItmEff->resource);
		pItmEff->timing = 1;
		POINT pt;
		pt.x = -1;
		pt.y = -1;
		CEffect* pEff = &CEffect::CreateEffect(*pItmEff, pElement->ptDest, pElement->eCre, pt, -1);

		CInfGame* pGame = g_pChitin->pGame;
		CCreatureObject* pCre = NULL;
		char threadVal;
		do {
			threadVal = pGame->m_GameObjectArrayHandler.GetGameObjectDeny(pElement->eCre, THREAD_ASYNCH, &pCre, INFINITE);
		} while (threadVal == OBJECT_SHARING || threadVal == OBJECT_DENYING);
		if (threadVal != OBJECT_SUCCESS) {
			delete pComp;
		} else {
			pComp->sCreLongName = pCre->GetLongName();

			bool bFoundIdentical = false;
			POSITION pos_j = cp.GetHeadPosition();
			while (pos_j != NULL) {
				MoveAreasComparator* pCompElement = (MoveAreasComparator*)cp.GetNext(pos_j);
				if (pCompElement->ptDest.x == pComp->ptDest.x &&
					pCompElement->ptDest.y == pComp->ptDest.y &&
					pCompElement->rArea == pComp->rArea &&
					pCompElement->sCreLongName.Compare(pComp->sCreLongName) == 0) {
					delete pComp;
					pGame->m_GameObjectArrayHandler.FreeGameObjectDeny(pElement->eCre, THREAD_ASYNCH, INFINITE);
					bFoundIdentical = true;
					break; //Bioware forgot to break this loop
				}
			}

			if (!bFoundIdentical) {
				cp.AddTail(pComp);
				pCre->m_BaseStats.dwFlags |= 0x4000; //bit14
				area.m_ObjectsToMarshal.AddTail((void*)pCre->e);
				pCre->ApplyEffect(*pEff, true, TRUE, FALSE);
				pGame->m_GameObjectArrayHandler.FreeGameObjectDeny(pElement->eCre, THREAD_ASYNCH, INFINITE);
			}
		}
	}

	POSITION pos_k = cp.GetHeadPosition();
	while (pos_k != NULL) {
		MoveAreasComparator* pElement = (MoveAreasComparator*)cp.GetNext(pos_k);
		delete pElement;
	}
	cp.RemoveAll();
	
	delete pItmEff;
	pItmEff = NULL;

	return;
}

//CInfGame
int DETOUR_CInfGame::DETOUR_GetNumOfItemInBag(ResRef& rBag, ResRef& rItem, BOOL bIdentifiedOnly) {
	if (0) IECString("DETOUR_CInfGame::DETOUR_GetNumOfItemInBag");

	if (g_pChitin->cNetwork.bSessionOpen) {
		BOOL bRequested = FALSE;
		CStore store;

		if (!g_pChitin->cNetwork.bSessionHosting) {
			store.Unmarshal(rBag);
			BOOL bStoreValid = store.bUnmarshaled && store.m_header == "STORV1.0" ? TRUE : FALSE;
			if (bStoreValid == FALSE) {
				bool bFailed = !g_pChitin->BaldurMessageHandler.RequestHostFile(rBag.FormatToString(), CRES_TYPE_STO, TRUE, TRUE, true);
				if (bFailed) {
					g_pChitin->cNetwork.CloseSession(true);
					return 0;
				} else {
					store.Unmarshal(rBag);
					bRequested = TRUE;
				}
			}
		} else {
			DemandServerStore(rBag, TRUE);
			store.Unmarshal(rBag);
		}

		int nItemCount = 0;
		POSITION pos = store.m_items.GetHeadPosition();
		while (pos != NULL) {
			StoFileItem* pItem = (StoFileItem*)store.m_items.GetNext(pos);
			if (pItem) {
				if (pItem->m_rName == rItem) {
					if (bIdentifiedOnly) {
						if (pItem->dwFlags & CITEMFLAG_IDENTIFIED) {
							int nAdd = pItem->m_bInfinite ? 1 : pItem->m_nNumInStock;
							nItemCount += nAdd;
						}
					} else {
						int nAdd = pItem->m_bInfinite ? 1 : pItem->m_nNumInStock;
						nItemCount += nAdd;
					}
				}
			}
		}

		if (g_pChitin->cNetwork.bSessionHosting) {
			g_pChitin->pGame->ReleaseServerStore(store.m_filename);
			return nItemCount;
		} else {
			if (bRequested) {
				CMessageHostReleaseServerStore* pMsg = IENew CMessageHostReleaseServerStore();
				pMsg->rStoreName = store.m_filename;
				g_pChitin->messages.Send(*pMsg, FALSE);
			}
			return nItemCount;
		}

	} else {
		CStore store(rBag);
		int nItemCount = 0;
		POSITION pos = store.m_items.GetHeadPosition();

		while (pos != NULL) {
			StoFileItem* pItem = (StoFileItem*)store.m_items.GetNext(pos);
			if (pItem) {
				if (pItem->m_rName == rItem) {
					if (bIdentifiedOnly) {
						if (pItem->dwFlags & CITEMFLAG_IDENTIFIED) {
							int nAdd = pItem->m_bInfinite ? 1 : pItem->m_nNumInStock;
							nItemCount += nAdd;
						}
					} else {
						int nAdd = pItem->m_bInfinite ? 1 : pItem->m_nNumInStock;
						nItemCount += nAdd;
					}
				}
			}
		}

		return nItemCount;
	}
}

void DETOUR_CInfGame::DETOUR_SetLoseCutscene() {
	DWORD Eip;
	GetEip(Eip);

	if (0) IECString("DETOUR_CInfGame::DETOUR_SetLoseCutscene");

	if (Eip == 0x5092EB || //CEffectInstantDeath::ApplyEffect()
		Eip == 0x50935F || //CEffectInstantDeath::ApplyEffect()
		Eip == 0x5277E6 || //CEffectPetrification::ApplyEffect()
		Eip == 0x527859 || //CEffectPetrification::ApplyEffect()
		Eip == 0x531E37 || //CEffectImprisonment::ApplyEffect()
		Eip == 0x7C612B || //CScreenWorld::Init()?
		Eip == 0x7D37B8) { //CScreenWorld::Update()
		return;
	}
	
	return (this->*Tramp_CInfGame_SetLoseCutscene)();
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

	STRREF strref;

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

		sscanf_s((LPCTSTR)sStrRef, "%d", &strref);
		return strref;
	} else {
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
	IECString sCreName(cre.name);
	POINT loc = {0, 0};
	ResRef rSlotItm = cre.m_Inventory.items[wSlot] ? cre.m_Inventory.items[wSlot]->m_itm.name : "";
	ResRef rGrabItm = &itmGrabbed ? itmGrabbed.m_itm.name : "";

	IECString sItm;
	IECString sUser;
	int dwFlags = 0;

	if (pRuleEx->m_ItemCreExclude.m_2da.bLoaded) {
		for (int row = 0; row < pRuleEx->m_ItemCreExclude.nRows; row++) {
			sItm = pRuleEx->m_ItemCreExclude.GetRowName(row);
			
			if (sItm.CompareNoCase(rSlotItm) &&	sItm.CompareNoCase(rGrabItm)) continue;

			loc.y = row;

			loc.x = ITEM_USE_COL_USER;
			sUser = pRuleEx->m_ItemCreExclude.GetValue(loc);

			loc.x = ITEM_USE_COL_FLAG;
			dwFlags = atoi((LPCTSTR)pRuleEx->m_ItemCreExclude.GetValue(loc));

			if (!sUser.CompareNoCase((LPCTSTR)sCreName) &&
				!sItm.CompareNoCase(rSlotItm) &&
				(dwFlags & (ITEM_USE_FLAG_NO_PICKUP | ITEM_USE_FLAG_NO_PICKUP_E))
			) {
				loc.x = (dwFlags & ITEM_USE_FLAG_NO_PICKUP) ? ITEM_USE_COL_STRREF1 : ITEM_USE_COL_STRREF8;
				STRREF strref = atoi((LPCTSTR)pRuleEx->m_ItemCreExclude.GetValue(loc));
				*pStrRef = strref;
					
				if (pGameOptionsEx->bDebugVerbose) {
					LPCTSTR lpsz = "CRuleTables_DoesEquipSlotPassCreExclude(): Found %s restricted on %s with FLAG_NO_PICKUP[_E]\r\n";
					L.timestamp();
					L.append(lpsz, 2, (LPCTSTR)sItm, (LPCTSTR)sUser);
					console.write(lpsz, 2, (LPCTSTR)sItm, (LPCTSTR)sUser);
				}
					
				bPass = FALSE;
				break;
			}

			if (sUser.CompareNoCase((LPCTSTR)sCreName) &&
				!sItm.CompareNoCase(rGrabItm) &&
				(dwFlags & ITEM_USE_FLAG_ONLY_EQUIP)
			) {
				loc.x = ITEM_USE_COL_STRREF2;
				STRREF strref = atoi((LPCTSTR)pRuleEx->m_ItemCreExclude.GetValue(loc));
				*pStrRef = strref;
				
				if (pGameOptionsEx->bDebugVerbose) {
					LPCTSTR lpsz = "CRuleTables_DoesEquipSlotPassCreExclude(): Found %s restricted on %s with FLAG_ONLY_EQUIP\r\n";
					L.timestamp();
					L.append(lpsz, 2, (LPCTSTR)sItm, (LPCTSTR)sUser);
					console.write(lpsz, 2, (LPCTSTR)sItm, (LPCTSTR)sUser);
				}
				
				bPass = FALSE;
				break;
			}

			if (!sUser.CompareNoCase((LPCTSTR)sCreName) &&
				!sItm.CompareNoCase(rGrabItm) &&
				(dwFlags & ITEM_USE_FLAG_NO_DROP_E)
			) {
				loc.x = ITEM_USE_COL_STRREF32;
				STRREF strref = atoi((LPCTSTR)pRuleEx->m_ItemCreExclude.GetValue(loc));
				*pStrRef = strref;

				if (pGameOptionsEx->bDebugVerbose) {
					LPCTSTR lpsz = "CRuleTables_DoesEquipSlotPassCreExclude(): Found %s restricted on %s with FLAG_NO_DROP_E\r\n";
					L.timestamp();
					L.append(lpsz, 2, (LPCTSTR)sItm, (LPCTSTR)sUser);
					console.write(lpsz, 2, (LPCTSTR)sItm, (LPCTSTR)sUser);
				}

				bPass = FALSE;
				break;
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
	IECString sCreName(cre.name);
	POINT loc = {0, 0};
	ResRef rSlotItm = cre.m_Inventory.items[wSlot] ? cre.m_Inventory.items[wSlot]->m_itm.name : "";
	ResRef rGrabItm = &itmGrabbed ? itmGrabbed.m_itm.name : "";

	IECString sItm;
	IECString sUser;
	int dwFlags = 0;

	if (pRuleEx->m_ItemCreExclude.m_2da.bLoaded) {
		for (int row = 0; row < pRuleEx->m_ItemCreExclude.nRows; row++) {
			sItm = pRuleEx->m_ItemCreExclude.GetRowName(row);
			
			if (sItm.CompareNoCase(rSlotItm) &&	sItm.CompareNoCase(rGrabItm)) continue;

			loc.y = row;

			loc.x = ITEM_USE_COL_USER;
			sUser = pRuleEx->m_ItemCreExclude.GetValue(loc);

			loc.x = ITEM_USE_COL_FLAG;
			dwFlags = atoi((LPCTSTR)pRuleEx->m_ItemCreExclude.GetValue(loc));
			
			if (!sUser.CompareNoCase((LPCTSTR)sCreName) &&
				!sItm.CompareNoCase(rSlotItm) &&
				(dwFlags & (ITEM_USE_FLAG_NO_PICKUP | ITEM_USE_FLAG_NO_PICKUP_I))
			) {
				loc.x = (dwFlags & ITEM_USE_FLAG_NO_PICKUP) ? ITEM_USE_COL_STRREF1 : ITEM_USE_COL_STRREF16;
				STRREF strref = atoi((LPCTSTR)pRuleEx->m_ItemCreExclude.GetValue(loc));
				*pStrRef = strref;

				if (pGameOptionsEx->bDebugVerbose) {
					LPCTSTR lpsz = "CRuleTables_DoesEquipSlotPassCreExclude(): Found %s restricted on %s with FLAG_NO_PICKUP[_I]\r\n";
					L.timestamp();
					L.append(lpsz, 2, (LPCTSTR)sItm, (LPCTSTR)sUser);
					console.write(lpsz, 2, (LPCTSTR)sItm, (LPCTSTR)sUser);
				}

				bPass = FALSE;
				break;
			}

			if (!sUser.CompareNoCase((LPCTSTR)sCreName) &&
				!sItm.CompareNoCase(rGrabItm) &&
				(dwFlags & ITEM_USE_FLAG_NO_DROP_I)
			) {
				loc.x = ITEM_USE_COL_STRREF64;
				STRREF strref = atoi((LPCTSTR)pRuleEx->m_ItemCreExclude.GetValue(loc));
				*pStrRef = strref;

				if (pGameOptionsEx->bDebugVerbose) {
					LPCTSTR lpsz = "CRuleTables_DoesEquipSlotPassCreExclude(): Found %s restricted on %s with FLAG_NO_DROP_I\r\n";
					L.timestamp();
					L.append(lpsz, 2, (LPCTSTR)sItm, (LPCTSTR)sUser);
					console.write(lpsz, 2, (LPCTSTR)sItm, (LPCTSTR)sUser);
				}

				bPass = FALSE;
				break;
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
	return nWeight > (nWeightAllowance * pRuleEx->m_nEncumbranceLowThreshold / 100);
}

BOOL __stdcall CRuleTables_IsHighEncumbrance(unsigned int nWeight, unsigned int nWeightAllowance) {
	if (pRuleEx->m_nEncumbranceHighThreshold == 0) return FALSE;
	return nWeight > (nWeightAllowance * pRuleEx->m_nEncumbranceHighThreshold / 100);
}

int __stdcall CRuleTables_GetWeightAllowance(CDerivedStats& cds) {
	int nWeightAllowanceStr;
	int nWeightAllowanceStrEx;
	int nWeightAllowanceMod;

	short nCol = 3; //WEIGHT_ALLOWANCE
	short nRow = cds.strength;
	IECString sWeightAllowanceStr;
	if (nCol < g_pChitin->pGame->STRMOD.nCols &&
		nRow < g_pChitin->pGame->STRMOD.nRows &&
		nCol >= 0 &&
		nRow >= 0) {
		sWeightAllowanceStr = *((g_pChitin->pGame->STRMOD.pDataArray) + (g_pChitin->pGame->STRMOD.nCols * nRow + nCol));
	} else {
		sWeightAllowanceStr = g_pChitin->pGame->STRMOD.defaultVal;
	}
	sscanf_s((LPCTSTR)sWeightAllowanceStr, "%d", &nWeightAllowanceStr);

	nCol = 3; //WEIGHT_ALLOWANCE
	nRow = cds.strengthEx; 
	IECString sWeightAllowanceStrEx;
	if (nCol < g_pChitin->pGame->STRMODEX.nCols &&
		nRow < g_pChitin->pGame->STRMODEX.nRows &&
		nCol >= 0 &&
		nRow >= 0) {
		sWeightAllowanceStrEx = *((g_pChitin->pGame->STRMODEX.pDataArray) + (g_pChitin->pGame->STRMODEX.nCols * nRow + nCol));
	} else {
		sWeightAllowanceStrEx = g_pChitin->pGame->STRMODEX.defaultVal;
	}
	sscanf_s((LPCTSTR)sWeightAllowanceStrEx, "%d", &nWeightAllowanceStrEx);

	return max(0, nWeightAllowanceStr + nWeightAllowanceStrEx + cds.GetStat(CDERIVEDSTATSEX_BASE + CDERIVEDSTATSEX_WEIGHTALLOWANCEMOD));
}