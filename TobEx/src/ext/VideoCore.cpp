#include "VideoCore.h"

#include "VideoCommon.h"
#include "vidcore.h"
#include "chitin.h"

void (VidPal::*Tramp_VidPal_SetFxPaletteNo3d)(ARGB*, DWORD, DWORD, DWORD, BOOL) =
	SetFP(static_cast<void (VidPal::*)(ARGB*, DWORD, DWORD, DWORD, BOOL)>		(&VidPal::SetFxPaletteNo3d),	0x9F5897);

void DETOUR_VidPal::DETOUR_SetFxPaletteNo3d(ARGB* pPalette, DWORD nBitsPerPixel, DWORD dwFlags, DWORD dwAlpha, BOOL bIgnoreBrighten) {
	(this->*Tramp_VidPal_SetFxPaletteNo3d)(pPalette, nBitsPerPixel, dwFlags, dwAlpha, bIgnoreBrighten);
	
	if (!g_pChitin->m_bDisableBrightest && (dwFlags & CVIDCELL_BRIGHTEST) && !bIgnoreBrighten) {
		switch (nBitsPerPixel) {
			case 16:
				for (int i = 1; i < 256; i++) {
					WORD color = *(WORD*)(pPalette + i);
					BYTE r, g, b;
					UnpackRGB565(color, r, g, b);
					if (r == 0, g == 255, b == 0) {
						*(WORD*)(pPalette + i) = PackRGB565(0, 0, 0);
					}
				}
				break;
			case 24:
			case 32:
				for (int i = 1; i < 256; i++) {
					ARGB color = *(pPalette + i);
					BYTE a, r, g, b;
					UnpackRGB8888(color, a, r, g, b);
					if (r == 0, g == 255, b == 0) {
						*(pPalette + i) = PackRGB8888(a, 0, 0, 0);
					}
				}
				break;
			default:
				break;
		}
	}

	return;
}