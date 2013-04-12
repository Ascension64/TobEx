#include "network.h"

DefineLibMemberFunc(void, CNetwork, CloseSession, (bool bCloseImmediately), CloseSession, CloseSession, (bCloseImmediately), 0x9C4EFE);
DefineLibMemberFunc(void, CNetwork, PrintNetworkError, (HRESULT hResult, LPCTSTR szMsg), PrintNetworkError, PrintNetworkError, (hResult, szMsg), 0x9C9502);
