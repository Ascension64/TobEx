#ifndef ANIMATIONCORE_H
#define ANIMATIONCORE_H

#include "animcore.h"

extern void (CAnimation::*Tramp_CAnimation_PlayCurrentSequenceSound)(CCreatureObject*);
extern BOOL (*Tramp_CAnimation_IsPlayableAnimation)(WORD);
extern LPCTSTR (CAnimation::*Tramp_CAnimation_GetWalkingSound)(WORD);

class DETOUR_CAnimation : public CAnimation {
public:
	void DETOUR_PlayCurrentSequenceSound(CCreatureObject*);
	static BOOL DETOUR_IsPlayableAnimation(WORD);
	LPCTSTR DETOUR_GetWalkingSound(WORD);
};

#endif //ANIMATIONCORE_H