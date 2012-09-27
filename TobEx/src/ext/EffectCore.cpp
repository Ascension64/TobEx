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
BOOL (CEffect::*Tramp_CEffect_ApplyTiming)(CCreatureObject&) =
	SetFP(static_cast<BOOL (CEffect::*)(CCreatureObject&)>						(&CEffect::ApplyTiming),		0x4FFFA0);

BOOL (CEffect::*Tramp_CEffect_CheckNotSaved)(CCreatureObject&, char&, char&, char&, char&, char&, char&) =
	SetFP(static_cast<BOOL (CEffect::*)(CCreatureObject&, char&, char&, char&, char&, char&, char&)>(&CEffect::CheckNotSaved),		0x501B29);
void (CEffectList::*Tramp_CEffectList_TryDispel)(CCreatureObject&, POSITION, BOOL, BOOL, char, char) =
	SetFP(static_cast<void (CEffectList::*)(CCreatureObject&, POSITION, BOOL, BOOL, char, char)>	(&CEffectList::TryDispel),	0x543EC8);

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
		effect.nDuration = min(effect.nDuration, CEFFECT_DURATION_MAX);
		effect.nDuration = effect.nDuration * 15 + g_pChitin->pGame->m_WorldTimer.nGameTime;
		break;
	case 10: //apply, set expiry time (duration in ticks)
		effect.nDuration = effect.nDuration * 15 + g_pChitin->pGame->m_WorldTimer.nGameTime;
		break;
	case 3: //set expiry time (duration in sec)
		effect.nTiming = 6;
		effect.nDuration = min(effect.nDuration, CEFFECT_DURATION_MAX);
		effect.nDuration = effect.nDuration * 15 + g_pChitin->pGame->m_WorldTimer.nGameTime;
		return TRUE;
		break;
	case 4: //set expiry time (duration in sec)
		effect.nTiming = 7;
		effect.nDuration = min(effect.nDuration, CEFFECT_DURATION_MAX);
		effect.nDuration = effect.nDuration * 15 + g_pChitin->pGame->m_WorldTimer.nGameTime;
		return TRUE;
		break;
	case 5:
		effect.nTiming = 8;
		effect.nDuration = min(effect.nDuration, CEFFECT_DURATION_MAX);
		effect.nDuration = effect.nDuration * 15 + g_pChitin->pGame->m_WorldTimer.nGameTime;
		return TRUE;
		break;
	case 6: //end delay if expired, then apply, set expiry time (duration in sec)
		if (g_pChitin->pGame->m_WorldTimer.nGameTime >= effect.nDuration) {
			effect.nTiming = 0x1000;
			effect.nDuration = min(nDurationAfterDelay, CEFFECT_DURATION_MAX);
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
				console.writef(lpsz, (DWORD)this, (DWORD)pFound);
				L.timestamp();
				L.appendf(lpsz, (DWORD)this, (DWORD)pFound);
			}
			return TRUE;
		} else {
			if (effect.nSaveType & EFFECT_STACKING_SUSPEND) {
				if (pGameOptionsEx->bDebugVerbose) {
					LPCTSTR lpsz = "[DETOUR]CEffect::ApplyTiming(): 0x%X unsuspended\r\n";
					console.writef(lpsz, (DWORD)this);
					L.timestamp();
					L.appendf(lpsz, (DWORD)this);
				}
				effect.nSaveType &= ~(EFFECT_STACKING_SUSPEND);
			}
		}
	}

	return ApplyEffect(creTarget);
}

