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

extern void (CScreenMageBook::*Tramp_CScreenMageBook_SetLevel)(int);
extern void (CScreenMageBook::*Tramp_CScreenMageBook_ContingencySelectOnLoad)(CPanel&);
extern void (CScreenMageBook::*Tramp_CScreenMageBook_ContingencySelectOnUpdate)(int);
extern bool (CScreenMageBook::*Tramp_CScreenMageBook_ClearContingencySpell)(char index);
extern void (CScreenMageBook::*Tramp_CScreenMageBook_CreateContingencySpellList)(char, char);

class DETOUR_CScreenMageBook : public CScreenMageBook {
public:
	void DETOUR_SetLevel(int nLevel);
	void DETOUR_ContingencySelectOnLoad(CPanel& panel);
	void DETOUR_ContingencySelectOnUpdate(int nPanelIdx);
	bool DETOUR_ClearContingencySpell(char index);
	void DETOUR_CreateContingencySpellList(char nSpellType, char nLevel);
};

#endif //ENGINEMAGEBOOK_H