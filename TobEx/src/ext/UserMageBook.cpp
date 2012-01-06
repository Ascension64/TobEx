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

CUICheckButtonMageBookContChoice& (CUICheckButtonMageBookContChoice::*Tramp_CUICheckButtonMageBookContChoice_Construct_2CPanel_ChuFileControlInfoBase)(CPanel&, ChuFileControlInfoBase&) =
	SetFP(static_cast<CUICheckButtonMageBookContChoice& (CUICheckButtonMageBookContChoice::*)(CPanel&, ChuFileControlInfoBase&)>
																			(&CUICheckButtonMageBookContChoice::Construct),		0x7C124D);
void (CUICheckButtonMageBookContChoice::*Tramp_CUICheckButtonMageBookContChoice_OnLClicked)(POINT) =
	SetFP(static_cast<void (CUICheckButtonMageBookContChoice::*)(POINT)>	(&CUICheckButtonMageBookContChoice::OnLClicked),	0x7C1304);
CUICheckButtonMageBookContSelected& (CUICheckButtonMageBookContSelected::*Tramp_CUICheckButtonMageBookContSelected_Construct_2CPanel_ChuFileControlInfoBase)(CPanel&, ChuFileControlInfoBase&) =
	SetFP(static_cast<CUICheckButtonMageBookContSelected& (CUICheckButtonMageBookContSelected::*)(CPanel&, ChuFileControlInfoBase&)>
																			(&CUICheckButtonMageBookContSelected::Construct),	0x7C0CAC);
void (CUICheckButtonMageBookContSelected::*Tramp_CUICheckButtonMageBookContSelected_OnLClicked)(POINT) =
	SetFP(static_cast<void (CUICheckButtonMageBookContSelected::*)(POINT)>	(&CUICheckButtonMageBookContSelected::OnLClicked),	0x7C0D56);

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
		if (pCre->m_KnownSpellsWizard[pWizSpell->currLevel].GetCount() % 4) nValues++;
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

CUICheckButtonMageBookContChoice& DETOUR_CUICheckButtonMageBookContChoice::DETOUR_Construct(CPanel& panel, ChuFileControlInfoBase& controlInfo) {
	(this->*Tramp_CUICheckButtonMageBookContChoice_Construct_2CPanel_ChuFileControlInfoBase)(panel, controlInfo);
	rParentSpell = "";
	return *this;
}

void DETOUR_CUICheckButtonMageBookContChoice::DETOUR_OnLClicked(POINT pt) {
	CMageBook* pWizSpell = g_pChitin->pWizSpell;
	if (pWizSpell == NULL) {
		LPCTSTR lpsz = "DETOUR_CUICheckButtonMageBookContChoice::DETOUR_OnLClicked(): pWiz == NULL\r\n";
		L.timestamp();
		L.append(lpsz);
		console.write(lpsz);
		return;
	}
	if (pWizSpell->GetTopPanel().index != 6) return;

	IECString sSpell = IECString(rSpell.GetBuffer());
	IECString sParentSpell = IECString(rParentSpell.GetBuffer());
	CTlkTbl* pTlk = &g_pChitin->m_TlkTbl;
	CUITextArea& textDesc = (CUITextArea&)pPanel->GetUIControl(25);
	CStrRef strref;
	switch (nArrowDirection) {
		case 0:
			if (rSpell.IsNotEmpty()) {
				if (CMageBook_AddContingencySpellEx(pWizSpell, sSpell, sParentSpell)) {
					pWizSpell->SetSpellContingencyState(rParentSpell.IsEmpty() ? sSpell : sParentSpell, FALSE);
				}
				ResSplContainer resSpell(rSpell);
				resSpell.Demand();
				textDesc.ClearText();
				pTlk->GetTlkString(resSpell.GetSpellDescription(), strref);
				IECString sLeft;
				textDesc.Append(sLeft, strref.text, textDesc.colLeft, textDesc.colRight, CUITEXTAREA_USERARG_NONE, false);
				resSpell.Release();
			}
			break;
		case 1:
			pWizSpell->m_wContScrollIdx += 9;
			break;
		case -1:
			pWizSpell->m_wContScrollIdx = max(pWizSpell->m_wContScrollIdx - 9, 0);
			break;
		default:
			LPCTSTR lpsz = "DETOUR_CUICheckButtonMageBookContChoice::DETOUR_OnLClicked(): invalid nArrowDirection\r\n";
			L.timestamp();
			L.append(lpsz);
			console.write(lpsz);
			break;
	}

	pWizSpell->ContingencySelectOnUpdate(pPanel->index);
	return;
}

CUICheckButtonMageBookContSelected& DETOUR_CUICheckButtonMageBookContSelected::DETOUR_Construct(CPanel& panel, ChuFileControlInfoBase& controlInfo) {
	(this->*Tramp_CUICheckButtonMageBookContSelected_Construct_2CPanel_ChuFileControlInfoBase)(panel, controlInfo);
	rParentSpell = "";
	return *this;
}

void DETOUR_CUICheckButtonMageBookContSelected::DETOUR_OnLClicked(POINT pt) {
	CMageBook* pWizSpell = g_pChitin->pWizSpell;
	pWizSpell->SetSpellContingencyState(rParentSpell.IsEmpty() ? IECString(rSpell.GetBuffer()) : IECString(rParentSpell.GetBuffer()), TRUE);
	pWizSpell->ClearContingencySpell(index - 22);
	pWizSpell->ContingencySelectOnUpdate(pPanel->index);
	return;
}

bool __stdcall CMageBook_AddContingencySpellEx(CMageBook* pWiz, IECString sSpell, IECString sParentSpell) {
	if (pWiz->m_rContSpell1.IsEmpty()) {
		pWiz->m_rContSpell1 = sSpell;
		DETOUR_CUICheckButtonMageBookContSelected& spell1 = (DETOUR_CUICheckButtonMageBookContSelected&)pWiz->GetTopPanel().GetUIControl(22);
		spell1.rParentSpell = sParentSpell;
		return true;
	}

	if (pWiz->m_nMaxContSpells == 1) return false;

	if (pWiz->m_rContSpell2.IsEmpty()) {
		pWiz->m_rContSpell2 = sSpell;
		DETOUR_CUICheckButtonMageBookContSelected& spell2 = (DETOUR_CUICheckButtonMageBookContSelected&)pWiz->GetTopPanel().GetUIControl(23);
		spell2.rParentSpell = sParentSpell;
		return true;
	}

	if (pWiz->m_nMaxContSpells != 3) return false;

	if (pWiz->m_rContSpell3.IsEmpty()) {
		pWiz->m_rContSpell3 = sSpell;
		DETOUR_CUICheckButtonMageBookContSelected& spell3 = (DETOUR_CUICheckButtonMageBookContSelected&)pWiz->GetTopPanel().GetUIControl(24);
		spell3.rParentSpell = sParentSpell;
		return true;
	}

	return false;
}
