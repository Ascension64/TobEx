#ifndef ANIMATION1300_H
#define ANIMATION1300_H

#include "animext.h"

DeclareTrampMemberFunc(LPCTSTR, CAnimation1300, GetWalkingSound, (short wTerrainCode), GetWalkingSound);

class DETOUR_CAnimation1300 : public CAnimation1300 {
public:
	LPCTSTR DETOUR_GetWalkingSound(short wTerrainCode);
};

#endif //ANIMATION1000_H