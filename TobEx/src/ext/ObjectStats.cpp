#include "ObjectStats.h"
#include "InfGameCommon.h"

#include "chitin.h"

void (CConditionalSpellList::*Tramp_CConditionalSpellList_EvaluateTriggers)(CCreatureObject&) =
	SetFP(static_cast<void (CConditionalSpellList::*)(CCreatureObject&)>	(&CConditionalSpellList::EvaluateTriggers),	0x46BE04);

CDerivedStats& (CDerivedStats::*Tramp_CDerivedStats_Construct_3)(CreFileData&, CreFileMemSpellLevel*, CreFileMemSpellLevel*) =
	SetFP(static_cast<CDerivedStats& (CDerivedStats::*)(CreFileData&, CreFileMemSpellLevel*, CreFileMemSpellLevel*)>
																			(&CDerivedStats::Construct),				0x46CB40);
CDerivedStats& (CDerivedStats::*Tramp_CDerivedStats_Construct_0)() =
	SetFP(static_cast<CDerivedStats& (CDerivedStats::*)()>					(&CDerivedStats::Construct),				0x46D1B2);
void (CDerivedStats::*Tramp_CDerivedStats_Init)(CreFileData&, CreFileMemSpellLevel*, CreFileMemSpellLevel*) =
	SetFP(static_cast<void (CDerivedStats::*)(CreFileData&, CreFileMemSpellLevel*, CreFileMemSpellLevel*)>
																			(&CDerivedStats::Init),						0x46DB9C);
CDerivedStats& (CDerivedStats::*Tramp_CDerivedStats_OpAssign)(CDerivedStats&) =
	SetFP(static_cast<CDerivedStats& (CDerivedStats::*)(CDerivedStats&)>	(&CDerivedStats::OpAssign),					0x46EAC6);
void (CDerivedStats::*Tramp_CDerivedStats_ClearStats)() =
	SetFP(static_cast<void (CDerivedStats::*)()>							(&CDerivedStats::ClearStats),				0x46FCF5);
CDerivedStats& (CDerivedStats::*Tramp_CDerivedStats_OpAdd)(CDerivedStats&) =
	SetFP(static_cast<CDerivedStats& (CDerivedStats::*)(CDerivedStats&)>	(&CDerivedStats::OpAdd),					0x470945);
void (CDerivedStats::*Tramp_CDerivedStats_LimitStats)() =
	SetFP(static_cast<void (CDerivedStats::*)()>							(&CDerivedStats::LimitStats),				0x471B36);
int (CDerivedStats::*Tramp_CDerivedStats_GetStat)(short) =
	SetFP(static_cast<int (CDerivedStats::*)(short)>						(&CDerivedStats::GetStat),					0x473162);
void (CDerivedStats::*Tramp_CDerivedStats_MarshalTemplate)(CDerivedStatsTemplate**, int*) =
	SetFP(static_cast<void (CDerivedStats::*)(CDerivedStatsTemplate**, int*)>(&CDerivedStats::MarshalTemplate),			0x474AAE);
void (CDerivedStats::*Tramp_CDerivedStats_UnmarshalTemplate)(CDerivedStatsTemplate&, int) =
	SetFP(static_cast<void (CDerivedStats::*)(CDerivedStatsTemplate&, int)>
																			(&CDerivedStats::UnmarshalTemplate),		0x474AF2);
void (CDerivedStats::*Tramp_CDerivedStats_Deconstruct)() =
	SetFP(static_cast<void (CDerivedStats::*)()>							(&CDerivedStats::Deconstruct),				0x567770);

