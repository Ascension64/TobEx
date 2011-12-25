#include "AnimationC000.h"

LPCTSTR (CAnimationC000::*Tramp_CAnimationC000_GetWalkingSound)(WORD) =
	SetFP(static_cast<LPCTSTR (CAnimationC000::*)(WORD)>	(&CAnimationC000::GetWalkingSound),				0x805F7E);

LPCTSTR DETOUR_CAnimationC000::DETOUR_GetWalkingSound(WORD wTerrainCode) {
	return CAnimation::GetWalkingSound(wTerrainCode);
}
