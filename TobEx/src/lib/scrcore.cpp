#include "scrcore.h"

BYTE (Object::*Object_GetClass)() =
	SetFP(static_cast<BYTE (Object::*)(void)>			(&Object::GetClass),		0x4158A4);

BYTE Object::GetClass() { return (this->*Object_GetClass)(); }

Action* (Action::*Action_Construct_0)(void) =
	SetFP(static_cast<Action* (Action::*)(void)>		(&Action::Construct),		0x405820);
void (Action::*Action_Deconstruct)(void) =
	SetFP(static_cast<void (Action::*)(void)>			(&Action::Deconstruct),		0x405930);

Action::Action() { (this->*Action_Construct_0)(); }
Action::~Action() { (this->*Action_Deconstruct)(); }