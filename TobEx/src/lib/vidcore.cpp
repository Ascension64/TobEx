#include "vidcore.h"

#include "stdafx.h"

DefineLibMemberFunc(void, VidPal, SetFxPaletteNo3d, (
	ABGR* pPalette,
	int nBitsPerPixel,
	unsigned int dwFlags,
	int dwAlpha,
	BOOL bIgnoreBrighten
	), SetFxPaletteNo3d, SetFxPaletteNo3d, (pPalette, nBitsPerPixel, dwFlags, dwAlpha, bIgnoreBrighten), 0x9F5897);
