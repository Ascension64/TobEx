#include "AnimationSound.h"

#include "utils.h"
#include "animcore.h"
#include "objcre.h"
#include "sndcore.h"
#include "areacore.h"
#include "chitin.h"

void DETOUR_CAnimation::DETOUR_PlayCurrentAnimationSequenceSound(CCreatureObject* pCre) {
	CAnimation::PlayCurrentAnimationSequenceSound(pCre);

	WORD wCycle, wFrame;
	GetCurrentAnimationCycleAndFrame(&wCycle, &wFrame);

	WORD wCurrentSequence = pCre->m_animation.wCurrentSequence;
	switch (wCurrentSequence) {
		case SEQ_ATTACK_SLASH: 
			soundset[SEQ_ATTACK_SLASH].PlayPrimedSound(wFrame, pCre);
			break;
		case SEQ_ATTACK_BACKSLASH:
			soundset[SEQ_ATTACK_BACKSLASH].PlayPrimedSound(wFrame, pCre);
			break;
		case SEQ_ATTACK_JAB:
			soundset[SEQ_ATTACK_JAB].PlayPrimedSound(wFrame, pCre);
			break;
		default:
			break;
	}

	return;
}