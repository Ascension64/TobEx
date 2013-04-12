#include "infgame.h"

//CWorldTimer
DefineLibMemberFunc(void, CWorldTimer, UnpauseGame, (), UnpauseGame, UnpauseGame, (), 0x649F8E);
DefineLibMemberFunc(void, CWorldTimer, PauseGame, (), PauseGame, PauseGame, (), 0x64A068);

//CPartySelection
DefineLibMemberFunc(ENUM, CPartySelection, GetFirstSelected, (), GetFirstSelected, GetFirstSelected, (), 0x408976);

//CRuleTable
DefineLibNoRetFunc(CRuleTable&, CRuleTable, CRuleTable, (), Construct, Construct, (), 0x63E230);
DefineLibMemberFunc(void, CRuleTable, LoadTable, (ResRef& r), LoadTable, LoadTable, (r), 0x402D85);
DefineLibMemberFunc(IECString&, CRuleTable, GetValue, (IECString& sColName, IECString& sRowName), GetValue, GetValue2, (sColName, sRowName), 0x4047EF);
DefineLibMemberFunc(bool, CRuleTable, FindString, (IECString& s, POSITION* ppos, BOOL bCheckHeaders), FindString, FindString, (s, ppos, bCheckHeaders), 0x404D61);
DefineLibMemberFunc(void, CRuleTable, UnloadRes, (), UnloadRes, UnloadRes, (), 0x43C010);
DefineLibMemberFunc(IECString, CRuleTable, GetDefaultValue, (), GetDefaultValue, GetDefaultValue, (), 0x43C6B0);
DefineLibMemberFunc(IECString&, CRuleTable, GetValue, (CPoint& ptColRow), GetValue, GetValue1, (ptColRow), 0x63E2B0);

CRuleTable::~CRuleTable() { //as 0x43C420 except for ~CString()
	if (pColHeaderArray) delete[] pColHeaderArray;
	if (pRowHeaderArray) delete[] pRowHeaderArray;
	if (pDataArray) delete[] pDataArray;
	UnloadRes();
	//CString defaultVal is automatically removed
}

IECString& CRuleTable::GetRowName(int nRow) {
	if (nRow < nRows &&
		nRow >= 0) {
		return *(pRowHeaderArray + nRow);
	} else {
		return defaultVal;
	}
}

IECString& CRuleTable::GetColName(int nCol) {
	if (nCol < nCols &&
		nCol >= 0) {
		return *(pColHeaderArray + nCol);
	} else {
		return defaultVal;
	}
}

//CRuleTables
DefineLibNoRetFunc(CRuleTables&, CRuleTables, CRuleTables, (), Construct, Construct, (), 0x6213DC);
DefineLibNoRetFunc(void, CRuleTables, ~CRuleTables, (), Deconstruct, Deconstruct, (), 0x6279D1);
DefineLibMemberFunc(IECString, CRuleTables, GetRaceString, (unsigned char nRace), GetRaceString, GetRaceString, (nRace), 0x62ACC5);
DefineLibMemberFunc(IECString, CRuleTables, GetAlignmentString, (char align), GetAlignmentString, GetAlignmentString, (align), 0x62AEA4);
DefineLibMemberFunc(IECString, CRuleTables, GetClassString, (unsigned char nClass, unsigned int dwKit), GetClassString, GetClassString, (nClass, dwKit), 0x62B072);
DefineLibMemberFunc(int, CRuleTables, CalculateNewHPRule, (
	CRuleTable& rule,
	int nLevelOld,
	int nLevelNew,
	int nMinRoll,
	int nDivisor,
	BOOL bOverrideSides,
	int nOverrideSides,
	BOOL bOverrideModifier,
	int nOverrideModifier
	), CalculateNewHPRule, CalculateNewHPRule, (rule, nLevelOld, nLevelNew, nMinRoll, nDivisor, bOverrideSides, nOverrideSides, bOverrideModifier, nOverrideModifier), 0x630ED4);
DefineLibMemberFunc(int, CRuleTables, CalculateNewHPSubclass, (
	char nClass,
	char nSubclass,
	CDerivedStats& cdsOld,
	CDerivedStats& cdsNew,
	int nMinRoll,
	int nDivisor
	), CalculateNewHPSubclass, CalculateNewHPSubclass, (nClass, nSubclass, cdsOld, cdsNew, nMinRoll, nDivisor), 0x631055);
DefineLibMemberFunc(int, CRuleTables, GetMaxMageSpells, (int nSpellLevel), GetMaxMageSpells, GetMaxMageSpells, (nSpellLevel), 0x6335D3);
DefineLibMemberFunc(ResRef, CRuleTables, GetMageSpellRef, (int nSpellLevel, int nIndex), GetMageSpellRef, GetMageSpellRef, (nSpellLevel, nIndex), 0x633691);
DefineLibMemberFunc(STRREF, CRuleTables, GetCharSndStrRef, (int dwCustom, int dwRow, char sex), GetCharSndStrRef, GetCharSndStrRef, (dwCustom, dwRow, sex), 0x63511C);
DefineLibMemberFunc(void, CRuleTables, GetDetailedClassString, (
	char Class,
	unsigned int dwKit,
	unsigned int dwFlags,
	IECString& ptr,
	CCreatureObject& cre
	), GetDetailedClassString, GetDetailedClassString, (Class, dwKit, dwFlags, ptr, cre), 0x635238);
