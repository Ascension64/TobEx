#include "UserChargenKit.h"

#include <cassert>

#include "stdafx.h"
#include "uicore.h"
#include "objcre.h"
#include "chitin.h"
#include "rescore.h"
#include "console.h"

static int currKitNum = 0;

CUIScrollBarChargenKit::CUIScrollBarChargenKit(CPanel& panel, ChuFileControlInfoBase& controlInfo) : CUIScrollBar(panel, controlInfo) {
	nCurrentValue = 0;
	nValues = 0;
	nRows = 0;
}

void CUIScrollBarChargenKit::UpdatePanel() {
	CCreatureObject* pCre;
	char threadNum = THREAD_ASYNCH;
	char threadVal;
	do {
		threadVal = g_pChitin->pGame->m_GameObjectArrayHandler.GetGameObjectDeny(g_pChitin->pCreateChar->eChar, threadNum, &pCre, INFINITE);
	} while (threadVal == OBJECT_SHARING || threadVal == OBJECT_DENYING);

	if (threadVal == OBJECT_SUCCESS) {
		g_pChitin->pCreateChar->UpdatePanel(pPanel->index, *pCre);
		g_pChitin->pGame->m_GameObjectArrayHandler.FreeGameObjectDeny(g_pChitin->pCreateChar->eChar, threadNum, INFINITE);
	}
	return;
}

CUIScrollBarChargenKit::~CUIScrollBarChargenKit() {}

void CUIScrollBarChargenKit::OnMouseDragKnob() {
	short nOld = nCurrentValue;
	if (nValues < nRows) {
		nCurrentValue = 0;
	} else {
		nCurrentValue = (nValues - nRows) * wKnobPosCurrent / wKnobPosMax;
	}
	if (nOld != nCurrentValue) UpdatePanel();
	return;
}

void CUIScrollBarChargenKit::OnLMouseBtnDnArrowUp() {
	short nOld = nCurrentValue;
	nCurrentValue = max(nCurrentValue - 1, 0);
	if (nOld != nCurrentValue) {
		UpdatePanel();
		UpdateKnobPosition(nCurrentValue, nValues, nRows);
	}
	return;
}

void CUIScrollBarChargenKit::OnLMouseBtnDnArrowDn() {
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

void CUIScrollBarChargenKit::OnLClickedAboveKnob(short interval) {
	if (interval > 10 || interval < 0) interval = 10;
	short nOld = nCurrentValue;
	nCurrentValue = max(nCurrentValue - interval, 0);
	if (nOld != nCurrentValue) {
		UpdatePanel();
		UpdateKnobPosition(nCurrentValue, nValues, nRows);
	}
	return;
}

void CUIScrollBarChargenKit::OnLClickedBelowKnob(short interval) {
	if (interval > 10 || interval < 0) interval = 10;
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