#ifndef RESREF_H
#define RESREF_H

#include "win32def.h"

#include "cstringex.h"

class ResRef {
public:
	ResRef();
	ResRef* Construct(void) {return this;} //dummy

	ResRef(IECString& s);
	ResRef* Construct(IECString&) {return this;} //dummy

	ResRef(LPTSTR sz);
	ResRef* Construct(LPTSTR) {return this;} //dummy

	ResRef(LPCTSTR sz);
	ResRef* Construct(LPCTSTR) {return this;} //dummy

	~ResRef();

	IECString ToString();
	void NullSpaces();
	LPTSTR GetBuffer() const;
	IECString SafeToString();
	BOOL IsNotEmpty();
	void ToChar(LPCTSTR sz);

	BOOL operator!=(ResRef& r);
	BOOL OpNeq(ResRef&) {return TRUE;} //dummy
	BOOL operator!=(IECString& s);
	BOOL OpNeq(IECString&) {return TRUE;} //dummy
	BOOL operator!=(LPTSTR sz);
	BOOL OpNeq(LPTSTR) {return TRUE;} //dummy
	BOOL operator==(IECString& s);
	BOOL OpEq(IECString&) {return TRUE;} //dummy
	BOOL operator==(LPTSTR sz);
	BOOL OpEq(LPTSTR) {return TRUE;} //dummy
	BOOL operator==(LPCTSTR sz);
	BOOL OpEq(LPCTSTR) {return TRUE;} //dummy

	BOOL IsEmpty();

	ResRef operator=(ResRef& r);
	ResRef OpAssign(ResRef& r) {return r; } //dummy
	ResRef operator=(LPCTSTR sz);
	ResRef OpAssign(LPCTSTR sz) {return sz; } //dummy
	ResRef operator=(IECString& s);
	ResRef OpAssign(IECString& s) {return s; } //dummy
	ResRef operator=(LPTSTR sz);
	ResRef OpAssign(LPTSTR sz) {return sz; } //dummy

	void ToUpper();
	ResRef CopyToUpper(IECString& s);
	void Copy(ResRef& r);

	//additional implementations
	operator LPTSTR() const;
	BOOL operator==(ResRef& r);

protected:
	char buf[8];
};

//member function pointers
extern ResRef* (ResRef::*ResRef_Construct_0)();
extern ResRef* (ResRef::*ResRef_Construct_1CString)(IECString&);
extern ResRef* (ResRef::*ResRef_Construct_1LPTSTR)(LPTSTR);
extern ResRef* (ResRef::*ResRef_Construct_1LPCTSTR)(LPCSTR);
extern IECString (ResRef::*ResRef_ToString)();
extern void (ResRef::*ResRef_NullSpaces)();
extern LPTSTR (ResRef::*ResRef_GetBuffer)() const;
extern IECString (ResRef::*ResRef_SafeToString)();
extern BOOL (ResRef::*ResRef_IsNotEmpty)();
extern void (ResRef::*ResRef_ToChar)(LPCTSTR);
extern BOOL (ResRef::*ResRef_OpNeq_ResRef)(ResRef&);
extern BOOL (ResRef::*ResRef_OpNeq_CString)(IECString&);
extern BOOL (ResRef::*ResRef_OpNeq_LPTSTR)(LPTSTR);
extern BOOL (ResRef::*ResRef_OpEq_CString)(IECString&);
extern BOOL (ResRef::*ResRef_OpEq_LPTSTR)(LPTSTR);
extern BOOL (ResRef::*ResRef_OpEq_LPCTSTR)(LPCTSTR);
extern BOOL (ResRef::*ResRef_IsEmpty)();
extern ResRef (ResRef::*ResRef_OpAssign_ResRef)(ResRef&);
extern ResRef (ResRef::*ResRef_OpAssign_LPCTSTR)(LPCTSTR);
extern ResRef (ResRef::*ResRef_OpAssign_CString)(IECString&);
extern ResRef (ResRef::*ResRef_OpAssign_LPTSTR)(LPTSTR);
extern void (ResRef::*ResRef_ToUpper)();
extern ResRef (ResRef::*ResRef_CopyToUpper)(IECString&);
extern void (ResRef::*ResRef_Copy)(ResRef&);

#endif //RESREF_H
