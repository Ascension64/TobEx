#ifndef PATCH_H
#define PATCH_H

#include "utils.h"

#include <vector>

#include "infgame.h"

extern CRuleTable** ClassAbilityTable;
extern BYTE* JumpTableChargenMageSpellScroll;
extern BYTE* JumpTableRecMageSpellScroll;
extern BYTE* JumpTableKitScroll;
extern BYTE* JumpTableMageBookScroll;
extern BYTE* JumpTablePriestBookScroll;
extern CPtrList cplChargenMageSpellPile, cplRecMageSpellPile;

typedef CRuleTable* ClAbTable[1281]; //for KitExtend

class Data {
public:
	Data();
	Data(DWORD, SIZE_T, char[]);
	Data(const Data&);
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
	Patch(std::vector<Data>);
protected:
	std::vector<Data> vData;
};

void ApplyPatch(Data);
void InitPatches();

#endif //PATCH_H