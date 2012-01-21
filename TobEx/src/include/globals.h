#ifndef GLOBALS_H
#define GLOBALS_H

#include "win32def.h"

#include "rule.h"
#include "datacons.h"

static const unsigned short* const g_pNumInventorySlots = (const unsigned short* const )0xAB0998;
static const unsigned int* const g_pEnableWildMage = (const unsigned int* const )0xAB3BCC;
static const short* const g_pHPHurtThresholdPercent = (const short* const )0xAB7398;
static const int* const g_pRandStealGoldChance = (const int* const )0xAB73B4;
static const int* const g_pRandGoldToSteal = (const int* const )0xAB73B8;
static const unsigned char* const g_pInventorySlots = (const unsigned char* const )0xAB73F5;

extern int (__cdecl *GetLongestAxialDistance)(POINT& pt1, POINT& pt2);
extern int (__cdecl *DieRoll)(int nDieSize, int nAdd);

#endif //GLOBALS_H