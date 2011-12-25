#ifndef ANIMATION6400_H
#define ANIMATION6400_H

#include "animext.h"

extern LPCTSTR (CAnimation6400::*Tramp_CAnimation6400_GetWalkingSound)(short);

class DETOUR_CAnimation6400 : public CAnimation6400 {
public:
	LPCTSTR DETOUR_GetWalkingSound(short wTerrainCode);
};

#endif //ANIMATION6400_H