#include "resref.h"

#include "utils.h"

//member function pointers
ResRef* (ResRef::*ResRef_Construct_0)() =
	SetFP(static_cast<ResRef* (ResRef::*)()>				(&ResRef::Construct),		0x999EC1);
ResRef* (ResRef::*ResRef_Construct_1CString)(IECString&) =
	SetFP(static_cast<ResRef* (ResRef::*)(IECString&)>		(&ResRef::Construct),		0x999ED9);
ResRef* (ResRef::*ResRef_Construct_1LPTSTR)(LPTSTR) =
	SetFP(static_cast<ResRef* (ResRef::*)(LPTSTR)>			(&ResRef::Construct),		0x999EFB);
ResRef* (ResRef::*ResRef_Construct_1LPCTSTR)(LPCSTR) =
	SetFP(static_cast<ResRef* (ResRef::*)(LPCSTR)>			(&ResRef::Construct),		0x999F1D);
IECString (ResRef::*ResRef_ToString)() =
	SetFP(static_cast<IECString (ResRef::*)()>				(&ResRef::ToString),		0x999F3F);
void (ResRef::*ResRef_NullSpaces)() =
	SetFP(static_cast<void (ResRef::*)()>					(&ResRef::NullSpaces),		0x999F6C);	
LPTSTR (ResRef::*ResRef_GetBuffer)() const =
	SetFP(static_cast<LPTSTR (ResRef::*)() const>			(&ResRef::GetBuffer),		0x999FB3);
IECString (ResRef::*ResRef_FormatToString)() =
	SetFP(static_cast<IECString (ResRef::*)()>				(&ResRef::FormatToString),	0x999FC1);
BOOL (ResRef::*ResRef_IsNotEmpty)() =
	SetFP(static_cast<BOOL (ResRef::*)()>					(&ResRef::IsNotEmpty),		0x99A040);
void (ResRef::*ResRef_ToChar)(LPCTSTR) =
	SetFP(static_cast<void (ResRef::*)(LPCTSTR)>			(&ResRef::ToChar),			0x99A05A);
BOOL (ResRef::*ResRef_OpNeq_ResRef)(ResRef&) =
	SetFP(static_cast<BOOL (ResRef::*)(ResRef&)>			(&ResRef::OpNeq),			0x99A07E);
BOOL (ResRef::*ResRef_OpNeq_CString)(IECString&) =
	SetFP(static_cast<BOOL (ResRef::*)(IECString&)>			(&ResRef::OpNeq),			0x99A0C9);
BOOL (ResRef::*ResRef_OpNeq_LPTSTR)(LPTSTR) =
	SetFP(static_cast<BOOL (ResRef::*)(LPTSTR)>				(&ResRef::OpNeq),			0x99A0EF);
BOOL (ResRef::*ResRef_OpEq_CString)(IECString&) =
	SetFP(static_cast<BOOL (ResRef::*)(IECString&)>			(&ResRef::OpEq),			0x99A1C3);
BOOL (ResRef::*ResRef_OpEq_LPTSTR)(LPTSTR) =
	SetFP(static_cast<BOOL (ResRef::*)(LPTSTR)>				(&ResRef::OpEq),			0x99A1E6);
BOOL (ResRef::*ResRef_OpEq_LPCTSTR)(LPCTSTR) =
	SetFP(static_cast<BOOL (ResRef::*)(LPCTSTR)>			(&ResRef::OpEq),			0x99A2BD);
BOOL (ResRef::*ResRef_IsEmpty)() =
	SetFP(static_cast<BOOL (ResRef::*)()>					(&ResRef::IsEmpty),			0x99A3A0);
ResRef (ResRef::*ResRef_OpAssign_ResRef)(ResRef&) =
	SetFP(static_cast<ResRef (ResRef::*)(ResRef&)>			(&ResRef::OpAssign),		0x99A3BF);
ResRef (ResRef::*ResRef_OpAssign_LPCTSTR)(LPCTSTR) =
	SetFP(static_cast<ResRef (ResRef::*)(LPCTSTR)>			(&ResRef::OpAssign),		0x99A3EF);
