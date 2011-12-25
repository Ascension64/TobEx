#include "rescore.h"

//ResItm
void* (ResItm::*ResItm_Demand)() =
	SetFP(static_cast<void* (ResItm::*)()>		(&ResItm::Demand),	0x40191C);
int (ResItm::*ResItm_Release)() =
	SetFP(static_cast<int (ResItm::*)()>		(&ResItm::Release),	0x401AFD);

void* ResItm::Demand()	{ return (this->*ResItm_Demand)(); }
int ResItm::Release()	{ return (this->*ResItm_Release)(); }