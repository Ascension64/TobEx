#include "objstats.h"

//CConditionalSpellList
DefineLibMemberFunc(void, CConditionalSpellList, EvaluateTriggers, (CCreatureObject& cre), EvaluateTriggers, EvaluateTriggers, (cre), 0x46BE04);

//CRepeatingEffBase
DefineLibNoRetFunc(CRepeatingEffBase&, CRepeatingEffBase, CRepeatingEffBase, (), Construct, Construct, (), 0x5662C0);

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
DefineLibMemberFunc(void, CRepeatingEff, Update, (CCreatureObject& cre, int nTicks), Update, Update, (cre, nTicks), 0x54772D);

//CRepeatingWingBuffet
CRepeatingWingBuffet::CRepeatingWingBuffet() {
	SetVT(this, 0xAA9A10);
	wType = 6;
	wMode = 1;
	nDistance = 6;
	ptOrigin.x = 0;
	ptOrigin.y = 0;
	eOrigin = ENUM_INVALID_INDEX;
}
DefineLibMemberFunc(void, CRepeatingWingBuffet, Update, (CCreatureObject& cre, int nTicks), Update, Update, (cre, nTicks), 0x547161);

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

//CStatModVsObjectList
DefineLibMemberFunc(int, CStatModVsObjectList, GetModValue, (Object& o), GetModValue, GetModValue, (o), 0x5A6C0D);

//CDerivedStats
DefineLibNoRetFunc(CDerivedStats&, CDerivedStats, CDerivedStats, (
	CreFileHeader& stats,
	CreFileMemorizedSpellLevel* memArrayMage,
	CreFileMemorizedSpellLevel* memArrayPriest
	), Construct, Construct3, (stats, memArrayMage, memArrayPriest), 0x46CB40);
DefineLibNoRetFunc(CDerivedStats&, CDerivedStats, CDerivedStats, (), Construct, Construct, (), 0x46D1B2);
DefineLibMemberFunc(void, CDerivedStats, Init, (
	CreFileHeader& stats,
	CreFileMemorizedSpellLevel* memArrayMage,
	CreFileMemorizedSpellLevel* memArrayPriest
	), Init, Init, (stats, memArrayMage, memArrayPriest), 0x46DB9C);
DefineLibMemberFunc(CDerivedStats&, CDerivedStats, operator=, (CDerivedStats& cds), OpAssign, OpAssign, (cds), 0x46EAC6);
DefineLibMemberFunc(void, CDerivedStats, ClearStats, (), ClearStats, ClearStats, (), 0x46FCF5);
DefineLibMemberFunc(CDerivedStats&, CDerivedStats, operator+, (CDerivedStats& cds), OpAdd, OpAdd, (cds), 0x470945);
DefineLibMemberFunc(void, CDerivedStats, LimitStats, (), LimitStats, LimitStats, (), 0x471B36);
DefineLibMemberFunc(int, CDerivedStats, GetStat, (short nOpcode), GetStat, GetStat, (nOpcode), 0x473162);
DefineLibMemberFunc(char, CDerivedStats, GetSubclassLevel, (char nClass, char nSubclass), GetSubclassLevel, GetSubclassLevel, (nClass, nSubclass), 0x473F40);
DefineLibMemberFunc(short, CDerivedStats, GetMeanLevel, (char nClass), GetMeanLevel, GetMeanLevel, (nClass), 0x4740A2);
DefineLibMemberFunc(unsigned char, CDerivedStats, GetFighterClassLevel, (unsigned char cClass), GetFighterClassLevel, GetFighterClassLevel, (cClass), 0x474805);
DefineLibMemberFunc(unsigned char, CDerivedStats, GetMageClassLevel, (unsigned char cClass), GetMageClassLevel, GetMageClassLevel, (cClass), 0x4748AE);
DefineLibMemberFunc(unsigned char, CDerivedStats, GetThiefClassLevel, (unsigned char cClass), GetThiefClassLevel, GetThiefClassLevel, (cClass), 0x47496D);
DefineLibMemberFunc(unsigned char, CDerivedStats, GetClericClassLevel, (unsigned char cClass), GetClericClassLevel, GetClericClassLevel, (cClass), 0x4749F9);
DefineLibMemberFunc(void, CDerivedStats, MarshalTemplate, (CDerivedStatsTemplate** ppcdst, int* pnSize), MarshalTemplate, MarshalTemplate, (ppcdst, pnSize), 0x474AAE);
DefineLibMemberFunc(void, CDerivedStats, UnmarshalTemplate, (CDerivedStatsTemplate& cds, int nSize), UnmarshalTemplate, UnmarshalTemplate, (cds, nSize), 0x474AF2);
DefineLibMemberFunc(char, CDerivedStats, GetEffectiveClericLevel, (unsigned char nClass), GetEffectiveClericLevel, GetEffectiveClericLevel, (nClass), 0x4758AD);
DefineLibMemberFunc(char, CDerivedStats, GetEffectiveMageLevel, (unsigned char nClass), GetEffectiveMageLevel, GetEffectiveMageLevel, (nClass), 0x4759FA);
DefineLibNoRetFunc(void, CDerivedStats, ~CDerivedStats, (), Deconstruct, Deconstruct, (), 0x567770);
