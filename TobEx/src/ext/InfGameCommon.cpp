#include "InfGameCommon.h"

#include "utils.h"
#include "console.h"
#include "log.h"

CRuleTablesEx* pRuleEx = NULL;

CRuleTablesEx::CRuleTablesEx() {
	Init();
}

void CRuleTablesEx::Init() {

	if (GetIniValue("Engine", "Externalise Class-Race Restrictions")) {
		m_AnimWalkSound.LoadTable(ResRef("ANIWKSND"));
		if (!m_AnimWalkSound.m_2da.bLoaded) {
			LPCTSTR lpsz = "CRuleTablesEx::Init(): ANIWKSND.2DA not found. Did you install the required WeiDU component?\r\n";
			console.write(lpsz);
			L.timestamp();
			L.append(lpsz);
		}
	}

	if (GetIniValue("Engine", "Externalise Class-Race Restrictions")) {
		m_AnimTerrainSound.LoadTable(ResRef("ANITNSND"));
		if (!m_AnimTerrainSound.m_2da.bLoaded) {
			LPCTSTR lpsz = "CRuleTablesEx::Init(): ANITNSND.2DA not found. Did you install the required WeiDU component?\r\n";
			console.write(lpsz);
			L.timestamp();
			L.append(lpsz);
		}
	}

	if (GetIniValue("Engine", "Externalise Class-Race Restrictions")) {
		m_ClassRaceReq.LoadTable(ResRef("CLSRCREQ"));
		if (!m_ClassRaceReq.m_2da.bLoaded) {
			LPCTSTR lpsz = "CRuleTablesEx::Init(): CLSRCREQ.2DA not found. Did you install the required WeiDU component?\r\n";
			console.write(lpsz);
			L.timestamp();
			L.append(lpsz);
		}
	}

	if (GetIniValue("Engine", "Externalise Class-Race Restrictions")) {
		m_MageSchoolRaceReq.LoadTable(ResRef("MGSRCREQ"));
		if (!m_MageSchoolRaceReq.m_2da.bLoaded) {
			LPCTSTR lpsz = "CRuleTablesEx::Init(): MGSRCREQ.2DA not found. Did you install the required WeiDU component?\r\n";
			console.write(lpsz);
			L.timestamp();
			L.append(lpsz);
		}
	}

	if (GetIniValue("UI", "Externalise Mage Spell Hiding")) {
		m_HideSpell.LoadTable(ResRef("HIDESPL"));
		if (!m_HideSpell.m_2da.bLoaded) {
			LPCTSTR lpsz = "CRuleTablesEx::Init(): HIDESPL.2DA not found. Did you install the required WeiDU component?\r\n";
			console.write(lpsz);
			L.timestamp();
			L.append(lpsz);
		}
	}

	if (GetIniValue("UI", "Externalise Race Selection StrRef")) {
		m_RaceText.LoadTable(ResRef("RACETEXT"));
		if (!m_RaceText.m_2da.bLoaded) {
			LPCTSTR lpsz = "CRuleTablesEx::Init(): RACETEXT.2DA not found. Did you install the required WeiDU component?\r\n";
			console.write(lpsz);
			L.timestamp();
			L.append(lpsz);
		}
	}

	return;
}