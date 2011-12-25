#ifndef VIDEOCOMMON_H
#define VIDEOCOMMON_H

#include "stdafx.h"

void UnpackRGB565(unsigned short color, unsigned char& b, unsigned char& g, unsigned char& r);
short PackRGB565(unsigned char b, unsigned char g, unsigned char r);
void UnpackRGB8888(unsigned int color, unsigned char& a, unsigned char& b, unsigned char& g, unsigned char& r);
short PackRGB8888(unsigned char a, unsigned char b, unsigned char g, unsigned char r);

#endif //VIDEOCOMMON_H
