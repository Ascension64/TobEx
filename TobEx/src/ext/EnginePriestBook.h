#ifndef ENGINEPRIESTBOOK_H
#define ENGINEPRIESTBOOK_H

#include "engpriestbk.h"

extern void (CPriestBook::*Tramp_CPriestBook_SetLevel)(int);

class DETOUR_CPriestBook : public CPriestBook {
public:
	void DETOUR_SetLevel(int nLevel);
};

#endif //ENGINEPRIESTBOOK_H