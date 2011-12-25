#include "vidcore.h"

#include "stdafx.h"

const ABGR* g_pColorRangeArray = (const ABGR*)0xAB9B78;
const ABGR g_ColorDefaultText = 0xBED7D7;

void (VidPal::*VidPal_SetFxPaletteNo3d)(ABGR*, int, unsigned int, int, BOOL) =
	SetFP(static_cast<void (VidPal::*)(ABGR*, int, unsigned int, int, BOOL)>	(&VidPal::SetFxPaletteNo3d),	0x9F5897);

void VidPal::SetFxPaletteNo3d(ABGR* pPalette, int nBitsPerPixel, unsigned int dwFlags, int dwAlpha, BOOL bIgnoreBrighten) {
	(this->*VidPal_SetFxPaletteNo3d)(pPalette, nBitsPerPixel, dwFlags, dwAlpha, bIgnoreBrighten);
}