//TobExEE
#ifndef INFGAMECOMMON_H
#define INFGAMECOMMON_H

#include "infgame.h"

//block variable array sizes
const int BLOCK_VAR_ARRAY_SIZE = 25;

//CBlockVariables
class CBlockVariables {
public:
	CBlockVariables();
	void Empty();
	int GetInt(unsigned int index);
	IECString GetStr(unsigned int index);
	void SetInt(unsigned int index, int value);
	void SetStr(unsigned int index, IECString value);

protected:
	int m_Ints[BLOCK_VAR_ARRAY_SIZE];
	IECString m_Strs[BLOCK_VAR_ARRAY_SIZE];
};

//CRuleTablesEx
class CRuleTablesEx {
public:
	CRuleTablesEx(CRuleTables& rule);
	~CRuleTablesEx();

	int m_nStats;
	MathPresso::Context m_mpContext;
	CBlockVariables m_TriggerVars;
	std::map<ENUM, CBlockVariables*> m_MapActionVars; //stores action block variables for each ENUM as required

protected:
	void Init(CRuleTables& rule);
};

extern CRuleTablesEx* pRuleEx;
extern int g_nCDerivedStatsTemplateSize;

#endif //INFGAMECOMMON_H