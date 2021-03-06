//TobExEE
#ifndef LUA_H
#define LUA_H

#include "stdafx.h"
#include "p_lua.h"

//Lua 3.0 typedefs
typedef unsigned int lua_Object;
typedef float real;
typedef void (*lua_CFunction) (void);

//IELua typedefs
typedef int IETag;

//IELua globals
static const IETag& g_IETagNumber = (const IETag&)(*(IETag*)G_IETAGNUMBER);
static const IETag& g_IETagString = (const IETag&)(*(IETag*)G_IETAGSTRING);
static const IETag& g_IETagUserdata = (const IETag&)(*(IETag*)G_IETAGUSERDATA);
static const IETag& g_IETagCBaldurChitin = (const IETag&)(*(IETag*)G_IETAGCBALDURCHITIN);

//CLUA functions
class CLUAConsole { //size 1h
public:
	void DisplayText(IECString s);
	void StartStore(char* sz);
protected:
	char u0;
};

//IELua functions
DefineGlobalFuncPtr(int, __stdcall, IElua_init, (), IELUA_INIT);
DefineGlobalFuncPtr(int, __stdcall, IElua_deinit, (), IELUA_DEINIT);
void IElua_GetBaldurChitin(); //re-implemented

/*error_badself
-prints an error message that the function funcname has inappropriate self*/
DefineGlobalFuncPtr(void, __cdecl, IElua_error_badself, (char* funcname), IELUA_ERROR_BADSELF);

/*error_badarg
-prints an error message that the function funcname parameter number is //
 of the wrong type, and should be of type type*/
DefineGlobalFuncPtr(void, __cdecl, IElua_error_badarg, (char* funcname, int number, char* type), IELUA_ERROR_BADARG);

/*error_toomanyargs
-prints an error message that the function funcname has too many arguments*/
DefineGlobalFuncPtr(void, __cdecl, IElua_error_toomanyargs, (char* funcname), IELUA_ERROR_TOOMANYARGS);

/*createtag
-if name does not already exist in toLua_tag, creates new IETag //
 and updates toLua_tag and toLua_name //
 initialises default IETag methods
-if name already exists, returns the found IETag*/
DefineGlobalFuncPtr(IETag, __cdecl, IElua_createtag, (char* name), IELUA_CREATETAG);

/*isvalidtype
-determines whether o is of the type specified
-standard types are: g_IETagNumber, g_IETagString, g_IETagUserdata
-if a non-standard type is specified, tag(o) is directly compared to type //
 if tag(o) == 0, the functions returns 1 //
 if tag(o) != type, the parent tag is iteratively obtained from toLua_parent.tag(o) and compared to type
 -returns a non-zero int if valid*/
DefineGlobalFuncPtr(int, __cdecl, IElua_isvalidtype, (lua_Object o, IETag type), IELUA_ISVALIDTYPE);

/*getparam
-gets the (number)th param and checks the type against tag*/
DefineGlobalFuncPtr(int, __cdecl, IElua_getparam, (int number, IETag tag), IELUA_GETPARAM);

/*getstring
-equivalent to lua_getstring() but aborts if o isnil()*/
DefineGlobalFuncPtr(char*, __cdecl, IElua_getstring, (lua_Object o), IELUA_GETSTRING);

/*getnumber
-equivalent to lua_getnumber()*/
DefineGlobalFuncPtr(real, __cdecl, IElua_getnumber, (lua_Object o), IELUA_GETNUMBER);

/*getuserdata
-equivalent to lua_getuserdata() but aborts if o isnil()*/
void* __cdecl IElua_getuserdata(lua_Object o); //re-implemented

/*cast
-tag(userdata) is compared to type //
 if tag(userdata) == 0, the function returns the value of userdata //
 if tag(userdata) != type, the parent tag is iteratively obtained from toLua_parent.tag(child) //
 and the userdata value from test_cast.tag(child) is iteratively called with function of form void* cast(void* u_child) //
 with the cast function returning the next userdata value
-the value of the final userdata is returned
-the function is generally used to cast the self parameter of a tag method
*/
DefineGlobalFuncPtr(void*, __cdecl, IElua_cast, (lua_Object userdata, IETag tag), IELUA_CAST);

