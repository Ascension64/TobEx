#include "EngineChargen.h"

#include <cassert>

#include "EngineCommon.h"
#include "UserChargenMageSpell.h"
#include "UserChargenKit.h"
#include "UserCommon.h"
#include "chitin.h"
#include "tlkcore.h"
#include "uibutton.h"
#include "console.h"
#include "log.h"
#include "InfGameCommon.h"

void (CCharGen::*Tramp_CCharGen_KitPanelOnLoad)(CPanel&, CCreatureObject&) =
	SetFP(static_cast<void (CCharGen::*)(CPanel&, CCreatureObject&)>	(&CCharGen::KitPanelOnLoad),			0x71A081);
void (CCharGen::*Tramp_CCharGen_MageBookPanelOnLoad)(CPanel&, CCreatureObject&) =
	SetFP(static_cast<void (CCharGen::*)(CPanel&, CCreatureObject&)>	(&CCharGen::MageBookPanelOnLoad),		0x71B220);
void (CCharGen::*Tramp_CCharGen_KitPanelOnUpdate)(CPanel&, CCreatureObject&) =
	SetFP(static_cast<void (CCharGen::*)(CPanel&, CCreatureObject&)>	(&CCharGen::KitPanelOnUpdate),			0x71E3A5);
void (CCharGen::*Tramp_CCharGen_MageBookPanelOnUpdate)(CPanel&, CCreatureObject&) =
	SetFP(static_cast<void (CCharGen::*)(CPanel&, CCreatureObject&)>	(&CCharGen::MageBookPanelOnUpdate),		0x720425);
void (CCharGen::*Tramp_CCharGen_ClassPanelOnUpdate)(CPanel&, CCreatureObject&) =
	SetFP(static_cast<void (CCharGen::*)(CPanel&, CCreatureObject&)>	(&CCharGen::ClassPanelOnUpdate),		0x720B4B);
void (CCharGen::*Tramp_CCharGen_MulticlassPanelOnUpdate)(CPanel&, CCreatureObject&) =
	SetFP(static_cast<void (CCharGen::*)(CPanel&, CCreatureObject&)>	(&CCharGen::MulticlassPanelOnUpdate),	0x721518);
void (CCharGen::*Tramp_CCharGen_MageSchoolPanelOnUpdate)(CPanel&, CCreatureObject&) =
	SetFP(static_cast<void (CCharGen::*)(CPanel&, CCreatureObject&)>	(&CCharGen::MageSchoolPanelOnUpdate),	0x721BA6);
void (CCharGen::*Tramp_CCharGen_InitSoundset)(CCreatureObject&) =
	SetFP(static_cast<void (CCharGen::*)(CCreatureObject&)>				(&CCharGen::InitSoundset),				0x724E37);

void DETOUR_CCharGen::DETOUR_KitPanelOnLoad(CPanel& panel, CCreatureObject& cre) {
	CUIScrollBarChargenKit& scroll = (CUIScrollBarChargenKit&)panel.GetUIControl(15);
	if (&scroll == NULL) {
		LPCTSTR lpsz = "DETOUR_KitPanelOnLoad(): Kit scroll bar not found. Did you install the required WeiDU component?\r\n";
		console.write(lpsz);
		L.timestamp();
		L.append(lpsz);
		return (this->*Tramp_CCharGen_KitPanelOnLoad)(panel, cre);
	}

	//clear values
	scroll.nCurrentValue = 0;
	scroll.nValues = 0;
	scroll.nRows = 0;

	(this->*Tramp_CCharGen_KitPanelOnLoad)(panel, cre);

	scroll.UpdateKnobPosition(scroll.nCurrentValue, scroll.nValues, scroll.nRows);

	return;
}

