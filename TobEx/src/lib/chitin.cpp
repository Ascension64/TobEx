#include "chitin.h"

#include "stdafx.h"

CBaldurChitin* g_pChitin;

CBaldurChitin& (CBaldurChitin::*CBaldurChitin_Construct)() =
	SetFP(static_cast<CBaldurChitin& (CBaldurChitin::*)()>		(&CBaldurChitin::Construct),	0x432108);

CBaldurChitin::CBaldurChitin() { (this->*CBaldurChitin_Construct)(); }