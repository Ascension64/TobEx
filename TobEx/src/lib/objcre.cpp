#include "objcre.h"

//CProtectedSplList
DefineLibMemberFunc(void, CProtectedSplList, AddTail, (
	CEffect& effect,
	int nPower,
	int nOpcode,
	CCreatureObject& cre,
	BOOL bCreateProj,
	STRREF strref,
	BOOL bDoNotUpdateEff,
	BOOL bRestoreLostSpls
	), AddTail, AddTail, (effect, nPower, nOpcode, cre, bCreateProj, strref, bDoNotUpdateEff, bRestoreLostSpls), 0x464A50);
DefineLibMemberFunc(void, CProtectedSplList, Update, (CCreatureObject& cre), Update, Update, (cre), 0x464BFB);

//CCreatureObject
DefineLibMemberFunc(CGameObject&, CCreatureObject, SetTarget, (Object& o, char type), SetTarget, SetTarget, (o, type), 0x48D519);
DefineLibMemberFunc(void, CCreatureObject, GetSpellIdsName, (int nSpellIdx, IECString* ptr), GetSpellIdsName, GetSpellIdsName, (nSpellIdx, ptr), 0x48FE60);
DefineLibMemberFunc(CDerivedStats&, CCreatureObject, GetActiveStats, (), GetActiveStats, GetActiveStats, (), 0x495630);
DefineLibMemberFunc(ACTIONRESULT, CCreatureObject, CastSpell, (
	ResRef& rResource,
	CGameObject& cgoTarget,
	BOOL bPrintStrref,
	STRREF strref,
	void* pMod,
	BOOL bPrintEventMsg,
	BOOL bDoNotApplySplAbil
	), CastSpell, CastSpell, (rResource, cgoTarget, bPrintStrref, strref, pMod, bPrintEventMsg, bDoNotApplySplAbil), 0x4AD88A);
DefineLibStaticFunc(void, __cdecl, CCreatureObject, RemoveItem, (CCreatureObject& cre, int nSlot), RemoveItem, (cre, nSlot), 0x52033C);
DefineLibMemberFunc(CEffectList&, CCreatureObject, GetEquippedEffectsList, (), GetEquippedEffectsList, GetEquippedEffectsList, (), 0x567540);
DefineLibMemberFunc(CEffectList&, CCreatureObject, GetTimedEffectList, (), GetTimedEffectList, GetTimedEffectList, (), 0x567560);

DefineLibNoRetFunc(CCreatureObject&, CCreatureObject, CCreatureObject, (
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
	), Construct, Construct10, (pFile, dwSize, wCreType, nExpirationTime, wHuntingRange, wFollowRange, nTimeOfDayVisible, nPosStartX, nPosStartY, nDirection), 0x87FB08);
