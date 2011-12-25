#ifndef VIDEOCORE_H
#define VIDEOCORE_H

#include "stdafx.h"
#include "vidcore.h"

extern void (VidPal::*Tramp_VidPal_SetFxPaletteNo3d)(ABGR*, int, unsigned int, int, BOOL);

struct DETOUR_VidPal : public VidPal {
	void DETOUR_SetFxPaletteNo3d(ABGR* pPalette, int nBitsPerPixel, unsigned int dwFlags, int dwAlpha, BOOL bIgnoreBrighten);
};

#endif VIDEOCORE_H