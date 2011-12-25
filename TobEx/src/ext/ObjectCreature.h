#ifndef OBJECTCREATURE_H
#define OBJECTCREATURE_H

#include "objcre.h"

class DETOUR_CCreatureObject : public CCreatureObject {
public:
	CreFileKnownSpell& DETOUR_GetKnownSpellPriest(DWORD, DWORD);
	CreFileKnownSpell& DETOUR_GetKnownSpellMage(DWORD, DWORD);
	BOOL DETOUR_AddMemSpellPriest(DWORD, DWORD, DWORD*);
	BOOL DETOUR_AddMemSpellMage(DWORD, DWORD, DWORD*);
};

#endif //OBJECTCREATURE_H