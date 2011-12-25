#include "Animation9000.h"

LPCTSTR (CAnimation9000::*Tramp_CAnimation9000_GetWalkingSound)(short) =
	SetFP(static_cast<LPCTSTR (CAnimation9000::*)(short)>	(&CAnimation9000::GetWalkingSound),				0x828F52);

LPCTSTR DETOUR_CAnimation9000::DETOUR_GetWalkingSound(short wTerrainCode) {
	return CAnimation::GetWalkingSound(wTerrainCode);
}
