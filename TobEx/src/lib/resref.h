#ifndef RESREF_H
#define RESREF_H

#include "win32def.h"
#include "globals.h"
#include "cstringex.h"

class ResRef {
	DEFINE_MEMALLOC_FUNC;
public:
	ResRef();
	ResRef* Construct(void) {return this;} //dummy

	ResRef(IECString& s);
	ResRef* Construct(IECString&) {return this;} //dummy

	ResRef(LPTSTR sz);
	ResRef* Construct(LPTSTR) {return this;} //dummy

	ResRef(LPCTSTR sz);
	ResRef* Construct(LPCTSTR) {return this;} //dummy

	~ResRef() {}

	IECString ToString();
	void NullSpaces();
	LPTSTR GetBuffer() const;
	IECString FormatToString();
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
	void Copy(ResRef& rTarget);

	//additional implementations
	operator LPTSTR() const;
	BOOL operator==(ResRef& r);

protected:
	char buf[8];
};

typedef ResRef RESREF;

#endif //RESREF_H
