#include "EngineMageBook.h"

#include "chitin.h"
#include "UserMageBook.h"

void (CMageBook::*Tramp_CMageBook_SetLevel)(int) =
	SetFP(static_cast<void (CMageBook::*)(int)>				(&CMageBook::SetLevel),						0x7B7BDC);
void (CMageBook::*Tramp_CMageBook_ContingencySelectOnLoad)(CPanel&) =
	SetFP(static_cast<void (CMageBook::*)(CPanel&)>			(&CMageBook::ContingencySelectOnLoad),		0x7BA23B);
void (CMageBook::*Tramp_CMageBook_ContingencySelectOnUpdate)(int) =
	SetFP(static_cast<void (CMageBook::*)(int)>				(&CMageBook::ContingencySelectOnUpdate),	0x7BAC41);
bool (CMageBook::*Tramp_CMageBook_ClearContingencySpell)(char index) =
	SetFP(static_cast<bool (CMageBook::*)(char)>			(&CMageBook::ClearContingencySpell),		0x7BD516);
void (CMageBook::*Tramp_CMageBook_CreateContingencySpellList)(char, char) =
	SetFP(static_cast<void (CMageBook::*)(char, char)>		(&CMageBook::CreateContingencySpellList),	0x7BDCB1);

MemSpellContingency::MemSpellContingency() {
	wMemorizedCount = 0;
	ua = 0;
}

void DETOUR_CMageBook::DETOUR_SetLevel(int nLevel) {
	if (0) IECString("DETOUR_CMageBook::DETOUR_SetLevel");

	CUIButtonMageBook_KnownSpellOffset = 0;
	(this->*Tramp_CMageBook_SetLevel)(nLevel);
	return;
}

void DETOUR_CMageBook::DETOUR_ContingencySelectOnLoad(CPanel& panel) {
	if (0) IECString("DETOUR_CMageBook::DETOUR_ContingencySelectOnLoad");

	DETOUR_CUICheckButtonMageBookContSelected& spell1 = (DETOUR_CUICheckButtonMageBookContSelected&)panel.GetUIControl(22);
	DETOUR_CUICheckButtonMageBookContSelected& spell2 = (DETOUR_CUICheckButtonMageBookContSelected&)panel.GetUIControl(23);
	DETOUR_CUICheckButtonMageBookContSelected& spell3 = (DETOUR_CUICheckButtonMageBookContSelected&)panel.GetUIControl(24);
	assert(&spell1 != NULL);
	assert(&spell2 != NULL);
	assert(&spell3 != NULL);
	spell1.rParentSpell = "";
	spell2.rParentSpell = "";
	spell3.rParentSpell = "";
	return (this->*Tramp_CMageBook_ContingencySelectOnLoad)(panel);
}

