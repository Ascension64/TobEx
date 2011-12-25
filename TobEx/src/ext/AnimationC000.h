#ifndef ANIMATIONC000_H
#define ANIMATIONC000_H

#include "animext.h"

extern LPCTSTR (CAnimationC000::*Tramp_CAnimationC000_GetWalkingSound)(short);

class DETOUR_CAnimationC000 : public CAnimationC000 {
public:
	LPCTSTR DETOUR_GetWalkingSound(short wTerrainCode);
};

#endif //ANIMATIONC000_H