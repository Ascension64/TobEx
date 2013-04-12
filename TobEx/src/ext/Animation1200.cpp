#include "Animation1200.h"

DefineTrampMemberFunc(LPCTSTR, CAnimation1200, GetWalkingSound, (short wTerrainCode), GetWalkingSound, GetWalkingSound, 0x82FB9D);

LPCTSTR DETOUR_CAnimation1200::DETOUR_GetWalkingSound(short wTerrainCode) {
	return CAnimation::GetWalkingSound(wTerrainCode);
}