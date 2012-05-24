#ifndef LUACOMMON_H
#define LUACOMMON_H

#include "stdafx.h"
#include "lua.h"
#include <map>

struct cmp_str {
	bool operator()(char const *a, char const *b) const {
		return std::strcmp(a, b) < 0;
	}
};
typedef IECString (*LUA_DumpFunc)(void*);
static std::map<char*, LUA_DumpFunc, cmp_str> g_DumpFunctions;

IECString LUADump_notype(void* p);
IECString LUADump_action(void* p);
IECString LUADump_creature(void* p);

void __stdcall LUA_InitExt();

void LUA_PushUserdata();
void LUA_PushFunction();
void LUA_CreateObject();
void LUA_InitObjectTagMethods(int tag);
void LUA_GetUserdata();
void LUA_GetByte();
void LUA_GetWord();
void LUA_GetDword();
void LUA_GetTable();
void LUA_Print();
void LUA_GetCurrentArea();
void LUA_GetCurrentCreature();

#endif //LUACOMMON_H