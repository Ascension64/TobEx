#ifndef ANIMATIONE000_H
#define ANIMATIONE000_H

#include "animext.h"

DeclareTrampMemberFunc(LPCTSTR, CAnimationE000, GetWalkingSound, (short wTerrainCode), GetWalkingSound);

class DETOUR_CAnimationE000 : public CAnimationE000 {
public:
	LPCTSTR DETOUR_GetWalkingSound(short wTerrainCode);
};

#endif //ANIMATIONE000_H