#ifndef OBJECTCREATURE_H
#define OBJECTCREATURE_H

#include "objcre.h"

extern CreFileKnownSpell& (CCreatureObject::*Tramp_CCreatureObject_GetKnownSpellPriest)(int, int);
extern CreFileKnownSpell& (CCreatureObject::*Tramp_CCreatureObject_GetKnownSpellMage)(int, int);
extern BOOL (CCreatureObject::*Tramp_CCreatureObject_AddMemSpellPriest)(int, int, int*);
extern BOOL (CCreatureObject::*Tramp_CCreatureObject_AddMemSpellMage)(int, int, int*);
extern void (CCreatureObject::*Tramp_CCreatureObject_ValidateAttackSequence)(char*);

class DETOUR_CCreatureObject : public CCreatureObject {
public:
	CreFileKnownSpell& DETOUR_GetKnownSpellPriest(int nLevel, int nIndex);
	CreFileKnownSpell& DETOUR_GetKnownSpellMage(int nLevel, int nIndex);
	BOOL DETOUR_AddMemSpellPriest(int nLevel , int nIndex, int* pIndex);
	BOOL DETOUR_AddMemSpellMage(int nLevel , int nIndex, int* pIndex);
	void DETOUR_ValidateAttackSequence(char* pSeq);
};

void __stdcall CCreatureObject_PrintExtraCombatInfoText(CCreatureObject& creSelf, IECString& sText);
BOOL __stdcall CCreatureObject_ShouldAvertCriticalHit(CCreatureObject& creTarget);
BOOL CCreatureObject_TryBackstab(CCreatureObject& creSource, CItem& itmMain, ItmFileAbility& abilMain, ItmFileAbility& abilLauncher, short orTarget, short orToTarget, CCreatureObject& creTarget);
BOOL __stdcall CCreatureObject_HasThrowingWeaponEquippedHumanoidOnly(CCreatureObject& cre);
BOOL __stdcall CCreatureObject_IsValidSpellTarget_CheckInvisible(CCreatureObject& creSource, CCreatureObject& creTarget);
BOOL __stdcall CCreatureObject_IsDeadInFrontVerticalList(CCreatureObject& cre);

#endif //OBJECTCREATURE_H