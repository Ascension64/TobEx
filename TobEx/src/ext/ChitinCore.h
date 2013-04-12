#ifndef CHITINCORE_H
#define CHITINCORE_H

#include "chitin.h"

DeclareTrampMemberFunc(CBaldurChitin&, CBaldurChitin, Construct, (), Construct);

int __stdcall CBaldurChitin_MessageBox(HWND hWnd, LPCSTR lpText, LPCSTR lpCaption, UINT uType);

class DETOUR_CBaldurChitin : public CBaldurChitin {
public:
	CBaldurChitin& DETOUR_Construct();
};

#endif //CHITINCORE_H