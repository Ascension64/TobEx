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
