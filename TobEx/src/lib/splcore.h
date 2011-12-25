#ifndef SPLCORE_H
#define SPLCORE_H

#include "rescore.h"
#include "effcore.h"

typedef IECPtrList CMemSpellList; //AAA8E4
typedef IECPtrList CKnownSpellList; //AAA8CC

struct ResSplContainer { //Size 10h
	ResSplContainer();

	ResSplContainer(ResRef r);
	ResSplContainer& Construct(ResRef r) { return *this; } //dummy

	~ResSplContainer();
	void Deconstruct() {} //dummy

	void LoadResource(ResRef& r, BOOL bAddToHandler, BOOL bLogNotFound);
	BOOL Demand();
	BOOL Release();
	int GetNumAbilities();
	SplFileAbility& GetSpellAbility(int nIndex);
	CEffect& GetAbilityEffect(int nAbilityIdx, int nEffectIdx, CCreatureObject& creSource);
	short GetSpellLevel();
	int GetExclusionFlags();
	STRREF GetSpellDescription();
	short GetSpellType();
	int GetSpellFlags();
	char GetSpellSchoolPrimary();

	BOOL bLoaded; //0h
	ResSpl* pRes; //4h
	ResRef name; //8h
};

extern ResSplContainer& (ResSplContainer::*ResSplContainer_Construct_1ResRef)(ResRef);
extern void (ResSplContainer::*ResSplContainer_Deconstruct)();
extern void (ResSplContainer::*ResSplContainer_LoadResource)(ResRef&, BOOL, BOOL);
extern BOOL (ResSplContainer::*ResSplContainer_Demand)();
extern BOOL (ResSplContainer::*ResSplContainer_Release)();
extern int (ResSplContainer::*ResSplContainer_GetNumAbilities)();
extern SplFileAbility& (ResSplContainer::*ResSplContainer_GetSpellAbility)(int);
extern CEffect& (ResSplContainer::*ResSplContainer_GetAbilityEffect)(int, int, CCreatureObject&);
extern short (ResSplContainer::*ResSplContainer_GetSpellLevel)();
extern int (ResSplContainer::*ResSplContainer_GetExclusionFlags)();
extern STRREF (ResSplContainer::*ResSplContainer_GetSpellDescription)();
extern short (ResSplContainer::*ResSplContainer_GetSpellType)();
extern int (ResSplContainer::*ResSplContainer_GetSpellFlags)();
extern char (ResSplContainer::*ResSplContainer_GetSpellSchoolPrimary)();

/*
struct SpellMod { //Size 1Eh
used in DoWildMagic() on CastSpell()
	short u0; nProjectile
	int u2; nPercentProjSpeed
	int u6; 100
	int ua; nPercentLevel
	BOOL ue; bApplyEffects
	int u12; 1
	BOOL u16; bSetProjTarget
	int u1a;
};
*/

#endif //SPLCORE_H