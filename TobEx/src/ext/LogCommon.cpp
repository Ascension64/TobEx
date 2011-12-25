#include "LogCommon.h"

LPCTSTR Assertion_GetReason(int Eip) {
	switch (Eip) {
	case 0x5121A8:
		return "CEffectHPMod::ApplyEffect() nParam2 out of bounds";
		break;
	case 0x796F6E:
		return "CStart::UpdatePanel() nPanelIdx == 6, 7, or out of bounds";
		break;
	case 0x975299:
		return "CreateUIControl() nCtrlIdx out of bounds in GUICG panel 7 (mage book)";
		break;
	case 0x97783D:
		return "CreateUIControl() nCtrlIdx out of bounds in GUICG panel 22 (class kit)";
	default:
		return NULL;
		break;
	}
}
