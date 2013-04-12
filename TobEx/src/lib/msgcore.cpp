#include "msgcore.h"

#include "stdafx.h"
#include "objcre.h"

//CMessage
CMessage::CMessage() {
	SetVT(this, 0xAA5C10);
	eTarget = ENUM_INVALID_INDEX;
	eSource = ENUM_INVALID_INDEX;
}

//CMessageHandler
DefineLibMemberFunc(void, CMessageHandler, ExecuteMessages, (), ExecuteMessages, ExecuteMessages, (), 0x5B0DB0);
DefineLibMemberFunc(short, CMessageHandler, AddMessage, (CMessage& msg, BOOL bForceAddToQueue), AddMessage, AddMessage, (msg, bForceAddToQueue), 0x5B91FD);

//CMessageAddActionHead
CMessageAddActionHead::CMessageAddActionHead() { SetVT(this, 0xAA5BF4); }

//CMessageAddActionTailInterrupt
CMessageAddActionTailInterrupt::CMessageAddActionTailInterrupt() { SetVT(this, 0xAA6ACC); }
DefineLibNoRetFunc(void, CMessageAddActionTailInterrupt, ~CMessageAddActionTailInterrupt, (), Deconstruct, Deconstruct, (), 0x495AA0);
DefineLibMemberFunc(short, CMessageAddActionTailInterrupt, GetMsgType, (), GetMsgType, GetMsgType, (), 0x495A30);
DefineLibMemberFunc(char, CMessageAddActionTailInterrupt, GetNetworkType1, (), GetNetworkType1, GetNetworkType1, (), 0x495A50);
DefineLibMemberFunc(char, CMessageAddActionTailInterrupt, GetNetworkType2, (), GetNetworkType2, GetNetworkType2, (), 0x495A60);
DefineLibMemberFunc(void, CMessageAddActionTailInterrupt, Marshal, (void* pData, int* dwSize), Marshal, Marshal, (pData, dwSize), 0x5C7F97);
DefineLibMemberFunc(BOOL, CMessageAddActionTailInterrupt, Unmarshal, (void* pData, int* dwSize), Unmarshal, Unmarshal, (pData, dwSize), 0x5C898E);
DefineLibMemberFunc(void, CMessageAddActionTailInterrupt, DoMessage, (), DoMessage, DoMessage, (), 0x5C8EF2);

//CMessageAddEffect
CMessageAddEffect::CMessageAddEffect() {
	SetVT(this, 0xAA6A40);
	u10 = 0;
	u11 = 0;
}

//CMessageCastSpell
CMessageCastSpell::CMessageCastSpell() {
	SetVT(this, 0xAA9970);
	eSpellTarget = ENUM_INVALID_INDEX;
}
DefineLibNoRetFunc(void, CMessageCastSpell, ~CMessageCastSpell, (), Deconstruct, Deconstruct, (), 0x568A70);
DefineLibMemberFunc(short, CMessageCastSpell, GetMsgType, (), GetMsgType, GetMsgType, (), 0x568A00);
DefineLibMemberFunc(char, CMessageCastSpell, GetNetworkType1, (), GetNetworkType1, GetNetworkType1, (), 0x568A20);
DefineLibMemberFunc(char, CMessageCastSpell, GetNetworkType2, (), GetNetworkType2, GetNetworkType2, (), 0x568A30);
DefineLibMemberFunc(void, CMessageCastSpell, Marshal, (void* pData, int* dwSize), Marshal, Marshal, (pData, dwSize), 0x5E75FE);
DefineLibMemberFunc(BOOL, CMessageCastSpell, Unmarshal, (void* pData, int* dwSize), Unmarshal, Unmarshal, (pData, dwSize), 0x5E793C);
DefineLibMemberFunc(void, CMessageCastSpell, DoMessage, (), DoMessage, DoMessage, (), 0x5E7B30);

//CMessageCreatureOverlay
CMessageCreatureOverlay::CMessageCreatureOverlay() {
	SetVT(this, 0xAA9790);
	param = 0;
	val = 0;
}

//CMessageCutSceneMode
CMessageCutSceneMode::CMessageCutSceneMode() {
	SetVT(this, 0xAA69D0);
	bEnable = 0;
	ud = 0;
}

//CMessageDisplayDialogue
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

