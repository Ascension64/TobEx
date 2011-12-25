#include "VideoCore.h"

#include "VideoCommon.h"
#include "vidcore.h"
#include "chitin.h"

void (VidPal::*Tramp_VidPal_SetFxPaletteNo3d)(ABGR*, int, unsigned int, int, BOOL) =
	SetFP(static_cast<void (VidPal::*)(ABGR*, int, unsigned int, int, BOOL)>	(&VidPal::SetFxPaletteNo3d),	0x9F5897);

void DETOUR_VidPal::DETOUR_SetFxPaletteNo3d(ABGR* pPalette, int nBitsPerPixel, unsigned int dwFlags, int dwAlpha, BOOL bIgnoreBrighten) {
	(this->*Tramp_VidPal_SetFxPaletteNo3d)(pPalette, nBitsPerPixel, dwFlags, dwAlpha, bIgnoreBrighten);
	unsigned char a, b, g, r;
	
	if (!g_pChitin->m_bDisableBrightest && (dwFlags & CVIDCELL_BRIGHTEST) && !bIgnoreBrighten) {
		switch (nBitsPerPixel) {
			case 16:
				for (int i = 1; i < 256; i++) {
					short color = *(short*)(pPalette + i);
					UnpackRGB565(color, r, g, b);
					if (r == 0, g == 255, b == 0) {
						*(short*)(pPalette + i) = PackRGB565(0, 0, 0);
					}
				}
				break;
			case 24:
			case 32:
				for (int i = 1; i < 256; i++) {
					ABGR color = *(pPalette + i);
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