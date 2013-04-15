//TobExEE
#include "ScriptCore.h"
#include "p_scrcore.h"

#include "chitin.h"
#include "optionsext.h"
#include "objcore.h"
#include "InfGameCommon.h"
#include "ScriptCommon.h"

//CScriptBlock
DefineTrampMemberFunc(BOOL, CScriptBlock, Evaluate, (CTriggerList& triggers, CGameSprite& sprite), Evaluate, Evaluate, CSCRIPTBLOCK_EVALUATE);

BOOL DETOUR_CScriptBlock::DETOUR_Evaluate(CTriggerList& triggers, CGameSprite& sprite) {
	if (0) IECString("DETOUR_CScriptBlock::DETOUR_Evaluate");

	//normal trigger variables
	BOOL bResult = FALSE;
	int nOr = 0;
	bool bBreak = false;
	
	//NextTriggerObject() variables
	BOOL bOverrideObject = FALSE;
	Object oOverride;
	CGameSprite* pOverrideSprite = NULL;

	//Eval() variables
	BOOL bOverrideInt[] = { FALSE, FALSE };
	int nOverride[] = { 0, 0 };
	BOOL bOverrideStr[] = { FALSE, FALSE };
	IECString sOverride[2];

	POSITION pos = m_lTriggers.GetHeadPosition();
	if (pos == NULL) return TRUE;

	while (pos != NULL && !bBreak) {
		if (nOr <= 0) bResult = FALSE; //AND
		Trigger* pt = (Trigger*)m_lTriggers.GetNext(pos);
		Trigger tCopy = *pt;
		
		switch (tCopy.m_wOpcode) {
		case TRIGGER_NEXT_TRIGGER_OBJECT:
			oOverride = tCopy.m_o;
			oOverride.DecodeIdentifiers(sprite);
			pOverrideSprite = (CGameSprite*)&oOverride.FindTargetOfType((CGameObject&)sprite, CGAMEOBJECT_TYPE_SPRITE, FALSE);
			bOverrideObject = TRUE;
			break;

		case TRIGGER_ASSIGN:
		{
			IECString sStatement = tCopy.m_s1;
			CGameSprite* pSpriteTarget = (bOverrideObject && pOverrideSprite) ? pOverrideSprite : &sprite;
					
			if (tCopy.m_i2 >= 0 && tCopy.m_i2 < BLOCK_VAR_ARRAY_SIZE) {
				if (tCopy.m_i == ARGTYPE_INT) {
					ParseStatement(tCopy.m_i2, tCopy.m_i, sStatement, *pSpriteTarget, pRuleEx->m_TriggerVars);
				} else if (tCopy.m_i == ARGTYPE_STR) {
					ParseStatement(tCopy.m_i2, tCopy.m_i, sStatement, *pSpriteTarget, pRuleEx->m_TriggerVars);
				}
			}

			//clean up
			bOverrideObject = FALSE;
			pOverrideSprite = NULL;
			break;
		} //TRIGGER_ASSIGN

		case TRIGGER_EVAL:
		{
			IECString sExpression = ParseBlockVariables(tCopy.m_s1, tCopy.m_i, pRuleEx->m_TriggerVars);
			int nLoc = (tCopy.m_i2 - 1) & 1;

			if (tCopy.m_i == ARGTYPE_INT) {
				int nValue = 0;
				MathPresso::Expression mpExp;
				MathPresso::mresult_t mpResult = mpExp.create(pRuleEx->m_mpContext, (LPCTSTR)sExpression);
				if (mpResult == MathPresso::MRESULT_OK) {
					nValue = mpExp.evaluate(NULL);
				} else {
					LPCTSTR lpsz = "Trigger Eval(): bad expression \"%s\" (error %d)\r\n";
					L.timestamp();
					L.appendf(lpsz, (LPCTSTR)sExpression, (int)mpResult);
					console.writef(lpsz, (LPCTSTR)sExpression, (int)mpResult);
				}

				bOverrideInt[nLoc] = TRUE;
				nOverride[nLoc] = nValue;
			} else if (tCopy.m_i == ARGTYPE_STR) {
				bOverrideStr[nLoc] = TRUE;
				sOverride[nLoc] = sExpression;
			}

			break;
		} //TRIGGER_EVAL

		default:
			//set OR value
			if (tCopy.m_wOpcode == TRIGGER_OR) {
				nOr = tCopy.m_i;
			} else nOr--;

			//substitute trigger parameters
			if (bOverrideInt[0]) {
				tCopy.m_i = nOverride[0];
				nOverride[0] = 0;
				bOverrideInt[0] = FALSE;
			}
			if (bOverrideInt[1]) {
				tCopy.m_i2 = nOverride[1];
				nOverride[1] = 0;
				bOverrideInt[1] = FALSE;
			}
			if (bOverrideStr[0]) {
				tCopy.m_s1 = sOverride[0];
				sOverride[0].Empty();
				bOverrideStr[0] = FALSE;
			}
			if (bOverrideStr[1]) {
				tCopy.m_s2 = sOverride[1];
				sOverride[1].Empty();
				bOverrideStr[1] = FALSE;
			}

			//evaluate trigger depending on override object
			if (bOverrideObject) {
				if (pOverrideSprite) {
					if ((tCopy.m_wOpcode & 0x4000) == 0) pt->DecodeIdentifiers(*pOverrideSprite); //workaround for 0x0XXX triggers that need the original trigger decoded to work properly
					bResult |= EvaluateTrigger(tCopy, triggers, *pOverrideSprite);
				} else bResult |= FALSE;
				bOverrideObject = FALSE;
				pOverrideSprite = NULL;
			} else {
				if ((tCopy.m_wOpcode & 0x4000) == 0) pt->DecodeIdentifiers(sprite); //workaround for 0x0XXX triggers that need the original trigger decoded to work properly
				bResult |= EvaluateTrigger(tCopy, triggers, sprite);
			}

			//terminate if not in OR
			if (bResult == FALSE &&	nOr <= 0) {
				//return FALSE;
				bResult = FALSE;
				bBreak = true;
			}

			break;
		} // switch(tCopy.opcode)
	} //while (pos != NULL)

	//clean up variables
	pRuleEx->m_TriggerVars.Empty();
	return bResult;
}
