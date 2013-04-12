#ifndef OBJECTCREATURE_H
#define OBJECTCREATURE_H

#include "objcre.h"

DeclareTrampMemberFunc(CCreatureObject&, CCreatureObject, Construct, (
	void* pFile,
	unsigned int dwSize,
	short wCreType,
	int nExpirationTime,
	int wHuntingRange,
	int wFollowRange,
	unsigned int nTimeOfDayVisible,
	int nPosStartX,
	int nPosStartY,
	int nDirection
	), Construct10);
DeclareTrampMemberFunc(CreFileKnownSpell&, CCreatureObject, GetKnownSpellPriest, (int nLevel, int nIndex), GetKnownSpellPriest);
DeclareTrampMemberFunc(CreFileKnownSpell&, CCreatureObject, GetKnownSpellMage, (int nLevel, int nIndex), GetKnownSpellMage);
DeclareTrampMemberFunc(BOOL, CCreatureObject, AddMemSpellPriest, (int nLevel , int nIndex, int* pIndex), AddMemSpellPriest);
DeclareTrampMemberFunc(BOOL, CCreatureObject, AddMemSpellMage, (int nLevel , int nIndex, int* pIndex), AddMemSpellMage);
DeclareTrampMemberFunc(void, CCreatureObject, ValidateAttackSequence, (char* pSeq), ValidateAttackSequence);
DeclareTrampMemberFunc(BOOL, CCreatureObject, EvaluateTrigger, (Trigger& t), EvaluateTrigger);
DeclareTrampMemberFunc(ACTIONRESULT, CCreatureObject, ExecuteAction, (), ExecuteAction);
DeclareTrampMemberFunc(short, CCreatureObject, GetProficiencyInItem, (CItem& itm), GetProficiencyInItem);
DeclareTrampMemberFunc(ACTIONRESULT, CCreatureObject, ActionPickPockets, (CCreatureObject& creTarget), ActionPickPockets);
DeclareTrampMemberFunc(ACTIONRESULT, CCreatureObject, ActionJumpToAreaEntranceMove, (IECString sArea), ActionJumpToAreaEntranceMove);
DeclareTrampMemberFunc(void, CCreatureObject, UpdateFaceTalkerTimer, (), UpdateFaceTalkerTimer);

class DETOUR_CCreatureObject : public CCreatureObject {
public:
	CCreatureObject& DETOUR_Construct(void* pFile, unsigned int dwSize, short wCreType, int nExpirationTime, int wHuntingRange, int wFollowRange, unsigned int nTimeOfDayVisible, int nPosStartX, int nPosStartY, int nDirection);
	CreFileKnownSpell& DETOUR_GetKnownSpellPriest(int nLevel, int nIndex);
	CreFileKnownSpell& DETOUR_GetKnownSpellMage(int nLevel, int nIndex);
	BOOL DETOUR_AddMemSpellPriest(int nLevel , int nIndex, int* pIndex);
	BOOL DETOUR_AddMemSpellMage(int nLevel , int nIndex, int* pIndex);
	void DETOUR_ValidateAttackSequence(char* pSeq);
	BOOL DETOUR_EvaluateTrigger(Trigger& t);
	ACTIONRESULT DETOUR_ExecuteAction();
	short DETOUR_GetProficiencyInItem(CItem& itm);
	ACTIONRESULT DETOUR_ActionPickPockets(CCreatureObject& creTarget);
	ACTIONRESULT DETOUR_ActionJumpToAreaEntranceMove(IECString sArea);
	void DETOUR_UpdateFaceTalkerTimer();
};

void __stdcall CCreatureObject_PrintExtraCombatInfoText(CCreatureObject& creSelf, IECString& sText);
BOOL __stdcall CCreatureObject_ShouldAvertCriticalHit(CCreatureObject& creTarget);
BOOL __stdcall CCreatureObject_ApplyDamage_TryBackstab(CCreatureObject& creSource, CItem& itmMain, ItmFileAbility& abilMain, ItmFileAbility& abilLauncher, short orTarget, short orToTarget, CCreatureObject& creTarget);
int __stdcall CCreatureObject_ApplyDamage_CalculateDamageBonus(CCreatureObject& creSource, ItmFileAbility& abilMain, short* pwDamage, CCreatureObject& creTarget);
BOOL __stdcall CCreatureObject_HasThrowingWeaponEquippedHumanoidOnly(CCreatureObject& cre);
void __stdcall CCreatureObject_GetClassAbilities(CCreatureObject& cre, unsigned char cClass, int nLevels, IECPtrList& cpl);
void __stdcall CCreatureObject_GetClassAbilities(CCreatureObject& cre, CDerivedStats& cdsTarget, IECPtrList& cpl);
void __stdcall CCreatureObject_JoinParty_UpdateClassAbilities(CCreatureObject& cre, CDerivedStats& cds);
BOOL __stdcall CCreatureObject_Spell_IsOverrideInvisible(CCreatureObject& creSource, CCreatureObject& creTarget);
BOOL __stdcall CCreatureObject_IsDeadInFrontVerticalList(CCreatureObject& cre);
BOOL __stdcall CCreatureObject_Spell_IsOverrideSilence(CCreatureObject& creSource);
LPCTSTR __stdcall CCreatureObject_DoSpellCasting_GetGenderLetter(CCreatureObject& creSource, ResSplFile& resSpell, SplFileAbility& ability);
short __stdcall CCreatureObject_DoSpellCasting_GetCastingSpeed(CCreatureObject& creSource, SplFileAbility& ability);
BOOL __stdcall CCreatureObject_UseItem_CannotTargetInvisible(CCreatureObject& creSource, CCreatureObject& creTarget);
void __stdcall CCreatureObject_UseItem_OverrideAnimation(CCreatureObject& creSource);
BOOL __stdcall CCreatureObject_AttackOnce_DoHalfAttack(CCreatureObject& creSource, char cInRoundIdx);
void __stdcall CCreatureObject_UpdateModalState_DoBardSongNormal(CCreatureObject& creSource);
void __stdcall CCreatureObject_SetDifficultyLuckModifier(CCreatureObject& cre);

#endif //OBJECTCREATURE_H