//TobExEE
#ifndef OBJCORE_H
#define OBJCORE_H

#include "stdafx.h"
#include "scrcore.h"
#include "arecore.h"
#include "sndcore.h"
#include "objstats.h"

//CGameObject types
#define CGAMEOBJECT_TYPE_OBJECT			0x00
#define CGAMEOBJECT_TYPE_SPRITE			0x01
#define CGAMEOBJECT_TYPE_SOUND			0x10
#define CGAMEOBJECT_TYPE_CONTAINER		0x11
#define CGAMEOBJECT_TYPE_SPAWNING		0x20
#define CGAMEOBJECT_TYPE_DOOR			0x21
#define CGAMEOBJECT_TYPE_STATIC			0x30
#define CGAMEOBJECT_TYPE_CREATURE		0x31
#define CGAMEOBJECT_TYPE_OBJECTMARKER	0x40
#define CGAMEOBJECT_TYPE_TRIGGER		0x41
#define CGAMEOBJECT_TYPE_PROJECTILE		0x50
#define CGAMEOBJECT_TYPE_TILE			0x51
#define CGAMEOBJECT_TYPE_SMOKE			0x60
#define CGAMEOBJECT_TYPE_AREA			0x61
#define CGAMEOBJECT_TYPE_BALDUR			0x71

//CGameObjectArray thread indices
const char THREAD_ASYNCH	= 0;
const char THREAD_1			= 1;
const char THREAD_2			= 2;

//CGameObjectArray return values (0xAAD1C4)
const char OBJECT_SUCCESS		= 0;
const char OBJECT_DELETED		= 2; //Index.id does not match ENUM.id
const char OBJECT_BAD_ENUM		= 3;

typedef IECPtrList CTimerList; //AA682C

struct CTimeElement { //Size 6h, FIX_ME
//For CTimerList
	int m_nTime; //0h
	char m_nId; //4h
	char p5;

};

struct CFeedback { //Size 1Ah, FIX_ME
	short m_wEventId;
	int m_nParam1;
	int m_nParam2;
	int m_nParam3;
	STRREF m_strrefParam4;
	BOOL m_bParam5;
	IECString m_sParam6;
};

class CFeedbackList : public IECPtrList { //Size 1Ch
public:
};

class CGameObject { //Size 48h
public:
	virtual ~CGameObject() {} //v0
	virtual char GetType() { return m_cType; } //v4
	virtual void AddToArea(CArea& area, CPoint& pt, int zPos, char cVertListType) {} //v8
	virtual void AIUpdate() {} //vc
	virtual Object& GetObject() { return m_o; } //return a value
	virtual void v14() {} //v14 - get some enum?
	virtual void GetPosition(CPoint& pt) {} //v18
	virtual POSITION& GetVerticalListPosition() { return *(POSITION*)0; } //v1c
	virtual char GetVertListType() { return 0; } //v20
	virtual void v24() {} //v24 bool IsAllowSaving(STRREF), 1 = allow save
	virtual void v28() {} //v28 bool CompressTime(int)
	virtual void v2c() {} //v2c void DebugDump()
	virtual BOOL IsPointWithinMe(CPoint pt) { return FALSE; } //v30
	virtual void v34() {} //v34 ? involves rectangles
	virtual void v38() {} //v38 BOOL InAnArea()
	virtual void v3c() {} //v3c ? to do with modal states
	virtual void v40() {} //v40 PlaySound? to do with modal states
	virtual void RemoveFromArea() {} //v44
	virtual void v48() {} //v48 void DrawAnimation(pArea, pCVideoMode, int)
	virtual bool NeedsAIUpdate(bool bRun, int nChitinUpdates) { return false; } //v4c
	virtual void v50() {} //v50 void SetObject(Object*)
	virtual void v54() {} //v54 ?
	virtual void v58() {} //v58 DoNothing
	virtual void v5c() {} //v5c void SetVerticalListPosition(POSITION*), sets 16h
	virtual void v60() {} //v60

	char m_cType; //4h, CGameObject type
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

	char p5[3];
	CPoint m_ptCurrent; //8h
	int m_zPos; //10h
	CArea* m_pArea; //14h
	POSITION* m_posVertList; //18h, ref to pos of vertical list with this enum
	char m_vertListType; //1ch, which area vertical this is part of
	char p1d[3];
	Object m_o; //20h, this o (main Object used in script triggers)
	ENUM m_e; //34h, this id
	short u38; // = 7 * 4 + 4
	char p3a[2];
	int m_nPlayerNetworkId; //3ch, remotePlayerID
	ENUM u40;
	
	//which modulus of the tick depends on m_nAIUpdateInterval & e == m_nAIUpdateInterval & nChitinUpdates
	//0: every tick
	//1: every 2nd tick (default)
	//3: every 4th tick
	char m_nAIUpdateInterval; //44h

	bool m_bIgnoreMessagesToSelf; //45h, network
	char u46; // increment modulo of 3 (range: 0-2), set to 1 when there are no triggers
	char p47;
};

class CGameSprite : public CGameObject { //Size 390h
public:
	virtual ~CGameSprite() {} //v0

