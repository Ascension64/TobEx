#ifndef LUACORE_H
#define LUACORE_H

#include "lua.h"

extern void (CLUAConsole::*Tramp_CLUAConsole_StartStore)(char*);

class DETOUR_CLUAConsole : public CLUAConsole { //size 1h
public:
	void DETOUR_StartStore(char* sz);
};

extern int (__stdcall *Tramp_IElua_init)();

int __stdcall DETOUR_IElua_init();

#endif //LUACORE_H