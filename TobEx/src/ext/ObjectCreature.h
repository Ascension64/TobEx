#ifndef OBJECTCREATURE_H
#define OBJECTCREATURE_H

#include "objcre.h"

extern CreFileKnownSpell& (CCreatureObject::*Tramp_CCreatureObject_GetKnownSpellPriest)(int, int);
extern CreFileKnownSpell& (CCreatureObject::*Tramp_CCreatureObject_GetKnownSpellMage)(int, int);
extern BOOL (CCreatureObject::*Tramp_CCreatureObject_AddMemSpellPriest)(int, int, int*);
extern BOOL (CCreatureObject::*Tramp_CCreatureObject_AddMemSpellMage)(int, int, int*);
extern void (CCreatureObject::*Tramp_CCreatureObject_ValidateAttackSequence)(char*);
extern BOOL (CCreatureObject::*Tramp_CCreatureObject_EvaluateTrigger)(Trigger&);
extern ACTIONRESULT (CCreatureObject::*Tramp_CCreatureObject_ExecuteAction)();

class DETOUR_CCreatureObject : public CCreatureObject {
public:
	CreFileKnownSpell& DETOUR_GetKnownSpellPriest(int nLevel, int nIndex);
	CreFileKnownSpell& DETOUR_GetKnownSpellMage(int nLevel, int nIndex);
	BOOL DETOUR_AddMemSpellPriest(int nLevel , int nIndex, int* pIndex);
	BOOL DETOUR_AddMemSpellMage(int nLevel , int nIndex, int* pIndex);
	void DETOUR_ValidateAttackSequence(char* pSeq);
	BOOL DETOUR_EvaluateTrigger(Trigger& t);
	ACTIONRESULT DETOUR_ExecuteAction();
};

void __stdcall CCreatureObject_PrintExtraCombatInfoText(CCreatureObject& creSelf, IECString& sText);
BOOL __stdcall CCreatureObject_ShouldAvertCriticalHit(CCreatureObject& creTarget);
BOOL __stdcall CCreatureObject_ApplyDamage_TryBackstab(CCreatureObject& creSource, CItem& itmMain, ItmFileAbility& abilMain, ItmFileAbility& abilLauncher, short orTarget, short orToTarget, CCreatureObject& creTarget);
int __stdcall CCreatureObject_ApplyDamage_CalculateDamageBonus(CCreatureObject& creSource, ItmFileAbility& abilMain, short* pwDamage, CCreatureObject& creTarget);
BOOL __stdcall CCreatureObject_HasThrowingWeaponEquippedHumanoidOnly(CCreatureObject& cre);
BOOL __stdcall CCreatureObject_Spell_IsOverrideInvisible(CCreatureObject& creSource, CCreatureObject& creTarget);
BOOL __stdcall CCreatureObject_IsDeadInFrontVerticalList(CCreatureObject& cre);
BOOL __stdcall CCreatureObject_Spell_IsOverrideSilence(CCreatureObject& creSource);
LPCTSTR __stdcall CCreatureObject_DoSpellCasting_GetGenderLetter(CCreatureObject& creSource, ResSplContainer& resSpell, SplFileAbility& ability);
short __stdcall CCreatureObject_DoSpellCasting_GetCastingSpeed(CCreatureObject& creSource, SplFileAbility& ability);
BOOL __stdcall CCreatureObject_UseItem_CannotTargetInvisible(CCreatureObject& creSource, CCreatureObject& creTarget);
void __stdcall CCreatureObject_UseItem_OverrideAnimation(CCreatureObject& creSource);

#endif //OBJECTCREATURE_H