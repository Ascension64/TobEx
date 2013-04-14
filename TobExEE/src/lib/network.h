//TobExEE
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

struct CJMPacketHeader { //Size 10h, FIX_ME
	//joint first (JM)
	char u0; //unused?
	char u1; //unused?
	char u2; //unused?
	short u3; //unused?
	unsigned char m_flags; //5h, bit1: compressed
	int u6; //unused?
	char m_type[2]; //ah, JM
	unsigned char m_numPacketsHighByte; //ch, numPackets >> 8
	unsigned char m_numPacketsLowByte; //dh //numPackets & 0xFF
	unsigned char m_nSizeHighByte; //eh, dwPacketSize >> 8 & 0xFF
	unsigned char m_nSizeLowByte; //fh, dwPacketSize & 0xFF
	//in CJMPacket, payload starts at 10h
};

struct CJBPacketHeader { //Size Ch, FIX_ME
	//joint subsequent (JB)
	char u0; //unused?
	char u1; //unused?
	char u2; //unused?
	short u3; //unused?
	unsigned char m_flags; //5h, bit1: compressed
	int u6; //unused?
	char m_type[2]; //ah, JB
	//in CJBPacket, payload starts at Ch
};

struct CMGPacketHeader { //Size Ch, FIX_ME
	char u0; //3
	char u1; //3
	char u2; //3
	short u3; //unused?
	unsigned char m_flags; //5h, bit1: compressed
	char m_type[2]; //ah, MG
	//in CMGPacket, payload starts at Ch
};

struct CChunk { //Size 14h
	int m_nSenderID; //0h
	int m_nTargetID; //4h
	void* m_pPacket; //8h
	unsigned int m_dwSize; //ch
	int u10;
};

struct CNetworkWindow { //Size 98h
	bool m_bInit; //0h
	char u1;
	char u2;
	char PN; //3h - player number (playerId)
	short AE; //4h
	short FTS; //6h, frame to send index?
	short FE; //8h
	short TF; //ah
	short uc;
	char pe[2];
	CChunk m_currChunkToSend; //10h
	int u24;
	int u28;
	int u2c; //of an element
	int u30; //of an element
	int u34;
	CChunkList m_chunksReceived; //38h, received
	CChunkList m_chunksSend; //54h, to be sent
	char u70;
	char p71[3];
	int u74; //of an element
	char u78;
	char p79;
	short NB; //7ah, number of chunks sent?
	char u7c;
	char p7d[3];
	int u80;
	int u84;
	char u88;
	char u89;
	char p8a[2];
	bool u8c; //sending a chunk?
	char p8d[3];
	int u90; //GetTickCount + 25000
	int u94; //GetTickCount + 200
};

class CNetwork { //Size 1014h (=>FFCh)
public:
	bool GetSessionOpen();

	RECT u0;
	char u10;
	char u11;
	char u12;
	char u13;
	int u14;
	char u18;
	char p19[3];
	IECString u1c[4];
	int u2c;
	int u30;
	int u34;
	int u38;
	char u3c;
	char p3d[3];
	int u40;
	IECString u44;
	int u48;
	int u4c;
	int u50;
	char u54;
	char u55;
	char p56[2];
	int u58;
	int u5c;
	IECString u60[64];
	RECT u160[64];
	char u560[64];
	RECT u5a0;
	char u5b0;
	char p5b1[3];
	IECString m_sHostName; //5b4h
	int u5b8;
	IECString m_sGamePassword; //5bch
	char m_bGameMode; //5c0h, 0 = closed playing, 1 = open playing
	char p5c1[3];
	char u5c4[0x114]; //struct
	bool m_bSessionOpen; //6d8h
	bool m_bSessionHosting; //6d9h
	char p6da[2];
	char u6dc[0x78]; //struct DPWrapper
	int m_nMaxPlayers; //754h
	int m_dwFlags; //758h
	char u75c;
	char u75d;
	char p75e[2];
	IECString u760;
	IECString u764;
	IECString u768;
	char u76c;
	char u76d;
	char p76e[2];
	int m_nThisPlayerID; //770h
	IECString m_sThisPlayerName; //774h
	int u778;
	IECString m_sPlayerNameArray[6]; //77ch
	int m_nPlayerIdArray[6]; //794h
	bool m_bSoloServerArray[6]; //7ach
	char p7b2[6];
	int u7b8[6]; //=>delete
	int u7d0;
	int m_nServerIdx; //7d4h
	IECString u7d8;
	BOOL u7dc; //handling direct play system message?
	CNetworkWindow m_ServerWindows[6]; //7e0h
	CNetworkWindow m_SoloServerWindow; //b70h
	int uc08[255]; //CRC32 polynomial
	int u1004;
	
	struct unk1 { //Size Ch
		int u0;
		int u4;
		IECString u8;
	} u1008;
};

#endif //NETWORK_H