#include "Animation2000.h"

DefineTrampMemberFunc(LPCTSTR, CAnimation2000, GetWalkingSound, (short wTerrainCode), GetWalkingSound, GetWalkingSound, 0x83EFBF);

LPCTSTR DETOUR_CAnimation2000::DETOUR_GetWalkingSound(short wTerrainCode) {
	return CAnimation::GetWalkingSound(wTerrainCode);
}