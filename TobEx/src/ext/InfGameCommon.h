#ifndef INFGAMECOMMON_H
#define INFGAMECOMMON_H

#include "infgame.h"

class CRuleTablesEx {
public:
	CRuleTablesEx();

	CRuleTable m_ClassSpellAbility;
	CRuleTable m_ClassRaceReq;
	CRuleTable m_MageSchoolRaceReq;
	CRuleTable m_HideSpell;
	CRuleTable m_RaceText;
	CRuleTable m_AnimWalkSound;
	CRuleTable m_AnimTerrainSound;
	CRuleTable m_ItemCreExclude;
	int m_nStats;
	CRuleTable m_Encumbrance;
	short m_nEncumbranceLowThreshold;
	short m_nEncumbranceHighThreshold;
	CRuleTable m_HPClass;
	CRuleTable m_HPBarbarian;

protected:
	void Init();
};

extern CRuleTablesEx* pRuleEx;

#endif //INFGAMECOMMON_H