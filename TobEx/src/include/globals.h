#ifndef GLOBALS_H
#define GLOBALS_H

#include "rule.h"
#include "datacons.h"

static const unsigned int* g_pEnableWildMage = (const unsigned int*)0xAB3BCC;
static const short* g_pHPHurtThresholdPercent = (const short*)0xAB7398;

extern int (__cdecl *DieRoll)(int nDieSize, int nAdd);

#endif //GLOBALS_H