#include "AnimationCore.h"

#include "objcre.h"
#include "infgame.h"
#include "console.h"
#include "log.h"
#include "InfGameCommon.h"

void (CAnimation::*Tramp_CAnimation_PlayCurrentSequenceSound)(CCreatureObject*) =
	SetFP(static_cast<void (CAnimation::*)(CCreatureObject*)>	(&CAnimation::PlayCurrentSequenceSound),	0x7F9DF4);
BOOL (*Tramp_CAnimation_IsPlayableAnimation)(WORD) =
	reinterpret_cast<BOOL (*)(WORD)>																		(0x85F364);
LPCTSTR (CAnimation::*Tramp_CAnimation_GetWalkingSound)(WORD) =
	SetFP(static_cast<LPCTSTR (CAnimation::*)(WORD)>			(&CAnimation::GetWalkingSound),				0x87B7B0);

void DETOUR_CAnimation::DETOUR_PlayCurrentSequenceSound(CCreatureObject* pCre) {
	(this->*Tramp_CAnimation_PlayCurrentSequenceSound)(pCre);

	WORD wCycle, wFrame;
	GetCurrentCycleAndFrame(wCycle, wFrame);

	WORD wCurrentSequence = pCre->m_animation.wCurrentSequence;
	switch (wCurrentSequence) {
		case SEQ_ATTACK_SLASH: 
			soundset[SEQ_ATTACK_SLASH].PlayPrimedSound(wFrame, pCre);
			break;
		case SEQ_ATTACK_BACKSLASH:
			soundset[SEQ_ATTACK_BACKSLASH].PlayPrimedSound(wFrame, pCre);
			break;
		case SEQ_ATTACK_JAB:
			soundset[SEQ_ATTACK_JAB].PlayPrimedSound(wFrame, pCre);
			break;
		default:
			break;
	}

	return;
}

BOOL DETOUR_CAnimation::DETOUR_IsPlayableAnimation(WORD wAnimId) {
	switch (wAnimId & 0xF00) { //class
	case 0x200: //MAGE_*
		switch (wAnimId & 0xF) { //race
		case 0: //HUMAN
		case 1: //ELF
		case 2: //DWARF
			break;
		case 3: //HALFLING
			return TRUE;
		case 4: //GNOME
		case 5: //HALF_ORC
		default:
			break;
		}
		break;

	default:
		break;

	}

	return Tramp_CAnimation_IsPlayableAnimation(wAnimId);
}

LPCTSTR DETOUR_CAnimation::DETOUR_GetWalkingSound(WORD wTerrainCode) {
	if (!pRuleEx->m_AnimWalkSound.m_2da.bLoaded ||
		!pRuleEx->m_AnimTerrainSound.m_2da.bLoaded) return (this->*Tramp_CAnimation_GetWalkingSound)(wTerrainCode);

	IECString sColSound = "WALK_SOUND";
	IECString sColRand = "WALK_NUM";

	char szAnimId[7];
	sprintf_s(szAnimId, 7, "0x%.4X", wAnimId);
	IECString sRowAnimId = szAnimId;

	char* szSound = IENew char[8];
	for (int i = 0; i < 8; i ++) {
		szSound[i] = '\0';
	}
	IECString sSound = pRuleEx->m_AnimWalkSound.GetValue(sColSound, sRowAnimId);
	IECString sRand = pRuleEx->m_AnimWalkSound.GetValue(sColRand, sRowAnimId);

	if (strcmp((LPCTSTR)sSound, "*")) {
		int nRand = 0;

		if (!strcmp((LPCTSTR)sSound, "TERRAIN") &&
			!strcmp((LPCTSTR)sRand, "*")) {
			int nCol = 0;
			int nRow = wTerrainCode;

			if (nCol < pRuleEx->m_AnimTerrainSound.nCols &&
				nRow < pRuleEx->m_AnimTerrainSound.nRows &&
				nCol >= 0 &&
				nRow >= 0) {
				sSound = *((pRuleEx->m_AnimTerrainSound.pDataArray) + (pRuleEx->m_AnimTerrainSound.nCols * nRow + nCol));
			} else {
				sSound = pRuleEx->m_AnimTerrainSound.defaultVal;
			}

			nCol = 1;
			if (nCol < pRuleEx->m_AnimTerrainSound.nCols &&
				nRow < pRuleEx->m_AnimTerrainSound.nRows &&
				nCol >= 0 &&
				nRow >= 0) {
				sRand = *((pRuleEx->m_AnimTerrainSound.pDataArray) + (pRuleEx->m_AnimTerrainSound.nCols * nRow + nCol));
			} else {
				sRand = pRuleEx->m_AnimTerrainSound.defaultVal;
			}
		}

		sscanf_s((LPCTSTR)sRand, "%d", &nRand);
		strncpy_s(szSound, 7, (LPCTSTR)sSound, 6);

		if (nRand > 0) {
			szSound[6] = (IERand() * nRand >> 15) + 'a';
			if (szSound[6] == nRand + 'a' - 1) szSound[6] = '\0';
		} else {
			szSound[6] = '\0';
		}
	}

	return szSound;
};