#include "ScriptTrigger.h"

#include "console.h"

BOOL __stdcall CCreatureObject_EvaluateTrigger_Kit(int dwKit, CreFileHeader* pHeader) {
	int dwCreKit = pHeader->m_wKit[1] | pHeader->m_wKit[0] << 16;
	if (dwKit == 0) return !pHeader->m_wKit[1];
	return dwKit == dwCreKit;
}
