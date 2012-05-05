#include "msgcore.h"

#include "stdafx.h"
#include "objcre.h"

CMessage::CMessage() {
	SetVT(this, 0xAA5C10);
	eTarget = ENUM_INVALID_INDEX;
	eSource = ENUM_INVALID_INDEX;
}

void (CPtrListMessage::*CPtrListMessage_ExecuteMessages)() =
	SetFP(static_cast<void (CPtrListMessage::*)()>						(&CPtrListMessage::ExecuteMessages),	0x5B0DB0);
short (CPtrListMessage::*CPtrListMessage_Send)(CMessage&, BOOL) =
	SetFP(static_cast<short (CPtrListMessage::*)(CMessage&, BOOL)>		(&CPtrListMessage::Send),		0x5B91FD);

void CPtrListMessage::ExecuteMessages() { return (this->*CPtrListMessage_ExecuteMessages)(); }
short CPtrListMessage::Send(CMessage& msg, BOOL bForceAddToQueue) {	return (this->*CPtrListMessage_Send)(msg, bForceAddToQueue); }

CMessageAddActionHead::CMessageAddActionHead() { SetVT(this, 0xAA5BF4); }

//CMessageAddActionTailInterrupt
void (CMessageAddActionTailInterrupt::*CMessageAddActionTailInterrupt_Deconstruct)() =
	SetFP(static_cast<void (CMessageAddActionTailInterrupt::*)()>			(&CMessageAddActionTailInterrupt::Deconstruct),		0x495AA0);
short (CMessageAddActionTailInterrupt::*CMessageAddActionTailInterrupt_GetMsgType)() =
	SetFP(static_cast<short (CMessageAddActionTailInterrupt::*)()>			(&CMessageAddActionTailInterrupt::GetMsgType),		0x495A30);
char (CMessageAddActionTailInterrupt::*CMessageAddActionTailInterrupt_GetNetworkType1)() =
	SetFP(static_cast<char (CMessageAddActionTailInterrupt::*)()>			(&CMessageAddActionTailInterrupt::GetNetworkType1),	0x495A50);
char (CMessageAddActionTailInterrupt::*CMessageAddActionTailInterrupt_GetNetworkType2)() =
	SetFP(static_cast<char (CMessageAddActionTailInterrupt::*)()>			(&CMessageAddActionTailInterrupt::GetNetworkType2),	0x495A60);
void (CMessageAddActionTailInterrupt::*CMessageAddActionTailInterrupt_Marshal)(void*, int*) =
	SetFP(static_cast<void (CMessageAddActionTailInterrupt::*)(void*, int*)>(&CMessageAddActionTailInterrupt::Marshal),			0x5C7F97);
BOOL (CMessageAddActionTailInterrupt::*CMessageAddActionTailInterrupt_Unmarshal)(void*, int*) =
	SetFP(static_cast<BOOL (CMessageAddActionTailInterrupt::*)(void*, int*)>(&CMessageAddActionTailInterrupt::Unmarshal),		0x5C898E);
void (CMessageAddActionTailInterrupt::*CMessageAddActionTailInterrupt_DoMessage)() =
	SetFP(static_cast<void (CMessageAddActionTailInterrupt::*)()>			(&CMessageAddActionTailInterrupt::DoMessage),		0x5C8EF2);

CMessageAddActionTailInterrupt::CMessageAddActionTailInterrupt() { SetVT(this, 0xAA6ACC); }

CMessageAddActionTailInterrupt::~CMessageAddActionTailInterrupt()		{ (this->*CMessageAddActionTailInterrupt_Deconstruct)(); }
short CMessageAddActionTailInterrupt::GetMsgType()						{ return (this->*CMessageAddActionTailInterrupt_GetMsgType)(); }
char CMessageAddActionTailInterrupt::GetNetworkType1()					{ return (this->*CMessageAddActionTailInterrupt_GetNetworkType1)(); }
char CMessageAddActionTailInterrupt::GetNetworkType2()					{ return (this->*CMessageAddActionTailInterrupt_GetNetworkType2)(); }
void CMessageAddActionTailInterrupt::Marshal(void* pData, int* dwSize)	{ return (this->*CMessageAddActionTailInterrupt_Marshal)(pData, dwSize); }
BOOL CMessageAddActionTailInterrupt::Unmarshal(void* pData, int* dwSize){ return (this->*CMessageAddActionTailInterrupt_Unmarshal)(pData, dwSize); }
void CMessageAddActionTailInterrupt::DoMessage()						{ return (this->*CMessageAddActionTailInterrupt_DoMessage)(); }

