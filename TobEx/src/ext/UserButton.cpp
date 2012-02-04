#include "UserButton.h"

#include <cassert>

#include "chitin.h"
#include "UserChargenKit.h"
#include "console.h"
#include "log.h"

unsigned int (CUICheckButtonChargenKit::*Tramp_CUICheckButtonChargenKit_GetKitId)(Object&) =
	SetFP(static_cast<unsigned int (CUICheckButtonChargenKit::*)(Object&)>	(&CUICheckButtonChargenKit::GetKitId),		0x73A6E8);
STRREF (CUICheckButtonChargenKit::*Tramp_CUICheckButtonChargenKit_GetKitHelpText)(Object&) =
	SetFP(static_cast<STRREF (CUICheckButtonChargenKit::*)(Object&)>		(&CUICheckButtonChargenKit::GetKitHelpText),0x73A84E);

unsigned int DETOUR_CUICheckButtonChargenKit::DETOUR_GetKitId(Object& o) {
	CScreenCharGen* pCreateChar = g_pChitin->pCreateChar;
	assert(pCreateChar != NULL);
	CPanel& panel = pCreateChar->manager.GetPanel(22);
	assert(&panel != NULL);
	CUIScrollBarChargenKit& scroll = (CUIScrollBarChargenKit&)panel.GetUIControl(15);

	if (&scroll == NULL) {
		LPCTSTR lpsz = "DETOUR_GetKitId(): Kit selection scroll bar not found\r\n";
		console.write(lpsz);
		L.timestamp();
		L.append(lpsz);
		return (this->*Tramp_CUICheckButtonChargenKit_GetKitId)(o);
	}

	int row = 0;

	switch (index - 1) {
	case 0:
		row = 0;
		break;
	case 1:
		row = 1;
		break;
	case 2:
		row = 2;
		break;
	case 3:
		row = 3;
		break;
	case 8:
		row = 4;
		break;
	case 9:
		row = 5;
		break;
	case 10:
		row = 6;
		break;
	case 11:
		row = 7;
		break;
	case 12:
		row = 8;
		break;
	case 13:
		row = 9;
		break;
	case 15:
		row = 10;
		break;
	default:
		break;
	}

	int col = 0;

	row += scroll.nCurrentValue;

	IECString sKit;
	if (col < g_pChitin->pCreateChar->Kit_Class_Race.nCols &&
		row < g_pChitin->pCreateChar->Kit_Class_Race.nRows &&
		col >= 0 &&
		row >= 0) {
		sKit = *((g_pChitin->pCreateChar->Kit_Class_Race.pDataArray) + (g_pChitin->pCreateChar->Kit_Class_Race.nCols * row + col));
	} else {
		sKit = g_pChitin->pCreateChar->Kit_Class_Race.defaultVal;
	}
	unsigned int nKitId;
	sscanf_s((LPCTSTR)sKit, "%d", &nKitId);

	return (nKitId | KIT_TRUECLASS);
}

STRREF DETOUR_CUICheckButtonChargenKit::DETOUR_GetKitHelpText(Object& o) {
	CScreenCharGen* pCreateChar = g_pChitin->pCreateChar;
	assert(pCreateChar != NULL);
	CPanel& panel = pCreateChar->manager.GetPanel(22);
	assert(&panel != NULL);
	CUIScrollBarChargenKit& scroll = (CUIScrollBarChargenKit&)panel.GetUIControl(15);

	if (&scroll == NULL) {
		LPCTSTR lpsz = "DETOUR_GetKitHelpText(): Kit selection scroll bar not found\r\n";
		console.write(lpsz);
		L.timestamp();
		L.append(lpsz);
		return (this->*Tramp_CUICheckButtonChargenKit_GetKitHelpText)(o);
	}

	int row = 0;

	switch (index - 1) {
	case 0:
		row = 0;
		break;
	case 1:
		row = 1;
		break;
	case 2:
		row = 2;
		break;
	case 3:
		row = 3;
		break;
	case 8:
		row = 4;
		break;
	case 9:
		row = 5;
		break;
	case 10:
		row = 6;
		break;
	case 11:
		row = 7;
		break;
	case 12:
		row = 8;
		break;
	case 13:
		row = 9;
		break;
	case 15:
		row = 10;
		break;
	default:
		break;
	}

	int col = 0;

	row += scroll.nCurrentValue;

	IECString sKit;
	if (col < g_pChitin->pCreateChar->Kit_Class_Race.nCols &&
		row < g_pChitin->pCreateChar->Kit_Class_Race.nRows &&
		col >= 0 &&
		row >= 0) {
		sKit = *((g_pChitin->pCreateChar->Kit_Class_Race.pDataArray) + (g_pChitin->pCreateChar->Kit_Class_Race.nCols * row + col));
	} else {
		sKit = g_pChitin->pCreateChar->Kit_Class_Race.defaultVal;
	}
	unsigned int nKitId;
	sscanf_s((LPCTSTR)sKit, "%d", &nKitId);

	if (pCreateChar->Kit_Class_Race.m_2da.name != "" && nKitId) {
		col = 3;

		IECString sKitHelpStrRef;
		if (col < g_pChitin->pGame->KITLIST.nCols &&
			nKitId < g_pChitin->pGame->KITLIST.nRows &&
			col >= 0 &&
			nKitId >= 0) {
			sKitHelpStrRef = *((g_pChitin->pGame->KITLIST.pDataArray) + (g_pChitin->pGame->KITLIST.nCols * nKitId + col));
		} else {
			sKitHelpStrRef = g_pChitin->pGame->KITLIST.defaultVal;
		}
		STRREF strref;
		sscanf_s((LPCTSTR)sKitHelpStrRef, "%d", &strref);
		return strref;
	} else {
		switch (o.GetClass() - 2) {
		case 0: //FIGHTER
			return 0x2554;
		case 1: //CLERIC
			return 0x2557;
		case 2: //THIEF
			return 0x2559;
		case 3: //BARD
			return 0x255A;
		case 4: //PALADIN
			return 0x2556;
		case 9: //DRUID
			return 0x2558;
		case 10: //RANGER
			return 0x2555;
		default:
			switch (pCreateChar->m_class - 2) {
			case 0: //FIGHTER
				return 0x2554;
			case 1: //CLERIC
				return 0x2557;
			case 2: //THIEF
				return 0x2559;
			case 3: //BARD
				return 0x255A;
			case 4: //PALADIN
				return 0x2556;
			case 9: //DRUID
				return 0x2558;
			case 10: //RANGER
				return 0x2555;
			default:
				LPCTSTR lpsz = "DETOUR_GetKitHelpText(): No valid kit help text found\r\n";
				console.write(lpsz);
				L.timestamp();
				L.append(lpsz);
				return -1;
			}
		}
	}

}