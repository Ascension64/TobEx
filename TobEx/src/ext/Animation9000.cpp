#include "Animation9000.h"

LPCTSTR (CAnimation9000::*Tramp_CAnimation9000_GetWalkingSound)(WORD) =
	SetFP(static_cast<LPCTSTR (CAnimation9000::*)(WORD)>	(&CAnimation9000::GetWalkingSound),				0x828F52);

LPCTSTR DETOUR_CAnimation9000::DETOUR_GetWalkingSound(WORD wTerrainCode) {
	return CAnimation::GetWalkingSound(wTerrainCode);
}
