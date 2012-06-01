#ifndef LUACOMMON_H
#define LUACOMMON_H

#include "stdafx.h"
#include "lua.h"

extern int g_TagObjects;

//general functions
void LUA_PushUserdata();
void LUA_U2N();
void LUA_PushFunction();
void LUA_GetSprite();

//TobExObject functions
void LUA_CreateObject();
void LUA_InitObjectTagMethods(int tag);
BOOL LUA_OpIndexGet(lua_Object var, lua_Object index);
BOOL LUA_OpIndexSet(lua_Object var, lua_Object index, lua_Object value);
void LUA_CDecl();
void LUA_StdCall();
void LUA_GetAddress();
void LUA_GetPointer();
void LUA_GetByte();
void LUA_GetWord();
void LUA_GetDword();
void LUA_GetString();
void LUA_GetList();
void LUA_Print();

#endif //LUACOMMON_H