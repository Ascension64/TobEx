#ifndef MSGCORE_H
#define MSGCORE_H

#include "utils.h"
#include "scrcore.h"
#include "resref.h"
#include "effcore.h"
#include "objcre.h"
#include "cstringex.h"

//CMessageOverlay param
#define CMESSAGEOVERLAY_BLUR 0 //off/on
#define CMESSAGEOVERLAY_ENTANGLE 1 //off/on
#define CMESSAGEOVERLAY_INVISIBLE 2 //remove/set STATE_INVISIBLE
#define CMESSAGEOVERLAY_MIRRORIMAGE 3 //val = nMirrorImages
#define CMESSAGEOVERLAY_SANCTUARY 4 //off/on
#define CMESSAGEOVERLAY_INVGLOBE 5 //off/on
#define CMESSAGEOVERLAY_SPELLSHIELD 6 //off/on
#define CMESSAGEOVERLAY_WEB 7 //off/on
#define CMESSAGEOVERLAY_GREASE 8 //off/on
#define CMESSAGEOVERLAY_IMPROVEDINVISIBILITY 9 //remove/set STATE_IMPROVEDINVISIBILITY

//CMessageOverlay val
#define CMESSAGEOVERLAY_OFF 0
#define CMESSAGEOVERLAY_ON 1

class CMessage { //Size Ch
public:
	//AA5C10
	CMessage();
	virtual ~CMessage() {} //v0
	virtual WORD GetMsgType(void) {return 0;} //v4, ?
	virtual BYTE GetNetworkType1(void) {return 0;} //v8, ?
	virtual BYTE GetNetworkType2(void) {return 0;} //vc, ?
	virtual void Marshal(DWORD* pData, DWORD* dwSize) {return;} //v10
	virtual BOOL Unmarshal(DWORD* pData, DWORD* dwSize) {return FALSE;} //v14
	virtual void DoMessage(void) {return;} //v18

	Enum eTarget; //0x4
	Enum eSource; //0x8
};

class CPtrListMessage : public CPtrList { //Size 1Ch
public:
	//AAB854
	WORD Send(CMessage&, BOOL);
};

extern WORD (CPtrListMessage::*CPtrListMessage_Send)(CMessage&, BOOL);

class CMessageAddAction: public CMessage { //Size 6Ah
public:
	//0xAA5BF4
	CMessageAddAction();
	virtual ~CMessageAddAction() {} //v0
	virtual WORD GetMsgType(void) {return 0;} //v4, ?
	virtual BYTE GetNetworkType1(void) {return 0;} //v8, ?
	virtual BYTE GetNetworkType2(void) {return 0;} //vc, ?
	virtual void Marshal(DWORD* pData, DWORD* dwSize) {return;} //v10
	virtual BOOL Unmarshal(DWORD* pData, DWORD* dwSize) {return FALSE;} //v14
	virtual void DoMessage(void) {return;} //v18

	Action a;
};

class CMessageApplyEffect : public CMessage { //Size 12h
//used for Invisible, Sparkle, Casting Glow, Global Effects
public:
	//0xAA6A40
	CMessageApplyEffect();
	virtual ~CMessageApplyEffect() {} //v0
	virtual WORD GetMsgType(void) {return 0;} //v4, ?
	virtual BYTE GetNetworkType1(void) {return 0;} //v8, ?
	virtual BYTE GetNetworkType2(void) {return 0;} //vc, ?
	virtual void Marshal(DWORD* pData, DWORD* dwSize) {return;} //v10
	virtual BOOL Unmarshal(DWORD* pData, DWORD* dwSize) {return FALSE;} //v14
	virtual void DoMessage(void) {return;} //v18
	
	CEffect* pCEffect; //ch
	bool u10; //0 (sparkle, casting glow, any global effect), 1
	BYTE u11; //pad
};

class CMessageCreatureOverlay : public CMessage { //Size Eh
public:
	//0xAA9790
	CMessageCreatureOverlay();
	virtual ~CMessageCreatureOverlay() {} //v0
	virtual WORD GetMsgType(void) {return 0;} //v4, ?
	virtual BYTE GetNetworkType1(void) {return 0;} //v8, ?
	virtual BYTE GetNetworkType2(void) {return 0;} //vc, ?
	virtual void Marshal(DWORD* pData, DWORD* dwSize) {return;} //v10
	virtual BOOL Unmarshal(DWORD* pData, DWORD* dwSize) {return FALSE;} //v14
	virtual void DoMessage(void) {return;} //v18