void DETOUR_CMageBook::DETOUR_ContingencySelectOnUpdate(int nPanelIdx) {
	if (0) IECString("DETOUR_CMageBook::DETOUR_ContingencySelectOnUpdate");

	CPanel& panel = GetManager().GetPanel(nPanelIdx);
	pScrollActive = (CUIScrollBar*)&panel.GetUIControl(26);
	short wScrollIdx = 0;
	CInfGame* pGame = g_pChitin->pGame;
	short wPlayerIdx = (short)nActivePlayerIdx;
	Enum eChar = wPlayerIdx < pGame->numInParty ? pGame->ePlayersPartyOrder[wPlayerIdx] : ENUM_INVALID_INDEX;

	if (m_wContType == 2) {
		panel.GetUIControl(4).SetEnabled(false);
		panel.GetUIControl(4).SetVisible(false);
		panel.GetUIControl(6).SetEnabled(false);
		panel.GetUIControl(6).SetVisible(false);
		panel.GetUIControl(5).SetEnabled(false);
		panel.GetUIControl(5).SetVisible(false);
		panel.GetUIControl(7).SetEnabled(false);
		panel.GetUIControl(7).SetVisible(false);
		panel.GetUIControl(0x10000000).SetEnabled(false);
		panel.GetUIControl(0x10000000).SetVisible(false);
		panel.GetUIControl(0x10000001).SetEnabled(false);
		panel.GetUIControl(0x10000001).SetVisible(false);
	}

	CCreatureObject* pCre = NULL;
	char threadVal;
	do {
		threadVal = g_pChitin->pGame->m_GameObjectArrayHandler.GetGameObjectShare(eChar, THREAD_ASYNCH, &pCre, INFINITE);
	} while (threadVal == OBJECT_SHARING || threadVal == OBJECT_DENYING);

	if (threadVal == OBJECT_SUCCESS) {
		char bUpdateSpellList = false;
		char nSpellType = (char)m_nContSpellType;
		if (nSpellType == 0) { //mage
			
			while (
				(
					(
						((pCre->GetCurrentObject().HasActiveSubclass(CLASS_MAGE, TRUE) || pCre->GetCurrentObject().HasActiveSubclass(CLASS_BARD, TRUE)) &&
							pCre->m_MemInfoWizard[m_nCurrContSpellLevel]->nNumSpells == 0) ||
						(pCre->GetCurrentObject().HasActiveSubclass(CLASS_SORCERER, TRUE) && pCre->GetNumUniqueMemSpellMage(m_nCurrContSpellLevel + 1, ResRef()) == 0)	
					) &&
					m_nCurrContSpellLevel > 0
				) ||
				m_nCurrContSpellLevel >= m_nContNumSpellLevels ||
				m_nCurrContSpellLevel >= 9
				) {
					m_nCurrContSpellLevel = max(m_nCurrContSpellLevel - 1, 0);
					bUpdateSpellList = true;
				}
		} else { //priest
			while (
				(pCre->m_MemInfoPriest[m_nCurrContSpellLevel]->nNumSpells == 0 && m_nCurrContSpellLevel > 0) ||
				m_nCurrContSpellLevel >= m_nContNumSpellLevels ||
				m_nCurrContSpellLevel >= 7) {
				m_nCurrContSpellLevel = max(m_nCurrContSpellLevel - 1, 0);
				bUpdateSpellList = true;
			}
		}

		if (bUpdateSpellList) {
			UpdateContingencySpellList();
		}

		int nSpells = m_ContSpells.GetCount();
		int nFirstChoiceIdx;
		if (m_wContScrollIdx == 0) {
			nFirstChoiceIdx = 11;
		} else {
			nFirstChoiceIdx = 12;
			CUICheckButtonMageBookContChoice& button = (CUICheckButtonMageBookContChoice&)panel.GetUIControl(11);
			button.SetSpell(ResRef(), 1);
			button.SetArrowIcon(1);
			button.SetActive(TRUE);
		}

		if (m_wContScrollIdx >= nSpells - (21 - nFirstChoiceIdx)) {
			wScrollIdx = max(nSpells - (21 - nFirstChoiceIdx) - 1, 0);
			m_wContScrollIdx = wScrollIdx;
		} else {
			wScrollIdx = m_wContScrollIdx;
		}

		int nLastChoiceIdx;
		if (nSpells - m_wContScrollIdx > (21 - nFirstChoiceIdx) + 1) {
			nLastChoiceIdx = 20;
			CUICheckButtonMageBookContChoice& button = (CUICheckButtonMageBookContChoice&)panel.GetUIControl(21);
			button.SetSpell(ResRef(), 1);
			button.SetArrowIcon(0);
			button.SetActive(TRUE);
		} else {
			nLastChoiceIdx = 21;
		}

		POSITION pos = m_ContSpells.GetHeadPosition();
		for (int i = 0; i < wScrollIdx; i++) {
			m_ContSpells.GetNext(pos);
			if (pos == NULL) break;
		}
		while (nFirstChoiceIdx <= nLastChoiceIdx) {
			DETOUR_CUICheckButtonMageBookContChoice& button = (DETOUR_CUICheckButtonMageBookContChoice&)panel.GetUIControl(nFirstChoiceIdx);
			assert(&button != NULL);
			if (pos != NULL) {
				MemSpellContingency* pMemSpell = (MemSpellContingency*)m_ContSpells.GetNext(pos);
				button.SetSpell(ResRef((LPCTSTR)pMemSpell->rName), pMemSpell->wMemorizedCount);
				button.rParentSpell = pMemSpell->rParentSpell;
				button.SetActive(TRUE);
			} else {
				button.SetSpell(ResRef(), 1);
				button.rParentSpell = "";
				button.SetActive(FALSE);
			}
			nFirstChoiceIdx++;
		}

		CUICheckButtonMageBookContSelected& spell1 = (CUICheckButtonMageBookContSelected&)panel.GetUIControl(22);
		CUICheckButtonMageBookContSelected& spell2 = (CUICheckButtonMageBookContSelected&)panel.GetUIControl(23);
		CUICheckButtonMageBookContSelected& spell3 = (CUICheckButtonMageBookContSelected&)panel.GetUIControl(24);
		assert(&spell1 != NULL);
		assert(&spell2 != NULL);
		assert(&spell3 != NULL);

		switch (m_nMaxContSpells) {
		case 1:
			spell1.SetActive(TRUE);
			spell2.SetActive(FALSE);
			spell3.SetActive(FALSE);
			spell1.SetEnabled(true);
			spell2.SetEnabled(false);
			spell3.SetEnabled(false);
			spell1.SetVisible(true);
			spell2.SetVisible(false);
			spell3.SetVisible(false);
			break;
		case 2:
			spell1.SetActive(TRUE);
			spell2.SetActive(TRUE);
			spell3.SetActive(FALSE);
			spell1.SetEnabled(true);
			spell2.SetEnabled(true);
			spell3.SetEnabled(false);
			spell1.SetVisible(true);
			spell2.SetVisible(true);
			spell3.SetVisible(false);
			break;
		case 3:
			spell1.SetActive(TRUE);
			spell2.SetActive(TRUE);
			spell3.SetActive(TRUE);
			spell1.SetEnabled(true);
			spell2.SetEnabled(true);
			spell3.SetEnabled(true);
			spell1.SetVisible(true);
			spell2.SetVisible(true);
			spell3.SetVisible(true);
			break;
		default:
			LPCTSTR lpsz = "DETOUR_CMageBook::DETOUR_ContingencySelectOnUpdate: invalid m_nMaxContSpells\r\n";
			L.timestamp();
			L.append(lpsz);
			console.write(lpsz);
			break;
		}

		spell1.SetSpell(m_rContSpell1);
		spell2.SetSpell(m_rContSpell2);
		spell3.SetSpell(m_rContSpell3);

		//FIX_ME - do not use itoa
		char szLevelNum[3] = {0};
		itoa(m_nCurrContSpellLevel + 1, szLevelNum, 10);
		IECString sLevelNum(szLevelNum);
		IECString sLevel("LEVEL");
		g_pChitin->m_TlkTbl.m_StringMap[(LPCTSTR)sLevel] = (LPCTSTR)sLevelNum;
		FormatLabel(*this, panel, 0x1000001D, "%s", (void*)(LPCTSTR)GetTlkString(0x2F69));

		CUIButton& buttonDone = (CUIButton&)panel.GetUIControl(27);
		buttonDone.SetActive(CanContinue());

		CUICheckButtonMageBookContSwitch& buttonSwitchClass = (CUICheckButtonMageBookContSwitch&)panel.GetUIControl(8);
		if (m_nContSpellType != 0) { //currently priest
			buttonSwitchClass.SetText(GetTlkString(0x4677)); //mage
			FormatLabel(*this, panel, 0x10000002, "%s", (void*)(LPCTSTR)GetTlkString(0xD450));
		} else { //currently mage
			buttonSwitchClass.SetText(GetTlkString(0x1C24)); //priest
			FormatLabel(*this, panel, 0x10000002, "%s", (void*)(LPCTSTR)GetTlkString(0x554C));
		}

		threadVal = g_pChitin->pGame->m_GameObjectArrayHandler.FreeGameObjectShare(eChar, THREAD_ASYNCH, INFINITE);
		panel.Redraw(NULL);
	}

	return;

};

