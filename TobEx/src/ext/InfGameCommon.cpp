#include "InfGameCommon.h"

#include "stdafx.h"
#include "chitin.h"

CRuleTablesEx* pRuleEx = NULL;
int g_nCDerivedStatsTemplateSize = 0;

CRuleTablesEx::CRuleTablesEx(CRuleTables& rule) {
	Init(rule);
}

CRuleTablesEx::~CRuleTablesEx() {
	delete m_StrModExToStepTable;
	m_StrModExToStepTable = NULL;
	delete m_StepToStrModExTable;
	m_StepToStrModExTable = NULL;
}

void CRuleTablesEx::Init(CRuleTables& rule) {

	if (pGameOptionsEx->bEffStrengthMod || pGameOptionsEx->bEffDexterityMod) {
		m_ClassSpellAbility.LoadTable(ResRef("CLSSPLAB"));
		if (!m_ClassSpellAbility.m_2da.bLoaded) {
			LPCTSTR lpsz = "CRuleTablesEx::Init(): CLSSPLAB.2DA not found\r\n";
			console.write(lpsz);
			L.timestamp();
			L.append(lpsz);
		}
	}

	if (pGameOptionsEx->bEffStrengthMod) {
		if (!rule.STRMODEX.m_2da.bLoaded) {
			rule.STRMODEX.LoadTable(ResRef("STRMODEX"));
		}
	    if (rule.STRMODEX.m_2da.bLoaded) {
			m_StrModExStepNum = 0;
			m_StrModExToStepTable = new char[101];
			m_StepToStrModExTable = new char[101];
			IECString sToHit = "TO_HIT";
			IECString sDamage = "DAMAGE";
			IECString sBBLG = "BEND_BARS_LIFT_GATES";
			IECString sWeight = "WEIGHT_ALLOWANCE";
			IECString sIdx;
			IECString sOldToHit;
			IECString sOldDamage;
			IECString sOldBBLG;
			IECString sOldWeight;
			IECString sNewToHit; 
			IECString sNewDamage;
			IECString sNewBBLG;  
			IECString sNewWeight;
			for (char i = 0; i < 101; ++i) {
				sIdx.Format("%d", i);
				sNewToHit = rule.STRMODEX.GetValue(sToHit, sIdx);
				sNewDamage = rule.STRMODEX.GetValue(sDamage, sIdx);
				sNewBBLG = rule.STRMODEX.GetValue(sBBLG, sIdx);
				sNewWeight = rule.STRMODEX.GetValue(sWeight, sIdx);

				if (i > 0) {
					if (sNewToHit.CompareNoCase(sOldToHit) || 
						sNewDamage.CompareNoCase(sOldDamage) ||
						sNewBBLG.CompareNoCase(sOldBBLG) ||
						sNewWeight.CompareNoCase(sOldWeight)) {
						m_StepToStrModExTable[m_StrModExStepNum++] = i;
					}
				}

				m_StrModExToStepTable[i] = 18 + m_StrModExStepNum;

				sOldToHit = sNewToHit;
				sOldDamage = sNewDamage;
				sOldBBLG = sNewBBLG;
				sOldWeight = sNewWeight;
			}
		} else {
			LPCTSTR lpsz = "CRuleTablesEx::Init(): STRMODEX.2DA not found\r\n";
			console.write(lpsz);
			L.timestamp();
			L.append(lpsz);
		}
	}
 
	if (pGameOptionsEx->bEngineExternClassRaceRestrictions) {
		m_ClassRaceReq.LoadTable(ResRef("CLSRCREQ"));
		if (!m_ClassRaceReq.m_2da.bLoaded) {
			LPCTSTR lpsz = "CRuleTablesEx::Init(): CLSRCREQ.2DA not found\r\n";
			console.write(lpsz);
			L.timestamp();
			L.append(lpsz);
		}
	}

	if (pGameOptionsEx->bEngineExternClassRaceRestrictions) {
		m_MageSchoolRaceReq.LoadTable(ResRef("MGSRCREQ"));
		if (!m_MageSchoolRaceReq.m_2da.bLoaded) {
			LPCTSTR lpsz = "CRuleTablesEx::Init(): MGSRCREQ.2DA not found\r\n";
			console.write(lpsz);
			L.timestamp();
			L.append(lpsz);
		}
	}

	if (pGameOptionsEx->bSoundExternWalkSounds) {
		m_AnimWalkSound.LoadTable(ResRef("ANIWKSND"));
		if (!m_AnimWalkSound.m_2da.bLoaded) {
			LPCTSTR lpsz = "CRuleTablesEx::Init(): ANIWKSND.2DA not found\r\n";
			console.write(lpsz);
			L.timestamp();
			L.append(lpsz);
		}
	}

	if (pGameOptionsEx->bSoundExternWalkSounds) {
		m_AnimTerrainSound.LoadTable(ResRef("ANITNSND"));
		if (!m_AnimTerrainSound.m_2da.bLoaded) {
			LPCTSTR lpsz = "CRuleTablesEx::Init(): ANITNSND.2DA not found\r\n";
			console.write(lpsz);
			L.timestamp();
			L.append(lpsz);
		}
	}

	if (pGameOptionsEx->bUserExternMageSpellHiding) {
		m_HideSpell.LoadTable(ResRef("HIDESPL"));
		if (!m_HideSpell.m_2da.bLoaded) {
			LPCTSTR lpsz = "CRuleTablesEx::Init(): HIDESPL.2DA not found\r\n";
			console.write(lpsz);
			L.timestamp();
			L.append(lpsz);
		}
	}

	if (pGameOptionsEx->bUserExternRaceSelectionText) {
		m_RaceText.LoadTable(ResRef("RACETEXT"));
		if (!m_RaceText.m_2da.bLoaded) {
			LPCTSTR lpsz = "CRuleTablesEx::Init(): RACETEXT.2DA not found\r\n";
			console.write(lpsz);
			L.timestamp();
			L.append(lpsz);
		}
	}

	if (pGameOptionsEx->bItemsExternCreExcl) {
		m_ItemCreExclude.LoadTable(ResRef("ITEM_USE"));
		if (!m_ItemCreExclude.m_2da.bLoaded) {
			LPCTSTR lpsz = "CRuleTablesEx::Init(): ITEM_USE.2DA not found\r\n";
			console.write(lpsz);
			L.timestamp();
			L.append(lpsz);
		}
	}

	if (pGameOptionsEx->bEngineExpandedStats) {
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
	}

	m_nEncumbranceLowThreshold = -1;
	m_nEncumbranceHighThreshold = -1;

	if (pGameOptionsEx->bEngineExternEncumbrance) {
		m_Encumbrance.LoadTable(ResRef("ENCUMBER"));
		if (!m_Encumbrance.m_2da.bLoaded) {
			LPCTSTR lpsz = "CRuleTablesEx::Init(): ENCUMBER.2DA not found\r\n";
			console.write(lpsz);
			L.timestamp();
			L.append(lpsz);
		} else {
			short s;
			IECString sLowThreshold = m_Encumbrance.GetValue(IECString("THRESHOLD"), IECString("LOW_ENCUMBRANCE"));
			IECString sHighThreshold = m_Encumbrance.GetValue(IECString("THRESHOLD"), IECString("HIGH_ENCUMBRANCE"));

			sscanf_s((LPCTSTR)sLowThreshold, "%d", &s);
			m_nEncumbranceLowThreshold = s;

			sscanf_s((LPCTSTR)sHighThreshold, "%d", &s);
			m_nEncumbranceHighThreshold = s;
		}
	}

	if (m_nEncumbranceLowThreshold < 0) m_nEncumbranceLowThreshold = 100;
	if (m_nEncumbranceHighThreshold < 0) m_nEncumbranceHighThreshold = 120;

	if (pGameOptionsEx->bEngineExternHPTables) {
		m_HPClass.LoadTable(ResRef("HPCLASS"));
		if (!m_HPClass.m_2da.bLoaded) {
			LPCTSTR lpsz = "CRuleTablesEx::Init(): HPCLASS.2DA not found\r\n";
			console.write(lpsz);
			L.timestamp();
			L.append(lpsz);
		}

		m_HPBarbarian.LoadTable(ResRef("HPBARB"));
		if (!m_HPBarbarian.m_2da.bLoaded) {
			LPCTSTR lpsz = "CRuleTablesEx::Init(): HPBARB.2DA not found\r\n";
			console.write(lpsz);
			L.timestamp();
			L.append(lpsz);
		}
	}

	if (pGameOptionsEx->bEngineExternStealSlots) {
		m_StealSlots.LoadTable(ResRef("SLTSTEAL"));
		if (!m_StealSlots.m_2da.bLoaded) {
			LPCTSTR lpsz = "CRuleTablesEx::Init(): SLTSTEAL.2DA not found\r\n";
			console.write(lpsz);
			L.timestamp();
			L.append(lpsz);
		}
	}

	return;
}