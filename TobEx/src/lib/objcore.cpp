#include "objcore.h"

#include "stdafx.h"

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