#include "vidcore.h"

#include "stdafx.h"

const ARGB* g_pColorRangeArray = (const ARGB*)0xAB9B78;
const ARGB g_ColorDefaultText = 0xBED7D7;

void (VidPal::*VidPal_SetFxPaletteNo3d)(ARGB*, int, unsigned int, int, BOOL) =
	SetFP(static_cast<void (VidPal::*)(ARGB*, int, unsigned int, int, BOOL)>	(&VidPal::SetFxPaletteNo3d),	0x9F5897);

void VidPal::SetFxPaletteNo3d(ARGB* pPalette, int nBitsPerPixel, unsigned int dwFlags, int dwAlpha, BOOL bIgnoreBrighten) {
	(this->*VidPal_SetFxPaletteNo3d)(pPalette, nBitsPerPixel, dwFlags, dwAlpha, bIgnoreBrighten);
}