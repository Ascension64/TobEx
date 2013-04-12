#include "ScriptAction.h"

#include "stdafx.h"
#include "effcore.h"
#include "msgcore.h"
#include "objcre.h"
#include "chitin.h"
#include "InfGameCommon.h"
#include "ScriptCommon.h"

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
	if (!oOverride.MatchCriteria(*g_poAny, FALSE, FALSE, FALSE) ||
		!oOverride.m_sName.IsEmpty() ||
		oOverride.m_oids.id1 != OBJECT_NOTHING) {
		oOverride.DecodeIdentifiers(sprite);
		pTarget = (CGameSprite*)&oOverride.FindTargetOfType(sprite, CGAMEOBJECT_TYPE_SPRITE, FALSE);
		if (pTarget) {
			a.oOverride = *g_poAny;
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
			var.m_nValue = bIncrement ? var.m_nValue + a.i : a.i;
			nNewValue = var.m_nValue;
		} else {
			varNew.SetName(sVariable);
			varNew.m_nValue = a.i;
			nNewValue = varNew.m_nValue;
			g_pChitin->pGame->m_GlobalVariables.Add(varNew);
		}

		CMessageModifyVariable* pMsg = IENew CMessageModifyVariable();
		pMsg->eSource = pTarget->e;
		pMsg->eTarget = pTarget->e;
		pMsg->sScope = sScope;
		pMsg->sVariable = sVariable;
		pMsg->nValue = nNewValue;
		pMsg->nBehaviour = 0;
		g_pChitin->m_MessageHandler.AddMessage(*pMsg, FALSE);

		return TRUE;
	}

	if (!sScope.Compare("LOCALS")) {
		if (pTarget->GetType() == CGAMEOBJECT_TYPE_CREATURE) {
			CVariable& var = ((CCreatureObject*)pTarget)->m_pLocalVariables->Find(sVariable);
			if (&var != NULL) {
				var.m_nValue = bIncrement ? var.m_nValue + a.i : a.i;
				nNewValue = var.m_nValue;
			} else {
				varNew.SetName(sVariable);
				varNew.m_nValue = a.i;
				nNewValue = varNew.m_nValue;
				((CCreatureObject*)pTarget)->m_pLocalVariables->Add(varNew); //64A2E8
			}

			CMessageModifyVariable* pMsg = IENew CMessageModifyVariable();
			pMsg->eSource = pTarget->e;
			pMsg->eTarget = pTarget->e;
			pMsg->sScope = sScope;
			pMsg->sVariable = sVariable;
			pMsg->nValue = nNewValue;
			pMsg->nBehaviour = 0;
			g_pChitin->m_MessageHandler.AddMessage(*pMsg, FALSE);

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
			var.m_nValue = bIncrement ? var.m_nValue + a.i : a.i;
			nNewValue = var.m_nValue;
		} else {
			varNew.SetName(sVariable);
			varNew.m_nValue = a.i;
			nNewValue = varNew.m_nValue;
			area.m_AreaVariables.Add(varNew);
		}

		CMessageModifyVariable* pMsg = IENew CMessageModifyVariable();
		pMsg->eSource = pTarget->e;
		pMsg->eTarget = pTarget->e;
		pMsg->sScope = sScope;
		pMsg->sVariable = sVariable;
		pMsg->nValue = nNewValue;
		pMsg->nBehaviour = 0;
		g_pChitin->m_MessageHandler.AddMessage(*pMsg, FALSE);

		return TRUE;
	}

	return TRUE;
}

ACTIONRESULT CGameSprite_ActionAssign(CGameSprite& sprite, Action& a) {
	IECString sStatement = a.sName1;
	CGameSprite* pSpriteRef = NULL;
	if (!a.oObject.IsAny()) {
		a.oObject.DecodeIdentifiers(sprite);
		pSpriteRef = (CGameSprite*)&a.oObject.FindTargetOfType(sprite, CGAMEOBJECT_TYPE_SPRITE, FALSE);
	} else {
		pSpriteRef = &sprite;
	}
	if (pSpriteRef &&
		a.i2 >= 0 && a.i2 < BLOCK_VAR_ARRAY_SIZE) {
		std::map<ENUM, CBlockVariables*>::iterator it = pRuleEx->m_MapActionVars.find(sprite.e);
		if (it == pRuleEx->m_MapActionVars.end()) pRuleEx->m_MapActionVars[sprite.e] = new CBlockVariables();

		if (a.i == ARGTYPE_INT) {
			ParseStatement(a.i2, a.i, sStatement, *pSpriteRef, *pRuleEx->m_MapActionVars[sprite.e]);
		} else if (a.i == ARGTYPE_STR) {
			ParseStatement(a.i2, a.i, sStatement, *pSpriteRef, *pRuleEx->m_MapActionVars[sprite.e]);
		}
	}

	return ACTIONRESULT_DONE;
}

