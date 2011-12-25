#ifndef ANIMATION6400_H
#define ANIMATION6400_H

#include "animext.h"

extern LPCTSTR (CAnimation6400::*Tramp_CAnimation6400_GetWalkingSound)(WORD);

class DETOUR_CAnimation6400 : public CAnimation6400 {
public:
	LPCTSTR DETOUR_GetWalkingSound(WORD);
};

#endif //ANIMATION6400_H