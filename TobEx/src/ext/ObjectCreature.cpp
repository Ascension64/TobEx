#include "ObjectCreature.h"

#include "animext.h"
#include "chitin.h"
#include "itmcore.h"
#include "objvef.h"
#include "vidcore.h"
#include "options.h"
#include "console.h"
#include "log.h"

#include "ObjectCommon.h"
#include "ObjectStats.h"
#include "UserMageBook.h"
#include "UserPriestBook.h"

CCreatureObject& (CCreatureObject::*Tramp_CCreatureObject_Construct_10)(void*, unsigned int, BOOL, int, int, int, unsigned int, int, int, int) =
	SetFP(static_cast<CCreatureObject& (CCreatureObject::*)(void*, unsigned int, BOOL, int, int, int, unsigned int, int, int, int)>
																			(&CCreatureObject::Construct),				0x87FB08);
CreFileKnownSpell& (CCreatureObject::*Tramp_CCreatureObject_GetKnownSpellPriest)(int, int) =
	SetFP(static_cast<CreFileKnownSpell& (CCreatureObject::*)(int, int)>	(&CCreatureObject::GetKnownSpellPriest),	0x8CB91F);
CreFileKnownSpell& (CCreatureObject::*Tramp_CCreatureObject_GetKnownSpellMage)(int, int) =
	SetFP(static_cast<CreFileKnownSpell& (CCreatureObject::*)(int, int)>	(&CCreatureObject::GetKnownSpellMage),		0x8CB949);
BOOL (CCreatureObject::*Tramp_CCreatureObject_AddMemSpellPriest)(int, int, int*) =
	SetFP(static_cast<BOOL (CCreatureObject::*)(int, int, int*)>			(&CCreatureObject::AddMemSpellPriest),		0x8CBB64);
BOOL (CCreatureObject::*Tramp_CCreatureObject_AddMemSpellMage)(int, int, int*) =
	SetFP(static_cast<BOOL (CCreatureObject::*)(int, int, int*)>			(&CCreatureObject::AddMemSpellMage),		0x8CBBEA);
void (CCreatureObject::*Tramp_CCreatureObject_ValidateAttackSequence)(char*) =
	SetFP(static_cast<void (CCreatureObject::*)(char*)>						(&CCreatureObject::ValidateAttackSequence),	0x8D6D78);
BOOL (CCreatureObject::*Tramp_CCreatureObject_EvaluateTrigger)(Trigger&) =
	SetFP(static_cast<BOOL (CCreatureObject::*)(Trigger&)>					(&CCreatureObject::EvaluateTrigger),		0x8F6C0E);
ACTIONRESULT (CCreatureObject::*Tramp_CCreatureObject_ExecuteAction)() =
	SetFP(static_cast<ACTIONRESULT (CCreatureObject::*)()>					(&CCreatureObject::ExecuteAction),			0x8E2276);

