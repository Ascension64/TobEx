#ifndef INFBUTTONARRAY_H
#define INFBUTTONARRAY_H

#include "infbtarr.h"

struct DETOUR_CButtonArray : public CButtonArray {
	BOOL DETOUR_CheckButtonEnabled(int nIdx);
};

extern BOOL (CButtonArray::*Tramp_CButtonArray_CheckButtonEnabled)(int);

#endif //INFBUTTONARRAY_H