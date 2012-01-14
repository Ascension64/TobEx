#include "rescore.h"

//Res
void (Res::*Res_RemoveFromHandler)() =
	SetFP(static_cast<void (Res::*)()>		(&Res::RemoveFromHandler),	0x987FCD);
void (Res::*Res_AddToHandler)() =
	SetFP(static_cast<void (Res::*)()>		(&Res::AddToHandler),		0x98827D);

void Res::RemoveFromHandler()	{ return (this->*Res_RemoveFromHandler)(); }
void Res::AddToHandler()	{ return (this->*Res_AddToHandler)(); }

//ResItm
void* (ResItm::*ResItm_Demand)() =
	SetFP(static_cast<void* (ResItm::*)()>		(&ResItm::Demand),	0x40191C);
int (ResItm::*ResItm_Release)() =
	SetFP(static_cast<int (ResItm::*)()>		(&ResItm::Release),	0x401AFD);

void* ResItm::Demand()	{ return (this->*ResItm_Demand)(); }
int ResItm::Release()	{ return (this->*ResItm_Release)(); }

//CResHandler
void (CResHandler::*CResHandler_Free)(Res&) =
	SetFP(static_cast<void (CResHandler::*)(Res&)>	(&CResHandler::Free),	0x99555F);

void CResHandler::Free(Res& res)	{ return (this->*CResHandler_Free)(res); }