DefineLibMemberFunc(void, CCreatureObject, CreateGore, (int dwUnused, short wOrient, short wType), CreateGore, CreateGore, (dwUnused, wOrient, wType), 0x8862FE);
DefineLibMemberFunc(void, CCreatureObject, UpdateHPStatusTooltip, (CUIControl& control), UpdateHPStatusTooltip, UpdateHPStatusTooltip, (control), 0x8AC3C5);
DefineLibMemberFunc(short, CCreatureObject, GetOrientationTo, (CPoint& pt), GetOrientationTo, GetOrientationTo, (pt), 0x8ACFC2);
DefineLibStaticFunc(short, __cdecl, CCreatureObject, CalculateOrientation, (CPoint& pt1, CPoint& pt2), CalculateOrientation, (pt1, pt2), 0x8AD080);
DefineLibMemberFunc(void, CCreatureObject, SetAnimationSequence, (short wSeq), SetAnimationSequence, SetAnimationSequence, (wSeq), 0x8AD630);
DefineLibMemberFunc(void, CCreatureObject, StartSpriteEffect, (char nEffectType, char nParticleType, int nParticles), StartSpriteEffect, StartSpriteEffect, (nEffectType, nParticleType, nParticles), 0x8B10DE);
DefineLibMemberFunc(CItem&, CCreatureObject, GetFirstEquippedLauncherOfAbility, (ItmFileAbility& ability, int* pnSlot), GetFirstEquippedLauncherOfAbility, GetFirstEquippedLauncherOfAbility, (ability, pnSlot), 0x8C5981);
DefineLibMemberFunc(int, CCreatureObject, GetSlotOfEquippedLauncherOfAmmo, (short wAmmoSlot, short wAbilityIdx), GetSlotOfEquippedLauncherOfAmmo, GetSlotOfEquippedLauncherOfAmmo, (wAmmoSlot, wAbilityIdx), 0x8C5B1E);
DefineLibMemberFunc(void, CCreatureObject, UnequipAll, (BOOL bKeepEffects), UnequipAll, UnequipAll, (bKeepEffects), 0x8CA628);
DefineLibMemberFunc(void, CCreatureObject, EquipAll, (BOOL bDoNotApplyEffects), EquipAll, EquipAll, (bDoNotApplyEffects), 0x8CA88D);
DefineLibMemberFunc(void, CCreatureObject, AddKnownSpell, (ResRef& name, BOOL bFeedback), AddKnownSpell, AddKnownSpell, (name, bFeedback), 0x8CAFE4);
DefineLibMemberFunc(CreFileKnownSpell&, CCreatureObject, GetKnownSpellPriest, (int nLevel, int nIndex), GetKnownSpellPriest, GetKnownSpellPriest, (nLevel, nIndex), 0x8CB91F);
DefineLibMemberFunc(CreFileKnownSpell&, CCreatureObject, GetKnownSpellMage, (int nLevel, int nIndex), GetKnownSpellMage, GetKnownSpellMage, (nLevel, nIndex), 0x8CB949);
DefineLibMemberFunc(CreFileKnownSpell&, CCreatureObject, GetKnownSpellInnate, (int nLevel, int nIndex), GetKnownSpellInnate, GetKnownSpellInnate, (nLevel, nIndex), 0x8CB973);
DefineLibMemberFunc(CreFileMemorizedSpell&, CCreatureObject, GetMemSpellPriest, (int nLevel, int nIndex), GetMemSpellPriest, GetMemSpellPriest, (nLevel, nIndex), 0x8CB9D9);
DefineLibMemberFunc(CreFileMemorizedSpell&, CCreatureObject, GetMemSpellMage, (int nLevel, int nIndex), GetMemSpellMage, GetMemSpellMage, (nLevel, nIndex), 0x8CBA03);
DefineLibMemberFunc(CreFileMemorizedSpell&, CCreatureObject, GetMemSpellInnate, (int nLevel, int nIndex), GetMemSpellInnate, GetMemSpellInnate, (nLevel, nIndex), 0x8CBA2D);
DefineLibMemberFunc(BOOL, CCreatureObject, AddMemSpellPriest, (int nLevel, int nIndex, int* pIndex), AddMemSpellPriest, AddMemSpellPriest, (nLevel, nIndex, pIndex), 0x8CBB64);
DefineLibMemberFunc(BOOL, CCreatureObject, AddMemSpellMage, (int nLevel, int nIndex, int* pIndex), AddMemSpellMage, AddMemSpellMage, (nLevel, nIndex, pIndex), 0x8CBBEA);
DefineLibMemberFunc(BOOL, CCreatureObject, AddMemSpellInnate, (int nLevel, int nIndex, int* pIndex), AddMemSpellInnate, AddMemSpellInnate, (nLevel, nIndex, pIndex), 0x8CBC70);
DefineLibMemberFunc(BOOL, CCreatureObject, AddKnownSpellPriest, (ResRef& name, int nLevel), AddKnownSpellPriest, AddKnownSpellPriest, (name, nLevel), 0x8CC4F4);
DefineLibMemberFunc(BOOL, CCreatureObject, AddKnownSpellMage, (ResRef& name, int nLevel), AddKnownSpellMage, AddKnownSpellMage, (name, nLevel), 0x8CC524);
DefineLibMemberFunc(BOOL, CCreatureObject, AddKnownSpellInnate, (ResRef& name, int nLevel), AddKnownSpellInnate, AddKnownSpellInnate, (name, nLevel), 0x8CC554);
DefineLibMemberFunc(void, CCreatureObject, ApplyClassAbilities, (CDerivedStats& cdsOld, BOOL bPrintMsgForSpecAbil), ApplyClassAbilities, ApplyClassAbilities, (cdsOld, bPrintMsgForSpecAbil), 0x8D22D8);
DefineLibMemberFunc(void, CCreatureObject, RemoveClassAbilities, (CDerivedStats& cdsTarget), RemoveClassAbilities, RemoveClassAbilities, (cdsTarget), 0x8D2E5F);
DefineLibMemberFunc(IECString&, CCreatureObject, GetLongName, (), GetLongName, GetLongName, (), 0x8D49D9);
DefineLibMemberFunc(STRREF, CCreatureObject, GetNameRef, (), GetNameRef, GetNameRef, (), 0x8D4AAC);
DefineLibMemberFunc(void, CCreatureObject, SetSpellMemorizedState, (ResSplFile& resSpell, BOOL bState), SetSpellMemorizedState, SetSpellMemorizedState, (resSpell, bState), 0x8D6202);
DefineLibMemberFunc(void, CCreatureObject, ValidateAttackSequence, (char* pSeq), ValidateAttackSequence, ValidateAttackSequence, (pSeq), 0x8D6D78);
DefineLibMemberFunc(char, CCreatureObject, GetNumUniqueMemSpellMage, (int nLevel, ResRef rTemp), GetNumUniqueMemSpellMage, GetNumUniqueMemSpellMage, (nLevel, rTemp), 0x8DAE88);
DefineLibMemberFunc(BOOL, CCreatureObject, InDialogAction, (), InDialogAction, InDialogAction, (), 0x8DE5F5);
DefineLibMemberFunc(void, CCreatureObject, SetResRef, (ResRef& rName), SetResRef, SetResRef, (rName), 0x8DF047);
DefineLibMemberFunc(unsigned int, CCreatureObject, GetKitUnusableFlag, (), GetKitUnusableFlag, GetKitUnusableFlag, (), 0x8E066B);
DefineLibMemberFunc(void, CCreatureObject, Feedback, (
	short wEventId,
	int nParam1,
	int nParam2,
	int nParam3,
	STRREF strrefParam4,
	BOOL bParam5,
	IECString& sParam6
	), Feedback, Feedback, (wEventId, nParam1, nParam2, nParam3, strrefParam4, bParam5, sParam6), 0x8FAE5A);