void __stdcall CProtectedSplList_Update_CreateVisualEffect(CCreatureObject& creSource, CCreatureObject& creTarget) {
	CVisualEffect* pVisEff = new CVisualEffect();
	ResVvcContainer vvc(ResRef("spsturni"));
	CVisualEffectVidCell* pVidCell = &vvc.Unmarshal();
	pVidCell->m_nOrientation = CCreatureObject::CalculateOrientation(creSource.m_currentLoc, creTarget.m_currentLoc);
	pVidCell->vvc.posFlags = VVCORIENTATION_IGNORE;
	pVidCell->m_nPurgeType = 1;
	//pVisEff->eOwner = creSource.e;
	pVisEff->u52 = 1;
	pVisEff->ptSource.x = creSource.m_currentLoc.x;
	pVisEff->ptSource.y = creSource.m_currentLoc.y;
	pVisEff->AddToArea(*creSource.pArea, creSource.m_currentLoc, 32, LIST_FRONT);
	if (pVidCell) {
		POINT pt;
		pt.x = pVidCell->vvc.ptOffset.x + creSource.m_currentLoc.x;
		pt.y = pVidCell->vvc.ptOffset.y + creSource.m_currentLoc.y;
		pVidCell->AddToArea(*creSource.pArea, pt, pVidCell->vvc.zPos, LIST_FRONT, 0);
		pVisEff->m_VidCells.AddTail((void*)pVidCell->e);
	}

	/*//this doesn't work because the vid cell gets purged unless there is an effect holding it in place
	CVisualEffect* pVisEff = NULL;

	ResVvcContainer vvc(ResRef("spsturni"));
	CVisualEffectVidCell* pVidCell = &vvc.Unmarshal();
	if (pVidCell) {
		pVidCell->m_nOrientation = CCreatureObject::CalculateOrientation(creSource.m_currentLoc, creTarget.m_currentLoc);
		pVidCell->vvc.posFlags = VVCORIENTATION_IGNORE;
		pVidCell->m_nPurgeType = 1;
		POINT pt;
		pt.x = pVidCell->vvc.ptOffset.x + creSource.m_currentLoc.x;
		pt.y = pVidCell->vvc.ptOffset.y + creSource.m_currentLoc.y;

		if (creSource.eVisualEffect != ENUM_INVALID_INDEX) {
			char threadVal;
			do {
				threadVal = g_pChitin->pGame->m_GameObjectArrayHandler.GetGameObjectDeny(creSource.eVisualEffect, THREAD_ASYNCH, &pVisEff, INFINITE);
			} while (threadVal == OBJECT_SHARING || threadVal == OBJECT_DENYING);
			if (threadVal == OBJECT_SUCCESS) {
				pVidCell->AddToArea(*creSource.pArea, pt, pVidCell->vvc.zPos, LIST_FRONT, 0);
				pVisEff->m_VidCells.AddTail((void*)pVidCell->e);
				g_pChitin->pGame->m_GameObjectArrayHandler.FreeGameObjectDeny(creSource.eVisualEffect, THREAD_ASYNCH, INFINITE);
			}
		} else {
			pVisEff = new CVisualEffect();
			pVisEff->m_dwFlags |= 1; //bit0
			pVisEff->m_dwFlags |= 4; //bit2
			pVisEff->u52 = 1;
			pVisEff->eOwner = creSource.e;
			pVisEff->ptSource.x = creSource.m_currentLoc.x;
			pVisEff->ptSource.y = creSource.m_currentLoc.y;
			pVisEff->AddToArea(*creSource.pArea, creSource.m_currentLoc, 32, LIST_FRONT);

			pVidCell->AddToArea(*creSource.pArea, pt, pVidCell->vvc.zPos, LIST_FRONT, 0);
			pVisEff->m_VidCells.AddTail((void*)pVidCell->e);
		}
	}*/

	return;
}

CCreatureObject& DETOUR_CCreatureObject::DETOUR_Construct(
	void* pFile,
	unsigned int dwSize,
	BOOL bHasSpawned,
	int nTicksTillRemove,
	int nMaxMvtDistance,
	int nMaxMvtDistanceToObject,
	unsigned int nSchedule,
	int nDestX,
	int nDestY,
	int nFacing
) {
	m_nBounceDelay = 0;
	return (this->*Tramp_CCreatureObject_Construct_10)(pFile, dwSize, bHasSpawned, nTicksTillRemove, nMaxMvtDistance, nMaxMvtDistanceToObject, nSchedule, nDestX, nDestY, nFacing);
}

CreFileKnownSpell& DETOUR_CCreatureObject::DETOUR_GetKnownSpellPriest(int nLevel, int nIndex) {
	int Eip;
	GetEip(Eip);

	if (Eip == 0x78744E) { //from CPriestBook::Update()
		nIndex += CUIButtonPriestBook_KnownSpellOffset;
	}

	return (this->*Tramp_CCreatureObject_GetKnownSpellPriest)(nLevel, nIndex);
}

CreFileKnownSpell& DETOUR_CCreatureObject::DETOUR_GetKnownSpellMage(int nLevel, int nIndex) {
	int Eip;
	GetEip(Eip);

	if (Eip == 0x7B8952) { //from CMageBook::Update()
		nIndex += CUIButtonMageBook_KnownSpellOffset;
	}

	return (this->*Tramp_CCreatureObject_GetKnownSpellMage)(nLevel, nIndex);
}

