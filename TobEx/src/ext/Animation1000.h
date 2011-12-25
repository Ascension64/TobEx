#ifndef ANIMATION1000_H
#define ANIMATION1000_H

#include "animext.h"

extern LPCTSTR (CAnimation1000::*Tramp_CAnimation1000_GetWalkingSound)(WORD);

class DETOUR_CAnimation1000 : public CAnimation1000 {
public:
	LPCTSTR DETOUR_GetWalkingSound(WORD);
};

#endif //ANIMATION1000_H