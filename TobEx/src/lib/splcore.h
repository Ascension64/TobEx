#ifndef SPLCORE_H
#define SPLCORE_H

#include "rescore.h"

typedef IECPtrList CMemSpellList; //AAA8E4
typedef IECPtrList CKnownSpellList; //AAA8CC

struct ResSplContainer { //Size 10h
	BOOL bLoaded; //0h
	ResSpl* pRes; //4h
	ResRef name; //8h
};

#endif //SPLCORE_H