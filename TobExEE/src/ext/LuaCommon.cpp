//TobExEE
#include "LuaCommon.h"
#include "LuaDump.h"

#include "chitin.h"
#include <math.h>

int g_TagObjects;

/* pow(x, y)
Global function
Executes a pow operation on two numbers and pushes the result onto the Lua stack
The values can be decimal numbers, or string hexadecimal numbers starting with "0x" */
void LUA_Pow() {
	real x;
	real y;

	lua_Object arg1 = lua_lua2C(1);
	if (lua_isnil(arg1)) {
		lua_error("bad argument for ^ operator");
		return;
	} else if (lua_isnumber(arg1)) {
		x = lua_getnumber(arg1);
	} else if (lua_isstring(arg1)) {
		sscanf_s(lua_getstring(arg1), "%d", &x);
	} else {
		IElua_error_badarg("pow", 1, "number or string");
		return;
	}

	lua_Object arg2 = lua_lua2C(2);
	if (lua_isnil(arg2)) {
		lua_error("bad argument for ^ operator");
		return;
	} else if (lua_isnumber(arg2)) {
		y = lua_getnumber(arg2);
	} else if (lua_isstring(arg2)) {
		sscanf_s(lua_getstring(arg2), "%d", &y);
	} else {
		IElua_error_badarg("pow", 2, "number or string");
		return;
	}

	lua_pushnumber(pow(x, y));
	return;
}

/* mod(x, y)
Global function
Executes a mod operation on two numbers and pushes the result onto the Lua stack
The values can be decimal numbers, or string hexadecimal numbers starting with "0x" */
void LUA_Mod() {
	unsigned int x;
	unsigned int y;

	lua_Object arg1 = lua_lua2C(1);
	if (lua_isnil(arg1)) {
		lua_error("bad argument for mod");
		return;
	} else if (lua_isnumber(arg1)) {
		x = (unsigned int)lua_getnumber(arg1);
	} else if (lua_isstring(arg1)) {
		sscanf_s(lua_getstring(arg1), "0x%x", &x);
	} else {
		IElua_error_badarg("mod", 1, "number or string");
		return;
	}

	lua_Object arg2 = lua_lua2C(2);
	if (lua_isnil(arg2)) {
		lua_error("bad argument for mod");
		return;
	} else if (lua_isnumber(arg2)) {
		y = (unsigned int)lua_getnumber(arg2);
	} else if (lua_isstring(arg2)) {
		sscanf_s(lua_getstring(arg2), "0x%x", &y);
	} else {
		IElua_error_badarg("mod", 2, "number or string");
		return;
	}

	if (y <= 0) {
		lua_error("division by zero");
		return;
	}

	lua_pushnumber((real)(x % y));
	return;
}

/* band(x, y)
Global function
Executes a bitwise and operation on two numbers and pushes the result onto the Lua stack
The values can be decimal numbers, or string hexadecimal numbers starting with "0x" */
void LUA_BAnd() {
	unsigned int x;
	unsigned int y;

	lua_Object arg1 = lua_lua2C(1);
	if (lua_isnil(arg1)) {
		lua_error("bad argument for band");
		return;
	} else if (lua_isnumber(arg1)) {
		x = (unsigned int)lua_getnumber(arg1);
	} else if (lua_isstring(arg1)) {
		sscanf_s(lua_getstring(arg1), "0x%x", &x);
	} else {
		IElua_error_badarg("band", 1, "number or string");
		return;
	}

	lua_Object arg2 = lua_lua2C(2);
	if (lua_isnil(arg2)) {
		lua_error("bad argument for band");
		return;
	} else if (lua_isnumber(arg2)) {
		y = (unsigned int)lua_getnumber(arg2);
	} else if (lua_isstring(arg2)) {
		sscanf_s(lua_getstring(arg2), "0x%x", &y);
	} else {
		IElua_error_badarg("band", 2, "number or string");
		return;
	}

	lua_pushnumber((real)(x & y));
	return;
}

