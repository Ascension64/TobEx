#include "chitin.h"

#include "utils.h"

CBaldurChitin* g_pChitin;

CBaldurChitin& (CBaldurChitin::*CBaldurChitin_Construct0)(void) =
	SetFP(static_cast<CBaldurChitin& (CBaldurChitin::*)(void)>		(&CBaldurChitin::Construct),	0x432108);

CBaldurChitin::CBaldurChitin() { (this->*CBaldurChitin_Construct0)(); }