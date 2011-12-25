#include "infgame.h"

#include "stdafx.h"
#include "resref.h"

//CRuleTable
CRuleTable& (CRuleTable::*CRuleTable_Construct)() =
	SetFP(static_cast<CRuleTable& (CRuleTable::*)()>						(&CRuleTable::Construct),	0x63E230);
void (CRuleTable::*CRuleTable_LoadRes)(ResRef&) =
	SetFP(static_cast<void (CRuleTable::*)(ResRef&)>						(&CRuleTable::LoadTable),	0x402D85);
IECString& (CRuleTable::*CRuleTable_GetValue)(IECString&, IECString&) =
	SetFP(static_cast<IECString& (CRuleTable::*)(IECString&, IECString&)>	(&CRuleTable::GetValue),	0x4047EF);
extern bool (CRuleTable::*CRuleTable_FindString)(IECString&, POSITION*, BOOL) =
	SetFP(static_cast<bool (CRuleTable::*)(IECString&, POSITION*, BOOL)>	(&CRuleTable::FindString),	0x404D61);
void (CRuleTable::*CRuleTable_UnloadRes)() =
	SetFP(static_cast<void (CRuleTable::*)()>								(&CRuleTable::UnloadRes),	0x43C010);

CRuleTable::CRuleTable() { (this->*CRuleTable_Construct)(); nRows = 0; nCols = 0; }
void CRuleTable::LoadTable(ResRef& r) { return (this->*CRuleTable_LoadRes)(r); }
IECString& CRuleTable::GetValue(IECString& sColName, IECString& sRowName) { return (this->*CRuleTable_GetValue)(sColName, sRowName); }
bool CRuleTable::FindString(IECString& s, POSITION* ppos, BOOL bCheckHeaders) { return (this->*CRuleTable_FindString)(s, ppos, bCheckHeaders); }
void CRuleTable::UnloadRes() { return (this->*CRuleTable_UnloadRes)(); }
CRuleTable::~CRuleTable() { //as 0x43C420 except for ~CString()
	if (pColHeaderArray) delete[] pColHeaderArray;
	if (pRowHeaderArray) delete[] pRowHeaderArray;
	if (pDataArray) delete[] pDataArray;
	UnloadRes();
	//CString defaultVal is automatically removed
}

//CRuleTables
CRuleTables& (CRuleTables::*CRuleTables_Construct)() =
	SetFP(static_cast<CRuleTables& (CRuleTables::*)()>										(&CRuleTables::Construct),					0x6213DC);
void (CRuleTables::*CRuleTables_Deconstruct)() =
	SetFP(static_cast<void (CRuleTables::*)()>												(&CRuleTables::Deconstruct),				0x6279D1);
IECString (CRuleTables::*CRuleTables_GetRaceString)(unsigned char) =
	SetFP(static_cast<IECString (CRuleTables::*)(unsigned char)>							(&CRuleTables::GetRaceString),				0x62ACC5);
IECString (CRuleTables::*CRuleTables_GetAlignmentString)(char) =
	SetFP(static_cast<IECString (CRuleTables::*)(char)>										(&CRuleTables::GetAlignmentString),			0x62AEA4);
IECString (CRuleTables::*CRuleTables_GetClassString)(unsigned char, unsigned int) =
	SetFP(static_cast<IECString (CRuleTables::*)(unsigned char, unsigned int)>				(&CRuleTables::GetClassString),				0x62B072);
ResRef (CRuleTables::*CRuleTables_GetMageSpellRef)(int, int) =
	SetFP(static_cast<ResRef (CRuleTables::*)(int, int)>									(&CRuleTables::GetMageSpellRef),			0x633691);
STRREF (CRuleTables::*CRuleTables_GetCharSndStrRef)(int, int, char) =
	SetFP(static_cast<STRREF (CRuleTables::*)(int, int, char)>								(&CRuleTables::GetCharSndStrRef),			0x63511C);
