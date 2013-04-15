//TobExEE
#include "InfGameCommon.h"

#include "optionsext.h"
#include "chitin.h"

//CBlockVariables
CBlockVariables::CBlockVariables() {
	for (int i = 0; i < BLOCK_VAR_ARRAY_SIZE; i++) {
		m_Ints[i] = 0;
	}
}

void CBlockVariables::Empty() {
	for (int i = 0; i < BLOCK_VAR_ARRAY_SIZE; i++) {
		m_Ints[i] = 0;
		m_Strs[i].Empty();
	}
}

int CBlockVariables::GetInt(unsigned int index) {
	return (index >= 0 && index < BLOCK_VAR_ARRAY_SIZE) ? m_Ints[index] : 0;
}

IECString CBlockVariables::GetStr(unsigned int index) {
	return (index >= 0 && index < BLOCK_VAR_ARRAY_SIZE) ? m_Strs[index] : IECString();
}

void CBlockVariables::SetInt(unsigned int index, int value) {
	if (index >= 0 && index < BLOCK_VAR_ARRAY_SIZE) m_Ints[index] = value;
}

void CBlockVariables::SetStr(unsigned int index, IECString value) {
	if (index >= 0 && index < BLOCK_VAR_ARRAY_SIZE) m_Strs[index] = value;
}

//CRuleTablesEx
static MathPresso::mreal_t mpAnd(MathPresso::mreal_t x, MathPresso::mreal_t y) { return (int)x && (int)y; }
static MathPresso::mreal_t mpOr(MathPresso::mreal_t x, MathPresso::mreal_t y) { return (int)x || (int)y; }
static MathPresso::mreal_t mpBAnd(MathPresso::mreal_t x, MathPresso::mreal_t y) { return (int)x & (int)y; }
static MathPresso::mreal_t mpBOr(MathPresso::mreal_t x, MathPresso::mreal_t y) { return (int)x | (int)y; }

CRuleTablesEx* pRuleEx = NULL;
int g_nCDerivedStatsTemplateSize = 0;

CRuleTablesEx::CRuleTablesEx(CRuleTables& rule) {
	Init(rule);
}

CRuleTablesEx::~CRuleTablesEx() {
	std::map<ENUM, CBlockVariables*>::iterator it;
	for (it = m_MapActionVars.begin(); it != m_MapActionVars.end(); it++) {
		delete it->second;
		it->second = NULL;
	}
	m_MapActionVars.clear();
}

void CRuleTablesEx::Init(CRuleTables& rule) {

	/*if (pGameOptionsEx->GetOption("Engine_ExpandedStats")) {
		Identifiers idStats("STATS");
		if (!idStats.m_ids.bLoaded) {
			LPCTSTR lpsz = "CRuleTablesEx::Init(): Something went wrong with loading STATS.IDS. Expanded Stats is disabled.\r\n";
			console.write(lpsz);
			L.timestamp();
			L.append(lpsz);
			m_nStats = 201;
		} else {
			int nHighestStat = 400; //incorporates new hard-coded stats 202-400
			POSITION pos = idStats.entries.GetHeadPosition();
			while (pos != NULL) {
				IdsEntry* pIde = (IdsEntry*)(idStats.entries.GetNext(pos));
				nHighestStat = max(nHighestStat, pIde->nOpcode);
			}
			m_nStats = nHighestStat;
		}
		g_nCDerivedStatsTemplateSize = sizeof(CDerivedStatsTemplate) + (m_nStats - 200 - 1) * 4;
	}*/

	m_mpContext.addFunction("and", mpAnd, MathPresso::MFUNC_F_ARG2);
	m_mpContext.addFunction("or", mpOr, MathPresso::MFUNC_F_ARG2);
	m_mpContext.addFunction("band", mpBAnd, MathPresso::MFUNC_F_ARG2);
	m_mpContext.addFunction("bor", mpBOr, MathPresso::MFUNC_F_ARG2);

	return;
}