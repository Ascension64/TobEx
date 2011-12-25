#include "infgame.h"

#include "stdafx.h"
#include "resref.h"

//CWorldTimer
void (CWorldTimer::*CWorldTimer_UnpauseGame)() =
	SetFP(static_cast<void (CWorldTimer::*)()>		(&CWorldTimer::UnpauseGame),	0x649F8E);
void (CWorldTimer::*CWorldTimer_PauseGame)() =
	SetFP(static_cast<void (CWorldTimer::*)()>		(&CWorldTimer::PauseGame),		0x64A068);

void CWorldTimer::UnpauseGame()	{ return (this->*CWorldTimer_UnpauseGame)(); }
void CWorldTimer::PauseGame()	{ return (this->*CWorldTimer_PauseGame)(); }

//CPartySelection
Enum (CPartySelection::*CPartySelection_GetFirstSelected)() =
	SetFP(static_cast<Enum (CPartySelection::*)()>	(&CPartySelection::GetFirstSelected),	0x408976);

Enum CPartySelection::GetFirstSelected() { return (this->*CPartySelection_GetFirstSelected)(); }

//CRuleTable
CRuleTable& (CRuleTable::*CRuleTable_Construct)() =
	SetFP(static_cast<CRuleTable& (CRuleTable::*)()>						(&CRuleTable::Construct),	0x63E230);
void (CRuleTable::*CRuleTable_LoadRes)(ResRef&) =
	SetFP(static_cast<void (CRuleTable::*)(ResRef&)>						(&CRuleTable::LoadTable),	0x402D85);
IECString& (CRuleTable::*CRuleTable_GetValue_2)(IECString&, IECString&) =
	SetFP(static_cast<IECString& (CRuleTable::*)(IECString&, IECString&)>	(&CRuleTable::GetValue),	0x4047EF);
extern bool (CRuleTable::*CRuleTable_FindString)(IECString&, POSITION*, BOOL) =
	SetFP(static_cast<bool (CRuleTable::*)(IECString&, POSITION*, BOOL)>	(&CRuleTable::FindString),	0x404D61);
void (CRuleTable::*CRuleTable_UnloadRes)() =
	SetFP(static_cast<void (CRuleTable::*)()>								(&CRuleTable::UnloadRes),	0x43C010);
extern IECString& (CRuleTable::*CRuleTable_GetValue_1)(POINT&) =
	SetFP(static_cast<IECString& (CRuleTable::*)(POINT&)>					(&CRuleTable::GetValue),	0x63E2B0);

CRuleTable::CRuleTable() { (this->*CRuleTable_Construct)(); nRows = 0; nCols = 0; }
void CRuleTable::LoadTable(ResRef& r) { return (this->*CRuleTable_LoadRes)(r); }
IECString& CRuleTable::GetValue(IECString& sColName, IECString& sRowName) { return (this->*CRuleTable_GetValue_2)(sColName, sRowName); }
bool CRuleTable::FindString(IECString& s, POSITION* ppos, BOOL bCheckHeaders) { return (this->*CRuleTable_FindString)(s, ppos, bCheckHeaders); }
void CRuleTable::UnloadRes() { return (this->*CRuleTable_UnloadRes)(); }
IECString& CRuleTable::GetValue(POINT& ptColRow) { return (this->*CRuleTable_GetValue_1)(ptColRow); }

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
CRuleTables& (CRuleTables::*CRuleTables_Construct)() =
	SetFP(static_cast<CRuleTables& (CRuleTables::*)()>										(&CRuleTables::Construct),						0x6213DC);
void (CRuleTables::*CRuleTables_Deconstruct)() =
	SetFP(static_cast<void (CRuleTables::*)()>												(&CRuleTables::Deconstruct),					0x6279D1);
IECString (CRuleTables::*CRuleTables_GetRaceString)(unsigned char) =
	SetFP(static_cast<IECString (CRuleTables::*)(unsigned char)>							(&CRuleTables::GetRaceString),					0x62ACC5);
IECString (CRuleTables::*CRuleTables_GetAlignmentString)(char) =
	SetFP(static_cast<IECString (CRuleTables::*)(char)>										(&CRuleTables::GetAlignmentString),				0x62AEA4);
IECString (CRuleTables::*CRuleTables_GetClassString)(unsigned char, unsigned int) =
	SetFP(static_cast<IECString (CRuleTables::*)(unsigned char, unsigned int)>				(&CRuleTables::GetClassString),					0x62B072);
int (CRuleTables::*CRuleTables_CalculateNewHPRule)(CRuleTable&, int, int, int, int, BOOL, int, BOOL, int) =
	SetFP(static_cast<int (CRuleTables::*)(CRuleTable&, int, int, int, int, BOOL, int, BOOL, int)>
																							(&CRuleTables::CalculateNewHPRule),				0x630ED4);
