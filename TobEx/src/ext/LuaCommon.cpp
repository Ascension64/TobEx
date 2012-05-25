#include "LuaCommon.h"
#include "LuaDump.h"

#include "chitin.h"

/* LUA_Init()
Called at the beginning of CBaldurChitin constructor
Initialises the TobExUser tag containing all the functions available for objects
Initialises all the output for the print() functions
Creates new global functions that can be used with Lua */
void __stdcall LUA_Init() {
	g_TagObjects = IElua_createtag("TobExUser");
	LUA_InitObjectTagMethods(g_TagObjects);
	LUADump_Init();

	lua_beginblock();
	
	lua_pushcfunction(lua_beginblock);
	lua_setglobal("beginblock");
	
	lua_pushcfunction(lua_endblock);
	lua_setglobal("endblock");

	lua_pushcfunction(LUA_PushUserdata);
	lua_setglobal("pushuserdata");

	lua_pushcfunction(LUA_PushFunction);
	lua_setglobal("pushcfunction");

	lua_pushcfunction(LUA_CreateObject);
	lua_setglobal("createobject");
	
	lua_pushcfunction(LUA_DeleteObject);
	lua_setglobal("deleteobject");

	lua_pushcfunction(LUA_GetCurrentArea);
	lua_setglobal("getcurrentarea");

	lua_pushcfunction(LUA_GetCurrentCreature);
	lua_setglobal("getcurrentcreature");

	lua_endblock();
	return;
}

/* pushuserdata(address)
Global function
Pushes a fixed memory address onto the C2Lua stack
The memory address can be a decimal number, or a hexadecimal number if bounded in quotes */
void LUA_PushUserdata() {
	int address = 0;
	IETag tag = 0;

	lua_Object arg1 = lua_lua2C(1);
	if (IElua_getparam(1, g_IETagNumber)) {
		address = (int)IElua_getnumber(arg1);
	} else if (IElua_getparam(1, g_IETagString)) {
		sscanf_s(IElua_getstring(arg1), "%8X", &address);
	} else {
		IElua_error_badarg("pushuserdata", 1, "number or string");
		return;
	}

	lua_Object arg2 = lua_lua2C(2);
	if (arg2 &&
		IElua_getparam(2, g_IETagNumber)) {
		tag = (int)IElua_getnumber(arg2);
	}

	if (lua_lua2C(3)) {
		IElua_error_toomanyargs("pushuserdata");
		return;
	}

	lua_pushusertag((void*)address, tag);
	return;
}

/* pushfunction(address)
Global function
Pushes a fixed memory address onto the C2Lua stack as a C function
The memory address can be a decimal number, or a hexadecimal number if bounded in quotes 
This function is bound to crash. DO NOT USE! */
void LUA_PushFunction() {
	unsigned int address = 0;
	IETag tag = 0;

	lua_Object arg1 = lua_lua2C(1);
	if (IElua_getparam(1, g_IETagNumber)) {
		address = (unsigned int)IElua_getnumber(arg1);
	} else if (IElua_getparam(1, g_IETagString)) {
		sscanf_s(IElua_getstring(arg1), "%8X", &address);
	} else {
		IElua_error_badarg("pushcfunction", 1, "number or string");
		return;
	}

	if (lua_lua2C(2)) {
		IElua_error_toomanyargs("pushuserdata");
		return;
	}

	lua_pushcfunction(reinterpret_cast<lua_CFunction>(address));
	return;
}

