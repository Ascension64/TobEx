#include "InfGameCommon.h"

#include "stdafx.h"

CRuleTablesEx* pRuleEx = NULL;

CRuleTablesEx::CRuleTablesEx() {
	Init();
}

void CRuleTablesEx::Init() {

	if (pGameOptionsEx->bEffStrengthMod || pGameOptionsEx->bEffDexterityMod) {
		m_ClassSpellAbility.LoadTable(ResRef("CLSSPLAB"));
		if (!m_ClassSpellAbility.m_2da.bLoaded) {
			LPCTSTR lpsz = "CRuleTablesEx::Init(): CLSSPLAB.2DA not found\r\n";
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
		m_ItemCreExclude.LoadTable(ResRef("ITCREXCL"));
		if (!m_ItemCreExclude.m_2da.bLoaded) {
			LPCTSTR lpsz = "CRuleTablesEx::Init(): ITCREXCL.2DA not found\r\n";
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

	return;
}