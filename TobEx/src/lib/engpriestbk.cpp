#include "engpriestbk.h"

#include "stdafx.h"

void (CPriestBook::*CPriestBook_SetLevel)(int) =
	SetFP(static_cast<void (CPriestBook::*)(int)>	(&CPriestBook::SetLevel),		0x7868D9);
void (CPriestBook::*CPriestBook_Update)() =
	SetFP(static_cast<void (CPriestBook::*)()>		(&CPriestBook::Update),			0x7870AC);

void CPriestBook::SetLevel(int nLevel)	{ return (this->*CPriestBook_SetLevel)(nLevel); }
void CPriestBook::Update()					{ return (this->*CPriestBook_Update)(); }