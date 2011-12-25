#include "engpriestbk.h"

#include "utils.h"

void (CPriestBook::*CPriestBook_SetLevel)(DWORD) =
	SetFP(static_cast<void (CPriestBook::*)(DWORD)>	(&CPriestBook::SetLevel),		0x7868D9);
void (CPriestBook::*CPriestBook_Update)() =
	SetFP(static_cast<void (CPriestBook::*)()>		(&CPriestBook::Update),			0x7870AC);

void CPriestBook::SetLevel(DWORD nLevel)	{ return (this->*CPriestBook_SetLevel)(nLevel); }
void CPriestBook::Update()					{ return (this->*CPriestBook_Update)(); }