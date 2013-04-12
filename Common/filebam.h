#ifndef FILEBAM_H
#define FILEBAM_H

#include "stdafx.h"
#include "resref.h"

struct BamFileFrameEntry { //Size Ch
	short width;
	short height;
	short x;
	short y;
	unsigned int dwFlags;
};

#endif //FILEBAM_H