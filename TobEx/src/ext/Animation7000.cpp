#include "Animation7000.h"

DefineTrampMemberFunc(LPCTSTR, CAnimation7000, GetWalkingSound, (short wTerrainCode), GetWalkingSound, GetWalkingSound, 0x81B0D7);

LPCTSTR DETOUR_CAnimation7000::DETOUR_GetWalkingSound(short wTerrainCode) {
	return CAnimation::GetWalkingSound(wTerrainCode);
}