CMessageApplyEffect::CMessageApplyEffect() {
	SetVT(this, 0xAA6A40);
	u10 = 0;
	u11 = 0;
}

//CMessageCastSpell
void (CMessageCastSpell::*CMessageCastSpell_Deconstruct)() =
	SetFP(static_cast<void (CMessageCastSpell::*)()>			(&CMessageCastSpell::Deconstruct),		0x568A70);
short (CMessageCastSpell::*CMessageCastSpell_GetMsgType)() =
	SetFP(static_cast<short (CMessageCastSpell::*)()>			(&CMessageCastSpell::GetMsgType),		0x568A00);
char (CMessageCastSpell::*CMessageCastSpell_GetNetworkType1)() =
	SetFP(static_cast<char (CMessageCastSpell::*)()>			(&CMessageCastSpell::GetNetworkType1),	0x568A20);
char (CMessageCastSpell::*CMessageCastSpell_GetNetworkType2)() =
	SetFP(static_cast<char (CMessageCastSpell::*)()>			(&CMessageCastSpell::GetNetworkType2),	0x568A30);
void (CMessageCastSpell::*CMessageCastSpell_Marshal)(void*, int*) =
	SetFP(static_cast<void (CMessageCastSpell::*)(void*, int*)>	(&CMessageCastSpell::Marshal),			0x5E75FE);
BOOL (CMessageCastSpell::*CMessageCastSpell_Unmarshal)(void*, int*) =
	SetFP(static_cast<BOOL (CMessageCastSpell::*)(void*, int*)>	(&CMessageCastSpell::Unmarshal),		0x5E793C);
void (CMessageCastSpell::*CMessageCastSpell_DoMessage)() =
	SetFP(static_cast<void (CMessageCastSpell::*)()>			(&CMessageCastSpell::DoMessage),		0x5E7B30);

CMessageCastSpell::CMessageCastSpell() {
	SetVT(this, 0xAA9970);
	eSpellTarget = ENUM_INVALID_INDEX;
}

CMessageCastSpell::~CMessageCastSpell()						{ (this->*CMessageCastSpell_Deconstruct)(); }
short CMessageCastSpell::GetMsgType()						{ return (this->*CMessageCastSpell_GetMsgType)(); }
char CMessageCastSpell::GetNetworkType1()					{ return (this->*CMessageCastSpell_GetNetworkType1)(); }
char CMessageCastSpell::GetNetworkType2()					{ return (this->*CMessageCastSpell_GetNetworkType2)(); }
void CMessageCastSpell::Marshal(void* pData, int* dwSize)	{ return (this->*CMessageCastSpell_Marshal)(pData, dwSize); }
BOOL CMessageCastSpell::Unmarshal(void* pData, int* dwSize)	{ return (this->*CMessageCastSpell_Unmarshal)(pData, dwSize); }
void CMessageCastSpell::DoMessage()							{ return (this->*CMessageCastSpell_DoMessage)(); }

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

//CMessageFaceTalker
void (CMessageFaceTalker::*CMessageFaceTalker_Deconstruct)() =
	SetFP(static_cast<void (CMessageFaceTalker::*)()>			(&CMessageFaceTalker::Deconstruct),		0x4E9920);
short (CMessageFaceTalker::*CMessageFaceTalker_GetMsgType)() =
	SetFP(static_cast<short (CMessageFaceTalker::*)()>			(&CMessageFaceTalker::GetMsgType),		0x4E98B0);
char (CMessageFaceTalker::*CMessageFaceTalker_GetNetworkType1)() =
	SetFP(static_cast<char (CMessageFaceTalker::*)()>			(&CMessageFaceTalker::GetNetworkType1),	0x4E98D0);
char (CMessageFaceTalker::*CMessageFaceTalker_GetNetworkType2)() =
	SetFP(static_cast<char (CMessageFaceTalker::*)()>			(&CMessageFaceTalker::GetNetworkType2),	0x4E98E0);
