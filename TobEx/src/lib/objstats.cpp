#include "objstats.h"

//CConditionalSpell
void CConditionalSpell::operator delete(void* mem)	{ return ::operator delete(mem, 0); } 

//CConditionalSpellList
void (CConditionalSpellList::*CConditionalSpellList_EvaluateTriggers)(CCreatureObject&) =
	SetFP(static_cast<void (CConditionalSpellList::*)(CCreatureObject&)>	(&CConditionalSpellList::EvaluateTriggers),	0x46BE04);

void CConditionalSpellList::EvaluateTriggers(CCreatureObject& cre)	{ return (this->*CConditionalSpellList_EvaluateTriggers)(cre); }

//CRepeatingEffBase
extern CRepeatingEffBase& (CRepeatingEffBase::*CRepeatingEffBase_Construct)() =
	SetFP(static_cast<CRepeatingEffBase& (CRepeatingEffBase::*)()>	(&CRepeatingEffBase::Construct),	0x5662C0);

CRepeatingEffBase::CRepeatingEffBase()	{ (this->*CRepeatingEffBase_Construct)(); }

//CRepeatingDisease
CRepeatingDisease::CRepeatingDisease() {
	SetVT(this, 0xAA9858);
	wType = 4;
	wMode = 0;
	wPostDelayDuration = -1;
	wAmount = 1;
	wPeriod = 1;
	nTicksLeft = 0;
	nTicksElapsed = 0;
	wSecondsElapsed = 0;
	bExpired = FALSE;
}

//CRepeatingEff
void (CRepeatingEff::*CRepeatingEff_Update)(CCreatureObject&, int) =
	SetFP(static_cast<void (CRepeatingEff::*)(CCreatureObject&, int)>		(&CRepeatingEff::Update),	0x54772D);

CRepeatingEff::CRepeatingEff() {
	SetVT(this, 0xAA9A1C);
	wType = 5;
	wMode = 0;
	wPostDelayDuration = -1;
	wAmount = 1;
	wPeriod = 1;
	nTicksLeft = 0;
	nTicksElapsed = 0;
	wSecondsElapsed = 0;
	bExpired = FALSE;
	pEffect = NULL;
}

void CRepeatingEff::Update(CCreatureObject& cre, int nTicks) { return (this->*CRepeatingEff_Update)(cre, nTicks); }

//CRepeatingWingBuffet
void (CRepeatingWingBuffet::*CRepeatingWingBuffet_Update)(CCreatureObject&, int) =
	SetFP(static_cast<void (CRepeatingWingBuffet::*)(CCreatureObject&, int)>		(&CRepeatingWingBuffet::Update),	0x547161);

CRepeatingWingBuffet::CRepeatingWingBuffet() {
	SetVT(this, 0xAA9A10);
	wType = 6;
	wMode = 1;
	nDistance = 6;
	ptOrigin.x = 0;
	ptOrigin.y = 0;
	eOrigin = ENUM_INVALID_INDEX;
}

void CRepeatingWingBuffet::Update(CCreatureObject& cre, int nTicks) { return (this->*CRepeatingWingBuffet_Update)(cre, nTicks); }

//CRepeatingPoison
CRepeatingPoison::CRepeatingPoison() {
	SetVT(this, 0xAA984C);
	wType = 3;
	wMode = 0;
	wPostDelayDuration = -1;
	wAmount = 1;
	wPeriod = 1;
	nTicksLeft = 0;
	nTicksElapsed = 0;
	wSecondsElapsed = 0;
	bExpired = FALSE;
}

//CRepeatingRegen
CRepeatingRegen::CRepeatingRegen() {
	SetVT(this, 0xAA9864);
	wType = 5;
	wMode = 0;
	wPostDelayDuration = -1;
	wAmount = 1;
	wPeriod = 1;
	nTicksLeft = 0;
	nTicksElapsed = 0;
	wSecondsElapsed = 0;
	bExpired = FALSE;
}

//CDerivedStats
CDerivedStats& (CDerivedStats::*CDerivedStats_Construct_3)(CreFileData&, CreFileMemSpellLevel*, CreFileMemSpellLevel*) =
	SetFP(static_cast<CDerivedStats& (CDerivedStats::*)(CreFileData&, CreFileMemSpellLevel*, CreFileMemSpellLevel*)>
																			(&CDerivedStats::Construct),				0x46CB40);
