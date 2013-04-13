//TobExEE
#ifndef SCRCORE_H
#define SCRCORE_H

#include "p_scrcore.h"

#include "stdafx.h"
#include "rescore.h"

class CGameObject;
class CGameSprite;
class CCreatureObject;
struct Action;

typedef short ACTIONRESULT;
typedef IECPtrList CActionList;
typedef IECPtrList CTriggerList;
typedef IECPtrList CScriptBlockList;

//FIX_ME
//static Action* g_pActionTemp = reinterpret_cast<Action*>(0xB79300);

//ACTIONRESULT
const ACTIONRESULT ACTIONRESULT_NEG3			= -3; //?, loads next action
const ACTIONRESULT ACTIONRESULT_ERROR			= -2; //failed, loads next action
const ACTIONRESULT ACTIONRESULT_DONE			= -1; //default, resets the script indices, loads next action, ignore post-action stuff
const ACTIONRESULT ACTIONRESULT_CONTINUE		= 0; //continue current action, increment action ticks elapsed, terminates instant action loop, halts script processing
const ACTIONRESULT ACTIONRESULT_SUCCESS			= 1; //stop walking, loads next action, increment action ticks elapsed, terminates instant action loop
const ACTIONRESULT ACTIONRESULT_2				= 2; //2, adds to action ticks elapsed

struct IdsEntry;

struct ResIdsFile { //Size 10h
	BOOL m_bLoaded; //0h
	ResTxt* m_pRes; //4h
	ResRef m_rName; //8h
};

class Identifiers { //Size 40h
	DEFINE_MEMALLOC_FUNC;

	Identifiers();
	Identifiers& Construct() {return *this;} //dummy

	Identifiers(ResRef rFile);
	Identifiers& Construct(ResRef rFile) {return *this;} //dummy

	virtual ~Identifiers();
	void Deconstruct() {} //dummy

	IdsEntry* FindByHead(IECString sValue, BOOL bCaseSensitive);

	ResIdsFile m_ids; //4h
	IECString u14; //14h
	IECPtrList m_entries; //18h, IdsEntry objects
	BOOL m_bUseArray; //34h
	int* m_pDataArray; //38h, ptr to array of pIdsEntry
	int m_nArraySize; //3ch
};

struct CVariable { //Size 54h
	SCRIPTNAME m_szName; //0h
	WORD m_wType; //20h, unused
	WORD m_wResRefType; //22h, unused
	DWORD m_dwValue; //24h, dmPt.Y
	LONG m_nValue; //28h, dmPt.X
	double m_dFloatValue; //2ch, unused
	SCRIPTNAME m_szStringValue; //34h, e.g. szDMArea, for Store Local Variable, = res1 + res2 + res3 (associated with deathmatch?)
};

struct CVariableMap { //Size 8h
	CVariable* m_pArray; //0h
	unsigned int m_nArraySize; //4h
};

struct ObjectIds { //Size 5h, FIX_ME
	ObjectIds();

	unsigned char operator[](unsigned int n);

	//OBJECT.IDS indices
	unsigned char m_id1;
	unsigned char m_id2;
	unsigned char m_id3;
	unsigned char m_id4;
	unsigned char m_id5;
};

struct Object { //Size 14h
	DEFINE_MEMALLOC_FUNC;

	//BCS correlation: OB ea, general, race, class, specific, gender, alignment, id1, id2, id3, id4, id5, name OB
	Object();

	~Object();
	void Deconstruct() {} //dummy

	Object(Object& o);
	Object& Construct(Object& o) {return *this;} //dummy

	Object(unsigned char cEnemyAlly, unsigned char cGeneral, unsigned char cRace, unsigned char cClass, unsigned char cSpecific, unsigned char cGender, unsigned char cAlignment, ENUM eTarget, ObjectIds* poids, IECString& sName);
	Object& Construct(unsigned char cEnemyAlly, unsigned char cGeneral, unsigned char cRace, unsigned char cClass, unsigned char cSpecific, unsigned char cGender, unsigned char cAlignment, ENUM eTarget, ObjectIds* poids, IECString& sName) {return *this;} //dummy

	Object(unsigned char cEnemyAlly, unsigned char cGeneral, unsigned char cRace, unsigned char cClass, unsigned char Specific, unsigned char cGender, unsigned char cAlignment, ENUM eTarget);
	Object& Construct(unsigned char cEnemyAlly, unsigned char cGeneral, unsigned char cRace, unsigned char cClass, unsigned char Specific, unsigned char cGender, unsigned char cAlignment, ENUM eTarget) {return *this;} //dummy

	bool MatchCriteria(Object& oCriteria, BOOL bAnyIncludesNonScript, BOOL bExcludeNonScript, BOOL bEAGroupMatch);

	void operator=(Object& o);
	void OpAssign(Object&) {} //dummy

	void DecodeIdentifiers(CGameSprite& spriteSource);
	CGameObject& FindTargetOfType(CGameObject& source, char type, BOOL bCheckMiddleList);
	CGameObject& FindTarget(CGameObject& source, BOOL bCheckMiddleList);
	void SetIdentifiers(ObjectIds& ids);
	Object GetOpposingEAObject();
	void GetDualClasses(unsigned char* pClassNew, unsigned char* pClassOrg);
	BOOL IsEqualIncludeEnum(Object& o);

