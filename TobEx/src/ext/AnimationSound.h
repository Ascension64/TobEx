#ifndef ANIMATIONSOUND_H
#define ANIMATIONSOUND_H

#include "animcore.h"

class DETOUR_CAnimation : public CAnimation {
public:
	void DETOUR_PlayCurrentAnimationSequenceSound(CCreatureObject*);
};

#endif //ANIMATIONSOUND_H