#ifndef ANIMATION7000_H
#define ANIMATION7000_H

#include "animext.h"

extern LPCTSTR (CAnimation7000::*Tramp_CAnimation7000_GetWalkingSound)(short);

class DETOUR_CAnimation7000 : public CAnimation7000 {
public:
	LPCTSTR DETOUR_GetWalkingSound(short wTerrainCode);
};

#endif //ANIMATION7000_H