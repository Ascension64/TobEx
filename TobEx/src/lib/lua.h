#ifndef LUA_H
#define LUA_H

#include "stdafx.h"

//Lua 3.0 typedefs
typedef unsigned int lua_Object;
typedef float real;
typedef void (*lua_CFunction) (void);

//IELua typedefs
typedef int IETag;

//IELua globals
static const IETag& g_IETagNumber = (const IETag&)(*(IETag*)0xBDD678);
static const IETag& g_IETagString = (const IETag&)(*(IETag*)0xBDD684);
static const IETag& g_IETagUserdata = (const IETag&)(*(IETag*)0xBDD680);

static const IETag& g_IETagCBaldurChitin = (const IETag&)(*(IETag*)0xB8C42C);
static const IETag& g_IETagCGameOptions = (const IETag&)(*(IETag*)0xB8C424);
static const IETag& g_IETagCInfGame = (const IETag&)(*(IETag*)0xB8C43C);
static const IETag& g_IETagCLUAConsole = (const IETag&)(*(IETag*)0xB8C448);
static const IETag& g_IETagCLUACheats = (const IETag&)(*(IETag*)0xB8C020);
static const IETag& g_IETagCTimerWorld = (const IETag&)(*(IETag*)0xB8C444);

//IElua table refs
static const int& g_tableref_toLua_tag = (const int&)(*(int*)0xB8C4DC);
static const int& g_tableref_toLua_name = (const int&)(*(int*)0xB8C4F0);
static const int& g_tableref_toLua_parent = (const int&)(*(int*)0xB8C4BC);
static const int& g_tableref_test_cast = (const int&)(*(int*)0xB8C4B8);
static const int& g_tableref_test_alloc = (const int&)(*(int*)0xB8C4EC);
static const int& g_tableref_test_getref = (const int&)(*(int*)0xBDD67C);
static const int& g_tableref_test_setref = (const int&)(*(int*)0xB8C4CC);
static const int& g_tableref_toLua_mate = (const int&)(*(int*)0xB8C4D4);

static char* g_szIEluaError = (char*)0xB8C454;
static size_t g_szIEluaErrorSize = 100;

//CLUA functions
class CLUAConsole { //size 1h
public:
	void DisplayText(IECString s);
	void StartStore(char* sz);
protected:
	char u0;
};

//IELua functions
DefineGlobalFuncPtr(int, __stdcall, IElua_init, (), 0x5ADD86);
DefineGlobalFuncPtr(int, __stdcall, IElua_deinit, (), 0x5AE158);

/*error_badself
-prints an error message that the function funcname has inappropriate self*/
DefineGlobalFuncPtr(void, __cdecl, IElua_error_badself, (char* funcname), 0x9864E0);

/*error_badarg
-prints an error message that the function funcname parameter number is //
 of the wrong type, and should be of type type*/
DefineGlobalFuncPtr(void, __cdecl, IElua_error_badarg, (char* funcname, int number, char* type), 0x986508);

/*error_badargarray
-prints an error message that the function funcname parameter number is //
 of the wrong type, and should be an array of type type with dimensions dimensions*/
DefineGlobalFuncPtr(void, __cdecl, IElua_error_badargarray, (char* funcname, int number, char* type, int dimensions), 0x986538);

/*error_toomanyargs
-prints an error message that the function funcname has too many arguments*/
DefineGlobalFuncPtr(void, __cdecl, IElua_error_toomanyargs, (char* funcname), 0x98656C);

/*createtag
-if name does not already exist in toLua_tag, creates new IETag //
 and updates toLua_tag and toLua_name //
 initialises default IETag methods
-if name already exists, returns the found IETag*/
DefineGlobalFuncPtr(IETag, __cdecl, IElua_createtag, (char* name), 0x9865B7);

/*setparent
-sets the parent of child
-technically this sets toLua_parent.child = parent and //
 test_cast.child = usertag(cast, 0)*/
DefineGlobalFuncPtr(void, __cdecl, IElua_setparent, (IETag child, IETag parent, void* cast), 0x9866C2);

/*isvalidtype
-determines whether o is of the type specified
-standard types are: g_IETagNumber, g_IETagString, g_IETagUserdata
-if a non-standard type is specified, tag(o) is directly compared to type //
 if tag(o) == 0, the functions returns 1 //
 if tag(o) != type, the parent tag is iteratively obtained from toLua_parent.tag(o) and compared to type
 -returns a non-zero int if valid*/
DefineGlobalFuncPtr(int, __cdecl, IElua_isvalidtype, (lua_Object o, IETag type), 0x986752);