/* bor(x, y)
Global function
Executes a bitwise or operation on two numbers and pushes the result onto the Lua stack
The values can be decimal numbers, or string hexadecimal numbers starting with "0x" */
void LUA_BOr() {
	unsigned int x;
	unsigned int y;

	lua_Object arg1 = lua_lua2C(1);
	if (lua_isnil(arg1)) {
		lua_error("bad argument for bor");
		return;
	} else if (lua_isnumber(arg1)) {
		x = (unsigned int)lua_getnumber(arg1);
	} else if (lua_isstring(arg1)) {
		sscanf_s(lua_getstring(arg1), "0x%x", &x);
	} else {
		IElua_error_badarg("bor", 1, "number or string");
		return;
	}

	lua_Object arg2 = lua_lua2C(2);
	if (lua_isnil(arg2)) {
		lua_error("bad argument for bor");
		return;
	} else if (lua_isnumber(arg2)) {
		y = (unsigned int)lua_getnumber(arg2);
	} else if (lua_isstring(arg2)) {
		sscanf_s(lua_getstring(arg2), "0x%x", &y);
	} else {
		IElua_error_badarg("bor", 2, "number or string");
		return;
	}

	lua_pushnumber((real)(x | y));
	return;
}

/* dec2hex(number)
Global function
Converts a decimal number to a string hexadecimal number starting with "0x" and pushes it onto the Lua stack */
void LUA_Dec2Hex() {
	int n;
	IECString s;

	lua_Object arg1 = lua_lua2C(1);
	if (IElua_getparam(1, g_IETagNumber)) {
		n = (int)IElua_getnumber(arg1);
	} else {
		IElua_error_badarg("dec2hex", 1, "number");
		return;
	}

	if (lua_lua2C(2)) {
		IElua_error_toomanyargs("dec2hex");
		return;
	}

	s.Format("0x%x", n);
	lua_pushstring(s.GetBuffer(0));
	return;
}

/* hex2dec(string)
Global function
Converts a string hexadecimal number starting with "0x" into a decimal number and pushes it onto the Lua stack */
void LUA_Hex2Dec() {
	int n;
	IECString s;

	lua_Object arg1 = lua_lua2C(1);
	if (IElua_getparam(1, g_IETagString)) {
		s = IElua_getstring(arg1);
	} else {
		IElua_error_badarg("hex2dec", 1, "string");
		return;
	}

	if (lua_lua2C(2)) {
		IElua_error_toomanyargs("hex2dec");
		return;
	}

	sscanf_s((LPCTSTR)s, "0x%x", &n);
	lua_pushnumber(n);
	return;
}

/* pushuserdata(number)
Global function
Pushes a memory address 'number' onto the Lua stack as a userdata
The memory address can be a decimal number, or a string hexadecimal number starting with "0x" */
void LUA_PushUserdata() {
	int address = 0;

	lua_Object arg1 = lua_lua2C(1);
	if (IElua_getparam(1, g_IETagNumber)) {
		address = (int)IElua_getnumber(arg1);
	} else if (IElua_getparam(1, g_IETagString)) {
		sscanf_s(IElua_getstring(arg1), "0x%x", &address);
	} else {
		IElua_error_badarg("pushuserdata", 1, "number or string");
		return;
	}

	if (lua_lua2C(2)) {
		IElua_error_toomanyargs("pushuserdata");
		return;
	}

	lua_pushusertag((void*)address, 0);
	return;
}

/* u2n(userdata)
Global function
Pushes the memory address from 'userdata' as a number onto the Lua stack */
void LUA_U2N() {
	void* u = NULL;

	lua_Object arg1 = lua_lua2C(1);
	if (IElua_getparam(1, g_IETagUserdata)) {
		u = IElua_getuserdata(arg1);
	} else {
		IElua_error_badarg("u2n", 2, "userdata");
		return;
	}

	if (lua_lua2C(2)) {
		IElua_error_toomanyargs("u2n");
		return;
	}

	lua_pushnumber((int)u);
	return;
}

