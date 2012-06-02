#include "ObjectCreature.h"

#include "animext.h"
#include "chitin.h"
#include "itmcore.h"
#include "objvef.h"
#include "vidcore.h"
#include "options.h"
#include "console.h"
#include "log.h"

#include "InfGameCommon.h"
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
ACTIONRESULT (CCreatureObject::*Tramp_CCreatureObject_ActionPickPockets)(CCreatureObject&) =
	SetFP(static_cast<ACTIONRESULT (CCreatureObject::*)(CCreatureObject&)>	(&CCreatureObject::ActionPickPockets),		0x9431AE);
void (CCreatureObject::*Tramp_CCreatureObject_UpdateFaceTalkerTimer)() =
	SetFP(static_cast<void (CCreatureObject::*)()>							(&CCreatureObject::UpdateFaceTalkerTimer),	0x955CD7);

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

	if (Eip == 0x78744E) { //from CScreenPriestBook::Update()
		nIndex += CUIButtonPriestBook_KnownSpellOffset;
	}

	return (this->*Tramp_CCreatureObject_GetKnownSpellPriest)(nLevel, nIndex);
}

CreFileKnownSpell& DETOUR_CCreatureObject::DETOUR_GetKnownSpellMage(int nLevel, int nIndex) {
	int Eip;
	GetEip(Eip);

	if (Eip == 0x7B8952) { //from CScreenMageBook::Update()
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

void __stdcall CCreatureObject_GetClassAbilities(CCreatureObject& cre, unsigned char cClass, int nLevels, IECPtrList& cpl) {
	if (0) IECString("CCreatureObject_GetClassAbilities4");

	IECString sAbilName;
	IECString sSpell;
	CRuleTable* pRuleTable = NULL;
	CDerivedStats* pcds = NULL;
	unsigned short wStartLevel;
	unsigned short cSubclassLevel;

	if (cClass == CLASS_RANGER && cre.m_BaseStats.dwFlags & CREFLAG_FALLEN_RANGER) {
		pRuleTable = &g_pChitin->pGame->CLABRN05;
	}
	else if (cClass == CLASS_PALADIN && cre.m_BaseStats.dwFlags & CREFLAG_FALLEN_PALADIN) {
		pRuleTable = &g_pChitin->pGame->CLABPA05;
	} else {
		pRuleTable = &g_pChitin->pGame->GetClassAbilityTable(cClass, cre.m_BaseStats.kit[1] | (cre.m_BaseStats.kit[0] << 16));
	}

	wStartLevel = 0;
	pcds = &cre.GetDerivedStats();
	cSubclassLevel = pcds->GetSubclassLevel(cre.o.GetClass(), cClass);
	if (nLevels != -1) {
		wStartLevel = cSubclassLevel - nLevels;
	}
	for (int nCol = wStartLevel; nCol < cSubclassLevel; nCol++) {
		if (nCol >= pRuleTable->nCols) break;
		for (int nRow = 0; nRow < pRuleTable->nRows; nRow++) {
			if (nCol < pRuleTable->nCols &&
				nRow < pRuleTable->nRows &&
				nCol >= 0 &&
				nRow >= 0) {
				sAbilName = *((pRuleTable->pDataArray) + (pRuleTable->nCols * nRow + nCol));
			} else {
				sAbilName = pRuleTable->defaultVal;
			}

			if (sAbilName.CompareNoCase(pRuleTable->GetDefaultValue())) {
				sSpell = sAbilName.Right(sAbilName.GetLength() - 3); //remove XX_ prefix
				sAbilName = sAbilName.Left(3); //XX_ prefix
				if (sAbilName.CompareNoCase("GA_") == 0) {
					cpl.AddTail(new ResRef((LPCTSTR)sSpell));
				}
			}
		}
	}

	POSITION pos = cpl.GetHeadPosition();
	while (pos) {
		ResRef* pr = (ResRef*)cpl.GetNext(pos);
	}

	return;
}

void __stdcall CCreatureObject_GetClassAbilities(CCreatureObject& cre, CDerivedStats& cdsTarget, IECPtrList& cpl) {
	if (0) IECString("CCreatureObject_GetClassAbilities3");

	unsigned char cClass = cre.oBase.GetClass();
	switch (cClass) {
	case CLASS_MAGE:
		CCreatureObject_GetClassAbilities(
			cre,
			CLASS_MAGE,
			cre.cdsCurrent.GetMageClassLevel(cClass) - cdsTarget.GetMageClassLevel(cClass),
			cpl
		);
		break;
	case CLASS_FIGHTER:
		CCreatureObject_GetClassAbilities(
			cre,
			CLASS_FIGHTER,
			cre.cdsCurrent.GetFighterClassLevel(cClass) - cdsTarget.GetFighterClassLevel(cClass),
			cpl
		);
		break;
	case CLASS_CLERIC:
		CCreatureObject_GetClassAbilities(
			cre,
			CLASS_CLERIC,
			cre.cdsCurrent.GetClericClassLevel(cClass) - cdsTarget.GetClericClassLevel(cClass),
			cpl
		);
		break;
	case CLASS_THIEF:
		CCreatureObject_GetClassAbilities(
			cre,
			CLASS_THIEF,
			cre.cdsCurrent.GetThiefClassLevel(cClass) - cdsTarget.GetThiefClassLevel(cClass),
			cpl
		);
		break;
	case CLASS_BARD:
		CCreatureObject_GetClassAbilities(
			cre,
			CLASS_BARD,
			cre.cdsCurrent.GetThiefClassLevel(cClass) - cdsTarget.GetThiefClassLevel(cClass),
			cpl
		);
		break;
	case CLASS_PALADIN:
		CCreatureObject_GetClassAbilities(
			cre,
			CLASS_PALADIN,
			cre.cdsCurrent.GetFighterClassLevel(cClass) - cdsTarget.GetFighterClassLevel(cClass),
			cpl
		);
		break;
	case CLASS_FIGHTER_MAGE:
		CCreatureObject_GetClassAbilities(
			cre,
			CLASS_FIGHTER,
			cre.cdsCurrent.GetFighterClassLevel(cClass) - cdsTarget.GetFighterClassLevel(cClass),
			cpl
		);
		CCreatureObject_GetClassAbilities(
			cre,
			CLASS_MAGE,
			cre.cdsCurrent.GetMageClassLevel(cClass) - cdsTarget.GetMageClassLevel(cClass),
			cpl
		);
		break;
	case CLASS_FIGHTER_CLERIC:
		CCreatureObject_GetClassAbilities(
			cre,
			CLASS_CLERIC,
			cre.cdsCurrent.GetClericClassLevel(cClass) - cdsTarget.GetClericClassLevel(cClass),
			cpl
		);
		CCreatureObject_GetClassAbilities(
			cre,
			CLASS_FIGHTER,
			cre.cdsCurrent.GetFighterClassLevel(cClass) - cdsTarget.GetFighterClassLevel(cClass),
			cpl
		);
		break;
	case CLASS_FIGHTER_THIEF:
		CCreatureObject_GetClassAbilities(
			cre,
			CLASS_THIEF,
			cre.cdsCurrent.GetThiefClassLevel(cClass) - cdsTarget.GetThiefClassLevel(cClass),
			cpl
		);
		CCreatureObject_GetClassAbilities(
			cre,
			CLASS_FIGHTER,
			cre.cdsCurrent.GetFighterClassLevel(cClass) - cdsTarget.GetFighterClassLevel(cClass),
			cpl
		);
		break;
	case CLASS_FIGHTER_MAGE_THIEF:
		CCreatureObject_GetClassAbilities(
			cre,
			CLASS_MAGE,
			cre.cdsCurrent.GetMageClassLevel(cClass) - cdsTarget.GetMageClassLevel(cClass),
			cpl
		);
		CCreatureObject_GetClassAbilities(
			cre,
			CLASS_THIEF,
			cre.cdsCurrent.GetThiefClassLevel(cClass) - cdsTarget.GetThiefClassLevel(cClass),
			cpl
		);
		CCreatureObject_GetClassAbilities(
			cre,
			CLASS_FIGHTER,
			cre.cdsCurrent.GetFighterClassLevel(cClass) - cdsTarget.GetFighterClassLevel(cClass),
			cpl
		);
		break;
	case CLASS_DRUID:
		CCreatureObject_GetClassAbilities(
			cre,
			CLASS_DRUID,
			cre.cdsCurrent.GetClericClassLevel(cClass) - cdsTarget.GetClericClassLevel(cClass),
			cpl
		);
		break;
	case CLASS_RANGER:
		CCreatureObject_GetClassAbilities(
			cre,
			CLASS_RANGER,
			cre.cdsCurrent.GetFighterClassLevel(cClass) - cdsTarget.GetFighterClassLevel(cClass),
			cpl
		);
		break;
	case CLASS_MAGE_THIEF:
		CCreatureObject_GetClassAbilities(
			cre,
			CLASS_MAGE,
			cre.cdsCurrent.GetMageClassLevel(cClass) - cdsTarget.GetMageClassLevel(cClass),
			cpl
		);
		CCreatureObject_GetClassAbilities(
			cre,
			CLASS_THIEF,
			cre.cdsCurrent.GetThiefClassLevel(cClass) - cdsTarget.GetThiefClassLevel(cClass),
			cpl
		);
		break;
	case CLASS_CLERIC_MAGE:
		CCreatureObject_GetClassAbilities(
			cre,
			CLASS_CLERIC,
			cre.cdsCurrent.GetClericClassLevel(cClass) - cdsTarget.GetClericClassLevel(cClass),
			cpl
		);
		CCreatureObject_GetClassAbilities(
			cre,
			CLASS_MAGE,
			cre.cdsCurrent.GetMageClassLevel(cClass) - cdsTarget.GetMageClassLevel(cClass),
			cpl
		);
		break;
	case CLASS_CLERIC_THIEF:
		CCreatureObject_GetClassAbilities(
			cre,
			CLASS_CLERIC,
			cre.cdsCurrent.GetClericClassLevel(cClass) - cdsTarget.GetClericClassLevel(cClass),
			cpl
		);
		CCreatureObject_GetClassAbilities(
			cre,
			CLASS_THIEF,
			cre.cdsCurrent.GetThiefClassLevel(cClass) - cdsTarget.GetThiefClassLevel(cClass),
			cpl
		);
		break;
	case CLASS_FIGHTER_DRUID:
		CCreatureObject_GetClassAbilities(
			cre,
			CLASS_DRUID,
			cre.cdsCurrent.GetClericClassLevel(cClass) - cdsTarget.GetClericClassLevel(cClass),
			cpl
		);
		CCreatureObject_GetClassAbilities(
			cre,
			CLASS_FIGHTER,
			cre.cdsCurrent.GetFighterClassLevel(cClass) - cdsTarget.GetFighterClassLevel(cClass),
			cpl
		);
		break;
	case CLASS_FIGHTER_MAGE_CLERIC:
		CCreatureObject_GetClassAbilities(
			cre,
			CLASS_CLERIC,
			cre.cdsCurrent.GetClericClassLevel(cClass) - cdsTarget.GetClericClassLevel(cClass),
			cpl
		);
		CCreatureObject_GetClassAbilities(
			cre,
			CLASS_FIGHTER,
			cre.cdsCurrent.GetFighterClassLevel(cClass) - cdsTarget.GetFighterClassLevel(cClass),
			cpl
		);
		CCreatureObject_GetClassAbilities(
			cre,
			CLASS_MAGE,
			cre.cdsCurrent.GetMageClassLevel(cClass) - cdsTarget.GetMageClassLevel(cClass),
			cpl
		);
		break;
	case CLASS_CLERIC_RANGER:
		CCreatureObject_GetClassAbilities(
			cre,
			CLASS_CLERIC,
			cre.cdsCurrent.GetClericClassLevel(cClass) - cdsTarget.GetClericClassLevel(cClass),
			cpl
		);
		CCreatureObject_GetClassAbilities(
			cre,
			CLASS_RANGER,
			cre.cdsCurrent.GetFighterClassLevel(cClass) - cdsTarget.GetFighterClassLevel(cClass),
			cpl
		);
		break;
	case CLASS_SORCERER:
		CCreatureObject_GetClassAbilities(
			cre,
			CLASS_SORCERER,
			cre.cdsCurrent.GetMageClassLevel(cClass) - cdsTarget.GetMageClassLevel(cClass),
			cpl
		);
		break;
	case CLASS_MONK:
		CCreatureObject_GetClassAbilities(
			cre,
			CLASS_MONK,
			cre.cdsCurrent.GetThiefClassLevel(cClass) - cdsTarget.GetThiefClassLevel(cClass),
			cpl
		);
		break;
	default:
		CCreatureObject_GetClassAbilities(
			cre,
			CLASS_FIGHTER,
			cre.cdsCurrent.GetFighterClassLevel(cClass) - cdsTarget.GetFighterClassLevel(cClass),
			cpl
		);
		break;
	}

	return;
}

void __stdcall CCreatureObject_JoinParty_UpdateClassAbilities(CCreatureObject& cre, CDerivedStats& cds) {
	if (0) IECString("CCreatureObject_JoinParty_UpdateClassAbilities");

	IECPtrList cplInnate;
	IECPtrList cplModify;
	POSITION pos;
	POSITION pos2;
	CreFileMemSpell* pMemSpell;

	//create a list of all used class abilities
	pos = cre.m_MemSpellsInnate.GetHeadPosition();
	while (pos) {
		pMemSpell = (CreFileMemSpell*)cre.m_MemSpellsInnate.GetNext(pos);
		if (!(pMemSpell->wFlags & CREMEMSPELL_MEMORIZED)) {
			cplInnate.AddTail(new ResRef(pMemSpell->name));
		}
	}

	//create a list of all class abilities to be modified
	CCreatureObject_GetClassAbilities(cre, cds, cplModify);

	//trim modify list to only include class abilities that need to be un-memorised
	pos = cplModify.GetHeadPosition();
	while (pos) {
		bool bMatch = false;

		POSITION posCurrent = pos;
		ResRef* pr = (ResRef*)cplModify.GetNext(pos);
		pos2 = cplInnate.GetHeadPosition();
		while (pos2) {
			POSITION posCurrent2 = pos2;
			ResRef* pr2 = (ResRef*)cplInnate.GetNext(pos2);
			if (*pr == *pr2) {
				bMatch = true;
				cplInnate.RemoveAt(posCurrent2);
				delete pr2;
				pr2 = NULL;
				break;
			}
		}
		if (pos2 == NULL && bMatch == false) {
			cplModify.RemoveAt(posCurrent);
			delete pr;
			pr = NULL;
		}
	}

	//vanilla code
	cre.RemoveClassAbilities(cds);
	cre.ApplyClassAbilities(cds, FALSE);

	//un-memorise previously used abilities
	pos = cplModify.GetHeadPosition();
	while (pos) {
		ResRef* prName = (ResRef*)cplModify.GetNext(pos);

		pos2 = cre.m_MemSpellsInnate.GetHeadPosition();
		while (pos2) {
			pMemSpell = (CreFileMemSpell*)cre.m_MemSpellsInnate.GetNext(pos2);
			if (pMemSpell->name == *prName && pMemSpell->wFlags & CREMEMSPELL_MEMORIZED) {
				pMemSpell->wFlags &= ~(CREMEMSPELL_MEMORIZED);
				break;
			}
		}
	}

	while (!cplInnate.IsEmpty()) delete (ResRef*)cplInnate.RemoveHead();
	while (!cplModify.IsEmpty()) delete (ResRef*)cplModify.RemoveHead();

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
	ACTIONRESULT ar = ACTIONRESULT_NONE;

	if (aCurrent.opcode == ACTION_BREAK_INSTANTS) SetCurrentAction(GetTopAction(g_pActionTemp));

	switch (aCurrent.opcode) {
	case ACTION_BREAK_INSTANTS:
		ar = ACTIONRESULT_NONE; //re-implement here to prevent weird behaviour for double BreakInstants()
		break;
	default:
		return (this->*Tramp_CCreatureObject_ExecuteAction)();
		break;
	}

	arCurrent = ar;
	bExecutingAction = FALSE;

	return ar;
}

ACTIONRESULT DETOUR_CCreatureObject::DETOUR_ActionPickPockets(CCreatureObject& creTarget) {
	if (0) IECString("DETOUR_CCreatureObject::DETOUR_ActionPickPockets");

	if (!pGameOptionsEx->bActionPickpocketRemainHidden &&
		!pGameOptionsEx->bTriggerPickpocketFailed &&
		(!pGameOptionsEx->bEngineExternStealSlots || !pRuleEx->m_StealSlots.m_2da.bLoaded)
	) {
		return (this->*Tramp_CCreatureObject_ActionPickPockets)(creTarget);
	}

	if (&creTarget == NULL ||
		creTarget.bScheduled == FALSE ||
		creTarget.bActive == FALSE ||
		creTarget.bFree == FALSE)
		return ACTIONRESULT_FAILED;

	if (this->GetDerivedStats().ButtonDisable[1]) {
		PrintEventMessage(EVENTMESSAGE_PICKPOCKET_DISABLED_ARMOR, 0, 0, 0, -1, 0, IECString(""));
		return ACTIONRESULT_FAILED;
	}

	if (creTarget.o.MatchCriteria(this->o.GetOpposingEAObject(), FALSE, FALSE, FALSE)) {
		PrintEventMessage(EVENTMESSAGE_PICKPOCKET_FAILED_HOSTILE, 0, 0, 0, -1, 0, IECString(""));
		return ACTIONRESULT_FAILED;
	}

	if (creTarget.m_bInStore) return ACTIONRESULT_FAILED;

	POINT ptTarget = {creTarget.m_currentLoc.x / PIXELS_PER_SEARCHMAP_PT_X, creTarget.m_currentLoc.y / PIXELS_PER_SEARCHMAP_PT_Y};
	POINT ptSource = {this->m_currentLoc.x / PIXELS_PER_SEARCHMAP_PT_X, this->m_currentLoc.y / PIXELS_PER_SEARCHMAP_PT_Y};
	int nDistance = GetLongestAxialDistance(ptSource, ptTarget);

	if (nDistance > 4 ||
		this->pArea->CheckPointsAccessible(creTarget.m_currentLoc, this->m_currentLoc, this->tt2, FALSE, this->GetSightRadius()) == FALSE
	) {
		ACTIONRESULT ar = this->ActionMoveToObject(creTarget);
		if (ar == ACTIONRESULT_NONE) ar = ACTIONRESULT_SUCCESS;
		return ar;
	}

	if (!pGameOptionsEx->bActionPickpocketRemainHidden &&
		this->GetDerivedStats().stateFlags & STATE_INVISIBLE) {
		ITEM_EFFECT eff;
		CEffect::CreateItemEffect(eff, 0x88);
		eff.timing = TIMING_INSTANT_PERMANENT;

		POINT ptDest = {-1, -1};

		CEffect& ceff = CEffect::CreateEffect(eff, this->m_currentLoc, this->e, ptDest, ENUM_INVALID_INDEX);

		CMessageApplyEffect* pMsg = IENew CMessageApplyEffect();
		pMsg->eTarget = this->e;
		pMsg->eSource = this->e;
		pMsg->pCEffect = &ceff;
		pMsg->u10 = 0;
		g_pChitin->messages.Send(*pMsg, FALSE);
	}

	int nDieRoll = IERand(100) + 1;

	if (nDieRoll == 100 ||
		nDieRoll >= this->GetDerivedStats().pickPockets - creTarget.GetDerivedStats().pickPockets ||
		creTarget.GetDerivedStats().pickPockets == 0x0FF
	) {
		//failed
		PrintEventMessage(EVENTMESSAGE_PICKPOCKET_FAILED, 0, 0, 0, -1, 0, IECString(""));

		if (!pGameOptionsEx->bTriggerPickpocketFailedOnly) {
			Trigger tAttackedBy(TRIGGER_ATTACKED_BY, this->o, 0);
			CMessageSetTrigger* pMsgST = IENew CMessageSetTrigger();
			pMsgST->eTarget = creTarget.e;
			pMsgST->eSource = this->e;
			pMsgST->t = tAttackedBy;
			g_pChitin->messages.Send(*pMsgST, FALSE);
		}

		if (pGameOptionsEx->bTriggerPickpocketFailed ||
			pGameOptionsEx->bTriggerPickpocketFailedOnly) {
			Trigger tPickpocketFailed(TRIGGER_PICKPOCKET_FAILED, this->o, 0);
			CMessageSetTrigger* pMsgST2 = IENew CMessageSetTrigger();
			pMsgST2->eTarget = creTarget.e;
			pMsgST2->eSource = this->e;
			pMsgST2->t = tPickpocketFailed;
			g_pChitin->messages.Send(*pMsgST2, FALSE);
		}

		if (pGameOptionsEx->bTriggerPickpocketFailedOnly) {
			CMessageFaceTalker* pMsgFT = IENew CMessageFaceTalker();
			pMsgFT->eTarget = creTarget.e;
			pMsgFT->eSource = creTarget.e;
			pMsgFT->eTalker = ENUM_INVALID_INDEX;
			pMsgFT->nTicks = 0;
			g_pChitin->messages.Send(*pMsgFT, FALSE);
		}

		if (pGameOptionsEx->bActionPickpocketRemainHidden &&
			this->GetDerivedStats().stateFlags & STATE_INVISIBLE) {
			ITEM_EFFECT eff;
			CEffect::CreateItemEffect(eff, 0x88);

			POINT dest = {-1, -1};

			CEffect& ceff = CEffect::CreateEffect(eff, this->m_currentLoc, this->e, dest, ENUM_INVALID_INDEX);

			CMessageApplyEffect* pcmAE = IENew CMessageApplyEffect();
			pcmAE->eTarget = this->e;
			pcmAE->eSource = this->e;
			pcmAE->pCEffect = &ceff;
			pcmAE->u10 = 0;
			g_pChitin->messages.Send(*pcmAE, FALSE);
		}

		if (this->o.EnemyAlly <= EA_GOODCUTOFF) {
			if (creTarget.InDialogAction() ||
				creTarget.m_bInDialogue) {
				CMessageInterruptDialogue* pMsgID = IENew CMessageInterruptDialogue();
				pMsgID->eTarget = creTarget.e;
				pMsgID->eSource = this->e;
				g_pChitin->messages.Send(*pMsgID, FALSE);
			}
		}

		return ACTIONRESULT_NONE;
	}

	BOOL bNotStealableArray[39]; //FIX_ME, should use a global variable
	for (int iSlotIdx = 0; iSlotIdx < *g_pInventorySlots; iSlotIdx++) {
		bNotStealableArray[iSlotIdx] = 0;
	}

	if (pGameOptionsEx->bEngineExternStealSlots && pRuleEx->m_StealSlots.m_2da.bLoaded) {
		for (int iRow = 0; iRow < *g_pInventorySlots; iRow++) {
			if (iRow == SLOT_FIST) {
				bNotStealableArray[iRow] = 1;
				continue;
			}

			if (iRow >= pRuleEx->m_StealSlots.nRows) break;
			int nCol = 0;
			if (nCol >= pRuleEx->m_StealSlots.nCols) break;

			IECString sValue = *((pRuleEx->m_StealSlots.pDataArray) + (pRuleEx->m_StealSlots.nCols * iRow + nCol));
			int nValue = atoi((LPCTSTR)sValue);
			if (nValue == 0 || nValue > this->GetDerivedStats().pickPockets) bNotStealableArray[iRow] = 1;
		}

		IECString sRowName("SLOT_EQUIPPED");
		IECString sColName("SKILL");
		IECString sValue(pRuleEx->m_StealSlots.GetValue(sColName, sRowName));
		int nValue = atoi((LPCTSTR)sValue);

		if (nValue == 0 || nValue > this->GetDerivedStats().pickPockets) {
			bNotStealableArray[creTarget.m_Inventory.nSlotSelected] = 1;

			short nSlotEquippedLauncher = creTarget.GetSlotOfEquippedLauncherOfAmmo(creTarget.m_Inventory.nSlotSelected, creTarget.m_Inventory.nAbilitySelected);
			if (nSlotEquippedLauncher != -1) bNotStealableArray[nSlotEquippedLauncher] = 1;
		}

	} else {
		bNotStealableArray[SLOT_FIST] = 1;
		bNotStealableArray[SLOT_ARMOR] = 1;
		bNotStealableArray[SLOT_BELT] = 1;
		bNotStealableArray[SLOT_BOOTS] = 1;
		bNotStealableArray[SLOT_CLOAK] = 1;
		bNotStealableArray[SLOT_GAUNTLETS] = 1;
		bNotStealableArray[SLOT_HELMET] = 1;
		bNotStealableArray[SLOT_SHIELD] = 1;
		bNotStealableArray[creTarget.m_Inventory.nSlotSelected] = 1;

		short nSlotEquippedLauncher = creTarget.GetSlotOfEquippedLauncherOfAmmo(creTarget.m_Inventory.nSlotSelected, creTarget.m_Inventory.nAbilitySelected);
		if (nSlotEquippedLauncher != -1) bNotStealableArray[nSlotEquippedLauncher] = 1;
	}

	IECString sNameTarget(creTarget.szScriptName);
	short nSlotToStealFirst = IERand(*g_pInventorySlots);
	short nSlotToSteal = nSlotToStealFirst;
	while (bNotStealableArray[nSlotToSteal] ||
		creTarget.m_Inventory.items[nSlotToSteal] == NULL ||
		creTarget.m_Inventory.items[nSlotToSteal]->dwFlags & CREITEM_UNSTEALABLE ||
		!(creTarget.m_Inventory.items[nSlotToSteal]->GetFlags() & ITEMFLAG_DROPPABLE) ||
		creTarget.m_Inventory.items[nSlotToSteal]->dwFlags & CREITEM_UNDROPPABLE ||
		(sNameTarget.CompareNoCase("MINSC") == 0 && creTarget.m_Inventory.items[nSlotToSteal]->m_itm.name == "MISC84") ||
		(sNameTarget.CompareNoCase("ALORA") == 0 && creTarget.m_Inventory.items[nSlotToSteal]->m_itm.name == "MISC88") ||
		(sNameTarget.CompareNoCase("EDWIN") == 0 && creTarget.m_Inventory.items[nSlotToSteal]->m_itm.name == "MISC89") ||
		creTarget.m_Inventory.items[nSlotToSteal]->GetType() == ITEMTYPE_CONTAINER
	) {
		if (nSlotToStealFirst % 2) {
			nSlotToSteal--;
			if (nSlotToSteal < 0) nSlotToSteal = static_cast<short>(*g_pInventorySlots) - 1;
		} else {
			nSlotToSteal++;
			if (nSlotToSteal >= static_cast<short>(*g_pInventorySlots)) nSlotToSteal = 0;
		}

		if (nSlotToSteal == nSlotToStealFirst) {
			PrintEventMessage(EVENTMESSAGE_PICKPOCKET_NO_ITEMS, 0, 0, 0, -1, 0, IECString(""));
			return ACTIONRESULT_NONE;
		}
	}

	if (IERand(*g_pRandStealGoldChance) == 0 &&
		g_pChitin->pGame->GetPartyMemberSlot(this->e) == -1) {
		int nGoldToSteal = IERand(*g_pRandGoldToSteal);
		CMessageModifyPartyGold* pMsgMPG = IENew CMessageModifyPartyGold();
		pMsgMPG->eTarget = this->e;
		pMsgMPG->eSource = this->e;
		pMsgMPG->nGold = nGoldToSteal;
		pMsgMPG->cMode = 1; //sum
		pMsgMPG->bPrintMessage = true;
		g_pChitin->messages.Send(*pMsgMPG, FALSE);

		PrintEventMessage(EVENTMESSAGE_PICKPOCKET_SUCCESS, 0, 0, 0, -1, 0, IECString(""));
		return ACTIONRESULT_NONE;
	}

	CItem* pItemToSteal = creTarget.m_Inventory.items[nSlotToSteal];
	if (g_pChitin->pGame->GetPartyMemberSlot(this->e) == -1) {
		//non-party
		for (int iSlotIdx = 0; iSlotIdx < 20; iSlotIdx++) {
			if (this->m_Inventory.items[iSlotIdx + SLOT_MISC0] == NULL) {
				CItem* pItem = IENew CItem(*pItemToSteal);
				this->m_Inventory.items[iSlotIdx + SLOT_MISC0] = pItem;

				CMessageRemoveItem* pMsgRI = IENew CMessageRemoveItem();
				pMsgRI->eTarget = creTarget.e;
				pMsgRI->eSource = this->e;
				pMsgRI->wSlot = nSlotToSteal;
				g_pChitin->messages.Send(*pMsgRI, FALSE);

				PrintEventMessage(EVENTMESSAGE_PICKPOCKET_SUCCESS, 0, 0, 0, -1, 0, IECString(""));
				return ACTIONRESULT_NONE;
			}
		}

		PrintEventMessage(EVENTMESSAGE_PICKPOCKET_INV_FULL, 0, 0, 0, -1, 0, IECString(""));
		return ACTIONRESULT_FAILED;

	} else {
		//party
		for (int iSlotIdx = 0; iSlotIdx < *g_pNumInventorySlots; iSlotIdx++) {
			if (this->m_Inventory.items[iSlotIdx + SLOT_MISC3] == NULL) {
				CItem* pItem = IENew CItem(*pItemToSteal);
				this->m_Inventory.items[iSlotIdx + SLOT_MISC3] = pItem;

				CMessageRemoveItem* pMsgRI = IENew CMessageRemoveItem();
				pMsgRI->eTarget = creTarget.e;
				pMsgRI->eSource = this->e;
				pMsgRI->wSlot = nSlotToSteal;
				g_pChitin->messages.Send(*pMsgRI, FALSE);

				PrintEventMessage(EVENTMESSAGE_PICKPOCKET_SUCCESS, 0, 0, 0, -1, 0, IECString(""));
				return ACTIONRESULT_NONE;
			}
		}

		PrintEventMessage(EVENTMESSAGE_PICKPOCKET_INV_FULL, 0, 0, 0, -1, 0, IECString(""));
		return ACTIONRESULT_FAILED;
	}
}

void DETOUR_CCreatureObject::DETOUR_UpdateFaceTalkerTimer() {
	if (m_nFaceTalkerTimer > 0) {
		POSITION pos = triggers.GetHeadPosition();
		while (pos) {
			Trigger* pt = (Trigger*)triggers.GetNext(pos);
			if (pt->opcode == TRIGGER_ATTACKED_BY ||
				pt->opcode == TRIGGER_HIT_BY) {
				m_nFaceTalkerTimer = 0;
				m_eTalker = ENUM_INVALID_INDEX;
				break;
			}
		}
	}
	return;
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
		sColname.Format("%d", nCol);
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

BOOL __stdcall CCreatureObject_AttackOnce_DoHalfAttack(CCreatureObject& creSource, char cInRoundIdx) {
	if (0) IECString("CCreatureObject_AttackOnce_DoHalfAttack");

	const char cInRoundOffset = 9;
	int nthAttack = cInRoundIdx - 9;
	CDerivedStats* pcds = &creSource.GetDerivedStats();
	int nAttacks = pcds->numAttacks - 5;

	if (nthAttack < nAttacks) { //full attack
		creSource.m_bIsAttacking = TRUE;
		creSource.m_bStatisticalAttack = true;
		if (!pGameOptionsEx->bActionAttackOnceFix) creSource.m_wDoHalfAttack = 0; //original code
		
		if (nthAttack == nAttacks - 1) { //last full attack
			creSource.m_bUsingLeftWeapon = TRUE;
		}
		if (nAttacks == 2) creSource.m_bUsingLeftWeapon = FALSE;
	} else {
		if (nthAttack == nAttacks) { //half attack
			if (!pGameOptionsEx->bActionAttackOnceFix) { //original code
				creSource.m_bIsAttacking = TRUE;
				creSource.m_bStatisticalAttack = true;
				creSource.m_bUsingLeftWeapon = FALSE;
				creSource.m_wDoHalfAttack = 1;
				if (IERand(2) == 0) {
					creSource.m_bStatisticalAttack = TRUE;
					creSource.m_bUsingLeftWeapon = FALSE;
					creSource.m_wDoHalfAttack = 0;
				} else {
					creSource.m_bStatisticalAttack = false;
					creSource.m_bUsingLeftWeapon = FALSE;
					creSource.m_wDoHalfAttack = 0;
				}
			} else { //fixed code
				if (creSource.m_wDoHalfAttack == 1) { //do half attack
					creSource.m_bIsAttacking = TRUE;
					creSource.m_bStatisticalAttack = true;
					creSource.m_bUsingLeftWeapon = FALSE;
					if (nAttacks == 2) creSource.m_bUsingLeftWeapon = TRUE;

					creSource.m_wDoHalfAttack = 0;
				} else { //don't do half attack
					creSource.m_bStatisticalAttack = false;
					creSource.m_bUsingLeftWeapon = FALSE;

					creSource.m_wDoHalfAttack = 1;
				}
			}
		} else { //nthAttack > nAttacks
			creSource.m_bStatisticalAttack = FALSE;
			creSource.m_bUsingLeftWeapon = FALSE;
			if (!pGameOptionsEx->bActionAttackOnceFix) creSource.m_wDoHalfAttack = 0; //original code
		}
	}

	return creSource.m_bStatisticalAttack;
}