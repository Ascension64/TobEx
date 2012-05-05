#include "scrcore.h"

//Identifiers
Identifiers& (Identifiers::*Identifiers_Construct_0)() =
	SetFP(static_cast<Identifiers& (Identifiers::*)()>				(&Identifiers::Construct),	0x40FB70);
Identifiers& (Identifiers::*Identifiers_Construct_1_ResRef)(ResRef) =
	SetFP(static_cast<Identifiers& (Identifiers::*)(ResRef)>		(&Identifiers::Construct),	0x40FC37);
void (Identifiers::*Identifiers_Deconstruct)() =
	SetFP(static_cast<void (Identifiers::*)()>						(&Identifiers::Deconstruct),0x40FE31);
IdsEntry* (Identifiers::*Identifiers_FindByValue)(IECString, BOOL) =
	SetFP(static_cast<IdsEntry* (Identifiers::*)(IECString, BOOL)>	(&Identifiers::FindByValue),0x410502);

Identifiers::Identifiers() { (this->*Identifiers_Construct_0)(); }
Identifiers::Identifiers(ResRef rFile) { (this->*Identifiers_Construct_1_ResRef)(rFile); }
Identifiers::~Identifiers() { (this->*Identifiers_Deconstruct)(); }
IdsEntry* Identifiers::FindByValue(IECString sValue, BOOL bCaseSensitive) { return (this->*Identifiers_FindByValue)(sValue, bCaseSensitive); }

//CVariable
void (CVariable::*CVariable_SetName)(IECString) =
	SetFP(static_cast<void (CVariable::*)(IECString)>			(&CVariable::SetName),		0x45FD80);
CVariable& (CVariable::*CVariable_Construct)() =
	SetFP(static_cast<CVariable& (CVariable::*)()>				(&CVariable::Construct),	0x4B6850);
CVariable& (CVariable::*CVariable_OpAssign)(CVariable&) =
	SetFP(static_cast<CVariable& (CVariable::*)(CVariable&)>	(&CVariable::OpAssign),		0x4B68C0);
IECString (CVariable::*CVariable_GetName)() =
	SetFP(static_cast<IECString (CVariable::*)()>				(&CVariable::GetName),		0x54DE90);

void CVariable::SetName(IECString s) { return (this->*CVariable_SetName)(s); }
CVariable::CVariable() { (this->*CVariable_Construct)(); }
CVariable& CVariable::operator=(CVariable& var) { return (this->*CVariable_OpAssign)(var); }
IECString CVariable::GetName() { return (this->*CVariable_GetName)(); }

//CVariableMap
CVariableMap& (CVariableMap::*CVariableMap_Construct)(int) =
	SetFP(static_cast<CVariableMap& (CVariableMap::*)(int)>		(&CVariableMap::Construct),		0x64A1E0);
void (CVariableMap::*CVariableMap_Deconstruct)() =
	SetFP(static_cast<void (CVariableMap::*)()>					(&CVariableMap::Deconstruct),	0x64A2C7);
BOOL (CVariableMap::*CVariableMap_Add)(CVariable&) =
	SetFP(static_cast<BOOL (CVariableMap::*)(CVariable&)>		(&CVariableMap::Add),			0x64A2E8);
CVariable& (CVariableMap::*CVariableMap_Find)(IECString) =
	SetFP(static_cast<CVariable& (CVariableMap::*)(IECString)>	(&CVariableMap::Find),			0x64A709);
unsigned int (CVariableMap::*CVariableMap_GetHash)(IECString) =
	SetFP(static_cast<unsigned int (CVariableMap::*)(IECString)>(&CVariableMap::GetHash),		0x64A96E);
void (CVariableMap::*CVariableMap_Empty)() =
	SetFP(static_cast<void (CVariableMap::*)()>					(&CVariableMap::Empty),			0x64AA27);
void (CVariableMap::*CVariableMap_SetSize)(int) =
	SetFP(static_cast<void (CVariableMap::*)(int)>				(&CVariableMap::SetSize),		0x64B23D);

