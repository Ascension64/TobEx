#ifndef ANIMATION9000_H
#define ANIMATION9000_H

#include "animext.h"

DeclareTrampMemberFunc(LPCTSTR, CAnimation9000, GetWalkingSound, (short wTerrainCode), GetWalkingSound);

class DETOUR_CAnimation9000 : public CAnimation9000 {
public:
	LPCTSTR DETOUR_GetWalkingSound(short wTerrainCode);
};

#endif //ANIMATION9000_H