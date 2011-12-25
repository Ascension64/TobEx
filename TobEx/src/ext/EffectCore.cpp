#include "EffectCore.h"

#include "stdafx.h"
#include "chitin.h"
#include "options.h"
#include "effcore.h"
#include "effopcode.h"
#include "EffectOpcode.h"

CEffect& (*Tramp_CEffect_CreateEffect)(ITEM_EFFECT&, POINT&, Enum, POINT&, Enum) =
	SetFP(static_cast<CEffect& (*)(ITEM_EFFECT&, POINT&, Enum, POINT&, Enum)>	(&CEffect::CreateEffect),		0x4F3EC2);

CEffect& DETOUR_CEffect::DETOUR_CreateEffect(ITEM_EFFECT& eff, POINT& ptSource, Enum eSource, POINT& ptDest, Enum e2) {
	CEffect* pEffect = NULL;
	switch (eff.opcode) {
		case 0x13E:
			if (pGameOptionsEx->bEffOpcode13E) {
				pEffect = new CEffect13E(eff, ptSource, eSource, ptDest.x, ptDest.y, FALSE, e2);
			}
			break;
		default:
			break;
	}

	if (pEffect == NULL) {
		//Let the engine handle the standard opcodes
		pEffect = &Tramp_CEffect_CreateEffect(eff, ptSource, eSource, ptDest, e2);
	}

	if (pEffect != NULL) {
		switch (eff.opcode) {
		case CEFFECT_OPCODE_POISON:
			if (pGameOptionsEx->bEffPoisonFix) {
				pEffect->effect.nParam4 = g_pChitin->pGame->m_WorldTimer.nGameTime;
			}
			break;
		case CEFFECT_OPCODE_DISEASE:
			if (pGameOptionsEx->bEffDiseaseFix) {
				pEffect->effect.nParam4 = g_pChitin->pGame->m_WorldTimer.nGameTime;
			}
			break;
		case CEFFECT_OPCODE_REGENERATION:
			if (pGameOptionsEx->bEffRegenerationFix) {
				pEffect->effect.nParam4 = g_pChitin->pGame->m_WorldTimer.nGameTime;
			}
			break;
		default:
			break;
		}
	}

	return *pEffect;

}