#ifndef ANIMATION5000_H
#define ANIMATION5000_H

#include "animext.h"

DeclareTrampMemberFunc(CAnimation5000&, CAnimation5000, Construct, (unsigned short wAnimId, CreFileColors& colors, int nOrientation), Construct);
DeclareTrampMemberFunc(LPCTSTR, CAnimation5000, GetWalkingSound, (short wTerrainCode), GetWalkingSound);

class DETOUR_CAnimation5000 : public CAnimation5000 {
public:
	CAnimation5000& DETOUR_Construct(unsigned short wAnimId, CreFileColors& colors, int nOrientation);
	LPCTSTR DETOUR_GetWalkingSound(short wTerrainCode);
};

#endif //ANIMATION5000_H