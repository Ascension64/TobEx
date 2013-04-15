//TobExEE
#ifndef MSGCORE_H
#define MSGCORE_H

#include "stdafx.h"
#include "scrcore.h"
#include "effcore.h"
#include "objcre.h"

class CMessage { //Size Ch
public:
	CMessage() {}
	virtual ~CMessage() {} //v0
	virtual short GetMsgType() {return 0;} //v4
	virtual char GetNetworkType1() {return 0;} //v8
	virtual char GetNetworkType2() {return 0;} //vc
	virtual void Marshal(void* pData, int* dwSize) {return;} //v10
	virtual BOOL Unmarshal(void* pData, int* dwSize) {return FALSE;} //v14
	virtual void DoMessage() {return;} //v18

	ENUM m_eTarget; //4h
	ENUM m_eSource; //8h
};

//CMessageDisplayDialogue
#define STRREF_PARTYSLOT_0	-2
#define STRREF_PARTYSLOT_1	-3
#define STRREF_PARTYSLOT_2	-4
#define STRREF_PARTYSLOT_3	-5
#define STRREF_PARTYSLOT_4	-6
#define STRREF_PARTYSLOT_5	-7

//CMessageModifyVariable
class CMessageModifyVariable : public CMessage { //Size 1Ch
	DEFINE_MEMALLOC_FUNC;
public:
	CMessageModifyVariable(IECString& sVariable, IECString& sScope, int nValue, unsigned char cType, ENUM eSource, ENUM eTarget);
	CMessageModifyVariable& Construct(IECString& sVariable, IECString& sScope, int nValue, unsigned char cType, ENUM eSource, ENUM eTarget) {return *this;} //dummy

	virtual ~CMessageModifyVariable(); //v0
	void Deconstruct() {} //dummy

	IECString m_sScope; //ch
	IECString m_sVariable; //10h
	int m_nValue; //14h
	unsigned char m_cBehaviour; //18h, 0 = set, 1 = sum
	char p19[3];
};

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

struct CUserMessages { //Size 3Ch
	CIECStringList m_names; //0h
	CIECStringList m_texts; //1ch
	int m_nNumMessages; //38h
};

struct CRemoteMessageHandler { //Size F8h
	char u0;
	char u1;
	char u2;
	char u3;
	char u4;
	char u5;
	char u6;
	char u7;
	CUserMessages m_UserMessages; //8h
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
	char p9e[2];
	int ua0[6];
	int ub8[6];
	char ud0;
	char ud1;
	char ud2;
	char ud3;
	int ud4;
	char ud8;
	char ud9;
	char uda;
	char udb;
	char udc;
	char udd;
	char ude;
	char udf;
	char ue0;
	char ue1;
	char ue2;
	char ue3;
	IECString ue4;
	IECString ue8;
	short uec;
	char pee[2];
	int uf0; //ClientTimout
	bool m_bCloseNetworkSession; //f4h
	char uf5;
	char uf6;
	char pf7;
};

class CMessageHandler : public IECPtrList { //Size 20h
public:
	short AddMessage(CMessage& msg, BOOL bForceAddToQueue);

	char u1c; //gets a value from CMultiplayerSettings
	char p1d[3];
};


#endif //MSGCORE_H