BOOL DETOUR_CCreatureObject::DETOUR_AddMemSpellPriest(int nLevel , int nIndex, int* pIndex) {
	int Eip;
	GetEip(Eip);

	if (Eip == 0x7892C9) { //from CUIButtonPriestBookKnownSpell::OnLClicked()
		nIndex += CUIButtonPriestBook_KnownSpellOffset;
	}

	return (this->*Tramp_CCreatureObject_AddMemSpellPriest)(nLevel, nIndex, pIndex);
}

BOOL DETOUR_CCreatureObject::DETOUR_AddMemSpellMage(int nLevel , int nIndex, int* pIndex) {
	int Eip;
	GetEip(Eip);

	if (Eip == 0x7BEEC7) { //from CUIButtonMageBookKnownSpell::OnLClicked()
		nIndex += CUIButtonMageBook_KnownSpellOffset;
	}

	return (this->*Tramp_CCreatureObject_AddMemSpellMage)(nLevel, nIndex, pIndex);
}

void DETOUR_CCreatureObject::DETOUR_ValidateAttackSequence(char* pSeq) {
	if (0) IECString("DETOUR_CCreatureObject::DETOUR_ValidateAttackSequence");

	if (*pSeq == SEQ_SHOOT) {
		CItem* pItm = m_Inventory.items[m_Inventory.nSlotSelected];
		if (pItm) {
			pItm->Demand();
			ItmFileAbility& ability = pItm->GetAbility(m_Inventory.nAbilitySelected);
			if (&ability) {
				if (ability.attackType != ITEMABILITYATTACKTYPE_RANGED) *pSeq = SEQ_ATTACK;

				if (CCreatureObject_HasThrowingWeaponEquippedHumanoidOnly(*this)) *pSeq = SEQ_ATTACK; //new line
			} else {
				*pSeq = SEQ_READY;
			}
			pItm->Release();
		} else {
			*pSeq = SEQ_READY;
		}
	} else if (*pSeq == SEQ_ATTACK) {
		CItem* pItm = m_Inventory.items[m_Inventory.nSlotSelected];
		if (pItm) {
			pItm->Demand();
			ItmFileAbility& ability = pItm->GetAbility(m_Inventory.nAbilitySelected);
			if (&ability) {
				if (ability.attackType == ITEMABILITYATTACKTYPE_RANGED) *pSeq = SEQ_SHOOT;

				if (CCreatureObject_HasThrowingWeaponEquippedHumanoidOnly(*this)) *pSeq = SEQ_ATTACK; //new line
			} else {
				*pSeq = SEQ_READY;
			}
			pItm->Release();
		} else {
			*pSeq = SEQ_READY;
		}
	}
	return;
}

BOOL DETOUR_CCreatureObject::DETOUR_EvaluateTrigger(Trigger& t) {
	if (0) IECString("DETOUR_CCreatureObject::DETOUR_EvaluateTrigger");

	Trigger tTemp = t;
	switch (tTemp.opcode) {
	default:
		return (this->*Tramp_CCreatureObject_EvaluateTrigger)(t);
		break;
	}

	return FALSE;
}

ACTIONRESULT DETOUR_CCreatureObject::DETOUR_ExecuteAction() {
	if (0) IECString("DETOUR_CCreatureObject::DETOUR_ExecuteAction");

	bExecutingAction = TRUE;
	ACTIONRESULT ar = ACTIONRESULT_NOACTIONTAKEN;

	if (aCurrent.opcode == ACTION_BREAK_INSTANTS) SetCurrentAction(GetTopAction(g_pActionTemp));

	switch (aCurrent.opcode) {
	case ACTION_BREAK_INSTANTS:
		ar = ACTIONRESULT_NOACTIONTAKEN; //re-implement here to prevent weird behaviour for double BreakInstants()
		break;
	default:
		return (this->*Tramp_CCreatureObject_ExecuteAction)();
		break;
	}

	arCurrent = ar;
	bExecutingAction = FALSE;

	return ar;
}

