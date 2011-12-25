#ifndef SPLCORE_H
#define SPLCORE_H

#include "resref.h"
#include "rescore.h"

typedef CPtrList CMemSpellList; //AAA8E4
typedef CPtrList CKnownSpellList; //AAA8CC

struct ResSplContainer { //Size 10h
	BOOL bLoaded; //0x0
	ResSpl* pRes; //0x4
	ResRef name; //0x8
};

#endif //SPLCORE_H