/* pushfunction(number)
Global function
Pushes a memory address 'number' onto the Lua stack as a cfunction
The memory address can be a decimal number, or a string hexadecimal number starting with "0x" */
void LUA_PushFunction() {
	unsigned int address = 0;

	lua_Object arg1 = lua_lua2C(1);
	if (IElua_getparam(1, g_IETagNumber)) {
		address = (unsigned int)IElua_getnumber(arg1);
	} else if (IElua_getparam(1, g_IETagString)) {
		sscanf_s(IElua_getstring(arg1), "0x%x", &address);
	} else {
		IElua_error_badarg("pushcfunction", 1, "number or string");
		return;
	}

	if (lua_lua2C(2)) {
		IElua_error_toomanyargs("pushcfunction");
		return;
	}

	lua_pushcfunction(reinterpret_cast<lua_CFunction>(address));
	return;
}

/* getsprite({enum|"scriptname"})
Global function
Pushes the memory address of a sprite onto the Lua stack
The sprite can be referenced either by its enum (as decimal number of a string containing a hexadecimal number starting with "0x") or scriptname */
void LUA_GetSprite() {
	Object o;
	ENUM e = ENUM_INVALID_INDEX;
	void* u = NULL;

	lua_Object arg1 = lua_lua2C(1);
	if (IElua_getparam(1, g_IETagNumber)) {
		e = (ENUM)IElua_getnumber(arg1);
	} else if (IElua_getparam(1, g_IETagString)) {
		sscanf_s(IElua_getstring(arg1), "0x%x", &e);
		if (e == 0 || e == ENUM_INVALID_INDEX) {
			o.m_sName = IElua_getstring(arg1);
			o.m_sName.MakeUpper();
		}
	} else {
		IElua_error_badarg("getsprite", 1, "number or string");
		return;
	}

	if (lua_lua2C(2)) {
		IElua_error_toomanyargs("getsprite");
		return;
	}

	CGameSprite* pSprite = NULL;
	if (e == ENUM_INVALID_INDEX) {
		e = g_pChitin->GetInfGame().m_ePlayersJoinOrder[0];
	}

	char nReturnVal;
	if (g_pChitin->GetInfGame().m_GameObjectArray.GetObject(e, &pSprite) == OBJECT_SUCCESS && pSprite) {
		if (o.m_sName.IsEmpty()) {
			u = pSprite;
		} else {
			o.DecodeIdentifiers(*pSprite);
			u = &o.FindTargetOfType(*pSprite, CGAMEOBJECT_TYPE_SPRITE, FALSE);
		}
		if (u) {
			lua_pushusertag(u, 0);
		} else {
			lua_error("Cannot find object");
		}
	} else {
		lua_error("GetObject failed");
	}

	return;
}

/* createobject(userdata, [type])
Global function
Pushes a table containing a fixed memory address 'userdata' and type 'type' onto the Lua stack
The object gains all the functions under the tag TobExObject
'type' can be explicitly named so that functions such as print() can output correctly */
void LUA_CreateObject() {
	void* u = NULL;
	char* type = NULL;

	lua_Object arg1 = lua_lua2C(1); //userdata
	if (IElua_getparam(1, g_IETagUserdata)) {
		u = lua_getuserdata(arg1);
	} else {
		IElua_error_badarg("createobject", 1, "userdata");
		return;
	}

	lua_Object arg2 = lua_lua2C(2);
	if (arg2) {
		if (IElua_getparam(2, g_IETagString)) {
			type = IElua_getstring(arg2);
		} else {
			IElua_error_badarg("createobject", 2, "string");
			return;
		}
	}

	if (lua_lua2C(3)) {
		IElua_error_toomanyargs("createobject");
		return;
	}

	lua_beginblock();

	lua_Object g = lua_createtable();
	lua_pushobject(g);
	lua_settag(g_TagObjects);

	lua_pushobject(g);
	lua_pushstring("userdata");
	lua_pushusertag(u, 0);
	lua_rawsettable();

	lua_pushobject(g);
	lua_pushstring("type");
	type ? lua_pushstring(type) : lua_pushstring("notype");
	lua_rawsettable();

	lua_endblock();

	lua_pushobject(g);

	return;
}