void DETOUR_CCharGen::DETOUR_MageBookPanelOnLoad(CPanel& panel, CCreatureObject& cre) {
	CUIScrollBarChargenMageSpell& scroll = (CUIScrollBarChargenMageSpell&)panel.GetUIControl(31);
	if (&scroll == NULL) {
		LPCTSTR lpsz = "DETOUR_MageBookPanelOnLoad(): Chargen mage spell selection scroll bar not found. Did you install the required WeiDU component?\r\n";
		console.write(lpsz);
		L.timestamp();
		L.append(lpsz);
		return (this->*Tramp_CCharGen_MageBookPanelOnLoad)(panel, cre);
	}

	//clear values
	scroll.nCurrentValue = 0;
	scroll.nValues = 0;
	scroll.nRows = 0;
	scroll.cplTempSpells.RemoveAll();

	(this->*Tramp_CCharGen_MageBookPanelOnLoad)(panel, cre);

	scroll.nValues = MageBookSpells.GetCount() / 6;
	if (scroll.nValues % 6) scroll.nValues++;
	scroll.nRows = 4;

	scroll.UpdateKnobPosition(scroll.nCurrentValue, scroll.nValues, scroll.nRows);

	return;
}

void DETOUR_CCharGen::DETOUR_KitPanelOnUpdate(CPanel& panel, CCreatureObject& cre) {
	CUIScrollBar& scroll = (CUIScrollBar&)panel.GetUIControl(6);
	pScrollActive = &scroll;
	Object& o = cre.IdsCopy1;

	CUIScrollBarChargenKit& scrollKit = (CUIScrollBarChargenKit&)panel.GetUIControl(15);

	CUICheckButtonChargenKit& option1 = (CUICheckButtonChargenKit&)panel.GetUIControl(1);
	CUICheckButtonChargenKit& option2 = (CUICheckButtonChargenKit&)panel.GetUIControl(2);
	CUICheckButtonChargenKit& option3 = (CUICheckButtonChargenKit&)panel.GetUIControl(3);
	CUICheckButtonChargenKit& option4 = (CUICheckButtonChargenKit&)panel.GetUIControl(4);
	CUICheckButtonChargenKit& option5 = (CUICheckButtonChargenKit&)panel.GetUIControl(9);
	CUICheckButtonChargenKit& option6 = (CUICheckButtonChargenKit&)panel.GetUIControl(10);
	CUICheckButtonChargenKit& option7 = (CUICheckButtonChargenKit&)panel.GetUIControl(11);
	CUICheckButtonChargenKit& option8 = (CUICheckButtonChargenKit&)panel.GetUIControl(12);
	CUICheckButtonChargenKit& option9 = (CUICheckButtonChargenKit&)panel.GetUIControl(13);
	CUICheckButtonChargenKit& option10 = (CUICheckButtonChargenKit&)panel.GetUIControl(14);
	CUICheckButtonChargenKit& option11 = (CUICheckButtonChargenKit&)panel.GetUIControl(16);

	CCharGen* pCreateChar = g_pChitin->pCreateChar;
	CInfGame* pGame = g_pChitin->pGame;

	assert(&option1 != NULL);
	assert(&option2 != NULL);
	assert(&option3 != NULL);
	assert(&option4 != NULL);
	assert(&option5 != NULL);
	assert(&option6 != NULL);
	assert(&option7 != NULL);
	assert(&option8 != NULL);
	assert(&option9 != NULL);
	assert(&option10 != NULL);
	assert(pCreateChar != NULL);
	assert(pGame != NULL);

	if (&scrollKit == NULL ||
		&option11 == NULL) {
		LPCTSTR lpsz = "DETOUR_KitPanelOnUpdate(): Kit selection scroll bar or button 11 not found. Did you install the required WeiDU component?\r\n";
		console.write(lpsz);
		L.timestamp();
		L.append(lpsz);
		return (this->*Tramp_CCharGen_KitPanelOnUpdate)(panel, cre);
	}

	IECString sClass, sRace, sKitName, sAlignment, sRowName, sKitFile;

	if (m_class) {
		sClass = pGame->GetClassString(m_class, TRUECLASS);
	} else {
		sClass = pGame->GetClassString(o.GetClass(), TRUECLASS);
	}

	sRace = pGame->GetRaceString(o.Race);
	sKitFile = pGame->KITTABLE.GetValue(sRace, sClass);

	if (Kit_Class_Race.m_2da.name != sKitFile) {
		Kit_Class_Race.LoadTable(ResRef(sKitFile));
	}

	for (int row = 0; row < Kit_Class_Race.nRows; row++) {

		int col = 0;

		IECString sKit;
		if (col < g_pChitin->pCreateChar->Kit_Class_Race.nCols &&
			row < g_pChitin->pCreateChar->Kit_Class_Race.nRows &&
			col >= 0 &&
			row >= 0) {
			sKit = *((g_pChitin->pCreateChar->Kit_Class_Race.pDataArray) + (g_pChitin->pCreateChar->Kit_Class_Race.nCols * row + col));
		} else {
			sKit = g_pChitin->pCreateChar->Kit_Class_Race.defaultVal;
		}
		int nKitId;
		sscanf_s((LPCTSTR)sKit, "%d", &nKitId);

		if (nKitId == 0) { //true class
			if (m_class) {
				pGame->GetDetailedClassString(m_class, TRUECLASS, 0, sKitName, cre);
			} else {
				pGame->GetDetailedClassString(o.GetClass(), TRUECLASS, 0, sKitName, cre);
			}
		} else {
			int col = 1;

			IECString sKitLowerStrRef;
			if (col < g_pChitin->pGame->KITLIST.nCols &&
				nKitId < g_pChitin->pGame->KITLIST.nRows &&
				col >= 0 &&
				nKitId >= 0) {
				sKitLowerStrRef = *((g_pChitin->pGame->KITLIST.pDataArray) + (g_pChitin->pGame->KITLIST.nCols * nKitId + col));
			} else {
				sKitLowerStrRef = g_pChitin->pGame->KITLIST.defaultVal;
			}
			STRREF strrefLower;
			sscanf_s((LPCTSTR)sKitLowerStrRef, "%d", &strrefLower);
			sKitName = GetTlkString(strrefLower);
		}

		switch (row - scrollKit.nCurrentValue) {
		case 0:
			option1.SetText(sKitName);
			break;
		case 1:
			option2.SetText(sKitName);
			break;
		case 2:
			option3.SetText(sKitName);
			break;
		case 3:
			option4.SetText(sKitName);
			break;
		case 4:
			option5.SetText(sKitName);
			break;
		case 5:
			option6.SetText(sKitName);
			break;
		case 6:
			option7.SetText(sKitName);
			break;
		case 7:
			option8.SetText(sKitName);
			break;
		case 8:
			option9.SetText(sKitName);
			break;
		case 9:
			option10.SetText(sKitName);
			break;
		case 10:
			option11.SetText(sKitName);
			break;
		}

	} //for (row)

	for (int index = 0; index < 11; index++) {
		CUICheckButton* pButton;
		switch (index) {
		case 0:
			pButton = &option1;
			break;
		case 1:
			pButton = &option2;
			break;
		case 2:
			pButton = &option3;
			break;
		case 3:
			pButton = &option4;
			break;
		case 4:
			pButton = &option5;
			break;
		case 5:
			pButton = &option6;
			break;
		case 6:
			pButton = &option7;
			break;
		case 7:
			pButton = &option8;
			break;
		case 8:
			pButton = &option9;
			break;
		case 9:
			pButton = &option10;
			break;
		case 10:
			pButton = &option11;
			break;
		}

		index += scrollKit.nCurrentValue;

		BOOL bKitAllowedByAlignment = FALSE;
		BOOL bAlignmentChecked = FALSE;
		int nKitId = 0;
		if ((index < Kit_Class_Race.nRows) && (charType == 5)) {
			sAlignment = pGame->GetAlignmentString(o.Alignment);

			int col = 0;

			IECString sKit;
			if (col < g_pChitin->pCreateChar->Kit_Class_Race.nCols &&
				index < g_pChitin->pCreateChar->Kit_Class_Race.nRows &&
				col >= 0 &&
				index >= 0) {
				sKit = *((g_pChitin->pCreateChar->Kit_Class_Race.pDataArray) + (g_pChitin->pCreateChar->Kit_Class_Race.nCols * index + col));
			} else {
				sKit = g_pChitin->pCreateChar->Kit_Class_Race.defaultVal;
			}
			sscanf_s((LPCTSTR)sKit, "%d", &nKitId);

			col = 0;

			if (col < g_pChitin->pGame->KITLIST.nCols &&
				nKitId < g_pChitin->pGame->KITLIST.nRows &&
				col >= 0 &&
				nKitId >= 0) {
				sRowName = *((g_pChitin->pGame->KITLIST.pDataArray) + (g_pChitin->pGame->KITLIST.nCols * nKitId + col));
			} else {
				sRowName = g_pChitin->pGame->KITLIST.defaultVal;
			}

			IECString sKitAllowedByAlignment = pGame->ALIGNMNT.GetValue(sAlignment, sRowName);
			sscanf_s((LPCTSTR)sKitAllowedByAlignment, "%d", &bKitAllowedByAlignment);
			bAlignmentChecked = TRUE;
		}

		if (index < Kit_Class_Race.nRows) {
			pButton->SetEnabled(TRUE);
			if (bAlignmentChecked && nKitId) { //not true class
				if (bAlignmentChecked && bKitAllowedByAlignment) {
					pButton->SetActive(TRUE);
				} else {
					pButton->SetActive(FALSE);
				}
			} else {
				pButton->SetActive(TRUE);
			}

		} else {
			pButton->SetEnabled(FALSE);
			pButton->SetActive(FALSE);
			pButton->SetVisible(FALSE);
		}

		index -= scrollKit.nCurrentValue;

	} //for (index)

	DWORD dwKit = cre.m_BaseStats.kit[1] | (cre.m_BaseStats.kit[0] << 16);

	option1.SetToggleState(false);
	option2.SetToggleState(false);
	option3.SetToggleState(false);
	option4.SetToggleState(false);
	option5.SetToggleState(false);
	option6.SetToggleState(false);
	option7.SetToggleState(false);
	option8.SetToggleState(false);
	option9.SetToggleState(false);
	option10.SetToggleState(false);
	option11.SetToggleState(false);

	if ((dwKit & TRUECLASS) && (dwKit & 0xBFFF)) { //has a kit
		DWORD dwKitOnly = dwKit & 0xBFFF;

		for (int row = 0; row < Kit_Class_Race.nRows; row++ ) {
			int col = 0;

			IECString sKit;
			if (col < g_pChitin->pCreateChar->Kit_Class_Race.nCols &&
				row < g_pChitin->pCreateChar->Kit_Class_Race.nRows &&
				col >= 0 &&
				row >= 0) {
				sKit = *((g_pChitin->pCreateChar->Kit_Class_Race.pDataArray) + (g_pChitin->pCreateChar->Kit_Class_Race.nCols * row + col));
			} else {
				sKit = g_pChitin->pCreateChar->Kit_Class_Race.defaultVal;
			}
			int nKitId;
			sscanf_s((LPCTSTR)sKit, "%d", &nKitId);

			if (nKitId == dwKitOnly) {
			switch (row - scrollKit.nCurrentValue) {
				case 0:
					option1.SetToggleState(TRUE);
					break;
				case 1:
					option2.SetToggleState(TRUE);
					break;
				case 2:
					option3.SetToggleState(TRUE);
					break;
				case 3:
					option4.SetToggleState(TRUE);
					break;
				case 4:
					option5.SetToggleState(TRUE);
					break;
				case 5:
					option6.SetToggleState(TRUE);
					break;
				case 6:
					option7.SetToggleState(TRUE);
					break;
				case 7:
					option8.SetToggleState(TRUE);
					break;
				case 8:
					option9.SetToggleState(TRUE);
					break;
				case 9:
					option10.SetToggleState(TRUE);
					break;
				case 10:
					option11.SetToggleState(TRUE);
					break;
				}
			}
		} //for
	} else {
		switch (dwKit) {
			case TRUECLASS:
				switch (scrollKit.nCurrentValue) {
				case 0:
					option1.SetToggleState(TRUE);
					break;
				default:
					break;
				}
				break;
			case BERSERKER:
			case CAVALIER:
			case FERALAN:
			case ASSASIN:
			case BLADE:
			case GODTALOS:
			case TOTEMIC:
				switch (scrollKit.nCurrentValue) {
				case 0:
					option2.SetToggleState(TRUE);
					break;
				case 1:
					option1.SetToggleState(TRUE);
					break;
				default:
					break;
				}
				break;
			case WIZARDSLAYER:
			case INQUISITOR:
			case STALKER:
			case BOUNTYHUNTER:
			case JESTER:
			case GODHELM:
			case SHAPESHIFTER:
				switch (scrollKit.nCurrentValue) {
				case 0:
					option1.SetToggleState(TRUE);
					break;
				case 1:
					option2.SetToggleState(TRUE);
					break;
				case 2:
					option3.SetToggleState(TRUE);
					break;
				default:
					break;
				}
				break;
			case KENSAI:
			case UNDEADHUNTER:
			case BEASTMASTER:
			case SWASHBUCKLER:
			case SKALD:
			case GODLATHANDER:
			case BEASTFRIEND:
				switch (scrollKit.nCurrentValue) {
				case 0:
					option1.SetToggleState(TRUE);
					break;
				case 1:
					option2.SetToggleState(TRUE);
					break;
				case 2:
					option3.SetToggleState(TRUE);
					break;
				case 3:
					option4.SetToggleState(TRUE);
					break;
				default:
					break;
				}
				break;
			default:
				break;
		}
	} //has a kit

	CUIButton& buttonDone = (CUIButton&)panel.GetUIControl(7);
	buttonDone.SetActive(CanContinue(cre));

	scrollKit.nValues = Kit_Class_Race.nRows;
	scrollKit.nRows = 11;

	return;
};

