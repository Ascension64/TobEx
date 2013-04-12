#include "NetworkCore.h"

DefineTrampMemberFunc(void, CNetwork, PrintNetworkError, (HRESULT hResult, LPCTSTR szMsg), PrintNetworkError, PrintNetworkError, 0x9C9502);

void DETOUR_CNetwork::DETOUR_PrintNetworkError(HRESULT hResult, LPCTSTR szMsg) {
	LPCTSTR lpsz = "Network error: %s returned 0x%.8X\r\n";
	L.timestamp();
	L.appendf(lpsz, szMsg, hResult);
	console.writef(lpsz, szMsg);
	return;
}