int (CRuleTables::*CRuleTables_CalculateNewHPSubclass)(char, char, CDerivedStats&, CDerivedStats&, int, int) =
	SetFP(static_cast<int (CRuleTables::*)(char, char, CDerivedStats&, CDerivedStats&, int, int)>
																							(&CRuleTables::CalculateNewHPSubclass),			0x631055);
ResRef (CRuleTables::*CRuleTables_GetMageSpellRef)(int, int) =
	SetFP(static_cast<ResRef (CRuleTables::*)(int, int)>									(&CRuleTables::GetMageSpellRef),				0x633691);
STRREF (CRuleTables::*CRuleTables_GetCharSndStrRef)(int, int, char) =
	SetFP(static_cast<STRREF (CRuleTables::*)(int, int, char)>								(&CRuleTables::GetCharSndStrRef),				0x63511C);
void (CRuleTables::*CRuleTables_GetDetailedClassString)(char, unsigned int, unsigned int, IECString&, CCreatureObject&) =
	SetFP(static_cast<void (CRuleTables::*)(char, unsigned int, unsigned int, IECString&, CCreatureObject&)>
																							(&CRuleTables::GetDetailedClassString),			0x635238);
int (CRuleTables::*CRuleTables_GetWeapProfMax)(char, char, char, BOOL, int, unsigned int) =
	SetFP(static_cast<int (CRuleTables::*)(char, char, char, BOOL, int, unsigned int)>		(&CRuleTables::GetWeapProfMax),					0x636C57);
BOOL (CRuleTables::*CRuleTables_IsMageSchoolAllowed)(unsigned int, unsigned char) =
	SetFP(static_cast<BOOL (CRuleTables::*)(unsigned int, unsigned char)>					(&CRuleTables::IsMageSchoolAllowed),			0x637DEE);
int (CRuleTables::*CRuleTables_GetIntModMaxSpellsPerLevel)(CDerivedStats&) =
	SetFP(static_cast<int (CRuleTables::*)(CDerivedStats&)>									(&CRuleTables::GetIntModMaxSpellsPerLevel),		0x639B71);
char (CRuleTables::*CRuleTables_GetMageSchool)(short) =
	SetFP(static_cast<char (CRuleTables::*)(short)>											(&CRuleTables::GetMageSchool),					0x639D4A);
bool (CRuleTables::*CRuleTables_GetContingencyConditionTexts)(STRREF*, STRREF*, short) =
	SetFP(static_cast<bool (CRuleTables::*)(STRREF*, STRREF*, short)>						(&CRuleTables::GetContingencyConditionTexts),	0x639E94);
bool (CRuleTables::*CRuleTables_GetContingencyTargetTexts)(STRREF*, STRREF*, short) =
	SetFP(static_cast<bool (CRuleTables::*)(STRREF*, STRREF*, short)>						(&CRuleTables::GetContingencyTargetTexts),		0x639FD5);
ResRef (CRuleTables::*CRuleTables_GetMageSpellRefAutoPick)(char, char) =
	SetFP(static_cast<ResRef (CRuleTables::*)(char, char)>									(&CRuleTables::GetMageSpellRefAutoPick),		0x63AD1A);

CRuleTables::CRuleTables() { (this->*CRuleTables_Construct)(); }
CRuleTables::~CRuleTables() { (this->*CRuleTables_Deconstruct)(); }
IECString CRuleTables::GetRaceString(unsigned char nRace) { return (this->*CRuleTables_GetRaceString)(nRace); }
IECString CRuleTables::GetAlignmentString(char align) { return (this->*CRuleTables_GetAlignmentString)(align); }
IECString CRuleTables::GetClassString(unsigned char nClass, unsigned int dwKit) { return (this->*CRuleTables_GetClassString)(nClass, dwKit); }
int CRuleTables::CalculateNewHPRule(CRuleTable& rule, int nLevelOld, int nLevelNew, int nMinRoll, int nDivisor, BOOL bOverrideSides, int nOverrideSides, BOOL bOverrideModifier, int nOverrideModifier)
	{ return (this->*CRuleTables_CalculateNewHPRule)(rule, nLevelOld, nLevelNew, nMinRoll, nDivisor, bOverrideSides, nOverrideSides, bOverrideModifier, nOverrideModifier); }
int CRuleTables::CalculateNewHPSubclass(char nClass, char nSubclass, CDerivedStats& cdsOld, CDerivedStats& cdsNew, int nMinRoll, int nDivisor)
	{ return (this->*CRuleTables_CalculateNewHPSubclass)(nClass, nSubclass, cdsOld, cdsNew, nMinRoll, nDivisor); }
ResRef CRuleTables::GetMageSpellRef(int nSpellLevel, int nIndex) { return (this->*CRuleTables_GetMageSpellRef)(nSpellLevel, nIndex); }
STRREF CRuleTables::GetCharSndStrRef(int dwCustom, int dwRow, char sex) { return (this->*CRuleTables_GetCharSndStrRef)(dwCustom, dwRow, sex); }
void CRuleTables::GetDetailedClassString(char Class, unsigned int dwKit, unsigned int dwFlags, IECString& ptr, CCreatureObject& cre)
	{ return (this->*CRuleTables_GetDetailedClassString)(Class, dwKit, dwFlags, ptr, cre); }
