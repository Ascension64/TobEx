//TobExEE
#ifndef TLKCORE_H
#define TLKCORE_H

#include "stdafx.h"
#include "sndcore.h"

class CTlkFile : public CFile { //Size 2Ch
public:
	char bOpened; //10h
	char p11[2];
	char u12[12];
	char p1e[2];
	int u20;
	int u24;
	int u28;
};

struct CStrRef { //Size 1Ch
	IECString m_sText; //0h
	CSoundWrapper m_snd; //4h
};

class CTlkTbl { //Size 88h
public:
	char u0;
	char p1;
	CMapWordToPtr m_FileMap; //2h, key->CFileTlk
	IECMapStringToString m_StringMap; //1eh
	char nKeyLow; //3ah, the low byte of the key to use for dialog (dialog.tlk vs dialogF.tlk)
	char p3b;
	
	//handles sounds?
	struct unk1 { //Size 4Ch
		IECString u0;
		IECString u4;
		
		class unk2 : public CFile { //Size 2Eh
			char u10;
			char p11;
			int* u12; //pArray
			int u16; //nArraySize
			char u1a[14];
			char p28[2];
			int u2a;
		} u8; //8h

		class unk3 : public CFile { //Size 16h
			int u10;
			char u14;
			char p15;
		} u36;

	} u3c;
};

#endif //TLKCORE_H