void (CMessageFaceTalker::*CMessageFaceTalker_Marshal)(void*, int*) =
	SetFP(static_cast<void (CMessageFaceTalker::*)(void*, int*)>(&CMessageFaceTalker::Marshal),			0x5CEF30);
BOOL (CMessageFaceTalker::*CMessageFaceTalker_Unmarshal)(void*, int*) =
	SetFP(static_cast<BOOL (CMessageFaceTalker::*)(void*, int*)>(&CMessageFaceTalker::Unmarshal),		0x5CF1E3);
void (CMessageFaceTalker::*CMessageFaceTalker_DoMessage)() =
	SetFP(static_cast<void (CMessageFaceTalker::*)()>			(&CMessageFaceTalker::DoMessage),		0x5CF365);

CMessageFaceTalker::CMessageFaceTalker() {
	SetVT(this, 0xAA743C);
	nTicks = 0;
	eTarget = ENUM_INVALID_INDEX;
}

CMessageFaceTalker::~CMessageFaceTalker()					{ (this->*CMessageFaceTalker_Deconstruct)(); }
short CMessageFaceTalker::GetMsgType()						{ return (this->*CMessageFaceTalker_GetMsgType)(); }
char CMessageFaceTalker::GetNetworkType1()					{ return (this->*CMessageFaceTalker_GetNetworkType1)(); }
char CMessageFaceTalker::GetNetworkType2()					{ return (this->*CMessageFaceTalker_GetNetworkType2)(); }
void CMessageFaceTalker::Marshal(void* pData, int* dwSize)	{ return (this->*CMessageFaceTalker_Marshal)(pData, dwSize); }
BOOL CMessageFaceTalker::Unmarshal(void* pData, int* dwSize){ return (this->*CMessageFaceTalker_Unmarshal)(pData, dwSize); }
void CMessageFaceTalker::DoMessage()						{ return (this->*CMessageFaceTalker_DoMessage)(); }

//CMessageHostReleaseServerStore
void (CMessageHostReleaseServerStore::*CMessageHostReleaseServerStore_Deconstruct)() =
	SetFP(static_cast<void (CMessageHostReleaseServerStore::*)()>			(&CMessageHostReleaseServerStore::Deconstruct),		0x4E2BA0);
short (CMessageHostReleaseServerStore::*CMessageHostReleaseServerStore_GetMsgType)() =
	SetFP(static_cast<short (CMessageHostReleaseServerStore::*)()>			(&CMessageHostReleaseServerStore::GetMsgType),		0x4E2B30);
char (CMessageHostReleaseServerStore::*CMessageHostReleaseServerStore_GetNetworkType1)() =
	SetFP(static_cast<char (CMessageHostReleaseServerStore::*)()>			(&CMessageHostReleaseServerStore::GetNetworkType1),	0x4E2B50);
char (CMessageHostReleaseServerStore::*CMessageHostReleaseServerStore_GetNetworkType2)() =
	SetFP(static_cast<char (CMessageHostReleaseServerStore::*)()>			(&CMessageHostReleaseServerStore::GetNetworkType2),	0x4E2B60);
void (CMessageHostReleaseServerStore::*CMessageHostReleaseServerStore_Marshal)(void*, int*) =
	SetFP(static_cast<void (CMessageHostReleaseServerStore::*)(void*, int*)>(&CMessageHostReleaseServerStore::Marshal),			0x5DF981);
BOOL (CMessageHostReleaseServerStore::*CMessageHostReleaseServerStore_Unmarshal)(void*, int*) =
	SetFP(static_cast<BOOL (CMessageHostReleaseServerStore::*)(void*, int*)>(&CMessageHostReleaseServerStore::Unmarshal),		0x5DFA5C);
void (CMessageHostReleaseServerStore::*CMessageHostReleaseServerStore_DoMessage)() =
	SetFP(static_cast<void (CMessageHostReleaseServerStore::*)()>			(&CMessageHostReleaseServerStore::DoMessage),		0x5DFAD7);

CMessageHostReleaseServerStore::CMessageHostReleaseServerStore() {
	SetVT(this, 0xAA7298);
}

