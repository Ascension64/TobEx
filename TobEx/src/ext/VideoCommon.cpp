#include "VideoCommon.h"

#include "vidcore.h"
#include "chitin.h"

void UnpackRGB565(unsigned short color, unsigned char &b, unsigned char &g, unsigned char &r) {
	b = (color >> 8) & 0xF8;
	g = (color >> 3) & 0xFC;
	r = (color << 3) & 0xF8;
	return;
}

short PackRGB565(unsigned char b, unsigned char g, unsigned char r) {
    short color;
    color = (b & 0xF8) << 8;
    color += (g & 0xFC) << 3;
    color += r >> 3;
    return color;
}

void UnpackRGB8888(unsigned int color, unsigned char &a, unsigned char &b, unsigned char &g, unsigned char &r) {
	a = (color >> 24) & 0xFF;
	b = (color >> 16) & 0xFF;
	g = (color >> 8) & 0xFF;
	r = color & 0xFF;
	return;
}

short PackRGB8888(unsigned char a, unsigned char b, unsigned char g, unsigned char r) {
    return ((a << 24) | (b << 16) | (g << 8) | r);
}