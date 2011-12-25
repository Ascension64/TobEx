#include "Animation2000.h"

LPCTSTR (CAnimation2000::*Tramp_CAnimation2000_GetWalkingSound)(short) =
	SetFP(static_cast<LPCTSTR (CAnimation2000::*)(short)>	(&CAnimation2000::GetWalkingSound),				0x83EFBF);

LPCTSTR DETOUR_CAnimation2000::DETOUR_GetWalkingSound(short wTerrainCode) {
	return CAnimation::GetWalkingSound(wTerrainCode);
}