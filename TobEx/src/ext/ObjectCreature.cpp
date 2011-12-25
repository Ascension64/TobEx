#include "ObjectCreature.h"

#include "animext.h"
#include "chitin.h"
#include "itmcore.h"
#include "vidcore.h"
#include "options.h"
#include "console.h"
#include "log.h"

#include "ObjectCommon.h"
#include "UserMageBook.h"
#include "UserPriestBook.h"

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
};

void __stdcall CCreatureObject_PrintExtraCombatInfoText(CCreatureObject& creSelf, IECString& sText) {
	if (g_pChitin->pGame->m_GameOptions.m_bDisplayExtraCombatInfo) {
		ABGR colorOwner = *(g_pColorRangeArray + creSelf.m_BaseStats.colors.colorMajor);
		ABGR colorText = g_ColorDefaultText;
		IECString sOwner = creSelf.GetLongName();
		g_pChitin->pWorld->PrintToConsole(sOwner, sText, colorOwner, colorText, -1, 0);
	}
	return;
}

BOOL __stdcall CCreatureObject_ShouldAvertCriticalHit(CCreatureObject& creTarget) {
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

BOOL CCreatureObject_TryBackstab(CCreatureObject& creSource, CItem& itmMain, ItmFileAbility& abilMain, ItmFileAbility& abilLauncher, short orTarget, short orToTarget, CCreatureObject& creTarget) {
	/* original code
    CDerivedStats& cds = creSource.GetDerivedStats();

    if ((abilMain.attackType != ITEMABILITYATTACKTYPE_RANGED) &&
        (cds.stateFlags & STATE_INVISIBLE || cds.m_BackstabEveryHit) &&
        cds.m_BackstabDamageMultiplier != 1) {

        if (creSource.o.EnemyAlly > EA_GOODCUTOFF || //not good
            cds.m_BackstabEveryHit ||
            ObjectCommon_InBackstabPosition(orTarget, orToTarget)) {
            
            if (!(creTarget.GetKitUnusableFlag() & KIT_BARBARIAN) ||
                !creTarget.GetDerivedStats().m_BackstabImmunity) {

                if (!(itmMain.GetUnusableFlags() & ITEMUNUSABLE_THIEF)) {
                    //success, game prints event message and calculates multiplier
                    return TRUE;
                } else {
                    creSource.PrintEventMessage(EVENTMESSAGE_BACKSTAB_WEAPON_UNSUITABLE, 0, 0, 0, -1, FALSE, IECString());
                    return FALSE;
                }
            } else {
                creSource.PrintEventMessage(EVENTMESSAGE_BACKSTAB_FAIL, 0, 0, 0, -1, FALSE, IECString());
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

		if (!(creTarget.GetKitUnusableFlag() & KIT_BARBARIAN) ||
			!creTarget.GetDerivedStats().m_BackstabImmunity) {

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
		} else {
			creSource.PrintEventMessage(EVENTMESSAGE_BACKSTAB_FAIL, 0, 0, 0, -1, FALSE, IECString());
			return FALSE;
		}
	}

	return FALSE;
}

BOOL __stdcall CCreatureObject_HasThrowingWeaponEquippedHumanoidOnly(CCreatureObject& cre) {
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

BOOL __stdcall CCreatureObject_IsValidSpellTarget_CheckInvisible(CCreatureObject& creSource, CCreatureObject& creTarget) {
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
			resSpell.Unload();
			return TRUE;
		}
	}
	resSpell.Unload();

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