BOOL DETOUR_CEffect::DETOUR_CheckNotSaved(CCreatureObject& creTarget, char& rollSaveDeath, char& rollSaveWands, char& rollSavePoly, char& rollSaveBreath, char& rollSaveSpells, char& rollMagicResist) {
	if (0) IECString("DETOUR_CEffect::DETOUR_CheckNotSaved");

	char cRollSaveDeath = rollSaveDeath & ~CRESAVE_USED;
	char cRollSaveWands = rollSaveWands & ~CRESAVE_USED;
	char cRollSavePoly = rollSavePoly & ~CRESAVE_USED;
	char cRollSaveBreath = rollSaveBreath & ~CRESAVE_USED;
	char cRollSaveSpells = rollSaveSpells & ~CRESAVE_USED;
	char cRollMagicResist = rollMagicResist & ~CRESAVE_USED;

	short wSaveRollTotal = 0;
	BOOL bSavedVsType = FALSE;
	STRREF srSuccessSave;
	CDerivedStats& cdsTarget = creTarget.GetDerivedStats();

	//Mirror images and stone skins ignore checking saves
	//Unless poison effects
	if (effect.nOpcode == CEFFECT_OPCODE_POISON) {
		if (creTarget.m_nMirrorImages > 0 ||
			creTarget.GetDerivedStats().m_nStoneSkins > 0 ||
			creTarget.GetDerivedStats().m_StoneSkinGolem > 0) {
			return FALSE;
		}
	}
	if (effect.nOpcode == CEFFECT_OPCODE_DISPLAY_ICON &&
		effect.nParam2 == 6) { //ICON_POISONED
		if (creTarget.m_nMirrorImages > 0 ||
			creTarget.GetDerivedStats().m_nStoneSkins > 0 ||
			creTarget.GetDerivedStats().m_StoneSkinGolem > 0) {
			return FALSE;
		}
	}

	short wSaveThreshold = 20; //if multiple save types, checks against the easiest save type

	//Magic Resistance
	if (!(effect.dwFlags & CEFFECT_FLAG_IGNORE_RESISTANCE) &&
		cdsTarget.resistMagic > cRollMagicResist && //threshold > roll
		effect.dwFlags & CEFFECT_FLAG_DISPELLABLE) {
		if (!(cRollMagicResist & CRESAVE_USED)) {
			CMessageDisplayDialogue* pMDD = IENew CMessageDisplayDialogue();
			pMDD->eTarget = creTarget.e;
			pMDD->eSource = creTarget.e;
			pMDD->srOwner = creTarget.GetLongNameStrRef();
			pMDD->srText = 19224; //'Magic Resistance'
			pMDD->rgbOwner = g_ColorDefaultText;
			pMDD->rgbText = g_ColorDefaultText;
			pMDD->u1c = -1;
			pMDD->u20 = 0;
			pMDD->bFloatText = false;
			pMDD->u22 = 0;
			pMDD->bPlaySound = true;

			g_pChitin->messages.Send(*pMDD, FALSE);
			rollMagicResist |= CRESAVE_USED;
		}

		return FALSE;
	}

	//Modified from vanilla, use only the lowest char
	if ((effect.nSaveType & 0xFF) == CEFFECT_SAVETYPE_NONE) return TRUE;

	if (pGameOptionsEx->bEffSavingThrowFix) {
		char cSaveTypeUsed = 0;

		//determine best saving throw
		if (effect.nSaveType & CEFFECT_SAVETYPE_DEATH &&
			!(rollSaveDeath & CRESAVE_USED)) {
			if (cdsTarget.saveDeath < wSaveThreshold) {
				wSaveRollTotal = cRollSaveDeath;
				wSaveThreshold = cdsTarget.saveDeath;
				srSuccessSave = 14009;
				cSaveTypeUsed = 1;
			}
		}
		if (effect.nSaveType & CEFFECT_SAVETYPE_WANDS &&
			!(rollSaveWands & CRESAVE_USED)) {
			if (cdsTarget.saveWands < wSaveThreshold) {
				wSaveRollTotal = cRollSaveWands;
				wSaveThreshold = cdsTarget.saveWands;
				srSuccessSave = 14006;
				cSaveTypeUsed = 2;
			}
		}
		if (effect.nSaveType & CEFFECT_SAVETYPE_POLYMORPH &&
			!(rollSavePoly & CRESAVE_USED)) {
			if (cdsTarget.savePoly < wSaveThreshold) {
				wSaveRollTotal = cRollSavePoly;
				wSaveThreshold = cdsTarget.savePoly;
				srSuccessSave = 14005;
				cSaveTypeUsed = 3;
			}
		}
		if (effect.nSaveType & CEFFECT_SAVETYPE_BREATH &&
			!(rollSaveBreath & CRESAVE_USED)) {
			if (cdsTarget.saveBreath < wSaveThreshold) {
				wSaveRollTotal = cRollSaveBreath;
				wSaveThreshold = cdsTarget.saveBreath;
				srSuccessSave = 14004;
				cSaveTypeUsed = 4;
			}
		}
		if (effect.nSaveType & CEFFECT_SAVETYPE_SPELLS &&
			!(rollSaveSpells & CRESAVE_USED)) {
			if (cdsTarget.saveSpell < wSaveThreshold) {
				wSaveRollTotal = cRollSaveSpells;
				wSaveThreshold = cdsTarget.saveSpell;
				srSuccessSave = 14003;
				cSaveTypeUsed = 5;
			}
		}

		switch (cSaveTypeUsed) {
		case 1: //death
			rollSaveDeath |= CRESAVE_USED;
			bSavedVsType = TRUE;
			break;
		case 2: //wands
			rollSaveWands |= CRESAVE_USED;
			bSavedVsType = TRUE;
			break;
		case 3: //poly
			rollSavePoly |= CRESAVE_USED;
			bSavedVsType = TRUE;
			break;
		case 4: //breath
			rollSaveBreath |= CRESAVE_USED;
			bSavedVsType = TRUE;
			break;
		case 5: //spells
			rollSaveSpells |= CRESAVE_USED;
			bSavedVsType = TRUE;
			break;
		default: //none
			break;
		}

		//apply modifiers to roll
		wSaveRollTotal += effect.nSaveBonus;

		if (g_pChitin->pGame->GetMageSchool(creTarget.m_BaseStats.kit[1]) == effect.nType1) {
			wSaveRollTotal += 2;
		}

		CCreatureObject* pCreSource = NULL;
		char returnVal;
		do {
			returnVal = g_pChitin->pGame->m_GameObjectArrayHandler.GetGameObjectShare(eSource, THREAD_ASYNCH, &pCreSource, INFINITE);
		} while (returnVal == OBJECT_SHARING || returnVal == OBJECT_DENYING);
		if (returnVal == OBJECT_SUCCESS) {
			if (pCreSource->GetType() == CGAMEOBJECT_TYPE_CREATURE) {
				wSaveRollTotal += creTarget.GetDerivedStats().m_SaveBonusVsObject.GetModValue(pCreSource->GetCurrentObject());

				//improved invis saving throw bonus inserted here
				if (!pCreSource->CanSeeInvisible() &&
					cdsTarget.stateFlags & STATE_IMPROVEDINVISIBILITY) {
					wSaveRollTotal += 4;
				}

			}
			returnVal = g_pChitin->pGame->m_GameObjectArrayHandler.FreeGameObjectShare(eSource, THREAD_ASYNCH, INFINITE);
		}
	}

	//original code
	if (!pGameOptionsEx->bEffSavingThrowFix) {

		if (effect.nSaveType & CEFFECT_SAVETYPE_DEATH) {
			if (cdsTarget.saveDeath < wSaveThreshold) {
				wSaveRollTotal = cRollSaveDeath;
				wSaveThreshold = cdsTarget.saveDeath;
				srSuccessSave = 14009;
				if (!(rollSaveDeath & CRESAVE_USED)) {
					if (wSaveRollTotal >= wSaveThreshold) {
						rollSaveDeath |= CRESAVE_USED;
						bSavedVsType = TRUE;
					}
				}
			}
		}

		if (effect.nSaveType & CEFFECT_SAVETYPE_WANDS) {
			if (cdsTarget.saveWands < wSaveThreshold) {
				wSaveRollTotal = cRollSaveWands;
				wSaveThreshold = cdsTarget.saveWands;
				srSuccessSave = 14006;
				//srFailedSave = 10049;
				if (!(rollSaveWands & CRESAVE_USED)) {
					if (wSaveRollTotal >= wSaveThreshold) {
						rollSaveWands |= CRESAVE_USED;
						bSavedVsType = TRUE;
					}
				}
			}
		}

		if (effect.nSaveType & CEFFECT_SAVETYPE_POLYMORPH) {
			if (cdsTarget.savePoly < wSaveThreshold) {
				wSaveRollTotal = cRollSavePoly;
				wSaveThreshold = cdsTarget.savePoly;
				srSuccessSave = 14005;
				//srFailedSave = 10050;
				if (!(rollSavePoly & CRESAVE_USED)) {
					if (wSaveRollTotal >= wSaveThreshold) {
						rollSavePoly |= CRESAVE_USED;
						bSavedVsType = TRUE;
					}
				}
			}
		}

		if (effect.nSaveType & CEFFECT_SAVETYPE_BREATH) {
			if (cdsTarget.saveBreath < wSaveThreshold) {
				wSaveRollTotal = cRollSaveBreath;
				wSaveThreshold = cdsTarget.saveBreath;
				srSuccessSave = 14004;
				//srFailedSave = 10051;
				if (!(rollSaveBreath & CRESAVE_USED)) {
					if (wSaveRollTotal >= wSaveThreshold) {
						rollSaveBreath |= CRESAVE_USED;
						bSavedVsType = TRUE;
					}
				}
			}
		}

		if (effect.nSaveType & CEFFECT_SAVETYPE_SPELLS) {
			if (cdsTarget.saveSpell < wSaveThreshold) {
				wSaveRollTotal = cRollSaveSpells;
				wSaveThreshold = cdsTarget.saveSpell;
				srSuccessSave = 14003;
				//srFailedSave = 10052;
				if (!(rollSaveSpells & CRESAVE_USED)) {
					if (wSaveRollTotal >= wSaveThreshold) {
						rollSaveSpells |= CRESAVE_USED;
						bSavedVsType = TRUE;
					}
				}
			}
		}

		wSaveRollTotal += effect.nSaveBonus;

		if (g_pChitin->pGame->GetMageSchool(creTarget.m_BaseStats.kit[1]) == effect.nType1) {
			wSaveRollTotal += 2;
		}

		CCreatureObject* pCreSource = NULL;
		char returnVal;
		do {
			returnVal = g_pChitin->pGame->m_GameObjectArrayHandler.GetGameObjectShare(eSource, THREAD_ASYNCH, &pCreSource, INFINITE);
		} while (returnVal == OBJECT_SHARING || returnVal == OBJECT_DENYING);
		if (returnVal == OBJECT_SUCCESS) {
			if (pCreSource->GetType() == CGAMEOBJECT_TYPE_CREATURE) {
				wSaveRollTotal += creTarget.GetDerivedStats().m_SaveBonusVsObject.GetModValue(pCreSource->GetCurrentObject());
			}
			returnVal = g_pChitin->pGame->m_GameObjectArrayHandler.FreeGameObjectShare(eSource, THREAD_ASYNCH, INFINITE);
		}
	}

	if (wSaveRollTotal >= wSaveThreshold) {
		//saved
		if (bSavedVsType &&
			!(cdsTarget.stateFlags & STATE_DEAD)) {
			if (g_pChitin->pGame->m_GameOptions.m_nEffectTextLevel & 1) {
				IECString sRoll;
				CStrRef csr;
				IECString sText;
				sRoll.Format("%d", wSaveRollTotal);
				g_pChitin->m_TlkTbl.GetTlkString(srSuccessSave, csr);
				sText = csr.text + " : " + sRoll;

				CMessageDisplayText* pMDT = IENew CMessageDisplayText();
				pMDT->eTarget = creTarget.e;
				pMDT->eSource = creTarget.e;
				pMDT->sLeft = creTarget.GetLongName();
				pMDT->sRight = sText;
				pMDT->rgbLeft = g_ColorDefaultText;
				pMDT->rgbRight = g_ColorDefaultText;
				pMDT->u1c = -1;
				pMDT->u20 = 0;
				pMDT->bFloatText = false;
				pMDT->u22 = 0;
				pMDT->u23 = 0;

				g_pChitin->messages.Send(*pMDT, FALSE);
			} else if (g_pChitin->pGame->m_GameOptions.m_nEffectTextLevel & 8) {
				CMessageDisplayDialogue* pMDD = IENew CMessageDisplayDialogue();
				pMDD->eTarget = creTarget.e;
				pMDD->eSource = creTarget.e;
				pMDD->srOwner = creTarget.GetLongNameStrRef();
				pMDD->srText = srSuccessSave;
				pMDD->rgbOwner = g_ColorDefaultText;
				pMDD->rgbText = g_ColorDefaultText;
				pMDD->u1c = -1;
				pMDD->u20 = 0;
				pMDD->bFloatText = false;
				pMDD->u22 = 0;
				pMDD->bPlaySound = true;

				g_pChitin->messages.Send(*pMDD, FALSE);
			}
		}

		return FALSE;
	} else return TRUE;
}

