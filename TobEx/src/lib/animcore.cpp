#include "animcore.h"

#include "utils.h"

BOOL (CAnimationSoundList::*CAnimationSoundList_PlayPrimedSound)(DWORD, CCreatureObject*) =
	SetFP(static_cast<BOOL (CAnimationSoundList::*)(DWORD, CCreatureObject*)>	(&CAnimationSoundList::PlayPrimedSound),	0x642E3D);

BOOL CAnimationSoundList::PlayPrimedSound(DWORD dwFrame, CCreatureObject* pCre) { return (this->*CAnimationSoundList_PlayPrimedSound)(dwFrame, pCre); }

void (CAnimation::*CAnimation_PlayCurrentAnimationSequenceSound)(CCreatureObject*) =
	SetFP(static_cast<void (CAnimation::*)(CCreatureObject*)>	(&CAnimation::PlayCurrentAnimationSequenceSound),	0x7F9DF4);

void CAnimation::PlayCurrentAnimationSequenceSound(CCreatureObject* pCre) { return (this->*CAnimation_PlayCurrentAnimationSequenceSound)(pCre); }
