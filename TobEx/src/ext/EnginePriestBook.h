#ifndef ENGINEPRIESTBOOK_H
#define ENGINEPRIESTBOOK_H

#include "engpriestbk.h"

extern void (CPriestBook::*Tramp_CPriestBook_SetLevel)(DWORD);

class DETOUR_CPriestBook : public CPriestBook {
public:
	void DETOUR_SetLevel(DWORD);
};

#endif //ENGINEPRIESTBOOK_H