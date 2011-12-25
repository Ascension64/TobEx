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
	void ExecuteMessages();
	short Send(CMessage& msg, BOOL bForceAddToQueue);

	char u1c; //gets u90 from CMultiplayerSettings
	char u1d; //pad
};

extern void (CPtrListMessage::*CPtrListMessage_ExecuteMessages)();
extern short (CPtrListMessage::*CPtrListMessage_Send)(CMessage&, BOOL);

class CMessageAddActionHead: public CMessage { //Size 6Ah
public:
	//AA5BF4
	CMessageAddActionHead();
	virtual ~CMessageAddActionHead() {} //v0
	virtual short GetMsgType(void) {return 0;} //v4, ?
	virtual char GetNetworkType1(void) {return 0;} //v8, ?
	virtual char GetNetworkType2(void) {return 0;} //vc, ?
	virtual void Marshal(void* pData, int* dwSize) {return;} //v10
	virtual BOOL Unmarshal(void* pData, int* dwSize) {return FALSE;} //v14
	virtual void DoMessage(void) {return;} //v18

	Action a;
};

class CMessageAddActionTailInterrupt : public CMessage { //Size 6Ah
public:
	CMessageAddActionTailInterrupt();

	//AA6ACC
	virtual ~CMessageAddActionTailInterrupt(); //v0
	void Deconstruct() {} //dummy

	virtual short GetMsgType(void); //v4
	virtual char GetNetworkType1(void); //v8
	virtual char GetNetworkType2(void); //vc
	virtual void Marshal(void* pData, int* dwSize); //v10
	virtual BOOL Unmarshal(void* pData, int* dwSize); //v14
	virtual void DoMessage(void); //v18

	Action a; //ch
};

extern void (CMessageAddActionTailInterrupt::*CMessageAddActionTailInterrupt_Deconstruct)();
extern short (CMessageAddActionTailInterrupt::*CMessageAddActionTailInterrupt_GetMsgType)(void);
extern char (CMessageAddActionTailInterrupt::*CMessageAddActionTailInterrupt_GetNetworkType1)(void);
extern char (CMessageAddActionTailInterrupt::*CMessageAddActionTailInterrupt_GetNetworkType2)(void);
extern void (CMessageAddActionTailInterrupt::*CMessageAddActionTailInterrupt_Marshal)(void*, int*);
extern BOOL (CMessageAddActionTailInterrupt::*CMessageAddActionTailInterrupt_Unmarshal)(void*, int*);
extern void (CMessageAddActionTailInterrupt::*CMessageAddActionTailInterrupt_DoMessage)(void);

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

class CMessageCastSpell : public CMessage { //Size 14h
public:
	CMessageCastSpell();

	//AA9970
	virtual ~CMessageCastSpell(); //v0
	void Deconstruct() {} //dummy

	virtual short GetMsgType(void); //v4
	virtual char GetNetworkType1(void); //v8
	virtual char GetNetworkType2(void); //vc
	virtual void Marshal(void* pData, int* dwSize); //v10
	virtual BOOL Unmarshal(void* pData, int* dwSize); //v14
	virtual void DoMessage(void); //v18

	IECString sSpell; //ch
	Enum eSpellTarget; //10h
};

extern void (CMessageCastSpell::*CMessageCastSpell_Deconstruct)();
extern short (CMessageCastSpell::*CMessageCastSpell_GetMsgType)(void);
extern char (CMessageCastSpell::*CMessageCastSpell_GetNetworkType1)(void);
extern char (CMessageCastSpell::*CMessageCastSpell_GetNetworkType2)(void);
extern void (CMessageCastSpell::*CMessageCastSpell_Marshal)(void*, int*);
extern BOOL (CMessageCastSpell::*CMessageCastSpell_Unmarshal)(void*, int*);
extern void (CMessageCastSpell::*CMessageCastSpell_DoMessage)(void);

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
	ABGR rgbOwner; //14h
	ABGR rgbText; //18h
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
	ABGR rgbLeft; //14h
	ABGR rgbRight; //18h
	int u1c; //-1
	char u20;
	bool bFloatText; //21h
	bool u22;
	bool u23; //pad
};

class CMessageHostReleaseServerStore : public CMessage { //Size 14h
public:
	CMessageHostReleaseServerStore();

	//AA7298
	virtual ~CMessageHostReleaseServerStore(); //v0
	void Deconstruct() {} //dummy

	virtual short GetMsgType(void); //v4
	virtual char GetNetworkType1(void); //v8
	virtual char GetNetworkType2(void); //vc
	virtual void Marshal(void* pData, int* dwSize); //v10
	virtual BOOL Unmarshal(void* pData, int* dwSize); //v14
	virtual void DoMessage(void); //v18

	ResRef rStoreName; //ch
};

