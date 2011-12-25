#ifndef ANIMATION9000_H
#define ANIMATION9000_H

#include "animext.h"

extern LPCTSTR (CAnimation9000::*Tramp_CAnimation9000_GetWalkingSound)(WORD);

class DETOUR_CAnimation9000 : public CAnimation9000 {
public:
	LPCTSTR DETOUR_GetWalkingSound(WORD);
};

#endif //ANIMATION9000_H