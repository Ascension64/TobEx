#include "AnimationA000.h"

DefineTrampMemberFunc(LPCTSTR, CAnimationA000, GetWalkingSound, (short wTerrainCode), GetWalkingSound, GetWalkingSound, 0x82B278);

LPCTSTR DETOUR_CAnimationA000::DETOUR_GetWalkingSound(short wTerrainCode) {
	return CAnimation::GetWalkingSound(wTerrainCode);
}