void __stdcall CCreatureObject_PrintExtraCombatInfoText(CCreatureObject& creSelf, IECString& sText) {
	if (0) IECString("CCreatureObject_PrintExtraCombatInfoText");

	if (g_pChitin->pGame->m_GameOptions.m_bDisplayExtraCombatInfo) {
		ABGR colorOwner = *(g_pColorRangeArray + creSelf.m_BaseStats.colors.colorMajor);
		ABGR colorText = g_ColorDefaultText;
		IECString sOwner = creSelf.GetLongName();
		g_pChitin->pWorld->PrintToConsole(sOwner, sText, colorOwner, colorText, -1, 0);
	}
	return;
}

BOOL __stdcall CCreatureObject_ShouldAvertCriticalHit(CCreatureObject& creTarget) {
	if (0) IECString("CCreatureObject_ShouldAvertCriticalHit");

	CItem* pItem = NULL;

	for (int i = 0; i < 10; i++) {
		pItem = creTarget.m_Inventory.items[i];
		if (pItem) {
			if (i != SLOT_HELMET &&
				(pItem->GetFlags() & ITEMFLAG_TOGGLE_CRITICALHIT)) {
				//avert critical hit if flag set (not SLOT_HELMET)
				return TRUE;
			}
			if (i == SLOT_HELMET &&
				!(pItem->GetFlags() & ITEMFLAG_TOGGLE_CRITICALHIT)) {
				//avert critical hit unless flag set (SLOT_HELMET)
				return TRUE;
			}
		}
	}

	pItem = creTarget.m_Inventory.items[creTarget.m_Inventory.nSlotSelected];
	if (pItem) {
		if (pItem->GetFlags() & ITEMFLAG_TOGGLE_CRITICALHIT) {
			return TRUE;
		}
	}

	return FALSE;
}

BOOL __stdcall CCreatureObject_ApplyDamage_TryBackstab(CCreatureObject& creSource, CItem& itmMain, ItmFileAbility& abilMain, ItmFileAbility& abilLauncher, short orTarget, short orToTarget, CCreatureObject& creTarget) {
	if (0) IECString("CCreatureObject_ApplyDamage_TryBackstab");

	/* original code
    CDerivedStats& cds = creSource.GetDerivedStats();

    if ((abilMain.attackType != ITEMABILITYATTACKTYPE_RANGED) &&
        (cds.stateFlags & STATE_INVISIBLE || cds.m_BackstabEveryHit) &&
        cds.m_BackstabDamageMultiplier != 1) {

        if (creSource.o.EnemyAlly > EA_GOODCUTOFF || //not good
            cds.m_BackstabEveryHit ||
            ObjectCommon_InBackstabPosition(orTarget, orToTarget)) {
            
			if (creTarget.GetKitUnusableFlag() & KIT_BARBARIAN) {
				creSource.PrintEventMessage(EVENTMESSAGE_BACKSTAB_FAIL, 0, 0, 0, -1, FALSE, IECString());
				return FALSE;
			}

			if (creTarget.GetDerivedStats().m_BackstabImmunity) {
				creSource.PrintEventMessage(EVENTMESSAGE_BACKSTAB_FAIL, 0, 0, 0, -1, FALSE, IECString());
				return FALSE;
			}

            if (!(itmMain.GetUnusableFlags() & ITEMUNUSABLE_THIEF)) {
                //success, game prints event message and calculates multiplier
                return TRUE;
            } else {
                creSource.PrintEventMessage(EVENTMESSAGE_BACKSTAB_WEAPON_UNSUITABLE, 0, 0, 0, -1, FALSE, IECString());
                return FALSE;
            }
        }
    }

    return FALSE;*/
	
	CDerivedStats& cds = creSource.GetDerivedStats();

	BOOL bToggleBackstab = FALSE;
	BOOL bIgnoreInvisible = cds.m_BackstabEveryHit;
	BOOL bIgnorePosition = cds.m_BackstabEveryHit;

	if (pGameOptionsEx->bItemsBackstabRestrictionsConfig) {
		bToggleBackstab = abilMain.flags & ITEMABILITYFLAG_TOGGLE_BACKSTAB;
		if (&abilLauncher != NULL && !bToggleBackstab) {
			bToggleBackstab = abilLauncher.flags & ITEMABILITYFLAG_TOGGLE_BACKSTAB;
		}
	}

	if (pGameOptionsEx->bEffBackstabEveryHitConfig) {
		bIgnoreInvisible = (cds.m_BackstabEveryHit & 0x1) || (cds.m_BackstabEveryHit & 0x2);
		bIgnorePosition = (cds.m_BackstabEveryHit & 0x1) || (cds.m_BackstabEveryHit & 0x4);
	}

	if (
		(cds.stateFlags & STATE_INVISIBLE || bIgnoreInvisible) &&
		cds.m_BackstabDamageMultiplier != 1 &&
		(creSource.o.EnemyAlly > EA_GOODCUTOFF || bIgnorePosition || ObjectCommon_InBackstabPosition(orTarget, orToTarget))
	) {

		if (creTarget.GetKitUnusableFlag() & KIT_BARBARIAN) {
			creSource.PrintEventMessage(EVENTMESSAGE_BACKSTAB_FAIL, 0, 0, 0, -1, FALSE, IECString());
			return FALSE;
		}

		if (creTarget.GetDerivedStats().m_BackstabImmunity) {
			creSource.PrintEventMessage(EVENTMESSAGE_BACKSTAB_FAIL, 0, 0, 0, -1, FALSE, IECString());
			return FALSE;
		}

		if (
			(!(itmMain.GetUnusableFlags() & ITEMUNUSABLE_THIEF) && abilMain.attackType != ITEMABILITYATTACKTYPE_RANGED && !bToggleBackstab) ||
			(!(itmMain.GetUnusableFlags() & ITEMUNUSABLE_THIEF) && abilMain.attackType == ITEMABILITYATTACKTYPE_RANGED && bToggleBackstab) ||
			(itmMain.GetUnusableFlags() & ITEMUNUSABLE_THIEF && bToggleBackstab)
		) {
			//success, game prints event message and calculates multiplier
			return TRUE;
		} else {
			creSource.PrintEventMessage(EVENTMESSAGE_BACKSTAB_WEAPON_UNSUITABLE, 0, 0, 0, -1, FALSE, IECString());
			return FALSE;
		}
	}

	return FALSE;
}

