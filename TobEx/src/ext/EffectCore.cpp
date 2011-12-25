#include "EffectCore.h"

#include "utils.h"
#include "effcore.h"
#include "EffectOpcode.h"

CEffect& DETOUR_CEffect::CreateEffect(ITEM_EFFECT& eff, POINT& ptSource, Enum eSource, POINT& ptDest, Enum e2) {
	switch (eff.opcode) {
		case 0x013E:
			return *new CEffect13E(eff, ptSource, eSource, ptDest.x, ptDest.y, FALSE, e2);
			break;
		default:
			//Let the engine handle the standard opcodes
			return CEffect::CreateEffect(eff, ptSource, eSource, ptDest, e2);
			break;
	}
}