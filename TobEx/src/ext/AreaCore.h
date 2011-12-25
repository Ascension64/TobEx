#ifndef AREACORE_H
#define AREACORE_H

#include "utils.h"

#include "arecore.h"

extern BYTE (CArea::*Tramp_CArea_GetSong)(WORD);

class DETOUR_CArea : public CArea {
public:
	DWORD DETOUR_GetSong(WORD);
};

#endif //AREACORE_H