/*pushuserdata
-pushes userdata(u, -1) on the C2lua stack
-if tag(userdata) == 0, tag(userdata) is set to tag*/
DefineGlobalFuncPtr(void, __cdecl, IElua_pushuserdata, (void* userdata, IETag tag), IELUA_PUSHUSERDATA);

/*gettable
-gets the value table.tag, which should be of type table
-if this value is not a table, newtable is created and stored in table.tag*/
DefineGlobalFuncPtr(lua_Object, __cdecl, IElua_gettable, (lua_Object table, IETag tag), IELUA_GETTABLE);

/*settaggetmethod
-stores a userdata(u, 0) in test_getref.tag.event
-the method is invoked in IELua using "tag:event" before a settagmethod method is discovered
-the method is of type "void method(void* u)" and pushes a value onto the C2lua stack*/
DefineGlobalFuncPtr(void, __cdecl, IElua_settaggetmethod, (IETag tag, char* event, void* u), IELUA_SETTAGGETMETHOD);

/*settagsetmethod
-stores a userdata(u, 0) in test_setref.tag.event
-the method is of type void method(void* u, lua_Object value)*/
DefineGlobalFuncPtr(void, __cdecl, IElua_settagsetmethod, (IETag tag, char* event, void* u), IELUA_SETTAGSETMETHOD);

/*settagmethod
-stores a lua_CFunction in test_getref.tag.event
-these are invoked in IELua with tag:event after userdata is discovered*/
DefineGlobalFuncPtr(void, __cdecl, IElua_settagmethod, (IETag tag, char* event, lua_CFunction func), IELUA_SETTAGMETHOD);

/*createglobaltag
-creates a new IETag and stores it in the global varname*/
DefineGlobalFuncPtr(void, __cdecl, IElua_createglobaltag, (char* varname), IELUA_CREATEGLOBALTAG);

