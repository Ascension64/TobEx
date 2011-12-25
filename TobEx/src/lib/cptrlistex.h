#ifndef CPTRLISTEX_H
#define CPTRLISTEX_H

#include "win32def.h"

class IECPtrList { //Size 1Ch
	DECLARE_DYNAMIC(IECPtrList)

public:
	IECPtrList(int nBlockSize = 10);
	IECPtrList& Construct(int nBlockSize = 10) { return *this; } //dummy

	void RemoveAll();

	~IECPtrList();
	void Deconstruct() {} //dummy

	POSITION AddHead(void* newElement);
	POSITION AddTail(void* newElement);
	void AddHead(IECPtrList* pNewList);
	void AddTail(IECPtrList* pNewList);
	void* RemoveHead();
	void* RemoveTail();
	POSITION InsertBefore(POSITION position, void* newElement);
	POSITION InsertAfter(POSITION position, void* newElement);
	void RemoveAt(POSITION position);
	POSITION FindIndex(int nIndex) const;
	POSITION Find(void* searchValue, POSITION startAfter = NULL) const;

	//integration with IECPtrList
	const CPtrList& ToCPtrList() const;
	CPtrList& ToCPtrList();

	int GetCount() const;
	BOOL IsEmpty() const;
	void*& GetHead();
	void* GetHead() const;
	void*& GetTail();
	void* GetTail() const;
	POSITION GetHeadPosition() const;
	POSITION GetTailPosition() const;
	void*& GetNext(POSITION& rPosition);
	void* GetNext(POSITION& rPosition) const;
	void*& GetPrev(POSITION& rPosition);
	void* GetPrev(POSITION& rPosition) const;
	void*& GetAt(POSITION position);
	void* GetAt(POSITION position) const;
	void SetAt(POSITION pos, void* newElement);

protected:
	struct CNode
	{
		CNode* pNext;
		CNode* pPrev;
		void* data;
	};

	CNode* m_pNodeHead;
	CNode* m_pNodeTail;
	int m_nCount;
	CNode* m_pNodeFree;
	struct CPlex* m_pBlocks;
	int m_nBlockSize;
};

extern IECPtrList& (IECPtrList::*IECPtrList_Construct)(int nBlockSize);
extern void (IECPtrList::*IECPtrList_RemoveAll)();
extern void (IECPtrList::*IECPtrList_Deconstruct)();
extern POSITION (IECPtrList::*IECPtrList_AddHead_void)(void* newElement);
extern POSITION (IECPtrList::*IECPtrList_AddTail_void)(void* newElement);
extern void (IECPtrList::*IECPtrList_AddHead_CPtrList)(IECPtrList* pNewList);
extern void (IECPtrList::*IECPtrList_AddTail_CPtrList)(IECPtrList* pNewList);
extern void* (IECPtrList::*IECPtrList_RemoveHead)();
extern void* (IECPtrList::*IECPtrList_RemoveTail)();
extern POSITION (IECPtrList::*IECPtrList_InsertBefore)(POSITION position, void* newElement);
extern POSITION (IECPtrList::*IECPtrList_InsertAfter)(POSITION position, void* newElement);
extern void (IECPtrList::*IECPtrList_RemoveAt)(POSITION position);
extern POSITION (IECPtrList::*IECPtrList_FindIndex)(int nIndex) const;
extern POSITION (IECPtrList::*IECPtrList_Find)(void* searchValue, POSITION startAfter) const;

#endif //CPTRLISTEX_H