	IECString m_sName; //0h
	unsigned char m_cEnemyAlly; //4h
	unsigned char m_cGeneral; //5h
	unsigned char m_cRace; //6h
	unsigned char m_cClass; //7h
	ENUM m_eTarget; //8h, set and used after evaluation of Ids
	ObjectIds m_oids; //ch
	unsigned char m_cSpecific; //11h, for GroupOfType
	unsigned char m_cGender; //12h
	unsigned char m_cAlignment; //13h
};

Object* const g_poAny = reinterpret_cast<Object* const>(G_OBJECT_ANY); //in CCreatureObject constructor
Object* const g_poAnything = reinterpret_cast<Object* const>(G_OBJECT_ANYTHING); //unused
Object* const g_poNothing = reinterpret_cast<Object* const>(G_OBJECT_NOTHING); //in CGameSprite constructor
Object* const g_poNonScript = reinterpret_cast<Object* const>(G_OBJECT_NONSCRIPT); //in CGameObject constructor
Object* const g_poMyself = reinterpret_cast<Object* const>(G_OBJECT_MYSELF); //unused, uses Construct10

struct Trigger { //Size 30h
	DEFINE_MEMALLOC_FUNC;

	//BCS correlation: TR opcode, i, dwFlags, i2, u22, sName1, sName2, o TR
	Trigger();

	Trigger(short wOpcode, Object& o, int i);
	Trigger& Construct(short wOpcode, Object& o, int i) {return *this;} //dummy

	Trigger(short wOpcode, int i);
	Trigger& Construct(short wOpcode, int i) {return *this;} //dummy

	Trigger& operator=(Trigger& t);
	Trigger& OpAssign(Trigger& t) {return *this;} //dummy

	void DecodeIdentifiers(CGameSprite& sprite);

	short m_wOpcode; //0h
	char p2[2];
	int m_i; //4h, gets Arg1 (I)
	Object m_o; //8h (O)
	unsigned int m_dwFlags; //1ch
	//bit0: NOT[!]
	//bit1: TRIGGER_EXECUTED (added internally on purge)
	//bit2: TRIGGER_UPDATED_SPRITE (added internally on add or purge)

	int m_i2; //20h (I2)
	int m_i3; //24h (unknown usage, I3?)
	IECString m_s1; //28h, (S), first global, the global name is appended to the global type e.g. "LOCALSDead", "GLOBALTest"
	IECString m_s2; //2ch, (S), (unknown usage, second global)
};

struct Action { //Size 60h
	DEFINE_MEMALLOC_FUNC;

	//BCS correlation: AC opcode, oOverride, oObject, oTarget, i, pt.x, pt.y, i2, i3, sName1, sName2 AC
	Action();
	Action& Construct() {return *this;} //dummy

	~Action();
	void Deconstruct() {} //dummy

	void operator=(Action& a);
	void OpAssign(Action& a) {} //dummy

	short m_wOpcode; //0h (A)
	char p2[2];
	Object m_oOverride; //4h (O)
	Object m_oObject; //18h (O)
	Object m_oTarget; //2ch (O)
	int m_i; //40h (I)
	int m_i2; //44h (I)
	int m_i3; //48h (I)
	IECString m_s1; //4ch (S)
	IECString m_s2; //50h (S)
	CPoint m_pt; //54h (P)
	unsigned int m_dwFlags; //5ch, bit0 = do not purge on clear all actions
};

struct Response { //Size 24h
	Response();
	Response& Construct() {return *this;} //dummy

	~Response();
	void Deconstruct() {} //dummy

	void operator=(Response& r);
	void OpAssign(Response& r) {} //dummy

	short m_wProbability; //0h
	short m_wResponseIdx; //2h, if chosen, gets response block # in the response list
	short m_wScriptBlockIdx; //4h, if chosen, gets script block # in the script
	short m_wScriptIdx; //6h, if chosen, gets script # in the script group (i.e. Override, Race, General, etc.), however this is always 0
	CActionList m_lActions; //8h
};

class CResponseList : public IECPtrList { //Size 20h, FIX_ME
public:
	//IECPtrList m_Responses; //0h
	int m_nTotalProbability; //1ch
};

struct CScriptBlock { //Size 3Ch, FIX_ME
	BOOL Evaluate(CTriggerList& triggers, CGameSprite& sprite);
	BOOL EvaluateTrigger(Trigger& t, CTriggerList& triggers, CGameSprite& sprite);

	CTriggerList m_lTriggers; //0h
	CResponseList m_lResponses; //1ch
};

struct CScript { //Size 28h
	ResRef m_rName; //0h
	int u8;
	CScriptBlockList m_lBlocks; //ch
};

struct CScriptParser { //Size F0h
	short GetTriggerOpcode(IECString sName);
	int GetOpcode(IECString sValue, IECString sIdsName);
	void SetError(IECString s);
	Object ParseObject(IECString& sArg);
	IECString SpanBefore(IECString s, char c);
	IECString SpanAfter(IECString s, char c);
	IECString GetArgText(int nArgIdx, IECString sFuncDesc);
	IECString GetIdsValue(Identifiers& ids, IECString& sName);
	IECString GetArgTextIdsName(IECString sArgText);

	short m_wMode; //0h, 0 = outside IF...END, 1 = in Trigger, 2 = in Action
	char p2[2];
	int m_nLineNumber; //4h
	CScript* u8;
	IECPtrList* uc; //contains CPtrListAction objects
	CTriggerList* u10;
	Response* m_pResponse; //14h, response to use after parsing
	IECString m_sError; //18h;
	CFile u1c;
	IECString u2c;
	Identifiers ACTION; //30h
	Identifiers TRIGGER; //70h
	Identifiers OBJECT; //b0h
};

#endif //SCRCORE_H