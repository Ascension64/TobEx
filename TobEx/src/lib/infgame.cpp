#include "infgame.h"

#include "utils.h"
#include "resref.h"

//Res2daContainer
void (Res2daContainer::*Res2daContainer_LoadRes)(ResRef&) =
	SetFP(static_cast<void (Res2daContainer::*)(ResRef&)>						(&Res2daContainer::LoadRes),	0x402D85);
IECString& (Res2daContainer::*Res2daContainer_GetValue)(IECString&, IECString&) =
	SetFP(static_cast<IECString& (Res2daContainer::*)(IECString&, IECString&)>	(&Res2daContainer::GetValue),	0x4047EF);

void Res2daContainer::LoadRes(ResRef& r) { return (this->*Res2daContainer_LoadRes)(r); }
IECString& Res2daContainer::GetValue(IECString& sColName, IECString& sRowName) { return (this->*Res2daContainer_GetValue)(sColName, sRowName); }

//CRuleTable
CRuleTable& (CRuleTable::*CRuleTable_Construct)(void) =
	SetFP(static_cast<CRuleTable& (CRuleTable::*)(void)>						(&CRuleTable::Construct),	0x63E230);

CRuleTable::CRuleTable() { (this->*CRuleTable_Construct)(); }

//CRuleTables
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
ResRef (CRuleTables::*CRuleTables_GetMageSpellRefAutoPick)(BYTE, BYTE) =
	SetFP(static_cast<ResRef (CRuleTables::*)(BYTE, BYTE)>										(&CRuleTables::GetMageSpellRefAutoPick),	0x63AD1A);

IECString CRuleTables::GetRaceString(BYTE race) { return (this->*CRuleTables_GetRaceString)(race); }
IECString CRuleTables::GetAlignmentString(BYTE align) { return (this->*CRuleTables_GetAlignmentString)(align); }
IECString CRuleTables::GetClassString(BYTE Class, DWORD dwKit) { return (this->*CRuleTables_GetClassString)(Class, dwKit); }
ResRef CRuleTables::GetMageSpellRef(DWORD nSpellLevel, DWORD nIndex) { return (this->*CRuleTables_GetMageSpellRef)(nSpellLevel, nIndex); }
STRREF CRuleTables::GetCharSndStrRef(DWORD dwCustom, DWORD dwRow, BYTE sex) { return (this->*CRuleTables_GetCharSndStrRef)(dwCustom, dwRow, sex); }
void CRuleTables::GetDetailedClassString(BYTE Class, DWORD dwKit, DWORD dwFlags, IECString& ptr, CCreatureObject& cre)
	{ return (this->*CRuleTables_GetDetailedClassString)(Class, dwKit, dwFlags, ptr, cre); }
DWORD CRuleTables::GetWeapProfMax(BYTE dwClassId, BYTE bClassPrimary, BYTE bClassSecondary, BOOL bClassMage, DWORD dwWeapProfId, DWORD dwKit)
	{ return (this->*CRuleTables_GetWeapProfMax)(dwClassId, bClassPrimary, bClassSecondary, bClassMage, dwWeapProfId, dwKit); }
ResRef CRuleTables::GetMageSpellRefAutoPick(BYTE nSpellLevel, BYTE nIndex) { return (this->*CRuleTables_GetMageSpellRefAutoPick)(nSpellLevel, nIndex); }

//CInfGame
void (CInfGame::*CInfGame_StorePartyLocations)(BOOL) =
	SetFP(static_cast<void (CInfGame::*)(BOOL)>				(&CInfGame::StorePartyLocations),	0x6B7D93);

void CInfGame::StorePartyLocations(BOOL bUseSecondList) { return (this->*CInfGame_StorePartyLocations)(bUseSecondList); }