#include "globals.h"

int (__cdecl *DieRoll)(int nDieSize, int nAdd) =
	reinterpret_cast<int (__cdecl *)(int, int)>		(0x99F330);
