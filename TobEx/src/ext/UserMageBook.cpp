#include "UserMageBook.h"

#include "stdafx.h"
#include "uicore.h"
#include "infgame.h"
#include "objcre.h"
#include "rescore.h"
#include "chitin.h"
#include "console.h"
#include "log.h"
#include "splcore.h"
#include "engmagebk.h"

int CUIButtonMageBook_KnownSpellOffset = 0;

CUIButtonMageBookUp::CUIButtonMageBookUp(CPanel& panel, ChuFileControlInfoBase& controlInfo) : CUIButton(panel, controlInfo, 1, TRUE) {}
CUIButtonMageBookUp::~CUIButtonMageBookUp() {}

void CUIButtonMageBookUp::OnLClicked(POINT pt) {
	CMageBook* pWizSpell = g_pChitin->pWizSpell;
	CPanel& panel = pWizSpell->manager.GetPanel(2);

	CInfGame* pGame = g_pChitin->pGame;
	Enum e;

	if (pWizSpell->nActivePlayerIdx < pGame->numInParty) {
		e = pGame->ePlayersPartyOrder[pWizSpell->nActivePlayerIdx];
	} else {
		e = ENUM_INVALID_INDEX;
	}

	CCreatureObject* pCre;
	char threadVal;
	do {
		threadVal = pGame->m_GameObjectArrayHandler.GetGameObjectShare(e, THREAD_ASYNCH, &pCre, INFINITE);
	} while (threadVal == OBJECT_SHARING || threadVal == OBJECT_DENYING);

	if (threadVal == OBJECT_SUCCESS) {
		CUIButtonMageBook_KnownSpellOffset = max(CUIButtonMageBook_KnownSpellOffset - 4, 0);

		for (int i = 27; i <= 50; i++ ) {
			CUIButtonMageBookKnownSpell& control = (CUIButtonMageBookKnownSpell&)panel.GetUIControl(i);
			CreFileKnownSpell& kspell = pCre->GetKnownSpellMage(pWizSpell->currLevel, i - 27 + CUIButtonMageBook_KnownSpellOffset);
			&kspell ? control.SetSpell(kspell.name) : control.SetSpell(ResRef());
			control.SetRedraw();
		}
		pGame->m_GameObjectArrayHandler.FreeGameObjectShare(e, THREAD_ASYNCH, INFINITE);
	} else {
		LPCTSTR lpsz = "CUIButtonMageBookUp::OnLClicked(): GetGameObjectShare returned %d\r\n";
		console.write(lpsz, 1, threadVal);
		L.timestamp();
		L.append(lpsz, 1, threadVal);
	}

	return;
}

CUIButtonMageBookDn::CUIButtonMageBookDn(CPanel& panel, ChuFileControlInfoBase& controlInfo) : CUIButton(panel, controlInfo, 1, TRUE) {}
CUIButtonMageBookDn::~CUIButtonMageBookDn() {}

void CUIButtonMageBookDn::OnLClicked(POINT pt) {
	CMageBook* pWizSpell = g_pChitin->pWizSpell;
	CPanel& panel = pWizSpell->manager.GetPanel(2);

	CInfGame* pGame = g_pChitin->pGame;
	Enum e;

	if (pWizSpell->nActivePlayerIdx < pGame->numInParty) {
		e = pGame->ePlayersPartyOrder[pWizSpell->nActivePlayerIdx];
	} else {
		e = ENUM_INVALID_INDEX;
	}

	CCreatureObject* pCre;
	char threadVal;
	do {
		threadVal = pGame->m_GameObjectArrayHandler.GetGameObjectShare(e, THREAD_ASYNCH, &pCre, INFINITE);
	} while (threadVal == OBJECT_SHARING || threadVal == OBJECT_DENYING);

	if (threadVal == OBJECT_SUCCESS) {
		int nValues = pCre->m_KnownSpellsWizard[pWizSpell->currLevel].GetCount() / 4;
		if (nValues % 4) nValues++;
		if (nValues < 6) {
			CUIButtonMageBook_KnownSpellOffset = 0;
		} else {
			CUIButtonMageBook_KnownSpellOffset = min(CUIButtonMageBook_KnownSpellOffset + 4, 4 * (nValues - 6));
		}

		for (int i = 27; i <= 50; i++ ) {
			CUIButtonMageBookKnownSpell& control = (CUIButtonMageBookKnownSpell&)panel.GetUIControl(i);
			CreFileKnownSpell& kspell = pCre->GetKnownSpellMage(pWizSpell->currLevel, i - 27 + CUIButtonMageBook_KnownSpellOffset);
			&kspell ? control.SetSpell(kspell.name) : control.SetSpell(ResRef());
			control.SetRedraw();
		}

		pGame->m_GameObjectArrayHandler.FreeGameObjectShare(e, THREAD_ASYNCH, INFINITE);
	} else {
		LPCTSTR lpsz = "CUIButtonMageBookDn::OnLClicked(): GetGameObjectShare returned %d\r\n";
		console.write(lpsz, 1, threadVal);
		L.timestamp();
		L.append(lpsz, 1, threadVal);
	}

	return;
}