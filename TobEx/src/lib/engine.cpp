#include "engine.h"

#include "stdafx.h"

int (CEngine::*CEngine_GetActivePlayerIdx)() =
	SetFP(static_cast<int (CEngine::*)()>		(&CEngine::GetActivePlayerIdx),		0x43AD5C);

int CEngine::GetActivePlayerIdx()	{ return (this->*CEngine_GetActivePlayerIdx)(); }