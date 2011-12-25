#ifndef ENGINEINVENTORY_H
#define ENGINEINVENTORY_H

#include "enginv.h"

extern void (CInventory::*Tramp_CInventory_Init)();

class DETOUR_CInventory : public CInventory {
public:
	void DETOUR_Init();
};

#endif //ENGINEINVENTORY_H