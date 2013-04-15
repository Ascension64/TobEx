//TobExEE
#include "objstats.h"
#include "p_objstats.h"

//CConditionalSpellList

//CRepeatingEffBase

//CRepeatingDisease

//CRepeatingEff

//CRepeatingWingBuffet

//CRepeatingPoison

//CRepeatingRegen

//CSpellProtection

//CStatModVsObjectList

//CDerivedStats
DefineLibNoRetFunc(CDerivedStats&, CDerivedStats, CDerivedStats, (), Construct, Construct0, (), CDERIVEDSTATS_CONSTRUCT0);
DefineLibMemberFunc(void, CDerivedStats, Init, (
	CreFileHeader& stats,
	CreFileMemorizedSpellLevel* memArrayMage,
	CreFileMemorizedSpellLevel* memArrayPriest
	), Init, Init, (stats, memArrayMage, memArrayPriest), CDERIVEDSTATS_INIT);
DefineLibMemberFunc(CDerivedStats&, CDerivedStats, operator=, (CDerivedStats& cds), OpAssign, OpAssign, (cds), CDERIVEDSTATS_OPASSIGN);
DefineLibMemberFunc(void, CDerivedStats, ClearStats, (), ClearStats, ClearStats, (), CDERIVEDSTATS_CLEARSTATS);
DefineLibMemberFunc(CDerivedStats&, CDerivedStats, operator+, (CDerivedStats& cds), OpAdd, OpAdd, (cds), CDERIVEDSTATS_OPADD);
DefineLibMemberFunc(void, CDerivedStats, LimitStats, (), LimitStats, LimitStats, (), CDERIVEDSTATS_LIMITSTATS);
DefineLibMemberFunc(int, CDerivedStats, GetStat, (short nOpcode), GetStat, GetStat, (nOpcode), CDERIVEDSTATS_GETSTAT);
DefineLibMemberFunc(char, CDerivedStats, GetSubclassLevel, (char nClass, char nSubclass), GetSubclassLevel, GetSubclassLevel, (nClass, nSubclass), CDERIVEDSTATS_GETSUBCLASSLEVEL);
DefineLibMemberFunc(short, CDerivedStats, GetMeanLevel, (char nClass), GetMeanLevel, GetMeanLevel, (nClass), CDERIVEDSTATS_GETMEANLEVEL);
DefineLibMemberFunc(unsigned char, CDerivedStats, GetFighterClassLevel, (unsigned char cClass), GetFighterClassLevel, GetFighterClassLevel, (cClass), CDERIVEDSTATS_GETFIGHTERCLASSLEVEL);
DefineLibMemberFunc(unsigned char, CDerivedStats, GetMageClassLevel, (unsigned char cClass), GetMageClassLevel, GetMageClassLevel, (cClass), CDERIVEDSTATS_GETMAGECLASSLEVEL);
DefineLibMemberFunc(unsigned char, CDerivedStats, GetThiefClassLevel, (unsigned char cClass), GetThiefClassLevel, GetThiefClassLevel, (cClass), CDERIVEDSTATS_GETTHIEFCLASSLEVEL);
DefineLibMemberFunc(unsigned char, CDerivedStats, GetClericClassLevel, (unsigned char cClass), GetClericClassLevel, GetClericClassLevel, (cClass), CDERIVEDSTATS_GETCLERICCLASSLEVEL);
DefineLibMemberFunc(void, CDerivedStats, MarshalTemplate, (CDerivedStatsTemplate** ppcdst, int* pnSize), MarshalTemplate, MarshalTemplate, (ppcdst, pnSize), CDERIVEDSTATS_MARSHALTEMPLATE);
DefineLibMemberFunc(void, CDerivedStats, UnmarshalTemplate, (CDerivedStatsTemplate& cds, int nSize), UnmarshalTemplate, UnmarshalTemplate, (cds, nSize), CDERIVEDSTATS_UNMARSHALTEMPLATE);
DefineLibMemberFunc(char, CDerivedStats, GetEffectiveClericLevel, (unsigned char nClass), GetEffectiveClericLevel, GetEffectiveClericLevel, (nClass), CDERIVEDSTATS_GETEFFECTIVECLERICLEVEL);
DefineLibMemberFunc(char, CDerivedStats, GetEffectiveMageLevel, (unsigned char nClass), GetEffectiveMageLevel, GetEffectiveMageLevel, (nClass), CDERIVEDSTATS_GETEFFECTIVEMAGELEVEL);
DefineLibNoRetFunc(void, CDerivedStats, ~CDerivedStats, (), Deconstruct, Deconstruct, (), CDERIVEDSTATS_DECONSTRUCT);
