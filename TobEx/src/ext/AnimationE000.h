#ifndef ANIMATIONE000_H
#define ANIMATIONE000_H

#include "animext.h"

extern LPCTSTR (CAnimationE000::*Tramp_CAnimationE000_GetWalkingSound)(short);

class DETOUR_CAnimationE000 : public CAnimationE000 {
public:
	LPCTSTR DETOUR_GetWalkingSound(short wTerrainCode);
};

#endif //ANIMATIONE000_H