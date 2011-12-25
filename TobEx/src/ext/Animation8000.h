#ifndef ANIMATION8000_H
#define ANIMATION8000_H

#include "animext.h"

extern LPCTSTR (CAnimation8000::*Tramp_CAnimation8000_GetWalkingSound)(short);

class DETOUR_CAnimation8000 : public CAnimation8000 {
public:
	LPCTSTR DETOUR_GetWalkingSound(short wTerrainCode);
};

#endif //ANIMATION8000_H