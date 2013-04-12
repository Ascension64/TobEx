#include "AnimationC000.h"

DefineTrampMemberFunc(LPCTSTR, CAnimationC000, GetWalkingSound, (short wTerrainCode), GetWalkingSound, GetWalkingSound, 0x805F7E);

LPCTSTR DETOUR_CAnimationC000::DETOUR_GetWalkingSound(short wTerrainCode) {
	return CAnimation::GetWalkingSound(wTerrainCode);
}