void LUA_InitObjectTagMethods(int tag) {
	IElua_settaggetmethod(tag, "operator_index_get", LUA_OpIndexGet);
	IElua_settagsetmethod(tag, "operator_index_set", LUA_OpIndexSet);
	IElua_settagmethod(tag, "cdecl", LUA_CDecl);
	IElua_settagmethod(tag, "stdcall", LUA_StdCall);
	IElua_settagmethod(tag, "getaddress", LUA_GetAddress);
	IElua_settagmethod(tag, "getpointer", LUA_GetPointer);
	IElua_settagmethod(tag, "getbyte", LUA_GetByte);
	IElua_settagmethod(tag, "getword", LUA_GetWord);
	IElua_settagmethod(tag, "getdword", LUA_GetDword);
	IElua_settagmethod(tag, "getstring", LUA_GetString);
	IElua_settagmethod(tag, "getlist", LUA_GetList);
	IElua_settagmethod(tag, "print", LUA_Print);
	return;
}

/* operator_index_get()
Addendum to tag method 'gettable' for TobExObject
Gets the value associated with table 'var' index 'index' as per var.index */
BOOL LUA_OpIndexGet(lua_Object var, lua_Object index) {
	lua_Object o;

	if (lua_isnil(index)) return FALSE;

	lua_beginblock();
	lua_pushobject(var);
	lua_pushobject(index);
	o = lua_rawgettable();
	lua_endblock();

	if (!lua_isnil(o)) {
		lua_pushobject(o);
		return TRUE;
	} else {
		return FALSE;
	}
}

/* operator_index_set()
Addendum to tag method 'settable' for TobExObject
Sets the value associated with table 'var' index 'index' as per var.index = value
To encapsulate data, this will only set existing indices */
BOOL LUA_OpIndexSet(lua_Object var, lua_Object index, lua_Object value) {
	if (lua_isnil(index)) return FALSE;

	lua_beginblock();
	lua_pushobject(var);
	lua_pushobject(index);
	lua_pushobject(value);
	lua_rawsettable();
	
	lua_endblock();
	return TRUE;
}

/* cdecl(function, [args]...)
Tag method for TobExObject
Calls the __cdecl C function 'function', pushing options 'args' onto the stack
Lua functions and tables are ignored if used as arguments, while nil or non-existent arguments terminate the argument list
The object is placed into ecx as per __thiscall
The return value eax is pushed onto the Lua stack as a userdata, since pointer return values lose precision from float32 conversions */
void LUA_CDecl() {
	unsigned int address_this = 0; //address of this pointer
	void* f = NULL; //function
	int r = 0; //return value
	int num = 0; //number argument
	char* sz = NULL; //string argument
	void* p = NULL; //pointer/cfunction argument
	int shift = 0; //stack pointer shift
	lua_Object argx; //argument lua_Object
	int i = 3; //starting position of function arguments

	lua_beginblock();

	lua_Object arg1 = lua_lua2C(1); //self
	if (!lua_istable(arg1)) {
		IElua_error_badarg("cdecl", 1, "self");
		return;
	}
	
	lua_pushobject(arg1);
	lua_pushstring("userdata");
	lua_Object userdata = lua_rawgettable();

	if (!lua_isuserdata(userdata)) {
		lua_error("expected type userdata in self.userdata");
		return;
	}
	address_this = (unsigned int)lua_getuserdata(userdata);

	lua_Object arg2 = lua_lua2C(2); //function
	if (!lua_iscfunction(arg2)) {
		IElua_error_badarg("cdecl", 1, "cfunction");
		return;
	}
	f = (void*)lua_getcfunction(arg2);

	while (argx = lua_lua2C(i)) {
		if (lua_isnil(argx)) break;
		i++;
	} //i = total number of arguments

	for (i -= 4; i >= 0; i--) {
		argx = lua_lua2C(i + 3);
		if (lua_isnumber(argx)) {
			num = (int)lua_getnumber(argx);
			_asm push num;
			shift += 4;
		} else if (lua_isstring(argx)) {
			sz = lua_getstring(argx);
			_asm push sz;
			shift += 4;
		} else if (lua_isuserdata(argx)) {
			p = lua_getuserdata(argx);
			_asm push p;
			shift += 4;
		} else if (lua_iscfunction(argx)) {
			p = (void*)lua_getcfunction(argx);
			_asm push p;
			shift += 4;
		}
	}

	lua_endblock();

	_asm mov ecx, address_this;
	_asm call f;
	_asm add esp, shift;
	_asm mov r, eax;

	//float32 precision is lost when returning pointers, so don't use lua_pushnumber
	lua_pushusertag((void*)r, 0);
	return;
}

