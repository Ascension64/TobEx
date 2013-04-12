#ifndef ANIMATIONA000_H
#define ANIMATIONA000_H

#include "animext.h"

DeclareTrampMemberFunc(LPCTSTR, CAnimationA000, GetWalkingSound, (short wTerrainCode), GetWalkingSound);

class DETOUR_CAnimationA000 : public CAnimationA000 {
public:
	LPCTSTR DETOUR_GetWalkingSound(short wTerrainCode);
};

#endif //ANIMATIONA000_H