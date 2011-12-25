#ifndef SPLCORE_H
#define SPLCORE_H

#include "rescore.h"

typedef IECPtrList CMemSpellList; //AAA8E4
typedef IECPtrList CKnownSpellList; //AAA8CC

struct ResSplContainer { //Size 10h
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