#ifndef ANIMATION8000_H
#define ANIMATION8000_H

#include "animext.h"

DeclareTrampMemberFunc(LPCTSTR, CAnimation8000, GetWalkingSound, (short wTerrainCode), GetWalkingSound);

class DETOUR_CAnimation8000 : public CAnimation8000 {
public:
	LPCTSTR DETOUR_GetWalkingSound(short wTerrainCode);
};

#endif //ANIMATION8000_H