#ifndef GLOBALS_H
#define GLOBALS_H

#include "win32def.h"

#include "utils.h"
#include "rule.h"
#include "datacons.h"

typedef int STRREF;
typedef char SCRIPTNAME[32];
typedef unsigned int ENUM; //index to CGameObjectArray element

const ENUM ENUM_INVALID_INDEX = UINT_MAX;
const unsigned int g_nPEAddressDefault = 0x400000;

const char* const szEmpty = (const char* const)0xB7473C;

const unsigned short* const g_pNumInventorySlots = (const unsigned short* const)0xAB0998;
const unsigned int* const g_pEnableWildMage = (const unsigned int* const)0xAB3BCC;
const short* const g_pHPHurtThresholdPercent = (const short* const)0xAB7398;
const int* const g_pRandStealGoldChance = (const int* const)0xAB73B4;
const int* const g_pRandGoldToSteal = (const int* const)0xAB73B8;
const unsigned char* const g_pInventorySlots = (const unsigned char* const)0xAB73F5;

DefineGlobalFuncPtr(int, __cdecl, _GetLongestAxialDistance, (CPoint& pt1, CPoint& pt2), 0x4318DF);
DefineGlobalFuncPtr(int, __cdecl, _DieRoll, (int nDieSize, int nAdd), 0x99F330);

DefineGlobalFuncPtr(void*, __cdecl, _New, (size_t size), 0xA50608);
DefineGlobalFuncPtr(void, __cdecl, _Delete, (void* mem), 0xA50631);
DefineGlobalFuncPtr(int, __cdecl, _Rand, (void), 0xA39100);

inline void* __cdecl operator new (size_t size, int i) { return (*_New)(size); }
inline void* __cdecl operator new[] (size_t size, int i) { return (*_New)(size); }
inline void __cdecl operator delete (void* mem, int i) { return (*_Delete)(mem); }
inline void __cdecl operator delete[] (void* mem, int i) { return (*_Delete)(mem); }
inline int __cdecl IERand() { return (*_Rand)(); }
inline int __cdecl IERand(int n) { return IERand() * n >> 15; }

//overrides the class memory allocation functions to use the BGMain executable memory allocation functions
#define DEFINE_MEMALLOC_FUNC \
	public: \
	void* operator new(size_t size) { return ::operator new(size, 0); } \
	void operator delete(void* mem) { return ::operator delete(mem, 0); } \
	void operator delete[](void* mem) { return ::operator delete[](mem, 0); }

#endif //GLOBALS_H