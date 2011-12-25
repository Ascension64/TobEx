#ifndef ENGINECHARGEN_H
#define ENGINECHARGEN_H

#include "engchargen.h"

extern void (CCharGen::*Tramp_CCharGen_KitPanelOnLoad)(CPanel&, CCreatureObject&);
extern void (CCharGen::*Tramp_CCharGen_MageBookPanelOnLoad)(CPanel&, CCreatureObject&);
extern void (CCharGen::*Tramp_CCharGen_KitPanelOnUpdate)(CPanel&, CCreatureObject&);
extern void (CCharGen::*Tramp_CCharGen_MageBookPanelOnUpdate)(CPanel&, CCreatureObject&);
extern void (CCharGen::*Tramp_CCharGen_ClassPanelOnUpdate)(CPanel&, CCreatureObject&);
extern void (CCharGen::*Tramp_CCharGen_MulticlassPanelOnUpdate)(CPanel&, CCreatureObject&);
extern void (CCharGen::*Tramp_CCharGen_MageSchoolPanelOnUpdate)(CPanel&, CCreatureObject&);
extern void (CCharGen::*Tramp_CCharGen_InitSoundset)(CCreatureObject&);

class DETOUR_CCharGen : public CCharGen {
public:
	void DETOUR_KitPanelOnLoad(CPanel&, CCreatureObject&);
	void DETOUR_MageBookPanelOnLoad(CPanel&, CCreatureObject&);
	void DETOUR_KitPanelOnUpdate(CPanel&, CCreatureObject&);
	void DETOUR_MageBookPanelOnUpdate(CPanel&, CCreatureObject&);
	void DETOUR_ClassPanelOnUpdate(CPanel&, CCreatureObject&);
	void DETOUR_MulticlassPanelOnUpdate(CPanel&, CCreatureObject&);
	void DETOUR_MageSchoolPanelOnUpdate(CPanel&, CCreatureObject&);
	void DETOUR_InitSoundset(CCreatureObject&);
};

#endif //ENGINECHARGEN_H