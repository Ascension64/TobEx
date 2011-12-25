#ifndef INFGAMECORE_H
#define INFGAMECORE_H

#include "stdafx.h"
#include "infgame.h"
#include "cstringex.h"
#include "objcre.h"
#include "resref.h"

extern CRuleTables& (CRuleTables::*Tramp_CRuleTables_Construct)();
extern void (CRuleTables::*Tramp_CRuleTables_Deconstruct)();
extern int (CRuleTables::*Tramp_CRuleTables_CalculateNewHPSubclass)(char, char, CDerivedStats&, CDerivedStats&, int, int);
extern ResRef (CRuleTables::*Tramp_CRuleTables_GetMageSpellRef)(int, int);
extern int (CRuleTables::*Tramp_CRuleTables_GetWeapProfMax)(char, char, char, BOOL, int, unsigned int);
extern BOOL (CRuleTables::*Tramp_CRuleTables_IsMageSchoolAllowed)(unsigned int, unsigned char);
extern ResRef (CRuleTables::*Tramp_CRuleTables_GetMageSpellRefAutoPick)(char, char);

class DETOUR_CRuleTables : public CRuleTables {
public:
	CRuleTables& DETOUR_Construct();
	void DETOUR_Deconstruct();
	int DETOUR_CalculateNewHPSubclass(char nClass, char nSubclass, CDerivedStats& cdsOld, CDerivedStats& cdsNew, int nMinRoll, int nDivisor);
	ResRef DETOUR_GetMageSpellRef(int nSpellLevel, int nIndex);
	int DETOUR_GetWeapProfMax(char dwClassId, char bClassPrimary, char bClassSecondary, BOOL bClassMage, int dwWeapProfId, unsigned int dwKit);
	BOOL DETOUR_IsMageSchoolAllowed(unsigned int dwKit, unsigned char nRace);
	ResRef DETOUR_GetMageSpellRefAutoPick(char nSpellLevel, char nIndex);
};

BOOL __stdcall CRuleTables_HasKnownMageSpells(CCreatureObject& cre);
ResRef CRuleTables_TryHideSpell(ResRef& rSpell);
IECString& __stdcall CRuleTables_GetMaxProfs(CCreatureObject& cre, IECString& sRowName);
STRREF __stdcall CInfGame_GetRaceText(unsigned int nRace);
BOOL __stdcall CRuleTables_DoesEquipSlotPassCreExclude(CCreatureObject& cre, short wSlot, CItem& itmGrabbed, STRREF* pStrRef);
BOOL __stdcall CRuleTables_DoesInvSlotPassCreExclude(CCreatureObject& cre, short wSlot, CItem& itmGrabbed, STRREF* pStrRef);
BOOL __stdcall CRuleTables_IsLowEncumbrance(unsigned int nWeight, unsigned int nWeightAllowance);
BOOL __stdcall CRuleTables_IsHighEncumbrance(unsigned int nWeight, unsigned int nWeightAllowance);

#endif //INFGAMECORE_H