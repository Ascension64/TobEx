#include "Animation5000.h"

DefineTrampMemberFunc(CAnimation5000&, CAnimation5000, Construct, (unsigned short wAnimId, CreFileColors& colors, int nOrientation), Construct, Construct, 0x843678);
DefineTrampMemberFunc(LPCTSTR, CAnimation5000, GetWalkingSound, (short wTerrainCode), GetWalkingSound, GetWalkingSound, 0x851DCA);

CAnimation5000& DETOUR_CAnimation5000::DETOUR_Construct(unsigned short wAnimId, CreFileColors& colors, int nOrientation) {
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

LPCTSTR DETOUR_CAnimation5000::DETOUR_GetWalkingSound(short wTerrainCode) {
	return CAnimation::GetWalkingSound(wTerrainCode);
}