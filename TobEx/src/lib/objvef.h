#ifndef OBJVEF_H
#define OBJVEF_H

#include "stdafx.h"
#include "rescore.h"
#include "scrcore.h"
#include "vidcore.h"
#include "sndcore.h"
#include "pathfind.h"
#include "objcore.h"

typedef IECPtrList CVefComponentList; //AAD00C

struct ResVvcContainer { //Size 10h
	BOOL bLoaded;
	ResVid* pRes;
	ResRef name;
};

class CVisualEffect : public CGameObject { //Size 2A6h
//Constructor: 0x65467D
public:
	//AACFA8

	//struct;
	int u42[0x70]; //42h
	/*int u52; //has ownerEnum? or 6e has flags?
	int nSpeed; //56h, Arg8 (zPos)
	int u5a;
	POINT u5e;
	int u66;
	int u6a;
	int flags; //6eh
	//bit0 = has entry in u296
	//bit1 = update zPos
	//bit2 = purge owner

	char u80;
	int u94;
	int u98;
	int u9c;
	long long ua0;*/

	CEnumList m_VidCells; //202h, contains CVisualEffectVidCell enums
	CVefComponentList m_VefComponents; //21eh, VefFileComponent1 and VefFileComponent2
	CVefComponentList m_VefComponents2; //23ah, unused
	POINT ptSource; //256h, directly from constructor
	Enum eOwner; //25eh
	POINT u262; //x * 2^16 and (y*4/3) * 2^16
	POINT ptPrev; //26ah (copied from 6h and ah during AIUpdate)
	int u272; //nAiUpdates?
	int u276;
	int orientation; //27ah, range: 0x0-0x10
	POINT u27e;
	int u286[4]; //set of constants
		
	//this is used to DisplayAllBams()
	//when one Vvc in VefVidCellList terminates due to end of duration, a new one is created based on this
	CKeyTableEntryList* u296;
	POSITION* u29a; //gets the m_pNodeHead of u296
	BOOL u29e; //bHasPosition (1 if u29a has a position)

	int u2a2;
};

class CVisualEffectVidCell : public CGameObject { //Size 3A0h
//Constructor: 0x64C5FE
public:
	//AACED0
	VvcFileData vvc; //42h
	CVidCell* anim1; //226h, related to nameAnim1
	CVidCell* anim2; //22ah, related to nameAnim2 (N.B. anim1 loaded here in constructor instead)
	VidPal u22e; //size 0x24
	CVidBitmap bitmap; //252h, object of nameBitmap
	int u308; //bDurationElapsed, 1 = duration finished
	int u30c; //ranges from 0x0-0x10, orientation
	TerrainTable u310; //050505ff, 05050505, 05ff0505, 0505ff05
	CSound u320; //320h, size 0x6a, for currentSnd
	CVidCell* anim3; //38ah, related to nameAnim3
	char u38e; //purgetype; 1 = name as ResRef in CMessage, 2 = nameanim1 as ResRef in CMessage
	char u38f; //played middle sound? no sound?
	int u390;

	//these three actually unused?
	int u394; //gets VvcArray.0xa (dw)
	int u398; //gets VvcArray.0xe (dw), copied to CVisualEffect 2a2h
	int u39c; //gets VvcArray.0x8 (w), compared with pGame->4dc4
};

#endif //OBJVEF_H