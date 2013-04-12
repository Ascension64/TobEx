#include "EngineChargen.h"

#include <cassert>

#include "EngineCommon.h"
#include "UserChargenMageSpell.h"
#include "UserChargenKit.h"
#include "UserCommon.h"
#include "chitin.h"
#include "tlkcore.h"
#include "uibutton.h"
#include "optionsext.h"
#include "InfGameCommon.h"

DefineTrampMemberFunc(void, CScreenCharGen, KitPanelOnLoad, (CPanel& panel, CCreatureObject& cre), KitPanelOnLoad, KitPanelOnLoad, 0x71A081);
DefineTrampMemberFunc(void, CScreenCharGen, MageBookPanelOnLoad, (CPanel& panel, CCreatureObject& cre), MageBookPanelOnLoad, MageBookPanelOnLoad, 0x71B220);
DefineTrampMemberFunc(void, CScreenCharGen, KitPanelOnUpdate, (CPanel& panel, CCreatureObject& cre), KitPanelOnUpdate, KitPanelOnUpdate, 0x71E3A5);
DefineTrampMemberFunc(void, CScreenCharGen, MageBookPanelOnUpdate, (CPanel& panel, CCreatureObject& cre), MageBookPanelOnUpdate, MageBookPanelOnUpdate, 0x720425);
DefineTrampMemberFunc(void, CScreenCharGen, ClassPanelOnUpdate, (CPanel& panel, CCreatureObject& cre), ClassPanelOnUpdate, ClassPanelOnUpdate, 0x720B4B);
DefineTrampMemberFunc(void, CScreenCharGen, MulticlassPanelOnUpdate, (CPanel& panel, CCreatureObject& cre), MulticlassPanelOnUpdate, MulticlassPanelOnUpdate, 0x721518);
DefineTrampMemberFunc(void, CScreenCharGen, MageSchoolPanelOnUpdate, (CPanel& panel, CCreatureObject& cre), MageSchoolPanelOnUpdate, MageSchoolPanelOnUpdate, 0x721BA6);
DefineTrampMemberFunc(void, CScreenCharGen, InitSoundset, (CCreatureObject& cre), InitSoundset, InitSoundset, 0x724E37);

void DETOUR_CScreenCharGen::DETOUR_KitPanelOnLoad(CPanel& panel, CCreatureObject& cre) {
	CUIScrollBarChargenKit& scroll = (CUIScrollBarChargenKit&)panel.GetUIControl(15);
	if (&scroll == NULL) {
		LPCTSTR lpsz = "DETOUR_CScreenCharGen::DETOUR_KitPanelOnLoad(): Kit scroll bar not found\r\n";
		console.write(lpsz);
		L.timestamp();
		L.append(lpsz);
		return (this->*Tramp_CScreenCharGen_KitPanelOnLoad)(panel, cre);
	}

	//clear values
	scroll.nCurrentValue = 0;
	scroll.nValues = 0;
	scroll.nRows = 0;

	(this->*Tramp_CScreenCharGen_KitPanelOnLoad)(panel, cre);

	scroll.UpdateKnobPosition(scroll.nCurrentValue, scroll.nValues, scroll.nRows);

	return;
}

void DETOUR_CScreenCharGen::DETOUR_MageBookPanelOnLoad(CPanel& panel, CCreatureObject& cre) {
	CUIScrollBarChargenMageSpell& scroll = (CUIScrollBarChargenMageSpell&)panel.GetUIControl(31);
	if (&scroll == NULL) {
		LPCTSTR lpsz = "DETOUR_CScreenCharGen::DETOUR_MageBookPanelOnLoad(): Chargen mage spell selection scroll bar not found\r\n";
		console.write(lpsz);
		L.timestamp();
		L.append(lpsz);
		return (this->*Tramp_CScreenCharGen_MageBookPanelOnLoad)(panel, cre);
	}

	//clear values
	scroll.nCurrentValue = 0;
	scroll.nValues = 0;
	scroll.nRows = 0;
	scroll.cplTempSpells.RemoveAll();

	(this->*Tramp_CScreenCharGen_MageBookPanelOnLoad)(panel, cre);

	scroll.nValues = MageBookSpells.GetCount() / 6;
	if (MageBookSpells.GetCount() % 6) scroll.nValues++;
	scroll.nRows = 4;

	if (pGameOptionsEx->GetOption("Debug_Verbose")) {
		LPCTSTR lpsz = "DETOUR_CScreenCharGen::DETOUR_MageBookPanelOnLoad(): nMageSpells(%d), nScrollValues(%d)\r\n";
		console.writef(lpsz, MageBookSpells.GetCount(), max(scroll.nValues - scroll.nRows, 0));
		L.timestamp();
		L.appendf(lpsz, MageBookSpells.GetCount(), scroll.nValues);
	}

	scroll.UpdateKnobPosition(scroll.nCurrentValue, scroll.nValues, scroll.nRows);

	return;
}

