//TobExEE
#include "lua.h"
#include "p_lua.h"

#include "stdafx.h"

//CLUAConsole
DefineLibMemberFunc(void, CLUAConsole, DisplayText, (IECString s), DisplayText, DisplayText, (s), CLUACONSOLE_DISPLAYTEXT);
DefineLibMemberFunc(void, CLUAConsole, StartStore, (char* sz), StartStore, StartStore, (sz), CLUACONSOLE_STARTSTORE);

//Lua 3.0
lua_Object lua_gettagmethod(int tag, char* event)
{
  lua_pushnumber(tag);
  lua_pushstring(event);
  do_unprotectedrun(luaI_gettagmethod, 2, 1);
  return put_luaObjectonTop();
}
