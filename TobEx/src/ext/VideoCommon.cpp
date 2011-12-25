#include "VideoCommon.h"

#include "vidcore.h"
#include "chitin.h"

void UnpackRGB565(WORD color, BYTE &r, BYTE &g, BYTE &b) {
	r = (color >> 8) & 0xF8;
	g = (color >> 3) & 0xFC;
	b = (color << 3) & 0xF8;
	return;
}

WORD PackRGB565(BYTE r, BYTE g, BYTE b) {
    WORD color;
    color = (r & 0xF8) << 8;
    color += (g & 0xFC) << 3;
    color += b >> 3;
    return color;
}

void UnpackRGB8888(DWORD color, BYTE &a, BYTE &r, BYTE &g, BYTE &b) {
	a = (color >> 24) & 0xFF;
	r = (color >> 16) & 0xFF;
	g = (color >> 8) & 0xFF;
	b = color & 0xFF;
	return;
}

WORD PackRGB8888(BYTE a, BYTE r, BYTE g, BYTE b) {
    return ((a << 24) | (r << 16) | (g << 8) | b);
}