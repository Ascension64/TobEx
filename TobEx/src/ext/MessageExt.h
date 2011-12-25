#ifndef MESSAGEEXT_H
#define MESSAGEEXT_H

#include "msgcore.h"

class CMessageRemoveAreaAirEffectSpecific : public CMessageRemoveAreaAirEffects { //Size 1Ch
public:
	virtual void Marshal(void* pData, int* dwSize); //v10
	virtual BOOL Unmarshal(void* pData, int* dwSize); //v14
	virtual void DoMessage(void); //v18

	ResRef rResource; //14h
};

struct CMessageRemoveAreaAirEffectSpecificM {
	ResRef rAreaName; //0h
	ResRef rResource; //8h
};

#endif //MESSAGEEXT_H