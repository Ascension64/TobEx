#include "Animation5000.h"

#include "console.h"

CAnimation5000& (CAnimation5000::*Tramp_CAnimation5000_Construct)(WORD, ColorRangeValues&, DWORD) =
	SetFP(static_cast<CAnimation5000& (CAnimation5000::*)(WORD, ColorRangeValues&, DWORD)>	(&CAnimation5000::Construct),		0x843678);
LPCTSTR (CAnimation5000::*Tramp_CAnimation5000_GetWalkingSound)(WORD) =
	SetFP(static_cast<LPCTSTR (CAnimation5000::*)(WORD)>									(&CAnimation5000::GetWalkingSound),	0x851DCA);

CAnimation5000& DETOUR_CAnimation5000::DETOUR_Construct(WORD wAnimId, ColorRangeValues& colors, DWORD nOrientation) {
	switch (wAnimId & 0xF00) { //class
	case 0x200: //MAGE_*
		switch (wAnimId & 0xF) { //race
		case 0: //HUMAN
		case 1: //ELF
		case 2: //DWARF
			break;
		case 3: //HALFLING
			wAnimId &= (~0xF00); //convert to CLERIC_*
		case 4: //GNOME
		case 5: //HALF_ORC
		default:
			break;
		}
		break;

	case 0x500: //MONK_*
		switch (wAnimId & 0xF) { //race
		case 0: //HUMAN
			break;
		case 1: //ELF
		case 2: //DWARF
		case 3: //HALFLING
		case 4: //GNOME
		case 5: //HALF_ORC
			wAnimId &= (~0xF00);
			wAnimId |= 0x100; //convert to FIGHTER_*
			break;
		default:
			break;
		}
		break;

	default:
		break;

	}

	return (this->*Tramp_CAnimation5000_Construct)(wAnimId, colors, nOrientation);
}

LPCTSTR DETOUR_CAnimation5000::DETOUR_GetWalkingSound(WORD wTerrainCode) {
	return CAnimation::GetWalkingSound(wTerrainCode);
}