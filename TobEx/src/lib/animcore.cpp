#include "animcore.h"

#include "stdafx.h"

//CAnimationSoundList
DefineLibMemberFunc(BOOL, CAnimationSoundList, PlayPrimedSound, (int dwFrame, CCreatureObject& cre), PlayPrimedSound, PlayPrimedSound, (dwFrame, cre), 0x642E3D);

//CAnimation
DefineLibNoRetFunc(CAnimation&, CAnimation, CAnimation, (), Construct, Construct, (), 0x7F9211);
DefineLibMemberFunc(void, CAnimation, PlayCurrentSequenceSound, (CCreatureObject& cre), PlayCurrentSequenceSound, PlayCurrentSequenceSound, (cre), 0x7F9DF4);
DefineLibStaticFunc(CAnimation*, __cdecl, CAnimation, CreateAnimation, (unsigned short wAnimId, CreFileColors& colors, unsigned short wOrient), CreateAnimation, (wAnimId, colors, wOrient), 0x7F9EBC);
DefineLibStaticFunc(BOOL, __cdecl, CAnimation, IsPlayableAnimation, (unsigned short wAnimId), IsPlayableAnimation, (wAnimId), 0x85F364);
DefineLibMemberFunc(LPCTSTR, CAnimation, GetWalkingSound, (short wTerrainCode), GetWalkingSound, GetWalkingSound, (wTerrainCode), 0x87B7B0);
DefineLibMemberFunc(bool, CAnimation, GetCurrentCycleAndFrame, (short& wCycle, short& wFrame), GetCurrentCycleAndFrame, GetCurrentCycleAndFrame, (wCycle, wFrame), 0x87BA10);
