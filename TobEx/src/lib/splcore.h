#ifndef SPLCORE_H
#define SPLCORE_H

#include "rescore.h"

//Spell flags
#define SPELLFLAG_HOSTILE			0x00000400
#define SPELLFLAG_IGNORE_LOS		0x00000800
#define SPELLFLAG_OUTDOOR			0x00002000
#define SPELLFLAG_NONMAGICAL		0x00004000
#define SPELLFLAG_CONDITIONAL		0x00008000
#define SPELLFLAG_NONCOMBAT			0x00010000
#define SPELLFLAG_TARGET_INVISIBLE	0x01000000 //new in TobEx

typedef IECPtrList CMemSpellList; //AAA8E4
typedef IECPtrList CKnownSpellList; //AAA8CC

struct ResSplContainer { //Size 10h
	void Unload();
	void LoadResource(ResRef& r, BOOL bAddToHandler, BOOL bLogNotFound);
	short GetSpellLevel();
	int GetSpellFlags();

	BOOL bLoaded; //0h
	ResSpl* pRes; //4h
	ResRef name; //8h
};

extern void (ResSplContainer::*ResSplContainer_Unload)();
extern void (ResSplContainer::*ResSplContainer_LoadResource)(ResRef&, BOOL, BOOL);
extern short (ResSplContainer::*ResSplContainer_GetSpellLevel)();
extern int (ResSplContainer::*ResSplContainer_GetSpellFlags)();

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