#ifndef ENGINEMAGEBOOK_H
#define ENGINEMAGEBOOK_H

#include "engmagebk.h"

struct MemSpellContingency { //Size 14h
	MemSpellContingency();

	ResRef rName; //0h
	short wMemorizedCount; //8h
	short ua; //ah
	ResRef rParentSpell; //ch
};

DeclareTrampMemberFunc(void, CScreenMageBook, SetLevel, (int nLevel), SetLevel);
DeclareTrampMemberFunc(void, CScreenMageBook, ContingencySelectOnLoad, (CPanel& panel), ContingencySelectOnLoad);
DeclareTrampMemberFunc(void, CScreenMageBook, ContingencySelectOnUpdate, (int nPanelIdx), ContingencySelectOnUpdate);
DeclareTrampMemberFunc(bool, CScreenMageBook, ClearContingencySpell, (char index), ClearContingencySpell);
DeclareTrampMemberFunc(void, CScreenMageBook, CreateContingencySpellList, (char nSpellType, char nLevel), CreateContingencySpellList);

class DETOUR_CScreenMageBook : public CScreenMageBook {
public:
	void DETOUR_SetLevel(int nLevel);
	void DETOUR_ContingencySelectOnLoad(CPanel& panel);
	void DETOUR_ContingencySelectOnUpdate(int nPanelIdx);
	bool DETOUR_ClearContingencySpell(char index);
	void DETOUR_CreateContingencySpellList(char nSpellType, char nLevel);
};

#endif //ENGINEMAGEBOOK_H