#ifndef ANIMATIONC000_H
#define ANIMATIONC000_H

#include "animext.h"

extern LPCTSTR (CAnimationC000::*Tramp_CAnimationC000_GetWalkingSound)(WORD);

class DETOUR_CAnimationC000 : public CAnimationC000 {
public:
	LPCTSTR DETOUR_GetWalkingSound(WORD);
};

#endif //ANIMATIONC000_H