//Lua 3.0 functions
DefineGlobalFuncPtr(int, __cdecl, lua_dofile, (char* filename), LUA_DOFILE);
DefineGlobalFuncPtr(int, __cdecl, lua_dostring, (char* str), LUA_DOSTRING);
DefineGlobalFuncPtr(lua_Object, __cdecl, lua_pop, (), LUA_POP);
DefineGlobalFuncPtr(lua_Object, __cdecl, lua_rawgettable, (), LUA_RAWGETTABLE);
DefineGlobalFuncPtr(void, __cdecl, lua_error, (char* message), LUA_ERROR);
DefineGlobalFuncPtr(lua_Object, __cdecl, lua_seterrormethod, (), LUA_SETERRORMETHOD);
DefineGlobalFuncPtr(int, __cdecl, lua_callfunction, (lua_Object function), LUA_CALLFUNCTION);
lua_Object lua_gettagmethod(int tag, char* event); //re-implemented
DefineGlobalFuncPtr(lua_Object, __cdecl, lua_settagmethod, (int tag, char* event), LUA_SETTAGMETHOD);
DefineGlobalFuncPtr(lua_Object, __cdecl, lua_gettable, (), LUA_GETTABLE);
DefineGlobalFuncPtr(void, __cdecl, lua_beginblock, (), LUA_BEGINBLOCK);
DefineGlobalFuncPtr(void, __cdecl, lua_endblock, (), LUA_ENDBLOCK);
DefineGlobalFuncPtr(void, __cdecl, lua_settag, (int tag), LUA_SETTAG);
DefineGlobalFuncPtr(void, __cdecl, lua_settable, (), LUA_SETTABLE);
DefineGlobalFuncPtr(void, __cdecl, lua_rawsettable, (), LUA_RAWSETTABLE);
DefineGlobalFuncPtr(lua_Object, __cdecl, lua_createtable, (), LUA_CREATETABLE);
DefineGlobalFuncPtr(lua_Object, __cdecl, lua_lua2C, (int number), LUA_LUA2C);
DefineGlobalFuncPtr(int, __cdecl, lua_isnil, (lua_Object o), LUA_ISNIL);
DefineGlobalFuncPtr(int, __cdecl, lua_istable, (lua_Object o), LUA_ISTABLE);
DefineGlobalFuncPtr(int, __cdecl, lua_isuserdata, (lua_Object o), LUA_ISUSERDATA);
DefineGlobalFuncPtr(int, __cdecl, lua_iscfunction, (lua_Object o), LUA_ISCFUNCTION);
DefineGlobalFuncPtr(int, __cdecl, lua_isnumber, (lua_Object o), LUA_ISNUMBER);
DefineGlobalFuncPtr(int, __cdecl, lua_isstring, (lua_Object o), LUA_ISSTRING);
DefineGlobalFuncPtr(int, __cdecl, lua_isfunction, (lua_Object o), LUA_ISFUNCTION);
DefineGlobalFuncPtr(real, __cdecl, lua_getnumber, (lua_Object o), LUA_GETNUMBER);
DefineGlobalFuncPtr(char*, __cdecl, lua_getstring, (lua_Object o), LUA_GETSTRING);
DefineGlobalFuncPtr(void*, __cdecl, lua_getuserdata, (lua_Object o), LUA_GETUSERDATA);
DefineGlobalFuncPtr(lua_CFunction, __cdecl, lua_getcfunction, (lua_Object o), LUA_GETCFUNCTION);
DefineGlobalFuncPtr(lua_Object, __cdecl, lua_getref, (int ref), LUA_GETREF);
DefineGlobalFuncPtr(int, __cdecl, lua_ref, (int lock), LUA_REF);
DefineGlobalFuncPtr(lua_Object, __cdecl, lua_getglobal, (char* name), LUA_GETGLOBAL);
DefineGlobalFuncPtr(lua_Object, __cdecl, lua_rawgetglobal, (char* name), LUA_RAWGETGLOBAL);
DefineGlobalFuncPtr(void, __cdecl, lua_setglobal, (char* varname), LUA_SETGLOBAL);
DefineGlobalFuncPtr(void, __cdecl, lua_rawsetglobal, (char* varname), LUA_RAWSETGLOBAL);
DefineGlobalFuncPtr(void, __cdecl, lua_pushnil, (), LUA_PUSHNIL);
DefineGlobalFuncPtr(void, __cdecl, lua_pushnumber, (real n), LUA_PUSHNUMBER);
DefineGlobalFuncPtr(void, __cdecl, lua_pushstring, (char* s), LUA_PUSHSTRING);
DefineGlobalFuncPtr(void, __cdecl, lua_pushcfunction, (lua_CFunction fn), LUA_PUSHCFUNCTION);
DefineGlobalFuncPtr(void, __cdecl, lua_pushusertag, (void* u, int tag), LUA_PUSHUSERTAG);
DefineGlobalFuncPtr(void, __cdecl, lua_pushobject, (lua_Object o), LUA_PUSHOBJECT);
DefineGlobalFuncPtr(int, __cdecl, lua_tag, (lua_Object o), LUA_TAG);
DefineGlobalFuncPtr(int, __cdecl, lua_newtag, (), LUA_NEWTAG);

//LUA 3.0 helper functions for BGEE re-implementations
DefineGlobalFuncPtr(void, __cdecl, do_unprotectedrun, (lua_CFunction f, int nParams, int nResults), DO_UNPROTECTEDRUN);
DefineGlobalFuncPtr(void, __cdecl, luaI_gettagmethod, (), LUAI_GETTAGMETHOD);
DefineGlobalFuncPtr(lua_Object, __cdecl, put_luaObjectonTop, (), PUT_LUAOBJECTONTOP);

#endif //LUA_H