	BYTE param; //ch
	BYTE val; //dh
};

class CMessageCutSceneMode : public CMessage { //Size Eh
public:
	//0xAA69D0
	CMessageCutSceneMode();
	virtual ~CMessageCutSceneMode() {} //v0
	virtual WORD GetMsgType(void) {return 0;} //v4, ?
	virtual BYTE GetNetworkType1(void) {return 0;} //v8, ?
	virtual BYTE GetNetworkType2(void) {return 0;} //vc, ?
	virtual void Marshal(DWORD* pData, DWORD* dwSize) {return;} //v10
	virtual BOOL Unmarshal(DWORD* pData, DWORD* dwSize) {return FALSE;} //v14
	virtual void DoMessage(void) {return;} //v18

	bool bEnable; //ch
	BYTE ud; //pad
};

#define STRREF_PARTYSLOT_0 -2
#define STRREF_PARTYSLOT_1 -3
#define STRREF_PARTYSLOT_2 -4
#define STRREF_PARTYSLOT_3 -5
#define STRREF_PARTYSLOT_4 -6
#define STRREF_PARTYSLOT_5 -7

class CMessageDisplayDialogue : public CMessage { //Size 24h
public:
	//0xAA63CC
	CMessageDisplayDialogue();
	virtual ~CMessageDisplayDialogue() {} //v0
	virtual WORD GetMsgType(void) {return 0;} //v4, ?
	virtual BYTE GetNetworkType1(void) {return 0;} //v8, ?
	virtual BYTE GetNetworkType2(void) {return 0;} //vc, ?
	virtual void Marshal(DWORD* pData, DWORD* dwSize) {return;} //v10
	virtual BOOL Unmarshal(DWORD* pData, DWORD* dwSize) {return FALSE;} //v14
	virtual void DoMessage(void) {return;} //v18

	STRREF srOwner; //ch
	STRREF srText; //10h
	ARGB rgbOwner; //14h
	ARGB rgbText; //18h
	DWORD u1c; //-1
	BYTE u20;
	bool bFloatText; //21h
	bool u22;
	bool bPlaySound; //23h, plays an empty sound
};

class CMessageDisplayText : public CMessage { //Size 24h
public:
	//0xAA9774
	CMessageDisplayText();
	virtual ~CMessageDisplayText() {} //v0
	virtual WORD GetMsgType(void) {return 0;} //v4, ?
	virtual BYTE GetNetworkType1(void) {return 0;} //v8, ?
	virtual BYTE GetNetworkType2(void) {return 0;} //vc, ?
	virtual void Marshal(DWORD* pData, DWORD* dwSize) {return;} //v10
	virtual BOOL Unmarshal(DWORD* pData, DWORD* dwSize) {return FALSE;} //v14
	virtual void DoMessage(void) {return;} //v18

	IECString sLeft; //ch
	IECString sRight; //10h
	ARGB rgbLeft; //14h
	ARGB rgbRight; //18h
	DWORD u1c; //-1
	BYTE u20;
	bool bFloatText; //21h
	bool u22;
	bool u23; //pad
};

class CMessageSetTrigger : public CMessage { //Size 3Ah
public:
	//0xAA5C84
	CMessageSetTrigger();
	virtual ~CMessageSetTrigger() {} //v0
	virtual WORD GetMsgType(void) {return 0;} //v4, ?
	virtual BYTE GetNetworkType1(void) {return 0;} //v8, ?
	virtual BYTE GetNetworkType2(void) {return 0;} //vc, ?
	virtual void Marshal(DWORD* pData, DWORD* dwSize) {return;} //v10
	virtual BOOL Unmarshal(DWORD* pData, DWORD* dwSize) {return FALSE;} //v14
	virtual void DoMessage(void) {return;} //v18

	Trigger t; //ch
};

