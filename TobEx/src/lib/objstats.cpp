#include "objstats.h"

//CConditionalSpell
void* CConditionalSpell::operator new(size_t size)	{ return ::operator new(size, 0); }
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

//CSpellProtection
CSpellProtection::CSpellProtection() { strrefMsg = 0; }

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
int (CDerivedStats::*CDerivedStats_GetStat)(short) =
	SetFP(static_cast<int (CDerivedStats::*)(short)>						(&CDerivedStats::GetStat),					0x473162);
char (CDerivedStats::*CDerivedStats_GetSubclassLevel)(char, char) =
	SetFP(static_cast<char (CDerivedStats::*)(char, char)>					(&CDerivedStats::GetSubclassLevel),			0x473F40);
short (CDerivedStats::*CDerivedStats_GetMeanLevel)(char nClass) =
	SetFP(static_cast<short (CDerivedStats::*)(char)>						(&CDerivedStats::GetMeanLevel),				0x4740A2);
unsigned char (CDerivedStats::*CDerivedStats_GetFighterClassLevel)(unsigned char) =
	SetFP(static_cast<unsigned char (CDerivedStats::*)(unsigned char)>		(&CDerivedStats::GetFighterClassLevel),		0x474805);
unsigned char (CDerivedStats::*CDerivedStats_GetMageClassLevel)(unsigned char) =
	SetFP(static_cast<unsigned char (CDerivedStats::*)(unsigned char)>		(&CDerivedStats::GetMageClassLevel),		0x4748AE);
unsigned char (CDerivedStats::*CDerivedStats_GetThiefClassLevel)(unsigned char) =
	SetFP(static_cast<unsigned char (CDerivedStats::*)(unsigned char)>		(&CDerivedStats::GetThiefClassLevel),		0x47496D);
unsigned char (CDerivedStats::*CDerivedStats_GetClericClassLevel)(unsigned char) =
	SetFP(static_cast<unsigned char (CDerivedStats::*)(unsigned char)>		(&CDerivedStats::GetClericClassLevel),		0x4749F9);
void (CDerivedStats::*CDerivedStats_MarshalTemplate)(CDerivedStatsTemplate**, int*) =
	SetFP(static_cast<void (CDerivedStats::*)(CDerivedStatsTemplate**, int*)>(&CDerivedStats::MarshalTemplate),			0x474AAE);
void (CDerivedStats::*CDerivedStats_UnmarshalTemplate)(CDerivedStatsTemplate&, int) =
	SetFP(static_cast<void (CDerivedStats::*)(CDerivedStatsTemplate&, int)>
																			(&CDerivedStats::UnmarshalTemplate),		0x474AF2);
char (CDerivedStats::*CDerivedStats_GetEffectiveClericLevel)(unsigned char) =
	SetFP(static_cast<char (CDerivedStats::*)(unsigned char)>				(&CDerivedStats::GetEffectiveClericLevel),	0x4758AD);
char (CDerivedStats::*CDerivedStats_GetEffectiveMageLevel)(unsigned char) =
	SetFP(static_cast<char (CDerivedStats::*)(unsigned char)>				(&CDerivedStats::GetEffectiveMageLevel),	0x4759FA);
void (CDerivedStats::*CDerivedStats_Deconstruct)() =
	SetFP(static_cast<void (CDerivedStats::*)()>							(&CDerivedStats::Deconstruct),				0x567770);

CDerivedStats::CDerivedStats(CreFileData& stats, CreFileMemSpellLevel* memArrayMage, CreFileMemSpellLevel* memArrayPriest) {
	(this->*CDerivedStats_Construct_3)(stats, memArrayMage, memArrayPriest);
}
CDerivedStats::CDerivedStats()											{ (this->*CDerivedStats_Construct_0)(); }
void CDerivedStats::Init(CreFileData& stats, CreFileMemSpellLevel* memArrayMage, CreFileMemSpellLevel* memArrayPriest) {
	return (this->*CDerivedStats_Init)(stats, memArrayMage, memArrayPriest);
}
CDerivedStats& CDerivedStats::operator=(CDerivedStats& cds)						{ return (this->*CDerivedStats_OpAssign)(cds); }
void CDerivedStats::ClearStats()												{ return (this->*CDerivedStats_ClearStats)(); }
CDerivedStats& CDerivedStats::operator+(CDerivedStats& cds)						{ return (this->*CDerivedStats_OpAdd)(cds); }
void CDerivedStats::LimitStats()												{ return (this->*CDerivedStats_LimitStats)(); }
int CDerivedStats::GetStat(short nOpcode)										{ return (this->*CDerivedStats_GetStat)(nOpcode); }
char CDerivedStats::GetSubclassLevel(char nClass, char nSubclass)				{ return (this->*CDerivedStats_GetSubclassLevel)(nClass, nSubclass); }
short CDerivedStats::GetMeanLevel(char nClass)									{ return (this->*CDerivedStats_GetMeanLevel)(nClass); }
unsigned char CDerivedStats::GetFighterClassLevel(unsigned char cClass)			{ return (this->*CDerivedStats_GetFighterClassLevel)(cClass); }
unsigned char CDerivedStats::GetMageClassLevel(unsigned char cClass)			{ return (this->*CDerivedStats_GetMageClassLevel)(cClass); }
unsigned char CDerivedStats::GetThiefClassLevel(unsigned char cClass)			{ return (this->*CDerivedStats_GetThiefClassLevel)(cClass); }
unsigned char CDerivedStats::GetClericClassLevel(unsigned char cClass)			{ return (this->*CDerivedStats_GetClericClassLevel)(cClass); }
void CDerivedStats::MarshalTemplate(CDerivedStatsTemplate** ppcdst, int* pnSize){ return (this->*CDerivedStats_MarshalTemplate)(ppcdst, pnSize); }
void CDerivedStats::UnmarshalTemplate(CDerivedStatsTemplate& cds, int nSize)	{ return (this->*CDerivedStats_UnmarshalTemplate)(cds, nSize); }
char CDerivedStats::GetEffectiveClericLevel(unsigned char nClass)				{ return (this->*CDerivedStats_GetEffectiveClericLevel)(nClass); }
char CDerivedStats::GetEffectiveMageLevel(unsigned char nClass)					{ return (this->*CDerivedStats_GetEffectiveMageLevel)(nClass); }
CDerivedStats::~CDerivedStats()													{ (this->*CDerivedStats_Deconstruct)(); }
