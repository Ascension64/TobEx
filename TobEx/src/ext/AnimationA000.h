#ifndef ANIMATIONA000_H
#define ANIMATIONA000_H

#include "animext.h"

extern LPCTSTR (CAnimationA000::*Tramp_CAnimationA000_GetWalkingSound)(WORD);

class DETOUR_CAnimationA000 : public CAnimationA000 {
public:
	LPCTSTR DETOUR_GetWalkingSound(WORD);
};

#endif //ANIMATIONA000_H