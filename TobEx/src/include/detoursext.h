#ifndef DETOURSEXT_H
#define DETOURSEXT_H

#include "utils.h"
#include "detours.h"

void ThisToStd(BYTE* target);

#define DetourFunction(target, detour) \
	DetourTransactionBegin(); \
	DetourAttach(&(PVOID&)target, (PVOID)detour); \
	DetourTransactionCommit();

#define DetourMemberFunction(target, detour) \
	DetourTransactionBegin(); \
	DetourAttach(&(PVOID&)target, (PVOID)(&(PVOID&)detour)); \
	DetourTransactionCommit();

void DetourMemberFunctionOld(PVOID* pTargetFunc, PVOID detourFunc, PVOID targetFunc);

#endif //DETOURSEXT_H