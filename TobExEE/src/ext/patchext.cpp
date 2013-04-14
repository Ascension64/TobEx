//TobExEE
#include "patchext.h"
#include "p_patch.h"

#include <algorithm>
#include "console.h"
#include "log.h"

#include "optionsext.h"

#include "ResourceCore.h"

void InitPatches() {
	std::vector<Patch> vPatchList;
	std::vector<Patch>::iterator vPatchItr;
	std::vector<Data> vDataList;

	if (pGameOptionsEx->GetOption("Debug_LogMissingRes")) {
		//CKeyTable::FindKey(): nop unconditional jump
		char bytes1[] = {0x90, 0x90, 0x90, 0x90, 0x90, 0x90};
		vDataList.push_back( Data(PATCH_DEBUG_LOGMISSINGRES_CKEYTABLE_FINDKEY1, 6, bytes1) );
		vPatchList.push_back( Patch(vDataList) );

		//CKeyTable::FindKey(): replace CString destructor
		void* ptr = (void*)P_CKeyTable_FindKey_PrintMissingResource;
		DWORD address = (DWORD)ptr - 5  - PATCH_DEBUG_LOGMISSINGRES_CKEYTABLE_FINDKEY2;
		char* bytes2 = (char*)&address;
		vDataList.push_back( Data(PATCH_DEBUG_LOGMISSINGRES_CKEYTABLE_FINDKEY2 + 1, 4, bytes2) );

		vPatchList.push_back( Patch(vDataList) );

		vDataList.clear();
	}

	InitUserPatches(&vPatchList, &vDataList);

	for (vPatchItr = vPatchList.begin(); vPatchItr != vPatchList.end(); vPatchItr++) {
		vDataList = vPatchItr->GetData();
		bool bApply = true;
		for (int i = 0; i < vDataList.size(); i++) {
			bApply = CheckPatch(vDataList[i]);
			if (!bApply) {
				LPCTSTR lpsz = "InitPatches(): patch '%s' not applied\r\n";
				console.writef(CONSOLEFORECOLOR_WARNING, lpsz, vPatchItr->GetName());
				L.timestamp();
				L.appendf(lpsz, vPatchItr->GetName());
				break;
			}
		}
		if (bApply) for_each(vDataList.begin(), vDataList.end(), ApplyPatch);
		vDataList.clear();
	}
	
	return;
}
