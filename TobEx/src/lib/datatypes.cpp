#include "datatypes.h"

//ITEM_EFFECT
void* ITEM_EFFECT::operator new(size_t size) { return ::operator new(size, 0); }
void ITEM_EFFECT::operator delete(void* mem) { return ::operator delete(mem, 0); } 
