//TobExEE
#include "debug.h"

#include "p_size.h"

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
#include "objdoor.h"
#include "objtext.h"
#include "objtrig.h"
#include "rescore.h"
#include "sndcore.h"
#include "tlkcore.h"
#include "vidcore.h"
#include "console.h"
#include "objvef.h"
#include "uitext.h"

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
	_CheckSize(SIZE_CAREA, CArea);
	_CheckSize(SIZE_CBALDURCHITIN, CBaldurChitin);
	_CheckSize(SIZE_CBUTTONARRAY, CButtonArray);
	_CheckSize(SIZE_CSCREENCHARGEN, CScreenCharGen);
	_CheckSize(SIZE_CCONTAINEROBJECT, CContainerObject);
	_CheckSize(SIZE_CCREATUREOBJECT, CCreatureObject);
	_CheckSize(SIZE_CDERIVEDSTATS, CDerivedStats);
	_CheckSize(SIZE_CDOOROBJECT, CDoorObject);
	_CheckSize(SIZE_CEFFECT, CEffect);
	_CheckSize(SIZE_CENGINE, CEngine);
	_CheckSize(SIZE_CGAMEOBJECT, CGameObject);
	_CheckSize(SIZE_CGAMESPRITE, CGameSprite);
	_CheckSize(SIZE_CGAMETEXT, CGameText);
	_CheckSize(SIZE_CGUIMAIN, CBaldurChitin::CGUIMain);
	_CheckSize(SIZE_CINFCURSOR, CInfCursor);
	_CheckSize(SIZE_CINFGAME, CInfGame);
	_CheckSize(SIZE_CSCREENINVENTORY, CScreenInventory);
	_CheckSize(SIZE_CREMOTEMESSAGEHANDLER, CRemoteMessageHandler);
	_CheckSize(SIZE_CNETWORK, CNetwork);
	_CheckSize(SIZE_CNETWORKWINDOW, CNetworkWindow);
	_CheckSize(SIZE_COBJECTMARKER, CObjectMarker);
	_CheckSize(SIZE_CPROJECTILE, CProjectile);
	_CheckSize(SIZE_CPROJECTILEAREA, CProjectileArea);
	_CheckSize(SIZE_CPROJECTILEBAM, CProjectileBAM);
	_CheckSize(SIZE_CRESHANDLER, CResHandler);
	_CheckSize(SIZE_CSOUND, CSound);
	_CheckSize(SIZE_CSOUNDMIXER, CSoundMixer);
	_CheckSize(SIZE_CSCREENRECORD, CScreenRecord);
	_CheckSize(SIZE_CSTORE, CStore);
	_CheckSize(SIZE_CSCREENMAGEBOOK, CScreenMageBook);
	_CheckSize(SIZE_CSCREENPRIESTBOOK, CScreenPriestBook);
	_CheckSize(SIZE_CSCREENSTORE, CScreenStore);
	_CheckSize(SIZE_CTLKTBL, CTlkTbl);
	_CheckSize(SIZE_CTRIGGEROBJECT, CTriggerObject);
	_CheckSize(SIZE_CUIBUTTON, CUIButton);
	_CheckSize(SIZE_CUISCROLLBAR, CUIScrollBar);
	_CheckSize(SIZE_CUITEXTAREA, CUITextArea);
	_CheckSize(SIZE_CUITEXTBAR, CUITextBar);
	_CheckSize(SIZE_CUITEXTFIELD, CUITextField);
	_CheckSize(SIZE_CVIDCELL, CVidCell);
	_CheckSize(SIZE_CVIDEO, CVideo);
	_CheckSize(SIZE_CVISUALEFFECTVIDCELL, CVisualEffectVidCell);
	_CheckSize(SIZE_CSCREENWORLD, CScreenWorld);

	//to check location of members, just replace the temp object type, member name and expected location
	//CCreatureObject temp;
	//console.write("CCreatureObject.cscTarget at 3714h, actual location: %Xh\r\n", 1, (int)(&temp.cscTarget) - (int)(&temp));

	return;
}