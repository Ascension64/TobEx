#ifndef FILEBIF_H
#define FILEBIF_H

#include "stdafx.h"
#include "resref.h"

struct BifFileHeader { //Size 14h
	int dwFileType; //0h, of mmioFOURCC type
	int dwVersion; //4h
	int dwFiles; //8h
	int dwTiles; //ch
	int* pFiles; //10h
};

struct BifFileEntry { //Size 10h
	int dwResourceLocator; //0h
	int* pData; //4h
	int dwSize; //8h
	short dwFileType; //ch
	short eh; //eh
};

struct BifTileEntry { //Size 14h
	int dwResourceLocator; //0h
	int* pData; //4h
	int dwTiles; //8h
	int dwSize; //ch
	short dwFileType; //10h
	short u12; //12h
};

#endif //FILEBIF_H