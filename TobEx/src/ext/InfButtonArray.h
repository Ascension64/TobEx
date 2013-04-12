#ifndef INFBUTTONARRAY_H
#define INFBUTTONARRAY_H

#include "infbtarr.h"

DeclareTrampMemberFunc(BOOL, CButtonArray, CheckButtonEnabled, (int nIdx), CheckButtonEnabled);

struct DETOUR_CButtonArray : public CButtonArray {
	BOOL DETOUR_CheckButtonEnabled(int nIdx);
};

#endif //INFBUTTONARRAY_H