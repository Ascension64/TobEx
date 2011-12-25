#ifndef NETWORK_H
#define NETWORK_H

#include "stdafx.h"

struct CNetworkWindow { //Size 88h
//Constructor: 0x9BE2B9
	bool bInit; //0h
	char u1;
	char u2;
	char PN; //3h - packet number?
	short AE; //4h
	short FTS; //6h
	short FE; //8h
	short TF; //ah
	short uc;
	int ue[2];
	int u16;
	int u1a;
	int u1e[2];
	int u26;
	int u2a;
	IECPtrList u2e; //AB9870, Messages (0x10 size))
	IECPtrList u4a; //AB9870, Messages (0x10 size)
	char u66;
	char u67; //pad
	int u68;
	char u6c;
	char u6d; //pad
	short NB; //6eh
	char u70;
	char u71; //pad
	int u72;
	int u76;
	char u7a;
	char u7b; //pad
	int u7c;
	int u80; //GetTickCount + 25000
	int u84; //GetTickCount + 200
};

class CNetwork { //Size F3Ah
//Constructor: 9C23E8
public:
	int u0;
	int u4;
	
	int u8[4]; //0xABD0F0, 0xAA5F70
	bool u18; //above ints u8 loaded

	bool u19;
	char u1a;
	char u1b;
	int u1c;
	int u20;
	int u24[4];
	IECString u34[4];
	int u44[16];
	char u84;
	short u85;
	char u87;
	char u88;
	char u89; //pad
	int u8a;
	int u8e;
	IECString u92[20];
	IECString ue2;
	IECString ue6;
	int uee;
	int uea;
	int uf2;
	int uf6;
	int ufa;
	int ufe[2];
	short u106;
	char u108;
	char u109;
	int u10a;
	int u10e;
	IECString u112[64];
	int u212[4][64]; //0xABD0F0
	char u612;
	char u613; //pad
	int u614[15];
	short u650;
	int u652[4]; //0xABD0F0
	char u662;
	char u663; //pad
	IECString sHostName; //664h
	short u668;
	IECString sGamePassword; //66ah
	char bGameMode; //66eh, 0 = closed playing, 1 = open playing
	char u66f; //pad
	int u670[20];
	int u6c0;
	int u6c4;
	bool bSessionOpen; //6c8h (3776h)
	bool bSessionHosting; //6c9h (3777h)
	int nMaxPlayers; //6cah
	unsigned int dwFlags; //6ceh
	bool u6d2;
	bool u6d3;
	IECString u6d4;
	IECString u6d8;
	IECString u6dc;
	char u6e0;
	char u6e1;
	int nThisPlayerID; //6e2h (3790h)
	IECString sThisPlayerName; //6e6h
	int u6ea;
	IECString sPlayerName[6]; //6eeh
	int nServerId[6]; //706h
	char u71e; //bSoloServer?
	char u71f; //pad
	int u720;
	char u724;
	char u725; //[ad
	int u726[7];
	int u742;
	int nServerIdx; //746h
	IECString u74a;
	int u74e;
	CNetworkWindow ServerWindows[6]; //752h
	CNetworkWindow SoloServerWindow; //a82h
	int ub0a[256];
	CRITICAL_SECTION uf0a;
	CRITICAL_SECTION uf22;
};

struct CRogerWilco { //Size 10h
//Constructor: 0x9DCA20
	IECString u0;
	IECString path; //4h, registry Roger Wilco path
	char bProcessOpen; //8h
	char u9;
	HANDLE hProcess; //ah
	short ue; //unused?
};

#endif //NETWORK_H