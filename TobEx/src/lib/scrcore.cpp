#include "scrcore.h"

//Identifiers
Identifiers& (Identifiers::*Identifiers_Construct_0)() =
	SetFP(static_cast<Identifiers& (Identifiers::*)()>			(&Identifiers::Construct),		0x40FB70);
Identifiers& (Identifiers::*Identifiers_Construct_1_ResRef)(ResRef) =
	SetFP(static_cast<Identifiers& (Identifiers::*)(ResRef)>	(&Identifiers::Construct),		0x40FC37);
void (Identifiers::*Identifiers_Deconstruct)() =
	SetFP(static_cast<void (Identifiers::*)()>					(&Identifiers::Deconstruct),	0x40FE31);

Identifiers::Identifiers()				{ (this->*Identifiers_Construct_0)(); }
Identifiers::Identifiers(ResRef rFile)	{ (this->*Identifiers_Construct_1_ResRef)(rFile); }
Identifiers::~Identifiers()				{ (this->*Identifiers_Deconstruct)(); }

//ObjectIds
ObjectIds::ObjectIds() {
	id1 = OBJECT_NOTHING;
	id2 = OBJECT_NOTHING;
	id3 = OBJECT_NOTHING;
	id4 = OBJECT_NOTHING;
	id5 = OBJECT_NOTHING;
}

//Object
static Object* poInvalid = reinterpret_cast<Object*>(0xB75AB8);

Object& (Object::*Object_Construct_10)(unsigned char, unsigned char, unsigned char, unsigned char, char, char, char, Enum, ObjectIds*, IECString&) =
	SetFP(static_cast<Object& (Object::*)(unsigned char, unsigned char, unsigned char, unsigned char, char, char, char, Enum, ObjectIds*, IECString&)>
																			(&Object::Construct),			0x410C14);
Object& (Object::*Object_Construct_8)(unsigned char, unsigned char, unsigned char, unsigned char, char, char, char, Enum) =
	SetFP(static_cast<Object& (Object::*)(unsigned char, unsigned char, unsigned char, unsigned char, char, char, char, Enum)>
																			(&Object::Construct),			0x410CEE);
void (Object::*Object_OpEq)(Object&) =
	SetFP(static_cast<void (Object::*)(Object&)>							(&Object::OpEq),				0x4119BD);
void (Object::*Object_DecodeIdentifiers)(CGameSprite&) =
	SetFP(static_cast<void (Object::*)(CGameSprite&)>						(&Object::DecodeIdentifiers),	0x411A4C);
CGameObject& (Object::*Object_GetTargetOfType)(CGameObject&, char, BOOL) =
	SetFP(static_cast<CGameObject& (Object::*)(CGameObject&, char, BOOL)>	(&Object::GetTargetOfType),		0x414EA9);

void (Object::*Object_SetIdentifiers)(ObjectIds&) =
	SetFP(static_cast<void (Object::*)(ObjectIds&)>							(&Object::SetIdentifiers),		0x41531E);
unsigned char (Object::*Object_GetClass)() =
	SetFP(static_cast<unsigned char (Object::*)()>							(&Object::GetClass),			0x4158A4);
void (Object::*Object_GetClasses)(unsigned char*, unsigned char*) =
	SetFP(static_cast<void (Object::*)(unsigned char*, unsigned char*)>		(&Object::GetClasses),			0x4158B5);
extern BOOL (Object::*Object_HasSubclass)(unsigned char, BOOL) =
	SetFP(static_cast<BOOL (Object::*)(unsigned char, BOOL)>				(&Object::HasSubclass),			0x415BD0);

bool Object::IsInvalid() {
	//normally inline
	if (
		EnemyAlly == poInvalid->EnemyAlly && //127
		General == poInvalid->General && //255
		Race == poInvalid->Race && //255
		Class == poInvalid->Class && //255
		Specific == poInvalid->Specific && //255
		Alignment == poInvalid->Alignment && //255
		Gender == poInvalid->Gender && //255
		eTarget == poInvalid->eTarget //0x80000000
	) {
		return true;
	} else {
		return false;
	}
}

Object::Object() { (this->*Object_Construct_8)(0, 0, 0, 0, 0, 0, 0, -1); }
Object::Object(unsigned char EnemyAlly, unsigned char General, unsigned char Race, unsigned char Class, char Specific, char Gender, char Alignment, Enum eTarget, ObjectIds* poids, IECString& sName)
	{ (this->*Object_Construct_10)(EnemyAlly, General, Race, Class, Specific, Gender, Alignment, eTarget, poids, sName); }
Object::Object(unsigned char EnemyAlly, unsigned char General, unsigned char Race, unsigned char Class, char Specific, char Gender, char Alignment, Enum eTarget)
	{ (this->*Object_Construct_8)(EnemyAlly, General, Race, Class, Specific, Gender, Alignment, eTarget); }
