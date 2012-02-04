#include "enginv.h"

void (CScreenInventory::*CScreenInventory_Init)() =
	SetFP(static_cast<void (CScreenInventory::*)()>	(&CScreenInventory::Init),	0x740178);

void CScreenInventory::Init() { return (this->*CScreenInventory_Init)(); }