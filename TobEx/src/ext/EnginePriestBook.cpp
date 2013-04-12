#include "EnginePriestBook.h"

#include "UserPriestBook.h"

DefineTrampMemberFunc(void, CScreenPriestBook, SetLevel, (int nLevel), SetLevel, SetLevel, 0x7868D9);

void DETOUR_CScreenPriestBook::DETOUR_SetLevel(int nLevel) {
	CUIButtonPriestBook_KnownSpellOffset = 0;
	(this->*Tramp_CScreenPriestBook_SetLevel)(nLevel);
	return;
};