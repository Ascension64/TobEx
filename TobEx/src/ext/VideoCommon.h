#ifndef VIDEOCOMMON_H
#define VIDEOCOMMON_H

#include "stdafx.h"

void UnpackRGB565(unsigned short, unsigned char&, unsigned char&, unsigned char&);
short PackRGB565(unsigned char, unsigned char, unsigned char);
void UnpackRGB8888(unsigned int, unsigned char&, unsigned char&, unsigned char&, unsigned char&);
short PackRGB8888(unsigned char, unsigned char, unsigned char, unsigned char);

#endif //VIDEOCOMMON_H
