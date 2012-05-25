#ifndef LUADUMP_H
#define LUADUMP_H

#include "stdafx.h"

struct cmp_str {
	bool operator()(char const *a, char const *b) const {
		return std::strcmp(a, b) < 0;
	}
};
typedef IECString (*LUA_DumpFunc)(void*);
extern std::map<char*, LUA_DumpFunc, cmp_str> g_DumpFunctions;

void LUADump_Init();

IECString LUADump_notype(void* p);
IECString LUADump_action(void* p);
IECString LUADump_creature(void* p);
IECString LUADump_object(void* p);
IECString LUADump_string(void* p);

#endif //LUADUMP_H