#ifndef ANIMATION5000_H
#define ANIMATION5000_H

#include "animext.h"

extern CAnimation5000& (CAnimation5000::*Tramp_CAnimation5000_Construct)(unsigned short, ColorRangeValues&, int);
extern LPCTSTR (CAnimation5000::*Tramp_CAnimation5000_GetWalkingSound)(short);

class DETOUR_CAnimation5000 : public CAnimation5000 {
public:
	CAnimation5000& DETOUR_Construct(unsigned short wAnimId, ColorRangeValues& colors, int nOrientation);
	LPCTSTR DETOUR_GetWalkingSound(short wTerrainCode);
};

#endif //ANIMATION5000_H