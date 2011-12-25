#ifndef ANIMATION1300_H
#define ANIMATION1300_H

#include "animext.h"

extern LPCTSTR (CAnimation1300::*Tramp_CAnimation1300_GetWalkingSound)(short);

class DETOUR_CAnimation1300 : public CAnimation1300 {
public:
	LPCTSTR DETOUR_GetWalkingSound(short wTerrainCode);
};

#endif //ANIMATION1000_H