void DETOUR_CConditionalSpellList::DETOUR_EvaluateTriggers(CCreatureObject& cre) {
	Object o = Object();
	if (cre.m_nContingencyDelay > 0) return;
	if (g_pChitin->pGame->m_GameSave.mode == 0x1016E || //CutSceneMode
		g_pChitin->pGame->m_GameSave.mode == 0x3016E) //CutSceneLite
		return;

	cre.m_nContingencyDelay = 0;
	int nGameTime = g_pChitin->pGame->m_WorldTimer.nGameTime;
	
	POSITION pos = this->GetHeadPosition();
	POSITION posPrev = pos;
	while (pos != NULL) {
		CConditionalSpell* pccs = (CConditionalSpell*)(this->GetNext(pos));

		unsigned int nDelay = pccs->eff.effect.nParam2 >> 16;
		if (nDelay == 0) nDelay = 100;

		if ((pccs->eff.effect.nParam3 >> 16) == 0) {
			if (pGameOptionsEx->bDebugVerbose) {
				LPCTSTR lpsz = "DETOUR_CConditionalSpellList::DETOUR_EvaluateTriggers(): effect application time not set\r\n";
				L.timestamp();
				L.append(lpsz);
				console.write(lpsz);
			}
			
			pccs->eff.effect.nParam4 = nGameTime;
			pccs->eff.effect.nParam3 |= (1 << 16);
		}

		if ((nGameTime - pccs->eff.effect.nParam4) % nDelay == 0) {
			if (pccs->t.opcode & 0x4000) {
				if (cre.EvaluateTrigger(pccs->t)) {
					o = pccs->oTarget;
					o.DecodeIdentifiers(cre);
					CGameObject& cgoTarget = cre.SetTarget(o, CGAMEOBJECT_TYPE_SPRITE);
					if (&cgoTarget != NULL) {
						cre.CastSpell(pccs->rResource1, cgoTarget, TRUE, 0x9049, NULL, TRUE, FALSE);
						if (pccs->rResource2 != "") cre.CastSpell(pccs->rResource2, cgoTarget, TRUE, 0x9049, NULL, TRUE, FALSE);
						if (pccs->rResource3 != "") cre.CastSpell(pccs->rResource3, cgoTarget, TRUE, 0x9049, NULL, TRUE, FALSE);
						g_pChitin->pGame->m_GameObjectArrayHandler.FreeGameObjectShare(cgoTarget.e, THREAD_ASYNCH, INFINITE);
					}

					if (pccs->dwFlags & 0x1) {
						CMessageDisplayDialogue* pcmDD = IENew CMessageDisplayDialogue();
						pcmDD->eTarget = cre.e;
						pcmDD->eSource = cre.e;
						pcmDD->srOwner = cre.GetLongNameStrRef();
						pcmDD->srText = 0x9048;
						pcmDD->rgbOwner = g_pColorRangeArray[cre.m_BaseStats.colors.colorMajor];
						pcmDD->rgbText = g_ColorDefaultText;
						pcmDD->u1c = -1;
						pcmDD->u20 = 0;
						pcmDD->bFloatText = false;
						pcmDD->bPlaySound = true;

						g_pChitin->messages.Send(*pcmDD, FALSE);

						cre.m_EffectsEquipped.RemoveOneEffect(pccs->eff, cre, TRUE);
						cre.m_EffectsMain.RemoveOneEffect(pccs->eff, cre, TRUE);
						this->RemoveAt(posPrev);
						delete pccs;
					}
				}
			}
		}
	
	posPrev = pos;

	}

	return;
}

CDerivedStats& DETOUR_CDerivedStats::DETOUR_Construct3(CreFileData& stats, CreFileMemSpellLevel* memArrayMage, CreFileMemSpellLevel* memArrayPriest) {
	DWORD nSize = pRuleEx->m_nStats - 200;

	//init pStatsEx
	int* pStatsEx = IENew int[nSize];
	for (int i = 0; i < nSize; i++ ) {
		pStatsEx[i] = 0;
	}

	animationRemoval = (int)pStatsEx;

	return (this->*Tramp_CDerivedStats_Construct_3)(stats, memArrayMage, memArrayPriest);
}

CDerivedStats& DETOUR_CDerivedStats::DETOUR_Construct0() {
	DWORD nSize = pRuleEx->m_nStats - 200;

	//init pStatsEx
	int* pStatsEx = IENew int[nSize];
	for (int i = 0; i < nSize; i++ ) {
		pStatsEx[i] = 0;
	}

	animationRemoval = (int)pStatsEx;

	return (this->*Tramp_CDerivedStats_Construct_0)();
}
	
void DETOUR_CDerivedStats::DETOUR_Init(CreFileData& stats, CreFileMemSpellLevel* memArrayMage, CreFileMemSpellLevel* memArrayPriest) {
	DWORD nSize = pRuleEx->m_nStats - 200;

	int* pStatsEx = NULL;
	if (animationRemoval) {
		pStatsEx = (int*)animationRemoval;
		for (int i = 0; i < nSize; i++ ) {
			pStatsEx[i] = 0;
		}
	} else {
		LPCTSTR lpsz = "DETOUR_CDerivedStats::DETOUR_Init(): pStatsEx == NULL\r\n";
		L.timestamp();
		L.append(lpsz);
		console.write(lpsz);
	}

	(this->*Tramp_CDerivedStats_Init)(stats, memArrayMage, memArrayPriest);

	if (pStatsEx != NULL && nSize >= 100) {	
		//init the values of new hard-coded stats here
		CCreatureObject* pCre = (CCreatureObject*)((unsigned int)&stats - 0x3F6);
		if (*(int*)pCre == 0xAA98A8) {
			Object o = pCre->oBase;

			pStatsEx[CDERIVEDSTATSEX_FIGHTERLEVEL] = CDerivedStats_GetSubclassLevelNoAssertion(*this, o.Class, CLASS_FIGHTER);
			pStatsEx[CDERIVEDSTATSEX_MAGELEVEL] = CDerivedStats_GetSubclassLevelNoAssertion(*this, o.Class, CLASS_MAGE);
			pStatsEx[CDERIVEDSTATSEX_CLERICLEVEL] = CDerivedStats_GetSubclassLevelNoAssertion(*this, o.Class, CLASS_CLERIC);
			pStatsEx[CDERIVEDSTATSEX_THIEFLEVEL] = CDerivedStats_GetSubclassLevelNoAssertion(*this, o.Class, CLASS_THIEF);
			pStatsEx[CDERIVEDSTATSEX_DRUIDLEVEL] = CDerivedStats_GetSubclassLevelNoAssertion(*this, o.Class, CLASS_DRUID);
			pStatsEx[CDERIVEDSTATSEX_RANGERLEVEL] = CDerivedStats_GetSubclassLevelNoAssertion(*this, o.Class, CLASS_RANGER);
			pStatsEx[CDERIVEDSTATSEX_EFFECTIVECLERICLEVEL] = CDerivedStats_GetEffectiveClericLevelNoAssertion(*this, o.Class);
		} else {
			LPCTSTR lpsz = "DETOUR_CDerivedStats::DETOUR_Init(): Problem getting CCreatureObject*\r\n";
			L.timestamp();
			L.append(lpsz);
			console.write(lpsz);
		}
	}

	animationRemoval = (int)pStatsEx;

	return;
}