ACTIONRESULT CGameSprite_ActionEval(CGameSprite& sprite, Action& a) {
	IECString sExpression;
	Action* aTarget = NULL;

	std::map<ENUM, CBlockVariables*>::iterator it = pRuleEx->m_MapActionVars.find(sprite.e);
	if (it == pRuleEx->m_MapActionVars.end()) {
		sExpression = a.sName1;
	} else {
		sExpression = ParseBlockVariables(a.sName1, a.i, *pRuleEx->m_MapActionVars[sprite.e]);
	}

	POSITION pos = sprite.actions.GetHeadPosition();
	POSITION posTarget = NULL;
	while (posTarget = pos) {
		Action* aTemp = (Action*)sprite.actions.GetNext(pos);
		if (aTemp->opcode == ACTION_CLEAR_BLOCK_VARIABLES) {
			posTarget = NULL;
			break;
		}
		if (aTemp->opcode != ACTION_EVAL &&
			aTemp->opcode != ACTION_ASSIGN)
			break;
	}
	if (posTarget) {
		aTarget = (Action*)sprite.actions.GetAt(posTarget);
	}

	if (aTarget) {
		if (a.i == ARGTYPE_INT) {
			int nValue = 0;
			MathPresso::Expression mpExp;
			MathPresso::mresult_t mpResult = mpExp.create(pRuleEx->m_mpContext, (LPCTSTR)sExpression);
			if (mpResult == MathPresso::MRESULT_OK) {
				nValue = mpExp.evaluate(NULL);
			} else {
				LPCTSTR lpsz = "Action Eval(): bad expression \"%s\" (error %d)\r\n";
				L.timestamp();
				L.appendf(lpsz, (LPCTSTR)sExpression, (int)mpResult);
				console.writef(lpsz, (LPCTSTR)sExpression, (int)mpResult);
			}

			switch (a.i2) {
			case 1: //int1
				aTarget->i = nValue;
				break;
			case 2: //int2
				aTarget->i2 = nValue;
				break;
			case 3: //int3
				aTarget->i3 = nValue;
				break;
			case 4: //pt.x
				aTarget->pt.x = nValue;
				break;
			case 5: //pt.y
				aTarget->pt.y = nValue;
				break;
			default:
				break;
			}

		} else if (a.i == ARGTYPE_STR) {
			switch (a.i2) {
			case 1: //int1
				aTarget->sName1 = sExpression;
				break;
			case 2: //int2
				aTarget->sName2 = sExpression;
				break;
			default:
				break;
			}
		}
	}

	return ACTIONRESULT_DONE;
}

ACTIONRESULT CGameSprite_ActionClearBlockVars(CGameSprite& sprite) {
	std::map<ENUM, CBlockVariables*>::iterator it = pRuleEx->m_MapActionVars.find(sprite.e);
	if (it != pRuleEx->m_MapActionVars.end()) {
		it->second->Empty();
		/*delete pRuleEx->m_MapActionVars[sprite.e];
		pRuleEx->m_MapActionVars[sprite.e] = NULL;
		pRuleEx->m_MapActionVars.erase(it);*/
	}

	return ACTIONRESULT_DONE;
}

void CCreatureObject_ActionChangeAnimation_CopyState(CCreatureObject& creOld, CCreatureObject& creNew) {
	creNew.SetResRef(ResRef(creOld.aCurrent.GetSName1()));
	if (creOld.m_header.m_wHitPoints <= 0) creNew.m_header.m_dwGeneralState |= STATE_DEAD;
	return;
}