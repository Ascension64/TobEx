#ifndef INFGAMECORE_H
#define INFGAMECORE_H

#include "utils.h"
#include "infgame.h"
#include "cstringex.h"
#include "objcre.h"
#include "resref.h"

extern CRuleTables& (CRuleTables::*Tramp_CRuleTables_Construct)();
extern void (CRuleTables::*Tramp_CRuleTables_Deconstruct)();
extern ResRef (CRuleTables::*Tramp_CRuleTables_GetMageSpellRef)(DWORD, DWORD);
extern DWORD (CRuleTables::*Tramp_CRuleTables_GetWeapProfMax)(BYTE, BYTE, BYTE, BOOL, DWORD, DWORD);
extern BOOL (CRuleTables::*Tramp_CRuleTables_IsMageSchoolAllowed)(DWORD, BYTE);
extern ResRef (CRuleTables::*Tramp_CRuleTables_GetMageSpellRefAutoPick)(BYTE, BYTE);

class DETOUR_CRuleTables : public CRuleTables {
public:
	CRuleTables& DETOUR_Construct();
	void DETOUR_Deconstruct();
	ResRef DETOUR_GetMageSpellRef(DWORD, DWORD);
	DWORD DETOUR_GetWeapProfMax(BYTE, BYTE, BYTE, BOOL, DWORD, DWORD);
	BOOL DETOUR_IsMageSchoolAllowed(DWORD, BYTE);
	ResRef DETOUR_GetMageSpellRefAutoPick(BYTE, BYTE);
};

BOOL __stdcall CRuleTables_HasKnownMageSpells(CCreatureObject&);
ResRef CRuleTables_TryHideSpell(ResRef&);
IECString& __stdcall CRuleTables_GetMaxProfs(CCreatureObject&, IECString&);
STRREF __stdcall CInfGame_GetRaceText(DWORD);

#endif //INFGAMECORE_H