CDerivedStats& DETOUR_CDerivedStats::DETOUR_OpAssign(CDerivedStats& cds) {
	DWORD nSize = pRuleEx->m_nStats - 200;

	int* pStatsEx = NULL;
	if (animationRemoval && cds.animationRemoval) {
		pStatsEx = (int*)animationRemoval;
		int* pStatsExAdd = (int*)cds.animationRemoval;
		for (int i = 0; i < nSize; i++ ) {
			pStatsEx[i] = pStatsExAdd[i];
		}
	} else {
		LPCTSTR lpsz = "DETOUR_CDerivedStats::DETOUR_OpAssign(): this->pStatsEx == NULL || cds.pStatsEx == NULL\r\n";
		L.timestamp();
		L.append(lpsz);
		console.write(lpsz);
	}

	(this->*Tramp_CDerivedStats_OpAssign)(cds);

	animationRemoval = (int)pStatsEx;

	return *this;
}

void DETOUR_CDerivedStats::DETOUR_ClearStats() {
	DWORD nSize = pRuleEx->m_nStats - 200;

	int* pStatsEx = NULL;
	if (animationRemoval) {
		pStatsEx = (int*)animationRemoval;
		for (int i = 0; i < nSize; i++ ) {
			pStatsEx[i] = 0;
		}
	} else {
		LPCTSTR lpsz = "DETOUR_CDerivedStats::DETOUR_ClearStats(): pStatsEx == NULL\r\n";
		L.timestamp();
		L.append(lpsz);
		console.write(lpsz);
	}

	(this->*Tramp_CDerivedStats_ClearStats)();

	animationRemoval = (int)pStatsEx;

	return;
}

CDerivedStats& DETOUR_CDerivedStats::DETOUR_OpAdd(CDerivedStats& cds) {
	if (pGameOptionsEx->bEffAttacksPerRoundFix) {
		float fNumAttacks = CDerivedStats_NumAttacksShortToFloat(numAttacks) + CDerivedStats_NumAttacksShortToFloat(cds.numAttacks);
		numAttacks = CDerivedStats_NumAttacksFloatToShort(fNumAttacks);
		cds.numAttacks = 0;
		numAttacks = CDerivedStats_NumAttacksFloatToShort(fNumAttacks);
	}

	int* pStatsEx = NULL;
	if (pGameOptionsEx->bEngineExpandedStats) {
		if (animationRemoval && cds.animationRemoval) {
			DWORD nSize = pRuleEx->m_nStats - 200;
			pStatsEx = (int*)animationRemoval;
			int* pStatsExAdd = (int*)cds.animationRemoval;
			for (int i = 0; i < nSize; i++ ) {
				switch (i + 200 + 1) { //make equivalent to the STATS.IDS opcode for easier viewing
				case 201: //ANIMATIONREMOVAL
					pStatsEx[i] |= pStatsExAdd[i];
					break;
				default:
					pStatsEx[i] += pStatsExAdd[i];
					break;
				}
			}
		} else {
			LPCTSTR lpsz = "DETOUR_CDerivedStats::DETOUR_OpAdd(): this->pStatsEx == NULL || cds.pStatsEx == NULL\r\n";
			L.timestamp();
			L.append(lpsz);
			console.write(lpsz);
		}
	}

	(this->*Tramp_CDerivedStats_OpAdd)(cds);

	if (pGameOptionsEx->bEngineExpandedStats) {
		animationRemoval = (int)pStatsEx;
	}

	return *this;

}

