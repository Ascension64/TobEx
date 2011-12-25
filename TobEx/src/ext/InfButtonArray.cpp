#include "InfButtonArray.h"

#include "chitin.h"
#include "ObjectStats.h"

BOOL (CButtonArray::*Tramp_CButtonArray_CheckButtonEnabled)(int) =
	SetFP(static_cast<BOOL (CButtonArray::*)(int)>	(&CButtonArray::CheckButtonEnabled),	0x671C9E);

BOOL DETOUR_CButtonArray::DETOUR_CheckButtonEnabled(int nIdx) {
	if (0) IECString("DETOUR_CButtonArray::DETOUR_CheckButtonEnabled");

	unsigned short wStatBtIdx = USHRT_MAX;
	switch (nIdx) {
	case CBUTTONARRAY_BTID_TALK:
		wStatBtIdx = CDERIVEDSTATS_BUTTONDISABLE_TALK;
		break;
	case CBUTTONARRAY_BTID_STEALTH:
		wStatBtIdx = CDERIVEDSTATS_BUTTONDISABLE_STEALTH;
		break;
	case CBUTTONARRAY_BTID_THIEVING:
		wStatBtIdx = CDERIVEDSTATS_BUTTONDISABLE_THIEVING;
		break;
	case CBUTTONARRAY_BTID_CASTSPELL:
		wStatBtIdx = CDERIVEDSTATS_BUTTONDISABLE_CASTSPELL;
		break;
	case CBUTTONARRAY_BTID_QUICKITEM1:
		wStatBtIdx = CDERIVEDSTATS_BUTTONDISABLE_QUICKITEM1;
		break;
	case CBUTTONARRAY_BTID_QUICKITEM2:
		wStatBtIdx = CDERIVEDSTATS_BUTTONDISABLE_QUICKITEM2;
		break;
	case CBUTTONARRAY_BTID_QUICKITEM3:
		wStatBtIdx = CDERIVEDSTATS_BUTTONDISABLE_QUICKITEM3;
		break;
	case CBUTTONARRAY_BTID_TURNUNDEAD:
		wStatBtIdx = CDERIVEDSTATS_BUTTONDISABLE_TURNUNDEAD;
		break;
	case CBUTTONARRAY_BTID_QUICKSPELL1:
		wStatBtIdx = CDERIVEDSTATS_BUTTONDISABLE_QUICKSPELL1;
		break;
	case CBUTTONARRAY_BTID_QUICKSPELL2:
		wStatBtIdx = CDERIVEDSTATS_BUTTONDISABLE_QUICKSPELL2;
		break;
	case CBUTTONARRAY_BTID_QUICKSPELL3:
		wStatBtIdx = CDERIVEDSTATS_BUTTONDISABLE_QUICKSPELL3;
		break;
	case CBUTTONARRAY_BTID_USEITEM:
		wStatBtIdx = CDERIVEDSTATS_BUTTONDISABLE_USEITEM;
		break;
	case CBUTTONARRAY_BTID_ABILITY:
		wStatBtIdx = CDERIVEDSTATS_BUTTONDISABLE_ABILITY;
		break;
	case CBUTTONARRAY_BTID_BARDSONG: //new
		wStatBtIdx = CDERIVEDSTATS_BUTTONDISABLE_BARDSONG;
		break;
	case CBUTTONARRAY_BTID_FINDTRAPS: //new
		wStatBtIdx = CDERIVEDSTATS_BUTTONDISABLE_FINDTRAPS;
		break;
	default:
		return TRUE;
		break;
	}

	if (g_pChitin->pGame->m_PartySelection.celSelected.GetCount() == 0) return TRUE;

	Enum e = g_pChitin->pGame->m_PartySelection.GetFirstSelected();
	CCreatureObject* pCre = NULL;
	
	char nResult;
	do {
		nResult = g_pChitin->pGame->m_GameObjectArrayHandler.GetGameObjectShare(e, THREAD_ASYNCH, &pCre, INFINITE);
	} while (nResult == OBJECT_SHARING || nResult == OBJECT_DENYING);
	if (nResult != OBJECT_SUCCESS) return TRUE;

	BOOL bButtonAllowed = TRUE;
	if (wStatBtIdx < 14) bButtonAllowed = !pCre->GetDerivedStats().ButtonDisable[wStatBtIdx];
	if (wStatBtIdx == 14) bButtonAllowed = !pCre->GetDerivedStats().GetStat(CDERIVEDSTATSEX_BASE + CDERIVEDSTATSEX_BUTTONDISABLEFINDTRAPS);

	g_pChitin->pGame->m_GameObjectArrayHandler.FreeGameObjectShare(e, THREAD_ASYNCH, INFINITE);
	return bButtonAllowed;
}
