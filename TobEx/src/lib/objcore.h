#ifndef OBJCORE_H
#define OBJCORE_H

#include "stdafx.h"
#include "scrcore.h"
#include "arecore.h"
#include "sndcore.h"
#include "objstats.h"

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
#define CGAMEOBJECT_TYPE_PROJECTILE	0x50
#define CGAMEOBJECT_TYPE_TILE		0x51
#define CGAMEOBJECT_TYPE_SMOKE		0x60
#define CGAMEOBJECT_TYPE_AREA		0x61
#define CGAMEOBJECT_TYPE_BALDUR		0x71

//CGameObjectArrayHandler thread indices
const char THREAD_ASYNCH	= 0;
const char THREAD_1			= 1;
const char THREAD_2			= 2;

//CGameObjectArrayHandler return values (0xAAD1C4)
const char OBJECT_SUCCESS		= 0;
const char OBJECT_LOCK_FAILED	= 1;
const char OBJECT_DELETED		= 2; //Index.id does not match Enum.id
const char OBJECT_BAD_ENUM		= 3;
const char OBJECT_SHARING		= 4;
const char OBJECT_DENYING		= 5;

class _8DF1F2 { //Size 50h
//Related to current area sprite is in
//Constructor: 0x008DF1F2, also 0x008DF105
public:
	IECString u0;
	short u4[2];
	long u8[2];
	char u10;
	char u11; //padding?
	short u12;
	POINT u14; //current position?
	short u1c;
	int u1e;
	short u22[8];
	int u32;
	char u36[5];
	char u3b; //padding?
	IECString u3c; //current area name?
	char u40;
	char u41; //padding?
	int u42;
	char u46[4];
	short u4a;
	int u4c;
};

struct CEventMessage { //Size 1Ah
	short wEventId;
	int nParam1;
	int nParam2;
	int nParam3;
	STRREF strrefParam4;
	BOOL bParam5;
	IECString sParam6;
};

class CEventMessageList : public IECPtrList { //Size 1Ch
//Constructor: 0x55E590
public:
	//AA9D28
};

class CGameObject { //Size 42h
//Constructor: 0x573470
public:
	//AA6844
	virtual ~CGameObject() {} //v0
	virtual char GetType() { return 0; } //v4
	virtual void v8() {} //AddToArea(pArea, POINT, zPos, type)
	virtual void vc() {} //AIUpdate()
	virtual Object& GetCurrentObject() { return o; } //return a value
	virtual void v14() {} //v14 (dw 3738h) - get some enum?
	virtual void v18() {} //v18 void GetCurrentPoint(POINT* ptr)
	virtual void v1c() {} //v1c POSITION& GetVerticalListPosition(), gets 16h
	virtual void v20() {} //v20 char GetVertListType(), returns 1ah
	virtual void v24() {} //v24 bool IsAllowSaving(STRREF), 1 = allow save
	virtual void v28() {} //v28 bool CompressTime(int)
	virtual void v2c() {} //v2c void DebugDump()
	virtual void v30() {} //v30 ? involves rectangles
	virtual void v34() {} //v34 ? involves rectangles
	virtual void v38() {} //v38 BOOL InAnArea()
	virtual void v3c() {} //v3c ? to do with areas
	virtual void v40() {} //v40 PlaySound? to do with areas
	virtual void RemoveFromArea() {} //v44
	virtual void v48() {} //v48 void DrawAnimation(pArea, pCVideoMode, int)
	virtual void v4c() {} //v4c bool NeedsAIUpdate(CWorldTimer->bRun, CBaldurChitin->nChitinUpdates)
	virtual void v50() {} //v50 void SetObject(Object*)
	virtual void v54() {} //v54 ?
	virtual void v58() {} //v58 DoNothing
	virtual void v5c() {} //v5c void SetVerticalListPosition(POSITION*), sets 16h

	char nObjType; //4h, CGameObject type
	//objectType, e.g. see constants from AAA9E1-AAA9ED
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

	char u5; //pad
	POINT m_currentLoc;
	int zPos; //eh
	CArea* pArea; //12h
	POSITION* posVertList; //16h, ref to pos of vertical list with this enum
	char m_vertListType; //1ah, which area vertical this is part of
	char u1b; //pad
	Object o;  //1ch, this o (main Object used in script triggers)
	Enum e; //30h, this e
	short u34;
	int nPlayerNetworkId; //36h, remotePlayerID
	Enum u3a; //another enum
	char u3e;
	bool bIgnoreMessagesToSelf; //3fh, network
	char u40;
	char u41; //padding?
};

