#include "areacore.h"

BYTE (CArea::*CArea_GetSong)(WORD) =
	SetFP(static_cast<BYTE (CArea::*)(WORD)>	(&CArea::GetSong),		0x4D40D6);

BYTE CArea::GetSong(WORD wType) { return (this->*CArea_GetSong)(wType); }
