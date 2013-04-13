//TobExEE
#include "LuaCore.h"
#include "p_lua.h"

#include "chitin.h"

#include "LuaCommon.h"
#include "LuaDump.h"

//global
DefineTrampGlobalFuncPtr(int, __stdcall, IElua_init, (), IELUA_INIT);

int __stdcall DETOUR_IElua_init() {
	int r = Tramp_IElua_init();

	//this was removed by BG:EE
	lua_pushcfunction(IElua_GetBaldurChitin);
	lua_setglobal("GetBaldurChitin");

	g_TagObjects = IElua_createtag("TobExObject"); //init functions available for objects
	
	LUA_InitObjectTagMethods(g_TagObjects);
	LUADump_Init(); //init print() function outputs

	lua_pushcfunction(lua_beginblock);
	lua_setglobal("beginblock");
	
	lua_pushcfunction(lua_endblock);
	lua_setglobal("endblock");

	lua_pushcfunction(LUA_Pow);
	lua_setglobal("pow");

	lua_pushcfunction(LUA_Mod);
	lua_setglobal("mod");
	
	lua_pushcfunction(LUA_BAnd);
	lua_setglobal("band");

	lua_pushcfunction(LUA_BOr);
	lua_setglobal("bor");

	lua_pushcfunction(LUA_Dec2Hex);
	lua_setglobal("dec2hex");

	lua_pushcfunction(LUA_Hex2Dec);
	lua_setglobal("hex2dec");

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
