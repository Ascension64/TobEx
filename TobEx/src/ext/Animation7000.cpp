#include "Animation7000.h"

LPCTSTR (CAnimation7000::*Tramp_CAnimation7000_GetWalkingSound)(WORD) =
	SetFP(static_cast<LPCTSTR (CAnimation7000::*)(WORD)>	(&CAnimation7000::GetWalkingSound),				0x81B0D7);

LPCTSTR DETOUR_CAnimation7000::DETOUR_GetWalkingSound(WORD wTerrainCode) {
	return CAnimation::GetWalkingSound(wTerrainCode);
}