CMessageHostReleaseServerStore::~CMessageHostReleaseServerStore()		{ (this->*CMessageHostReleaseServerStore_Deconstruct)(); }
short CMessageHostReleaseServerStore::GetMsgType()						{ return (this->*CMessageHostReleaseServerStore_GetMsgType)(); }
char CMessageHostReleaseServerStore::GetNetworkType1()					{ return (this->*CMessageHostReleaseServerStore_GetNetworkType1)(); }
char CMessageHostReleaseServerStore::GetNetworkType2()					{ return (this->*CMessageHostReleaseServerStore_GetNetworkType2)(); }
void CMessageHostReleaseServerStore::Marshal(void* pData, int* dwSize)	{ return (this->*CMessageHostReleaseServerStore_Marshal)(pData, dwSize); }
BOOL CMessageHostReleaseServerStore::Unmarshal(void* pData, int* dwSize){ return (this->*CMessageHostReleaseServerStore_Unmarshal)(pData, dwSize); }
void CMessageHostReleaseServerStore::DoMessage()						{ return (this->*CMessageHostReleaseServerStore_DoMessage)(); }

//CMessageModifyPartyGold
void (CMessageModifyPartyGold::*CMessageModifyPartyGold_Deconstruct)() =
	SetFP(static_cast<void (CMessageModifyPartyGold::*)()>			(&CMessageModifyPartyGold::Deconstruct),		0x4B6F70);
short (CMessageModifyPartyGold::*CMessageModifyPartyGold_GetMsgType)() =
	SetFP(static_cast<short (CMessageModifyPartyGold::*)()>			(&CMessageModifyPartyGold::GetMsgType),			0x5CB613);
char (CMessageModifyPartyGold::*CMessageModifyPartyGold_GetNetworkType1)() =
	SetFP(static_cast<char (CMessageModifyPartyGold::*)()>			(&CMessageModifyPartyGold::GetNetworkType1),	0x4B6F20);
char (CMessageModifyPartyGold::*CMessageModifyPartyGold_GetNetworkType2)() =
	SetFP(static_cast<char (CMessageModifyPartyGold::*)()>			(&CMessageModifyPartyGold::GetNetworkType2),	0x4B6F30);
void (CMessageModifyPartyGold::*CMessageModifyPartyGold_Marshal)(void*, int*) =
	SetFP(static_cast<void (CMessageModifyPartyGold::*)(void*, int*)>(&CMessageModifyPartyGold::Marshal),			0x5CB646);
BOOL (CMessageModifyPartyGold::*CMessageModifyPartyGold_Unmarshal)(void*, int*) =
	SetFP(static_cast<BOOL (CMessageModifyPartyGold::*)(void*, int*)>(&CMessageModifyPartyGold::Unmarshal),			0x5CB749);
void (CMessageModifyPartyGold::*CMessageModifyPartyGold_DoMessage)() =
	SetFP(static_cast<void (CMessageModifyPartyGold::*)()>			(&CMessageModifyPartyGold::DoMessage),			0x5CB7EA);

CMessageModifyPartyGold::CMessageModifyPartyGold() {
	SetVT(this, 0xAA6E4C);
	nGold = 0;
	cMode = 0;
	bPrintMessage = false;
}

CMessageModifyPartyGold::~CMessageModifyPartyGold()				{ (this->*CMessageModifyPartyGold_Deconstruct)(); }
short CMessageModifyPartyGold::GetMsgType()						{ return (this->*CMessageModifyPartyGold_GetMsgType)(); }
char CMessageModifyPartyGold::GetNetworkType1()					{ return (this->*CMessageModifyPartyGold_GetNetworkType1)(); }
char CMessageModifyPartyGold::GetNetworkType2()					{ return (this->*CMessageModifyPartyGold_GetNetworkType2)(); }
void CMessageModifyPartyGold::Marshal(void* pData, int* dwSize)	{ return (this->*CMessageModifyPartyGold_Marshal)(pData, dwSize); }
BOOL CMessageModifyPartyGold::Unmarshal(void* pData, int* dwSize){ return (this->*CMessageModifyPartyGold_Unmarshal)(pData, dwSize); }
void CMessageModifyPartyGold::DoMessage()						{ return (this->*CMessageModifyPartyGold_DoMessage)(); }

