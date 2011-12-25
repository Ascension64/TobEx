#include "animcore.h"

#include "stdafx.h"

//CAnimationSoundList
BOOL (CAnimationSoundList::*CAnimationSoundList_PlayPrimedSound)(int, CCreatureObject&) =
	SetFP(static_cast<BOOL (CAnimationSoundList::*)(int, CCreatureObject&)>	(&CAnimationSoundList::PlayPrimedSound),	0x642E3D);

BOOL CAnimationSoundList::PlayPrimedSound(int dwFrame, CCreatureObject& cre) { return (this->*CAnimationSoundList_PlayPrimedSound)(dwFrame, cre); }

//CAnimation
CAnimation& (CAnimation::*CAnimation_Construct)() =
	SetFP(static_cast<CAnimation& (CAnimation::*)()>			(&CAnimation::Construct),					0x7F9211);
void (CAnimation::*CAnimation_PlayCurrentSequenceSound)(CCreatureObject&) =
	SetFP(static_cast<void (CAnimation::*)(CCreatureObject&)>	(&CAnimation::PlayCurrentSequenceSound),	0x7F9DF4);
BOOL (*CAnimation_IsPlayableAnimation)(unsigned short) =
	reinterpret_cast<BOOL (*)(unsigned short)>																(0x85F364);
LPCTSTR (CAnimation::*CAnimation_GetWalkingSound)(short) =
	SetFP(static_cast<LPCTSTR (CAnimation::*)(short)>			(&CAnimation::GetWalkingSound),				0x87B7B0);
bool (CAnimation::*CAnimation_GetCurrentCycleAndFrame)(short&, short&) =
	SetFP(static_cast<bool (CAnimation::*)(short&, short&)>		(&CAnimation::GetCurrentCycleAndFrame),		0x87BA10);

CAnimation::CAnimation()												{ (this->*CAnimation_Construct)(); }
void CAnimation::PlayCurrentSequenceSound(CCreatureObject& cre)			{ return (this->*CAnimation_PlayCurrentSequenceSound)(cre); }
BOOL CAnimation::IsPlayableAnimation(unsigned short wAnimId)			{ return (*CAnimation_IsPlayableAnimation)(wAnimId); }
LPCTSTR CAnimation::GetWalkingSound(short wTerrainCode)					{ return (this->*CAnimation_GetWalkingSound)(wTerrainCode); }
bool CAnimation::GetCurrentCycleAndFrame(short& wCycle, short& wFrame)	{ return (this->*CAnimation_GetCurrentCycleAndFrame)(wCycle, wFrame); }