extern void (CMessageHostReleaseServerStore::*CMessageHostReleaseServerStore_Deconstruct)();
extern short (CMessageHostReleaseServerStore::*CMessageHostReleaseServerStore_GetMsgType)(void);
extern char (CMessageHostReleaseServerStore::*CMessageHostReleaseServerStore_GetNetworkType1)(void);
extern char (CMessageHostReleaseServerStore::*CMessageHostReleaseServerStore_GetNetworkType2)(void);
extern void (CMessageHostReleaseServerStore::*CMessageHostReleaseServerStore_Marshal)(void*, int*);
extern BOOL (CMessageHostReleaseServerStore::*CMessageHostReleaseServerStore_Unmarshal)(void*, int*);
extern void (CMessageHostReleaseServerStore::*CMessageHostReleaseServerStore_DoMessage)(void);

class CMessageModifyVariable : public CMessage { //Size 1Ah
public:
	CMessageModifyVariable();

	//AA6CE0
	virtual ~CMessageModifyVariable(); //v0
	void Deconstruct() {} //dummy

	virtual short GetMsgType(void); //v4
	virtual char GetNetworkType1(void); //v8
	virtual char GetNetworkType2(void); //vc
	virtual void Marshal(void* pData, int* dwSize); //v10
	virtual BOOL Unmarshal(void* pData, int* dwSize); //v14
	virtual void DoMessage(void); //v18

	IECString sScope; //ch
	IECString sVariable; //10h
	int nValue; //14h
	unsigned char nBehaviour; //18h, 0 = set, 1 = sum
	char u19; //pad
};

extern void (CMessageModifyVariable::*CMessageModifyVariable_Deconstruct)();
extern short (CMessageModifyVariable::*CMessageModifyVariable_GetMsgType)(void);
extern char (CMessageModifyVariable::*CMessageModifyVariable_GetNetworkType1)(void);
extern char (CMessageModifyVariable::*CMessageModifyVariable_GetNetworkType2)(void);
extern void (CMessageModifyVariable::*CMessageModifyVariable_Marshal)(void*, int*);
extern BOOL (CMessageModifyVariable::*CMessageModifyVariable_Unmarshal)(void*, int*);
extern void (CMessageModifyVariable::*CMessageModifyVariable_DoMessage)(void);

class CMessagePlaySound : public CMessage { //Size 1Ah
//Constructor: 0x5684E0
public:
	CMessagePlaySound();

	CMessagePlaySound(ResRef rSound, int n, Enum eSource, Enum eTarget);
	CMessagePlaySound* Construct(ResRef rSound, int n, Enum eSource, Enum eTarget) { return this; } //dummy

	//AA6E68
	virtual ~CMessagePlaySound(); //v0
	void Deconstruct() {} //dummy

	virtual short GetMsgType(void); //v4
	virtual char GetNetworkType1(void); //v8
	virtual char GetNetworkType2(void); //vc
	virtual void Marshal(void* pData, int* dwSize); //v10
	virtual BOOL Unmarshal(void* pData, int* dwSize); //v14
	virtual void DoMessage(void); //v18

	ResRef rSound; //ch
	unsigned char nChannel; //14h
	unsigned char u15;
	int u16;
};

extern CMessagePlaySound* (CMessagePlaySound::*CMessagePlaySound_Construct_4)(ResRef, int, Enum, Enum);
extern void (CMessagePlaySound::*CMessagePlaySound_Deconstruct)();
extern short (CMessagePlaySound::*CMessagePlaySound_GetMsgType)(void);
extern char (CMessagePlaySound::*CMessagePlaySound_GetNetworkType1)(void);
extern char (CMessagePlaySound::*CMessagePlaySound_GetNetworkType2)(void);
extern void (CMessagePlaySound::*CMessagePlaySound_Marshal)(void*, int*);
extern BOOL (CMessagePlaySound::*CMessagePlaySound_Unmarshal)(void*, int*);
extern void (CMessagePlaySound::*CMessagePlaySound_DoMessage)(void);

