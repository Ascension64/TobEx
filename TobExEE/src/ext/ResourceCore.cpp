#include "ResourceCore.h"

void __stdcall P_CKeyTable_FindKey_PrintMissingResource() {
	IECString* pThis;
	GetThis(pThis);

	console.write(*pThis);
	L.timestamp();
	L.append(*pThis);

	return;
}