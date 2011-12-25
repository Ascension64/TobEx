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

//Object
static Object* poInvalid = reinterpret_cast<Object*>(0xB75AB8);

Object* (Object::*Object_Construct_10)(unsigned char, unsigned char, unsigned char, unsigned char, char, char, char, Enum, ObjectIds*, IECString&) =
	SetFP(static_cast<Object* (Object::*)(unsigned char, unsigned char, unsigned char, unsigned char, char, char, char, Enum, ObjectIds*, IECString&)>
																		(&Object::Construct),			0x410C14);
Object* (Object::*Object_Construct_8)(unsigned char, unsigned char, unsigned char, unsigned char, char, char, char, Enum) =
	SetFP(static_cast<Object* (Object::*)(unsigned char, unsigned char, unsigned char, unsigned char, char, char, char, Enum)>
																		(&Object::Construct),			0x410CEE);
void (Object::*Object_OpEq)(Object&) =
	SetFP(static_cast<void (Object::*)(Object&)>						(&Object::OpEq),				0x4119BD);
void (Object::*Object_DecodeIdentifiers)(CGameSprite&) =
	SetFP(static_cast<void (Object::*)(CGameSprite&)>					(&Object::DecodeIdentifiers),	0x411A4C);
unsigned char (Object::*Object_GetClass)() =
	SetFP(static_cast<unsigned char (Object::*)()>						(&Object::GetClass),			0x4158A4);
void (Object::*Object_GetClasses)(unsigned char*, unsigned char*) =
	SetFP(static_cast<void (Object::*)(unsigned char*, unsigned char*)>	(&Object::GetClasses),			0x4158B5);
extern BOOL (Object::*Object_HasSubclass)(unsigned char, BOOL) =
	SetFP(static_cast<BOOL (Object::*)(unsigned char, BOOL)>			(&Object::HasSubclass),			0x415BD0);

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

Object::Object() {
	Object(0, 0, 0, 0, 0, 0, 0, -1);
}

Object::Object(unsigned char EnemyAlly, unsigned char General, unsigned char Race, unsigned char Class, char Specific, char Gender, char Alignment, Enum eTarget, ObjectIds* poids, IECString& sName)
	{ (this->*Object_Construct_10)(EnemyAlly, General, Race, Class, Specific, Gender, Alignment, eTarget, poids, sName); }
Object::Object(unsigned char EnemyAlly, unsigned char General, unsigned char Race, unsigned char Class, char Specific, char Gender, char Alignment, Enum eTarget)
	{ (this->*Object_Construct_8)(EnemyAlly, General, Race, Class, Specific, Gender, Alignment, eTarget); }
void Object::operator=(Object& o)										{ return (this->*Object_OpEq)(o); }
void Object::DecodeIdentifiers(CGameSprite& spriteSource)				{ return (this->*Object_DecodeIdentifiers)(spriteSource); }
unsigned char Object::GetClass()										{ return (this->*Object_GetClass)(); }
void Object::GetClasses(unsigned char* pClass1, unsigned char* pClass2)	{ return (this->*Object_GetClasses)(pClass1, pClass2); }
BOOL Object::HasSubclass(unsigned char Class, BOOL bThreadAsync)		{ return (this->*Object_HasSubclass)(Class, bThreadAsync); }

//Action
Action* (Action::*Action_Construct_0)() =
	SetFP(static_cast<Action* (Action::*)()>	(&Action::Construct),		0x405820);
void (Action::*Action_Deconstruct)() =
	SetFP(static_cast<void (Action::*)()>		(&Action::Deconstruct),		0x405930);

Action::Action() { (this->*Action_Construct_0)(); }
Action::~Action() { (this->*Action_Deconstruct)(); }