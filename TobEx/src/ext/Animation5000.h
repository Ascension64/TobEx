#ifndef ANIMATION5000_H
#define ANIMATION5000_H

#include "animext.h"

extern CAnimation5000& (CAnimation5000::*Tramp_CAnimation5000_Construct)(WORD, ColorRangeValues&, DWORD);
extern LPCTSTR (CAnimation5000::*Tramp_CAnimation5000_GetWalkingSound)(WORD);

class DETOUR_CAnimation5000 : public CAnimation5000 {
public:
	CAnimation5000& DETOUR_Construct(WORD, ColorRangeValues&, DWORD);
	LPCTSTR DETOUR_GetWalkingSound(WORD);
};

#endif //ANIMATION5000_H