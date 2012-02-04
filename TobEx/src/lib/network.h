#ifndef NETWORK_H
#define NETWORK_H

#include "stdafx.h"

typedef IECPtrList CChunkList; //AB9870

#define CSPECIFICMESSAGE_NOT_TEXT	-1

/* struct CTextMessage {
   char m_nameLength; //0h
   char name[];
   char m_textLength;
   char text[];
*/

/* struct CSpecificMessage { //Size 3h + dwSize
	char notext; //0h, CSPECIFICMESSAGE_NOT_TEXT, this denotes that the message is not a text message
	char type; //1h
	char subtype; //2h
	char data[dwSize]; //3h
};
*/

/* struct CSpecificMessageZip { //Size 7h + dwSize
	char notext; //0h, CSPECIFICMESSAGE_NOT_TEXT, , this denotes that the message is not a text message
	char type; //1h
	char subtype; //2h
	unsigned int size_uncompressed; //3h, little endian
	char compressed_data[dwSizeUncompressed]; //7h
};
*/

struct CJMPacketHeader { //Size 10h
	//joint first (JM)
	char u0; //unused?
	char u1; //unused?
	char u2; //unused?
	short u3; //unused?
	unsigned char flags; //5h, bit1: compressed
	int u6; //unused?
	char type[2]; //ah, JM
	unsigned char numPacketsHighByte; //ch, numPackets >> 8
	unsigned char numPacketsLowByte; //dh //numPackets & 0xFF
	unsigned char nSizeHighByte; //eh, dwPacketSize >> 8 & 0xFF
	unsigned char nSizeLowByte; //fh, dwPacketSize & 0xFF
	//in CJMPacket, payload starts at 10h
};

struct CJBPacketHeader { //Size Ch
	//joint subsequent (JB)
	char u0; //unused?
	char u1; //unused?
	char u2; //unused?
	short u3; //unused?
	unsigned char flags; //5h, bit1: compressed
	int u6; //unused?
	char type[2]; //ah, JB
	//in CJBPacket, payload starts at Ch
};

struct CMGPacketHeader { //Size Ch
	char u0; //3
	char u1; //3
	char u2; //3
	short u3; //unused?
	unsigned char flags; //5h, bit1: compressed
	char type[2]; //ah, MG
	//in CMGPacket, payload starts at Ch
};

struct CChunk { //Size 10h
	int nSenderID; //0h
	int nTargetID; //4h
	void* pPacket; //8h
	unsigned int dwPacketSize; //ch
};

struct CNetworkWindow { //Size 88h
//Constructor: 0x9BE2B9
	bool bInit; //0h
	char u1;
	char u2;
	char PN; //3h - player number (playerId)
	short AE; //4h
	short FTS; //6h, frame to send index?
	short FE; //8h
	short TF; //ah
	short uc;
	CChunk m_currChunkToSend; //eh

	int u1e[2];
	int u26;
	int u2a;
	CChunkList m_chunksReceived; //2eh, received
	CChunkList m_chunksSend; //4ah, to be sent
	char u66;
	char u67; //pad
	int u68[1];
	char u6c;
	char u6d; //pad
	short NB; //6eh, number of chunks sent?
	char u70;
	char u71; //pad
	int u72;
	int u76;
	char u7a;
	bool u7b; //sending a chunk?
	int u7c;
	int u80; //GetTickCount + 25000
	int u84; //GetTickCount + 200
};

class CNetwork { //Size F3Ah
//Constructor: 9C23E8
public:
	void CloseSession(bool bCloseImmediately);
	void PrintNetworkError(HRESULT hResult, LPCTSTR szMsg);

	void* u0; //pIDirectPlay4A
	void* u4; //pIDirectPlayLobby3A
	
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
	IECString sPlayerNameArray[6]; //6eeh
	int nPlayerIdArray[6]; //706h
	bool m_bSoloServerArray[6]; //71eh
	char u724;
	char u725; //[ad
	int u726[7];
	int u742;
	int nServerIdx; //746h
	IECString u74a;
	BOOL u74e; //handling direct play system message?
	CNetworkWindow ServerWindows[6]; //752h
	CNetworkWindow SoloServerWindow; //a82h
	int ub0a[256];
	CRITICAL_SECTION csWindowMessages; //f0ah, for access to u2e of CNetworkWindow
	CRITICAL_SECTION csIDirectPlay4A; //f22h
};

extern void (CNetwork::*CNetwork_CloseSession)(bool);
extern void (CNetwork::*CNetwork_PrintNetworkError)(HRESULT, LPCTSTR);

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