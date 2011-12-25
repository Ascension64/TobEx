#include "debug.h"

#include "chitin.h"
#include "engine.h"
#include "infcursor.h"
#include "infgame.h"
#include "msgcore.h"
#include "network.h"
#include "objcre.h"
#include "rescore.h"
#include "sndcore.h"
#include "tlkcore.h"
#include "vidcore.h"
#include "console.h"
#include "objvef.h"

#define SIZE_CBALDURCHITIN			0x720C
#define SIZE_CBUTTONARRAY			0x1820
#define SIZE_CCHARGEN				0x148C
#define SIZE_CCREATUREOBJECT		0x6774
#define SIZE_CENGINE				0x00FE
#define SIZE_CGUIMAIN				0x19E8
#define SIZE_CINFCURSOR				0x08F6
#define SIZE_CINFGAME				0x4DC8
#define SIZE_CMESSAGEHANDLER		0x0114
#define SIZE_CNETWORK				0x0F3A
#define SIZE_CNETWORKWINDOW			0x0088
#define SIZE_CRESHANDLER			0x02A8
#define SIZE_CSOUND					0x006A
#define SIZE_CSOUNDMIXER			0x28DA
#define SIZE_CRECORD				0x1520
#define SIZE_CSERVERSTORE			0x00DC
#define SIZE_CSTORE					0x148A
#define SIZE_CTLKTBL				0x00A6
#define SIZE_CVIDEO					0x0168
#define SIZE_CVIDEOMODE				0x0732
#define SIZE_CVISUALEFFECTVIDCELL	0x03A0

void CheckSize(LPCTSTR lpszName, size_t nExpectedSize, size_t nActualSize) {
	if (nActualSize != nExpectedSize) console.write("Debug(): %s has incorrect size 0x%X (expected 0x%X)\r\n", 3, lpszName, nActualSize, nExpectedSize);
	return;
}

void Debug() {
	_CheckSize(SIZE_CBALDURCHITIN, CBaldurChitin);
	_CheckSize(SIZE_CBUTTONARRAY, CInfGame::CButtonArray);
	_CheckSize(SIZE_CCHARGEN, CCharGen);
	_CheckSize(SIZE_CCREATUREOBJECT, CCreatureObject);
	_CheckSize(SIZE_CENGINE, CEngine);
	_CheckSize(SIZE_CGUIMAIN, CBaldurChitin::CGUIMain);
	_CheckSize(SIZE_CINFCURSOR, CInfCursor);
	_CheckSize(SIZE_CINFGAME, CInfGame);
	_CheckSize(SIZE_CMESSAGEHANDLER, CMessageHandler);
	_CheckSize(SIZE_CNETWORK, CNetwork);
	_CheckSize(SIZE_CNETWORKWINDOW, CNetworkWindow);
	_CheckSize(SIZE_CSOUND, CSound);
	_CheckSize(SIZE_CSOUNDMIXER, CSoundMixer);
	_CheckSize(SIZE_CRECORD, CRecord);
	_CheckSize(SIZE_CSERVERSTORE, CServerStore);
	_CheckSize(SIZE_CSTORE, CStore);
	_CheckSize(SIZE_CTLKTBL, CTlkTbl);
	_CheckSize(SIZE_CVIDEO, CVideo);
	_CheckSize(SIZE_CVIDEOMODE, CVideoMode);
	_CheckSize(SIZE_CVISUALEFFECTVIDCELL, CVisualEffectVidCell);

	//to check location of members, just replace the temp object type, member name and expected location
	//CCreatureObject temp;
	//console.write("CCreatureObject.cscTarget at 3714h, actual location: %Xh\r\n", 1, (int)(&temp.cscTarget) - (int)(&temp));

	return;
}