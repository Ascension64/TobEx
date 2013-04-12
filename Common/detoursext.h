#ifndef DETOURSEXT_H
#define DETOURSEXT_H

#include "detours.h"

#define DetourFunction(target, detour) DetourAttach(&(PVOID&)target, (PVOID)detour);
#define DetourMemberFunction(target, detour) DetourAttach(&(PVOID&)target, (PVOID)(&(PVOID&)detour));

#endif //DETOURSEXT_H