#ifndef ANIMATION2000_H
#define ANIMATION2000_H

#include "animext.h"

extern LPCTSTR (CAnimation2000::*Tramp_CAnimation2000_GetWalkingSound)(WORD);

class DETOUR_CAnimation2000 : public CAnimation2000 {
public:
	LPCTSTR DETOUR_GetWalkingSound(WORD);
};

#endif //ANIMATION2000_H