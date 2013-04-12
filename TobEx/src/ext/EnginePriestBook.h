#ifndef ENGINEPRIESTBOOK_H
#define ENGINEPRIESTBOOK_H

#include "engpriestbk.h"

DeclareTrampMemberFunc(void, CScreenPriestBook, SetLevel, (int nLevel), SetLevel);

class DETOUR_CScreenPriestBook : public CScreenPriestBook {
public:
	void DETOUR_SetLevel(int nLevel);
};

#endif //ENGINEPRIESTBOOK_H