#include "scrcore.h"

//Identifiers
DefineLibNoRetFunc(Identifiers&, Identifiers, Identifiers, (), Construct, Construct0, (), 0x40FB70);
DefineLibNoRetFunc(Identifiers&, Identifiers, Identifiers, (ResRef rFile), Construct, Construct1, (rFile), 0x40FC37);
DefineLibNoRetFunc(void, Identifiers, ~Identifiers, (), Deconstruct, Deconstruct, (), 0x40FE31);
DefineLibMemberFunc(IdsEntry*, Identifiers, FindByHead, (IECString sValue, BOOL bCaseSensitive), FindByHead, FindByHead, (sValue, bCaseSensitive), 0x410502);

//CVariable
DefineLibMemberFunc(void, CVariable, SetName, (IECString s), SetName, SetName, (s), 0x45FD80);
DefineLibNoRetFunc(CVariable&, CVariable, CVariable, (), Construct, Construct, (), 0x4B6850);
DefineLibMemberFunc(CVariable&, CVariable, operator=, (CVariable& var), OpAssign, OpAssign, (var), 0x4B68C0);
DefineLibMemberFunc(IECString, CVariable, GetName, (), GetName, GetName, (), 0x54DE90);

//CVariableMap
DefineLibNoRetFunc(CVariableMap&, CVariableMap, CVariableMap, (int nSize), Construct, Construct, (nSize), 0x64A1E0);
DefineLibNoRetFunc(void, CVariableMap, ~CVariableMap, (), Deconstruct, Deconstruct, (), 0x64A2C7);
DefineLibMemberFunc(BOOL, CVariableMap, Add, (CVariable& var), Add, Add, (var), 0x64A2E8);
DefineLibMemberFunc(CVariable&, CVariableMap, Find, (IECString sVar), Find, Find, (sVar), 0x64A709);
DefineLibMemberFunc(unsigned int, CVariableMap, GetHash, (IECString sVar), GetHash, GetHash, (sVar), 0x64A96E);
DefineLibMemberFunc(void, CVariableMap, Empty, (), Empty, Empty, (), 0x64AA27);
DefineLibMemberFunc(void, CVariableMap, SetSize, (int nSize), SetSize, SetSize, (nSize), 0x64B23D);

//ObjectIds
ObjectIds::ObjectIds() {
	id1 = OBJECT_NOTHING;
	id2 = OBJECT_NOTHING;
	id3 = OBJECT_NOTHING;
	id4 = OBJECT_NOTHING;
	id5 = OBJECT_NOTHING;
}

char ObjectIds::operator[](unsigned int n) {
	return n < 5 ? *((unsigned char*)this + n) : 0;
}

//Object
Object::Object() { Object(0, 0, 0, 0, 0, 0, 0, -1); }
DefineLibNoRetFunc(Object&, Object, Object, (
	unsigned char cEnemyAlly,
	unsigned char cGeneral,
	unsigned char cRace,
	unsigned char cClass,
	unsigned char cSpecific,
	unsigned char cGender,
	unsigned char cAlignment,
	ENUM eTarget,
	ObjectIds* poids,
	IECString& sName
	), Construct, Construct10, (cEnemyAlly, cGeneral, cRace, cClass, cSpecific, cGender, cAlignment, eTarget, poids, sName), 0x410C14);
DefineLibNoRetFunc(Object&, Object, Object, (
	unsigned char cEnemyAlly,
	unsigned char cGeneral,
	unsigned char cRace,
	unsigned char cClass,
	unsigned char cSpecific,
	unsigned char cGender,
	unsigned char cAlignment,
	ENUM eTarget
	), Construct, Construct8, (cEnemyAlly, cGeneral, cRace, cClass, cSpecific, cGender, cAlignment, eTarget), 0x410CEE);
DefineLibMemberFunc(bool, Object, MatchCriteria, (
	Object& oCriteria,
	BOOL bAnyIncludesNonScript,
	BOOL bExcludeNonScript,
	BOOL bEAGroupMatch
	), MatchCriteria, MatchCriteria, (oCriteria, bAnyIncludesNonScript, bExcludeNonScript, bEAGroupMatch), 0x410D9E);
DefineLibMemberFunc(void, Object, operator=, (Object& o), OpAssign, OpAssign, (o), 0x4119BD);
DefineLibMemberFunc(void, Object, DecodeIdentifiers, (CGameSprite& spriteSource), DecodeIdentifiers, DecodeIdentifiers, (spriteSource), 0x411A4C);
DefineLibMemberFunc(CGameObject&, Object, FindTargetOfType, (CGameObject& source, char type, BOOL bCheckMiddleList), FindTargetOfType, FindTargetOfType, (source, type, bCheckMiddleList), 0x414EA9);
DefineLibMemberFunc(CGameObject&, Object, FindTarget, (CGameObject& source, BOOL bCheckMiddleList), FindTarget, FindTarget, (source, bCheckMiddleList), 0x414FA8);
DefineLibMemberFunc(void, Object, SetIdentifiers, (ObjectIds& ids), SetIdentifiers, SetIdentifiers, (ids), 0x41531E);
DefineLibMemberFunc(Object, Object, GetOpposingEAObject, (), GetOpposingEAObject, GetOpposingEAObject, (), 0x4157E9);
DefineLibMemberFunc(unsigned char, Object, GetClass, (), GetClass, GetClass, (), 0x4158A4);
DefineLibMemberFunc(void, Object, GetDualClasses, (unsigned char* pClassNew, unsigned char* pClassOrg), GetDualClasses, GetDualClasses, (pClassNew, pClassOrg), 0x4158B5);
DefineLibMemberFunc(BOOL, Object, HasActiveSubclass, (unsigned char nSubclass, BOOL bThreadAsync), HasActiveSubclass, HasActiveSubclass, (nSubclass, bThreadAsync), 0x415BD0);

