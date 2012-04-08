#include "EngineRecord.h"

#include <cassert>

#include "stdafx.h"
#include "objcre.h"
#include "objcore.h"
#include "chitin.h"
#include "uicore.h"
#include "infgame.h"
#include "console.h"
#include "log.h"
#include "EngineCommon.h"
#include "UserRecMageSpell.h"
#include "UserCommon.h"

void (CScreenRecord::*Tramp_CScreenRecord_MageBookPanelOnLoad)(CCreatureObject&) =
	SetFP(static_cast<void (CScreenRecord::*)(CCreatureObject&)>	(&CScreenRecord::MageBookPanelOnLoad),	0x6E0FE6);
void (CScreenRecord::*Tramp_CScreenRecord_MageBookPanelOnUpdate)(CCreatureObject&) =
	SetFP(static_cast<void (CScreenRecord::*)(CCreatureObject&)>	(&CScreenRecord::MageBookPanelOnUpdate),0x6E563F);
void (CScreenRecord::*Tramp_CScreenRecord_UpdateCharacter)() =
	SetFP(static_cast<void (CScreenRecord::*)()>					(&CScreenRecord::UpdateCharacter),		0x6E9F57);

void DETOUR_CScreenRecord::DETOUR_MageBookPanelOnLoad(CCreatureObject& cre) {
	CPanel& panel = manager.GetPanel(8);
	assert(&panel != NULL);
	CUIScrollBarRecMageSpell& scroll = (CUIScrollBarRecMageSpell&)panel.GetUIControl(30);
	
	if (&scroll == NULL) {
		LPCTSTR lpsz = "DETOUR_MageBookPanelOnLoad(): Level-up mage spell selection scroll bar not found\r\n";
		console.write(lpsz);
		L.timestamp();
		L.append(lpsz);
		return (this->*Tramp_CScreenRecord_MageBookPanelOnLoad)(cre);
	}

	//clear values
	scroll.nCurrentValue = 0;
	scroll.nValues = 0;
	scroll.nRows = 0;
	scroll.cplTempSpells.RemoveAll();

	(this->*Tramp_CScreenRecord_MageBookPanelOnLoad)(cre);

	if (this->bHighLevelAbility == FALSE) {
		scroll.nValues = MageBookSpells.GetCount() / 5;
		if (MageBookSpells.GetCount() % 5) scroll.nValues++;
		scroll.nRows = 5;
	}

	scroll.UpdateKnobPosition(scroll.nCurrentValue, scroll.nValues, scroll.nRows);

	return;
}

void DETOUR_CScreenRecord::DETOUR_MageBookPanelOnUpdate(CCreatureObject& cre) {
	CPanel& panel = manager.GetPanel(8);
	assert(&panel != NULL);
	CUIScrollBarRecMageSpell& scroll = (CUIScrollBarRecMageSpell&)panel.GetUIControl(30);

	if (&scroll == NULL) {
		LPCTSTR lpsz = "DETOUR_MageBookPanelOnUpdate(): Level-up mage spell selection scroll bar not found\r\n";
		console.write(lpsz);
		L.timestamp();
		L.append(lpsz);
		return (this->*Tramp_CScreenRecord_MageBookPanelOnUpdate)(cre);
	}

	//do not apply to selecting high level abilities
	if (this->bHighLevelAbility == TRUE) {
		(this->*Tramp_CScreenRecord_MageBookPanelOnUpdate)(cre);
		scroll.SetEnabled(FALSE);
		scroll.SetVisible(FALSE);
		return;
	}

	//Depending on offset in MageBookSpells, transfer spells to/from temporary spell pile
	int nPileCount = scroll.cplTempSpells.GetCount();
	int nSliderCount = 5 * scroll.nCurrentValue;

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

	(this->*Tramp_CScreenRecord_MageBookPanelOnUpdate)(cre);

	//Update on/off status of spell buttons
	for (int i = 0; i <= 24; i++ ) {
		Enum eChar = ENUM_INVALID_INDEX;
		CInfGame* pGame = g_pChitin->pGame;
		CScreenRecord* pCharacter = g_pChitin->pCharacter;
		int nPlayerIdx = pCharacter->GetActivePlayerIdx();
		if (nPlayerIdx < pGame->numInParty) {
			eChar = pGame->ePlayersPartyOrder[nPlayerIdx];
		} else {
			eChar = ENUM_INVALID_INDEX;
		}

		CCreatureObject* pCre = &cre;
		char threadNum = THREAD_ASYNCH;
		char threadVal;
		do {
			threadVal = g_pChitin->pGame->m_GameObjectArrayHandler.GetGameObjectShare(eChar, threadNum, &pCre, INFINITE);
		} while (threadVal == OBJECT_SHARING || threadVal == OBJECT_DENYING);

		if (threadVal == OBJECT_SUCCESS) {
			CUICheckButtonRecMageSpell& control = (CUICheckButtonRecMageSpell&)panel.GetUIControl(i);
			if (&control != NULL) {
				if (UserCommon_HasKnownSpell(&cre, control.m_rSpell, nCurrentMageBookLevel)) {
					control.bToggle = TRUE;
				} else {
					control.bToggle = FALSE;
				}
				control.SetRedraw();
			} else {
				LPCTSTR lpsz = "DETOUR_MageBookPanelOnUpdate(): pButton == NULL\r\n";
				L.timestamp();
				L.append(lpsz);
				console.write(lpsz);
			}
			g_pChitin->pGame->m_GameObjectArrayHandler.FreeGameObjectShare(eChar, threadNum, INFINITE);
		}
	}

	if (scroll.cplTempSpells.GetCount() + MageBookSpells.GetCount() > 25) {
		scroll.SetEnabled(TRUE);
		scroll.SetVisible(TRUE);
	} else {
		scroll.SetEnabled(FALSE);
		scroll.SetVisible(FALSE);
	}

	return;
}

void DETOUR_CScreenRecord::DETOUR_UpdateCharacter() {
	CPanel& cp = GetTopPanel();
	assert(&cp != NULL);

	(this->*Tramp_CScreenRecord_UpdateCharacter)();

	if (cp.index - 3 == 17) {

		CInfGame* pGame = g_pChitin->pGame;
		assert(pGame);

		Enum ePlayer1;
		if (u141c) {
			ePlayer1 = g_pChitin->pCreateChar->eChar;
		} else {
			if (nActivePlayerIdx < pGame->numInParty) {
				ePlayer1 = pGame->ePlayersPartyOrder[nActivePlayerIdx];
			} else {
				ePlayer1 = ENUM_INVALID_INDEX;
			}
		}

		CCreatureObject* pCre;
		char threadVal;
		do {
			threadVal = pGame->m_GameObjectArrayHandler.GetGameObjectDeny(ePlayer1, THREAD_ASYNCH, &pCre, INFINITE);
		} while (threadVal == OBJECT_SHARING || threadVal == OBJECT_DENYING);

		if (threadVal == OBJECT_SUCCESS) {
			EngineCommon_ApplySoundset(*pCre);
			pGame->m_GameObjectArrayHandler.FreeGameObjectDeny(ePlayer1, THREAD_ASYNCH, INFINITE);
		} else {
			LPCTSTR lpsz = "DETOUR_UpdateCharacter(): FreeGameObjectDeny returned %d\r\n";
			console.writef(lpsz, threadVal);
			L.timestamp();
			L.appendf(lpsz, threadVal);
			return;
		}

	} //cp.index

	return;
}

