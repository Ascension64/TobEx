#include "arecore.h"

char (CArea::*CArea_GetSong)(short) =
	SetFP(static_cast<char (CArea::*)(short)>	(&CArea::GetSong),		0x4D40D6);

char CArea::GetSong(short wType) { return (this->*CArea_GetSong)(wType); }
