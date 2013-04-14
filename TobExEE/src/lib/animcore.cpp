//TobExEE
#include "animcore.h"
#include "p_animcore.h"

#include "stdafx.h"

//CAnimationSoundList
DefineLibMemberFunc(BOOL, CAnimationSoundList, PlayPrimedSound, (int dwFrame, CCreatureObject& cre), PlayPrimedSound, PlayPrimedSound, (dwFrame, cre), CANIMATIONSOUNDLIST_PLAYPRIMEDSOUND);

//CAnimation
DefineLibMemberFunc(void, CAnimation, PlayCurrentSequenceSound, (CCreatureObject& cre), PlayCurrentSequenceSound, PlayCurrentSequenceSound, (cre), CANIMATION_PLAYCURRENTSEQUENCESOUND);
