#ifndef INFGAMECOMMON_H
#define INFGAMECOMMON_H

#include "infgame.h"

class CRuleTablesEx {
public:
	CRuleTablesEx(CRuleTables& rule);
	~CRuleTablesEx();

	CRuleTable m_ClassSpellAbility;
	char m_StrModExStepNum;
	char* m_StrModExToStepTable;
	char* m_StepToStrModExTable;

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
	CRuleTable m_StealSlots;

protected:
	void Init(CRuleTables& rule);
};

extern CRuleTablesEx* pRuleEx;
extern int g_nCDerivedStatsTemplateSize;

#endif //INFGAMECOMMON_H