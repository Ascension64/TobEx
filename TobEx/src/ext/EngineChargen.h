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
	void DETOUR_KitPanelOnLoad(CPanel& panel, CCreatureObject& cre);
	void DETOUR_MageBookPanelOnLoad(CPanel& panel, CCreatureObject& cre);
	void DETOUR_KitPanelOnUpdate(CPanel& panel, CCreatureObject& cre);
	void DETOUR_MageBookPanelOnUpdate(CPanel& panel, CCreatureObject& cre);
	void DETOUR_ClassPanelOnUpdate(CPanel& panel, CCreatureObject& cre);
	void DETOUR_MulticlassPanelOnUpdate(CPanel& panel, CCreatureObject& cre);
	void DETOUR_MageSchoolPanelOnUpdate(CPanel& panel, CCreatureObject& cre);
	void DETOUR_InitSoundset(CCreatureObject& cre);
};

BOOL CCharGen_MageSchoolPanelCanContinue(CCreatureObject&);

#endif //ENGINECHARGEN_H