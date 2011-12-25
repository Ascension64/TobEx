#include "ObjectStats.h"

#include "chitin.h"

void (CConditionalSpellList::*Tramp_CConditionalSpellList_EvaluateTriggers)(CCreatureObject&) =
	SetFP(static_cast<void (CConditionalSpellList::*)(CCreatureObject&)>	(&CConditionalSpellList::EvaluateTriggers),	0x46BE04);
CDerivedStats& (CDerivedStats::*Tramp_CDerivedStats_OpAdd)(CDerivedStats&) =
	SetFP(static_cast<CDerivedStats& (CDerivedStats::*)(CDerivedStats&)>	(&CDerivedStats::OpAdd),	0x470945);

void DETOUR_CConditionalSpellList::DETOUR_EvaluateTriggers(CCreatureObject& cre) {
	Object o = Object();
	if (cre.m_nContingencyDelay > 0) return;
	if (g_pChitin->pGame->m_GameSave.mode == 0x1016E || //CutSceneMode
		g_pChitin->pGame->m_GameSave.mode == 0x3016E) //CutSceneLite
		return;

	if (pGameOptionsEx->nEngineContingencyTriggerDelay > 0) {
		cre.m_nContingencyDelay = pGameOptionsEx->nEngineContingencyTriggerDelay;
	} else {
		cre.m_nContingencyDelay = 100;
	}
	
	POSITION pos = this->GetHeadPosition();
	POSITION posPrev = pos;
	while (pos != NULL) {
		CConditionalSpell* pccs = (CConditionalSpell*)(this->GetNext(pos));
		pccs->eff.effect.nParam3--;
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
					pcmDD->rgbOwner = cre.m_BaseStats.colors.colorMajor;
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
	
	posPrev = pos;

	}

	return;
}

CDerivedStats& DETOUR_CDerivedStats::DETOUR_OpAdd(CDerivedStats& cds) {
	if (pGameOptionsEx->bEffAttacksPerRoundFix) {
		float fNumAttacks = CDerivedStats_NumAttacksShortToFloat(numAttacks) + CDerivedStats_NumAttacksShortToFloat(cds.numAttacks);
		numAttacks = CDerivedStats_NumAttacksFloatToShort(fNumAttacks);
		cds.numAttacks = 0;
		numAttacks = CDerivedStats_NumAttacksFloatToShort(fNumAttacks);
	}

	return (this->*Tramp_CDerivedStats_OpAdd)(cds);
}

float CDerivedStats_NumAttacksShortToFloat(short s) {
	bool bNegative = s < 0 ? true : false;
	if (bNegative) s = -s;
	float f = (float)s;

	if (f >= 0.0 && f <= 5.0) {
	} else {
		if (f >= 6.0 && f <= 10.0) {
			f -= 5.5;
		} else {
			LPCTSTR lpsz = "CDerivedStats_NumAttacksShortToFloat(): Number of attacks out of range (%d)\r\n";
			console.write(lpsz, 1, s);
			L.timestamp();
			L.append(lpsz, 1, s);
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