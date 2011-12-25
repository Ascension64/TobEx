#include "enginv.h"

void (CInventory::*CInventory_Init)() =
	SetFP(static_cast<void (CInventory::*)()>	(&CInventory::Init),	0x740178);

void CInventory::Init() { return (this->*CInventory_Init)(); }