#include "EffectOpcode.h"

#include "utils.h"
#include "effopcode.h"
#include "effcore.h"
#include "infgame.h"
#include "msgcore.h"
#include "console.h"
#include "log.h"
#include "chitin.h"
#include "objcre.h"

BOOL (CEffectDamage::*Tramp_CEffectDamage_ApplyEffect)(CCreatureObject&) =
	SetFP(static_cast<BOOL (CEffectDamage::*)(CCreatureObject&)>			(&CEffectDamage::ApplyEffect),			0x505570);
BOOL (CEffectBlindness::*Tramp_CEffectBlindness_ApplyEffect)(CCreatureObject&) =
	SetFP(static_cast<BOOL (CEffectBlindness::*)(CCreatureObject&)>			(&CEffectBlindness::ApplyEffect),		0x51ADF9);
BOOL (CEffectMagicResistMod::*Tramp_CEffectMagicResistMod_ApplyEffect)(CCreatureObject&) =
	SetFP(static_cast<BOOL (CEffectMagicResistMod::*)(CCreatureObject&)>	(&CEffectMagicResistMod::ApplyEffect),	0x52EB97);
BOOL (CEffectCutScene2::*Tramp_CEffectCutScene2_ApplyEffect)(CCreatureObject&) =
	SetFP(static_cast<BOOL (CEffectCutScene2::*)(CCreatureObject&)>			(&CEffectCutScene2::ApplyEffect),		0x542815);

BOOL DETOUR_CEffectDamage::DETOUR_ApplyEffect(CCreatureObject& creTarget) {
	(this->*Tramp_CEffectDamage_ApplyEffect)(creTarget);

	//CEffectAwaken::ApplyEffect(creTarget)
	creTarget.m_BaseStats.stateFlags &= ~STATE_SLEEPING;
	creTarget.cdsCurrent.stateFlags &= ~STATE_SLEEPING;
	creTarget.EffectsEquipped.RemoveEffect(creTarget, CEFFECT_OPCODE_SLEEP, creTarget.EffectsEquipped.posItrPrev, -1, ResRef(), FALSE);
	creTarget.EffectsMain.RemoveEffect(creTarget, CEFFECT_OPCODE_SLEEP, creTarget.EffectsMain.posItrPrev, -1, ResRef(), FALSE);
	//bPurge = TRUE;

	return TRUE;
};

BOOL DETOUR_CEffectBlindness::DETOUR_ApplyEffect(CCreatureObject& creTarget) {

	/*original function
	if (timing == 1) {
		//permanent
		creTarget.m_BaseStats.stateFlags |= STATE_BLIND;
		creTarget.cdsCurrent.stateFlags |= STATE_BLIND;
		creTarget.m_BaseStats.THAC0 -= (-10);
		creTarget.cdsCurrent.THAC0 -= (-10);
		bPurge = TRUE;
	} else {
		//limited
		creTarget.cdsCurrent.stateFlags |= STATE_BLIND;
		creTarget.cdsCurrent.THAC0 -= (-10);
	}*/

	//Remove cumulative penalty
	if (GetIniValue("Effect Opcodes", "Blindness Fix") == 1) {
		if (effect.nTiming == 1) {
			//permanent
			if (!(creTarget.m_BaseStats.stateFlags & STATE_BLIND)) creTarget.m_BaseStats.THAC0 -= (-10);
			creTarget.m_BaseStats.stateFlags |= STATE_BLIND;
			if (!(creTarget.cdsCurrent.stateFlags & STATE_BLIND)) creTarget.cdsCurrent.THAC0 -= (-10);
			creTarget.cdsCurrent.stateFlags |= STATE_BLIND;
		
			bPurge = TRUE;
		} else {
			//limited
			if (!(creTarget.cdsCurrent.stateFlags & STATE_BLIND)) creTarget.cdsCurrent.THAC0 -= (-10);
			creTarget.cdsCurrent.stateFlags |= STATE_BLIND;
		}

		return TRUE;
	}

	//Change to game description
	if (GetIniValue("Effect Opcodes", "Blindness Fix") == 2) {
		if (effect.nTiming == 1) {
			//permanent
			if (!(creTarget.m_BaseStats.stateFlags & STATE_BLIND)) {
				creTarget.m_BaseStats.THAC0 -= (-4);
				creTarget.m_BaseStats.ACEffective = min(20, creTarget.m_BaseStats.ACEffective - (-4));
			}
			creTarget.m_BaseStats.stateFlags |= STATE_BLIND;
			if (!(creTarget.cdsCurrent.stateFlags & STATE_BLIND)) {
				creTarget.cdsCurrent.THAC0 -= (-4);
			}
			creTarget.cdsCurrent.stateFlags |= STATE_BLIND;
		
			bRefreshCurrentState = TRUE;
			bPurge = TRUE;
		} else {
			//limited
			if (!(creTarget.cdsCurrent.stateFlags & STATE_BLIND)) {
				creTarget.cdsCurrent.THAC0 -= (-4);
				creTarget.cdsDiff.ACEffective -= (-4);
			}
			creTarget.cdsCurrent.stateFlags |= STATE_BLIND;

			bPurge = FALSE;
		}

		return TRUE;
	}

	return true;
}

