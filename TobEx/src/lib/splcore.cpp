#include "splcore.h"

void (ResSplContainer::*ResSplContainer_Unload)() =
	SetFP(static_cast<void (ResSplContainer::*)()>							(&ResSplContainer::Unload),			0x4B65C0);
void (ResSplContainer::*ResSplContainer_LoadResource)(ResRef&, BOOL, BOOL) =
	SetFP(static_cast<void (ResSplContainer::*)(ResRef&, BOOL, BOOL)>		(&ResSplContainer::LoadResource),	0x4B6630);
short (ResSplContainer::*ResSplContainer_GetSpellLevel)() =
	SetFP(static_cast<short (ResSplContainer::*)()>							(&ResSplContainer::GetSpellLevel),	0x6434A7);
int (ResSplContainer::*ResSplContainer_GetSpellFlags)() =
	SetFP(static_cast<int (ResSplContainer::*)()>							(&ResSplContainer::GetSpellFlags),	0x643B06);

void ResSplContainer::Unload() { return (this->*ResSplContainer_Unload)(); }
void ResSplContainer::LoadResource(ResRef& r, BOOL bAddToHandler, BOOL bLogNotFound) { return (this->*ResSplContainer_LoadResource)(r, bAddToHandler, bLogNotFound); }
short ResSplContainer::GetSpellLevel() { return (this->*ResSplContainer_GetSpellLevel)(); }
int ResSplContainer::GetSpellFlags() { return (this->*ResSplContainer_GetSpellFlags)(); }
