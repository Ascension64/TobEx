#ifndef ENGINECHARGEN_H
#define ENGINECHARGEN_H

#include "engchargen.h"

DeclareTrampMemberFunc(void, CScreenCharGen, KitPanelOnLoad, (CPanel& panel, CCreatureObject& cre), KitPanelOnLoad);
DeclareTrampMemberFunc(void, CScreenCharGen, MageBookPanelOnLoad, (CPanel& panel, CCreatureObject& cre), MageBookPanelOnLoad);
DeclareTrampMemberFunc(void, CScreenCharGen, KitPanelOnUpdate, (CPanel& panel, CCreatureObject& cre), KitPanelOnUpdate);
DeclareTrampMemberFunc(void, CScreenCharGen, MageBookPanelOnUpdate, (CPanel& panel, CCreatureObject& cre), MageBookPanelOnUpdate);
DeclareTrampMemberFunc(void, CScreenCharGen, ClassPanelOnUpdate, (CPanel& panel, CCreatureObject& cre), ClassPanelOnUpdate);
DeclareTrampMemberFunc(void, CScreenCharGen, MulticlassPanelOnUpdate, (CPanel& panel, CCreatureObject& cre), MulticlassPanelOnUpdate);
DeclareTrampMemberFunc(void, CScreenCharGen, MageSchoolPanelOnUpdate, (CPanel& panel, CCreatureObject& cre), MageSchoolPanelOnUpdate);
DeclareTrampMemberFunc(void, CScreenCharGen, InitSoundset, (CCreatureObject& cre), InitSoundset);


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