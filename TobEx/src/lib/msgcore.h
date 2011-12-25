#ifndef MSGCORE_H
#define MSGCORE_H

#include "stdafx.h"
#include "scrcore.h"
#include "effcore.h"
#include "objcre.h"

//CMessageOverlay param
#define CMESSAGEOVERLAY_BLUR					0 //off/on
#define CMESSAGEOVERLAY_ENTANGLE				1 //off/on
#define CMESSAGEOVERLAY_INVISIBLE				2 //remove/set STATE_INVISIBLE
#define CMESSAGEOVERLAY_MIRRORIMAGE				3 //val = nMirrorImages
#define CMESSAGEOVERLAY_SANCTUARY				4 //off/on
#define CMESSAGEOVERLAY_INVGLOBE				5 //off/on
#define CMESSAGEOVERLAY_SPELLSHIELD				6 //off/on
#define CMESSAGEOVERLAY_WEB						7 //off/on
#define CMESSAGEOVERLAY_GREASE					8 //off/on
#define CMESSAGEOVERLAY_IMPROVEDINVISIBILITY	9 //remove/set STATE_IMPROVEDINVISIBILITY

//CMessageOverlay val
#define CMESSAGEOVERLAY_OFF		0
#define CMESSAGEOVERLAY_ON		1

class CMessage { //Size Ch
public:
	//AA5C10
	CMessage();
	virtual ~CMessage() {} //v0
	virtual short GetMsgType(void) {return 0;} //v4, ?
	virtual char GetNetworkType1(void) {return 0;} //v8, ?
	virtual char GetNetworkType2(void) {return 0;} //vc, ?
	virtual void Marshal(void* pData, int* dwSize) {return;} //v10
	virtual BOOL Unmarshal(void* pData, int* dwSize) {return FALSE;} //v14
	virtual void DoMessage(void) {return;} //v18

	Enum eTarget; //0x4
	Enum eSource; //0x8
};

class CPtrListMessage : public IECPtrList { //Size 1Eh
public:
	//AAB854
	short Send(CMessage& msg, BOOL bForceAddToQueue);

	char u1c; //gets u90 from CMultiplayerSettings
	char u1d; //pad
};

extern short (CPtrListMessage::*CPtrListMessage_Send)(CMessage&, BOOL);

class CMessageAddAction: public CMessage { //Size 6Ah
public:
	//AA5BF4
	CMessageAddAction();
	virtual ~CMessageAddAction() {} //v0
	virtual short GetMsgType(void) {return 0;} //v4, ?
	virtual char GetNetworkType1(void) {return 0;} //v8, ?
	virtual char GetNetworkType2(void) {return 0;} //vc, ?
	virtual void Marshal(void* pData, int* dwSize) {return;} //v10
	virtual BOOL Unmarshal(void* pData, int* dwSize) {return FALSE;} //v14
	virtual void DoMessage(void) {return;} //v18

	Action a;
};

class CMessageApplyEffect : public CMessage { //Size 12h
//used for Invisible, Sparkle, Casting Glow, Global Effects
public:
	//AA6A40
	CMessageApplyEffect();
	virtual ~CMessageApplyEffect() {} //v0
	virtual short GetMsgType(void) {return 0;} //v4, ?
	virtual char GetNetworkType1(void) {return 0;} //v8, ?
	virtual char GetNetworkType2(void) {return 0;} //vc, ?
	virtual void Marshal(void* pData, int* dwSize) {return;} //v10
	virtual BOOL Unmarshal(void* pData, int* dwSize) {return FALSE;} //v14
	virtual void DoMessage(void) {return;} //v18
	
	CEffect* pCEffect; //ch
	bool u10; //0 (sparkle, casting glow, any global effect), 1
	char u11; //pad
};

class CMessageCreatureOverlay : public CMessage { //Size Eh
public:
	//AA9790
	CMessageCreatureOverlay();
	virtual ~CMessageCreatureOverlay() {} //v0
	virtual short GetMsgType(void) {return 0;} //v4, ?
	virtual char GetNetworkType1(void) {return 0;} //v8, ?
	virtual char GetNetworkType2(void) {return 0;} //vc, ?
	virtual void Marshal(void* pData, int* dwSize) {return;} //v10
	virtual BOOL Unmarshal(void* pData, int* dwSize) {return FALSE;} //v14
	virtual void DoMessage(void) {return;} //v18

	char param; //ch
	char val; //dh
};

