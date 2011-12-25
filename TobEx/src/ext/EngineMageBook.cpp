#include "EngineMageBook.h"

#include "UserMageBook.h"

void (CMageBook::*Tramp_CMageBook_SetLevel)(int) =
	SetFP(static_cast<void (CMageBook::*)(int)>	(&CMageBook::SetLevel),		0x7B7BDC);

void DETOUR_CMageBook::DETOUR_SetLevel(int nLevel) {
	CUIButtonMageBook_KnownSpellOffset = 0;
	(this->*Tramp_CMageBook_SetLevel)(nLevel);
	return;
};