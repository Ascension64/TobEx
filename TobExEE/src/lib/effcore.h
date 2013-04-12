//TobExEE
#ifndef EFFCORE_H
#define EFFCORE_H

#include "stdafx.h"
#include "rescore.h"
#include "sndcore.h"

#define CEFFECT_DURATION_MAX	0x8888888

class CCreatureObject;
class CEffect;

struct ResEffFile { //Size 10h
	BOOL m_bLoaded; //0h
	ResEff* m_pRes; //4h
	ResRef m_rName; //8h
};

class CEffect { //Size 148h
	DEFINE_MEMALLOC_FUNC;
public:
	virtual ~CEffect(); //v0
	void Deconstruct() {} //dummy

	virtual CEffect& Copy(); //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
	virtual BOOL ApplyTiming(CCreatureObject& creTarget); //vc, calls ApplyEffect
	virtual void OnDelayFinished(CCreatureObject& creTarget); //v10
	virtual void v14() {}
	virtual void OnAdd(CCreatureObject& creTarget); //v18, to CEffectList
	virtual BOOL CheckNotSaved(
		CCreatureObject& creTarget,
		char& rollSaveDeath,
		char& rollSaveWands,
		char& rollSavePoly,
		char& rollSaveBreath,
		char& rollSaveSpells,
		char& rollMagicResist
	); //v1c
	virtual BOOL IgnoreLevelCheck(); //v20
	virtual void PrintEffectText(CCreatureObject& creTarget); //v24
	virtual void OnRemove(CCreatureObject& creTarget); //v28, from CEffectList

	EffFileData effect; //4h
	ENUM eSource; //10ch
	BOOL bPurge; //110h - deconstruct and remove effect from CEffectList after application
	BOOL bRefreshStats; //114h - use if you change a m_header member, sets bApplyEffectsAgain in CEffectList, repeating effect application
	int nDurationAfterDelay; //118h

	//used like wildcards when checking against a CEffectList element
	BOOL m_bMatchOpcode; //11ch, match any with same opcode
	BOOL m_bMatchOpcodeParam2; //120h, match any with same opcode and param2
	BOOL m_bMatchOpcodeParam1; //124h, match any with same opcode and param1
	BOOL m_bMatchOpcodeResource; //128h, match any with same opcode and resource
	CSoundWrapper m_snd; //12ch
	ENUM enum2; //144h, Arg7, inherits value of Cre+30h for a global effect of an item equipped by the Cre
};

class CEffectList : public IECPtrList { //Size 2Ch
public:
	POSITION posCurrent; //1ch
	POSITION posItrPrev; //20h
	int u24; //24h
	BOOL bRefreshStats; //28h
};

#endif //EFFCORE_H