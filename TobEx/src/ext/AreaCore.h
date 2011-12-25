#ifndef AREACORE_H
#define AREACORE_H

#include "stdafx.h"

#include "arecore.h"

extern char (CArea::*Tramp_CArea_GetSong)(short);

class DETOUR_CArea : public CArea {
public:
	int DETOUR_GetSong(short wType);
};

#endif //AREACORE_H