#ifndef SCRCORE_H
#define SCRCORE_H

#include "utils.h"
#include "rescore.h"
#include "resref.h"
#include "cstringex.h"

typedef CPtrList CPtrListAction; //AA5C5C
typedef CPtrList CPtrListTrigger; //AA5E28
typedef CPtrList CScriptBlockList; //AA5E50

struct ResIdsContainer { //Size 10h
	BOOL bLoaded; //0h
	ResTxt* pRes; //4h
	ResRef name; //8h
};

class Identifiers { //Size 40h
//Constructor: 0x40FB70
public:
	DWORD* vtable; //0h
	ResIdsContainer m_ids; //4h
	IECString u14; //14h
	CPtrList entries; //18h, contain IdsEntry objects
	BOOL bUseArray; //34h
	DWORD* pDataArray; //38h, ptr to array of pIdsEntry
	DWORD nArraySize; //3ch
};

struct CVariable {
//Size: 0x54
	char name[32]; //0h
	WORD u20;
	WORD u22;
	DWORD u24;
	DWORD value; //28h
	QWORD u2c;
	char u34[32];
};

struct CVariableArray {
//Size: 0x8
	CVariable* pArray;
	DWORD nArraySize;
};

struct Object { //Size 14h
//Constructor: 0x410CEE
	//BCS correlation: OB ea, general, race, class, specific, gender, alignment, id1, id2, id3, id4, id5, name OB

	//functions
	BYTE GetClass();

	//members
	IECString Name; //0h
	BYTE EnemyAlly; //4h
	BYTE General; //5h
	BYTE Race; //6h
	BYTE Class; //7h
	Enum eOwner; //8h, if this is set, evaluation of Ids and name is skipped
		
	//OBJECT.IDS indices
	BYTE Id1; //ch
	BYTE Id2; //dh
	BYTE Id3; //eh
	BYTE Id4; //fh
	BYTE Id5; //10h

	BYTE Specific; //11h, for GroupOfType
	BYTE Gender; //12h
	BYTE Alignment; //13h
};

extern BYTE (Object::*Object_GetClass)();

struct Trigger {
	//Size: 0x2E
	//Constructor: 430720h (3 args), 430180h (2 args)
	//Note: trigger opcodes (WORD) from AA5E68-AA5F66
	//BCS correlation: TR opcode, i, dwFlags, i2, u22, sName1, sName2, o TR

	WORD opcode; //0h
	DWORD i; //2h, gets Arg1 (I)
	Object o; //6h (O)
	DWORD dwFlags; //1ah
	//bit0: NOT[!]
	//bit1: trigger has been executed on CCreatureObject (added internally)
	//bit2: checked with ? CDerivedStats.u640 involved? (added internally)

	DWORD i2; //1eh (I)
	DWORD u22; //22h (unknown usage)
	IECString sName1; //26h, (S), first global, the global name is appended to the global type e.g. "LOCALSDead", "GLOBALTest"
	IECString sName2; //2ah, (S), second global
};

struct Action { //Size 5Eh
//Constructor: 0x405820
//Note: action opcodes (WORD) from AA5980-AA5B32
//BCS correlation: AC opcode, oOverride, oObject, oTarget, i, pt.x, pt.y, i2, i3, sName1, sName2 AC
public:
	Action();
	Action* Construct(void) {return this;} //dummy

	~Action();
	void Deconstruct(void) {} //dummy

	WORD opcode; //0h (A)
	Object oOverride; //2h (O)
	Object oObject; //16h (O)
	Object oTarget; //2ah (O)
	DWORD i; //3eh (I)
	DWORD i2; //42h (I)
	DWORD i3; //46h (I)
	IECString sName1; //4ah (S)
	IECString sName2; //4eh (S)
	POINT pt; //52h (P)
	DWORD dwFlags; //5ah, bit0 = do not purge on clear all actions
};

extern Action* (Action::*Action_Construct_0)(void);
extern void (Action::*Action_Deconstruct)(void);

struct Response {
//Size: 0x24
//Constructor: 0x416130
	WORD probability; //0h
	WORD nResponseIdx; //2h, if chosen, gets response block # in the response list
	WORD nScriptBlockIdx; //4h, if chosen, gets script block # in the script
	WORD nScriptIdx; //6h, if chosen, gets script # in the script group (i.e. Override, Race, General, etc.), however this is always 0
	CPtrListAction actions; //8h
};

class CPtrListResponse : protected CPtrList {
//Size: 0x20
//vtable: 0xAA5E10
public:
	virtual void v0() {}

	//CPtrList contains Response objects
	DWORD totalProbability; //1ch
};

struct CScriptBlock {
//Size: 0x3c
//Constructor: see 0x41829F
	CPtrListTrigger triggers; //0h
	CPtrListResponse responses; //1ch
};

struct CScript {
//Size: 0x28
	ResRef name; //0h
	DWORD u8;
	CScriptBlockList blocks; //ch
};

struct CScriptParser {
//Size: 0xee
//Constructor: 0x41926B
	WORD mode; //0h, 0 = outside IF...END, 1 = in Trigger, 2 = in Action
	DWORD lineNumber;
	DWORD* u6; //0x28 size, 0x0 ResRef, 0x8 DWORD, 0xc CPtrListAA5E50
	CPtrList* ua; //contains CPtrListAction objects
	CPtrListTrigger* ue;
	CPtrListAction* u12;
	IECString error;
	CFile u1a;
	IECString u2a;
	Identifiers ACTION; //2eh
	Identifiers TRIGGER; //6eh
	Identifiers OBJECT; //aeh
};

#endif //SCRCORE_H