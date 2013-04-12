//TobExEE
#ifndef LUACORE_H
#define LUACORE_H

#include "lua.h"

//global
DeclareTrampGlobalFuncPtr(int, __stdcall, IElua_init, ());

int __stdcall DETOUR_IElua_init();

#endif //LUACORE_H