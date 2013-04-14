//TobExEE
#ifndef ENGINEINVENTORY_H
#define ENGINEINVENTORY_H

#include "enginv.h"

DeclareTrampMemberFunc(void, CScreenInventory, Init, (), Init);

class DETOUR_CScreenInventory : public CScreenInventory {
public:
	void DETOUR_Init();
};

#endif //ENGINEINVENTORY_H