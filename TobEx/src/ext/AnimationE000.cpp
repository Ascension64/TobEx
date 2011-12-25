#include "AnimationE000.h"

LPCTSTR (CAnimationE000::*Tramp_CAnimationE000_GetWalkingSound)(short) =
	SetFP(static_cast<LPCTSTR (CAnimationE000::*)(short)>	(&CAnimationE000::GetWalkingSound),				0x82483B);

LPCTSTR DETOUR_CAnimationE000::DETOUR_GetWalkingSound(short wTerrainCode) {
	return CAnimation::GetWalkingSound(wTerrainCode);
}
