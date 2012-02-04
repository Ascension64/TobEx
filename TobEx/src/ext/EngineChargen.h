#ifndef ENGINECHARGEN_H
#define ENGINECHARGEN_H

#include "engchargen.h"

extern void (CScreenCharGen::*Tramp_CScreenCharGen_KitPanelOnLoad)(CPanel&, CCreatureObject&);
extern void (CScreenCharGen::*Tramp_CScreenCharGen_MageBookPanelOnLoad)(CPanel&, CCreatureObject&);
extern void (CScreenCharGen::*Tramp_CScreenCharGen_KitPanelOnUpdate)(CPanel&, CCreatureObject&);
extern void (CScreenCharGen::*Tramp_CScreenCharGen_MageBookPanelOnUpdate)(CPanel&, CCreatureObject&);
extern void (CScreenCharGen::*Tramp_CScreenCharGen_ClassPanelOnUpdate)(CPanel&, CCreatureObject&);
extern void (CScreenCharGen::*Tramp_CScreenCharGen_MulticlassPanelOnUpdate)(CPanel&, CCreatureObject&);
extern void (CScreenCharGen::*Tramp_CScreenCharGen_MageSchoolPanelOnUpdate)(CPanel&, CCreatureObject&);
extern void (CScreenCharGen::*Tramp_CScreenCharGen_InitSoundset)(CCreatureObject&);

class DETOUR_CScreenCharGen : public CScreenCharGen {
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

BOOL CScreenCharGen_MageSchoolPanelCanContinue(CCreatureObject&);

#endif //ENGINECHARGEN_H