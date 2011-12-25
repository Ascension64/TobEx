#ifndef ANIMATIONCORE_H
#define ANIMATIONCORE_H

#include "animcore.h"

extern void (CAnimation::*Tramp_CAnimation_PlayCurrentSequenceSound)(CCreatureObject&);
extern BOOL (*Tramp_CAnimation_IsPlayableAnimation)(unsigned short);
extern LPCTSTR (CAnimation::*Tramp_CAnimation_GetWalkingSound)(short);

class DETOUR_CAnimation : public CAnimation {
public:
	void DETOUR_PlayCurrentSequenceSound(CCreatureObject& cre);
	static BOOL DETOUR_IsPlayableAnimation(unsigned short wAnimId);
	LPCTSTR DETOUR_GetWalkingSound(short wTerrainCode);
};

#endif //ANIMATIONCORE_H