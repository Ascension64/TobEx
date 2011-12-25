#include "EngineRecord.h"

#include <cassert>

#include "utils.h"
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

void (CRecord::*Tramp_CRecord_MageBookPanelOnLoad)(CCreatureObject&) =
	SetFP(static_cast<void (CRecord::*)(CCreatureObject&)>			(&CRecord::MageBookPanelOnLoad),	0x6E0FE6);
void (CRecord::*Tramp_CRecord_MageBookPanelOnUpdate)(CCreatureObject&) =
	SetFP(static_cast<void (CRecord::*)(CCreatureObject&)>			(&CRecord::MageBookPanelOnUpdate),	0x6E563F);
void (CRecord::*Tramp_CRecord_UpdateCharacter)(void) =
	SetFP(static_cast<void (CRecord::*)(void)>						(&CRecord::UpdateCharacter),		0x6E9F57);

void DETOUR_CRecord::DETOUR_MageBookPanelOnLoad(CCreatureObject& cre) {
	CPanel& panel = manager.GetPanel(8);
	assert(&panel != NULL);
	CUIScrollBarRecMageSpell& scroll = (CUIScrollBarRecMageSpell&)panel.GetUIControl(30);
	
	if (&scroll == NULL) {
		LPCTSTR lpsz = "DETOUR_MageBookPanelOnLoad(): Level-up mage spell selection scroll bar not found. Did you install the required WeiDU component?\r\n";
		console.write(lpsz);
		L.timestamp();
		L.append(lpsz);
		return (this->*Tramp_CRecord_MageBookPanelOnLoad)(cre);
	}

	//clear values
	scroll.nCurrentValue = 0;
	scroll.nValues = 0;
	scroll.nRows = 0;
	scroll.cplTempSpells.RemoveAll();

	(this->*Tramp_CRecord_MageBookPanelOnLoad)(cre);

	scroll.nValues = MageBookSpells.GetCount() / 5;
	if (scroll.nValues % 5) scroll.nValues++;
	scroll.nRows = 5;

	scroll.UpdateKnobPosition(scroll.nCurrentValue, scroll.nValues, scroll.nRows);

	return;
}

void DETOUR_CRecord::DETOUR_MageBookPanelOnUpdate(CCreatureObject& cre) {
	CPanel& panel = manager.GetPanel(8);
	assert(&panel != NULL);
	CUIScrollBarRecMageSpell& scroll = (CUIScrollBarRecMageSpell&)panel.GetUIControl(30);

	if (&scroll == NULL) {
		LPCTSTR lpsz = "DETOUR_MageBookPanelOnUpdate(): Level-up mage spell selection scroll bar not found. Did you install the required WeiDU component?\r\n";
		console.write(lpsz);
		L.timestamp();
		L.append(lpsz);
		return (this->*Tramp_CRecord_MageBookPanelOnUpdate)(cre);
	}

	//Depending on offset in MageBookSpells, transfer spells to/from temporary spell pile
	DWORD nPileCount = scroll.cplTempSpells.GetCount();
	DWORD nSliderCount = 5 * scroll.nCurrentValue;

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

	(this->*Tramp_CRecord_MageBookPanelOnUpdate)(cre);

	//Update on/off status of spell buttons
	for (int i = 0; i <= 24; i++ ) {
		Enum eChar = ENUM_INVALID_INDEX;
		CInfGame* pGame = g_pChitin->pGame;
		CRecord* pCharacter = g_pChitin->pCharacter;
		DWORD nPlayerIdx = pCharacter->GetActivePlayerIdx();
		if (nPlayerIdx < pGame->numInParty) {
			eChar = pGame->ePlayersPartyOrder[nPlayerIdx];
		} else {
			eChar = ENUM_INVALID_INDEX;
		}

		CCreatureObject* pCre = &cre;
		BYTE threadNum = THREAD_ASYNCH;
		BYTE threadVal;
		do {
			threadVal = g_pChitin->pGame->m_GameObjectArrayHandler.GetGameObjectShare(eChar, threadNum, &pCre, INFINITE);
		} while (threadVal == OBJECT_SHARING || threadVal == OBJECT_DENYING);

		if (threadVal == OBJECT_SUCCESS) {
			CUICheckButtonRecMageSpell& control = (CUICheckButtonRecMageSpell&)panel.GetUIControl(i);
			if (UserCommon_HasKnownSpell(&cre, control.m_rSpell, nCurrentMageBookLevel)) {
				control.bToggle = TRUE;
			} else {
				control.bToggle = FALSE;
			}
			control.SetRedraw();
			g_pChitin->pGame->m_GameObjectArrayHandler.FreeGameObjectShare(eChar, threadNum, INFINITE);
		}
	}

	return;
}

void DETOUR_CRecord::DETOUR_UpdateCharacter() {
	CPanel& cp = GetTopPanel();
	assert(&cp != NULL);

	(this->*Tramp_CRecord_UpdateCharacter)();

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
		BYTE threadVal;
		do {
			threadVal = pGame->m_GameObjectArrayHandler.GetGameObjectDeny(ePlayer1, THREAD_ASYNCH, &pCre, INFINITE);
		} while (threadVal == OBJECT_SHARING || threadVal == OBJECT_DENYING);

		if (threadVal == OBJECT_SUCCESS) {
			EngineCommon_ApplySoundset(*pCre);
			pGame->m_GameObjectArrayHandler.FreeGameObjectDeny(ePlayer1, THREAD_ASYNCH, INFINITE);
		} else {
			LPCTSTR lpsz = "DETOUR_UpdateCharacter(): FreeGameObjectDeny returned %d\r\n";
			console.write(lpsz, 1, threadVal);
			L.timestamp();
			L.append(lpsz, 1, threadVal);
			return;
		}

	} //cp.index

	return;
}