//CMessageDisplayText
CMessageDisplayText::CMessageDisplayText() {
	SetVT(this, 0xAA9774);
	rgbLeft = 0x000000;
	rgbRight = g_ColorDefaultText;
	u1c = -1;
	bFloatText = FALSE;
	u22 = FALSE;
	u23 = TRUE;
}

//CMessageFaceTalker
CMessageFaceTalker::CMessageFaceTalker() {
	SetVT(this, 0xAA743C);
	nTicks = 0;
	eTarget = ENUM_INVALID_INDEX;
}
DefineLibNoRetFunc(void, CMessageFaceTalker, ~CMessageFaceTalker, (), Deconstruct, Deconstruct, (), 0x4E9920);
DefineLibMemberFunc(short, CMessageFaceTalker, GetMsgType, (), GetMsgType, GetMsgType, (), 0x4E98B0);
DefineLibMemberFunc(char, CMessageFaceTalker, GetNetworkType1, (), GetNetworkType1, GetNetworkType1, (), 0x4E98D0);
DefineLibMemberFunc(char, CMessageFaceTalker, GetNetworkType2, (), GetNetworkType2, GetNetworkType2, (), 0x4E98E0);
DefineLibMemberFunc(void, CMessageFaceTalker, Marshal, (void* pData, int* dwSize), Marshal, Marshal, (pData, dwSize), 0x5CEF30);
DefineLibMemberFunc(BOOL, CMessageFaceTalker, Unmarshal, (void* pData, int* dwSize), Unmarshal, Unmarshal, (pData, dwSize), 0x5CF1E3);
DefineLibMemberFunc(void, CMessageFaceTalker, DoMessage, (), DoMessage, DoMessage, (), 0x5CF365);

//CMessageHostReleaseServerStore
CMessageHostReleaseServerStore::CMessageHostReleaseServerStore() { SetVT(this, 0xAA7298); }
DefineLibNoRetFunc(void, CMessageHostReleaseServerStore, ~CMessageHostReleaseServerStore, (), Deconstruct, Deconstruct, (), 0x4E2BA0);
DefineLibMemberFunc(short, CMessageHostReleaseServerStore, GetMsgType, (), GetMsgType, GetMsgType, (), 0x4E2B30);
DefineLibMemberFunc(char, CMessageHostReleaseServerStore, GetNetworkType1, (), GetNetworkType1, GetNetworkType1, (), 0x4E2B50);
DefineLibMemberFunc(char, CMessageHostReleaseServerStore, GetNetworkType2, (), GetNetworkType2, GetNetworkType2, (), 0x4E2B60);
DefineLibMemberFunc(void, CMessageHostReleaseServerStore, Marshal, (void* pData, int* dwSize), Marshal, Marshal, (pData, dwSize), 0x5DF981);
DefineLibMemberFunc(BOOL, CMessageHostReleaseServerStore, Unmarshal, (void* pData, int* dwSize), Unmarshal, Unmarshal, (pData, dwSize), 0x5DFA5C);
DefineLibMemberFunc(void, CMessageHostReleaseServerStore, DoMessage, (), DoMessage, DoMessage, (), 0x5DFAD7);

//CMessageModifyPartyGold
CMessageModifyPartyGold::CMessageModifyPartyGold() {
	SetVT(this, 0xAA6E4C);
	nGold = 0;
	cMode = 0;
	bPrintMessage = false;
}
DefineLibNoRetFunc(void, CMessageModifyPartyGold, ~CMessageModifyPartyGold, (), Deconstruct, Deconstruct, (), 0x4B6F70);
DefineLibMemberFunc(short, CMessageModifyPartyGold, GetMsgType, (), GetMsgType, GetMsgType, (), 0x5CB613);
DefineLibMemberFunc(char, CMessageModifyPartyGold, GetNetworkType1, (), GetNetworkType1, GetNetworkType1, (), 0x4B6F20);
DefineLibMemberFunc(char, CMessageModifyPartyGold, GetNetworkType2, (), GetNetworkType2, GetNetworkType2, (), 0x4B6F30);
DefineLibMemberFunc(void, CMessageModifyPartyGold, Marshal, (void* pData, int* dwSize), Marshal, Marshal, (pData, dwSize), 0x5CB646);
DefineLibMemberFunc(BOOL, CMessageModifyPartyGold, Unmarshal, (void* pData, int* dwSize), Unmarshal, Unmarshal, (pData, dwSize), 0x5CB749);
DefineLibMemberFunc(void, CMessageModifyPartyGold, DoMessage, (), DoMessage, DoMessage, (), 0x5CB7EA);

