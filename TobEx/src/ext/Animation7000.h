#ifndef ANIMATION7000_H
#define ANIMATION7000_H

#include "animext.h"

DeclareTrampMemberFunc(LPCTSTR, CAnimation7000, GetWalkingSound, (short wTerrainCode), GetWalkingSound);

class DETOUR_CAnimation7000 : public CAnimation7000 {
public:
	LPCTSTR DETOUR_GetWalkingSound(short wTerrainCode);
};

#endif //ANIMATION7000_H