class CGameSprite : public CGameObject { //Size 3D4h
//Constructor: 0x476DED
public:
	virtual ~CGameSprite() {} //v0
	virtual BOOL EvaluateTrigger(Trigger& t) { return TRUE; } //v60
	virtual void v64() {} //v64, void ClearAllActions(BOOL bExceptFlagged)
	virtual void v68() {} //v68, void SetTarget(creTarget)
	virtual void v6c() {} //v6c, void AddActionHead(pAction)
	virtual void ApplyEffect(CEffect& eff, bool bCheckEffectListType, BOOL bDelayFinished, BOOL bUpdateCre) {} //v70
	//v74, update for new round? (BOOL) calls v64, v88
	//v78, void ExecuteOneAction(), calls v7c
	//v7c, short ExecuteAction()
	//v80, void AddActionTail(Action*)
	//v84, void AIUpdateActions(), called from AIUpdate
	//v88, void SetCurrentAction(pAction), calls vb0
	//v8c
	//v90, int GetSightRadius(), returned in pixels
	//v94, TerrainTable& GetTerrainTable()
	//v98 ?
	//v9c ?
	//va0 ?
	//va4, void ExecuteTriggers()
		
	//va8, void SetAutoPauseInfo(int type)
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

	//vac, BOOL GetSeeInvisible(), returns TRUE if cdsCurrent->seeInivisible is set, or game is in CutSceneMode
	//vb0
	//vc0 void RefreshObjects()
	//...
	//etc. to v114

	Object oAttacker; //42h, for AttackedBy() trigger, for LastAttackerOf triggerid
		
	int nAttackedType; //56h
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
	CScript* pOverride; //23ah
	CScript* u23e;
	CScript* pAreaSpecific; //242h
	CScript* pClass; //246h
	CScript* pRace; //24ah
	CScript* pGeneral; //24eh
	CScript* pDefault; //252h
	CActionList actions; //256h, checked in ActionListEmpty()
	CTriggerList triggers; //272h
	//Triggers 0x0*** are checked here with == only
	//Triggers 0x4*** are checked more sophisticatedly

	int u28e;
	int u292;
	IECPtrList u296; //timers?, AA682C
	short nCurrResponseIdx; //2b2h, gets Response.u2
	short nCurrScriptBlockIdx; //2b4h, gets Response.u4
	short nCurrScriptIdx; //2b6h, gets Response.u6
	BOOL bUseCurrIdx; //2b8h, use above three values?
	short wActionTicksElapsed; //2ch, how many updates has the current action been running for
	Action aCurrent; //2beh
	int u31c; //used with Delay() trigger
	short u320; //random number, 0-15, used with Delay() trigger
	short u322;
	char name[32]; //324h, script name/death var
	BOOL u344;
	int u348;
	int u34c;
	int u350; //random number 0-37627
	char u354; //value of 0xa
	char u355; //pad?
	short u356; //the return value of ExecuteAction()
	char u358;
	char u359; //pad?
	Enum u35a; //contains enum
	BOOL u35e; //exeucting an action?
	BOOL u362; //has stored triggers?
	BOOL u366;
	CSound u36a;
};

struct CGameObjectEntry { //Size Ch
public:
	char m_bShareCounts[3]; //0h
	char m_bDenyCounts[3]; //3h
	short id; //6h, low short
	CGameObject* pGameObject; //8h
};

struct CGameObjectArrayHandler { //Size 2Eh
//Constructor: 0x675FB0
	char GetGameObjectShare(Enum e, char threadNum, void* pptr, int dwTimeout);
	char GetGameObject(Enum e, char threadNum, void* pptr, int dwTimeout);
	char GetGameObjectDeny(Enum e, char threadNum, void* pptr, int dwTimeout);
	char FreeGameObjectShare(Enum e, char threadNum, int dwTimeout);
	char FreeGameObjectDeny(Enum e, char threadNum, int dwTimeout);

#ifdef _DEBUG
	_CCriticalSection ccs; //0h
#else
	CCriticalSection ccs; //0h
#endif
	CGameObjectEntry* m_pArray; //20h
	short nArrayCurrentSize; //24h
	short nArrayGrowSize; //26h
	short nEntries; //28h, enum1 total, high short
	short nIdMax; //2ah, enum2 total, low short
	short nIdxLink; //2ch, nRemoteIdx?
};

struct CGameRemoteObjectArrayHandler { //Size 90h
//Constructor: 0x677B5D
	int* dwArray; //0h
	short dwArraySize; //4h, numEntries
	short u6;
	int u8;
	int uc;
	short u10;
	int u12;
	int u16;
	short u1a;
	ResRef u1c[6];
	int u4c[6];
	short u64[6];
#ifdef _DEBUG
	_CCriticalSection ccs; //70h
#else
	CCriticalSection ccs; //70h
#endif
};

extern char (CGameObjectArrayHandler::*CGameObjectArrayHandler_GetGameObjectShare)(Enum, char, void*, int);
extern char (CGameObjectArrayHandler::*CGameObjectArrayHandler_GetGameObject)(Enum, char, void*, int);
extern char (CGameObjectArrayHandler::*CGameObjectArrayHandler_GetGameObjectDeny)(Enum, char, void*, int);
extern char (CGameObjectArrayHandler::*CGameObjectArrayHandler_FreeGameObjectShare)(Enum, char, int);
extern char (CGameObjectArrayHandler::*CGameObjectArrayHandler_FreeGameObjectShare)(Enum, char, int);

#endif //OBJCORE_H