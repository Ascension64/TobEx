#include "LuaCore.h"

#include "LuaCommon.h"
#include "LuaDump.h"

int (__stdcall *Tramp_IElua_init)() =
	reinterpret_cast<int (__stdcall *)()>	(0x5ADD86);

int __stdcall DETOUR_IElua_init() {
	int r = Tramp_IElua_init();
	g_TagObjects = IElua_createtag("TobExObject"); //init functions available for objects
	
	LUA_InitObjectTagMethods(g_TagObjects);
	LUADump_Init(); //init print() function outputs

	lua_pushcfunction(lua_beginblock);
	lua_setglobal("beginblock");
	
	lua_pushcfunction(lua_endblock);
	lua_setglobal("endblock");

	lua_pushcfunction(LUA_PushUserdata);
	lua_setglobal("pushuserdata");

	lua_pushcfunction(LUA_U2N);
	lua_setglobal("u2n");

	lua_pushcfunction(LUA_PushFunction);
	lua_setglobal("pushcfunction");

	lua_pushcfunction(LUA_CreateObject);
	lua_setglobal("createobject");
	
	lua_pushcfunction(LUA_GetSprite);
	lua_setglobal("getsprite");

	lua_dofile("TobEx_ini/TobEx.lua");
	return r;
}