//CMessageModifyVariable
CMessageModifyVariable::CMessageModifyVariable() {
	SetVT(this, 0xAA6CE0);
	nValue = 0;
	nBehaviour = 0;
	u19 = 0;
}
DefineLibNoRetFunc(void, CMessageModifyVariable, ~CMessageModifyVariable, (), Deconstruct, Deconstruct, (), 0x4B73A0);
DefineLibMemberFunc(short, CMessageModifyVariable, GetMsgType, (), GetMsgType, GetMsgType, (), 0x4B7330);
DefineLibMemberFunc(char, CMessageModifyVariable, GetNetworkType1, (), GetNetworkType1, GetNetworkType1, (), 0x4B7350);
DefineLibMemberFunc(char, CMessageModifyVariable, GetNetworkType2, (), GetNetworkType2, GetNetworkType2, (), 0x4B7360);
DefineLibMemberFunc(void, CMessageModifyVariable, Marshal, (void* pData, int* dwSize), Marshal, Marshal, (pData, dwSize), 0x5D6108);
DefineLibMemberFunc(BOOL, CMessageModifyVariable, Unmarshal, (void* pData, int* dwSize), Unmarshal, Unmarshal, (pData, dwSize), 0x5D63F3);
DefineLibMemberFunc(void, CMessageModifyVariable, DoMessage, (), DoMessage, DoMessage, (), 0x5D65D0);

//CMessageInterruptDialogue
CMessageInterruptDialogue::CMessageInterruptDialogue() {
	SetVT(this, 0xAA9758);
	b = 0;
	ud = 0;
}
DefineLibNoRetFunc(void, CMessageInterruptDialogue, ~CMessageInterruptDialogue, (), Deconstruct, Deconstruct, (), 0x5689E0);
DefineLibMemberFunc(short, CMessageInterruptDialogue, GetMsgType, (), GetMsgType, GetMsgType, (), 0x568970);
DefineLibMemberFunc(char, CMessageInterruptDialogue, GetNetworkType1, (), GetNetworkType1, GetNetworkType1, (), 0x568990);
DefineLibMemberFunc(char, CMessageInterruptDialogue, GetNetworkType2, (), GetNetworkType2, GetNetworkType2, (), 0x5689A0);
DefineLibMemberFunc(void, CMessageInterruptDialogue, Marshal, (void* pData, int* dwSize), Marshal, Marshal, (pData, dwSize), 0x5E4209);
DefineLibMemberFunc(BOOL, CMessageInterruptDialogue, Unmarshal, (void* pData, int* dwSize), Unmarshal, Unmarshal, (pData, dwSize), 0x5E43C5);
DefineLibMemberFunc(void, CMessageInterruptDialogue, DoMessage, (), DoMessage, DoMessage, (), 0x5E449D);

//CMessagePlaySound
CMessagePlaySound::CMessagePlaySound() {
	SetVT(this, 0xAA6E68);
	nChannel = 0;
	u15 = 0;
	u16 = 0;
}
DefineLibNoRetFunc(CMessagePlaySound*, CMessagePlaySound, CMessagePlaySound, (ResRef rSound, int n, ENUM eSource, ENUM eTarget), Construct, Construct4, (rSound, n, eSource, eTarget), 0x5684E0);
DefineLibNoRetFunc(void, CMessagePlaySound, ~CMessagePlaySound, (), Deconstruct, Deconstruct, (), 0x4B7010);
DefineLibMemberFunc(short, CMessagePlaySound, GetMsgType, (), GetMsgType, GetMsgType, (), 0x4B6F90);
DefineLibMemberFunc(char, CMessagePlaySound, GetNetworkType1, (), GetNetworkType1, GetNetworkType1, (), 0x4B6FC0);
DefineLibMemberFunc(char, CMessagePlaySound, GetNetworkType2, (), GetNetworkType2, GetNetworkType2, (), 0x4B6FD0);
DefineLibMemberFunc(void, CMessagePlaySound, Marshal, (void* pData, int* dwSize), Marshal, Marshal, (pData, dwSize), 0x5CBD6A);
DefineLibMemberFunc(BOOL, CMessagePlaySound, Unmarshal, (void* pData, int* dwSize), Unmarshal, Unmarshal, (pData, dwSize), 0x5CC06A);
DefineLibMemberFunc(void, CMessagePlaySound, DoMessage, (), DoMessage, DoMessage, (), 0x5CC258);

