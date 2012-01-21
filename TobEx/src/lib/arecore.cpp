#include "arecore.h"

char (CArea::*CArea_GetSong)(short) =
	SetFP(static_cast<char (CArea::*)(short)>	(&CArea::GetSong),		0x4D40D6);
extern BOOL (CArea::*CArea_CheckPointsAccessible)(POINT&, POINT&, TerrainTable&, BOOL, int) =
	SetFP(static_cast<BOOL (CArea::*)(POINT&, POINT&, TerrainTable&, BOOL, int)>	(&CArea::CheckPointsAccessible),	0x4B8F21);

char CArea::GetSong(short wType) { return (this->*CArea_GetSong)(wType); }
BOOL CArea::CheckPointsAccessible(POINT& pt1, POINT& pt2, TerrainTable& tt, BOOL bCheckVisibility, int nRadius) { return (this->*CArea_CheckPointsAccessible)(pt1, pt2, tt, bCheckVisibility, nRadius); }
