#include "infbtarr.h"

BOOL (CButtonArray::*CButtonArray_CheckButtonEnabled)(int) =
	SetFP(static_cast<BOOL (CButtonArray::*)(int)>	(&CButtonArray::CheckButtonEnabled),	0x671C9E);

BOOL CButtonArray::CheckButtonEnabled(int nIdx) { return (this->*CButtonArray_CheckButtonEnabled)(nIdx); }

