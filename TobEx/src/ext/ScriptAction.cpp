#include "ScriptAction.h"

#include "stdafx.h"
#include "objcre.h"
#include "effcore.h"
#include "msgcore.h"
#include "chitin.h"

void __stdcall CCreatureObject_ForceVisible(CCreatureObject& creSource) {
	//In function int CCreatureObject::PickPocket(CCreatureObject& creTarget)
	CDerivedStats& cds = creSource.GetDerivedStats();

	if (cds.stateFlags & STATE_INVISIBLE) {
		ITEM_EFFECT eff;
		CEffect::CreateItemEffect(eff, 0x88); //Invisible opcode

		POINT dest = {-1, -1};

		CEffect& ceff = CEffect::CreateEffect(eff, creSource.m_currentLoc, creSource.e, dest, ENUM_INVALID_INDEX);

		CMessageApplyEffect* pcmAE = IENew CMessageApplyEffect();
		pcmAE->eTarget = creSource.e;
		pcmAE->eSource = creSource.e;
		pcmAE->pCEffect = &ceff;
		pcmAE->u10 = 0;
		g_pChitin->messages.Send(*pcmAE, FALSE);

	}

	return;
}