int __stdcall CCreatureObject_ApplyDamage_CalculateDamageBonus(CCreatureObject& creSource, ItmFileAbility& abilMain, short* pwDamage, CCreatureObject& creTarget) {
	if (0) IECString("CCreatureObject_ApplyDamage_CalculateDamageBonus");

	short wDamageBonus = 0;

	switch (abilMain.damType) {
	case 1: //piercing
		wDamageBonus = *pwDamage * creSource.GetDerivedStats().GetStat(CDERIVEDSTATSEX_BASE + CDERIVEDSTATSEX_PIERCINGDAMAGEBONUS) / 100;
		break;
	case 2: //crushing
		wDamageBonus = *pwDamage * creSource.GetDerivedStats().GetStat(CDERIVEDSTATSEX_BASE + CDERIVEDSTATSEX_CRUSHINGDAMAGEBONUS) / 100;
		break;
	case 3: //slashing
		wDamageBonus = *pwDamage * creSource.GetDerivedStats().GetStat(CDERIVEDSTATSEX_BASE + CDERIVEDSTATSEX_SLASHINGDAMAGEBONUS) / 100;
		break;
	case 4: //missile
		wDamageBonus = *pwDamage * creSource.GetDerivedStats().GetStat(CDERIVEDSTATSEX_BASE + CDERIVEDSTATSEX_MISSILEDAMAGEBONUS) / 100;
		break;
	case 5: //stunning
		wDamageBonus = *pwDamage * creSource.GetDerivedStats().GetStat(CDERIVEDSTATSEX_BASE + CDERIVEDSTATSEX_STUNNINGDAMAGEBONUS) / 100;
		break;
	case 6: //piercing/crushing
		if (&creTarget != NULL) {
			if (creTarget.GetDerivedStats().resistPiercing > creTarget.GetDerivedStats().resistCrushing) {
				wDamageBonus = *pwDamage * creSource.GetDerivedStats().GetStat(CDERIVEDSTATSEX_BASE + CDERIVEDSTATSEX_CRUSHINGDAMAGEBONUS) / 100;
			} else {
				wDamageBonus = *pwDamage * creSource.GetDerivedStats().GetStat(CDERIVEDSTATSEX_BASE + CDERIVEDSTATSEX_PIERCINGDAMAGEBONUS) / 100;
			}
		} else {
			wDamageBonus = *pwDamage * creSource.GetDerivedStats().GetStat(CDERIVEDSTATSEX_BASE + CDERIVEDSTATSEX_PIERCINGDAMAGEBONUS) / 100;
		}
		break;
	case 7: //piercing/slashing
		if (&creTarget != NULL) {
			if (creTarget.GetDerivedStats().resistPiercing > creTarget.GetDerivedStats().resistSlashing) {
				wDamageBonus = *pwDamage * creSource.GetDerivedStats().GetStat(CDERIVEDSTATSEX_BASE + CDERIVEDSTATSEX_SLASHINGDAMAGEBONUS) / 100;
			} else {
				wDamageBonus = *pwDamage * creSource.GetDerivedStats().GetStat(CDERIVEDSTATSEX_BASE + CDERIVEDSTATSEX_PIERCINGDAMAGEBONUS) / 100;
			}
		} else {
			wDamageBonus = *pwDamage * creSource.GetDerivedStats().GetStat(CDERIVEDSTATSEX_BASE + CDERIVEDSTATSEX_PIERCINGDAMAGEBONUS) / 100;
		}
		break;
	case 8: //crushing/slashing
		if (&creTarget != NULL) {
			if (creTarget.GetDerivedStats().resistCrushing > creTarget.GetDerivedStats().resistSlashing) {
				wDamageBonus = *pwDamage * creSource.GetDerivedStats().GetStat(CDERIVEDSTATSEX_BASE + CDERIVEDSTATSEX_CRUSHINGDAMAGEBONUS) / 100;
			} else {
				wDamageBonus = *pwDamage * creSource.GetDerivedStats().GetStat(CDERIVEDSTATSEX_BASE + CDERIVEDSTATSEX_SLASHINGDAMAGEBONUS) / 100;
			}
		} else {
			wDamageBonus = *pwDamage * creSource.GetDerivedStats().GetStat(CDERIVEDSTATSEX_BASE + CDERIVEDSTATSEX_CRUSHINGDAMAGEBONUS) / 100;
		}
		break;
	default:
		break;
	}

	wDamageBonus += creSource.GetDerivedStats().damageBonus;
	*pwDamage += wDamageBonus;
	return wDamageBonus;
}

