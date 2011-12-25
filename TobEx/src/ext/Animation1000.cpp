#include "Animation1000.h"

LPCTSTR (CAnimation1000::*Tramp_CAnimation1000_GetWalkingSound)(WORD) =
	SetFP(static_cast<LPCTSTR (CAnimation1000::*)(WORD)>	(&CAnimation1000::GetWalkingSound),				0x8379B6);

LPCTSTR DETOUR_CAnimation1000::DETOUR_GetWalkingSound(WORD wTerrainCode) {
	return CAnimation::GetWalkingSound(wTerrainCode);
}