//CMessagePlaySoundset
CMessagePlaySoundset::CMessagePlaySoundset() {
	SetVT(this, 0xAA73DC);
	bPrintToConsole = FALSE;
	bLimitLength = FALSE;
	nSoundIdx = 0;
	u15 = 0;
}
DefineLibNoRetFunc(void, CMessagePlaySoundset, ~CMessagePlaySoundset, (), Deconstruct, Deconstruct, (), 0x4E9740);
DefineLibMemberFunc(short, CMessagePlaySoundset, GetMsgType, (), GetMsgType, GetMsgType, (), 0x4E96D0);
DefineLibMemberFunc(char, CMessagePlaySoundset, GetNetworkType1, (), GetNetworkType1, GetNetworkType1, (), 0x4E96F0);
DefineLibMemberFunc(char, CMessagePlaySoundset, GetNetworkType2, (), GetNetworkType2, GetNetworkType2, (), 0x4E9700);
DefineLibMemberFunc(void, CMessagePlaySoundset, Marshal, (void* pData, int* dwSize), Marshal, Marshal, (pData, dwSize), 0x5CB939);
DefineLibMemberFunc(BOOL, CMessagePlaySoundset, Unmarshal, (void* pData, int* dwSize), Unmarshal, Unmarshal, (pData, dwSize), 0x5CBB4C);
DefineLibMemberFunc(void, CMessagePlaySoundset, DoMessage, (), DoMessage, DoMessage, (), 0x5CBC95);

//CMessageQueueActions
CMessageQueueActions::CMessageQueueActions() {
	SetVT(this, 0xAA6DC0);
	bSkipIfAlreadyQueued = FALSE;
	bClearActionQueue = FALSE;
}
DefineLibNoRetFunc(void, CMessageQueueActions, ~CMessageQueueActions, (), Deconstruct, Deconstruct, (), 0x4B6ED0);
DefineLibMemberFunc(short, CMessageQueueActions, GetMsgType, (), GetMsgType, GetMsgType, (), 0x4B6E60);
DefineLibMemberFunc(char, CMessageQueueActions, GetNetworkType1, (), GetNetworkType1, GetNetworkType1, (), 0x4B6E80);
DefineLibMemberFunc(char, CMessageQueueActions, GetNetworkType2, (), GetNetworkType2, GetNetworkType2, (), 0x4B6E90);
DefineLibMemberFunc(void, CMessageQueueActions, Marshal, (void* pData, int* dwSize), Marshal, Marshal, (pData, dwSize), 0x5C8FF6);
DefineLibMemberFunc(BOOL, CMessageQueueActions, Unmarshal, (void* pData, int* dwSize), Unmarshal, Unmarshal, (pData, dwSize), 0x5C9EF2);
DefineLibMemberFunc(void, CMessageQueueActions, DoMessage, (), DoMessage, DoMessage, (), 0x5CA80B);

//CMessageRemoveAreaAirEffects
CMessageRemoveAreaAirEffects::CMessageRemoveAreaAirEffects()			{ SetVT(this, 0xAA727C); }
DefineLibNoRetFunc(void, CMessageRemoveAreaAirEffects, ~CMessageRemoveAreaAirEffects, (), Deconstruct, Deconstruct, (), 0x4E2930);
DefineLibMemberFunc(short, CMessageRemoveAreaAirEffects, GetMsgType, (), GetMsgType, GetMsgType, (), 0x4E28C0);
DefineLibMemberFunc(char, CMessageRemoveAreaAirEffects, GetNetworkType1, (), GetNetworkType1, GetNetworkType1, (), 0x4E28E0);
DefineLibMemberFunc(char, CMessageRemoveAreaAirEffects, GetNetworkType2, (), GetNetworkType2, GetNetworkType2, (), 0x4E28F0);
DefineLibMemberFunc(void, CMessageRemoveAreaAirEffects, Marshal, (void* pData, int* dwSize), Marshal, Marshal, (pData, dwSize), 0x5BD036);
DefineLibMemberFunc(BOOL, CMessageRemoveAreaAirEffects, Unmarshal, (void* pData, int* dwSize), Unmarshal, Unmarshal, (pData, dwSize), 0x5BD111);
DefineLibMemberFunc(void, CMessageRemoveAreaAirEffects, DoMessage, (), DoMessage, DoMessage, (), 0x5BD193);

