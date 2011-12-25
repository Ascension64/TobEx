#include "Animation2000.h"

LPCTSTR (CAnimation2000::*Tramp_CAnimation2000_GetWalkingSound)(WORD) =
	SetFP(static_cast<LPCTSTR (CAnimation2000::*)(WORD)>	(&CAnimation2000::GetWalkingSound),				0x83EFBF);

LPCTSTR DETOUR_CAnimation2000::DETOUR_GetWalkingSound(WORD wTerrainCode) {
	return CAnimation::GetWalkingSound(wTerrainCode);
}