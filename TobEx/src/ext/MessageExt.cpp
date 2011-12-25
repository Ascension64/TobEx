#include "MessageExt.h"

#include "chitin.h"
#include "AreaCommon.h"

void CMessageRemoveAreaAirEffectSpecific::Marshal(void* pData, int* dwSize) {
	if (pData == NULL || *dwSize == 0) {
		//normally an assert continue
		LPCTSTR lpsz = "CMessageRemoveAreaAirEffectSpecific::Marshal(): pData or *dwSize is NULL\r\n";
		L.timestamp();
		L.append(lpsz);
		console.write(lpsz);
	}
	*dwSize = 16;
	pData = IENew CMessageRemoveAreaAirEffectSpecificM();
	if (pData == NULL) {
		//normally an assert continue
		*dwSize = 0;
		LPCTSTR lpsz = "CMessageRemoveAreaAirEffectSpecific::Marshal(): IENew failed\r\n";
		L.timestamp();
		L.append(lpsz);
		console.write(lpsz);
		return;
	}

	int cnt = 0;
	((CMessageRemoveAreaAirEffectSpecificM*)pData)->rAreaName = this->rAreaName.GetBuffer();
	cnt += 8;
	((CMessageRemoveAreaAirEffectSpecificM*)pData)->rResource = this->rResource.GetBuffer();
	cnt += 8;

	if (cnt != *dwSize) {
		//normally an assert continue
		LPCTSTR lpsz = "CMessageRemoveAreaAirEffectSpecific::Marshal(): cnt != *dwSize\r\n";
		L.timestamp();
		L.append(lpsz);
		console.write(lpsz);
	}

	return;
}

BOOL CMessageRemoveAreaAirEffectSpecific::Unmarshal(void* pData, int* dwSize) {
	if (pData == NULL) {
		//normally an assert continue
		LPCTSTR lpsz = "CMessageRemoveAreaAirEffectSpecific::Unmarshal(): pData is NULL\r\n";
		L.timestamp();
		L.append(lpsz);
		console.write(lpsz);
	}
	int cnt = 0;
	this->rAreaName = ((CMessageRemoveAreaAirEffectSpecific*)pData)->rAreaName.GetBuffer();
	cnt += 8;
	this->rResource = ((CMessageRemoveAreaAirEffectSpecific*)pData)->rResource.GetBuffer();
	cnt += 8;

	if (cnt != *dwSize) {
		//normally an assert continue
		LPCTSTR lpsz = "CMessageRemoveAreaAirEffectSpecific::Unmarshal(): cnt != *dwSize\r\n";
		L.timestamp();
		L.append(lpsz);
		console.write(lpsz);
	}

	return TRUE;
}

void CMessageRemoveAreaAirEffectSpecific::DoMessage(void) {

	IECString s = this->rAreaName.SafeToString();
	CArea& area = g_pChitin->pGame->GetLoadedArea(s);
	if (&area != NULL) {
		CArea_RemoveAreaAirEffectSpecific(area, this->rResource);
	}

	return;
}