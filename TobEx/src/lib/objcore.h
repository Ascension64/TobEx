#ifndef OBJCORE_H
#define OBJCORE_H

#include "utils.h"
#include "scrcore.h"
#include "arecore.h"
#include "sndcore.h"
#include "cstringex.h"

//CGameObject types
#define CGAMEOBJECT_TYPE_OBJECT		0x00
#define CGAMEOBJECT_TYPE_SPRITE		0x01
#define CGAMEOBJECT_TYPE_SOUND		0x10
#define CGAMEOBJECT_TYPE_CONTAINER	0x11
#define CGAMEOBJECT_TYPE_SPAWNING	0x20
#define CGAMEOBJECT_TYPE_DOOR		0x21
#define CGAMEOBJECT_TYPE_STATIC		0x30
#define CGAMEOBJECT_TYPE_CREATURE	0x31
#define CGAMEOBJECT_TYPE_5E			0x40
#define CGAMEOBJECT_TYPE_TRIGGER	0x41
#define CGAMEOBJECT_TYPE_TILE		0x51
#define CGAMEOBJECT_TYPE_SMOKE		0x60
#define CGAMEOBJECT_TYPE_AREA		0x61
#define CGAMEOBJECT_TYPE_BALDUR		0x71

//CGameObjectArrayHandler thread indices
const BYTE THREAD_ASYNCH = 0;
const BYTE THREAD_1 = 1;
const BYTE THREAD_2 = 2;

//CGameObjectArrayHandler return values (0xAAD1C4)
const BYTE OBJECT_SUCCESS = 0;
const BYTE OBJECT_LOCK_FAILED = 1;
const BYTE OBJECT_DELETED = 2; //Index.id does not match Enum.id
const BYTE OBJECT_BAD_ENUM = 3;
const BYTE OBJECT_SHARING = 4;
const BYTE OBJECT_DENYING = 5;

class _8DF1F2 {
//Related to current area sprite is in
//Size: 0x50
//Constructor: 0x008DF1F2, also 0x008DF105
public:
	IECString u0;
	WORD u4[2];
	QWORD u8;
	BYTE u10;
	BYTE u11; //padding?
	WORD u12;
	POINT u14; //current position?
	WORD u1c;
	DWORD u1e;
	WORD u22[8];
	DWORD u32;
	BYTE u36[5];
	BYTE u3b; //padding?
	IECString u3c; //current area name?
	BYTE u40;
	BYTE u41; //padding?
	DWORD u42;
	BYTE u46[4];
	WORD u4a;
	DWORD u4c;
};

class CGameObject {
//Size: 0x42
//Constructor: 0x573470
//vtable: 0xAA6844
public:
	virtual ~CGameObject() {} //v0
	virtual void v4() {} //GetType() - return byte 0x4h
	virtual void v8() {} //AddToArea(pArea, POINT, zPos, type)
	virtual void vc() {} //AIUpdate()
	virtual Object& GetObject() { return o; } //return a value
	//v14 (dw 3738h) - get some enum?
	//v18 void GetCurrentPoint(POINT* ptr)
	//v1c POSITION* GetVerticalListPosition(), gets 16h
	//v20 GetVertListType(), returns 1ah
	//v24 bool IsAllowSaving(STRREF), 1 = allow save
	//v28 bool CompressTime(DWORD)
	//v2c void DebugDump()
	//v30 ? involves rectangles
	//v34 ? involves rectangles
	//v38 BOOL InAnArea()
	//v3c ? to do with areas
	//v40 PlaySound? to do with areas
	//v44 void RemoveFromArea()
	//v48 void DrawAnimation(pArea, pCVideoMode, int)
	//v4c bool NeedsAIUpdate(CWorldTimer->bRun, CBaldurChitin->nChitinUpdates)
	//v50 void SetObject(Object*)
	//v54 ?
	//v58 DoNothing
	//v5c void SetVerticalListPosition(POSITION*), sets 16h

