//TobExEE
#include "cptrlistex.h"
#include "p_cptrlist.h"

#include "utils.h"

DefineLibNoRetFunc(IECPtrList&, IECPtrList, IECPtrList, (int nBlockSize), Construct, Construct, (nBlockSize), IECPTRLIST_CONSTRUCT);
DefineLibMemberFunc(void, IECPtrList, RemoveAll, (), RemoveAll, RemoveAll, (), IECPTRLIST_REMOVEALL);
DefineLibNoRetFunc(void, IECPtrList, ~IECPtrList, (), Deconstruct, Deconstruct, (), IECPTRLIST_DECONSTRUCT);
DefineLibMemberFunc(POSITION, IECPtrList, AddHead, (void* newElement), AddHead, AddHead_void, (newElement), IECPTRLIST_ADDHEAD_VOID);
DefineLibMemberFunc(POSITION, IECPtrList, AddTail, (void* newElement), AddTail, AddTail_void, (newElement), IECPTRLIST_ADDTAIL_VOID);
DefineLibMemberFunc(void, IECPtrList, AddHead, (IECPtrList* pNewList), AddHead, AddHead_IECPtrList, (pNewList), IECPTRLIST_ADDHEAD_IECPTRLIST);
DefineLibMemberFunc(void, IECPtrList, AddTail, (IECPtrList* pNewList), AddTail, AddTail_IECPtrList, (pNewList), IECPTRLIST_ADDTAIL_IECPTRLIST);
DefineLibMemberFunc(void*, IECPtrList, RemoveHead, (), RemoveHead, RemoveHead, (), IECPTRLIST_REMOVEHEAD);
DefineLibMemberFunc(void*, IECPtrList, RemoveTail, (), RemoveTail, RemoveTail, (), IECPTRLIST_REMOVETAIL);
DefineLibMemberFunc(POSITION, IECPtrList, InsertBefore, (POSITION position, void* newElement), InsertBefore, InsertBefore, (position, newElement), IECPTRLIST_INSERTBEFORE);
DefineLibMemberFunc(POSITION, IECPtrList, InsertAfter, (POSITION position, void* newElement), InsertAfter, InsertAfter, (position, newElement), IECPTRLIST_INSERTAFTER);
DefineLibMemberFunc(void, IECPtrList, RemoveAt, (POSITION position), RemoveAt, RemoveAt, (position), IECPTRLIST_REMOVEAT);
DefineLibMemberFunc(POSITION, IECPtrList, FindIndex, (int nIndex) const, FindIndex, FindIndex, (nIndex), IECPTRLIST_FINDINDEX);
DefineLibMemberFunc(POSITION, IECPtrList, Find, (void* searchValue, POSITION startAfter) const, Find, Find, (searchValue, startAfter), IECPTRLIST_FIND);

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