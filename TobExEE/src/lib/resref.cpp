//TobExEE
#include "resref.h"
#include "p_resref.h"

#include "utils.h"

DefineLibNoRetFunc(ResRef*, ResRef, ResRef, (), Construct, Construct0, (), RESREF_CONSTRUCT0);
DefineLibNoRetFunc(ResRef*, ResRef, ResRef, (IECString& s), Construct, Construct1_IECString, (s), RESREF_CONSTRUCT1_IECSTRING);
DefineLibNoRetFunc(ResRef*, ResRef, ResRef, (LPTSTR sz), Construct, Construct1_LPTSTR, (sz), RESREF_CONSTRUCT1_LPTSTR);
DefineLibNoRetFunc(ResRef*, ResRef, ResRef, (LPCTSTR sz), Construct, Construct1_LPCTSTR, (sz), RESREF_CONSTRUCT1_LPCTSTR);
DefineLibMemberFunc(IECString, ResRef, ToString, (), ToString, ToString, (), RESREF_TOSTRING);
DefineLibMemberFunc(LPTSTR, ResRef, GetBuffer, () const, GetBuffer, GetBuffer, (), RESREF_GETBUFFER);
DefineLibMemberFunc(IECString, ResRef, FormatToString, (), FormatToString, FormatToString, (), RESREF_FORMATTOSTRING);
DefineLibMemberFunc(BOOL, ResRef, IsNotEmpty, (), IsNotEmpty, IsNotEmpty, (), RESREF_ISNOTEMPTY);
DefineLibMemberFunc(BOOL, ResRef, operator!=, (ResRef& r), OpNeq, OpNeq_ResRef, (r), RESREF_OPNEQ_RESREF);
DefineLibMemberFunc(BOOL, ResRef, operator!=, (IECString& s), OpNeq, OpNeq_IECString, (s), RESREF_OPNEQ_IECSTRING);
DefineLibMemberFunc(BOOL, ResRef, operator!=, (LPTSTR sz), OpNeq, OpNeq_LPTSTR, (sz), RESREF_OPNEQ_LPTSTR);
DefineLibMemberFunc(BOOL, ResRef, operator==, (IECString& s), OpEq, OpEq_IECString, (s), RESREF_OPEQ_IECSTRING);
DefineLibMemberFunc(BOOL, ResRef, operator==, (LPTSTR sz), OpEq, OpEq_LPTSTR, (sz), RESREF_OPEQ_LPTSTR);
DefineLibMemberFunc(BOOL, ResRef, operator==, (LPCTSTR sz), OpEq, OpEq_LPCTSTR, (sz), RESREF_OPEQ_LPCTSTR);
DefineLibMemberFunc(BOOL, ResRef, IsEmpty, (), IsEmpty, IsEmpty, (), RESREF_ISEMPTY);
DefineLibMemberFunc(ResRef, ResRef, operator=, (ResRef& r), OpAssign, OpAssign_ResRef, (r), RESREF_OPASSIGN_RESREF);
DefineLibMemberFunc(ResRef, ResRef, operator=, (LPCTSTR sz), OpAssign, OpAssign_LPCTSTR, (sz), RESREF_OPASSIGN_LPCTSTR);
DefineLibMemberFunc(ResRef, ResRef, operator=, (IECString& s), OpAssign, OpAssign_IECString, (s), RESREF_OPASSIGN_IECSTRING);
DefineLibMemberFunc(ResRef, ResRef, operator=, (LPTSTR sz), OpAssign, OpAssign_LPTSTR, (sz), RESREF_OPASSIGN_LPTSTR);
DefineLibMemberFunc(void, ResRef, ToUpper, (), ToUpper, ToUpper, (), RESREF_TOUPPER);
DefineLibMemberFunc(ResRef, ResRef, CopyToUpper, (IECString& s), CopyToUpper, CopyToUpper, (s), RESREF_COPYTOUPPER);
DefineLibMemberFunc(void, ResRef, Copy, (ResRef& rTarget), Copy, Copy, (rTarget), RESREF_COPY);

ResRef::operator LPTSTR() const					{ return GetBuffer(); }
BOOL ResRef::operator==(ResRef& r)				{ return !operator!=(r); }