void Object::operator=(Object& o)										{ return (this->*Object_OpEq)(o); }
void Object::DecodeIdentifiers(CGameSprite& spriteSource)				{ return (this->*Object_DecodeIdentifiers)(spriteSource); }
CGameObject& Object::GetTargetOfType(CGameObject& source, char type, BOOL bCheckMiddleList)
	{ return (this->*Object_GetTargetOfType)(source, type, bCheckMiddleList); }
void Object::SetIdentifiers(ObjectIds& ids)								{ return (this->*Object_SetIdentifiers)(ids); }
unsigned char Object::GetClass()										{ return (this->*Object_GetClass)(); }
void Object::GetClasses(unsigned char* pClass1, unsigned char* pClass2)	{ return (this->*Object_GetClasses)(pClass1, pClass2); }
BOOL Object::HasSubclass(unsigned char Class, BOOL bThreadAsync)		{ return (this->*Object_HasSubclass)(Class, bThreadAsync); }

//Trigger
Trigger& (Trigger::*Trigger_Construct_2)(short, int) =
	SetFP(static_cast<Trigger& (Trigger::*)(short, int)>	(&Trigger::Construct),			0x430810);
Trigger& (Trigger::*Trigger_OpEq)(Trigger&) =
	SetFP(static_cast<Trigger& (Trigger::*)(Trigger&)>		(&Trigger::OpEq),				0x496100);
short (Trigger::*Trigger_GetOpcode)() =
	SetFP(static_cast<short (Trigger::*)()>					(&Trigger::GetOpcode),			0x4943B0);
void (Trigger::*Trigger_DecodeIdentifiers)(CGameSprite&) =
	SetFP(static_cast<void (Trigger::*)(CGameSprite&)>		(&Trigger::DecodeIdentifiers),	0x4943D0);
int (Trigger::*Trigger_GetI)() =
	SetFP(static_cast<int (Trigger::*)()>					(&Trigger::GetI),				0x4943F0);
int (Trigger::*Trigger_GetI2)() =
	SetFP(static_cast<int (Trigger::*)()>					(&Trigger::GetI2),				0x494410);
IECString* (Trigger::*Trigger_GetSName1)() =
	SetFP(static_cast<IECString* (Trigger::*)()>			(&Trigger::GetSName1),			0x494430);
IECString* (Trigger::*Trigger_GetSName2)() =
	SetFP(static_cast<IECString* (Trigger::*)()>			(&Trigger::GetSName2),			0x494450);

Trigger::Trigger()									{ (this->*Trigger_Construct_2)(TRIGGER_NONE, 0); }
Trigger::Trigger(short wOpcode, int n)				{ (this->*Trigger_Construct_2)(wOpcode, n); }
Trigger& Trigger::operator=(Trigger& t)				{ return (this->*Trigger_OpEq)(t); }
short Trigger::GetOpcode()							{ return (this->*Trigger_GetOpcode)(); }
void Trigger::DecodeIdentifiers(CGameSprite& sprite){ return (this->*Trigger_DecodeIdentifiers)(sprite); }
int Trigger::GetI()									{ return (this->*Trigger_GetI)(); }
int Trigger::GetI2()								{ return (this->*Trigger_GetI2)(); }
IECString* Trigger::GetSName1()						{ return (this->*Trigger_GetSName1)(); }
IECString* Trigger::GetSName2()						{ return (this->*Trigger_GetSName2)(); }

//Action
Action& (Action::*Action_Construct_0)() =
	SetFP(static_cast<Action& (Action::*)()>	(&Action::Construct),		0x405820);
void (Action::*Action_Deconstruct)() =
	SetFP(static_cast<void (Action::*)()>		(&Action::Deconstruct),		0x405930);
IECString (Action::*Action_GetSName1)() =
	SetFP(static_cast<IECString (Action::*)()>	(&Action::GetSName1),		0x430330);

Action::Action() { (this->*Action_Construct_0)(); }
Action::~Action() { (this->*Action_Deconstruct)(); }
IECString Action::GetSName1() { return (this->*Action_GetSName1)(); }

//CScriptBlock
BOOL (CScriptBlock::*CScriptBlock_Evaluate)(CTriggerList&, CGameSprite&) =
	SetFP(static_cast<BOOL (CScriptBlock::*)(CTriggerList&, CGameSprite&)>				(&CScriptBlock::Evaluate),			0x405D19);
BOOL (CScriptBlock::*CScriptBlock_EvaluateTrigger)(Trigger&, CTriggerList&, CGameSprite&) =
	SetFP(static_cast<BOOL (CScriptBlock::*)(Trigger&, CTriggerList&, CGameSprite&)>	(&CScriptBlock::EvaluateTrigger),	0x405DDD);

BOOL CScriptBlock::Evaluate(CTriggerList& triggers, CGameSprite& sprite)					{ return (this->*CScriptBlock_Evaluate)(triggers, sprite); }
BOOL CScriptBlock::EvaluateTrigger(Trigger& t, CTriggerList& triggers, CGameSprite& sprite)	{ return (this->*CScriptBlock_EvaluateTrigger)(t, triggers, sprite); }
