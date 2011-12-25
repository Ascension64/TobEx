#ifndef OBJECTCREATURE_H
#define OBJECTCREATURE_H

#include "objcre.h"

extern CreFileKnownSpell& (CCreatureObject::*Tramp_CCreatureObject_GetKnownSpellPriest)(DWORD, DWORD);
extern CreFileKnownSpell& (CCreatureObject::*Tramp_CCreatureObject_GetKnownSpellMage)(DWORD, DWORD);
extern BOOL (CCreatureObject::*Tramp_CCreatureObject_AddMemSpellPriest)(DWORD, DWORD, DWORD*);
extern BOOL (CCreatureObject::*Tramp_CCreatureObject_AddMemSpellMage)(DWORD, DWORD, DWORD*);

class DETOUR_CCreatureObject : public CCreatureObject {
public:
	CreFileKnownSpell& DETOUR_GetKnownSpellPriest(DWORD, DWORD);
	CreFileKnownSpell& DETOUR_GetKnownSpellMage(DWORD, DWORD);
	BOOL DETOUR_AddMemSpellPriest(DWORD, DWORD, DWORD*);
	BOOL DETOUR_AddMemSpellMage(DWORD, DWORD, DWORD*);
};

#endif //OBJECTCREATURE_H