#ifndef ENGINEINVENTORY_H
#define ENGINEINVENTORY_H

#include "enginv.h"

extern void (CScreenInventory::*Tramp_CScreenInventory_Init)();

class DETOUR_CScreenInventory : public CScreenInventory {
public:
	void DETOUR_Init();
};

#endif //ENGINEINVENTORY_H