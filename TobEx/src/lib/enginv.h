#ifndef ENGINV_H
#define ENGINV_H

#include "engine.h"
#include "itmcore.h"

class CScreenInventory : public CEngine { //Size 1424h
public:
	//AB09AC
	virtual void Init(); //v14

	CItem* pItemGrabbed; //feh
	int u102;
	int u106;
	short u10a;
	char u10c;
	char u10d;

	CHotkey keymap[91]; //10eh
	char keybuffer[92]; //3e6h

	int u442;
	int u446;
	int u44a;
	Enum eContainersOpened[6]; //44eh, current container interacted with by each player
	BOOL bContainerSearched[6]; //466h, one for each playerId
	int u47e;
	int u482;
	IECPtrList u486; //of panels
	int u4a2;
	struct _u4a6 { //Size 30h
		ResRef u0;
		int u8;
		ResRef uc;
		int u14;
		short u18;
		struct _u1a { //Size 14h
			short u0;
			short u2;
			short u4;
			ResRef u6;
			short ue;
			int u10;
		} u1a;
		char u2e;
		char u2f;
	} u4a6;

	int u4d6;
	int u4da; //related to 4deh, index?
	STRREF strrefError; //4deh
	int u4e2;
	STRREF strrefErrorButtons[3]; //u4e6
	int u4f2;
	int u4f6;
	int nPlayerIdxOfGrabbedItem; //4fah
	int nSlotOfGrabbedItem; //4feh
	BOOL bCanModifyInventory; //502h
	ResRef u506;
	int u50e;
	int u512; //BOOL bHadGrabbedItemWhenLeftInv?
	bool bShowNoLongerPauseInStatus; //516h, 0: show in error dialog, 1: show in inventory area
	char u517; //pad
	CVidFont u518;
	CVidFont ua14;
	CVidFont uf10;
	IECString u140c;
	IECString u1410;
	int u1414;
	int u1418;
	int u141c;
	BOOL bWorldPaused; //from CScreenWorld.146h;
};

extern void (CScreenInventory::*CScreenInventory_Init)();

#endif //ENGINV_H