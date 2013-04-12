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

//CUIButtonMageBookUp
int CUIButtonMageBook_KnownSpellOffset = 0;

CUIButtonMageBookUp::CUIButtonMageBookUp(CPanel& panel, ChuFileControlInfoBase& controlInfo) : CUIButton(panel, controlInfo, 1, TRUE) {}
CUIButtonMageBookUp::~CUIButtonMageBookUp() {}

void CUIButtonMageBookUp::OnLClicked(CPoint pt) {
	CScreenMageBook* pWizSpell = g_pChitin->pWizSpell;
	CPanel& panel = pWizSpell->manager.GetPanel(2);

	CInfGame* pGame = g_pChitin->pGame;
	ENUM e;

	if (pWizSpell->nActivePlayerIdx < pGame->numInParty) {
		e = pGame->ePlayersPartyOrder[pWizSpell->nActivePlayerIdx];
	} else {
		e = ENUM_INVALID_INDEX;
	}

	CCreatureObject* pCre;
	char threadVal;
	do {
		threadVal = pGame->m_GameObjectArray.GetShare(e, THREAD_ASYNCH, &pCre, INFINITE);
	} while (threadVal == OBJECT_SHARING || threadVal == OBJECT_DENYING);

	if (threadVal == OBJECT_SUCCESS) {
		CUIButtonMageBook_KnownSpellOffset = max(CUIButtonMageBook_KnownSpellOffset - 4, 0);

		for (int i = 27; i <= 50; i++ ) {
			CUIButtonMageBookKnownSpell& control = (CUIButtonMageBookKnownSpell&)panel.GetUIControl(i);
			CreFileKnownSpell& kspell = pCre->GetKnownSpellMage(pWizSpell->currLevel, i - 27 + CUIButtonMageBook_KnownSpellOffset);
			&kspell ? control.SetSpell(kspell.m_rKnownSpellName) : control.SetSpell(ResRef());
			control.SetRedraw();
		}
		pGame->m_GameObjectArray.FreeShare(e, THREAD_ASYNCH, INFINITE);
	} else {
		LPCTSTR lpsz = "CUIButtonMageBookUp::OnLClicked(): GetShare returned %d\r\n";
		console.writef(lpsz, threadVal);
		L.timestamp();
		L.appendf(lpsz, threadVal);
	}

	return;
}

//CUIButtonMageBookDn
CUIButtonMageBookDn::CUIButtonMageBookDn(CPanel& panel, ChuFileControlInfoBase& controlInfo) : CUIButton(panel, controlInfo, 1, TRUE) {}
CUIButtonMageBookDn::~CUIButtonMageBookDn() {}

void CUIButtonMageBookDn::OnLClicked(CPoint pt) {
	CScreenMageBook* pWizSpell = g_pChitin->pWizSpell;
	CPanel& panel = pWizSpell->manager.GetPanel(2);

	CInfGame* pGame = g_pChitin->pGame;
	ENUM e;

	if (pWizSpell->nActivePlayerIdx < pGame->numInParty) {
		e = pGame->ePlayersPartyOrder[pWizSpell->nActivePlayerIdx];
	} else {
		e = ENUM_INVALID_INDEX;
	}

	CCreatureObject* pCre;
	char threadVal;
	do {
		threadVal = pGame->m_GameObjectArray.GetShare(e, THREAD_ASYNCH, &pCre, INFINITE);
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
			&kspell ? control.SetSpell(kspell.m_rKnownSpellName) : control.SetSpell(ResRef());
			control.SetRedraw();
		}

		pGame->m_GameObjectArray.FreeShare(e, THREAD_ASYNCH, INFINITE);
	} else {
		LPCTSTR lpsz = "CUIButtonMageBookDn::OnLClicked(): GetShare returned %d\r\n";
		console.writef(lpsz, threadVal);
		L.timestamp();
		L.appendf(lpsz, threadVal);
	}

	return;
}

//CUICheckButtonMageBookContChoice
DefineTrampMemberFunc(CUICheckButtonMageBookContChoice&, CUICheckButtonMageBookContChoice, Construct, (CPanel& panel, ChuFileControlInfoBase& controlInfo), Construct, Construct2, 0x7C124D);
DefineTrampMemberFunc(void, CUICheckButtonMageBookContChoice, OnLClicked, (CPoint pt), OnLClicked, OnLClicked, 0x7C1304);

CUICheckButtonMageBookContChoice& DETOUR_CUICheckButtonMageBookContChoice::DETOUR_Construct(CPanel& panel, ChuFileControlInfoBase& controlInfo) {
	(this->*Tramp_CUICheckButtonMageBookContChoice_Construct2)(panel, controlInfo);
	rParentSpell = "";
	return *this;
}

void DETOUR_CUICheckButtonMageBookContChoice::DETOUR_OnLClicked(CPoint pt) {
	CScreenMageBook* pWizSpell = g_pChitin->pWizSpell;
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
				if (CScreenMageBook_AddContingencySpellEx(pWizSpell, sSpell, sParentSpell)) {
					pWizSpell->SetSpellContingencyState(rParentSpell.IsEmpty() ? sSpell : sParentSpell, FALSE);
				}
				ResSplFile resSpell(rSpell);
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

//CUICheckButtonMageBookContSelected
DefineTrampMemberFunc(CUICheckButtonMageBookContSelected&, CUICheckButtonMageBookContSelected, Construct, (CPanel& panel, ChuFileControlInfoBase& controlInfo), Construct, Construct2, 0x7C0CAC);
DefineTrampMemberFunc(void, CUICheckButtonMageBookContSelected, OnLClicked, (CPoint pt), OnLClicked, OnLClicked, 0x7C0D56);

CUICheckButtonMageBookContSelected& DETOUR_CUICheckButtonMageBookContSelected::DETOUR_Construct(CPanel& panel, ChuFileControlInfoBase& controlInfo) {
	(this->*Tramp_CUICheckButtonMageBookContSelected_Construct2)(panel, controlInfo);
	rParentSpell = "";
	return *this;
}

void DETOUR_CUICheckButtonMageBookContSelected::DETOUR_OnLClicked(CPoint pt) {
	CScreenMageBook* pWizSpell = g_pChitin->pWizSpell;
	pWizSpell->SetSpellContingencyState(rParentSpell.IsEmpty() ? IECString(rSpell.GetBuffer()) : IECString(rParentSpell.GetBuffer()), TRUE);
	pWizSpell->ClearContingencySpell(index - 22);
	pWizSpell->ContingencySelectOnUpdate(pPanel->index);
	return;
}

bool __stdcall CScreenMageBook_AddContingencySpellEx(CScreenMageBook* pWiz, IECString sSpell, IECString sParentSpell) {
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
