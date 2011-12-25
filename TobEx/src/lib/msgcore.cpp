#include "msgcore.h"

#include "stdafx.h"
#include "objcre.h"

CMessage::CMessage() {
	SetVT(this, 0xAA5C10);
	eTarget = ENUM_INVALID_INDEX;
	eSource = ENUM_INVALID_INDEX;
}

short (CPtrListMessage::*CPtrListMessage_Send)(CMessage&, BOOL) =
	SetFP(static_cast<short (CPtrListMessage::*)(CMessage&, BOOL)>		(&CPtrListMessage::Send),		0x5B91FD);

short CPtrListMessage::Send(CMessage& msg, BOOL bForceAddToQueue) {	return (this->*CPtrListMessage_Send)(msg, bForceAddToQueue); }

CMessageAddAction::CMessageAddAction() { SetVT(this, 0xAA5BF4); }

CMessageApplyEffect::CMessageApplyEffect() {
	SetVT(this, 0xAA6A40);
	u10 = 0;
	u11 = 0;
}

CMessageCreatureOverlay::CMessageCreatureOverlay() {
	SetVT(this, 0xAA9790);
	param = 0;
	val = 0;
}

CMessageCutSceneMode::CMessageCutSceneMode() {
	SetVT(this, 0xAA69D0);
	bEnable = 0;
	ud = 0;
}

CMessageDisplayDialogue::CMessageDisplayDialogue() {
	SetVT(this, 0xAA63CC);
	srOwner = -1;
	srText = -1;
	rgbOwner = 0x000000;
	rgbText = g_ColorDefaultText;
	u1c = -1;
	u20 = FALSE;
	bFloatText = FALSE;
	u22 = FALSE;
	bPlaySound = TRUE;
}

CMessageDisplayText::CMessageDisplayText() {
	SetVT(this, 0xAA9774);
	rgbLeft = 0x000000;
	rgbRight = g_ColorDefaultText;
	u1c = -1;
	bFloatText = FALSE;
	u22 = FALSE;
	u23 = TRUE;
}

//CMessagePlaySound
CMessagePlaySound* (CMessagePlaySound::*CMessagePlaySound_Construct_4)(ResRef, int, Enum, Enum) =
	SetFP(static_cast<CMessagePlaySound* (CMessagePlaySound::*)(ResRef, int, Enum, Enum)>
																(&CMessagePlaySound::Construct),		0x5684E0);
void (CMessagePlaySound::*CMessagePlaySound_Deconstruct)() =
	SetFP(static_cast<void (CMessagePlaySound::*)()>			(&CMessagePlaySound::Deconstruct),		0x4B7010);
short (CMessagePlaySound::*CMessagePlaySound_GetMsgType)() =
	SetFP(static_cast<short (CMessagePlaySound::*)()>			(&CMessagePlaySound::GetMsgType),		0x4B6F90);
char (CMessagePlaySound::*CMessagePlaySound_GetNetworkType1)() =
	SetFP(static_cast<char (CMessagePlaySound::*)()>			(&CMessagePlaySound::GetNetworkType1),	0x4B6FC0);
char (CMessagePlaySound::*CMessagePlaySound_GetNetworkType2)() =
	SetFP(static_cast<char (CMessagePlaySound::*)()>			(&CMessagePlaySound::GetNetworkType2),	0x4B6FD0);
void (CMessagePlaySound::*CMessagePlaySound_Marshal)(void*, int*) =
	SetFP(static_cast<void (CMessagePlaySound::*)(void*, int*)>	(&CMessagePlaySound::Marshal),			0x5CBD6A);
BOOL (CMessagePlaySound::*CMessagePlaySound_Unmarshal)(void*, int*) =
	SetFP(static_cast<BOOL (CMessagePlaySound::*)(void*, int*)>	(&CMessagePlaySound::Unmarshal),		0x5CC06A);
void (CMessagePlaySound::*CMessagePlaySound_DoMessage)() =
	SetFP(static_cast<void (CMessagePlaySound::*)()>			(&CMessagePlaySound::DoMessage),		0x5CC258);

CMessagePlaySound::CMessagePlaySound() {
	SetVT(this, 0xAA6E68);
	nChannel = 0;
	u15 = 0;
	u16 = 0;
}

