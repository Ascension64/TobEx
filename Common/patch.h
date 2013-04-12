#ifndef PATCH_H
#define PATCH_H

#include "win32def.h"

#include <vector>

class Data {
public:
	Data();
	Data(const Data& d);
	Data(DWORD address, SIZE_T size, char bytes[]);
	Data(DWORD address, SIZE_T size, char bytes[], char src[]);
	~Data();

	Data& operator=(const Data& d);

	DWORD GetAddress();
	SIZE_T GetSize();
	char* GetBytes();
	char* GetSrc();

protected:
	DWORD dwAddress;
	SIZE_T nSize;
	char* szBytes;
	char* szSrc;
};

class Patch {
public:
	Patch();
	Patch(const Patch& p);
	Patch(std::vector<Data> vData);
	Patch(std::vector<Data> vData, const char* sz);
	~Patch();

	Patch& operator=(const Patch& p);

	char* GetName();
	std::vector<Data> GetData();
protected:
	char* szName;
	std::vector<Data> vData;
};

bool CheckPatch(Data& d);
void ApplyPatch(Data& d);
void InitUserPatches(std::vector<Patch>* pvPatchList, std::vector<Data>* pvDataList);

#endif //PATCH_H