/* stdcall(function, [args]...)
Tag method for TobExObject
Calls the __stdcall C function 'function', pushing options 'args' onto the stack
Lua functions and tables are ignored if used as arguments, while nil or non-existent arguments terminate the argument list
The object is placed into ecx as per __thiscall
If too many or too few arguments are supplied for the function, the stack pointer is corrected
The return value eax is pushed onto the Lua stack as a userdata, since pointer return values lose precision from float32 conversions */
void LUA_StdCall() {
	unsigned int address_this = 0; //address of this pointer
	void* f = NULL; //function
	int r = 0; //return value
	int num = 0; //number argument
	char* sz = NULL; //string argument
	void* p = NULL; //pointer/cfunction argument
	lua_Object argx; //argument lua_Object
	int i = 3; //starting position of function arguments

	DWORD EspBefore;
	DWORD EspAfter;
	_asm mov EspBefore, esp;

	lua_beginblock();

	lua_Object arg1 = lua_lua2C(1); //self
	if (!lua_istable(arg1)) {
		IElua_error_badarg("stdcall", 1, "self");
		return;
	}
	
	lua_pushobject(arg1);
	lua_pushstring("userdata");
	lua_Object userdata = lua_rawgettable();

	if (!lua_isuserdata(userdata)) {
		lua_error("expected type userdata in self.userdata");
		return;
	}
	address_this = (unsigned int)lua_getuserdata(userdata);

	lua_Object arg2 = lua_lua2C(2); //function
	if (!lua_iscfunction(arg2)) {
		IElua_error_badarg("stdcall", 1, "cfunction");
		return;
	}
	f = (void*)lua_getcfunction(arg2);

	while (argx = lua_lua2C(i)) {
		if (lua_isnil(argx)) break;
		i++;
	} //i = total number of arguments

	for (i -= 4; i >= 0; i--) {
		argx = lua_lua2C(i + 3);
		if (lua_isnumber(argx)) {
			num = (int)lua_getnumber(argx);
			_asm push num;
		} else if (lua_isstring(argx)) {
			sz = lua_getstring(argx);
			_asm push sz;
		} else if (lua_isuserdata(argx)) {
			p = lua_getuserdata(argx);
			_asm push p;
		} else if (lua_iscfunction(argx)) {
			p = (void*)lua_getcfunction(argx);
			_asm push p;
		}
	}

	lua_endblock();

	_asm mov ecx, address_this;
	_asm call f;
	_asm mov EspAfter, esp;
	_asm mov r, eax;

	if (EspBefore != EspAfter) {
		console.writef("LUA_StdCall(): Stack pointer mismatch! (Before = 0x%X -> After = 0x%X\r\n", EspBefore, EspAfter);
		_asm mov esp, EspBefore;
	}

	//float32 precision is lost when returning pointers, so don't use lua_pushnumber
	lua_pushusertag((void*)r, 0);
	return;
}

/* getaddress(address)
Tag method for TobExObject
Pushes a userdata onto the Lua stack referencing 'address' relative to the object 
The memory address can be a decimal number, or a string hexadecimal number starting with "0x" */
void LUA_GetAddress() {
	unsigned int address_base = 0;
	unsigned int address_rel = 0;

	lua_beginblock();

	lua_Object arg1 = lua_lua2C(1); //self
	if (!lua_istable(arg1)) {
		IElua_error_badarg("getaddress", 1, "self");
		return;
	}
	
	lua_pushobject(arg1);
	lua_pushstring("userdata");
	lua_Object userdata = lua_rawgettable();

	if (!lua_isuserdata(userdata)) {
		lua_error("expected type userdata in self.userdata");
		return;
	}
	address_base = (unsigned int)lua_getuserdata(userdata);

	lua_Object arg2 = lua_lua2C(2);
	if (IElua_getparam(2, g_IETagNumber)) {
		address_rel = (unsigned int)IElua_getnumber(arg2);
	} else if (IElua_getparam(2, g_IETagString)) {
		sscanf_s(IElua_getstring(arg2), "0x%x", &address_rel);
	} else {
		IElua_error_badarg("getaddress", 2, "number or string");
		return;
	}

	if (lua_lua2C(3)) {
		IElua_error_toomanyargs("getaddress");
		return;
	}

	lua_endblock();

	lua_pushusertag((void*)(address_base + address_rel), 0);

	return;
}

