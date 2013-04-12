#ifndef NETWORKCORE_H
#define NETWORKCORE_H

#include "network.h"

DeclareTrampMemberFunc(void, CNetwork, PrintNetworkError, (HRESULT hResult, LPCTSTR szMsg), PrintNetworkError);

class DETOUR_CNetwork : public CNetwork {
public:
	void DETOUR_PrintNetworkError(HRESULT, LPCTSTR);
};

#endif //NETWORKCORE_H