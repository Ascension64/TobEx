#ifndef LUA_H
#define LUA_H

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

//IELua functions
extern int (__stdcall *IElua_init)();
extern int (__stdcall *IElua_deinit)();

/*error_badself
-prints an error message that the function funcname has inappropriate self*/
extern void (__cdecl *IElua_error_badself)(char* funcname);

/*error_badarg
-prints an error message that the function funcname parameter number is //
 of the wrong type, and should be of type type*/
extern void (__cdecl *IElua_error_badarg)(char* funcname, int number, char* type);

/*error_badarg
-prints an error message that the function funcname parameter number is //
 of the wrong type, and should be an array of type type with dimensions dimensions*/
extern void (__cdecl *IElua_error_badargarray)(char* funcname, int number, char* type, int dimensions);

/*createtag
-if name does not already exist in toLua_tag, creates new IETag //
 and updates toLua_tag and toLua_name //
 initialises default IETag methods
-if name already exists, returns the found IETag*/
extern IETag (__cdecl *IElua_createtag)(char* name);

/*setparent
-sets the parent of child
-technically this sets toLua_parent.child = parent and //
 test_cast.child = usertag(cast, 0)*/
extern void (__cdecl *IElua_setparent)(IETag child, IETag parent, void* cast);

/*error_toomanyparams
-prints an error message that the function funcname has too many arguments*/
extern void (__cdecl *IElua_error_toomanyargs)(char* funcname);

/*isvalidtype
-determines whether o is of the type specified
-standard types are: g_IETagNumber, g_IETagString, g_IETagUserdata
-if a non-standard type is specified, tag(o) is directly compared to type //
 if tag(o) == 0, the functions returns 1 //
 if tag(o) != type, the parent tag is iteratively obtained from toLua_parent.tag(o) and compared to type
 -returns a non-zero int if valid*/
extern int (__cdecl *IElua_isvalidtype)(lua_Object o, IETag type);

/*getparam
-gets the (number)th param and checks the type against tag*/
extern int (__cdecl *IElua_getparam)(int number, IETag tag);

/*checktable
-checks that each numerical index of the table of size size is of type type
-if table is not of type table, returns zero
-if any field is not of type type, returns zero
-if size is smaller than the number of elements in the table, returns zero*/
extern int (__cdecl *IElua_checktable)(lua_Object table, IETag type, int size);

/*getstring
-equivalent to lua_getstring() but aborts if o isnil()*/
extern char* (__cdecl *IElua_getstring)(lua_Object o);

/*getnumber
-equivalent to lua_getnumber()*/
extern real (__cdecl *IElua_getnumber)(lua_Object o);

/*getuserdata
-equivalent to lua_getuserdata() but aborts if o isnil()*/
extern void* (__cdecl *IElua_getuserdata)(lua_Object o);

/*cast
-tag(userdata) is compared to type //
 if tag(userdata) == 0, the function returns the value of userdata //
 if tag(userdata) != type, the parent tag is iteratively obtained from toLua_parent.tag(child) //
 and the userdata value from test_cast.tag(child) is iteratively called with function of form void* cast(void* u_child) //
 with the cast function returning the next userdata value
-the value of the final userdata is returned
-the function is generally used to cast the self parameter of a tag method
*/
extern void* (__cdecl *IElua_cast)(lua_Object userdata, IETag tag);

/*pushstring
-equivalent to lua_pushstring() but pushnil() if NULL*/
extern void (__cdecl *IElua_pushstring)(char*);

/*pushuserdata
-pushes userdata(u, -1) on the C2lua stack
-if tag(userdata) == 0, tag(userdata) is set to tag*/
extern void (__cdecl *IElua_pushuserdata)(void*, IETag tag);

/* alloc
-create a new object and stores as an index so test_alloc.userdata(obj, 0) = 0.0
-the object is assigned tag IETag and is given a garbage collection method "gc"
-the object is initialised by copying pData into it
-the userdata is pushed onto the C2lua stack before return*/
extern void (__cdecl *IElua_alloc)(void* pData, int size, IETag tag);

