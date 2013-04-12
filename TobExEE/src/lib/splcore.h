//TobExEE
#ifndef SPLCORE_H
#define SPLCORE_H

#include "rescore.h"
#include "effcore.h"

typedef IECPtrList CMemSpellList;
typedef IECPtrList CKnownSpellList;

struct ResSplFile { //Size 10h
	BOOL m_bLoaded; //0h
	ResSpl* m_pRes; //4h
	ResRef m_rName; //8h
};

/*
struct SpellMod { //Size 1Eh, FIX_ME
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