/* createobject(name, userdata, type)
Global function
Creates a global object with 'name' of 'type' referencing the fixed memory address 'userdata'
The object gains all the functions under the tag TobExUser
'type' needs to be specifically named so that functions such as print() can output correctly
The object references a table stored in 'toLua_mate' */
void LUA_CreateObject() {
	void* u = NULL;
	char* name = NULL;
	char* type = NULL;

	lua_Object arg1 = lua_lua2C(1); //name
	if (IElua_getparam(1, g_IETagString)) {
		name = IElua_getstring(arg1);
		if (!strcmp(name, "")) {
			lua_error("nul name supplied for createobject");
		}
	} else {
		IElua_error_badarg("createobject", 1, "string");
		return;
	}

	lua_Object arg2 = lua_lua2C(2); //userdata
	if (IElua_getparam(2, g_IETagUserdata)) {
		u = lua_getuserdata(arg2);
		if (!u) {
			lua_error("nul reference supplied for createobject");
			return;
		}
	} else {
		IElua_error_badarg("createobject", 2, "userdata");
		return;
	}

	lua_Object arg3 = lua_lua2C(3);
	if (arg3 &&
		IElua_getparam(3, g_IETagString)) {
		type = IElua_getstring(arg3);
	}

	if (lua_lua2C(4)) {
		IElua_error_toomanyargs("createobject");
		return;
	}

	lua_beginblock();

	lua_Object g = lua_getglobal(name);
	bool bValid = true;
	if (!lua_isnil(g)) {
		//if exists, check if already an object created by this function
		if (lua_istable(g)) {
			lua_pushobject(g);
			lua_pushstring("name");
			if (!lua_isstring(lua_gettable())) bValid = false;

			lua_pushobject(g);
			lua_pushstring("userdata");
			if (!lua_isuserdata(lua_gettable())) bValid = false;

			lua_pushobject(g);
			lua_pushstring("type");
			if (!lua_isstring(lua_gettable())) bValid = false;

			if (lua_tag(g) != g_TagObjects) bValid = false;
		} else {
			sprintf_s(g_szIEluaError, g_szIEluaErrorSize, "%s is not an object", name);
			lua_error(g_szIEluaError);
		}
	} else {
		g = lua_createtable();
		lua_pushobject(g);
		lua_settag(g_TagObjects);
	}

	if (bValid) {
		lua_pushobject(g);
		lua_pushstring("name");
		lua_pushstring(name);
		lua_settable();
	
		lua_pushobject(g);
		lua_pushstring("userdata");
		lua_pushusertag(u, 0);
		lua_settable();

		lua_pushobject(g);
		lua_pushstring("type");
		type ? lua_pushstring(type) : lua_pushstring("notype");
		lua_settable();

		lua_pushobject(g);
		lua_setglobal(name);
	}

	lua_endblock();

	return;
}

/* deleteobject(name)
Deletes the global object with 'name' */
void LUA_DeleteObject() {
	char* name = NULL;

	lua_Object arg1 = lua_lua2C(1); //name
	if (IElua_getparam(1, g_IETagString)) {
		name = IElua_getstring(arg1);
		if (!strcmp(name, "")) {
			lua_error("nul name supplied for deleteobject");
			return;
		}
	} else {
		IElua_error_badarg("deleteobject", 1, "string");
		return;
	}

	if (lua_lua2C(2)) {
		IElua_error_toomanyargs("deleteobject");
		return;
	}

	lua_beginblock();

	lua_Object g = lua_getglobal(name);
	bool bValid = true;
	if (!lua_isnil(g)) {
		//check if exists
		if (lua_istable(g)) {
			lua_pushobject(g);
			lua_pushstring("name");
			if (!lua_isstring(lua_gettable())) bValid = false;

			lua_pushobject(g);
			lua_pushstring("userdata");
			if (!lua_isuserdata(lua_gettable())) bValid = false;

			lua_pushobject(g);
			lua_pushstring("type");
			if (!lua_isstring(lua_gettable())) bValid = false;

			if (lua_tag(g) != g_TagObjects) bValid = false;
		} else {
			sprintf_s(g_szIEluaError, g_szIEluaErrorSize, "%s is not an object", name);
			lua_error(g_szIEluaError);
		}
	} else {
		//does not exist
		sprintf_s(g_szIEluaError, g_szIEluaErrorSize, "%s is not an object", name);
		lua_error(g_szIEluaError);
	}

	if (bValid) {
		lua_pushobject(lua_getref(g_tableref_toLua_mate));
		lua_pushobject(g);
		if (!lua_isnil(lua_rawgettable())) {
			lua_pushobject(lua_getref(g_tableref_toLua_mate));
			lua_pushobject(g);
			lua_pushnil();
			lua_rawsettable();
		}

		lua_pushnil();
		lua_setglobal(name);
	}

	lua_endblock();

	return;
}

void LUA_InitObjectTagMethods(int tag) {
	IElua_settagmethod(tag, "getpointer", LUA_GetPointer);
	IElua_settagmethod(tag, "getbyte", LUA_GetByte);
	IElua_settagmethod(tag, "getword", LUA_GetWord);
	IElua_settagmethod(tag, "getdword", LUA_GetDword);
	IElua_settagmethod(tag, "getstring", LUA_GetString);
	IElua_settagmethod(tag, "getlist", LUA_GetList);
	IElua_settagmethod(tag, "print", LUA_Print);
	return;
}

