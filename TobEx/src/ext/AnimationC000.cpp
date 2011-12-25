#include "AnimationC000.h"

LPCTSTR (CAnimationC000::*Tramp_CAnimationC000_GetWalkingSound)(short) =
	SetFP(static_cast<LPCTSTR (CAnimationC000::*)(short)>	(&CAnimationC000::GetWalkingSound),				0x805F7E);

LPCTSTR DETOUR_CAnimationC000::DETOUR_GetWalkingSound(short wTerrainCode) {
	return CAnimation::GetWalkingSound(wTerrainCode);
}
