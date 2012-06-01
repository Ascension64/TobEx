#ifndef LUACORE_H
#define LUACORE_H

extern int (__stdcall *Tramp_IElua_init)();

int __stdcall DETOUR_IElua_init();

#endif //LUACORE_H