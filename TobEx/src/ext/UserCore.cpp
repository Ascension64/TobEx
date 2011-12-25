#include "UserCore.h"

#include <cassert>

#include "stdafx.h"
#include "options.h"
#include "UserChargenKit.h"
#include "UserChargenMageSpell.h"
#include "UserRecMageSpell.h"
#include "UserMageBook.h"
#include "UserPriestBook.h"
#include "uicore.h"
#include "console.h"

CUIControl* (__cdecl *Tramp_CreateUIControl)(CPanel&, ChuFileControlInfoBase&) =
	reinterpret_cast<CUIControl* (__cdecl *)(CPanel&, ChuFileControlInfoBase&)>	(0x95D5E0);

CUIControl* __cdecl DETOUR_CreateUIControl(CPanel& panel, ChuFileControlInfoBase& controlInfo) {
	CUIControl* pControl = Tramp_CreateUIControl(panel, controlInfo);

	if (pControl == NULL) {
		assert(&controlInfo != NULL);
		ResRef rManager = panel.pManager->name;

		//Chargen
		if (rManager = "GUICG") {
			switch (panel.index) {
			case 7:
				switch (controlInfo.id) {
				case 31:
					if (pGameOptionsEx->bUserChargenMageSpellScroll) {
						pControl = new CUIScrollBarChargenMageSpell(panel, controlInfo);
					}
					break;
				default:
					break;
				}
				break;
			case 22:
				switch (controlInfo.id) {
				case 15:
					if (pGameOptionsEx->bUserChargenKitSelectScroll) {
						pControl = new CUIScrollBarChargenKit(panel, controlInfo);
					}
					break;
				case 16:
					if (pGameOptionsEx->bUserChargenKitSelectScroll) {
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
				switch (controlInfo.id) {
				case 65:
					if (pGameOptionsEx->bUserMageBookScroll) {
						pControl = new CUIButtonMageBookUp(panel, controlInfo);
					}
					break;
				case 66:
					if (pGameOptionsEx->bUserMageBookScroll) {
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
				switch (controlInfo.id) {
				case 62:
					if (pGameOptionsEx->bUserPriestBookScroll) {
						pControl = new CUIButtonPriestBookUp(panel, controlInfo);
					}
					break;
				case 63:
					if (pGameOptionsEx->bUserPriestBookScroll) {
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
				switch (controlInfo.id) {
				case 24:
					if (pGameOptionsEx->bUserRecordMageSpellScroll) {
						pControl = IENew CUICheckButtonRecMageSpell(panel, controlInfo);
					}
					break;
				case 30:
					if (pGameOptionsEx->bUserRecordMageSpellScroll) {
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

	}

	return pControl;
}