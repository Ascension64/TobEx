#include "scrcore.h"

//Object
BYTE (Object::*Object_GetClass)() =
	SetFP(static_cast<BYTE (Object::*)(void)>			(&Object::GetClass),		0x4158A4);
void (Object::*Object_GetClasses)(BYTE*, BYTE*) =
	SetFP(static_cast<void (Object::*)(BYTE*, BYTE*)>	(&Object::GetClasses),		0x4158B5);

BYTE Object::GetClass()									{ return (this->*Object_GetClass)(); }
void Object::GetClasses(BYTE* pClass1, BYTE* pClass2)	{ return (this->*Object_GetClasses)(pClass1, pClass2); }

//Action
Action* (Action::*Action_Construct_0)(void) =
	SetFP(static_cast<Action* (Action::*)(void)>		(&Action::Construct),		0x405820);
void (Action::*Action_Deconstruct)(void) =
	SetFP(static_cast<void (Action::*)(void)>			(&Action::Deconstruct),		0x405930);

Action::Action() { (this->*Action_Construct_0)(); }
Action::~Action() { (this->*Action_Deconstruct)(); }