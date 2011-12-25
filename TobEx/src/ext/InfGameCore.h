#ifndef INFGAMECORE_H
#define INFGAMECORE_H

#include "utils.h"
#include "infgame.h"
#include "cstringex.h"
#include "objcre.h"
#include "resref.h"

class DETOUR_CRuleTables : public CRuleTables {
public:
	CRuleTables& DETOUR_Construct();
	ResRef DETOUR_GetMageSpellRef(DWORD, DWORD);
	DWORD DETOUR_GetWeapProfMax(BYTE, BYTE, BYTE, BOOL, DWORD, DWORD);
	ResRef DETOUR_GetMageSpellRefAutoPick(BYTE, BYTE);
};

BOOL __stdcall CRuleTables_HasKnownMageSpells(CCreatureObject&);
ResRef CRuleTables_TryHideSpell(ResRef&);
IECString& __stdcall CRuleTables_GetMaxProfs(CCreatureObject&, IECString&);
STRREF __stdcall CInfGame_GetRaceText(DWORD);

#endif //INFGAMECORE_H