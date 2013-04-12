//TobExEE
//don't include this; just a quick reference to structures of some MFC42 objects

#include "win32def.h"

class CWnd { //Size 3Ch
	DWORD* vtable; //0h
	long m_dwRef; //4h
	LPUNKNOWN m_pOuterUnknown; //8h
	DWORD m_xInnerUnknown; //ch
	XDispatch m_xDispatch {DWORD m_vtbl}; //10h
	BOOL m_bResultExpected; //14h
	XConnPtContainer m_xConnPtContainer {DWORD m_vtbl}; //18h

	HWND m_hWnd; //1ch
	HWND m_hWndOwner;  //20h
	UINT m_nFlags; //24h
	WNDPROC m_pfnSuper; //28h
	int m_nModalResult; //2ch
	COleDropTarget* m_pDropTarget; //30h
	COleControlContainer* m_pCtrlCont; //34h
	COleControlSite* m_pCtrlSite; //38h
};

class CFile { //Size 10h
	UINT m_hFile; //4h
	BOOL m_bCloseOnDelete; //8h
	CString m_strFileName; //Ch
};

struct CStringData {
	long interlockVar; //nRefs, reference count
	int nDataLength;
	int nAllocLength;
	TCHAR data;
};

class CString {
protected:
	LPTSTR m_pchData; //pointer to data
};

struct CNode { //Size Ch
	CNode* pNext;
	CNode* pPrev;
	void* data;
};

class CPtrList { //SIze 1Ch
protected:
	DWORD* vtable; //0h
	CNode* m_pNodeHead; //first filled node, 4h
	CNode* m_pNodeTail; //last filled node, 8h
	DWORD m_nCount; //numbered of filled nodes, ch
	CNode* m_pNodeFree; //last free node of block, 10h
	struct CPlex* m_pBlocks; //ptr to block (block = pNextBlock + CNode[m_nBlockSize]), 14h
	DWORD m_nBlockSize; //size of block, fixed maximum size, default 0xa, 18h
};

class CPtrArray { //Size 14h
protected:
	DWORD* vtable;
	void** m_pData;   // the actual array of data
	int m_nSize;     // # of elements (upperBound - 1)
	int m_nMaxSize;  // max allocated
	int m_nGrowBy;   // grow amount
};
