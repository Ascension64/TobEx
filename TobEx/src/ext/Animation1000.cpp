#include "Animation1000.h"

DefineTrampMemberFunc(LPCTSTR, CAnimation1000, GetWalkingSound, (short wTerrainCode), GetWalkingSound, GetWalkingSound, 0x8379B6);

LPCTSTR DETOUR_CAnimation1000::DETOUR_GetWalkingSound(short wTerrainCode) {
	return CAnimation::GetWalkingSound(wTerrainCode);
}
