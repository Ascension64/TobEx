#include "VideoCommon.h"

#include "vidcore.h"
#include "chitin.h"

void UnpackRGB565(unsigned short color, unsigned char &r, unsigned char &g, unsigned char &b) {
	r = (color >> 8) & 0xF8;
	g = (color >> 3) & 0xFC;
	b = (color << 3) & 0xF8;
	return;
}

short PackRGB565(unsigned char r, unsigned char g, unsigned char b) {
    short color;
    color = (r & 0xF8) << 8;
    color += (g & 0xFC) << 3;
    color += b >> 3;
    return color;
}

void UnpackRGB8888(unsigned int color, unsigned char &a, unsigned char &r, unsigned char &g, unsigned char &b) {
	a = (color >> 24) & 0xFF;
	r = (color >> 16) & 0xFF;
	g = (color >> 8) & 0xFF;
	b = color & 0xFF;
	return;
}

short PackRGB8888(unsigned char a, unsigned char r, unsigned char g, unsigned char b) {
    return ((a << 24) | (r << 16) | (g << 8) | b);
}