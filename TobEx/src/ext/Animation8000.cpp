#include "Animation8000.h"

LPCTSTR (CAnimation8000::*Tramp_CAnimation8000_GetWalkingSound)(short) =
	SetFP(static_cast<LPCTSTR (CAnimation8000::*)(short)>	(&CAnimation8000::GetWalkingSound),				0x83BB22);

LPCTSTR DETOUR_CAnimation8000::DETOUR_GetWalkingSound(short wTerrainCode) {
	return CAnimation::GetWalkingSound(wTerrainCode);
}