CVariableMap::CVariableMap(int nSize)				{ (this->*CVariableMap_Construct)(nSize); }
CVariableMap::~CVariableMap()						{ (this->*CVariableMap_Deconstruct)(); }
BOOL CVariableMap::Add(CVariable& var)				{ return (this->*CVariableMap_Add)(var); }
CVariable& CVariableMap::Find(IECString sVar)		{ return (this->*CVariableMap_Find)(sVar); }
unsigned int CVariableMap::GetHash(IECString sVar)	{ return (this->*CVariableMap_GetHash)(sVar); }
void CVariableMap::Empty()							{ return (this->*CVariableMap_Empty)(); }
void CVariableMap::SetSize(int nSize)				{ return (this->*CVariableMap_SetSize)(nSize); }

//ObjectIds
ObjectIds::ObjectIds() {
	id1 = OBJECT_NOTHING;
	id2 = OBJECT_NOTHING;
	id3 = OBJECT_NOTHING;
	id4 = OBJECT_NOTHING;
	id5 = OBJECT_NOTHING;
}

//Object
static Object* poAnything = reinterpret_cast<Object*>(0xB75AA0); //unused
static Object* poNonScript = reinterpret_cast<Object*>(0xB75AB8); //only in CGameObject constructor
static Object* poNothing = reinterpret_cast<Object*>(0xB75AD0); //for constructors
Object* poAny = reinterpret_cast<Object*>(0xB75AE8); //for criteria objects
static Object* poMyself = reinterpret_cast<Object*>(0xB75B00); //unused

Object& (Object::*Object_Construct_10)(unsigned char, unsigned char, unsigned char, unsigned char, char, char, char, Enum, ObjectIds*, IECString&) =
	SetFP(static_cast<Object& (Object::*)(unsigned char, unsigned char, unsigned char, unsigned char, char, char, char, Enum, ObjectIds*, IECString&)>
																			(&Object::Construct),			0x410C14);
Object& (Object::*Object_Construct_8)(unsigned char, unsigned char, unsigned char, unsigned char, char, char, char, Enum) =
	SetFP(static_cast<Object& (Object::*)(unsigned char, unsigned char, unsigned char, unsigned char, char, char, char, Enum)>
																			(&Object::Construct),			0x410CEE);
bool (Object::*Object_MatchCriteria)(Object&, BOOL, BOOL, BOOL) =
	SetFP(static_cast<bool (Object::*)(Object&, BOOL, BOOL, BOOL)>			(&Object::MatchCriteria),		0x410D9E);
void (Object::*Object_OpAssign)(Object&) =
	SetFP(static_cast<void (Object::*)(Object&)>							(&Object::OpAssign),			0x4119BD);
void (Object::*Object_DecodeIdentifiers)(CGameSprite&) =
	SetFP(static_cast<void (Object::*)(CGameSprite&)>						(&Object::DecodeIdentifiers),	0x411A4C);
CGameObject& (Object::*Object_FindTargetOfType)(CGameObject&, char, BOOL) =
	SetFP(static_cast<CGameObject& (Object::*)(CGameObject&, char, BOOL)>	(&Object::FindTargetOfType),	0x414EA9);
CGameObject& (Object::*Object_FindTarget)(CGameObject&, BOOL) =
	SetFP(static_cast<CGameObject& (Object::*)(CGameObject&, BOOL)>			(&Object::FindTarget),			0x414FA8);

void (Object::*Object_SetIdentifiers)(ObjectIds&) =
	SetFP(static_cast<void (Object::*)(ObjectIds&)>							(&Object::SetIdentifiers),		0x41531E);
Object (Object::*Object_GetOpposingEAObject)() =
	SetFP(static_cast<Object (Object::*)()>									(&Object::GetOpposingEAObject),	0x4157E9);
unsigned char (Object::*Object_GetClass)() =
	SetFP(static_cast<unsigned char (Object::*)()>							(&Object::GetClass),			0x4158A4);
