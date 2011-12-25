#ifndef OBJVEF_H
#define OBJVEF_H

#include "utils.h"
#include "resref.h"
#include "rescore.h"
#include "scrcore.h"
#include "vidcore.h"
#include "sndcore.h"
#include "pathfind.h"
#include "objcore.h"

typedef CPtrList CPtrListVefComponent; //AAD00C

struct ResVvcContainer { //Size 10h
	BOOL bLoaded;
	ResVid* pRes;
	ResRef name;
};

class CVisualEffect : public CGameObject {
//Size: 0x2A6
//vtable: 0xAACFA8
//Constructor: 0x65467D
public:
	virtual void v0() {}
	virtual void v4() {}
	virtual void v8() {}
	virtual void vc() {}
	virtual Object& GetObject() { return o; } //return a value

	//struct;
	DWORD u42[0x70]; //0x42
	/*DWORD u52; //has ownerEnum? or 6e has flags?
	DWORD nSpeed; //56h, Arg8 (zPos)
	DWORD u5a;
	POINT u5e;
	DWORD u66;
	DWORD u6a;
	DWORD flags; //6eh
	//bit0 = has entry in u296
	//bit1 = update zPos
	//bit2 = purge owner

	BYTE u80;
	DWORD u94;
	DWORD u98;
	DWORD u9c;
	QWORD ua0;*/

	CEnumList vvcs; //202h, contains CVisualEffectVidCell enums
	CPtrListVefComponent vefComponents; //21eh, VefFileComponent1 and VefFileComponent2
	CPtrListVefComponent u23a; //unused
	POINT ptSource; //256h, directly from constructor
	Enum eOwner; //25eh
	POINT u262; //x * 2^16 and (y*4/3) * 2^16
	POINT ptPrev; //26ah (copied from 6h and ah during AIUpdate)
	DWORD u272; //nAiUpdates?
	DWORD u276;
	DWORD orientation; //27ah, range: 0x0-0x10
	POINT u27e;
	DWORD u286[4]; //set of constants
		
	//this is used to DisplayAllBams()
	//when one Vvc in VefVidCellList terminates due to end of duration, a new one is created based on this
	CPtrListKeyTableEntry* u296;
	POSITION* u29a; //gets the m_pNodeHead of u296
	BOOL u29e; //bHasPosition (1 if u29a has a position)

	DWORD u2a2;
};

class CVisualEffectVidCell : public CGameObject {
//Size: 0x3A0
//vtable: 0xAACED0
//Constructor: 0x64C5FE
public:
	virtual void v0() {}
	virtual void v4() {}
	virtual void v8() {}
	virtual void vc() {}
	virtual Object& GetObject() { return o; } //return a value

	//struct;
	ResRef nameAnim1; //0x42 -- 8h
	ResRef nameAnim2; //0x4a -- 10h, this animation is set to zPos on top of anim1 (anim1.y + zPos)
	DWORD displayFlags; //0x52, -- 18h
	DWORD u56; //0x56 -- 1ch
	DWORD seqFlags; //0x5a -- 20h (bit2: use zPos, bit4: has nameBitmap, bit5: send CMessage then purge)
	DWORD u5e; //0x5e -- 24h
	POINT ptOffset; //0x62 -- 28h
	BOOL bUseOrientation; //0x6a -- 30h, sensitive to orientation
	DWORD nFrameRate; //0x6e -- 34h
	DWORD nOrientations; //0x72 -- 38h, can be 0/1, 8, and 16
	DWORD defaultOrientation; //0x76 -- 3ch, used when coordinates are equal, modified over time
	DWORD orientationFlags; //0x7a -- 40h (none = VisFX current relative to VisFX previous, bit 0 = this relative to source VisFX, bit 1 = use parent creature orientation, bit 3 = as 0, bit 4 = ignore orientation)
	ResRef nameBitmap; //0x7e -- 44h
	DWORD zOffset; //0x86, -- 4ch
	POINT ptCentre; //0x8a, -- 50h, used on seqbit1 translate centre point by x.y and enlarge frame by 2x.2y
	//8ah also determines the frame of GRNDGLOW to use (frame = (8ah - 3)/5)

	DWORD glowBrightness; //0x92, -- 58h, BYTE only, sets how much RGB to brighten the GRNDGLOW
	DWORD duration; //0x96, in frames, -- 5c
	ResRef name; //9ah, VvcFilename, not unmarshaled
	DWORD animCycleBegin; //0xa2, -- 68h, related to all three anims
	DWORD animCycleMiddle; //0xa6, -- 6ch
	DWORD currCycle; //0xaa, -- 70h, end of cycle number of which to transition to end cycle/sound; if 0, then set to equal the Begin cycle
	DWORD spanCycles; //0xae, bit0 = span multiple cycles, not unmarshaled
	ResRef sndBegin; //0xb2, -- 78h
	ResRef sndMiddle; //0xba, -- 80h
	ResRef nameAnim3; //0xc2, -- 88h
	DWORD animCycleEnd; //0xca, -- 90h
	ResRef sndEnd; //0xce, -- 94h
	char ud6[0x150]; //unused stuff?, not unmarshaled

	CVidCell* anim1; //226h, related to nameAnim1
	CVidCell* anim2; //22ah, related to nameAnim2 (N.B. anim1 loaded here in constructor instead)
	VidPal u22e; //size 0x24
	CVidBitmap bitmap; //252h, object of nameBitmap
	DWORD u308; //bDurationElapsed, 1 = duration finished
	DWORD u30c; //ranges from 0x0-0x10, orientation
	TerrainTable u310; //050505ff, 05050505, 05ff0505, 0505ff05
	CSound u320; //320h, size 0x6a, for currentSnd
	CVidCell* anim3; //38ah, related to nameAnim3
	BYTE u38e; //purgetype; 1 = name as ResRef in CMessage, 2 = nameanim1 as ResRef in CMessage
	BYTE u38f; //played middle sound? no sound?
	DWORD u390;

	//these three actually unused?
	DWORD u394; //gets VvcArray.0xa (dw)
	DWORD u398; //gets VvcArray.0xe (dw), copied to CVisualEffect 2a2h
	DWORD u39c; //gets VvcArray.0x8 (w), compared with pGame->4dc4
};

#endif //OBJVEF_H