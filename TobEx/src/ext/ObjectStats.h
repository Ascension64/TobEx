#ifndef OBJECTSTATS_H
#define OBJECTSTATS_H

#include "objstats.h"

extern void (CConditionalSpellList::*Tramp_CConditionalSpellList_EvaluateTriggers)(CCreatureObject&);
extern CDerivedStats& (CDerivedStats::*Tramp_CDerivedStats_OpAdd)(CDerivedStats&);

class DETOUR_CConditionalSpellList : public CConditionalSpellList {
public:
	void DETOUR_EvaluateTriggers(CCreatureObject& cre);
};

class DETOUR_CDerivedStats : public CDerivedStats {
public:
	CDerivedStats& DETOUR_OpAdd(CDerivedStats& cds);
};

float CDerivedStats_NumAttacksShortToFloat(short s);
short CDerivedStats_NumAttacksFloatToShort(float f);
char CDerivedStats_GetEffectiveStrength(char strength, char strengthEx);
void CDerivedStats_GetRealStrength(char strengthEffective, char& strength, char& strengthEx);
char CDerivedStats_GetEffectiveStrengthSpell(char strength, char strengthEx);
void CDerivedStats_GetRealStrengthSpell(char strengthEffective, char& strength, char& strengthEx);

#endif //OBJECTSTATS_H