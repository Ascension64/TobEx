#ifndef CPTRLISTEX_H
#define CPTRLISTEX_H

#include "win32def.h"
#include "globals.h"

class IECPtrList : public CObject { //Size 1Ch
	DECLARE_DYNAMIC(IECPtrList)
	DEFINE_MEMALLOC_FUNC;

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

#endif //CPTRLISTEX_H