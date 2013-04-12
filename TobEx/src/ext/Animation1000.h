#ifndef ANIMATION1000_H
#define ANIMATION1000_H

#include "animext.h"

DeclareTrampMemberFunc(LPCTSTR, CAnimation1000, GetWalkingSound, (short wTerrainCode), GetWalkingSound);

class DETOUR_CAnimation1000 : public CAnimation1000 {
public:
	LPCTSTR DETOUR_GetWalkingSound(short wTerrainCode);
};

#endif //ANIMATION1000_H