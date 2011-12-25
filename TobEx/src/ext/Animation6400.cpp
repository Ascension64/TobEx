#include "Animation6400.h"

LPCTSTR (CAnimation6400::*Tramp_CAnimation6400_GetWalkingSound)(WORD) =
	SetFP(static_cast<LPCTSTR (CAnimation6400::*)(WORD)>	(&CAnimation6400::GetWalkingSound),				0x8703A8);

LPCTSTR DETOUR_CAnimation6400::DETOUR_GetWalkingSound(WORD wTerrainCode) {
	return CAnimation::GetWalkingSound(wTerrainCode);
}