void DETOUR_CDerivedStats::DETOUR_LimitStats() {
	proficiencyBastardSword = max(0, proficiencyBastardSword & 0x00000007) | (proficiencyBastardSword & 0xFFFFFFF8);
	proficiencyBastardSword = min(5, proficiencyBastardSword & 0x00000007) | (proficiencyBastardSword & 0xFFFFFFF8);
	proficiencyLongSword = max(0, proficiencyLongSword & 0x00000007) | (proficiencyLongSword & 0xFFFFFFF8);
	proficiencyLongSword = min(5, proficiencyLongSword & 0x00000007) | (proficiencyLongSword & 0xFFFFFFF8);
	proficiencyShortSword = max(0, proficiencyShortSword & 0x00000007) | (proficiencyShortSword & 0xFFFFFFF8);
	proficiencyShortSword = min(5, proficiencyShortSword & 0x00000007) | (proficiencyShortSword & 0xFFFFFFF8);
	proficiencyAxe = max(0, proficiencyAxe & 0x00000007) | (proficiencyAxe & 0xFFFFFFF8);
	proficiencyAxe = min(5, proficiencyAxe & 0x00000007) | (proficiencyAxe & 0xFFFFFFF8);
	proficiencyTwoHandedSword = max(0, proficiencyTwoHandedSword & 0x00000007) | (proficiencyTwoHandedSword & 0xFFFFFFF8);
	proficiencyTwoHandedSword = min(5, proficiencyTwoHandedSword & 0x00000007) | (proficiencyTwoHandedSword & 0xFFFFFFF8);
	proficiencyKatana = max(0, proficiencyKatana & 0x00000007) | (proficiencyKatana & 0xFFFFFFF8);
	proficiencyKatana = min(5, proficiencyKatana & 0x00000007) | (proficiencyKatana & 0xFFFFFFF8);
	proficiencyScimitarWakizashiNinjato = max(0, proficiencyScimitarWakizashiNinjato & 0x00000007) | (proficiencyScimitarWakizashiNinjato & 0xFFFFFFF8);
	proficiencyScimitarWakizashiNinjato = min(5, proficiencyScimitarWakizashiNinjato & 0x00000007) | (proficiencyScimitarWakizashiNinjato & 0xFFFFFFF8);
	proficiencyDagger = max(0, proficiencyDagger & 0x00000007) | (proficiencyDagger & 0xFFFFFFF8);
	proficiencyDagger = min(5, proficiencyDagger & 0x00000007) | (proficiencyDagger & 0xFFFFFFF8);
	proficiencyWarhammer = max(0, proficiencyWarhammer & 0x00000007) | (proficiencyWarhammer & 0xFFFFFFF8);
	proficiencyWarhammer = min(5, proficiencyWarhammer & 0x00000007) | (proficiencyWarhammer & 0xFFFFFFF8);
	proficiencySpear = max(0, proficiencySpear & 0x00000007) | (proficiencySpear & 0xFFFFFFF8);
	proficiencySpear = min(5, proficiencySpear & 0x00000007) | (proficiencySpear & 0xFFFFFFF8);
	proficiencyHalberd = max(0, proficiencyHalberd & 0x00000007) | (proficiencyHalberd & 0xFFFFFFF8);
	proficiencyHalberd = min(5, proficiencyHalberd & 0x00000007) | (proficiencyHalberd & 0xFFFFFFF8);
	proficiencyFlailMorningstar = max(0, proficiencyFlailMorningstar & 0x00000007) | (proficiencyFlailMorningstar & 0xFFFFFFF8);
	proficiencyFlailMorningstar = min(5, proficiencyFlailMorningstar & 0x00000007) | (proficiencyFlailMorningstar & 0xFFFFFFF8);
	proficiencyMace = max(0, proficiencyMace & 0x00000007) | (proficiencyMace & 0xFFFFFFF8);
	proficiencyMace = min(5, proficiencyMace & 0x00000007) | (proficiencyMace & 0xFFFFFFF8);
	proficiencyQuarterstaff = max(0, proficiencyQuarterstaff & 0x00000007) | (proficiencyQuarterstaff & 0xFFFFFFF8);
	proficiencyQuarterstaff = min(5, proficiencyQuarterstaff & 0x00000007) | (proficiencyQuarterstaff & 0xFFFFFFF8);
	proficiencyCrossbow = max(0, proficiencyCrossbow & 0x00000007) | (proficiencyCrossbow & 0xFFFFFFF8);
	proficiencyCrossbow = min(5, proficiencyCrossbow & 0x00000007) | (proficiencyCrossbow & 0xFFFFFFF8);
	proficiencyLongbow = max(0, proficiencyLongbow & 0x00000007) | (proficiencyLongbow & 0xFFFFFFF8);
	proficiencyLongbow = min(5, proficiencyLongbow & 0x00000007) | (proficiencyLongbow & 0xFFFFFFF8);
	proficiencyShortbow = max(0, proficiencyShortbow & 0x00000007) | (proficiencyShortbow & 0xFFFFFFF8);
	proficiencyShortbow = min(5, proficiencyShortbow & 0x00000007) | (proficiencyShortbow & 0xFFFFFFF8);
	proficiencyDart = max(0, proficiencyDart & 0x00000007) | (proficiencyDart & 0xFFFFFFF8);
	proficiencyDart = min(5, proficiencyDart & 0x00000007) | (proficiencyDart & 0xFFFFFFF8);
	proficiencySling = max(0, proficiencySling & 0x00000007) | (proficiencySling & 0xFFFFFFF8);
	proficiencySling = min(5, proficiencySling & 0x00000007) | (proficiencySling & 0xFFFFFFF8);
	/*proficiencyBlackjack = max(0, proficiencyBlackjack & 0x00000007) | (proficiencyBlackjack & 0xFFFFFFF8);
	proficiencyBlackjack = min(5, proficiencyBlackjack & 0x00000007) | (proficiencyBlackjack & 0xFFFFFFF8);
	proficiencyGun = max(0, proficiencyGun & 0x00000007) | (proficiencyGun & 0xFFFFFFF8);
	proficiencyGun = min(5, proficiencyGun & 0x00000007) | (proficiencyGun & 0xFFFFFFF8);
	proficiencyMartialArts = max(0, proficiencyMartialArts & 0x00000007) | (proficiencyMartialArts & 0xFFFFFFF8);
	proficiencyMartialArts = min(5, proficiencyMartialArts & 0x00000007) | (proficiencyMartialArts & 0xFFFFFFF8);*/
	proficiencyTwoHanded = max(0, proficiencyTwoHanded & 0x00000007) | (proficiencyTwoHanded & 0xFFFFFFF8);
	proficiencyTwoHanded = min(5, proficiencyTwoHanded & 0x00000007) | (proficiencyTwoHanded & 0xFFFFFFF8);
	proficiencySwordAndShield = max(0, proficiencySwordAndShield & 0x00000007) | (proficiencySwordAndShield & 0xFFFFFFF8);
	proficiencySwordAndShield = min(5, proficiencySwordAndShield & 0x00000007) | (proficiencySwordAndShield & 0xFFFFFFF8);
	proficiencySingleWeapon = max(0, proficiencySingleWeapon & 0x00000007) | (proficiencySingleWeapon & 0xFFFFFFF8);
	proficiencySingleWeapon = min(5, proficiencySingleWeapon & 0x00000007) | (proficiencySingleWeapon & 0xFFFFFFF8);
	proficiencyTwoWeapon = max(0, proficiencyTwoWeapon & 0x00000007) | (proficiencyTwoWeapon & 0xFFFFFFF8);
	proficiencyTwoWeapon = min(5, proficiencyTwoWeapon & 0x00000007) | (proficiencyTwoWeapon & 0xFFFFFFF8);
	/*proficiencyExtra1 = max(0, proficiencyExtra1 & 0x00000007) | (proficiencyExtra1 & 0xFFFFFFF8);
	proficiencyExtra1 = min(5, proficiencyExtra1 & 0x00000007) | (proficiencyExtra1 & 0xFFFFFFF8);
	proficiencyExtra2 = max(0, proficiencyExtra2 & 0x00000007) | (proficiencyExtra2 & 0xFFFFFFF8);
	proficiencyExtra2 = min(5, proficiencyExtra2 & 0x00000007) | (proficiencyExtra2 & 0xFFFFFFF8);
	proficiencyExtra3 = max(0, proficiencyExtra3 & 0x00000007) | (proficiencyExtra3 & 0xFFFFFFF8);
	proficiencyExtra3 = min(5, proficiencyExtra3 & 0x00000007) | (proficiencyExtra3 & 0xFFFFFFF8);
	proficiencyExtra4 = max(0, proficiencyExtra4 & 0x00000007) | (proficiencyExtra4 & 0xFFFFFFF8);
	proficiencyExtra4 = min(5, proficiencyExtra4 & 0x00000007) | (proficiencyExtra4 & 0xFFFFFFF8);
	proficiencyExtra5 = max(0, proficiencyExtra5 & 0x00000007) | (proficiencyExtra5 & 0xFFFFFFF8);
	proficiencyExtra5 = min(5, proficiencyExtra5 & 0x00000007) | (proficiencyExtra5 & 0xFFFFFFF8);
	proficiencyExtra6 = max(0, proficiencyExtra6 & 0x00000007) | (proficiencyExtra6 & 0xFFFFFFF8);
	proficiencyExtra6 = min(5, proficiencyExtra6 & 0x00000007) | (proficiencyExtra6 & 0xFFFFFFF8);
	proficiencyExtra7 = max(0, proficiencyExtra7 & 0x00000007) | (proficiencyExtra7 & 0xFFFFFFF8);
	proficiencyExtra7 = min(5, proficiencyExtra7 & 0x00000007) | (proficiencyExtra7 & 0xFFFFFFF8);
	proficiencyExtra8 = max(0, proficiencyExtra8 & 0x00000007) | (proficiencyExtra8 & 0xFFFFFFF8);
	proficiencyExtra8 = min(5, proficiencyExtra8 & 0x00000007) | (proficiencyExtra8 & 0xFFFFFFF8);
	proficiencyExtra9 = max(0, proficiencyExtra9 & 0x00000007) | (proficiencyExtra9 & 0xFFFFFFF8);
	proficiencyExtra9 = min(5, proficiencyExtra9 & 0x00000007) | (proficiencyExtra9 & 0xFFFFFFF8);
	proficiencyExtra10 = max(0, proficiencyExtra10 & 0x00000007) | (proficiencyExtra10 & 0xFFFFFFF8);
	proficiencyExtra10 = min(5, proficiencyExtra10 & 0x00000007) | (proficiencyExtra10 & 0xFFFFFFF8);
	proficiencyExtra11 = max(0, proficiencyExtra11 & 0x00000007) | (proficiencyExtra11 & 0xFFFFFFF8);
	proficiencyExtra11 = min(5, proficiencyExtra11 & 0x00000007) | (proficiencyExtra11 & 0xFFFFFFF8);
	proficiencyExtra12 = max(0, proficiencyExtra12 & 0x00000007) | (proficiencyExtra12 & 0xFFFFFFF8);
	proficiencyExtra12 = min(5, proficiencyExtra12 & 0x00000007) | (proficiencyExtra12 & 0xFFFFFFF8);
	proficiencyExtra13 = max(0, proficiencyExtra13 & 0x00000007) | (proficiencyExtra13 & 0xFFFFFFF8);
	proficiencyExtra13 = min(5, proficiencyExtra13 & 0x00000007) | (proficiencyExtra13 & 0xFFFFFFF8);
	proficiencyExtra14 = max(0, proficiencyExtra14 & 0x00000007) | (proficiencyExtra14 & 0xFFFFFFF8);
	proficiencyExtra14 = min(5, proficiencyExtra14 & 0x00000007) | (proficiencyExtra14 & 0xFFFFFFF8);
	proficiencyExtra15 = max(0, proficiencyExtra15 & 0x00000007) | (proficiencyExtra15 & 0xFFFFFFF8);
	proficiencyExtra15 = min(5, proficiencyExtra15 & 0x00000007) | (proficiencyExtra15 & 0xFFFFFFF8);
	proficiencyExtra16 = max(0, proficiencyExtra16 & 0x00000007) | (proficiencyExtra16 & 0xFFFFFFF8);
	proficiencyExtra16 = min(5, proficiencyExtra16 & 0x00000007) | (proficiencyExtra16 & 0xFFFFFFF8);
	proficiencyExtra17 = max(0, proficiencyExtra17 & 0x00000007) | (proficiencyExtra17 & 0xFFFFFFF8);
	proficiencyExtra17 = min(5, proficiencyExtra17 & 0x00000007) | (proficiencyExtra17 & 0xFFFFFFF8);
	proficiencyExtra18 = max(0, proficiencyExtra18 & 0x00000007) | (proficiencyExtra18 & 0xFFFFFFF8);
	proficiencyExtra18 = min(5, proficiencyExtra18 & 0x00000007) | (proficiencyExtra18 & 0xFFFFFFF8);
	proficiencyExtra19 = max(0, proficiencyExtra19 & 0x00000007) | (proficiencyExtra19 & 0xFFFFFFF8);
	proficiencyExtra19 = min(5, proficiencyExtra19 & 0x00000007) | (proficiencyExtra19 & 0xFFFFFFF8);
	proficiencyExtra20 = max(0, proficiencyExtra20 & 0x00000007) | (proficiencyExtra20 & 0xFFFFFFF8);
	proficiencyExtra20 = min(5, proficiencyExtra20 & 0x00000007) | (proficiencyExtra20 & 0xFFFFFFF8);*/

	return (this->*Tramp_CDerivedStats_LimitStats)();
}