void DETOUR_CCharGen::DETOUR_MageBookPanelOnUpdate(CPanel& panel, CCreatureObject& cre) {
	CUIScrollBarChargenMageSpell& scroll = (CUIScrollBarChargenMageSpell&)panel.GetUIControl(31);
	if (&scroll == NULL) {
		LPCTSTR lpsz = "DETOUR_MageBookPanelOnUpdate(): Chargen mage spell selection scroll bar not found. Did you install the required WeiDU component?\r\n";
		console.write(lpsz);
		L.timestamp();
		L.append(lpsz);
		return (this->*Tramp_CCharGen_MageBookPanelOnUpdate)(panel, cre);
	}

	//Depending on offset in MageBookSpells, transfer spells to/from temporary spell pile
	DWORD nPileCount = scroll.cplTempSpells.GetCount();
	DWORD nSliderCount = 6 * scroll.nCurrentValue;

	if (nSliderCount > nPileCount) {
		int i = nSliderCount - nPileCount;
		while (i) {
			if (MageBookSpells.IsEmpty()) {
				LPCTSTR lpsz = "DETOUR_MageBookPanelOnUpdate(): Mage book is empty\r\n";
				console.write(lpsz);
				L.timestamp();
				L.append(lpsz);
				break;
			}
			scroll.cplTempSpells.AddHead(MageBookSpells.RemoveHead());
			i--;
		}
	}

	if (nSliderCount < nPileCount) {
		int i = nPileCount - nSliderCount;
		while (i) {
			if (scroll.cplTempSpells.IsEmpty()) {
				LPCTSTR lpsz = "DETOUR_MageBookPanelOnUpdate(): Mage spell pile is empty\r\n";
				console.write(lpsz);
				L.timestamp();
				L.append(lpsz);
				break;
			}
			MageBookSpells.AddHead(scroll.cplTempSpells.RemoveHead());
			i--;
		}
	}

	(this->*Tramp_CCharGen_MageBookPanelOnUpdate)(panel, cre);

	//Update on/off status of spell buttons
	for (int i = 2; i <= 25; i++ ) {
		CCreatureObject* pCre = &cre;
		BYTE threadNum = THREAD_ASYNCH;
		BYTE threadVal;
		do {
			threadVal = g_pChitin->pGame->m_GameObjectArrayHandler.GetGameObjectShare(g_pChitin->pCreateChar->eChar, threadNum, &pCre, INFINITE);
		} while (threadVal == OBJECT_SHARING || threadVal == OBJECT_DENYING);

		if (threadVal == OBJECT_SUCCESS) {
			CUICheckButtonChargenMageSpell& control = (CUICheckButtonChargenMageSpell&)panel.GetUIControl(i);
			if (UserCommon_HasKnownSpell(&cre, control.m_rSpell, nCurrentMageBookLevel)) {
				control.bToggle = TRUE;
			} else {
				control.bToggle = FALSE;
			}
			control.SetRedraw();
			g_pChitin->pGame->m_GameObjectArrayHandler.FreeGameObjectShare(g_pChitin->pCreateChar->eChar, threadNum, INFINITE);
		}
	}

	return;
}