ResRef (ResRef::*ResRef_OpAssign_CString)(IECString&) =
	SetFP(static_cast<ResRef (ResRef::*)(IECString&)>		(&ResRef::OpAssign),		0x99A4A5);
ResRef (ResRef::*ResRef_OpAssign_LPTSTR)(LPTSTR) =
	SetFP(static_cast<ResRef (ResRef::*)(LPTSTR)>			(&ResRef::OpAssign),		0x99A5A0);
void (ResRef::*ResRef_ToUpper)() =
	SetFP(static_cast<void (ResRef::*)()>					(&ResRef::ToUpper),			0x99A634);
ResRef (ResRef::*ResRef_CopyToUpper)(IECString&) =
	SetFP(static_cast<ResRef (ResRef::*)(IECString&)>		(&ResRef::CopyToUpper),		0x99A6C5);
void (ResRef::*ResRef_Copy)(ResRef&) =
	SetFP(static_cast<void (ResRef::*)(ResRef&)>			(&ResRef::Copy),			0x99A7AC);

//implementations
ResRef::ResRef()								{ (this->*ResRef_Construct_0)(); }
ResRef::ResRef(IECString& s)					{ (this->*ResRef_Construct_1CString)(s); }
ResRef::ResRef(LPTSTR sz)						{ (this->*ResRef_Construct_1LPTSTR)(sz); }
ResRef::ResRef(LPCTSTR sz)						{ (this->*ResRef_Construct_1LPCTSTR)(sz); }
ResRef::~ResRef()								{}
IECString ResRef::ToString()					{ return (this->*ResRef_ToString)(); }
void ResRef::NullSpaces()						{ return (this->*ResRef_NullSpaces)(); }
LPTSTR ResRef::GetBuffer() const				{ return (this->*ResRef_GetBuffer)(); }
IECString ResRef::FormatToString()				{ return (this->*ResRef_FormatToString)(); }
BOOL ResRef::IsNotEmpty()						{ return (this->*ResRef_IsNotEmpty)(); }
void ResRef::ToChar(LPCTSTR sz)					{ return (this->*ResRef_ToChar)(sz); }
BOOL ResRef::operator!=(ResRef& r)				{ return (this->*ResRef_OpNeq_ResRef)(r); }
BOOL ResRef::operator!=(IECString& s)			{ return (this->*ResRef_OpNeq_CString)(s); }
BOOL ResRef::operator!=(LPTSTR sz)				{ return (this->*ResRef_OpNeq_LPTSTR)(sz); }
BOOL ResRef::operator==(IECString& s)			{ return (this->*ResRef_OpEq_CString)(s); }
BOOL ResRef::operator==(LPTSTR sz)				{ return (this->*ResRef_OpEq_LPTSTR)(sz); }
BOOL ResRef::operator==(LPCTSTR sz)				{ return (this->*ResRef_OpEq_LPCTSTR)(sz); }
BOOL ResRef::IsEmpty()							{ return (this->*ResRef_IsEmpty)(); }
ResRef ResRef::operator=(ResRef& r)				{ return (this->*ResRef_OpAssign_ResRef)(r); }
ResRef ResRef::operator=(LPCTSTR sz)			{ return (this->*ResRef_OpAssign_LPCTSTR)(sz); }
ResRef ResRef::operator=(IECString& s)			{ return (this->*ResRef_OpAssign_CString)(s); }
ResRef ResRef::operator=(LPTSTR sz)				{ return (this->*ResRef_OpAssign_LPTSTR)(sz); }
void ResRef::ToUpper()							{ return (this->*ResRef_ToUpper)(); }
ResRef ResRef::CopyToUpper(IECString& s)		{ return (this->*ResRef_CopyToUpper)(s); }
void ResRef::Copy(ResRef& r)					{ return (this->*ResRef_Copy)(r); }

ResRef::operator LPTSTR() const					{ return GetBuffer(); }
BOOL ResRef::operator==(ResRef& r)				{ return !(this->*ResRef_OpNeq_ResRef)(r); }