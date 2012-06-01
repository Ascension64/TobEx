#include "lua.h"

int (__stdcall *IElua_init)() =
	reinterpret_cast<int (__stdcall *)()>	(0x5ADD86);
int (__stdcall *IElua_deinit)() =
	reinterpret_cast<int (__stdcall *)()>	(0x5AE158);

void (__cdecl *IElua_error_badself)(char*) =
	reinterpret_cast<void (__cdecl *)(char*)>	(0x9864E0);
void (__cdecl *IElua_error_badarg)(char*, int, char*) =
	reinterpret_cast<void (__cdecl *)(char*, int, char*)>	(0x986508);
void (__cdecl *IElua_error_badargarray)(char*, int, char*, int) =
	reinterpret_cast<void (__cdecl *)(char*, int, char*, int)>	(0x986538);
void (__cdecl *IElua_error_toomanyargs)(char*) =
	reinterpret_cast<void (__cdecl *)(char*)>	(0x98656C);
IETag (__cdecl *IElua_createtag)(char*) =
	reinterpret_cast<IETag (__cdecl *)(char*)>	(0x9865B7);
void (__cdecl *IElua_setparent)(IETag, IETag, void*) =
	reinterpret_cast<void (__cdecl *)(IETag, IETag, void*)>	(0x9866C2);
int (__cdecl *IElua_isvalidtype)(lua_Object, IETag) =
	reinterpret_cast<int (__cdecl *)(lua_Object, IETag)>	(0x986752);
int (__cdecl *IElua_getparam)(int, IETag) =
	reinterpret_cast<int (__cdecl *)(int, IETag)>	(0x986893);
int (__cdecl *IElua_checktable)(lua_Object, IETag, int) =
	reinterpret_cast<int (__cdecl *)(lua_Object, IETag, int)>	(0x9868BA);
char* (__cdecl *IElua_getstring)(lua_Object) =
	reinterpret_cast<char* (__cdecl *)(lua_Object)>	(0x98698F);
real (__cdecl *IElua_getnumber)(lua_Object) =
	reinterpret_cast<real (__cdecl *)(lua_Object)>	(0x9869B4);
void* (__cdecl *IElua_getuserdata)(lua_Object) =
	reinterpret_cast<void* (__cdecl *)(lua_Object)>	(0x9869CD);
void* (__cdecl *IElua_cast)(lua_Object, IETag) =
	reinterpret_cast<void* (__cdecl *)(lua_Object, IETag)>	(0x9869F2);
void (__cdecl *IElua_pushstring)(char*) =
	reinterpret_cast<void (__cdecl*)(char*)>	(0x986AE8);
void (__cdecl *IElua_pushuserdata)(void*, IETag) =
	reinterpret_cast<void (__cdecl*)(void*, IETag)>	(0x986B06);
void (__cdecl *IElua_alloc)(void*, int, IETag) =
	reinterpret_cast<void (__cdecl*)(void*, int, IETag)>	(0x986B65);
lua_Object (__cdecl *IElua_gettable)(lua_Object, IETag) =
	reinterpret_cast<lua_Object (__cdecl *)(lua_Object, IETag)>	(0x986C9F);
void (__cdecl *IElua_settaggetmethod)(IETag, char*, void*) =
	reinterpret_cast<void (__cdecl *)(IETag, char*, void*)>	(0x986D2B);
void (__cdecl *IElua_settagsetmethod)(IETag, char*, void*) =
	reinterpret_cast<void (__cdecl *)(IETag, char*, void*)>	(0x986D7E);
void (__cdecl *IElua_settagmethod)(IETag, char*, lua_CFunction) =
	reinterpret_cast<void (__cdecl *)(IETag, char*, lua_CFunction)>	(0x986DD1);
void (__cdecl *IElua_createglobaltag)(char*) =
	reinterpret_cast<void (__cdecl *)(char*)>	(0x986E22);
void (__cdecl *IElua_createtaggetmethod)(char*, void*) =
	reinterpret_cast<void (__cdecl*)(char*, void*)>	(0x986E5D);
void (__cdecl *IElua_createtagsetmethod)(char*, void*) =
	reinterpret_cast<void (__cdecl*)(char*, void*)>	(0x986E88);

int (__cdecl *lua_dofile)(char*) =
	reinterpret_cast<int (__cdecl *)(char*)>	(0xA25380);
int (__cdecl *lua_dostring)(char*) =
	reinterpret_cast<int (__cdecl *)(char*)>	(0xA25490);
lua_Object (__cdecl *lua_pop)() =
	reinterpret_cast<lua_Object (__cdecl *)()>	(0xA25D50);
lua_Object (__cdecl *lua_rawgettable)() =
	reinterpret_cast<lua_Object (__cdecl *)()>	(0xA25F10);
void (__cdecl *lua_error)(char*) =
	reinterpret_cast<void (__cdecl *)(char*)>	(0xA25FB0);
int (__cdecl *lua_callfunction)(lua_Object) =
	reinterpret_cast<int (__cdecl *)(lua_Object)>	(0xA266D0);