//CMessageModifyVariable
void (CMessageModifyVariable::*CMessageModifyVariable_Deconstruct)() =
	SetFP(static_cast<void (CMessageModifyVariable::*)()>			(&CMessageModifyVariable::Deconstruct),		0x4B73A0);
short (CMessageModifyVariable::*CMessageModifyVariable_GetMsgType)() =
	SetFP(static_cast<short (CMessageModifyVariable::*)()>			(&CMessageModifyVariable::GetMsgType),		0x4B7330);
char (CMessageModifyVariable::*CMessageModifyVariable_GetNetworkType1)() =
	SetFP(static_cast<char (CMessageModifyVariable::*)()>			(&CMessageModifyVariable::GetNetworkType1),	0x4B7350);
char (CMessageModifyVariable::*CMessageModifyVariable_GetNetworkType2)() =
	SetFP(static_cast<char (CMessageModifyVariable::*)()>			(&CMessageModifyVariable::GetNetworkType2),	0x4B7360);
void (CMessageModifyVariable::*CMessageModifyVariable_Marshal)(void*, int*) =
	SetFP(static_cast<void (CMessageModifyVariable::*)(void*, int*)>(&CMessageModifyVariable::Marshal),			0x5D6108);
BOOL (CMessageModifyVariable::*CMessageModifyVariable_Unmarshal)(void*, int*) =
	SetFP(static_cast<BOOL (CMessageModifyVariable::*)(void*, int*)>(&CMessageModifyVariable::Unmarshal),		0x5D63F3);
void (CMessageModifyVariable::*CMessageModifyVariable_DoMessage)() =
	SetFP(static_cast<void (CMessageModifyVariable::*)()>			(&CMessageModifyVariable::DoMessage),		0x5D65D0);

CMessageModifyVariable::CMessageModifyVariable() {
	SetVT(this, 0xAA6CE0);
	nValue = 0;
	nBehaviour = 0;
	u19 = 0;
}

CMessageModifyVariable::~CMessageModifyVariable()				{ (this->*CMessageModifyVariable_Deconstruct)(); }
short CMessageModifyVariable::GetMsgType()						{ return (this->*CMessageModifyVariable_GetMsgType)(); }
char CMessageModifyVariable::GetNetworkType1()					{ return (this->*CMessageModifyVariable_GetNetworkType1)(); }
char CMessageModifyVariable::GetNetworkType2()					{ return (this->*CMessageModifyVariable_GetNetworkType2)(); }
void CMessageModifyVariable::Marshal(void* pData, int* dwSize)	{ return (this->*CMessageModifyVariable_Marshal)(pData, dwSize); }
BOOL CMessageModifyVariable::Unmarshal(void* pData, int* dwSize){ return (this->*CMessageModifyVariable_Unmarshal)(pData, dwSize); }
void CMessageModifyVariable::DoMessage()						{ return (this->*CMessageModifyVariable_DoMessage)(); }

//CMessageInterruptDialogue
void (CMessageInterruptDialogue::*CMessageInterruptDialogue_Deconstruct)() =
	SetFP(static_cast<void (CMessageInterruptDialogue::*)()>			(&CMessageInterruptDialogue::Deconstruct),		0x5689E0);
short (CMessageInterruptDialogue::*CMessageInterruptDialogue_GetMsgType)() =
	SetFP(static_cast<short (CMessageInterruptDialogue::*)()>			(&CMessageInterruptDialogue::GetMsgType),		0x568970);
char (CMessageInterruptDialogue::*CMessageInterruptDialogue_GetNetworkType1)() =
	SetFP(static_cast<char (CMessageInterruptDialogue::*)()>			(&CMessageInterruptDialogue::GetNetworkType1),	0x568990);
char (CMessageInterruptDialogue::*CMessageInterruptDialogue_GetNetworkType2)() =
	SetFP(static_cast<char (CMessageInterruptDialogue::*)()>			(&CMessageInterruptDialogue::GetNetworkType2),	0x5689A0);
