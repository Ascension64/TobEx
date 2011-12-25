#ifndef ENGPRIESTBK_H
#define ENGPRIESTBK_H

#include "engine.h"

class CPriestBook : public CEngine { //Size 1470h
//constructor: 0x784820
public:
	void SetLevel(DWORD);
	void Update();

	virtual void v0() {}

	char ufe[0x346];
	DWORD currLevel; //444h
	//0x572 - BOOL showKnownSpellIcons (?)
};

extern void (CPriestBook::*CPriestBook_SetLevel)(DWORD);
extern void (CPriestBook::*CPriestBook_Update)();

#endif //ENGPRIESTBK_H