//CMessagePlaySoundset
#define SOUNDSET_INITIAL_MEETING		1
#define SOUNDSET_MORALE					2
#define SOUNDSET_HAPPY					3
#define SOUNDSET_UNHAPPY_ANNOYED		4
#define SOUNDSET_UNHAPPY_SERIOUS		5
#define SOUNDSET_UNHAPPY_BREAKINGPOIINT	6
#define SOUNDSET_LEADER					7
#define SOUNDSET_TIRED					8
#define SOUNDSET_BORED					9
#define SOUNDSET_BATTLE_CRY				10
#define SOUNDSET_ATTACK					11
#define SOUNDSET_DAMAGE					12
#define SOUNDSET_DYING					13
#define SOUNDSET_HURT					14
#define SOUNDSET_AREA_FOREST			15
#define SOUNDSET_AREA_CITY				16
#define SOUNDSET_AREA_DUNGEON			17
#define SOUNDSET_AREA_DAY				18
#define SOUNDSET_AREA_NIGHT				19
#define SOUNDSET_SELECT_COMMON			20
#define SOUNDSET_SELECT_COMMON_NOOPT	21
#define SOUNDSET_SELECT_ACTION			22
#define SOUNDSET_SELECT_RARE			23
#define SOUNDSET_INTERACTION			24
#define SOUNDSET_INSULT					25
#define SOUNDSET_COMPLIMENT				26
#define SOUNDSET_SPECIAL				27
#define SOUNDSET_REACT_TO_DIE_GENERAL	28
#define SOUNDSET_REACT_TO_DIE_SPECIFIC	29
#define SOUNDSET_MISC_20				30
#define SOUNDSET_RESPONSE_TO_COMPLIMENT	31
#define SOUNDSET_RESPONSE_TO_INSULT		32
#define SOUNDSET_DIALOG_HOSTILE			33
#define SOUNDSET_DIALOG_DEFAULT			34
#define SOUNDSET_EXISTANCE				35
#define SOUNDSET_SELECT_RARE2			36
#define SOUNDSET_CRITICAL_HIT			37
#define SOUNDSET_CRITICAL_MISS			38
#define SOUNDSET_TARGET_IMMUNE			39
#define SOUNDSET_INVENTORY_FULL			40
#define SOUNDSET_PICKED_POCKET			41
#define SOUNDSET_EXISTANCE1				42
#define SOUNDSET_EXISTANCE2				43
#define SOUNDSET_EXISTANCE3				44

class CMessagePlaySoundset : public CMessage { //Size 16h
public:
	//AA73DC
	CMessagePlaySoundset();

	virtual ~CMessagePlaySoundset(); //v0
	void Deconstruct() {} //dummy

	virtual short GetMsgType(void); //v4
	virtual char GetNetworkType1(void); //v8
	virtual char GetNetworkType2(void); //vc
	virtual void Marshal(void* pData, int* dwSize); //v10
	virtual BOOL Unmarshal(void* pData, int* dwSize); //v14
	virtual void DoMessage(void); //v18

	BOOL bPrintToConsole; //ch
	BOOL bLimitLength; //10h
	unsigned char nSoundIdx; //14h
	char u15; //pad
};

extern void (CMessagePlaySoundset::*CMessagePlaySoundset_Deconstruct)();
extern short (CMessagePlaySoundset::*CMessagePlaySoundset_GetMsgType)(void);
extern char (CMessagePlaySoundset::*CMessagePlaySoundset_GetNetworkType1)(void);
extern char (CMessagePlaySoundset::*CMessagePlaySoundset_GetNetworkType2)(void);
extern void (CMessagePlaySoundset::*CMessagePlaySoundset_Marshal)(void*, int*);
extern BOOL (CMessagePlaySoundset::*CMessagePlaySoundset_Unmarshal)(void*, int*);
extern void (CMessagePlaySoundset::*CMessagePlaySoundset_DoMessage)(void);

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

//CMessageSetAnimationSequence
class CMessageSetAnimationSequence : public CMessage { //Size Eh
public:
	//AA6D6C
	CMessageSetAnimationSequence();

	virtual ~CMessageSetAnimationSequence(); //v0
	void Deconstruct() {} //dummy

	virtual short GetMsgType(void); //v4
	virtual char GetNetworkType1(void); //v8
	virtual char GetNetworkType2(void); //vc
	virtual void Marshal(void* pData, int* dwSize); //v10
	virtual BOOL Unmarshal(void* pData, int* dwSize); //v14
	virtual void DoMessage(void); //v18

	unsigned char nSeq; //ch, SEQ.IDS
	char ud; //pad
};

extern void (CMessageSetAnimationSequence::*CMessageSetAnimationSequence_Deconstruct)();
extern short (CMessageSetAnimationSequence::*CMessageSetAnimationSequence_GetMsgType)(void);
extern char (CMessageSetAnimationSequence::*CMessageSetAnimationSequence_GetNetworkType1)(void);
extern char (CMessageSetAnimationSequence::*CMessageSetAnimationSequence_GetNetworkType2)(void);
extern void (CMessageSetAnimationSequence::*CMessageSetAnimationSequence_Marshal)(void*, int*);
extern BOOL (CMessageSetAnimationSequence::*CMessageSetAnimationSequence_Unmarshal)(void*, int*);
extern void (CMessageSetAnimationSequence::*CMessageSetAnimationSequence_DoMessage)(void);

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
	bool RequestHostFile(IECString& sResName, int nCResType, BOOL bSendMsgToHost, BOOL bWaitUntilResponse, bool bUseTempPath);

	char u0;
	char u1;
	char u2;
	char u3;
	char u4;
	char u5;
	char u6;
	char u7;

	struct CUserMessages {
		CIECStringList m_names; //0h
		CIECStringList m_texts; //1ch
		int m_nNumMessages; //38h
	} m_UserMessages; //8h

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
	bool m_bCloseNetworkSession; //110h
	char u111;
	char u112;
	char u113; //pad
};

extern bool (CMessageHandler::*CMessageHandler_RequestHostFile)(IECString&, int, BOOL, BOOL, bool);

#endif //MSGCORE_H