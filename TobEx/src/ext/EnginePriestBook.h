#ifndef ENGINEPRIESTBOOK_H
#define ENGINEPRIESTBOOK_H

#include "engpriestbk.h"

extern void (CScreenPriestBook::*Tramp_CScreenPriestBook_SetLevel)(int);

class DETOUR_CScreenPriestBook : public CScreenPriestBook {
public:
	void DETOUR_SetLevel(int nLevel);
};

#endif //ENGINEPRIESTBOOK_H