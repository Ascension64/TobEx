#ifndef LUACOMMON_H
#define LUACOMMON_H

#include "stdafx.h"
#include "lua.h"

static int g_TagObjects;

void __stdcall LUA_Init();

void LUA_PushUserdata();
void LUA_PushFunction();
void LUA_CreateObject();
void LUA_DeleteObject();
void LUA_InitObjectTagMethods(int tag);
void LUA_GetPointer();
void LUA_GetByte();
void LUA_GetWord();
void LUA_GetDword();
void LUA_GetString();
void LUA_GetList();
void LUA_Print();
void LUA_GetCurrentArea();
void LUA_GetCurrentCreature();

#endif //LUACOMMON_H