void DETOUR_CCharGen::DETOUR_ClassPanelOnUpdate(CPanel& panel, CCreatureObject& cre) {
	if (!pRuleEx->m_ClassRaceReq.m_2da.bLoaded) return (this->*Tramp_CCharGen_ClassPanelOnUpdate)(panel, cre);

	CUIScrollBar& scroll = (CUIScrollBar&)panel.GetUIControl(12);
	pScrollActive = &scroll;
	CInfGame* pGame = g_pChitin->pGame;
	CreFileData& stats = cre.m_BaseStats;
	Object& o = cre.IdsCopy1;
	DWORD dwKit = stats.kit[1] | stats.kit[0] << 16;

	for (int i = 2; i <= 9; i++) {
		CUICheckButtonChargenClass& button = (CUICheckButtonChargenClass&)panel.GetUIControl(i);
		if (button.GetClass() == o.Class) {
			if (o.Class == FIGHTER && dwKit == BARBARIAN) {
				button.SetToggleState(FALSE);
			} else {
				button.SetToggleState(TRUE);
			}
		} else {
			button.SetToggleState(FALSE);
		}

		IECString sRace = pGame->GetRaceString(o.Race);
		IECString sClass = pGame->GetClassString(button.GetClass(), TRUECLASS);
		IECString sAllowed = pRuleEx->m_ClassRaceReq.GetValue(sRace, sClass);
		BOOL bAllowed;
		sscanf_s((LPCTSTR)sAllowed, "%d", &bAllowed);
		button.SetActive(bAllowed);
	}

	for (int i = 15; i <= 17; i++) {
		CUICheckButtonChargenClass& button = (CUICheckButtonChargenClass&)panel.GetUIControl(i);
		if (button.GetClass() == o.Class) {
			if (o.Class == FIGHTER && dwKit != BARBARIAN) {
				button.SetToggleState(FALSE);
			} else {
				button.SetToggleState(TRUE);
			}
		} else {
			button.SetToggleState(FALSE);
		}

		IECString sRace = pGame->GetRaceString(o.Race);
		IECString sClass = pGame->GetClassString(button.GetClass(), TRUECLASS);
		IECString sAllowed = pRuleEx->m_ClassRaceReq.GetValue(sRace, sClass);
		BOOL bAllowed;
		sscanf_s((LPCTSTR)sAllowed, "%d", &bAllowed);
		button.SetActive(bAllowed);
	}

	//CUIButton& buttonMulticlass = (CUIButton&)panel.GetUIControl(10);
	//buttonMulticlass.SetActive((bool)(o.Race - 1));
	CUIButton& buttonDone = (CUIButton&)panel.GetUIControl(0);
	buttonDone.SetActive(CanContinue(cre));

	return;
}