/* getpointer(address)
Tag method for TobExUser
Pushes a fixed memory address onto the Lua stack at 'address' relative to the object 
The memory address can be a decimal number, or a hexadecimal number if bounded in quotes */
void LUA_GetPointer() {
	unsigned int address_base = 0;
	unsigned int address_rel = 0;

	lua_beginblock();

	lua_Object arg1 = lua_lua2C(1); //self
	if (!lua_istable(arg1)) {
		IElua_error_badarg("getuserdata", 1, "self");
		return;
	}
	
	lua_pushobject(arg1);
	lua_pushstring("userdata");
	lua_Object userdata = lua_gettable();

	if (!lua_isuserdata(userdata)) {
		lua_error("expected type userdata in self.userdata");
		return;
	}
	address_base = (unsigned int)lua_getuserdata(userdata);

	lua_Object arg2 = lua_lua2C(2);
	if (IElua_getparam(2, g_IETagNumber)) {
		address_rel = (unsigned int)IElua_getnumber(arg2);
	} else if (IElua_getparam(2, g_IETagString)) {
		sscanf_s(IElua_getstring(arg2), "%8X", &address_rel);
	} else {
		IElua_error_badarg("getuserdata", 2, "number or string");
		return;
	}

	if (lua_lua2C(3)) {
		IElua_error_toomanyargs("getuserdata");
		return;
	}

	lua_endblock();

	lua_pushusertag((void*)(address_base + address_rel), 0);

	return;
}