DefineLibMemberFunc(int, CRuleTables, GetWeapProfMax, (
	char nClassId,
	char nClassPrimary,
	char nClassSecondary,
	BOOL bTwoClasses,
	int nWeapProfId,
	unsigned int dwKit
	), GetWeapProfMax, GetWeapProfMax, (nClassId, nClassPrimary, nClassSecondary, bTwoClasses, nWeapProfId, dwKit), 0x636C57);
DefineLibMemberFunc(BOOL, CRuleTables, IsMageSchoolAllowed, (unsigned int dwKit, unsigned char nRace), IsMageSchoolAllowed, IsMageSchoolAllowed, (dwKit, nRace), 0x637DEE);
DefineLibMemberFunc(int, CRuleTables, GetIntModMaxSpellsPerLevel, (CDerivedStats& cds), GetIntModMaxSpellsPerLevel, GetIntModMaxSpellsPerLevel, (cds), 0x639B71);
DefineLibMemberFunc(char, CRuleTables, GetMageSchool, (short wKitLow), GetMageSchool, GetMageSchool, (wKitLow), 0x639D4A);
DefineLibMemberFunc(bool, CRuleTables, GetContingencyConditionTexts, (STRREF* pStrref, STRREF* pDescription, short wIndex), GetContingencyConditionTexts, GetContingencyConditionTexts, (pStrref, pDescription, wIndex), 0x639E94);
DefineLibMemberFunc(bool, CRuleTables, GetContingencyTargetTexts, (STRREF* pStrref, STRREF* pDescription, short wIndex), GetContingencyTargetTexts, GetContingencyTargetTexts, (pStrref, pDescription, wIndex), 0x639FD5);
DefineLibMemberFunc(CRuleTable&, CRuleTables, GetClassAbilityTable, (unsigned char cClass, unsigned int dwKit), GetClassAbilityTable, GetClassAbilityTable, (cClass, dwKit), 0x63A81C);
DefineLibMemberFunc(ResRef, CRuleTables, GetMageSpellRefAutoPick, (char nSpellLevel, char nIndex), GetMageSpellRefAutoPick, GetMageSpellRefAutoPick, (nSpellLevel, nIndex), 0x63AD1A);

//CMoveAreasList
DefineLibMemberFunc(void, CMoveAreasList, MoveAllTo, (CArea& area), MoveAllTo, MoveAllTo, (area), 0x5EFA6D);

//CInfGame
DefineLibMemberFunc(void, CInfGame, InitGame, (int nUnused, int nUnused2), InitGame, InitGame, (nUnused, nUnused2), 0x67C6C5);
DefineLibMemberFunc(int, CInfGame, GetNumOfItemInBag, (ResRef& rBag, ResRef& rItem, BOOL bIdentifiedOnly), GetNumOfItemInBag, GetNumOfItemInBag, (rBag, rItem, bIdentifiedOnly), 0x68F35C);
DefineLibMemberFunc(void, CInfGame, DemandServerStore, (ResRef& rName, BOOL bAlsoUpdateTemp), DemandServerStore, DemandServerStore, (rName, bAlsoUpdateTemp), 0x69182E);
DefineLibMemberFunc(void, CInfGame, ReleaseServerStore, (ResRef& rName), ReleaseServerStore, ReleaseServerStore, (rName), 0x691BC0);
DefineLibMemberFunc(short, CInfGame, GetCharacterPortraitNum, (ENUM e), GetCharacterPortraitNum, GetCharacterPortraitNum, (e), 0x69410C);
DefineLibMemberFunc(CArea&, CInfGame, GetLoadedArea, (IECString sAreaName), GetLoadedArea, GetLoadedArea, (sAreaName), 0x69A7D4);
DefineLibMemberFunc(void, CInfGame, AddExperienceParty, (int n), AddExperienceParty, AddExperienceParty, (n), 0x6A97C1);
DefineLibMemberFunc(void, CInfGame, SetLoseCutscene, (), SetLoseCutscene, SetLoseCutscene, (), 0x6AE3E0);
DefineLibMemberFunc(void, CInfGame, StorePartyLocations, (BOOL bUseSecondList), StorePartyLocations, StorePartyLocations, (bUseSecondList), 0x6B7D93);
DefineLibMemberFunc(int, CInfGame, GetNumControlledSummons, (), GetNumControlledSummons, GetNumControlledSummons, (), 0x6B934A);
