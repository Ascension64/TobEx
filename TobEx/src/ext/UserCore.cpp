#include "UserCore.h"

#include <cassert>

#include "stdafx.h"
#include "optionsext.h"
#include "UserChargenKit.h"
#include "UserChargenMageSpell.h"
#include "UserRecMageSpell.h"
#include "UserMageBook.h"
#include "UserPriestBook.h"
#include "uicore.h"
#include "uitext.h"

DefineTrampGlobalFuncPtr(CUIControl*, __cdecl, CreateUIControl, (CPanel& panel, ChuFileControlInfoBase& controlInfo), 0x95D5E0);

CUIControl* __cdecl DETOUR_CreateUIControl(CPanel& panel, ChuFileControlInfoBase& controlInfo) {
	CUIControl* pControl = Tramp_CreateUIControl(panel, controlInfo);

	if (pControl == NULL) {
		assert(&controlInfo != NULL);
		ResRef rManager = panel.pManager->name;

		//Chargen
		if (rManager = "GUICG") {
			switch (panel.index) {
			case 7:
				switch (controlInfo.m_nId) {
				case 31:
					if (pGameOptionsEx->GetOption("User_ChargenMageSpellScroll")) {
						pControl = new CUIScrollBarChargenMageSpell(panel, controlInfo);
					}
					break;
				default:
					break;
				}
				break;
			case 22:
				switch (controlInfo.m_nId) {
				case 15:
					if (pGameOptionsEx->GetOption("User_ChargenKitSelectScroll")) {
						pControl = new CUIScrollBarChargenKit(panel, controlInfo);
					}
					break;
				case 16:
					if (pGameOptionsEx->GetOption("User_ChargenKitSelectScroll")) {
						pControl = IENew CUICheckButtonChargenKit(panel, controlInfo);
					}
					break;
				default:
					break;
				}
				break;
			default:
				break;
			}
		}

		//MageBook
		if (rManager = "GUIMG") {
			switch (panel.index) {
			case 2:
				switch (controlInfo.m_nId) {
				case 65:
					if (pGameOptionsEx->GetOption("User_MageBookScroll")) {
						pControl = new CUIButtonMageBookUp(panel, controlInfo);
					}
					break;
				case 66:
					if (pGameOptionsEx->GetOption("User_MageBookScroll")) {
						pControl = new CUIButtonMageBookDn(panel, controlInfo);
					}
					break;
				default:
					break;
				}
				break;
			default:
				break;
			}
		}

		//PriestBook
		if (rManager = "GUIPR") {
			switch (panel.index) {
			case 2:
				switch (controlInfo.m_nId) {
				case 62:
					if (pGameOptionsEx->GetOption("User_PriestBookScroll")) {
						pControl = new CUIButtonPriestBookUp(panel, controlInfo);
					}
					break;
				case 63:
					if (pGameOptionsEx->GetOption("User_PriestBookScroll")) {
						pControl = new CUIButtonPriestBookDn(panel, controlInfo);
					}
					break;
				default:
					break;
				}
				break;
			default:
				break;
			}
		}

		//Record
		if (rManager = "GUIREC") {
			switch (panel.index) {
			case 8:
				switch (controlInfo.m_nId) {
				case 24:
					if (pGameOptionsEx->GetOption("User_RecordMageSpellScroll")) {
						pControl = IENew CUICheckButtonRecMageSpell(panel, controlInfo);
					}
					break;
				case 30:
					if (pGameOptionsEx->GetOption("User_RecordMageSpellScroll")) {
						pControl = new CUIScrollBarRecMageSpell(panel, controlInfo);
					}
					break;
				default:
					break;
				}
				break;
			default:
				break;
			}
		}

	} else {
		assert(&controlInfo != NULL);
		ResRef rManager = panel.pManager->name;

		//World
		if (rManager == "GUIW" ||
			rManager == "GUIW08" ||
			rManager == "GUIW10" ||
			rManager == "GUIW12" ||
			rManager == "GUIW16" ||
			rManager == "GUIW20") {
			switch (panel.index) {
			case 4: //small log bar
				switch (controlInfo.m_nId) {
				case 3:
					if (pGameOptionsEx->GetOption("User_CustomDlgBarSize")) {
						((CUITextArea*)pControl)->wRowsMax = pGameOptionsEx->GetOption("User_CustomDlgBarSize");
					}
					break;
				default:
					break;
				}
				break;
			case 7: //large log bar
				switch (controlInfo.m_nId) {
				case 1:
					if (pGameOptionsEx->GetOption("User_CustomDlgBarSize")) {
						((CUITextArea*)pControl)->wRowsMax = pGameOptionsEx->GetOption("User_CustomDlgBarSize");
					}
					break;
				default:
					break;
				}
				break;
			case 12: //medium log bar
				switch (controlInfo.m_nId) {
				case 1:
					if (pGameOptionsEx->GetOption("User_CustomDlgBarSize")) {
						((CUITextArea*)pControl)->wRowsMax = pGameOptionsEx->GetOption("User_CustomDlgBarSize");
					}
					break;
				default:
					break;
				}
				break;
			case 13: //dialog3
				switch (controlInfo.m_nId) {
				case 1:
					if (pGameOptionsEx->GetOption("User_CustomDlgBarSize")) {
						((CUITextArea*)pControl)->wRowsMax = pGameOptionsEx->GetOption("User_CustomDlgBarSize");
					}
					break;
				default:
					break;
				}
				break;
			case 14: //dialog2
				switch (controlInfo.m_nId) {
				case 1:
					if (pGameOptionsEx->GetOption("User_CustomDlgBarSize")) {
						((CUITextArea*)pControl)->wRowsMax = pGameOptionsEx->GetOption("User_CustomDlgBarSize");
					}
					break;
				default:
					break;
				}
				break;
			case 18: //large log bar (MP)/dialogue panel (MP)
				switch (controlInfo.m_nId) {
				case 1:
					if (pGameOptionsEx->GetOption("User_CustomDlgBarSize")) {
						((CUITextArea*)pControl)->wRowsMax = pGameOptionsEx->GetOption("User_CustomDlgBarSize");
					}
					break;
				default:
					break;
				}
				break;
			case 22: //medium log bar (MP)
				switch (controlInfo.m_nId) {
				case 1:
					if (pGameOptionsEx->GetOption("User_CustomDlgBarSize")) {
						((CUITextArea*)pControl)->wRowsMax = pGameOptionsEx->GetOption("User_CustomDlgBarSize");
					}
					break;
				default:
					break;
				}
				break;
			case 29: //dialog panel
				switch (controlInfo.m_nId) {
				case 1:
					if (pGameOptionsEx->GetOption("User_CustomDlgBarSize")) {
						((CUITextArea*)pControl)->wRowsMax = pGameOptionsEx->GetOption("User_CustomDlgBarSize");
					}
					break;
				default:
					break;
				}
				break;
			case 30: //dialog3 (MP)
				switch (controlInfo.m_nId) {
				case 1:
					if (pGameOptionsEx->GetOption("User_CustomDlgBarSize")) {
						((CUITextArea*)pControl)->wRowsMax = pGameOptionsEx->GetOption("User_CustomDlgBarSize");
					}
					break;
				default:
					break;
				}
				break;
			case 31: //dialog2 (MP)
				switch (controlInfo.m_nId) {
				case 1:
					if (pGameOptionsEx->GetOption("User_CustomDlgBarSize")) {
						((CUITextArea*)pControl)->wRowsMax = pGameOptionsEx->GetOption("User_CustomDlgBarSize");
					}
					break;
				default:
					break;
				}
				break;
			default:
				break;
			}
		}

	}



	return pControl;
}