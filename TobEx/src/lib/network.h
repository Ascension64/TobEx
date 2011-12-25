#ifndef NETWORK_H
#define NETWORK_H

#include "utils.h"
#include "cstringex.h"

struct CNetworkWindow { //Size 88h
//Constructor: 0x9BE2B9
	bool bInit; //0h
	BYTE u1;
	BYTE u2;
	BYTE PN; //3h - packet number?
	WORD AE; //4h
	WORD FTS; //6h
	WORD FE; //8h
	WORD TF; //ah
	WORD uc;
	DWORD ue[2];
	DWORD u16;
	DWORD u1a;
	DWORD u1e[2];
	DWORD u26;
	DWORD u2a;
	CPtrList u2e; //AB9870, Messages (0x10 size))
	CPtrList u4a; //AB9870, Messages (0x10 size)
	BYTE u66;
	BYTE u67; //pad
	DWORD u68;
	BYTE u6c;
	BYTE u6d; //pad
	WORD NB; //6eh
	BYTE u70;
	BYTE u71; //pad
	DWORD u72;
	DWORD u76;
	BYTE u7a;
	BYTE u7b; //pad
	DWORD u7c;
	DWORD u80; //GetTickCount + 25000
	DWORD u84; //GetTickCount + 200
};

class CNetwork { //Size F3Ah
//Constructor: 9C23E8
public:
	DWORD u0;
	DWORD u4;
	
	DWORD u8[4]; //0xABD0F0, 0xAA5F70
	bool u18; //above DWORDs u8 loaded

	bool u19;
	BYTE u1a;
	BYTE u1b;
	DWORD u1c;
	DWORD u20;
	DWORD u24[4];
	IECString u34[4];
	DWORD u44[16];
	BYTE u84;
	WORD u85;
	BYTE u87;
	BYTE u88;
	BYTE u89; //pad
	DWORD u8a;
	DWORD u8e;
	IECString u92[20];
	IECString ue2;
	IECString ue6;
	DWORD uee;
	DWORD uea;
	DWORD uf2;
	DWORD uf6;
	DWORD ufa;
	DWORD ufe[2];
	WORD u106;
	BYTE u108;
	BYTE u109;
	DWORD u10a;
	DWORD u10e;
	IECString u112[64];
	DWORD u212[4][64]; //0xABD0F0
	BYTE u612;
	BYTE u613; //pad
	DWORD u614[15];
	WORD u650;
	DWORD u652[4]; //0xABD0F0
	BYTE u662;
	BYTE u663; //pad
	IECString sHostName; //664h
	WORD u668;
	IECString sGamePassword; //66ah
	BYTE bGameMode; //66eh, 0 = closed playing, 1 = open playing
	BYTE u66f; //pad
	DWORD u670[20];
	DWORD u6c0;
	DWORD u6c4;
	bool bSessionOpen; //6c8h (3776h)
	bool bSessionHosting; //6c9h (3777h)
	DWORD nMaxPlayers; //6cah
	DWORD dwFlags; //6ceh
	bool u6d2;
	bool u6d3;
	IECString u6d4;
	IECString u6d8;
	IECString u6dc;
	BYTE u6e0;
	BYTE u6e1;
	DWORD nThisPlayerID; //6e2h (3790h)
	IECString sThisPlayerName; //6e6h
	DWORD u6ea;
	IECString sPlayerName[6]; //6eeh
	DWORD nServerId[6]; //706h
	BYTE u71e; //bSoloServer?
	BYTE u71f; //pad
	DWORD u720;
	BYTE u724;
	BYTE u725; //[ad
	DWORD u726[7];
	DWORD u742;
	DWORD nServerIdx; //746h
	IECString u74a;
	DWORD u74e;
	CNetworkWindow ServerWindows[6]; //752h
	CNetworkWindow SoloServerWindow; //a82h
	DWORD ub0a[256];
	CRITICAL_SECTION uf0a;
	CRITICAL_SECTION uf22;
};

struct CRogerWilco { //Size 10h
//Constructor: 0x9DCA20
	IECString u0;
	IECString path; //4h, registry Roger Wilco path
	BYTE bProcessOpen; //8h
	BYTE u9;
	HANDLE hProcess; //ah
	WORD ue; //unused?
};

#endif //NETWORK_H