void (CRuleTables::*CRuleTables_GetDetailedClassString)(char, unsigned int, unsigned int, IECString&, CCreatureObject&) =
	SetFP(static_cast<void (CRuleTables::*)(char, unsigned int, unsigned int, IECString&, CCreatureObject&)>
																							(&CRuleTables::GetDetailedClassString),		0x635238);
int (CRuleTables::*CRuleTables_GetWeapProfMax)(char, char, char, BOOL, int, unsigned int) =
	SetFP(static_cast<int (CRuleTables::*)(char, char, char, BOOL, int, unsigned int)>		(&CRuleTables::GetWeapProfMax),				0x636C57);
BOOL (CRuleTables::*CRuleTables_IsMageSchoolAllowed)(unsigned int, unsigned char) =
	SetFP(static_cast<BOOL (CRuleTables::*)(unsigned int, unsigned char)>					(&CRuleTables::IsMageSchoolAllowed),		0x637DEE);
ResRef (CRuleTables::*CRuleTables_GetMageSpellRefAutoPick)(char, char) =
	SetFP(static_cast<ResRef (CRuleTables::*)(char, char)>									(&CRuleTables::GetMageSpellRefAutoPick),	0x63AD1A);

CRuleTables::CRuleTables() { (this->*CRuleTables_Construct)(); }
CRuleTables::~CRuleTables() { (this->*CRuleTables_Deconstruct)(); }
IECString CRuleTables::GetRaceString(unsigned char nRace) { return (this->*CRuleTables_GetRaceString)(nRace); }
IECString CRuleTables::GetAlignmentString(char align) { return (this->*CRuleTables_GetAlignmentString)(align); }
IECString CRuleTables::GetClassString(unsigned char nClass, unsigned int dwKit) { return (this->*CRuleTables_GetClassString)(nClass, dwKit); }
ResRef CRuleTables::GetMageSpellRef(int nSpellLevel, int nIndex) { return (this->*CRuleTables_GetMageSpellRef)(nSpellLevel, nIndex); }
STRREF CRuleTables::GetCharSndStrRef(int dwCustom, int dwRow, char sex) { return (this->*CRuleTables_GetCharSndStrRef)(dwCustom, dwRow, sex); }
void CRuleTables::GetDetailedClassString(char Class, unsigned int dwKit, unsigned int dwFlags, IECString& ptr, CCreatureObject& cre)
	{ return (this->*CRuleTables_GetDetailedClassString)(Class, dwKit, dwFlags, ptr, cre); }
int CRuleTables::GetWeapProfMax(char dwClassId, char bClassPrimary, char bClassSecondary, BOOL bClassMage, int dwWeapProfId, unsigned int dwKit)
	{ return (this->*CRuleTables_GetWeapProfMax)(dwClassId, bClassPrimary, bClassSecondary, bClassMage, dwWeapProfId, dwKit); }
BOOL CRuleTables::IsMageSchoolAllowed(unsigned int dwKit, unsigned char nRace) { return (this->*CRuleTables_IsMageSchoolAllowed)(dwKit, nRace); }
ResRef CRuleTables::GetMageSpellRefAutoPick(char nSpellLevel, char nIndex) { return (this->*CRuleTables_GetMageSpellRefAutoPick)(nSpellLevel, nIndex); }

//CInfGame
CArea& (CInfGame::*CInfGame_GetLoadedArea)(IECString) =
	SetFP(static_cast<CArea& (CInfGame::*)(IECString)>		(&CInfGame::GetLoadedArea),			0x69A7D4);
void (CInfGame::*CInfGame_StorePartyLocations)(BOOL) =
	SetFP(static_cast<void (CInfGame::*)(BOOL)>				(&CInfGame::StorePartyLocations),	0x6B7D93);

CArea& CInfGame::GetLoadedArea(IECString sAreaName)		{ return (this->*CInfGame_GetLoadedArea)(sAreaName); }
void CInfGame::StorePartyLocations(BOOL bUseSecondList)	{ return (this->*CInfGame_StorePartyLocations)(bUseSecondList); }