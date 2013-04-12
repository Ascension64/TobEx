#include "Animation9000.h"

DefineTrampMemberFunc(LPCTSTR, CAnimation9000, GetWalkingSound, (short wTerrainCode), GetWalkingSound, GetWalkingSound, 0x828F52);

LPCTSTR DETOUR_CAnimation9000::DETOUR_GetWalkingSound(short wTerrainCode) {
	return CAnimation::GetWalkingSound(wTerrainCode);
}
