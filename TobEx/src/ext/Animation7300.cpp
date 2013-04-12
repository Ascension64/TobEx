#include "Animation7300.h"

DefineTrampMemberFunc(LPCTSTR, CAnimation7300, GetWalkingSound, (short wTerrainCode), GetWalkingSound, GetWalkingSound, 0x80F669);

LPCTSTR DETOUR_CAnimation7300::DETOUR_GetWalkingSound(short wTerrainCode) {
	return CAnimation::GetWalkingSound(wTerrainCode);
}