BOOL DETOUR_CEffectMagicResistMod::DETOUR_ApplyEffect(CCreatureObject& creTarget) {

	/*original function
	switch (effect.nParam2) {
		case 0:
			//sum
			creTarget.cdsCurrent.resistMagic += effect.nParam1;
			break;
		case 1:
			//set
			creTarget.cdsCurrent.resistMagic = effect.nParam1;
			break;
		default:
			break;
	}*/

	switch (effect.nParam2) {
		case 0:
			//sum
			if (effect.nTiming == 1) {
				creTarget.m_BaseStats.resistMagic += effect.nParam1;
				creTarget.m_BaseStats.resistMagic = min(creTarget.m_BaseStats.resistMagic, 100);
				creTarget.m_BaseStats.resistMagic = max(creTarget.m_BaseStats.resistMagic, 0);
				bRefreshCurrentState = TRUE;
				bPurge = TRUE;
			} else {
				creTarget.cdsDiff.resistMagic += effect.nParam1;
				bPurge = TRUE;
			}
			break;
		case 1:
			//set
			if (effect.nTiming == 1) {
				creTarget.m_BaseStats.resistMagic = effect.nParam1;
				creTarget.m_BaseStats.resistMagic = min(creTarget.m_BaseStats.resistMagic, 100);
				creTarget.m_BaseStats.resistMagic = max(creTarget.m_BaseStats.resistMagic, 0);
				bRefreshCurrentState = TRUE;
				bPurge = TRUE;
			} else {
				creTarget.cdsCurrent.resistMagic = effect.nParam1;
				creTarget.cdsCurrent.resistMagic = min(creTarget.cdsCurrent.resistMagic, 100);
				creTarget.cdsCurrent.resistMagic = max(creTarget.cdsCurrent.resistMagic, 0);
				bPurge = FALSE;
			}
			break;
		case 2:
			//percentage
			if (effect.nTiming == 1) {
				creTarget.m_BaseStats.resistMagic = (creTarget.m_BaseStats.resistMagic * effect.nParam1) / 100;
				creTarget.m_BaseStats.resistMagic = min(creTarget.m_BaseStats.resistMagic, 100);
				creTarget.m_BaseStats.resistMagic = max(creTarget.m_BaseStats.resistMagic, 0);
				bRefreshCurrentState = TRUE;
				bPurge = TRUE;
			} else {
				creTarget.cdsCurrent.resistMagic = (creTarget.m_BaseStats.resistMagic * effect.nParam1) / 100;
				creTarget.cdsCurrent.resistMagic = min(creTarget.m_BaseStats.resistMagic, 100);
				creTarget.cdsCurrent.resistMagic = max(creTarget.m_BaseStats.resistMagic, 0);
				bPurge = FALSE;
			}
			break;
		default:
			LPCTSTR lpsz = "DETOUR_CEffectMagicResistMod::ApplyEffect(): invalid effect.nParam2 (%d)\r\n";
			console.write(lpsz, 1, effect.nParam2);
			L.timestamp();
			L.append(lpsz, 1, effect.nParam2);
			break;
	}
	return TRUE;
}

BOOL DETOUR_CEffectCutScene2::DETOUR_ApplyEffect(CCreatureObject& creTarget) {
	CInfGame* pGame = g_pChitin->pGame;
	CInfGame::CGameSave* pGameSave = &pGame->m_GameSave;

	if (pGameSave->mode == 0x1016E || pGameSave->mode == 0x3016E) {
		bPurge = TRUE;
		return TRUE;
	}

	switch (effect.nParam1) {
		case 1:
			//Use StorePartyLocations() list
			pGame->StorePartyLocations(FALSE);
			break;
		case 2:
			//Do not store party member locations
			break;
		case 0:
		default:
			//Use pocket plane list
			pGame->StorePartyLocations(TRUE);
			break;
	}

	CMessageCutSceneMode* pcmCSM = IENew CMessageCutSceneMode();
	pcmCSM->eTarget = creTarget.e;
	pcmCSM->eSource = creTarget.e;
	pcmCSM->bEnable = true;
	g_pChitin->messages.Send(*pcmCSM, FALSE);

	CMessageAddAction* pcmA = IENew CMessageAddAction();
	pcmA->eTarget = pGame->ePlayersPartyOrder[0];
	pcmA->eSource = pGame->ePlayersPartyOrder[0];
	pcmA->a.opcode = 120; //StartCutScene
	pcmA->a.sName1 = effect.nParam2 ? IECString(effect.rResource.GetBuffer()) : "cut250a";
	pcmA->a.dwFlags |= 1;
	g_pChitin->messages.Send(*pcmA, FALSE);

	bPurge = TRUE;
	return TRUE;
}

CEffect13E::CEffect13E(ITEM_EFFECT& data, POINT& ptSource, Enum eSource, DWORD destX, DWORD destY, BOOL bUseDice, Enum e2) \
	: CEffect(data, ptSource, eSource, destX, destY, bUseDice, e2) {}

CEffect& CEffect13E::Duplicate() {
	CEffect13E* pceff = new CEffect13E(ToItemEffect(), effect.ptSource, eSource, effect.nDestX, effect.nDestY, FALSE, ENUM_INVALID_INDEX);
	pceff->Unmarshal(effect);
	return *pceff;
}

BOOL CEffect13E::ApplyEffect(CCreatureObject& creTarget) {
	CMessageDisplayText* pcmDT = IENew CMessageDisplayText();
	pcmDT->eTarget = creTarget.e;
	pcmDT->eSource = creTarget.e;
	pcmDT->sLeft = "TobEx";
	pcmDT->sRight = "Applied effect 0x13E via AddMessage()";
	pcmDT->rgbLeft = 0x239526;
	pcmDT->rgbRight = 0x728460;
	pcmDT->bFloatText = TRUE;

	g_pChitin->messages.Send(*pcmDT, FALSE);

	ThisCall((void*)0x7DDE63, g_pChitin->pWorld, &IECString("TobEx"), &IECString("Applied effect 0x13E directly through GUIW"), (void*)0x00239526, (void*)0x00ab3fec, (void*)-1, (void*)0);

	return TRUE;
}