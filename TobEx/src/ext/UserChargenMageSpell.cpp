#include "UserChargenMageSpell.h"

#include "stdafx.h"
#include "chitin.h"
#include "uicore.h"
#include "rescore.h"
#include "objcre.h"
#include "engine.h"
#include "UserCommon.h"

CUIScrollBarChargenMageSpell::CUIScrollBarChargenMageSpell(CPanel& panel, ChuFileControlInfoBase& controlInfo) : CUIScrollBar(panel, controlInfo) {
	nCurrentValue = 0;
	nValues = 0;
	nRows = 0;
}

void CUIScrollBarChargenMageSpell::UpdatePanel() {
	CCreatureObject* pCre;
	char threadNum = THREAD_ASYNCH;
	char threadVal;
	do {
		threadVal = g_pChitin->pGame->m_GameObjectArray.GetDeny(g_pChitin->pCreateChar->eChar, threadNum, &pCre, INFINITE);
	} while (threadVal == OBJECT_SHARING || threadVal == OBJECT_DENYING);

	if (threadVal == OBJECT_SUCCESS) {
		g_pChitin->pCreateChar->UpdatePanel(pPanel->index, *pCre);
		g_pChitin->pGame->m_GameObjectArray.FreeDeny(g_pChitin->pCreateChar->eChar, threadNum, INFINITE);
	}
	return;
}

CUIScrollBarChargenMageSpell::~CUIScrollBarChargenMageSpell() {
	cplTempSpells.RemoveAll();
}

void CUIScrollBarChargenMageSpell::OnMouseDragKnob() {
	short nOld = nCurrentValue;
	if (nValues < nRows) {
		nCurrentValue = 0;
	} else {
		nCurrentValue = (nValues - nRows) * wKnobPosCurrent / wKnobPosMax;
	}
	if (nOld != nCurrentValue) UpdatePanel();
	return;
}

void CUIScrollBarChargenMageSpell::OnLMouseBtnDnArrowUp() {
	short nOld = nCurrentValue;
	nCurrentValue = max(nCurrentValue - 1, 0);
	if (nOld != nCurrentValue) {
		UpdatePanel();
		UpdateKnobPosition(nCurrentValue, nValues, nRows);
	}
	return;
}

void CUIScrollBarChargenMageSpell::OnLMouseBtnDnArrowDn() {
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

void CUIScrollBarChargenMageSpell::OnLClickedAboveKnob(short interval) {
	if (interval > 3 || interval < 0) interval = 3;
	short nOld = nCurrentValue;
	nCurrentValue = max(nCurrentValue - interval, 0);
	if (nOld != nCurrentValue) {
		UpdatePanel();
		UpdateKnobPosition(nCurrentValue, nValues, nRows);
	}
	return;
}

void CUIScrollBarChargenMageSpell::OnLClickedBelowKnob(short interval) {
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