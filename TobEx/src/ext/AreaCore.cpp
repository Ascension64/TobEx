#include "AreaCore.h"

#include "utils.h"
#include "chitin.h"

BYTE (CArea::*Tramp_CArea_GetSong)(WORD) =
	SetFP(static_cast<BYTE (CArea::*)(WORD)>	(&CArea::GetSong),		0x4D40D6);

DWORD DETOUR_CArea::DETOUR_GetSong(WORD wType) {
	DWORD dwSong;

	switch (wType) {
		case 0: //DAY
			dwSong = nSongDay;
			break;
		case 1: //NIGHT
			dwSong = nSongNight;
			break;
		case 2:
			dwSong = nSongVictory;
			break;
		case 3: //BATTLE
			dwSong = nSongBattle;
			break;
		case 4:
			dwSong = nSongDefeat;
			break;
		case 5:
			dwSong = nSong5;
			break;
		case 6:
			dwSong = nSong6;
			break;
		case 7:
			dwSong = nSong7;
			break;
		case 8:
			dwSong = nSong8;
			break;
		case 9:
			dwSong = nSong9;
			break;
		case 0x100: //POST_BATTLE
			BOOL bIsDay;
			if ((g_pChitin->pGame->timer.nGameTime % ONE_DAY >= SEVEN_HOURS) &&
				  (g_pChitin->pGame->timer.nGameTime % ONE_DAY < TWENTYONE_HOURS)) {
				bIsDay = TRUE;
			} else {
				bIsDay = FALSE;
			}

			if (bIsDay) {
				dwSong = nSongDay;
			} else {
				BOOL bIsDusk;
				if ((g_pChitin->pGame->timer.nGameTime % ONE_DAY >= TWENTYONE_HOURS) &&
					  (g_pChitin->pGame->timer.nGameTime % ONE_DAY < TWENTYTWO_HOURS)) {
					bIsDusk = TRUE;
				} else {
					bIsDusk = FALSE;
				}

				if (bIsDusk) {
					dwSong = nSongDay;
				} else {
					dwSong = nSongNight;
				}
			}

			break;
		default:
			dwSong = -1;
			break;
	}

	if (dwSong == -2) { //Continue Area Music
		BOOL bIsDay;
		if ((g_pChitin->pGame->timer.nGameTime % ONE_DAY >= SEVEN_HOURS) &&
			  (g_pChitin->pGame->timer.nGameTime % ONE_DAY < TWENTYONE_HOURS)) {
			bIsDay = TRUE;
		} else {
			bIsDay = FALSE;
		}

		if (bIsDay) {
			dwSong = nSongDay;
		} else {
			BOOL bIsNight;
			if ((g_pChitin->pGame->timer.nGameTime % ONE_DAY < TWENTYTWO_HOURS) &&
				  (g_pChitin->pGame->timer.nGameTime % ONE_DAY >= SIX_HOURS)) {
				bIsNight = false;
			} else {
				bIsNight = true;
			}

			if (bIsNight) {
				dwSong = nSongNight;
			}
		}
	}

	if (dwSong == -1) { //Continue Outside Music
		switch (wType) {
			case 0:
				dwSong = g_pChitin->pGame->pMasterArea->nSongDay;
				break;
			case 1:
				dwSong = g_pChitin->pGame->pMasterArea->nSongNight;
				break;
			case 2:
				dwSong = g_pChitin->pGame->pMasterArea->nSongVictory;
				break;
			case 3:
				dwSong = g_pChitin->pGame->pMasterArea->nSongBattle;
				break;
			case 4:
				dwSong = g_pChitin->pGame->pMasterArea->nSongDefeat;
				break;
			case 5:
				dwSong = g_pChitin->pGame->pMasterArea->nSong5;
				break;
			case 6:
				dwSong = g_pChitin->pGame->pMasterArea->nSong6;
				break;
			case 7:
				dwSong = g_pChitin->pGame->pMasterArea->nSong7;
				break;
			case 8:
				dwSong = g_pChitin->pGame->pMasterArea->nSong8;
				break;
			case 9:
				dwSong = g_pChitin->pGame->pMasterArea->nSong9;
				break;
			case 0x100:
				BOOL bIsDay;
				if ((g_pChitin->pGame->timer.nGameTime % ONE_DAY >= SEVEN_HOURS) && 
						(g_pChitin->pGame->timer.nGameTime % ONE_DAY < TWENTYONE_HOURS)) {
					bIsDay = TRUE;
				} else {
					bIsDay = FALSE;
				}

				if (bIsDay) {
					dwSong = g_pChitin->pGame->pMasterArea->nSongDay;
				} else {
					BOOL  bIsDusk;
					if ((g_pChitin->pGame->timer.nGameTime % ONE_DAY >= TWENTYONE_HOURS) &&
							(g_pChitin->pGame->timer.nGameTime % ONE_DAY < TWENTYTWO_HOURS)) {
						bIsDusk = TRUE;
					} else {
						bIsDusk = FALSE;
					}

					if (bIsDusk) {
						dwSong = g_pChitin->pGame->pMasterArea->nSongDay;
					} else {
						dwSong = g_pChitin->pGame->pMasterArea->nSongNight;
					}
				}
				break;
			default:
				dwSong = -1;
				break;
		}
	}

	if (dwSong == 0) { //No Music
		dwSong = -1;
	}

	return dwSong;
}