#ifndef VIDEOCORE_H
#define VIDEOCORE_H

#include "utils.h"
#include "vidcore.h"

extern void (VidPal::*Tramp_VidPal_SetFxPaletteNo3d)(ARGB*, DWORD, DWORD, DWORD, BOOL);

struct DETOUR_VidPal : public VidPal {
	void DETOUR_SetFxPaletteNo3d(ARGB*, DWORD, DWORD, DWORD, BOOL);
};

#endif VIDEOCORE_H