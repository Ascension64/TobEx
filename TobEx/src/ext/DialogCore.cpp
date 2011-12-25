#include "DialogCore.h"

#include "chitin.h"
#include "ScriptAction.h"

void __stdcall CDlgResponse_ExecuteSetVariables(CDlgResponse& cdResponse, CCreatureObject& cre) {
	if (0) IECString("CDlgResponse_ExecuteSetVariables");

	POSITION pos = cdResponse.m_responseActive.m_actions.GetHeadPosition();
	POSITION posOld;
	while ((posOld = pos) != NULL) {
		Action* pa = (Action*)cdResponse.m_responseActive.m_actions.GetNext(pos);
		if (pa->opcode == ACTION_SET_GLOBAL ||
			pa->opcode == ACTION_SG ||
			pa->opcode == ACTION_INCREMENT_GLOBAL) {
			if (CGameSprite_AtomicSetGlobal(cre, *pa)) {
				cdResponse.m_responseActive.m_actions.RemoveAt(posOld);
				delete pa;
			}
		}
	}
	return;
}
