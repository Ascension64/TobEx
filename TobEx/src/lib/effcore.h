#ifndef EFFCORE_H
#define EFFCORE_H

#include "stdafx.h"
#include "rescore.h"
#include "sndcore.h"

typedef void* CEffectVirtualTable[10];

#define CEFFECT_DURATION_MAX	0x8888888

class CCreatureObject;
class CEffect;

struct ResEffFile { //Size 10h
//Constructor: 0x4F2810
	ResEffFile(ResRef r);
	ResEffFile& Construct(ResRef r) { return *this; } //dummy

	~ResEffFile();
	void Deconstruct() {} //dummy

	CEffect& CreateCEffect();

	BOOL bLoaded; //0h
	ResEff* pRes; //4h
	ResRef name; //8h
};

class CEffect { //Size 19Ah
	DEFINE_MEMALLOC_FUNC;
public:
	CEffect();
	CEffect& Construct() { return *this; } //dummy

	CEffect(ItmFileEffect& data, CPoint& ptSource, ENUM eSource, int destX, int destY, BOOL bUseDice, ENUM e2); //4F34C8
	CEffect& Construct(ItmFileEffect& data, CPoint& ptSource, ENUM eSource, int destX, int destY, BOOL bUseDice, ENUM e2) {return *this;} //dummy

	void operator=(CEffect& eff);
	void OpAssign(CEffect& eff) {} //dummy

	void Unmarshal(EffFileData& data);

	CEffect(EffFileData& data);
	CEffect& Construct(EffFileData&) {return *this;} //dummy

	static CEffect& DecodeEffect(ItmFileEffect& data, CPoint& ptSource, ENUM eSource, CPoint& ptDest, ENUM e2);
	static void CEffect::ClearItemEffect(ItmFileEffect& ptr, int nOpcode);

	void PlaySound(ResRef& rSound, CCreatureObject& cre);
	BOOL IsExpired();
	BOOL TryApplyEffect(
		CCreatureObject& creTarget,
		char* pcSaveDeath,
		char* pcSaveWands,
		char* pcSavePoly,
		char* pcSaveBreath,
		char* pcSaveSpells,
		char* pcResistMagic,
		char* pcEffProb
	);
	ItmFileEffect& ToItemEffect();

	//AA6378
	virtual ~CEffect(); //v0
	void Deconstruct() {} //dummy

	virtual CEffect& Copy(); //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
	virtual BOOL ApplyTiming(CCreatureObject& creTarget); //vc, calls ApplyEffect
	virtual void OnDelayFinished(CCreatureObject& creTarget); //v10
	virtual void OnAdd(CCreatureObject& creTarget); //v14, on addition to CEffectList
	virtual BOOL CheckNotSaved(
		CCreatureObject& creTarget,
		char& rollSaveDeath,
		char& rollSaveWands,
		char& rollSavePoly,
		char& rollSaveBreath,
		char& rollSaveSpells,
		char& rollMagicResist
	); //v18
	virtual BOOL IgnoreLevelCheck(); //v1c
	virtual void PrintEffectText(CCreatureObject& creTarget); //v20
	virtual void OnRemove(CCreatureObject& creTarget); //v24, on removal from CEffectList

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
	CSound sound;
	ENUM enum2; //196h, Arg7, inherits value of Cre+30h for a global effect of an item equipped by the Cre
};

class CEffectList : public IECPtrList { //Size 2Ch
public:
	//AAA8A8
	BOOL RemoveOneEffect(CEffect& eff, CCreatureObject& cre, BOOL bMatchSourceAndParent);
	void RemoveEffect(CCreatureObject& creTarget, int nOpcode, POSITION posSkip, int nParam2, ResRef rResource, BOOL bCheckPermTiming);
	void TryDispel(CCreatureObject& creTarget, POSITION posSkip, BOOL bCheckDispellableFlag, BOOL bCheckProbability, char cRand, char cDispelLevel);
	BOOL ApplyEffects(CCreatureObject& cre);
	POSITION GetCurrentPosition();

	POSITION posCurrent; //1ch
	POSITION posItrPrev; //20h
	int u24; //24h
	BOOL bRefreshStats; //28h
};

#endif //EFFCORE_H