class CMessageCutSceneMode : public CMessage { //Size Eh
public:
	//AA69D0
	CMessageCutSceneMode();
	virtual ~CMessageCutSceneMode() {} //v0
	virtual short GetMsgType(void) {return 0;} //v4, ?
	virtual char GetNetworkType1(void) {return 0;} //v8, ?
	virtual char GetNetworkType2(void) {return 0;} //vc, ?
	virtual void Marshal(void* pData, int* dwSize) {return;} //v10
	virtual BOOL Unmarshal(void* pData, int* dwSize) {return FALSE;} //v14
	virtual void DoMessage(void) {return;} //v18

	bool bEnable; //ch
	char ud; //pad
};

#define STRREF_PARTYSLOT_0	-2
#define STRREF_PARTYSLOT_1	-3
#define STRREF_PARTYSLOT_2	-4
#define STRREF_PARTYSLOT_3	-5
#define STRREF_PARTYSLOT_4	-6
#define STRREF_PARTYSLOT_5	-7

class CMessageDisplayDialogue : public CMessage { //Size 24h
public:
	//AA63CC
	CMessageDisplayDialogue();
	virtual ~CMessageDisplayDialogue() {} //v0
	virtual short GetMsgType(void) {return 0;} //v4, ?
	virtual char GetNetworkType1(void) {return 0;} //v8, ?
	virtual char GetNetworkType2(void) {return 0;} //vc, ?
	virtual void Marshal(void* pData, int* dwSize) {return;} //v10
	virtual BOOL Unmarshal(void* pData, int* dwSize) {return FALSE;} //v14
	virtual void DoMessage(void) {return;} //v18

	STRREF srOwner; //ch
	STRREF srText; //10h
	ARGB rgbOwner; //14h
	ARGB rgbText; //18h
	int u1c; //-1
	char u20;
	bool bFloatText; //21h
	bool u22;
	bool bPlaySound; //23h, plays an empty sound
};

class CMessageDisplayText : public CMessage { //Size 24h
public:
	//AA9774
	CMessageDisplayText();
	virtual ~CMessageDisplayText() {} //v0
	virtual short GetMsgType(void) {return 0;} //v4, ?
	virtual char GetNetworkType1(void) {return 0;} //v8, ?
	virtual char GetNetworkType2(void) {return 0;} //vc, ?
	virtual void Marshal(void* pData, int* dwSize) {return;} //v10
	virtual BOOL Unmarshal(void* pData, int* dwSize) {return FALSE;} //v14
	virtual void DoMessage(void) {return;} //v18

	IECString sLeft; //ch
	IECString sRight; //10h
	ARGB rgbLeft; //14h
	ARGB rgbRight; //18h
	int u1c; //-1
	char u20;
	bool bFloatText; //21h
	bool u22;
	bool u23; //pad
};

class CMessageRemoveAreaAirEffects : public CMessage { //Size 14h
public:
	//AA727C
	CMessageRemoveAreaAirEffects();

	virtual ~CMessageRemoveAreaAirEffects(); //v0
	void Deconstruct() {} //dummy

	virtual short GetMsgType(void); //v4
	virtual char GetNetworkType1(void); //v8
	virtual char GetNetworkType2(void); //vc
	virtual void Marshal(void* pData, int* dwSize); //v10
	virtual BOOL Unmarshal(void* pData, int* dwSize); //v14
	virtual void DoMessage(void); //v18

	ResRef rAreaName; //ch
};

extern void (CMessageRemoveAreaAirEffects::*CMessageRemoveAreaAirEffects_Deconstruct)();
extern short (CMessageRemoveAreaAirEffects::*CMessageRemoveAreaAirEffects_GetMsgType)(void);
extern char (CMessageRemoveAreaAirEffects::*CMessageRemoveAreaAirEffects_GetNetworkType1)(void);
extern char (CMessageRemoveAreaAirEffects::*CMessageRemoveAreaAirEffects_GetNetworkType2)(void);
extern void (CMessageRemoveAreaAirEffects::*CMessageRemoveAreaAirEffects_Marshal)(void*, int*);
extern BOOL (CMessageRemoveAreaAirEffects::*CMessageRemoveAreaAirEffects_Unmarshal)(void*, int*);
extern void (CMessageRemoveAreaAirEffects::*CMessageRemoveAreaAirEffects_DoMessage)(void);