BOOL __stdcall CCreatureObject_HasThrowingWeaponEquippedHumanoidOnly(CCreatureObject& cre) {
	if (0) IECString("CCreatureObject_HasThrowingWeaponEquippedHumanoidOnly");

	CItem* pItm = cre.m_Inventory.items[cre.m_Inventory.nSlotSelected];
	if (pItm == NULL) return FALSE;
	pItm->Demand();
	ItmFileAbility& ability = pItm->GetAbility(cre.m_Inventory.nAbilitySelected);
	if (&ability == NULL) {
		pItm->Release();
		return FALSE;
	}

	int nSlot;
	if (ability.attackType == ITEMABILITYATTACKTYPE_RANGED &&
		cre.m_Inventory.nSlotSelected >= SLOT_WEAPON0 &&
		cre.m_Inventory.nSlotSelected <= SLOT_WEAPON3 &&
		pItm->GetType() != ITEMTYPE_BOW &&
		pItm->GetType() != ITEMTYPE_SLING &&
		pItm->GetType() != ITEMTYPE_XBOW &&
		&cre.GetFirstEquippedLauncherOfAbility(ability, &nSlot) == NULL) {
		
		//restrict to humanoid animation IDs only (this is Infinity Animations-friendly)
		CAnimation* pAnimation = cre.m_animation.pAnimation;
		if (pAnimation == NULL) {
			LPCTSTR lpsz = "CCreatureObject_HasThrowingWeaponEquippedHumanoidOnly(): cre.m_animation.pAnimation == NULL\r\n";
			L.timestamp();
			L.append(lpsz);
			console.write(lpsz);
		} else {
			if (
				(pAnimation->wAnimId >= 0x5000 &&
				pAnimation->wAnimId < 0x5400 &&
				((CAnimation5000*)pAnimation)->sPrefix[0] == 'C' //avoid clash with Infinity Animations
				) ||
				pAnimation->wAnimId & 0x6000
				) {
				pItm->Release();
				return TRUE;
			}
		}

	}
	pItm->Release();
	return FALSE;
};

