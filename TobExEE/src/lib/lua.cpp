//TobExEE
#include "lua.h"
#include "p_lua.h"

#include "stdafx.h"
#include "chitin.h"

//CLUAConsole
DefineLibMemberFunc(void, CLUAConsole, DisplayText, (IECString s), DisplayText, DisplayText, (s), CLUACONSOLE_DISPLAYTEXT);

//IELua
void IElua_GetBaldurChitin() {
	return IElua_pushuserdata(g_pChitin, g_IETagCBaldurChitin);
}

void* __cdecl IElua_getuserdata(lua_Object o) {
	if (lua_isnil(o)) return NULL;
	return lua_getuserdata(o);
}

//Lua 3.0
lua_Object lua_gettagmethod(int tag, char* event)
{
  lua_pushnumber(tag);
  lua_pushstring(event);
  do_unprotectedrun(luaI_gettagmethod, 2, 1);
  return put_luaObjectonTop();
}