void DETOUR_CScreenCharGen::DETOUR_KitPanelOnUpdate(CPanel& panel, CCreatureObject& cre) {
	CUIScrollBar& scroll = (CUIScrollBar&)panel.GetUIControl(6);
	pScrollActive = &scroll;
	Object& o = cre.oBase;

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

	CScreenCharGen* pCreateChar = g_pChitin->pCreateChar;
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
		LPCTSTR lpsz = "DETOUR_CScreenCharGen::DETOUR_KitPanelOnUpdate(): Kit selection scroll bar or button 11 not found\r\n";
		console.write(lpsz);
		L.timestamp();
		L.append(lpsz);
		return (this->*Tramp_CScreenCharGen_KitPanelOnUpdate)(panel, cre);
	}

	IECString sClass, sRace, sKitName, sAlignment, sRowName, sKitFile;

	if (m_class) {
		sClass = pGame->GetClassString(m_class, KIT_TRUECLASS);
	} else {
		sClass = pGame->GetClassString(o.GetClass(), KIT_TRUECLASS);
	}

	sRace = pGame->GetRaceString(o.m_cRace);
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
		unsigned int nKitId;
		sscanf_s((LPCTSTR)sKit, "%d", &nKitId);

		if (nKitId == 0) { //true class
			if (m_class) {
				pGame->GetDetailedClassString(m_class, KIT_TRUECLASS, 0, sKitName, cre);
			} else {
				pGame->GetDetailedClassString(o.GetClass(), KIT_TRUECLASS, 0, sKitName, cre);
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
		unsigned int nKitId = 0;
		if ((index < Kit_Class_Race.nRows) && (nChargenProgress == 5)) {
			sAlignment = pGame->GetAlignmentString(o.m_cAlignment);

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

	unsigned int dwKit = cre.m_header.m_wKit[1] | (cre.m_header.m_wKit[0] << 16);

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

	if ((dwKit & KIT_TRUECLASS) && (dwKit & 0xBFFF)) { //has a kit
		unsigned int dwKitOnly = dwKit & 0xBFFF;

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
			unsigned int nKitId;
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
			case KIT_TRUECLASS:
				switch (scrollKit.nCurrentValue) {
				case 0:
					option1.SetToggleState(TRUE);
					break;
				default:
					break;
				}
				break;
			case KIT_BERSERKER:
			case KIT_CAVALIER:
			case KIT_FERALAN:
			case KIT_ASSASIN:
			case KIT_BLADE:
			case KIT_GODTALOS:
			case KIT_TOTEMIC:
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
			case KIT_WIZARDSLAYER:
			case KIT_INQUISITOR:
			case KIT_STALKER:
			case KIT_BOUNTYHUNTER:
			case KIT_JESTER:
			case KIT_GODHELM:
			case KIT_SHAPESHIFTER:
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
			case KIT_KENSAI:
			case KIT_UNDEADHUNTER:
			case KIT_BEASTMASTER:
			case KIT_SWASHBUCKLER:
			case KIT_SKALD:
			case KIT_GODLATHANDER:
			case KIT_BEASTFRIEND:
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
	if (Kit_Class_Race.nRows > 11) {
		scrollKit.SetEnabled(TRUE);
		scrollKit.SetVisible(TRUE);
	} else {
		scrollKit.SetEnabled(FALSE);
		scrollKit.SetVisible(FALSE);
	}

	if (pGameOptionsEx->GetOption("Debug_Verbose")) {
		
		LPCTSTR lpsz = "DETOUR_CScreenCharGen::DETOUR_KitPanelOnUpdate(): nKits(%d), nScrollValues(%d), wKit(0x%X)\r\n";
		console.writef(lpsz, Kit_Class_Race.nRows, max(scrollKit.nValues - scrollKit.nRows, 0), dwKit);
		L.timestamp();
		L.appendf(lpsz, Kit_Class_Race.nRows, scrollKit.nValues, dwKit);
	}

	return;
};

void DETOUR_CScreenCharGen::DETOUR_MageBookPanelOnUpdate(CPanel& panel, CCreatureObject& cre) {
	CUIScrollBarChargenMageSpell& scroll = (CUIScrollBarChargenMageSpell&)panel.GetUIControl(31);
	if (&scroll == NULL) {
		LPCTSTR lpsz = "DETOUR_CScreenCharGen::DETOUR_MageBookPanelOnUpdate(): Chargen mage spell selection scroll bar not found\r\n";
		console.write(lpsz);
		L.timestamp();
		L.append(lpsz);
		return (this->*Tramp_CScreenCharGen_MageBookPanelOnUpdate)(panel, cre);
	}

	//Depending on offset in MageBookSpells, transfer spells to/from temporary spell pile
	int nPileCount = scroll.cplTempSpells.GetCount();
	int nSliderCount = 6 * scroll.nCurrentValue;

	if (nSliderCount > nPileCount) {
		int i = nSliderCount - nPileCount;
		while (i) {
			if (MageBookSpells.IsEmpty()) {
				LPCTSTR lpsz = "DETOUR_CScreenCharGen::DETOUR_MageBookPanelOnUpdate(): Mage book is empty\r\n";
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
				LPCTSTR lpsz = "DETOUR_CScreenCharGen::DETOUR_MageBookPanelOnUpdate(): Mage spell pile is empty\r\n";
				console.write(lpsz);
				L.timestamp();
				L.append(lpsz);
				break;
			}
			MageBookSpells.AddHead(scroll.cplTempSpells.RemoveHead());
			i--;
		}
	}

	(this->*Tramp_CScreenCharGen_MageBookPanelOnUpdate)(panel, cre);

	//Update on/off status of spell buttons
	for (int i = 2; i <= 25; i++ ) {
		CCreatureObject* pCre = &cre;
		char threadNum = THREAD_ASYNCH;
		char threadVal;
		do {
			threadVal = g_pChitin->pGame->m_GameObjectArray.GetShare(g_pChitin->pCreateChar->eChar, threadNum, &pCre, INFINITE);
		} while (threadVal == OBJECT_SHARING || threadVal == OBJECT_DENYING);

		if (threadVal == OBJECT_SUCCESS) {
			CUICheckButtonChargenMageSpell& control = (CUICheckButtonChargenMageSpell&)panel.GetUIControl(i);
			if (UserCommon_HasKnownSpell(&cre, control.m_rSpell, nCurrentMageBookLevel)) {
				control.bToggle = TRUE;
			} else {
				control.bToggle = FALSE;
			}
			control.SetRedraw();
			g_pChitin->pGame->m_GameObjectArray.FreeShare(g_pChitin->pCreateChar->eChar, threadNum, INFINITE);
		}
	}

	if (scroll.cplTempSpells.GetCount() + MageBookSpells.GetCount() > 24) {
		scroll.SetEnabled(TRUE);
		scroll.SetVisible(TRUE);
	} else {
		scroll.SetEnabled(FALSE);
		scroll.SetVisible(FALSE);
	}

	return;
}

void DETOUR_CScreenCharGen::DETOUR_ClassPanelOnUpdate(CPanel& panel, CCreatureObject& cre) {
	if (!pRuleEx->m_ClassRaceReq.m_2da.bLoaded) return (this->*Tramp_CScreenCharGen_ClassPanelOnUpdate)(panel, cre);

	CUIScrollBar& scroll = (CUIScrollBar&)panel.GetUIControl(12);
	pScrollActive = &scroll;
	CInfGame* pGame = g_pChitin->pGame;
	CreFileHeader& stats = cre.m_header;
	Object& o = cre.oBase;
	unsigned int dwKit = stats.m_wKit[1] | stats.m_wKit[0] << 16;

	for (int i = 2; i <= 9; i++) {
		CUICheckButtonChargenClass& button = (CUICheckButtonChargenClass&)panel.GetUIControl(i);
		if (button.GetClass() == o.m_cClass) {
			if (o.m_cClass == CLASS_FIGHTER && dwKit == KIT_BARBARIAN) {
				button.SetToggleState(FALSE);
			} else {
				button.SetToggleState(TRUE);
			}
		} else {
			button.SetToggleState(FALSE);
		}

		IECString sRace = pGame->GetRaceString(o.m_cRace);
		IECString sClass = pGame->GetClassString(button.GetClass(), KIT_TRUECLASS);
		IECString sAllowed = pRuleEx->m_ClassRaceReq.GetValue(sRace, sClass);
		BOOL bAllowed;
		sscanf_s((LPCTSTR)sAllowed, "%d", &bAllowed);
		button.SetActive(bAllowed);
	}

	for (int i = 15; i <= 17; i++) {
		CUICheckButtonChargenClass& button = (CUICheckButtonChargenClass&)panel.GetUIControl(i);
		if (button.GetClass() == o.m_cClass) {
			if (o.m_cClass == CLASS_FIGHTER && dwKit != KIT_BARBARIAN) {
				button.SetToggleState(FALSE);
			} else {
				button.SetToggleState(TRUE);
			}
		} else {
			button.SetToggleState(FALSE);
		}

		IECString sRace = pGame->GetRaceString(o.m_cRace);
		IECString sClass = pGame->GetClassString(button.GetClass(), KIT_TRUECLASS);
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

void DETOUR_CScreenCharGen::DETOUR_MulticlassPanelOnUpdate(CPanel& panel, CCreatureObject& cre) {
	if (!pRuleEx->m_ClassRaceReq.m_2da.bLoaded) return (this->*Tramp_CScreenCharGen_MulticlassPanelOnUpdate)(panel, cre);

	CUIScrollBar& scroll = (CUIScrollBar&)panel.GetUIControl(13);
	pScrollActive = &scroll;
	CInfGame* pGame = g_pChitin->pGame;
	Object& o = cre.oBase;

	for (int i = 2; i <= 11; i++) {
		CUICheckButtonChargenMulticlass& button = (CUICheckButtonChargenMulticlass&)panel.GetUIControl(i);
		button.SetToggleState(button.GetClass() == o.m_cClass);

		IECString sRace = pGame->GetRaceString(o.m_cRace);
		IECString sClass = pGame->GetClassString(button.GetClass(), KIT_TRUECLASS);
		IECString sAllowed = pRuleEx->m_ClassRaceReq.GetValue(sRace, sClass);
		BOOL bAllowed;
		sscanf_s((LPCTSTR)sAllowed, "%d", &bAllowed);
		button.SetActive(bAllowed);
	}

	CUIButton& buttonDone = (CUIButton&)panel.GetUIControl(0);
	buttonDone.SetActive(CanContinue(cre));

	return;
}

void DETOUR_CScreenCharGen::DETOUR_MageSchoolPanelOnUpdate(CPanel& panel, CCreatureObject& cre) {
	if (!pRuleEx->m_MageSchoolRaceReq.m_2da.bLoaded) return (this->*Tramp_CScreenCharGen_MageSchoolPanelOnUpdate)(panel, cre);

	CUIScrollBar& scroll = (CUIScrollBar&)panel.GetUIControl(10);
	pScrollActive = &scroll;
	CInfGame* pGame = g_pChitin->pGame;
	CreFileHeader& stats = cre.m_header;
	Object& o = cre.oBase;
	unsigned int dwKit = stats.m_wKit[1] | stats.m_wKit[0] << 16;
	BOOL bButtonToggled = FALSE;

	BOOL bMageClass = o.GetClass() == CLASS_MAGE || o.GetClass() == CLASS_SORCERER;
	if (!bMageClass) {
		unsigned char nClassNew;
		unsigned char nClassOrg;
		o.GetDualClasses(&nClassNew, &nClassOrg);
		bMageClass = nClassNew == CLASS_MAGE || nClassOrg == CLASS_MAGE;
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

		buttonSchool.SetActive(pGame->IsMageSchoolAllowed(buttonSchool.GetKit(), o.m_cRace));
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
		buttonWildMage.SetActive(pGame->IsMageSchoolAllowed(buttonWildMage.GetKit(), o.m_cRace));
	} else {
		buttonWildMage.SetToggleState(FALSE);
		buttonWildMage.SetActive(FALSE);
		buttonWildMage.SetEnabled(FALSE);
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
	buttonMage.SetActive(pGame->IsMageSchoolAllowed(buttonMage.GetKit(), o.m_cRace));

	CUIButton& buttonDone = (CUIButton&)panel.GetUIControl(0);
	buttonDone.SetActive(CanContinue(cre) && pGame->IsMageSchoolAllowed(dwKit, o.m_cRace));

	return;
}

void DETOUR_CScreenCharGen::DETOUR_InitSoundset(CCreatureObject& cre) {
	(this->*Tramp_CScreenCharGen_InitSoundset)(cre);
	EngineCommon_ApplySoundset(cre);
	return;
}

BOOL CScreenCharGen_MageSchoolPanelCanContinue(CCreatureObject& cre) {
	return g_pChitin->pGame->IsMageSchoolAllowed(cre.GetKitUnusableFlag(), cre.oBase.m_cRace);
}