int DETOUR_CDerivedStats::DETOUR_GetStat(short nOpcode) {
	if (nOpcode < 201) return (this->*Tramp_CDerivedStats_GetStat)(nOpcode);

	if (nOpcode > 200 && nOpcode <= pRuleEx->m_nStats) {
		if (animationRemoval) {
			int* pStatsEx = (int*)animationRemoval;
			return pStatsEx[nOpcode - 200 - 1];
		} else {
			LPCTSTR lpsz = "DETOUR_CDerivedStats::DETOUR_GetStat(): pStatsEx == NULL\r\n";
			L.timestamp();
			L.append(lpsz);
			console.write(lpsz);
			return 0;
		}
	} else {
		LPCTSTR lpsz = "DETOUR_CDerivedStats::DETOUR_GetStat(): nOpcode out of bounds (%d; expected 1-%d)\r\n";
		L.timestamp();
		L.append(lpsz);
		console.write(lpsz, 2, nOpcode, pRuleEx->m_nStats);
		return 0;
	}
}

void DETOUR_CDerivedStats::DETOUR_MarshalTemplate(CDerivedStatsTemplate** ppcdst, int* pnSize) {
	*pnSize = g_nCDerivedStatsTemplateSize;
	*ppcdst = (CDerivedStatsTemplate*)IENew int[*pnSize];
	memcpy_s(*ppcdst, sizeof(CDerivedStatsTemplate) - 4, this, sizeof(CDerivedStatsTemplate) - 4);

	int* pStatsEx = NULL;
	if (animationRemoval) {
		pStatsEx = (int*)animationRemoval;
		memcpy_s((char*)(*ppcdst) + sizeof(CDerivedStatsTemplate) - 4, g_nCDerivedStatsTemplateSize - sizeof(CDerivedStatsTemplate) + 4, pStatsEx, g_nCDerivedStatsTemplateSize - sizeof(CDerivedStatsTemplate) + 4);
	} else {
		LPCTSTR lpsz = "DETOUR_CDerivedStats::DETOUR_MarshalTemplate(): pStatsEx == NULL\r\n";
		L.timestamp();
		L.append(lpsz);
		console.write(lpsz);
	}

	return;
}

