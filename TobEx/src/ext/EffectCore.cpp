#include "EffectCore.h"

#include "stdafx.h"
#include "chitin.h"
#include "options.h"
#include "effcore.h"
#include "effopcode.h"
#include "EffectCommon.h"
#include "EffectOpcode.h"
#include "console.h"
#include "log.h"

CEffect& (*Tramp_CEffect_CreateEffect)(ITEM_EFFECT&, POINT&, Enum, POINT&, Enum) =
	SetFP(static_cast<CEffect& (*)(ITEM_EFFECT&, POINT&, Enum, POINT&, Enum)>	(&CEffect::CreateEffect),		0x4F3EC2);
BOOL (CEffect::*Tramp_CEffect_IsExpired)() =
	SetFP(static_cast<BOOL (CEffect::*)()>										(&CEffect::IsExpired),			0x500517);
BOOL (CEffect::*Tramp_CEffect_ApplyTiming)(CCreatureObject&) =
	SetFP(static_cast<BOOL (CEffect::*)(CCreatureObject&)>						(&CEffect::ApplyTiming),		0x4FFFA0);

BOOL (CEffectList::*Tramp_CEffectList_ApplyEffects)(CCreatureObject&) =
	SetFP(static_cast<BOOL (CEffectList::*)(CCreatureObject&)>					(&CEffectList::ApplyEffects),	0x544C0B);

CEffect& DETOUR_CEffect::DETOUR_CreateEffect(ITEM_EFFECT& eff, POINT& ptSource, Enum eSource, POINT& ptDest, Enum e2) {
	if (0) IECString("DETOUR_CEffect::DETOUR_CreateEffect");

	CEffect* pEffect = NULL;
	switch (eff.opcode) {
	case CEFFECT_OPCODE_SET_STAT: //0x13E
		if (pGameOptionsEx->bEngineExpandedStats) pEffect = new CEffectSetStat(eff, ptSource, eSource, ptDest.x, ptDest.y, FALSE, e2);
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

BOOL DETOUR_CEffect::DETOUR_ApplyTiming(CCreatureObject& creTarget) {
	if (0) IECString("DETOUR_CEffect::DETOUR_ApplyTiming");

	if (creTarget.o.IsNonScript()) return FALSE;

	switch (effect.nTiming) {
	case 0x1000: //apply until expired
		if (g_pChitin->pGame->m_WorldTimer.nGameTime >= effect.nDuration) {
			bPurge = TRUE;
			return TRUE;
		}
		break;
	case 0: //apply, set expiry time (duration in sec)
		effect.nTiming = 0x1000;
		effect.nDuration = min(effect.nDuration, EFFECT_DURATION_MAX);
		effect.nDuration = effect.nDuration * 15 + g_pChitin->pGame->m_WorldTimer.nGameTime;
		break;
	case 10: //apply, set expiry time (duration in ticks)
		effect.nDuration = effect.nDuration * 15 + g_pChitin->pGame->m_WorldTimer.nGameTime;
		break;
	case 3: //set expiry time (duration in sec)
		effect.nTiming = 6;
		effect.nDuration = min(effect.nDuration, EFFECT_DURATION_MAX);
		effect.nDuration = effect.nDuration * 15 + g_pChitin->pGame->m_WorldTimer.nGameTime;
		return TRUE;
		break;
	case 4: //set expiry time (duration in sec)
		effect.nTiming = 7;
		effect.nDuration = min(effect.nDuration, EFFECT_DURATION_MAX);
		effect.nDuration = effect.nDuration * 15 + g_pChitin->pGame->m_WorldTimer.nGameTime;
		return TRUE;
		break;
	case 5:
		effect.nTiming = 8;
		effect.nDuration = min(effect.nDuration, EFFECT_DURATION_MAX);
		effect.nDuration = effect.nDuration * 15 + g_pChitin->pGame->m_WorldTimer.nGameTime;
		return TRUE;
		break;
	case 6: //end delay if expired, then apply, set expiry time (duration in sec)
		if (g_pChitin->pGame->m_WorldTimer.nGameTime >= effect.nDuration) {
			effect.nTiming = 0x1000;
			effect.nDuration = min(nDurationAfterDelay, EFFECT_DURATION_MAX);
			effect.nDuration = nDurationAfterDelay * 15 + g_pChitin->pGame->m_WorldTimer.nGameTime;
			OnDelayFinished(creTarget);
			PrintEffectText(creTarget);
			break;
		} else {
			return TRUE;
		}
		break;
	case 7: //end delay if expired, then apply
		if (g_pChitin->pGame->m_WorldTimer.nGameTime >= effect.nDuration) {
			effect.nTiming = 1;
			OnDelayFinished(creTarget);
			PrintEffectText(creTarget);
			break;
		} else {
			return TRUE;
		}
		break;
	case 8: //end delay if expired, then apply
		if (g_pChitin->pGame->m_WorldTimer.nGameTime >= effect.nDuration) {
			effect.nTiming = 2;
			OnDelayFinished(creTarget);
			PrintEffectText(creTarget);
			break;
		} else {
			return TRUE;
		}
		break;
	default:
		break;
	}

	BOOL bSimilarEffectExists = FALSE;
	CEffectList& listEquipped = creTarget.GetEquippedEffectsList();
	CEffectList& listMain = creTarget.GetMainEffectsList();
	CEffect* pFound = NULL;
	if (pGameOptionsEx->bEngineModifyEffectStacking) {
		pFound = CEffectList_Find(listEquipped, *this, listEquipped.GetCurrentPosition(), creTarget);
		if (pFound == NULL) pFound = CEffectList_Find(listMain, *this, listMain.GetCurrentPosition(), creTarget);
		if (pFound != NULL) bSimilarEffectExists = TRUE;
	
		if (bSimilarEffectExists) {
			effect.nSaveType |= EFFECT_STACKING_SUSPEND;
			if (pGameOptionsEx->bDebugVerbose) {
				LPCTSTR lpsz = "[DETOUR]CEffect::ApplyTiming(): 0x%X suspended (similar to 0x%x)\r\n";
				console.write(lpsz, 2, (DWORD)this, (DWORD)pFound);
				L.timestamp();
				L.append(lpsz, 2, (DWORD)this, (DWORD)pFound);
			}
			return TRUE;
		} else {
			if (effect.nSaveType & EFFECT_STACKING_SUSPEND) {
				if (pGameOptionsEx->bDebugVerbose) {
					LPCTSTR lpsz = "[DETOUR]CEffect::ApplyTiming(): 0x%X unsuspended\r\n";
					console.write(lpsz, 1, (DWORD)this);
					L.timestamp();
					L.append(lpsz, 1, (DWORD)this);
				}
				effect.nSaveType &= ~(EFFECT_STACKING_SUSPEND);
			}
		}
	}

	return ApplyEffect(creTarget);
};