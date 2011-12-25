#include "objcore.h"

#include "utils.h"

BYTE (CGameObjectArrayHandler::*CGameObjectArrayHandler_GetGameObjectShare)(Enum, BYTE, void*, DWORD) =
	SetFP(static_cast<BYTE (CGameObjectArrayHandler::*)(Enum, BYTE, void*, DWORD)>						(&CGameObjectArrayHandler::GetGameObjectShare),		0x67626B);
BYTE (CGameObjectArrayHandler::*CGameObjectArrayHandler_GetGameObject)(Enum, BYTE, void*, DWORD) =
	SetFP(static_cast<BYTE (CGameObjectArrayHandler::*)(Enum, BYTE, void*, DWORD)>						(&CGameObjectArrayHandler::GetGameObject),			0x6764E5);
BYTE (CGameObjectArrayHandler::*CGameObjectArrayHandler_GetGameObjectDeny)(Enum, BYTE, void*, DWORD) =
	SetFP(static_cast<BYTE (CGameObjectArrayHandler::*)(Enum, BYTE, void*, DWORD)>						(&CGameObjectArrayHandler::GetGameObjectDeny),		0x676570);
BYTE (CGameObjectArrayHandler::*CGameObjectArrayHandler_FreeGameObjectShare)(Enum, BYTE, DWORD) =
	SetFP(static_cast<BYTE (CGameObjectArrayHandler::*)(Enum, BYTE, DWORD)>										(&CGameObjectArrayHandler::FreeGameObjectShare),	0x676808);
BYTE (CGameObjectArrayHandler::*CGameObjectArrayHandler_FreeGameObjectDeny)(Enum, BYTE, DWORD) =
	SetFP(static_cast<BYTE (CGameObjectArrayHandler::*)(Enum, BYTE, DWORD)>										(&CGameObjectArrayHandler::FreeGameObjectDeny),		0x676A16);

BYTE CGameObjectArrayHandler::GetGameObjectShare(Enum e, BYTE threadNum, void* ptr, DWORD dwTimeout) {
	return (this->*CGameObjectArrayHandler_GetGameObjectShare)(e, threadNum, ptr, dwTimeout);
}
BYTE CGameObjectArrayHandler::GetGameObject(Enum e, BYTE threadNum, void* ptr, DWORD dwTimeout) {
	return (this->*CGameObjectArrayHandler_GetGameObject)(e, threadNum, ptr, dwTimeout);
}
BYTE CGameObjectArrayHandler::GetGameObjectDeny(Enum e, BYTE threadNum, void* ptr, DWORD dwTimeout) {
	return (this->*CGameObjectArrayHandler_GetGameObjectDeny)(e, threadNum, ptr, dwTimeout);
}
BYTE CGameObjectArrayHandler::FreeGameObjectShare(Enum e, BYTE threadNum, DWORD dwTimeout) {
	return (this->*CGameObjectArrayHandler_FreeGameObjectShare)(e, threadNum, dwTimeout);
}
BYTE CGameObjectArrayHandler::FreeGameObjectDeny(Enum e, BYTE threadNum, DWORD dwTimeout) {
	return (this->*CGameObjectArrayHandler_FreeGameObjectDeny)(e, threadNum, dwTimeout);
}