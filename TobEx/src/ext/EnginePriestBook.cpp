#include "EnginePriestBook.h"

#include "UserPriestBook.h"

void (CPriestBook::*Tramp_CPriestBook_SetLevel)(int) =
	SetFP(static_cast<void (CPriestBook::*)(int)>	(&CPriestBook::SetLevel),		0x7868D9);

void DETOUR_CPriestBook::DETOUR_SetLevel(int nLevel) {
	CUIButtonPriestBook_KnownSpellOffset = 0;
	(this->*Tramp_CPriestBook_SetLevel)(nLevel);
	return;
};