class CMessageSpriteUpdate : public CMessage { //Size 58h
public:
	//0xAAB914
	CMessageSpriteUpdate();
	CMessageSpriteUpdate(CCreatureObject*, Enum, Enum);
	CMessageSpriteUpdate* Construct(CCreatureObject* pCre, Enum eSource, Enum eTarget) {return this;} //dummy

	virtual ~CMessageSpriteUpdate() {} //v0
	virtual WORD GetMsgType(void) {return 0;} //v4, ?
	virtual BYTE GetNetworkType1(void) {return 0;} //v8, ?
	virtual BYTE GetNetworkType2(void) {return 0;} //vc, ?
	virtual void Marshal(DWORD* pData, DWORD* dwSize) {return;} //v10
	virtual BOOL Unmarshal(DWORD* pData, DWORD* dwSize) {return FALSE;} //v14
	virtual void DoMessage(void) {return;} //v18

	DWORD uc; //pointer to object with size designated by u10*4
	WORD u10; //sprite 33eeh, related to current area, size of object pointed by uc/4
	WORD u12; //sprite 3428h, related to current area
	QWORD u14; //sprite 35ech
	IECString areaName; //1ch
	WORD wCurrentSequence; //20h
	POINT pos; //22h, sprite position
	WORD u2a; //linked to animation, sprite 33e8h
	DWORD stateFlags; //2ch, from CDerivedStats
	WORD currentHP; //30h
	WORD maxHP; //32h
	WORD effectiveAC; //34h
	WORD ACCrushingMod; //36h
	WORD ACMissileMod; //38h
	WORD ACPiercingMod; //3ah
	WORD ACSlashingMod; //3ch
	WORD m_nPortraitIcons; //3eh
	DWORD m_pPortraitIcons; //40h, each object is 4h in size
	BYTE EnemyAlly; //44h
	BYTE EnemyAlly2; //45h, from CCreatureObject IdsCopy2
	BYTE General; //46h
	BYTE General2; //47h, from CCreatureObject IdsCopy2
	BYTE u48; //sprite 6298h
	BYTE u49; //something from m_animation
	DWORD u4a; //related to constitution?, sprite 63b6h
	BYTE u4e; //sprite 63ceh
	BYTE u4f; //CDerivedStats 1e2h
	BYTE doNotJump; //50h, from CDerivedStats
	BYTE u51; //CDerivedStats a0h
	BYTE u52; //CDerivedStats 230h
	BYTE u53; //CDerivedStats 90h
	BYTE u54; //sprite 2c0ch
	BYTE u55; //padding
	WORD u56;
};

extern CMessageSpriteUpdate* (CMessageSpriteUpdate::*CMessageSpriteUpdate_Construct)(CCreatureObject*, Enum, Enum);

extern WORD (CMessageSpriteUpdate::*CMessageSpriteUpdate_GetMsgType)(void);

struct CMessageHandler { //Size 114h
//Constructor: 0x43CD30

	//members
	BYTE u0;
	BYTE u1;
	BYTE u2;
	BYTE u3;
	BYTE u4;
	BYTE u5;
	BYTE u6;
	BYTE u7;

	struct _u8 {
		CPtrList u0; //AA63B4
		CPtrList u1c; //AA63B4
		DWORD u38;
	} u8;

	BYTE u44; //24, nObjects?
	BYTE u45;
	BYTE u46;
	BYTE u47[24]; //related to u44
	BYTE u5f[24];
	BYTE u77[24]; //related to u44
	BYTE u8f;
	IECString u90;
	DWORD u94;
	BYTE u98[6];
	DWORD u9e[6];
#ifdef _DEBUG
	_CCriticalSection ub6;
#else
	CCriticalSection ub6;
#endif
	DWORD ud6[6];
	BYTE uee;
	BYTE uef;
	BYTE uf0;
	BYTE uf1;
	DWORD uf2;
	BYTE uf6;
	BYTE uf7;
	BYTE uf8;
	BYTE uf9;
	BYTE ufa;
	BYTE ufb;
	BYTE ufc;
	BYTE ufd;
	BYTE ufe;
	BYTE uff;
	BYTE u100;
	BYTE u101;
	IECString u102;
	IECString u106;
	WORD u10a;
	DWORD u10c; //ClientTimout
	BYTE u110;
	BYTE u111;
	BYTE u112;
	BYTE u113; //pad
};

#endif //MSGCORE_H