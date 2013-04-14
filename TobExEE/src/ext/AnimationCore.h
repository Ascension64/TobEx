//TobExEE
#ifndef ANIMATIONCORE_H
#define ANIMATIONCORE_H

#include "animcore.h"

DeclareTrampMemberFunc(void, CAnimation, PlayCurrentSequenceSound, (CCreatureObject& cre), PlayCurrentSequenceSound);

class DETOUR_CAnimation : public CAnimation {
public:
	void DETOUR_PlayCurrentSequenceSound(CCreatureObject& cre);
};

#endif //ANIMATIONCORE_H