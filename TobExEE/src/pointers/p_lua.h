//TobExEE
#ifndef P_RESREF_H
#define P_RESREF_H

#ifdef __2014

  #define	CLUACONSOLE_DISPLAYTEXT	0x51ED30

  #define	G_IETAGNUMBER	0XB61C3C
  #define	G_IETAGSTRING	0XB61C44
  #define	G_IETAGUSERDATA	0XB61C40
  #define	G_IETAGCBALDURCHITIN	0X9A19C4

  #define	IELUA_INIT	0X51F6C0
  #define	IELUA_DEINIT	0X51FA10

  #define	IELUA_ERROR_BADSELF	0X768CE0
  #define	IELUA_ERROR_BADARG	0X768D10
  #define	IELUA_ERROR_TOOMANYARGS	0X768D40
  #define	IELUA_CREATETAG	0X768DA0
  #define	IELUA_ISVALIDTYPE	0X768EB0
  #define	IELUA_GETPARAM	0X769010
  #define	IELUA_GETSTRING	0X769040
  #define	IELUA_GETNUMBER	0X769070
  #define	IELUA_CAST	0X769090
  #define	IELUA_PUSHUSERDATA	0X769190
  #define	IELUA_GETTABLE	0X7691F0
  #define	IELUA_SETTAGGETMETHOD	0X769280
  #define	IELUA_SETTAGSETMETHOD	0X7692E0
  #define	IELUA_SETTAGMETHOD	0X769340
  #define	IELUA_CREATEGLOBALTAG	0X7693A0
		
  #define	DO_UNPROTECTEDRUN	0X786240
  #define	LUAI_GETTAGMETHOD	0X789530
  #define	PUT_LUAOBJECTONTOP	0X785710

  #define	LUA_DOFILE	0X784B30
  #define	LUA_DOSTRING	0X784C30
  #define	LUA_POP	0X7856C0
  #define	LUA_RAWGETTABLE	0X785910
  #define	LUA_ERROR	0X7859F0
  #define	LUA_SETERRORMETHOD	0X786340
  #define	LUA_CALLFUNCTION	0X7861D0

  #define	LUA_SETTAGMETHOD	0X7862A0
  #define	LUA_GETTABLE	0X786370
  #define	LUA_BEGINBLOCK	0X7864D0
  #define	LUA_ENDBLOCK	0X786530
  #define	LUA_SETTAG	0X7865B0
  #define	LUA_SETTABLE	0X7865E0
  #define	LUA_RAWSETTABLE	0X786750
  #define	LUA_CREATETABLE	0X786780
  #define	LUA_LUA2C	0X786810
  #define	LUA_ISNIL	0X786840
  #define	LUA_ISTABLE	0X786880
  #define	LUA_ISUSERDATA	0X7868C0
  #define	LUA_ISCFUNCTION	0X786900
  #define	LUA_ISNUMBER	0X786940
  #define	LUA_ISSTRING	0X786A10
  #define	LUA_ISFUNCTION	0X786A50
  #define	LUA_GETNUMBER	0X786AA0
  #define	LUA_GETSTRING	0X786AF0
  #define	LUA_GETUSERDATA	0X786C10
  #define	LUA_GETCFUNCTION	0X786C40
  #define	LUA_GETREF	0X786C80
  #define	LUA_REF	0X786CB0
  #define	LUA_GETGLOBAL	0X786CE0
  #define	LUA_RAWGETGLOBAL	0X786E20
  #define	LUA_SETGLOBAL	0X786E50
  #define	LUA_RAWSETGLOBAL	0X786FB0
  #define	LUA_PUSHNIL	0X787010
  #define	LUA_PUSHNUMBER	0X787050
  #define	LUA_PUSHSTRING	0X7870A0
  #define	LUA_PUSHCFUNCTION	0X787100
  #define	LUA_PUSHUSERTAG	0X787140
  #define	LUA_PUSHOBJECT	0X7871F0
  #define	LUA_TAG	0X787280
  #define	LUA_NEWTAG	0X7893D0

#elif
#endif

#endif //P_RESREF_H