void DETOUR_CDerivedStats::DETOUR_UnmarshalTemplate(CDerivedStatsTemplate& cdst, int nSize) {
	//calling functioning passes sizeof(CDerivedStatsTemplate), no room to change hex so left alone
	/*if (nSize != g_nCDerivedStatsTemplateSize) {
		LPCTSTR lpsz = "DETOUR_CDerivedStats::DETOUR_UnmarshalTemplate(): incorrect CDerivedStatsTemplate size 0x%X (expected 0x%X)\r\n";
		L.timestamp();
		L.append(lpsz, 2, nSize, g_nCDerivedStatsTemplateSize);
		console.write(lpsz, 2, nSize, g_nCDerivedStatsTemplateSize);
	}*/

	int* pStatsEx = NULL;
	if (animationRemoval) {
		pStatsEx = (int*)animationRemoval;
		memcpy_s(pStatsEx, g_nCDerivedStatsTemplateSize - sizeof(CDerivedStatsTemplate) + 4, (char*)&cdst + sizeof(CDerivedStatsTemplate) - 4, g_nCDerivedStatsTemplateSize - sizeof(CDerivedStatsTemplate) + 4);
	} else {
		LPCTSTR lpsz = "DETOUR_CDerivedStats::DETOUR_UnmarshalTemplate(): pStatsEx == NULL\r\n";
		L.timestamp();
		L.append(lpsz);
		console.write(lpsz);
	}

	memcpy_s(this, sizeof(CDerivedStatsTemplate) - 4, &cdst, sizeof(CDerivedStatsTemplate) - 4);

	return;
}