/*gettable
-gets the value table.tag, which should be of type table
-if this value is not a table, newtable is created and stored in table.tag*/
extern lua_Object (__cdecl *IElua_gettable)(lua_Object table, IETag tag);

/*settaggetmethod
-stores a userdata(u, 0) in test_getref.tag.event
-the method is invoked in IELua using "tag:event" before a settagmethod method is discovered
-the method is of type "void method(void* u)" and pushes a value onto the C2lua stack*/
extern void (__cdecl *IElua_settaggetmethod)(IETag tag, char* event, void* u);

/*settagsetmethod
-stores a userdata(u, 0) in test_setref.tag.event
-the method is of type void method(void* u, lua_Object value)*/
extern void (__cdecl *IElua_settagsetmethod)(IETag tag, char* event, void* u);

/*settagmethod
-stores a lua_CFunction in test_getref.tag.event
-these are invoked in IELua with tag:event after userdata is discovered*/
extern void (__cdecl *IElua_settagmethod)(IETag tag, char* event, lua_CFunction func);

/*createglobaltag
-creates a new IETag and stores it in the global varname*/
extern void (__cdecl *IElua_createglobaltag)(char* varname);

/*createtaggetmethod
-creates a new tag and stores userdata(u, 0) in test_getref.tag.event*/
extern void (__cdecl *IElua_createtaggetmethod)(char* event, void* u);

/*createtagsetmethod
-creates a new tag and stores userdata(u, 0) in test_setref.tag.event*/
extern void (__cdecl *IElua_createtagsetmethod)(char* event, void* u);

//Lua 3.0 functions
extern int (__cdecl *lua_dofile)(char* filename);
extern int (__cdecl *lua_dostring)(char* str);
extern lua_Object (__cdecl *lua_pop)();
extern lua_Object (__cdecl *lua_rawgettable)();
extern void (__cdecl *lua_error)(char* message);
extern int (__cdecl *lua_callfunction)(lua_Object function);
extern lua_Object (__cdecl *lua_gettagmethod)(int tag, char* event);
extern lua_Object (__cdecl *lua_settagmethod)(int tag, char* event);
extern lua_Object (__cdecl *lua_gettable)();
extern void (__cdecl *lua_beginblock)();
extern void (__cdecl *lua_endblock)();
extern void (__cdecl *lua_settag)(int tag);
extern void (__cdecl *lua_settable)();
extern void (__cdecl *lua_rawsettable)();
extern lua_Object (__cdecl *lua_createtable)();
extern lua_Object (__cdecl *lua_lua2C)(int number);
extern int (__cdecl *lua_isnil)(lua_Object o);
extern int (__cdecl *lua_istable)(lua_Object o);
extern int (__cdecl *lua_isuserdata)(lua_Object o);
extern int (__cdecl *lua_iscfunction)(lua_Object o);
extern int (__cdecl *lua_isnumber)(lua_Object o);
extern int (__cdecl *lua_isstring)(lua_Object o);
extern int (__cdecl *lua_isfunction)(lua_Object o);
extern real (__cdecl *lua_getnumber)(lua_Object o);
extern char* (__cdecl *lua_getstring)(lua_Object o);
extern void* (__cdecl *lua_getuserdata)(lua_Object o);
extern lua_CFunction (__cdecl *lua_getcfunction)(lua_Object o);
extern lua_Object (__cdecl *lua_getref)(int ref);
extern int (__cdecl *lua_ref)(int lock);
extern lua_Object (__cdecl *lua_getglobal)(char* name);
extern lua_Object (__cdecl *lua_rawgetglobal)(char* name);
extern void (__cdecl *lua_setglobal)(char* varname);
extern void (__cdecl *lua_rawsetglobal)(char* name);
extern void (__cdecl *lua_pushnil)(void);
extern void (__cdecl *lua_pushnumber)(real n);
extern void (__cdecl *lua_pushstring)(char* s);
extern void (__cdecl *lua_pushcfunction)(lua_CFunction fn);
extern void (__cdecl *lua_pushusertag)(void* u, int tag);
extern void (__cdecl *lua_pushobject)(lua_Object o);
extern int (__cdecl *lua_tag)(lua_Object o);
extern int (__cdecl *lua_newtag)();

#endif //LUA_H