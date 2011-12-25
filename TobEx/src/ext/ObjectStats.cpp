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
int (CDerivedStats::*Tramp_CDerivedStats_GetStat)(short) =
	SetFP(static_cast<int (CDerivedStats::*)(short)>						(&CDerivedStats::GetStat),					0x473162);
void (CDerivedStats::*Tramp_CDerivedStats_MarshalTemplate)(CDerivedStatsTemplate*, int*) =
	SetFP(static_cast<void (CDerivedStats::*)(CDerivedStatsTemplate*, int*)>(&CDerivedStats::MarshalTemplate),			0x474AAE);
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

int DETOUR_CDerivedStats::DETOUR_GetStat(short nOpcode) {
	if (nOpcode < 201) return (this->*Tramp_CDerivedStats_GetStat)(nOpcode);

	if (nOpcode > 200 && nOpcode <= pRuleEx->m_nStats) {
		if (animationRemoval) {
			int* pStatsEx = (int*)animationRemoval;
			if (pGameOptionsEx->bDebugVerbose && nOpcode > 201) {
				LPCTSTR lpsz = "DETOUR_CDerivedStats::DETOUR_GetStat(): stat %d = %d\r\n";
				L.timestamp();
				L.append(lpsz, 2, nOpcode, pStatsEx[nOpcode - 200 - 1]);
				console.write(lpsz, 2, nOpcode, pStatsEx[nOpcode - 200 - 1]);
			}
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

void DETOUR_CDerivedStats::DETOUR_MarshalTemplate(CDerivedStatsTemplate* pcdst, int* pnSize) {
	DWORD size = pRuleEx->m_nStats - 200;

	(this->*Tramp_CDerivedStats_MarshalTemplate)(pcdst, pnSize);

	int* pStatsEx = NULL;
	if (animationRemoval) {
		pStatsEx = (int*)animationRemoval;
		pcdst->animationRemoval = pStatsEx[0];
	} else {
		LPCTSTR lpsz = "DETOUR_CDerivedStats::DETOUR_MarshalTemplate(): pStatsEx == NULL\r\n";
		L.timestamp();
		L.append(lpsz);
		console.write(lpsz);
	}

	return;
}

void DETOUR_CDerivedStats::DETOUR_UnmarshalTemplate(CDerivedStatsTemplate& cdst, int nSize) {
	DWORD size = pRuleEx->m_nStats - 200;

	int* pStatsEx = NULL;
	if (animationRemoval) {
		pStatsEx = (int*)animationRemoval;
		pStatsEx[0] = cdst.animationRemoval;
	} else {
		LPCTSTR lpsz = "DETOUR_CDerivedStats::DETOUR_UnmarshalTemplate(): pStatsEx == NULL\r\n";
		L.timestamp();
		L.append(lpsz);
		console.write(lpsz);
	}

	(this->*Tramp_CDerivedStats_UnmarshalTemplate)(cdst, nSize);

	animationRemoval = (int)pStatsEx;

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
	//Map strength-strengthEx into a 0-30 combined strength
	if (strength > 18)
		return strength + 5;
	else if (strength == 18) {
		if (strengthEx >= 100)
			return 23;
		else if (strengthEx >= 91)
			return 22;
		else if (strengthEx >= 76)
			return 21;
		else if (strengthEx >= 51)
			return 20;
		else if (strengthEx > 0)
			return 19;
		else return 18;
	} else 
	return strength;
}

void CDerivedStats_GetRealStrength(char strengthEffective, char& strength, char& strengthEx) {
	//Map 0-30 combined strength back to strength-strengthEx
	strengthEx = 0;
	if (strengthEffective >= 24) {
		strength = strengthEffective - 5;
		strengthEx = 100;
	} else if (strengthEffective >= 18) {
		strength = 18;
		switch (strengthEffective) {
			case 23:
				strengthEx = 100;
				break;
			case 22:
				strengthEx = 91;
				break;
			case 21:
				strengthEx = 76;
				break;
			case 20:
				strengthEx = 51;
				break;
			case 19:
				strengthEx = 1;
				break;
			case 18:
				strengthEx = 0;
		}
	} else
		strength = strengthEffective;
	return;
}

char CDerivedStats_GetEffectiveStrengthSpell(char strength, char strengthEx) {
	//Map strength-strengthEx into a 0-30 combined strength
	if (strength > 18)
		return strength + 10;
	else if (strength == 18)
		return strength + strengthEx / 10;
	else return strength;
}

void CDerivedStats_GetRealStrengthSpell(char strengthEffective, char& strength, char& strengthEx) {
	//Map 0-30 combined strength back to strength-strengthEx
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