	BYTE nType; //4h, CGameObject type
	//objectType, e.g. see contants from AAA9E1-AAA9ED
	//having a 1 means scriptable
	//CVisualEffectVidCell (0h)
	//CGameObject (0h)
	//CGameSprite (1h)
	//CSoundObject (10h) (list 1)
	//CContainerObject (11h) (list 1)
	//CSpawningObject (20h) (list 1)
	//CDoorObject (21h)
	//CStaticObject (30h) (list 1)
	//CCreatureObject (31h) (list 1, if dead?)
	//C5EObject (40h)
	//CTriggerObject (41h) (list 1)
	//CTiledObject (51h) - should be 50h?
	//CSmokeObject (60h)
	//CAreaObject (61h) -0x3D8, AA6B74 (list 1)
	//CBaldurObject (71h) - size: 0x3D8, AA6C28

	BYTE u5; //pad
	POINT m_currentLoc;
	DWORD zPos; //eh
	CArea* pArea; //12h
	POSITION* posVertList; //16h, ref to pos of vertical list with this enum
	BYTE m_vertListType; //1ah, which area vertical this is part of
	BYTE u1b; //pad
	Object o;  //1ch, this o (main Object used in script triggers)
	Enum e; //30h, this e
	WORD u34;
	DWORD nPlayerID; //36h, network
	Enum u3a; //another enum
	BYTE u3e;
	bool bIgnoreMessagesToSelf; //3fh, network
	BYTE u40;
	BYTE u41; //padding?
};

class CGameSprite : public CGameObject {
//Size: 0x3D4
//Constructor: 0x476DED
public:
	virtual ~CGameSprite() {} //v0
	//v60, BOOL EvaluateTrigger(Trigger*)
	//v64, void ClearAllActions(BOOL bExceptFlagged)
	//v68, ? (pCCreatureObject)
	//v6c, void AddActionHead(pAction)
	//v70, void TryApplyEffect(pCEffect, int, int)
	//v74, update for new round? (BOOL) calls v64, v88
	//v78, void ExecuteOneAction(), calls v7c
	//v7c, WORD ExecuteAction()
	//v80, void AddActionTail(Action*)
	//v84, void AIUpdateActions(), called from AIUpdate
	//v88, void SetCurrentAction(pAction), calls vb0
	//v8c
	//v90 ?
	//v94 ?
	//v98 ?
	//v9c ?
	//va0 ?
	//va4, void ExecuteTriggers()
		
	//va8, void SetAutoPauseInfo(DWORD type)
	/* type
	0x1 WEAPON_UNUSABLE
	0x2 ATTACKED
	0x4 HIT
	0x8 BADLY_WOUNDED
	0x10 UNKNOWN_TRIGGER
	0x20 TARGET_GONE
	0x40 ROUND_END
	0x80 ENEMY_SIGHTED
	0x100 SCRIPTED
	0x200 SPELL_CAST
	0x400 TRAP_FOUND
	default UNKNOWN_REASON*/

	//vac
	//vb0
	//...
	//etc. to v114

	Object oAttacker; //42h, for AttackedBy() trigger, for LastAttackerOf triggerid
		
	DWORD nType; //56h
	//ASTYLE.IDS from AttackedBy()
	//DAMAGES.IDS from HitBy()

	Object oCommander; //5ah, for ReceivedOrder() trigger, for LastCommandedBy triggerid
	Object oProtector; //6eh, for ProtectedBy triggerid
	Object oProtectee; //82h, for ProtectorOf triggerid
	Object oTargetor; //96h, for LastTargetedBy triggerid
	Object oHitter; //aah, for HitBy() trigger, for LastHitter triggerid
	Object oHelpShouter; //beh, for Help() trigger, for LastHelp triggerid
	Object oTriggerer; //d2h, for trigger in SVTRIOBJ.IDS, for LastTrigger triggerid
	Object oSeeer; //e6h, for LastSeenBy triggerid
	Object oTalker; //fah, for Said() trigger, for LastTalkedToBy triggerid
	Object oShouter; //10eh, for Heard() trigger, for LastHeardBy triggerid
	Object oSummoned; //122h, for Summoned() trigger, for LastSummonerOf triggerid
	Object u136;
	Object u14a;
	Object u15e;
	Object u172;
	Object u186;
	Object u19a;
	Object u1ae;
	Object u1c2;
	Object u1d6;
	Object u1ea;
	Object u1fe;
	Object u212;
	Object u226;
	CScript* pOverride; //0x23a
	CScript* u23e;
	CScript* pAreaSpecific; //0x242
	CScript* pClass; //0x246
	CScript* pRace; //0x24a
	CScript* pGeneral; //0x24e
	CScript* pDefault; //0x252
	CPtrListAction actions; //0x256, checked in ActionListEmpty()
	CPtrListTrigger triggers; //0x272
	//Triggers 0x0*** are checked here with == only
	//Triggers 0x4*** are checked more sophisticatedly

