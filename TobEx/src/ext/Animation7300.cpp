#include "Animation7300.h"

LPCTSTR (CAnimation7300::*Tramp_CAnimation7300_GetWalkingSound)(WORD) =
	SetFP(static_cast<LPCTSTR (CAnimation7300::*)(WORD)>	(&CAnimation7300::GetWalkingSound),				0x80F669);

LPCTSTR DETOUR_CAnimation7300::DETOUR_GetWalkingSound(WORD wTerrainCode) {
	return CAnimation::GetWalkingSound(wTerrainCode);
}
