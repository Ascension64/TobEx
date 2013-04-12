#ifndef ANIMATION1200_H
#define ANIMATION1200_H

#include "animext.h"

DeclareTrampMemberFunc(LPCTSTR, CAnimation1200, GetWalkingSound, (short wTerrainCode), GetWalkingSound);

class DETOUR_CAnimation1200 : public CAnimation1200 {
public:
	LPCTSTR DETOUR_GetWalkingSound(short wTerrainCode);
};

#endif //ANIMATION1000_H