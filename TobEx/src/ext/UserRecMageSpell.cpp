#include "UserRecMageSpell.h"

#include "stdafx.h"
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
	ENUM eChar = ENUM_INVALID_INDEX;
	CInfGame* pGame = g_pChitin->pGame;
	CScreenRecord* pCharacter = g_pChitin->pCharacter;
	int nPlayerIdx = pCharacter->GetActivePlayerIdx();
	if (nPlayerIdx < pGame->numInParty) {
		eChar = pGame->ePlayersPartyOrder[nPlayerIdx];
	} else {
		eChar = ENUM_INVALID_INDEX;
	}

	CCreatureObject* pCre;
	char threadNum = THREAD_ASYNCH;
	char threadVal;
	do {
		threadVal = g_pChitin->pGame->m_GameObjectArray.GetDeny(eChar, threadNum, &pCre, INFINITE);
	} while (threadVal == OBJECT_SHARING || threadVal == OBJECT_DENYING);

	if (threadVal == OBJECT_SUCCESS) {
		g_pChitin->pCharacter->UpdatePanel(pPanel->index, *pCre);
		g_pChitin->pGame->m_GameObjectArray.FreeDeny(eChar, threadNum, INFINITE);
	}
	return;
}

CUIScrollBarRecMageSpell::~CUIScrollBarRecMageSpell() {
	cplTempSpells.RemoveAll();
}

void CUIScrollBarRecMageSpell::OnMouseDragKnob() {
	short nOld = nCurrentValue;
	if (nValues < nRows) {
		nCurrentValue = 0;
	} else {
		nCurrentValue = (nValues - nRows) * wKnobPosCurrent / wKnobPosMax;
	}
	if (nOld != nCurrentValue) UpdatePanel();
	return;
}

void CUIScrollBarRecMageSpell::OnLMouseBtnDnArrowUp() {
	short nOld = nCurrentValue;
	nCurrentValue = max(nCurrentValue - 1, 0);
	if (nOld != nCurrentValue) {
		UpdatePanel();
		UpdateKnobPosition(nCurrentValue, nValues, nRows);
	}
	return;
}

void CUIScrollBarRecMageSpell::OnLMouseBtnDnArrowDn() {
	short nOld = nCurrentValue;
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

void CUIScrollBarRecMageSpell::OnLClickedAboveKnob(short interval) {
	if (interval > 3 || interval < 0) interval = 3;
	short nOld = nCurrentValue;
	nCurrentValue = max(nCurrentValue - interval, 0);
	if (nOld != nCurrentValue) {
		UpdatePanel();
		UpdateKnobPosition(nCurrentValue, nValues, nRows);
	}
	return;
}

void CUIScrollBarRecMageSpell::OnLClickedBelowKnob(short interval) {
	if (interval > 3 || interval < 0) interval = 3;
	short nOld = nCurrentValue;
	if (nValues < nRows) {
		nCurrentValue = 0;
	} else {
		nCurrentValue = min(nCurrentValue + interval, nValues - nRows);
	}
	if (nOld != nCurrentValue) {
		UpdatePanel();
		UpdateKnobPosition(nCurrentValue, nValues, nRows);
	}
	return;
}