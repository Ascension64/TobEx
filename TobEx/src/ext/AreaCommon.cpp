#include "AreaCommon.h"

#include <cassert>

#include "chitin.h"
#include "infgame.h"

void CArea_RemoveAreaAirEffectSpecific(CArea& area, ResRef& rResource) {
	if (0) IECString("CArea_RemoveAreaAirEffectSpecific");

	bool bUseResource = true;
	CRuleTable crtResource;
	crtResource.LoadTable(rResource);
	if (crtResource.m_2da.bLoaded == FALSE) {
		LPCTSTR lpsz = "CArea_RemoveAreaAirEffectSpecific(): %s.2da not found, using ClearAir.2da...\r\n";
		L.timestamp();
		L.appendf(lpsz, rResource.GetBuffer());
		console.writef(lpsz, rResource.GetBuffer());
		bUseResource = false;
	}

	POSITION pos = area.m_lVertSortFront.GetHeadPosition();
	while (pos != NULL) {
		ENUM e = (ENUM)area.m_lVertSortFront.GetNext(pos);
		CGameObject* pObj;
		if (g_pChitin->pGame->m_GameObjectArray.GetShare(e, THREAD_ASYNCH, &pObj, -1) == OBJECT_SUCCESS) {
			if (pObj->GetType() == CGAMEOBJECT_TYPE_PROJECTILE) {
				IECString sMissileId;
				sMissileId.Format("%d", ((CProjectile*)pObj)->nMissileId);

				POSITION posString;
				bool bFound = bUseResource
					? crtResource.FindString(sMissileId, &posString, FALSE) 
					: g_pChitin->pGame->CLEARAIR.FindString(sMissileId, &posString, FALSE);
				if (bFound) {
					char nResult;
					do {
						nResult = g_pChitin->pGame->m_GameObjectArray.GetDeny(e, THREAD_ASYNCH, &pObj, INFINITE);
					} while (nResult == OBJECT_SHARING);

					if (nResult == OBJECT_SUCCESS) {
						pObj->RemoveFromArea();
						g_pChitin->pGame->m_GameObjectArray.FreeDeny(e, THREAD_ASYNCH, INFINITE);
					}
				}
			} 
			else if (pObj->GetType() == CGAMEOBJECT_TYPE_SMOKE) {
				bool bRemoveSmoke = false;
				AnimData& animData = ((CSmokeObject*)pObj)->m_animation;
				assert(animData.pAnimation != NULL);
				
				short wAnimId = animData.pAnimation->wAnimId;
				
				if (bUseResource) {
					char szSmokeId[7] = {0};
					sprintf_s(szSmokeId, "0x%.4X", wAnimId & 0xFF0F);
					IECString sSmokeId(szSmokeId);
					POSITION posString;
					bRemoveSmoke = crtResource.FindString(sSmokeId, &posString, FALSE);
				}
				else if ((wAnimId & 0xFF0F) == 0x500) { //STINKCLOUD_*
					bRemoveSmoke = true;
				}

				if (bRemoveSmoke) {
					char nResult;
					do {
						nResult = g_pChitin->pGame->m_GameObjectArray.GetDeny(e, THREAD_ASYNCH, &pObj, INFINITE);
					} while (nResult == OBJECT_SHARING);

					if (nResult == OBJECT_SUCCESS) {
						pObj->RemoveFromArea();
						g_pChitin->pGame->m_GameObjectArray.FreeDeny(e, THREAD_ASYNCH, INFINITE);
					}
				}
			}
			g_pChitin->pGame->m_GameObjectArray.FreeShare(e, THREAD_ASYNCH, INFINITE);
		}
	}
	return;
}