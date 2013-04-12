#include "splcore.h"

#include "stdafx.h"

//ResSplFile
ResSplFile::ResSplFile() {
	bLoaded = FALSE;
	pRes = NULL;
}

DefineLibNoRetFunc(ResSplFile&, ResSplFile, ResSplFile, (ResRef r), Construct, Construct1, (r), 0x566E90);
DefineLibNoRetFunc(void, ResSplFile, ~ResSplFile, (), Deconstruct, Deconstruct, (), 0x4B65C0);
DefineLibMemberFunc(void, ResSplFile, LoadResource, (ResRef& r, BOOL bAddToHandler, BOOL bLogNotFound), LoadResource, LoadResource, (r, bAddToHandler, bLogNotFound), 0x4B6630);
DefineLibMemberFunc(BOOL, ResSplFile, Demand, (), Demand, Demand, (), 0x6430F0);
DefineLibMemberFunc(BOOL, ResSplFile, Release, (), Release, Release, (), 0x64313D);
DefineLibMemberFunc(int, ResSplFile, GetNumAbilities, (), GetNumAbilities, GetNumAbilities, (), 0x643165);
DefineLibMemberFunc(SplFileAbility&, ResSplFile, GetSpellAbility, (int nIndex), GetSpellAbility, GetSpellAbility, (nIndex), 0x643244);
DefineLibMemberFunc(CEffect&, ResSplFile, GetAbilityEffect, (int nAbilityIdx, int nEffectIdx, CCreatureObject& creSource), GetAbilityEffect, GetAbilityEffect, (nAbilityIdx, nEffectIdx, creSource), 0x6432B6);
DefineLibMemberFunc(short, ResSplFile, GetSpellLevel, (), GetSpellLevel, GetSpellLevel, (), 0x6434A7);
DefineLibMemberFunc(int, ResSplFile, GetExclusionFlags, (), GetExclusionFlags, GetExclusionFlags, (), 0x64352E);
DefineLibMemberFunc(STRREF, ResSplFile, GetSpellDescription, (), GetSpellDescription, GetSpellDescription, (), 0x643728);
DefineLibMemberFunc(short, ResSplFile, GetSpellType, (), GetSpellType, GetSpellType, (), 0x6437AC);
DefineLibMemberFunc(int, ResSplFile, GetSpellFlags, (), GetSpellFlags, GetSpellFlags, (), 0x643B06);
DefineLibMemberFunc(char, ResSplFile, GetSpellSchoolPrimary, (), GetSpellSchoolPrimary, GetSpellSchoolPrimary, (), 0x643B91);