void (Object::*Object_GetDualClasses)(unsigned char*, unsigned char*) =
	SetFP(static_cast<void (Object::*)(unsigned char*, unsigned char*)>		(&Object::GetDualClasses),		0x4158B5);
extern BOOL (Object::*Object_HasActiveSubclass)(unsigned char, BOOL) =
	SetFP(static_cast<BOOL (Object::*)(unsigned char, BOOL)>				(&Object::HasActiveSubclass),	0x415BD0);

Object::Object() { (this->*Object_Construct_8)(0, 0, 0, 0, 0, 0, 0, -1); }
Object::Object(unsigned char EnemyAlly, unsigned char General, unsigned char Race, unsigned char Class, char Specific, char Gender, char Alignment, Enum eTarget, ObjectIds* poids, IECString& sName)
	{ (this->*Object_Construct_10)(EnemyAlly, General, Race, Class, Specific, Gender, Alignment, eTarget, poids, sName); }
Object::Object(unsigned char EnemyAlly, unsigned char General, unsigned char Race, unsigned char Class, char Specific, char Gender, char Alignment, Enum eTarget)
	{ (this->*Object_Construct_8)(EnemyAlly, General, Race, Class, Specific, Gender, Alignment, eTarget); }
bool Object::MatchCriteria(Object& oCriteria, BOOL bAnyIncludesNonScript, BOOL bExcludeNonScript, BOOL bEAGroupMatch)
	{ return (this->*Object_MatchCriteria)(oCriteria, bAnyIncludesNonScript, bExcludeNonScript, bEAGroupMatch); }
void Object::operator=(Object& o)												{ return (this->*Object_OpAssign)(o); }
void Object::DecodeIdentifiers(CGameSprite& spriteSource)						{ return (this->*Object_DecodeIdentifiers)(spriteSource); }
CGameObject& Object::FindTargetOfType(CGameObject& source, char type, BOOL bCheckMiddleList)
	{ return (this->*Object_FindTargetOfType)(source, type, bCheckMiddleList); }
CGameObject& Object::FindTarget(CGameObject& source, BOOL bCheckMiddleList)		{ return (this->*Object_FindTarget)(source, bCheckMiddleList); }
void Object::SetIdentifiers(ObjectIds& ids)										{ return (this->*Object_SetIdentifiers)(ids); }
Object Object::GetOpposingEAObject()											{ return (this->*Object_GetOpposingEAObject)(); }
unsigned char Object::GetClass()												{ return (this->*Object_GetClass)(); }
void Object::GetDualClasses(unsigned char* pClassNew, unsigned char* pClassOrg)	{ return (this->*Object_GetDualClasses)(pClassNew, pClassOrg); }
BOOL Object::HasActiveSubclass(unsigned char nSubclass, BOOL bThreadAsync)		{ return (this->*Object_HasActiveSubclass)(nSubclass, bThreadAsync); }

BOOL inline Object::operator==(Object& o) {
	//normally inline
	if (
		EnemyAlly == o.EnemyAlly &&
		General == o.General &&
		Race == o.Race &&
		Class == o.Class &&
		Specific == o.Specific &&
		Alignment == o.Alignment &&
		Gender == o.Gender &&
		eTarget == o.eTarget
	) {
		return TRUE;
	} else {
		return FALSE;
	}
}

BOOL Object::IsAnything()	{ return operator==(*poAnything); }
BOOL Object::IsNonScript()	{ return operator==(*poNonScript); }
BOOL Object::IsNothing()	{ return operator==(*poNothing); }
BOOL Object::IsAny()		{ return operator==(*poAny); }
BOOL Object::IsMyself()		{ return operator==(*poMyself); }

//Trigger
Trigger& (Trigger::*Trigger_Construct_3)(short, Object&, int) =
	SetFP(static_cast<Trigger& (Trigger::*)(short, Object&, int)>	(&Trigger::Construct),			0x430720);
Trigger& (Trigger::*Trigger_Construct_2)(short, int) =
	SetFP(static_cast<Trigger& (Trigger::*)(short, int)>			(&Trigger::Construct),			0x430810);