/*getparam
-gets the (number)th param and checks the type against tag*/
DefineGlobalFuncPtr(int, __cdecl, IElua_getparam, (int number, IETag tag), 0x986893);

/*checktable
-checks that each numerical index of the table of size size is of type type
-if table is not of type table, returns zero
-if any field is not of type type, returns zero
-if size is smaller than the number of elements in the table, returns zero*/
DefineGlobalFuncPtr(int, __cdecl, IElua_checktable, (lua_Object table, IETag type, int size), 0x9868BA);

/*getstring
-equivalent to lua_getstring() but aborts if o isnil()*/
DefineGlobalFuncPtr(char*, __cdecl, IElua_getstring, (lua_Object o), 0x98698F);

/*getnumber
-equivalent to lua_getnumber()*/
DefineGlobalFuncPtr(real, __cdecl, IElua_getnumber, (lua_Object o), 0x9869B4);

/*getuserdata
-equivalent to lua_getuserdata() but aborts if o isnil()*/
DefineGlobalFuncPtr(void*, __cdecl, IElua_getuserdata, (lua_Object o), 0x9869CD);

/*cast
-tag(userdata) is compared to type //
 if tag(userdata) == 0, the function returns the value of userdata //
 if tag(userdata) != type, the parent tag is iteratively obtained from toLua_parent.tag(child) //
 and the userdata value from test_cast.tag(child) is iteratively called with function of form void* cast(void* u_child) //
 with the cast function returning the next userdata value
-the value of the final userdata is returned
-the function is generally used to cast the self parameter of a tag method
*/
DefineGlobalFuncPtr(void*, __cdecl, IElua_cast, (lua_Object userdata, IETag tag), 0x9869F2);

/*pushstring
-equivalent to lua_pushstring() but pushnil() if NULL*/
DefineGlobalFuncPtr(void, __cdecl, IElua_pushstring, (char* sz), 0x986AE8);

/*pushuserdata
-pushes userdata(u, -1) on the C2lua stack
-if tag(userdata) == 0, tag(userdata) is set to tag*/
DefineGlobalFuncPtr(void, __cdecl, IElua_pushuserdata, (void* userdata, IETag tag), 0x986B06);

/* alloc
-create a new object and stores as an index so test_alloc.userdata(obj, 0) = 0.0
-the object is assigned tag IETag and is given a garbage collection method "gc"
-the object is initialised by copying pData into it
-the userdata is pushed onto the C2lua stack before return*/
DefineGlobalFuncPtr(void, __cdecl, IElua_alloc, (void* pData, int size, IETag tag), 0x986B65);

/*gettable
-gets the value table.tag, which should be of type table
-if this value is not a table, newtable is created and stored in table.tag*/
DefineGlobalFuncPtr(lua_Object, __cdecl, IElua_gettable, (lua_Object table, IETag tag), 0x986C9F);

/*settaggetmethod
-stores a userdata(u, 0) in test_getref.tag.event
-the method is invoked in IELua using "tag:event" before a settagmethod method is discovered
-the method is of type "void method(void* u)" and pushes a value onto the C2lua stack*/
DefineGlobalFuncPtr(void, __cdecl, IElua_settaggetmethod, (IETag tag, char* event, void* u), 0x986D2B);

/*settagsetmethod
-stores a userdata(u, 0) in test_setref.tag.event
-the method is of type void method(void* u, lua_Object value)*/
DefineGlobalFuncPtr(void, __cdecl, IElua_settagsetmethod, (IETag tag, char* event, void* u), 0x986D7E);

/*settagmethod
-stores a lua_CFunction in test_getref.tag.event
-these are invoked in IELua with tag:event after userdata is discovered*/
DefineGlobalFuncPtr(void, __cdecl, IElua_settagmethod, (IETag tag, char* event, lua_CFunction func), 0x986DD1);

/*createglobaltag
-creates a new IETag and stores it in the global varname*/
DefineGlobalFuncPtr(void, __cdecl, IElua_createglobaltag, (char* varname), 0x986E22);

/*createtaggetmethod
-creates a new tag and stores userdata(u, 0) in test_getref.tag.event*/
DefineGlobalFuncPtr(void, __cdecl, IElua_createtaggetmethod, (char* event, void* u), 0x986E5D);

/*createtagsetmethod
-creates a new tag and stores userdata(u, 0) in test_setref.tag.event*/
DefineGlobalFuncPtr(void, __cdecl, IElua_createtagsetmethod, (char* event, void* u), 0x986E88);

