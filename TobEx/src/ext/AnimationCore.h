#ifndef ANIMATIONCORE_H
#define ANIMATIONCORE_H

#include "animcore.h"

DeclareTrampMemberFunc(void, CAnimation, PlayCurrentSequenceSound, (CCreatureObject& cre), PlayCurrentSequenceSound);
DeclareTrampStaticFunc(BOOL, __cdecl, CAnimation, IsPlayableAnimation, (unsigned short wAnimId), IsPlayableAnimation);
DeclareTrampMemberFunc(LPCTSTR, CAnimation, GetWalkingSound, (short wTerrainCode), GetWalkingSound);

class DETOUR_CAnimation : public CAnimation {
public:
	void DETOUR_PlayCurrentSequenceSound(CCreatureObject& cre);
	static BOOL DETOUR_IsPlayableAnimation(unsigned short wAnimId);
	LPCTSTR DETOUR_GetWalkingSound(short wTerrainCode);
};

#endif //ANIMATIONCORE_H