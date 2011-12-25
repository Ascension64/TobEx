#ifndef INFGAMECOMMON_H
#define INFGAMECOMMON_H

#include "infgame.h"

class CRuleTablesEx {
public:
	CRuleTablesEx();

	//members
	CRuleTable m_ClassRaceReq;
	CRuleTable m_MageSchoolRaceReq;
	CRuleTable m_HideSpell;
	CRuleTable m_RaceText;
	CRuleTable m_AnimWalkSound;
	CRuleTable m_AnimTerrainSound;

protected:
	void Init();
};

extern CRuleTablesEx* pRuleEx;

#endif //INFGAMECOMMON_H