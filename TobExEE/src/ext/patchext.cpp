//TobExEE
#include "patchext.h"

#include <algorithm>
#include "console.h"
#include "log.h"

void InitPatches() {
	std::vector<Patch> vPatchList;
	std::vector<Patch>::iterator vPatchItr;
	std::vector<Data> vDataList;

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