Trigger& (Trigger::*Trigger_OpAssign)(Trigger&) =
	SetFP(static_cast<Trigger& (Trigger::*)(Trigger&)>				(&Trigger::OpAssign),			0x496100);
short (Trigger::*Trigger_GetOpcode)() =
	SetFP(static_cast<short (Trigger::*)()>							(&Trigger::GetOpcode),			0x4943B0);
void (Trigger::*Trigger_DecodeIdentifiers)(CGameSprite&) =
	SetFP(static_cast<void (Trigger::*)(CGameSprite&)>				(&Trigger::DecodeIdentifiers),	0x4943D0);
int (Trigger::*Trigger_GetI)() =
	SetFP(static_cast<int (Trigger::*)()>							(&Trigger::GetI),				0x4943F0);
int (Trigger::*Trigger_GetI2)() =
	SetFP(static_cast<int (Trigger::*)()>							(&Trigger::GetI2),				0x494410);
IECString& (Trigger::*Trigger_GetSName1)() =
	SetFP(static_cast<IECString& (Trigger::*)()>					(&Trigger::GetSName1),			0x494430);
IECString& (Trigger::*Trigger_GetSName2)() =
	SetFP(static_cast<IECString& (Trigger::*)()>					(&Trigger::GetSName2),			0x494450);

Trigger::Trigger()									{ (this->*Trigger_Construct_2)(TRIGGER_NONE, 0); }
Trigger::Trigger(short wOpcode, Object& o, int i)	{ (this->*Trigger_Construct_3)(wOpcode, o, i); }
Trigger::Trigger(short wOpcode, int n)				{ (this->*Trigger_Construct_2)(wOpcode, n); }
Trigger& Trigger::operator=(Trigger& t)				{ return (this->*Trigger_OpAssign)(t); }
short Trigger::GetOpcode()							{ return (this->*Trigger_GetOpcode)(); }
void Trigger::DecodeIdentifiers(CGameSprite& sprite){ return (this->*Trigger_DecodeIdentifiers)(sprite); }
int Trigger::GetI()									{ return (this->*Trigger_GetI)(); }
int Trigger::GetI2()								{ return (this->*Trigger_GetI2)(); }
IECString& Trigger::GetSName1()						{ return (this->*Trigger_GetSName1)(); }
IECString& Trigger::GetSName2()						{ return (this->*Trigger_GetSName2)(); }

//Action
Action& (Action::*Action_Construct_0)() =
	SetFP(static_cast<Action& (Action::*)()>	(&Action::Construct),		0x405820);
IECString (Action::*Action_GetSName1)() =
	SetFP(static_cast<IECString (Action::*)()>	(&Action::GetSName1),		0x430330);

void* Action::operator new(size_t size) { return ::operator new(size, 0); }
void Action::operator delete(void* mem) { return ::operator delete(mem, 0); } 
Action::Action() { (this->*Action_Construct_0)(); }
IECString Action::GetSName1() { return (this->*Action_GetSName1)(); }

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

//Response
Response& (Response::*Response_Construct_0)() =
	SetFP(static_cast<Response& (Response::*)()>	(&Response::Construct),	0x416130);
void (Response::*Response_OpEq)(Response&) =
	SetFP(static_cast<void (Response::*)(Response&)>(&Response::OpEq),		0x4162A9);

Response::Response() { (this->*Response_Construct_0)(); }
void Response::operator=(Response& r) { (this->*Response_OpEq)(r); }

//CScriptBlock
BOOL (CScriptBlock::*CScriptBlock_Evaluate)(CTriggerList&, CGameSprite&) =
	SetFP(static_cast<BOOL (CScriptBlock::*)(CTriggerList&, CGameSprite&)>				(&CScriptBlock::Evaluate),			0x405D19);
