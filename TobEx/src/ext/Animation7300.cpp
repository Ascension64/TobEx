#include "Animation7300.h"

LPCTSTR (CAnimation7300::*Tramp_CAnimation7300_GetWalkingSound)(short) =
	SetFP(static_cast<LPCTSTR (CAnimation7300::*)(short)>	(&CAnimation7300::GetWalkingSound),				0x80F669);

LPCTSTR DETOUR_CAnimation7300::DETOUR_GetWalkingSound(short wTerrainCode) {
	return CAnimation::GetWalkingSound(wTerrainCode);
}