CMessagePlaySound::CMessagePlaySound(ResRef rSound, int n, Enum eSource, Enum eTarget)
	{ (this->*CMessagePlaySound_Construct_4)(rSound, n, eSource, eTarget); }
CMessagePlaySound::~CMessagePlaySound()						{ (this->*CMessagePlaySound_Deconstruct)(); }
short CMessagePlaySound::GetMsgType()						{ return (this->*CMessagePlaySound_GetMsgType)(); }
char CMessagePlaySound::GetNetworkType1()					{ return (this->*CMessagePlaySound_GetNetworkType1)(); }
char CMessagePlaySound::GetNetworkType2()					{ return (this->*CMessagePlaySound_GetNetworkType2)(); }
void CMessagePlaySound::Marshal(void* pData, int* dwSize)	{ return (this->*CMessagePlaySound_Marshal)(pData, dwSize); }
BOOL CMessagePlaySound::Unmarshal(void* pData, int* dwSize)	{ return (this->*CMessagePlaySound_Unmarshal)(pData, dwSize); }
void CMessagePlaySound::DoMessage()							{ return (this->*CMessagePlaySound_DoMessage)(); }

//CMessagePlaySoundset
void (CMessagePlaySoundset::*CMessagePlaySoundset_Deconstruct)() =
	SetFP(static_cast<void (CMessagePlaySoundset::*)()>				(&CMessagePlaySoundset::Deconstruct),		0x4E9740);
short (CMessagePlaySoundset::*CMessagePlaySoundset_GetMsgType)() =
	SetFP(static_cast<short (CMessagePlaySoundset::*)()>			(&CMessagePlaySoundset::GetMsgType),		0x4E96D0);
char (CMessagePlaySoundset::*CMessagePlaySoundset_GetNetworkType1)() =
	SetFP(static_cast<char (CMessagePlaySoundset::*)()>				(&CMessagePlaySoundset::GetNetworkType1),	0x4E96F0);
char (CMessagePlaySoundset::*CMessagePlaySoundset_GetNetworkType2)() =
	SetFP(static_cast<char (CMessagePlaySoundset::*)()>				(&CMessagePlaySoundset::GetNetworkType2),	0x4E9700);
void (CMessagePlaySoundset::*CMessagePlaySoundset_Marshal)(void*, int*) =
	SetFP(static_cast<void (CMessagePlaySoundset::*)(void*, int*)>	(&CMessagePlaySoundset::Marshal),			0x5CB939);
BOOL (CMessagePlaySoundset::*CMessagePlaySoundset_Unmarshal)(void*, int*) =
	SetFP(static_cast<BOOL (CMessagePlaySoundset::*)(void*, int*)>	(&CMessagePlaySoundset::Unmarshal),			0x5CBB4C);
void (CMessagePlaySoundset::*CMessagePlaySoundset_DoMessage)() =
	SetFP(static_cast<void (CMessagePlaySoundset::*)()>				(&CMessagePlaySoundset::DoMessage),			0x5CBC95);

CMessagePlaySoundset::CMessagePlaySoundset() {
	SetVT(this, 0xAA73DC);
	bPrintToConsole = FALSE;
	bLimitLength = FALSE;
	nSoundIdx = 0;
	u15 = 0;
}

CMessagePlaySoundset::~CMessagePlaySoundset()					{ (this->*CMessagePlaySoundset_Deconstruct)(); }
short CMessagePlaySoundset::GetMsgType()						{ return (this->*CMessagePlaySoundset_GetMsgType)(); }
char CMessagePlaySoundset::GetNetworkType1()					{ return (this->*CMessagePlaySoundset_GetNetworkType1)(); }
char CMessagePlaySoundset::GetNetworkType2()					{ return (this->*CMessagePlaySoundset_GetNetworkType2)(); }
void CMessagePlaySoundset::Marshal(void* pData, int* dwSize)	{ return (this->*CMessagePlaySoundset_Marshal)(pData, dwSize); }
BOOL CMessagePlaySoundset::Unmarshal(void* pData, int* dwSize)	{ return (this->*CMessagePlaySoundset_Unmarshal)(pData, dwSize); }
void CMessagePlaySoundset::DoMessage()							{ return (this->*CMessagePlaySoundset_DoMessage)(); }

