#ifndef CHITINCORE_H
#define CHITINCORE_H

#include "chitin.h"

extern CBaldurChitin& (CBaldurChitin::*Tramp_CBaldurChitin_Construct0)(void);

int __stdcall CBaldurChitin_MessageBox(HWND, LPCSTR, LPCSTR, UINT);

class DETOUR_CBaldurChitin : public CBaldurChitin {
public:
	CBaldurChitin& DETOUR_Construct();
};

#endif //CHITINCORE_H