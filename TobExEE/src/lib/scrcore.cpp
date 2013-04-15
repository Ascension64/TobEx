//TobExEE
#include "scrcore.h"
#include "p_scrcore.h"

//Identifiers
DefineLibNoRetFunc(Identifiers&, Identifiers, Identifiers, (), Construct, Construct0, (), IDENTIFIERS_CONSTRUCT0);
DefineLibNoRetFunc(Identifiers&, Identifiers, Identifiers, (ResRef rFile), Construct, Construct1, (rFile), IDENTIFIERS_CONSTRUCT1);
DefineLibNoRetFunc(void, Identifiers, ~Identifiers, (), Deconstruct, Deconstruct, (), IDENTIFIERS_DECONSTRUCT);
DefineLibMemberFunc(IdsEntry*, Identifiers, FindByHead, (IECString sValue, BOOL bCaseSensitive), FindByHead, FindByHead, (sValue, bCaseSensitive), IDENTIFIERS_FINDBYHEAD);

//CVariable
DefineLibMemberFunc(void, CVariable, SetName, (IECString s), SetName, SetName, (s), CVARIABLE_SETNAME);
DefineLibNoRetFunc(CVariable&, CVariable, CVariable, (), Construct, Construct, (), CVARIABLE_CONSTRUCT);
DefineLibMemberFunc(CVariable&, CVariable, operator=, (CVariable& var), OpAssign, OpAssign, (var), CVARIABLE_OPASSIGN);
DefineLibMemberFunc(IECString, CVariable, GetName, (), GetName, GetName, (), CVARIABLE_GETNAME);

//CVariableMap
DefineLibNoRetFunc(CVariableMap&, CVariableMap, CVariableMap, (int nSize), Construct, Construct, (nSize), CVARIABLEMAP_CONSTRUCT);
DefineLibNoRetFunc(void, CVariableMap, ~CVariableMap, (), Deconstruct, Deconstruct, (), CVARIABLEMAP_DECONSTRUCT);
DefineLibMemberFunc(BOOL, CVariableMap, Add, (CVariable& var), Add, Add, (var), CVARIABLEMAP_ADD);
DefineLibMemberFunc(CVariable&, CVariableMap, Find, (IECString sVar), Find, Find, (sVar), CVARIABLEMAP_FIND);
DefineLibMemberFunc(unsigned int, CVariableMap, GetHash, (IECString sVar), GetHash, GetHash, (sVar), CVARIABLEMAP_GETHASH);
DefineLibMemberFunc(void, CVariableMap, Empty, (), Empty, Empty, (), CVARIABLEMAP_EMPTY);
DefineLibMemberFunc(void, CVariableMap, SetSize, (int nSize), SetSize, SetSize, (nSize), CVARIABLEMAP_SETSIZE);

//ObjectIds
ObjectIds::ObjectIds() {
	m_id1 = OBJECT_NOTHING;
	m_id2 = OBJECT_NOTHING;
	m_id3 = OBJECT_NOTHING;
	m_id4 = OBJECT_NOTHING;
	m_id5 = OBJECT_NOTHING;
}

unsigned char ObjectIds::operator[](unsigned int n) {
	return n < 5 ? *((unsigned char*)this + n) : 0;
}

//Object
Object::Object() { Object(0, 0, 0, 0, 0, 0, 0, -1); }
DefineLibNoRetFunc(void, Object, ~Object, (), Deconstruct, Deconstruct, (), OBJECT_DECONSTRUCT);
DefineLibNoRetFunc(Object&, Object, Object, (Object& o), Construct, Construct1, (o), OBJECT_CONSTRUCT1);
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
	), Construct, Construct10, (cEnemyAlly, cGeneral, cRace, cClass, cSpecific, cGender, cAlignment, eTarget, poids, sName), OBJECT_CONSTRUCT10);
DefineLibNoRetFunc(Object&, Object, Object, (
	unsigned char cEnemyAlly,
	unsigned char cGeneral,
	unsigned char cRace,
	unsigned char cClass,
	unsigned char cSpecific,
	unsigned char cGender,
	unsigned char cAlignment,
	ENUM eTarget
	), Construct, Construct8, (cEnemyAlly, cGeneral, cRace, cClass, cSpecific, cGender, cAlignment, eTarget), OBJECT_CONSTRUCT8);
DefineLibMemberFunc(bool, Object, MatchCriteria, (
	Object& oCriteria,
	BOOL bAnyIncludesNonScript,
	BOOL bExcludeNonScript,
	BOOL bEAGroupMatch
	), MatchCriteria, MatchCriteria, (oCriteria, bAnyIncludesNonScript, bExcludeNonScript, bEAGroupMatch), OBJECT_MATCHCRITERIA);
