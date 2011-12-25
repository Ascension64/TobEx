#include "AnimationA000.h"

LPCTSTR (CAnimationA000::*Tramp_CAnimationA000_GetWalkingSound)(short) =
	SetFP(static_cast<LPCTSTR (CAnimationA000::*)(short)>	(&CAnimationA000::GetWalkingSound),				0x82B278);

LPCTSTR DETOUR_CAnimationA000::DETOUR_GetWalkingSound(short wTerrainCode) {
	return CAnimation::GetWalkingSound(wTerrainCode);
}
