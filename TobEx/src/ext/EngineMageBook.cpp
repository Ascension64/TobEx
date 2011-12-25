#include "EngineMageBook.h"

#include "UserMageBook.h"

void DETOUR_CMageBook::DETOUR_SetLevel(DWORD nLevel) {
	CUIButtonMageBook_KnownSpellOffset = 0;
	SetLevel(nLevel);
	return;
};