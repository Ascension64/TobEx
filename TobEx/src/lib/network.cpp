#include "network.h"

void (CNetwork::*CNetwork_CloseSession)(bool) =
	SetFP(static_cast<void (CNetwork::*)(bool)>				(&CNetwork::CloseSession),		0x9C4EFE);
void (CNetwork::*CNetwork_PrintNetworkError)(HRESULT, LPCTSTR) =
	SetFP(static_cast<void (CNetwork::*)(HRESULT, LPCTSTR)>	(&CNetwork::PrintNetworkError),	0x9C9502);

void CNetwork::CloseSession(bool bCloseImmediately) { return (this->*CNetwork_CloseSession)(bCloseImmediately); }
void CNetwork::PrintNetworkError(HRESULT hResult, LPCTSTR szMsg) { return (this->*CNetwork_PrintNetworkError)(hResult, szMsg); }
