#include "Animation6400.h"

DefineTrampMemberFunc(LPCTSTR, CAnimation6400, GetWalkingSound, (short wTerrainCode), GetWalkingSound, GetWalkingSound, 0x8703A8);

LPCTSTR DETOUR_CAnimation6400::DETOUR_GetWalkingSound(short wTerrainCode) {
	return CAnimation::GetWalkingSound(wTerrainCode);
}