void (CMessageInterruptDialogue::*CMessageInterruptDialogue_Marshal)(void*, int*) =
	SetFP(static_cast<void (CMessageInterruptDialogue::*)(void*, int*)>(&CMessageInterruptDialogue::Marshal),			0x5E4209);
BOOL (CMessageInterruptDialogue::*CMessageInterruptDialogue_Unmarshal)(void*, int*) =
	SetFP(static_cast<BOOL (CMessageInterruptDialogue::*)(void*, int*)>(&CMessageInterruptDialogue::Unmarshal),			0x5E43C5);
void (CMessageInterruptDialogue::*CMessageInterruptDialogue_DoMessage)() =
	SetFP(static_cast<void (CMessageInterruptDialogue::*)()>			(&CMessageInterruptDialogue::DoMessage),		0x5E449D);

CMessageInterruptDialogue::CMessageInterruptDialogue() {
	SetVT(this, 0xAA9758);
	b = 0;
	ud = 0;
}

CMessageInterruptDialogue::~CMessageInterruptDialogue()				{ (this->*CMessageInterruptDialogue_Deconstruct)(); }
short CMessageInterruptDialogue::GetMsgType()						{ return (this->*CMessageInterruptDialogue_GetMsgType)(); }
char CMessageInterruptDialogue::GetNetworkType1()					{ return (this->*CMessageInterruptDialogue_GetNetworkType1)(); }
char CMessageInterruptDialogue::GetNetworkType2()					{ return (this->*CMessageInterruptDialogue_GetNetworkType2)(); }
void CMessageInterruptDialogue::Marshal(void* pData, int* dwSize)	{ return (this->*CMessageInterruptDialogue_Marshal)(pData, dwSize); }
BOOL CMessageInterruptDialogue::Unmarshal(void* pData, int* dwSize){ return (this->*CMessageInterruptDialogue_Unmarshal)(pData, dwSize); }
void CMessageInterruptDialogue::DoMessage()						{ return (this->*CMessageInterruptDialogue_DoMessage)(); }

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

//CMessageQueueActions
void (CMessageQueueActions::*CMessageQueueActions_Deconstruct)() =
	SetFP(static_cast<void (CMessageQueueActions::*)()>				(&CMessageQueueActions::Deconstruct),		0x4B6ED0);
short (CMessageQueueActions::*CMessageQueueActions_GetMsgType)() =
	SetFP(static_cast<short (CMessageQueueActions::*)()>			(&CMessageQueueActions::GetMsgType),		0x4B6E60);
char (CMessageQueueActions::*CMessageQueueActions_GetNetworkType1)() =
	SetFP(static_cast<char (CMessageQueueActions::*)()>				(&CMessageQueueActions::GetNetworkType1),	0x4B6E80);
char (CMessageQueueActions::*CMessageQueueActions_GetNetworkType2)() =
	SetFP(static_cast<char (CMessageQueueActions::*)()>				(&CMessageQueueActions::GetNetworkType2),	0x4B6E90);
void (CMessageQueueActions::*CMessageQueueActions_Marshal)(void*, int*) =
	SetFP(static_cast<void (CMessageQueueActions::*)(void*, int*)>	(&CMessageQueueActions::Marshal),			0x5C8FF6);
BOOL (CMessageQueueActions::*CMessageQueueActions_Unmarshal)(void*, int*) =
	SetFP(static_cast<BOOL (CMessageQueueActions::*)(void*, int*)>	(&CMessageQueueActions::Unmarshal),			0x5C9EF2);
void (CMessageQueueActions::*CMessageQueueActions_DoMessage)() =
	SetFP(static_cast<void (CMessageQueueActions::*)()>				(&CMessageQueueActions::DoMessage),			0x5CA80B);

CMessageQueueActions::CMessageQueueActions() {
	SetVT(this, 0xAA6DC0);
	bSkipIfAlreadyQueued = FALSE;
	bClearActionQueue = FALSE;
}

