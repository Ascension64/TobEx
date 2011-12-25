#include "UserCore.h"

#include <cassert>

#include "utils.h"
#include "UserChargenKit.h"
#include "UserChargenMageSpell.h"
#include "UserRecMageSpell.h"
#include "UserMageBook.h"
#include "UserPriestBook.h"
#include "uicore.h"
#include "console.h"

CUIControl* __cdecl DETOUR_CreateUIControl(CPanel& panel, ChuFileControlInfoBase& controlInfo) {
	CUIControl* pControl = CreateUIControl(panel, controlInfo);

	if (pControl == NULL) {
		assert(&controlInfo != NULL);
		ResRef rManager = panel.pManager->name;

		//Chargen
		if (rManager = "GUICG") {
			switch (panel.index) {
			case 7:
				switch (controlInfo.id) {
				case 31:
					if (GetIniValue("UI", "Scrollable Chargen Mage Spell Selection")) {
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
					if (GetIniValue("UI", "Scrollable Kit Selection")) {
						pControl = new CUIScrollBarChargenKit(panel, controlInfo);
					}
					break;
				case 16:
					if (GetIniValue("UI", "Scrollable Kit Selection")) {
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
					if (GetIniValue("UI", "Scrollable Mage Spellbook")) {
						pControl = new CUIButtonMageBookUp(panel, controlInfo);
					}
					break;
				case 66:
					if (GetIniValue("UI", "Scrollable Mage Spellbook")) {
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
					if (GetIniValue("UI", "Scrollable Priest Spellbook")) {
						pControl = new CUIButtonPriestBookUp(panel, controlInfo);
					}
					break;
				case 63:
					if (GetIniValue("UI", "Scrollable Priest Spellbook")) {
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
					if (GetIniValue("UI", "Scrollable Level Up Mage Spell Selection")) {
						pControl = IENew CUICheckButtonRecMageSpell(panel, controlInfo);
					}
					break;
				case 30:
					if (GetIniValue("UI", "Scrollable Level Up Mage Spell Selection")) {
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