/* getbyte(address)
Tag method for TobExUser
Pushes a char (IE byte) onto the Lua stack at 'address' relative to the object 
The memory address can be a decimal number, or a hexadecimal number if bounded in quotes */
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
	lua_Object userdata = lua_gettable();

	if (!lua_isuserdata(userdata)) {
		lua_error("expected type userdata in self.userdata");
		return;
	}
	address_base = (unsigned int)lua_getuserdata(userdata);

	lua_Object arg2 = lua_lua2C(2);
	if (IElua_getparam(2, g_IETagNumber)) {
		address_rel = (unsigned int)IElua_getnumber(arg2);
	} else if (IElua_getparam(2, g_IETagString)) {
		sscanf_s(IElua_getstring(arg2), "%8X", &address_rel);
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
Tag method for TobExUser
Pushes a short (IE word) onto the Lua stack at 'address' relative to the object 
The memory address can be a decimal number, or a hexadecimal number if bounded in quotes */
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
	lua_Object userdata = lua_gettable();

	if (!lua_isuserdata(userdata)) {
		lua_error("expected type userdata in self.userdata");
		return;
	}
	address_base = (unsigned int)lua_getuserdata(userdata);

	lua_Object arg2 = lua_lua2C(2);
	if (IElua_getparam(2, g_IETagNumber)) {
		address_rel = (unsigned int)IElua_getnumber(arg2);
	} else if (IElua_getparam(2, g_IETagString)) {
		sscanf_s(IElua_getstring(arg2), "%8X", &address_rel);
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
Tag method for TobExUser
Pushes an int (IE dword) onto the Lua stack at 'address' relative to the object 
The memory address can be a decimal number, or a hexadecimal number if bounded in quotes */
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
	lua_Object userdata = lua_gettable();

	if (!lua_isuserdata(userdata)) {
		lua_error("expected type userdata in self.userdata");
		return;
	}
	address_base = (unsigned int)lua_getuserdata(userdata);

	lua_Object arg2 = lua_lua2C(2);
	if (IElua_getparam(2, g_IETagNumber)) {
		address_rel = (unsigned int)IElua_getnumber(arg2);
	} else if (IElua_getparam(2, g_IETagString)) {
		sscanf_s(IElua_getstring(arg2), "%8X", &address_rel);
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

/* getstring(address [, length])
Tag method for TobExUser
Pushes a string onto the Lua stack at 'address' relative to the object
The memory address can be a decimal number, or a hexadecimal number if bounded in quotes
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
	lua_Object userdata = lua_gettable();

	if (!lua_isuserdata(userdata)) {
		lua_error("expected type userdata in self.userdata");
		return;
	}
	address_base = (unsigned int)lua_getuserdata(userdata);

	lua_Object arg2 = lua_lua2C(2);
	if (IElua_getparam(2, g_IETagNumber)) {
		address_rel = (unsigned int)IElua_getnumber(arg2);
	} else if (IElua_getparam(2, g_IETagString)) {
		sscanf_s(IElua_getstring(arg2), "%8X", &address_rel);
	} else {
		IElua_error_badarg("getstring", 2, "number or string");
		return;
	}

	lua_Object arg3 = lua_lua2C(3);
	if (arg3 &&
		IElua_getparam(3, g_IETagNumber)) {
		length = IElua_getnumber(arg3);
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
Tag method for TobExUser
Pushes a table onto the Lua stack derived from a CPtrList at 'address' relative to the object
The index of the table is the index from the head of a MFC CList object, and the value is its corresponding value
The memory address can be a decimal number, or a hexadecimal number if bounded in quotes */
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
	lua_Object userdata = lua_gettable();

	if (!lua_isuserdata(userdata)) {
		lua_error("expected type userdata in self.userdata");
		return;
	}
	address_base = (unsigned int)lua_getuserdata(userdata);

	lua_Object arg2 = lua_lua2C(2);
	if (IElua_getparam(2, g_IETagNumber)) {
		address_rel = (unsigned int)IElua_getnumber(arg2);
	} else if (IElua_getparam(2, g_IETagString)) {
		sscanf_s(IElua_getstring(arg2), "%8X", &address_rel);
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

/* print()
Tag method for TobExUser
Dumps information about the object based on its type onto the dialogue window */
void LUA_Print() {
	void* pObject = NULL;
	int nType = 0;
	char* szType = NULL;

	lua_beginblock();

	lua_Object arg1 = lua_lua2C(1); //self
	if (!lua_istable(arg1)) {
		IElua_error_badarg("print", 1, "self");
		return;
	}
	
	lua_pushobject(arg1);
	lua_pushstring("userdata");
	lua_Object userdata = lua_gettable();

	if (!lua_isuserdata(userdata)) {
		lua_error("expected type userdata in self.userdata");
		return;
	}
	pObject = lua_getuserdata(userdata);

	lua_pushobject(arg1);
	lua_pushstring("type");
	lua_Object type = lua_gettable();
	szType = lua_isstring(type) ? lua_getstring(type) : "notype";

	if (lua_lua2C(2)) {
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

	sRight.Format("%s: %X -> %s", szType, (unsigned int)pObject, (LPCTSTR)sDump);

	g_pChitin->pWorld->PrintToConsole(IECString(), IECString(sRight), -1, 0);
	return;
}

/* getcurrentarea()
Global function
Pushes the fixed memory address of the current area onto the Lua stack */
void LUA_GetCurrentArea() {
	void* u = g_pChitin->pGame->m_pLoadedAreas[g_pChitin->pGame->m_VisibleAreaIdx];
	if (u) {
		lua_pushusertag(u, 0);
	} else {
		lua_error("Error getting current area");
	}
	return;
}

/* getcurrentarea()
Global function
Pushes the fixed memory address of the creature highlighted under the mouse cursor onto the Lua stack */
void LUA_GetCurrentCreature() {
	void* u = NULL;
	Enum e = g_pChitin->pGame->m_pLoadedAreas[g_pChitin->pGame->m_VisibleAreaIdx]->eCursorTarget;
	if (e == ENUM_INVALID_INDEX) {
		lua_error("No creature under cursor");
		return;
	} else {
		char nReturnVal;
		do {
			nReturnVal = g_pChitin->pGame->m_GameObjectArrayHandler.GetGameObjectShare(e, THREAD_ASYNCH, &u, INFINITE);
		} while (nReturnVal == OBJECT_SHARING || nReturnVal == OBJECT_DENYING);
		if (nReturnVal == OBJECT_SUCCESS) {
			if (u) {
				lua_pushusertag(u, 0);
			} else {
				lua_error("Error getting current creature");
			}
			nReturnVal = g_pChitin->pGame->m_GameObjectArrayHandler.FreeGameObjectShare(e, THREAD_ASYNCH, INFINITE);
		} else {
			lua_error("Error getting current creature");
		}
	}
	return;
}
