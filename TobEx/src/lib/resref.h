#ifndef RESREF_H
#define RESREF_H

#include "utils.h"
#include "cstringex.h"

typedef CPtrList CResRefList; //0xAA6334

class ResRef {
public:
	ResRef();
	ResRef* Construct(void) {return this;} //dummy

	ResRef(IECString&);
	ResRef* Construct(IECString&) {return this;} //dummy

	ResRef(LPTSTR);
	ResRef* Construct(LPTSTR) {return this;} //dummy

	ResRef(LPCTSTR);
	ResRef* Construct(LPCTSTR) {return this;} //dummy

	~ResRef();

	IECString& ToString(IECString&);
	void NullSpaces(void);
	LPTSTR GetBuffer(void) const;
	IECString& SafeToString(IECString&);
	BOOL IsNotEmpty();
	void ToChar(LPCTSTR);

	BOOL operator!=(ResRef&);
	BOOL OpNeq(ResRef&) {return TRUE;} //dummy
	BOOL operator!=(IECString&);
	BOOL OpNeq(IECString&) {return TRUE;} //dummy
	BOOL operator!=(LPTSTR);
	BOOL OpNeq(LPTSTR) {return TRUE;} //dummy
	BOOL operator==(IECString&);
	BOOL OpEq(IECString&) {return TRUE;} //dummy
	BOOL operator==(LPTSTR);
	BOOL OpEq(LPTSTR) {return TRUE;} //dummy
	BOOL operator==(LPCTSTR);
	BOOL OpEq(LPCTSTR) {return TRUE;} //dummy

	BOOL IsEmpty(void);

	ResRef operator=(ResRef&);
	ResRef OpAssign(ResRef& r) {return r; } //dummy
	ResRef operator=(LPCTSTR);
	ResRef OpAssign(LPCTSTR sz) {return sz; } //dummy
	ResRef operator=(IECString&);
	ResRef OpAssign(IECString& s) {return s; } //dummy
	ResRef operator=(LPTSTR);
	ResRef OpAssign(LPTSTR sz) {return sz; } //dummy

	void ToUpper(void);
	ResRef CopyToUpper(IECString&);
	void Copy(ResRef&);

	//additional implementations
	operator LPTSTR() const;

protected:
	char buf[8];
};

//member function pointers
extern ResRef* (ResRef::*ResRef_Construct_0)(void);
extern ResRef* (ResRef::*ResRef_Construct_1CString)(IECString&);
extern ResRef* (ResRef::*ResRef_Construct_1LPTSTR)(LPTSTR);
extern ResRef* (ResRef::*ResRef_Construct_1LPCTSTR)(LPCSTR);
extern IECString& (ResRef::*ResRef_ToString)(IECString&);
extern void (ResRef::*ResRef_NullSpaces)(void);
extern LPTSTR (ResRef::*ResRef_GetBuffer)(void) const;
extern IECString& (ResRef::*ResRef_SafeToString)(IECString&);
extern BOOL (ResRef::*ResRef_IsNotEmpty)(void);
extern void (ResRef::*ResRef_ToChar)(LPCTSTR);
extern BOOL (ResRef::*ResRef_OpNeq_ResRef)(ResRef&);
extern BOOL (ResRef::*ResRef_OpNeq_CString)(IECString&);
extern BOOL (ResRef::*ResRef_OpNeq_LPTSTR)(LPTSTR);
extern BOOL (ResRef::*ResRef_OpEq_CString)(IECString&);
extern BOOL (ResRef::*ResRef_OpEq_LPTSTR)(LPTSTR);
extern BOOL (ResRef::*ResRef_OpEq_LPCTSTR)(LPCTSTR);
extern BOOL (ResRef::*ResRef_IsEmpty)(void);
extern ResRef (ResRef::*ResRef_OpAssign_ResRef)(ResRef&);
extern ResRef (ResRef::*ResRef_OpAssign_LPCTSTR)(LPCTSTR);
extern ResRef (ResRef::*ResRef_OpAssign_CString)(IECString&);
extern ResRef (ResRef::*ResRef_OpAssign_LPTSTR)(LPTSTR);
extern void (ResRef::*ResRef_ToUpper)(void);
extern ResRef (ResRef::*ResRef_CopyToUpper)(IECString&);
extern void (ResRef::*ResRef_Copy)(ResRef&);

#endif //RESREF_H
