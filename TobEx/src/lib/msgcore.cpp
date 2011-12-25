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
	rgbText = 0xBED7D7;
	u1c = -1;
	u20 = FALSE;
	bFloatText = FALSE;
	u22 = FALSE;
	bPlaySound = TRUE;
}

CMessageDisplayText::CMessageDisplayText() {
	SetVT(this, 0xAA9774);
	rgbLeft = 0x000000;
	rgbRight = 0xBED7D7;
	u1c = -1;
	bFloatText = FALSE;
	u22 = FALSE;
	u23 = TRUE;
}

CMessageSetTrigger::CMessageSetTrigger() { SetVT(this, 0xAA5C84); }

CMessageSpriteUpdate* (CMessageSpriteUpdate::*CMessageSpriteUpdate_Construct)(CCreatureObject*, Enum, Enum) =
	SetFP(static_cast<CMessageSpriteUpdate* (CMessageSpriteUpdate::*)(CCreatureObject*, Enum, Enum)>	(&CMessageSpriteUpdate::Construct),	0x5D8B73);

CMessageSpriteUpdate::CMessageSpriteUpdate() { SetVT(this, 0xAAB914); }
CMessageSpriteUpdate::CMessageSpriteUpdate(CCreatureObject* pCre, Enum eSource, Enum eTarget) {
	(this->*CMessageSpriteUpdate_Construct)(pCre, eSource, eTarget);
}
