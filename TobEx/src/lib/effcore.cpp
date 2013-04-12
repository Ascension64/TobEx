#include "effcore.h"

//ResEffFile
DefineLibNoRetFunc(ResEffFile&, ResEffFile, ResEffFile, (ResRef r), Construct, Construct, (r), 0x4F2810);
DefineLibNoRetFunc(void, ResEffFile, ~ResEffFile, (), Deconstruct, Deconstruct, (), 0x4E27C0);
DefineLibMemberFunc(CEffect&, ResEffFile, CreateCEffect, (), CreateCEffect, CreateCEffect, (), 0x4F299B);

//CEffect
DefineLibNoRetFunc(CEffect&, CEffect, CEffect, (), Construct, Construct0, (), 0x465440);
DefineLibNoRetFunc(CEffect&, CEffect, CEffect, (ItmFileEffect& data, CPoint& ptSource, ENUM eSource, int destX, int destY, BOOL bUseDice, ENUM e2), Construct, Construct7, (data, ptSource, eSource, destX, destY, bUseDice, e2), 0x4F34C8);
DefineLibMemberFunc(void, CEffect, operator=, (CEffect& eff), OpAssign, OpAssign, (eff), 0x4F3A61);
DefineLibMemberFunc(void, CEffect, Unmarshal, (EffFileData& data), Unmarshal, Unmarshal, (data), 0x4F3BEC);
DefineLibNoRetFunc(CEffect&, CEffect, CEffect, (EffFileData& data), Construct, Construct1, (data), 0x4F3E67);
DefineLibStaticFunc(CEffect&, __cdecl, CEffect, DecodeEffect, (ItmFileEffect& data, CPoint& ptSource, ENUM eSource, CPoint& ptDest, ENUM e2), DecodeEffect, (data, ptSource, eSource, ptDest, e2), 0x4F3EC2);
DefineLibStaticFunc(void, __cdecl, CEffect, ClearItemEffect, (ItmFileEffect& ptr, int nOpcode), ClearItemEffect, (ptr, nOpcode), 0x4FFC3E);
DefineLibMemberFunc(void, CEffect, PlaySound, (ResRef& rSound, CCreatureObject& cre), PlaySound, PlaySound, (rSound, cre), 0x4FFCCF);
DefineLibMemberFunc(BOOL, CEffect, IsExpired, (), IsExpired, IsExpired, (), 0x500517);
DefineLibMemberFunc(BOOL, CEffect, TryApplyEffect, (
	CCreatureObject& creTarget,
	char* pcSaveDeath,
	char* pcSaveWands,
	char* pcSavePoly,
	char* pcSaveBreath,
	char* pcSaveSpells,
	char* pcResistMagic,
	char* pcEffProb
	), TryApplyEffect, TryApplyEffect, (creTarget, pcSaveDeath, pcSaveWands, pcSavePoly, pcSaveBreath, pcSaveSpells, pcResistMagic, pcEffProb), 0x5006AF);
DefineLibMemberFunc(ItmFileEffect&, CEffect, ToItemEffect, (), ToItemEffect, ToItemEffect, (), 0x50270A);

DefineLibNoRetFunc(void, CEffect, ~CEffect, (), Deconstruct, Deconstruct, (), 0x465810);
DefineLibMemberFunc(CEffect&, CEffect, Copy, (), Copy, Copy, (), 0x465730);
DefineLibMemberFunc(BOOL, CEffect, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect, ApplyEffect, (creTarget), 0x465760);
DefineLibMemberFunc(BOOL, CEffect, ApplyTiming, (CCreatureObject& creTarget), ApplyTiming, ApplyTiming, (creTarget), 0x4FFFA0);
DefineLibMemberFunc(void, CEffect, OnDelayFinished, (CCreatureObject& creTarget), OnDelayFinished, OnDelayFinished, (creTarget), 0x4657A0);
DefineLibMemberFunc(void, CEffect, OnAdd, (CCreatureObject& creTarget), OnAdd, OnAdd, (creTarget), 0x4657B0);
DefineLibMemberFunc(BOOL, CEffect, CheckNotSaved, (
	CCreatureObject& creTarget,
	char& rollSaveDeath,
	char& rollSaveWands,
	char& rollSavePoly,
	char& rollSaveBreath,
	char& rollSaveSpells,
	char& rollMagicResist
	), CheckNotSaved, CheckNotSaved, (creTarget, rollSaveDeath, rollSaveWands, rollSavePoly, rollSaveBreath, rollSaveSpells, rollMagicResist), 0x501B29);
DefineLibMemberFunc(BOOL, CEffect, IgnoreLevelCheck, (), IgnoreLevelCheck, IgnoreLevelCheck, (), 0x4657C0);
DefineLibMemberFunc(void, CEffect, PrintEffectText, (CCreatureObject& creTarget), PrintEffectText, PrintEffectText, (creTarget), 0x50284F);
DefineLibMemberFunc(void, CEffect, OnRemove, (CCreatureObject& creTarget), OnRemove, OnRemove, (creTarget), 0x4657D0);

//CEffectList
DefineLibMemberFunc(BOOL, CEffectList, RemoveOneEffect, (CEffect& eff, CCreatureObject& cre, BOOL bMatchSourceAndParent), RemoveOneEffect, RemoveOneEffect, (eff, cre, bMatchSourceAndParent), 0x542F03);
DefineLibMemberFunc(void, CEffectList, RemoveEffect, (
	CCreatureObject& creTarget,
	int nOpcode,
	POSITION posSkip,
	int nParam2,
	ResRef rResource,
	BOOL bCheckPermTiming
	), RemoveEffect, RemoveEffect, (creTarget, nOpcode, posSkip, nParam2, rResource, bCheckPermTiming), 0x54306D);
DefineLibMemberFunc(void, CEffectList, TryDispel, (
	CCreatureObject& creTarget,
	POSITION posSkip,
	BOOL bCheckDispellableFlag,
	BOOL bCheckProbability,
	char cRand,
	char cDispelLevel
	), TryDispel, TryDispel, (creTarget, posSkip, bCheckDispellableFlag, bCheckProbability, cRand, cDispelLevel), 0x543EC8);
DefineLibMemberFunc(BOOL, CEffectList, ApplyEffects, (CCreatureObject& cre), ApplyEffects, ApplyEffects, (cre), 0x544C0B);
DefineLibMemberFunc(POSITION, CEffectList, GetCurrentPosition, (), GetCurrentPosition, GetCurrentPosition, (), 0x5661A0);
