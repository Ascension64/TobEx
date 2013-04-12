#ifndef SPLCORE_H
#define SPLCORE_H

#include "rescore.h"
#include "effcore.h"

typedef IECPtrList CMemSpellList; //AAA8E4
typedef IECPtrList CKnownSpellList; //AAA8CC

struct ResSplFile { //Size 10h
	ResSplFile();

	ResSplFile(ResRef r);
	ResSplFile& Construct(ResRef r) { return *this; } //dummy

	~ResSplFile();
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