//CMessageRemoveItem
CMessageRemoveItem::CMessageRemoveItem() {
	SetVT(this, 0xAA6E14);
	wSlot = 0;
}
DefineLibNoRetFunc(void, CMessageRemoveItem, ~CMessageRemoveItem, (), Deconstruct, Deconstruct, (), 0x4B70A0);
DefineLibMemberFunc(short, CMessageRemoveItem, GetMsgType, (), GetMsgType, GetMsgType, (), 0x4B7030);
DefineLibMemberFunc(char, CMessageRemoveItem, GetNetworkType1, (), GetNetworkType1, GetNetworkType1, (), 0x4B7050);
DefineLibMemberFunc(char, CMessageRemoveItem, GetNetworkType2, (), GetNetworkType2, GetNetworkType2, (), 0x4B7060);
DefineLibMemberFunc(void, CMessageRemoveItem, Marshal, (void* pData, int* dwSize), Marshal, Marshal, (pData, dwSize), 0x5CC536);
DefineLibMemberFunc(BOOL, CMessageRemoveItem, Unmarshal, (void* pData, int* dwSize), Unmarshal, Unmarshal, (pData, dwSize), 0x5CC6F4);
DefineLibMemberFunc(void, CMessageRemoveItem, DoMessage, (), DoMessage, DoMessage, (), 0x5CC7CE);

//CMessageSetAnimationSequence
CMessageSetAnimationSequence::CMessageSetAnimationSequence() {
	SetVT(this, 0xAA6D6C);
	nSeq = 0;
	ud = 0;
}
DefineLibNoRetFunc(void, CMessageSetAnimationSequence, ~CMessageSetAnimationSequence, (), Deconstruct, Deconstruct, (), 0x4B7250);
DefineLibMemberFunc(short, CMessageSetAnimationSequence, GetMsgType, (), GetMsgType, GetMsgType, (), 0x4B71E0);
DefineLibMemberFunc(char, CMessageSetAnimationSequence, GetNetworkType1, (), GetNetworkType1, GetNetworkType1, (), 0x4B7200);
DefineLibMemberFunc(char, CMessageSetAnimationSequence, GetNetworkType2, (), GetNetworkType2, GetNetworkType2, (), 0x4B7210);
DefineLibMemberFunc(void, CMessageSetAnimationSequence, Marshal, (void* pData, int* dwSize), Marshal, Marshal, (pData, dwSize), 0x5D2E62);
DefineLibMemberFunc(BOOL, CMessageSetAnimationSequence, Unmarshal, (void* pData, int* dwSize), Unmarshal, Unmarshal, (pData, dwSize), 0x5D3011);
DefineLibMemberFunc(void, CMessageSetAnimationSequence, DoMessage, (), DoMessage, DoMessage, (), 0x5D30E9);

//CMessageSetTrigger
CMessageSetTrigger::CMessageSetTrigger() { SetVT(this, 0xAA5C84); }

//CMessageSetTriggerRemovalTimer
CMessageSetTriggerRemovalTimer::CMessageSetTriggerRemovalTimer() {
	SetVT(this, 0xAA7458);
	wTicks = 0;
}

//CMessageSpriteUpdate
CMessageSpriteUpdate::CMessageSpriteUpdate() { SetVT(this, 0xAAB914); }
DefineLibNoRetFunc(CMessageSpriteUpdate*, CMessageSpriteUpdate, CMessageSpriteUpdate, (CCreatureObject* pCre, ENUM eSource, ENUM eTarget), Construct, Construct, (pCre, eSource, eTarget), 0x5D8B73);

//CRemoteMessageHandler
DefineLibMemberFunc(bool, CRemoteMessageHandler, RequestHostFile, (IECString& sResName, int nCResType, BOOL bSendMsgToHost, BOOL bWaitUntilResponse, bool bUseTempPath), RequestHostFile, RequestHostFile, (sResName, nCResType, bSendMsgToHost, bWaitUntilResponse, bUseTempPath), 0x43D0B4);