lua_Object (__cdecl *lua_gettagmethod)(int, char*) =
	reinterpret_cast<lua_Object (__cdecl *)(int, char*)>	(0xA26740);
lua_Object (__cdecl *lua_settagmethod)(int, char*) =
	reinterpret_cast<lua_Object (__cdecl *)(int, char*)>	(0xA267D0);
lua_Object (__cdecl *lua_gettable)() =
	reinterpret_cast<lua_Object (__cdecl *)()>	(0xA26880);
void (__cdecl *lua_beginblock)() =
	reinterpret_cast<void (__cdecl *)()>	(0xA26980);
void (__cdecl *lua_endblock)() =
	reinterpret_cast<void (__cdecl *)()>	(0xA269D0);
void (__cdecl *lua_settag)(int) =
	reinterpret_cast<void (__cdecl *)(int)>	(0xA26A30);
void (__cdecl *lua_settable)() =
	reinterpret_cast<void (__cdecl *)()>	(0xA26A60);
void (__cdecl *lua_rawsettable)() =
	reinterpret_cast<void (__cdecl *)()>	(0xA26BA0);
lua_Object (__cdecl *lua_createtable)() =
	reinterpret_cast<lua_Object (__cdecl *)()>	(0xA26BC0);
lua_Object (__cdecl *lua_lua2C)(int) =
	reinterpret_cast<lua_Object (__cdecl *)(int)>	(0xA26C50);
int (__cdecl *lua_isnil)(lua_Object) =
	reinterpret_cast<int (__cdecl *)(lua_Object)>	(0xA26C70);
int (__cdecl *lua_istable)(lua_Object) =
	reinterpret_cast<int (__cdecl *)(lua_Object)>	(0xA26C90);
int (__cdecl *lua_isuserdata)(lua_Object) =
	reinterpret_cast<int (__cdecl *)(lua_Object)>	(0xA26CB0);
int (__cdecl *lua_iscfunction)(lua_Object) =
	reinterpret_cast<int (__cdecl *)(lua_Object)>	(0xA26CD0);
int (__cdecl *lua_isnumber)(lua_Object) =
	reinterpret_cast<int (__cdecl *)(lua_Object)>	(0xA26CF0);
int (__cdecl *lua_isstring)(lua_Object) =
	reinterpret_cast<int (__cdecl *)(lua_Object)>	(0xA26D70);
int (__cdecl *lua_isfunction)(lua_Object) =
	reinterpret_cast<int (__cdecl *)(lua_Object)>	(0xA26D90);
real (__cdecl *lua_getnumber)(lua_Object) =
	reinterpret_cast<real (__cdecl *)(lua_Object)>	(0xA26DC0);
char* (__cdecl *lua_getstring)(lua_Object) =
	reinterpret_cast<char* (__cdecl *)(lua_Object)>	(0xA26E10);
void* (__cdecl *lua_getuserdata)(lua_Object) =
	reinterpret_cast<void* (__cdecl *)(lua_Object)>	(0xA26F10);
lua_CFunction (__cdecl *lua_getcfunction)(lua_Object) =
	reinterpret_cast<lua_CFunction (__cdecl *)(lua_Object)>	(0xA26F40);
lua_Object (__cdecl *lua_getref)(int) =
	reinterpret_cast<lua_Object (__cdecl *)(int)>	(0xA26F70);
int (__cdecl *lua_ref)(int) =
	reinterpret_cast<int (__cdecl *)(int)>	(0xA26F90);
lua_Object (__cdecl *lua_getglobal)(char*) =
	reinterpret_cast<lua_Object (__cdecl *)(char*)>	(0xA26FC0);
lua_Object (__cdecl *lua_rawgetglobal)(char*) =
	reinterpret_cast<lua_Object (__cdecl *)(char*)>	(0xA270E0);
void (__cdecl *lua_setglobal)(char*) =
	reinterpret_cast<void (__cdecl *)(char*)>	(0xA27110);
void (__cdecl *lua_rawsetglobal)(char*) =
	reinterpret_cast<void (__cdecl *)(char*)>	(0xA27250);
void (__cdecl *lua_pushnil)() =
	reinterpret_cast<void (__cdecl *)()>	(0xA272A0);
void (__cdecl *lua_pushnumber)(real) =
	reinterpret_cast<void (__cdecl *)(real)>	(0xA272D0);
void (__cdecl *lua_pushstring)(char*) =
	reinterpret_cast<void (__cdecl *)(char*)>	(0xA27310);
void (__cdecl *lua_pushcfunction)(lua_CFunction) =
	reinterpret_cast<void (__cdecl *)(lua_CFunction)>	(0xA27360);
void (__cdecl *lua_pushusertag)(void*, int) =
	reinterpret_cast<void (__cdecl *)(void*, int)>	(0xA273A0);
void (__cdecl *lua_pushobject)(lua_Object) =
	reinterpret_cast<void (__cdecl *)(lua_Object)>	(0xA27440);
int (__cdecl *lua_tag)(lua_Object) =
	reinterpret_cast<int (__cdecl *)(lua_Object)>	(0xA274C0);
int (__cdecl *lua_newtag)() = 
	reinterpret_cast<int (__cdecl *)()>	(0xA28D90);
