#include "resref.h"

#include "utils.h"

DefineLibNoRetFunc(ResRef*, ResRef, ResRef, (), Construct, Construct0, (), 0x999EC1);
DefineLibNoRetFunc(ResRef*, ResRef, ResRef, (IECString& s), Construct, Construct1_IECString, (s), 0x999ED9);
DefineLibNoRetFunc(ResRef*, ResRef, ResRef, (LPTSTR sz), Construct, Construct1_LPTSTR, (sz), 0x999EFB);
DefineLibNoRetFunc(ResRef*, ResRef, ResRef, (LPCTSTR sz), Construct, Construct1_LPCTSTR, (sz), 0x999F1D);
DefineLibMemberFunc(IECString, ResRef, ToString, (), ToString, ToString, (), 0x999F3F);
DefineLibMemberFunc(void, ResRef, NullSpaces, (), NullSpaces, NullSpaces, (), 0x999F6C);
DefineLibMemberFunc(LPTSTR, ResRef, GetBuffer, () const, GetBuffer, GetBuffer, (), 0x999FB3);
DefineLibMemberFunc(IECString, ResRef, FormatToString, (), FormatToString, FormatToString, (), 0x999FC1);
DefineLibMemberFunc(BOOL, ResRef, IsNotEmpty, (), IsNotEmpty, IsNotEmpty, (), 0x99A040);
DefineLibMemberFunc(void, ResRef, ToChar, (LPCTSTR sz), ToChar, ToChar, (sz), 0x99A05A);
DefineLibMemberFunc(BOOL, ResRef, operator!=, (ResRef& r), OpNeq, OpNeq_ResRef, (r), 0x99A07E);
DefineLibMemberFunc(BOOL, ResRef, operator!=, (IECString& s), OpNeq, OpNeq_IECString, (s), 0x99A0C9);
DefineLibMemberFunc(BOOL, ResRef, operator!=, (LPTSTR sz), OpNeq, OpNeq_LPTSTR, (sz), 0x99A0EF);
DefineLibMemberFunc(BOOL, ResRef, operator==, (IECString& s), OpEq, OpEq_IECString, (s), 0x99A1C3);
DefineLibMemberFunc(BOOL, ResRef, operator==, (LPTSTR sz), OpEq, OpEq_LPTSTR, (sz), 0x99A1E6);
DefineLibMemberFunc(BOOL, ResRef, operator==, (LPCTSTR sz), OpEq, OpEq_LPCTSTR, (sz), 0x99A2BD);
DefineLibMemberFunc(BOOL, ResRef, IsEmpty, (), IsEmpty, IsEmpty, (), 0x99A3A0);
DefineLibMemberFunc(ResRef, ResRef, operator=, (ResRef& r), OpAssign, OpAssign_ResRef, (r), 0x99A3BF);
DefineLibMemberFunc(ResRef, ResRef, operator=, (LPCTSTR sz), OpAssign, OpAssign_LPCTSTR, (sz), 0x99A3EF);
DefineLibMemberFunc(ResRef, ResRef, operator=, (IECString& s), OpAssign, OpAssign_IECString, (s), 0x99A4A5);
DefineLibMemberFunc(ResRef, ResRef, operator=, (LPTSTR sz), OpAssign, OpAssign_LPTSTR, (sz), 0x99A5A0);
DefineLibMemberFunc(void, ResRef, ToUpper, (), ToUpper, ToUpper, (), 0x99A634);
DefineLibMemberFunc(ResRef, ResRef, CopyToUpper, (IECString& s), CopyToUpper, CopyToUpper, (s), 0x99A6C5);
DefineLibMemberFunc(void, ResRef, Copy, (ResRef& rTarget), Copy, Copy, (rTarget), 0x99A7AC);

ResRef::operator LPTSTR() const					{ return GetBuffer(); }
BOOL ResRef::operator==(ResRef& r)				{ return !operator!=(r); }