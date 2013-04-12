#include "itmcore.h"

#include "stdafx.h"

DefineLibNoRetFunc(CItem&, CItem, CItem, (), Construct, Construct, (), 0x5A83F0);
DefineLibNoRetFunc(CItem&, CItem, CItem, (CItem& itm), Copy, Copy, (itm), 0x5A84BE);
DefineLibNoRetFunc(void, CItem, ~CItem, (), Deconstruct, Deconstruct, (), 0x5A9E16);
DefineLibMemberFunc(BOOL, CItem, Demand, (), Demand, Demand, (), 0x5AA032);
DefineLibMemberFunc(BOOL, CItem, Release, (), Release, Release, (), 0x5AA07F);
DefineLibMemberFunc(void, CItem, LoadResource, (ResRef& res, BOOL bAddToHandler), LoadResource, LoadResource, (res, bAddToHandler), 0x5AA0A7);
DefineLibMemberFunc(int, CItem, GetNumAbilities, (), GetNumAbilities, GetNumAbilities, (), 0x5AA1D6);
DefineLibMemberFunc(short, CItem, GetNumUsage, (int nUsageIdx), GetNumUsage, GetNumUsage, (nUsageIdx), 0x5AA258);
DefineLibMemberFunc(short, CItem, GetNumCharges, (int nAbilityIdx), GetNumCharges, GetNumCharges, (nAbilityIdx), 0x5AA2EF);
DefineLibMemberFunc(void, CItem, SetNumUsage, (int nUsageIdx, short wValue), SetNumUsage, SetNumUsage, (nUsageIdx, wValue), 0x5AA3AA);
DefineLibMemberFunc(void, CItem, Equip, (CCreatureObject& cre, int nSlot, BOOL bDoNotApplyEffects), Equip, Equip, (cre, nSlot, bDoNotApplyEffects), 0x5AA430);
DefineLibMemberFunc(ItmFileAbility&, CItem, GetAbility, (int nAbilityIdx), GetAbility, GetAbility, (nAbilityIdx), 0x5AB0D7);
DefineLibMemberFunc(CEffect&, CItem, GetAbilityEffect, (int nAbilityIdx, int nEffectIdx, CCreatureObject& creSource), GetAbilityEffect, GetAbilityEffect, (nAbilityIdx, nEffectIdx, creSource), 0x5AB168);
DefineLibMemberFunc(short, CItem, GetType, (), GetType, GetType, (), 0x5AB32B);
DefineLibMemberFunc(unsigned int, CItem, GetFlags, (), GetFlags, GetFlags, (), 0x5AB591);
DefineLibMemberFunc(unsigned int, CItem, GetUnusableFlags, (), GetUnusableFlags, GetUnusableFlags, (), 0x5AB609);
DefineLibMemberFunc(short, CItem, GetMaximumStackSize, (), GetMaximumStackSize, GetMaximumStackSize, (), 0x5AB8B7);
DefineLibMemberFunc(char, CItem, GetProficiencyType, (), GetProficiencyType, GetProficiencyType, (), 0x5ACAB3);
