#ifndef ANIMATION1200_H
#define ANIMATION1200_H

#include "animext.h"

extern LPCTSTR (CAnimation1200::*Tramp_CAnimation1200_GetWalkingSound)(WORD);

class DETOUR_CAnimation1200 : public CAnimation1200 {
public:
	LPCTSTR DETOUR_GetWalkingSound(WORD);
};

#endif //ANIMATION1000_H