CDerivedStats& (CDerivedStats::*CDerivedStats_Construct_0)() =
	SetFP(static_cast<CDerivedStats& (CDerivedStats::*)()>					(&CDerivedStats::Construct),				0x46D1B2);
void (CDerivedStats::*CDerivedStats_Init)(CreFileData&, CreFileMemSpellLevel*, CreFileMemSpellLevel*) =
	SetFP(static_cast<void (CDerivedStats::*)(CreFileData&, CreFileMemSpellLevel*, CreFileMemSpellLevel*)>
																			(&CDerivedStats::Init),						0x46DB9C);
CDerivedStats& (CDerivedStats::*CDerivedStats_OpAssign)(CDerivedStats&) =
	SetFP(static_cast<CDerivedStats& (CDerivedStats::*)(CDerivedStats&)>	(&CDerivedStats::OpAssign),					0x46EAC6);
void (CDerivedStats::*CDerivedStats_ClearStats)() =
	SetFP(static_cast<void (CDerivedStats::*)()>							(&CDerivedStats::ClearStats),				0x46FCF5);
CDerivedStats& (CDerivedStats::*CDerivedStats_OpAdd)(CDerivedStats&) =
	SetFP(static_cast<CDerivedStats& (CDerivedStats::*)(CDerivedStats&)>	(&CDerivedStats::OpAdd),					0x470945);
void (CDerivedStats::*CDerivedStats_LimitStats)() =
	SetFP(static_cast<void (CDerivedStats::*)()>							(&CDerivedStats::LimitStats),				0x471B36);
short (CDerivedStats::*CDerivedStats_GetStat)(int) =
	SetFP(static_cast<short (CDerivedStats::*)(int)>						(&CDerivedStats::GetStat),					0x473162);
void (CDerivedStats::*CDerivedStats_LoadStats)(CDerivedStatsTemplate&, int) =
	SetFP(static_cast<void (CDerivedStats::*)(CDerivedStatsTemplate&, int)>
																			(&CDerivedStats::LoadStats),				0x474AF2);
char (CDerivedStats::*CDerivedStats_GetEffectiveClericLevel)(unsigned char) =
	SetFP(static_cast<char (CDerivedStats::*)(unsigned char)>				(&CDerivedStats::GetEffectiveClericLevel),	0x4758AD);
char (CDerivedStats::*CDerivedStats_GetEffectiveMageLevel)(unsigned char) =
	SetFP(static_cast<char (CDerivedStats::*)(unsigned char)>				(&CDerivedStats::GetEffectiveMageLevel),	0x4759FA);

CDerivedStats::CDerivedStats(CreFileData& stats, CreFileMemSpellLevel* memArrayMage, CreFileMemSpellLevel* memArrayPriest) {
	(this->*CDerivedStats_Construct_3)(stats, memArrayMage, memArrayPriest);
}
CDerivedStats::CDerivedStats()															{ (this->*CDerivedStats_Construct_0)(); }
void CDerivedStats::Init(CreFileData& stats, CreFileMemSpellLevel* memArrayMage, CreFileMemSpellLevel* memArrayPriest) {
	return (this->*CDerivedStats_Init)(stats, memArrayMage, memArrayPriest);
}
CDerivedStats& CDerivedStats::operator=(CDerivedStats& cds)				{ return (this->*CDerivedStats_OpAssign)(cds); }
void CDerivedStats::ClearStats()										{ return (this->*CDerivedStats_ClearStats)(); }
CDerivedStats& CDerivedStats::operator+(CDerivedStats& cds)				{ return (this->*CDerivedStats_OpAdd)(cds); }
void CDerivedStats::LimitStats()										{ return (this->*CDerivedStats_LimitStats)(); }
short CDerivedStats::GetStat(int index)									{ return (this->*CDerivedStats_GetStat)(index); }
void CDerivedStats::LoadStats(CDerivedStatsTemplate& cds, int nSize)	{ return (this->*CDerivedStats_LoadStats)(cds, nSize); }
char CDerivedStats::GetEffectiveClericLevel(unsigned char nClass)		{ return (this->*CDerivedStats_GetEffectiveClericLevel)(nClass); }
char CDerivedStats::GetEffectiveMageLevel(unsigned char nClass)			{ return (this->*CDerivedStats_GetEffectiveMageLevel)(nClass); }