BOOL inline Object::operator==(Object& o) {
	//normally inline
	return m_cEnemyAlly == o.m_cEnemyAlly &&
		m_cGeneral == o.m_cGeneral &&
		m_cRace == o.m_cRace &&
		m_cClass == o.m_cClass &&
		m_cSpecific == o.m_cSpecific &&
		m_cAlignment == o.m_cAlignment &&
		m_cGender == o.m_cGender &&
		m_eTarget == o.m_eTarget;
}

BOOL Object::IsAnything()	{ return operator==(*g_poAnything); }
BOOL Object::IsNonScript()	{ return operator==(*g_poNonScript); }
BOOL Object::IsNothing()	{ return operator==(*g_poNothing); }
BOOL Object::IsAny()		{ return operator==(*g_poAny); }
BOOL Object::IsMyself()		{ return operator==(*g_poMyself); }

//Trigger
Trigger::Trigger()	{ Trigger(TRIGGER_NONE, 0); }
DefineLibNoRetFunc(Trigger&, Trigger, Trigger, (short wOpcode, Object& o, int i), Construct, Construct3, (wOpcode, o, i), 0x430720);
DefineLibNoRetFunc(Trigger&, Trigger, Trigger, (short wOpcode, int i), Construct, Construct2, (wOpcode, i), 0x430810);
DefineLibMemberFunc(Trigger&, Trigger, operator=, (Trigger& t), OpAssign, OpAssign, (t), 0x496100);
DefineLibMemberFunc(short, Trigger, GetOpcode, (), GetOpcode, GetOpcode, (), 0x4943B0);
DefineLibMemberFunc(void, Trigger, DecodeIdentifiers, (CGameSprite& sprite), DecodeIdentifiers, DecodeIdentifiers, (sprite), 0x4943D0);
DefineLibMemberFunc(int, Trigger, GetI, (), GetI, GetI, (), 0x4943F0);
DefineLibMemberFunc(int, Trigger, GetI2, (), GetI2, GetI2, (), 0x494410);
DefineLibMemberFunc(IECString&, Trigger, GetSName1, (), GetSName1, GetSName1, (), 0x494430);
DefineLibMemberFunc(IECString&, Trigger, GetSName2, (), GetSName2, GetSName2, (), 0x494450);

//Action
DefineLibNoRetFunc(Action&, Action, Action, (), Construct, Construct0, (), 0x405820);

void Action::operator=(Action& a) {
	this->opcode = a.opcode;
	this->oOverride = a.oOverride;
	this->oObject = a.oObject;
	this->oTarget = a.oTarget;
	this->i = a.i;
	this->i2 = a.i2;
	this->i3 = a.i3;
	this->sName1 = a.sName1;
	this->sName2 = a.sName2;
	this->pt.x = a.pt.x;
	this->pt.y = a.pt.y;
	this->dwFlags = a.dwFlags;
	return;
}

DefineLibMemberFunc(IECString, Action, GetSName1, (), GetSName1, GetSName1, (), 0x430330);

//Response
DefineLibNoRetFunc(Response&, Response, Response, (), Construct, Construct0, (), 0x416130);
DefineLibMemberFunc(void, Response, operator=, (Response& r), OpAssign, OpAssign, (r), 0x4162A9);

//CScriptBlock
DefineLibMemberFunc(BOOL, CScriptBlock, Evaluate, (CTriggerList& triggers, CGameSprite& sprite), Evaluate, Evaluate, (triggers, sprite), 0x405D19);
DefineLibMemberFunc(BOOL, CScriptBlock, EvaluateTrigger, (Trigger& t, CTriggerList& triggers, CGameSprite& sprite), EvaluateTrigger, EvaluateTrigger, (t, triggers, sprite), 0x405DDD);

//CScriptParser
DefineLibMemberFunc(short, CScriptParser, GetTriggerOpcode, (IECString sName), GetTriggerOpcode, GetTriggerOpcode, (sName), 0x428829);
DefineLibMemberFunc(int, CScriptParser, GetOpcode, (IECString sValue, IECString sIdsName), GetOpcode, GetOpcode, (sValue, sIdsName), 0x428EB0);
DefineLibMemberFunc(void, CScriptParser, SetError, (IECString s), SetError, SetError, (s), 0x428F9E);
DefineLibMemberFunc(Object, CScriptParser, ParseObject, (IECString& sArg), ParseObject, ParseObject, (sArg), 0x429035);
DefineLibMemberFunc(IECString, CScriptParser, SpanBefore, (IECString s, char c), SpanBefore, SpanBefore, (s, c), 0x429A23);
DefineLibMemberFunc(IECString, CScriptParser, SpanAfter, (IECString s, char c), SpanAfter, SpanAfter, (s, c), 0x429B24);
DefineLibMemberFunc(IECString, CScriptParser, GetArgText, (int nArgIdx, IECString sFuncDesc), GetArgText, GetArgText, (nArgIdx, sFuncDesc), 0x42FB7A);
DefineLibMemberFunc(IECString, CScriptParser, GetIdsValue, (Identifiers& ids, IECString& sName), GetIdsValue, GetIdsValue, (ids, sName), 0x430430);
DefineLibMemberFunc(IECString, CScriptParser, GetArgTextIdsName, (IECString sArgText), GetArgTextIdsName, GetArgTextIdsName, (sArgText), 0x430620);