void DETOUR_CCharGen::DETOUR_MulticlassPanelOnUpdate(CPanel& panel, CCreatureObject& cre) {
	if (!pRuleEx->m_ClassRaceReq.m_2da.bLoaded) return (this->*Tramp_CCharGen_MulticlassPanelOnUpdate)(panel, cre);

	CUIScrollBar& scroll = (CUIScrollBar&)panel.GetUIControl(13);
	pScrollActive = &scroll;
	CInfGame* pGame = g_pChitin->pGame;
	Object& o = cre.IdsCopy1;

	for (int i = 2; i <= 11; i++) {
		CUICheckButtonChargenMulticlass& button = (CUICheckButtonChargenMulticlass&)panel.GetUIControl(i);
		button.SetToggleState(button.GetClass() == o.Class);

		IECString sRace = pGame->GetRaceString(o.Race);
		IECString sClass = pGame->GetClassString(button.GetClass(), TRUECLASS);
		IECString sAllowed = pRuleEx->m_ClassRaceReq.GetValue(sRace, sClass);
		BOOL bAllowed;
		sscanf_s((LPCTSTR)sAllowed, "%d", &bAllowed);
		button.SetActive(bAllowed);
	}

	CUIButton& buttonDone = (CUIButton&)panel.GetUIControl(0);
	buttonDone.SetActive(CanContinue(cre));

	return;
}

