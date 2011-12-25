#include "vidcore.h"

#include "utils.h"

void (VidPal::*VidPal_SetFxPaletteNo3d)(ARGB*, DWORD, DWORD, DWORD, BOOL) =
	SetFP(static_cast<void (VidPal::*)(ARGB*, DWORD, DWORD, DWORD, BOOL)>		(&VidPal::SetFxPaletteNo3d),	0x9F5897);

void VidPal::SetFxPaletteNo3d(ARGB* pPalette, DWORD nBitsPerPixel, DWORD dwFlags, DWORD dwAlpha, BOOL bIgnoreBrighten) { (this->*VidPal_SetFxPaletteNo3d)(pPalette, nBitsPerPixel, dwFlags, dwAlpha, bIgnoreBrighten); }