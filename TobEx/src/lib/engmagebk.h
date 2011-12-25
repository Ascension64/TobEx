#ifndef ENGMAGEBK_H
#define ENGMAGEBK_H

#include "engine.h"

class CMageBook : public CEngine { //Size 14DAh
//constructor: 0x7B5970
public:
	void SetLevel(DWORD);
	BOOL UpdatePanel(DWORD);

	virtual void v0() {}

	char ufe[0x346];
	DWORD currLevel; //444h
	//0x572 - BOOL showKnownSpellIcons (?)
	//0x1470 - BOOL isSorcererClass
};

extern void (CMageBook::*CMageBook_SetLevel)(DWORD);
extern BOOL (CMageBook::*CMageBook_UpdatePanel)(DWORD);

#endif //ENGMAGEBK_H