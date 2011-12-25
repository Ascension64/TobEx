#include "EffectCommon.h"

bool CEffect_IsSimilar(CEffect& eff1, CEffect& eff2) {
	if (eff1.effect.nOpcode == eff2.effect.nOpcode &&
		eff1.effect.nTarget == eff2.effect.nTarget &&
		eff1.effect.nSplLvl == eff2.effect.nSplLvl &&
		eff1.effect.nParam1 == eff2.effect.nParam1 &&
		eff1.effect.nParam2 == eff2.effect.nParam2 &&
		eff1.effect.wProbHigh == eff2.effect.wProbHigh &&
		eff1.effect.wProbLow == eff2.effect.wProbLow &&
		eff1.effect.rResource == eff2.effect.rResource &&
		eff1.effect.nDice == eff2.effect.nDice &&
		eff1.effect.nDieSides == eff2.effect.nDieSides &&
		(eff1.effect.nSaveType & 0x000000FF) == (eff2.effect.nSaveType & 0x000000FF) &&
		eff1.effect.bStoreLocalVariableParam == eff2.effect.bStoreLocalVariableParam &&
		eff1.effect.nType1 == eff2.effect.nType1 &&
		eff1.effect.nLevelMin == eff2.effect.nLevelMin &&
		eff1.effect.nLevelMax == eff2.effect.nLevelMax &&
		eff1.effect.dwFlags == eff2.effect.dwFlags &&
		eff1.effect.nParam3 == eff2.effect.nParam3 &&
		eff1.effect.nParam4 == eff2.effect.nParam4 &&
		eff1.effect.rResource2 == eff2.effect.rResource2 &&
		eff1.effect.rResource3 == eff2.effect.rResource3 &&
		eff1.effect.nParentResourceType == eff2.effect.nParentResourceType &&
		eff1.effect.rParentResource == eff2.effect.rParentResource &&
		eff1.effect.dwParentFlags == eff2.effect.dwParentFlags &&
		eff1.effect.nParentProjectile == eff2.effect.nParentProjectile &&
		eff1.effect.nType2 == eff2.effect.nType2
	) {
		return true;
	} else {
		return false;
	}
}

CEffect* CEffectList_Find(CEffectList& list, CEffect& eff, POSITION posCurrent, CCreatureObject& cre) {
	POSITION pos = posCurrent ? posCurrent : list.GetTailPosition();
	CEffect* pFound = NULL;
	if (posCurrent != NULL) {
		list.GetPrev(pos); //skip the current effect
	}

	while (pos != NULL) {
		CEffect* pEff = (CEffect*)list.GetPrev(pos);
		if (!(pEff->effect.nSaveType & EFFECT_STACKING_SUSPEND)) {
			if (CEffect_IsSimilar(eff, *pEff)) {
				pFound = pEff;
				break;
			}
		}
	}

	return pFound;
}