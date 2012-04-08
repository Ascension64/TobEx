#include "debug.h"

#include "animext.h"
#include "chitin.h"
#include "engine.h"
#include "engstore.h"
#include "infcursor.h"
#include "infbtarr.h"
#include "infgame.h"
#include "msgcore.h"
#include "network.h"
#include "objare.h"
#include "objcont.h"
#include "objcre.h"
#include "objtext.h"
#include "rescore.h"
#include "sndcore.h"
#include "tlkcore.h"
#include "vidcore.h"
#include "console.h"
#include "objvef.h"
#include "uitext.h"

#define SIZE_CANIMATION0000			0x0976
#define SIZE_CANIMATION1000			0x073A
#define SIZE_CANIMATION1200			0x0AC6
#define SIZE_CANIMATION1300			0x07F4
#define SIZE_CANIMATION2000			0x0E0C
#define SIZE_CANIMATION3000			0x1106
#define SIZE_CANIMATION4000			0x07E4
#define SIZE_CANIMATION5000			0x16E0
#define SIZE_CANIMATION6400			0x36B0
#define SIZE_CANIMATION7000			0x0B2C
#define SIZE_CANIMATION7300			0x0D3C
#define SIZE_CANIMATION8000			0x0E02
#define SIZE_CANIMATION9000			0x0C1A
#define SIZE_CANIMATIONA000			0x0C1A
#define SIZE_CANIMATIONB000			0x08C2
#define SIZE_CANIMATIONC000			0x08CA
#define SIZE_CANIMATIOND000			0x07E4
#define SIZE_CANIMATIONE000			0x3278
#define SIZE_CBALDURCHITIN			0x720C
#define SIZE_CBUTTONARRAY			0x1820
#define SIZE_CSCREENCHARGEN			0x148C
#define SIZE_CCONTAINEROBJECT		0x0712
#define SIZE_CCREATUREOBJECT		0x6774
#define SIZE_CENGINE				0x00FE
#define SIZE_CGAMETEXT				0x0620
#define SIZE_CGUIMAIN				0x19E8
#define SIZE_CINFCURSOR				0x08F6
#define SIZE_CINFGAME				0x4DC8
#define SIZE_CSCREENINVENTORY		0x1424
#define SIZE_CMESSAGEHANDLER		0x0114
#define SIZE_CNETWORK				0x0F3A
#define SIZE_CNETWORKWINDOW			0x0088
#define SIZE_COBJECTMARKER			0x005E
#define SIZE_CRESHANDLER			0x02A8
#define SIZE_CSOUND					0x006A
#define SIZE_CSOUNDMIXER			0x28DA
#define SIZE_CSCREENRECORD			0x1520
#define SIZE_CSTORE					0x00DC
#define SIZE_CSCREENSTORE			0x148A
#define SIZE_CTLKTBL				0x00A6
#define SIZE_CUITEXTAREA			0x0AA8
#define SIZE_CVIDEO					0x0168
#define SIZE_CVIDEOMODE				0x0732
#define SIZE_CVISUALEFFECTVIDCELL	0x03A0
#define SIZE_CSCREENWORLD			0x124C

void CheckSize(LPCTSTR lpszName, size_t nExpectedSize, size_t nActualSize) {
	if (nActualSize != nExpectedSize) console.writef("Debug(): %s has incorrect size 0x%X (expected 0x%X)\r\n", lpszName, nActualSize, nExpectedSize);
	return;
}

void Debug() {
	_CheckSize(SIZE_CANIMATION0000, CAnimation0000);
	_CheckSize(SIZE_CANIMATION1000, CAnimation1000);
	_CheckSize(SIZE_CANIMATION1200, CAnimation1200);
	_CheckSize(SIZE_CANIMATION1300, CAnimation1300);
	_CheckSize(SIZE_CANIMATION2000, CAnimation2000);
	_CheckSize(SIZE_CANIMATION3000, CAnimation3000);
	_CheckSize(SIZE_CANIMATION4000, CAnimation4000);
	_CheckSize(SIZE_CANIMATION5000, CAnimation5000);
	_CheckSize(SIZE_CANIMATION6400, CAnimation6400);
	_CheckSize(SIZE_CANIMATION7000, CAnimation7000);
	_CheckSize(SIZE_CANIMATION8000, CAnimation8000);
	_CheckSize(SIZE_CANIMATION9000, CAnimation9000);
	_CheckSize(SIZE_CANIMATIONA000, CAnimationA000);
	_CheckSize(SIZE_CANIMATIONB000, CAnimationB000);
	_CheckSize(SIZE_CANIMATIONC000, CAnimationC000);
	_CheckSize(SIZE_CANIMATIOND000, CAnimationD000);
	_CheckSize(SIZE_CANIMATIONE000, CAnimationE000);
	_CheckSize(SIZE_CBALDURCHITIN, CBaldurChitin);
	_CheckSize(SIZE_CBUTTONARRAY, CButtonArray);
	_CheckSize(SIZE_CSCREENCHARGEN, CScreenCharGen);
	_CheckSize(SIZE_CCONTAINEROBJECT, CContainerObject);
	_CheckSize(SIZE_CCREATUREOBJECT, CCreatureObject);
	_CheckSize(SIZE_CENGINE, CEngine);
	_CheckSize(SIZE_CGAMETEXT, CGameText);
	_CheckSize(SIZE_CGUIMAIN, CBaldurChitin::CGUIMain);
	_CheckSize(SIZE_CINFCURSOR, CInfCursor);
	_CheckSize(SIZE_CINFGAME, CInfGame);
	_CheckSize(SIZE_CSCREENINVENTORY, CScreenInventory);
	_CheckSize(SIZE_CMESSAGEHANDLER, CMessageHandler);
	_CheckSize(SIZE_CNETWORK, CNetwork);
	_CheckSize(SIZE_CNETWORKWINDOW, CNetworkWindow);
	_CheckSize(SIZE_COBJECTMARKER, CObjectMarker);
	_CheckSize(SIZE_CSOUND, CSound);
	_CheckSize(SIZE_CSOUNDMIXER, CSoundMixer);
	_CheckSize(SIZE_CSCREENRECORD, CScreenRecord);
	_CheckSize(SIZE_CSTORE, CStore);
	_CheckSize(SIZE_CSCREENSTORE, CScreenStore);
	_CheckSize(SIZE_CTLKTBL, CTlkTbl);
	_CheckSize(SIZE_CUITEXTAREA, CUITextArea);
	_CheckSize(SIZE_CVIDEO, CVideo);
	_CheckSize(SIZE_CVIDEOMODE, CVideoMode);
	_CheckSize(SIZE_CVISUALEFFECTVIDCELL, CVisualEffectVidCell);
	_CheckSize(SIZE_CSCREENWORLD, CScreenWorld);

	//to check location of members, just replace the temp object type, member name and expected location
	//CCreatureObject temp;
	//console.write("CCreatureObject.cscTarget at 3714h, actual location: %Xh\r\n", 1, (int)(&temp.cscTarget) - (int)(&temp));

	return;
}