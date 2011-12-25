#ifndef OBJECTSTATS_H
#define OBJECTSTATS_H

#include "objstats.h"

//pStatsEx indices (add 201 to get STATS.IDS index)
#define CDERIVEDSTATSEX_BASE					201
#define CDERIVEDSTATSEX_ANIMATIONREMOVAL		0
//reserved for GemRB 1-54 (STATS.IDS 202-255)
//reserved for GemRB 55-99 (STATS.IDS 256-300)
#define CDERIVEDSTATSEX_FIGHTERLEVEL			100
#define CDERIVEDSTATSEX_MAGELEVEL				101
#define CDERIVEDSTATSEX_CLERICLEVEL				102 //41 - 242
#define CDERIVEDSTATSEX_THIEFLEVEL				103
#define CDERIVEDSTATSEX_DRUIDLEVEL				104 //42 - 243
#define CDERIVEDSTATSEX_RANGERLEVEL				105 //45 - 246
#define CDERIVEDSTATSEX_EFFECTIVECLERICLEVEL	106
#define CDERIVEDSTATSEX_WEIGHTALLOWANCEMOD		199

extern void (CConditionalSpellList::*Tramp_CConditionalSpellList_EvaluateTriggers)(CCreatureObject&);

extern CDerivedStats& (CDerivedStats::*Tramp_CDerivedStats_Construct_3)(CreFileData&, CreFileMemSpellLevel*, CreFileMemSpellLevel*);
extern CDerivedStats& (CDerivedStats::*Tramp_CDerivedStats_Construct_0)();
extern void (CDerivedStats::*Tramp_CDerivedStats_Init)(CreFileData&, CreFileMemSpellLevel*, CreFileMemSpellLevel*);
extern CDerivedStats& (CDerivedStats::*Tramp_CDerivedStats_OpAssign)(CDerivedStats&);
extern void (CDerivedStats::*Tramp_CDerivedStats_ClearStats)();
extern CDerivedStats& (CDerivedStats::*Tramp_CDerivedStats_OpAdd)(CDerivedStats&);
extern int (CDerivedStats::*Tramp_CDerivedStats_GetStat)(short);
extern void (CDerivedStats::*Tramp_CDerivedStats_MarshalTemplate)(CDerivedStatsTemplate*, int*);
extern void (CDerivedStats::*Tramp_CDerivedStats_UnmarshalTemplate)(CDerivedStatsTemplate&, int);
extern void (CDerivedStats::*Tramp_CDerivedStats_Deconstruct)();

class DETOUR_CConditionalSpellList : public CConditionalSpellList {
public:
	void DETOUR_EvaluateTriggers(CCreatureObject& cre);
};

class DETOUR_CDerivedStats : public CDerivedStats {
public:
	CDerivedStats& DETOUR_Construct3(CreFileData& stats, CreFileMemSpellLevel* memArrayMage, CreFileMemSpellLevel* memArrayPriest);
	CDerivedStats& DETOUR_Construct0();
	void DETOUR_Init(CreFileData& stats, CreFileMemSpellLevel* memArrayMage, CreFileMemSpellLevel* memArrayPriest);
	CDerivedStats& DETOUR_OpAssign(CDerivedStats& cds);
	void DETOUR_ClearStats();
	CDerivedStats& DETOUR_OpAdd(CDerivedStats& cds);
	int DETOUR_GetStat(short nOpcode);
	void DETOUR_MarshalTemplate(CDerivedStatsTemplate* pcdst, int* pnSize);
	void DETOUR_UnmarshalTemplate(CDerivedStatsTemplate& cdst, int nSize);
	void DETOUR_Deconstruct();
};

float CDerivedStats_NumAttacksShortToFloat(short s);
short CDerivedStats_NumAttacksFloatToShort(float f);
char CDerivedStats_GetEffectiveStrength(char strength, char strengthEx);
void CDerivedStats_GetRealStrength(char strengthEffective, char& strength, char& strengthEx);
char CDerivedStats_GetEffectiveStrengthSpell(char strength, char strengthEx);
void CDerivedStats_GetRealStrengthSpell(char strengthEffective, char& strength, char& strengthEx);
void CDerivedStats_SetStat(CDerivedStats& cds, short nOpcode, int nValue);
char CDerivedStats_GetSubclassLevelNoAssertion(CDerivedStats& cds, char nClass, char nSubclass);
char CDerivedStats_GetEffectiveClericLevelNoAssertion(CDerivedStats& cds, char nClass);

#endif //OBJECTSTATS_H