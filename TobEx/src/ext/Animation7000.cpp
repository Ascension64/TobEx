#include "Animation7000.h"

LPCTSTR (CAnimation7000::*Tramp_CAnimation7000_GetWalkingSound)(short) =
	SetFP(static_cast<LPCTSTR (CAnimation7000::*)(short)>	(&CAnimation7000::GetWalkingSound),				0x81B0D7);

LPCTSTR DETOUR_CAnimation7000::DETOUR_GetWalkingSound(short wTerrainCode) {
	return CAnimation::GetWalkingSound(wTerrainCode);
}