int CRuleTables::GetWeapProfMax(char nClassId, char nClassPrimary, char nClassSecondary, BOOL bTwoClasses, int nWeapProfId, unsigned int dwKit)
	{ return (this->*CRuleTables_GetWeapProfMax)(nClassId, nClassPrimary, nClassSecondary, bTwoClasses, nWeapProfId, dwKit); }
BOOL CRuleTables::IsMageSchoolAllowed(unsigned int dwKit, unsigned char nRace) { return (this->*CRuleTables_IsMageSchoolAllowed)(dwKit, nRace); }
int CRuleTables::GetIntModMaxSpellsPerLevel(CDerivedStats& cds) { return (this->*CRuleTables_GetIntModMaxSpellsPerLevel)(cds); }
char CRuleTables::GetMageSchool(short wKitLow) { return (this->*CRuleTables_GetMageSchool)(wKitLow); }
bool CRuleTables::GetContingencyConditionTexts(STRREF* pStrref, STRREF* pDescription, short wIndex) { return (this->*CRuleTables_GetContingencyConditionTexts)(pStrref, pDescription, wIndex); }
bool CRuleTables::GetContingencyTargetTexts(STRREF* pStrref, STRREF* pDescription, short wIndex) { return (this->*CRuleTables_GetContingencyTargetTexts)(pStrref, pDescription, wIndex); }
ResRef CRuleTables::GetMageSpellRefAutoPick(char nSpellLevel, char nIndex) { return (this->*CRuleTables_GetMageSpellRefAutoPick)(nSpellLevel, nIndex); }

//CInfGame
int (CInfGame::*CInfGame_GetNumOfItemInBag)(ResRef&, ResRef&, BOOL) =
	SetFP(static_cast<int (CInfGame::*)(ResRef&, ResRef&, BOOL)>	(&CInfGame::GetNumOfItemInBag),		0x68F35C);
void (CInfGame::*CInfGame_DemandServerStore)(ResRef&, BOOL) =
	SetFP(static_cast<void (CInfGame::*)(ResRef&, BOOL)>			(&CInfGame::DemandServerStore),		0x69182E);
void (CInfGame::*CInfGame_ReleaseServerStore)(ResRef&) =
	SetFP(static_cast<void (CInfGame::*)(ResRef&)>					(&CInfGame::ReleaseServerStore),	0x691BC0);
short (CInfGame::*CInfGame_GetPartyMemberSlot)(Enum) =
	SetFP(static_cast<short (CInfGame::*)(Enum)>					(&CInfGame::GetPartyMemberSlot),	0x69410C);
CArea& (CInfGame::*CInfGame_GetLoadedArea)(IECString) =
	SetFP(static_cast<CArea& (CInfGame::*)(IECString)>				(&CInfGame::GetLoadedArea),			0x69A7D4);
void (CInfGame::*CInfGame_AddExperienceParty)(int) =
	SetFP(static_cast<void (CInfGame::*)(int)>						(&CInfGame::AddExperienceParty),	0x6A97C1);
void (CInfGame::*CInfGame_SetLoseCutscene)() =
	SetFP(static_cast<void (CInfGame::*)()>							(&CInfGame::SetLoseCutscene),		0x6AE3E0);
void (CInfGame::*CInfGame_StorePartyLocations)(BOOL) =
	SetFP(static_cast<void (CInfGame::*)(BOOL)>						(&CInfGame::StorePartyLocations),	0x6B7D93);

int CInfGame::GetNumOfItemInBag(ResRef& rBag, ResRef& rItem, BOOL bIdentifiedOnly)
	{ return (this->*CInfGame_GetNumOfItemInBag)(rBag, rItem, bIdentifiedOnly); }
void CInfGame::DemandServerStore(ResRef& rName, BOOL bAlsoUpdateTemp)	{ return (this->*CInfGame_DemandServerStore)(rName, bAlsoUpdateTemp); }
void CInfGame::ReleaseServerStore(ResRef& rName)						{ return (this->*CInfGame_ReleaseServerStore)(rName); }
short CInfGame::GetPartyMemberSlot(Enum e)								{ return (this->*CInfGame_GetPartyMemberSlot)(e); }
CArea& CInfGame::GetLoadedArea(IECString sAreaName)						{ return (this->*CInfGame_GetLoadedArea)(sAreaName); }
void CInfGame::AddExperienceParty(int n)								{ return (this->*CInfGame_AddExperienceParty)(n); }
void CInfGame::SetLoseCutscene()										{ return (this->*CInfGame_SetLoseCutscene)(); }
void CInfGame::StorePartyLocations(BOOL bUseSecondList)					{ return (this->*CInfGame_StorePartyLocations)(bUseSecondList); }