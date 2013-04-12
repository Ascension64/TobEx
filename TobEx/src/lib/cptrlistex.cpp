#include "cptrlistex.h"

#include "utils.h"

DefineLibNoRetFunc(IECPtrList&, IECPtrList, IECPtrList, (int nBlockSize), Construct, Construct, (nBlockSize), 0xA4E475);
DefineLibMemberFunc(void, IECPtrList, RemoveAll, (), RemoveAll, RemoveAll, (), 0xA4E4D4);
DefineLibNoRetFunc(void, IECPtrList, ~IECPtrList, (), Deconstruct, Deconstruct, (), 0xA4E4B4);
DefineLibMemberFunc(POSITION, IECPtrList, AddHead, (void* newElement), AddHead, AddHead_void, (newElement), 0xA4E56E);
DefineLibMemberFunc(POSITION, IECPtrList, AddTail, (void* newElement), AddTail, AddTail_void, (newElement), 0xA4E598);
DefineLibMemberFunc(void, IECPtrList, AddHead, (IECPtrList* pNewList), AddHead, AddHead_IECPtrList, (pNewList), 0xA4E5C1);
DefineLibMemberFunc(void, IECPtrList, AddTail, (IECPtrList* pNewList), AddTail, AddTail_IECPtrList, (pNewList), 0xA4E5E6);
DefineLibMemberFunc(void*, IECPtrList, RemoveHead, (), RemoveHead, RemoveHead, (), 0xA4E60A);
DefineLibMemberFunc(void*, IECPtrList, RemoveTail, (), RemoveTail, RemoveTail, (), 0xA4E62E);
DefineLibMemberFunc(POSITION, IECPtrList, InsertBefore, (POSITION position, void* newElement), InsertBefore, InsertBefore, (position, newElement), 0xA4E652);
DefineLibMemberFunc(POSITION, IECPtrList, InsertAfter, (POSITION position, void* newElement), InsertAfter, InsertAfter, (position, newElement), 0xA4E691);
DefineLibMemberFunc(void, IECPtrList, RemoveAt, (POSITION position), RemoveAt, RemoveAt, (position), 0xA4E6CE);
DefineLibMemberFunc(POSITION, IECPtrList, FindIndex, (int nIndex) const, FindIndex, FindIndex, (nIndex), 0xA4E705);
DefineLibMemberFunc(POSITION, IECPtrList, Find, (void* searchValue, POSITION startAfter) const, Find, Find, (searchValue, startAfter), 0xA4E72B);

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