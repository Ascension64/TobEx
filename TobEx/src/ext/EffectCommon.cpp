#include "EffectCommon.h"

CEffect* CEffectList_FindPrevious(CEffectList& list, CEffect& eff, POSITION posCurrent, CCreatureObject& cre) {
	POSITION pos = posCurrent ? posCurrent : list.GetTailPosition();
	CEffect* pFound = NULL;
	
	if (posCurrent) list.GetPrev(pos); //skip the current effect

	while (pos) {
		CEffect* pEff = (CEffect*)list.GetPrev(pos);
		if ((pEff->effect.nSaveType & CEFFECT_STACKING_LIMIT) && //previous effect limits stacking
			!(pEff->effect.nSaveType & CEFFECT_STACKING_SUSPEND) && //previous effect not suspended
			eff.effect.nOpcode == pEff->effect.nOpcode && //same opcode
			eff.effect.nSpecial == pEff->effect.nSpecial) { //same stacking ID
			pFound = pEff;
			break;
		}
	}

	return pFound;
}