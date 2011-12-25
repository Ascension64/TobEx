#include "splcore.h"

//ResSplContainer
ResSplContainer& (ResSplContainer::*ResSplContainer_Construct_1ResRef)(ResRef) =
	SetFP(static_cast<ResSplContainer& (ResSplContainer::*)(ResRef)>		(&ResSplContainer::Construct),				0x566E90);
void (ResSplContainer::*ResSplContainer_Deconstruct)() =
	SetFP(static_cast<void (ResSplContainer::*)()>							(&ResSplContainer::Deconstruct),			0x4B65C0);
void (ResSplContainer::*ResSplContainer_LoadResource)(ResRef&, BOOL, BOOL) =
	SetFP(static_cast<void (ResSplContainer::*)(ResRef&, BOOL, BOOL)>		(&ResSplContainer::LoadResource),			0x4B6630);
BOOL (ResSplContainer::*ResSplContainer_Demand)() =
	SetFP(static_cast<BOOL (ResSplContainer::*)()>							(&ResSplContainer::Demand),					0x6430F0);
BOOL (ResSplContainer::*ResSplContainer_Release)() =
	SetFP(static_cast<BOOL (ResSplContainer::*)()>							(&ResSplContainer::Release),				0x64313D);
int (ResSplContainer::*ResSplContainer_GetNumAbilities)() =
	SetFP(static_cast<int (ResSplContainer::*)()>							(&ResSplContainer::GetNumAbilities),		0x643165);
SplFileAbility& (ResSplContainer::*ResSplContainer_GetSpellAbility)(int) =
	SetFP(static_cast<SplFileAbility& (ResSplContainer::*)(int)>			(&ResSplContainer::GetSpellAbility),		0x643244);
CEffect& (ResSplContainer::*ResSplContainer_GetAbilityEffect)(int, int, CCreatureObject&) =
	SetFP(static_cast<CEffect& (ResSplContainer::*)(int, int, CCreatureObject&)>
																			(&ResSplContainer::GetAbilityEffect),		0x6432B6);
short (ResSplContainer::*ResSplContainer_GetSpellLevel)() =
	SetFP(static_cast<short (ResSplContainer::*)()>							(&ResSplContainer::GetSpellLevel),			0x6434A7);
int (ResSplContainer::*ResSplContainer_GetExclusionFlags)() =
	SetFP(static_cast<int (ResSplContainer::*)()>							(&ResSplContainer::GetExclusionFlags),		0x64352E);
STRREF (ResSplContainer::*ResSplContainer_GetSpellDescription)() =
	SetFP(static_cast<STRREF (ResSplContainer::*)()>						(&ResSplContainer::GetSpellDescription),	0x643728);
short (ResSplContainer::*ResSplContainer_GetSpellType)() =
	SetFP(static_cast<short (ResSplContainer::*)()>							(&ResSplContainer::GetSpellType),			0x6437AC);
int (ResSplContainer::*ResSplContainer_GetSpellFlags)() =
	SetFP(static_cast<int (ResSplContainer::*)()>							(&ResSplContainer::GetSpellFlags),			0x643B06);
char (ResSplContainer::*ResSplContainer_GetSpellSchoolPrimary)() =
	SetFP(static_cast<char (ResSplContainer::*)()>							(&ResSplContainer::GetSpellSchoolPrimary),	0x643B91);

ResSplContainer::ResSplContainer() {
	bLoaded = FALSE;
	pRes = NULL;
}

ResSplContainer::ResSplContainer(ResRef r) { (this->*ResSplContainer_Construct_1ResRef)(r); }
ResSplContainer::~ResSplContainer() { (this->*ResSplContainer_Deconstruct)(); }
void ResSplContainer::LoadResource(ResRef& r, BOOL bAddToHandler, BOOL bLogNotFound) { return (this->*ResSplContainer_LoadResource)(r, bAddToHandler, bLogNotFound); }
BOOL ResSplContainer::Demand() { return (this->*ResSplContainer_Demand)(); }
BOOL ResSplContainer::Release() { return (this->*ResSplContainer_Release)(); }
int ResSplContainer::GetNumAbilities() { return (this->*ResSplContainer_GetNumAbilities)(); }
SplFileAbility& ResSplContainer::GetSpellAbility(int nIndex) { return (this->*ResSplContainer_GetSpellAbility)(nIndex); }
CEffect& ResSplContainer::GetAbilityEffect(int nAbilityIdx, int nEffectIdx, CCreatureObject& creSource) {return (this->*ResSplContainer_GetAbilityEffect)(nAbilityIdx, nEffectIdx, creSource); }
short ResSplContainer::GetSpellLevel() { return (this->*ResSplContainer_GetSpellLevel)(); }
STRREF ResSplContainer::GetSpellDescription() { return (this->*ResSplContainer_GetSpellDescription)(); }
int ResSplContainer::GetExclusionFlags() { return (this->*ResSplContainer_GetExclusionFlags)(); }
short ResSplContainer::GetSpellType() { return (this->*ResSplContainer_GetSpellType)(); }
int ResSplContainer::GetSpellFlags() { return (this->*ResSplContainer_GetSpellFlags)(); }
char ResSplContainer::GetSpellSchoolPrimary() { return (this->*ResSplContainer_GetSpellSchoolPrimary)(); }