DefineLibMemberFunc(void, Object, operator=, (Object& o), OpAssign, OpAssign, (o), OBJECT_OPASSIGN);
DefineLibMemberFunc(void, Object, DecodeIdentifiers, (CGameSprite& spriteSource), DecodeIdentifiers, DecodeIdentifiers, (spriteSource), OBJECT_DECODEIDENTIFIERS);
DefineLibMemberFunc(CGameObject&, Object, FindTargetOfType, (CGameObject& source, char type, BOOL bCheckMiddleList), FindTargetOfType, FindTargetOfType, (source, type, bCheckMiddleList), OBJECT_FINDTARGETOFTYPE);
DefineLibMemberFunc(CGameObject&, Object, FindTarget, (CGameObject& source, BOOL bCheckMiddleList), FindTarget, FindTarget, (source, bCheckMiddleList), OBJECT_FINDTARGET);
DefineLibMemberFunc(void, Object, SetIdentifiers, (ObjectIds& ids), SetIdentifiers, SetIdentifiers, (ids), OBJECT_SETIDENTIFIERS);
DefineLibMemberFunc(Object, Object, GetOpposingEAObject, (), GetOpposingEAObject, GetOpposingEAObject, (), OBJECT_GETOPPOSINGEAOBJECT);
DefineLibMemberFunc(void, Object, GetDualClasses, (unsigned char* pClassNew, unsigned char* pClassOrg), GetDualClasses, GetDualClasses, (pClassNew, pClassOrg), OBJECT_GETDUALCLASSES);
DefineLibMemberFunc(BOOL, Object, IsEqualIncludeEnum, (Object& o), IsEqualIncludeEnum, IsEqualIncludeEnum, (o), OBJECT_ISEQUALINCLUDEENUM);

//Trigger
Trigger::Trigger()	{ Trigger(TRIGGER_NONE, 0); }
DefineLibNoRetFunc(Trigger&, Trigger, Trigger, (short wOpcode, Object& o, int i), Construct, Construct3, (wOpcode, o, i), TRIGGER_CONSTRUCT3);
DefineLibNoRetFunc(Trigger&, Trigger, Trigger, (short wOpcode, int i), Construct, Construct2, (wOpcode, i), TRIGGER_CONSTRUCT2);
DefineLibMemberFunc(Trigger&, Trigger, operator=, (Trigger& t), OpAssign, OpAssign, (t), TRIGGER_OPASSIGN);
DefineLibMemberFunc(void, Trigger, DecodeIdentifiers, (CGameSprite& sprite), DecodeIdentifiers, DecodeIdentifiers, (sprite), TRIGGER_DECODEIDENTIFIERS);

//Action
DefineLibNoRetFunc(Action&, Action, Action, (), Construct, Construct0, (), ACTION_CONSTRUCT0);
DefineLibNoRetFunc(void, Action, ~Action, (), Deconstruct, Deconstruct, (), ACTION_DECONSTRUCT);
DefineLibMemberFunc(void, Action, operator=, (Action& a), OpAssign, OpAssign, (a), ACTION_OPASSIGN);

//Response
DefineLibNoRetFunc(Response&, Response, Response, (), Construct, Construct0, (), RESPONSE_CONSTRUCT0);
DefineLibNoRetFunc(void, Response, ~Response, (), Deconstruct, Deconstruct, (), RESPONSE_DECONSTRUCT0);
DefineLibMemberFunc(void, Response, operator=, (Response& r), OpAssign, OpAssign, (r), RESPONSE_OPASSIGN);

//CScriptBlock
DefineLibMemberFunc(BOOL, CScriptBlock, Evaluate, (CTriggerList& triggers, CGameSprite& sprite), Evaluate, Evaluate, (triggers, sprite), CSCRIPTBLOCK_EVALUATE);
DefineLibMemberFunc(BOOL, CScriptBlock, EvaluateTrigger, (Trigger& t, CTriggerList& triggers, CGameSprite& sprite), EvaluateTrigger, EvaluateTrigger, (t, triggers, sprite), CSCRIPTBLOCK_EVALUATETRIGGER);

//CScriptParser
DefineLibMemberFunc(short, CScriptParser, GetTriggerOpcode, (IECString sName), GetTriggerOpcode, GetTriggerOpcode, (sName), CSCRIPTPARSER_GETTRIGGEROPCODE);
DefineLibMemberFunc(int, CScriptParser, GetOpcode, (IECString sValue, IECString sIdsName), GetOpcode, GetOpcode, (sValue, sIdsName), CSCRIPTPARSER_GETOPCODE);
DefineLibMemberFunc(void, CScriptParser, SetError, (IECString s), SetError, SetError, (s), CSCRIPTPARSER_SETERROR);
DefineLibMemberFunc(Object, CScriptParser, ParseObject, (IECString& sArg), ParseObject, ParseObject, (sArg), CSCRIPTPARSER_PARSEOBJECT);
DefineLibMemberFunc(IECString, CScriptParser, SpanBefore, (IECString s, char c), SpanBefore, SpanBefore, (s, c), CSCRIPTPARSER_SPANBEFORE);
DefineLibMemberFunc(IECString, CScriptParser, SpanAfter, (IECString s, char c), SpanAfter, SpanAfter, (s, c), CSCRIPTPARSER_SPANAFTER);
DefineLibMemberFunc(IECString, CScriptParser, GetArgText, (int nArgIdx, IECString sFuncDesc), GetArgText, GetArgText, (nArgIdx, sFuncDesc), CSCRIPTPARSER_GETARGTEXT);
DefineLibMemberFunc(IECString, CScriptParser, GetIdsValue, (Identifiers& ids, IECString& sName), GetIdsValue, GetIdsValue2, (ids, sName), CSCRIPTPARSER_GETIDSVALUE2);
DefineLibMemberFunc(IECString, CScriptParser, GetArgTextIdsName, (IECString sArgText), GetArgTextIdsName, GetArgTextIdsName, (sArgText), CSCRIPTPARSER_GETARGTEXTIDSNAME);