	virtual BOOL EvaluateTrigger(Trigger& t); //v64
	virtual void ClearAllActions(BOOL bSkipFlagged); //v68
	virtual void v6c() {} //v6c, void SetTarget(creTarget)
	virtual void AddActionHead(Action& a) {} //v70
	virtual void ApplyEffect(CEffect& eff, bool bCheckEffectListType, BOOL bDelayFinished, BOOL bUpdateCre) {} //v74
	virtual void v78() {} //v78, update for new round? (BOOL) calls v64, v88
	virtual void ExecuteOneAction() {}//v7c, calls v80
	virtual ACTIONRESULT ExecuteAction(); //v80
	virtual void AddActionTail(Action& a) {} //v84
	virtual void AIUpdateActions() {} //v88, called from AIUpdate
	virtual void SetCurrentAction(Action& a); //v8c, calls vb4
	virtual void SetScript(int nScriptIdx, CScript& script) {} //v90
	virtual int GetSightRadius() { return 0; } //v94, returned in pixels
	virtual void GetTerrainTable2() {} //v98, TerrainTable& GetTerrainTable2()
	virtual void GetTerrainTable() {} //v9c, TerrainTable& GetTerrainTable()
	virtual int FindTargetCreature(Trigger& t, CCreatureObject** ppCre) { return 0; } //va0
	virtual int GetVisualRange() { return 0; } //va4, m_SightRadius x 48
	virtual void ExecuteTriggers() {} //va8
	virtual void SetAutoPauseInfo(int type) {} //vac

	//SetAutoPauseInfo(int type)
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

	virtual BOOL GetSeeInvisible() { return TRUE; } //vb0, returns TRUE if cdsCurrent->seeInivisible is set, or game is in CutSceneMode
	virtual void DoPostAction(Action& a) {} //vb4, for every ACTIONRESULT except no action taken
	virtual void vb8() {} //vb8

	Object m_oAttacker; //48h, for AttackedBy() trigger, for LastAttackerOf triggerid
		
	int m_nAttackedType; //5ch
	//ASTYLE.IDS from AttackedBy()
	//DAMAGES.IDS from HitBy()

	Object m_oCommander; //60h, for ReceivedOrder() trigger, for LastCommandedBy triggerid
	Object m_oProtector; //74h, for ProtectedBy triggerid
	Object m_oProtectee; //88h, for ProtectorOf triggerid
	Object m_oTargetor; //9ch, for LastTargetedBy triggerid
	Object m_oHitter; //b0h, for HitBy() trigger, for LastHitter triggerid
	Object m_oHelpShouter; //c4h, for Help() trigger, for LastHelp triggerid
	Object m_oTriggerer; //d8h, for trigger in SVTRIOBJ.IDS, for LastTrigger triggerid
	Object m_oSeeer; //ech, for LastSeenBy triggerid
	Object m_oTalker; //100h, for Said() trigger, for LastTalkedToBy triggerid
	Object m_oShouter; //114h, for Heard() trigger, for LastHeardBy triggerid
	Object m_oSummoned; //128h, for Summoned() trigger, for LastSummonerOf triggerid
	Object u13c;
	Object u150;
	Object u164;
	Object u178;
	Object u18c;
	Object u1a0;
	Object u1b4;
	Object u1c8;
	Object u1dc;
	Object u1f0;
	Object u204;
	Object u218;
	Object u22c;
	CScript* m_pScriptOverride; //240h
	CScript* m_pScript1; //244h
	CScript* m_pScriptAreaSpecific; //248h
	CScript* m_pScriptClass; //24ch
	CScript* m_pScriptRace; //250h
	CScript* m_pScriptGeneral; //254h
	CScript* m_pScriptDefault; //258h
	CActionList m_actions; //25ch, checked in ActionListEmpty()
	CTriggerList m_triggers; //278h
	//Triggers 0x0*** are checked here with == only
	//Triggers 0x4*** are checked more sophisticatedly

	int m_nTimeFree; //294h, countup, time free (i.e. not mazed/imprisoned)
	int u298; //countup timer
	CTimerList m_timers; //29ch
	short m_nCurrResponseIdx; //2b8h, gets Response.u2
	short m_nCurrScriptBlockIdx; //2bah, gets Response.u4
	short m_nCurrScriptIdx; //2bch, gets Response.u6
	char p2be[2];
	BOOL m_bUseCurrScriptIdx; //2c0h, use above three values?
	short m_wActionTicksElapsed; //2c4h, how many updates has the current action been running for
	char p2c6[2];
	Action m_aCurrent; //2c8h
	int u328; //used with Delay() trigger
	short u32c; //random number, 0-15, used with Delay() trigger
	short u32e;
	SCRIPTNAME m_szScriptName; //330h, script name/death var
	BOOL u350; //bEmptyActionList?
	int u354;
	int u358;
	int u35c; //random number 0-37627
	char m_nReactionBase; //360h
	char p361;
	ACTIONRESULT arCurrent; //362h, the return value of ExecuteAction()
	char p364[2];
	char u366;
	char p367;
	ENUM m_eGameTextOverHead; //368h
	BOOL m_bExecutingAction; //36ch, set during the ExecuteAction() function
	BOOL u370; //has stored triggers?
	BOOL m_bInterruptState; //374h, SetInterrupt() for sprite
	CSoundWrapper u378;
};

struct CGameObjectEntry { //Size 8h
public:
	short m_id; //0h, low short (in ENUM, high WORD = array index, low WORD = id)
	CGameObject* m_pGameObject; //8h
};

struct CGameObjectArray { //Size 4h, in BG:EE the object array is global
	char GetObject(ENUM e, void* ppObject);

	CGameObjectEntry* m_pArray; //0h
};

struct CGameRemoteObjectArray { //Size 74h
	int* m_dwArray; //0h
	short m_dwArraySize; //4h, numEntries
	short u6;
	int u8;
	int uc;
	short u10;
	char p12[2];
	int u14;
	int u18;
	short u1c;
	ResRef u1e[6];
	int u4e[6];
	short u66[6];
	char p72[2];
};

#endif //OBJCORE_H