/* getpointer(address)
Tag method for TobExObject
Pushes a userdata onto the Lua stack at 'address' relative to the object 
The memory address can be a decimal number, or a string hexadecimal number starting with "0x" */
void LUA_GetPointer() {
	unsigned int address_base = 0;
	unsigned int address_rel = 0;

	lua_beginblock();

	lua_Object arg1 = lua_lua2C(1); //self
	if (!lua_istable(arg1)) {
		IElua_error_badarg("getpointer", 1, "self");
		return;
	}
	
	lua_pushobject(arg1);
	lua_pushstring("userdata");
	lua_Object userdata = lua_rawgettable();

	if (!lua_isuserdata(userdata)) {
		lua_error("expected type userdata in self.userdata");
		return;
	}
	address_base = (unsigned int)lua_getuserdata(userdata);

	lua_Object arg2 = lua_lua2C(2);
	if (IElua_getparam(2, g_IETagNumber)) {
		address_rel = (unsigned int)IElua_getnumber(arg2);
	} else if (IElua_getparam(2, g_IETagString)) {
		sscanf_s(IElua_getstring(arg2), "0x%x", &address_rel);
	} else {
		IElua_error_badarg("getpointer", 2, "number or string");
		return;
	}

	if (lua_lua2C(3)) {
		IElua_error_toomanyargs("getpointer");
		return;
	}

	lua_endblock();

	lua_pushusertag((void*)(*(int*)(address_base + address_rel)), 0);

	return;
}

/* getbyte(address)
Tag method for TobExObject
Pushes a char (IE byte) onto the Lua stack at 'address' relative to the object 
The memory address can be a decimal number, or a string hexadecimal number starting with "0x" */
void LUA_GetByte() {
	unsigned int address_base = 0;
	unsigned int address_rel = 0;

	lua_beginblock();

	lua_Object arg1 = lua_lua2C(1); //self
	if (!lua_istable(arg1)) {
		IElua_error_badarg("getbyte", 1, "self");
		return;
	}
	
	lua_pushobject(arg1);
	lua_pushstring("userdata");
	lua_Object userdata = lua_rawgettable();

	if (!lua_isuserdata(userdata)) {
		lua_error("expected type userdata in self.userdata");
		return;
	}
	address_base = (unsigned int)lua_getuserdata(userdata);

	lua_Object arg2 = lua_lua2C(2);
	if (IElua_getparam(2, g_IETagNumber)) {
		address_rel = (unsigned int)IElua_getnumber(arg2);
	} else if (IElua_getparam(2, g_IETagString)) {
		sscanf_s(IElua_getstring(arg2), "0x%x", &address_rel);
	} else {
		IElua_error_badarg("getbyte", 2, "number or string");
		return;
	}

	if (lua_lua2C(3)) {
		IElua_error_toomanyargs("getbyte");
		return;
	}

	lua_endblock();

	lua_pushnumber(*(char*)(address_base + address_rel));
	return;
}