BOOL __stdcall CCreatureObject_Spell_IsOverrideInvisible(CCreatureObject& creSource, CCreatureObject& creTarget) {
	if (0) IECString("CCreatureObject_Spell_IsOverrideInvisible");

	if (&creSource == &creTarget) return TRUE;

	IECString sSpell;
	if (creSource.aCurrent.GetSName1().IsEmpty()) {
		creSource.GetSpellIdsName(creSource.aCurrent.i, &sSpell);
	} else {
		sSpell = creSource.aCurrent.GetSName1();
	}
	
	ResSplContainer resSpell;
	resSpell.LoadResource(ResRef(sSpell), TRUE, TRUE);
	if (resSpell.bLoaded &&
		resSpell.name.IsNotEmpty()) {
		if (resSpell.GetSpellFlags() & SPELLFLAG_TARGET_INVISIBLE) {
			return TRUE;
		}
	}

	if (!creSource.CanSeeInvisible()) {
		if (creTarget.GetDerivedStats().stateFlags & STATE_INVISIBLE ||
			creTarget.GetDerivedStats().stateFlags & STATE_IMPROVEDINVISIBILITY) {
			return FALSE;
		}
	}

	if (!creSource.CanSeeInvisible()) {
		if (creTarget.GetDerivedStats().sanctuary) {
			return FALSE;
		}
	}

	return TRUE;
};

BOOL __stdcall CCreatureObject_IsDeadInFrontVerticalList(CCreatureObject& cre) {
	if (0) IECString("CCreatureObject_IsDeadInFrontVerticalList");

	if (cre.GetVertListType() == LIST_FRONT) {
		CDerivedStats& cds = cre.GetDerivedStats();
		if (cds.stateFlags & STATE_DEAD) {
			CAnimation* pAnimation = cre.m_animation.pAnimation;
			if (pAnimation == NULL) {
				LPCSTR lpsz = "CCreatureObject_IsDeadInFrontVerticalList(): pAnimation == NULL\r\n";
				L.timestamp();
				L.append(lpsz);
				console.write(lpsz);
				return FALSE;
			}
			if (!pAnimation->CanUseMiddleVertList()) {
				return TRUE;
			}
		}
	}
	return FALSE;
}

BOOL __stdcall CCreatureObject_Spell_IsOverrideSilence(CCreatureObject& creSource) {
	//called when creSource has STATE_SILENCED set

	if (0) IECString("CCreatureObject_Spell_IsOverrideSilence");

	IECString sSpell;
	if (creSource.aCurrent.GetSName1().IsEmpty()) {
		creSource.GetSpellIdsName(creSource.aCurrent.i, &sSpell);
	} else {
		sSpell = creSource.aCurrent.GetSName1();
	}

	if (!sSpell.Compare("SPWI219")) return TRUE; //Vocalize
	if (!sSpell.Compare("SPCL412")) return TRUE; //Set Snare
	if (!sSpell.Compare("SPCL414")) return TRUE; //Set Special Snare
	if (!sSpell.Compare("SPIN649")) return TRUE; //Pocket Plane
	
	ResSplContainer resSpell;
	resSpell.LoadResource(ResRef(sSpell), TRUE, TRUE);
	if (resSpell.bLoaded &&
		resSpell.name.IsNotEmpty()) {
		if (resSpell.GetSpellFlags() & SPELLFLAG_NO_VOICE) {
			return TRUE;
		}
	}

	return FALSE;
}

