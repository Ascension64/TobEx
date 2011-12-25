#include "ObjectCommon.h"

BOOL ObjectCommon_InBackstabPosition(short orTarget, short orToTarget) {
	//return TRUE if orToTarget is in 90-degree arc of orTarget

	if (orTarget > 2 && orTarget < 14) {
		if (orToTarget > orTarget - 3 &&
			orToTarget < orTarget + 3) {
			return TRUE;
		}
	}

	if (orTarget <= 2) {
		if (orToTarget > orTarget + 13 /* % 16 */ ||
			orToTarget < orTarget + 3) {
			return TRUE;
		}
	}

	if (orTarget >= 14) {
		if (orToTarget > orTarget - 3 ||
			orToTarget < (orTarget + 3) % 16) {
			return TRUE;
		}
	}

	return FALSE;
}