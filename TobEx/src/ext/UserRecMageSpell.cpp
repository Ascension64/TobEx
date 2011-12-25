#include "UserRecMageSpell.h"

#include "utils.h"
#include "chitin.h"
#include "uicore.h"
#include "rescore.h"
#include "objcre.h"
#include "engine.h"
#include "UserCommon.h"
#include "console.h"

CUIScrollBarRecMageSpell::CUIScrollBarRecMageSpell(CPanel& panel, ChuFileControlInfoBase& controlInfo) : CUIScrollBar(panel, controlInfo) {
	nCurrentValue = 0;
	nValues = 0;
	nRows = 0;
}

void CUIScrollBarRecMageSpell::UpdatePanel() {
	Enum eChar = ENUM_INVALID_INDEX;
	CInfGame* pGame = g_pChitin->pGame;
	CRecord* pCharacter = g_pChitin->pCharacter;
	DWORD nPlayerIdx = pCharacter->GetActivePlayerIdx();
	if (nPlayerIdx < pGame->numInParty) {
		eChar = pGame->ePlayersPartyOrder[nPlayerIdx];
	} else {
		eChar = ENUM_INVALID_INDEX;
	}

	CCreatureObject* pCre;
	BYTE threadNum = THREAD_ASYNCH;
	BYTE threadVal;
	do {
		threadVal = g_pChitin->pGame->m_GameObjectArrayHandler.GetGameObjectDeny(eChar, threadNum, &pCre, INFINITE);
	} while (threadVal == OBJECT_SHARING || threadVal == OBJECT_DENYING);

	if (threadVal == OBJECT_SUCCESS) {
		g_pChitin->pCharacter->UpdatePanel(pPanel->index, *pCre);
		g_pChitin->pGame->m_GameObjectArrayHandler.FreeGameObjectDeny(eChar, threadNum, INFINITE);
	}
	return;
}

CUIScrollBarRecMageSpell::~CUIScrollBarRecMageSpell() {
	cplTempSpells.RemoveAll();
}

void CUIScrollBarRecMageSpell::OnMouseDragKnob() {
	WORD nOld = nCurrentValue;
	if (nValues < nRows) {
		nCurrentValue = 0;
	} else {
		nCurrentValue = (nValues - nRows) * wKnobPosCurrent / wKnobPosMax;
	}
	if (nOld != nCurrentValue) UpdatePanel();
	return;
}

void CUIScrollBarRecMageSpell::OnLMouseBtnDnArrowUp() {
	WORD nOld = nCurrentValue;
	nCurrentValue = max(nCurrentValue - 1, 0);
	if (nOld != nCurrentValue) {
		UpdatePanel();
		UpdateKnobPosition(nCurrentValue, nValues, nRows);
	}
	return;
}

void CUIScrollBarRecMageSpell::OnLMouseBtnDnArrowDn() {
	WORD nOld = nCurrentValue;
	if (nValues < nRows) {
		nCurrentValue = 0;
	} else {
		nCurrentValue = min(nCurrentValue + 1, nValues - nRows);
	}
	if (nOld != nCurrentValue) {
		UpdatePanel();
		UpdateKnobPosition(nCurrentValue, nValues, nRows);
	}
	return;
}

void CUIScrollBarRecMageSpell::OnLClickedAboveKnob(DWORD interval) {
	if (interval > 3) interval = 3;
	WORD nOld = nCurrentValue;
	nCurrentValue = max(nCurrentValue - (WORD)interval, 0);
	if (nOld != nCurrentValue) {
		UpdatePanel();
		UpdateKnobPosition(nCurrentValue, nValues, nRows);
	}
	return;
}

void CUIScrollBarRecMageSpell::OnLClickedBelowKnob(DWORD interval) {
	if (interval > 3) interval = 3;
	WORD nOld = nCurrentValue;
	if (nValues < nRows) {
		nCurrentValue = 0;
	} else {
		nCurrentValue = min(nCurrentValue + (WORD)interval, nValues - nRows);
	}
	if (nOld != nCurrentValue) {
		UpdatePanel();
		UpdateKnobPosition(nCurrentValue, nValues, nRows);
	}
	return;
}