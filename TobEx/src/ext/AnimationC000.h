#ifndef ANIMATIONC000_H
#define ANIMATIONC000_H

#include "animext.h"

DeclareTrampMemberFunc(LPCTSTR, CAnimationC000, GetWalkingSound, (short wTerrainCode), GetWalkingSound);

class DETOUR_CAnimationC000 : public CAnimationC000 {
public:
	LPCTSTR DETOUR_GetWalkingSound(short wTerrainCode);
};

#endif //ANIMATIONC000_H