#ifndef ANIMATION2000_H
#define ANIMATION2000_H

#include "animext.h"

DeclareTrampMemberFunc(LPCTSTR, CAnimation2000, GetWalkingSound, (short wTerrainCode), GetWalkingSound);

class DETOUR_CAnimation2000 : public CAnimation2000 {
public:
	LPCTSTR DETOUR_GetWalkingSound(short wTerrainCode);
};

#endif //ANIMATION2000_H