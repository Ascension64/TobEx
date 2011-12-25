#ifndef NETWORKCORE_H
#define NETWORKCORE_H

#include "network.h"

class DETOUR_CNetwork : public CNetwork {
public:
	void DETOUR_PrintNetworkError(HRESULT, LPCTSTR);
};

extern void (CNetwork::*Tramp_CNetwork_PrintNetworkError)(HRESULT, LPCTSTR);

#endif //NETWORKCORE_H