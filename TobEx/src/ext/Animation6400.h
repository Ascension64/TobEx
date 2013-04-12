#ifndef ANIMATION6400_H
#define ANIMATION6400_H

#include "animext.h"

DeclareTrampMemberFunc(LPCTSTR, CAnimation6400, GetWalkingSound, (short wTerrainCode), GetWalkingSound);

class DETOUR_CAnimation6400 : public CAnimation6400 {
public:
	LPCTSTR DETOUR_GetWalkingSound(short wTerrainCode);
};

#endif //ANIMATION6400_H