class CMessageSetTrigger : public CMessage { //Size 3Ah
public:
	//AA5C84
	CMessageSetTrigger();
	virtual ~CMessageSetTrigger() {} //v0
	virtual short GetMsgType(void) {return 0;} //v4, ?
	virtual char GetNetworkType1(void) {return 0;} //v8, ?
	virtual char GetNetworkType2(void) {return 0;} //vc, ?
	virtual void Marshal(void* pData, int* dwSize) {return;} //v10
	virtual BOOL Unmarshal(void* pData, int* dwSize) {return FALSE;} //v14
	virtual void DoMessage(void) {return;} //v18

	Trigger t; //ch
};

class CMessageSpriteUpdate : public CMessage { //Size 58h
public:
	//AAB914
	CMessageSpriteUpdate();
	CMessageSpriteUpdate(CCreatureObject*, Enum, Enum);
	CMessageSpriteUpdate* Construct(CCreatureObject* pCre, Enum eSource, Enum eTarget) {return this;} //dummy

	virtual ~CMessageSpriteUpdate() {} //v0
	virtual short GetMsgType(void) {return 0;} //v4, ?
	virtual char GetNetworkType1(void) {return 0;} //v8, ?
	virtual char GetNetworkType2(void) {return 0;} //vc, ?
	virtual void Marshal(void* pData, int* dwSize) {return;} //v10
	virtual BOOL Unmarshal(void* pData, int* dwSize) {return FALSE;} //v14
	virtual void DoMessage(void) {return;} //v18

	void* uc; //pointer to object with size designated by u10*4
	short u10; //sprite 33eeh, related to current area, size of object pointed by uc/4
	short u12; //sprite 3428h, related to current area
	long long u14; //sprite 35ech
	IECString areaName; //1ch
	short wCurrentSequence; //20h
	POINT pos; //22h, sprite position
	short u2a; //linked to animation, sprite 33e8h
	unsigned int stateFlags; //2ch, from CDerivedStats
	short currentHP; //30h
	short maxHP; //32h
	short effectiveAC; //34h
	short ACCrushingMod; //36h
	short ACMissileMod; //38h
	short ACPiercingMod; //3ah
	short ACSlashingMod; //3ch
	short m_nPortraitIcons; //3eh
	int* m_pPortraitIcons; //40h, each object is 4h in size
	unsigned char EnemyAlly; //44h
	unsigned char EnemyAlly2; //45h, from CCreatureObject oDerived
	char General; //46h
	char General2; //47h, from CCreatureObject oDerived
	char u48; //sprite 6298h
	char u49; //something from m_animation
	int u4a; //related to constitution?, sprite 63b6h
	char u4e; //sprite 63ceh
	char u4f; //CDerivedStats 1e2h
	char doNotJump; //50h, from CDerivedStats
	char u51; //CDerivedStats a0h
	char u52; //CDerivedStats 230h
	char u53; //CDerivedStats 90h
	char u54; //sprite 2c0ch
	char u55; //padding
	short u56;
};

extern CMessageSpriteUpdate* (CMessageSpriteUpdate::*CMessageSpriteUpdate_Construct)(CCreatureObject*, Enum, Enum);

extern short (CMessageSpriteUpdate::*CMessageSpriteUpdate_GetMsgType)(void);

struct CMessageHandler { //Size 114h
//Constructor: 0x43CD30
	char u0;
	char u1;
	char u2;
	char u3;
	char u4;
	char u5;
	char u6;
	char u7;

	struct _u8 {
		IECPtrList u0; //AA63B4
		IECPtrList u1c; //AA63B4
		int u38;
	} u8;

	char u44; //24, nObjects?
	char u45;
	char u46;
	char u47[24]; //related to u44
	char u5f[24];
	char u77[24]; //related to u44
	char u8f;
	IECString u90;
	int u94;
	char u98[6];
	int u9e[6];
#ifdef _DEBUG
	_CCriticalSection ub6;
#else
	CCriticalSection ub6;
#endif
	int ud6[6];
	char uee;
	char uef;
	char uf0;
	char uf1;
	int uf2;
	char uf6;
	char uf7;
	char uf8;
	char uf9;
	char ufa;
	char ufb;
	char ufc;
	char ufd;
	char ufe;
	char uff;
	char u100;
	char u101;
	IECString u102;
	IECString u106;
	short u10a;
	int u10c; //ClientTimout
	char u110;
	char u111;
	char u112;
	char u113; //pad
};

#endif //MSGCORE_H