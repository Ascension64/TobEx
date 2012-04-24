#include "StoreCore.h"

void __stdcall CStore_AddItem_SetUsages(CStore& sto, CItem& itm, StoFileItem& stoitm, unsigned int nUsageIdx) {
	if (0) IECString("CStore_AddItem_SetUsages");

	if (itm.GetNumCharges(nUsageIdx) > 0) {
		if (
			(
				sto.sto.m_nType == STORETYPE_BAG &&
				!(sto.sto.m_dwFlags & STOREFLAG_RECHARGE) //non-rechargable bag
			) || (
				sto.sto.m_nType != STORETYPE_BAG &&
				sto.sto.m_dwFlags & STOREFLAG_RECHARGE //non-rechargable store
			)
		) {
			stoitm.m_wUsage[nUsageIdx] = itm.GetNumUsage(nUsageIdx);
		} else {
			stoitm.m_wUsage[nUsageIdx] = itm.GetNumCharges(nUsageIdx);
		}
	}

	return;
}

void __stdcall CStore_GetBuyPrice_GetChargePercent(CStore& sto, short& nTotalUsages, short& nTotalCharges, CItem& itm, unsigned int nUsageIdx) {
	short nCharges = itm.GetNumCharges(nUsageIdx);
	ItmFileAbility* pAbility = NULL;
	if (itm.Demand()) {
		pAbility = &itm.GetAbility(nUsageIdx);
		itm.Release();
	}
	assert(pAbility != NULL);

	if (nCharges > 0) {
		nTotalCharges += nCharges;
		nTotalUsages += (pAbility->chargeType == 3 || pAbility->flags & ITEMABILITYFLAG_RECHARGES) ? nCharges : itm.GetNumUsage(nUsageIdx);
	}
	return;
}

void __stdcall CStore_GetSellPrice_GetChargePercent(CStore& sto, short& nTotalUsages, short& nTotalCharges, CItem& itm, unsigned int nUsageIdx) {
	short nCharges = itm.GetNumCharges(nUsageIdx);
	ItmFileAbility* pAbility = NULL;
	if (itm.Demand()) {
		pAbility = &itm.GetAbility(nUsageIdx);
		itm.Release();
	}
	assert(pAbility != NULL);

	if (nCharges > 0) {
		nTotalCharges += nCharges;
		nTotalUsages += (pAbility->chargeType == 3 || pAbility->flags & ITEMABILITYFLAG_RECHARGES) ? nCharges : itm.GetNumUsage(nUsageIdx);
	}
	return;
}