LPCTSTR __stdcall CCreatureObject_DoSpellCasting_GetGenderLetter(CCreatureObject& creSource, ResSplContainer& resSpell, SplFileAbility& ability) {
	if (0) IECString("CCreatureObject_DoSpellCasting_GetGenderLetter");

	if (pGameOptionsEx->bSpellsUnvoicedConfig &&
		creSource.GetDerivedStats().stateFlags & STATE_SILENCED &&
		resSpell.GetSpellFlags() & SPELLFLAG_NO_VOICE)
		return "S";

	if (pGameOptionsEx->bSpellsCastingFix) {
		unsigned char gender = creSource.o.Gender;
		unsigned char sex = creSource.m_BaseStats.sex;

		if (ability.castSpeed - creSource.GetDerivedStats().mentalSpeed < 3) return "S";

		switch (gender) {
		case GENDER_MALE:
			return "M";
		case GENDER_FEMALE:
			return "F";
		case GENDER_OTHER:
		case GENDER_NIETHER:
			return "S";
		default:
			if (sex == 1) return "M";
			if (sex == 2) return "F";
			return "S";
		}
	} else {
		//original code
		if (ability.castSpeed < 3) return "S";

		unsigned char gender = creSource.o.Gender;
		if (gender == GENDER_FEMALE) return "F";
		if (gender == GENDER_OTHER ||
			gender == GENDER_NIETHER)
			return "S";

		return "M";
	}
}

short __stdcall CCreatureObject_DoSpellCasting_GetCastingSpeed(CCreatureObject& creSource, SplFileAbility& ability) {
	if (0) IECString("CCreatureObject_DoSpellCasting_GetCastingSpeed");

	return max(0, ability.castSpeed - creSource.GetDerivedStats().mentalSpeed) * 100 / 10;
}

BOOL __stdcall CCreatureObject_UseItem_CannotTargetInvisible(CCreatureObject& creSource, CCreatureObject& creTarget) {
	if (0) IECString("CCreatureObject_UseItem_CannotTargetInvisible");

	if (&creSource == &creTarget) return FALSE;

	ItmFileAbility itmAbility = creSource.m_currentItem->GetAbility(creSource.m_currentItemAbility);
	if (itmAbility.flags & ITEMFLAG_NO_TARGET_INVIS) {
		if (!creSource.CanSeeInvisible()) {
			if (creTarget.GetDerivedStats().stateFlags & STATE_INVISIBLE ||
				creTarget.GetDerivedStats().stateFlags & STATE_IMPROVEDINVISIBILITY ||
				creTarget.GetDerivedStats().sanctuary) {
				creSource.PrintEventMessage(EVENTMESSAGE_SPELLFAILED_INVISIBLE, 0, 0, 0, -1, 0, IECString());
				return TRUE;
			}
		}
	}

	return FALSE;
}

void __stdcall CCreatureObject_UseItem_OverrideAnimation(CCreatureObject& creSource) {
	if (0) IECString("CCreatureObject_UseItem_OverrideAnimation");

	IECString sRowname(creSource.m_currentItem->m_itm.name);

	creSource.m_currentItem->Demand();
	int nCol = 0;
	if (creSource.m_currentItemAbility != 0 &&
		&creSource.m_currentItem->GetAbility(creSource.m_currentItemAbility) != NULL) {
		nCol = creSource.m_currentItemAbility;
	}
	creSource.m_currentItem->Release();

	IECString sColname = "SEQUENCE";
	if (nCol &&
		nCol < g_pChitin->pGame->ITEMANIM.nCols) {
		//FIX_ME - do not use itoa
		char szColname[3] = {0};
		itoa(nCol, szColname, 10);
		sColname = szColname;
	}

	IECString sSeq = g_pChitin->pGame->ITEMANIM.GetValue(sColname, sRowname);

	int nSeq;
	if (sSeq.Compare((LPCTSTR)g_pChitin->pGame->ITEMANIM.defaultVal)) {
		sscanf_s((LPCTSTR)sSeq, "%d", &nSeq);

		CMessageSetAnimationSequence* pMsg = IENew CMessageSetAnimationSequence();
		pMsg->eSource = creSource.e;
		pMsg->eTarget = creSource.e;
		pMsg->nSeq = nSeq;
		g_pChitin->messages.Send(*pMsg, FALSE);
	}

	return;
}