/* getword(address)
Tag method for TobExObject
Pushes a short (IE word) onto the Lua stack at 'address' relative to the object 
The memory address can be a decimal number, or a string hexadecimal number starting with "0x" */
void LUA_GetWord() {
	unsigned int address_base = 0;
	unsigned int address_rel = 0;

	lua_beginblock();

	lua_Object arg1 = lua_lua2C(1); //self
	if (!lua_istable(arg1)) {
		IElua_error_badarg("getword", 1, "self");
		return;
	}
	
	lua_pushobject(arg1);
	lua_pushstring("userdata");
	lua_Object userdata = lua_rawgettable();

	if (!lua_isuserdata(userdata)) {
		lua_error("expected type userdata in self.userdata");
		return;
	}
	address_base = (unsigned int)lua_getuserdata(userdata);

	lua_Object arg2 = lua_lua2C(2);
	if (IElua_getparam(2, g_IETagNumber)) {
		address_rel = (unsigned int)IElua_getnumber(arg2);
	} else if (IElua_getparam(2, g_IETagString)) {
		sscanf_s(IElua_getstring(arg2), "0x%x", &address_rel);
	} else {
		IElua_error_badarg("getword", 2, "number or string");
		return;
	}

	if (lua_lua2C(3)) {
		IElua_error_toomanyargs("getword");
		return;
	}

	lua_endblock();

	lua_pushnumber(*(short*)(address_base + address_rel));
	return;
}

/* getdword(address)
Tag method for TobExObject
Pushes an int (IE dword) onto the Lua stack at 'address' relative to the object 
The memory address can be a decimal number, or a string hexadecimal number starting with "0x" */
void LUA_GetDword() {
	unsigned int address_base = 0;
	unsigned int address_rel = 0;

	lua_beginblock();

	lua_Object arg1 = lua_lua2C(1); //self
	if (!lua_istable(arg1)) {
		IElua_error_badarg("getdword", 1, "self");
		return;
	}
	
	lua_pushobject(arg1);
	lua_pushstring("userdata");
	lua_Object userdata = lua_rawgettable();

	if (!lua_isuserdata(userdata)) {
		lua_error("expected type userdata in self.userdata");
		return;
	}
	address_base = (unsigned int)lua_getuserdata(userdata);

	lua_Object arg2 = lua_lua2C(2);
	if (IElua_getparam(2, g_IETagNumber)) {
		address_rel = (unsigned int)IElua_getnumber(arg2);
	} else if (IElua_getparam(2, g_IETagString)) {
		sscanf_s(IElua_getstring(arg2), "0x%x", &address_rel);
	} else {
		IElua_error_badarg("getdword", 2, "number or string");
		return;
	}

	if (lua_lua2C(3)) {
		IElua_error_toomanyargs("getdword");
		return;
	}

	lua_endblock();

	lua_pushnumber(*(int*)(address_base + address_rel));
	return;
}

/* getstring(address, [length])
Tag method for TobExObject
Pushes a string onto the Lua stack at 'address' relative to the object
The memory address can be a decimal number, or a string hexadecimal number starting with "0x"
Optionally, a specific 'length' can be set for the string */
void LUA_GetString() {
	unsigned int address_base = 0;
	unsigned int address_rel = 0;
	unsigned int length = 100;

	lua_beginblock();

	lua_Object arg1 = lua_lua2C(1); //self
	if (!lua_istable(arg1)) {
		IElua_error_badarg("getstring", 1, "self");
		return;
	}
	
	lua_pushobject(arg1);
	lua_pushstring("userdata");
	lua_Object userdata = lua_rawgettable();

	if (!lua_isuserdata(userdata)) {
		lua_error("expected type userdata in self.userdata");
		return;
	}
	address_base = (unsigned int)lua_getuserdata(userdata);

	lua_Object arg2 = lua_lua2C(2);
	if (IElua_getparam(2, g_IETagNumber)) {
		address_rel = (unsigned int)IElua_getnumber(arg2);
	} else if (IElua_getparam(2, g_IETagString)) {
		sscanf_s(IElua_getstring(arg2), "0x%x", &address_rel);
	} else {
		IElua_error_badarg("getstring", 2, "number or string");
		return;
	}

	lua_Object arg3 = lua_lua2C(3);
	if (arg3) {
		if (IElua_getparam(3, g_IETagNumber)) {
			length = IElua_getnumber(arg3);
		} else {
		IElua_error_badarg("getstring", 3, "number");
		return;
		}
	}

	if (lua_lua2C(4)) {
		IElua_error_toomanyargs("getstring");
		return;
	}

	lua_endblock();

	IECString s = (LPCSTR)(address_base + address_rel);
	s = s.Left(length);
	lua_pushstring(s.GetBuffer(0));
	return;
}

