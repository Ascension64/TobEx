#include "EnginePriestBook.h"

#include "UserPriestBook.h"

void DETOUR_CPriestBook::DETOUR_SetLevel(DWORD nLevel) {
	CUIButtonPriestBook_KnownSpellOffset = 0;
	SetLevel(nLevel);
	return;
};