#ifndef EFFECTCORE_H
#define EFFECTCORE_H

#include "stdafx.h"
#include "effcore.h"
#include "objcre.h"

//CEffect
DeclareTrampStaticFunc(CEffect&, __cdecl, CEffect, DecodeEffect, (ItmFileEffect& eff, CPoint& ptSource, ENUM eSource, CPoint& ptDest, ENUM e2), DecodeEffect);
DeclareTrampMemberFunc(BOOL, CEffect, ApplyTiming, (CCreatureObject& creTarget), ApplyTiming);
DeclareTrampMemberFunc(BOOL, CEffect, CheckNotSaved, (
	CCreatureObject& creTarget,
	char& rollSaveDeath,
	char& rollSaveWands,
	char& rollSavePoly,
	char& rollSaveBreath,
	char& rollSaveSpells,
	char& rollMagicResist
	), CheckNotSaved);

class DETOUR_CEffect : public CEffect {
public:
	static CEffect& DETOUR_DecodeEffect(ItmFileEffect& eff, CPoint& ptSource, ENUM eSource, CPoint& ptDest, ENUM e2);
	BOOL DETOUR_ApplyTiming(CCreatureObject& creTarget);
	BOOL DETOUR_CheckNotSaved(CCreatureObject& creTarget, char& rollSaveDeath, char& rollSaveWands, char& rollSavePoly, char& rollSaveBreath, char& rollSaveSpells, char& rollMagicResist);
};

//CEffectList
DeclareTrampMemberFunc(void, CEffectList, TryDispel, (
	CCreatureObject& creTarget,
	POSITION posSkip,
	BOOL bCheckDispellableFlag,
	BOOL bCheckProbability,
	char cRand,
	char cDispelLevel
	), TryDispel);

class DETOUR_CEffectList : public CEffectList {
public:
	void DETOUR_TryDispel(CCreatureObject& creTarget, POSITION posSkip, BOOL bCheckDispellableFlag, BOOL bCheckProbability, char cRand, char cDispelLevel);
};

#endif //EFFECTCORE_H