#ifndef LUACORE_H
#define LUACORE_H

#include "lua.h"

//CLUAConsole
DeclareTrampMemberFunc(void, CLUAConsole, StartStore, (char* sz), StartStore);

class DETOUR_CLUAConsole : public CLUAConsole { //size 1h
public:
	void DETOUR_StartStore(char* sz);
};

//global
DeclareTrampGlobalFuncPtr(int, __stdcall, IElua_init, ());

int __stdcall DETOUR_IElua_init();

#endif //LUACORE_H