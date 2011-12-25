#include "engine.h"

#include "utils.h"

DWORD (CEngine::*CEngine_GetActivePlayerIdx)() =
	SetFP(static_cast<DWORD (CEngine::*)()>		(&CEngine::GetActivePlayerIdx),		0x43AD5C);

DWORD CEngine::GetActivePlayerIdx()	{ return (this->*CEngine_GetActivePlayerIdx)(); }