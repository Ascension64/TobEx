#ifndef ENGPRIESTBK_H
#define ENGPRIESTBK_H

#include "engine.h"

class CScreenPriestBook : public CEngine { //Size 1470h
//constructor: 0x784820
public:
	void SetLevel(int nLevel);
	void Update();

	virtual void v0() {}

	char ufe[0x346];
	int currLevel; //444h
	//0x572 - BOOL showKnownSpellIcons (?)
};

#endif //ENGPRIESTBK_H