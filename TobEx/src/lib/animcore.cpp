#include "animcore.h"

#include "utils.h"

//CAnimationSoundList
BOOL (CAnimationSoundList::*CAnimationSoundList_PlayPrimedSound)(DWORD, CCreatureObject*) =
	SetFP(static_cast<BOOL (CAnimationSoundList::*)(DWORD, CCreatureObject*)>	(&CAnimationSoundList::PlayPrimedSound),	0x642E3D);

BOOL CAnimationSoundList::PlayPrimedSound(DWORD dwFrame, CCreatureObject* pCre) { return (this->*CAnimationSoundList_PlayPrimedSound)(dwFrame, pCre); }

//CAnimation
CAnimation& (CAnimation::*CAnimation_Construct)() =
	SetFP(static_cast<CAnimation& (CAnimation::*)()>			(&CAnimation::Construct),					0x7F9211);
void (CAnimation::*CAnimation_PlayCurrentSequenceSound)(CCreatureObject*) =
	SetFP(static_cast<void (CAnimation::*)(CCreatureObject*)>	(&CAnimation::PlayCurrentSequenceSound),	0x7F9DF4);
BOOL (*CAnimation_IsPlayableAnimation)(WORD) =
	reinterpret_cast<BOOL (*)(WORD)>																		(0x85F364);
LPCTSTR (CAnimation::*CAnimation_GetWalkingSound)(WORD) =
	SetFP(static_cast<LPCTSTR (CAnimation::*)(WORD)>			(&CAnimation::GetWalkingSound),				0x87B7B0);
bool (CAnimation::*CAnimation_GetCurrentCycleAndFrame)(WORD&, WORD&) =
	SetFP(static_cast<bool (CAnimation::*)(WORD&, WORD&)>		(&CAnimation::GetCurrentCycleAndFrame),		0x87BA10);

CAnimation::CAnimation()												{ (this->*CAnimation_Construct)(); }
void CAnimation::PlayCurrentSequenceSound(CCreatureObject* pCre)		{ return (this->*CAnimation_PlayCurrentSequenceSound)(pCre); }
BOOL CAnimation::IsPlayableAnimation(WORD wAnimId)						{ return (*CAnimation_IsPlayableAnimation)(wAnimId); }
LPCTSTR CAnimation::GetWalkingSound(WORD wTerrainCode)					{ return (this->*CAnimation_GetWalkingSound)(wTerrainCode); }
bool CAnimation::GetCurrentCycleAndFrame(WORD& wCycle, WORD& wFrame)	{ return (this->*CAnimation_GetCurrentCycleAndFrame)(wCycle, wFrame); }
