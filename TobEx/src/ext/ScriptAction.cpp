#include "ScriptAction.h"

#include "stdafx.h"
#include "effcore.h"
#include "msgcore.h"
#include "chitin.h"

BOOL CGameSprite_AtomicSetGlobal(CGameSprite& sprite, Action& a) {
	IECString sArg = a.GetSName1();
	sArg.MakeUpper();
	IECString sScope = sArg.Left(6);
	IECString sVariable = sArg.Right(sArg.GetLength() - 6);
	CVariable varNew;

	BOOL bIncrement = a.opcode == ACTION_INCREMENT_GLOBAL;
	int nNewValue;

	CGameSprite* pTarget = NULL;
	Object oOverride = a.oOverride;
	if (!oOverride.MatchCriteria(*poAny, FALSE, FALSE, FALSE) ||
		!oOverride.Name.IsEmpty() ||
		oOverride.oids.id1 != OBJECT_NOTHING) {
		oOverride.DecodeIdentifiers(sprite);
		pTarget = (CGameSprite*)&oOverride.FindTargetOfType(sprite, CGAMEOBJECT_TYPE_SPRITE, FALSE);
		if (pTarget) {
			a.oOverride = *poAny;
		} else {
			return TRUE;
		}
	} else {
		pTarget = &sprite;
	}

	if (a.opcode == ACTION_SG) {
		sScope = "GLOBAL";
		sVariable = sArg;
	}

	if (!sScope.Compare("GLOBAL")) {
		CVariable& var = g_pChitin->pGame->m_GlobalVariables.Find(sVariable);
		if (&var != NULL) {
			var.value = bIncrement ? var.value + a.i : a.i;
			nNewValue = var.value;
		} else {
			varNew.name = sVariable;
			varNew.value = a.i;
			nNewValue = varNew.value;
			g_pChitin->pGame->m_GlobalVariables.Add(varNew);
		}

		CMessageModifyVariable* pMsg = IENew CMessageModifyVariable();
		pMsg->eSource = pTarget->e;
		pMsg->eTarget = pTarget->e;
		pMsg->sScope = sScope;
		pMsg->sVariable = sVariable;
		pMsg->nValue = nNewValue;
		pMsg->nBehaviour = 0;
		g_pChitin->messages.Send(*pMsg, FALSE);

		return TRUE;
	}

	if (!sScope.Compare("LOCALS")) {
		if (pTarget->GetType() == CGAMEOBJECT_TYPE_CREATURE) {
			CVariable& var = ((CCreatureObject*)pTarget)->m_pLocalVariables->Find(sVariable);
			if (&var != NULL) {
				var.value = bIncrement ? var.value + a.i : a.i;
				nNewValue = var.value;
			} else {
				varNew.name = sVariable;
				varNew.value = a.i;
				nNewValue = varNew.value;
				((CCreatureObject*)pTarget)->m_pLocalVariables->Add(varNew); //64A2E8
			}

			CMessageModifyVariable* pMsg = IENew CMessageModifyVariable();
			pMsg->eSource = pTarget->e;
			pMsg->eTarget = pTarget->e;
			pMsg->sScope = sScope;
			pMsg->sVariable = sVariable;
			pMsg->nValue = nNewValue;
			pMsg->nBehaviour = 0;
			g_pChitin->messages.Send(*pMsg, FALSE);

			return TRUE;
		} else {
			LPCTSTR lpsz = "CGameSprite_AtomicSetGlobal(): pTarget not CGAMEOBJECT_TYPE_CREATURE for setting LOCALS\r\n";
			L.timestamp();
			L.append(lpsz);
			console.write(lpsz);
			return TRUE;
		}
	}

	if (!sScope.Compare("MYAREA")) {
		sScope = pTarget->pArea->rAreaName.FormatToString();
	}
	CArea& area = g_pChitin->pGame->GetLoadedArea(sScope);
	if (&area != NULL) {
		CVariable& var = area.m_AreaVariables.Find(sVariable);
		if (&var != NULL) {
			var.value = bIncrement ? var.value + a.i : a.i;
			nNewValue = var.value;
		} else {
			varNew.name = sVariable;
			varNew.value = a.i;
			nNewValue = varNew.value;
			area.m_AreaVariables.Add(varNew);
		}

		CMessageModifyVariable* pMsg = IENew CMessageModifyVariable();
		pMsg->eSource = pTarget->e;
		pMsg->eTarget = pTarget->e;
		pMsg->sScope = sScope;
		pMsg->sVariable = sVariable;
		pMsg->nValue = nNewValue;
		pMsg->nBehaviour = 0;
		g_pChitin->messages.Send(*pMsg, FALSE);

		return TRUE;
	}

	return TRUE;
}