BOOL (CScriptBlock::*CScriptBlock_EvaluateTrigger)(Trigger&, CTriggerList&, CGameSprite&) =
	SetFP(static_cast<BOOL (CScriptBlock::*)(Trigger&, CTriggerList&, CGameSprite&)>	(&CScriptBlock::EvaluateTrigger),	0x405DDD);

BOOL CScriptBlock::Evaluate(CTriggerList& triggers, CGameSprite& sprite)					{ return (this->*CScriptBlock_Evaluate)(triggers, sprite); }
BOOL CScriptBlock::EvaluateTrigger(Trigger& t, CTriggerList& triggers, CGameSprite& sprite)	{ return (this->*CScriptBlock_EvaluateTrigger)(t, triggers, sprite); }

//CScriptParser
short (CScriptParser::*CScriptParser_GetTriggerOpcode)(IECString) =
	SetFP(static_cast<short (CScriptParser::*)(IECString)>						(&CScriptParser::GetTriggerOpcode),	0x428829);
int (CScriptParser::*CScriptParser_GetOpcode)(IECString, IECString) =
	SetFP(static_cast<int (CScriptParser::*)(IECString, IECString)>				(&CScriptParser::GetOpcode),		0x428EB0);
void (CScriptParser::*CScriptParser_SetError)(IECString) =
	SetFP(static_cast<void (CScriptParser::*)(IECString)>						(&CScriptParser::SetError),			0x428F9E);
Object (CScriptParser::*CScriptParser_ParseObject)(IECString&) =
	SetFP(static_cast<Object (CScriptParser::*)(IECString&)>					(&CScriptParser::ParseObject),		0x429035);
IECString (CScriptParser::*CScriptParser_SpanBefore)(IECString, char) =
	SetFP(static_cast<IECString (CScriptParser::*)(IECString, char)>			(&CScriptParser::SpanBefore),		0x429A23);
IECString (CScriptParser::*CScriptParser_SpanAfter)(IECString, char) =
	SetFP(static_cast<IECString (CScriptParser::*)(IECString, char)>			(&CScriptParser::SpanAfter),		0x429B24);
IECString (CScriptParser::*CScriptParser_GetArgText)(int, IECString) =
	SetFP(static_cast<IECString (CScriptParser::*)(int, IECString)>				(&CScriptParser::GetArgText),		0x42FB7A);
IECString (CScriptParser::*CScriptParser_GetIdsValue)(Identifiers&, IECString&) =
	SetFP(static_cast<IECString (CScriptParser::*)(Identifiers&, IECString&)>	(&CScriptParser::GetIdsValue),		0x430430);
IECString (CScriptParser::*CScriptParser_GetArgTextIdsName)(IECString) =
	SetFP(static_cast<IECString (CScriptParser::*)(IECString)>					(&CScriptParser::GetArgTextIdsName),0x430620);

short CScriptParser::GetTriggerOpcode(IECString sName) { return (this->*CScriptParser_GetTriggerOpcode)(sName); }
void CScriptParser::SetError(IECString s) { return (this->*CScriptParser_SetError)(s); }
Object CScriptParser::ParseObject(IECString& sArg) { return (this->*CScriptParser_ParseObject)(sArg); }
IECString CScriptParser::SpanBefore(IECString s, char c) { return (this->*CScriptParser_SpanBefore)(s, c); }
IECString CScriptParser::SpanAfter(IECString s, char c) { return (this->*CScriptParser_SpanAfter)(s, c); }
IECString CScriptParser::GetArgText(int nArgIdx, IECString sFuncDesc) { return (this->*CScriptParser_GetArgText)(nArgIdx, sFuncDesc); }
IECString CScriptParser::GetIdsValue(Identifiers& ids, IECString& sName) { return (this->*CScriptParser_GetIdsValue)(ids, sName); }
int CScriptParser::GetOpcode(IECString sValue, IECString sIdsName) { return (this->*CScriptParser_GetOpcode)(sValue, sIdsName); }
IECString CScriptParser::GetArgTextIdsName(IECString sArgText) { return (this->*CScriptParser_GetArgTextIdsName)(sArgText); }