void DETOUR_CDerivedStats::DETOUR_Deconstruct() {
	if (animationRemoval) {
		operator delete((int*)animationRemoval, 0);
		animationRemoval = 0;
	} else {
		LPCTSTR lpsz = "DETOUR_CDerivedStats::DETOUR_Deconstruct(): pStatsEx == NULL\r\n";
		L.timestamp();
		L.append(lpsz);
		console.write(lpsz);
	}

	return (this->*Tramp_CDerivedStats_Deconstruct)();
};

float CDerivedStats_NumAttacksShortToFloat(short s) {
	bool bNegative = s < 0 ? true : false;
	if (bNegative) s = -s;
	float f = (float)s;

	if (f >= 0.0 && f <= 5.0) {
	} else {
		if (f >= 6.0 && f <= 10.0) {
			f -= 5.5;
		} else {
			if (pGameOptionsEx->bDebugVerbose) {
				LPCTSTR lpsz = "CDerivedStats_NumAttacksShortToFloat(): Number of attacks out of range (%d)\r\n";
				console.write(lpsz, 1, s);
				L.timestamp();
				L.append(lpsz, 1, s);
			}
			f = 0.0;
		}
	}

	if (bNegative) f = -f;
	return f;
}

short CDerivedStats_NumAttacksFloatToShort(float f) {
	short s;

	bool bNegative = f < 0.0 ? true : false;
	if (bNegative) f = -f;

	if (f > 5.0) f = 5.0;
	if (f < 0.0) f = 0.0;

	if (f == 0.0 ||
		f == 1.0 ||
		f == 2.0 ||
		f == 3.0 ||
		f == 4.0 ||
		f == 5.0) {
		s = (short)f;
	} else {
		if (f == 0.5 ||
			f == 1.5 ||
			f == 2.5 ||
			f == 3.5 ||
			f == 4.5) {
			s = (short)(f + 5.5);
		} else {
			LPCTSTR lpsz = "CDerivedStats_NumAttacksFloatToShort(): I got a strange number of attacks value (%f)\r\n";
			console.write(lpsz, 1, f);
			L.timestamp();
			L.append(lpsz, 1, f);
			s = 0;
		}
	}

	if (bNegative) s = -s;
	return s;
}

char CDerivedStats_GetEffectiveStrength(char strength, char strengthEx) {
	//convert Str/StrEx to step integer Str
	if (strength > 18)
		return strength + pRuleEx->m_StrModExStepNum;
	else if (strength == 18 && strengthEx > 0)
		return pRuleEx->m_StrModExToStepTable[strengthEx];
	else
		return strength;
}

void CDerivedStats_GetRealStrength(char strengthEffective, char& strength, char& strengthEx) {
	//convert step integer Str to Str/StrEx
	if (strengthEffective > 18 + pRuleEx->m_StrModExStepNum) {
		strength = strengthEffective - pRuleEx->m_StrModExStepNum;
		strengthEx = 100;
	} else if (strengthEffective > 18) {
		strength = 18;
		strengthEx = pRuleEx->m_StepToStrModExTable[strengthEffective - 18 - 1];
	} else {
		strength = strengthEffective;
		strengthEx = 0;
	}

	return;
}

char CDerivedStats_GetEffectiveStrengthSpell(char strength, char strengthEx) {
	//convert Str/StrEx to step integer Str
	if (strength > 18)
		return strength + 10;
	else if (strength == 18)
		return strength + strengthEx / 10;
	else return strength;
}

void CDerivedStats_GetRealStrengthSpell(char strengthEffective, char& strength, char& strengthEx) {
	//convert step integer Str to Str/StrEx
	strengthEx = 0;
	if (strengthEffective >= 29) {
		strength = strengthEffective - 10;
		strengthEx = 100;
	} else if (strengthEffective >= 18) {
		strength = 18;
		strengthEx = (strengthEffective - 18) * 10;
	} else
		strength = strengthEffective;
	return;
}

void CDerivedStats_SetStat(CDerivedStats& cds, short nOpcode, int nValue) {
	DWORD nSize = pRuleEx->m_nStats;

	if (nOpcode < 202) {
		LPCTSTR lpsz = "CDerivedStats_SetStat(): Tried to set a stat with index < 202 (expected 202-%d)\r\n";
		L.timestamp();
		L.append(lpsz, 1, nSize);
		console.write(lpsz, 1, nSize);
		return;
	}

	if (nOpcode > nSize) {
		LPCTSTR lpsz = "CDerivedStats_SetStat(): nOpcode out of bounds (maximum %d)\r\n";
		L.timestamp();
		L.append(lpsz, 1, nSize);
		console.write(lpsz, 1, nSize);
		return;
	}

	if (cds.animationRemoval) {
		int* pStatsEx = (int*)cds.animationRemoval;
		pStatsEx[nOpcode - 200 - 1] = nValue;
	} else {
		LPCTSTR lpsz = "CDerivedStats_SetStat(): cds.pStatsEx == NULL\r\n";
		L.timestamp();
		L.append(lpsz);
		console.write(lpsz);
	}

	return;

}

