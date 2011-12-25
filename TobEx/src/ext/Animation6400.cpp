#include "Animation6400.h"

LPCTSTR (CAnimation6400::*Tramp_CAnimation6400_GetWalkingSound)(short) =
	SetFP(static_cast<LPCTSTR (CAnimation6400::*)(short)>	(&CAnimation6400::GetWalkingSound),				0x8703A8);

LPCTSTR DETOUR_CAnimation6400::DETOUR_GetWalkingSound(short wTerrainCode) {
	return CAnimation::GetWalkingSound(wTerrainCode);
}