/* getlist(address)
Tag method for TobExObject
Pushes a table onto the Lua stack derived from a CPtrList at 'address' relative to the object
The memory address can be a decimal number, or a string hexadecimal number starting with "0x"
The index of the table is the index from the head of a MFC CList object, and the value is its corresponding value */
void LUA_GetList() {
	unsigned int address_base = 0;
	unsigned int address_rel = 0;

	lua_beginblock();

	lua_Object arg1 = lua_lua2C(1); //self
	if (!lua_istable(arg1)) {
		IElua_error_badarg("getlist", 1, "self");
		return;
	}
	
	lua_pushobject(arg1);
	lua_pushstring("userdata");
	lua_Object userdata = lua_rawgettable();

	if (!lua_isuserdata(userdata)) {
		lua_error("expected type userdata in self.userdata");
		return;
	}
	address_base = (unsigned int)lua_getuserdata(userdata);

	lua_Object arg2 = lua_lua2C(2);
	if (IElua_getparam(2, g_IETagNumber)) {
		address_rel = (unsigned int)IElua_getnumber(arg2);
	} else if (IElua_getparam(2, g_IETagString)) {
		sscanf_s(IElua_getstring(arg2), "0x%x", &address_rel);
	} else {
		IElua_error_badarg("getlist", 2, "number or string");
		return;
	}

	if (lua_lua2C(3)) {
		IElua_error_toomanyargs("getlist");
		return;
	}

	CPtrList* pList = (CPtrList*)(address_base + address_rel);
	POSITION pos = pList->GetHeadPosition();
	
	if (!pos) {
		lua_endblock();
		lua_pushnil();
		return;
	}

	lua_Object table = lua_createtable();
	unsigned int index = 0;

	while (pos) {
		void* ptr = pList->GetNext(pos);
		lua_pushobject(table);
		lua_pushnumber(index);
		lua_pushusertag(ptr, 0);
		lua_rawsettable();
		index++;
	}

	lua_endblock();

	lua_pushobject(table);
	return;
}

/* print([to_console])
Tag method for TobExObject
Dumps information about the object based on its type onto the dialogue window */
void LUA_Print() {
	void* pObject = NULL;
	int nType = 0;
	char* szType = NULL;
	bool bPrint = false;

	lua_beginblock();

	lua_Object arg1 = lua_lua2C(1); //self
	if (!lua_istable(arg1)) {
		IElua_error_badarg("print", 1, "self");
		return;
	}
	
	lua_pushobject(arg1);
	lua_pushstring("userdata");
	lua_Object userdata = lua_rawgettable();

	if (!lua_isuserdata(userdata)) {
		lua_error("expected type userdata in self.userdata");
		return;
	}
	pObject = lua_getuserdata(userdata);

	lua_pushobject(arg1);
	lua_pushstring("type");
	lua_Object type = lua_rawgettable();
	szType = lua_isstring(type) ? lua_getstring(type) : "notype";

	lua_Object arg2 = lua_lua2C(2);
	if (arg2) {
		if (IElua_getparam(2, g_IETagNumber)) {
			bPrint = (bool)IElua_getnumber(arg2);
		} else {
		IElua_error_badarg("print", 2, "number");
		return;
		}
	}

	if (lua_lua2C(3)) {
		IElua_error_toomanyargs("print");
		return;
	}

	lua_endblock();

	IECString sRight;
	IECString sDump;

	//work out what to dump based on type
	if (szType) {
		std::map<char*, LUA_DumpFunc, cmp_str>::iterator it = g_DumpFunctions.find(szType);
		if (it != g_DumpFunctions.end()) {
			sDump = it->second(pObject);
		} else {
			sDump = "no dump function";
		}
	} else {
		sDump = "no type info";
	}

	if (bPrint) {
		sRight.Format("%s: %X -> %s", szType, (unsigned int)pObject, (LPCTSTR)sDump);
		g_pChitin->GetWorld().PrintToConsole(IECString(), IECString(sRight), -1, 0);
	} else {
		sRight.Format("%s", (LPCTSTR)sDump);
		lua_pushstring(sRight.GetBuffer(0));
	}

	return;
}