char CDerivedStats_GetSubclassLevelNoAssertion(CDerivedStats& cds, char nClass, char nSubclass) {
	switch (nClass) {
	case CLASS_MAGE:
	case CLASS_FIGHTER:
	case CLASS_CLERIC:
	case CLASS_THIEF:
	case CLASS_BARD:
	case CLASS_PALADIN:
	case CLASS_DRUID:
	case CLASS_RANGER:
	case CLASS_SORCERER:
	case CLASS_MONK:
		if (nSubclass == nClass) {
			return (char)cds.levelPrimary;
		} else {
			return 0;
		}
		break;
	case CLASS_FIGHTER_MAGE:
		switch (nSubclass) {
		case CLASS_FIGHTER:
			return (char)cds.levelPrimary;
			break;
		case CLASS_MAGE:
			return (char)cds.levelSecondary;
			break;
		default:
			return 0;
			break;
		}
		break;
	case CLASS_FIGHTER_CLERIC:
		switch (nSubclass) {
		case CLASS_FIGHTER:
			return (char)cds.levelPrimary;
			break;
		case CLASS_CLERIC:
			return (char)cds.levelSecondary;
			break;
		default:
			return 0;
			break;
		}
		break;
	case CLASS_FIGHTER_THIEF:
		switch (nSubclass) {
		case CLASS_FIGHTER:
			return (char)cds.levelPrimary;
			break;
		case CLASS_THIEF:
			return (char)cds.levelSecondary;
			break;
		default:
			return 0;
			break;
		}
		break;
	case CLASS_FIGHTER_MAGE_THIEF:
		switch (nSubclass) {
		case CLASS_FIGHTER:
			return (char)cds.levelPrimary;
			break;
		case CLASS_MAGE:
			return (char)cds.levelSecondary;
			break;
		case CLASS_THIEF:
			return (char)cds.levelTertiary;
			break;
		default:
			return 0;
			break;
		}
		break;
	case CLASS_MAGE_THIEF:
		switch (nSubclass) {
		case CLASS_MAGE:
			return (char)cds.levelPrimary;
			break;
		case CLASS_THIEF:
			return (char)cds.levelSecondary;
			break;
		default:
			return 0;
			break;
		}
		break;
	case CLASS_CLERIC_MAGE:
		switch (nSubclass) {
		case CLASS_CLERIC:
			return (char)cds.levelPrimary;
			break;
		case CLASS_MAGE:
			return (char)cds.levelSecondary;
			break;
		default:
			return 0;
			break;
		}
		break;
	case CLASS_CLERIC_THIEF:
		switch (nSubclass) {
		case CLASS_CLERIC:
			return (char)cds.levelPrimary;
			break;
		case CLASS_THIEF:
			return (char)cds.levelSecondary;
			break;
		default:
			return 0;
			break;
		}
		break;
	case CLASS_FIGHTER_DRUID:
		switch (nSubclass) {
		case CLASS_FIGHTER:
			return (char)cds.levelPrimary;
			break;
		case CLASS_DRUID:
			return (char)cds.levelSecondary;
			break;
		default:
			return 0;
			break;
		}
		break;
	case CLASS_FIGHTER_MAGE_CLERIC:
		switch (nSubclass) {
		case CLASS_FIGHTER:
			return (char)cds.levelPrimary;
			break;
		case CLASS_MAGE:
			return (char)cds.levelSecondary;
			break;
		case CLASS_CLERIC:
			return (char)cds.levelTertiary;
			break;
		default:
			return 0;
			break;
		}
		break;
	case CLASS_CLERIC_RANGER:
		switch (nSubclass) {
		case CLASS_CLERIC:
			return (char)cds.levelPrimary;
			break;
		case CLASS_RANGER:
			return (char)cds.levelSecondary;
			break;
		default:
			return 0;
			break;
		}
		break;
	default:
		return 0;
		break;
	}
	return 0;
}

char CDerivedStats_GetEffectiveClericLevelNoAssertion(CDerivedStats& cds, char nClass) {
	switch (nClass) {
	case CLASS_CLERIC:
	case CLASS_DRUID:
		return CDerivedStats_GetSubclassLevelNoAssertion(cds, nClass, nClass);
		break;
	case CLASS_FIGHTER_CLERIC:
	case CLASS_CLERIC_MAGE:
	case CLASS_CLERIC_THIEF:
	case CLASS_FIGHTER_MAGE_CLERIC:
	case CLASS_CLERIC_RANGER:
		return CDerivedStats_GetSubclassLevelNoAssertion(cds, nClass, CLASS_CLERIC);
		break;
	case CLASS_FIGHTER_DRUID:
		return CDerivedStats_GetSubclassLevelNoAssertion(cds, nClass, CLASS_DRUID);
		break;
	case CLASS_RANGER:
		return max(CDerivedStats_GetSubclassLevelNoAssertion(cds, nClass, nClass) - 7, 0);
		break;
	case CLASS_PALADIN:
		return max(CDerivedStats_GetSubclassLevelNoAssertion(cds, nClass, nClass) - 8, 0);
		break;
	default:
		return 0;
		break;
	}
	return 0;
}
