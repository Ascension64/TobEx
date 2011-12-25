#include "EngineMageBook.h"

#include "UserMageBook.h"

void (CMageBook::*Tramp_CMageBook_SetLevel)(DWORD) =
	SetFP(static_cast<void (CMageBook::*)(DWORD)>	(&CMageBook::SetLevel),		0x7B7BDC);

void DETOUR_CMageBook::DETOUR_SetLevel(DWORD nLevel) {
	CUIButtonMageBook_KnownSpellOffset = 0;
	(this->*Tramp_CMageBook_SetLevel)(nLevel);
	return;
};