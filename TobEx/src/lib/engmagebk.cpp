#include "engmagebk.h"

#include "utils.h"

void (CMageBook::*CMageBook_SetLevel)(DWORD) =
	SetFP(static_cast<void (CMageBook::*)(DWORD)>	(&CMageBook::SetLevel),		0x7B7BDC);
BOOL (CMageBook::*CMageBook_UpdatePanel)(DWORD) =
	SetFP(static_cast<BOOL (CMageBook::*)(DWORD)>	(&CMageBook::UpdatePanel),	0x7B8F0E);

void CMageBook::SetLevel(DWORD nLevel)			{ return (this->*CMageBook_SetLevel)(nLevel); }
BOOL CMageBook::UpdatePanel(DWORD nPanelIdx)	{ return (this->*CMageBook_UpdatePanel)(nPanelIdx); }