CMessageQueueActions::~CMessageQueueActions()					{ (this->*CMessageQueueActions_Deconstruct)(); }
short CMessageQueueActions::GetMsgType()						{ return (this->*CMessageQueueActions_GetMsgType)(); }
char CMessageQueueActions::GetNetworkType1()					{ return (this->*CMessageQueueActions_GetNetworkType1)(); }
char CMessageQueueActions::GetNetworkType2()					{ return (this->*CMessageQueueActions_GetNetworkType2)(); }
void CMessageQueueActions::Marshal(void* pData, int* dwSize)	{ return (this->*CMessageQueueActions_Marshal)(pData, dwSize); }
BOOL CMessageQueueActions::Unmarshal(void* pData, int* dwSize)	{ return (this->*CMessageQueueActions_Unmarshal)(pData, dwSize); }
void CMessageQueueActions::DoMessage()							{ return (this->*CMessageQueueActions_DoMessage)(); }

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

//CMessageRemoveItem
void (CMessageRemoveItem::*CMessageRemoveItem_Deconstruct)() =
	SetFP(static_cast<void (CMessageRemoveItem::*)()>				(&CMessageRemoveItem::Deconstruct),		0x4B70A0);
short (CMessageRemoveItem::*CMessageRemoveItem_GetMsgType)() =
	SetFP(static_cast<short (CMessageRemoveItem::*)()>				(&CMessageRemoveItem::GetMsgType),		0x4B7030);
char (CMessageRemoveItem::*CMessageRemoveItem_GetNetworkType1)() =
	SetFP(static_cast<char (CMessageRemoveItem::*)()>				(&CMessageRemoveItem::GetNetworkType1),	0x4B7050);
char (CMessageRemoveItem::*CMessageRemoveItem_GetNetworkType2)() =
	SetFP(static_cast<char (CMessageRemoveItem::*)()>				(&CMessageRemoveItem::GetNetworkType2),	0x4B7060);
void (CMessageRemoveItem::*CMessageRemoveItem_Marshal)(void*, int*) =
	SetFP(static_cast<void (CMessageRemoveItem::*)(void*, int*)>	(&CMessageRemoveItem::Marshal),			0x5CC536);
BOOL (CMessageRemoveItem::*CMessageRemoveItem_Unmarshal)(void*, int*) =
	SetFP(static_cast<BOOL (CMessageRemoveItem::*)(void*, int*)>	(&CMessageRemoveItem::Unmarshal),		0x5CC6F4);
void (CMessageRemoveItem::*CMessageRemoveItem_DoMessage)() =
	SetFP(static_cast<void (CMessageRemoveItem::*)()>				(&CMessageRemoveItem::DoMessage),		0x5CC7CE);

CMessageRemoveItem::CMessageRemoveItem() {
	SetVT(this, 0xAA6E14);
	wSlot = 0;
}
CMessageRemoveItem::~CMessageRemoveItem()					{ (this->*CMessageRemoveItem_Deconstruct)(); }
short CMessageRemoveItem::GetMsgType()						{ return (this->*CMessageRemoveItem_GetMsgType)(); }
char CMessageRemoveItem::GetNetworkType1()					{ return (this->*CMessageRemoveItem_GetNetworkType1)(); }
char CMessageRemoveItem::GetNetworkType2()					{ return (this->*CMessageRemoveItem_GetNetworkType2)(); }
void CMessageRemoveItem::Marshal(void* pData, int* dwSize)	{ return (this->*CMessageRemoveItem_Marshal)(pData, dwSize); }
BOOL CMessageRemoveItem::Unmarshal(void* pData, int* dwSize){ return (this->*CMessageRemoveItem_Unmarshal)(pData, dwSize); }
void CMessageRemoveItem::DoMessage()						{ return (this->*CMessageRemoveItem_DoMessage)(); }

//CMessageSetAnimationSequence
void (CMessageSetAnimationSequence::*CMessageSetAnimationSequence_Deconstruct)() =
	SetFP(static_cast<void (CMessageSetAnimationSequence::*)()>				(&CMessageSetAnimationSequence::Deconstruct),		0x4B7250);
short (CMessageSetAnimationSequence::*CMessageSetAnimationSequence_GetMsgType)() =
	SetFP(static_cast<short (CMessageSetAnimationSequence::*)()>			(&CMessageSetAnimationSequence::GetMsgType),		0x4B71E0);
char (CMessageSetAnimationSequence::*CMessageSetAnimationSequence_GetNetworkType1)() =
	SetFP(static_cast<char (CMessageSetAnimationSequence::*)()>				(&CMessageSetAnimationSequence::GetNetworkType1),	0x4B7200);
