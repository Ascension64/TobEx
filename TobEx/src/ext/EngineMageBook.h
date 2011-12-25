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

extern void (CMageBook::*Tramp_CMageBook_SetLevel)(int);
extern void (CMageBook::*Tramp_CMageBook_ContingencySelectOnLoad)(CPanel&);
extern void (CMageBook::*Tramp_CMageBook_ContingencySelectOnUpdate)(int);
extern bool (CMageBook::*Tramp_CMageBook_ClearContingencySpell)(char index);
extern void (CMageBook::*Tramp_CMageBook_CreateContingencySpellList)(char, char);

class DETOUR_CMageBook : public CMageBook {
public:
	void DETOUR_SetLevel(int nLevel);
	void DETOUR_ContingencySelectOnLoad(CPanel& panel);
	void DETOUR_ContingencySelectOnUpdate(int nPanelIdx);
	bool DETOUR_ClearContingencySpell(char index);
	void DETOUR_CreateContingencySpellList(char nSpellType, char nLevel);
};

#endif //ENGINEMAGEBOOK_H