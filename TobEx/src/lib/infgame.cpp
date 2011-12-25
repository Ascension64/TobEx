#include "infgame.h"

#include "utils.h"
#include "resref.h"

//CRuleTable
CRuleTable& (CRuleTable::*CRuleTable_Construct)(void) =
	SetFP(static_cast<CRuleTable& (CRuleTable::*)(void)>					(&CRuleTable::Construct),	0x63E230);
void (CRuleTable::*CRuleTable_LoadRes)(ResRef&) =
	SetFP(static_cast<void (CRuleTable::*)(ResRef&)>						(&CRuleTable::LoadTable),	0x402D85);
IECString& (CRuleTable::*CRuleTable_GetValue)(IECString&, IECString&) =
	SetFP(static_cast<IECString& (CRuleTable::*)(IECString&, IECString&)>	(&CRuleTable::GetValue),	0x4047EF);
void (CRuleTable::*CRuleTable_UnloadRes)() =
	SetFP(static_cast<void (CRuleTable::*)()>								(&CRuleTable::UnloadRes),	0x43C010);

CRuleTable::CRuleTable() { (this->*CRuleTable_Construct)(); nRows = 0; nCols = 0; }
void CRuleTable::LoadTable(ResRef& r) { return (this->*CRuleTable_LoadRes)(r); }
IECString& CRuleTable::GetValue(IECString& sColName, IECString& sRowName) { return (this->*CRuleTable_GetValue)(sColName, sRowName); }
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
	SetFP(static_cast<CRuleTables& (CRuleTables::*)()>											(&CRuleTables::Construct),					0x6213DC);
void (CRuleTables::*CRuleTables_Deconstruct)() =
	SetFP(static_cast<void (CRuleTables::*)()>													(&CRuleTables::Deconstruct),				0x6279D1);
IECString (CRuleTables::*CRuleTables_GetRaceString)(BYTE) =
	SetFP(static_cast<IECString (CRuleTables::*)(BYTE)>											(&CRuleTables::GetRaceString),				0x62ACC5);
IECString (CRuleTables::*CRuleTables_GetAlignmentString)(BYTE) =
	SetFP(static_cast<IECString (CRuleTables::*)(BYTE)>											(&CRuleTables::GetAlignmentString),			0x62AEA4);
IECString (CRuleTables::*CRuleTables_GetClassString)(BYTE, DWORD) =
	SetFP(static_cast<IECString (CRuleTables::*)(BYTE, DWORD)>									(&CRuleTables::GetClassString),				0x62B072);
ResRef (CRuleTables::*CRuleTables_GetMageSpellRef)(DWORD, DWORD) =
	SetFP(static_cast<ResRef (CRuleTables::*)(DWORD, DWORD)>									(&CRuleTables::GetMageSpellRef),			0x633691);
STRREF (CRuleTables::*CRuleTables_GetCharSndStrRef)(DWORD, DWORD, BYTE) =
	SetFP(static_cast<STRREF (CRuleTables::*)(DWORD, DWORD, BYTE)>								(&CRuleTables::GetCharSndStrRef),			0x63511C);
void (CRuleTables::*CRuleTables_GetDetailedClassString)(BYTE, DWORD, DWORD, IECString&, CCreatureObject&) =
	SetFP(static_cast<void (CRuleTables::*)(BYTE, DWORD, DWORD, IECString&, CCreatureObject&)>	(&CRuleTables::GetDetailedClassString),		0x635238);
DWORD (CRuleTables::*CRuleTables_GetWeapProfMax)(BYTE, BYTE, BYTE, BOOL, DWORD, DWORD) =
	SetFP(static_cast<DWORD (CRuleTables::*)(BYTE, BYTE, BYTE, BOOL, DWORD, DWORD)>				(&CRuleTables::GetWeapProfMax),				0x636C57);
BOOL (CRuleTables::*CRuleTables_IsMageSchoolAllowed)(DWORD, BYTE) =
	SetFP(static_cast<BOOL (CRuleTables::*)(DWORD, BYTE)>										(&CRuleTables::IsMageSchoolAllowed),		0x637DEE);
ResRef (CRuleTables::*CRuleTables_GetMageSpellRefAutoPick)(BYTE, BYTE) =
	SetFP(static_cast<ResRef (CRuleTables::*)(BYTE, BYTE)>										(&CRuleTables::GetMageSpellRefAutoPick),	0x63AD1A);

CRuleTables::CRuleTables() { (this->*CRuleTables_Construct)(); }
CRuleTables::~CRuleTables() { (this->*CRuleTables_Deconstruct)(); }
IECString CRuleTables::GetRaceString(BYTE race) { return (this->*CRuleTables_GetRaceString)(race); }
IECString CRuleTables::GetAlignmentString(BYTE align) { return (this->*CRuleTables_GetAlignmentString)(align); }
IECString CRuleTables::GetClassString(BYTE Class, DWORD dwKit) { return (this->*CRuleTables_GetClassString)(Class, dwKit); }
ResRef CRuleTables::GetMageSpellRef(DWORD nSpellLevel, DWORD nIndex) { return (this->*CRuleTables_GetMageSpellRef)(nSpellLevel, nIndex); }
STRREF CRuleTables::GetCharSndStrRef(DWORD dwCustom, DWORD dwRow, BYTE sex) { return (this->*CRuleTables_GetCharSndStrRef)(dwCustom, dwRow, sex); }
void CRuleTables::GetDetailedClassString(BYTE Class, DWORD dwKit, DWORD dwFlags, IECString& ptr, CCreatureObject& cre)
	{ return (this->*CRuleTables_GetDetailedClassString)(Class, dwKit, dwFlags, ptr, cre); }
DWORD CRuleTables::GetWeapProfMax(BYTE dwClassId, BYTE bClassPrimary, BYTE bClassSecondary, BOOL bClassMage, DWORD dwWeapProfId, DWORD dwKit)
	{ return (this->*CRuleTables_GetWeapProfMax)(dwClassId, bClassPrimary, bClassSecondary, bClassMage, dwWeapProfId, dwKit); }
BOOL CRuleTables::IsMageSchoolAllowed(DWORD dwKit, BYTE race) { return (this->*CRuleTables_IsMageSchoolAllowed)(dwKit, race); }
ResRef CRuleTables::GetMageSpellRefAutoPick(BYTE nSpellLevel, BYTE nIndex) { return (this->*CRuleTables_GetMageSpellRefAutoPick)(nSpellLevel, nIndex); }

//CInfGame
void (CInfGame::*CInfGame_StorePartyLocations)(BOOL) =
	SetFP(static_cast<void (CInfGame::*)(BOOL)>				(&CInfGame::StorePartyLocations),	0x6B7D93);

void CInfGame::StorePartyLocations(BOOL bUseSecondList) { return (this->*CInfGame_StorePartyLocations)(bUseSecondList); }