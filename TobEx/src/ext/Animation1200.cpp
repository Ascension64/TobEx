#include "Animation1200.h"

LPCTSTR (CAnimation1200::*Tramp_CAnimation1200_GetWalkingSound)(short) =
	SetFP(static_cast<LPCTSTR (CAnimation1200::*)(short)>	(&CAnimation1200::GetWalkingSound),				0x82FB9D);

LPCTSTR DETOUR_CAnimation1200::DETOUR_GetWalkingSound(short wTerrainCode) {
	return CAnimation::GetWalkingSound(wTerrainCode);
}