//TobExEE
#include "AnimationCore.h"
#include "p_animcore.h"

#include "objcre.h"

DefineTrampMemberFunc(void, CAnimation, PlayCurrentSequenceSound, (CCreatureObject& cre), PlayCurrentSequenceSound, PlayCurrentSequenceSound, CANIMATION_PLAYCURRENTSEQUENCESOUND);

void DETOUR_CAnimation::DETOUR_PlayCurrentSequenceSound(CCreatureObject& cre) {
	(this->*Tramp_CAnimation_PlayCurrentSequenceSound)(cre);

	short wCycle, wFrame;
	GetCurrentCycleAndFrame(wCycle, wFrame);

	short wCurrentSequence = cre.m_animation.m_wCurrentSequence;
	switch (wCurrentSequence) {
		case SEQ_ATTACK_SLASH: 
			m_soundset[SEQ_ATTACK_SLASH].PlayPrimedSound(wFrame, cre);
			break;
		case SEQ_ATTACK_BACKSLASH:
			m_soundset[SEQ_ATTACK_BACKSLASH].PlayPrimedSound(wFrame, cre);
			break;
		case SEQ_ATTACK_JAB:
			m_soundset[SEQ_ATTACK_JAB].PlayPrimedSound(wFrame, cre);
			break;
		default:
			break;
	}

	return;
}
