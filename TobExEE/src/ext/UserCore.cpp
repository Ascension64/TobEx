//TobExEE
#include "UserCore.h"

#include "stdafx.h"
#include "p_uicore.h"

#include "optionsext.h"
#include "uicore.h"
#include "uitext.h"

DefineTrampGlobalFuncPtr(CUIControl*, __cdecl, CreateUIControl, (CPanel& panel, ChuFileControlInfoBase& controlInfo), _CREATEUICONTROL);

CUIControl* __cdecl DETOUR_CreateUIControl(CPanel& panel, ChuFileControlInfoBase& controlInfo) {
	CUIControl* pControl = Tramp_CreateUIControl(panel, controlInfo);

	if (pControl) {
		ResRef rManager = panel.m_pManager->m_rName;

		//World
		if (rManager == "GUIW" ||
			rManager == "GUIW08" ||
			rManager == "GUIW09" ||
			rManager == "GUIW10" ||
			rManager == "GUIW12" ||
			rManager == "GUIW13" ||
			rManager == "GUIW16" ||
			rManager == "GUIW20") {
			switch (panel.m_nIndex) {
			case 4: //small log bar
				switch (controlInfo.m_nId) {
				case 3:
					if (pGameOptionsEx->GetOption("User_CustomDlgBarSize")) {
						((CUITextArea*)pControl)->m_wRowsMax = pGameOptionsEx->GetOption("User_CustomDlgBarSize");
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
						((CUITextArea*)pControl)->m_wRowsMax = pGameOptionsEx->GetOption("User_CustomDlgBarSize");
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
						((CUITextArea*)pControl)->m_wRowsMax = pGameOptionsEx->GetOption("User_CustomDlgBarSize");
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
						((CUITextArea*)pControl)->m_wRowsMax = pGameOptionsEx->GetOption("User_CustomDlgBarSize");
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
						((CUITextArea*)pControl)->m_wRowsMax = pGameOptionsEx->GetOption("User_CustomDlgBarSize");
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
						((CUITextArea*)pControl)->m_wRowsMax = pGameOptionsEx->GetOption("User_CustomDlgBarSize");
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
						((CUITextArea*)pControl)->m_wRowsMax = pGameOptionsEx->GetOption("User_CustomDlgBarSize");
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
						((CUITextArea*)pControl)->m_wRowsMax = pGameOptionsEx->GetOption("User_CustomDlgBarSize");
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
						((CUITextArea*)pControl)->m_wRowsMax = pGameOptionsEx->GetOption("User_CustomDlgBarSize");
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
						((CUITextArea*)pControl)->m_wRowsMax = pGameOptionsEx->GetOption("User_CustomDlgBarSize");
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