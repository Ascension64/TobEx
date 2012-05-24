#include "LuaCommon.h"

#include "chitin.h"

IECString LUADump_notype(void* p) {
	return IECString("no info");
}

IECString LUADump_action(void* p) {
	Action* pAction = (Action*)p;
	IECString sDump = "error";
	Identifiers& idAction = g_pChitin->pGame->m_pScriptParser->ACTION;

	POSITION pos = idAction.entries.GetHeadPosition();
	IdsEntry* pEntry = NULL;
	while (pos) {
		pEntry = (IdsEntry*)idAction.entries.GetNext(pos);
		if (pEntry->nOpcode == pAction->opcode) break;
	}

	if (pEntry) {
		sDump.Format("%d %s", pEntry->nOpcode, (LPCTSTR)pEntry->value);
	}
	
	return sDump;
}

IECString LUADump_creature(void* p) {
	CCreatureObject* pCre = (CCreatureObject*)p;
	IECString sDump;
	sDump.Format("%s", (LPCTSTR)sDump, pCre->name);
	return sDump;
}

void __stdcall LUA_InitExt() {
	g_DumpFunctions["notype"] = LUADump_notype;
	g_DumpFunctions["action"] = LUADump_action;
	g_DumpFunctions["creature"] = LUADump_creature;

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
	
	lua_pushcfunction(LUA_GetCurrentArea);
	lua_setglobal("getcurrentarea");

	lua_pushcfunction(LUA_GetCurrentCreature);
	lua_setglobal("getcurrentcreature");

	lua_endblock();
	return;
}

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

void LUA_CreateObject() {
	void* u = NULL;
	char* name = NULL;
	char* type = NULL;

	lua_Object arg1 = lua_lua2C(1); //name
	if (IElua_getparam(1, g_IETagString)) {
		name = IElua_getstring(arg1);
	} else {
		IElua_error_badarg("createobject", 1, "string");
		return;
	}

	lua_Object arg2 = lua_lua2C(2); //userdata
	if (IElua_getparam(2, g_IETagUserdata)) {
		u = lua_getuserdata(arg2);
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
	int tag = 0;
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

			tag = lua_tag(g);
		} else {
			sprintf_s(g_szIEluaError, g_szIEluaErrorSize, "%s is not an object", name);
			lua_error(g_szIEluaError);
		}
	} else {
		//does not exist, make new object
		tag = IElua_createtag(name);
		LUA_InitObjectTagMethods(tag);
	
		g = lua_createtable();
		lua_pushobject(g);
		lua_settag(tag);
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

void LUA_InitObjectTagMethods(int tag) {
	IElua_settagmethod(tag, "getuserdata", LUA_GetUserdata);
	IElua_settagmethod(tag, "getbyte", LUA_GetByte);
	IElua_settagmethod(tag, "getword", LUA_GetWord);
	IElua_settagmethod(tag, "getdword", LUA_GetDword);
	IElua_settagmethod(tag, "gettable", LUA_GetTable);
	IElua_settagmethod(tag, "print", LUA_Print);
	return;
}

void LUA_GetUserdata() {
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

void LUA_GetTable() {
	unsigned int address_base = 0;
	unsigned int address_rel = 0;

	lua_beginblock();

	lua_Object arg1 = lua_lua2C(1); //self
	if (!lua_istable(arg1)) {
		IElua_error_badarg("gettable", 1, "self");
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
		IElua_error_badarg("gettable", 2, "number or string");
		return;
	}

	if (lua_lua2C(3)) {
		IElua_error_toomanyargs("gettable");
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

	while (pos) {
		void* ptr = pList->GetNext(pos);
		lua_pushobject(table);
		lua_pushusertag(ptr, 0);
		lua_pushnumber(0);
		lua_settable();
	}

	lua_endblock();

	lua_pushobject(table);
	return;
}

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
			sDump = "noinfo";
		}
	} else {
		sDump = "noinfo";
	}


	sRight.Format("%s: %X -> %s", szType, (unsigned int)pObject, (LPCTSTR)sDump);

	g_pChitin->pWorld->PrintToConsole(IECString(), IECString(sRight), -1, 0);
	return;
}

void LUA_GetCurrentArea() {
	void* u = g_pChitin->pGame->m_pLoadedAreas[g_pChitin->pGame->m_VisibleAreaIdx];
	if (u) {
		lua_pushusertag(u, 0);
	} else {
		lua_error("Error getting current area");
	}
	return;
}

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
