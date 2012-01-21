#include "globals.h"

int (__cdecl *GetLongestAxialDistance)(POINT& pt1, POINT& pt2) =
	reinterpret_cast<int (__cdecl *)(POINT&, POINT&)>	(0x4318DF);
int (__cdecl *DieRoll)(int nDieSize, int nAdd) =
	reinterpret_cast<int (__cdecl *)(int, int)>			(0x99F330);
