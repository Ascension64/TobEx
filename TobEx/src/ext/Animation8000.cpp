#include "Animation8000.h"

DefineTrampMemberFunc(LPCTSTR, CAnimation8000, GetWalkingSound, (short wTerrainCode), GetWalkingSound, GetWalkingSound, 0x83BB22);

LPCTSTR DETOUR_CAnimation8000::DETOUR_GetWalkingSound(short wTerrainCode) {
	return CAnimation::GetWalkingSound(wTerrainCode);
}
