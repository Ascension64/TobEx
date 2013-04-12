#include "ItemCommon.h"

ItmFileAbility* __stdcall CItem_GetFirstLauncherAbility(CItem& itm) {
	int nAbilities = itm.m_nNumAbilities;
	for (int i = 0; i < nAbilities; i++) {
		ItmFileAbility& ability = itm.GetAbility(i);
		if (ability.m_cAttackType == ITEMABILITYATTACKTYPE_LAUNCHER) {
			return &ability;
		}
	}

	return NULL;
}