char (CMessageSetAnimationSequence::*CMessageSetAnimationSequence_GetNetworkType2)() =
	SetFP(static_cast<char (CMessageSetAnimationSequence::*)()>				(&CMessageSetAnimationSequence::GetNetworkType2),	0x4B7210);
void (CMessageSetAnimationSequence::*CMessageSetAnimationSequence_Marshal)(void*, int*) =
	SetFP(static_cast<void (CMessageSetAnimationSequence::*)(void*, int*)>	(&CMessageSetAnimationSequence::Marshal),			0x5D2E62);
BOOL (CMessageSetAnimationSequence::*CMessageSetAnimationSequence_Unmarshal)(void*, int*) =
	SetFP(static_cast<BOOL (CMessageSetAnimationSequence::*)(void*, int*)>	(&CMessageSetAnimationSequence::Unmarshal),			0x5D3011);
void (CMessageSetAnimationSequence::*CMessageSetAnimationSequence_DoMessage)() =
	SetFP(static_cast<void (CMessageSetAnimationSequence::*)()>				(&CMessageSetAnimationSequence::DoMessage),			0x5D30E9);

CMessageSetAnimationSequence::CMessageSetAnimationSequence() {
	SetVT(this, 0xAA6D6C);
	nSeq = 0;
	ud = 0;
}

CMessageSetAnimationSequence::~CMessageSetAnimationSequence()			{ (this->*CMessageSetAnimationSequence_Deconstruct)(); }
short CMessageSetAnimationSequence::GetMsgType()						{ return (this->*CMessageSetAnimationSequence_GetMsgType)(); }
char CMessageSetAnimationSequence::GetNetworkType1()					{ return (this->*CMessageSetAnimationSequence_GetNetworkType1)(); }
char CMessageSetAnimationSequence::GetNetworkType2()					{ return (this->*CMessageSetAnimationSequence_GetNetworkType2)(); }
void CMessageSetAnimationSequence::Marshal(void* pData, int* dwSize)	{ return (this->*CMessageSetAnimationSequence_Marshal)(pData, dwSize); }
BOOL CMessageSetAnimationSequence::Unmarshal(void* pData, int* dwSize)	{ return (this->*CMessageSetAnimationSequence_Unmarshal)(pData, dwSize); }
void CMessageSetAnimationSequence::DoMessage()							{ return (this->*CMessageSetAnimationSequence_DoMessage)(); }

CMessageSetTrigger::CMessageSetTrigger() { SetVT(this, 0xAA5C84); }

CMessageSetTriggerRemovalTimer::CMessageSetTriggerRemovalTimer() {
	SetVT(this, 0xAA7458);
	wTicks = 0;
}

CMessageSpriteUpdate* (CMessageSpriteUpdate::*CMessageSpriteUpdate_Construct)(CCreatureObject*, Enum, Enum) =
	SetFP(static_cast<CMessageSpriteUpdate* (CMessageSpriteUpdate::*)(CCreatureObject*, Enum, Enum)>	(&CMessageSpriteUpdate::Construct),	0x5D8B73);

CMessageSpriteUpdate::CMessageSpriteUpdate() { SetVT(this, 0xAAB914); }
CMessageSpriteUpdate::CMessageSpriteUpdate(CCreatureObject* pCre, Enum eSource, Enum eTarget) {
	(this->*CMessageSpriteUpdate_Construct)(pCre, eSource, eTarget);
}

//CMessageHandler
bool (CMessageHandler::*CMessageHandler_RequestHostFile)(IECString&, int, BOOL, BOOL, bool) =
	SetFP(static_cast<bool (CMessageHandler::*)(IECString&, int, BOOL, BOOL, bool)>		(&CMessageHandler::RequestHostFile),	0x43D0B4);

bool CMessageHandler::RequestHostFile(IECString& sResName, int nCResType, BOOL bSendMsgToHost, BOOL bWaitUntilResponse, bool bUseTempPath)
	{ return (this->*CMessageHandler_RequestHostFile)(sResName, nCResType, bSendMsgToHost, bWaitUntilResponse, bUseTempPath); }

