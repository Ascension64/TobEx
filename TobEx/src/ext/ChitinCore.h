#ifndef CHITINCORE_H
#define CHITINCORE_H

#include "chitin.h"

int __stdcall CBaldurChitin_MessageBox(HWND, LPCSTR, LPCSTR, UINT);

class DETOUR_CBaldurChitin : public CBaldurChitin {
public:
	CBaldurChitin& DETOUR_Construct();
};

#endif //CHITINCORE_H