#include "EffectCore.h"

#include "utils.h"
#include "effcore.h"
#include "EffectOpcode.h"

CEffect& (*Tramp_CEffect_CreateEffect)(ITEM_EFFECT&, POINT&, Enum, POINT&, Enum) =
	SetFP(static_cast<CEffect& (*)(ITEM_EFFECT&, POINT&, Enum, POINT&, Enum)>						(&CEffect::CreateEffect),		0x4F3EC2);

CEffect& DETOUR_CEffect::DETOUR_CreateEffect(ITEM_EFFECT& eff, POINT& ptSource, Enum eSource, POINT& ptDest, Enum e2) {
	switch (eff.opcode) {
		case 0x013E:
			return *new CEffect13E(eff, ptSource, eSource, ptDest.x, ptDest.y, FALSE, e2);
			break;
		default:
			//Let the engine handle the standard opcodes
			return Tramp_CEffect_CreateEffect(eff, ptSource, eSource, ptDest, e2);
			break;
	}
}