#ifndef DETOURSEXT_H
#define DETOURSEXT_H

#include "stdafx.h"
#include "detours.h"

#define DetourFunction(target, detour) \
	DetourTransactionBegin(); \
	DetourAttach(&(PVOID&)target, (PVOID)detour); \
	DetourTransactionCommit();

#define DetourMemberFunction(target, detour) \
	DetourTransactionBegin(); \
	DetourAttach(&(PVOID&)target, (PVOID)(&(PVOID&)detour)); \
	DetourTransactionCommit();

void ThisToStd(BYTE* target);
void DetourMemberFunctionOld(PVOID* pTargetFunc, PVOID detourFunc, PVOID targetFunc);

#endif //DETOURSEXT_H