//Lua 3.0 functions
DefineGlobalFuncPtr(int, __cdecl, lua_dofile, (char* filename), 0xA25380);
DefineGlobalFuncPtr(int, __cdecl, lua_dostring, (char* str), 0xA25490);
DefineGlobalFuncPtr(lua_Object, __cdecl, lua_pop, (), 0xA25D50);
DefineGlobalFuncPtr(lua_Object, __cdecl, lua_rawgettable, (), 0xA25F10);
DefineGlobalFuncPtr(void, __cdecl, lua_error, (char* message), 0xA25FB0);
DefineGlobalFuncPtr(lua_Object, __cdecl, lua_seterrormethod, (), 0xA26860);
DefineGlobalFuncPtr(int, __cdecl, lua_callfunction, (lua_Object function), 0xA266D0);
DefineGlobalFuncPtr(lua_Object, __cdecl, lua_gettagmethod, (int tag, char* event), 0xA26740);
DefineGlobalFuncPtr(lua_Object, __cdecl, lua_settagmethod, (int tag, char* event), 0xA267D0);
DefineGlobalFuncPtr(lua_Object, __cdecl, lua_gettable, (), 0xA26880);
DefineGlobalFuncPtr(void, __cdecl, lua_beginblock, (), 0xA26980);
DefineGlobalFuncPtr(void, __cdecl, lua_endblock, (), 0xA269D0);
DefineGlobalFuncPtr(void, __cdecl, lua_settag, (int tag), 0xA26A30);
DefineGlobalFuncPtr(void, __cdecl, lua_settable, (), 0xA26A60);
DefineGlobalFuncPtr(void, __cdecl, lua_rawsettable, (), 0xA26BA0);
DefineGlobalFuncPtr(lua_Object, __cdecl, lua_createtable, (), 0xA26BC0);
DefineGlobalFuncPtr(lua_Object, __cdecl, lua_lua2C, (int number), 0xA26C50);
DefineGlobalFuncPtr(int, __cdecl, lua_isnil, (lua_Object o), 0xA26C70);
DefineGlobalFuncPtr(int, __cdecl, lua_istable, (lua_Object o), 0xA26C90);
DefineGlobalFuncPtr(int, __cdecl, lua_isuserdata, (lua_Object o), 0xA26CB0);
DefineGlobalFuncPtr(int, __cdecl, lua_iscfunction, (lua_Object o), 0xA26CD0);
DefineGlobalFuncPtr(int, __cdecl, lua_isnumber, (lua_Object o), 0xA26CF0);
DefineGlobalFuncPtr(int, __cdecl, lua_isstring, (lua_Object o), 0xA26D70);
DefineGlobalFuncPtr(int, __cdecl, lua_isfunction, (lua_Object o), 0xA26D90);
DefineGlobalFuncPtr(real, __cdecl, lua_getnumber, (lua_Object o), 0xA26DC0);
DefineGlobalFuncPtr(char*, __cdecl, lua_getstring, (lua_Object o), 0xA26E10);
DefineGlobalFuncPtr(void*, __cdecl, lua_getuserdata, (lua_Object o), 0xA26F10);
DefineGlobalFuncPtr(lua_CFunction, __cdecl, lua_getcfunction, (lua_Object o), 0xA26F40);
DefineGlobalFuncPtr(lua_Object, __cdecl, lua_getref, (int ref), 0xA26F70);
DefineGlobalFuncPtr(int, __cdecl, lua_ref, (int lock), 0xA26F90);
DefineGlobalFuncPtr(lua_Object, __cdecl, lua_getglobal, (char* name), 0xA26FC0);
DefineGlobalFuncPtr(lua_Object, __cdecl, lua_rawgetglobal, (char* name), 0xA270E0);
DefineGlobalFuncPtr(void, __cdecl, lua_setglobal, (char* varname), 0xA27110);
DefineGlobalFuncPtr(void, __cdecl, lua_rawsetglobal, (char* varname), 0xA27250);
DefineGlobalFuncPtr(void, __cdecl, lua_pushnil, (), 0xA272A0);
DefineGlobalFuncPtr(void, __cdecl, lua_pushnumber, (real n), 0xA272D0);
DefineGlobalFuncPtr(void, __cdecl, lua_pushstring, (char* s), 0xA27310);
DefineGlobalFuncPtr(void, __cdecl, lua_pushcfunction, (lua_CFunction fn), 0xA27360);
DefineGlobalFuncPtr(void, __cdecl, lua_pushusertag, (void* u, int tag), 0xA273A0);
DefineGlobalFuncPtr(void, __cdecl, lua_pushobject, (lua_Object o), 0xA27440);
DefineGlobalFuncPtr(int, __cdecl, lua_tag, (lua_Object o), 0xA274C0);
DefineGlobalFuncPtr(int, __cdecl, lua_newtag, (), 0xA28D90);

#endif //LUA_H