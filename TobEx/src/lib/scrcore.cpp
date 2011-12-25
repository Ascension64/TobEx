#include "scrcore.h"

//Object
unsigned char (Object::*Object_GetClass)() =
	SetFP(static_cast<unsigned char (Object::*)()>						(&Object::GetClass),		0x4158A4);
void (Object::*Object_GetClasses)(unsigned char*, unsigned char*) =
	SetFP(static_cast<void (Object::*)(unsigned char*, unsigned char*)>	(&Object::GetClasses),		0x4158B5);

unsigned char Object::GetClass()										{ return (this->*Object_GetClass)(); }
void Object::GetClasses(unsigned char* pClass1, unsigned char* pClass2)	{ return (this->*Object_GetClasses)(pClass1, pClass2); }

//Action
Action* (Action::*Action_Construct_0)() =
	SetFP(static_cast<Action* (Action::*)()>	(&Action::Construct),		0x405820);
void (Action::*Action_Deconstruct)() =
	SetFP(static_cast<void (Action::*)()>		(&Action::Deconstruct),		0x405930);

Action::Action() { (this->*Action_Construct_0)(); }
Action::~Action() { (this->*Action_Deconstruct)(); }