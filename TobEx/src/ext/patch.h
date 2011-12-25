#ifndef PATCH_H
#define PATCH_H

#include "stdafx.h"

#include <vector>

#include "infgame.h"

extern CRuleTable** ClassAbilityTable;

typedef CRuleTable* ClAbTable[1281]; //for KitExtend

class Data {
public:
	Data();
	Data(const Data& d);
	Data(DWORD address, SIZE_T size, char bytes[]);
	~Data();

	DWORD GetAddress();
	SIZE_T GetSize();
	char* GetBytes();

protected:
	DWORD dwAddress;
	SIZE_T nSize;
	char* szBytes;
};

class Patch {
public:
	std::vector<Data> GetData();
	Patch(std::vector<Data> vData);
protected:
	std::vector<Data> vData;
};

void ApplyPatch(Data& d);
void InitPatches();

#endif //PATCH_H