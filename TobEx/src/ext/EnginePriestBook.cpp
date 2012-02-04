#include "EnginePriestBook.h"

#include "UserPriestBook.h"

void (CScreenPriestBook::*Tramp_CScreenPriestBook_SetLevel)(int) =
	SetFP(static_cast<void (CScreenPriestBook::*)(int)>	(&CScreenPriestBook::SetLevel),		0x7868D9);

void DETOUR_CScreenPriestBook::DETOUR_SetLevel(int nLevel) {
	CUIButtonPriestBook_KnownSpellOffset = 0;
	(this->*Tramp_CScreenPriestBook_SetLevel)(nLevel);
	return;
};