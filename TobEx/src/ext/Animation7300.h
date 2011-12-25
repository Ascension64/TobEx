#ifndef ANIMATION7300_H
#define ANIMATION7300_H

#include "animext.h"

extern LPCTSTR (CAnimation7300::*Tramp_CAnimation7300_GetWalkingSound)(WORD);

class DETOUR_CAnimation7300 : public CAnimation7300 {
public:
	LPCTSTR DETOUR_GetWalkingSound(WORD);
};

#endif //ANIMATION7300_H