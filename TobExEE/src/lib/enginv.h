//TobExEE
#ifndef ENGINV_H
#define ENGINV_H

#include "engine.h"
#include "itmcore.h"

class CScreenInventory : public CEngine { //Size 834h
public:
	virtual void Init(); //v18

	CItem* m_pItemGrabbed; //d0h
	int ud4;
	int ud8;
	short udc;
	char ude;
	char udf;
	CHotkey m_keymap[95]; //e0h
	int m_keybuffer[95]; //554h
	char u6d0;
	char p6d1[3];
	int u6d4;
	int u6d8;
	int u6dc;
	ENUM m_eContainersOpened[6]; //6e0h, current container interacted with by each player
	BOOL m_bContainerSearched[6]; //6f8h, one for each playerId
	int u710;
	int u714;
	IECPtrList m_lPanels; //718h
	int u734;

	struct unk1 { //Size 34h
		ResRef u0;
		int u8;
		ResRef uc;
		int u14;
		short u18;
		char p1a[2];
		struct unk2 { //Size 14h
			short u0;
			short u2;
			short u4;
			ResRef u6;
			short ue;
			int u10;
		} u1c;
		char u30;
		char u31;
		char p32[2];
	} u738;

	int u4d6;
	int u4da; //related to 4deh, index?
	STRREF m_strrefError; //4deh
	int u4e2;
	STRREF m_strrefErrorButtons[3]; //u4e6
	int u4f2;
	int u4f6;
	int m_nPlayerIdxOfGrabbedItem; //4fah
	int m_nSlotOfGrabbedItem; //4feh
	BOOL m_bCanModifyInventory; //502h

	ResRef u79c;
	int u7a4;
	int u7a8; //BOOL bHadGrabbedItemWhenLeftInv?
	bool m_bShowNoLongerPauseInStatus; //7ac, 0: show in error dialog, 1: show in inventory area
	char p7ad[3];
	CVidFont u7b0;
	CVidFont u7d4;
	CVidFont u7f8;
	IECString u81c;
	IECString u820;
	int u824;
	int u828;
	int u82c;
	BOOL m_bWorldPaused; //830h, from CScreenWorld.146h;
};

#endif //ENGINV_H