#include "cptrlistex.h"

#include "utils.h"

extern IECPtrList& (IECPtrList::*IECPtrList_Construct)(int) =
	SetFP(static_cast<IECPtrList& (IECPtrList::*)(int)>					(&IECPtrList::Construct),		0xA4E475);
extern void (IECPtrList::*IECPtrList_RemoveAll)() =
	SetFP(static_cast<void (IECPtrList::*)()>							(&IECPtrList::RemoveAll),		0xA4E4D4);
extern void (IECPtrList::*IECPtrList_Deconstruct)() =
	SetFP(static_cast<void (IECPtrList::*)()>							(&IECPtrList::Deconstruct),		0xA4E4B4);
extern POSITION (IECPtrList::*IECPtrList_AddHead_void)(void*) =
	SetFP(static_cast<POSITION (IECPtrList::*)(void*)>					(&IECPtrList::AddHead),			0xA4E56E);
extern POSITION (IECPtrList::*IECPtrList_AddTail_void)(void*) =
	SetFP(static_cast<POSITION (IECPtrList::*)(void*)>					(&IECPtrList::AddTail),			0xA4E598);
extern void (IECPtrList::*IECPtrList_AddHead_CPtrList)(IECPtrList*) =
	SetFP(static_cast<void (IECPtrList::*)(IECPtrList*)>				(&IECPtrList::AddHead),			0xA4E5C1);
extern void (IECPtrList::*IECPtrList_AddTail_CPtrList)(IECPtrList*) =
	SetFP(static_cast<void (IECPtrList::*)(IECPtrList*)>				(&IECPtrList::AddTail),			0xA4E5E6);
extern void* (IECPtrList::*IECPtrList_RemoveHead)() =
	SetFP(static_cast<void* (IECPtrList::*)()>							(&IECPtrList::RemoveHead),		0xA4E60A);
extern void* (IECPtrList::*IECPtrList_RemoveTail)() =
	SetFP(static_cast<void* (IECPtrList::*)()>							(&IECPtrList::RemoveTail),		0xA4E62E);
extern POSITION (IECPtrList::*IECPtrList_InsertBefore)(POSITION, void*) =
	SetFP(static_cast<POSITION (IECPtrList::*)(POSITION, void*)>		(&IECPtrList::InsertBefore),	0xA4E652);
extern POSITION (IECPtrList::*IECPtrList_InsertAfter)(POSITION, void*) =
	SetFP(static_cast<POSITION (IECPtrList::*)(POSITION, void*)>		(&IECPtrList::InsertAfter),		0xA4E691);
extern void (IECPtrList::*IECPtrList_RemoveAt)(POSITION) =
	SetFP(static_cast<void (IECPtrList::*)(POSITION)>					(&IECPtrList::RemoveAt),		0xA4E6CE);
extern POSITION (IECPtrList::*IECPtrList_FindIndex)(int) const =
	SetFP(static_cast<POSITION (IECPtrList::*)(int) const>				(&IECPtrList::FindIndex),		0xA4E705);
extern POSITION (IECPtrList::*IECPtrList_Find)(void*, POSITION) const =
	SetFP(static_cast<POSITION (IECPtrList::*)(void*, POSITION) const>	(&IECPtrList::Find),			0xA4E72B);

IECPtrList::IECPtrList(int nBlockSize)									{ (this->*IECPtrList_Construct)(nBlockSize); }
void IECPtrList::RemoveAll()											{ return (this->*IECPtrList_RemoveAll)(); }
IECPtrList::~IECPtrList()												{ (this->*IECPtrList_Deconstruct)(); }
POSITION IECPtrList::AddHead(void* newElement)							{ return (this->*IECPtrList_AddHead_void)(newElement); }
POSITION IECPtrList::AddTail(void* newElement)							{ return (this->*IECPtrList_AddTail_void)(newElement); }
void IECPtrList::AddHead(IECPtrList* pNewList)							{ return (this->*IECPtrList_AddHead_CPtrList)(pNewList); }
void IECPtrList::AddTail(IECPtrList* pNewList)							{ return (this->*IECPtrList_AddTail_CPtrList)(pNewList); }
void* IECPtrList::RemoveHead()											{ return (this->*IECPtrList_RemoveHead)(); }
void* IECPtrList::RemoveTail()											{ return (this->*IECPtrList_RemoveTail)(); }
POSITION IECPtrList::InsertBefore(POSITION position, void* newElement)	{ return (this->*IECPtrList_InsertBefore)(position, newElement); }
POSITION IECPtrList::InsertAfter(POSITION position, void* newElement)	{ return (this->*IECPtrList_InsertAfter)(position, newElement); }
void IECPtrList::RemoveAt(POSITION position)							{ return (this->*IECPtrList_RemoveAt)(position); }
POSITION IECPtrList::FindIndex(int nIndex) const						{ return (this->*IECPtrList_FindIndex)(nIndex); }
POSITION IECPtrList::Find(void* searchValue, POSITION startAfter) const	{ return (this->*IECPtrList_Find)(searchValue, startAfter); }

const CPtrList& IECPtrList::ToCPtrList() const			{ return reinterpret_cast<const CPtrList&>(*this); }
CPtrList& IECPtrList::ToCPtrList()						{ return reinterpret_cast<CPtrList&>(*this); }
int IECPtrList::GetCount() const						{ return (*this).ToCPtrList().GetCount(); }
BOOL IECPtrList::IsEmpty() const						{ return (*this).ToCPtrList().IsEmpty(); }
void*& IECPtrList::GetHead()							{ return (*this).ToCPtrList().GetHead(); }
void* IECPtrList::GetHead() const						{ return (*this).ToCPtrList().GetHead(); }
void*& IECPtrList::GetTail()							{ return (*this).ToCPtrList().GetTail(); }
void* IECPtrList::GetTail() const						{ return (*this).ToCPtrList().GetTail(); }
POSITION IECPtrList::GetHeadPosition() const			{ return (*this).ToCPtrList().GetHeadPosition(); }
POSITION IECPtrList::GetTailPosition() const			{ return (*this).ToCPtrList().GetTailPosition(); }
void*& IECPtrList::GetNext(POSITION& rPosition)			{ return (*this).ToCPtrList().GetNext(rPosition); }
void* IECPtrList::GetNext(POSITION& rPosition) const	{ return (*this).ToCPtrList().GetNext(rPosition); }
void*& IECPtrList::GetPrev(POSITION& rPosition)			{ return (*this).ToCPtrList().GetPrev(rPosition); }
void* IECPtrList::GetPrev(POSITION& rPosition) const	{ return (*this).ToCPtrList().GetPrev(rPosition); }
void*& IECPtrList::GetAt(POSITION position)				{ return (*this).ToCPtrList().GetAt(position); }
void* IECPtrList::GetAt(POSITION position) const		{ return (*this).ToCPtrList().GetAt(position); }
void IECPtrList::SetAt(POSITION pos, void* newElement)	{ return (*this).ToCPtrList().SetAt(pos, newElement); }

IMPLEMENT_DYNAMIC(IECPtrList, CObject)