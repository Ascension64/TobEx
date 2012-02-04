#include "StoreCore.h"

void __stdcall CStore_UnmarshalItem_SetUsages(CStore& sto, CItem& itm, StoFileItem& stoitm, unsigned int nUsageIdx) {
	if (0) IECString("CStore_UnmarshalItem_SetUsages");

	if (sto.sto.m_nType == STORETYPE_BAG &&
		itm.GetMaximumStackSize() <= 1 &&
		nUsageIdx < itm.GetNumAbilities()
	) {
		itm.SetNumUsage(nUsageIdx, stoitm.m_wUsage[nUsageIdx]);
	} else {
		itm.SetNumUsage(
			nUsageIdx,
			stoitm.m_wUsage[nUsageIdx] < 1 ? 1 : stoitm.m_wUsage[nUsageIdx]
		);
	}
	return;
}