void DETOUR_CCharGen::DETOUR_MageSchoolPanelOnUpdate(CPanel& panel, CCreatureObject& cre) {
	if (!pRuleEx->m_MageSchoolRaceReq.m_2da.bLoaded) return (this->*Tramp_CCharGen_MageSchoolPanelOnUpdate)(panel, cre);

	CUIScrollBar& scroll = (CUIScrollBar&)panel.GetUIControl(10);
	pScrollActive = &scroll;
	CInfGame* pGame = g_pChitin->pGame;
	CreFileData& stats = cre.m_BaseStats;
	Object& o = cre.IdsCopy1;
	DWORD dwKit = stats.kit[1] | stats.kit[0] << 16;
	BOOL bButtonToggled = FALSE;

	BOOL bMageClass = o.GetClass() == MAGE || o.GetClass() == SORCERER;
	if (!bMageClass) {
		BYTE class1;
		BYTE class2;
		o.GetClasses(&class1, &class2);
		bMageClass = class1 == MAGE || class2 == MAGE;
	}

	for (int i = 2; i <= 9; i++) {
		CUICheckButtonChargenMageSchool& buttonSchool = (CUICheckButtonChargenMageSchool&)panel.GetUIControl(i);
		if (bMageClass &&
			dwKit == buttonSchool.GetKit()) {
			buttonSchool.SetToggleState(TRUE);
			bButtonToggled = TRUE;
		} else {
			buttonSchool.SetToggleState(FALSE);
		}

		buttonSchool.SetActive(pGame->IsMageSchoolAllowed(buttonSchool.GetKit(), o.Race));
	}

	CUICheckButtonChargenMageSchool& buttonWildMage = (CUICheckButtonChargenMageSchool&)panel.GetUIControl(14);
	if (*g_pEnableWildMage) {
		if (bMageClass &&
			dwKit == buttonWildMage.GetKit()) {
			buttonWildMage.SetToggleState(TRUE);
			bButtonToggled = TRUE;
		} else {
			buttonWildMage.SetToggleState(FALSE);
		}
		buttonWildMage.SetActive(pGame->IsMageSchoolAllowed(buttonWildMage.GetKit(), o.Race));
	} else {
		buttonWildMage.SetToggleState(FALSE);
		buttonWildMage.SetActive(FALSE);
		buttonWildMage.SetEnabled(false);
		buttonWildMage.SetVisible(FALSE);
	}

	CUICheckButtonChargenMageSchool& buttonMage = (CUICheckButtonChargenMageSchool&)panel.GetUIControl(13);
	if (bMageClass &&
		dwKit == buttonMage.GetKit()) {
		buttonMage.SetToggleState(TRUE);
		bButtonToggled = TRUE;
	} else {
		buttonMage.SetToggleState(FALSE);
	}
	buttonMage.SetActive(pGame->IsMageSchoolAllowed(buttonMage.GetKit(), o.Race));

	CUIButton& buttonDone = (CUIButton&)panel.GetUIControl(0);
	buttonDone.SetActive(CanContinue(cre) && pGame->IsMageSchoolAllowed(dwKit, o.Race));

	return;
}

void DETOUR_CCharGen::DETOUR_InitSoundset(CCreatureObject& cre) {
	(this->*Tramp_CCharGen_InitSoundset)(cre);
	EngineCommon_ApplySoundset(cre);
	return;
}