	DWORD u28e;
	DWORD u292;
	CPtrList u296; //timers?, AA682C
	WORD nCurrResponseIdx; //2b2h, gets Response.u2
	WORD nCurrScriptBlockIdx; //2b4h, gets Response.u4
	WORD nCurrScriptIdx; //2b6h, gets Response.u6
	BOOL bUseCurrIdx; //2b8h, use above three values?
	WORD u2bc; //assoc actions, an upgoing counter of some kind
	Action aCurrent; //2beh
	DWORD u31c; //used with Delay() trigger
	WORD u320; //random number, 0-15, used with Delay() trigger
	WORD u322;
	char name[32]; //324h, script name/death var
	BOOL u344;
	DWORD u348;
	DWORD u34c;
	DWORD u350; //random number 0-37627
	BYTE u354; //value of 0xa
	BYTE u355; //pad?
	WORD u356; //the return value of ExecuteAction()
	BYTE u358;
	BYTE u359; //pad?
	Enum u35a; //contains enum
	BOOL u35e; //exeucting an action?
	BOOL u362; //has stored triggers?
	BOOL u366;
	CSound u36a;
};

struct CGameObjectEntry { //Size Ch
public:
	BYTE m_bShareCounts[3]; //0h
	BYTE m_bDenyCounts[3]; //3h
	WORD id; //6h, low WORD
	CGameObject* pGameObject; //8h
};

struct CGameObjectArrayHandler { //Size 2Eh
//Constructor: 0x675FB0
	//functions
	BYTE GetGameObjectShare(Enum, BYTE, void*, DWORD);
	BYTE GetGameObject(Enum, BYTE, void*, DWORD);
	BYTE GetGameObjectDeny(Enum, BYTE, void*, DWORD);
	BYTE FreeGameObjectShare(Enum, BYTE, DWORD);
	BYTE FreeGameObjectDeny(Enum, BYTE, DWORD);

	//members
#ifdef _DEBUG
	_CCriticalSection ccs; //0h
#else
	CCriticalSection ccs; //0h
#endif
	CGameObjectEntry* m_pArray; //20h
	WORD nArrayCurrentSize; //24h
	WORD nArrayGrowSize; //26h
	WORD nEntries; //28h, enum1 total, high WORD
	WORD nIdMax; //2ah, enum2 total, low WORD
	WORD nIdxLink; //2ch, nRemoteIdx?
};

struct CGameRemoteObjectArrayHandler { //Size 90h
//Constructor: 0x677B5D
	DWORD* dwArray; //0x0
	WORD dwArraySize; //0x4, numEntries
	WORD u6;
	DWORD u8;
	DWORD uc;
	WORD u10;
	DWORD u12;
	DWORD u16;
	WORD u1a;
	ResRef u1c[6];
	DWORD u4c[6];
	WORD u64[6];
#ifdef _DEBUG
	_CCriticalSection ccs; //70h
#else
	CCriticalSection ccs; //70h
#endif
};

extern BYTE (CGameObjectArrayHandler::*CGameObjectArrayHandler_GetGameObjectShare)(Enum, BYTE, void*, DWORD);
extern BYTE (CGameObjectArrayHandler::*CGameObjectArrayHandler_GetGameObject)(Enum, BYTE, void*, DWORD);
extern BYTE (CGameObjectArrayHandler::*CGameObjectArrayHandler_GetGameObjectDeny)(Enum, BYTE, void*, DWORD);
extern BYTE (CGameObjectArrayHandler::*CGameObjectArrayHandler_FreeGameObjectShare)(Enum, BYTE, DWORD);
extern BYTE (CGameObjectArrayHandler::*CGameObjectArrayHandler_FreeGameObjectShare)(Enum, BYTE, DWORD);

#endif //OBJCORE_H