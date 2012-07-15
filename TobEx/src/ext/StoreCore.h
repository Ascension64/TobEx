#ifndef STORECORE_H
#define STORECORE_H

#include "stdafx.h"
#include "stocore.h"

void __stdcall CStore_AddItem_SetUsages(CStore& sto, CItem& itm, StoFileItem& stoitm, unsigned int nUsageIdx);
void __stdcall CStore_GetBuyPrice_GetChargePercent(CStore& sto, short& nTotalUsages, short& nTotalCharges, CItem& itm, unsigned int nUsageIdx);
void __stdcall CStore_GetSellPrice_GetChargePercent(CStore& sto, short& nTotalUsages, short& nTotalCharges, CItem& itm, unsigned int nUsageIdx);
void __stdcall CStore_UnmarshalItem_SetUsages(CItem& itm, StoFileItem& stoitm, unsigned int nUsageIdx);

#endif //STORECORE_H