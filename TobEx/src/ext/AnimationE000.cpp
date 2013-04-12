#include "AnimationE000.h"

DefineTrampMemberFunc(LPCTSTR, CAnimationE000, GetWalkingSound, (short wTerrainCode), GetWalkingSound, GetWalkingSound, 0x82483B);

LPCTSTR DETOUR_CAnimationE000::DETOUR_GetWalkingSound(short wTerrainCode) {
	return CAnimation::GetWalkingSound(wTerrainCode);
}
