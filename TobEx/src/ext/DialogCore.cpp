#include "DialogCore.h"

#include "chitin.h"
#include "ScriptAction.h"

void __stdcall CDlgResponse_QueueActions(CDlgResponse& cdResponse, CCreatureObject& cre) {
	if (0) IECString("CDlgResponse_QueueActions");

	if (cdResponse.m_response.m_actions.GetCount()) {
		if (!cdResponse.bAddedInterrupts) {
			cdResponse.bAddedInterrupts = TRUE;

			Action* pAInterruptFalse = new Action();
			pAInterruptFalse->opcode = ACTION_SET_INTERRUPT;
			pAInterruptFalse->i = 0;
			cdResponse.m_response.m_actions.AddHead(pAInterruptFalse);

			Action* pAInterruptTrue = new Action();
			pAInterruptTrue->opcode = ACTION_SET_INTERRUPT;
			pAInterruptTrue->i = 1;
			cdResponse.m_response.m_actions.AddHead(pAInterruptTrue);
		}

		//new - atomic set global
		POSITION pos = cdResponse.m_response.m_actions.GetHeadPosition();
		POSITION posOld;
		while ((posOld = pos) != NULL) {
			Action* pa = (Action*)cdResponse.m_response.m_actions.GetNext(pos);
			if (pa->opcode == ACTION_DIALOG_SET_GLOBAL ||
				pa->opcode == ACTION_DIALOG_SG ||
				pa->opcode == ACTION_DIALOG_INCREMENT_GLOBAL) {
				if (CGameSprite_AtomicSetGlobal(cre, *pa)) {
					cdResponse.m_response.m_actions.RemoveAt(posOld);
					delete pa;
				}
			}
		}

		CMessageQueueActions* pMsgQA = IENew CMessageQueueActions();
		pMsgQA->eSource = cre.e;
		pMsgQA->eTarget = cre.e;
		pMsgQA->r = cdResponse.m_response;
		pMsgQA->bClearActionQueue = FALSE;
		pMsgQA->bSkipIfAlreadyQueued = FALSE;
		g_pChitin->messages.Send(*pMsgQA, FALSE);

		CMessageSetTriggerRemovalTimer* pMsgSTRT = IENew CMessageSetTriggerRemovalTimer();
		pMsgSTRT->eSource = cre.e;
		pMsgSTRT->eTarget = cre.e;
		pMsgSTRT->wTicks = 75;
		g_pChitin->messages.Send(*pMsgSTRT, FALSE);
	}

	return;
}
