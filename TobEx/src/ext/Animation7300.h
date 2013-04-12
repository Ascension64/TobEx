#ifndef ANIMATION7300_H
#define ANIMATION7300_H

#include "animext.h"

DeclareTrampMemberFunc(LPCTSTR, CAnimation7300, GetWalkingSound, (short wTerrainCode), GetWalkingSound);

class DETOUR_CAnimation7300 : public CAnimation7300 {
public:
	LPCTSTR DETOUR_GetWalkingSound(short wTerrainCode);
};

#endif //ANIMATION7300_H