void DETOUR_CEffectList::DETOUR_TryDispel(
	CCreatureObject& creTarget,
	POSITION posSkip,
	BOOL bCheckDispellableFlag,
	BOOL bCheckProbability,
	char cRand,
	char cDispelLevel
) {
	BOOL bDispel = TRUE;
	int nDispelChance = 50;

	POSITION pos = GetHeadPosition();
	POSITION posCurr = pos;
	while (pos) {
		posCurr = pos;
		CEffect* pEff = (CEffect*)GetNext(pos);
		if (bCheckProbability) {
			nDispelChance = 50;
			if (pEff->effect.nSourceCreLevel > cDispelLevel) {
				//original code without proper brackets
				//nDispelChance += pEff->effect.nSourceCreLevel * 10 - nDispelLevel;
				nDispelChance += (pEff->effect.nSourceCreLevel - cDispelLevel) * 10;
			} else {
				nDispelChance -= (cDispelLevel - pEff->effect.nSourceCreLevel) * 5;
			}
			if (cRand == 0) {
				bDispel = FALSE;
			} else {
				//bDispel = (cRand > nDispelChance || cRand > 99) ? 1 : 0;
				bDispel = (cRand > nDispelChance || cRand > 98) ? 1 : 0; //roll is 0-99, allow 99 for always dispel
			}
		} else {
			bDispel = TRUE;
		}

		if (posCurr != posSkip && bDispel) {
			if (!bCheckDispellableFlag || pEff->effect.dwFlags & 1) {
				RemoveAt(posCurr);
				pEff->OnRemove(creTarget);
				delete pEff;
				pEff = NULL;
			}
		}

	} //while

	this->posCurrent = 0;

	return;
}