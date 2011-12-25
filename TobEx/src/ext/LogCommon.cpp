#include "LogCommon.h"

LPCTSTR Assertion_GetReason(int Eip) {
	switch (Eip) {
	case 0x5121A8:
		return "CEffectHPMod::ApplyEffect: nParam2 out of bounds";
		break;
	case 0x636D63:
		return "CRuleTables::GetWeapProfMax: proficiency ID not found in WEAPPROF.2DA";
		break;
	case 0x796F6E:
		return "CStart::UpdatePanel: nPanelIdx == 6, 7, or out of bounds";
		break;
	case 0x8AE58D:
		return "CCreatureObject::SetAnimationSequence: pItmFileAbility->meleeIdx overflow past JAB %";
		break;
	case 0x8AE705:
		return "CCreatureObject::SetAnimationSequence: pItmFileAbility->meleeIdx sum not 100%";
		break;
	case 0x96EDC6:
		return "CreateUIControl: nCtrlIdx out of bounds in GUIREC panel 8 (mage spells)";
		break;
	case 0x9712B3:
		return "CreateUIControl: nCtrlIdx out of bounds in GUIMG panel 2 (mage book)";
		break;
	case 0x97271D:
		return "CreateUIControl: nCtrlIdx out of bounds in GUIPR panel 2 (priest book)";
		break;
	case 0x975299:
		return "CreateUIControl: nCtrlIdx out of bounds in GUICG panel 7 (mage book)";
		break;
	case 0x97783D:
		return "CreateUIControl: nCtrlIdx out of bounds in GUICG panel 22 (class kit)";
		break;
	case 0x9FFB75:
		return "CVidCell::FXRender3dSetPalette: LoadFrame() failed";
		break;
	default:
		return NULL;
		break;
	}
}
