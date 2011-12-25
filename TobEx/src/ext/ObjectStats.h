#ifndef OBJECTSTATS_H
#define OBJECTSTATS_H

#include "objstats.h"

extern CDerivedStats& (CDerivedStats::*Tramp_CDerivedStats_OpAdd)(CDerivedStats&);

class DETOUR_CDerivedStats : public CDerivedStats {
public:
	CDerivedStats& DETOUR_OpAdd(CDerivedStats& cds);
};

float CDerivedStats_NumAttacksShortToFloat(short s);
short CDerivedStats_NumAttacksFloatToShort(float f);

#endif //OBJECTSTATS_H