#include "Animation1300.h"

DefineTrampMemberFunc(LPCTSTR, CAnimation1300, GetWalkingSound, (short wTerrainCode), GetWalkingSound, GetWalkingSound, 0x875655);

LPCTSTR DETOUR_CAnimation1300::DETOUR_GetWalkingSound(short wTerrainCode) {
	return CAnimation::GetWalkingSound(wTerrainCode);
}