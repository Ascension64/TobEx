#include "engmagebk.h"

#include "stdafx.h"

void (CMageBook::*CMageBook_SetLevel)(int) =
	SetFP(static_cast<void (CMageBook::*)(int)>	(&CMageBook::SetLevel),		0x7B7BDC);
BOOL (CMageBook::*CMageBook_UpdatePanel)(int) =
	SetFP(static_cast<BOOL (CMageBook::*)(int)>	(&CMageBook::UpdatePanel),	0x7B8F0E);

void CMageBook::SetLevel(int nLevel)			{ return (this->*CMageBook_SetLevel)(nLevel); }
BOOL CMageBook::UpdatePanel(int nPanelIdx)	{ return (this->*CMageBook_UpdatePanel)(nPanelIdx); }