bool DETOUR_CMageBook::DETOUR_ClearContingencySpell(char index) {
	switch (index) {
	case 0:
		if (m_rContSpell1.IsNotEmpty()) m_rContSpell1 = "";
		((DETOUR_CUICheckButtonMageBookContSelected&)GetTopPanel().GetUIControl(22)).rParentSpell = "";
		return true;
		break;
	case 1:
		if (m_rContSpell2.IsNotEmpty()) m_rContSpell2 =  "";
		((DETOUR_CUICheckButtonMageBookContSelected&)GetTopPanel().GetUIControl(23)).rParentSpell = "";
		return true;
		break;
	case 2:
		if (m_rContSpell3.IsNotEmpty()) m_rContSpell3 =  "";
		((DETOUR_CUICheckButtonMageBookContSelected&)GetTopPanel().GetUIControl(24)).rParentSpell = "";
		return true;
		break;
	default:
		LPCTSTR lpsz = "DETOUR_CMageBook::DETOUR_ClearContingencySpell(): invalid contingency spell index\r\n";
		L.timestamp();
		L.append(lpsz);
		console.write(lpsz);
		break;
	}

	return false;
}

void DETOUR_CMageBook::DETOUR_CreateContingencySpellList(char nSpellType, char nLevel) {
	m_ContSpells.RemoveAll();
	CInfGame* pGame = g_pChitin->pGame;
	short wPlayerIdx = (short)nActivePlayerIdx;

	Enum eChar = wPlayerIdx < pGame->numInParty ? pGame->ePlayersPartyOrder[wPlayerIdx] : ENUM_INVALID_INDEX;
	CCreatureObject* pCre = NULL;
	char threadVal;
	do {
		threadVal = g_pChitin->pGame->m_GameObjectArrayHandler.GetGameObjectShare(eChar, THREAD_ASYNCH, &pCre, INFINITE);
	} while (threadVal == OBJECT_SHARING || threadVal == OBJECT_DENYING);

	if (threadVal == OBJECT_SUCCESS) {
		short idx = 0;
		CreFileMemSpell* pMemSpell = NULL;
		do {
			pMemSpell = &(nSpellType ? pCre->GetMemSpellPriest(nLevel, idx) : pCre->GetMemSpellMage(nLevel, idx));
			if (pMemSpell &&
				pMemSpell->wFlags & CREMEMSPELL_MEMORIZED) {

				ResRef rSpellList;
				BOOL bUseChildSpells = FALSE;
				CRuleTable ruleSpells;
				SplFileAbility* pAbility = NULL;
				int nAbilityIdx = 0;

				ResSplContainer resSpell = ResSplContainer(pMemSpell->name);
				resSpell.Demand();
				short wSpellCastingLevel = pCre->GetSpellCastingLevel(resSpell, TRUE);
				for (nAbilityIdx = 0; nAbilityIdx < resSpell.GetNumAbilities(); nAbilityIdx++) {
					if (resSpell.GetSpellAbility(nAbilityIdx).wMinLevel > wSpellCastingLevel) break;
					pAbility = &resSpell.GetSpellAbility(nAbilityIdx);
				}
				nAbilityIdx--;

				if (pAbility) { //the ability that would be used if casting now
					for (int i = 0; i < pAbility->wNumEffects; i++) {
						CEffect* pEff = &resSpell.GetAbilityEffect(nAbilityIdx, i, *pCre);
						if (pEff->effect.nOpcode == CEFFECT_OPCODE_USE_EFF_FILE) {
							Object o = pCre->o;
							Object oCriteria;
							BOOL bMatches = FALSE;
							switch (pEff->effect.nParam2) {
							case 2: //EA
								oCriteria.EnemyAlly = pEff->effect.nParam1;
								if (o.MatchCriteria(oCriteria, FALSE, FALSE, FALSE)) {
									bMatches = TRUE;
								}
								break;
							case 3: //General
								if (o.General == pEff->effect.nParam1 ||
									pEff->effect.nParam1 == GENDER_ANY)
									bMatches = TRUE;
								break;
							case 4: //Race
								if (o.Race == pEff->effect.nParam1 ||
									pEff->effect.nParam1 == RACE_ANY)
									bMatches = TRUE;
								break;
							case 5: //Class
								{
									unsigned char nClass = o.Class;
									unsigned char nClassNew;
									unsigned char nClassOrg;
									o.GetDualClasses(&nClassNew, &nClassOrg);
									if (nClassNew != nClassOrg || //dual-classed
										!o.HasActiveSubclass(nClassOrg, TRUE)) { //original class inactive
										nClass = nClassNew; //new class only
									}
									if (nClass == pEff->effect.nParam1 ||
										pEff->effect.nParam1 == CLASS_ANY)
										bMatches = TRUE;
								}
								break;
							case 6: //Specific
								if (o.Specific == pEff->effect.nParam1 ||
									pEff->effect.nParam1 == SPECIFIC_ANY)
									bMatches = TRUE;
								break;
							case 7: //Gender
								if (o.Gender == pEff->effect.nParam1 ||
									pEff->effect.nParam1 == GENDER_ANY)
									bMatches = TRUE;
								break;
							case 8: //Align
								if (o.Alignment == pEff->effect.nParam1 ||
									pEff->effect.nParam1 == ALIGN_ANY)
									bMatches = TRUE;
								if (pEff->effect.nParam1 == ALIGN_MASK_GOOD &&
									o.Alignment & 0xF == ALIGN_MASK_GOOD)
									bMatches = TRUE;
								if (pEff->effect.nParam1 == ALIGN_MASK_NEUTRAL &&
									o.Alignment & 0xF == ALIGN_MASK_NEUTRAL)
									bMatches = TRUE;
								if (pEff->effect.nParam1 == ALIGN_MASK_EVIL &&
									o.Alignment & 0xF == ALIGN_MASK_EVIL)
									bMatches = TRUE;
								if (pEff->effect.nParam1 == ALIGN_LAWFUL_MASK &&
									o.Alignment & 0xF == ALIGN_LAWFUL_MASK)
									bMatches = TRUE;
								if (pEff->effect.nParam1 == ALIGN_NEUTRAL_MASK &&
									o.Alignment & 0xF == ALIGN_NEUTRAL_MASK)
									bMatches = TRUE;
								if (pEff->effect.nParam1 == ALIGN_CHAOTIC_MASK &&
									o.Alignment & 0xF == ALIGN_CHAOTIC_MASK)
									bMatches = TRUE;
								break;
							default:
								break;
							}

							if (bMatches) {
								ResEffContainer resEff(pEff->effect.rResource);
								CEffect& effFile = resEff.CreateCEffect();
								effFile.effect.ptSource = pEff->effect.ptSource;
								effFile.eSource = pEff->eSource;
								effFile.enum2 = pEff->enum2;
								effFile.effect.ptDest = pEff->effect.ptDest;
								effFile.effect.nDuration = pEff->effect.nDuration;
								effFile.effect.nTiming = pEff->effect.nTiming & 0xFFFF;

								if (effFile.effect.nOpcode == CEFFECT_OPCODE_CAST_SPELL_FROM_LIST &&
									effFile.effect.nParam2 == 0) { //all spells
									rSpellList = effFile.effect.rResource;
								}
							}
						}

						if (pEff->effect.nOpcode == CEFFECT_OPCODE_CAST_SPELL_FROM_LIST &&
							pEff->effect.nParam2 == 0) { //all spells
							rSpellList = pEff->effect.rResource;
						}
					}
				}
				resSpell.Release();

				if (rSpellList.IsNotEmpty()) {
					ruleSpells.LoadTable(rSpellList);
					if (ruleSpells.m_2da.bLoaded) {
						bUseChildSpells = TRUE;
					}
				}

				if (bUseChildSpells) {
					for (int row = 0; row < ruleSpells.nRows; row++) {
						int col = 0;
						IECString sChildSpell;

						if (col < ruleSpells.nCols &&
							row < ruleSpells.nRows &&
							col >= 0 &&
							row >= 0) {
							sChildSpell = *((ruleSpells.pDataArray) + (ruleSpells.nCols * row + col));
						} else {
							sChildSpell = ruleSpells.defaultVal;
						}

						if (sChildSpell.Compare((LPCTSTR)ruleSpells.defaultVal)) {
							MemSpellContingency* pMemSpellCont = NULL;
							POSITION pos = m_ContSpells.GetHeadPosition();
							while (pos != NULL) {
								pMemSpellCont = (MemSpellContingency*)m_ContSpells.GetAt(pos);
								if (!strcmpi(pMemSpellCont->rName, (LPCTSTR)sChildSpell) &&
									!strcmpi(pMemSpellCont->rParentSpell, pMemSpell->name))
									break;
								m_ContSpells.GetNext(pos);
							}
							if (pos) {
								//found
								pMemSpellCont->wMemorizedCount++;
							} else {
								//not found
								if (IsSpellAllowedInContingency(nLevel, IECString(sChildSpell)) &&
									IsSpellAllowedInContingency(nLevel, IECString(pMemSpell->name))
								) {
									MemSpellContingency* pMemSpellContNew = IENew MemSpellContingency();
									pMemSpellContNew->rName = sChildSpell;
									pMemSpellContNew->wMemorizedCount = 1;
									pMemSpellContNew->rParentSpell = pMemSpell->name;
									m_ContSpells.AddTail(pMemSpellContNew);
								}
							}
						}

					}
				} else {
					MemSpellContingency* pMemSpellCont = NULL;
					POSITION pos = m_ContSpells.GetHeadPosition();
					while (pos != NULL) {
						pMemSpellCont = (MemSpellContingency*)m_ContSpells.GetAt(pos);
						if (!strcmpi(pMemSpellCont->rName, pMemSpell->name)) break;
						m_ContSpells.GetNext(pos);
					}
					if (pos) {
						//found
						pMemSpellCont->wMemorizedCount++;
					} else {
						//not found
						if (IsSpellAllowedInContingency(nLevel, IECString(pMemSpell->name))) {
							MemSpellContingency* pMemSpellContNew = IENew MemSpellContingency();
							pMemSpellContNew->rName = pMemSpell->name;
							pMemSpellContNew->wMemorizedCount = 1;
							m_ContSpells.AddTail(pMemSpellContNew);
						}
					}
				}
			}
			idx++;
		} while (pMemSpell != NULL);

		threadVal =  g_pChitin->pGame->m_GameObjectArrayHandler.FreeGameObjectShare(eChar, THREAD_ASYNCH, INFINITE);
	}

	return;
}