DefineLibMemberFunc(short, CCreatureObject, GetProficiencyInItem, (CItem& itm), GetProficiencyInItem, GetProficiencyInItem, (itm), 0x90C663);
DefineLibMemberFunc(ACTIONRESULT, CCreatureObject, ActionMoveToObject, (CGameObject& cgoTarget), ActionMoveToObject, ActionMoveToObject, (cgoTarget), 0x90EBCA);
DefineLibMemberFunc(ACTIONRESULT, CCreatureObject, ActionPickPockets, (CCreatureObject& creTarget), ActionPickPockets, ActionPickPockets, (creTarget), 0x9431AE);
DefineLibMemberFunc(short, CCreatureObject, GetProficiency, (int nWeapProfId), GetProficiency, GetProficiency, (nWeapProfId), 0x950A4F);
DefineLibMemberFunc(short, CCreatureObject, GetSpellCastingLevel, (ResSplFile& resSpell, BOOL bUseWildMagicMod), GetSpellCastingLevel, GetSpellCastingLevel, (resSpell, bUseWildMagicMod), 0x9514A1);
DefineLibMemberFunc(ACTIONRESULT, CCreatureObject, ActionJumpToAreaEntranceMove, (IECString sArea), ActionJumpToAreaEntranceMove, ActionJumpToAreaEntranceMove, (sArea), 0x953CE9);
DefineLibMemberFunc(void, CCreatureObject, UpdateFaceTalkerTimer, (), UpdateFaceTalkerTimer, UpdateFaceTalkerTimer, (), 0x955CD7);

DefineLibMemberFunc(bool, CCreatureObject, NeedsAIUpdate, (bool bRun, int nChitinUpdates), NeedsAIUpdate, NeedsAIUpdate, (bRun, nChitinUpdates), 0x8DE733);
DefineLibMemberFunc(BOOL, CCreatureObject, EvaluateTrigger, (Trigger& t), EvaluateTrigger, EvaluateTrigger, (t), 0x8F6C0E);
DefineLibMemberFunc(ACTIONRESULT, CCreatureObject, ExecuteAction, (), ExecuteAction, ExecuteAction, (), 0x8E2276);
DefineLibMemberFunc(void, CCreatureObject, SetCurrentAction, (Action& a), SetCurrentAction, SetCurrentAction, (a), 0x8F97AA);
