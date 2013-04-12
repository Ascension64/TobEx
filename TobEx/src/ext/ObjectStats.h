#ifndef OBJECTSTATS_H
#define OBJECTSTATS_H

#include "objstats.h"

//CConditionalSpellList
DeclareTrampMemberFunc(void, CConditionalSpellList, EvaluateTriggers, (CCreatureObject& cre), EvaluateTriggers);

class DETOUR_CConditionalSpellList : public CConditionalSpellList {
public:
	void DETOUR_EvaluateTriggers(CCreatureObject& cre);
};

//CDerivedStats
//pStatsEx indices (add 201 to get STATS.IDS index)
#define CDERIVEDSTATSEX_BASE						201
#define CDERIVEDSTATSEX_ANIMATIONREMOVAL			0
//reserved for GemRB 1-54 (STATS.IDS 202-255)
//reserved for GemRB 55-99 (STATS.IDS 256-300)
#define CDERIVEDSTATSEX_FIGHTERLEVEL				100
#define CDERIVEDSTATSEX_MAGELEVEL					101
#define CDERIVEDSTATSEX_CLERICLEVEL					102 //41 - 242
#define CDERIVEDSTATSEX_THIEFLEVEL					103
#define CDERIVEDSTATSEX_DRUIDLEVEL					104 //42 - 243
#define CDERIVEDSTATSEX_RANGERLEVEL					105 //45 - 246
#define CDERIVEDSTATSEX_EFFECTIVECLERICLEVEL		106
#define CDERIVEDSTATSEX_BUTTONDISABLESTEALTH		107
#define CDERIVEDSTATSEX_BUTTONDISABLETHIEVING		108
#define CDERIVEDSTATSEX_BUTTONDISABLECASTSPELL		109
#define CDERIVEDSTATSEX_BUTTONDISABLEQUICKSPELL1	110
#define CDERIVEDSTATSEX_BUTTONDISABLEQUICKSPELL2	111
#define CDERIVEDSTATSEX_BUTTONDISABLEQUICKSPELL3	112
#define CDERIVEDSTATSEX_BUTTONDISABLETURNUNDEAD		113
#define CDERIVEDSTATSEX_BUTTONDISABLETALK			114
#define CDERIVEDSTATSEX_BUTTONDISABLEUSEITEM		115
#define CDERIVEDSTATSEX_BUTTONDISABLEQUICKITEM1		116
#define CDERIVEDSTATSEX_BUTTONDISABLEBARDSONG		117
#define CDERIVEDSTATSEX_BUTTONDISABLEQUICKITEM2		118
#define CDERIVEDSTATSEX_BUTTONDISABLEQUICKITEM3		119
#define CDERIVEDSTATSEX_BUTTONDISABLEABILITY		120
#define CDERIVEDSTATSEX_BUTTONDISABLEFINDTRAPS		121
#define CDERIVEDSTATSEX_AID							122
#define CDERIVEDSTATSEX_BLESS						123
#define CDERIVEDSTATSEX_CHANT						124
#define CDERIVEDSTATSEX_DRAWUPONHOLYMIGHT			125
#define CDERIVEDSTATSEX_CHANTBAD					126
#define CDERIVEDSTATSEX_DISABLESPELLTYPEWIZARD		127
#define CDERIVEDSTATSEX_DISABLESPELLTYPEPRIEST		128
#define CDERIVEDSTATSEX_DISABLESPELLTYPEINNATE		129
#define CDERIVEDSTATSEX_WINGBUFFET					130

#define CDERIVEDSTATSEX_ACIDDAMAGEBONUS				186
#define CDERIVEDSTATSEX_COLDDAMAGEBONUS				187
#define CDERIVEDSTATSEX_CRUSHINGDAMAGEBONUS			188
#define CDERIVEDSTATSEX_ELECTRICITYDAMAGEBONUS		189
#define CDERIVEDSTATSEX_FIREDAMAGEBONUS				190
#define CDERIVEDSTATSEX_PIERCINGDAMAGEBONUS			191
#define CDERIVEDSTATSEX_POISONDAMAGEBONUS			192
#define CDERIVEDSTATSEX_MAGICDAMAGEBONUS			193
#define CDERIVEDSTATSEX_MISSILEDAMAGEBONUS			194
#define CDERIVEDSTATSEX_SLASHINGDAMAGEBONUS			195
#define CDERIVEDSTATSEX_MAGICFIREDAMAGEBONUS		196
#define CDERIVEDSTATSEX_MAGICCOLDDAMAGEBONUS		197
#define CDERIVEDSTATSEX_STUNNINGDAMAGEBONUS			198
#define CDERIVEDSTATSEX_WEIGHTALLOWANCEMOD			199

DeclareTrampMemberFunc(CDerivedStats&, CDerivedStats, Construct, (CreFileHeader& stats, CreFileMemorizedSpellLevel* memArrayMage, CreFileMemorizedSpellLevel* memArrayPriest), Construct3);
DeclareTrampMemberFunc(CDerivedStats&, CDerivedStats, Construct, (), Construct0);
DeclareTrampMemberFunc(void, CDerivedStats, Init, (CreFileHeader& stats, CreFileMemorizedSpellLevel* memArrayMage, CreFileMemorizedSpellLevel* memArrayPriest), Init);
DeclareTrampMemberFunc(CDerivedStats&, CDerivedStats, OpAssign, (CDerivedStats& cds), OpAssign);
DeclareTrampMemberFunc(void, CDerivedStats, ClearStats, (), ClearStats);
DeclareTrampMemberFunc(CDerivedStats&, CDerivedStats, OpAdd, (CDerivedStats& cds), OpAdd);
DeclareTrampMemberFunc(void, CDerivedStats, LimitStats, (), LimitStats);
DeclareTrampMemberFunc(int, CDerivedStats, GetStat, (short nOpcode), GetStat);
DeclareTrampMemberFunc(void, CDerivedStats, MarshalTemplate, (CDerivedStatsTemplate** ppcdst, int* pnSize), MarshalTemplate);
DeclareTrampMemberFunc(void, CDerivedStats, UnmarshalTemplate, (CDerivedStatsTemplate& cdst, int nSize), UnmarshalTemplate);
DeclareTrampMemberFunc(void, CDerivedStats, Deconstruct, (), Deconstruct);

class DETOUR_CDerivedStats : public CDerivedStats {
public:
	CDerivedStats& DETOUR_Construct3(CreFileHeader& stats, CreFileMemorizedSpellLevel* memArrayMage, CreFileMemorizedSpellLevel* memArrayPriest);
	CDerivedStats& DETOUR_Construct0();
	void DETOUR_Init(CreFileHeader& stats, CreFileMemorizedSpellLevel* memArrayMage, CreFileMemorizedSpellLevel* memArrayPriest);
	CDerivedStats& DETOUR_OpAssign(CDerivedStats& cds);
	void DETOUR_ClearStats();
	CDerivedStats& DETOUR_OpAdd(CDerivedStats& cds);
	void DETOUR_LimitStats();
	int DETOUR_GetStat(short nOpcode);
	void DETOUR_MarshalTemplate(CDerivedStatsTemplate** ppcdst, int* pnSize);
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