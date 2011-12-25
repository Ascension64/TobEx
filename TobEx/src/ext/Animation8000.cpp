#include "Animation8000.h"

LPCTSTR (CAnimation8000::*Tramp_CAnimation8000_GetWalkingSound)(WORD) =
	SetFP(static_cast<LPCTSTR (CAnimation8000::*)(WORD)>	(&CAnimation8000::GetWalkingSound),				0x83BB22);

LPCTSTR DETOUR_CAnimation8000::DETOUR_GetWalkingSound(WORD wTerrainCode) {
	return CAnimation::GetWalkingSound(wTerrainCode);
}
