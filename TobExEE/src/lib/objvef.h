//TobExEE
#ifndef OBJVEF_H
#define OBJVEF_H

#include "stdafx.h"
#include "rescore.h"
#include "scrcore.h"
#include "vidcore.h"
#include "sndcore.h"
#include "pathfind.h"
#include "objcore.h"

typedef IECPtrList CVefComponentList;

class CVisualEffectVidCell : public CGameObject { //Size 354h
public:
	VvcFileBase m_vvc; //48h
	CVidCell* m_pVidAnim1; //22ch, related to nameAnim1
	CVidCell* m_pVidAnim2; //230h, related to nameAnim2 (N.B. anim1 loaded here in constructor instead)
	VidPal u234;
	CVidBitmap m_bitmap; //258h, object of nameBitmap
	BOOL m_bDurationElapsed; //30ch
	int m_nOrientation; //310h
	TerrainTable u314; //050505ff, 05050505, 05ff0505, 0505ff05
	CSoundWrapper u324; //for currentSnd
	CVidCell* m_pVidAnim3; //33ch, related to nameAnim3
	char m_nPurgeType; //340h, 1 = name as ResRef in CMessage, 2 = nameanim1 as ResRef in CMessage
	char u341; //played middle sound? no sound?
	char p342[2];
	int u344;

	//these three actually unused?
	int u348; //gets VvcArray.0xa (dw)
	int u34c; //gets VvcArray.0xe (dw), copied to CVisualEffect 2a2h
	int u350; //gets VvcArray.0x8 (w), compared with pGame->4dc4
};

struct ResVvcFile { //Size 10h
	BOOL m_bLoaded;
	ResVid* m_pRes;
	ResRef m_rName;
};

struct VefFileHeader { //Size 1C0h
	int u0;
	int u4;
	int u8;
	int uc;
	int u10; //has owner (or 6e has flags?)
	int m_nSpeed; //14h, Arg8 (zPos)
	int m_nDuration; //18h, purge if m_nAIUpdates > this, unless duration <= 0
	CPoint u1c;
	int u24; //zPos?
	int u28;

	//bit0 = do not purge if no more vid cells/vef components
	//bit1 = update zPos
	//bit2 = attached to an owner (cre or projectileBAM)
	DWORD m_dwFlags; //2ch
	int u30;
	int u34;
	int u38;
	short u3c;
	char u3e;
	char u3f;
	int u40;
	int u44;
	int u48;
	int u4c;
	short u50;
	int u52;
	int u56;
	int u5a;
	int u5e[2];
	short u66;
	int u68[0x56];
};

class CVisualEffect : public CGameObject { //Size 2ACh
	DEFINE_MEMALLOC_FUNC;
public:
	VefFileHeader m_header; //48h
	CEnumList m_lVidCells; //208h, contains CVisualEffectVidCell enums
	CVefComponentList m_lVefComponents; //224h, VefFileComponent1 and VefFileComponent2
	CVefComponentList m_lVefComponents2; //240h, unused
	CPoint m_ptSource; //25ch, directly from constructor
	ENUM m_eOwner; //264h
	CPoint m_ptPixels; //268h, set when AddToArea(), adds 27eh, y is 4/3 normal (in pixels, not x.y pos, 1024 pixels per pos)
	CPoint m_ptPrev; //270h (copied from 6h and ah during AIUpdate)
	int m_nAIUpdates; //278h
	int u27c;
	int m_nOrientation; //280h, range: 0x0-0x10
	CPoint m_ptToAdd; //284h, how much to move in next tick, y is 4/3 normal (in pixel, not x.y pos)
	int u28c[4]; //set of constants
		
	//this is used to DisplayAllBams()
	//when one Vvc in VefVidCellList terminates due to end of duration, a new one is created based on this
	CKeyTableEntryList* u29c;
	POSITION* u2a0; //gets the m_pNodeHead of u296
	BOOL u2a4; //bHasPosition (1 if u29a has a position)

	int u2a8;
};

#endif //OBJVEF_H