//CMessageRemoveAreaAirEffects
void (CMessageRemoveAreaAirEffects::*CMessageRemoveAreaAirEffects_Deconstruct)() =
	SetFP(static_cast<void (CMessageRemoveAreaAirEffects::*)()>				(&CMessageRemoveAreaAirEffects::Deconstruct),		0x4E2930);
short (CMessageRemoveAreaAirEffects::*CMessageRemoveAreaAirEffects_GetMsgType)() =
	SetFP(static_cast<short (CMessageRemoveAreaAirEffects::*)()>			(&CMessageRemoveAreaAirEffects::GetMsgType),		0x4E28C0);
char (CMessageRemoveAreaAirEffects::*CMessageRemoveAreaAirEffects_GetNetworkType1)() =
	SetFP(static_cast<char (CMessageRemoveAreaAirEffects::*)()>				(&CMessageRemoveAreaAirEffects::GetNetworkType1),	0x4E28E0);
char (CMessageRemoveAreaAirEffects::*CMessageRemoveAreaAirEffects_GetNetworkType2)() =
	SetFP(static_cast<char (CMessageRemoveAreaAirEffects::*)()>				(&CMessageRemoveAreaAirEffects::GetNetworkType2),	0x4E28F0);
void (CMessageRemoveAreaAirEffects::*CMessageRemoveAreaAirEffects_Marshal)(void*, int*) =
	SetFP(static_cast<void (CMessageRemoveAreaAirEffects::*)(void*, int*)>	(&CMessageRemoveAreaAirEffects::Marshal),			0x5BD036);
BOOL (CMessageRemoveAreaAirEffects::*CMessageRemoveAreaAirEffects_Unmarshal)(void*, int*) =
	SetFP(static_cast<BOOL (CMessageRemoveAreaAirEffects::*)(void*, int*)>	(&CMessageRemoveAreaAirEffects::Unmarshal),			0x5BD111);
void (CMessageRemoveAreaAirEffects::*CMessageRemoveAreaAirEffects_DoMessage)() =
	SetFP(static_cast<void (CMessageRemoveAreaAirEffects::*)()>				(&CMessageRemoveAreaAirEffects::DoMessage),			0x5BD193);

CMessageRemoveAreaAirEffects::CMessageRemoveAreaAirEffects()			{ SetVT(this, 0xAA727C); }
CMessageRemoveAreaAirEffects::~CMessageRemoveAreaAirEffects()			{ (this->*CMessageRemoveAreaAirEffects_Deconstruct)(); }
short CMessageRemoveAreaAirEffects::GetMsgType()						{ return (this->*CMessageRemoveAreaAirEffects_GetMsgType)(); }
char CMessageRemoveAreaAirEffects::GetNetworkType1()					{ return (this->*CMessageRemoveAreaAirEffects_GetNetworkType1)(); }
char CMessageRemoveAreaAirEffects::GetNetworkType2()					{ return (this->*CMessageRemoveAreaAirEffects_GetNetworkType2)(); }
void CMessageRemoveAreaAirEffects::Marshal(void* pData, int* dwSize)	{ return (this->*CMessageRemoveAreaAirEffects_Marshal)(pData, dwSize); }
BOOL CMessageRemoveAreaAirEffects::Unmarshal(void* pData, int* dwSize)	{ return (this->*CMessageRemoveAreaAirEffects_Unmarshal)(pData, dwSize); }
void CMessageRemoveAreaAirEffects::DoMessage()							{ return (this->*CMessageRemoveAreaAirEffects_DoMessage)(); }

CMessageSetTrigger::CMessageSetTrigger() { SetVT(this, 0xAA5C84); }

CMessageSpriteUpdate* (CMessageSpriteUpdate::*CMessageSpriteUpdate_Construct)(CCreatureObject*, Enum, Enum) =
	SetFP(static_cast<CMessageSpriteUpdate* (CMessageSpriteUpdate::*)(CCreatureObject*, Enum, Enum)>	(&CMessageSpriteUpdate::Construct),	0x5D8B73);

CMessageSpriteUpdate::CMessageSpriteUpdate() { SetVT(this, 0xAAB914); }
CMessageSpriteUpdate::CMessageSpriteUpdate(CCreatureObject* pCre, Enum eSource, Enum eTarget) {
	(this->*CMessageSpriteUpdate_Construct)(pCre, eSource, eTarget);
}
