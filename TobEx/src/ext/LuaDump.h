#ifndef LUADUMP_H
#define LUADUMP_H

#include "stdafx.h"

struct cmp_str {
	bool operator()(char const *a, char const *b) const { return std::strcmp(a, b) < 0;	}
};
typedef IECString (*LUA_DumpFunc)(void*);
extern std::map<char*, LUA_DumpFunc, cmp_str> g_DumpFunctions;

void LUADump_Init();

IECString LUADump_notype(void* p);
IECString LUADump_action(void* p);
IECString LUADump_object(void* p);
IECString LUADump_sprite(void* p);
IECString LUADump_sprite(void* p);
IECString LUADump_sprite_area(void* p);
IECString LUADump_sprite_baldur(void* p);
IECString LUADump_sprite_container(void* p);
IECString LUADump_sprite_creature(void* p);
IECString LUADump_sprite_door(void* p);
IECString LUADump_sprite_projectile(void* p);
IECString LUADump_sprite_sound(void* p);
IECString LUADump_sprite_spawn(void* p);
IECString LUADump_sprite_static(void* p);
IECString LUADump_sprite_tile(void* p);
IECString LUADump_sprite_trigger(void* p);
IECString LUADump_trigger(void* p);

#endif //LUADUMP_H