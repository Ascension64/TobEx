#include "objcore.h"

#include "stdafx.h"

//CGameObject
Enum (CGameObject::*CGameObject_GetEnum)() =
	SetFP(static_cast<Enum (CGameObject::*)()>	(&CGameObject::GetEnum),	0x494D00);

Enum CGameObject::GetEnum()	{ return (this->*CGameObject_GetEnum)(); }

//CGameSprite
BOOL (CGameSprite::*CGameSprite_EvaluateTrigger)(Trigger&) =
	SetFP(static_cast<BOOL (CGameSprite::*)(Trigger&)>	(&CGameSprite::EvaluateTrigger),	0x47F4F2);
ACTIONRESULT (CGameSprite::*CGameSprite_ExecuteAction)() =
	SetFP(static_cast<ACTIONRESULT (CGameSprite::*)()>	(&CGameSprite::ExecuteAction),		0x47891B);
void (CGameSprite::*CGameSprite_SetCurrentAction)(Action&) =
	SetFP(static_cast<void (CGameSprite::*)(Action&)>	(&CGameSprite::SetCurrentAction),	0x48F85F);
Action& (CGameSprite::*CGameSprite_GetTopAction)(Action*) =
	SetFP(static_cast<Action& (CGameSprite::*)(Action*)>		(&CGameSprite::GetTopAction),		0x48CC65);

BOOL CGameSprite::EvaluateTrigger(Trigger& t)		{ return (this->*CGameSprite_EvaluateTrigger)(t); }
ACTIONRESULT CGameSprite::ExecuteAction()			{ return (this->*CGameSprite_ExecuteAction)(); }
void CGameSprite::SetCurrentAction(Action& a)		{ return (this->*CGameSprite_SetCurrentAction)(a); }
Action& CGameSprite::GetTopAction(Action* pAction)	{ return (this->*CGameSprite_GetTopAction)(pAction); }

//CGameObjectArrayHandler
char (CGameObjectArrayHandler::*CGameObjectArrayHandler_GetGameObjectShare)(Enum, char, void*, int) =
	SetFP(static_cast<char (CGameObjectArrayHandler::*)(Enum, char, void*, int)>	(&CGameObjectArrayHandler::GetGameObjectShare),		0x67626B);
char (CGameObjectArrayHandler::*CGameObjectArrayHandler_GetGameObject)(Enum, char, void*, int) =
	SetFP(static_cast<char (CGameObjectArrayHandler::*)(Enum, char, void*, int)>	(&CGameObjectArrayHandler::GetGameObject),			0x6764E5);
char (CGameObjectArrayHandler::*CGameObjectArrayHandler_GetGameObjectDeny)(Enum, char, void*, int) =
	SetFP(static_cast<char (CGameObjectArrayHandler::*)(Enum, char, void*, int)>	(&CGameObjectArrayHandler::GetGameObjectDeny),		0x676570);
char (CGameObjectArrayHandler::*CGameObjectArrayHandler_FreeGameObjectShare)(Enum, char, int) =
	SetFP(static_cast<char (CGameObjectArrayHandler::*)(Enum, char, int)>			(&CGameObjectArrayHandler::FreeGameObjectShare),	0x676808);
char (CGameObjectArrayHandler::*CGameObjectArrayHandler_FreeGameObjectDeny)(Enum, char, int) =
	SetFP(static_cast<char (CGameObjectArrayHandler::*)(Enum, char, int)>			(&CGameObjectArrayHandler::FreeGameObjectDeny),		0x676A16);

char CGameObjectArrayHandler::GetGameObjectShare(Enum e, char threadNum, void* pptr, int dwTimeout) {
	return (this->*CGameObjectArrayHandler_GetGameObjectShare)(e, threadNum, pptr, dwTimeout);
}
char CGameObjectArrayHandler::GetGameObject(Enum e, char threadNum, void* pptr, int dwTimeout) {
	return (this->*CGameObjectArrayHandler_GetGameObject)(e, threadNum, pptr, dwTimeout);
}
char CGameObjectArrayHandler::GetGameObjectDeny(Enum e, char threadNum, void* pptr, int dwTimeout) {
	return (this->*CGameObjectArrayHandler_GetGameObjectDeny)(e, threadNum, pptr, dwTimeout);
}
char CGameObjectArrayHandler::FreeGameObjectShare(Enum e, char threadNum, int dwTimeout) {
	return (this->*CGameObjectArrayHandler_FreeGameObjectShare)(e, threadNum, dwTimeout);
}
char CGameObjectArrayHandler::FreeGameObjectDeny(Enum e, char threadNum, int dwTimeout) {
	return (this->*CGameObjectArrayHandler_FreeGameObjectDeny)(e, threadNum, dwTimeout);
}
