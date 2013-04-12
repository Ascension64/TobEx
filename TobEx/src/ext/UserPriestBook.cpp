#include "UserPriestBook.h"

#include "stdafx.h"
#include "uicore.h"
#include "infgame.h"
#include "objcre.h"
#include "rescore.h"
#include "chitin.h"
#include "console.h"
#include "log.h"
#include "splcore.h"
#include "engpriestbk.h"

int CUIButtonPriestBook_KnownSpellOffset = 0;

CUIButtonPriestBookUp::CUIButtonPriestBookUp(CPanel& panel, ChuFileControlInfoBase& controlInfo) : CUIButton(panel, controlInfo, 1, TRUE) {}
CUIButtonPriestBookUp::~CUIButtonPriestBookUp() {}

void CUIButtonPriestBookUp::OnLClicked(CPoint pt) {
	CScreenPriestBook* pPriestSpell = g_pChitin->pPriestSpell;
	CPanel& panel = pPriestSpell->manager.GetPanel(2);

	CInfGame* pGame = g_pChitin->pGame;
	ENUM e;

	if (pPriestSpell->nActivePlayerIdx < pGame->numInParty) {
		e = pGame->ePlayersPartyOrder[pPriestSpell->nActivePlayerIdx];
	} else {
		e = ENUM_INVALID_INDEX;
	}

	CCreatureObject* pCre;
	char threadVal;
	do {
		threadVal = pGame->m_GameObjectArray.GetShare(e, THREAD_ASYNCH, &pCre, INFINITE);
	} while (threadVal == OBJECT_SHARING || threadVal == OBJECT_DENYING);

	if (threadVal == OBJECT_SUCCESS) {
		CUIButtonPriestBook_KnownSpellOffset = max(CUIButtonPriestBook_KnownSpellOffset - 4, 0);

		for (int i = 27; i <= 50; i++ ) {
			CUIButtonPriestBookKnownSpell& control = (CUIButtonPriestBookKnownSpell&)panel.GetUIControl(i);
			CreFileKnownSpell& kspell = pCre->GetKnownSpellPriest(pPriestSpell->currLevel, i - 27 + CUIButtonPriestBook_KnownSpellOffset);
			&kspell ? control.SetSpell(kspell.m_rKnownSpellName) : control.SetSpell(ResRef());
			control.SetRedraw();
		}
		pGame->m_GameObjectArray.FreeShare(e, THREAD_ASYNCH, INFINITE);
	} else {
		LPCTSTR lpsz = "CUIButtonPriestBookUp::OnLClicked(): GetShare returned %d\r\n";
		console.writef(lpsz, threadVal);
		L.timestamp();
		L.appendf(lpsz, threadVal);
	}

	return;
}

CUIButtonPriestBookDn::CUIButtonPriestBookDn(CPanel& panel, ChuFileControlInfoBase& controlInfo) : CUIButton(panel, controlInfo, 1, TRUE) {}
CUIButtonPriestBookDn::~CUIButtonPriestBookDn() {}

void CUIButtonPriestBookDn::OnLClicked(CPoint pt) {
	CScreenPriestBook* pPriestSpell = g_pChitin->pPriestSpell;
	CPanel& panel = pPriestSpell->manager.GetPanel(2);

	CInfGame* pGame = g_pChitin->pGame;
	ENUM e;

	if (pPriestSpell->nActivePlayerIdx < pGame->numInParty) {
		e = pGame->ePlayersPartyOrder[pPriestSpell->nActivePlayerIdx];
	} else {
		e = ENUM_INVALID_INDEX;
	}

	CCreatureObject* pCre;
	char threadVal;
	do {
		threadVal = pGame->m_GameObjectArray.GetShare(e, THREAD_ASYNCH, &pCre, INFINITE);
	} while (threadVal == OBJECT_SHARING || threadVal == OBJECT_DENYING);

	if (threadVal == OBJECT_SUCCESS) {
		int nValues = pCre->m_KnownSpellsPriest[pPriestSpell->currLevel].GetCount() / 4;
		if (pCre->m_KnownSpellsPriest[pPriestSpell->currLevel].GetCount() % 4) nValues++;
		if (nValues < 6) {
			CUIButtonPriestBook_KnownSpellOffset = 0;
		} else {
			CUIButtonPriestBook_KnownSpellOffset = min(CUIButtonPriestBook_KnownSpellOffset + 4, 4 * (nValues - 6));
		}

		for (int i = 27; i <= 50; i++ ) {
			CUIButtonPriestBookKnownSpell& control = (CUIButtonPriestBookKnownSpell&)panel.GetUIControl(i);
			CreFileKnownSpell& kspell = pCre->GetKnownSpellPriest(pPriestSpell->currLevel, i - 27 + CUIButtonPriestBook_KnownSpellOffset);
			&kspell ? control.SetSpell(kspell.m_rKnownSpellName) : control.SetSpell(ResRef());
			control.SetRedraw();
		}

		pGame->m_GameObjectArray.FreeShare(e, THREAD_ASYNCH, INFINITE);
	} else {
		LPCTSTR lpsz = "CUIButtonPriestBookDn::OnLClicked(): GetShare returned %d\r\n";
		console.writef(lpsz, threadVal);
		L.timestamp();
		L.appendf(lpsz, threadVal);
	}

	return;
}