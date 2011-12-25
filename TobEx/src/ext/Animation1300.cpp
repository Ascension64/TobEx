#include "Animation1300.h"

LPCTSTR (CAnimation1300::*Tramp_CAnimation1300_GetWalkingSound)(WORD) =
	SetFP(static_cast<LPCTSTR (CAnimation1300::*)(WORD)>	(&CAnimation1300::GetWalkingSound),				0x875655);

LPCTSTR DETOUR_CAnimation1300::DETOUR_GetWalkingSound(WORD wTerrainCode) {
	return CAnimation::GetWalkingSound(wTerrainCode);
}